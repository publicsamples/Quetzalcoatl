#include "CombiOscEngine.h"

#include <cmath>
#include <iostream>
#include <vector>

int main() {
    osc::CombiOscEngine engine;
    engine.prepare(48000.0, 128, 8);
    engine.noteOn(60, 1.0f);

    std::vector<float> buffer(128, 0.0f);
    engine.render(buffer.data(), static_cast<int>(buffer.size()));
    engine.noteOff(60);

    float magnitude = 0.0f;
    for (const float s : buffer) {
        magnitude += std::abs(s);
    }

    if (magnitude <= 0.0f) {
        std::cerr << "OSC redesign smoke test failed: silent output." << std::endl;
        return 1;
    }

    std::cout << "OSC redesign smoke test ran. Magnitude=" << magnitude << std::endl;
    return 0;
}
