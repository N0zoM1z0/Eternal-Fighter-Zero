# Nagamori `Character06::Slot02` — tracked input command source

**Only a partial natural C++ implementation; not full-function Exact.**
Original Nagamori vtable slot 2 at `0x00788404` points to
`[0x004B1780,0x004B2AB5)` (**4,917 bytes**) followed by 11
alignment `CC` bytes. Verified complete target SHA and per-scan hashes:
`docs/evidence/nagamori-slot02-first-scan-boundary.json`.

The current `Character06Command.cpp` reconstructs the first **three**
ordered scans, original **1,377 bytes / 410 instructions**:

| Scan | Original range | Bytes | Instructions | Result |
| --- | --- | ---: | ---: | --- |
| 1 | `0x004B1780..0x004B191C` | 412 | 120 | Original meter==3000 and ground gate, command 0x5B |
| 2 | `0x004B191C..0x004B1AD7` | 443 | 133 | 100–179 history ticks, two early 0x78-series finish paths |
| 3 | `0x004B1AD7..0x004B1CE1` | 522 | 157 | 90–179 history ticks, meter>=1000, two 0x6E-series finishes |

Each sequence preserves the original signed-facing computation,
input-history wrap and priority. The third scan was verified against
the *Nagamori original*, even though its natural C++ form resembles
Ikumi's independently exact scanner. One accidentally duplicated
third scan was removed after native comparison showed an extra
522-byte block; the correct source matches exactly one original scan.

Focused verification compiles only this source under pinned VC7.1:

```bash
scripts/repo-python workbench/nagamori-command/check_first_scan.py
```

The original first **410/410 instruction forms and operands** match
after normalizing only numeric forward-jump destinations and the
canonical x87 0.0 double address. The compiler emits **1,381 bytes**:
1,377 original-prefix bytes plus an artificial local 3-instruction
return. No whole-owner match/relocation acceptance exists yet.
The **next scan begins at `0x004B1CE1`**; 12 lower-priority scans
remain, and this partial source must stay outside production `src/`.
