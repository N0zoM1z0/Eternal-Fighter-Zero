# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** The workbench has original
default and **73 authentic live cases**, including native 161–171.
Sixty-five other real states are not yet reconstructed. The probe's
synthetic markers are compilation aids and never source credit.

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

`[0x00607930,0x0060E73D)` = **28,173 native code bytes**,
original SHA-256
`82eb27ca715820c331e1968ab61ba3b159e60c68eae9ff4249d65b2de05811fe`.
Source-authored original default plus **73 live cases**: 1–9,
13–16,47,50–77,81–87,96–99,150–158,161–171.

New 167–171 are real source: 167 uses `StartTrail(10)`, combo
resource transfer, tint, effect1 on pose1 and effect4 on pose2;
168/169 reset genuine physics and emit a ground effect, returning to
stand/crouch; 170 stores horizontal/vertical speed at 100x in child
fields, enters a 60-frame freeze and restores speeds at0.01x;
171 has the original two effects on *different* frames, and restores
saved velocity and gravity0.035 at the end. The sibling's pose0
single-effect branch was proven wrong and corrected by native compare.

Run only the target-scoped strict check:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It independently pins **7,758 original x86 instruction
positions/widths/register-abstracted forms**, **692 original internal
and 85 shared-return branch targets**, **728 original native COFF
calls/IEEE-754 operands**, and 2 local selector/jump-table pointers.
All other selected machine-code bytes match. Candidate six-byte
frame allocation still uses provisional `0x128` versus full
native `0x2E8`; exact original-bound COFF operands and unclosed
shared-return displacements are the only additional exclusions.

**Next original case180 starts at `0x0060E73D`**. The other 65 real
live cases and full native stack, table and return remain OPEN.
Selected-prefix proof, **NOT complete Exact**. Never count probe
marker cases or run full cold all-unit replay.
