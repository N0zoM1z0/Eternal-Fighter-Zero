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

[0x00451850, 0x00453147): **6,391 original bytes, 1,765 original
instructions**, SHA-256
d392f15f0e2611a4adffa4424266d4d2b62c8da99d51bea691840c03a47d848f.

Original natural behavior has been recovered for the default branch,
animation IDs **1–9, 13–16, 47, and 50–55**: Nayuki field3148-dependent
ground speed, 0.024 jump gravity, original -2.0 rising velocity,
direction/dash bonuses, FaceOpponent order, and landing state
transitions. The 50–55 grounded recoil tiers now preserve native meter awards, impact-scaling damage, pushback velocity and original recovery timing. The Makoto-only dash reset and incorrect jump timing
were corrected without machine-byte edits.

Selected native audit ONLY:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

The checker uses probe_prefix.py to compile the reviewed opening
with temporary and explicitly unaccepted neutral marker branches
for the other canonical 137 live IDs. Complex late states 300–306
are retained in this *probe only* to preserve the original native
ESI-prologue behavior without repeatedly compiling 154 KB of
experimental source. Marker bodies do not count as reconstructed
behavior. The generated probe source is removed after execution.

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces 1,765 original
same-offset/same-width x86 instruction forms, except the
incomplete candidate stack allocation (0x180 vs original 0x2B4).
All **156 original internal branch targets, 22 valid canonical
outbound destinations, 184 original-bound external and IEEE-754
literal relocations, and 2 separately verified switch-table
fields** pass. The first 20 original state destinations are
independently checked against original selector/target bytes.

Continue at 0x00453147 (state 56). **56,302 original code
bytes, 21 missing live cases, the complete original stack, all
remaining branches/relocations, owned tables and final return**
remain open. No full cold replay or runtime-equivalence claim.
