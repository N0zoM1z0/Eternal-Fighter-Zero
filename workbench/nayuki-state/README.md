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

Native [0x00451850,0x00460065): **59,413 / 62,693 original code bytes**,
**16,275 original x86 instructions**, SHA-256
`6aec028989229f10eb5fec56e035a4cc60ca59eb9ce9b374a6fda6b8528a0031`.
Default plus **134 live states** are reviewed, and all 137 original
case labels exist in the natural workbench source.

**State303 (897 bytes)** now has original Nayuki C++, not inherited
Makoto scaffolding: first-tick ResetFrame, frame3 spend 1000 meter,
hitstun120, tint0xB0 and global 0x44/palette0x13. Frames6/7 zero
velocity and allow vertical/horizontal motion ±0.5 according to
`inputX/inputY`; later frames apply gravity and a ground collision
between frames8–11 skips to frame12. Frame6 emits two local effects
0x19D and 0x19E at integer X with Y-80/normal Y. Frame8 may loop
back by two until field3138 reaches 14, then gravity becomes .015;
frame12 loops back by two. Exit state7 calls FaceOpponent then
virtual ResetPose. All native call targets and float payloads were
compared against the original.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Focused pinned VC7.1 `/Od /G6 /MT /Gy /W3` proof verifies **16,275
same-offset/same-width normalized original x86 instructions**,
**1,521 internal branches**, **230 outbound branch targets**, **1,217
nonlocal original-bound COFF call/float references**, two switch
operands and **134 native case entries**. Partial compiler frame
0x2F8 vs original 0x2B4; this is NOT full-function Exact.

## Next state and remaining closure

Original **state304 starts 0x00460065**. Three authored but unreviewed
cases304–306 remain, alongside **3,280 original code bytes**, original
stack, adjacent 552/306-byte selector data, remaining relocations and
shared return. Continue focused `probe_prefix.py --through 304`
and original disassembly, not all-unit cold replay. No whole-game
runtime claim.
