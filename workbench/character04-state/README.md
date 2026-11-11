# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** The original default and
**53 real live cases** are implemented in natural C++: 1–9,13–16,47,
50–77,81–87,96–99. The other 85 original live cases are unimplemented.
Throwaway compilation markers for them never count as authored source.

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

`[0x00607930,0x0060C81F)` = **20,207 native executable bytes**,
original SHA-256
`1f4e0c8bf16522d67bf8ebe7b298bc32d49fb97e8d9b7d88a4efdde377e1fa16`.
The 53 authored real states include a new 96–99 knockout/recovery
sequence: 96 restores standing/crouching face direction; 97/98
make genuinely independent ground impact effects and call the
native `SetVerticalShake(3,0)`; and 99 has an early health/pose/tick
recovery return **before** its frame counter increments. This last
return is required for exact native control-flow form and semantics.

Selected original-bound verification:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It checks **5,575 original x86 instruction positions, widths and
abstracted opcode forms**, **512 internal and 63 shared-return native
jump targets**, **500 original-bound direct calls / IEEE-754
references** plus two local selector/switch pointers, and exact
machine bytes elsewhere. The original-width six-byte stack
allocation still uses provisional `0xD4` rather than original
`0x2E8`; only this immediate, unclosed shared-return displacement
and independently native-bound COFF operands are excepted.

**Next real state150 starts at `0x0060C81F`.** IDs100–149 map to
original default. 85 live states, full stack frame, adjacent
jump table, selector bytes and final return are still OPEN.
**NOT whole-function Exact.** No cold all-unit replay and no
acceptance of compiler probe markers.
