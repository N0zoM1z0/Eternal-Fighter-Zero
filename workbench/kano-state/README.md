# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current natural C++ `Character20State.cpp` now contains default and
**68 original-bound reviewed cases**: 1–9, 13–16, 47, 50–77,
81–87, 96–99, 150–158, 161–166. Canonical contiguous code
`[0x006429C0,0x0064911B)` = **26,459 bytes / 7,287 x86 instructions**,
SHA-256 `4c148d2a49bd6c34e09c03fcdbd4ed578afd138bd7cb9d3d1df34de50bb185d5`.
Next native case167 begins at **`0x0064911B`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected checker verifies
**7,287 original instruction offsets, lengths and normalized forms**,
**664 internal and 81 outbound original branch targets**, **652
native-bound nonlocal COFF call/float references**, and two original
switch pointers. The incomplete stack allocation is 0xF4 vs native
0x4A4 (same six-byte opcode); NO offset shift is normalized.
This is a selected original-bound prefix, NOT whole-function Exact.
**68 case bodies** and original native tables/return remain open.
Existing experimental C++ 167–171 is retained but UNREVIEWED.

Reviewed 165/166 (425/429 bytes) are materially different from the
Makoto sibling: +1.1/−1.1 initial horizontal dash with zero vertical
movement/gravity, sound17, animation-frame loop and facing-dependent
state9 recovery. Recovery sets ±0.9 horizontal velocity with Kano's
0.02/0.03 gravity gate. Literal float and external call operands
are verified against original EFZ.exe, not simply masked.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 167 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case167 `0x0064911B`**. Original
0x4A4 frame, 68 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
