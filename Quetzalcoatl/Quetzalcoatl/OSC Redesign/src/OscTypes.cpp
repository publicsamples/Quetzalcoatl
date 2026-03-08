#include "OscTypes.h"

namespace osc {

const Zone* MultiSampleMap::findZone(int midiNote) const {
    for (const auto& zone : zones) {
        if (midiNote >= zone.keyLow && midiNote <= zone.keyHigh) {
            return &zone;
        }
    }
    return nullptr;
}

} // namespace osc
