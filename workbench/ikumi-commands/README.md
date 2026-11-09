# Ikumi `Character14::Slot02` — ordered input command recognition

This is a **tracked partial natural C++ reconstruction, NOT Exact**.
It targets the original Ikumi virtual slot 2 (pointer at `0x00788D7C`),
whose function begins at `0x006AB7E0` and owns **5,153 bytes** through
exclusive `0x006ACC01`, followed by 15 `CC` bytes before the next
original function. The canonical complete function and boundary are
recorded in `docs/evidence/ikumi-slot02-command-scan-boundary.json`.

## What has actually been recovered

`Character14Commands.cpp` implements the **first two priority-ordered
input-history scans**, with 346 original x86 instructions matched.

The first scan is the **highest-priority**
input-history scan**, reading 70–179 frames from the 180-entry circular
history, with ten stages and two finishing paths for recognized command
`0x5E`. It uses the real signed 16-bit history write index and a
modulo-180 wrap. The original first scan is **499 bytes / 153 x86 instructions** at
`[0x006AB7E0,0x006AB9D3)`. The second scans 45–179 frames and has
**623 bytes / 193 instructions** at `[0x006AB9D3,0x006ABC42)`;
it recognizes a button-flagged command with base ID 0x96 and retains
both original early-finish branches and the unusual stage-5 to
stage-8 transition. The two original scans together are **1,122
bytes / 346 instructions**.

Original disassembly, not a decompiler's Boolean simplification,
proved that the directional term must be
`2 + (facing == -1 ? 0 : -1)` or
`6 + (facing == -1 ? 0 : -1)`. This is respectively 2/6 when facing
is -1 and 1/5 otherwise. A first attempt with the opposite condition
changed the game's input semantics and generated 30 unnecessary code
bytes. The corrected natural C++ matches **all 346 original x86
instructions from both scans** after normalizing *only numeric jump
destinations*; no registers, immediates, stack-home offsets or branch
mnemonics are normalized away. The focused candidate compiles to **1,126 bytes**: the original
1,122-byte two-scan prefix plus an artificial four-byte shared-exit
epilogue. The original full function has **13 more priority-ordered
scans** before the shared epilogue. Its long
branch destinations necessarily differ until those scans exist.

## Reproduce without a cold replay

```bash
scripts/repo-python workbench/ikumi-commands/check_first_scan.py
```

This compiles only the local TU using pinned VC7.1 and reads the
canonical executable, then verifies both scans' 346-instruction
sequence. The original second-scan SHA-256 is
`f4eeecf8e53d97e964c42481798a090a8ef6f1168e55468c195abee8a92abc80`.
It does **not** prove full function code bytes, the missing scans,
or any whole-function relocation mapping. The source remains in
`workbench/`, not `src/` or the Exact function ledger. The next work is to reconstruct the third priority scan beginning
at `0x006ABC42`, then the other 12 scans, always preserving original
priority, signed facing expressions and early returns.
