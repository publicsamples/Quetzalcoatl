#import <AppKit/AppKit.h>
#import <AudioToolbox/AudioToolbox.h>

#include "CombiOscEngine.h"
#include "OscTypes.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <mutex>
#include <vector>

namespace {
constexpr double kSampleRate = 48000.0;
constexpr int kFramesPerBuffer = 256;
constexpr int kNumChannels = 1;
constexpr int kVoiceCount = 8;
constexpr int kScopeSize = 2048;

struct SharedScopeBuffer {
    std::array<float, kScopeSize> samples{};
    std::atomic<int> writeIndex{0};
};

class AudioEngine {
public:
    ~AudioEngine() { stop(); }

    bool initialise() {
        std::lock_guard<std::mutex> lock(engineMutex_);

        engine_.prepare(kSampleRate, kFramesPerBuffer, kVoiceCount);
        engine_.setSourceAParam(static_cast<int>(osc::ParamId::VaWaveform), static_cast<float>(osc::Waveform::Saw));
        engine_.setSourceBParam(static_cast<int>(osc::ParamId::WtPosition), 0.0f);

        AudioStreamBasicDescription format{};
        format.mSampleRate = kSampleRate;
        format.mFormatID = kAudioFormatLinearPCM;
        format.mFormatFlags = kAudioFormatFlagIsSignedInteger | kAudioFormatFlagIsPacked;
        format.mBitsPerChannel = 16;
        format.mChannelsPerFrame = kNumChannels;
        format.mBytesPerFrame = static_cast<UInt32>((format.mBitsPerChannel / 8) * format.mChannelsPerFrame);
        format.mFramesPerPacket = 1;
        format.mBytesPerPacket = format.mBytesPerFrame;

        OSStatus status = AudioQueueNewOutput(&format, &AudioEngine::audioCallback, this, nullptr, nullptr, 0, &queue_);
        if (status != noErr || queue_ == nullptr) {
            return false;
        }

        const UInt32 bytesPerBuffer = static_cast<UInt32>(kFramesPerBuffer * sizeof(int16_t));
        for (auto& buffer : buffers_) {
            status = AudioQueueAllocateBuffer(queue_, bytesPerBuffer, &buffer);
            if (status != noErr || buffer == nullptr) {
                return false;
            }

            std::memset(buffer->mAudioData, 0, bytesPerBuffer);
            buffer->mAudioDataByteSize = bytesPerBuffer;
            AudioQueueEnqueueBuffer(queue_, buffer, 0, nullptr);
        }

        return true;
    }

    bool start() {
        std::lock_guard<std::mutex> lock(engineMutex_);
        if (queue_ == nullptr || running_) {
            return running_;
        }

        if (playingNote_) {
            engine_.noteOn(currentMidiNote_, 1.0f);
        }

        const OSStatus status = AudioQueueStart(queue_, nullptr);
        running_ = (status == noErr);
        return running_;
    }

    void stop() {
        std::lock_guard<std::mutex> lock(engineMutex_);
        if (queue_ != nullptr) {
            AudioQueueStop(queue_, true);
            AudioQueueDispose(queue_, true);
            queue_ = nullptr;
        }
        running_ = false;
    }

    void setPlaying(bool shouldPlay) {
        std::lock_guard<std::mutex> lock(engineMutex_);
        playingNote_ = shouldPlay;
        if (playingNote_) {
            engine_.noteOn(currentMidiNote_, 1.0f);
        } else {
            engine_.noteOff(currentMidiNote_);
        }
    }

    void trigger() {
        std::lock_guard<std::mutex> lock(engineMutex_);
        engine_.noteOff(currentMidiNote_);
        engine_.noteOn(currentMidiNote_, 1.0f);
    }

    void setMix(float value) {
        std::lock_guard<std::mutex> lock(engineMutex_);
        engine_.setMix(value);
    }

    void setFmAmount(float value) {
        std::lock_guard<std::mutex> lock(engineMutex_);
        engine_.setFmAmount(value);
    }

