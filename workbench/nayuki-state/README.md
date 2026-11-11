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

Original [0x00451850,0x0045E522): **52,434 / 62,693 code bytes**,
**14,384 native x86 instructions**, SHA-256
13dafd7fcfc2c3e076888ceca3f3cbe98704626de847d4a575f2d67e508ac110.
The default and **121 live states** through state272 have been reviewed.

State271 is a fully reconstructed 222-byte charge/tier counter:
it always calls ResetFrame, emits sound5 and increments `field3148`
at frame5/tick0, caps field3148 at nine, advances each animation tick
with attackCollisionResult3 and exits by ResetPose then state7.
State272 is a 667-byte combo/cancel state: initializes horizontal
velocity1.4 and zero vertical/deceleration, damps by 0.08 after
frame3, triggers context sound21 on frames1/3, and accepts original
button pulses only before frame4. Input chooses 275/269, 274,
276/281 or 271/280/268 by tier and inputY. Frame4 can rewind to
frame0 while field313c<3, and animation exit switches to state268,
then ResetFrame/ResetPose and rewrites frame to8. Original 1.4/0.08
IEEE-754 references and call order were compared.

Focused selected native verification:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` matches **14,384 original
instruction offsets/widths/normalized forms** except partial stack
allocation (candidate 0x314 vs canonical 0x2B4), **1,349 internal
branches**, **199 outbound targets**, **1,102 original-bound nonlocal
COFF call/float references**, 2 local switch operands and **121
original selector case targets**. This is NOT whole Exact.

## Next state and unresolved work

Original state273 begins **0x0045E522**. **9 missing states273–281**
and seven unreviewed 300–306 remain. Workbench has 128/137 live case
labels, 121 reviewed. **10,259 unmatched native bytes**, full stack,
local switch tables, remaining relocations and shared return are open.
Continue native-driven focused `probe_prefix.py --through 273` only;
marker bodies are UNACCEPTED and full cold replay is prohibited.
