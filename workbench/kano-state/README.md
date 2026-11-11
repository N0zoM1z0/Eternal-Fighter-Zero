# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Current natural C++ at `Character20State.cpp` reconstructs
original default plus **39 real reviewed cases**: 1–9, 13–16, 47,
50–74. The selected native code `[0x006429C0,0x00646423)` spans
**14,947 bytes / 4,125 original x86 instructions**, SHA-256
`23def50e36aa07c82059a6c0f06b728b9b03e3eb47921c97f53614f49679deac`.
The original frame allocates 0x4A4 bytes; the incomplete candidate
now allocates 0x90 bytes, but both use the **same six-byte instruction
form**, so the selected comparator requires identical instruction
positions *without a stack-length adjustment*. The stack amount
still differs: no complete Exact claim. Native-bound checks verify
**387 internal and 46 outbound original branches**, **376 nonlocal
COFF call/float references**, two local switch-address pointers, and
all **4,125 original instruction forms/offsets/widths**. All later
97 cases are neutral unaccepted marker bodies in the probe.

New native-reviewed cases70–74 cover Kano's wall/landing recovery,
resource-costly recoil and grounded defensive poses. State70 uses
meter+30, original wall impact effect0, sound31 and upward launch
with gravity0.025; state71 uses direct high-gravity 0.072 vertical
recovery; cases72–74 preserve edge pushback with stage-boundary and
opponent air-height predicates. The source preserves original call
order, reset/landing transitions and IEEE-754 constants.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 75 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case75 `0x00646423`**, followed by
states76–77 and larger late moves. The original 0x4A4 frame,
97 remaining native bodies, local switch DATA, return and complete
relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
