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

Reviewed original code [0x00451850,0x0045E1A9): **51,545 / 62,693
bytes**, **14,141 x86 instructions**, SHA-256
8fa2492e029cfb1a19a6448ffb0c3612adc237c4eb7ca7c19f458af4f16b4e50.
Original default and **119 live cases** through state270 now match.

New state269 (518 bytes) handles an airborne-impact attack: first-tick
ResetFrame + one hit; gravity while airborne; at frames3–7 a landing
condition resets frame, positionY and triggers vertical shake(3,0),
global effect3 at facing*30, sound7, then frame8. Frame3 grants
meter45 and velocity (1.4,-2.1) with gravity .045, while frame8
loops back to7. Completion returns to state0 in the original
FaceOpponent/ResetFrame/ResetPose order.

New state270 (468 bytes) is a delayed advancing attack: it resets
the frame, enables hitcount at frame5, requests sound20 and meter35 at
frame3, advances own positionX by facing*40 over frames3–5 and later
launches at (0.7,-1) with gravity .033 at frame9. Airborne landing
changes to state13 after ResetPose; the last animation frame loops
back one frame. Canonical original IEEE-754 constants and x87 order
are checked, not just normalized opcodes.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` compares **14,141 instruction
positions/widths/forms**, **1,322 original internal branches**,
**192 outbound targets**, **1,090 nonlocal original-bound COFF call/
float references**, two local switch operands, and **119 selector
case entries**. Candidate frame 0x314 differs from original 0x2B4;
this is selected-prefix evidence, NOT whole-function Exact.

## Next state and unresolved work

Original state271 starts at **0x0045E1A9**. Remaining **11 absent
states271–281**, seven unreviewed 300–306 and full original
stack/switch data/return remain open. Of 137 original live IDs,
126 authored case labels exist, 119 reviewed. **11,148 original code
bytes** are still unmatched. Continue native disassembly and focused
`probe_prefix.py --through 271 --context 12` only. Never count
neutral case markers or run full all-unit cold replay.
