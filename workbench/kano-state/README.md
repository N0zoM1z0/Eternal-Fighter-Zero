# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Original default and **86 native-reviewed live cases** are authored in
`Character20State.cpp`, including fully reconstructed 200–210.
The strict selected original prefix `[0x006429C0,0x0064AE89)` now
covers **33,993 native code bytes / 9,312 x86 instructions**, SHA-256
`bf13e6307f4f049a8b29077f0f818d6890542ebcf06c94dc115a4aa90d277411`.
Next original case211 starts **`0x0064AE89`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` scoped checker verifies **9,312
original instruction offsets, widths and normalized forms**, **870
internal and 113 outbound native jump targets**, **779 original-bound
nonlocal COFF call/IEEE-754 operands**, and both native local switch
address operands. Candidate stack0x120 versus canonical0x4A4 has
identical six-byte instruction width and no position normalization.
This is strictly a *selected code prefix*, NOT whole-function Exact:
**50 original case bodies**, full stack, adjacent jump tables and
shared return remain unresolved. Generated marker cases never count.

New state209 (605 bytes) is an original five-hit aerial combo: frame2
sets hit count5, frames7 and10 request sound20, and animation frames
7/9/11/13 re-enable the attack collision window; frame14 may loop
back seven frames once. It retains native jump cancellation and
landing to state13. State210 (337 bytes) resets the dash and frame,
then at frame8 emits local effect0x199 at X+facing*150,Y=-40,
increments field3138, requests character sound2, and **spends 20
meter**. Its last frame resets to state0. Both cases are original-
bound by instruction, branch target and IEEE-754/call reference.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 211 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case211 `0x0064AE89`**. Original
0x4A4 frame, 50 unverified live cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
