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

Original [0x00451850,0x0045F4E9): **56,473 / 62,693 native code bytes**,
**15,484 x86 instructions**, SHA-256
`b463b5fbe7f5bbcc43f7be5a1495b83fe1f668544c76dc144e0e3805b05726f4`.
The original default, states through278, and **state300** are now
reviewed: **128 live states** total.

**State300 (598 bytes)** was reconstructed against its native owner,
not accepted from inherited Makoto source. At frame0/tick0 it zeros
velocityX, velocityY and gravity; before frame3 it requests horizontal
shake(50,3). At frame2/tick0 it sets hitstun120, spends 1000 meter,
sets tint(0xB0,3), and emits global type0x44/palette0x13 at integer
X and Y-40. Frames >=2 set the 16-bit input lock at offset 0xF2 to
10. At frame4/tick0 it emits local type0x196 at integer X+facing*14,
Y-41, with owner=1, group/layer0, field0028=1, facing flag, and
character sound0. The timer advances on `frameDuration`, or at
frame5/tick `frameDuration - field3148 * 6`, and exits to state0.
This code was compared at every original instruction position,
relative jump and float/call operand.

The **physical original case order differs from numeric case order**:
277 (0x45ED5D), 278 (0x45EFF8), **300 (0x45F293)**,
279 (0x45F4E9). `probe_prefix.py` now orders cases by original jump
addresses from the 138-entry canonical table, not by numeric IDs.
Previously frozen 55,875-byte proof remains valid after this fix.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` matches **15,484 original native
instruction offsets, widths and normalized forms**, except the
provisional stack size (0x328 vs original 0x2B4). Original-bound
checks verify **1,456 internal branches**, **223 outbound targets**,
**1,167 nonlocal COFF call/IEEE-754 references**, two local switch
operands and **128 original case entries**. This is not full Exact.

## Remaining source and next target

Next original state279 starts at **0x0045F4E9**. Only **three case
bodies 279–281** are missing, and six existing 301–306 bodies still
lack whole-function verification. **6,220 original code bytes**,
full native stack, adjacent switch DATA, remaining relocations and
shared return remain unresolved. Use focused original disassembly
and `probe_prefix.py --through 300 --context 12`; marker cases
are UNACCEPTED, and do not perform an all-unit cold replay.
