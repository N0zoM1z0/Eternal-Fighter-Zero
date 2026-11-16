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

The natural-C++ draft compiles reproducibly under VC7.1 to **4,031 bytes and
115 COFF relocations**; the canonical owner is 4,029 bytes. The candidate has
3,895 code bytes versus 3,893 native code bytes. All four stage constructors
are now ordinary C++ `new Background01/10/12/16(videoOwner)` expressions using
the reviewed `Backgrounds.h` class declarations. Their four constructor calls
are normal COFF REL32 relocations; there are no raw call operands, inline
assembly blocks, or `_emit` directives. The first `LoadResources` call is also
a normal C++ virtual call.

A focused relocation-bound comparison classifies **85 code relocations and
30 table relocations**. After binding those original operands, both switch
address tables and the 16-byte selector are byte-exact. The remaining code
comparison reports **269 differing bytes across 64 runs**; the first is at
`0x0076D744`, in the first background-constructor argument setup. The owner is
two bytes longer than native. These are still open strict-codegen differences,
not bytes to mask or overwrite. The workbench source currently contains no
inline assembly or emitted opcodes.

### Source-form experiments and remaining work

The previous local placeholder background classes were removed in favor of
the real `Background01`, `Background10`, `Background12`, and `Background16`
declarations from `Backgrounds.h`. This also replaced three raw constructor
call sites and the handwritten vtable dispatch with normal C++ expressions.
A trial using explicit placement-new locals expanded the frame and code, so it
was discarded; the simple typed `new` expressions are retained. A trial local
`Video *` alias also expanded the frame and was discarded.

Next, continue with C++-only experiments around constructor argument
expressions, temporary lifetimes, and the `LoadResources` virtual-call receiver.
Review each remaining mismatch against native disassembly, then materialize
all 115 relocations and retain the strict table/selector checks. Do not add
inline assembly, `_emit`, byte patches, or arbitrary normalization. Reconcile
the provisional view with accepted headers only through targeted consumers;
never overwrite `src/` wholesale.

## Reviewed authored boundary is separately registered

The direct original `Scene2::Step` call at `0x0076C8FD` and every byte
of the 4,029-byte function/tables were independently checked. The
reviewed boundary and authored origin now have formal registry entries
and a reproducible target-only certificate at
`docs/evidence/prepare-battle-boundary-review.json`. That progress
**does not** imply codegen Exact for this 4,031-byte natural-C++ draft.
