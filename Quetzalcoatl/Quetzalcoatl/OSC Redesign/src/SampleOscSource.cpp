#include "SampleOscSource.h"

namespace osc {

void SampleOscSource::prepare(double sampleRate, int /*maxBlockSize*/) { sampleRate_ = sampleRate; }
void SampleOscSource::reset() {}
void SampleOscSource::start(const NoteEvent& /*note*/) {}
void SampleOscSource::release() {}
void SampleOscSource::setParam(int /*paramId*/, float /*value*/) {}
float SampleOscSource::renderSample(const ModFrame& /*mod*/) { return 0.0f; }

} // namespace osc
