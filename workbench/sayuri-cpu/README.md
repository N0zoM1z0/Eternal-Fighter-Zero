# Sayuri Character09::Slot05 CPU boss — partial C++ reconstruction

The original Character09 vtable slot 5 (0x0078814C) points to
0x0044AB30. Its complete code range [0x0044AB30,0x0044DB5A)
is **12,330 original instruction bytes**, followed by six CC
padding bytes. Full-target SHA-256:
359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5.

The natural C++ source Character09Cpu.cpp now covers
[0x0044AB30,0x0044C625), **6,901 original
bytes / 1,774 instructions**, SHA-256
7f0791a91b316db677720f52f252478bb4f38b383f952e45e6b4ff0346d9def8.

Recovered logic comprises CPU defensive initialization,
the Sayuri-specific early 0x14 command, graded 0xA8/A9
attack priorities, AA-state aerial follow-ups, CPU
states 0..7, and main 0xC8/0xC9/0xCA/0xCB collision-
confirm trees. The new CA and CB trees preserve original
ground/air eligibility, exact timer intervals, meter
checks, RandomRange calls and attack pulse/input commands.
CB's 700+ timer window depends on the original
attackCollisionResult==3 multiplier, so it must not be
replaced with a constant threshold.

Use only:

    scripts/repo-python workbench/sayuri-cpu/check_prefix.py

VC7.1 /Od /G6 /MT /Gy /W3 emits **6,894 bytes /
1,776 instructions**, including the temporary
three-instruction return and **124 relocations**.
Of 1,773 comparable original instruction forms,
1,772 match after call/jump/float-address
normalization; the one remaining form difference
is the incomplete stack frame, original 0xD8
versus draft 0xC4. Two original near JMPs to the
unrecovered shared return compile as short JMPs.
**219 internal branch destinations**, **68 valid
original outbound jumps** and **all 124 original-
bound COFF relocations**, including 29 unique
symbols and original IEEE-754 payloads, agree.

Next original block is 0x0044C625, the CC action
reaction group. **Not complete Exact**:
5,429 target bytes, complete stack/return and
full relocation closure are still pending. No
all-unit cold replay is performed for this draft.
