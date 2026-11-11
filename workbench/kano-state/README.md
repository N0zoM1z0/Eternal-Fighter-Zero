# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current natural C++ `Character20State.cpp` has original default and
**66 native-reviewed live case bodies**: 1–9, 13–16, 47,
50–77, 81–87, 96–99, 150–158 and 161–164. Original code
`[0x006429C0,0x00648DC5)` = **25,605 native bytes / 7,045 x86
instructions**, SHA-256
`5b9690a14e9d7ce276f2d6e7df577e26f7c72d5c03d6565ae12d8e3a3293a514`.
Next native case **165 starts `0x00648DC5`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected native checker matches
**7,045 instruction positions, widths and normalized opcodes**,
**642 internal and 79 outbound original branch targets**, **632
independently original-bound nonlocal COFF call/IEEE-754 operands** and
both original switch address references. Incomplete candidate frame
0xF4 versus full original 0x4A4 has equal six-byte instruction length
and no offset compensation. This remains *selected-prefix evidence,
NOT full owner Exact*. 70 cases remain unreviewed/unimplemented.
Experimental source for 165–171 exists but is UNACCEPTED until each
body matches canonical native. The selective probe uses diagnostic
neutral markers for later cases and does not count them as source.

New cases161–164 are substantively Kano-specific: effect9 at Y−70,
frame4 and frame15 gates on the aerial launch, conditional frame>3
velocityX=1.5 and a three-frame rewind on forward dash, and the
native reverse dash with `StartTrail(2)`, X=-3.1, +0.04 friction,
ResetFrame and state0 stop. These were corrected against original
machine code, control flow and numeric constants, not assumed from
Makoto behavior.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 165 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case165 `0x00648DC5`**. Original
0x4A4 frame, 70 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
