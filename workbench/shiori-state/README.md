# Shiori / Character08::Slot06 — C++ workbench with pinned native regions (not whole-function Exact)

This **tracked, independent workbench** preserves the complete original-branch
C++ reconstruction for Shiori's 134-case animation dispatcher and true default.
Narrowly scoped inline-assembly regions now pin compiler-sensitive
native register sequences; this remains a workbench, not a production source
or an accepted whole-function match unit. The local
`ShioriState.cpp`, `CharacterViews.h`, `Engine.h` and `Input.h`
preserve the candidate's compilation context. Its headers are provisional;
keep them separate from the accepted `src/` headers.

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
scripts/repo-python workbench/shiori-state/audit_case_codegen.py --rebuild --start 300 --end 319
scripts/repo-python workbench/shiori-state/verify_exact_regions.py --rebuild
```

The complete COFF contribution is now **63,132 bytes**, exactly the native
function-code + table + selector extent, with **1,374 relocation sites**.
The 135 table destinations and all 319 selector bytes are exact. Matching
extent and dispatch data do not by themselves establish whole-function Exact.

## Focused byte-exact regions (2026-11-16)

`verify_exact_regions.py` independently rebuilds only the Shiori workbench TU,
then verifies selected code against the canonical PE. Its evidence is
`docs/evidence/shiori-slot06-exact-regions.json`.

- **Earlier selected groups:** 116 complete bodies across **1–9, 13–16, 47,
  50–77, 81–87, 96–99, 150–158, 161–171, 178, 180, 200–209, 220–221,
  230–235 and 248–270** are byte-exact. Together they contribute **49,063 unique
  native code bytes** and **1,014 body COFF relocations** (231 calls and 783
  float operands). This includes case203 at
  808 bytes, case252 at 909 bytes and case264 at 937 bytes; every call and
  float operand is bound to the canonical PE, not inferred from opcode similarity.
- **Case303:** the complete **611-byte** case body is byte-identical after
  materializing its **nine original-bound REL32 call operands**. This removes
  the former EAX/ECX/DX register-allocation cascade beginning at
  `0x0041FC1E`.
- **Case304:** the complete **796-byte** case body is byte-identical after
  materializing **nine original-bound REL32 calls**; its frame/loop/pose-reset
  tail is pinned to the native register sequence.
- **Case305:** the complete **846-byte** case body is byte-identical after
  materializing **ten original-bound REL32 calls**; its timed loop and reset
  tail now match natively.
- **Case312:** the complete **1,084-byte** case body is byte-identical after
  materializing **24 relocations** (11 direct calls and 13 original-bound
  floating-point operands).
- **Case317:** the complete **706-byte** case body is byte-identical after
  materializing six original-bound COFF calls and four pinned inline-assembly
  `__ftol2` calls. Its 3000-point cost, effect0x46/palette0x40, scene timer,
  capped local-effect pair, state8 threshold13 rollback, and terminal pose
  reset all match the native instruction order.
- **Case318:** the complete **725-byte** case body is byte-identical after
  materializing eight COFF relocations (five calls and three zero-valued float
  operands) and six pinned inline-assembly `__ftol2` calls. Its three-frame
  setup, dual effect pair, state11 local effect, and terminal frame reset are
  pinned directly to the native instruction sequence.
- The final-image resolver restores the native `sub esp,0x384` frame from the
  compiler's `sub esp,0x338`. Seventy-two stack-slot operand bytes are restored
  only for independently disassembled conversion temporaries in
  cases310/311/312/313/314/315/316; every patch is checked against its native byte.
- **Case319:** the complete **900-byte** body is byte-identical after
  materializing **17 COFF relocations** (six calls and eleven float operands).
  The four named float constants and all zero operands bind to their original
  PE addresses; the opponent handoff, 0x168 charge counter, transition/shake
  calls, landing return and terminal frame rollback match instruction-for-instruction.
- **Case306:** the complete **567-byte** case body is byte-identical after
  materializing eight original-bound relocations (seven calls and one zero
  float operand); its 25-byte meter subtraction/store is included.
- **Case307:** the complete **542-byte** case body is byte-identical after
  materializing five COFF relocations (four calls and one zero float operand)
  and three raw `__ftol2` calls bound to the original runtime target; its
  25-byte meter subtraction/store is included.
- **Case308:** the complete **577-byte** case body is byte-identical after
  materializing six COFF relocations (five calls and one zero float operand)
  and three raw `__ftol2` calls bound to the original runtime target; its
  25-byte meter subtraction/store is included.
- **Case309:** the complete **293-byte** case body is byte-identical after
  materializing its two COFF calls (`ResetFrame` and `FaceOpponent`) and two
  raw `__ftol2` calls; its frame-completion tail already compiles exactly.
- **Case313:** the complete **1,085-byte** case body is byte-identical after
  materializing 24 original-bound COFF relocations (11 calls and 13 float
  operands) and restoring its twelve conversion-temp operand bytes; its
  dual-phase frame rollback is pinned to the native register sequence.
- **Case314:** the complete **1,119-byte** case body is byte-identical after
  materializing 25 original-bound COFF relocations (12 calls and 13 float
  operands) and restoring its eight conversion-temp operand bytes; its
  `field313c < 13` rollback tail is pinned to the native register sequence.
- **Case315:** the complete **672-byte** case body is byte-identical after
  materializing nine COFF calls and restoring eight conversion-temp operand
  bytes. Its meter subtraction, state8 loop (threshold5), four-frame rollback,
  and terminal FaceOpponent/virtual ResetPose path are all included.
- **Case316:** the complete **672-byte** body is byte-identical after binding
  nine COFF calls and restoring eight more conversion-temp operand bytes.
  The distinct 2000-point meter cost, effect0x45, local-effect pair and
  threshold8 loop all match the original instruction order.

The final-image resolver now reconstructs the complete **63,132-byte owner**
byte-for-byte. It covers the 174-byte entry/dispatch prefix, all 135 unique
switch destinations (136 selector IDs because 301/302 alias one default body),
62,099 unique case-body bytes, the 540-byte switch table and 319-byte selector.
All **1,356 COFF relocation sites** are classified and materialized exactly
once: 375 REL32 calls and 981 DIR32 operands. This includes 18 raw inline-asm
`__ftol2` calls, the two prefix runtime calls, two prefix local-address operands,
and all 135 switch-table entries. The source object's `0x338` frame is explicitly
restored to native `0x384`; 72 EBP-relative conversion-temp operand bytes are
individually checked and restored. No arbitrary code bytes are masked.

Resolved owner SHA-256: `b677461e2b0e0104de11fc3ed40c47545c86ea0f02c4d6dc68437e0ea475aded`
(native owner hash is identical).

The fourteen direct-call leaf dependencies have also been cold-built and
strictly compared as individually selected normal-COFF units: **1,966/1,966
native bytes**, **26 original-bound relocations**, zero differences. This set
covers the EffectSpawn constructor, local-effect defaults, facing/collision,
global effect emission, frame/tint/shake helpers, trail, scene timer, damage,
random range and transition request. Evidence:
`docs/evidence/shiori-slot06-leaf-dependencies-exact.json`. Only these fourteen
units were replayed; no full-project cold replay was run.

## Natural C++ conversion experiment — cases303–309 (2026-11-16)

`ShioriState-natural-cases303-309.cpp` is a separate full-translation-unit
copy of the current Shiori workbench. It preserves the surrounding compilation
context and changes only original cases303–309. All seven case bodies are now
ordinary C++: there is no `__asm` or `_emit` in those seven bodies. The other
cases in this copy remain the pre-existing pinned workbench source; this is a
scoped conversion experiment, not a natural whole-function source or an Exact
claim. The file is unchanged outside those seven case bodies relative to
`ShioriState.cpp` apart from trailing-whitespace normalization.

Built only this TU with VC7.1 `/Od /G6 /MT /Gy /W3`. The candidate owner is
63,151 bytes (62,292 code + 540 table + 319 selector) versus the native
63,132 bytes (62,273 code + 540 table + 319 selector). Per-case comparison:

| Case | Native bytes | Candidate bytes | Native / candidate instructions | COFF relocations | Result |
| --- | ---: | ---: | ---: | ---: | --- |
| 303 | 611 | 611 | 160 / 160 | 9 / 9 original-bound | No width differences; 11 GPR-abstracted instruction differences remain |
| 304 | 796 | 796 | 203 / 203 | 9 / 9 original-bound | No width differences; 11 GPR-abstracted instruction differences remain |
| 305 | 846 | 846 | 217 / 217 | 10 / 10 original-bound | No width differences; 11 GPR-abstracted instruction differences remain |
| 306 | 567 | 567 | 149 / 149 | 8 / 8 original-bound | No width differences; 10 GPR-abstracted instruction differences remain |
| 307 | 542 | 543 | 144 / 144 | 8 / 8 original-bound | One instruction-width byte and register differences remain |
| 308 | 577 | 595 | 154 / 157 | 11 present, not yet fully bound | Three extra instructions; alignment and codegen remain open |
| 309 | 293 | 293 | 80 / 80 | 4 / 4 original-bound | No width differences; 8 GPR-abstracted differences remain |

The original-bound calls include all nine case303 relocations, all nine
case304 relocations, all ten case305 relocations, the three `__ftol2`
conversions in case306, three in case307, and two in case309; these are ordinary
compiler-generated COFF relocations, not inline assembly. The case308
conversions are also normal COFF calls, but its changed instruction layout
means its relocation mapping still needs a dedicated alignment review. None of
these seven cases is promoted to the Exact ledger. Continue by resolving
natural source/register and local stack-lifetime differences, not by adding
assembly or padding.

## Remaining source-object work

The complete resolved final image is now byte-for-byte equal to the canonical
63,132-byte PE owner. This is stronger than the previous selected-case proof:
all 135 unique case destinations, entry/dispatch bytes, table, selector and all
1,356 COFF relocation sites are covered.

The remaining gap is source-object Exact rather than target-byte coverage. The
VC7.1 object still needs two explicit normalizations before it equals the
native owner: the compiler emits a `0x338` stack frame instead of `0x384`, and
72 conversion-temp operand bytes use different EBP offsets. Eighteen inline-
assembly `__ftol2` calls also need their raw rel32 operands materialized from
the canonical image. Keep these transformations explicit and individually
validated; do not relabel the unmodified object as source-object Exact.
