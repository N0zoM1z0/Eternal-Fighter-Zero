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

Reviewed code [0x00451850,0x0045B1EB): **39,323 / 62,693 original
bytes**, **10,794 original x86 instructions**, SHA-256:
cea46d99882ded7e580281a97cde1c51e76ffe390829f55dc43d9878b8007cb6.

The reviewed default and **97 live cases** are 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221 and 230–232. States213–214 restore airborne
landing and wakeup; state220 repairs Nayuki's grounded throw and
state221 the 750-damage-scaled follow-through. States230–232 were
recovered from original aerial action logic rather than inherited
Makoto StartTrail/dash branches. 230 and 231 react to aerial
cancellation without a field015c restriction, and 231 sets frame1
remaining hits to field3148/2+2. State232 triggers 30-meter/3-hit
activation and tier-dependent three-tick frame advance.

Reproduce **focused** native checks only:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces **10,794 native instruction
offsets, widths and normalized forms**, except the temporary partial
frame allocation (0x298 vs original 0x2B4). Original-bound checks:
**1,002 internal branches**, **143 outbound destinations**, **865
nonlocal COFF call/IEEE-754 references**, two local switch operands
and **97 original case entry destinations**.

## Next code target and open scope

Original state248 starts at **0x0045B1EB** and is still unreviewed.
The existing copy from a sibling character is NOT verified. Probe:

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 248 --context 12

This is a selected *prefix*, **NOT full Exact**. **23,370 original code
bytes** remain, along with the complete 0x2B4 stack frame, local
switch tables, relocations and shared return. Of 137 original live
IDs, source has 118 cases: **97 reviewed**, **21 unreviewed** and
**19 missing IDs 263–281**. The selective probe includes deliberately
UNACCEPTED neutral marker branches for unrelated later cases and
original-like 300–306 bodies to preserve register/prologue shape.
Never use full cold replay merely for this edited workbench.
