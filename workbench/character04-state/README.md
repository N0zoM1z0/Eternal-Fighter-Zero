# Character04 Slot06 — original-bound 59,143-byte state boss workbench

**Status: PARTIAL, not whole-function Exact.** This workbench contains real
ordinary C++ for the original default handler and native live states **1–9, 13–16, 47 and 50–70**.
Only these physically reviewed cases are claimed in the selected prefix;
synthetic markers temporarily generated for the other 103 live case IDs are
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
for default plus IDs 1–9, 13–16, 47 and 50–70: neutral, ±0.5 horizontal movement,
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
resource drain and precise x87 wall-clamp calculations. States56–58 return directly to the crouching state3; states
59–61 implement three distinct aerial hit reactions with native
-2.0/-4.0/-6.0 vertical velocity clamps, 0.032 gravity, frame
loop timing and conditional ground hit transitions to state97/98.
The original Character04 does not clear dashMomentumFlag in
the grounded recoil states, unlike the related Makoto owner.
States66/67 add native `CollisionSide` wall checks. States68/69
use direct knockback with ±landing recovery and state70 implements
a true wall-bounce: original resource/meter bookkeeping, 0.025
gravity, 0.5/-2.5 velocity, global impact effect and a landing
transition. Cases62–65 add unclamped/direct
knockback and wall-sensitive airborne collisions, including two
original `CollisionSide` calls, conditional state70 recovery and
native vertical clamps −2.0/−4.0.

## Strict selected-prefix check (fast and original-bound)

Run ONLY:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

The canonical continuous opening `[0x00607930,0x0060ACB7)` covers
**13,191 native code bytes / 3,669 x86 instructions**, SHA-256
`f8d8368e12a1d09811ed281cadf4f54e35646e61618124c4a735a74ca63881a0`.
The checker compiles only the scope's candidate C++ and checks all
3,669 native instruction offsets, widths and opcode forms, all
**342 original in-prefix and 42 original shared-return branches**,
**335 independently original-bound native direct calls/IEEE-754
operands** and both **original local selector and jump-table pointers**.
It then compares every nonexceptional original machine-code byte.
There are **zero additional byte differences** after accounting for
*only* the provisional `sub esp,0x84` versus native
`sub esp,0x2E8` *immediate operand* (both are six-byte instructions,
with no offset compensation), the still-outbound shared-return
`JMP` displacement, and independently original-bound four-byte
COFF relocation operands.

**Next live original case71 begins at `0x0060ACB7`.** Remaining
103 authentic live case bodies, full original frame, all destination
table bytes and original shared-return closure are **OPEN**. This is
strict selected-prefix evidence, **NOT whole-owner Exact**. Never
mark marker branches or this workbench as accepted production source;
never run the cold all-unit replay for this research iteration.
