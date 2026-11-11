# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Ordinary natural C++ in
`Character04State.cpp` now implements the original default and
**49 real live cases**: 1–9, 13–16, 47, 50–77, 81–87. The other
89 live cases are unimplemented. The build-only probe generates
marker cases strictly for local compilation, never accepted source.

## Original PE ownership and dispatch

- Original vtable pointer `0x00788B94` selects `0x00607930`
- Native owner `[0x00607930,0x00616037)` **59,143 code bytes**, SHA-256
  `200261f2d50fa04663e62d285dd09cd0eeaf601fdee46e08b2798e8cf95b02a1`
- Native pointer table `[0x00616037,0x00616263)`: **139 DWORD
  destinations**, one for each of 138 live states plus default
- Original selectors `[0x00616263,0x006163A8)`: **325 bytes**,
  138 live IDs, 187 default IDs
- Original full stack allocation is `sub esp,0x2E8`; the native
  shared epilogue at `0x00616033` is `mov esp,ebp; pop ebp; ret`

## Current audited continuous prefix

**`[0x00607930,0x0060C4E5)` = 19,381 original code bytes**,
canonical SHA-256
`c0a2283a2bebf8e901b85b35769abbe928813bb64912c2df36e5f85edf14d4f9`.
Original default and 49 physical native states cover movement,
three jump variants, grounded recovery, 12 grounded recoil tiers,
aerial hits, wall collision/rebound, multiple landing paths and
new cases81–87, which implement air lift, ground impact, sprite
bursts and their original timers. The native cases83–86 test and
write the actual character-local field at **offset `0x3154`**,
not the related character's `0x3144`; a small private local view
is used in this workbench to avoid changing accepted headers.

Original-bound selected compile and codegen audit:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It checks **all 5,340 original x86 instruction offsets, widths
and register-abstracted forms**, **494 exact original internal and
58 original shared-return branch targets**, **486 original-bound
COFF direct-call/IEEE-754 operands** plus two native local
selector/table address pointers. Every remaining selected opcode
byte matches. Candidate VC7.1 uses original six-byte stack
allocation width (`sub esp,0xC4` provisional vs original
`sub esp,0x2E8`); only this immediate, outbound return JMP
displacements and original-bound four-byte COFF fields are
excluded. No arbitrary missing-code masks or byte padding.

**Next native live case96 starts at `0x0060C4E5`**. IDs88–95
map to the native default. Other **89 real live cases**, full
original frame, adjacent switch and selector data, final return,
and eventual full-byte Exact closure are still OPEN. This is
strictly a selected-prefix **NOT whole Exact** certificate.
Do not run all-unit cold replay; never count generated probes.
