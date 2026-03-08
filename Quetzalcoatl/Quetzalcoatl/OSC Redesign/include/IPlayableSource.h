#pragma once

#include "OscTypes.h"

namespace osc {

class IPlayableSource {
public:
    virtual ~IPlayableSource() = default;

    virtual void prepare(double sampleRate, int maxBlockSize) = 0;
    virtual void reset() = 0;

    virtual void start(const NoteEvent& note) = 0;
    virtual void release() = 0;

    virtual void setParam(int paramId, float value) = 0;
    virtual float renderSample(const ModFrame& mod) = 0;

    virtual void render(float* outMono, int numSamples, const ModFrame& mod) {
        for (int i = 0; i < numSamples; ++i) {
            outMono[i] = renderSample(mod);
        }
    }
};

} // namespace osc
