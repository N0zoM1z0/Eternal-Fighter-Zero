# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Natural C++ now reconstructs
native default plus **91 real live IDs**: 1–9,13–16,47,50–77,
81–87,96–99,150–158,161–171,180,200–216. The other **47**
authentic original live cases remain OPEN. Transient probe marker
cases are never accepted or counted as real source.

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

Original `[0x00607930,0x006105D8)` covers **36,008 native
executable bytes**, SHA-256
`0f299ef0aa39afaea2360524d27e29fb0db10e4bef6578e270150d57de7f23a6`.
This selected code comprises original default plus 91 real cases.
Newest 213–215 implement three original resource-cost specials:
frame0 zeros horizontal/vertical speed, primes a hit and subtracts
**1000 from the child-specific resource field at `0x3148`**; frame2
adds native meter25 and emits local effect0x19F/0x1A0/0x1A1 at
facing-dependent offsets **28/21/5** and Y **−44/−63/−61**;
frame6 requests sound2; their original animation advancement
always resets attack collision. They share a real down-input
cancel gate allowing `attackCollisionResult >= 2`.
Case216 independently implements `ResetFrame`, initial hit count1,
strict **`velocityX > 0.0`** deceleration by 0.08 (not `>=`, which
changes original x87 condition bits), floor clamp at zero, and a
frame3 velocity3.0/meter25/sound21 transition with state0
`FaceOpponent()`/`ResetPose()` completion.

Fast original-bound selected check:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

The scope passes **9,866 original x86 offsets/widths and
register-abstracted opcode forms**, **911 native internal and 119
original shared-return branch targets**, **803 independently original-
bound COFF direct-call/IEEE-754 references** and two native local
selector/table addresses. Other selected machine code bytes match.
Allowed exceptions are strictly original-width six-byte provisional
stack allocation (`0x158` versus original `0x2E8`), outbound native
shared-return JMP displacements and already original-bound COFF
operand locations, not arbitrary padding.

**Next real native case220 begins `0x006105D8`**. Remaining 47 live
cases, full stack, 139-entry switch/325 selector data and original
shared return remain open. This is a strict selected **prefix,
NOT whole-function Exact**. No all-unit cold replay, no probe-credit.
