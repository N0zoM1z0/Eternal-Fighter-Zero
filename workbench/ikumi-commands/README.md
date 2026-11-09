# Ikumi Slot02 — priority-ordered circular input history, partial natural C++

Original vtable slot 2 at `0x00788D7C` points to `0x006AB7E0`.
Its complete owner occupies **5,153 bytes** through exclusive
`0x006ACC01`; 15 following `CC` bytes align the next owner.
The original function has 15 separately ordered input scans.
The tracked `Character14Commands.cpp` currently reconstructs **three**
scans, covering 1,628 original bytes and 494 x86 instructions.
**It remains a workbench, not a full-function Exact match.**

## Source recovery

The selected VC7.1 compiler (`/Od /G6 /MT /Gy /W3`) reproduces every
one of the **494 original instructions**, including register choices,
stack-home offsets, immediate values and all condition/instruction
mnemonics, after normalizing **only** numeric branch destinations.
The first three original scans and their meanings:

| Scan | Original range | Bytes | Instructions | Recognition |
| --- | --- | ---: | ---: | --- |
| 1 | `0x006AB7E0..0x006AB9D3` | 499 | 153 | Ten-stage directional motion, command 0x5E |
| 2 | `0x006AB9D3..0x006ABC42` | 623 | 193 | 45–179-frame motion, base command 0x96 plus button flags, including the original early-finish and stage-5→8 path |
| 3 | `0x006ABC42..0x006ABE3C` | 506 | 148 | 90–179-frame charged motion, command 0xAA or early 0xA0 plus button flags |

Scan 3 permits the initial directional state only when either
`meter >= 1000` **or `field315c > 0`** — this Ikumi-specific override
was recovered from the target's integer comparison sequence, not
copied from another character. The 180-frame ring uses the original
signed 16-bit write cursor and a single wrap on reads.

The facing terms must preserve the precise original C++ distinctions:
`2 + (facing == -1 ? 0 : -1)` and `6 + (facing == -1 ? 0 : -1)`
are different from `2 - (facing == -1)` and
`6 - (facing == -1)`. An early guess based on a decompiler's Boolean
simplification reversed the direction and generated extraneous code;
the corrected native forms match the original instruction sequence.

## Focused check

```bash
scripts/repo-python workbench/ikumi-commands/check_first_scan.py
```

The check compiles only this translation unit with pinned VC7.1,
verifies the canonical EFZ.exe and asserts **494/494** instruction
matches under the stated branch-target normalization.
Because the other **12** scans are absent, the compiled temporary
function is **1,632 bytes**: the 1,628-byte original prefix followed
by a four-byte *temporary* shared epilogue. Branch destinations
throughout the final 5,153-byte owner cannot yet match. No byte
masking, claimed whole-function Exact or cold replay is involved.

Canonical full-owner and per-scan SHA-256 evidence is in
`docs/evidence/ikumi-slot02-command-scan-boundary.json`.
Next: start with the fourth scan at `0x006ABE3C`, then the remaining
priority-ordered scans; retain correct input priority and early returns.
