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

The current source Character09Input.cpp reconstructs the first **3,770
original bytes / 933 instructions**, through the beginning of the next
command guard at 0x0044763A (prefix SHA-256
1b401b206f86f776949192c39125c138c4a71f27e6a0d0231b1f7c14fba93a15).
It covers buffered action-input expiration; the special 150–155
animation + opponent-ID check; and the ordered 0x34, 0x62, 0xAC,
0xAB/AC, 0xAA/AB/AC, 0xA2, 0xA1/A2, 0xA0/A1/A2, 0x6E/0x6F/0x70 and aerial 0x2A/0x29/0x28 command upgrades, with exact
meter thresholds, sequence flags, frame guards and vtable calls.

Run only:

    scripts/repo-python workbench/sayuri-action/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits 3,767 bytes, 935
instructions including the temporary three-instruction return and
31 COFF relocations. The first 932 target instruction forms/operands
agree except the incomplete stack allocation (target sub esp,0x14,
candidate push ecx). The final target-prefix JMP goes to the original
full-function shared return and is not present in the partial source.
The focused checker additionally verifies **142 internal branch targets
and all 31 original-bound relocation fields** by corresponding
instruction ordinal, including four unique real symbol destinations.
These tests do **not** establish whole-function Exact status.

Continue from original 0x0044763A (next 0x16 command meter/air-action gate), then reconstruct the remaining action dispatch and
shared exit. Do not add this partial workbench to config/matches.csv.
Do not run all-unit cold replay.
