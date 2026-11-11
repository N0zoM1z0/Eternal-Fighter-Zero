# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Original default and **88 reviewed live states** are authored in
`Character20State.cpp`, through case212. Strict selected original
`[0x006429C0,0x0064B177)` covers **34,743 native code bytes /
9,524 original x86 instructions**, selected SHA-256
`529406942a44a20d95bf7b8f934066887a98ad43098216f625e6bb5da6d72bb0`.
Next original case213 begins **`0x0064B177`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` scoped checker matches **9,524
original instruction positions/widths/normalized forms**, **894
internal and 116 outbound original branch targets**, **795 native-
bound nonlocal COFF call/IEEE-754 operands** plus two original switch
pointers. Candidate frame0x120 differs from canonical0x4A4 but is
same-width six-byte instruction: no position compensation. This is
**selected-prefix evidence, NOT full Exact**. **48 original live
case bodies** plus full stack, local switch data, remaining relocation
closure and common return are still OPEN. Probe marker bodies are
never accepted as native source.

Newly recovered state211 (286 bytes) handles native frame0 velocity
reset, frame3 dual velocity 1.2 and frame1 one-hit count, landing to
state13, and original casted frame-decrement loop. State212 (464
bytes) implements a distinct dash continuation: frame0 velocity
friction0.03 if dashMomentumFlag set, frame1 +2.6 velocityX with
context sound20/hit1, further 0.03 decay and clamp, frame<2
collision clear, frame4->2 repetition up to three cycles controlled
by field3138, and original grounded state7/3 exit with
FaceOpponent/ResetPose call order. **Polar velocity helper0x434010
belongs to NEXT case213, not 212**; never conflate native boundaries.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 213 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case213 `0x0064B177`**. Original
0x4A4 frame, 48 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
