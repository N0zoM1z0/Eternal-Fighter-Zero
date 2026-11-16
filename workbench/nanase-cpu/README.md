# Nanase Character00::Slot05 — natural C++ CPU boss, in progress

Canonical owner: `0x0048F690` with 14,102 executable bytes; Nanase vtable
slot5 at `0x00788348` selects that address. The current compiled natural-C++
prototype is `Character00Cpu-natural.cpp` and **must not be marked Exact**.

This began as a structural sibling to Mayu's already reconstructed
`Character05::Slot05`, preserving the shared CPU input reset, RNG selection,
movement and buffered-button logic. We then added authentic Nanase behavior
from the original executable/decompile rather than accepting the sibling's
character-specific choices:

- Mode-0 `0xFB` air-intercept command decisions based on opponent positive
  horizontal velocity, `[-280,-20]` and `[-220,-20]` height windows, and
  original random thresholds 2/30/10, producing commands 10/0xB/0xC.
- `0xA8` startup pressure decisions, including command `0x46`, the two
  Nanase-specific pattern banks and 201/202/205 counter-hit pulse choices.
  The original Secondary byte layout is respected: `inputX/inputY` live at
  `0x188/0x189`, while `buttonPulse[0..3]` begins at `0x18A` (these are
  **not** interchangeable). The distance tests are 40/60/80/120 and mode
  selects through child offset `0x344C`.
- `0xA8/0xA9` follow-up selector: six native close-range mode/charge actions
  (including `0x14/0x0C/0x20/0x6E/0x64`), plus direct 160/220-distance
  mid/far special choices, with original ordered `RandomRange` tests.
- `0xAA` one-frame startup: native three pulse alternatives tied to vertical
  `[-60,0)` displacement, distance 80/100, and mode-0 bank eligibility.

All 13 relevant original IEEE-754 double constants are verified directly
in EFZ.exe by the focused audit, not guessed from convenient numeric values.

Current pinned VC7.1 `/Od /G6 /MT /Gy /W3` candidate: **15,173 bytes** versus
14,102 original (+1,071). The natural compiler frame is **0xE0** vs native
**0xEC**, with 298 normal COFF relocations. The size increased because actual
Nanase-specific close/mid/far actions replaced the shorter Mayu-only code; this
is additional recovered behavior, **not** a byte-matching claim. Other Nanase-specific CPU action
branches and the natural stack-frame/codegen alignment still require serious
reconstruction. This is source-level progress, not whole-owner byte parity.
No ASM, artificial padding or emitted opcodes are present.

Rebuild/audit only this translation unit:

```bash
scripts/repo-python workbench/nanase-cpu/verify_cpu_progress.py --rebuild
```

Diagnostic evidence: `docs/evidence/nanase-slot05-cpu-natural-progress.json`.
Keep the candidate separate from `src/`, `config/implemented.csv` and
`config/matches.csv` until selected-only strict native-bound Exact is achieved.
No full all-unit cold replay was run.
