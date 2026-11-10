# Nagamori `Character06::Slot02` — tracked input command source

**Only a partial natural C++ implementation; not full-function Exact.**
Original Nagamori vtable slot 2 at `0x00788404` points to
`[0x004B1780,0x004B2AB5)` (**4,917 bytes**) followed by 11
alignment `CC` bytes. Verified complete target SHA and per-scan hashes:
`docs/evidence/nagamori-slot02-first-scan-boundary.json`.

The current `Character06Command.cpp` reconstructs the first **eight**
ordered scans, original **3,437 bytes / 1,010 instructions**:

| Scan | Original range | Bytes | Instructions | Result |
| --- | --- | ---: | ---: | --- |
| 1 | `0x004B1780..0x004B191C` | 412 | 120 | Original meter==3000 and ground gate, command 0x5B |
| 2 | `0x004B191C..0x004B1AD7` | 443 | 133 | 100–179 history ticks, two early 0x78-series finish paths |
| 3 | `0x004B1AD7..0x004B1CE1` | 522 | 157 | 90–179 history ticks, meter>=1000, two 0x6E-series finishes |
| 4 | `0x004B1CE1..0x004B1EEB` | 522 | 156 | Base 0x64, meter>=1000 **and** grounded, two alternate finish paths |
| 5 | `0x004B1EEB..0x004B2072` | 391 | 113 | 45-frame 2/6/4 pattern, base command 0x28 |
| 6 | `0x004B2072..0x004B21EA` | 376 | 109 | 60-frame 2/4/6 pattern, base command 0x14 |
| 7 | `0x004B21EA..0x004B2368` | 382 | 109 | 45-frame 4/6/2 pattern, base command 0x0A |
| 8 | `0x004B2368..0x004B24ED` | 389 | 113 | 45-frame mirrored 4/6/2 pattern, base command 0x1E |

Each sequence preserves the original signed-facing computation,
input-history wrap and priority. The third and fourth scans were verified against
the *Nagamori original*, even though its natural C++ form resembles
Ikumi's independently exact scanner. Duplicate fifth and sixth scan drafts were independently compiled
and reconciled against Nagamori target x86; each is retained once.
The compiler now matches eight full ordered scan bodies.

Focused verification compiles only this source under pinned VC7.1:

```bash
scripts/repo-python workbench/nagamori-command/check_first_scan.py
```

The original first **1,010/1,010 instruction forms and operands** match
after normalizing only numeric forward-jump destinations and the
canonical x87 0.0 double address. The compiler emits **3,438 bytes**:
3,437 original-prefix bytes plus an artificial local 3-instruction
return. No whole-owner match/relocation acceptance exists yet.
The **next scan begins at `0x004B24ED`**; 7 lower-priority scans
remain, and this partial source must stay outside production `src/`.
