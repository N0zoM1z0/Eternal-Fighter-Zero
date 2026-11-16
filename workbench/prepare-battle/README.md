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
print(len(code), len(rels))  # 4029, 115; this is not Exact
PY2
```

The natural-C++ draft compiles reproducibly under VC7.1. Its current best
source form is **4,029 bytes with 115 COFF relocations**, exactly the original
owner extent: **3,893 code bytes plus 136 switch-table/selector bytes**. All
four stage constructors are ordinary C++ new Background01/10/12/16(videoOwner)
expressions using the reviewed Backgrounds.h class declarations. Their
constructor calls are normal COFF REL32 relocations; there are no raw call
operands, inline assembly blocks, or _emit directives. Both LoadResources
expressions are ordinary C++ virtual calls.

A source-order experiment changed the scale assignment from if/else to a
natural default-first form (backgroundScale = 1.0; if stage == 16, assign
0.125). The previous candidate was 4,031 bytes with 269 differing code bytes;
this candidate is exactly 4,029 bytes and, after materializing all 115 COFF
relocations, has **87 differing code bytes across 37 runs**. All 136 bytes of
both switch tables and the selector remain byte-exact. The first remaining
code difference is still at 0x0076D744, in constructor argument register
selection. This is a measured reduction, not an Exact certificate. Detailed
comparison: docs/evidence/prepare-battle-natural-cpp-progress-v2.json. Rebuild
and reproduce the complete relocation-bound comparison with:

    scripts/repo-python workbench/prepare-battle/compare_prepare_battle.py

The remaining differences are now localized by operation. Each of the four
background-constructor branches has the same stack temporary and native
constructor target, but the candidate rotates the three scratch registers
relative to native (for example native ECX/EDX versus candidate EDX/EAX at
0x0076D743). The first LoadResources virtual dispatch has one extra
`mov ecx, edx` immediately before the call; the second dispatch's complete
instruction sequence is byte-identical. The default-first scale assignment
closes the two-byte owner-extent gap, but its branch layout differs from the
native condition-first if/else. The if/else candidate retains the extra
two-byte receiver copy and is therefore 4,031 bytes; it is not accepted as a
better source form.

The four constructor leafs reached by this switch have also been independently
cold-built and strictly matched: **1,561/1,561 bytes**, **44 relocations**, zero
differences across `Background01`, `Background10`, `Background12`, and
`Background16`. Their native entry points are respectively `0x00751370`,
`0x00751A40`, `0x007520B0`, and `0x00752900`. Only these four selected units
were replayed. Evidence: `docs/evidence/prepare-battle-background-constructors-exact.json`.

The full four-stage polymorphic family is now covered as well: all **16
constructor/destructor/update/render functions**, **7,687/7,687 bytes**,
**123 relocations**, zero byte differences. Fifteen units pass the strict
replay workflow. `Background16::Update` is separately checked because VC7.1
assigned different names to five local COFF labels; every relocation site and
nonlocal symbol is identical, all five local target offsets match the recorded
native addresses, and the complete 604-byte relocated body is byte-exact.
No all-project cold replay was run. Evidence:
`docs/evidence/prepare-battle-background-family-exact.json`.

### Source-form experiments and remaining work

The previous local placeholder background classes were removed in favor of
the real Background01, Background10, Background12, and Background16
declarations from Backgrounds.h. This also replaced three raw constructor
call sites and the handwritten vtable dispatch with normal C++ expressions.
A trial using explicit placement-new locals expanded the frame and code, so it
was discarded; the simple typed new expressions are retained. A trial local
Video pointer alias also expanded the frame and was discarded.

The current best code-size candidate uses the default-first background-scale
assignment described above. The original if/else expression is retained in
the comparison build only; the tracked source uses the improved form. Both are
ordinary C++ and neither alters the native data tables. Additional C++-only
experiments covered alternate switch case order, explicit base qualification,
pointer/reference aliases, const/volatile member qualifiers, local lifetimes,
register hints, placement new, inline accessors, and targeted compiler flags.
None improved the relocation-bound candidate; variants that introduced
additional temporaries expanded the frame or code and were discarded.

The condition-first if/else source form is still useful diagnostically: it
produces 3,895 code bytes, and after a non-acceptance diagnostic alignment
that removes its extra two-byte receiver copy, 45 code bytes still differ.
It is not a valid owner candidate because its extent is two bytes too large.
The inverse-default spelling (assign 0.125, then override to 1.0 when the stage
is not 16) compiles to the same code as the retained default-first form.
Changing only braces, splitting the condition into two independent ifs, using
a ternary, or using a switch did not improve the comparison. /G5 and /Oy-
did not change the register rotation; /O1, /O2, and /Og produced
substantially shorter functions (2,184, 2,700, and 2,404 code bytes), so they
do not describe this target's build profile.

Next, continue from the reproducible comparison script and investigate the
source-level cause of the cyclic constructor/virtual-call register allocation.
Any new form must retain the complete owner extent and all 115 relocation
checks; compare all code bytes and both tables, not just instruction snippets.
Do not add inline assembly, _emit, byte patches, or arbitrary normalization.
Reconcile the provisional view with accepted headers only through targeted
consumers; never overwrite src/ wholesale.

## Reviewed authored boundary is separately registered

The direct original `Scene2::Step` call at `0x0076C8FD` and every byte
of the 4,029-byte function/tables were independently checked. The
reviewed boundary and authored origin now have formal registry entries
and a reproducible target-only certificate at
`docs/evidence/prepare-battle-boundary-review.json`. That progress
**does not** imply codegen Exact for this 4,029-byte natural-C++ candidate.
