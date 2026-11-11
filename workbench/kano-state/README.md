# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The authored natural C++ `Character20State.cpp` currently has
original common setup, default and **19 reviewed live cases**:
1–9, 13–16, 47 and 50–54. Next native case55 begins `0x00644167`.
The selected original prefix `[0x006429C0,0x00644167)` is **6,055
native code bytes / 1,669 original x86 instructions**, SHA-256
`96ba1a868dd57db0da3037785566c4df780db3cacab3dd435bd60387224601b5`.

Original `sub esp,0x4A4` has a six-byte instruction; the selected
candidate currently uses short `sub esp,0x6C`, three bytes shorter,
because the remaining 117 native cases are not yet authored. The
focused checker normalizes *only* this provisional three-byte frame
instruction-size shift. It then strictly verifies all **1,669 native
instruction positions, widths and forms**, **146 original internal
branches**, **21 outbound targets**, **164 native-bound nonlocal
call/IEEE-754 COFF operands** and both switch-table address operands.
This is NOT whole-function Exact, and marker bodies have no credit.

Case47 (304 bytes) restores the airborne landing/impact transition,
with gravity0.035 and frame2 loop. States50–54 are Kano's full
**497-byte-per-state recoil/guard reactions**: each applies resource
loss if flagged, uses original opponent combo-damage scaling to set
horizontal pushback, enforces stage-edge constraints, and advances
animation to neutral/defensive recovery. Original tier-dependent
meter gain and recoil constants are preserved and verified against
native IEEE-754 locations. These are actual authored source bodies,
not mere labels or untouched sibling placeholders.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 55 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case55 `0x00644167`**, followed by
remaining states56–77 and larger late bodies. The full 0x4A4 stack
frame, 117 remaining source cases, local switch DATA, return and
complete relocation closure are OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
