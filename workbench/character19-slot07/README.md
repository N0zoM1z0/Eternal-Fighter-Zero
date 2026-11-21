# Character19::Slot07 workbench

Target: 0x0067CF50, reviewed native code extent [0x0067CF50, 0x0068340B) (25,787 bytes). The vtable at 0x00788CE0 + 0x1c selects this owner.

The production source in src/Character19Effects.cpp is a complete natural-C++ port of the 54-case local-effect update/lifetime dispatcher. It preserves the native 64-entry effect ring, per-type frame progression, local effect emission/removal, Kanna-specific random motion, and state-sensitive sound/effect paths.

## Current reconstruction state

The selected VC7.1 /Od /G6 /MT /Gy /W3 compile succeeds. The current COFF symbol is 26,105 bytes, including 320 bytes of compiler-emitted switch data (55 four-byte jump entries plus a 100-byte selector table) after the native code owner. The natural-C++ code prefix is 25,785 bytes versus 25,787 native bytes: 2 bytes shorter, not Exact. The 100-byte selector table matches the native table byte-for-byte; all 265 COFF relocations still require original-target binding and verification. The appended switch data must not be mistaken for part of the native function extent.

The source-level progress includes:

- Moved case 0x1c0 to native switch-arm order.
- Corrected all ten case-0x1f0 spawn pairs to use the character's positionX/positionY, not the active effect slot's x/y.
- Corrected the case-0x1f0 group writes and all nine other native group=2 stores to the byte group field.
- Corrected six case-0x1b7 spawn payload writes from palette to field0030.
- Removed 33 incorrect signed casts from the unsigned-short field0008 comparisons.
- Rewrote 42 tick and 21 frame increments and 10 tick decrements as natural 16-bit postfix operators. VC7.1 now emits the native-width MOV/ADD/SUB forms.
- Reordered case 0x196 and 0x197 to match native branch-arm order and thresholds.
- Recovered the outer lifetime branch order for cases 0x19b through 0x19e while preserving floating-point unordered-value behavior.
- Reordered case 0x1b1's boundary and removal arm to match the native path.

The current candidate has 53 of 55 switch intervals at their exact native lengths. Only case 0x1b4 and 0x1b7 remain one byte short each, leaving the code prefix two bytes shorter overall. The complete per-case boundary table, source/object hashes and current status are recorded in progress.json. The 320-byte appended compiler switch data consists of 55 relocatable jump entries and a 100-byte selector table; the selector table is already byte-exact. This is still not Exact: original code bytes and all 265 relocations must be independently bound and verified. No ASM, padding, or byte patching is being used.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
