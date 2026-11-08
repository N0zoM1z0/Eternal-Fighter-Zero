# Provisional source drafts

Files in this directory are reconstruction work products and are not included in
any production or exact-match build. A draft may intentionally contain
unimplemented cases. Do not add a match-unit recipe or treat a successful compile
as semantic or code-generation proof until its target body, data ownership, and
relocations have been independently reviewed.
`Character03State.cpp` is the first complete natural-C++ pass for Makoto's
`Character03::Slot06` (124 explicit animation cases plus fallback). It builds
with the pinned VC7.1 compiler, but its 77,210-byte function is larger than the
58,482-byte target code. It is a working reconstruction draft, not a match unit;
stack lifetime, helper-expression shape, and code generation remain under active
comparison. The per-call `_ftol2` classification is in
`docs/evidence/makoto-ftol2-call-map.csv`.
