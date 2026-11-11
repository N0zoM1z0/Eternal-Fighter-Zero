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

Reviewed original code [0x00451850,0x0045BC9E): **42,062 / 62,693 code
bytes**, **11,569 original x86 instructions**, SHA-256:
765f61bc30ca653dfcfca460f7aea4b55d247c2794cd96f4bb0dbeb6837694fd.

Reviewed default and **102 live states**: 1–9, 13–16, 47, 50–77,
81–87, 96–99, 123, 150–158, 161–171, 178–180, 200–214,
220–221, 230–232, 248–252. State249 was reconstructed as a
1,015-byte aerial grapple that carries/launches the opponent and
calls `ApplyDamage(1300,500.0)` at frame7. States250/251 are
original 348-byte tiered frame-gated attack emissions: `0x191` and
`0x192` at frame3 with original facing*14/Y-41, `field0028 = 1`,
group/layer=0 and virtual `EmitLocalEffect`, incrementing meter by
45. The unusual native timer threshold only reduces the frame
length by `field3148 * 3` when `field000a == 4` (compiler emits
`sub; neg; sbb; inc`), not at all earlier frames.

State252 is a distinct 530-byte resource-consuming variant. On
frame0/tick0 it deducts 500 or 250 depending on `field0120`,
emits global type33 / palette11 at integer Y -50, and calls
`ResetFrame` after the global emission. At frame3 it emits local
`0x193` with the same tiered timer path. Its field-write order
(`field0028` before group/layer) differs from states250/251 and was
confirmed from native instruction offsets.

Selected check (never full cold replay):

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` reproduces **11,569 native
instruction offsets, widths and opcode forms** except the incomplete
stack allocation (partial candidate 0x2E0 versus original 0x2B4).
Original-bound checks include **1,052 internal branches**, **149
outbound destinations**, **903 original-bound nonlocal call/IEEE-754
COFF references**, 2 local switch operands and **102 original selector
case destinations**. Selected-prefix evidence is NOT full Exact.

## Next original state and open scope

State253 begins at **0x0045BC9E** and remains an unverified sibling
template. `probe_prefix.py --through 253 --context 12` is the next
focused comparison. Original function still has **20,631 code bytes**
to recover, a real 0x2B4 frame, local switch DATA, remaining binding
closure and a shared return. Source has 118 of 137 original labels:
102 verified, 16 unreviewed and 19 missing (263–281). Generated
neutral marker branches and late 300–306 scaffolding are NOT source.
