# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Natural C++ `Character20State.cpp` now authors default plus **81
reviewed original live states**: 1–9,13–16,47,50–77,81–87,
96–99,150–158,161–171,178,180, and 200–205. Contiguous native code
`[0x006429C0,0x0064A601)` covers **31,809 bytes / 8,718 original x86
instructions**, selected SHA-256
`91fff2a75dfbda84e04ca1d3a4fd4bb58ad3181ce85c3ead5d492051fd010725`.
Next state206 starts at **`0x0064A601`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` scoped checker verifies **8,718
original instruction forms/widths/offsets**, **803 internal and 102
outbound native branch targets**, **764 native-bound nonlocal COFF
call/IEEE-754 operands** and both original switch table pointers.
Candidate stack0x11C is incomplete against canonical0x4A4 but has
the same six-byte instruction width; no positional shift is allowed.
This is **NOT whole-function Exact**: **55 live cases** remain absent,
full stack/table/return still unverified. Generated diagnostic neutral
markers have no source or Exact credit.

Cases200–205 are six native-reviewed grounded dash attacks/cancels.
They use specific frame1/2/4 context sound20/21 and hit-count gates,
original jump cancel and grounded state0/3 recovery, plus different
frame<3/4/6 collision-reset thresholds. Several speculative meter
grants and local effects from related character templates are absent
from Kano original and were removed. State203 specifically requires
`attackCollisionResult==3` for jump cancellation, not `>=2`.
All native machine-code forms, float operands and calls are checked.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 206 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case206 `0x0064A601`**. Original
0x4A4 frame, 55 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
