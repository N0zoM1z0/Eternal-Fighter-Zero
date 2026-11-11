# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The natural C++ `Character20State.cpp` now contains the original
default and **73 original-bound reviewed live cases**: 1–9,
13–16,47,50–77,81–87,96–99,150–158 and 161–171.
Strict selected native prefix `[0x006429C0,0x00649954)` is **28,564
machine-code bytes / 7,833 original x86 instructions**, SHA-256
`f9066304a2f788c3d7c8bdf8839c5a8a255f615b48e8ba190e47f0c4bcc2c66c`.
Next original case178 starts at **`0x00649954`** (179 is not live).

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected native checker verifies
**7,833 original instruction offsets, lengths and normalized forms**,
**700 original internal jumps**, **87 outbound targets**, **714
nonlocal original-bound COFF call/IEEE-754 operands** and both local
switch-table references. Partial candidate stack0x11C differs from
canonical0x4A4 but uses the same six-byte instruction width, so no
position shift or fake padding is allowed. This is a partial prefix,
NOT complete function Exact; **63 native cases remain unreviewed**.
Only the original-bound cases are credited: later temporary diagnostic
neutral markers never count as restored source.

Newly reviewed 170 and171 together contribute 957 native bytes.
State170 stores X/Y velocity *100 in child integer caches, tests zero
gravity by x87 comparison **before** clearing motion, and restores
velocity with 0.01 scaling after hitstun expires. Ground contact
moves to state169. State171 instead zeros motion before conditional
combo resource scaling, emits effect1 with sound18, and on completed
frames restores cached velocity before checking **gravity==0.0**
through native x87 ordering, setting gravity0.02 only when zero.
The subtle variable write order and conditional comparison are required
for exact original compiler instruction sequence.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 178 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case178 `0x00649954`**. Original
0x4A4 frame, 63 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
