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

Original [0x00451850,0x0045FCE4): **58,516 / 62,693 code bytes**,
**16,034 x86 instructions**, SHA-256
`70732f7eb87ab9be57e4de741db4f3167fc800d548ec96898f425e406134311f`.
Original default plus **133 live state bodies** now have selected
original-bound checks. All 137 case IDs exist in authored C++.

State301 (597 bytes) is a full original two-thousand-meter special:
it zeros motion and gravity on entry, shakes the screen through
frame2, spends 2000 meter, sets hitstun120 and tint(0xB0,3), and
emits global type0x45/palette5 at (int X,int Y-40). It enables the
10-frame input lock from frame2, and at frame4 emits local type0x197
at X+facing*14, Y-41, using original owner/group/field write order.
Its frame5 timer shortens by field3148*6.

State302 (608 bytes) spends **3000 meter**, uses global type0x46,
palette0x40 and local type0x198; additionally sets context sound0x25
and calls accepted `Context::SetSceneTimer(15)` at 0x004080C0 after
frame2. Unlike 301, 302 has no 0xF2 input-lock assignment.
Original direct-call targets and the complete code/branch forms
were independently bound to EFZ.exe. The prior complete function
proof remains valid.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` checks **16,034 original native
instruction offsets, widths and normalized forms** except temporary
frame allocation (candidate 0x330, native 0x2B4), **1,500 internal
branches**, **228 outbound targets**, **1,198 nonlocal original-bound
COFF call/float references**, 2 switch operands and **133 original
case destinations**. This is selected-prefix evidence, NOT full Exact.

## Next state and remaining closure

**State303 at 0x0045FCE4** begins the four unreviewed original bodies
303–306. The other 133 state cases are original-bound compared.
**4,177 original code bytes**, full canonical stack, switch DATA,
remaining relocation bindings and common return are open.
Continue with original disassembly and focused
`probe_prefix.py --through 303 --context 12`; no all-unit cold
replay and no acceptance of unverified inherited source.
