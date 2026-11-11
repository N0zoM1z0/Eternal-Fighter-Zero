# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Authored natural C++ now
covers the original default and **62 authentic live IDs**: 1–9,
13–16,47,50–77,81–87,96–99,150–158. The remaining 76 native live
states are *not* reconstructed. Temporary probe markers are only
for compilation, never source acceptance.

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

`[0x00607930,0x0060D54B)` = **23,579 original code bytes**,
canonical SHA-256
`3530f7f8805f82b717c5a312271fa539d4bc482fd004ac3b63be39da25ba294f`.
The latest nine actual source branches implement native states150–158:
six ground/crouch recoil variants at different meter and velocity
tiers, one forward aerial hit, and two original air/impact stage-effect
variants. They preserve the original no-dash-reset behavior and
restore *state9 plus `ResetPose`* on animation completion for states
157/158, rather than a related character's two-frame rewind.

Run the independently pinned selected-only audit:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It checks **6,513 authentic original instruction offsets/widths and
register-abstracted opcode forms**, **598 internal and 72 shared-return
native jump targets**, **602 original-bound direct calls / IEEE-754
references** plus 2 original local dispatch pointers. All other
reviewed code bytes match. The original six-byte frame allocation
still reserves a provisional `0xE4` rather than original `0x2E8`;
only that immediate, incomplete original shared-return displacements
and independently target-bound COFF fields are excluded from raw
byte equality. No arbitrary padding or missing-code masking.

**Next native case161 starts `0x0060D54B`**; IDs159/160 map to
native default. The remaining **76 original live cases**, whole
frame, full 139-entry native switch/325 selectors and shared return
are still OPEN. Strict selected-prefix proof is **NOT full Exact**.
Never run cold all-unit replay or count marker source.
