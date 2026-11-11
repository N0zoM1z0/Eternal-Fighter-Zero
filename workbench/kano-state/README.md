# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current natural C++ `Character20State.cpp` has original default
plus **53 native-reviewed live cases**: 1–9, 13–16, 47, 50–77,
81–87, and 96–99. The selected prefix `[0x006429C0,0x00647A3A)`
reconstructs **20,602 original code bytes / 5,664 x86 instructions**,
SHA-256
`8566a57cefe15e360f84466889a9e171e44f03ba6b411f50fb4b7a763cc69d28`.
The next original state is **150 at 0x00647A3A**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` local code comparison strictly
matches all **5,664 original instruction positions/widths/forms**,
**519 internal native branch targets**, **62 outbound targets**,
**502 original-bound external COFF calls/IEEE-754 operands**, and
both original switch table address operands. This is a partial prefix
check, not whole-owner Exact: the compiler currently reserves 0xD4
stack bytes versus original 0x4A4, though both stack instructions have
the same six-byte width and no positional adjustment is needed.
**83 real state bodies** remain absent from the source, with only
UNACCEPTED diagnostic marker branches in the temporary probe.

New cases96–99 restore wakeup/crouch timing, two original 248-byte
ground impact effects with `SetVerticalShake(3,0)` and type3 stage
emission, and the 186-byte health-gated wakeup timer. Original branch
ordering and code/float/call bindings are checked, including the
original `SetVerticalShake` call target `0x00410A10`.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 150 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case150 `0x00647A3A`**. Original
0x4A4 stack frame, 83 remaining native bodies, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
