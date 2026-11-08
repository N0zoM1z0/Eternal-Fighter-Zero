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
decomposition. `SecondaryPose::field000c` is `unsigned short`, matching target
`MOVZX` loads. Opponent-owned `ResetFrame` and `SetHorizontalShake` calls pass
the opponent as `this` where required. The two early-return guards are now one
short-circuit OR, matching the target's shared exit jump. All 124 explicit
animation blocks have the same byte extent as the target; dispatch prelude and
epilogue boundaries also align. Cases 50-61 now also match instruction shape
after normalizing registers and branch targets, including the nested x87 clamp
branches in 59-61. The VC7.1 stack frame is `0x378`, the 369
direct-call sequence matches in order, and the emitted instruction body is
58,482 bytes, matching the target extent. This is structural/extent alignment,
not a claim that every instruction byte is identical; normalized instruction-shape comparison currently identifies 74 of 124 cases
as identical; remaining differences are recorded in
`docs/evidence/makoto-slot06-instruction-diff-summary.json`.
