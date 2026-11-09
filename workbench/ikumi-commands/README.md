# Ikumi `Character14::Slot02` — ordered input command recognition

This is a **tracked partial natural C++ reconstruction, NOT Exact**.
It targets the original Ikumi virtual slot 2 (pointer at `0x00788D7C`),
whose function begins at `0x006AB7E0` and owns **5,153 bytes** through
exclusive `0x006ACC01`, followed by 15 `CC` bytes before the next
original function. The canonical complete function and boundary are
recorded in `docs/evidence/ikumi-slot02-command-scan-boundary.json`.

## What has actually been recovered

`Character14Commands.cpp` implements the **highest-priority first
input-history scan**, reading 70–179 frames from the 180-entry circular
history, with ten stages and two finishing paths for recognized command
`0x5E`. It uses the real signed 16-bit history write index and a
modulo-180 wrap. The original first scan is **499 bytes / 153 x86
instructions** at `[0x006AB7E0,0x006AB9D3)`.

Original disassembly, not a decompiler's Boolean simplification,
proved that the directional term must be
`2 + (facing == -1 ? 0 : -1)` or
`6 + (facing == -1 ? 0 : -1)`. This is respectively 2/6 when facing
is -1 and 1/5 otherwise. A first attempt with the opposite condition
changed the game's input semantics and generated 30 unnecessary code
bytes. The corrected natural C++ matches **all 153 original x86
instructions** after normalizing *only the numeric destinations of
jumps*; no registers, immediates, stack-home offsets or branch
mnemonics are normalized away. The focused candidate compiles to
503 bytes: the original 499-byte first scan plus an artificial
four-byte shared-exit epilogue. The original full function has **14
more priority-ordered scans** before the shared epilogue. Its long
branch destinations necessarily differ until those scans exist.

## Reproduce without a cold replay

```bash
scripts/repo-python workbench/ikumi-commands/check_first_scan.py
```

This compiles only the local TU using pinned VC7.1 and reads the
canonical executable, then verifies the 153-instruction sequence.
It does **not** prove full function code bytes, the missing scans,
or any whole-function relocation mapping. The source remains in
`workbench/`, not `src/` or the Exact function ledger. The next work
is to reconstruct the second 45–179-frame priority scan beginning
at `0x006AB9D3`, then proceed through the remaining command
patterns, always preserving original priority and early returns.
