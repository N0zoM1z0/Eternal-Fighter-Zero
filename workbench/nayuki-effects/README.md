# Nayuki Character10::Slot07 — first 15,548 original code bytes reviewed

Original Nayuki vtable Slot07 at 0x0078828C selects the full native
[0x00468870, 0x0046D895) owner: 20,517 original x86 bytes,
SHA-256 cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9.
The complete code extent is directly followed by a 28-entry destination
table at 0x0046D895, then a 100-entry compact ID table at 0x0046D905;
do not classify these tables as instruction bytes or CC padding.

Natural C++ workbench Character10Effects.cpp reconstructs
[0x00468870,0x0046C52C), **15,548 original bytes /
3,484 x86 instructions**, canonical SHA-256
944efee87482a799b0b28a0b47956c144f506f91e4ee8500733e4e050e54f5e3.
The original complete owner remains 20,517 bytes.

Selected one-owner native prefix audit:

    scripts/repo-python workbench/nayuki-effects/check_prefix.py

VC7.1 /Od /G6 /MT /Gy /W3 produces
**3,483/3,484 normalized forms/operands** at
their original offsets and original widths;
the single unmatched form is the incomplete
stack frame (candidate 0x1E0 vs original 0x1D4).
The checker verifies **192 original internal
jump targets**, **27 original outbound targets**,
and **166 original-bound non-switch COFF
relocations** over 30 uniquely bound symbols.
The two compiler-local switch table relocations
remain separately checked; the first 20 original
case targets are validated from the canonical
jump table bytes.

Important structural correction: the inherited
sibling effects skeleton originally contained
59 case labels, but the canonical Nayuki switch
table has only 27 live cases. All 32 sibling-only
labels have been removed; the prior experimental
source remains recoverable in Git history.
This naturally restores the original emitted
case-code order and reduces candidate code size
to near the complete original size. No binary
patches or inserted assembly.

Native case bodies now cover 0x190–0x1A1 and
0x1AB/0x1AC. Both newly recovered 0x1AB/0x1AC
bounce effects have native frame0/tick0 guards,
respectively 0.3 and 0.8 horizontal speeds,
-3.5 vertical and +0.045 gravity, a strict
floor-contact field0058 reset at offset 0x528,
the field0080 knockback trigger, -1.5/-0.5
bounce behavior and canonical retirement.

Continue at original 0x0046C52C, effect case 0x1AD.
**4,969 code bytes remain unaccepted**, as do
the final 0x1D4 stack frame and shared exit,
remaining case bodies and full original jump
table relocation closure. NOT whole-function
Exact, no all-unit cold replay or runtime claim.
