#pragma once

#include <vector>

#include "CombiOscVoice.h"

namespace osc {

class CombiOscEngine {
public:
    void prepare(double sampleRate, int maxBlockSize, int numVoices);
    void reset();

    void noteOn(int midiNote, float velocity);
    void noteOff(int midiNote);

    void setMix(float mix);
    void setFmAmount(float amount);
    void setFmRoute(FmRoute route);
    void setSourceAParam(int paramId, float value);
    void setSourceBParam(int paramId, float value);

    void render(float* outMono, int numSamples);

private:
    std::vector<CombiOscVoice> voices_;
};

} // namespace osc
