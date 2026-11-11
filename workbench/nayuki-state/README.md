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

Reviewed original [0x00451850,0x0045D484): **48,180 / 62,693 code
bytes**, **13,233 original native x86 instructions**, SHA-256:
b2227e02df897973aea02954620cab14c17ba57d10a72440fab0ce45726a4fcf.

Reviewed original default and **114 live states**: 1–9, 13–16,
47, 50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232, 248–254, and 256–265.

Missing original states263 (629 bytes), 264 (721 bytes), and now
265 (697 bytes) have real C++ source instead of the selective probe's
neutral marker cases. State263 implements a repeated aerial hit chain,
landing frame16->5 restart and frame5 tiered launch. State264 has
long-frame tier gates, frame7->4 hit loops and a 2.2/3.4 horizontal
frame4 launch, decelerating 0.08 after frame9. State265 is the reverse
counterpart: the same original timing/loop structure but 0.08 is
**added** to negative horizontal velocity and clamped at zero, and
frame4 launches at **-2.2** without state264's alternate 3.4 branch.
The canonical constant operands are verified; neither state is a
renamed Makoto template or a matching-instruction-form-only guess.

Focused native original-bound comparison:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` matches **13,233 original
instruction positions, widths and normalized opcode forms** apart
from the incomplete candidate stack allocation (0x2F8 vs native
0x2B4). Independently validated **1,226 internal original jumps**,
**171 canonical outbound destinations**, **1,032 original-bound
nonlocal call/IEEE-754 COFF references**, two switch operands and
**114 original case entry targets**. This is selected-prefix evidence,
NOT complete original-owner Exact.

## Next missing case and unresolved closure

Next original **state266 begins at 0x0045D484**. Missing states266–281
remain; reconstruct their actual original instructions, not synthetic
neutral marker cases. The focus probe can compile through 266 only:

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 266 --context 12

**14,513 original code bytes**, original 0x2B4 stack frame, adjacent
552/306-byte switch DATA, remaining relocations and shared return
are open. Of 137 original live states, source has 121 labels:
114 reviewed, seven unreviewed inherited 300–306 and **16 absent
266–281**. No all-unit cold replay or whole-product/runtime claim.
