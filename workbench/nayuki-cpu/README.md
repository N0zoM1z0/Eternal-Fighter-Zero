# Nayuki Character10::Slot05 CPU boss — original-bound partial C++

The original Nayuki vtable slot05 at 0x00788284 selects 0x004654A0.
Its complete authored code extent [0x004654A0,0x0046886B)
is **13,259 original x86 bytes**, with five trailing CC padding
bytes and whole-owner SHA-256
fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce.

Natural C++ workbench Character10Cpu.cpp now covers
[0x004654A0,0x00467153), **7,347 original bytes /
1,874 instructions**, prefix SHA-256
823141cebf49e73c64d42eee79cdb22a0e2d2d6e1daeb2c7cb60353ae4791ff2.

Nayuki's CPU source now restores the original initial
defensive policy, A8/A9 graded special commands,
AA airborne reactions, CPU state 4–10 recovery,
FA/FC grounded vs airborne counterattacks,
0x10C timed four-button sequence, and complete
randomized collision response trees for 0xC8,
0xC9, 0xCA and 0xCB. The 0xCA logic includes a
150-unit airborne dependent upper timer bound,
action-field 3148 dependent 10-frame extension
and 0x6E meter option; 0xCB prioritizes original
0x0A/0x1E/0x46/0x34/0x6E/0x64 commands, with the
original roll and meter gates and state-4 fallback.
Every RandomRange call and apparently redundant
timer check is retained in original source order.

Focused selected native build and audit:

    scripts/repo-python workbench/nayuki-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits **7,343
code bytes / 1,876 instructions**, including
temporary return, with **111 COFF relocations**.
Of 1,873 comparable original body instructions,
**1,872 match** after call/jump/float normalization.
The incomplete stack allocation is 0x98 versus
original 0xC0; one original near JMP shortens
because the actual distant return is absent.
All **263 in-prefix branch targets, 75 valid
original outbound targets, and 111 original-bound
relocations** agree, with 27 uniquely bound symbols
and exact IEEE-754 literal payload comparisons.

Next original block is 0x00467153 (0xCC collision
response and subsequent actions). **Not full Exact**:
5,912 original code bytes and the original stack,
shared return and remaining relocations are still
open. No all-unit cold replay was performed.
The unverified action-Slot04 experiment is retained
in workbench/nayuki-action.
