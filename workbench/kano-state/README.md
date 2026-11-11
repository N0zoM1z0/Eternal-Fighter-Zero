# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Kano `Character20State.cpp` now contains original default and
**102 native-reviewed live cases** through state249. The selected
original code `[0x006429C0,0x0064C750)` covers **40,336 native
bytes / 11,096 original x86 instructions**, SHA-256
`c919786c0a1cb38c73818936db0dd297c6f02574021224c7a636f59ad7b31f75`.
The next physical native case250 begins at **`0x0064C750`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` strict selected checker verifies
**11,096 original instruction positions, widths, normalized forms**,
**1,032 original internal and 136 outbound branch destinations**,
**906 independently original-bound COFF calls/IEEE-754 operands** and
two local switch table references. The incomplete candidate uses
stack0x148 versus original0x4A4, both six-byte allocations with no
position normalization. This is a strict selected prefix, **NOT full
Exact**: **34 missing real state bodies**, the canonical complete
stack frame, adjacent native switch DATA, remaining relocations and
shared return still need verification. Neutral probe case markers
are not accepted as authored source.

New **state249 (822 bytes)** reconstructs an original complex aerial
throw sequence: while frames<5 it requests native horizontal offset
and shake (50,3); frame0/tick1 reverses the grabbed fighter's facing;
X/Y velocity advances under gravity. At frames2/3/4 it moves the
opponent to X+facing*(28/20/29), Y-(47/38/62), and assigns original
opponent states101/101/100 and facing. On frame5/tick0 it sets the
opponent position to own X,Y-72, state63 and facing, calls accepted
`ApplyDamage(1200,500.0)`, resets opponent pose, and assigns original
knockback velocities -1.0/-2.3; at frame12 it sets gravity0.035.
A native landing branch only fires on **strict Y+velocityY >0** and
frame>5, doing own ResetFrame, zeroing Y, virtual own ResetPose,
then switching to state13. Animation end repeats the last two frames.
The full code path, direct call targets and canonical IEEE-754 values
match in selected VC7.1 native comparison.

### Experimental next state250 — NOT selected-prefix acceptance

Original Kano state250 is `[0x0064C750,0x0064C999)` (**585 code
bytes**). Actual natural C++ has been authored in
`Character20State.cpp`, including original charge counter cap10000,
frame3–6 button release/charge cancel, paired native local effects
`0x196`/`0x197`, four-frame animation rewind, and frame0 reset.
It is **experimental, not accepted**: `probe_prefix.py --through 250`
first diverges at **0x0064C955** (offset `0x9F95` from owner base)
during the tail animation-frame comparison. Native code begins
`mov edx,[ebp-0x54]; movzx eax,word [edx+0xa]`, while the current
VC7.1 candidate rotates scratch registers to EAX/ECX at the same
instruction boundary. Twelve-plus expression variants were tested,
including `==7` reversal, cast/assignment forms, frame-count
comparison order, member qualification and increment forms; none
closed this difference without disrupting earlier matching bytes.
The strict selected native checker remains **pinned at case249 end
0x0064C750** and must NOT be advanced to case250 until full original
instruction/branch/relocation parity is established. No ledger or
`src/` accepted function is changed on this hypothesis.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 250 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case250 `0x0064C750`**. Original
0x4A4 frame, 34 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
