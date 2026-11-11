# Nayuki Character10::Slot06 — partial native state-machine reconstruction

**Status: PARTIAL, NOT full Exact.** Work in
`workbench/nayuki-state/Character10State.cpp` and preserve every local
change. The accepted `src/` tree remains separate, and unrecovered
sibling-derived states must never be counted as original source.

## Original owner

Character10 Slot06 vtable entry at 0x00788288 targets code
[0x00451850,0x00460D35), **62,693 bytes**, SHA-256:
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Adjacent separately owned switch DATA: 138 four-byte destinations at
0x00460D35, then 306 selector bytes at 0x00460F5D.
The switch maps 137 live animation IDs and 169 default IDs.

## Selected original-bound native checkpoint

Original [0x00451850,0x0045F82F): **57,311 / 62,693 original code
bytes**, **15,714 native x86 instructions**, SHA-256
`35d168b00dbd58242387bcbfb4543f93dfd7e627e3aeae7e947768fc6c56e29c`.
Default and **131 original live states** are now reviewed.
**All 137 original case labels are present in natural source.**

The last three formerly missing case bodies have been reconstructed:
state279 (348 bytes) is a tiered local strike using effect0x191,
frame3 meter+45 and the original frame4 `field3148*3` acceleration.
State280 (152 bytes) calls ResetFrame each tick, requests character
sound4 at entry, sets `attackCollisionResult=3` on frame step and
ends by ResetPose then state0. State281 (338 bytes) is a positive
dash-momentum decay: when dashMomentumFlag=0 zero both velocities,
otherwise subtract 0.03 from positive horizontal speed or clear flag;
frame3 gives meter+25, sound20 and one hit, finishing at state0 or
state3 according to inputY after FaceOpponent/ResetPose.

Original physical code order after state278 remains:
**300 (0x45F293) -> 279 (0x45F4E9) -> 280 (0x45F645) ->
281 (0x45F6DD) -> 301 (0x45F82F)**. The selective probe uses the
canonical switch table addresses to preserve this order.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` verifies **15,714 native
instruction positions/widths/normalized forms** except partial stack
allocation (0x330 versus original 0x2B4), **1,476 original internal
branches**, **226 outbound targets**, **1,177 nonlocal original-bound
COFF call/float references**, two original switch operands and **131
original case destinations**. This is NOT whole-function Exact.

## Remaining owner work

The original **state301 at 0x0045F82F** starts the six unreviewed
large cases 301–306, with known vtable selector entries already in the
source. **5,382 original code bytes**, native stack, original
552/306-byte switch DATA, relocation closure and shared return are
not verified. Next targeted check is original disassembly and
`probe_prefix.py --through 301 --context 12`. Do not claim
whole-function Exact or run full all-unit cold replay.
