# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current natural C++ `Character20State.cpp` now authors default and
**62 native-reviewed real cases**: 1–9, 13–16, 47, 50–77,
81–87, 96–99 and 150–158. Original continuous code
`[0x006429C0,0x006487A2)` = **24,034 bytes / 6,614 original x86
instructions**, SHA-256
`d19ab1094159f6437e5ff70ef1d63b41a9e78a1482dd84daf5d8766d2feb7bd3`.
Next original case is **161 at `0x006487A2`**.

The pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected native checker
matches **6,614 original instruction positions, lengths and forms**,
**605 internal branches**, **71 original outbound targets**,
**604 nonlocal original-bound call/IEEE-754 COFF references** and both
native switch-table address operands. The candidate still reserves
0xE4 stack bytes versus canonical 0x4A4, with identical six-byte
allocation instruction lengths and no offset normalization. This is
ONLY a strict selected prefix, not whole-function Exact. **74 cases**
remain absent; diagnostic neutral markers get no acceptance credit.

New reviewed cases150–155 implement independent crouch/standing
recoil variants with different meter values and X velocity
-1.5/-1.8/-2.3, wall/edge pushback, deceleration0.06 and animation
transitions. Case156 handles upward knockback; cases157/158 implement
positive/negative aerial effect attacks with gravity0.045 and local
state transitions. Crucially, original Kano states157/158 do **not**
clear `dashMomentumFlag`, and end in state9/ResetPose rather than the
Makoto-style `frame -= 2` loop. Every difference was resolved against
original machine code and IEEE-754 operand locations.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 161 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case161 `0x006487A2`**. Original
0x4A4 stack frame, 74 remaining native bodies, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
