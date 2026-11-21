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
- Restored the native x87 unordered-comparison behavior in cases 0x19b-0x19e. The source now expresses the native negated comparisons for y and vy, and reverses the lower-bound y comparison to match the original x87 status-word tests.
- Reordered three 680-unit x bounds, the case-0x1ae opponent-height comparison, and the 900-unit x bound to reproduce the native x87 evaluation order. This also aligns every code relocation operand to the same byte offset as its native counterpart.
- Corrected the spawn payloads in cases 0x190-0x192 to use group = 0 and field0028 = 1 in native store order, rather than group = 1 and field0030 = 0. All three case instruction signatures now match 100%.

The current code prefix is 25,787/25,787 bytes. All 55 switch intervals and all 55 jump-table destinations match the native case boundaries; the selector table is 100/100 exact. All 210 code relocation field offsets now match the original instructions exactly. A reconstruction pass resolves all 265 relocation destinations to 110 consistent symbols with zero conflicts. A register-independent instruction-signature diagnostic reports 99.65% mean similarity and 100% median similarity, with 53 intervals at 100% signature similarity; only case 0x1f0 and the default arm remain structurally divergent. This diagnostic is not an acceptance metric. Per-case boundaries, source/object hashes and the current state are recorded in progress.json. The next gate is adding the 265 explicit relocation bindings to the match-unit manifest and passing the selected exact replay. No ASM, padding, or byte patching is used.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
