# Sayuri Character09::Slot02 — command interpreter (partial natural C++)

The original Character09/Sayuri vtable at 0x00788138 has its virtual
Slot02 pointer at 0x00788140, selecting 0x004493C0.
The complete original function [0x004493C0,0x0044AB2B) is
**5,995 bytes** with canonical SHA-256
e4aa3f06f35134fcecf1fc29caee30cacfc38fcad71244148689c41e17212436.
The shared return ends at 0x0044AB2A; five CC padding bytes precede
the next function at 0x0044AB30.

The natural source Character09Commands.cpp currently covers
[0x004493C0,0x00449F42), **2,946 original bytes /
885 instructions**, prefix SHA-256
c2a2fdadfdffce690d302893ec4a44fa8c0d6066692450b01fc5c0644ca33340.

The six original prioritized circular history scans are reconstructed:
the initial 0x62 command, the 0xAA and 0xA0 meter
patterns, the 0x64 and 0x6E six-stage patterns, and the
0x46 three-stage command sequence. All 180-frame wrap
arithmetic, meter, facing, button and landing checks
retain the original priority and original x87 load ordering.

Run only:

    scripts/repo-python workbench/sayuri-commands/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 compiles the incomplete
source into **2,947 bytes / 888 instructions** including
a temporary three-instruction return. All **885/885
original instruction forms and operands** agree after
normalizing direct branch destinations and original
double addresses. **112 original in-prefix branch
destinations** agree by instruction ordinal. The 11
outbound jumps still point to valid original owner
instructions beyond the prefix. One final original
5-byte near jump shortens to a 2-byte JMP in the
partial source because the true shared exit is absent;
no other instruction width differs. All **six COFF
floating literal relocations** match the original
IEEE-754 zero constant at 0x007872F8.

Continue at 0x00449F42 (the 0x14 three-stage command
follow-up), then reconstruct the remaining priority
scans, full exit and original relocations. The remaining
**3,049 original bytes are not yet reconstructed**.
**Do not register this incomplete function as Exact**
or run a complete-game cold replay.