    void setFmRoute(osc::FmRoute route) {
        std::lock_guard<std::mutex> lock(engineMutex_);
        engine_.setFmRoute(route);
    }

    void setWaveformA(osc::Waveform waveform) {
        std::lock_guard<std::mutex> lock(engineMutex_);
        engine_.setSourceAParam(static_cast<int>(osc::ParamId::VaWaveform), static_cast<float>(waveform));
    }

    void setWavetablePosition(float position) {
        std::lock_guard<std::mutex> lock(engineMutex_);
        engine_.setSourceBParam(static_cast<int>(osc::ParamId::WtPosition), position);
    }

    void copyLatestScope(std::vector<float>& output) {
        output.resize(512);
        const int end = scope_.writeIndex.load(std::memory_order_acquire);
        const int start = end - static_cast<int>(output.size());
        for (size_t i = 0; i < output.size(); ++i) {
            int idx = (start + static_cast<int>(i)) % kScopeSize;
            if (idx < 0) {
                idx += kScopeSize;
            }
            output[i] = scope_.samples[static_cast<size_t>(idx)];
        }
    }

private:
    static void audioCallback(void* userData, AudioQueueRef queue, AudioQueueBufferRef buffer) {
        auto* self = static_cast<AudioEngine*>(userData);
        self->renderInto(buffer);
        AudioQueueEnqueueBuffer(queue, buffer, 0, nullptr);
    }

    void renderInto(AudioQueueBufferRef buffer) {
        std::vector<float> temp(kFramesPerBuffer, 0.0f);

        {
            std::lock_guard<std::mutex> lock(engineMutex_);
            engine_.render(temp.data(), kFramesPerBuffer);
        }

        auto* out = reinterpret_cast<int16_t*>(buffer->mAudioData);
        for (int i = 0; i < kFramesPerBuffer; ++i) {
            const float s = std::clamp(temp[i] * 0.2f, -1.0f, 1.0f);
            out[i] = static_cast<int16_t>(s * 32767.0f);

            const int write = scope_.writeIndex.load(std::memory_order_relaxed);
            scope_.samples[static_cast<size_t>(write % kScopeSize)] = s;
            scope_.writeIndex.store((write + 1) % kScopeSize, std::memory_order_release);
        }

        buffer->mAudioDataByteSize = static_cast<UInt32>(kFramesPerBuffer * sizeof(int16_t));
    }

    osc::CombiOscEngine engine_;
    std::mutex engineMutex_;
    SharedScopeBuffer scope_;

    AudioQueueRef queue_ = nullptr;
    std::array<AudioQueueBufferRef, 3> buffers_{};

    int currentMidiNote_ = 60;
    bool playingNote_ = true;
    bool running_ = false;
};

} // namespace

@interface WaveformView : NSView
- (void)updateSamples:(const std::vector<float>&)samples;
@end

@implementation WaveformView {
    std::vector<float> _samples;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    if (self) {
        self.wantsLayer = YES;
        _samples.assign(512, 0.0f);
    }
    return self;
}

- (void)updateSamples:(const std::vector<float>&)samples {
    _samples = samples;
    [self setNeedsDisplay:YES];
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];

    [[NSColor colorWithRed:0.07 green:0.08 blue:0.11 alpha:1.0] setFill];
    NSRectFill(self.bounds);

    [[NSColor colorWithRed:0.19 green:0.22 blue:0.30 alpha:1.0] setStroke];
    NSBezierPath* grid = [NSBezierPath bezierPath];
    const CGFloat midY = NSMidY(self.bounds);
    [grid moveToPoint:NSMakePoint(NSMinX(self.bounds), midY)];
    [grid lineToPoint:NSMakePoint(NSMaxX(self.bounds), midY)];
    [grid stroke];

    [[NSColor colorWithRed:0.13 green:0.89 blue:0.77 alpha:1.0] setStroke];
    NSBezierPath* line = [NSBezierPath bezierPath];
    line.lineWidth = 1.5;

    if (_samples.empty()) {
        return;
    }

    const CGFloat w = NSWidth(self.bounds);
    const CGFloat h = NSHeight(self.bounds);
    for (size_t i = 0; i < _samples.size(); ++i) {
        const CGFloat x = (static_cast<CGFloat>(i) / static_cast<CGFloat>(_samples.size() - 1)) * w;
        const CGFloat y = midY + (_samples[i] * (h * 0.45f));
        if (i == 0) {
            [line moveToPoint:NSMakePoint(x, y)];
        } else {
            [line lineToPoint:NSMakePoint(x, y)];
        }
    }

    [line stroke];
}

