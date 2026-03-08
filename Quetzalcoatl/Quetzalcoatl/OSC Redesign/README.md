# OSC Redesign

This folder contains all work for the new dual-source combi oscillator redesign.

## Scope (MVP)
- Dual source (`OscA`, `OscB`) per voice
- Modes per source: `VA`, `WT`, `SAMPLE`, `MULTISAMPLE`
- Shared controls: `mix`, `fmAmount`, `fmRoute`
- Multisample support: key-range mapping + root note + loop on/off

## Layout
- `include/`: public engine headers
- `src/`: engine implementation stubs
- `tests/`: lightweight checks (to be added)
- `docs/`: design docs

## Xcode setup
1. Generate Xcode project files:
   - `cmake --preset xcode-debug`
2. Open the generated project:
   - `OSC Redesign/build-xcode/OSCRedesign.xcodeproj`
3. Build from terminal (optional):
   - `cmake --build --preset xcode-debug`
4. Run smoke test from terminal:
   - `OSC Redesign/build-xcode/Debug/osc_smoke_test`

## Hear audio now (macOS)
1. Build standalone target:
   - `cmake --build --preset xcode-debug --target osc_standalone`
2. Run standalone oscillator:
   - `OSC Redesign/build-xcode/Debug/osc_standalone 10`
3. Optional duration argument:
   - Pass seconds as argv[1], eg `osc_standalone 30`

## Test UI app (macOS)
1. Build the UI target:
   - `cmake --build --preset xcode-debug --target osc_ui`
2. Run the UI app:
   - `open \"OSC Redesign/build-xcode/Debug/osc_ui.app\"`
3. Controls included:
   - `Play` toggle
   - `Trigger` button
   - `Mix A/B` slider
   - `FM Amount` slider
   - `FM Route` menu
   - `Osc A Wave` menu
   - `Osc B WT Position` slider
   - live waveform display panel
