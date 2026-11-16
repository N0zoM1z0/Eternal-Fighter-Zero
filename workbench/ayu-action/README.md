# Ayu Character01::Slot04 — accepted natural-C++ boss with historical workbench

The complete native owner `0x006E84D0` has **10,923 executable bytes**,
selected by original Character01 vtable slot4 `0x00788E5C`.
The **accepted** source is `src/Character01Action.cpp`, compiled with
pinned VC7.1 `/Od /G6 /MT /Gy /W3` to **10,923 / 10,923 bytes Exact** after
independent original binding of all **87 COFF relocation targets**: 38
`ClearBufferedButtons`, four `FaceOpponent` and 45 floating-literal operands.
The formal certificate is `docs/evidence/character-01-slot04-exact.json`.

`Character01Action-natural.cpp` is retained as an exploratory snapshot, not
the canonical complete source. Earlier restoration milestones recovered the
first 21 high-priority state transitions, all 38 original button clearing
states, Ayu-only airborne/ground A/B/C/D actions, air-dash counter increments,
and the shared-return shape. The final accepted source additionally restores
the native evaluation order in all seven remaining high-priority float/guard
comparisons. No ASM, `_emit`, handpatched opcode bytes or padding was used.

Diagnostic workbench audit (not the formal Exact certificate):

```bash
scripts/repo-python workbench/ayu-action/verify_action_progress.py --rebuild
```

Formal selected-only strict replay for the accepted source:

```bash
scripts/repo-python scripts/replay-exact-units.py --unit character-01-slot04
scripts/repo-python scripts/validate-tracking.py --check-proofs --unit character-01-slot04
```

Keep the history `docs/evidence/ayu-slot04-natural-progress.json` separate
from the accepted strict proof. Other Ayu Slot05/Slot06/Slot07 large owners
remain OPEN. No full all-unit cold replay was performed.
