#include "CombiOscEngine.h"

#include <algorithm>
#include <vector>

namespace osc {

void CombiOscEngine::prepare(double sampleRate, int maxBlockSize, int numVoices) {
    voices_.resize(static_cast<size_t>(std::max(1, numVoices)));
    for (auto& v : voices_) v.prepare(sampleRate, maxBlockSize);
}

void CombiOscEngine::reset() {
    for (auto& v : voices_) v.reset();
}

void CombiOscEngine::noteOn(int midiNote, float velocity) {
    if (voices_.empty()) return;
    NoteEvent event{midiNote, velocity};
    voices_[0].noteOn(event);
}

void CombiOscEngine::noteOff(int /*midiNote*/) {
    if (voices_.empty()) return;
    voices_[0].noteOff();
}

void CombiOscEngine::setMix(float mix) {
    for (auto& v : voices_) {
        v.setMix(mix);
    }
}

void CombiOscEngine::setFmAmount(float amount) {
    for (auto& v : voices_) {
        v.setFmAmount(amount);
    }
}

void CombiOscEngine::setFmRoute(FmRoute route) {
    for (auto& v : voices_) {
        v.setFmRoute(route);
    }
}

void CombiOscEngine::setSourceAParam(int paramId, float value) {
    for (auto& v : voices_) {
        v.setSourceAParam(paramId, value);
    }
}

void CombiOscEngine::setSourceBParam(int paramId, float value) {
    for (auto& v : voices_) {
        v.setSourceBParam(paramId, value);
    }
}

void CombiOscEngine::render(float* outMono, int numSamples) {
    std::fill(outMono, outMono + numSamples, 0.0f);
    for (auto& v : voices_) {
        v.render(outMono, numSamples);
    }
}

} // namespace osc
