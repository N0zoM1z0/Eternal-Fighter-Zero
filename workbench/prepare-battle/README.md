# `Scene2::PrepareBattle` — complete unaccepted C++ candidate

This directory is a **tracked, isolated natural C++ workbench** for the
complete resource/background/replay preparation owner `Scene2::PrepareBattle`.
Its local `SceneLoading.cpp`, `Engine.h`, `Input.h` and `Backgrounds.h`
preserve the candidate's provisional compilation context. Keep these views
separate from accepted `src/` headers and loading functions.
The accepted `src/SceneLoading.cpp` is a *different production owner*.
This draft is **not linked and not Exact**.

## Independently verified original target extent

The canonical `resources/EFZ.exe` owns exactly **4,029 bytes** starting at
`0x0076CA50` and ending at `0x0076DA0D`:

- **3,893 instruction bytes**: `[0x0076CA50, 0x0076D985)`;
- **100-byte switch-address table**: `[0x0076D985, 0x0076D9E9)`, 25
  distinct destinations, all real addresses inside the code extent;
- **20-byte switch-address table**: `[0x0076D9E9, 0x0076D9FD)`, five
  distinct, valid code destinations;
- **16-byte selector map**: `[0x0076D9FD, 0x0076DA0D)`, values
  `[0,4,4,4,4,4,4,4,4,1,4,2,4,4,4,3]` — 12 default entries.

The full original SHA-256 is
`1b529588799198f4fd6d913e877c029fe53e129cccb391a928cea0a1dae03d99`.
Three following `CC` bytes align the next loading keyboard owner at
`0x0076DA10`. This target-extent review is **not** a codegen match.

## Focused native build (without full cold replay)

```bash
scripts/repo-python - <<'PY2'
import sys
sys.path.insert(0,'scripts')
from common import ROOT
from native_build import compile_source
from coff import object_function
src = ROOT/'workbench/prepare-battle/SceneLoading.cpp'
obj = ROOT/'build/scene-loading/SceneLoading.tracked-workbench.obj'
compile_source(src, obj, ['/Od','/G6','/MT','/Gy','/GS','/W3'],
               ROOT/'.analysis/build/prepare-tracked-workbench.log')
code, rels = object_function(obj, '?PrepareBattle@Scene2@@QAEXXZ')
print(len(code), len(rels))  # 4031, 115; this is not Exact
PY2
```

The repaired draft now compiles reproducibly to **4,031 bytes and 112 COFF
relocations** under VC7.1; the target is 4,029 bytes. Three constructor calls
are deliberately emitted as raw `E8` sites and must be bound to the native
`LoadingBackground01` (`0x00751370`), `LoadingBackground10` (`0x00751A40`)
and `LoadingBackground16` (`0x00752900`) entry points. The first remaining
post-relocation mismatch is the `this` spill at `0x0076CA63`: candidate
`[ebp-0x78]` versus native `[ebp-0x6c]`. The later resource-load virtual call
still needs a strict receiver/register comparison. The two-byte owner-size
difference is not a permissible tail mask. Both switch tables must remain in
the strict comparison; never treat an apparent length match as byte-level proof.

### Targeted new source-form experiments

The first background allocation has been lowered to explicit allocation /
constructor sequencing while keeping the natural C++ owner. A previous
compiler-symbol call spelling for the three constructors did not compile under
VC7.1; those calls now use pinned raw `E8` operands, while the C++ allocation
literal is corrected to `0x1C`. The selected workbench translation unit builds
again. The candidate remains unaccepted and still needs the `this` spill and
later virtual receiver resolved.

Remaining tasks: restore the native `this` stack slot without changing the
rest of the frame; pin the later virtual-load receiver; materialize and verify
all 112 COFF relocations plus the three raw constructor calls; then compare
both address tables and selector byte-for-byte. Also reconcile the provisional
view with the current accepted header graph **by targeted consumers**, never
by overwriting `src/`.

## Reviewed authored boundary is separately registered

The direct original `Scene2::Step` call at `0x0076C8FD` and every byte
of the 4,029-byte function/tables were independently checked. The
reviewed boundary and authored origin now have formal registry entries
and a reproducible target-only certificate at
`docs/evidence/prepare-battle-boundary-review.json`. That progress
**does not** imply codegen Exact for this 4,031-byte draft.
