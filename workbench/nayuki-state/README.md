# Nayuki Character10::Slot06 — partial native state-machine reconstruction

**Status: PARTIAL, NOT full Exact.** Work in
`workbench/nayuki-state/Character10State.cpp` and preserve every local
change. The accepted `src/` tree remains separate, and unrecovered
sibling-derived states must never be counted as original source.

## Original owner

Character10 Slot06 vtable entry at 0x00788288 targets code
[0x00451850,0x00460D35), **62,693 bytes**, SHA-256:
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Adjacent separately owned switch DATA: 138 four-byte destinations at
0x00460D35, then 306 selector bytes at 0x00460F5D.
The switch maps 137 live animation IDs and 169 default IDs.

## Selected original-bound native checkpoint

Reviewed code [0x00451850,0x0045B3DD): **39,821 / 62,693 original code
bytes** and **10,933 original x86 instructions**, SHA-256:
b0af53155881577a75fe5c7f8b1348467b19431b610c98bfc38ba298c33d774a.

The reviewed default and **98 live states** are 1–9, 13–16, 47,
50–77, 81–87, 96–99, 123, 150–158, 161–171, 178–180,
200–214, 220–221, 230–232 and 248. State248 replaces an inherited
Makoto throw with Nayuki's original 498-byte aerial grab. It orders
opponent ResetFrame/ResetPose before own ResetPose/ResetFrame,
sets opponent state 100 and own state 249, emits an impact at own
X + facing*33 and own Y - 51, places opponent at own X + facing*33
and own Y - 61, then continues the standard frame timer rather than
returning prematurely. On timeout it selects state209 at frame2.

Reproduce **focused** selected native comparison only:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` reproduces all **10,933 native
instruction offsets, widths and normalized opcode forms** except for
the temporary frame allocation (candidate 0x2A4 vs original 0x2B4).
Original-bound checks verify **1,011 internal branches**, **144
outbound destinations**, **872 nonlocal COFF call/IEEE-754 references**,
2 local switch-table operands and **98 original case destinations**.
This is selected-prefix proof, NOT full-function Exact.

## Next code target and open scope

Original state249 begins at **0x0045B3DD**. The current candidate is
unverified and diverges at **0x0045B3E0** (owner offset 0x9B90):
original checks frame index against 7, whereas the inherited template
immediately writes hit invulnerability. Source remains in the workbench.

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 249 --context 12

**22,872 original code bytes** are open, plus original 0x2B4 full
stack frame, switch DATA, remaining relocations and shared return.
The source holds 118 of 137 live IDs: **98 reviewed**, **20 unreviewed**
and **19 missing 263–281**. The selective probe uses deliberately
UNACCEPTED neutral markers for other original case IDs and late
300–306 bodies to retain the VC7.1 prologue. Never claim those
markers are authentic code. No all-unit cold replay or runtime claim.
