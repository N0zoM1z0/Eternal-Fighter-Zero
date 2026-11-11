# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The authored natural C++ `Character20State.cpp` now reconstructs
default and **34 real reviewed cases** (1–9, 13–16, 47, 50–69).
Its continuous selected native code reaches **case70 at
`0x00645CB1`**, original `[0x006429C0,0x00645CB1)`:
**13,041 native bytes / 3,617 original x86 instructions**, SHA-256
`bf77cec9fa8cefb8e2eb0c62943e4906983342ba2ac6983a2ef3e37076385a5b`.

Canonical native stack is `sub esp,0x4A4`; the partial source still
compiles with a three-byte shorter `sub esp,0x7C` because 102 state
bodies are unimplemented. Normalizing ONLY that one 3-byte prologue
shift, selected checker validates **3,617 original instruction
positions, lengths and forms**, **339 internal and 41 outbound
original jump targets**, **328 original-bound nonlocal COFF
call/IEEE-754 references**, and both original local switch table
addresses. Complete codegen Exact is NOT established.

Reviewed states62–67 recover distinct aerial knockback physics with
incoming hit resource cost 0.8, initial meter +30, optional wall
collision into state70, original 0.75 vertical impulse scaling,
velocity clamps -2.0/-0.5 or -4.0/-0.5, gravity0.032 and landing
state97/98. States68–69 handle airborne recovery with cost1.5,
original meter+3, direct knockback X/Y and wall cancellation only in
state68. No diagnostic neutral marker case was accepted as source.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 70 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case70 `0x00645CB1`**, followed by
states71–77 and larger late moves. The original full 0x4A4 frame,
102 remaining native bodies, local switch DATA, return and complete
relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
