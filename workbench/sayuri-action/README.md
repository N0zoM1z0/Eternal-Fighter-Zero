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

Natural C++ candidate Character09Input.cpp now covers
[0x00446780,0x00448730), **8,112 original bytes /
2,044 instructions** (prefix SHA-256
9823904b804842e36c2fb6d86b4b376d613a4b13a9252ce034fae2ba5a2dac30).

The source restores input buffer aging; the 150–155
opponent-state tint rule; high-priority command/meter
tiers; grounded and aerial commands; command-dependent
A5/A6 air dashes and mirrored A3/A4 ground movement.
It now includes the original command-6 air action
permission guard, action counter increment and
choice of 0x0E, 0x0F or 0x10 based on horizontal
input relative to facing. The original field015c < 2
guard covers the full special-command chain, not only
the first four states; the checker explicitly tests
this previously missed control-flow edge.

Reproduce the selected pinned VC7.1 native build with:

    scripts/repo-python workbench/sayuri-action/check_prefix.py

The partial compiler emits 8,111 bytes / 2,046
instructions including the temporary epilogue,
with **72 COFF relocations**. All 2,043 aligned original
body instructions match after normalizing
direct branch/call and literal addresses; the **original
sub esp,0x14 stack frame is now restored** naturally.
The final original JMP targets the complete shared
exit, so it is absent from the partial C++.
**295 original in-prefix branch targets and all 72
target-bound relocation operands** agree, including
the IEEE-754 constant payloads.

Continue at 0x00448730: defensive input masks, attack
eligibility and generic movement/attack decisions.
**This is not full-function Exact**: 3,007 target
bytes and the final stack/exit/relocation closure
remain. Do not run the full cold replay.
