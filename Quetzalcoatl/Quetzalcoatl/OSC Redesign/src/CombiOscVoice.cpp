#include "CombiOscVoice.h"

#include "VAOscSource.h"
#include "WTOscSource.h"

#include <algorithm>

namespace osc {

CombiOscVoice::CombiOscVoice() {
    sourceA_ = std::make_unique<VAOscSource>();
    sourceB_ = std::make_unique<WTOscSource>();
}

void CombiOscVoice::prepare(double sampleRate, int maxBlockSize) {
    if (sourceA_) sourceA_->prepare(sampleRate, maxBlockSize);
    if (sourceB_) sourceB_->prepare(sampleRate, maxBlockSize);
}

void CombiOscVoice::reset() {
    if (sourceA_) sourceA_->reset();
    if (sourceB_) sourceB_->reset();
}

void CombiOscVoice::noteOn(const NoteEvent& note) {
    if (sourceA_) sourceA_->start(note);
    if (sourceB_) sourceB_->start(note);
}

void CombiOscVoice::noteOff() {
    if (sourceA_) sourceA_->release();
    if (sourceB_) sourceB_->release();
}

void CombiOscVoice::setSourceA(std::unique_ptr<IPlayableSource> source) { sourceA_ = std::move(source); }
void CombiOscVoice::setSourceB(std::unique_ptr<IPlayableSource> source) { sourceB_ = std::move(source); }
void CombiOscVoice::setMix(float mix) { mix_ = std::clamp(mix, 0.0f, 1.0f); }
void CombiOscVoice::setFmAmount(float amount) { fmAmount_ = std::clamp(amount, 0.0f, 1.0f); }
void CombiOscVoice::setFmRoute(FmRoute route) { fmRoute_ = route; }
void CombiOscVoice::setSourceAParam(int paramId, float value) {
    if (sourceA_) {
        sourceA_->setParam(paramId, value);
    }
}
void CombiOscVoice::setSourceBParam(int paramId, float value) {
    if (sourceB_) {
        sourceB_->setParam(paramId, value);
    }
}

void CombiOscVoice::render(float* outMono, int numSamples) {
    for (int i = 0; i < numSamples; ++i) {
        float a = 0.0f;
        float b = 0.0f;

        ModFrame modA{};
        ModFrame modB{};

        switch (fmRoute_) {
            case FmRoute::AToB:
                if (sourceA_) {
                    a = sourceA_->renderSample(modA);
                }
                modB.phaseMod = fmAmount_ * a * 0.25f;
                modB.pitchModSemitones = fmAmount_ * a * 12.0f;
                if (sourceB_) {
                    b = sourceB_->renderSample(modB);
                }
                break;
            case FmRoute::BToA:
                if (sourceB_) {
                    b = sourceB_->renderSample(modB);
                }
                modA.phaseMod = fmAmount_ * b * 0.25f;
                modA.pitchModSemitones = fmAmount_ * b * 12.0f;
                if (sourceA_) {
                    a = sourceA_->renderSample(modA);
                }
                break;
            case FmRoute::Off:
            default:
                if (sourceA_) {
                    a = sourceA_->renderSample(modA);
                }
                if (sourceB_) {
                    b = sourceB_->renderSample(modB);
                }
                break;
        }

        outMono[i] += ((1.0f - mix_) * a) + (mix_ * b);
    }
}

} // namespace osc
