# Nagamori nonvirtual effect proximity helper — independent exact owner

The complete original `Character06::MarkEffectCollision(short,short,short,short)`
function at `0x004AE1D0` has natural C++ in
`src/Character06Collision.cpp`. Its original unpadded length is
**231 bytes**, ending at `0x004AE2B7`, with nine following `CC` bytes.
The selected pinned VC7.1 COFF unit `character-06-effect-proximity`
strictly matches **231/231 source-code bytes**, zero differences,
and **two original-bound calls** to CRT `fabs` at `0x0077842D`.
The public proof is `docs/evidence/nagamori-effect-proximity-exact.json`.

`CharacterViews.h` in this directory is a *unit-isolated, same-object-size*
Nagamori class declaration, including this nonvirtual helper. It is
used only for compiling the original single source owner. Keeping this
private avoids changing the widely shared `src/CharacterViews.h` and
making 123 unrelated selected-unit source-dependency certificates
stale for a method whose object layout and vtable are unchanged.
Both source and class declaration are retained for audit; the original
partial `Character06Helper.cpp` is a historical equivalent TU.
This chosen isolation proves individual original machine-code and
relocation equivalence, **not** whole-program C++ ODR/linkage or game
runtime equivalence.

Focused check without a full cold replay:

```bash
scripts/repo-python scripts/build-match-unit.py --unit character-06-effect-proximity
scripts/repo-python scripts/compare-coff-function.py --unit character-06-effect-proximity
```
