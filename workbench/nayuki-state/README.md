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

Code [0x00451850,0x0045A62F): **36,319 / 62,693 original bytes**,
**9,968 original x86 instructions**, SHA-256:
5fe28ffd5d7739caed581e0b3305934da74398440173511cacfd387b4f3d1247.

The reviewed default and **90 live cases** are 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180 and 200–212.

States 204–209 were restored against original frame gates, dash
physics, multi-hit and rebound behavior. State210's existing four-frame
launcher now independently matches the native code. State211 was
reconstructed as a grounded attack-cancel with frame3 meter/hit award
and no inherited landing code. State212 was rebuilt as the 583-byte
aerial rebound with state257 collision counter-transition, ground
impact effect, early frame5 loop, and state7 exit. Unreviewed state213
begins immediately after this selected prefix.

Run **focused** checks from repository root:

    scripts/repo-python scripts/verify-target.py
    scripts/repo-python workbench/nayuki-state/check_prefix.py
    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 213 --context 12

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces all **9,968 original
offsets and opcode widths**; the 9,967 other normalized instruction
forms match, apart from the incomplete stack allocation (temporary
0x280 versus native full 0x2B4). Independently original-bound:
**936 internal branch destinations**, **127 valid outbound targets**,
**829 nonlocal call/float COFF relocations**, **2 switch operands**,
**90 original selector targets**. Branch target/relocation checks do
not count marker cases as reconstruction.

## Next code target and caveats

Original state213 starts at **0x0045A62F**, and the first mismatch
is at **0x0045A632** (owner offset 0x8DE2). The provisional candidate
for state213 is not matched. Use original disassembly to reconstruct
its physics and transitions; avoid generic sibling templates.

**26,374 code bytes**, the full stack, original local switch tables,
remaining COFF relocations and common return are open.
Of 137 original live IDs, source has 118 labels: 90 reviewed,
28 unreviewed and 19 absent (263–281). `probe_prefix.py` inserts
UNACCEPTED neutral branches for later states and authentic late
300–306 bodies solely to preserve compiler structure. No all-unit
cold replay, no whole-image or runtime claim, and no full Exact.
