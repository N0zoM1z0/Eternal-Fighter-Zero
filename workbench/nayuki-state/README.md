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

Reviewed original code [0x00451850,0x0045D1CB): **47,483 / 62,693 code
bytes**, **13,042 original x86 instructions**, SHA-256:
47d1a6e4b4ee51636bcdba81eb4976b3f0bd71ae0b41934144aef48a414c9046.

Reviewed original default and **113 live states**: 1–9, 13–16,
47, 50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232, 248–254, and 256–264.

States261/262 are 587/889-byte native airborne multi-hit chains;
state263 (629 bytes) is the first formerly missing Nayuki-specific
natural case, restoring tiered airborne recovery, repeated hit count
and a frame16->5 loop. State264 (721 bytes), also previously absent,
now has authentic frame logic: frame0 zeroes motion and sets two hits;
after frame9 it decelerates horizontal speed by 0.08 until zero;
frames4/6 trigger context sound21. At frame11 the timer may skip
forward at tick24 for tiers >3; other early frame gates depend on
`field3148*3` at frame11 or tier thresholds on frames1 and2.
Frame4 grants meter45 and horizontal speed 2.2, or 3.4 when
`field3138==1`. Frame7 loops to frame4 while `field313c<2`, or
at the higher limit 4 when `field3138==1`; completed animations
return to state7 after ResetFrame then virtual ResetPose.

The original byte-bound IEEE-754 references were independently checked:
state264 horizontal damping 0.08 at 0x7881D0, base speed 2.2 at
0x787D20 and alternate 3.4 at 0x7881C8. Merely matching instruction
forms without canonical float bindings would not have caught
incorrect constants, so `check_prefix.py` enforces them too.

Focused selected native check:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` matches **13,042 original instruction
offsets, widths and normalized opcode forms** except the temporary
stack allocation (partial 0x2F8, original 0x2B4). It independently
validates **1,199 original internal branches**, **169 outbound targets**,
**1,024 original-bound nonlocal call/float COFF references**, two local
switch operands and **113 original selector destinations**. This is a
selected prefix, NOT full-function Exact.

## Next missing case and remaining work

Original state265 starts at **0x0045D1CB**; cases265–281 do not yet
exist as natural C++ and must be reconstructed, not bypassed. Focused
probe: `probe_prefix.py --through 265 --context 12`.

**15,210 original code bytes**, full original 0x2B4 frame, adjacent
552/306-byte local switch DATA, remaining relocations and common
return remain open. Workbench now has 120 of 137 live case labels:
113 reviewed, 7 inherited/unreviewed 300–306 and **17 absent
265–281**. Generated marker cases are UNACCEPTED placeholders;
never treat them as complete source or run all-unit cold replay.
