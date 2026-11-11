# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Natural C++ reconstructs
original default and **81 real live cases**, now including 204–206.
The other 57 live IDs remain explicitly unimplemented. Temporary
compiler-probe markers are never accepted original source.

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

`[0x00607930,0x0060F331)` = **31,233 original machine-code bytes**,
SHA-256 `ad5046c133681bcb7af1523b647854cdb588acab526bb40b8ae34383badb023b`.
Native source has default and **81 reviewed real cases**: 1–9,
13–16,47,50–77,81–87,96–99,150–158,161–171,180,200–206.
Newest C++ states204–206 implement three distinct ground action
recovery tiers: original zero horizontal/vertical velocity,
down-input dash cancel with `field015c<3` and respective
collisionResult thresholds (>=2 vs ==3), meter5/13/25 on
frame1/1/3, sound21/20, pose10 character sound2 on 206,
pose<3 collision reset, and standing/crouching completion with
`FaceOpponent()` and `ResetPose()`. No unrelated Makoto dash-drag
logic was carried into these original Character04 branches.

Original-bound scope:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It validates **8,587 original x86 instruction positions/widths
and register-abstracted forms**, **786 native internal and 99
original shared-return branches**, **760 original-bound COFF
calls/IEEE-754 operands** and two local switch dispatch pointers.
Every other selected machine-code byte matches. Only original-
width provisional stack allocation `0x128` vs native `0x2E8`,
original-bound COFF fields and the still-outbound shared return
JMP displacements remain excluded. This remains a **selected
prefix, NOT a full native Exact**.

**Next real state207 starts at `0x0060F331`**; the other 57
original live cases, full stack, switch table, selector bytes and
final return are OPEN. No cold all-unit replay and no acceptance
of probe marker code.
