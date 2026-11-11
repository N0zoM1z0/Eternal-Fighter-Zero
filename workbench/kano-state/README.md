# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The Kano `Character20State.cpp` partial natural C++ now has original
default plus **92 native-reviewed live cases** through 217.
Selected original code `[0x006429C0,0x0064B6F9)` is **36,153 bytes /
9,919 x86 instructions**, original-bound SHA-256
`58c95ff05ba4c1ab3f958141eed76816621bdc1dfb043a12725a69e8f40d70f6`.
Next **physical original case220** starts at `0x0064B6F9`.
Original live case215 at `0x0064B461` and217 at `0x0064B5D6`
were recovered; 216/218/219 are default IDs.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` checker verifies **9,919
original native instruction offsets/widths/forms**, **936 internal
and 123 outbound original branch targets**, **828 original-bound
nonlocal COFF calls/IEEE-754 operands** and both native original
switch pointers. Candidate frame0x120 differs from canonical0x4A4
but has a same-width six-byte allocation instruction; no position
normalization. Strict selected-prefix proof ONLY, NOT full Exact.
The **44 remaining live bodies**, canonical stack, original local
switch DATA, other relocations and common return are unresolved.
Unaccepted probe marker cases do not count as original source.

State215 (373 bytes) uses `SecondaryEffectSlot::SetVelocityPolar`
with authentic **(60°,1.5)** and repeats frame5->3, preserving the
original ground early landing and virtual pose/face return. State217
(291 bytes) handles actual dashMomentumFlag-dependent horizontal
friction0.03, frame4 sound20/one hit, collision clear below frame6,
and state0/FaceOpponent/ResetPose completion. These were compared
at every original opcode/branch/reference position, not inherited.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 220 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case220 `0x0064B6F9`**. Original
0x4A4 frame, 44 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
