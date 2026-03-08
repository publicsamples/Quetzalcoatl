#include "MultiSampleSource.h"

namespace osc {

void MultiSampleSource::prepare(double sampleRate, int /*maxBlockSize*/) { sampleRate_ = sampleRate; }
void MultiSampleSource::reset() { activeZone_ = nullptr; }
void MultiSampleSource::start(const NoteEvent& note) {
    activeZone_ = map_ ? map_->findZone(note.note) : nullptr;
}
void MultiSampleSource::release() {}
void MultiSampleSource::setParam(int /*paramId*/, float /*value*/) {}
float MultiSampleSource::renderSample(const ModFrame& /*mod*/) { return 0.0f; }

void MultiSampleSource::setMap(std::shared_ptr<const MultiSampleMap> map) {
    map_ = std::move(map);
}

} // namespace osc
