# Nayuki Character10::Slot05 CPU boss — original-bound partial C++

The original Nayuki vtable slot05 at 0x00788284 selects 0x004654A0.
Its complete authored code extent [0x004654A0,0x0046886B)
is **13,259 original x86 bytes**, with five trailing CC padding
bytes and whole-owner SHA-256
fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce.

Natural-source workbench Character10Cpu.cpp now covers
[0x004654A0,0x00466D6E), **6,350 original bytes /
1,650 instructions**, prefix SHA-256
c277b4472010e301dcc8f6a5909c399d27d2a98a65d3aa2c6240131090c42e73.

The CPU policy reconstructs Nayuki A8/A9 graded specials,
AA aerial attacks, CPU state 4–10 recovery, FA/FC
ground/air counterattacks, the 0x10C timed four-button
sequence, and complete 0xC8/0xC9 randomized collision
follow-up trees. All original opponent-altitude tests,
forward-distance windows, roll thresholds, input pulses,
state 1/4/7 outcomes, and RandomRange argument/order
remain in their original priority. Overlapping and
apparently unreachable timer windows were retained.

Reproduce only this selected partial native audit:

    scripts/repo-python workbench/nayuki-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits **6,343
bytes / 1,652 instructions** with a temporary return.
Of 1,649 original comparable body instructions,
**1,648 agree** after branch/call/float normalization.
The incomplete stack frame is 0x94 instead of original
0xC0; two original near jumps currently shorten
because the true shared exit has not been reconstructed.
**223 internal branch targets, 62 valid original
outbound destinations, and all 101 original-bound
COFF relocations agree**, with 27 unique symbol
bindings and exact original IEEE-754 literal payloads.

Continue original 0x00466D6E (CA collision follow-up).
**Not whole-function Exact:** 6,909 original code bytes,
full frame/return and remaining original relocations
are still open. Experimental Nayuki action Slot04 remains
untouched in workbench/nayuki-action. No all-unit cold replay.
