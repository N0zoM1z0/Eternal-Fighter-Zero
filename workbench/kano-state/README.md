# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Kano `Character20State.cpp` now authors the native default and
**101 reviewed live states** through 248. Strict selected original
`[0x006429C0,0x0064C41A)` is **39,514 native code bytes /
10,848 original x86 instructions**, SHA-256
`380f695f6544b8489bbeca95d015d7ee31935bcb042177634419d350a0b67706`.
The next original state249 starts at **`0x0064C41A`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected checker verifies
**10,848 original instruction offsets, widths and normalized forms**,
**1,017 internal and 134 outbound native jump destinations**, **892
nonlocal original-bound COFF call/IEEE-754 references**, and both
native switch-table address operands. This selected codegen candidate
has a provisional stack frame0x13C vs original0x4A4, but both
allocation instructions have identical six-byte widths and no
position normalization is allowed. This is **NOT whole-function Exact**;
**35 original live cases**, final stack, original local switch DATA,
remaining relocations and shared return remain OPEN. The compiler's
neutral diagnostic marker cases receive no original-source credit.

**State248 (520 bytes)** restores Kano's original airborne opponent
capture: frame1/grab collision3 invokes both opponent and own
ResetPose/ResetFrame in original order, sends own state249 and opponent
state100, emits group2/layer1 impact0 at integer X+facing×29 and
Y−62, then places opponent at X+facing×29/Y−62.0. It calls native
`SetHorizontalOffset(50,3)` (original 0x410A40) and
`SetHorizontalShake(50,3)` (0x410A80), both bound in strict COFF
original relocation checks. The original animation completion sets
state209 and frame2. No marker body is claimed.

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
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 249 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case249 `0x0064C41A`**. Original
0x4A4 frame, 35 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
