#include "VAOscSource.h"

#include <algorithm>
#include <cmath>

namespace osc {

void VAOscSource::prepare(double sampleRate, int /*maxBlockSize*/) { sampleRate_ = sampleRate; }
void VAOscSource::reset() { phase_ = 0.0f; }
void VAOscSource::start(const NoteEvent& note) {
    baseFrequencyHz_ = 440.0f * std::pow(2.0f, (static_cast<float>(note.note) - 69.0f) / 12.0f);
    active_ = true;
}
void VAOscSource::release() { active_ = false; }

void VAOscSource::setParam(int paramId, float value) {
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
        case ParamId::VaPulseWidth:
            pulseWidth_ = std::clamp(value, 0.02f, 0.98f);
            break;
        case ParamId::VaWaveform: {
            const int wave = std::clamp(static_cast<int>(value), 0, 4);
            waveform_ = static_cast<Waveform>(wave);
            break;
        }
        default:
            break;
    }
}

float VAOscSource::computeFrequencyHz(float pitchModSemitones) const {
    const float tuneSemitones = coarseSemitones_ + (fineCents_ * 0.01f) + pitchModSemitones;
    return baseFrequencyHz_ * std::pow(2.0f, tuneSemitones / 12.0f);
}

float VAOscSource::renderSample(const ModFrame& mod) {
    if (!active_) {
        return 0.0f;
    }

    constexpr float kTwoPi = 6.28318530718f;

    const float frequencyHz = computeFrequencyHz(mod.pitchModSemitones);
    const float phaseIncrement = frequencyHz / static_cast<float>(sampleRate_);
    float modulatedPhase = phase_ + mod.phaseMod;
    modulatedPhase -= std::floor(modulatedPhase);

    float sample = 0.0f;
    switch (waveform_) {
        case Waveform::Sine:
            sample = std::sin(kTwoPi * modulatedPhase);
            break;
        case Waveform::Saw:
            sample = (2.0f * modulatedPhase) - 1.0f;
            break;
        case Waveform::Square:
            sample = (modulatedPhase < pulseWidth_) ? 1.0f : -1.0f;
            break;
        case Waveform::Triangle:
            sample = 1.0f - (4.0f * std::abs(modulatedPhase - 0.5f));
            break;
        case Waveform::Noise:
            noiseState_ = (1664525u * noiseState_) + 1013904223u;
            sample = (static_cast<float>((noiseState_ >> 9) & 0x7FFFFF) / 4194304.0f) - 1.0f;
            break;
    }

    phase_ += phaseIncrement;
    phase_ -= std::floor(phase_);
    return gain_ * sample;
}

} // namespace osc
