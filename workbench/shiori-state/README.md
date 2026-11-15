# Shiori / Character08::Slot06 — C++ workbench with pinned native regions (not whole-function Exact)

This **tracked, independent workbench** preserves the complete original-branch
C++ reconstruction for Shiori's 134-case animation dispatcher and true default.
Eight narrowly scoped inline-assembly regions now pin compiler-sensitive
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

## Focused byte-exact regions (2026-11-15)

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
- **Case306:** the 25-byte meter subtraction/store sequence at `0x0042038B`
  matches exactly, including `sub eax,0x3E8`.
- **Case307:** the 25-byte sequence at `0x004205C2` matches exactly, including
  `sub eax,0x7D0`.
- **Case308:** the 25-byte sequence at `0x004207E0` matches exactly, including
  `sub eax,0xBB8`.
- **Case315:** the 26-byte sequence at `0x00421BEB` matches exactly, including
  `sub edx,0x3E8`.

Across the ten complete cases (300–305, 310–312 and 319), **6,201 native code
bytes** are byte-exact after materializing **103 relocations** (72 calls and
31 float operands). The four additional meter regions contribute another
**101 byte-exact bytes**. These eight narrowly scoped inline-assembly regions
recover compiler-sensitive register lifetimes; the rest of each case remains
ordinary C++. No bytes are padded or masked.

## Remaining whole-function work

`audit_case_codegen.py` still reports **20/20 late-state normalized opcode
sequences** identical, and the candidate owner extent is now **63,132/63,132
bytes**. That audit normalizes GPR names and branch operands, so it is only a
diagnostic, not a strict byte certificate.

A focused per-case relocation-materialized comparison now finds ten whole
cases byte-exact: **300–305, 310–312 and 319** (6,201 code bytes; 103 original-
bound relocations). Cases **306–309 and 313–318** still contain register-
allocation byte differences. The meter arithmetic subregions of 306, 307,
308 and 315 are already exact, but their remaining case bodies are open. Next
attack case306's register-lifetime differences, then 307–309 and 313–318. Do
not call the whole boss Exact until all code bytes and all relocation operands
are strictly reconstructed.
