# Nayuki Character10::Slot07 — first 12,858 original code bytes reviewed

Original Nayuki vtable Slot07 at 0x0078828C selects the full native
[0x00468870, 0x0046D895) owner: 20,517 original x86 bytes,
SHA-256 cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9.
The complete code extent is directly followed by a 28-entry destination
table at 0x0046D895, then a 100-entry compact ID table at 0x0046D905;
do not classify these tables as instruction bytes or CC padding.

Natural C++ workbench Character10Effects.cpp now reconstructs
[0x00468870,0x0046BAAA), **12,858 original code bytes /
2,895 x86 instructions**, original prefix SHA-256
ae6f216e043d32cec93d9c21d9ab0feece5b3f27e510f45a4377c477be8e5038.
The complete owner still spans 20,517 bytes; not whole Exact.

Selected native workbench audit only (no full replay):

    scripts/repo-python workbench/nayuki-effects/check_prefix.py

VC7.1 /Od /G6 /MT /Gy /W3 emits **2,894 matching
original instruction forms and operands** in
their original same-width locations, except the
incomplete frame allocation (the original frame
is 0x1D4; candidate frame changes as later effects
are recovered). **159 original in-prefix branch
destinations, 22 original outbound targets and
147 non-switch original-bound COFF relocations**
over 27 uniquely bound symbol targets agree.
Both compiler-local switch-table relocations
are treated separately, and the first 15
original case destinations are verified against
canonical switch table bytes. None of this
claims an Exact whole owner or complete jump table.

The now-reviewed natural C++ includes Nayuki effect
handlers 0x190–0x19E: hit/ground bounces, opponent
facing and distance tests, camera-bound clipping,
multi-frame 0x19A/0x19B particle bursts, and
randomized 0x19C projectile emissions. The
0x19B, 0x19C, 0x19D and 0x19E bodies extend the
prior 0x19A random-particle family with their
original state permissions, timing and source
call order. Floating-point literal bit patterns,
RandomRange and local emission callees have been
checked against the target, not copied unchecked.

Continue at original 0x0046BAAA, case 0x19F.
**7,659 original code bytes remain open**,
plus original final 0x1D4 stack lifetime, the
remaining switch targets, return and relocations.
Later sibling-derived source remains experimental
until audited. No full-game cold replay.
