# Nagamori Slot05 CPU boss — partial natural C++

The original virtual slot 5 at `0x00788410` points to
`Character06::Slot05` at `[0x004B2AC0,0x004B667C)`, **15,292 bytes**.
Four `CC` bytes follow the original return. The complete original
SHA-256 is `14a83398918558355cd4ae747fa313b60f62771f1758ba870a593d29f596bfb9`.

`Character06Cpu.cpp` reconstructs the original opening AI decisions,
including CPU movement counters, input clearing, random guard choices,
opponent-distance calculation, short-range reactions and meter attacks.
It was initially shaped using another exact character's CPU source,
but Nagamori's own target disassembly forced the corrections below.

The canonical original prefix `[0x004B2AC0,0x004B3495)` is
**2,517 bytes / 689 instructions**. A focused pinned VC7.1 build
reproduces **688 of 689 original instruction forms and operands**
after normalizing numeric jump/call targets and external constants.
Only the prologue allocation differs (`sub esp,0xE8` original versus
`sub esp,0x88` partial), because later local variables are missing.
The partial object is **2,514 bytes** and ends in a temporary return.
It is NOT a full-function Exact owner.

Target-derived differences include a 3.0f rather than 2.0f CPU
aggression multiplier, the original `buttonPulse[0] = 3` for forward
range 60–120, an `0x0C` branch, an `0x48` branch with a two-point
bonus when `field0118 > 500.0`, a randomized `0x14/0x16` action, and
`0x65`/`0x66` commands gated by 2000/3000 meter and distance ceilings
60/150. The 150.0 double is verified at original `0x00787EF0`.

Run only this affected translation unit:

```bash
scripts/repo-python workbench/nagamori-cpu/check_prefix.py
```

The next original decision begins at `0x004B349A`. The separately
rejected sibling-derived full-function hypothesis remains in private
`.analysis/probes/nagamori-slot05-sibling-candidate.cpp`. Continue
checking Nagamori against its own disassembly; no full cold replay.
