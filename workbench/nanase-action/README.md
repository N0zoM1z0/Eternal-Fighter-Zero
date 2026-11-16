# Nanase Character00::Slot04 — accepted strict natural-C++ boss

The complete native `Character00::Slot04` owner at `0x0048ACA0` (11,424 bytes,
original vtable slot4 at `0x00788344`) has now been promoted to **accepted
ordinary C++** in `src/Character00Action.cpp`. The pinned VC7.1 normal-COFF
selected replay reports **11,424/11,424 bytes Exact**, zero differences and
**93/93 original-bound relocations** (39 buffered-button clearing calls,
4 facing calls, 50 floating literals). See the authoritative
`docs/evidence/character-00-slot04-exact.json` and formal matching recipe
`config/match-units.toml` (`character-00-slot04`). No inline assembly,
artificial instruction emission or padding was used.

`Character00Action-natural.cpp` remains as the exploratory workbench history.
It reconstructs all 39 action paths, Nanase's bank0/bank1 command priorities,
separate air recovery, and special projectile-action fallthrough. The decisive
natural codegen corrections were the short-circuit ordering of original
sequence-duration and active-state eligibility guards in the `0x70`, `0x15`,
`0x20`, `0x0C` and `0x48` action families. Earlier intermediate artifacts
were 918, 668 and 252 relocation-bound differing bytes; all reached zero
without manually changing compiled machine code.

Only this workbench TU may be rebuilt diagnostically with:

```bash
scripts/repo-python workbench/nanase-action/verify_action_progress.py --rebuild
```

The diagnostic proof is `docs/evidence/nanase-slot04-natural-progress.json`.
The **accepted** strict replay is instead:

```bash
scripts/repo-python scripts/replay-exact-units.py --unit character-00-slot04
scripts/repo-python scripts/validate-tracking.py --check-proofs --unit character-00-slot04
```

The other Nanase Slot05/Slot06/Slot07 bosses remain open; no full all-unit cold
replay was performed.
