#pragma once

#include "IPlayableSource.h"

namespace osc {

class WTOscSource final : public IPlayableSource {
public:
    void prepare(double sampleRate, int maxBlockSize) override;
    void reset() override;
    void start(const NoteEvent& note) override;
    void release() override;
    void setParam(int paramId, float value) override;
    float renderSample(const ModFrame& mod) override;

private:
    float computeFrequencyHz(float pitchModSemitones) const;

    double sampleRate_ = 48000.0;
    float phase_ = 0.0f;
    float baseFrequencyHz_ = 440.0f;
    float gain_ = 1.0f;
    float coarseSemitones_ = 0.0f;
    float fineCents_ = 0.0f;
    float tablePosition_ = 0.0f;
    bool active_ = false;
};

} // namespace osc
