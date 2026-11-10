# Nayuki Character10::Slot07 — first 14,094 original code bytes reviewed

Original Nayuki vtable Slot07 at 0x0078828C selects the full native
[0x00468870, 0x0046D895) owner: 20,517 original x86 bytes,
SHA-256 cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9.
The complete code extent is directly followed by a 28-entry destination
table at 0x0046D895, then a 100-entry compact ID table at 0x0046D905;
do not classify these tables as instruction bytes or CC padding.

Natural C++ workbench Character10Effects.cpp now recovers
[0x00468870,0x0046BF7E), **14,094 original code
bytes / 3,170 x86 instructions**, prefix SHA-256
79b89b0d6463f8bf02314a914b46b220bad96bd3d0d2f98f00a29ee71d09ba25.
This does NOT make the 20,517-byte owner full Exact.

Selected native prefix audit (no full replay):

    scripts/repo-python workbench/nayuki-effects/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reconstructs
**3,169/3,170 original instruction forms/operands**
with identical in-prefix offsets and widths;
the missing full 0x1D4 stack lifetime still causes
a different temporary candidate stack allocation.
All **178 original internal jump targets**, **25 valid
original outbound destinations**, and **150
original-bound non-switch COFF relocations**
across 29 distinct reference symbols agree.
Two compiler-local jump-table relocations are
independently identified; the first 18 canonical
effect cases are validated from original target data.

Restored natural C++ covers original effect handlers
0x190–0x1A1. It includes impact/contact bounce,
camera clipping, timed local particle bursts,
randomized 0x19C emission, and the 0x19F/0x1A0
positions recorded in Character10 field314C/
field3150 and field3154/field3158 respectively,
for action types 0x12F–0x131. The new 0x1A1
branch uses its original -1.9 horizontal and
-2.5 vertical speed, 0.035 gravity, and group
change at frame 7. Both original frame0 guards,
effect tick priorities and float bit patterns are
recovered without artificial opcode patches.

Continue at original 0x0046BF7E, effect 0x1AB.
**6,423 original code bytes remain**, plus full stack,
compiler jump-table completion and final return,
so this stays a PARTIAL workbench checkpoint.
Later sibling-derived effects remain unreviewed.
No full cold replay or game runtime claim.
