# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Authored natural C++ now
covers original default and **96 genuine live cases**: 1–9,13–16,
47,50–77,81–87,96–99,150–158,161–171,180,200–216,220–221,
230–232. The other **42** native live case IDs remain OPEN.
Throwaway compilation markers never earn original source credit.

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

The original code `[0x00607930,0x00610DDA)` now has **38,058
original executable bytes**, canonical SHA-256
`27ab84c93456fccd601d7ff0f64f56f8d0edc08d334fbd2234e6b7dcdbb4c0e3`.
New real C++ cases220–221 reconstruct an actual two-character
grab and four-stage throw. Case220 zeroes both speeds, transitions
own pose221 and opponent pose108, triggers original effect0 at
X+facing×49/Y−43, and immediately returns from successful grab.
At frame advance it clears `remainingHitCount` whenever not on
pose1 or the opponent is airborne; this condition was independently
caught by native branch-target validation, not inferred from length.
Case221 shakes screen `(50,3)`, clamps owner X, positions the
opponent in successive native states103/117/97 at original
Y−150/−100/−81/0, sets the opponent's facing, applies native
`ApplyDamage(1200,750.0)` and calls opponent ResetPose/ResetFrame.
New airborne cases230–232 use original gravity0.03 and velocityX0.5,
grants meter5/10/10 at poses1/2/1, requests sound21/21/20, and
returns to state13 upon landing or state9 at animation completion.

Focused canonical selected-prefix check:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It verifies **10,439 original x86 instruction widths/positions and
register-abstracted forms**, **950 original internal +128 native
shared-return branch targets**, **840 independently original-bound
COFF call/IEEE-754 references**, and two original local dispatch
addresses. All other reviewed opcode bytes match exactly. Allowed
exceptions are only the original-width provisional six-byte stack
immediate (`0x170` vs native `0x2E8`), incomplete final shared-return
jump distance and original-bound COFF fields. No arbitrary branch
target differences or source padding are accepted.

**Next live native state240 starts `0x00610DDA`**. The remaining
42 original live case bodies, full stack, 139-entry jump table,
325 selector bytes and shared return remain OPEN. This certificate
is **selected-prefix only, NOT whole Exact**; no all-unit cold replay.
