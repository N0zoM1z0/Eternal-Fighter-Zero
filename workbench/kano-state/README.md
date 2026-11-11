# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The authored natural C++ `Character20State.cpp` now has original
common setup, default, and **26 reviewed real cases**:
1–9, 13–16, 47 and 50–61. Next original case62 begins at
**`0x00644ED6`**. The consecutive selected original prefix
`[0x006429C0,0x00644ED6)` is **9,494 native code bytes / 2,605
instructions**, SHA-256
`b554ad2cf978442ee6357749aa8bd272b04aa7b4dc284f94d353fc3fe25bf571`.

The canonical native stack is `sub esp,0x4A4`; the incomplete selected
C++ compiles with short `sub esp,0x7C` due to unimplemented later
cases. The checker normalizes **only that one three-byte instruction-
size displacement**, then strictly compares all **2,605 original
instruction offsets, lengths and forms**, **240 internal branches**,
**28 outbound original targets**, **269 original-bound nonlocal
call/IEEE-754 COFF operands** and 2 original-local switch pointers.
This is NOT whole-function Exact; the other 110 case markers are
unaccepted neutral tests with no reconstruction credit.

Newly reviewed original states55–61 implement nontrivial tiered
recoil, hit meter recovery, edge pushback and opponent combo-damage
scaling. State55 deliberately **does not** clear `dashMomentumFlag`;
states56–58 **do** clear it after resource deduction. Native state
lengths include 55=487, 56–58=473 each, and 59–61=511 each.
Their actual machine instructions, branches and numeric IEEE-754
operands were checked rather than assuming source equivalence with
Makoto. These branches are preserved in authored natural C++.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 62 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case62 `0x00644ED6`**, followed by
remaining states63–77 and more complex late bodies. The full 0x4A4
stack frame, 110 remaining native cases, local switch DATA, return
and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
