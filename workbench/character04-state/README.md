# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** The workbench now has
native default and **68 real live cases**: 1–9,13–16,47,50–77,
81–87,96–99,150–158,161–166. Seventy other real states remain
unimplemented. Synthetic probe markers remain unaccepted.

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

`[0x00607930,0x0060DEBA)` = **25,994 original code bytes**,
SHA-256 `84cf429086883cc7f0185da7ff69ad6acf1db31ee3bceb61af8cb931395ba519`.
Natural C++ cases163–166 now reproduce distinct original actions:
163 uses two native flight speeds selected by character field3144
(2.5/-0.3/0.02 or 3.2/-0.25/0.025), a frame5->3 loop and landing
ResetFrame; 164 starts `StartTrail(2)`, then an aerial transition
with -2/-1 velocity, +0.04 vertical acceleration and frame7 landing;
165 and166 implement different forward/backward impulse 1.3/-1.3
and frame clocks with 120/48-frame facing/acceleration transitions.
The original compiler emits real per-state control-flow instructions,
not markers.

Run only the selected one-Boss original-bound checker:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` codegen matches **7,191 native
x86 instruction offsets/widths/register-abstracted forms**,
**655 original internal and 79 shared-return branches**, **662
original-bound direct-call/IEEE-754 references** and 2 native
switch/selector pointers. Every remaining original byte in the
selected scope matches except the original-width provisional stack
size immediate (`0xF8` vs full native `0x2E8`), unclosed shared-return
JMP displacement and independently native-bound COFF fields.
`StartTrail` uses the original byte argument ABI symbol
`?StartTrail@Secondary@@QAEXE@Z` at 0x004109D0.

**Next original case167 starts at `0x0060DEBA`**; 70 real live
cases, full native stack and local dispatch data/return are still
OPEN. This is **selected-prefix proof, NOT whole-function Exact**.
No cold all-unit replay and no probe-marker acceptance.
