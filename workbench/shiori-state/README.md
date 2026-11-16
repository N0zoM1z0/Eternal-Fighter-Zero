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
- **Case318:** the complete **725-byte** case body is byte-identical after
  materializing 12 COFF relocations (9 calls and 3 zero-valued float operands),
  two inline-assembly `__ftol2` calls, and eight native stack-temporary bytes.
- **Case319:** the complete **900-byte** case body is byte-identical after
  materializing 17 COFF relocations (6 calls and 11 float operands) and two
  native stack-temporary bytes.
- The final-image resolver restores the native `sub esp,0x384` frame from the
  compiler's `sub esp,0x35C`. Fifty-eight stack-slot operand bytes are restored
  only for independently disassembled conversion temporaries in
  cases310/311/312/313 and 318/319; every patch is checked against its native byte.
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
- **Case315:** the 26-byte sequence at `0x00421BEB` matches exactly, including
  `sub edx,0x3E8`.

Across the sixteen complete cases (300–313 and 318–319), **9,990 native code
bytes** are byte-exact after materializing **160 COFF relocations** (110 calls
and 50 float operands) plus ten raw `__ftol2` call operands. One additional
meter region in case315 contributes another **26 byte-exact bytes**. The
focused resolver restores the native frame and 58 individually checked
conversion-temp operand bytes; it does not mask arbitrary bytes.

## Remaining whole-function work

`audit_case_codegen.py` still reports **20/20 late-state normalized opcode
sequences** identical, and the candidate owner extent is now **63,132/63,132
bytes**. That audit normalizes GPR names and branch operands, so it is only a
diagnostic, not a strict byte certificate.

A focused per-case final-image comparison now finds sixteen whole cases
byte-exact: **300–313 and 318–319** (9,990 code bytes; 160 COFF relocations
plus ten pinned runtime calls). Cases **314–317** still contain
register-allocation byte differences. The meter arithmetic subregion of 315
is exact but its remaining case body is open. Next attack case314, then 315–317.
Do not call the whole boss Exact until all code bytes and all relocation
operands are strictly reconstructed.
