# Sayuri Character09::Slot05 CPU boss — partial C++ reconstruction

The original Character09 vtable slot 5 (0x0078814C) points to
0x0044AB30. Its complete code range [0x0044AB30,0x0044DB5A)
is **12,330 original instruction bytes**, followed by six CC
padding bytes. Full-target SHA-256:
359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5.

The natural-C++ workbench Character09Cpu.cpp covers
[0x0044AB30,0x0044B699), **2,921 original bytes / 791
instructions**, prefix SHA-256
14bf1272ffd01a60679fb196b82ea2edbb314e7ae6e1cfdb57c7c14a3dfdb4af.
The source restores common early CPU random guards, the extra
140-distance Sayuri 0x14 branch, the 40..90 confirmed hit reaction,
and a unique 0xA8/0xA9 action priority tree (80/135/220 forward
distance, meter thresholds, and random command variants).
The literal at 0x787ED8 is 1.0f: using 2.0f instead changes
the target FMUL into an incorrect FADD instruction.

Reproduce only this partial selected native check:

    scripts/repo-python workbench/sayuri-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits 2,917 bytes /
793 instructions with a temporary return and 59 COFF relocations.
Of the 790 comparable original body instructions, 789 agree,
normalizing direct call/branch and FP addresses. The unfinished
stack frame is 0xA4 instead of the complete original 0xD8.
One original five-byte near JMP shrinks to a two-byte JMP
because the distant shared exit is absent. The final original
instruction also jumps to that shared return.
**81 internal jump destinations, 22 valid outbound original
destinations, and all 59 relocation bindings** agree; the
23 symbol targets and full literal bit patterns are verified
against the original executable.

Continue at 0x0044B699 (0xAA aerial action decisions). This
is NOT complete Exact: 9,409 target bytes, the full frame,
return and original relocation closure remain open.
Do not run full all-unit cold replay.