@end

@interface AppDelegate : NSObject <NSApplicationDelegate>
@end

@implementation AppDelegate {
    NSWindow* _window;
    NSButton* _playButton;
    NSSlider* _mixSlider;
    NSSlider* _fmSlider;
    NSSlider* _wtPosSlider;
    NSPopUpButton* _fmRouteMenu;
    NSPopUpButton* _waveMenu;
    WaveformView* _waveView;
    NSTimer* _scopeTimer;
    AudioEngine _audio;
}

- (void)applicationDidFinishLaunching:(NSNotification*)notification {
    (void)notification;

    if (!_audio.initialise() || !_audio.start()) {
        NSAlert* alert = [[NSAlert alloc] init];
        alert.messageText = @"Failed to start audio engine";
        [alert runModal];
        [NSApp terminate:nil];
        return;
    }

    [self buildUI];
    _audio.setPlaying(true);
    _scopeTimer = [NSTimer scheduledTimerWithTimeInterval:(1.0 / 30.0)
                                                   target:self
                                                 selector:@selector(updateScope)
                                                 userInfo:nil
                                                  repeats:YES];
}

- (void)applicationWillTerminate:(NSNotification*)notification {
    (void)notification;
    [_scopeTimer invalidate];
    _scopeTimer = nil;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)sender {
    (void)sender;
    return YES;
}

- (void)buildUI {
    const NSRect frame = NSMakeRect(0, 0, 920, 560);
    _window = [[NSWindow alloc] initWithContentRect:frame
                                          styleMask:(NSWindowStyleMaskTitled |
                                                     NSWindowStyleMaskClosable |
                                                     NSWindowStyleMaskMiniaturizable |
                                                     NSWindowStyleMaskResizable)
                                            backing:NSBackingStoreBuffered
                                              defer:NO];
    _window.title = @"OSC Redesign Test UI";
    [_window center];

    NSView* content = _window.contentView;

    _waveView = [[WaveformView alloc] initWithFrame:NSMakeRect(20, 300, 880, 230)];
    [content addSubview:_waveView];

    _playButton = [[NSButton alloc] initWithFrame:NSMakeRect(20, 248, 110, 32)];
    _playButton.title = @"Play";
    _playButton.buttonType = NSButtonTypeSwitch;
    _playButton.state = NSControlStateValueOn;
    _playButton.target = self;
    _playButton.action = @selector(onPlayToggle:);
    [content addSubview:_playButton];

    NSButton* triggerButton = [[NSButton alloc] initWithFrame:NSMakeRect(140, 248, 110, 32)];
    triggerButton.title = @"Trigger";
    triggerButton.target = self;
    triggerButton.action = @selector(onTrigger:);
    [content addSubview:triggerButton];

    NSTextField* mixLabel = [self label:@"Mix A/B" frame:NSMakeRect(20, 205, 120, 20)];
    [content addSubview:mixLabel];
    _mixSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(20, 180, 250, 24)];
    _mixSlider.minValue = 0.0;
    _mixSlider.maxValue = 1.0;
    _mixSlider.doubleValue = 0.5;
    _mixSlider.target = self;
    _mixSlider.action = @selector(onMix:);
    [content addSubview:_mixSlider];

    NSTextField* fmLabel = [self label:@"FM Amount" frame:NSMakeRect(300, 205, 120, 20)];
    [content addSubview:fmLabel];
    _fmSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(300, 180, 250, 24)];
    _fmSlider.minValue = 0.0;
    _fmSlider.maxValue = 1.0;
    _fmSlider.doubleValue = 0.0;
    _fmSlider.target = self;
    _fmSlider.action = @selector(onFmAmount:);
    [content addSubview:_fmSlider];

    NSTextField* fmRouteLabel = [self label:@"FM Route" frame:NSMakeRect(580, 205, 120, 20)];
    [content addSubview:fmRouteLabel];
    _fmRouteMenu = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(580, 176, 140, 28) pullsDown:NO];
    [_fmRouteMenu addItemsWithTitles:@[@"Off", @"A -> B", @"B -> A"]];
    _fmRouteMenu.target = self;
    _fmRouteMenu.action = @selector(onFmRoute:);
    [content addSubview:_fmRouteMenu];

    NSTextField* waveALabel = [self label:@"Osc A Wave" frame:NSMakeRect(20, 130, 120, 20)];
    [content addSubview:waveALabel];
    _waveMenu = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(20, 100, 170, 28) pullsDown:NO];
    [_waveMenu addItemsWithTitles:@[@"Sine", @"Saw", @"Square", @"Triangle", @"Noise"]];
    _waveMenu.target = self;
    _waveMenu.action = @selector(onWaveA:);
    [_waveMenu selectItemAtIndex:1];
    [content addSubview:_waveMenu];

    NSTextField* wtPosLabel = [self label:@"Osc B WT Position" frame:NSMakeRect(220, 130, 160, 20)];
    [content addSubview:wtPosLabel];
    _wtPosSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(220, 100, 330, 24)];
    _wtPosSlider.minValue = 0.0;
    _wtPosSlider.maxValue = 1.0;
    _wtPosSlider.doubleValue = 0.0;
    _wtPosSlider.target = self;
    _wtPosSlider.action = @selector(onWtPos:);
    [content addSubview:_wtPosSlider];

    [_window makeKeyAndOrderFront:nil];
}

