# Ayu original command recognizer — reconstruction source lineage

The exploratory full-TU source `Character01Commands-natural.cpp` was used to
recover Ayu's original `Character01::Slot02` ordered 14-scan input recognizer.
Its original template scans came from reviewed sibling command recognizers,
with Ayu's unique `0x5D` high-priority charge gate restored from the
`0x006EAFD0` original function. The independent selected pinned VC7.1 compile
proved **4,482/4,482 byte-for-byte Exact, zero relocations**.

The **authoritative accepted implementation** is now
`src/Character01Commands.cpp`; its selected formal certificate is
`docs/evidence/character-01-slot02-exact.json`. This historical workbench file
is retained to record how the original scan order and source blocks were
reconstructed. It is not an additional tracked owner and must not be
registered twice in `implemented.csv` or `matches.csv`.

No ASM, emitted opcodes, padding or full cold replay were used.
