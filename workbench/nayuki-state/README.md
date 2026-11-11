# Nayuki Character10::Slot06 — focused state-boss reconstruction

**PARTIAL, NOT Exact.** Work on workbench/nayuki-state/Character10State.cpp,
not the accepted src/ tree. The initial Makoto-derived source contains
UNVERIFIED late case bodies and must not be counted as Nayuki recovery.

## Original owner

- Slot06 vtable 0x00788288 -> 0x00451850.
- Original code [0x00451850,0x00460D35): 62,693 bytes, SHA-256
  4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
- Adjacent local DATA: 138 four-byte destination addresses at 0x00460D35,
  306 selector bytes at 0x00460F5D; 137 live state IDs and 169 defaults.
- Workbench has 118/137 labels; missing 19 are IDs 263–281. Another
  37 later existing case bodies remain unverified.

## Reviewed selected checkpoint (2026-11-11)

[0x00451850,0x00459441): **31,729 original code bytes / 8,731
instructions**, prefix SHA-256
e79a6fe2cab2a71967c6ad8eb3d518a1120379c75b91102ea8954e9aba8e3201.

The default plus **81 reviewed live states**: 1–9, 13–16, 47, 50–77,
81–87, 96–99, 123, 150–158, 161–171, 178–180, 200–203.
Recently recovered: state200 original damping/ground meter window,
state201 early state3148 frame advance, state202 airborne multi-hit and
landing particle/shake, and state203 zero-height cancel/launch. State203
uses the x87 FUCOMPP equality test (positionY == 0.0); frame gates in
state202 reset collision only at original frames 4/5/7/9/11.

Selected test only:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces the original offsets and
widths for all 8,731 instructions; 8,730 normalized instruction forms
match exactly with the partial frame allocation the sole exception
(candidate 0x270 vs original complete 0x2B4). Independently tested:
798 original internal branches; 105 valid original outbound destinations;
781 original-bound nonlocal COFF call/float relocations plus 2 original
local jump-table fields; 81 original case-entry targets.

probe_prefix.py compiles the verified states and deliberately UNACCEPTED
neutral placeholder cases for other selector IDs, keeping original ESI
codegen by retaining authentic late states 300–306. These placeholders
are not reconstruction progress.

## Next work

Start **state204** at 0x00459441 (original function offset 0x7BF1).
First differing opcode at 0x00459444 (offset 0x7BF4), original reads
the 0x158 dash flag byte, while the current local probe uses a
state204 placeholder. Focused command:

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 204 --context 8

**NOT full-function Exact**: 30,964 original code bytes, 19 missing
live states, 37 other unreviewed cases, complete stack/frame/return and
switch tables remain open. Do not run all-unit cold replay, patch machine
bytes, or overclaim runtime equivalence.
