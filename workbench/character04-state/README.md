# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Ordinary C++ now covers
native default plus **84 authentic live IDs**: 1–9,13–16,47,50–77,
81–87,96–99,150–158,161–171,180,200–209. The other **54** native
live states remain OPEN; generated probe markers are never credited.

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

`[0x00607930,0x0060F8F1)` is **32,705 original code bytes**,
SHA-256 `a659a1ad2dc011fc1ede375151d918b3de76a1fce1f715ce696df2982440951c`.
The C++ is real source for default plus 84 reviewed live states.
Newest 207–209 are three distinct aerial cancel / hit behaviors;
207 grants meter5 at pose1, whereas 208 grants meter13 when the
animation advances to pose1, and 209 grants meter30 at pose1
**before landing**. All three use native aerial jump cancel
(airActionCount gate, down input and attack collision) and
correctly separate pose4 sound, ground contact to state13,
pose<3 collision reset and frame completion to state9.

Fast original-bound selected checker:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

The original-bound selected audit proves **8,978 original x86
instruction offsets/widths and register-abstracted forms**, **828
native internal and 108 native shared-return branches**, **766
original COFF direct-call / IEEE-754 references** and two local
native dispatch pointers. All other code bytes match. Only the
original-width provisional six-byte stack immediate (`0x128`
versus complete original `0x2E8`), unresolved shared-return JMP
displacements and independently original-bound relocation operand
fields are excepted; no skipped or padded reviewed code.

**Next original live case210 starts at `0x0060F8F1`.** Remaining
54 authentic live states, complete original frame, 139 native
switch addresses, 325 selector bytes and final shared return are
still OPEN. This is **selected prefix, NOT full Exact**. Never
count temporary compilation markers or run cold all-unit replay.
