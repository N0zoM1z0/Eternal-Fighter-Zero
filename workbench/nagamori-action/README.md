# Nagamori `Character06::Slot04` — 12,277-byte action-priority boss

**Work in progress, NOT full-function Exact.** The reviewed original
Nagamori vtable slot 4 at `0x0078840C` points to `0x004AE2E0`.
The code body owns `[0x004AE2E0,0x004B12D5)`, **12,277 bytes**;
11 `CC` padding bytes align the next Slot01 at `0x004B12E0`.
The full target SHA-256 and the reviewed first-action prefix are in
`docs/evidence/nagamori-slot04-first-actions-boundary.json`.

## Implemented source

`Character06Input.cpp` is natural C++, deliberately isolated from
accepted production `src/`. Its first **eleven priority-ordered action
guards** recover the original buffering rules, command checks,
current animation/frame cancel flags, meter thresholds, attack-state
restrictions, action group semantics, and result animations.
Specifically it reconstructs the commands 0x34, 0x5B, 0x7A,
0x79/0x7A, 0x78/0x79/0x7A, 0x70, 0x6F, 0x6E, 0x66,
0x65/0x66, and 0x64/0x65/0x66, including original
per-action level caps at `sequences[167]` and `sequences[312..315]`
plus separate 306/307/308 caps. It also preserves the unusual
conditional airborne follow-on actions after 0x34/0x70/0x6F/0x6E.
These tests were derived from canonical EFZ.exe instruction order;
related-character code served only as an initial source-shape reference.

A focused VC7.1 compile of these first actions emits **2,976 bytes**
including a temporary standalone epilogue; the exact canonical
first-eight-action prefix is **2,974 bytes / 731 instructions** ending
just before the original `jmp` to the final shared epilogue at
`0x004AEE7E`. A reproducible check compares 730 original
instructions/operands (everything through the last action state
assignment) and finds **730/730 matching normalized instruction forms**
with the single incomplete stack-frame prologue instruction excluded. Only numeric branch/call
targets and original x87 constant destination addresses are normalized.
The original large function allocates a 20-byte frame with additional
locals used in the yet-unimplemented action branches; the partial
source currently allocates 4 bytes. That discrepancy is intentional,
**not** a license to add inert locals or pad machine-code bytes.

## Run the focused native source check

```bash
scripts/repo-python workbench/nagamori-action/check_prefix.py
```

The checker compiles this one TU using the repository's pinned VC7.1,
attests the original 2,974-byte prefix and asserts 730/730
opcodes/operands after the documented **one frame instruction** is
excluded. It does not assert whole-function 12,277-byte Exact, and
no source/match ledger acceptance or broad cold replay is implied.

Next: implement the priority action branch beginning at `0x004AEE83`
(command 0x2A), then continue the original guard order
until the common epilogue at `0x004B12D1`. Keep explicit numeric
sequence-array index and action-ID original checks; avoid templating
away source-level order because VC7.1 codegen depends on it.

The last three implemented guards were intentionally reordered to check
`sequences[..].field0002` against original per-level 302/301/300 caps
**before** the final hit-state guard. The first natural C++ draft
reversed this order, causing three groups of ten displaced x86
instructions despite equivalent Boolean outcomes. The revised source
now matches the original instruction sequence.
