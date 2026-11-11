# Character04 Slot06 — original-bound 59,143-byte state boss workbench

**Status: PARTIAL, not whole-function Exact.** This workbench contains real
ordinary C++ for the original default handler and native live states **1–9, 13–16, 47 and 50–54**.
Only these physically reviewed cases are claimed in the selected prefix;
synthetic markers temporarily generated for the other 119 live case IDs are
**unaccepted diagnostics, not reconstructed source or acceptable byte padding**.

## Independently original-bound boundaries and dispatch

Original `EFZ.exe` vtable `0x00788B94` selects complete native
`Character04::Slot06` code `[0x00607930,0x00616037)` — **59,143 bytes**, SHA-256
`200261f2d50fa04663e62d285dd09cd0eeaf601fdee46e08b2798e8cf95b02a1`.
Adjacent, separately identified original switch data:

- `0x00616037..0x00616263`: **139 original four-byte destinations**
  (138 real live cases and the default branch)
- `0x00616263..0x006163A8`: **325 animation-ID selectors**;
  138 live IDs and 187 default IDs
- Original full-frame stack allocation: **`0x2E8`**
- Native shared return begins `0x00616033` (`mov esp,ebp; pop ebp; ret`)

The already-authored natural C++ is in `Character04State.cpp`. Pinned
VC7.1 `/Od /G6 /MT /Gy /W3` produces the original source structure
for default plus IDs 1–9, 13–16, 47 and 50–54: neutral, ±0.5 horizontal movement,
facing-to-opponent, three real aerial jumps (gravity0.035,
velocityY−2.7, forward/backward velocityX ±0.6), neutral recovery,
state8 recovery and falling-to-land motion. Cases13–16 add native
directional wakeup, dash-carry aerial takeoff, forward/backward air
velocity with facing-dependent release and strict frame-gated landing.
The real landing path
checks x87 `positionY+velocityY >=0`, resets pose, requests sound9,
selects state13 and preserves the original call ordering. Case47
restores a low airborne strike with landing impact and frame rewind;
cases50–54 implement five original grounded recoil/pushback tiers,
meter gains 10/15/20 and distinct -1.1/-1.5/-1.8 velocities,
resource drain and precise x87 wall-clamp calculations. The
original Character04 never clears dashMomentumFlag in these
recoil states, unlike the related Makoto owner.

## Strict selected-prefix check (fast and original-bound)

Run ONLY:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

The canonical continuous opening `[0x00607930,0x00608FAB)` covers
**5,755 native code bytes / 1,599 x86 instructions**, SHA-256
`85eb4668366cea69cd6c47b32c22bc2725fe84fa4193e3cafa166345807ad9f5`.
The checker compiles only the scope's candidate C++ and checks all
1,599 native instruction offsets, widths and opcode forms, all
**139 original in-prefix and 21 original shared-return branches**,
**162 independently original-bound native direct calls/IEEE-754
operands** and both **original local selector and jump-table pointers**.
It then compares every nonexceptional original machine-code byte.
There are **zero additional byte differences** after accounting for
*only* the temporary 3-byte shorter `sub esp,0x58` instruction
(the full owner uses the original same-function `0x2E8` allocation),
the still-outbound shared-return `JMP` displacement, and the
independently original-bound four-byte COFF relocation operands.

**Next live original case55 begins at `0x00608FAB`.** Remaining
119 authentic live case bodies, full original frame, all destination
table bytes and original shared-return closure are **OPEN**. This is
strict selected-prefix evidence, **NOT whole-owner Exact**. Never
mark marker branches or this workbench as accepted production source;
never run the cold all-unit replay for this research iteration.
