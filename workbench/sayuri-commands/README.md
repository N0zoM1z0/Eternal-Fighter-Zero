# Sayuri Character09::Slot02 — command interpreter (partial natural C++)

The original Character09/Sayuri vtable at 0x00788138 has its virtual
Slot02 pointer at 0x00788140, selecting 0x004493C0.
The complete original function [0x004493C0,0x0044AB2B) is
**5,995 bytes** with canonical SHA-256
e4aa3f06f35134fcecf1fc29caee30cacfc38fcad71244148689c41e17212436.
The shared return ends at 0x0044AB2A; five CC padding bytes precede
the next function at 0x0044AB30.

The natural source Character09Commands.cpp currently reconstructs the
original contiguous **2,019-byte / 607-instruction** opening
[0x004493C0,0x00449BA3), SHA-256
5c06b95f6afa3c924b9255dc94cd3be8709e3845e373f429c9591b073e4aa742.
It implements four prioritized 180-frame circular history scans:
the first priority command 0x62 with its empty input/hold state gates;
the following 0xAA meter command, 0xA0 eight-stage command and
0x64 six-stage meter command. The input history wraps exactly once
at 180, and the original meter, direction, landing and staged button
conditions preserve natural VC7.1 machine instruction order.

Only compile/review this incomplete owner:

    scripts/repo-python workbench/sayuri-commands/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits 2,023 bytes including
a three-instruction temporary return; the first 607 original
instructions match in form and operands. There are four COFF
floating-point relocations, all verified against the target's
original 0.0 double constant address 0x007872F8. All 80
internal branch destinations agree by instruction ordinal,
and seven outbound jumps target valid original boundaries
outside the recovered portion.

**Not complete Exact**: 3,976 original bytes, remaining priority
history scans, full function shared exit and all original
relocation closure are still open. Continue at 0x00449BA3
(the next six-stage 0x6E command scan). Do not run full cold replay.
