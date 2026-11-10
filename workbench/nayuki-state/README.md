# Nayuki Character10::Slot06 — partial reconstruction of the 62,693-byte state boss

Original Nayuki vtable slot06 at 0x00788288 selects x86 code
[0x00451850,0x00460D35), **62,693 bytes**, SHA-256
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Separate contiguous data comprises 138 switch destinations (552 bytes)
at 0x00460D35 plus 306 selector bytes at 0x00460F5D:
**137 live state IDs and 169 default mappings**.

## Reviewed selected native prefix

[0x00451850,0x00457483): **23,603 original code bytes,
6,524 original i386 instructions**, SHA-256
90c23e75f2b9c002223a451d66722efd6b1f23a19f17636840ef6f24950cb671.

Character10State.cpp is a natural C++ *workbench*, not an accepted
whole-function implementation. Native Nayuki behavior has been recovered
for the original default branch and **63 live cases**:
1–9, 13–16, 47, 50–77, 81–87, 96–99, 123, and 150–158.
This includes real movement, gravity, dash and boost, frame counters,
grounded and airborne knockback, wall collision, effect emission,
wakeup state 96 cooldown, previously missing state 123's neutral
recovery to state 99, six grounded recoil transitions 150–155,
and 156–158 airborne reactions. Sibling-only initial inputY state
switches and dash flag writes were removed where the Nayuki executable
does not contain them. State 157/158 original animation completion
uses ResetPose into state 9, not Makoto's repeated two-frame loop.
Canonical constants, x87 flags, relative-branch targets and direct calls
were independently checked.

Run ONLY the selected prefix checker:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

It regenerates a manageable VC7.1 /Od /G6 /MT /Gy /W3 unit with authentic
reviewed cases plus **deliberately unaccepted neutral markers** for the
remaining canonical live IDs. The large inherited workbench is NOT
silently accepted or cold-replayed; the marker bodies are not counted
as recovered code. Authentic late state 300–306 bodies in the probe
preserve original ESI prologue and compiler shape.

The checked prefix has **6,524 matching original normalized forms,
same instruction widths and same byte offsets**, except the one partial
stack allocation (0x20C in the current probe, original 0x2B4).
It verifies **594 canonical internal jump targets, 72 valid outbound
branch targets, 608 independent original-bound non-local COFF call/float
relocations and 2 compiler-local switch-table fields**. The 63 original
case-entry targets are checked against both canonical dispatch tables.

**NOT whole-function Exact.** The remaining 39,090 code bytes,
20 missing Nayuki-specific live states, complete 0x2B4 stack frame,
late control flow, original switch tables, final shared return and
all remaining relocation targets require reconstruction.
Continue at 0x00457483 (original state 161).
No all-unit cold replay, injected opcodes or runtime-equivalence claim.
