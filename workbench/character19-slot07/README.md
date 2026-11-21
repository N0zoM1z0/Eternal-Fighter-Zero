# Character19::Slot07 workbench

Target: 0x0067CF50, native code extent [0x0067CF50, 0x0068340B) (25,787 bytes) plus 320 bytes of compiler-emitted switch data [0x0068340B, 0x0068354B). The complete reviewed COFF contribution is [0x0067CF50, 0x0068354B) (26,107 bytes). The vtable at 0x00788CE0 + 0x1c selects this owner.

The production source in src/Character19Effects.cpp is a complete natural-C++ port of the 54-case local-effect update/lifetime dispatcher. It preserves the native 64-entry effect ring, per-type frame progression, local effect emission/removal, Kanna-specific random motion, and state-sensitive sound/effect paths.

## Current reconstruction state

The selected VC7.1 /Od /G6 /MT /Gy /W3 compile succeeds. The COFF symbol is exactly 26,107 bytes: 25,787 bytes of native code followed by 320 bytes of compiler-emitted switch data (55 four-byte jump entries plus a 100-byte selector table). All 55 switch entries resolve to their native case boundaries, and the 100-byte selector table matches byte-for-byte. All 265 COFF relocations (69 REL32, 196 DIR32) are explicitly bound to 110 consistent symbols with zero conflicts. The official selected-unit replay returns exact: 26,107/26,107 bytes matched, zero differences, and all 265 relocations accepted.

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
- Restored the native x87 unordered-comparison behavior in cases 0x19b-0x19e. The source now expresses the native negated comparisons for y and vy, and reverses the lower-bound y comparison to match the original x87 status-word tests.
- Reordered three 680-unit x bounds, the case-0x1ae opponent-height comparison, and the 900-unit x bound to reproduce the native x87 evaluation order. This also aligns every code relocation operand to the same byte offset as its native counterpart.
- Corrected the spawn payloads in cases 0x190-0x192 to use group = 0 and field0028 = 1 in native store order, rather than group = 1 and field0030 = 0. All three case instruction signatures now match 100%.
- Rewrote five negative facing multipliers in case 0x1f0 as positive magnitudes followed by subtraction, matching the native SHL/IMUL plus SUB instruction sequences.
- Rewrote the ring-wrap condition as i >= 0x40, matching the native CMP 0x40 / JL sequence.
- Added explicit switch breaks to 21 native early-advance paths so they leave the type switch and resume at the shared effect-ring increment, rather than falling through into the next effect-type arm.

The complete contribution is now Exact. The native code prefix is 25,787/25,787 bytes; all 55 switch intervals and all 55 jump-table destinations match the native case boundaries; the 100-byte selector table is exact. All 210 code relocation field offsets align with native operands. The manifest binds all 265 relocations (69 REL32, 196 DIR32) to 110 consistent symbols with zero conflicts. The official targeted replay reports 26,107/26,107 bytes matched, difference_count = 0, and 265 accepted relocations. A register-independent diagnostic also reports 100% mean and median instruction-signature similarity across all 55 intervals. Per-case boundaries, source/object hashes, and the accepted replay state are recorded in progress.json. No ASM, padding, or byte patching is used.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
