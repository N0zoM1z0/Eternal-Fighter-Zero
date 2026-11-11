# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Natural C++ now reconstructs
original default plus **87 real live IDs**: 1–9,13–16,47,50–77,
81–87,96–99,150–158,161–171,180,200–212. The other **51**
authentic live IDs remain OPEN. Diagnostic marker cases are never
accepted as source or credited toward byte matching.

## Original PE ownership and dispatch

- Original vtable pointer `0x00788B94` selects `0x00607930`
- Native owner `[0x00607930,0x00616037)` **59,143 code bytes**, SHA-256
  `200261f2d50fa04663e62d285dd09cd0eeaf601fdee46e08b2798e8cf95b02a1`
- Native pointer table `[0x00616037,0x00616263)`: **139 DWORD
  destinations**, one for each of 138 live states plus default
- Original selectors `[0x00616263,0x006163A8)`: **325 bytes**,
  138 live IDs, 187 default IDs
- Original full stack allocation is `sub esp,0x2E8`; the native
  shared epilogue at `0x00616033` is `mov esp,ebp; pop ebp; ret`

## Current audited continuous prefix

Original `[0x00607930,0x0060FE22)` covers **34,034 native
executable bytes**, SHA-256
`b92ebcb066f6deb3f64259a26deb6dbda11b673085d39d065028e7121bcf3ac3`.
Source contains native default plus 87 real live case branches.
Newest 210–212 are three distinct local hit levels with original
state-specific animation and effect timing. State210 has the
original ground dash cancel gate, pose0 speed reset, pose2
0x19F effect at X−facing×28/Y−44 and sound1; 211/212 have no
dash cancel and emit 0x1A0 at X−facing×21/Y−63 or 0x1A1 at
X−facing×5/Y−61. Case212 clears early collision only for
new pose<2, unlike the other two (<3). Their pose6 sound2,
true effect emission/remaining hits and state0 reset are native.

Focused original-bound check:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

Verifies **9,339 original x86 instruction offsets, widths and
register-abstracted forms**, **861 exact internal and 112 original
shared-return branch destinations**, **781 original COFF direct-call
/ IEEE-754 references** and two original local selector/table
pointers. Other original opcode bytes match exactly. Only the
original-width provisional stack allocation (`0x140` vs native
full `0x2E8`), still-outbound shared-return jump displacement and
the independently native-bound COFF operands are exempt.

**Next original live case213 begins at `0x0060FE22`**. The
remaining 51 original live states, full original stack, 139-DWORD
native switch table, 325 selector bytes and shared return remain
OPEN. This is selected-prefix, **NOT full native Exact**. Never
run cold all-unit replay or count probe marker code.
