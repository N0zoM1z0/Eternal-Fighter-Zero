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

Reviewed original code [0x00451850,0x0045C6C1): **44,657 / 62,693
code bytes**, **12,270 original x86 instructions**, SHA-256:
03fb8403a7c8c9928e7990fdaff79d770cf187e6715ec69eff0f50e12792e27a.

Reviewed original default and **109 live states**: 1–9, 13–16,
47, 50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232, 248–254, 256–260.

States 249–252 restore Nayuki's airborne grapple, tier-gated local
attack effects, resource expenditure and sound/meter controls.
States 253–257 replace sibling templates with authentic launches,
wall bounce (`CollisionSide`, state257) and recovery input reset.
New state258 (284 bytes) sets gravity 0.04, halves horizontal speed
on first tick, awards one remaining hit at frame3, and transitions
to state97 on landing. State259 (254 bytes) unconditionally calls
`ResetFrame`, increases `field3148` at frame10, caps at nine,
emits sound slots 4/5 and exits via state7 after ResetPose.
State260 is a **712-byte tiered airborne launcher**: starts with
zero motion, gravity .035 and one hit, falls when airborne, applies
.025 horizontal damping during frames5–8, increments field313c
on frame changes, and on frame4 grants meter45 with launch speeds
(1.8,-1.9), tiers >2 (2.1,-2), >5 (2.4,-2.1), >8 (3,-2.2).
The frame5 transition can skip to6/7/8 based on tiers; frames6–8
rewind to9, reducing horizontal speed by 0.3 at frame9. It exits
to state7 only after `ResetFrame()` and `ResetPose()` in that order.
Preserving `velocityY + positionY` operand order was required to
reproduce the original x87 `fld`/`fadd` sequence.

Run focused original-bound comparison:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` reproduces **12,270 original
instruction offsets, widths and normalized opcode forms** except
for the partial stack allocation (0x2F0 candidate vs 0x2B4
original). Original-bound checks verify **1,112 internal branches**,
**161 outbound destinations**, **962 nonlocal COFF call/IEEE-754
references**, two local switch operands and **109 original selector
case destinations**. This is selected-prefix evidence, NOT full Exact.

## Next original state and remaining work

Original state261 starts at **0x0045C6C1** and still uses an inherited
unverified template. Use `probe_prefix.py --through 261 --context 12`
and original disassembly. **18,036 original code bytes**, full
stack, local switch tables, remaining relocations and common return
are open. Of 137 live IDs, source has 118 labels: 109 reviewed,
9 existing unreviewed and 19 missing IDs 263–281. Neutral marker
cases and late 300–306 compiler scaffolding are not reconstructed
source. Do not run all-unit cold replay for this owner.
