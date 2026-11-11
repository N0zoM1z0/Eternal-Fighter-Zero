# Nayuki Character10::Slot06 — partial native state-machine reconstruction

**Status: PARTIAL, NOT full Exact.** Work in
`workbench/nayuki-state/Character10State.cpp` and preserve every local
change. The accepted `src/` tree remains separate, and unrecovered
sibling-derived states must never be counted as original source.

## Original owner

Character10 Slot06 vtable entry at 0x00788288 targets code
[0x00451850,0x00460D35), **62,693 bytes**, SHA-256:
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Adjacent separately owned switch DATA: 138 four-byte destinations at
0x00460D35, then 306 selector bytes at 0x00460F5D.
The switch maps 137 live animation IDs and 169 default IDs.

## Selected original-bound native checkpoint

Reviewed original [0x00451850,0x0045B7D4): **40,836 / 62,693 code
bytes** and **11,236 x86 instructions**, SHA-256:
677a6350127d7f1904d1809c250a32e18d523644c27b6c87e7e964fd1560f02b.

The reviewed default and **99 live states** are 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232 and 248–249. State249 is an authentic
**1,015-byte airborne grapple follow-through**, not the inherited
Makoto animation: while frames are <7 it applies horizontal offset and
shake (50,3), drags opponent Y from own Y minus a 66/69/73/74/71/70
step sequence and X from own X plus facing times 23/21/19/19/17/16.
At frame7/tick0 it sets opponent facing, Y = own Y - 60,
X = own X - facing*37, opponent state63, calls
`ApplyDamage(1300,500.0)`, resets opponent, and sets original
knockback (-2,-1). At frame11 it changes gravity to 0.035,
inverts own facing on transition, and loops late frames by minus two.
The original floating-point and integer operations, call order and
branch forms are compared independently.

Reproduce focused original-bound comparison, never all-unit cold replay:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` reproduces **11,236 native
instruction offsets, widths and normalized forms** except temporary
frame allocation (partial candidate 0x2C0 versus original 0x2B4).
Original-bound checks verify **1,030 internal branches**, **146
outbound destinations**, **889 nonlocal call/IEEE-754 COFF
references**, two local switch operands and **99 original cases**.
This is selected-prefix evidence, not whole-function Exact.

## Next original state and open scope

State250 begins at **0x0045B7D4**. The sibling-derived candidate is
still unreviewed; use original disassembly and
`probe_prefix.py --through 250 --context 12` to advance.

**21,857 code bytes**, complete 0x2B4 original frame, switch DATA,
remaining relocations and shared return remain open.
Of 137 live IDs, 118 labels are present: **99 reviewed**, 19 existing
unreviewed and 19 absent (263–281). The partial probe deliberately
uses UNACCEPTED neutral markers and late 300–306 scaffolding to keep
the compiler prologue. Do not treat these as accepted C++.
