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

Reviewed code [0x00451850,0x0045AC54): **37,892 / 62,693 original bytes**,
**10,405 original x86 instructions**, SHA-256:
eec18795aa057bd38ccb9fdf18e6ff18ed7f9fe757f47e6bed32fe161913f2fb.

The reviewed default and **94 live cases** are 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220 and 221. State213 restores the 0.04-gravity airborne
recovery, meter award and landing transition to state97; state214
handles its >0 landing frame10 skip. State220 restores a genuine
Nayuki throw: ground-only hit activation, 40..600 X clamp, opponent
state107 and facing-relative opponent placement, impact effect at
facing*37 and -22. State221 awards ApplyDamage(1000, 750.0), places
the opponent into state63 with knockback (1.0,-2.5), sets opponent Y
-50, and drags the opponent by facing each of frames 1–3.

Native selected-prefix verification (NOT full owner Exact):

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces all **10,405 original
instruction offsets, widths and normalized opcode forms** except for
the provisional frame allocation (0x298 candidate vs 0x2B4 original).
Original-bound verification includes **963 internal branch targets**,
**134 outbound targets**, **859 call/IEEE-754 COFF references**,
2 local switch operands, and **94 original selector destinations**.
The original `Secondary::ApplyDamage` call at 0x4105A0 has been bound.

## Next action and remaining scope

Original state230 begins at **0x0045AC54**. Examine its current inherited
body against original bytes; begin with:

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 230 --context 12

**24,801 remaining code bytes**, full 0x2B4 stack frame, complete
local switch tables, remaining relocations and shared return are open.
Source has 118 of 137 live case labels: **94 reviewed**, 24 existing
unreviewed and **19 absent IDs 263–281**. `probe_prefix.py` includes
deliberately UNACCEPTED neutral marker bodies for other states and
late 300–306 code to preserve ESI/prologue. No all-unit cold replay,
no whole-game runtime claim and no full Exact acceptance.
