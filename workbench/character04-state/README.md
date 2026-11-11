# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Real source covers the original
default plus **64 live cases**: 1–9,13–16,47,50–77,81–87,96–99,
150–158,161–162. Other 74 live cases remain unimplemented.
Temporary compilation markers are never accepted original source.

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

`[0x00607930,0x0060D84A)` is now **24,346 original code bytes**,
SHA-256 `d58598e3bde5a195d3bf366353d67e9495697664ad5788dcee6d2f32c0800206`.
The newest true C++ case161 emits original aerial effect9 at Y−70,
sets hit count and sound, and resets into state9; case162 performs
a separate frame2 launch, emits the same effect on frame7,
spends meter1000, restores gravity on **frame12** and uses native
pose-loop and landing return behavior. These points differ from
the related character's 60-offset/frame3/frame18 source and were
independently corrected from original machine code.

Run only the one-Boss selected audit:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

The checker binds **6,719 original x86 instruction widths/offsets
and register-abstracted forms**, **612 original internal plus
75 native shared-return branches**, **617 original-bound COFF call/
IEEE-754 references** and 2 native local dispatch pointers.
All other source-scoped opcode bytes agree. Its only allowed
exceptions are the original-width provisional stack allocation
(`sub esp,0xF4` versus native `0x2E8`), the unresolved final return
JMP displacement and independently bound COFF operand fields.

**Next live original case163 at `0x0060D84A`**; 74 live cases,
full stack/139-DWORD switch/325 selector arrays and final
shared return still open. This is **NOT whole-function Exact**.
Never run cold all-unit replay or count synthetic marker cases.
