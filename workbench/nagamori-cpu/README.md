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

The reviewed original prefix `[0x004B2AC0,0x004B35ED)` contains
**2,861 bytes / 784 x86 instructions**. The focused pinned VC7.1
compiler reproduces **783 original instruction forms and operands**,
normalizing only branch/direct-call destinations and original FP
constant addresses. The one differing instruction is the unfinished
stack allocation: `sub esp,0xE8` in the complete target versus
`sub esp,0x94` in the partial source. The partial output is **2,858
bytes** and finishes with a temporary return; it is NOT full-function
Exact. Its stack allocation has grown naturally as real decisions
are restored, without padding.

The current source preserves Nagamori's 3.0f close-range aggression
factor (rather than a sibling's 2x), original forward range 60–120
`buttonPulse[0]=3`, conditional commands 0x0C/0x48, a randomized
0x14-or-0x16 attack, and 0x65/0x66 meter tiers. A further three
original ranges select different attacks: under 160 uses 3x chance
and `field0118 > 500.0` for 0x0C; 160–220 uses 1x chance and a
random 0x46-series command; over 220 uses 1x chance plus the 500
permission gate for a random 0x0A-series command. The range literals
160.0/220.0 are verified at original `0x00787370`/`0x00787ED0`.

Reproduce by compiling only this workbench TU:

```bash
scripts/repo-python workbench/nagamori-cpu/check_prefix.py
```

The next original branch begins at `0x004B35F2`. The rest of the CPU
behavior is not implemented. An unaccepted full sibling-derived
source hypothesis remains privately in
`.analysis/probes/nagamori-slot05-sibling-candidate.cpp` for study.
No full cold replay is needed.
