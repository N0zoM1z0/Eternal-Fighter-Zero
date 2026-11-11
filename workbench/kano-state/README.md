# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The natural C++ workbench `Character20State.cpp` now has default and
**94 reviewed original live cases** through case221. The strict
original-bound selected code `[0x006429C0,0x0064BA44)` spans
**36,996 bytes / 10,146 x86 instructions**, prefix SHA-256
`1f758ffc2edf8a43b932af3ec38b959060d45503cee4152be367ba132a0e7349`.
The next native case230 starts at **`0x0064BA44`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` checker verifies all **10,146
instruction positions, widths and normalized forms**, **949 original
internal and 125 outbound jump targets**, **847 independently
original-bound COFF external calls/IEEE-754 references** and both
native switch pointers. Candidate stack0x130 vs original0x4A4 uses
the same six-byte prologue allocation width and no position shift.
This is selected prefix, **NOT full Exact**: **42 live native cases**,
full frame, adjacent switch tables and common return remain OPEN.
Generated neutral marker cases have no acceptance credit.

State220 (476 bytes) restores frame2 opponent grab/ground check, both
fighter pose/state changes, source effect at X+facing*35 and fixed
Y=-52, and recovery through state7/3. State221 (367 bytes) is the
original follow-through: at frame2 sets opponent **hitstopFrames=30**
(offset0x14A, *not* guardInputFrames), emits palette2 stage effect at
integer X+facing*74,Y-54, invokes accepted
`Secondary::ApplyDamage(1000,750.0)` (canonical 0x004105A0), then
sets opponent state63 and knockback X=-2,Y=-1.5. Original branch,
call, effect-field write and exit order were compared instruction-wise.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 230 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case230 `0x0064BA44`**. Original
0x4A4 frame, 42 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
