# Character19::Slot07 workbench

Target: 0x0067CF50, reviewed native code extent [0x0067CF50, 0x0068340B) (25,787 bytes). The vtable at 0x00788CE0 + 0x1c selects this owner.

The production source in src/Character19Effects.cpp is a complete natural-C++ port of the 54-case local-effect update/lifetime dispatcher. It preserves the native 64-entry effect ring, per-type frame progression, local effect emission/removal, Kanna-specific random motion, and state-sensitive sound/effect paths.

## Current reconstruction state

The selected VC7.1 /Od /G6 /MT /Gy /W3 compile succeeds. The COFF symbol is now exactly 26,107 bytes: 25,787 bytes of native code followed by 320 bytes of compiler-emitted switch data (55 four-byte jump entries plus a 100-byte selector table). All 55 candidate switch entries now resolve to the corresponding native case boundaries, and the 100-byte selector table matches byte-for-byte. The source code prefix and every case interval have the exact native length. The 265 COFF relocations (69 REL32, 196 DIR32) still require original-target binding and full replay; do not call this Exact until that replay passes.

The source-level progress includes:

- Moved case 0x1c0 to native switch-arm order.
- Corrected all ten case-0x1f0 spawn pairs to use the character's positionX/positionY, not the active effect slot's x/y.
- Corrected the case-0x1f0 group writes and all nine other native group=2 stores to the byte group field.
- Corrected six case-0x1b7 spawn payload writes from palette to field0030.
- Removed 33 incorrect signed casts from unsigned-short field0008 comparisons.
- Rewrote 42 tick and 21 frame increments plus 10 tick decrements as natural 16-bit postfix operators.
- Reordered case 0x196 and 0x197 to match native branch order and thresholds.
- Recovered the outer lifetime branch order for cases 0x19b through 0x19e while preserving floating-point unordered-value behavior.
- Reordered case 0x1b1's boundary and removal arm to match the native path.
- Rewrote all 52 tick/frame-duration and 52 frame/frame-count comparisons with the native operand order (tick >= frameDuration, frame >= frameCount). This is semantically equivalent C++, but VC7.1 now emits the native branch polarity and register assignment.

The current code prefix is 25,787/25,787 bytes. All 55 switch intervals and all 55 jump-table destinations match the native case boundaries; the selector table is 100/100 exact. A register-aware instruction-signature diagnostic reports 97.53% mean similarity and 100% median similarity across the 55 intervals; the largest remaining divergence is case 0x1ae. This diagnostic is not an acceptance metric. Per-case boundaries, source/object hashes and the current state are recorded in progress.json. The next gate is explicit binding of all 265 original relocations and the selected exact replay. No ASM, padding, or byte patching is used.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
