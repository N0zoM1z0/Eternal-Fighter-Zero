# Sayuri Character09::Slot05 CPU boss — partial C++ reconstruction

The original Character09 vtable slot 5 (0x0078814C) points to
0x0044AB30. Its complete code range [0x0044AB30,0x0044DB5A)
is **12,330 original instruction bytes**, followed by six CC
padding bytes. Full-target SHA-256:
359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5.

The natural C++ source Character09Cpu.cpp now covers
[0x0044AB30,0x0044C9DB), **7,851 original
bytes / 1,997 instructions**, SHA-256
62d89b2cff402fe1d36b0b4497883d5a611bee887871e39b370c824826e206b0.

The recovered source now includes common defensive
CPU guards, Sayuri-specific 0xA8/0xA9/0xAA reactions,
state 0..7 restoration, and action-specific collision
follow-ups **0xC8 through 0xCD**, with original
timer windows, opponent-height conditions, meter
thresholds and button/command choices. C8's
distance<80 action deliberately falls through
rather than returning; original late randomized
state transitions preserve their exact call ordering.

Run the single-owner pinned codegen audit:

    scripts/repo-python workbench/sayuri-cpu/check_prefix.py

VC7.1 /Od /G6 /MT /Gy /W3 compiles **7,844
bytes / 1,999 instructions** including its
temporary epilogue and **138 relocations**.
**1,995/1,996 original comparable body forms**
agree after normalizing original branches, calls
and floating references. The incomplete native
stack allocation is 0xC4 versus original 0xD8.
Two distant original near jumps shorten in this
partial draft; its final prefix instruction jumps
to the shared full-function exit absent from source.
All **251 in-prefix branches, 82 valid original
outbound destinations and 138 target-bound COFF
relocations** agree with unambiguous 29 symbol
bindings and exact original IEEE-754 payloads.

Continue at original 0x0044C9DB, action CE.
**Not whole-function Exact**: 4,479 target bytes
and the complete stack, shared exit and remaining
relocations remain open. No all-unit cold replay.
