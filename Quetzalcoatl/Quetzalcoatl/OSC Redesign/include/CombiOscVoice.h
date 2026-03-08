#pragma once

#include <memory>

#include "IPlayableSource.h"

namespace osc {

class CombiOscVoice {
public:
    CombiOscVoice();

    void prepare(double sampleRate, int maxBlockSize);
    void reset();

    void noteOn(const NoteEvent& note);
    void noteOff();

    void setSourceA(std::unique_ptr<IPlayableSource> source);
    void setSourceB(std::unique_ptr<IPlayableSource> source);

    void setMix(float mix);
    void setFmAmount(float amount);
    void setFmRoute(FmRoute route);
    void setSourceAParam(int paramId, float value);
    void setSourceBParam(int paramId, float value);

    void render(float* outMono, int numSamples);

private:
    std::unique_ptr<IPlayableSource> sourceA_;
    std::unique_ptr<IPlayableSource> sourceB_;

    float mix_ = 0.5f;
    float fmAmount_ = 0.0f;
    FmRoute fmRoute_ = FmRoute::Off;
};

} // namespace osc
