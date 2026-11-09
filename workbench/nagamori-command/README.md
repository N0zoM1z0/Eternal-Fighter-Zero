# Nagamori `Character06::Slot02` — command-history recognizer

**Partial natural C++ workbench only; NOT an accepted full-function Exact source.**
Original Nagamori vtable slot 2 at `0x00788404` points to
`[0x004B1780,0x004B2AB5)` (**4,917 bytes**), followed by 11 `CC`
alignment bytes. Original target SHA and reviewed boundaries are in
`docs/evidence/nagamori-slot02-first-scan-boundary.json`.

The first **two priority-ordered scans** have now been reconstructed
in `Character06Command.cpp`. The original first scan owns
`[0x004B1780,0x004B191C)` (**412 bytes / 120 instructions**) and
requires both **3000 meter and exact ground contact** before a five-
stage motion can issue command `0x5B`. Certain buttons abort the scan
without a result, passing control to lower-priority scans.

The original second scan owns `[0x004B191C,0x004B1AD7)` (**443
bytes / 133 instructions**), scans input-history ticks 100–179 and
recognizes command base `0x78` with input button flags. It preserves
both the high-priority completed-motion finish and the same-frame
stage-three finish; its facing arithmetic was reconstructed from
original `neg/sbb/add` and `sub` instructions, not copied blindly.

Together **855 original bytes / 253 instructions** match natural VC7.1
C++ after normalizing only numeric branch destinations and the 0.0
constant's original PE location. The local TU emits **859 bytes**
including a temporary three-instruction return. The remaining
priority scans are open and this is **not a complete Exact owner**.

Reproduce with *only* the named C++ source and canonical executable:

```bash
scripts/repo-python workbench/nagamori-command/check_first_scan.py
```

Next original scan begins at `0x004B1AD7`. The rest of the function
remains in workbench until complete strict whole-owner matching.
