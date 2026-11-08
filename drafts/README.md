# Provisional source drafts

Files in this directory are reconstruction work products and are not included in
any production or exact-match build. A draft may intentionally contain
unimplemented cases. Do not add a match-unit recipe or treat a successful compile
as semantic or code-generation proof until its target body, data ownership, and
relocations have been independently reviewed.
`Character03State.cpp` is the current natural-C++ reconstruction for Makoto's
`Character03::Slot06` (124 explicit animation cases plus fallback). The source
uses direct integer-to-double casts for the 178 x87 conversions and restores
the target's FPU branch ordering rather than preserving Ghidra's boolean XOR
decomposition. The `SecondaryPose::field000c` frame counter is `unsigned
short`, matching target `MOVZX` loads. Opponent-owned `ResetFrame` and
`SetHorizontalShake` calls pass the opponent as `this` where required.
Animation groups 64-68, 83-84, 162, 170, 212 and 249 now have target-sized
blocks; the 212/162/170 landing branches use explicit function exits to retain
the target's near jump layout. The VC7.1 stack frame is `0x378`, the 369
direct-call sequence matches in order, and the emitted instruction body is
58,482 bytes, matching the target extent. Cases 300-302 remain one byte short
each while the dispatch prelude is three bytes longer, so function-size
agreement is not evidence of byte-for-byte identity. Per-animation deltas
remain in `docs/evidence/makoto-slot06-case-deltas.csv`; instruction-level
verification is still in progress.
