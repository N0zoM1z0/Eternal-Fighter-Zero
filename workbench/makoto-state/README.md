# Makoto Slot06 — natural C++ reconstruction in progress

The original Character03::Slot06 is an authored 58,482-byte function at
0x005E85F0, followed by a 500-byte 125-entry jump table and 310-byte
animation selector table. The full owned extent is
[0x005E85F0, 0x005F6D8C), 59,292 bytes. It is still open.

Character03State.cpp is a **partial, isolated source draft**. It is **not**
linked into src/, does not implement all mapped states, and is not an exact
candidate. In particular, its default return is only a marker for unfinished
work, not the original behavior for valid unimplemented animations.

## Recovered natural C++ paths

- Entry: return on nonzero self hitstop or opponent hitstun.
- Initialize EffectSpawn, read PatternFrame::duration and
  PatternSequence::count, call ResetLocalEffectSpawn.
- Animation ID 1: clear dashMomentumFlag, set velocity (0.7, 0.0).
- Animation ID 2: clear dashMomentumFlag, set velocity (-0.7, 0.0).
- Animation ID 3: set velocity (0.0, 0.0), clear dashMomentumFlag,
  and invoke FaceOpponent.
- Animation ID 5 (block 0x005E89F4): repeat the first-tick face/zero
  behavior, then on pose 3's first tick set gravity=0.042, vertical speed=-2.9,
  horizontal speed=0.7, with dashMomentumFlag==1 upgrading horizontal speed
  to 1.1 and clearing that flag. Gravity accumulates past pose 2. On frame
  exhaustion, subtract 2 from the advanced frame index rather than switching
  animations. Landing after pose 3 requests context sound 9 and selects
  animation 13.
- Animation ID 4 (block 0x005E8891): on the first tick, face the opponent
  when not carrying dash momentum and clear horizontal speed. On pose 3's
  first tick set gravity=0.042 and vertical speed=-2.9. If dash momentum
  equals 1, replace horizontal speed with 0.4 and clear the flag. Gravity
  accumulates after pose 2. The frame counter advances using the captured
  duration; on animation exhaustion, select animation 9 and ResetPose.
  Landing at pose >3 with positionY+velocityY >=0 requests context sound 9,
  faces the opponent, selects animation 13, and ResetPose.
- For these cases, increment field000c, wrapping to zero and advancing
  field000a once the frame's duration is reached, then wrap the frame index
  at the animation's frame count. These are unsigned 16-bit members in the
  original load/stores.

The constants at target 0x00787DE8 and 0x00787DE0 decode to 0.7 and
-0.7 as IEEE-754 double. 0x00405490 is EffectSpawn::EffectSpawn,
0x00413090 is Secondary::ResetLocalEffectSpawn, and 0x0040E630
is Secondary::FaceOpponent.

The selector contains 124 explicit animation IDs and 186 defaulted IDs.
The reviewed mapping is in the ignored
.analysis/probes/makoto/state-case-map.csv; the original 58 KB disassembly
is in .analysis/probes/makoto/state-code-005e85f0.txt.
The evidence and extent are documented under
docs/KNOWLEDGE_BASE.md#makoto-state-dispatch-boundary-and-selector-mapping.

## Next implementation work

Extend cases 6 and onward directly from reviewed target instructions,
retaining each case's distinct frame behavior. Once a complete owner exists,
add its selected match unit with correct internal jump/selector table
ownership and run the strict VC7.1 COFF comparison. Do not add it to the
exact-function ledger until the entire 59,292-byte owned extent matches.
