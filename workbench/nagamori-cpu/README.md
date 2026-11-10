# Nagamori Slot05 CPU boss — partial natural C++

Original vtable slot 5 at `0x00788410` points to
`Character06::Slot05` at `[0x004B2AC0,0x004B667C)`, **15,292 code
bytes**, followed by four `CC` bytes. The complete original SHA-256 is
`14a83398918558355cd4ae747fa313b60f62771f1758ba870a593d29f596bfb9`.

`Character06Cpu.cpp` reconstructs original CPU input initialization,
random defensive decisions, opponent distance and the first close-
and medium-range offensive choices. The shape was tested initially
using another accepted character's CPU source, but every retained
instruction is compared against Nagamori's own executable.

The reviewed original contiguous prefix
[0x004B2AC0,0x004B54CF) contains **10,767 bytes and
2,737 instructions**, SHA-256
077793f37f1408d598ced341ccd23fba753fabb486116aa75840d8029c786303.

Selected pinned VC7.1 emits a **10,760-byte partial COFF
function** (2,739 instructions including temporary epilogue,
190 relocations). **2,735 / 2,736 comparable forms** agree,
with incomplete stack frame 0xC4 instead of original 0xE8.
The final original instruction jumps to the shared exit.
The diagnostic checks **373 internal branch destinations**
and **120 IEEE-754 literal payloads** against the original.

This source now implements the recovered defensive, movement,
CPU state 4..11 and collision-follow-up action 0xC8..0xD1
decisions. New 0xCF / 0xD0 / 0xD1 groups cover conditional
command selection, meter gates, jump/button responses and
horizontal steering, preserving priority and return placement.

Compile/test only this TU:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

Continue at original 0x004B54CF (action 0xE7). This is
**not strict Exact**; the remaining 4,525 target bytes,
shared exit, full frame and target-bound relocations are
still unfinished.
