# Ikumi `Character14::Slot08` — natural C++ effect-state boss workbench

This is a **real partial reconstruction**, deliberately **NOT Exact**.
The correct owner is `Character14::Slot08`, not `Slot07`: the canonical
Character14 vtable begins at `0x00788D74`, and its **slot 8 pointer** at
`0x00788D94` points to original function `0x006AB060`. This slot was
independently verified rather than inherited from a previous guess.
The alternate pattern-bank file reader and resource wrapper are now
independently strict Exact in `src/Character14Loader.cpp`; those
acceptances do not cover this still-open effect-state boss.
The target body owns **1,592 bytes** (`[0x006AB060,0x006AB698)`),
ending in `RET` immediately before eight `CC` bytes and the separately
Exact `Character14::SetAlternateMode` at `0x006AB6A0`.

## Implemented source content

The new natural C++ workbench `Character14Effects.cpp` uses the accepted
`src/CharacterViews.h` rather than substituting old provisional class
headers. It implements these original branches:

- Enter state 300 when EX-mode state is 8, grounded, and action ID is
  below 8 but not 300, through ResetPose then ResetFrame.
- EX-mode 10 countdown, 186-tick color cycling, 17 independent
  `SetCharacterTint` events, trail-start and restoration of the saved
  pattern/sequence bank via the independently Exact `SetAlternateMode`.
- Five separate hit-effect groups for action IDs 201/202/205/208,
  231/234, 253/254/256/257, 255/258/266/267/272/273, and
  269/270/276/277. Each group selects its original effect type,
  opponent-height offset and one-shot counter gate.

First VC7.1 code-generation comparison identified a real semantic
source fix: the final EX countdown condition must be `field3150 <= 0`,
**not** `field3150 < 1`. The original uses `cmp ...,0; jg`; the
natural C++ now compiles to that exact original form. The instruction
sequence through most of the tint events and countdown is very close.

## Targeted compilation and remaining blocker

```
scripts/repo-python - <<'PY'
import sys
sys.path.insert(0, 'scripts')
from common import ROOT
from native_build import compile_source
from coff import object_function
source = ROOT/'workbench/ikumi-effects/Character14Effects.cpp'
obj = ROOT/'build/ikumi-effects/Character14Effects.partial.obj'
compile_source(source, obj, ['/Od','/G6','/MT','/Gy','/W3'],
               ROOT/'.analysis/build/ikumi-effects-workbench.log')
code, relocs = object_function(obj, '?Slot08@Character14@@UAEXXZ')
print(len(code), len(relocs))  # 1537, 33 — NOT Exact
PY
```

The current workbench compiles to **1,537 bytes and 33 COFF relocations**
versus original **1,592** bytes. All five original effect-spawn sites
load the opponent's X into the x87 stack *before* calling CRT `rand()`;
the present natural draft instead stores the converted random integer
without those x87 loads. That accounts for an important part of the
remaining gap, and source-level expression/evaluation order must be
investigated. It is **not** legitimate to substitute `x += rand()`
merely to obtain a 1,592-byte function: an independent experiment made
that gross length match while changing the original x87 instruction
sequence. The exact target SHA, vtable slot, source boundary and
alignment are retained in
`docs/evidence/ikumi-slot08-boundary-review.json`.

A full strict match unit with original relocation bindings and source
integration must only be created **after** the code/FP ordering is
verified; do not mark this function Exact or run a whole-game cold replay.
