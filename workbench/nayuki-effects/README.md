# Nayuki Character10::Slot07 — first 5,731 original code bytes reviewed

Original Nayuki vtable Slot07 at 0x0078828C selects the full native
[0x00468870, 0x0046D895) owner: 20,517 original x86 bytes,
SHA-256 cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9.
The complete code extent is directly followed by a 28-entry destination
table at 0x0046D895, then a 100-entry compact ID table at 0x0046D905;
do not classify these tables as instruction bytes or CC padding.

The naturally authored workbench Character10Effects.cpp now has
Nayuki-specific effect cases 0x190–0x196 reviewed against the
canonical executable. Its contiguous reviewed opening is
[0x00468870, 0x0046A44B), **7,131 original bytes / 1,603
original instructions**, SHA-256
b3c00d2a268e23974a725bd297f8cc906bd7530ee54a213feb9c4b519d7358d7.

Reproduce ONLY the selected native prefix:

    scripts/repo-python workbench/nayuki-effects/check_prefix.py

Pinned native VC7.1 /Od /G6 /MT /Gy /W3 produces 1,603
same-offset, same-width original instruction forms;
1,602 instruction forms and operands agree, with
only the incomplete full-function stack frame
0x34C candidate versus original 0x1D4. The checker
verifies **92 original internal branch targets**,
**14 canonical outbound branches** and **85 verified
original-bound non-switch COFF relocations** over
24 distinct original reference symbols. Two
compiler-local switch-table relocations are independently
identified (not accepted byte-exact), and the first
seven original switch targets are checked against the
canonical target's adjacent case tables.

Reviewed effects include original 0x190 frame5
particle emission, 0x191/0x192 contact bounce and
opposite-facing +/-60 impact windows, 0x193
field0084 conditional bounce and frame6 rollback,
0x194 cameraBounds.top - 40 clipping with x87
operand order matching, 0x195 simple lifetime,
and 0x196 tick30/frame5 vertical shake, subeffect
0x199 and pending sound. Their original float
constants and call destinations are verified.

The entire source body AFTER case 0x196 is
UNREVIEWED sibling-derived structural scaffolding.
Continue at original 0x0046A44B, effect case 0x197.
**13,386 original code bytes** plus full original
stack lifetime, later jump-table layout and many
relocations remain open. Not whole-function Exact,
not a runtime/linkage claim. No full cold replay.
