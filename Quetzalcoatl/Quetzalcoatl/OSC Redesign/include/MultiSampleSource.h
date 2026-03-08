#pragma once

#include "IPlayableSource.h"

namespace osc {

class MultiSampleSource final : public IPlayableSource {
public:
    void prepare(double sampleRate, int maxBlockSize) override;
    void reset() override;
    void start(const NoteEvent& note) override;
    void release() override;
    void setParam(int paramId, float value) override;
    float renderSample(const ModFrame& mod) override;

    void setMap(std::shared_ptr<const MultiSampleMap> map);

private:
    double sampleRate_ = 48000.0;
    float gain_ = 1.0f;
    std::shared_ptr<const MultiSampleMap> map_;
    const Zone* activeZone_ = nullptr;
};

} // namespace osc
