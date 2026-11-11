# Nayuki Character10::Slot06 — focused native reconstruction

**Status: PARTIAL, NOT complete Exact.** The natural C++ workbench is
workbench/nayuki-state/Character10State.cpp. The accepted src/ tree is separate.
Retain and reconcile dirty edits; inherited later Makoto-state hypotheses are
not original Nayuki evidence.

## Original owner

Character10 vtable Slot06 at 0x00788288 selects original code
[0x00451850,0x00460D35): **62,693 bytes**, SHA-256
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Separate immediately adjacent tables: 138 four-byte destinations at
0x00460D35 and 306 selector bytes at 0x00460F5D.
Of 306 animation IDs, 137 are live, 169 map to default.
The workbench has 118 of 137 case labels; 19 absent IDs 263–281.
Of its present labels, 87 are prefix-reviewed and 31 later remain unverified.

## Selected native checkpoint

Original [0x00451850,0x0045A0F0): **34,976 / 62,693 code bytes**,
**9,602 original x86 instructions**, prefix SHA-256:
0fda318cf0ae26e7ede886e6a07b8a2c43c6a84081e1f631383ff6c4eabb4cf0.

The reviewed default and **87 live cases** are 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180 and 200–209.
States 204/205 implement frame skips and hit/meter changes; state206
restores a three-tick frame gate keyed by field3148; state207 matches
its original airborne cancellation and landing logic; state208 scales
remainingHitCount with field3148/2+2; state209 adds its original
30-meter, three-hit activation and another dynamic frame gate.

Selected native check (no all-unit cold replay):

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 matches **9,602 original offsets and
instruction widths**, and all normalized opcode forms except the
incomplete partial stack allocation (candidate 0x280 vs original 0x2B4).
Original-bound checks cover **903 internal branches**, **120 valid
outbound destinations**, **805 bound call/float COFF relocations**, two
local switch operands, and **87 original selector case destinations**.

probe_prefix.py emits test-only neutral marker branches for unreviewed
live cases and retains later 300–306 states to reproduce register usage.
Those test markers are NOT recovered source and this prefix is NOT
full-function Exact. 31 present state bodies are still unreviewed and
19 original IDs 263–281 have no authored body.

## Next code target

Original state210 starts **0x0045A0F0** (function offset 0x88A0).
The unreviewed source differs at **0x0045A0F7** (offset 0x88A7), where
the original checks frame number and the probe does not yet include
an authentic 210 body. Read original disassembly and compare:

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 210 --context 10

**27,717 original code bytes** remain, plus the full stack, local
switch tables, relocations and shared return. Do not publish Exact.

## Next code target

Next original state206 starts **0x00459901** (offset 0x80B1).
First mismatch after the selected prefix is **0x00459904** (0x80B4):
target reads byte [eax+0x158], while the unreviewed local probe
uses a marker branch for state206.

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 206 --context 8

**Not whole-function Exact:** 29,748 original code bytes, 19 missing live
case bodies (IDs 263–281), 35 existing unreviewed later cases, full native
0x2B4 stack, local jump tables, remaining relocations and return are OPEN.
No all-unit cold replay or whole-game runtime claim.
