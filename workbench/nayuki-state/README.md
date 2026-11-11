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
  are 263–281**. Another 41 existing cases remain unreviewed.

## Latest selected native proof (2026-11-11)

Code [0x00451850,0x00458A23): **29,139 bytes / 8,027 x86 instructions**,
SHA-256 5d806ca17e1c22319b18fc68100395b69414584e3110bf5834a7e1c8ed412850.

The reviewed default plus **77 live states** are:
1–9, 13–16, 47, 50–77, 81–87, 96–99, 123,
150–158, 161–171, and 178–180.

Pinned VC7.1 /Od /G6 /MT /Gy /W3 matches all 8,027 original
instruction forms, widths and offsets in the selected prefix except the
temporary partial stack allocation (candidate 0x264, original 0x2B4).
Original-bound validation verifies **707 internal branches**, **97 outbound
branch destinations**, **747 nonlocal COFF call/IEEE-754 relocations**,
**2 local switch operand references** and **77 original case targets**.
This is a selected-prefix result, NOT whole-function Exact.

## How to continue

Run from the EFZ repository root:

    git status --short --branch
    scripts/repo-python scripts/verify-target.py
    scripts/repo-python workbench/nayuki-state/check_prefix.py
    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 200 --context 8
    scripts/repo-python scripts/ci.py

**Next original state is 200 at 0x00458A23.** First opcode-form mismatch:
**0x00458A26 (owner offset 0x71D6)**. Original executes a byte load
from [ecx+0x158]; current unreviewed sibling case200 follows an
unrelated timer path. Recover that state using original disassembly,
then advance the selected prefix and verify targeted bindings.

probe_prefix.py generates a short-lived partial VC7.1 function containing
the verified early cases, intentionally UNACCEPTED neutral marker branches
for other canonical IDs, and authentic late 300–306 bodies only to preserve
the original compiler ESI/prologue shape. The temporary generated source
is removed after execution. Do not count marker cases as reconstruction.

## Preserve and do not overclaim

**33,554 code bytes**, **19 missing live states**, complete 0x2B4 stack
frame, late candidate cases, original switch tables, remaining relocations
and final shared return are OPEN. Never register this workbench in the exact
match ledger. No full cold replay or whole-game runtime claim.

Other Nayuki Slot01, Slot02, Slot04, Slot05 and Slot07 owners are accepted
in src/ with selected Exact evidence. They are not workbench drafts.

Ignored build/, .analysis/ and Python __pycache__/ contain regenerable scratch.
Preserve the pinned compiler/Wine runtime (.tools/), Ghidra project,
resources/EFZ.exe, tracked evidence and tracked workbench source.
