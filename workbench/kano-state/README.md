# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The authored natural C++ `Character20State.cpp` now contains
original default plus **100 native-reviewed live cases** through235.
The strict original-bound prefix `[0x006429C0,0x0064C212)` spans
**38,994 native code bytes / 10,702 x86 instructions**, SHA-256
`83b434493f6966cac0d4d24f23cda2476878f3339d85efa82901a5d5419d3cf0`.
Next original live state248 starts at **`0x0064C212`**; original
case IDs236–247 are default selectors, NOT missing code bodies.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` checker independently verifies
all **10,702 original instruction offsets/forms/widths**, **1,008
internal and 133 outbound native branch targets**, **883 bound
nonlocal COFF call/IEEE-754 operand references** plus both original
local switch pointers. Partial candidate frame0x130 differs from
canonical0x4A4 but both use identical six-byte instruction lengths
(no address shift). SELECTED PREFIX only, **NOT full Exact**:
**36 original live state bodies**, complete stack, switch DATA,
remaining relocs and return remain OPEN. Probe marker cases unaccepted.

The original 233/234/235 are three complete Kano grounded trail
strikes (284/284/272 bytes) with `StartTrail(3)`, X speed decay0.01,
frame0 X=1.2/Y=0 and state3 recovery. 233 starts sound21/hit1 on
frame1, 234 on frame2, 235 has frame2 sound21/**six hits** and
unconditional collision clear on animation advance. The distinct
frame condition and hit count are verified against canonical opcode
structure, jump edges and original operands—not sibling assumptions.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 248 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case248 `0x0064C212`**. Original
0x4A4 frame, 36 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
