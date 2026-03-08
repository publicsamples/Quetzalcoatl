#pragma once

#include <cstdint>
#include <memory>
#include <vector>

namespace osc {

enum class SourceMode : uint8_t {
    VA,
    WT,
    SAMPLE,
    MULTISAMPLE
};

enum class FmRoute : uint8_t {
    Off,
    AToB,
    BToA
};

enum class Waveform : uint8_t {
    Sine,
    Saw,
    Square,
    Triangle,
    Noise
};

enum class ParamId : int {
    CommonGain = 1,
    CommonCoarseSemitones = 2,
    CommonFineCents = 3,
    CommonPhaseOffset = 4,
    CommonMix = 5,
    CommonFmAmount = 6,
    VaWaveform = 100,
    VaPulseWidth = 101,
    WtPosition = 200
};

struct NoteEvent {
    int note = 60;
    float velocity = 1.0f;
};

struct ModFrame {
    float pitchModSemitones = 0.0f;
    float phaseMod = 0.0f;
};

struct Zone {
    int keyLow = 0;
    int keyHigh = 127;
    int rootNote = 60;
    int sampleIndex = -1;
    int loopStart = 0;
    int loopEnd = 0;
    bool loopEnabled = false;
};

struct MultiSampleMap {
    std::vector<Zone> zones;

    const Zone* findZone(int midiNote) const;
};

} // namespace osc
