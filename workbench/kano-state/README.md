# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The natural C++ `Character20State.cpp` now authors default plus
**84 native-reviewed original live cases**: 1–9, 13–16, 47,
50–77, 81–87, 96–99, 150–158, 161–171, 178, 180 and 200–208.
Selected canonical `[0x006429C0,0x0064AADB)` is **33,051 native
code bytes / 9,054 original x86 instructions**, SHA-256
`7f1ddb1d2c769fa91b8389f0f0a63a489676557567760d367132c7a0d7290d63`.
Next original case209 starts at **`0x0064AADB`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected checker verifies **9,054
original instruction forms, offsets and widths**, **841 internal and
109 outbound original branch targets**, **774 independently
original-bound nonlocal COFF call/IEEE-754 operands**, and both
native switch-table pointers. Candidate stack0x11C still differs
from native0x4A4 but uses the same six-byte instruction width;
no offset normalization is applied. This remains a SELECTED PREFIX,
**NOT full Exact**. 52 original state bodies, complete stack,
local switch data, remaining relocations and return are OPEN.
Generated marker cases do not count as authored reconstruction.

New cases206–208 recover Kano-specific aerial and grounded attack
windows. Case206 (303 bytes) is a crouch-sensitive grounded strike
with frame1 sound21, 1 hit and unconditional collision reset.
Case207 (447 bytes) implements aerial jump cancel, frame2 hit/sound21,
landing to state13 and a frame<3 attack collision reset. Case208
(492 bytes) implements a separate aerial combo: frame3 sound20 and
2 hits, frame8 additional sound20, plus frame4/9 collision reset
and landing/animation exit to state13/9. All original direct and
floating references are checked, not just opcode forms.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 209 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case209 `0x0064AADB`**. Original
0x4A4 frame, 52 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
