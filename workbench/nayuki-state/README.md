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

Reviewed original code [0x00451850,0x0045CEFA): **46,762 / 62,693
code bytes**, **12,845 original x86 instructions**, SHA-256:
03fc1c25136a56b6f4b9a397891cc29e61bd31f5fd97e8aa7abed3c753c6bc46.

The reviewed default and **112 original live states** are 1–9, 13–16,
47, 50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232, 248–254 and 256–263.

States261/262 are original-bound 587- and 889-byte multi-hit airborne
moves (full dynamics, frame transitions, resource expense and tiered
velocity). Critically, **missing original state263** has now been
reconstructed as a 629-byte natural C++ implementation rather than
using the probe's neutral placeholder case: frame0 zeroes velocities
and deceleration and sets `remainingHitCount = field3148 + 6`;
gravity applies in air, after frame15 horizontal velocity decelerates
by 0.028 to zero, and frames6/11 trigger context sound20. A landing
condition between frames6–15 skips to frame16 and zeros landing
vertical velocity. Three-tick hit-cycle counter `field313c` resets
collision result on overflow; frame5 gives meter45 and tiered
launch: (1.8,-1.7), gravity .035, or (0.6,-3.2), gravity .024 when
`field3138 == 1`. Frame16 loops back to frame5; completion changes
to state7 after ResetFrame/ResetPose.

Focused native verification:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` reproduces **12,845 original
instruction offsets, lengths and normalized opcode forms** except
the temporary stack frame allocation (0x2F8 candidate vs original
0x2B4). Original-bound audit validates **1,171 internal jumps**,
**167 outbound destinations**, **1,015 nonlocal COFF call/float
references**, two local switch-address operands and **112 case entry
targets**. This is a selected-prefix check, NOT full-owner Exact.

## Next missing state and remaining work

Next original state264 starts at **0x0045CEFA**; like 265–281 it
has no natural C++ case body yet. Use original disassembly to add it,
then focused `probe_prefix.py --through 264 --context 12`, and
advance the strict selected checker. Do not bypass missing states.

**15,931 code bytes** remain, along with the full 0x2B4 frame,
original adjacent 552/306-byte switch DATA, relocations and common
return. Of 137 live IDs, 119 labels now exist in the workbench:
112 reviewed, 7 unreviewed 300–306 and **18 absent 264–281**.
The selective probe's neutral marker cases are UNACCEPTED. No
all-unit cold replay or whole-game/runtime equivalence claim.
