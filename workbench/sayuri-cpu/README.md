# Sayuri Character09::Slot05 CPU boss — partial C++ reconstruction

The original Character09 vtable slot 5 (0x0078814C) points to
0x0044AB30. Its complete code range [0x0044AB30,0x0044DB5A)
is **12,330 original instruction bytes**, followed by six CC
padding bytes. Full-target SHA-256:
359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5.

The natural-C++ workbench Character09Cpu.cpp now covers
[0x0044AB30,0x0044BE2B), **4,859 original bytes /
1,297 instructions**, prefix SHA-256
46b3ef24f1cfb2419c126a2c3abd72fc30ae4562a0e682cbca08093cb946d06b.

The source restores the common defensive CPU opening and
Sayuri-specific 140-distance 0x14 trigger, 40..90 collision
reaction, 0xA8/0xA9 graded command selection and the
five-priority AA-state aerial attack decisions (including
upward/downward relative Y, ±30/40/80 thresholds and
the meter-gated command 0x2A). It now also reconstructs
the grounded and airborne opponent 0xA8/0xA9/0xAA
reactions, and CPU state 0–7 recovery: dash-direction
inputs, state reset, one-shot button pulses and the
airborne 0x28 state. The opponent attack check is
hitstunFrames at +0x14C, NOT guardInputFrames at +0x14E.
The attacker reaction probability uses the canonical
15.0f literal at 0x787EB0, not an inferred 10.0f.

Reproduce the native focused comparison only:

    scripts/repo-python workbench/sayuri-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits a
4,855-byte partial candidate / 1,299 instructions,
including a three-instruction temporary epilogue,
with **96 COFF relocations**. Of 1,296 original
comparable body instructions, **1,295 match** after
call/jump/float-reference normalization; the only
differing instruction form is the incomplete stack
frame (0xC0 versus original 0xD8). One original
five-byte near JMP shrinks to a short JMP before
the temporary epilogue; the original last prefix
instruction also targets the future shared return.
**151 in-prefix branch destinations, 37 valid outbound
original branches and all 96 original-bound
relocations** agree, including all literal byte
payloads and 28 uniquely bound symbols.

Continue from original 0x0044BE2B (randomized
collision reaction/attack continuation). **Not full
Exact**: 7,471 target bytes, complete stack lifetime,
return and relocation closure remain unfinished.
No full all-unit cold replay was performed.
