#include "CharacterViews.h"
#include <math.h>

void Character19::Slot07()
{
  if ((*opponentSlot)->field014c < 1) {
    int effectIndex = effectRead;
    EffectSpawn spawn;

    while (effectIndex != effectWrite) {
      if (effectActive[effectIndex] != 0) {
        unsigned short frameDuration = effects[effectIndex].patterns->frames[effects[effectIndex].frame].duration;
        unsigned short frameCount = effects[effectIndex].patterns->count;

        ResetLocalEffectSpawn(&spawn);
        if ((effects[effectIndex].field0086 == 0) &&
            ((field014c == 0) ||
             ((field014c > 0) && (effects[effectIndex].field0088 != 0)))) {
          switch (effects[effectIndex].type) {
          case 400:
            if (field3154[effectIndex] == 0) {
              field3154[effectIndex] += 1;
              effects[effectIndex].vy = -3.0;
            }
            if ((effects[effectIndex].vy < 0.0) && (effects[effectIndex].frame < 8)) {
              effects[effectIndex].vy += 0.105;
              if (0.0 < effects[effectIndex].vy) {
                effects[effectIndex].vy = 0.0;
              }
            }
            if ((effects[effectIndex].frame < 8) && (field0008 > 0x31) && (field0008 < 0x9d)) {
              RemoveLocalEffect(effectIndex);
            }
            else if ((effects[effectIndex].frame != 8) ||
                     ((effects[effectIndex].vy += 0.055),
                      (effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].tick += 1;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame += 1;
                effects[effectIndex].field0080 = 0;
                if ((effects[effectIndex].frame == 8) && (field3254[effectIndex] < 1)) {
                  effects[effectIndex].frame = 0;
                  field3254[effectIndex] += 1;
                }
                if (effects[effectIndex].frame == 8) {
                  effects[effectIndex].vy = 7.0;
                }
                if (frameCount <= effects[effectIndex].frame) {
                  RemoveLocalEffect(effectIndex);
                }
              }
            }
            else {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0;
              effects[effectIndex].field0080 = 0;
              if (field3154[effectIndex] < 1) {
                // The native x87 conversion currently resolves to zero; its source operand is still under review.
                int randomOffset = 0;
                spawn.owner = 1;
                spawn.type = 0x193;
                spawn.x = (double)(randomOffset + (int)facing * 0x32);
                spawn.y = 0.0;
                spawn.flag0018 = facing;
                spawn.group = 0;
                spawn.layer = 1;
                spawn.field0028 = 1;
                EmitLocalEffect(&spawn);
                field3154[effectIndex] += 1;
              }
            }
            break;
          default:
            break;
          }
        }
      }
      effectIndex += 1;
      if (effectIndex >= 0x40) {
        effectIndex = 0;
      }
    }
  }
}