- (NSTextField*)label:(NSString*)text frame:(NSRect)frame {
    NSTextField* label = [[NSTextField alloc] initWithFrame:frame];
    label.stringValue = text;
    label.bezeled = NO;
    label.drawsBackground = NO;
    label.editable = NO;
    label.selectable = NO;
    return label;
}

- (void)onPlayToggle:(id)sender {
    (void)sender;
    _audio.setPlaying(_playButton.state == NSControlStateValueOn);
}

- (void)onTrigger:(id)sender {
    (void)sender;
    _audio.trigger();
}

- (void)onMix:(id)sender {
    (void)sender;
    _audio.setMix(static_cast<float>(_mixSlider.doubleValue));
}

- (void)onFmAmount:(id)sender {
    (void)sender;
    _audio.setFmAmount(static_cast<float>(_fmSlider.doubleValue));
}

- (void)onFmRoute:(id)sender {
    (void)sender;
    const NSInteger idx = _fmRouteMenu.indexOfSelectedItem;
    osc::FmRoute route = osc::FmRoute::Off;
    if (idx == 1) route = osc::FmRoute::AToB;
    if (idx == 2) route = osc::FmRoute::BToA;
    _audio.setFmRoute(route);
}

- (void)onWaveA:(id)sender {
    (void)sender;
    const NSInteger idx = _waveMenu.indexOfSelectedItem;
    const int clamped = static_cast<int>(std::clamp(static_cast<int>(idx), 0, 4));
    _audio.setWaveformA(static_cast<osc::Waveform>(clamped));
}

- (void)onWtPos:(id)sender {
    (void)sender;
    _audio.setWavetablePosition(static_cast<float>(_wtPosSlider.doubleValue));
}

- (void)updateScope {
    std::vector<float> samples;
    _audio.copyLatestScope(samples);
    [_waveView updateSamples:samples];
}

@end

int main(int argc, const char* argv[]) {
    (void)argc;
    (void)argv;

    @autoreleasepool {
        NSApplication* app = [NSApplication sharedApplication];
        AppDelegate* delegate = [[AppDelegate alloc] init];
        app.delegate = delegate;
        [app run];
    }

    return 0;
}
