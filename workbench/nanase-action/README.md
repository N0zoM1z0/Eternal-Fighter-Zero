# Nanase Character00::Slot04 — natural C++ action selection (open boss)

Native complete owner: `0x0048ACA0`, 11,424 bytes, vtable slot4 at
`0x00788344`. Candidate: `Character00Action-natural.cpp`, a genuine C++
translation unit that remains outside the exact tracking ledgers.

The candidate is adapted from the already reconstructed Makoto action selector,
then corrected against Nanase's original executable for the 22 priority
special-action transitions and the final button/air transition groups. Its
normal VC7.1 `/Od /G6 /MT /Gy /W3` build has **11,424 code bytes** (native
11,424) and 2,873 decoded instructions (native 2,873). All **39 native ClearBufferedButtons call sites now align at identical
offsets**, thanks to restoring the original evaluation order of the ten
high-priority C++ conditions and the three final command guards (`0xC/0xB/0xA`). All **39 native
first-after-ClearBufferedButtons action state IDs**, including 0x133/0x136,
the 0x66 and 0x70 multi-command banks, 0x102/0x101/0x100, the 0xfa group,
and the ordinary button/air states, are represented **in matching native order**.

Not Exact! The count and state-ID alignment does not establish every input
guard, fallthrough, side effect, branch target or relocation binding. The natural candidate now matches the **whole-owner extent and instruction
count**, but not yet the machine code. Instructions, registers, branch
destinations and COFF relocations still require full byte-level validation; native-specific fallthroughs remain unverified in the final
button/air paths. Do not promote this
source to `src/`, `implemented.csv` or `matches.csv` until independently
reviewed full-function native matching; never use ASM or artificial padding.

Rebuild/audit only the touched TU:

```bash
scripts/repo-python workbench/nanase-action/verify_action_progress.py --rebuild
```

Progress proof:
`docs/evidence/nanase-slot04-natural-progress.json`. The verifier checks the
canonical original SHA, vtable slot, pinned object receipt, full instruction
counts and all 39 original first action state transitions, without performing a
cold all-unit replay. The temporary probe sources remain under `.analysis/`.
