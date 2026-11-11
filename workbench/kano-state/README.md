# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

The authored natural C++ `Character20State.cpp` currently has the
original common setup, default, and fully reviewed **cases 1–9**.
Native-defined starts: default `0x00642A6C`, 1 `0x00642AE7`,
2 `0x00642B62`, 3 `0x00642BDD`, 4 `0x00642C60`,
5 `0x00642DC3`, 6 `0x00642F32`, 7 `0x0064307C`,
8 `0x00643109`, 9 `0x00643196`, 13 `0x0064324D`.

Selected prefix `[0x006429C0,0x0064324D)` = **2,189 original code
bytes / 621 instructions**, native SHA-256
`ac84ae47828177f4c4491f3026131d6fe3fb4271df45a3b5166ea123ef7e5c87`.
After normalizing only the provisional **three-byte difference in the
original six-byte `sub esp,0x4A4` versus incomplete candidate three-byte
`sub esp,0x58`**, the selected native checker validates **621 x86
instruction offsets, widths and forms**, 50 internal branches,
11 outbound original code targets, 44 original-bound float/call
relocation operands and both switch table address operands.
`Character20::Slot06` is still NOT complete; no marker state counts
as source. This is NOT a strict Exact whole-owner certificate.

Important Kano-specific differences from the related Makoto dispatcher:
case1/2 speed `+0.6`/`-0.6`, case4/5/6 jump starts at frame2
not3, gravity `0.025`, vertical launch `-2.2`, optional carry velocity
`0.3` on case4. Cases5/6 terminate with state9 and ResetPose,
unlike Makoto's trailing frame loop. All these variants are verified
against original code positions and IEEE-754 values. Cases7/8 reset
in state0/3, and case9 applies gravity/landing to state13.

Run ONLY focused checks, not full cold replay:

    scripts/repo-python scripts/verify-target.py
    scripts/repo-python workbench/kano-state/check_prefix.py
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 13 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case13 `0x0064324D`**, then cases14–16 and
larger late state bodies. The original full 0x4A4 frame, all remaining
127 source cases, local switch DATA, return and complete relocation
closure are OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
