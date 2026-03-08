#pragma once

#include "IPlayableSource.h"

namespace osc {

class SampleOscSource final : public IPlayableSource {
public:
    void prepare(double sampleRate, int maxBlockSize) override;
    void reset() override;
    void start(const NoteEvent& note) override;
    void release() override;
    void setParam(int paramId, float value) override;
    float renderSample(const ModFrame& mod) override;

private:
    double sampleRate_ = 48000.0;
    float gain_ = 1.0f;
};

} // namespace osc
