# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The authored natural C++ `Character20State.cpp` currently has
original common setup, default and **thirteen reviewed live cases**:
1–9 and 13–16. The native owner starts at `0x006429C0` and the
next unreviewed case47 starts at `0x00643682`. Case starts:
default `0x00642A6C`, 1 `0x00642AE7`, 2 `0x00642B62`,
3 `0x00642BDD`, 4 `0x00642C60`, 5 `0x00642DC3`,
6 `0x00642F32`, 7 `0x0064307C`, 8 `0x00643109`,
9 `0x00643196`, 13 `0x0064324D`, 14 `0x006432F2`,
15 `0x00643426`, 16 `0x0064355A`.

The selected prefix `[0x006429C0,0x00643682)` is **3,266 native
bytes / 927 instructions**, SHA-256
`c3ec6e125d3da52249b6111f22c5e719ae86a3d664b5d2d10a38898cd552f1ae`.
The original six-byte `sub esp,0x4A4` is still compiled with a
provisional three-byte `sub esp,0x58` because the other 123 real
source cases are missing. Explicitly restoring ONLY that known
three-byte position shift, the local verifier checks **927 native
instruction positions, widths and normalized opcodes**, **74 internal
branches**, **15 outbound original branch targets**, **67 canonical
nonlocal float/call relocation operands** and 2 original-local
switch address operands. There is no fake assembly padding and no
full-function Exact claim.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 47 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case47 `0x00643682`**, then cases50–77
and the larger late state bodies. The full original 0x4A4 frame,
123 remaining source cases, local switch DATA, return and complete
relocation closure are OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
