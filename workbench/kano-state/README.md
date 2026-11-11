# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Original default plus **90 native-reviewed live states** are now
authored through state214. The continuous canonical code
`[0x006429C0,0x0064B461)` is **35,489 native bytes / 9,734
original x86 instructions**, SHA-256
`99ceeb0cfe0ccd41d52f1aee9a60c8e6ad4f5f1ab236577254cfe39dbb2b8e9a`.
Next live original state220 starts at **`0x0064B461`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected code verifier checks
**9,734 original instruction positions/widths/normalized forms**,
**916 original internal and 120 outbound jump targets**, **813
nonlocal original-bound COFF call/IEEE-754 operands**, plus two
original local switch address references. The completed exact callee
`SecondaryEffectSlot::SetVelocityPolar` at **0x00434010** is now
original-bound in both newly authored native case bodies. The
incomplete source frame0x120 differs from original0x4A4 but has
the same six-byte allocation opcode; no position shifts are allowed.
**46 case bodies**, full native stack, switch DATA and return remain
OPEN: this is a SELECTED PREFIX, NOT full-function Exact.

Newly recovered states213 and214 are separate **373-byte original
polar-launch sequences**. They start with X/Y motion reset and one
hit on frame1, detect early ground contact and skip to frame5;
at frame3 they call the already exact member helper with original
parameters **(30.0°,2.2)** for state213 and **(45.0°,1.7)** for214.
On frame5 they loop back two poses, then perform the original
virtual ResetPose, set state7 and FaceOpponent call ordering. All
native x87 constants and direct REL32 helper targets are reviewed.

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

Next work begins at **Kano case220 `0x0064B461`**. Original
0x4A4 frame, 46 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
