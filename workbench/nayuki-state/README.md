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

Original [0x00451850,0x0045ED5D): **54,541 / 62,693 code bytes**,
**14,962 native x86 instructions**, SHA-256
c429f929b7ebe0ff66fc31061d7de478c6719f7bccf8ef61b9d789eaa5bbad78.
Original default plus **125 live state bodies** have been reviewed.

New state275 (518 bytes) restores the second airborne grab-impact
branch: entry ResetFrame and one remaining hit, frame3 launch
(1.4,-2.1), gravity .045 and meter45, landing frames3–7 trigger
shake(3,0), effect3 at X+facing*30, sound7 and the frame8->7 loop.
Exit requires FaceOpponent, ResetFrame, then virtual ResetPose.
State276 (514 bytes) is a distinct dash attack with a frame1
**39 - field3148 * 3** time gate in addition to the normal duration.
It sets frame3 sound20/meter35, frame5 hitcount1, advances X by
facing*40 at frames3–5, and later starts airborne motion with
vertical speed -0.7, velocityX 0.7 and gravity .033. Its post-launch
landing moves to state13, and animation exit loops the final frame.
Both restored cases match original code and bound floating constants;
no unreviewed inherited body was counted as source.

Focused original-bound verification:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` validates **14,962 original
instruction positions/widths/normalized forms** apart from the
incomplete compiler frame allocation (0x328 vs native 0x2B4).
The audit independently verifies **1,404 original internal branches**,
**210 outbound destinations**, **1,135 nonlocal original-bound COFF
call/IEEE-754 references**, 2 local switch operands and **125
original selector case targets**. This is selected-prefix evidence,
NOT complete original-function Exact.

## Next state and unfinished full owner

Original state277 begins at **0x0045ED5D**. Only **five missing live
case IDs 277–281** remain unimplemented; seven inherited bodies
300–306 are still not whole-function verified. Workbench has 132 of
137 state labels (125 selected-prefix verified). **8,152 original code
bytes**, canonical 0x2B4 frame, 552/306-byte switch tables, remaining
relocations and shared return remain open. Use original disassembly
and `probe_prefix.py --through 277 --context 12`; never count
synthetic marker branches or run all-unit cold replay.
