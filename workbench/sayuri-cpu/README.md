# Sayuri Character09::Slot05 CPU boss — partial C++ reconstruction

The original Character09 vtable slot 5 (0x0078814C) points to
0x0044AB30. Its complete code range [0x0044AB30,0x0044DB5A)
is **12,330 original instruction bytes**, followed by six CC
padding bytes. Full-target SHA-256:
359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5.

The natural C++ workbench covers [0x0044AB30,0x0044CC86),
**8,534 original bytes / 2,157 instructions**, prefix SHA-256:
51d0973f6f6c87a843d5f7fa4ae686c377b2a7c69f6b576124f03e580fa90847.

Recovered CPU policy includes opening defensive checks,
Sayuri-specific 140-distance special, A8/A9 graded moves,
AA aerial attacks, state 0..7 recovery and complete
C8/C9/CA/CB/CC/CD/CE collision-followup trees.
All unusual distance and meter gates, counter ranges,
button assignments and RandomRange argument/order are
preserved. The CE action adds a 750..800 randomized
meter attack and a collision-dependent upper timer bound.

Reproduce only this selected native diagnostic:

    scripts/repo-python workbench/sayuri-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits **8,527 bytes /
2,159 instructions** including a temporary epilogue
and **146 original-bound COFF relocations**. Of
2,156 comparable original body instructions,
2,155 match after normalizing calls, jumps and
literal addresses. Only the incomplete stack frame
differs (0xC4 instead of original 0xD8). Two original
near JMPs shorten due to the missing shared return.
**276 internal jump destinations, 91 original
outbound jump targets and all 146 original-bound
relocations agree**, with 29 unique symbols and
canonical IEEE-754 payloads.

Continue at 0x0044CC86 (CF/D0). **Not full Exact**:
3,796 target code bytes, the final frame, return
and remaining relocations are open. No full replay.
