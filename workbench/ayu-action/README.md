# Ayu Character01::Slot04 — original-priority natural C++ workbench, OPEN

This is the next major Ayu owner after the formally accepted 4,482-byte
`Character01::Slot02` command recognizer. Original `Character01::Slot04`
starts at `0x006E84D0`, size **10,923 code bytes**, and virtual slot4 is at
`0x00788E5C`. The normal VC7.1 `/Od /G6 /MT /Gy /W3` candidate
`Character01Action-natural.cpp` compiles to **11,972 bytes** (delta +1,049),
with 102 normal COFF relocations; it is **not Exact**.

The candidate began with shared Mayu action-selection control flow, then
reconstructed Ayu's high-priority families in native order: `0x5D`,
`0x7A/79/78`, `0x70/6F/6E`, `0x66/65/64`. The second pass removed five
Mayu-only high-priority paths, inserted Ayu's extra `0x78` meter-3000
priority and recovered the original `0x16/15/14`, `0x20/1F/1E`, and
`0x0C/0B/0A` actions. The **first 21** native post-clear state IDs now
match in order, including the aerial alternate `0x10B` and the `0x70`
air/ground state variants. The source remains ordinary C++; no compiler
directives, ASM, `_emit` or opcode padding were used.

**Still unresolved:** the full native owner contains 38
ClearBufferedButtons calls, whereas this candidate has 39. The **10,963-byte**
code extent is just 40 bytes longer than the 10,923-byte native owner, but
later dash/air-action state families are misordered; original-bound COFF
targets, branch edges and all machine code still need strict verification.
Do not promote this workbench candidate to `src/`, `matches.csv`, or
`implemented.csv` and do not call it Exact just because the first states match.

Reproduce the scoped original-target audit without a full cold replay:

```bash
scripts/repo-python workbench/ayu-action/verify_action_progress.py --rebuild
```

Evidence: `docs/evidence/ayu-slot04-natural-progress.json`.
