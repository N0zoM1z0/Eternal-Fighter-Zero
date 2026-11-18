# Character19::Slot07 workbench

Target: 0x0067CF50, reviewed native extent [0x0067CF50, 0x0068340B) (25,787 bytes). The vtable at 0x00788CE0 + 0x1c selects this owner.

The production source now contains a complete natural-C++ port of the 54-case local-effect update/lifetime dispatcher. The port preserves the native 64-entry effect ring, per-type frame progression, local effect emission, removal, Kanna-specific random motion, and state-sensitive sound/effect paths. It compiles through the selected VC7.1 /Od /G6 /MT /Gy /W3 match-unit profile.

Current selected build is 26,421 bytes versus the 25,787-byte native owner. The remaining 634-byte size gap is a code-generation/control-flow problem, not an ASM/padding workaround. Continue with native x87-to-integer temporary lifetime, local-variable layout, branch shape, and native helper-call matching; do not promote the source as Exact until the selected replay reaches zero differences.

Character15::Slot07 and Character23::Slot07 are structural references only; their case behavior is not copied as Kanna behavior.
