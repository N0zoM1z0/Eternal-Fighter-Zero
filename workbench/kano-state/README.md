# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current natural C++ `Character20State.cpp` now has original default
and **42 reviewed native cases**: 1–9, 13–16, 47, 50–77. The
continuous selected original code prefix `[0x006429C0,0x00646A02)`
is **16,450 native bytes / 4,521 x86 instructions**, SHA-256
`69ebb02baaf70889bd2c24a2414270e61e237f8bacd590f06f24424f6347e059`.
The next native case81 starts at **`0x00646A02`**.

Original stack reserves 0x4A4 bytes; incomplete source currently
reserves only 0x9C bytes, but **both stack instructions have equal
six-byte length**, so no position shift or normalization is used.
Selected scoped verifier checks **4,521 original instruction forms,
offsets and widths**, **425 internal and 49 outbound original jump
targets**, **427 native-bound nonlocal COFF call/IEEE-754 operands**,
and both original switch-table pointers. **94 other cases are still
unimplemented**; neutral marker cases in the probe have no proof
credit, and there is no full-Exact claim.

Newly restored Kano states75–77 are 509/509/485-byte forward recoil
states with resource loss0.6 per tick and an additional 30 when
flagged, meter+30, initial velocityX=2.2, gravity cleared, horizontal
deceleration0.06 and stage-edge pushback dependent on opponent height.
Completion chooses state7/3 for 75–76 or state3 for 77. They match
original instruction order, branch targets and IEEE-754 constants.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 81 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case81 `0x00646A02`**. The original
0x4A4 frame, 94 remaining native bodies, local switch DATA, return
and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
