# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Workbench includes original
default and **78 real live cases**: 1–9,13–16,47,50–77,81–87,
96–99,150–158,161–171,180,200–203. Sixty real states still lack
source; generated probe markers are not accepted reconstruction.

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

Native `[0x00607930,0x0060EE5D)` = **29,997 original code bytes**,
canonical SHA-256
`c2a6e55016f6a67f58a6bc554cb34081263cedc8ece4141ad765f277ed3c6f66`.
Real source now has default and 78 true native live cases.
The new case180 uses native `StartTrail(2)`, a frame7 landing
interruption, x87 `positionY+velocityY > 0` condition, and delayed
−0.5/−1.0/0.028 impulse on frame2 (not the related character's
frame1/10). Cases200/201 check original down-input cancel and
pose1-specific meter +5/+15, instead of unrelated dash-deceleration;
case202 has distinct collisionResult3 and frame9 sound2, and case203
adds meter35 on pose2 and frame10 sound2, with original timer and
hit-count reset semantics.

Original-bound single-owner audit:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

Independently validates **8,259 original instruction offsets,
widths and register-abstracted forms**, **748 native internal and
93 original shared-return branches**, **751 original COFF
call/IEEE-754 operands** and two native switch local pointers.
Every other selected source opcode byte matches. Provisional
six-byte frame reserves `0x128` instead of complete original
`0x2E8`; only that immediate, original-bound relocation words and
still-outbound shared-return JMP displacements are excepted.
**Next real state204 at `0x0060EE5D`**; 60 real states and
full native stack/139-entry switch/325 selectors/return remain open.
This is **selected-prefix only, NOT whole-owner Exact**. Do not
run all-unit cold replay or accept synthetic marker source.
