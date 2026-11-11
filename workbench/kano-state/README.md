# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current natural C++ `Character20State.cpp` now includes original
default plus **71 native-reviewed live cases**: 1–9, 13–16, 47,
50–77, 81–87, 96–99, 150–158, and 161–169. Selected code
`[0x006429C0,0x00649597)` is **27,607 original bytes /
7,586 x86 instructions**, SHA-256
`435dc0515825455aba0d5c5be5fb8d89542029849be47af37069f3af84f15dbb`.
Next case170 begins **`0x00649597`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` strict selected checker validates
**7,586 original instruction positions/widths/forms**, **683
original internal and 84 outbound jump targets**, **684 bound
external COFF call/IEEE-754 operands**, and two native switch
references. The partial candidate frame0x114 vs canonical0x4A4
uses the same six-byte allocation instruction, so zero shift is
permitted. This is NOT whole-function Exact: **65 native cases**,
full stack/tables and common return remain unresolved. Existing
170/171 C++ is experimental and not yet reviewed; diagnostic neutral
marker cases have no acceptance credit.

Cases167–169 are newly selected-native verified. State167 (488 bytes)
clears dash/motion, handles resource-sensitive combo scaling and
tint, then emits original stage effects1 and4 with precise sound and
state0 recovery. Two 330-byte cases168/169 implement independent
impact/grounded recovery and correctly select state0/3. Each native
instruction, flow edge, numeric operand and direct external call was
original-bound verified; sibling-derived comments are not authority.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 170 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case170 `0x00649597`**. Original
0x4A4 frame, 65 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
