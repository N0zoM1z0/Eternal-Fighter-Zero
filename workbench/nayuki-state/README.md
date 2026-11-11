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

Original code [0x00451850,0x004603E6): **60,310 / 62,693 bytes**,
**16,516 original x86 instructions**, SHA-256
f67d8a1c5c3ba6f6314fb8c9bb2d087b9e99273158784fd2fa38f3d2f64242b0.
Original default and **135/137 live states** now have original-bound
natural C++ source, including all formerly missing 263–281 and
late super states300–304.

State304 is an **897-byte original high-meter controllable super**:
entry ResetFrame, frame3/tick0 spends 2000 meter and emits global
0x45/palette5 effect at Y-40 with hitstun120/tint(0xB0,3). Frames6/7
zero movement and choose ±0.65 vertical/horizontal velocity from
inputY, inputX and facing. Gravity applies after frame7; a landing
condition in frames8–11 jumps to frame12. Frame6 transition emits
local effects0x19D/0x19E; frame8 can repeat frame6 up to 20 times,
then applies gravity0.015, and frame12 loops back to frame10.
Exit selects state7 after FaceOpponent/ResetPose. This implementation
was recovered against original native bytes, not inherited Makoto code.

Targeted original-bound native verification:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` compares **16,516 same-offset,
same-width normalized original instructions** except the incomplete
candidate stack allocation (0x288 vs original 0x2B4), **1,542
internal branches**, **232 canonical outbound destinations**,
**1,236 nonlocal COFF call/float references**, 2 local switch operands
and 135 original selector case entry targets. Not full Exact.

## Final native state bodies / owner closure

Only **305 and306** remain unreviewed inherited state bodies: original
address 305 **0x004603E6**, with **2,383 original code bytes** until
the common return at 0x00460D35. Full 0x2B4 native stack, adjacent
552-byte destination and 306-byte selector tables, remaining
relocation/return closure are not yet proven. Work with original
`probe_prefix.py --through 305` and selected verifier only; no
all-unit cold replay, no synthetic marker acceptance.
