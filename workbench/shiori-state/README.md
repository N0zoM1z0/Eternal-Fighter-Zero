# Shiori / Character08::Slot06 — full natural C++ workbench (not Exact)

This **tracked, independent workbench** preserves the complete original-branch
natural C++ draft for Shiori's 134-case animation dispatcher and true default.
It is **not** a production source or an accepted match unit. The four local
files `ShioriState.cpp`, `CharacterViews.h`, `Engine.h` and `Input.h` come from
`.analysis/probes/shiori-state/` at the same SHA-256 and reproduce the earlier
parked best draft. In particular the local headers are *provisional views*,
not substitutes for the newer, accepted `src/` headers. Do not overwrite the
accepted headers with these older private copies. The code does not create
any new compiled production symbol until properly integrated.

## Original independently checked ownership

Target entry `0x004136D0` is the selected Character08 vtable Slot06 at
pointer address `0x00787E10` (not an inferred decompiler slot). The
complete function owns exactly **63,132 bytes**:

- Original x86 instructions: `[0x004136D0, 0x00422A11)` — **62,273 bytes**.
- 135-entry DWORD switch-address table: `[0x00422A11, 0x00422C2D)` — **540 bytes**.
- Animation-ID selector table for IDs 1–319:
  `[0x00422C2D, 0x00422D6C)` — **319 bytes**.

All 135 table destinations are distinct valid instruction addresses within
the original function and all 135 selector values 0–134 occur. Four `CC`
bytes align to the next constructor at `0x00422D70`. Target-owned SHA-256:
`b677461e2b0e0104de11fc3ed40c47545c86ea0f02c4d6dc68437e0ea475aded`.
These observations give boundaries and ownership, **not** Exact status.

## Reproducible selected VC7.1 workbench build

Only compile this one file — never replay the cold full-game suite:

```bash
scripts/repo-python - <<'PY2'
import sys
sys.path.insert(0, 'scripts')
from common import ROOT
from native_build import compile_source
from coff import object_function
src = ROOT/'workbench/shiori-state/ShioriState.cpp'
obj = ROOT/'build/shiori-state/ShioriState.tracked-workbench.obj'
compile_source(src, obj, ['/Od','/G6','/MT','/Gy','/W3'],
               ROOT/'.analysis/build/shiori-tracked-workbench.log')
code, relocs = object_function(obj, '?Slot06@Character08@@UAEXXZ')
print(len(code), len(relocs))  # 63133, 1374 — NOT Exact
PY2
```

The resulting complete COFF contribution is **63,133 bytes**, 1 byte longer
than the target, with 1,374 relocation sites. The initial code and most
individual cases have strong instruction-level matches, but **do not**
normalize/register-relabel the entire function and mark Exact: the original
byte mismatches beginning at `0x0041FC1E` in case 303 remain, along with
additional register and stack-temp differences in 303–309 and 312–318.
See the frozen `case-sizes-baseline.json` for all 134 per-case extents.
Specific size deltas are +1 in 307 and 308, -1 in 315, explaining the
net +1 result but **not** explaining all byte mismatches.

## New independently tested case-303 variants

A targeted VC7.1 experiment used the complete candidate source and only
modified the second pose/tick guard and adjacent counter increment in case
303. Seven natural formulations were compiled separately, without any
machine-code patching:

| Form | Complete code+table size | Finding |
| --- | ---: | --- |
| `if (pose == 3 && tick == 0)` | 63,133 | Same first divergence |
| Explicit inner `{}` | 63,133 | Same first divergence |
| `if (!tick)` | 63,133 | Same first divergence |
| Tick-first nested guard | 63,133 | Same first divergence |
| Tick-first combined guard | 63,133 | Same first divergence |
| `tick++` | 63,133 | Same first divergence |
| `tick = (unsigned short)(tick + 1)` | 63,132 | **Not accepted:** worsens the local opcode match dramatically |

At the first mismatch `0x0041FC1E`, the canonical source executes
`mov eax,[ebp-0x54]` and increments tick via `cx`; the archived VC7.1
draft loads `ecx` and increments via `dx`, with subsequent register-choice
differences. Matching *only* the 63,132-byte extent therefore does not
prove equivalent code. Real next tasks: reconstruct the register-life
source form for case 303 and independently review late cases 307, 308 and
315 before attempting complete relocation-bound Exact. Never mask bytes.

See `.analysis/probes/shiori-state/` for the original disassembly,
full normalized diffs, source attempts and unaccepted objects. They remain
preserved and were not overwritten during this work.
