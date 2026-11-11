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

Reviewed [0x00451850,0x0045E955): **53,509 / 62,693 native code
bytes**, **14,677 original x86 instructions**, SHA-256
fb64b228b834142e26b0f0612e24d2a726e5acbeb322181651db495ff3c8c5ac.
Original default plus **123 live states** through274 are reviewed.

State273 is a natural 667-byte reverse counterpart of 272: initial
velocityX **-1.4** rather than +1.4 (IEEE-754 0x788088), while
retaining 0.08 damping, frame1/3 sound21, button cancellation,
frame4 rewind, state268 exit and the canonical call order.
State274 is a separate 408-byte attack: first-tick ResetFrame,
then a tier-dependent frame9 timing gate. On transition to frame7
it selects local effect **0x1AC**, 0x1AD for inputX==facing or
0x1AB for the opposite input; it emits at integer X + facing*30,
Y-50, field0028=1, group/layer=0, facing flag, then gives 45 meter.
Completion resets state0 after virtual ResetPose. The original
`sub/neg/sbb/inc` VC7.1 frame9 indicator and all operands match.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected audit checks **14,677
original instruction offsets/widths/normalized forms** except partial
stack allocation (0x31C vs original 0x2B4), **1,377 internal jumps**,
**206 outbound**, **1,116 nonlocal original-bound COFF call/float
references**, two local switch operands and **123 selector case
entries**. This is NOT full function Exact.

## Next original case and incomplete full owner

State275 starts at **0x0045E955**. Seven original live IDs275–281
remain missing from natural source, alongside seven inherited
300–306 bodies not yet fully verified. Workbench now has 130/137
case labels, 123 reviewed. **9,184 native code bytes**, full
canonical stack, switch DATA, remaining relocations and common return
are open. Probe only `probe_prefix.py --through 275`, never full
all-unit cold replay; marker branches are UNACCEPTED.
