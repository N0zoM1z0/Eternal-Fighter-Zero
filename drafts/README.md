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
comparison now matches 92 of 124 animation blocks (register allocation and
branch destinations normalized); the other 32 remain under reconstruction.
Cases 4-6 now use unsigned-byte reads for `field0158`, and cases 200-206
reconstruct the charge/decay gate and frame transitions with matching
instruction shape.
This is not a claim of byte-for-byte identity.
