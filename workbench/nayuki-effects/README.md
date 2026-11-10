# Nayuki Character10::Slot07 — first 5,731 original code bytes reviewed

Original Nayuki vtable Slot07 at 0x0078828C selects the full native
[0x00468870, 0x0046D895) owner: 20,517 original x86 bytes,
SHA-256 cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9.
The complete code extent is directly followed by a 28-entry destination
table at 0x0046D895, then a 100-entry compact ID table at 0x0046D905;
do not classify these tables as instruction bytes or CC padding.

The natural C++ candidate Character10Effects.cpp began from the accepted
Character08 structural skeleton; all cases after 0x193 are still
experimental sibling scaffolding and are NOT accepted as Nayuki behavior.
The opening and four Nayuki-specific effect states 0x190–0x193 were
rewritten and reviewed against the original executable:

  [0x00468870, 0x00469ED3): 5,731 bytes / 1,293 original instructions
  SHA-256: 0699fb618eea6325b68ee8e58a6e35dffed7632b616f3dad80bcb988ce613d9d

Reproduce ONLY the selected native prefix audit:

    scripts/repo-python workbench/nayuki-effects/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces all 1,293 original
instruction forms except the as-yet-incomplete stack allocation
(0x348 candidate versus original 0x1D4). Every instruction has the
same original offset and byte width over the compared range. The
checker verifies 77 internal original branch targets, 11 valid original
outbound targets, and 73 original-bound non-switch COFF relocation fields,
including full IEEE-754 literal payloads and four reviewed call targets.
The two switch-table relocations are separately identified, and the
first four canonical switch targets are verified from original table
bytes. The candidate switch table for unreviewed later cases and its
entire remaining owner are NOT accepted as exact.

Reviewed source restores original 0x190 frame-5 particle generation,
0x191 and 0x192 grounded bounce and ±60 position windows,
0x193 field0084 collision permission and frame-6 backward transition,
the original state-dependent particle velocity double constants,
effect layer changes, frame clock, object retirement and group updates.
The original x87 compare flags distinguish >0 from >=0 in the landing
branches; no byte injection or inline assembler was used.

Continue at original 0x00469ED3, 0x194 effect handler. More than 14 KB,
the true final 0x1D4 frame lifetime, complete switch table and all later
relocations remain OPEN. This is a partial checkpoint, NOT whole-function
Exact, game linkage or runtime acceptance. No all-unit cold replay.
