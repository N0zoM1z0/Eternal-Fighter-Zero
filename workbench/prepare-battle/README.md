# `Scene2::PrepareBattle` — complete unaccepted C++ candidate

This directory is a **tracked, isolated natural C++ workbench** for the
complete resource/background/replay preparation owner `Scene2::PrepareBattle`.
It deliberately retains the earlier provisional `SceneLoading.cpp`,
`Engine.h`, `Input.h`, and `Backgrounds.h` views from the archived
`.analysis/probes/scene-loading/parked-best/` without overwriting the
currently accepted `src/` headers or the already-Exact loading functions.
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

The draft reproducibly emits **4,031 bytes and 115 relocations** under
VC7.1; the target is 4,029 bytes. `parked-best/prepare-instruction.diff`
retained privately has the first compiler register divergence at
`0x0076D743` while constructing the first background object. At a later
resource-load virtual call, the candidate adds a two-byte `mov ecx,edx`.
These are differences in the **complete owner**, not an acceptable
2-byte tail mask. Both switch tables must remain in a future strict
comparison. Never treat an apparent length match as byte-level proof.

### Targeted new source-form experiments

The first background allocation was compiled in six additional natural
forms: C-style pointer cast, explicit `this->videoOwner`, typed pointer
local, `const` typed pointer local, `void *` local, and explicit global
`::new`. The cast / `this` / global-new variants all retained 4,031
bytes and the same first register mismatch; introducing a named local
expanded the generated contribution to **4,045 bytes**, worsening the
codegen. None was copied into the tracked best candidate. The original
full C++ body remains intact for further work.

Remaining tasks: reproduce the original register allocation from the
new-background allocation through the later virtual-load call; strictly
bind all relocations and verify both address tables and selector before
accepting. Also reconcile the provisional view with the current accepted
header graph **by targeted consumers**, never by overwriting `src/`.
