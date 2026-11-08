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
XOR decomposition. Seven conditional branch structures were inverted to match
the target's machine-code branch layout. The VC7.1 stack frame now matches the
target exactly (`0x378`), and the 369 direct-call sequence matches in order.
The emitted instruction body is 58,432 bytes versus 58,482 target bytes; the
remaining 50-byte difference is tracked per animation in
`docs/evidence/makoto-slot06-case-deltas.csv`. The draft remains excluded from
the normal build until byte-level verification is complete.

