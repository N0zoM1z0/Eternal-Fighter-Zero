# Nayuki Character10::Slot06 — selected original-native state-machine workbench

The original Character10 vtable Slot06 at 0x00788288 selects the state
dispatcher [0x00451850, 0x00460D35): **62,693 original x86 bytes**,
SHA-256 4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Directly adjacent are a 138-entry, 552-byte switch address table at
0x00460D35 and a 306-byte switch selector at 0x00460F5D. Original
selector IDs contain 137 live state cases and 169 default mappings.

Character10State.cpp is an **incomplete** natural C++ workbench whose
initial scaffolding derives from accepted Makoto. Makoto behavior is
not evidence for Nayuki. Eight unsupported sibling case labels have
been removed, but **21 live Nayuki-specific cases are still absent**
from this large source. Never call the full owner Exact yet.

## Original-bound reviewed opening

[0x00451850,0x004557A1): **16,209 original code bytes /
4,470 original x86 instructions**, original SHA-256
97a16c405e5fb6f0b0bc7ca52cec0d3cad72a868b979562b75c9e93c64766db9.

Nayuki-specific natural C++ has now been recovered for the
default state and **42 state IDs**: 1–9, 13–16, 47 and
50–77. This is real state-machine work, not just leaf functions:
field3148-dependent ground speed, original jumping and
directional dash bonuses, wall/airborne collision reactions,
ground hitstun, the distinct 50–58 recoil tiers, landing
priority and 0x61/0x62 knockdown selection. Source was
adjusted using original i386 instruction forms, original
branch targets and exact IEEE-754 literal bits; inherited
sibling-only dash reset instructions were removed where
Nayuki does not execute them.

Run ONLY the selected native prefix audit:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

The check dynamically builds those authentic opening cases
and explicitly *unaccepted* marker branches for other
live IDs, retaining the original 137-case/169-default
selector structure without compiling the entire 154 KB
workbench on every edit. Complex late states 300–306 are
retained in this trial only to preserve VC7.1 ESI prologue
behavior. The placeholder branches are not reconstructed.
The generated source is cleaned up after testing.

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits the same
original offsets, instruction forms and widths for all
4,470 opening instructions except the incomplete partial
stack allocation, currently 0x1C4 rather than
original 0x2B4. It verifies **422 internal original branch
destinations, 49 valid original outbound jump targets,
429 target-bound non-local COFF relocation fields**
(including exact original floats and six named callee
symbols), and two separately verified original local
switch references. All 42 reviewed state entry addresses
are independently crosschecked against the original
138-address table and 306-byte index map.

Continue at **0x004557A1**, native state 81.
**46,484 original code bytes, 21 absent live states,
original 0x2B4 stack, complete jump table/data,
final return and remaining relocations are OPEN**.
This is not full Exact or runtime equivalence.
No all-unit cold replay was performed.
