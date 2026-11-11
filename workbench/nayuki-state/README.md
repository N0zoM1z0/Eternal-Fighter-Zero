# Nayuki Character10::Slot06 — native state boss workbench (partial)

Canonical vtable slot06 (0x00788288) selects 62,693 code bytes
[0x00451850,0x00460D35), SHA-256:
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Original adjacent jump tables consist of 138 four-byte destinations
at 0x00460D35 and 306 selector bytes at 0x00460F5D.
The selector maps 137 live state IDs and 169 default IDs.

## Reviewed selected original prefix

[0x00451850,0x0045824C): **27,132 original code bytes,
7,486 original x86 instructions**, SHA-256:
7f7dc354621912742a96787549560f9177abe51ab70f29d8f67dfef2a0325690.

Natural C++ workbench Character10State.cpp has authentic Nayuki
logic for the default and 72 live cases:
1–9, 13–16, 47, 50–77, 81–87, 96–99, 123,
150–158, and 161–169. The state machine is real boss-function
work: grounded/airborne physics, hitstop and damage recovery,
wakeup state96, formerly missing state123, combo/knockback tiers,
animation/collision priorities, and character-specific effect
spawns at states 161/162/165/166/167/168/169.
Original state163/164 includes frame-based trail, camera/ground
collision and 1.4/-0.75/0.015 vs field3148-dependent
-2.0-0.1x/(-1.2) dynamics. State165/166 mirror particle
0x190 with distinct thresholds and exact +36/-36 offsets,
right/left facing and rebound velocity. State167/168/169
control tint, damage, sound and grouped effects. All constants,
register use and source evaluation ordering were checked
against the canonical x87 and call sites, not assumed from
the sibling Makoto state machine.

Run ONLY the selected prefix verifier:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

The verifier emits a local VC7.1 /Od /G6 /MT /Gy /W3 probe
with 72 reviewed original live states plus deliberately
UNACCEPTED placeholder bodies for later state IDs.
Complex late original states 300–306 maintain the native ESI
prologue. Placeholder code is NOT recovered Nayuki behavior.
The generated test source is automatically removed.

The checker establishes 7,486 same-offset, same-width
normalized instruction forms over the opening (except the
single incomplete candidate stack frame 0x24C versus original
0x2B4). It independently validates 667 native in-prefix
branch targets, 89 canonical outbound jumps, 693 source
call/IEEE-754 original-bound COFF relocations, two local
switch references, and 72 exact original case entry targets.
Do not confuse these facts with whole-function Exact.

Continue at original 0x0045824C (state 170).
**35,561 code bytes plus 20 missing original live cases**,
the exact native stack allocation, complete local data,
remaining original relocation targets and final return
are still OPEN. No full cold replay, no binary injection,
and no whole-game runtime equivalence assertion.
