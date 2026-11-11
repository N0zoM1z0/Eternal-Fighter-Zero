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

Reviewed original [0x00451850,0x0045D7A7): **48,983 / 62,693 code
bytes**, **13,446 native x86 instructions**, original prefix SHA-256:
1da4b3feae3309afd71e0801abbb795a0624414550d6ca4e60c95b973d66db2f.

Reviewed default and **115 live states**: 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232, 248–254, and 256–266.

The previously missing **states263–266** now have complete natural
original-bound C++ paths. State263 (629 bytes) implements an aerial
rebound with tiered frame5 launch and frame16 restart. State264
(721 bytes) is an advanced horizontal attack with frame4 speed 2.2
or 3.4, -0.08 drag and early timer gates. State265 (697 bytes) is
its reverse, frame4 speed -2.2 and +0.08 drag to zero. State266
(803 bytes) is a **resource-consuming variant**: frame0 deducts
500/250 resource based on field0120, emits global effect33/palette11,
and sets hitCount to field3148+1. After frame9, it subtracts 0.3
horizontal speed and sets one remaining hit before clamping speed at
zero. Frame4 grants meter45 and velocityX=2.5, with two frame7->4
loops (field313c bounds 2/4 according to field3138) and frame11
and frames1/2 tier-dependent shortened durations. No frame11 fixed
24-tick skip occurs in this variant. All three new nonlocal IEEE-754
payloads are checked against original data.

Run only the focused original-bound native check:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` compares **13,446 same-offset,
same-width original x86 instruction forms** excluding only the
partial candidate stack allocation (0x300 vs original 0x2B4).
Original-bound: **1,252 internal jumps**, **173 outbound targets**,
**1,045 nonlocal COFF call/float relocation bindings**, 2 local
switch-address operands and **115 original selector case targets**.
This is selected-prefix verification, NOT whole-owner Exact.

## Next missing case and unresolved full owner

Original **state267 begins at 0x0045D7A7**. States267–281 are still
missing natural source and require original disassembly, not sibling
hypotheses or synthetic marker cases. Focused probe:

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 267 --context 12

**13,710 remaining code bytes**, canonical 0x2B4 stack frame,
552/306-byte local switch DATA, remaining COFF relocations and
shared return are open. Of 137 original live IDs, 122 now have
source labels: **115 reviewed**, seven later 300–306 unreviewed,
**15 missing 267–281**. Marker cases in the probe are UNACCEPTED;
no all-unit cold replay or whole-game runtime/portability claim.
