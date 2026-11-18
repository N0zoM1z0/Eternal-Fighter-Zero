# Character19 lifecycle leafs

These six small Kanna lifecycle owners were rebuilt with the pinned VC7.1 profile using the targeted scripts/replay-exact-units.py path. All six returned result: exact, difference_count: 0, and matched their complete native extents.

| Unit | Native owner | Bytes | Relocations |
|---|---:|---:|---:|
| InitializeState | 0x00675E20 | 283 | 1 REL32 |
| ResetPose | 0x00675F40 | 58 | 1 REL32 |
| RemoveLocalEffect | 0x00675F80 | 80 | 1 REL32 |
| Slot01 | 0x00677E10 | 11 | 0 |
| Slot08 | 0x00677E20 | 11 | 0 |
| EmitLocalEffect | 0x00677E30 | 47 | 1 REL32 |

The three external calls resolve to the reviewed Secondary implementations at 0x0040EDF0, 0x0040F110, 0x00412E60, and 0x00412B10 respectively. The two empty virtual slots match their 11-byte native bodies exactly.

This was a six-unit targeted replay, not a full repository cold replay. The results are local code-generation evidence; canonical Factory acceptance remains a separate step.
