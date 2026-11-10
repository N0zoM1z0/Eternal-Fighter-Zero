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

[0x00451850, 0x0045649A): **19,530 original code bytes /
5,377 original x86 instructions**, original SHA-256
6f9523c035e1ba22be13357225561c2cfc80e173b698cddc90787ff3086bc3f7.

Nayuki-specific C++ has now been reviewed for the original default
branch and **49 live state cases**: 1–9, 13–16, 47, 50–77 and 81–87.
Reconstructed behavior includes field3148-dependent movement, jumps,
grounded recoil, wall and airborne collisions, late knockdown,
state 81–86 impact/launch/ground-contact reactions, and original
state 87's effect 0x1EF on render layer 1. The earlier Makoto
structural experiment did not have the correct layer or dash
flag behavior. IEEE-754 literals, local effect spawn order and
the original branch targets are verified from the canonical binary.

Selected native audit only:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

The checker recompiles a **focused selected function**: the 49
authentic reviewed early cases, deliberately unaccepted neutral
markers for the other selector IDs, and authentic late state
300–306 structural branches to preserve the original VC7.1
ESI prologue. All marker bodies remain unreviewed and are
excluded from the matched prefix. The temporary source is
always cleaned up.

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces **5,377
same-offset/same-width original instruction forms** except
its deliberately incomplete stack allocation (the original
full frame is 0x2B4). The selected checker confirms **498
original internal jump destinations**, **58 canonical
outbound targets**, **490 original-bound external
call/IEEE-754 relocation fields**, **two** independently
verified local switch-table references, and the first
**49 canonical case entries** from the original selector
and jump destination tables.

Next original code address **0x0045649A**, live state 96.
**43,163 original code bytes**, full 0x2B4 stack lifetime,
21 absent live case labels, remaining codegen, original
switch tables and relocation closure are OPEN. Do not
claim whole-function Exact, runtime equivalence or
all-unit cold replay.
