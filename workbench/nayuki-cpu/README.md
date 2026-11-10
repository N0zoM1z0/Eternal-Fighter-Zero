# Nayuki Character10::Slot05 CPU boss — original-bound partial C++

The original Nayuki vtable slot05 at 0x00788284 selects 0x004654A0.
Its complete authored code extent [0x004654A0,0x0046886B)
is **13,259 original x86 bytes**, with five trailing CC padding
bytes and whole-owner SHA-256
fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce.

Natural C++ workbench Character10Cpu.cpp now covers
[0x004654A0,0x004678AA), **9,226 original
code bytes / 2,308 instructions**, prefix SHA-256
2a2f2b43bcd16144c2b0e974e500568118337fa710cd417cb0326f97d4177cf1.

The natural source now reconstructs the early CPU
state, Nayuki-specific A8/A9 and AA reactions,
states 4–10, FA/FC and 0x10C follow-ups,
and complete 0xC8–0xD1 attack-collision priorities.
New 0xCF/D0/D1 follow-ups include the original
60x30 fast hit window, opponent-airborne reaction,
the original state-1/3/4 fallback rolls and
short/long timer thresholds. The C8–D1 trees
retain authentic call order and overlapping
timer conditions, with no manual byte patches.

Run only the selected native prefix audit:

    scripts/repo-python workbench/nayuki-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits **9,216
bytes / 2,310 instructions**, including its temporary
return, and **132 original-bound COFF relocations**.
Of 2,307 comparable original body instructions,
**2,306 match** after branch/call/literal normalization.
The incomplete native stack frame is still 0x98,
rather than original 0xC0, and three original near
JMPs shrink to short jumps because the full shared
exit is absent. All **333 original internal branch
destinations, 104 valid outbound jump targets and
132 original-bound relocations agree** across 28
distinct verified symbol bindings.

Next original block is 0x004678AA, the generic
ground/air CPU decision tail. **Not complete Exact**:
4,033 original bytes, full stack/return and
remaining relocation closure remain open.
No full-game cold replay was run. The unverified
Nayuki Slot04 experiment remains in its workbench.
