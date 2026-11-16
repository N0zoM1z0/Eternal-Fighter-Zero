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

- **Earlier selected groups:** 102 complete bodies across **50–77, 81–87,
  96–99, 150–158, 161–171, 178, 180, 200–209, 220–221, 230–235 and 248–270**
  are now byte-exact. Together they contribute **45,788 native code bytes**
  and **944 original-bound COFF relocations** (218 calls and 726 float
  operands). This includes case203 at 808 bytes, case252 at 909 bytes and
  case264 at 937 bytes; every call and float operand is bound to the canonical
  PE, not inferred from opcode similarity.
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

Across the one hundred twenty-two complete cases (50–77, 81–87, 96–99,
150–158, 161–171, 178, 180, 200–209, 220–221, 230–235, 248–270 and 300–319),
**58,947 native code bytes** are byte-exact after materializing **1,149 COFF
relocations** (360 calls and 789 float operands) plus eighteen raw `__ftol2`
call operands. The focused resolver restores the native frame and 72
individually checked conversion-temp operand bytes; it does not mask arbitrary
bytes. No separate meter-only region is counted because all reviewed meter
instructions are inside complete case bodies.

## Remaining whole-function work

`audit_case_codegen.py` still reports **20/20 late-state normalized opcode
sequences** identical, and the candidate owner extent is now **63,132/63,132
bytes**. That audit normalizes GPR names and branch operands, so it is only a
diagnostic, not a strict byte certificate.

A focused per-case final-image comparison now finds **122 of 134** whole cases
byte-exact across **50–77, 81–87, 96–99, 150–158, 161–171, 178, 180, 200–209,
220–221, 230–235, 248–270 and 300–319** (58,947 code bytes; 1,149 COFF
relocations plus eighteen pinned runtime calls). Twelve case bodies remain
open. Do not call the whole boss Exact until all code bytes and all relocation
operands are strictly reconstructed.
