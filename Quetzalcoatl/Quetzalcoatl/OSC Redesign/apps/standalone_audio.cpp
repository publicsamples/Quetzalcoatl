#include "CombiOscEngine.h"

#include <AudioToolbox/AudioToolbox.h>

#include <chrono>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>

namespace {

constexpr double kSampleRate = 48000.0;
constexpr int kFramesPerBuffer = 256;
constexpr int kNumChannels = 1;
constexpr int kVoiceCount = 8;

struct AudioState {
    osc::CombiOscEngine engine;
};

static void audioCallback(void* userData, AudioQueueRef queue, AudioQueueBufferRef buffer) {
    auto* state = static_cast<AudioState*>(userData);
    auto* out = reinterpret_cast<int16_t*>(buffer->mAudioData);

    std::vector<float> temp(kFramesPerBuffer, 0.0f);
    state->engine.render(temp.data(), kFramesPerBuffer);

    for (int i = 0; i < kFramesPerBuffer; ++i) {
        float s = temp[i] * 0.2f; // conservative headroom
        if (s > 1.0f) s = 1.0f;
        if (s < -1.0f) s = -1.0f;
        out[i] = static_cast<int16_t>(s * 32767.0f);
    }

    buffer->mAudioDataByteSize = static_cast<UInt32>(kFramesPerBuffer * sizeof(int16_t));
    AudioQueueEnqueueBuffer(queue, buffer, 0, nullptr);
}

} // namespace

int main(int argc, char** argv) {
    int durationSeconds = 10;
    if (argc > 1) {
        durationSeconds = std::max(1, std::atoi(argv[1]));
    }

    AudioState state;
    state.engine.prepare(kSampleRate, kFramesPerBuffer, kVoiceCount);
    state.engine.noteOn(60, 1.0f);

    AudioStreamBasicDescription format{};
    format.mSampleRate = kSampleRate;
    format.mFormatID = kAudioFormatLinearPCM;
    format.mFormatFlags = kAudioFormatFlagIsSignedInteger | kAudioFormatFlagIsPacked;
    format.mBitsPerChannel = 16;
    format.mChannelsPerFrame = kNumChannels;
    format.mBytesPerFrame = static_cast<UInt32>((format.mBitsPerChannel / 8) * format.mChannelsPerFrame);
    format.mFramesPerPacket = 1;
    format.mBytesPerPacket = format.mBytesPerFrame * format.mFramesPerPacket;

    AudioQueueRef queue = nullptr;
    OSStatus status = AudioQueueNewOutput(&format, audioCallback, &state, nullptr, nullptr, 0, &queue);
    if (status != noErr || queue == nullptr) {
        std::cerr << "Failed to create audio queue: " << status << std::endl;
        return 1;
    }

    constexpr int kNumBuffers = 3;
    AudioQueueBufferRef buffers[kNumBuffers]{};
    const UInt32 bytesPerBuffer = static_cast<UInt32>(kFramesPerBuffer * sizeof(int16_t));

    for (int i = 0; i < kNumBuffers; ++i) {
        status = AudioQueueAllocateBuffer(queue, bytesPerBuffer, &buffers[i]);
        if (status != noErr) {
            std::cerr << "Failed to allocate audio buffer: " << status << std::endl;
            AudioQueueDispose(queue, true);
            return 1;
        }

        std::memset(buffers[i]->mAudioData, 0, bytesPerBuffer);
        buffers[i]->mAudioDataByteSize = bytesPerBuffer;
        AudioQueueEnqueueBuffer(queue, buffers[i], 0, nullptr);
    }

    status = AudioQueueStart(queue, nullptr);
    if (status != noErr) {
        std::cerr << "Failed to start audio queue: " << status << std::endl;
        AudioQueueDispose(queue, true);
        return 1;
    }

    std::cout << "Playing osc_standalone for " << durationSeconds
              << "s. Pass seconds as argv[1]." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(durationSeconds));

    state.engine.noteOff(60);
    AudioQueueStop(queue, true);
    AudioQueueDispose(queue, true);

    return 0;
}
