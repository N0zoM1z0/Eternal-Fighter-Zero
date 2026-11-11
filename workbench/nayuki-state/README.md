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

Reviewed code [0x00451850,0x0045C1DF): **43,407 / 62,693 original
bytes**, **11,926 original x86 instructions**, SHA-256:
ced7c15c3fc3e2084b2db13f6696c7870a4666819e9c0dae6777ee288768e301.

Reviewed original default and **106 live states**: 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232, 248–254, and 256–257.
State249 is the authentic 1,015-byte aerial opponent grapple;
250/251 restore effects 0x191/0x192 with a frame4-only field3148
three-tick reduction; 252 adds global effect33 plus resource cost and
local effect0x193. States253 and 254 are distinct grounded/airborne
launches: 253 damps horizontal velocity only when airborne, then
at frame4 gives a 45-meter launch with velocities (1.2,-2.5),
gravity .03 and state256/258 exit; 254 emits local effect0x194 at
frame4 with velocities (1.7,-1.7) and state258 exit.
State256 is a genuine 481-byte wall collision/rebound routine:
frame0 sets 2.4 horizontal speed and one hit, `CollisionSide()`
plus zero `field313c` triggers state257, sound31, impact effect0
and a counter increment; an exhausted hit also transitions to
state257. When grounded, nonnegative vertical speed is reset.
State257 is a 138-byte motion/gravity handler which calls
`Secondary::ClearBufferedButtons` and on animation exit invokes
ResetPose then selects state9. Neither uses sibling dash/trail code.

Focused native comparison:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` reproduces **11,926 original
instruction offsets, widths and normalized opcodes**, except the
incomplete partial stack allocation (candidate 0x2F0 vs original
0x2B4). Original-bound validation includes **1,076 internal branches**,
**155 canonical outbound destinations**, **936 original-bound
nonlocal COFF call/IEEE-754 references**, two local switch operands,
and **106 original selector destinations**. Not full function Exact.

## Next state / remaining scope

State258 begins at **0x0045C1DF** and is still unreviewed. Use
`probe_prefix.py --through 258 --context 12` and original disassembly.
**19,286 original code bytes**, complete frame, local switch DATA,
remaining relocations and shared return are open. Of 137 live IDs,
118 have source labels: **106 reviewed**, 12 inherited unreviewed and
19 absent (263–281). The probe's UNACCEPTED neutral marker branches
and late 300–306 compiler-shape scaffolding do not count as recovered
source. Avoid all-unit cold replay and whole-game claims.
