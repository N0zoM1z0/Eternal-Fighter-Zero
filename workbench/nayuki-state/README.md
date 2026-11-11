# Nayuki Character10::Slot06 — handoff for the next agent

**Status: PARTIAL, NOT Exact.** Work on workbench/nayuki-state/Character10State.cpp,
not the accepted src/ tree. Its inherited Makoto scaffolding must not be treated
as verified Nayuki logic. Preserve this source and its unreviewed cases.

## Locked target and selector

- Character10 vtable Slot06 at 0x00788288 points to 0x00451850.
- Original code: [0x00451850,0x00460D35), **62,693 bytes**.
  SHA-256: 4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
- Adjacent DATA, not code: 138 x 4-byte switch destinations at 0x00460D35,
  then 306 selector bytes at 0x00460F5D.
- 137 original live state IDs and 169 default mappings.
- Workbench has **118/137** original case labels. The **19 missing labels
  are 263–281**. Another 37 existing cases remain unreviewed.

## Latest selected native proof (2026-11-11)

Code [0x00451850,0x00459441): **31,729 / 62,693 original code bytes**,
**8,731 original x86 instructions**, SHA-256:
e79a6fe2cab2a71967c6ad8eb3d518a1120379c75b91102ea8954e9aba8e3201.

The reviewed default and **81 live states** are 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180, 200–203.
Original states 200 and 201 reproduce their full frame/timer paths;
state 202 contains the actual 823-byte aerial multi-hit and landing
rebound, and state 203 the 725-byte grounded cancel/launch logic.
The comparison for state203 must express `positionY == 0.0` (operand
order matters to original VC7.1 x87 code generation).

Pinned VC7.1 /Od /G6 /MT /Gy /W3 matches all 8,731 original
instruction forms, widths and offsets in the selected prefix except
its incomplete stack allocation (candidate 0x270, original 0x2B4).
Original-bound verification covers **798 internal branches**, **105
outbound branch destinations**, **781 nonlocal COFF call/IEEE-754
relocations**, **two local switch operands** and **81 original case targets**.
This is selected-prefix verification, NOT whole-function Exact.

## How to continue

From the EFZ repository root:

    git status --short --branch
    scripts/repo-python scripts/verify-target.py
    scripts/repo-python workbench/nayuki-state/check_prefix.py
    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 204 --context 10

**Next original state is 204 at 0x00459441.** Its inherited candidate
first diverges at **0x004595D7** (owner offset 0x7D87): original compares
`field000a == 3` before rewriting it to 4, while the sibling template
instead resets the hit collision counter on `field000a < 2`.
Reconstruct the remainder against original disassembly and advance the
original-bound checker, not merely an instruction-prefix printout.

The probe generates neutral UNACCEPTED marker branches for other canonical
IDs and authentic late 300–306 bodies to preserve the VC7.1 ESI/prologue.
It deletes the temporary generated source automatically. Do not mistake
marker branches for recovered C++.

## Preserve and do not overclaim

**30,964 code bytes**, **19 missing live states**, complete 0x2B4 stack
frame, late candidate cases, original switch tables, remaining relocations
and final shared return are OPEN. Never register this workbench in the exact
match ledger. No full cold replay or whole-game runtime claim.

Other Nayuki Slot01, Slot02, Slot04, Slot05 and Slot07 owners are accepted
in src/ with selected Exact evidence. They are not workbench drafts.

Ignored build/, .analysis/ and Python __pycache__/ contain regenerable scratch.
Preserve the pinned compiler/Wine runtime (.tools/), Ghidra project,
resources/EFZ.exe, tracked evidence and tracked workbench source.
