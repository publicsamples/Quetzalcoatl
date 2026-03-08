# CombiOsc MVP Spec

## Voice Model
- Polyphonic `CombiOscEngine`
- Per voice: `CombiOscVoice` with `OscA` + `OscB`
- Per-source mode switch among VA / WT / SAMPLE / MULTISAMPLE

## Multisample Constraints (MVP)
- Key-range zone lookup only
- Root note transpose
- Loop enabled/disabled per zone
- No RR, no velocity layers, no keyswitching

## Render Path (MVP)
- Start both oscillators on note-on
- Apply FM route (`OFF`, `A_TO_B`, `B_TO_A`)
- Blend with `mix` (`0 = A`, `1 = B`)
- Apply amp envelope and voice gain

## Non-goals (MVP)
- Disk streaming
- SFZ/HISE parser compatibility
- Advanced anti-aliasing / mipmaps
