// Kanna local-effect update and lifetime dispatch, reconstructed as natural C++
// from the complete native Character19::Slot07 owner.
#include "CharacterViews.h"
#include <cstdlib>

void Character19::Slot07()
{
    EffectSpawn spawn;
    unsigned short frameDuration;
    unsigned short frameCount;
    int iVar7;
    int i;
  if ((*opponentSlot)->hitstunFrames < 1) {
    i = (int)effectRead;
    
    while (i != effectWrite) {
      if (((effectActive[i] != 0) &&
          (effects[i].field0086 == 0)) &&
         ((hitstunFrames == 0 ||
          ((0 < hitstunFrames && (effects[i].field0088 != 0)))))) {
        frameDuration = patterns[effects[i].type].frames[effects[i].frame].duration;
        frameCount = patterns[effects[i].type].count;
        ResetLocalEffectSpawn(&spawn);
        switch(effects[i].type) {
            unsigned short uVar5;
            unsigned short uVar6;
            int iVar7;
            int iVar8;
            double dVar2;
            double dVar3;
        case 400:
          if (field3154[i] == 0) {
            field3154[i] = field3154[i] + 1;
            effects[i].vy = -3.0;
          }
          if (((effects[i].vy < 0.0) &&
              (effects[i].frame < 8)) &&
             (effects[i].vy =
                   effects[i].vy + 0.105,
             0.0 < effects[i].vy)) {
            effects[i].vy = 0.0;
          }
          if (((effects[i].frame < 8) &&
              (0x31 < field0008)) && (field0008 < 0x9d)) {
            RemoveLocalEffect((short)i);
          }
          else if ((effects[i].frame != 8) ||
                  (effects[i].vy =
                        effects[i].vy + 0.055,
                  effects[i].vy +
                  effects[i].y <= 0.0)) {
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if ((effects[i].frame == 8) &&
                 (field3254[i] < 1)) {
                effects[i].frame = 0;
                field3254[i] = field3254[i] + 1;
              }
              if (effects[i].frame == 8) {
                effects[i].vy = 7.0;
              }
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            effects[i].y = 0.0;
            effects[i].vy = 0.0;
            effects[i].tick = 0;
            effects[i].frame = 9;
            spawn.type = 0x193;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * 0x32;
            spawn.x = (double)iVar7;
            spawn.y = 0.0;
            spawn.field0030 = 0;
            spawn.group = 1;
            spawn.owner = 1;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
          }
          break;
        case 0x191:
          if (field3154[i] == 0) {
            field3154[i] = field3154[i] + 1;
            effects[i].vy = -3.0;
          }
          if (((effects[i].vy < 0.0) &&
              (effects[i].frame < 8)) &&
             (effects[i].vy =
                   effects[i].vy + 0.105,
             0.0 < effects[i].vy)) {
            effects[i].vy = 0.0;
          }
          if (((effects[i].frame < 8) &&
              (0x31 < field0008)) && (field0008 < 0x9d)) {
            RemoveLocalEffect((short)i);
          }
          else if ((effects[i].frame != 8) ||
                  (effects[i].vy =
                        effects[i].vy + 0.055,
                  effects[i].vy +
                  effects[i].y <= 0.0)) {
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if ((effects[i].frame == 8) &&
                 (field3254[i] < 1)) {
                effects[i].frame = 0;
                field3254[i] = field3254[i] + 1;
              }
              if (effects[i].frame == 8) {
                effects[i].vy = 7.0;
              }
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            effects[i].y = 0.0;
            effects[i].vy = 0.0;
            effects[i].tick = 0;
            effects[i].frame = 9;
            spawn.type = 0x193;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * 0x7d;
            spawn.x = (double)iVar7;
            spawn.y = 0.0;
            spawn.field0030 = 0;
            spawn.group = 1;
            spawn.owner = 1;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
          }
          break;
        case 0x192:
          if (field3154[i] == 0) {
            field3154[i] = field3154[i] + 1;
            effects[i].vy = -3.0;
          }
          if (((effects[i].vy < 0.0) &&
              (effects[i].frame < 8)) &&
             (effects[i].vy =
                   effects[i].vy + 0.105,
             0.0 < effects[i].vy)) {
            effects[i].vy = 0.0;
          }
          if (((effects[i].frame < 8) &&
              (0x31 < field0008)) && (field0008 < 0x9d)) {
            RemoveLocalEffect((short)i);
          }
          else if ((effects[i].frame != 8) ||
                  (effects[i].vy =
                        effects[i].vy + 0.055,
                  effects[i].vy +
                  effects[i].y <= 0.0)) {
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if ((effects[i].frame == 8) &&
                 (field3254[i] < 1)) {
                effects[i].frame = 0;
                field3254[i] = field3254[i] + 1;
              }
              if (effects[i].frame == 8) {
                effects[i].vy = 7.0;
              }
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            effects[i].y = 0.0;
            effects[i].vy = 0.0;
            effects[i].tick = 0;
            effects[i].frame = 9;
            spawn.type = 0x193;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * 200;
            spawn.x = (double)iVar7;
            spawn.y = 0.0;
            spawn.field0030 = 0;
            spawn.group = 1;
            spawn.owner = 1;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
          }
          break;
        case 0x193:
          if ((effects[i].frame == 0) &&
             (effects[i].tick == 0)) {
            effects[i].field0084 = 1;
            SetVerticalShake(5,0);
            pendingCharacterSoundSlot = 3;
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x194:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x195:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x196:
          if (((effects[i].frame == 0) &&
              (effects[i].tick == 0)) && (field3154[i] == 0)) {
            effects[i].field0084 = 99;
            effects[i].vx = 3.0;
            effects[i].vy = 0.0;
            field3154[i] = field3154[i] + 1;
          }
          if (effects[i].field0080 < 2) {
            if ((effects[i].x < -100.0) ||
               (0x2e4 < effects[i].frame)) {
              RemoveLocalEffect((short)i);
            }
            effects[i].vx =
                 effects[i].vx - 0.025;
            if (effects[i].vx < 1.2) {
              effects[i].vx = 1.2;
            }
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              if (frameCount <= effects[i].frame) {
                effects[i].frame = 0;
              }
            }
          }
          else {
            effects[i].type = 0x199;
            effects[i].field0084 = 0;
            effects[i].frame = 0;
            effects[i].tick = 0;
          }
          break;
        case 0x197:
          if (((effects[i].frame == 0) &&
              (effects[i].tick == 0)) && (field3154[i] == 0)) {
            effects[i].field0084 = 1;
            effects[i].vx = 3.0;
            effects[i].vy = 0.0;
          }
          if ((effects[i].field0080 < 2) &&
             ((field0008 < 0x32 || (0x95 < field0008)))) {
            effects[i].vx =
                 effects[i].vx - 0.015;
            if (effects[i].vx < 0.4) {
              effects[i].vx = 0.4;
            }
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            effects[i].type = 0x19a;
            effects[i].field0084 = 0;
          }
          break;
        case 0x198:
          if ((effects[i].frame == 0) &&
             (effects[i].tick == 0)) {
            effects[i].field0084 = 1;
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x199:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x19a:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x19b:
          if ((effects[i].frame == 0) &&
             (effects[i].tick == 0)) {
            effects[i].field0084 = 1;
            uVar5 = RandomRange(0,10);
            effects[i].vx =
                 (double)uVar5 * 0.1 + 2.5;
            uVar5 = RandomRange(0,0x14);
            effects[i].vy =
                 -1.2 - (double)uVar5 * 0.1;
          }
          effects[i].vy =
               effects[i].vy + 0.05;
          if (((effects[i].y < 0.0) ||
              (effects[i].vy <= 0.0)) ||
             (effects[i].frame != 1)) {
            if (((0.0 <= effects[i].y) ||
                (1 < effects[i].field0080)) &&
               (effects[i].frame == 0)) {
              effects[i].y =
                   effects[i].y - 1.0;
              effects[i].frame = 1;
              effects[i].vy = -1.5;
              spawn.type = 0x19c;
              iVar7 = (int)effects[i].x;
              spawn.x = (double)iVar7;
              iVar7 = (int)effects[i].y;
              spawn.y = (double)iVar7;
              spawn.field0030 = 0;
              spawn.layer = 1;
              spawn.flag0018 = facing;
              EmitLocalEffect(&spawn);
              pendingCharacterSoundSlot = 1;
            }
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            RemoveLocalEffect((short)i);
          }
          break;
        case 0x19c:
          if ((effects[i].frame == 0) &&
             (effects[i].tick == 0)) {
            uVar5 = RandomRange(0,10);
            effects[i].vx =
                 (double)uVar5 * 0.1 + 1.5;
            effects[i].vy = -1.5;
          }
          effects[i].vy =
               effects[i].vy + 0.05;
          if ((effects[i].y < 0.0) ||
             (effects[i].vy <= 0.0)) {
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            RemoveLocalEffect((short)i);
          }
          break;
        case 0x19d:
          if ((effects[i].frame == 0) &&
             (effects[i].tick == 0)) {
            effects[i].field0084 = 1;
            uVar5 = RandomRange(0,0x14);
            effects[i].vx =
                 (double)uVar5 * 0.1 + 1.7;
            uVar5 = RandomRange(0,10);
            effects[i].vy =
                 -0.5 - (double)uVar5 * 0.1;
          }
          effects[i].vy =
               effects[i].vy + 0.05;
          if (((effects[i].y < 0.0) ||
              (effects[i].vy <= 0.0)) ||
             (effects[i].frame != 1)) {
            if (((0.0 <= effects[i].y) ||
                (1 < effects[i].field0080)) &&
               (effects[i].frame == 0)) {
              effects[i].y =
                   effects[i].y - 1.0;
              effects[i].frame = 1;
              effects[i].vy = -1.5;
              spawn.type = 0x19e;
              spawn.x = (double)(int)effects[i].x;
              spawn.y = (double)(int)effects[i].y;
              spawn.field0030 = 0;
              spawn.layer = 1;
              spawn.flag0018 = facing;
              EmitLocalEffect(&spawn);
              pendingCharacterSoundSlot = 1;
            }
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            RemoveLocalEffect((short)i);
          }
          break;
        case 0x19e:
          if ((effects[i].frame == 0) &&
             (effects[i].tick == 0)) {
            uVar5 = RandomRange(0,10);
            effects[i].vx =
                 (double)uVar5 * 0.1 + 1.5;
            effects[i].vy = -1.5;
          }
          effects[i].vy =
               effects[i].vy + 0.05;
          if ((effects[i].y < 0.0) ||
             (effects[i].vy <= 0.0)) {
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                RemoveLocalEffect((short)i);
              }
            }
          }
          else {
            RemoveLocalEffect((short)i);
          }
          break;
        case 0x19f:
          if (field3154[i] == 0) {
            effects[i].field0084 = 1;
            field3154[i] = field3154[i] + 1;
            effects[i].vx = -3.0;
            effects[i].vy = 0.5;
          }
          effects[i].vy =
               effects[i].vy -
               effects[i].ay;
          effects[i].tick = effects[i].tick + 1;
          if ((((680.0 < effects[i].x) &&
               ((char)effects[i].flag0048 == '\x01')) ||
              ((effects[i].x < -60.0 &&
               ((char)effects[i].flag0048 == -1)))) ||
             (effects[i].y < -320.0)) {
            RemoveLocalEffect((short)i);
          }
          else if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1a0:
          if (field3154[i] == 0) {
            effects[i].field0084 = 1;
            field3154[i] = field3154[i] + 1;
            uVar5 = RandomRange(0,100);
            effects[i].vx =
                 (double)uVar5 * 0.01 + 1.0;
            uVar5 = RandomRange(0,100);
            effects[i].ay = (double)uVar5 * 0.0002;
            effects[i].vy = 0.5;
            uVar6 = RandomRange(0,0xf);
            effects[i].frame = uVar6;
          }
          effects[i].vy =
               effects[i].vy -
               effects[i].ay;
          effects[i].tick = effects[i].tick + 1;
          if ((((680.0 < effects[i].x) &&
               ((char)effects[i].flag0048 == '\x01')) ||
              ((effects[i].x < -60.0 &&
               ((char)effects[i].flag0048 == -1)))) ||
             (effects[i].y < -320.0)) {
            RemoveLocalEffect((short)i);
          }
          else if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1a1:
          if (field3154[i] == 0) {
            effects[i].field0084 = 1;
            field3154[i] = field3154[i] + 1;
            uVar5 = RandomRange(0,100);
            effects[i].vx =
                 (double)uVar5 * 0.01 + 3.5;
            uVar5 = RandomRange(0,100);
            effects[i].ay = (double)uVar5 * 0.00015;
            effects[i].vy = 0.5;
            uVar6 = RandomRange(0,0xf);
            effects[i].frame = uVar6;
          }
          effects[i].vy =
               effects[i].vy -
               effects[i].ay;
          effects[i].tick = effects[i].tick + 1;
          if ((((680.0 < effects[i].x) &&
               ((char)effects[i].flag0048 == '\x01')) ||
              ((effects[i].x < -60.0 &&
               ((char)effects[i].flag0048 == -1)))) ||
             (effects[i].y < -320.0)) {
            RemoveLocalEffect((short)i);
          }
          else if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1a2:
          if ((short)field0008 == 0x12f) {
            effects[i].x =
                 (double)((char)effects[i].flag0048 * 10) + positionX +
                 0.0;
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (((effects[i].frame == 9) &&
                (field000a < 0xd)) && ((short)field0008 == 0x12f)) {
              effects[i].frame =
                   effects[i].frame + -2;
            }
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1a3:
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0x100) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1a4:
          if ((short)field0008 != 0xc9) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0xc9) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1a5:
          if ((short)field0008 != 0xca) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0xca) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1a6:
          if ((short)field0008 != 0xcd) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0xcd) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1a7:
          if ((short)field0008 != 0xd0) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0xd0) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1a8:
          if ((short)field0008 != 0xcb) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0xcb) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1a9:
          if ((short)field0008 != 0xd1) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0xd1) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1aa:
          effects[i].x = positionX;
          effects[i].y = positionY;
          if (effects[i].frame == 0) {
            effects[i].field0084 = 1;
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1ab:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            if (effects[i].frame == 4) {
              spawn.type = 0x1ac;
              spawn.x = (double)contextOwner->cameraBounds.left;
              iVar7 = (int)effects[i].y;
              iVar7 = iVar7 + -0x3c;
              spawn.y = (double)iVar7;
              spawn.field0030 = 2;
              spawn.layer = 1;
              spawn.flag0018 = 1;
              EmitLocalEffect(&spawn);
            }
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1ac:
          effects[i].x = (double)contextOwner->cameraBounds.left;
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1ad:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            if (effects[i].frame == 4) {
              spawn.type = 0x1ae;
              spawn.x = (double)(int)effects[i].x;
              spawn.y = (double)(int)effects[i].y;
              spawn.field0030 = 2;
              spawn.layer = 1;
              spawn.flag0018 = effects[i].flag0048;
              spawn.owner = 1;
              EmitLocalEffect(&spawn);
              EmitLocalEffect(&spawn);
              EmitLocalEffect(&spawn);
              EmitLocalEffect(&spawn);
              EmitLocalEffect(&spawn);
              EmitLocalEffect(&spawn);
            }
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1ae:
          if (field3154[i] == 0) {
            field3154[i] = field3154[i] + 1;
            effects[i].field0084 = 1;
            if (field3138 == 0) {
              effects[i].SetVelocityPolar(-140.0,3.0);
            }
            if (field3138 == 1) {
              effects[i].SetVelocityPolar(-165.0,3.0);
            }
            if (field3138 == 2) {
              effects[i].SetVelocityPolar(-170.0,3.0);
            }
            if (field3138 == 3) {
              effects[i].SetVelocityPolar(140.0,3.0);
            }
            if (field3138 == 4) {
              effects[i].SetVelocityPolar(165.0,3.0);
            }
            if (field3138 == 5) {
              effects[i].SetVelocityPolar(170.0,3.0);
            }
            field3138 = field3138 + 1;
            if (field3138 == 6) {
              field3138 = 0;
            }
          }
          effects[i].vx =
               effects[i].vx + 0.025;
          if ((*opponentSlot)->positionY - 45.0 <
              effects[i].y) {
            effects[i].vy =
                 effects[i].vy - 0.015;
          }
          if (effects[i].y <
              (*opponentSlot)->positionY - 45.0) {
            effects[i].vy =
                 effects[i].vy + 0.015;
          }
          if (effects[i].tick == 0) {
            spawn.type = 0x1af;
            spawn.x = (double)(int)effects[i].x;
            spawn.y = (double)(int)effects[i].y;
            spawn.field0030 = 2;
            spawn.layer = 1;
            spawn.flag0018 = effects[i].flag0048;
            EmitLocalEffect(&spawn);
          }
          if (((900.0 < effects[i].x) ||
              (effects[i].x < -360.0)) ||
             (0 < effects[i].field0080)) {
            effects[i].type = 0x1af;
            effects[i].frame = 0;
            effects[i].tick = 0;
          }
          else {
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                effects[i].frame = 0;
              }
            }
          }
          break;
        case 0x1af:
          effects[i].vx = 0.0;
          effects[i].vy = 0.0;
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1b0:
          if ((short)field0008 != 0x135) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0x135) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1b1:
          if ((short)field0008 != 0x135) {
            RemoveLocalEffect((short)i);
          }
          effects[i].field008c = 30000;
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if ((field000a == 0x37) &&
             (effects[i].frame < 0x50)) {
            effects[i].tick = 0;
            effects[i].frame = 0x50;
          }
          else if (field000a < 0x38) {
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if ((effects[i].frame == 0x50) &&
                 (field000a < 0x37)) {
                effects[i].frame = 0x38;
              }
              if (frameCount <= effects[i].frame) {
                effects[i].frame = 0x6c;
              }
            }
          }
          else {
            RemoveLocalEffect((short)i);
          }
          break;
        case 0x1b2:
          if ((short)field0008 != 0x135) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0x135) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1b3:
          if ((short)field0008 != 0x135) {
            RemoveLocalEffect((short)i);
          }
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (((short)field0008 == 0x135) && (0 < hitstopFrames)) {
            effects[i].tick =
                 effects[i].tick + -1;
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1b4:
          effects[i].field008c = 30000;
          if (((short)field0008 != 0x135) || (0x35 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1b5:
          effects[i].field008c = 30000;
          if (((short)field0008 != 0x135) || (0x35 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1b6:
          effects[i].field008c = 30000;
          if (((short)field0008 != 0x135) || (0x35 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1b7:
          if (((short)field0008 != 0x135) || (0x36 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          field3154[i] = field3154[i] + 1;
          if (field3154[i] == 0x96) {
            spawn.type = 0x1ba;
            spawn.x = effects[i].x;
            spawn.y = effects[i].y;
            spawn.field0030 = 2;
            spawn.layer = 1;
            spawn.owner = 1;
            spawn.flag0018 = 1;
            spawn.palette = 1;
            EmitLocalEffect(&spawn);
          }
          if (field3154[i] == 0xd2) {
            spawn.type = 0x1bb;
            spawn.x = effects[i].x;
            spawn.y = effects[i].y;
            spawn.field0030 = 2;
            spawn.layer = 1;
            spawn.owner = 1;
            spawn.flag0018 = 1;
            spawn.palette = 1;
            EmitLocalEffect(&spawn);
          }
          if (field3154[i] == 0x10e) {
            spawn.type = 0x1bc;
            spawn.x = effects[i].x;
            spawn.y = effects[i].y;
            spawn.field0030 = 2;
            spawn.layer = 1;
            spawn.owner = 1;
            spawn.flag0018 = 1;
            spawn.palette = 1;
            EmitLocalEffect(&spawn);
          }
          if (field3154[i] == 300) {
            spawn.type = 0x1bd;
            spawn.x = effects[i].x;
            spawn.y = effects[i].y;
            spawn.field0030 = 2;
            spawn.layer = 1;
            spawn.owner = 1;
            spawn.flag0018 = 1;
            spawn.palette = 1;
            EmitLocalEffect(&spawn);
          }
          if (field3154[i] == 0x14a) {
            spawn.type = 0x1be;
            spawn.x = effects[i].x;
            spawn.y = effects[i].y;
            spawn.field0030 = 2;
            spawn.layer = 1;
            spawn.owner = 1;
            spawn.flag0018 = 1;
            spawn.palette = 1;
            EmitLocalEffect(&spawn);
          }
          if (field3154[i] == 0x153) {
            spawn.type = 0x1bf;
            spawn.x = effects[i].x;
            spawn.y = effects[i].y;
            spawn.field0030 = 2;
            spawn.layer = 1;
            spawn.owner = 1;
            spawn.flag0018 = 1;
            spawn.palette = 1;
            EmitLocalEffect(&spawn);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1b8:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1b9:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1ba:
          if (((short)field0008 != 0x135) || (0x36 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame =
                   effects[i].frame + -2;
            }
          }
          break;
        case 0x1bb:
          if (((short)field0008 != 0x135) || (0x36 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame =
                   effects[i].frame + -2;
            }
          }
          break;
        case 0x1bc:
          if (((short)field0008 != 0x135) || (0x36 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame =
                   effects[i].frame + -2;
            }
          }
          break;
        case 0x1bd:
          if (((short)field0008 != 0x135) || (0x36 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame =
                   effects[i].frame + -2;
            }
          }
          break;
        case 0x1be:
          if (((short)field0008 != 0x135) || (0x36 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame =
                   effects[i].frame + -2;
            }
          }
          break;
        case 0x1bf:
          if (((short)field0008 != 0x135) || (0x36 < field000a)) {
            RemoveLocalEffect((short)i);
          }
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame =
                   effects[i].frame + -2;
            }
          }
          break;
        case 0x1c0:
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
          break;
        case 0x1ef:
          effects[i].vx = -0.02;
          effects[i].field008c = 30000;
          effects[i].tick = effects[i].tick + 1;
          if ((short)field0008 != 0x57) {
            RemoveLocalEffect((short)i);
          }
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              effects[i].frame = 0;
            }
          }
          break;
        case 0x1f0:
          if (((((((short)field0008 == 0x53) || ((short)field0008 == 0x54)) ||
                ((short)field0008 == 0x55)) || ((short)field0008 == 0x56)) &&
              (((short)field0008 != 0x53 || (field000a < 2)))) &&
             (((short)field0008 != 0x54 || (field000a < 2)))) {
            effects[i].tick =
                 effects[i].tick + 1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                effects[i].frame = 0;
              }
            }
          }
          else {
            spawn.type = 0x1f1;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * 0x17;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -4;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * -4;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -6;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * -0xe;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -0x1a;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            spawn.x = (double)(int)effects[i].x;
            spawn.y = (double)(int)effects[i].y;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * 0x1e;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -0x28;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * -0x19;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -0x50;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * -0x23;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -0x2a;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * -0x12;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -0x14;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * 2;
            spawn.x = (double)iVar7;
            iVar7 = (int)effects[i].y;
            iVar7 = iVar7 + -0x41;
            spawn.y = (double)iVar7;
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            iVar7 = (int)effects[i].x;
            iVar7 = iVar7 + (char)facing * 0x10;
            spawn.x = (double)iVar7;
            spawn.y = (double)((int)effects[i].y + -0x50);
            spawn.field0030 = 0;
            spawn.layer = 1;
            spawn.flag0018 = facing;
            EmitLocalEffect(&spawn);
            pendingContextSoundSlot = 0x22;
            RemoveLocalEffect((short)i);
            field3144 = 0;
          }
          break;
        case 0x1f1:
          if (((effects[i].frame == 0) &&
              (effects[i].tick == 0)) && (field3154[i] == 0)) {
            iVar7 = rand();
            iVar8 = rand();
            field3254[i] =
                 (unsigned int)(16000 < iVar7) * 0x28 + 0x50 + (unsigned int)(16000 < iVar8) * 0x14;
            field3154[i] = field3154[i] + 1;
            iVar7 = rand();
            dVar2 = (double)(16000 < iVar7) * 1.2;
            iVar7 = rand();
            dVar3 = (double)(16000 < iVar7) * 0.7;
            iVar7 = rand();
            effects[i].vx =
                 (double)(16000 < iVar7) * 1.7 + dVar3 + dVar2 + -1.8;
            iVar7 = rand();
            dVar2 = (double)(16000 < iVar7) * 0.6;
            iVar7 = rand();
            dVar3 = (double)(16000 < iVar7) * 0.9;
            iVar7 = rand();
            effects[i].vy =
                 -1.2 - ((double)(16000 < iVar7) * 1.4 + dVar3 + dVar2);
          }
          effects[i].vy =
               effects[i].vy + 0.05;
          if ((0.0 < effects[i].y) &&
             (0.0 < effects[i].vy)) {
            effects[i].vy =
                 -effects[i].vy;
          }
          if (field3254[i] < 10) {
            effects[i].group = 1;
          }
          if (field3254[i] < 0) {
            RemoveLocalEffect((short)i);
          }
          else {
            effects[i].tick =
                 effects[i].tick + 1;
            field3254[i] = field3254[i] + -1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                effects[i].frame = 0;
              }
            }
          }
          break;
        case 0x1f2:
          if (((effects[i].frame == 0) &&
              (effects[i].tick == 0)) && (field3154[i] == 0)) {
            iVar7 = rand();
            iVar8 = rand();
            field3254[i] =
                 (unsigned int)(16000 < iVar7) * 0x3c + 0x78 + (unsigned int)(16000 < iVar8) * 0x28;
            field3154[i] = field3154[i] + 1;
            iVar7 = rand();
            iVar8 = rand();
            dVar2 = (double)(16000 < iVar8) * 0.5;
            iVar8 = rand();
            effects[i].vx =
                 (double)(16000 < iVar8) * 1.5 + dVar2 + (double)(16000 < iVar7) +
                 -1.5;
            iVar7 = rand();
            dVar2 = (double)(16000 < iVar7) * 0.5;
            iVar7 = rand();
            dVar3 = (double)(16000 < iVar7) * 0.8;
            iVar7 = rand();
            effects[i].vy =
                 -1.0 - ((double)(16000 < iVar7) * 1.2 + dVar3 + dVar2);
          }
          effects[i].vy =
               effects[i].vy + 0.03;
          if ((0.0 < effects[i].y) &&
             (0.0 < effects[i].vy)) {
            effects[i].vy =
                 -effects[i].vy;
          }
          if (field3254[i] < 10) {
            effects[i].group = 1;
          }
          if (field3254[i] < 0) {
            RemoveLocalEffect((short)i);
          }
          else {
            effects[i].tick =
                 effects[i].tick + 1;
            field3254[i] = field3254[i] + -1;
            if (frameDuration <= effects[i].tick) {
              effects[i].tick = 0;
              effects[i].frame =
                   effects[i].frame + 1;
              effects[i].field0080 = 0;
              if (frameCount <= effects[i].frame) {
                effects[i].frame = 0;
              }
            }
          }
          break;
        case 499:
          effects[i].x = positionX;
          effects[i].y = positionY;
          effects[i].tick = effects[i].tick + 1;
          if (frameDuration <= effects[i].tick) {
            effects[i].tick = 0;
            effects[i].frame =
                 effects[i].frame + 1;
            effects[i].field0080 = 0;
            if (frameCount <= effects[i].frame) {
              RemoveLocalEffect((short)i);
            }
          }
        }
      }
      ++i;
      if (0x3f < i) {
        i = 0;
      }
    }
  }
  return;
}
