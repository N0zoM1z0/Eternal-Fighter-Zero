# Nayuki Character10::Slot06 — focused native reconstruction

**Status: PARTIAL, NOT complete Exact.** The natural C++ workbench is
workbench/nayuki-state/Character10State.cpp. The accepted src/ tree is separate.
Retain and reconcile dirty edits; inherited later Makoto-state hypotheses are
not original Nayuki evidence.

## Original owner

Character10 vtable Slot06 at 0x00788288 selects original code
[0x00451850,0x00460D35): **62,693 bytes**, SHA-256
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Separate immediately adjacent tables: 138 four-byte destinations at
0x00460D35 and 306 selector bytes at 0x00460F5D.
Of 306 animation IDs, 137 are live, 169 map to default.
The workbench has 118 of 137 case labels; 19 absent IDs 263–281.
Of its present labels, 83 are prefix-reviewed and 35 later remain unverified.

## Selected native checkpoint

Original [0x00451850,0x00459901): **32,945 bytes / 9,056 original x86
instructions**, prefix SHA-256
ca349ed1b20142e0620a2c6ae706a85f610201b12931c2460a5a2ff03f3c9096.

Reviewed original default plus 83 live cases: 1–9, 13–16, 47, 50–77,
81–87, 96–99, 123, 150–158, 161–171, 178–180, 200–205.
The most recent states 204/205 restore original dash damping, grounded
input cancel, meter/timer, and Nayuki's special tiered 3-tick frame advance.
State205 moves the fighter 15 pixels at frames 1 and 2 and recovers to
state 3. These are native branch and instruction comparisons, not guesses
borrowed from the sibling character.

Run focused validation only:

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces all 9,056 original
instruction offsets and widths and 9,055 normalized matching forms.
The only unmatched form is the temporary partial stack allocation
(candidate 0x278 vs complete original 0x2B4). Checker verifies
**842 original internal branches**, **109 canonical outbound targets**,
**793 independently bound original nonlocal COFF call/float references**,
two separately verified original local switch fields, and the first
**83 original selector case destinations**.

probe_prefix.py creates authentic reviewed early bodies alongside
deliberately UNACCEPTED neutral marker branches for later live states.
Original later 300–306 bodies are retained in this test solely to preserve
VC7.1 ESI/prologue compiler behavior. Test-only markers are never
accepted reconstruction.

## Next code target

Next original state206 starts **0x00459901** (offset 0x80B1).
First mismatch after the selected prefix is **0x00459904** (0x80B4):
target reads byte [eax+0x158], while the unreviewed local probe
uses a marker branch for state206.

    scripts/repo-python workbench/nayuki-state/probe_prefix.py --through 206 --context 8

**Not whole-function Exact:** 29,748 original code bytes, 19 missing live
case bodies (IDs 263–281), 35 existing unreviewed later cases, full native
0x2B4 stack, local jump tables, remaining relocations and return are OPEN.
No all-unit cold replay or whole-game runtime claim.
