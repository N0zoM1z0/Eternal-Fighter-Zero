# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current authored C++ `Character20State.cpp` now contains default
and **49 real native-reviewed cases**: 1–9, 13–16, 47, 50–77 and
81–87. The continuous original code prefix
`[0x006429C0,0x006476FB)` is **19,771 bytes / 5,428 x86 instructions**,
SHA-256
`064c3c64368d4a5cbedc833b3feaafb2589832bcf6e4c8676f06b85b68b64156`.
Native **next case96** starts at `0x006476FB`.

The incomplete candidate has compiler stack allocation 0xC4,
while the canonical full owner uses 0x4A4. Both use identical
six-byte prologue instructions; no location shift is normalized.
The selected checker validates **5,428 native instruction offsets,
lengths and opcode forms**, **501 internal branches**, **58 outbound
original targets**, **488 original-bound COFF call/IEEE-754 references**,
and both local switch address operands. This is only a scoped prefix,
NOT complete function Exact. Neutral placeholders for other 87 states
receive no source/acceptance credit.

New original states81–87 include 485-byte airborne hit recovery,
546-byte repeated aerial lift, two independent 581-byte ground-impact
reactions, 467/482-byte direct knockback and one-shot lift recovery,
and an authentic 179-byte fixed-position effect state87. These
reconstruct conditional resource costs, field3144 one-shot special
hit effect0x1F0, input/ground collision transitions, frame repeat
conditions, x87 speed/friction constants, and native call order.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 96 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case96 `0x006476FB`**. The original
0x4A4 frame, 87 remaining native bodies, local switch DATA, return
and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
