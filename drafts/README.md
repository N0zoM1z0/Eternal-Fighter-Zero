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
the opponent as `this` where required. The two early-return guards are one
short-circuit OR, matching the target's shared exit jump. All 124 explicit
animation blocks have the same byte extent as the target; dispatch prelude and
epilogue boundaries also align. The VC7.1 stack frame is `0x378`, the 369
direct-call sequence matches in order, and the emitted instruction body is
58,482 bytes, matching the target extent. A normalized instruction-sequence
comparison now matches all 124 of 124 animation blocks (register allocation,
branch destinations, and absolute constant addresses normalized).
Cases 4-6 use unsigned-byte reads for `field0158`; charge/decay groups 200-206
and 230-235, clamps 150-155, and large finisher groups 303-305 now match
instruction shape. Frame-band comparisons in 163/165/166 and 221/256-258,
plus the landing/throw transitions in 69-86 and 164/260, are also aligned.
Case 248 uses the positive short-circuit predicate for the opponent-height and
state-band gate, matching the target instruction shape.
This is not a claim of byte-for-byte identity.
