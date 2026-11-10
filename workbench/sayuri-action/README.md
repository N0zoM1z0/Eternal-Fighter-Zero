# Sayuri Character09::Slot04 — in-progress command/action boss

This is a real **partial natural C++ reconstruction**, not an Exact owner.
The original Character09 vtable at 0x00788138 has Slot04 at
0x00788148 pointing to the 11,119-byte original function 0x00446780.
The complete canonical code extent is [0x00446780,0x004492EF),
SHA-256 fd248e424f2ebcdddb59462a3101f653e9931e4053d53eb2af9a067e2c0bb286.
All 2,815 original instructions decode contiguously and all 460
direct jumps stay on original instruction starts inside the function.
The shared return is at 0x004492EB. One CC byte separates the function
from the next prologue at 0x004492F0.

The current natural C++ source Character09Input.cpp reconstructs
the first **5,424 original bytes / 1,354 instructions** through
the beginning of the next action guard at 0x00447CB0.
Reviewed prefix SHA-256:
5ba50c91574ca5fbc4642c0a5c508201209c4ed6effb95bc793df4df4d8d952d.

This source covers input-buffer expiration, the animation 150–155
and opponent-action gate, and the strict original priority
of 0x34, 0x62, 0xAC, 0xA0–0xA2, 0x6E–0x70, aerial
0x28–0x2A, grounded 0x14–0x16, 0x1E–0x20, and 0x46–0x48
command families. Grounded/airborne, meter, attackCollisionResult,
sequence flags and frame-start gates remain in their original order.

Run the bounded VC7.1 comparison:

    scripts/repo-python workbench/sayuri-action/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits **5,421 bytes**,
1,356 instructions including the three-instruction temporary
epilogue and 47 COFF relocations. Of the 1,353 aligned,
comparable original body instructions, 1,352 agree after
normalizing original direct-call/jump destinations and fixed
FP constant addresses. The only differing instruction is the
incomplete stack frame (original sub esp,0x14; candidate push ecx).
The target's last instruction in the prefix jumps to the
complete function's distant shared exit, absent from this draft.
**206 in-prefix branch targets and all 47 original-bound
relocation sites** agree with the candidate, including the
original literal IEEE-754 payloads.

Next target block begins at 0x00447CB0 (command 0x0C),
followed by remaining action dispatch. **Do not claim Exact**:
5,695 original bytes, complete stack lifetime, return and
whole-owner relocation closure are still unfinished. Never
run an all-unit cold replay for this draft.
