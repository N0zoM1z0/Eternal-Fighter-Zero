# Sayuri Character09::Slot02 — command interpreter (partial natural C++)

The original Character09/Sayuri vtable at 0x00788138 has its virtual
Slot02 pointer at 0x00788140, selecting 0x004493C0.
The complete original function [0x004493C0,0x0044AB2B) is
**5,995 bytes** with canonical SHA-256
e4aa3f06f35134fcecf1fc29caee30cacfc38fcad71244148689c41e17212436.
The shared return ends at 0x0044AB2A; five CC padding bytes precede
the next function at 0x0044AB30.

The natural C++ source Character09Commands.cpp now covers
[0x004493C0,0x0044A3E2), **4,130 original bytes /
1,229 x86 instructions**, prefix SHA-256
1160ebee6eb1b523fe6778afd6717e5f9fc7bbc485ae4d0f6384b81c5837c8c5.

Nine prioritized original command scans are reconstructed:
0x62, 0xAA, 0xA0, 0x64, 0x6E, 0x46,
0x14, 0x0A and 0x28. They preserve the
original 180-frame circular index arithmetic,
facing-conditioned direction tests, staged button
transitions, meter constraints and landing restrictions.
Importantly, the initial 0x14 scan uses a grounded
state check while the 0x28 scan requires positionY < 0.0:
the latter was independently corrected after x87
comparison instructions exposed the wrong condition.

Rebuild only this candidate with:

    scripts/repo-python workbench/sayuri-commands/check_prefix.py

The pinned VC7.1 /Od /G6 /MT /Gy /W3 compiler yields
a **4,131-byte partial function / 1,232 instructions**,
including a temporary three-instruction epilogue.
**1,229/1,229 original instruction forms and operands**
agree after normalizing call/jump destinations and
float literal addresses; **150 in-prefix branch
destinations** agree by instruction ordinal, while
17 outbound jumps resolve to original full-function
instructions beyond this reviewed segment. The one
branch-width change is a final 5-byte original
near jump becoming a 2-byte JMP to the temporary
return; all other instruction widths align. **Eight
COFF double relocations** are checked against exact
IEEE-754 zero bits at 0x007872F8.

Next original branch is 0x0044A3E2, an additional
0x1E-series command scan. The remaining **1,865
original bytes**, shared exit and complete symbol
binding are open. Do not record this partial owner
as Exact, and do not run full cold replay.
