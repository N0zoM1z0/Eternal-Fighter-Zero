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

[0x00451850, 0x004525DD): **3,469 original bytes, 991 original
instructions**, SHA-256
da8cab5b1faa8040f8faf416775a9905bcca7ec499a65c3d12e6ef7899f83eef.

Original natural behavior has been recovered for the default branch,
animation IDs **1–9, 13–16, and 47**: Nayuki field3148-dependent
ground speed, 0.024 jump gravity, original -2.0 rising velocity,
direction/dash bonuses, FaceOpponent order, and landing state
transitions. The Makoto-only dash reset and incorrect jump timing
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

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces 991 original
same-offset/same-width x86 instruction forms, except the
incomplete candidate stack allocation (0x180 vs original 0x2B4).
All **78 original internal branch targets, 16 valid canonical
outbound destinations, 76 original-bound external and IEEE-754
literal relocations, and 2 separately verified switch-table
fields** pass. The first 14 original state destinations are
independently checked against original selector/target bytes.

Continue at 0x004525DD (state 50). **59,224 original code
bytes, 21 missing live cases, the complete original stack, all
remaining branches/relocations, owned tables and final return**
remain open. No full cold replay or runtime-equivalence claim.
