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
required by this accepted recipe and included directly by its source. Keep it
until the helper is integrated with the shared class declaration. Individual
codegen exactness does not establish whole-program ODR/linkage correctness.

Focused check without a full cold replay:

```bash
scripts/repo-python scripts/build-match-unit.py --unit character-06-effect-proximity
scripts/repo-python scripts/compare-coff-function.py --unit character-06-effect-proximity
```
