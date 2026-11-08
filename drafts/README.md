# Provisional source drafts

Files in this directory are reconstruction work products and are not included in
any production or exact-match build. A draft may intentionally contain
unimplemented cases. Do not add a match-unit recipe or treat a successful compile
as semantic or code-generation proof until its target body, data ownership, and
relocations have been independently reviewed.
`Character03State.cpp` is the current natural-C++ reconstruction for Makoto's
`Character03::Slot06` (124 explicit animation cases plus fallback). The source
uses direct integer-to-double casts for the 178 x87 conversions and restores
the target's FPU `<= 0.0` comparisons rather than preserving Ghidra's boolean
XOR decomposition. It restores the target's branch layout in the large
animation groups, including explicit unsigned frame-index comparisons and
byte-counter increments. `SecondaryPose::field000c` is `unsigned short`,
matching target `MOVZX` loads. Opponent-owned `ResetFrame` and
`SetHorizontalShake` calls now pass the opponent as `this` where required.
The VC7.1 stack frame matches the target exactly (`0x378`), the 369 direct-call
sequence matches in order, and the emitted instruction body is now exactly
58,482 bytes, matching the target's extent. Per-animation size deltas remain
in `docs/evidence/makoto-slot06-case-deltas.csv`; several still differ and
cancel at function scope, so byte-for-byte identity is not yet claimed. The
draft remains excluded from the normal build until instruction-level
verification is complete.
