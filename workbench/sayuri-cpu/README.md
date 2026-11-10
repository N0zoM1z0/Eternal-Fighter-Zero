# Sayuri Character09::Slot05 CPU boss — partial C++ reconstruction

The original Character09 vtable slot 5 (0x0078814C) points to
0x0044AB30. Its complete code range [0x0044AB30,0x0044DB5A)
is **12,330 original instruction bytes**, followed by six CC
padding bytes. Full-target SHA-256:
359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5.

The natural-C++ workbench Character09Cpu.cpp now covers
[0x0044AB30,0x0044C2C6), **6,038 original bytes /
1,571 instructions**, prefix SHA-256
6d4c13f9b7139ef0e66278f50d55cb7dca841ec96f2608d9645ac8d8a50a1e1b.

The code reconstructs the original CPU defense entry,
Sayuri-specific 140-distance 0x14 trigger, graded 0xA8/0xA9
reactions, AA-state aerial follow-ups, opponent action
reactions and CPU state 0..7 steering. The main randomized
attack collision tree now covers complete 0xC8/0xC9
decisions, with their precise timer and distance windows,
opponent airborne conditions, meter gates and state changes.
The original C8 button-write path at distance <80 and
roll <400 falls through to subsequent checks, rather
than returning. Every RandomRange call is retained,
including the late timer tests that may be unreachable
after earlier decisions.

Run only the native selected check:

    scripts/repo-python workbench/sayuri-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits a
**6,031-byte / 1,573-instruction partial candidate**
including a temporary epilogue, with **113 COFF
relocations**. Of 1,570 comparable original body
instructions, **1,569 agree** after normalizing direct
call/jump destinations and floating literal addresses.
The incomplete stack frame is 0xC4 rather than
original 0xD8. Two original near jumps to the distant
shared exit shorten to short jumps in the partial
candidate. All **185 internal branch destinations, 57
valid outbound original destinations, and 113 target-
bound relocations** agree, including original literal
payloads and 29 unique symbol bindings.

Next original address is 0x0044C2C6 (0xCA collision
follow-up). **Not complete Exact**: 6,292 remaining
target bytes, full stack/return and relocation closure
are open. No all-unit cold replay was performed.
