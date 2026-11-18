# Character19::Slot07 workbench

Target: 0x0067CF50, reviewed native code extent [0x0067CF50, 0x0068340B) (25,787 bytes). The vtable at 0x00788CE0 + 0x1c selects this owner.

The production source in src/Character19Effects.cpp is a complete natural-C++ port of the 54-case local-effect update/lifetime dispatcher. It preserves the native 64-entry effect ring, per-type frame progression, local effect emission/removal, Kanna-specific random motion, and state-sensitive sound/effect paths.

## Current reconstruction state

The selected VC7.1 /Od /G6 /MT /Gy /W3 compile succeeds. The current COFF symbol is 26,059 bytes, including 320 bytes of switch data (55 four-byte jump entries plus a 100-byte selector table) that sits after the native code owner. The candidate code prefix is 25,739 bytes versus 25,787 native bytes: 48 bytes shorter, not Exact. The 100-byte selector table matches the native table byte-for-byte; 265 COFF relocations remain to be bound and verified.

The current pass made these source-level corrections:

- Moved case 0x1c0 to the native switch-arm order.
- Corrected all ten case-0x1f0 spawn pairs to use the character's positionX/positionY, not the active effect slot's x/y.
- Corrected all ten case-0x1f0 spawn group writes from field0030 to the actual group field, matching the native byte stores.
- Matched the unsigned-short field tests and <= 1 threshold, then inverted the equivalent if/else so the spawn path precedes the frame-update path as in the native layout.

Those changes reduced the candidate code prefix by 294 bytes (26,033 to 25,739). The case-0x1f0 interval is now 1,399 bytes versus 1,401 native bytes, with the native branch ordering reproduced. Other per-arm differences remain small but still need instruction-level resolution. Do not promote this source as Exact until the selected replay reaches zero differences and all original relocations are explicitly bound.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
