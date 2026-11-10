# Nayuki Character10::Slot05 CPU boss — original-bound partial C++

The original Nayuki vtable slot05 at 0x00788284 selects 0x004654A0.
Its complete authored code extent [0x004654A0,0x0046886B)
is **13,259 original x86 bytes**, with five trailing CC padding
bytes and whole-owner SHA-256
fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce.

The natural workbench Character10Cpu.cpp recovers the continuous
[0x004654A0,0x004665E4) opening, **4,420 original code
bytes / 1,186 original x86 instructions**, SHA-256
240202b17a0bdb78ecee357744a568d7b081c79ba92fc5c44df569a72b73929e.

The opening CPU defense/random policy is shared with accepted
Sayuri, but Nayuki's A8/A9 graded special priorities have
0x48/0x16/0x0C/0x61 choices, 100- and 220-unit spacing,
and the A8 hit-confirm/AA aerial response contains its own
0.0/-40.0 and 60.0 thresholds. The reconstructed CPU
reactions include Nayuki-specific A5/A6 dash pulses,
opponent A8-A9-AA response, the 150..156 special,
and CPU state 4–10 handling with the unusual original
conditions retained. The source is not a blind copy of
Sayuri's complete CPU code.

Run ONLY the selected native candidate:

    scripts/repo-python workbench/nayuki-cpu/check_prefix.py

VC7.1 /Od /G6 /MT /Gy /W3 generates **4,416 bytes /
1,188 instructions**, including a temporary three-instruction
return. Of 1,185 comparable original body instructions,
**1,184 are form/operand matched** after normalizing
direct branches and canonical float addresses; the
incomplete frame is candidate 0x90 vs original 0xC0.
The original last instruction jumps to the still-missing
shared return. All **153 internal branch targets**,
**34 validated original outbound destinations** and
**74 original-bound COFF relocations** over 24 symbols
agree, with original float bit patterns verified.

Next original block is 0x004665E4 (Nayuki CPU
collision-confirm and general AI behavior).
**Not full Exact**: 8,839 original code bytes,
full stack frame, shared return and remaining
symbol binding still need reconstruction.
No all-unit cold replay has been run.
