# Nayuki Character10::Slot05 CPU boss — original-bound partial C++

The original Nayuki vtable slot05 at 0x00788284 selects 0x004654A0.
Its complete authored code extent [0x004654A0,0x0046886B)
is **13,259 original x86 bytes**, with five trailing CC padding
bytes and whole-owner SHA-256
fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce.

The natural-source workbench Character10Cpu.cpp recovers
[0x004654A0,0x004668D5), **5,173 original code
bytes / 1,379 original x86 instructions**, prefix SHA-256
84f93312ce88b7dec59b456344cebcbd3e858ea7de184adbf46a02bcb739955b.

The shared early CPU policy was adjusted for Nayuki's unique
A8/A9 graded 0x48/0x16/0x0C/0x61 commands,
AA aerial attacks, opponent reactions, A5/A6 dash pulse,
and CPU state 4–10 recovery. New original FA/FC
counterattacks preserve the timed windows 0–300, 300–450,
450–550 and 550–650, first checking the opponent is
grounded (positionY == 0.0), then airborne (positionY < 0).
A separate original 0x10C owner uses 120/160/100
horizontal distance limits and up to four distinct
button-pulse outcomes. The grounded/airborne split
was proven from x87 FUCOMPP flags; using a seemingly
reasonable '< 0.0' guess for all four branches generates
different native code. The horizontal/vertical distance
distinction was likewise reviewed against original
stack references.

Reproduce ONLY this selected workbench:

    scripts/repo-python workbench/nayuki-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits a
**5,169-byte / 1,381-instruction partial body**
including the temporary three-instruction return,
with **87 COFF relocations**. Of 1,378 original
body instructions compared, **1,377 forms and
operands agree** after branch/call/float-reference
normalization; only the incomplete 0x90 frame
differs from original 0xC0. One original near
JMP currently shrinks to a JMP short because
the complete shared return is not available;
the last original prefix instruction itself
jumps to that distant return. **185 original
internal branch targets, 44 valid original
outbound targets, and all 87 target-bound COFF
relocations agree**, with 26 uniquely bound
symbols and full IEEE-754 bit comparisons.

Continue at original 0x004668D5 (remaining Nayuki
action-collision and generic CPU AI selection).
**Not Exact:** 8,086 original bytes, full frame,
return and later relocations remain open. The
unverified action-Slot04 experiment remains in
workbench/nayuki-action, untouched. No full replay.
