# Ikumi `Character14::Slot02` — complete natural C++ input recognizer

**Accepted strict Exact.** The complete production source is
`src/Character14Commands.cpp`; this workbench retains the reconstruction
source and its focused regression check. Original Ikumi vtable slot 2
at `0x00788D7C` points to `0x006AB7E0`. The complete owner is
`[0x006AB7E0,0x006ACC01)`, **5,153 bytes**, followed by 15 `CC`
alignment bytes belonging to neither this function nor its source.

All **15 priority-ordered command-history scans** are reconstructed,
with signed-facing directional tests, a single 180-frame history
wrap, frame windows spanning 5–135 ticks, correct early return
priority, and the shared original function epilogue. The total is
**1,508 x86 instructions and 5,153 bytes**, with zero COFF
relocations and zero differing target bytes. Both original and
selected rebuilt SHA-256 are
`752ea6e701bca768800303e3a6a370d0d0ce8f17d238378528e2e8f678e1466c`.

## Original scan boundaries and meanings

| Scan | Original range | Bytes | Instructions | Notes |
| --- | --- | ---: | ---: | --- |
| 1 | `0x006AB7E0..0x006AB9D3` | 499 | 153 | Ten-stage directional combo, command 0x5E |
| 2 | `0x006AB9D3..0x006ABC42` | 623 | 193 | Priority combo with base 0x96 and early finish |
| 3 | `0x006ABC42..0x006ABE3C` | 506 | 148 | Charged special 0xAA/0xA0, meter or `field315c` gate |
| 4 | `0x006ABE3C..0x006AC046` | 522 | 157 | Meter-gated 4/6/2 chain, base 0x6E |
| 5 | `0x006AC046..0x006AC1D8` | 402 | 119 | Quick 60-frame motion, base 0x46 |
| 6 | `0x006AC1D8..0x006AC350` | 376 | 109 | 55-frame diagonal finish, base 0x14 |
| 7 | `0x006AC350..0x006AC4CB` | 379 | 109 | Mirrored diagonal, base 0x0A |
| 8 | `0x006AC4CB..0x006AC64E` | 387 | 113 | Mirrored diagonal, base 0x1E |
| 9 | `0x006AC64E..0x006AC6E3` | 149 | 40 | Five-tick button 8 release, command 6 |
| 10 | `0x006AC6E3..0x006AC7C6` | 227 | 63 | 0/4/0/4 followed by button 0x80, command 0x35 |
| 11 | `0x006AC7C6..0x006AC8A6` | 224 | 63 | Similar prefix followed by 0x40, command 0x34 |
| 12 | `0x006AC8A6..0x006AC987` | 225 | 63 | Similar prefix followed by 0x20, command 0x33 |
| 13 | `0x006AC987..0x006ACA68` | 225 | 63 | Similar prefix followed by 0x10, command 0x32 |
| 14 | `0x006ACA68..0x006ACB34` | 204 | 56 | Neutral/1/neutral/1, command 1 |
| 15 | `0x006ACB34..0x006ACBFD` | 201 | 56 | Neutral/2/neutral/2, command 0 |
| Exit | `0x006ACBFD..0x006ACC01` | 4 | 3 | Common epilogue |

The original signed-facing comparisons must retain their distinct C++
forms, such as `2 + (facing == -1 ? 0 : -1)` versus
`2 - (facing == -1)`. One decompiler reading initially reversed a
direction; the corrected source matches the full original instruction
and behavior. The original third scan additionally permits a 1,000
meter threshold **or** `field315c > 0`, unlike generic characters.

## Focused reproducibility

```bash
scripts/repo-python workbench/ikumi-commands/check_first_scan.py
scripts/repo-python scripts/build-match-unit.py --unit character-14-slot02
scripts/repo-python scripts/compare-coff-function.py --unit character-14-slot02
```

These compile only the named Ikumi translation unit under pinned
VC7.1, compare all original bytes and verify zero relocations. The
formal independent source receipt is
`docs/evidence/ikumi-slot02-exact.json`; original individual-scan
byte ranges and hashes remain in
`docs/evidence/ikumi-slot02-command-scan-boundary.json` for audit.
**This does not imply whole-game Windows linkage or runtime
comparison, nor does it repair unrelated older stale receipts.**
