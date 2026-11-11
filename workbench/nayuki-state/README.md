# Nayuki Character10::Slot06 — partial native state-machine reconstruction

**Status: COMPLETE native codegen Exact in accepted `src/Character10State.cpp`.**
This workbench retains the historical iterative source; its 61,242-byte
prefix checker is superseded by the complete strict selected oracle.

## Original owner

Character10 Slot06 vtable entry at 0x00788288 targets code
[0x00451850,0x00460D35), **62,693 bytes**, SHA-256:
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Adjacent separately owned switch DATA: 138 four-byte destinations at
0x00460D35, then 306 selector bytes at 0x00460F5D.
The switch maps 137 live animation IDs and 169 default IDs.

## Completed native reconstruction — accepted source

This historical workbench was the scratch source for the large Nayuki
state boss. Its complete edited body, including all 137 original live
case IDs, was promoted to the accepted
`src/Character10State.cpp` as **complete selected-original-bound Exact**.
The original function code `[0x00451850,0x00460D35)` is 62,693 bytes;
its 552-byte destination table and 306-byte selector table extend the
owned contribution to `[0x00451850,0x0046108F)` = **63,551 bytes**.

The pinned VC7.1 `/Od /G6 /MT /Gy /W3` single-unit exact oracle
compared **63,551 / 63,551 native bytes, zero differences**, after
binding 1,433 independent original relocation fields: 951 literal
IEEE-754, 342 external calls, 140 switch-local pointers. The real
0x2B4 frame, original physical case order (state300 before279),
complete 138-entry destination and 306-byte selector tables, all
137 live IDs, default and shared return now match EFZ.exe.

Proof: `docs/evidence/character-10-state-slot06-exact.json`.
The former `check_prefix.py` is a historical 61,242-byte *partial*
audit, not the complete accepted owner. For current checks use:

    scripts/repo-python scripts/replay-exact-units.py --unit character-10-state-slot06
    scripts/repo-python scripts/validate-tracking.py --check-proofs --unit character-10-state-slot06

The workbench retains its historical original-bound incremental C++
for comparison and research. Edit accepted `src/Character10State.cpp`
for future intentional corrections. **Full game linkage, runtime
parity and portability are separate open goals.** No all-unit cold
replay is required for this complete unit.
