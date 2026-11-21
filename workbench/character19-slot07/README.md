# Character19::Slot07 workbench

Target: 0x0067CF50, reviewed native code extent [0x0067CF50, 0x0068340B) (25,787 bytes). The vtable at 0x00788CE0 + 0x1c selects this owner.

The production source in src/Character19Effects.cpp is a complete natural-C++ port of the 54-case local-effect update/lifetime dispatcher. It preserves the native 64-entry effect ring, per-type frame progression, local effect emission/removal, Kanna-specific random motion, and state-sensitive sound/effect paths.

## Current reconstruction state

The selected VC7.1 /Od /G6 /MT /Gy /W3 compile succeeds. The current COFF symbol is 26,122 bytes, including 320 bytes of switch data (55 four-byte jump entries plus a 100-byte selector table) after the native code owner. The candidate code prefix is now 25,802 bytes versus 25,787 native bytes: 15 bytes longer, not Exact. The 100-byte selector table matches the native table byte-for-byte; 265 COFF relocations remain to be bound and verified.

The current pass made these source-level corrections:

- Moved case 0x1c0 to the native switch-arm order.
- Corrected all ten case-0x1f0 spawn pairs to use the character's positionX/positionY, not the active effect slot's x/y.
- Corrected all ten case-0x1f0 spawn group writes from field0030 to the actual group field, matching the native byte stores.
- Matched the unsigned-short field tests and <= 1 threshold, then inverted the equivalent if/else so the spawn path precedes the frame-update path as in the native layout.

Those changes reduced the candidate code prefix by 294 bytes (26,033 to 25,739). A follow-up codegen probe showed the native counter updates use 16-bit register increments rather than promoted 32-bit arithmetic. Rewriting 63 tick/frame arithmetic assignments as natural postfix increments now reproduces all 108 native 16-bit counter-increment instruction pairs exactly. This added 63 bytes and moved the code prefix to 25,802 bytes. The case-0x1f0 interval is now 1,401 bytes, matching native exactly. Remaining per-arm size deltas are localized to cases 0x196, 0x197, 0x19b-0x19e, 0x1ab, 0x1ad, 0x1ae, 0x1b1, and several one-byte-short arms around 0x1a3-0x1a9 and 0x1b0-0x1b7. Continue resolving these from the original instruction stream; do not promote this source as Exact until the selected replay reaches zero differences and all original relocations are explicitly bound.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
