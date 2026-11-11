# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The authored natural C++ `Character20State.cpp` now contains
original default and **97 reviewed live case bodies** through state232.
The selected original `[0x006429C0,0x0064BECA)` covers **38,154
native code bytes / 10,466 x86 instructions**, SHA-256
`e790ad12a48cb8263f331204afbecf7d29f12d45ccccffb07e156023a20e321b`.
Next native case233 starts at **`0x0064BECA`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` original-bound checker verifies
**10,466 original instruction positions/widths/normalized forms**,
**985 internal / 130 outbound branch targets**, **865 nonlocal
original-bound COFF call/IEEE-754 references** and two original
switch table address operands. Incomplete compiler frame0x130 vs
canonical0x4A4 has identical six-byte instruction width; no offset
normalization is allowed. This is SELECTED PREFIX only, **NOT whole
Exact**. **39 native live case bodies**, full original stack,
local switch DATA, remaining relocs and common return remain OPEN.
Temporary neutral probe markers have no source/Exact credit.

Newly verified Kano states230/231/232 are complete 284/437/437-byte
trail-strike variants. All call `StartTrail(3)`, clear dash momentum,
apply horizontal friction0.01 and initialize velocityX=1.2. State230
starts hit/sound21 on frame1. State231 starts its sound20/one hit on
frame4 and state232 on frame2; both include genuine frame-gated
upward jump cancel with directional state4/5/6 selection. The original
collision-reset boundaries differ: below frame3 for 230 and232,
below frame6 for231. Original float payloads, native branch offsets,
virtual call ordering and exit to state0 were all checked.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 233 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case233 `0x0064BECA`**. Original
0x4A4 frame, 39 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
