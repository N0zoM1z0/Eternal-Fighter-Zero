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

Native [0x00451850,0x0045F293): **55,875 / 62,693 original code bytes**,
**15,326 x86 instructions**, SHA-256
`e6fb4d7815706357f70ca149f7719152065aef7d4bfa12c04e2103a633d6dfe5`.
Original default and **127 live states through 278** are reviewed.

New state277 (667 bytes) is an exact original-bound third variant
of the positive-direction charge movement: entry velocityX=1.4,
post-frame3 damping=0.08, context sound21 at frames1/3, input
cancellation to state275/269/274/276/281/271/280/268, repeated
frame4->0 loops and reset to state268 frame8 on completion.
State278 (667 bytes) is the reverse-direction counterpart with
velocityX=-1.4. Both compare at original native instruction positions,
widths, branch destinations and IEEE-754 references; they are natural
source cases, not marker substitutions.

Run focused proof only:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` validates **15,326 original
instruction offsets, widths and normalized forms** except the
incomplete stack frame allocation (candidate 0x328 versus original
0x2B4). Checks bind **1,444 internal branches**, **222 outbound
jump destinations**, **1,157 nonlocal COFF call/float references**,
two switch operands and **127 original case entry targets**.
Selected-prefix evidence is NOT full-function Exact.

## Critical original layout and next work

The physical original order is **state278 at 0x45EFF8, then state300
at 0x45F293, then state279 at 0x45F4E9**. The current selective probe
emits case labels in numeric order, so its synthetic state279 marker
comes before state300 and creates a mismatch at 0x45F293; do NOT
mistake this for a failed 278 body. The local probe's case emission
must preserve original physical order to compare the next region.
Original states279–281 are still missing, and inherited 300–306 are
not yet fully verified. **6,818 original code bytes**, full original
frame, adjacent 552/306-byte switch DATA, remaining relocations and
common return remain open. Avoid full cold replay and unaccepted
neutral case markers.
