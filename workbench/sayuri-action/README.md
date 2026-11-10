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

The current source Character09Input.cpp reconstructs the first **4,474
original bytes / 1,112 instructions**, through the beginning of the next
command guard at 0x004478FA (prefix SHA-256
b48cc6010e85cf04393a3e2ec0ad9af7b7bebe20d3713d976cc77a4da450c028).
It covers buffered action-input expiration; the special 150–155
animation + opponent-ID check; and the ordered 0x34, 0x62, 0xAC,
0xAB/AC, 0xAA/AB/AC, 0xA2, 0xA1/A2, 0xA0/A1/A2, 0x6E/0x6F/0x70 and aerial 0x2A/0x29/0x28 and grounded 0x16/0x15/0x14 command upgrades, with exact
meter thresholds, sequence flags, frame guards and vtable calls.

Run only:

    scripts/repo-python workbench/sayuri-action/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits 4,471 bytes, 1,114
instructions including the temporary three-instruction return and
38 COFF relocations. The first 1,111 target instruction forms/operands
agree except the incomplete stack allocation (target sub esp,0x14,
candidate push ecx). The final target-prefix JMP goes to the original
full-function shared return and is not present in the partial source.
The focused checker additionally verifies **169 internal branch targets
and all 38 original-bound relocation fields** by corresponding
instruction ordinal, including four unique real symbol destinations.
These tests do **not** establish whole-function Exact status.

Continue from original 0x004478FA (next 0x1E/0x1F/0x20 command group), then reconstruct the remaining action dispatch and
shared exit. Do not add this partial workbench to config/matches.csv.
Do not run all-unit cold replay.
