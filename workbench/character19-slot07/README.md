# Character19::Slot07 workbench

Target: 0x0067CF50, reviewed native code extent [0x0067CF50, 0x0068340B) (25,787 bytes). The vtable at 0x00788CE0 + 0x1c selects this owner.

The production source in src/Character19Effects.cpp is a complete natural-C++ port of the 54-case local-effect update/lifetime dispatcher. It preserves the native 64-entry effect ring, per-type frame progression, local effect emission/removal, Kanna-specific random motion, and state-sensitive sound/effect paths.

## Current reconstruction state

The selected VC7.1 /Od /G6 /MT /Gy /W3 compile succeeds. The current COFF symbol is 26,113 bytes, including 320 bytes of compiler-emitted switch data (55 four-byte jump entries plus a 100-byte selector table) after the native code owner. The natural-C++ code prefix is 25,793 bytes versus 25,787 native bytes: 6 bytes longer, not Exact. The 100-byte selector table matches the native table byte-for-byte; the 265 COFF relocations still require original-target binding and verification. The appended switch data must not be mistaken for part of the native function extent.

The source-level progress includes:

- Moved case 0x1c0 to native switch-arm order.
- Corrected all ten case-0x1f0 spawn pairs to use the character's positionX/positionY, not the active effect slot's x/y.
- Corrected all ten case-0x1f0 spawn group writes from field0030 to the actual group field, matching the native byte stores.
- Matched the unsigned-short field tests and <= 1 threshold, then inverted the equivalent if/else so the spawn path precedes the frame-update path as in the native layout.
- Rewrote 42 tick and 21 frame assignments from promoted-int x = x + 1 expressions to natural 16-bit postfix increments. VC7.1 now emits the native-width MOV/ADD forms, adding 63 bytes to the code prefix.
- Reordered case 0x196 so the field0080 >= 2 transition arm precedes its movement path; its native interval now matches exactly.
- Rewrote case 0x197 with the native <= 0x31 and >= 0x96 thresholds and matching branch-arm order; its native interval now matches exactly.
- Inverted the outer case 0x19b and 0x19d effect predicates with logical negation, preserving the original floating-point truth behavior while moving the removal arm into the native branch layout.

The code prefix moved from 25,739 bytes (48 shorter) to 25,802 bytes (15 longer) after the 63 native-width increment rewrites, then to 25,793 bytes (6 longer) after the branch-layout repairs. Current case-by-case boundaries and source/object hashes are recorded in progress.json. Remaining per-arm differences still require instruction-level resolution. Do not promote this source as Exact until the selected replay reaches zero differences and all original relocations are explicitly bound.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
