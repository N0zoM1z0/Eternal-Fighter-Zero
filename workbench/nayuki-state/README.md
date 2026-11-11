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

Code [0x00451850,0x0045DA2B): **49,627 / 62,693 bytes**, **13,615
original x86 instructions**, SHA-256
038868d2b0bbdabdf424cc724faa7f697ac46b5a9f003a204687fd4d0a3f32cf.
Reviewed default and **116 live case IDs** through 267, including the
previously missing source for states263–267. Case267 is an authentic
644-byte resource-consuming attack: frame0 deducts 500/250 resource,
emits global type33/palette11 impact, clears motion and sets 99 hits.
After frame9, horizontal velocity decays by 0.3 and clamps to zero.
Frame4 grants meter45 and velocityX **2.8**; frames4/6 trigger sound21,
while frame7 repeats from4 under tiered `field313c` limits.
Unlike case266, it uses an ordinary `timing.frameDuration` gate with no
fast-forward condition and does not clamp remaining hits later.
Canonical float relocations for 500/250, 0.3 and 2.8 were checked.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Selected pinned VC7.1 `/Od /G6 /MT /Gy /W3` comparison verifies
**13,615 same-offset/width normalized instructions**, **1,270 internal
jumps**, **175 outbound targets**, **1,058 original-bound nonlocal
call/float COFF references**, 2 local switch operands and **116
selector case targets**. Only the partial stack allocation differs
(candidate 0x308, original 0x2B4). This is NOT whole Exact.

## Next state and open work

State268 begins at **0x0045DA2B**. Natural source has 123 of 137 live
case labels: **116 reviewed**, seven existing unreviewed 300–306,
**14 absent 268–281**. Reconstruct actual state268 disassembly, not
synthetic markers, then use the focused `probe_prefix.py --through 268`.
**13,066 remaining original code bytes**, complete native stack,
switch DATA and shared return remain open. Never run all-unit cold replay
for this selective owner; no whole-game/runtime claim.
