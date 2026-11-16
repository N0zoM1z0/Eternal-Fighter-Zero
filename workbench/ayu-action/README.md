# Ayu Character01::Slot04 — original-priority natural C++ workbench, OPEN

This is the next major Ayu owner after the formally accepted 4,482-byte
`Character01::Slot02` command recognizer. Original `Character01::Slot04`
starts at `0x006E84D0`, size **10,923 code bytes**, and virtual slot4 is at
`0x00788E5C`. The normal VC7.1 `/Od /G6 /MT /Gy /W3` candidate
`Character01Action-natural.cpp` compiles to **11,972 bytes** (delta +1,049),
with 102 normal COFF relocations; it is **not Exact**.

The candidate began with the shared Mayu action-selection control flow and
reconstructed the original first **ten high-priority Ayu command families**
from native disassembly/decompile. In native order these are `0x5D`,
`0x7A/79/78`, `0x70/6F/6E`, and `0x66/65/64`. This restores the original
first **eleven** post-ClearBufferedButtons state values in order:
`0xA7, 0x13E, 0x134, 0x133, 0x132, 0x12E, 0x12D, 0x12C, 0x13D, 0x13C,
0x13B`. The `0x70` family also changes state on aerial activation, preserving
original separate air/ground destinations. The source remains ordinary C++;
no compiler directives, ASM, `_emit` or opcode padding were used.

**Still unresolved:** the full native owner contains 38
ClearBufferedButtons calls, whereas the uncorrected later Mayu branches give
the candidate 43. Later input/air-action state families, all COFF targets,
control flow and byte layout must be reconstructed before strict acceptance.
Do not promote this workbench candidate to `src/`, `matches.csv`, or
`implemented.csv` and do not call it Exact just because the first states match.

Reproduce the scoped original-target audit without a full cold replay:

```bash
scripts/repo-python workbench/ayu-action/verify_action_progress.py --rebuild
```

Evidence: `docs/evidence/ayu-slot04-natural-progress.json`.
