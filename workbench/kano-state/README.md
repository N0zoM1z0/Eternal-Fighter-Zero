# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Natural C++ at `Character20State.cpp` now contains the original
default and **75 native-reviewed live cases**: 1–9,13–16,47,
50–77,81–87,96–99,150–158,161–171,178,180.
The strict selected original `[0x006429C0,0x00649BF2)` spans
**29,234 code bytes / 8,023 original x86 instructions**, SHA-256
`5d52f335247c236154b01bf0e8e4b08c0dd62fcc00fcb13650fbe866ead6dc68`.
Next live state200 starts at **`0x00649BF2`**. Original state179 is
not live and naturally dispatches to the default case.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` scoped original comparison
verifies **8,023 instruction positions/widths/normalized forms**,
**716 canonical internal and 91 outbound jump targets**, **728
independently native-bound nonlocal COFF call/IEEE-754 references**
and both original local switch pointers. Partial candidate stack0x11C
still differs from original0x4A4 (equal 6-byte instruction width,
no position normalization). This is a **selected-prefix audit**, NOT
whole-function Exact. The remaining **61 original live cases** are
not verified; the probe's neutral markers have no acceptance credit.

New state178 (300 bytes) restores the original ground dash X−0.03
friction, clamp/clear-dash behavior, directional jump cancel into
4/5/6, and final state0 reset (not sibling state7). State180 (370
bytes) restores `StartTrail(2)`, gravity only while airborne, landing
skip to frame9, sound9, frame2 initial launch (−0.5,−1.0) with
gravity0.028, frame9→7 animation loop and original pose-reset/state0
exit order. The original IEEE-754 operand references and all control
flow instructions matched the compiled source. State179 is default.

Important Kano-specific differences from the related Makoto dispatcher:
case1/2 speed `+0.6`/`-0.6`, cases4/5/6 jump start at frame2
not3, gravity `0.025`, vertical launch `-2.2`, optional carry velocity
`0.3` in case4. Cases5/6 terminate with state9 and ResetPose,
unlike Makoto's trailing frame loop. Cases13–16 have Kano's
own grounded/airborne recovery: zero/±0.7 X speed at start, gravity
0.025 and Y=-2.2, optional dash X speeds 0.4 / 1.1, and landing
state13. All these values and source branches were checked against
original code positions and IEEE-754 values. Cases7/8 reset to
state0/3, and case9 applies gravity/landing to state13.

Run ONLY focused checks, not full cold replay:

    scripts/repo-python scripts/verify-target.py
    scripts/repo-python workbench/kano-state/check_prefix.py
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 200 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case200 `0x00649BF2`**. Original
0x4A4 frame, 61 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
