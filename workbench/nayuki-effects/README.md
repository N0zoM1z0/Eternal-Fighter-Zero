# Nayuki Character10::Slot07 — first 9,713 original code bytes reviewed

Original Nayuki vtable Slot07 at 0x0078828C selects the full native
[0x00468870, 0x0046D895) owner: 20,517 original x86 bytes,
SHA-256 cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9.
The complete code extent is directly followed by a 28-entry destination
table at 0x0046D895, then a 100-entry compact ID table at 0x0046D905;
do not classify these tables as instruction bytes or CC padding.

Natural C++ workbench Character10Effects.cpp now reconstructs
Nayuki-specific effect types 0x190–0x199 against the
canonical executable's native control flow:
[0x00468870,0x0046AE61), **9,713 original x86
bytes / 2,187 original instructions**, prefix SHA-256
59483bc2b67477d8e72df5bf12919dd29850a02fa7db5791a66caa050b584164.

Selected reproducible native audit:

    scripts/repo-python workbench/nayuki-effects/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits the
**2,186 comparable matching original instruction forms**
with original offsets and original byte widths.
Only the unfinished full-owner stack allocation differs
(0x380 candidate versus original 0x1D4).
**120 original internal branches**, **17 valid
original outbound branches** and **117 original-bound
non-switch COFF literal/call relocations** across
26 distinct symbols are checked by original bytes.
The two compiler-local switch table relocations
are independently reviewed; ten original dispatch
targets are checked against the original jump table.
Later unreviewed switch cases are NOT exact.

Reconstructed 0x190–0x196 includes frame5 particle,
0x191/0x192 bounce, 0x193 frame6 rollback, 0x194
camera top clamp, 0x195 simple clock, and 0x196
tick30 shake plus child effect. Newly authored
0x197 has twin 0x19A subeffects at ticks 24 and 30
with +/-40 x offsets; 0x198 emits three 0x19B
subeffects at ticks 19/24/30 with 0/+50/-50 x
offsets and SetVerticalShake(15,0); 0x199 emits
randomized child 0x19C from canonical x-50.0
margin with three RandomRange(0,100) calls.
All original floating literals and direct calls
in the reviewed range are original-bound.

Continue at original **0x0046AE61**, effect 0x19A.
**10,804 more original instruction bytes**, full
frame/return and remaining local jump table and
relocations are open. The structural C++ after
0x199 is UNREVIEWED sibling scaffolding; do not
credit it as native exactness. No all-unit cold replay.
