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

The reviewed original prefix [0x004B2AC0,0x004B3891) now contains
**3,537 bytes / 974 x86 instructions**. The focused pinned VC7.1
compiler reproduces **972 of the first 973 original instruction forms
and operands**, normalizing branch/direct-call destinations and original
FP constant addresses. The one differing form is the unfinished
stack allocation: sub esp,0xE8 in the complete target versus
sub esp,0xA8 in the partial source. The final original prefix
instruction, a five-byte jump to the complete owner's shared return,
cannot exist in this partial source; it falls into a temporary return
instead. The candidate is **3,529 bytes / 976 instructions including
the three temporary epilogue instructions**, with 86 COFF relocations.

Matching normalized instruction forms is not byte-exact proof: an
earlier conditional jump is short in the candidate but near in the
complete owner, and direct-call/constant addresses require original
binding. Full-function Exact status remains open.

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

A new five-branch aerial-state priority chain begins at original
0x004B35F2: for action 0xAA, pose 1, tick 0 it can enter 3-state AI,
select buttons 0/1/2 from relative height and forward distance, or
issue command 0x16. Its thresholds are the original -50/-40/-30/0/50
relative heights, 50/60/80/100/120 distance cutoffs, and 5x/2x
random chance factors. In particular, the last 2x chance naturally
emits the original fld plus x87 fadd st(0),st(0) using
field00a8 * 2.0f; directly adding two field reads emits different
machine instructions. These extra 671 original bytes are included
in the audited native prefix, not claimed as stand-alone Exact.

The **next** original branch starts at 0x004B3891 (opponent
aerial-state responses and randomized commands). Continue this
15,292-byte boss from its own original instructions without byte
padding or a full-game replay.
