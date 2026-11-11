# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Ordinary natural C++ in
`Character04State.cpp` implements the real native default plus **42
physical live cases**: 1–9, 13–16, 47, 50–77. The remaining 96 live
states are NOT implemented. Markers for those cases are generated *only*
for throwaway compilation probes; never count them as authored source.

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

**`[0x00607930,0x0060B7EC)` = 16,060 original native bytes**,
SHA-256 `5313d76de1f173dd6e6b414facae7df16ca810a1dab5b9f73c587f3ee4281b5e`.
Native default plus **42 reviewed real states** cover ground movement,
three aerial jump types, neutral/crouch recovery, low aerial impact,
12 distinct grounded recoil variations, airborne hit reactions with
-2/-4/-6 vertical clamps, true `CollisionSide` wall checks,
state70 wall-bounce impact and airborne-to-ground transitions.
States71–77 additionally restore high-gravity direct knockback,
grounded boundary pushback and three distinct 2.2-horizontal-speed
recoil attacks; Character04 does not clear dash momentum on these
recoil paths, unlike the related Makoto code.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected-only code verification:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

This checks **4,433 original x86 instruction offsets, widths and
opcode forms**, **418 original internal and 49 native shared-return
jump destinations**, **425 original-bound external direct-call /
IEEE-754 operands** and two native selector/table address pointers.
All other selected code bytes match exactly. The one incomplete-
function prologue reserves `0x9C` instead of native `0x2E8`, **but
both allocation instructions are six bytes** (no position shift).
The checker permits *only* this stack-allocation immediate, the
unresolved outbound shared-return displacement and independently
original-bound COFF operand bytes. No synthetic marker bodies and
no unreviewed opcode differences are accepted.

**Next real case81 starts at `0x0060B7EC`.** State IDs78/79/80 map
natively to default. The remaining **96 live cases**, native full
stack, adjacent switch tables, return/relocation closure and whole
Windows runtime remain OPEN. This is strictly SELECTED PREFIX,
**NOT whole Exact**. Do not run cold all-unit replay or accept probe
marker bodies as reconstruction.
