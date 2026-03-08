#include "WTOscSource.h"

#include <algorithm>
#include <cmath>

namespace osc {

void WTOscSource::prepare(double sampleRate, int /*maxBlockSize*/) { sampleRate_ = sampleRate; }
void WTOscSource::reset() { phase_ = 0.0f; }
void WTOscSource::start(const NoteEvent& note) {
    baseFrequencyHz_ = 440.0f * std::pow(2.0f, (static_cast<float>(note.note) - 69.0f) / 12.0f);
    active_ = true;
}
void WTOscSource::release() { active_ = false; }

void WTOscSource::setParam(int paramId, float value) {
    switch (static_cast<ParamId>(paramId)) {
        case ParamId::CommonGain:
            gain_ = std::max(0.0f, value);
            break;
        case ParamId::CommonCoarseSemitones:
            coarseSemitones_ = value;
            break;
        case ParamId::CommonFineCents:
            fineCents_ = value;
            break;
        case ParamId::WtPosition:
            tablePosition_ = std::clamp(value, 0.0f, 1.0f);
            break;
        default:
            break;
    }
}

float WTOscSource::computeFrequencyHz(float pitchModSemitones) const {
    const float tuneSemitones = coarseSemitones_ + (fineCents_ * 0.01f) + pitchModSemitones;
    return baseFrequencyHz_ * std::pow(2.0f, tuneSemitones / 12.0f);
}

float WTOscSource::renderSample(const ModFrame& mod) {
    if (!active_) {
        return 0.0f;
    }

    constexpr float kTwoPi = 6.28318530718f;

    const float frequencyHz = computeFrequencyHz(mod.pitchModSemitones);
    const float phaseIncrement = frequencyHz / static_cast<float>(sampleRate_);
    float modulatedPhase = phase_ + mod.phaseMod;
    modulatedPhase -= std::floor(modulatedPhase);

    const float sine = std::sin(kTwoPi * modulatedPhase);
    const float saw = (2.0f * modulatedPhase) - 1.0f;
    const float sample = ((1.0f - tablePosition_) * sine) + (tablePosition_ * saw);

    phase_ += phaseIncrement;
    phase_ -= std::floor(phase_);
    return gain_ * sample;
}

} // namespace osc
