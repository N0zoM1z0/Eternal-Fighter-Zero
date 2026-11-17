// Minagi's native Character21 vtable Slot07 (0x005B2D10), typed
// full-dispatch reconstruction candidate. Semantic/byte-exact proof pending.
// The normal switch below generates an attached 69-entry jump table and
// 100-byte compact index in VC7.1 COFF; no handwritten table/padding is used.
// Landing predicates preserve the original inverted <= tests: unordered
// floating comparisons must take the native landing path, not a direct > path.
#include "../../src/CharacterViews.h"
#include <cstdlib>

void Character21::Slot07()
{
    double dVar1, dVar2;
    unsigned short frameCount, frameDuration, uVar5;
    unsigned int uVar6;
    int iVar7, iVar8;
    int effectIndex;


  if ((*opponentSlot)->hitstunFrames > 0) return;
  effectIndex = (int)(short)effectRead;
    EffectSpawn spawn;
    while (effectIndex != effectWrite) {
      if (((effectActive[effectIndex] != 0) &&
          (effects[effectIndex].field0086 == 0)) &&
         (((short)hitstunFrames == 0 ||
          ((0 < (short)hitstunFrames && (effects[effectIndex].field0088 != 0)))))) {
        frameDuration = patterns[effects[effectIndex].type].frames[effects[effectIndex].frame].duration;
        frameCount = patterns[effects[effectIndex].type].count;
        ResetLocalEffectSpawn(&spawn);

        switch(effects[effectIndex].type) {
        case 400:
          field3154[effectIndex] = 0;
          effects[effectIndex].field0084 = 0;
          if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
            effects[effectIndex].flag0048 = 1;
          }
          else {
            effects[effectIndex].flag0048 = -1;
          }
          effects[effectIndex].vx = 0.0;
          effects[effectIndex].vy = 0.0;
          field3148 = 0;
          if ((field0008 == 0xfa) && (field000a == 0)) {
            field3148 = 1;
            effects[effectIndex].type = 0x191;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((field0008 == 0xfb) || (field0008 == 0xfc)) {
            field3148 = 2;
            effects[effectIndex].type = 0x192;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0xfd) && (field000a == 2)) ||
                  ((field0008 == 0x109 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x194;
            effects[effectIndex].frame = 7;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0xfe) && (field000a == 2)) ||
                  ((field0008 == 0x10a && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x195;
            effects[effectIndex].frame = 7;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0xff) && (field000a == 2)) ||
                  ((field0008 == 0x10b && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x196;
            effects[effectIndex].frame = 7;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x100) && (field000a == 2)) ||
                  ((field0008 == 0x10d && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x197;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x101) && (field000a == 2)) ||
                  ((field0008 == 0x10e && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x198;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x102) && (field000a == 2)) ||
                  ((field0008 == 0x10f && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x199;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x103) && (field000a == 2)) ||
                  ((field0008 == 0x110 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x19a;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x104) && (field000a == 2)) ||
                  ((field0008 == 0x111 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x19b;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x105) && (field000a == 2)) ||
                  ((field0008 == 0x112 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x19c;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((field0008 == 0x113) && (field000a == 2)) {
            field3148 = 4;
            effects[effectIndex].type = 0x1d2;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((field0008 == 0x114) && (field000a == 2)) {
            field3148 = 4;
            effects[effectIndex].type = 0x1d3;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((field0008 == 0x115) && (field000a == 2)) {
            field3148 = 4;
            effects[effectIndex].type = 0x1d4;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 300) && (field000a == 2)) ||
                  ((field0008 == 0x132 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c6;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x12d) && (field000a == 2)) ||
                  ((field0008 == 0x133 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c7;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x12e) && (field000a == 2)) ||
                  ((field0008 == 0x134 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c8;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x12f) && (field000a == 2)) ||
                  ((field0008 == 0x135 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1a0;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x130) && (field000a == 2)) ||
                  ((field0008 == 0x136 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1a2;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x131) && (field000a == 2)) ||
                  ((field0008 == 0x137 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1a4;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((((field0008 == 0x138) || (field0008 == 0x139)) ||
                   (field0008 == 0x13a)) && (field000a == 2)) {
            field3148 = 4;
            effects[effectIndex].type = 0x1b5;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((field0008 == 0x13b) && (field000a == 3)) {
            field3148 = 4;
            effects[effectIndex].type = 0x1be;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x13c) && (field000a == 2)) ||
                  ((field0008 == 0x13f && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c6;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x13d) && (field000a == 2)) ||
                  ((field0008 == 0x140 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c7;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x13e) && (field000a == 2)) ||
                  ((field0008 == 0x141 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c8;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (field0008 == 0x7b) {
            field3148 = 4;
            effects[effectIndex].y = 0.0;
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].vy = 0.0;
            effects[effectIndex].ay = 0.0;
            effects[effectIndex].type = 0x1d5;
            effects[effectIndex].frame = 0xb;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((300.0 <
                 positionX - effects[effectIndex].x) ||
               (positionX - effects[effectIndex].x <
                -300.0)) {
              field3148 = 2;
              effects[effectIndex].type = 0x1b4;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              if (effects[effectIndex].x < positionX) {
                effects[effectIndex].flag0048 = 1;
              }
              if (positionX <= effects[effectIndex].x) {
                effects[effectIndex].flag0048 = -1;
              }
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
              }
            }
          }
          break;
        case 0x191: {
          field3154[effectIndex] = 0;
          effects[effectIndex].vy = 0.0;
          effects[effectIndex].vx = 0.0;
          effects[effectIndex].field0084 = 0;
          if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
            effects[effectIndex].flag0048 = 1;
          }
          else {
            effects[effectIndex].flag0048 = -1;
          }
          effects[effectIndex].vx = 0.0;
          effects[effectIndex].vy = 0.0;
          field3148 = 1;
          // The common idle-frame advancement is also entered when the
          // active character state stops matching the temporary attack.
          if (effects[effectIndex].frame >= 8 &&
              effects[effectIndex].frame < 17) {
            field3148 = 3;
            if ((field0008 == 0xfa) && (field000a == 0)) {
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x11;
              break;
            }
            else if (((field0008 == 0xfd) && (field000a == 2)) ||
                    ((field0008 == 0x109 && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1a6;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0xfe) && (field000a == 2)) ||
                    ((field0008 == 0x10a && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1a7;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0xff) && (field000a == 2)) ||
                    ((field0008 == 0x10b && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1a8;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x100) && (field000a == 2)) ||
                    ((field0008 == 0x10d && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x197;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x101) && (field000a == 2)) ||
                    ((field0008 == 0x10e && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x198;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x102) && (field000a == 2)) ||
                    ((field0008 == 0x10f && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x199;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x103) && (field000a == 2)) ||
                    ((field0008 == 0x110 && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1aa;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x104) && (field000a == 2)) ||
                    ((field0008 == 0x111 && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1ab;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x105) && (field000a == 2)) ||
                    ((field0008 == 0x112 && (field000a == 3)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1ac;
              effects[effectIndex].frame = 8;
              effects[effectIndex].tick = 0;
              break;
            }
            else if ((field0008 == 0x113) && (field000a == 2)) {
              field3148 = 4;
              effects[effectIndex].type = 0x1d2;
              effects[effectIndex].frame = 9;
              effects[effectIndex].tick = 0;
              break;
            }
            else if ((field0008 == 0x114) && (field000a == 2)) {
              field3148 = 4;
              effects[effectIndex].type = 0x1d3;
              effects[effectIndex].frame = 9;
              effects[effectIndex].tick = 0;
              break;
            }
            else if ((field0008 == 0x115) && (field000a == 2)) {
              field3148 = 4;
              effects[effectIndex].type = 0x1d4;
              effects[effectIndex].frame = 9;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 300) && (field000a == 2)) ||
                    ((field0008 == 0x132 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1c6;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x12d) && (field000a == 2)) ||
                    ((field0008 == 0x133 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1c7;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x12e) && (field000a == 2)) ||
                    ((field0008 == 0x134 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1c8;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x12f) && (field000a == 2)) ||
                    ((field0008 == 0x135 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1a1;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x130) && (field000a == 2)) ||
                    ((field0008 == 0x136 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1a3;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x131) && (field000a == 2)) ||
                    ((field0008 == 0x137 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1a5;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if ((((field0008 == 0x138) || (field0008 == 0x139)) ||
                     (field0008 == 0x13a)) && (field000a == 2)) {
              field3148 = 4;
              effects[effectIndex].type = 0x1b5;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if ((field0008 == 0x13b) && (field000a == 3)) {
              field3148 = 4;
              effects[effectIndex].type = 0x1be;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x13c) && (field000a == 2)) ||
                    ((field0008 == 0x13f && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1c9;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x13d) && (field000a == 2)) ||
                    ((field0008 == 0x140 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1ca;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (((field0008 == 0x13e) && (field000a == 2)) ||
                    ((field0008 == 0x141 && (field000a == 1)))) {
              field3148 = 4;
              effects[effectIndex].type = 0x1cb;
              effects[effectIndex].frame = 0;
              effects[effectIndex].tick = 0;
              break;
            }
            else if (field0008 == 0x7b) {
              field3148 = 4;
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].ay = 0.0;
              effects[effectIndex].type = 0x1d5;
              effects[effectIndex].frame = 0xb;
              effects[effectIndex].tick = 0;
              break;
            }
          }
          if ((field0008 == 0xfb) || (field0008 == 0xfc)) {
            field3148 = 1;
            effects[effectIndex].type = 0x192;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0x11) {
                effects[effectIndex].frame = 8;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
                effects[effectIndex].type = 400;
                field3148 = 0;
              }
            }
          }
          break;
        }
        case 0x192:
          field3148 = 2;
          effects[effectIndex].field0084 = 0;
          if (effects[effectIndex].frame < 0xb) {
            effects[effectIndex].vx = 1.5;
            effects[effectIndex].vy = 0.0;
          }
          if (10 < effects[effectIndex].frame) {
            if (effects[effectIndex].vx > 0.0) {
              effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.035;
            }
            if (effects[effectIndex].vx < 0.0) {
              effects[effectIndex].vx = 0.0;
            }
          }
          if (effects[effectIndex].x > 620.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 620.0;
          }
          if (effects[effectIndex].x < 20.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 20.0;
          }
          if (((field0008 == 0xfd) && (field000a == 2)) ||
             ((field0008 == 0x109 && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x194;
            effects[effectIndex].frame = 7;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0xfe) && (field000a == 2)) ||
                  ((field0008 == 0x10a && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x195;
            effects[effectIndex].frame = 7;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0xff) && (field000a == 2)) ||
                  ((field0008 == 0x10b && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x196;
            effects[effectIndex].frame = 7;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x100) && (field000a == 2)) ||
                  ((field0008 == 0x10d && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x197;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x101) && (field000a == 2)) ||
                  ((field0008 == 0x10e && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x198;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x102) && (field000a == 2)) ||
                  ((field0008 == 0x10f && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x199;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x103) && (field000a == 2)) ||
                  ((field0008 == 0x110 && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x19a;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x104) && (field000a == 2)) ||
                  ((field0008 == 0x111 && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x19b;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x105) && (field000a == 2)) ||
                  ((field0008 == 0x112 && (field000a == 3)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x19c;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if ((field0008 == 0x113) && (field000a == 2)) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1d2;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if ((field0008 == 0x114) && (field000a == 2)) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1d3;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if ((field0008 == 0x115) && (field000a == 2)) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1d4;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 300) && (field000a == 2)) ||
                  ((field0008 == 0x132 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1c6;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x12d) && (field000a == 2)) ||
                  ((field0008 == 0x133 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1c7;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x12e) && (field000a == 2)) ||
                  ((field0008 == 0x134 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1c8;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x12f) && (field000a == 2)) ||
                  ((field0008 == 0x135 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1a0;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x130) && (field000a == 2)) ||
                  ((field0008 == 0x136 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1a2;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x131) && (field000a == 2)) ||
                  ((field0008 == 0x137 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1a4;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if ((((field0008 == 0x138) || (field0008 == 0x139)) ||
                   (field0008 == 0x13a)) && (field000a == 2)) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1b5;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if ((field0008 == 0x13b) && (field000a == 3)) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1be;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x13c) && (field000a == 2)) ||
                  ((field0008 == 0x13f && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1c6;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x13d) && (field000a == 2)) ||
                  ((field0008 == 0x140 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1c7;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (((field0008 == 0x13e) && (field000a == 2)) ||
                  ((field0008 == 0x141 && (field000a == 1)))) {
            if (effects[effectIndex].x <= (*opponentSlot)->positionX) {
              effects[effectIndex].flag0048 = 1;
            }
            else {
              effects[effectIndex].flag0048 = -1;
            }
            field3148 = 4;
            effects[effectIndex].type = 0x1c8;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else if (field0008 == 0x7b) {
            field3148 = 4;
            effects[effectIndex].y = 0.0;
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].vy = 0.0;
            effects[effectIndex].ay = 0.0;
            effects[effectIndex].type = 0x1d5;
            effects[effectIndex].frame = 0xb;
            effects[effectIndex].tick = 0;
          }
          else if (field3154[effectIndex] == 0) {
            field3154[effectIndex] = 1;
            if (field0008 == 0xfb) {
              effects[effectIndex].flag0048 = 1;
            }
            if (field0008 == 0xfc) {
              effects[effectIndex].flag0048 = 0xff;
            }
          }
          else if (field0008 == 0xfa) {
            field3148 = 1;
            effects[effectIndex].type = 0x191;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if ((effects[effectIndex].frame == 0xb) &&
                 (field3154[effectIndex] < 0)) {
                effects[effectIndex].frame = 0;
                field3154[effectIndex] = field3154[effectIndex] + 1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].type = 400;
                field3154[effectIndex] = 0;
              }
            }
          }
          break;
        case 0x193:
          field3148 = 4;
          effects[effectIndex].field0088 = 0;
          field3154[effectIndex] = 0;
          field3254[effectIndex] = 0;
          field3354[effectIndex] = 0;
          if (field0008 == 0x7b) {
            field3148 = 4;
            effects[effectIndex].y = 0.0;
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].vy = 0.0;
            effects[effectIndex].ay = 0.0;
            effects[effectIndex].type = 0x1d5;
            effects[effectIndex].frame = 0xb;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = -1.0;
              effects[effectIndex].vy = -2.5;
              effects[effectIndex].ay = 0.035;
            }
            if (((effects[effectIndex].y < 0.0) &&
                (effects[effectIndex].frame < 7)) &&
               (effects[effectIndex].vy =
                     effects[effectIndex].vy +
                     effects[effectIndex].ay,
               0.0 <
               effects[effectIndex].y +
               effects[effectIndex].vy)) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 7;
              SetVerticalShake(3,0);
              spawn.type = 3;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)iVar7;
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)iVar7;
              spawn.group = 2;
              spawn.layer = 0;
              contextOwner->EmitEffect(&spawn);
              pendingContextSoundSlot = 7;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 7) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -2;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x194:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.9;
              effects[effectIndex].vy = -1.1;
              effects[effectIndex].ay = 0.025;
              effects[effectIndex].field0084 = 1;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame < 12 &&
                (effects[effectIndex].vy += effects[effectIndex].ay,
                 !(effects[effectIndex].y + effects[effectIndex].vy <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xc;
            }
            else {
              if (effects[effectIndex].field0080 < 1) {
                if (effects[effectIndex].x > 620.0) {
                  effects[effectIndex].vx = 0.0;
                  effects[effectIndex].x = 620.0;
                }
                if (effects[effectIndex].x < 20.0) {
                  effects[effectIndex].vx = 0.0;
                  effects[effectIndex].x = 20.0;
                }
                ++effects[effectIndex].tick;
                if (effects[effectIndex].tick >= frameDuration) {
                  effects[effectIndex].tick = 0;
                  ++effects[effectIndex].frame;
                  effects[effectIndex].field0080 = 0;
                  if (effects[effectIndex].frame == 0xc) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
              else {
                effects[effectIndex].frame = 0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].type = 0x1a9;
              }
            }
          }
          break;
        case 0x195:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 1.5;
              effects[effectIndex].vy = -1.4;
              effects[effectIndex].ay = 0.025;
              effects[effectIndex].field0084 = 1;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame < 12 &&
                (effects[effectIndex].vy += effects[effectIndex].ay,
                 !(effects[effectIndex].y + effects[effectIndex].vy <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xc;
            }
            else {
              if (effects[effectIndex].field0080 < 1) {
                if (effects[effectIndex].x > 620.0) {
                  effects[effectIndex].vx = 0.0;
                  effects[effectIndex].x = 620.0;
                }
                if (effects[effectIndex].x < 20.0) {
                  effects[effectIndex].vx = 0.0;
                  effects[effectIndex].x = 20.0;
                }
                ++effects[effectIndex].tick;
                if (effects[effectIndex].tick >= frameDuration) {
                  effects[effectIndex].tick = 0;
                  ++effects[effectIndex].frame;
                  effects[effectIndex].field0080 = 0;
                  if (effects[effectIndex].frame == 0xc) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
              else {
                effects[effectIndex].frame = 0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].type = 0x1a9;
              }
            }
          }
          break;
        case 0x196:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 2.0;
              effects[effectIndex].vy = -1.4;
              effects[effectIndex].ay = 0.025;
              effects[effectIndex].field0084 = 5;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame < 12 &&
                (effects[effectIndex].vy += effects[effectIndex].ay,
                 !(effects[effectIndex].y + effects[effectIndex].vy <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xc;
            }
            else {
              if (effects[effectIndex].field0080 < 1) {
                if (effects[effectIndex].x > 620.0) {
                  effects[effectIndex].vx = 0.0;
                  effects[effectIndex].x = 620.0;
                }
                if (effects[effectIndex].x < 20.0) {
                  effects[effectIndex].vx = 0.0;
                  effects[effectIndex].x = 20.0;
                }
                ++effects[effectIndex].tick;
                if (effects[effectIndex].tick >= frameDuration) {
                  effects[effectIndex].tick = 0;
                  ++effects[effectIndex].frame;
                  effects[effectIndex].field0080 = 0;
                  if (effects[effectIndex].frame == 0xc) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
              else {
                effects[effectIndex].frame = 0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].type = 0x1a9;
              }
            }
          }
          break;
        case 0x197:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0084 = 0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.2;
              effects[effectIndex].vy = -2.5;
              effects[effectIndex].ay = 0.035;
            }
            if (effects[effectIndex].frame == 9) {
              if (0.0 <= (*opponentSlot)->positionY) {
                effects[effectIndex].field0084 = 0;
              }
              else {
                effects[effectIndex].field0084 = 1;
              }
            }
            if ((effects[effectIndex].frame == 10) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].y < 0.0) &&
                (effects[effectIndex].frame < 0xf)) &&
               (effects[effectIndex].vy =
                     effects[effectIndex].vy +
                     effects[effectIndex].ay,
               0.0 <
               effects[effectIndex].y +
               effects[effectIndex].vy)) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xf;
            }
            if ((effects[effectIndex].frame == 0x12) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = -0.8;
              effects[effectIndex].vy = -1.0;
              effects[effectIndex].ay = 0.035;
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].y < 0.0) &&
                (effects[effectIndex].frame < 0x17)) &&
               ((0x12 < effects[effectIndex].frame &&
                (effects[effectIndex].vy =
                      effects[effectIndex].vy +
                      effects[effectIndex].ay,
                0.0 <
                effects[effectIndex].y +
                effects[effectIndex].vy)))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x17;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -1;
              }
              if (effects[effectIndex].frame == 0x17) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x198:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0084 = 0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.5;
              effects[effectIndex].vy = -2.5;
              effects[effectIndex].ay = 0.035;
            }
            if (effects[effectIndex].frame == 9) {
              if (0.0 <= (*opponentSlot)->positionY) {
                effects[effectIndex].field0084 = 0;
              }
              else {
                effects[effectIndex].field0084 = 1;
              }
            }
            if ((effects[effectIndex].frame == 10) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].y < 0.0) &&
                (effects[effectIndex].frame < 0xf)) &&
               (effects[effectIndex].vy =
                     effects[effectIndex].vy +
                     effects[effectIndex].ay,
               0.0 <
               effects[effectIndex].y +
               effects[effectIndex].vy)) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xf;
            }
            if ((effects[effectIndex].frame == 0x12) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = -0.8;
              effects[effectIndex].vy = -1.0;
              effects[effectIndex].ay = 0.035;
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].y < 0.0) &&
                (effects[effectIndex].frame < 0x17)) &&
               ((0x12 < effects[effectIndex].frame &&
                (effects[effectIndex].vy =
                      effects[effectIndex].vy +
                      effects[effectIndex].ay,
                0.0 <
                effects[effectIndex].y +
                effects[effectIndex].vy)))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x17;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -1;
              }
              if (effects[effectIndex].frame == 0x17) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x199:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0084 = 0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 1.3;
              effects[effectIndex].vy = -3.5;
              effects[effectIndex].ay = 0.045;
            }
            if (effects[effectIndex].frame == 9) {
              if (0.0 <= (*opponentSlot)->positionY) {
                effects[effectIndex].field0084 = 0;
              }
              else {
                effects[effectIndex].field0084 = 1;
              }
            }
            if ((effects[effectIndex].frame == 10) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].field0084 = 1;
            }
            if (((((effects[effectIndex].y < 0.0) &&
                  (effects[effectIndex].vx > 0.0)) &&
                 (effects[effectIndex].x -
                  (*opponentSlot)->positionX < 50.0)) &&
                ((-50.0 <
                  effects[effectIndex].x -
                  (*opponentSlot)->positionX &&
                 (effects[effectIndex].frame < 0x11)))) &&
               (effects[effectIndex].vx =
                     effects[effectIndex].vx - 0.02,
               effects[effectIndex].vx < 0.0)) {
              effects[effectIndex].vx = 0.0;
            }
            if (((effects[effectIndex].y < 0.0) &&
                (effects[effectIndex].frame < 0xf)) &&
               (effects[effectIndex].vy =
                     effects[effectIndex].vy +
                     effects[effectIndex].ay,
               0.0 <
               effects[effectIndex].y +
               effects[effectIndex].vy)) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xf;
              effects[effectIndex].field0080 = 0;
            }
            if ((effects[effectIndex].frame == 0x12) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = -1.0;
              effects[effectIndex].vy = -1.0;
              effects[effectIndex].ay = 0.035;
              effects[effectIndex].field0084 = 1;
            }
            if ((((effects[effectIndex].y < 0.0) &&
                 (effects[effectIndex].frame < 0x17)) &&
                (0x12 < effects[effectIndex].frame)) &&
               (effects[effectIndex].vy =
                     effects[effectIndex].vy +
                     effects[effectIndex].ay,
               0.0 <
               effects[effectIndex].y +
               effects[effectIndex].vy)) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x17;
              effects[effectIndex].field0080 = 0;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -1;
              }
              if (effects[effectIndex].frame == 0x17) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x19a:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              field3154[effectIndex] = 0;
              field3254[effectIndex] = 0;
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = -1.8;
              effects[effectIndex].ay = 0.055;
              effects[effectIndex].field0084 = 4;
              field3154[effectIndex] = field3154[effectIndex] + 1;
            }
            if ((effects[effectIndex].y < 0.0) &&
               (effects[effectIndex].frame < 0xf)) {
              effects[effectIndex].vy =
                   effects[effectIndex].vy +
                   effects[effectIndex].ay;
              if (effects[effectIndex].vy > 0.3) {
                effects[effectIndex].vy = 0.3;
              }
              if (0.0 <
                  effects[effectIndex].vy +
                  effects[effectIndex].y) {
                effects[effectIndex].y = 0.0;
                effects[effectIndex].vy = 0.0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 0xf;
                break;
              }
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x19b:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              field3154[effectIndex] = 0;
              field3254[effectIndex] = 0;
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = -2.8;
              effects[effectIndex].ay = 0.055;
              effects[effectIndex].field0084 = 6;
              field3154[effectIndex] = field3154[effectIndex] + 1;
            }
            if ((effects[effectIndex].y < 0.0) &&
               (effects[effectIndex].frame < 0xf)) {
              effects[effectIndex].vy =
                   effects[effectIndex].vy +
                   effects[effectIndex].ay;
              if (effects[effectIndex].vy > 0.3) {
                effects[effectIndex].vy = 0.3;
              }
              if (0.0 <
                  effects[effectIndex].vy +
                  effects[effectIndex].y) {
                effects[effectIndex].y = 0.0;
                effects[effectIndex].vy = 0.0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 0xf;
                break;
              }
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x19c:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              field3154[effectIndex] = 0;
              field3254[effectIndex] = 0;
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = -1.8;
              effects[effectIndex].ay = 0.055;
              effects[effectIndex].field0084 = 0xc;
              field3154[effectIndex] = field3154[effectIndex] + 1;
            }
            if ((effects[effectIndex].y < 0.0) &&
               (effects[effectIndex].frame < 0xf)) {
              effects[effectIndex].vy =
                   effects[effectIndex].vy +
                   effects[effectIndex].ay;
              if (effects[effectIndex].vy > 0.15) {
                effects[effectIndex].vy = 0.15;
              }
              if (0.0 <
                  effects[effectIndex].vy +
                  effects[effectIndex].y) {
                effects[effectIndex].y = 0.0;
                effects[effectIndex].vy = 0.0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 0xf;
                break;
              }
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x19d:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x10) {
            SetHorizontalShake(50,30);
          }
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 300) && (field0008 != 0x132)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 17 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x14;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 10) {
                  effects[effectIndex].field0084 = 99;
                  field3254[effectIndex] = 0;
                  field3154[effectIndex] = 0;
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + 4;
                }
                else {
                  if ((effects[effectIndex].frame == 0xe) &&
                     (field3254[effectIndex] < 2)) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3254[effectIndex] = field3254[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame == 0xf) {
                    effects[effectIndex].vx = 0.5;
                    effects[effectIndex].vy = -2.2;
                  }
                  if ((effects[effectIndex].frame == 0x10) &&
                     (field3154[effectIndex] < 2)) {
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -1;
                  }
                  if (effects[effectIndex].frame == 0x14) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x19e:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x14) {
            SetHorizontalShake(50,30);
          }
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x12d) && (field0008 != 0x133)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 17 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x17;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 10) {
                  effects[effectIndex].field0084 = 99;
                  field3254[effectIndex] = 0;
                  field3154[effectIndex] = 0;
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + 4;
                }
                else {
                  if ((effects[effectIndex].frame == 0xe) &&
                     (field3254[effectIndex] < 3)) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3254[effectIndex] = field3254[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame == 0xf) {
                    effects[effectIndex].vx = 0.5;
                    effects[effectIndex].vy = -2.6;
                  }
                  if ((effects[effectIndex].frame == 0x10) &&
                     (field3154[effectIndex] < 3)) {
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -1;
                  }
                  if (effects[effectIndex].frame == 0x17) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x19f:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x17) {
            SetHorizontalShake(50,30);
            contextOwner->SetSceneTimer(15);
          }
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x12e) && (field0008 != 0x134)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 17 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x1a;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 10) {
                  effects[effectIndex].field0084 = 99;
                  field3254[effectIndex] = 0;
                  field3154[effectIndex] = 0;
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + 4;
                }
                else {
                  if ((effects[effectIndex].frame == 0xe) &&
                     (field3254[effectIndex] < 3)) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3254[effectIndex] = field3254[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame == 0xf) {
                    effects[effectIndex].vx = 0.5;
                    effects[effectIndex].vy = -2.6;
                  }
                  if ((effects[effectIndex].frame == 0x10) &&
                     (field3154[effectIndex] < 4)) {
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -1;
                  }
                  if (effects[effectIndex].frame == 0x1a) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1a0:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              field3154[effectIndex] = 0;
            }
            if ((effects[effectIndex].frame == 4) &&
               (effects[effectIndex].tick == 0)) {
              spawn.type = 0x1f;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)iVar7;
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)iVar7;
              spawn.group = 0;
              spawn.layer = 1;
              spawn.facing = (unsigned int)((char)effects[effectIndex].flag0048 == '\x01');
              contextOwner->EmitEffect(&spawn);
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].frame == 5) &&
                (effects[effectIndex].field0080 == 3)) && (field3154[effectIndex] == 0)) {
              (*opponentSlot)->hitstopFrames = 0x2d;
              effects[effectIndex].field0086 = 0x2d;
              field3154[effectIndex] = 1;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x1a1:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else {
            if ((1 < effects[effectIndex].frame) &&
               (effects[effectIndex].frame < 6)) {
              if ((-50.0 <
                   effects[effectIndex].x -
                   (*opponentSlot)->positionX) &&
                 (effects[effectIndex].x -
                  (*opponentSlot)->positionX < 50.0)) {
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 6;
              }
              effects[effectIndex].vx = 2.2;
            }
            if (5 < effects[effectIndex].frame) {
              effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.1;
            }
            if (effects[effectIndex].vx < 0.0) {
              effects[effectIndex].vx = 0.0;
            }
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              field3154[effectIndex] = 0;
            }
            if ((effects[effectIndex].frame == 10) &&
               (effects[effectIndex].tick == 0)) {
              spawn.type = 0x1f;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)iVar7;
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)iVar7;
              spawn.group = 0;
              spawn.layer = 1;
              spawn.facing = (unsigned int)((char)effects[effectIndex].flag0048 == '\x01');
              contextOwner->EmitEffect(&spawn);
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].field0080 == 3)) && (field3154[effectIndex] == 0)) {
              (*opponentSlot)->hitstopFrames = 0x5a;
              effects[effectIndex].field0086 = 0x5a;
              field3154[effectIndex] = 1;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if ((effects[effectIndex].frame == 6) &&
                 (field3254[effectIndex] < 2)) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
                field3254[effectIndex] = field3254[effectIndex] + 1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
                field3154[effectIndex] = 0;
                field3254[effectIndex] = 0;
              }
            }
          }
          break;
        case 0x1a2:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x10) {
            SetHorizontalShake(50,30);
          }
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              field3154[effectIndex] = 0;
            }
            if ((effects[effectIndex].frame == 4) &&
               (effects[effectIndex].tick == 0)) {
              spawn.type = 0x1f;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)iVar7;
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)iVar7;
              spawn.group = 0;
              spawn.layer = 1;
              spawn.facing = (unsigned int)((char)effects[effectIndex].flag0048 == '\x01');
              contextOwner->EmitEffect(&spawn);
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].frame == 5) &&
                (effects[effectIndex].field0080 == 3)) && (field3154[effectIndex] == 0)) {
              (*opponentSlot)->hitstopFrames = 0x4b;
              effects[effectIndex].field0086 = 0x4b;
              field3154[effectIndex] = 1;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x1a3:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else {
            if ((1 < effects[effectIndex].frame) &&
               (effects[effectIndex].frame < 6)) {
              if ((-50.0 <
                   effects[effectIndex].x -
                   (*opponentSlot)->positionX) &&
                 (effects[effectIndex].x -
                  (*opponentSlot)->positionX < 50.0)) {
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 6;
              }
              effects[effectIndex].vx = 2.2;
            }
            if (5 < effects[effectIndex].frame) {
              effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.1;
            }
            if (effects[effectIndex].vx < 0.0) {
              effects[effectIndex].vx = 0.0;
            }
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              field3154[effectIndex] = 0;
            }
            if ((effects[effectIndex].frame == 10) &&
               (effects[effectIndex].tick == 0)) {
              spawn.type = 0x1f;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)iVar7;
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)iVar7;
              spawn.group = 0;
              spawn.layer = 1;
              spawn.facing = (unsigned int)((char)effects[effectIndex].flag0048 == '\x01');
              contextOwner->EmitEffect(&spawn);
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].field0080 == 3)) && (field3154[effectIndex] == 0)) {
              (*opponentSlot)->hitstopFrames = 0x96;
              effects[effectIndex].field0086 = 0x96;
              field3154[effectIndex] = 1;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if ((effects[effectIndex].frame == 6) &&
                 (field3254[effectIndex] < 4)) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
                field3254[effectIndex] = field3254[effectIndex] + 1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
                field3154[effectIndex] = 0;
                field3254[effectIndex] = 0;
              }
            }
          }
          break;
        case 0x1a4:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x10) {
            SetHorizontalShake(50,30);
          }
          contextOwner->SetSceneTimer(15);
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              field3154[effectIndex] = 0;
            }
            if ((effects[effectIndex].frame == 4) &&
               (effects[effectIndex].tick == 0)) {
              spawn.type = 0x1f;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)iVar7;
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)iVar7;
              spawn.group = 0;
              spawn.layer = 1;
              spawn.facing = (unsigned int)((char)effects[effectIndex].flag0048 == '\x01');
              contextOwner->EmitEffect(&spawn);
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].frame == 5) &&
                (effects[effectIndex].field0080 == 3)) && (field3154[effectIndex] == 0)) {
              (*opponentSlot)->hitstopFrames = 100;
              effects[effectIndex].field0086 = 100;
              field3154[effectIndex] = 1;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x1a5:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3154[effectIndex] = 0;
          }
          else {
            if ((1 < effects[effectIndex].frame) &&
               (effects[effectIndex].frame < 6)) {
              if ((-50.0 <
                   effects[effectIndex].x -
                   (*opponentSlot)->positionX) &&
                 (effects[effectIndex].x -
                  (*opponentSlot)->positionX < 50.0)) {
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 6;
              }
              effects[effectIndex].vx = 2.2;
            }
            if (5 < effects[effectIndex].frame) {
              effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.1;
            }
            if (effects[effectIndex].vx < 0.0) {
              effects[effectIndex].vx = 0.0;
            }
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              field3154[effectIndex] = 0;
            }
            if ((effects[effectIndex].frame == 10) &&
               (effects[effectIndex].tick == 0)) {
              spawn.type = 0x1f;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)iVar7;
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)iVar7;
              spawn.group = 0;
              spawn.layer = 1;
              spawn.facing = (unsigned int)((char)effects[effectIndex].flag0048 == '\x01');
              contextOwner->EmitEffect(&spawn);
              effects[effectIndex].field0084 = 1;
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].field0080 == 3)) && (field3154[effectIndex] == 0)) {
              (*opponentSlot)->hitstopFrames = 200;
              effects[effectIndex].field0086 = 200;
              field3154[effectIndex] = 1;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if ((effects[effectIndex].frame == 6) &&
                 (field3254[effectIndex] < 6)) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
                field3254[effectIndex] = field3254[effectIndex] + 1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
                field3154[effectIndex] = 0;
                field3254[effectIndex] = 0;
              }
            }
          }
          break;
        case 0x1a6:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.9;
              effects[effectIndex].vy = -1.1;
              effects[effectIndex].ay = 0.025;
              effects[effectIndex].field0084 = 1;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame < 12 &&
                (effects[effectIndex].vy += effects[effectIndex].ay,
                 !(effects[effectIndex].y + effects[effectIndex].vy <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xc;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 0xc) {
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + -2;
                }
                if (effects[effectIndex].frame >= frameCount) {
                  effects[effectIndex].type = 400;
                  effects[effectIndex].frame = 0;
                  field3148 = 0;
                }
              }
            }
          }
          break;
        case 0x1a7:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 1.5;
              effects[effectIndex].vy = -1.4;
              effects[effectIndex].ay = 0.025;
              effects[effectIndex].field0084 = 1;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame < 12 &&
                (effects[effectIndex].vy += effects[effectIndex].ay,
                 !(effects[effectIndex].y + effects[effectIndex].vy <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xc;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 0xc) {
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + -2;
                }
                if (effects[effectIndex].frame >= frameCount) {
                  effects[effectIndex].type = 400;
                  effects[effectIndex].frame = 0;
                  field3148 = 0;
                }
              }
            }
          }
          break;
        case 0x1a8:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 2.0;
              effects[effectIndex].vy = -1.4;
              effects[effectIndex].ay = 0.025;
              effects[effectIndex].field0084 = 5;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame < 12 &&
                (effects[effectIndex].vy += effects[effectIndex].ay,
                 !(effects[effectIndex].y + effects[effectIndex].vy <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0xc;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 0xc) {
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + -2;
                }
                if (effects[effectIndex].frame >= frameCount) {
                  effects[effectIndex].type = 400;
                  effects[effectIndex].frame = 0;
                  field3148 = 0;
                }
              }
            }
          }
          break;
        case 0x1a9:
          field3148 = 4;
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
            effects[effectIndex].vx =
                 -effects[effectIndex].vx * 0.5;
            effects[effectIndex].vy = -2.5;
            effects[effectIndex].ay = 0.025;
            field3154[effectIndex] = field3154[effectIndex] + 1;
          }
          if (((effects[effectIndex].y < 0.0) &&
              (effects[effectIndex].frame < 8)) &&
             (effects[effectIndex].vy =
                   effects[effectIndex].vy +
                   effects[effectIndex].ay,
             0.0 <
             effects[effectIndex].y +
             effects[effectIndex].vy)) {
            effects[effectIndex].y = 0.0;
            effects[effectIndex].vy = 0.0;
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].tick = 0;
            effects[effectIndex].frame = 8;
          }
          if (effects[effectIndex].x > 620.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 620.0;
          }
          if (effects[effectIndex].x < 20.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 20.0;
          }
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame == 8) {
              effects[effectIndex].frame =
                   effects[effectIndex].frame + -2;
            }
            if (effects[effectIndex].frame >= frameCount) {
              effects[effectIndex].type = 400;
              effects[effectIndex].frame = 0;
              field3148 = 0;
              field3154[effectIndex] = 0;
            }
          }
          break;
        case 0x1aa:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              field3154[effectIndex] = 0;
              field3254[effectIndex] = 0;
            }
            if (effects[effectIndex].y < 0.0) {
              if (positionX > effects[effectIndex].x) {
                effects[effectIndex].vx =
                     (double)(int)(char)effects[effectIndex].flag0048 * 0.5;
              }
              else {
                effects[effectIndex].vx =
                     (double)(int)(char)effects[effectIndex].flag0048 * -0.5;
              }
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = -1.8;
              effects[effectIndex].ay = 0.055;
              effects[effectIndex].field0084 = 4;
              field3154[effectIndex] = field3154[effectIndex] + 1;
            }
            if ((effects[effectIndex].y < 0.0) &&
               (effects[effectIndex].frame < 0xf)) {
              effects[effectIndex].vy =
                   effects[effectIndex].vy +
                   effects[effectIndex].ay;
              if (effects[effectIndex].vy > 0.3) {
                effects[effectIndex].vy = 0.3;
              }
              if (0.0 <
                  effects[effectIndex].vy +
                  effects[effectIndex].y) {
                effects[effectIndex].y = 0.0;
                effects[effectIndex].vy = 0.0;
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 0xf;
                break;
              }
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x1ab:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              field3154[effectIndex] = 0;
              field3254[effectIndex] = 0;
            }
            if (effects[effectIndex].y < 0.0) {
              if (positionX > effects[effectIndex].x) {
                effects[effectIndex].vx =
                     (double)(int)(char)effects[effectIndex].flag0048 * 0.5;
              }
              else {
                effects[effectIndex].vx =
                     (double)(int)(char)effects[effectIndex].flag0048 * -0.5;
              }
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = -2.8;
              effects[effectIndex].ay = 0.055;
              effects[effectIndex].field0084 = 6;
              field3154[effectIndex] = field3154[effectIndex] + 1;
            }
            if ((effects[effectIndex].y < 0.0) &&
               (effects[effectIndex].frame < 0xf)) {
              effects[effectIndex].vy =
                   effects[effectIndex].vy +
                   effects[effectIndex].ay;
              if (effects[effectIndex].vy > 0.3) {
                effects[effectIndex].vy = 0.3;
              }
              if (0.0 <
                  effects[effectIndex].vy +
                  effects[effectIndex].y) {
                effects[effectIndex].y = 0.0;
                effects[effectIndex].vy = 0.0;
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 0xf;
                break;
              }
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x1ac:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if ((effects[effectIndex].frame == 9) &&
               (effects[effectIndex].tick == 0)) {
              field3154[effectIndex] = 0;
              field3254[effectIndex] = 0;
            }
            if (effects[effectIndex].y < 0.0) {
              if (positionX > effects[effectIndex].x) {
                effects[effectIndex].vx =
                     (double)(int)(char)effects[effectIndex].flag0048 * 0.5;
              }
              else {
                effects[effectIndex].vx =
                     (double)(int)(char)effects[effectIndex].flag0048 * -0.5;
              }
            }
            if (((effects[effectIndex].frame == 0xb) &&
                (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = -1.8;
              effects[effectIndex].ay = 0.055;
              effects[effectIndex].field0084 = 0xc;
              field3154[effectIndex] = field3154[effectIndex] + 1;
            }
            if ((effects[effectIndex].y < 0.0) &&
               (effects[effectIndex].frame < 0xf)) {
              effects[effectIndex].vy =
                   effects[effectIndex].vy +
                   effects[effectIndex].ay;
              if (effects[effectIndex].vy > 0.15) {
                effects[effectIndex].vy = 0.15;
              }
              if (0.0 <
                  effects[effectIndex].vy +
                  effects[effectIndex].y) {
                effects[effectIndex].y = 0.0;
                effects[effectIndex].vy = 0.0;
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].frame = 0xf;
                break;
              }
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0xf) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                field3148 = 0;
              }
            }
          }
          break;
        case 0x1ad:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 1;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx = 1.7;
          }
          if ((effects[effectIndex].vx > 0.8) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.035,
             effects[effectIndex].vx < 0.8)) {
            effects[effectIndex].vx = 0.8;
          }
          if (((0 < effects[effectIndex].field0080) && (field3154[effectIndex] == 0)) &&
             ((char)effects[effectIndex].group == '\0')) {
            effects[effectIndex].group = 1;
            field3154[effectIndex] = 0x1e;
          }
          if (((char)effects[effectIndex].group == '\x01') &&
             (--field3154[effectIndex] < 0
             )) {
            RemoveLocalEffect((short)effectIndex);
            field314c = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
                if (field3354[effectIndex] < 1) {
                  field3354[effectIndex] = field3354[effectIndex] + 1;
                }
                else {
                  RemoveLocalEffect((short)effectIndex);
                  field314c = 0;
                }
              }
            }
          }
          break;
        case 0x1ae:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 1;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx = 2.1;
          }
          if ((effects[effectIndex].vx > 0.8) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.035,
             effects[effectIndex].vx < 0.8)) {
            effects[effectIndex].vx = 0.8;
          }
          if (((0 < effects[effectIndex].field0080) && (field3154[effectIndex] == 0)) &&
             ((char)effects[effectIndex].group == '\0')) {
            effects[effectIndex].group = 1;
            field3154[effectIndex] = 0x1e;
          }
          if (((char)effects[effectIndex].group == '\x01') &&
             (--field3154[effectIndex] < 0
             )) {
            RemoveLocalEffect((short)effectIndex);
            field314c = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
                if (field3354[effectIndex] < 2) {
                  field3354[effectIndex] = field3354[effectIndex] + 1;
                }
                else {
                  RemoveLocalEffect((short)effectIndex);
                  field314c = 0;
                }
              }
            }
          }
          break;
        case 0x1af:
          field3150 = (int)(effects[effectIndex].x);
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 2;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx = 2.0;
          }
          if ((effects[effectIndex].vx > 0.8) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.035,
             effects[effectIndex].vx < 0.6)) {
            effects[effectIndex].vx = 0.6;
          }
          if ((((short)effects[effectIndex].field0084 == 0) && (field3154[effectIndex] == 0)) &&
             ((char)effects[effectIndex].group == '\0')) {
            field314c = 2;
            effects[effectIndex].group = 1;
            field3154[effectIndex] = 0x1e;
          }
          if (((char)effects[effectIndex].group == '\x01') &&
             (--field3154[effectIndex] < 0
             )) {
            RemoveLocalEffect((short)effectIndex);
            field314c = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              if ((effects[effectIndex].frame == 6) ||
                 (effects[effectIndex].frame == 0xc)) {
                effects[effectIndex].field0080 = 0;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
                if (field3354[effectIndex] < 3) {
                  field3354[effectIndex] = field3354[effectIndex] + 1;
                }
                else {
                  RemoveLocalEffect((short)effectIndex);
                  field314c = 0;
                }
              }
            }
          }
          break;
        case 0x1b0:
          effects[effectIndex].x = (double)field3150;
          if (((field314c == 2) || (field314c == 0)) &&
             (effects[effectIndex].frame < 0x18)) {
            effects[effectIndex].frame = 0x18;
            effects[effectIndex].tick = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame == 0x18) {
                effects[effectIndex].frame = 0;
              }
              if (effects[effectIndex].frame >= frameCount) {
                RemoveLocalEffect((short)effectIndex);
              }
            }
          }
          break;
        case 0x1b4:
          field3148 = 2;
          effects[effectIndex].field0084 = 0;
          if (effects[effectIndex].frame < 10) {
            effects[effectIndex].vx = 1.5;
          }
          effects[effectIndex].vy = 0.0;
          if (effects[effectIndex].x > 620.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 620.0;
          }
          if (effects[effectIndex].x < 20.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 20.0;
          }
          if ((9 < effects[effectIndex].frame) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.035,
             effects[effectIndex].vx < 0.0)) {
            effects[effectIndex].vx = 0.0;
          }
          if ((field0008 == 0xfa) && (field000a == 0)) {
            effects[effectIndex].tick = 0;
            effects[effectIndex].frame = 0;
            effects[effectIndex].type = 400;
          }
          else if (((field0008 == 0xfd) && (field000a == 2)) ||
                  ((field0008 == 0x109 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x194;
            effects[effectIndex].frame = 8;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0xfe) && (field000a == 2)) ||
                  ((field0008 == 0x10a && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x195;
            effects[effectIndex].frame = 8;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0xff) && (field000a == 2)) ||
                  ((field0008 == 0x10b && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x196;
            effects[effectIndex].frame = 8;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x100) && (field000a == 2)) ||
                  ((field0008 == 0x10d && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x197;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x101) && (field000a == 2)) ||
                  ((field0008 == 0x10e && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x198;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x102) && (field000a == 2)) ||
                  ((field0008 == 0x10f && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x199;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x103) && (field000a == 2)) ||
                  ((field0008 == 0x110 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x19a;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x104) && (field000a == 2)) ||
                  ((field0008 == 0x111 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x19b;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x105) && (field000a == 2)) ||
                  ((field0008 == 0x112 && (field000a == 3)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x19c;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 300) && (field000a == 2)) ||
                  ((field0008 == 0x132 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c6;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x12d) && (field000a == 2)) ||
                  ((field0008 == 0x133 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c7;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x12e) && (field000a == 2)) ||
                  ((field0008 == 0x134 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c8;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x12f) && (field000a == 2)) ||
                  ((field0008 == 0x135 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1a0;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x130) && (field000a == 2)) ||
                  ((field0008 == 0x136 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1a2;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x131) && (field000a == 2)) ||
                  ((field0008 == 0x137 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1a4;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((((field0008 == 0x138) || (field0008 == 0x139)) ||
                   (field0008 == 0x13a)) && (field000a == 2)) {
            field3148 = 4;
            effects[effectIndex].type = 0x1b5;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if ((field0008 == 0x13b) && (field000a == 3)) {
            field3148 = 4;
            effects[effectIndex].type = 0x1be;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x13c) && (field000a == 2)) ||
                  ((field0008 == 0x13f && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c6;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x13d) && (field000a == 2)) ||
                  ((field0008 == 0x140 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c7;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (((field0008 == 0x13e) && (field000a == 2)) ||
                  ((field0008 == 0x141 && (field000a == 1)))) {
            field3148 = 4;
            effects[effectIndex].type = 0x1c8;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else if (field3154[effectIndex] == 0) {
            field3154[effectIndex] = 1;
            if (field0008 == 0xfb) {
              effects[effectIndex].flag0048 = 1;
            }
            if (field0008 == 0xfc) {
              effects[effectIndex].flag0048 = 0xff;
            }
          }
          else if (field0008 == 0xfa) {
            field3148 = 1;
            effects[effectIndex].type = 0x191;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if ((effects[effectIndex].frame == 10) &&
                 (((effects[effectIndex].x < positionX &&
                   (effects[effectIndex].x - positionX <
                    -200.0)) ||
                  ((positionX < effects[effectIndex].x &&
                   (200.0 <
                    effects[effectIndex].x - positionX)))))) {
                effects[effectIndex].frame = 0;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
                effects[effectIndex].tick = 0;
                effects[effectIndex].type = 400;
                field3154[effectIndex] = 0;
              }
            }
          }
          break;
        case 0x1b5:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if (((field0008 != 0x138) && (field0008 != 0x139)) &&
               (field0008 != 0x13a)) {
              effects[effectIndex].field0088 = 0;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            if (((3 < effects[effectIndex].frame) &&
                (effects[effectIndex].frame < 8)) &&
               (--field3354[effectIndex] < 1)) {
              spawn.type = 0x1bb;
              iVar7 = (int)(effects[effectIndex].x);
              spawn.x = (double)(iVar7 + (char)effects[effectIndex].flag0048 * 0x17);
              iVar7 = (int)(effects[effectIndex].y);
              spawn.y = (double)(iVar7 + -0x21);
              spawn.group = 2;
              spawn.flag0018 = (unsigned char)effects[effectIndex].flag0048;
              spawn.layer = 1;
              EmitLocalEffect(&spawn);
              field3354[effectIndex] = 0x15;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if ((effects[effectIndex].frame == 8) &&
                 (field3254[effectIndex] <
                  (int)((unsigned int)(field0008 == 0x139) * 3 + 5 +
                       (unsigned int)(field0008 == 0x13a) * 6))) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -4;
                field3254[effectIndex] = field3254[effectIndex] + 1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                effects[effectIndex].tick = 0;
                field3148 = 0;
                field3254[effectIndex] = 0;
                effects[effectIndex].field0088 = 0;
              }
            }
          }
          break;
        case 0x1b8:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 1;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 1.2;
            effects[effectIndex].vy =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 0.0;
          }
          if ((effects[effectIndex].vx > 0.8) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.015,
             effects[effectIndex].vx < 0.8)) {
            effects[effectIndex].vx = 0.8;
          }
          effects[effectIndex].vy =
               effects[effectIndex].vy - 0.015;
          if ((0 < effects[effectIndex].field0080) &&
             (effects[effectIndex].frame < 0x18)) {
            effects[effectIndex].tick = 0;
            effects[effectIndex].frame = 0x18;
          }
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1b9:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 1;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 1.6;
            effects[effectIndex].vy =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 0.0;
          }
          if ((effects[effectIndex].vx > 0.8) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.015,
             effects[effectIndex].vx < 0.8)) {
            effects[effectIndex].vx = 0.8;
          }
          effects[effectIndex].vy =
               effects[effectIndex].vy - 0.015;
          if ((0 < effects[effectIndex].field0080) &&
             (effects[effectIndex].frame < 0x18)) {
            effects[effectIndex].tick = 0;
            effects[effectIndex].frame = 0x18;
          }
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1ba:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 1;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 2.0;
            effects[effectIndex].vy =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 0.0;
          }
          if ((effects[effectIndex].vx > 0.8) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.015,
             effects[effectIndex].vx < 0.8)) {
            effects[effectIndex].vx = 0.8;
          }
          effects[effectIndex].vy =
               effects[effectIndex].vy - 0.015;
          if ((0 < effects[effectIndex].field0080) &&
             (effects[effectIndex].frame < 0x18)) {
            effects[effectIndex].tick = 0;
            effects[effectIndex].frame = 0x18;
          }
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1bb:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 1;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 0.5;
            effects[effectIndex].vy =
                 (double)(unsigned short)RandomRange(0,10) * 0.1 + 0.0;
          }
          if ((effects[effectIndex].vx > 0.8) &&
             (effects[effectIndex].vx =
                   effects[effectIndex].vx - 0.015,
             effects[effectIndex].vx < 0.0)) {
            effects[effectIndex].vx = 0.0;
          }
          effects[effectIndex].vy =
               effects[effectIndex].vy - 0.015;
          if ((0 < effects[effectIndex].field0080) &&
             (effects[effectIndex].frame < 0x18)) {
            effects[effectIndex].tick = 0;
            effects[effectIndex].frame = 0x18;
          }
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1be:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
            field3254[effectIndex] = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
              pendingCharacterSoundSlot = 2;
            }
            if (field0008 != 0x13b) {
              effects[effectIndex].field0088 = 0;
            }
            if (effects[effectIndex].x > 620.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 620.0;
            }
            if (effects[effectIndex].x < 20.0) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].x = 20.0;
            }
            if (((9 < effects[effectIndex].frame) &&
                (effects[effectIndex].frame < 0x16)) &&
               (--field3354[effectIndex] < 1)) {
              spawn.type = 0x1bf;
              spawn.owner = 1;
              spawn.x = ((positionX - (double)(unsigned short)RandomRange(0,0x1e0)) + 240.0) -
                         (double)((char)effects[effectIndex].flag0048 * 0x78);
              spawn.y = -480.0;
              spawn.group = 2;
              spawn.flag0018 = (unsigned char)effects[effectIndex].flag0048;
              spawn.layer = 1;
              EmitLocalEffect(&spawn);
              field3354[effectIndex] = 0x12;
            }
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if ((effects[effectIndex].frame == 0x16) &&
                 (field3254[effectIndex] < 0x11)) {
                effects[effectIndex].frame =
                     effects[effectIndex].frame + -6;
                field3254[effectIndex] = field3254[effectIndex] + 1;
              }
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].type = 400;
                effects[effectIndex].frame = 0;
                effects[effectIndex].tick = 0;
                field3148 = 0;
                field3254[effectIndex] = 0;
                effects[effectIndex].field0088 = 0;
              }
            }
          }
          break;
        case 0x1bf:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3254[effectIndex] == 0)) {
            effects[effectIndex].field0084 = 1;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            effects[effectIndex].vx = 1.5;
            effects[effectIndex].vy = 3.0;
          }
          field3354[effectIndex] = field3354[effectIndex] + -1;
          if (field3354[effectIndex] < 1) {
            spawn.type = (short)field3254[effectIndex] + 0x1c0;
            spawn.x = effects[effectIndex].x;
            spawn.y = effects[effectIndex].y;
            spawn.group = 2;
            spawn.flag0018 = (unsigned char)effects[effectIndex].flag0048;
            spawn.layer = 0;
            EmitLocalEffect(&spawn);
            field3354[effectIndex] = 6;
            field3254[effectIndex] = field3254[effectIndex] + 1;
            if (4 < field3254[effectIndex]) {
              field3254[effectIndex] = 0;
            }
          }
          if (effects[effectIndex].y <= 200.0) {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
              }
            }
          }
          else {
            RemoveLocalEffect((short)effectIndex);
          }
          break;
        case 0x1c0:
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1c1:
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1c2:
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1c3:
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1c4:
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1c5:
          if (effects[effectIndex].frame == 0) {
            effects[effectIndex].vy = 3.0;
            (*opponentSlot)->positionX =
                 effects[effectIndex].x;
            (*opponentSlot)->positionY =
                 effects[effectIndex].y;
          }
          if ((effects[effectIndex].frame == 0) &&
             (0.0 <
              effects[effectIndex].y +
              effects[effectIndex].vy)) {
            effects[effectIndex].tick = 0;
            effects[effectIndex].frame = 1;
            (*opponentSlot)->ResetPose();
            *(unsigned short *)(*(int *)opponentSlot + 8) = 0x62;
            (*opponentSlot)->positionY = 0.0;
            (*opponentSlot)->positionX =
                 effects[effectIndex].x;
            ApplyDamage(1200,500.0);
            effects[effectIndex].vy = 0.0;
          }
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            if (effects[effectIndex].frame == 3) {
              effects[effectIndex].group = 1;
            }
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1c6:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 300) && (field0008 != 0x132)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame > 3 &&
effects[effectIndex].frame < 8 &&
                (effects[effectIndex].vy += 0.0035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 8;
              pendingContextSoundSlot = 7;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                if ((3 < effects[effectIndex].frame) &&
                   (effects[effectIndex].frame < 9)) {
                  spawn.type = 0x1cf;
                  uVar6 = RandomRange(0,0x1e);

                  spawn.x = (double)(int)((uVar6 & 0xffff) *
                                          (int)(char)effects[effectIndex].flag0048) +
                             effects[effectIndex].x;
                  frameDuration = RandomRange(0,0x50);
                  spawn.y = ((effects[effectIndex].y - (double)frameDuration) +
                             40.0) - 30.0;
                  spawn.flag0018 = (unsigned char)effects[effectIndex].flag0048;
                  spawn.layer = 1;
                  spawn.group = 2;
                  EmitLocalEffect(&spawn);
                }
                if (((effects[effectIndex].frame == 1) ||
                    (effects[effectIndex].frame == 5)) ||
                   (effects[effectIndex].frame == 7)) {
                  effects[effectIndex].field0080 = 0;
                }
                if (effects[effectIndex].frame == 4) {
                  effects[effectIndex].field0084 = 99;
                  effects[effectIndex].vx = 0.5;
                  effects[effectIndex].vy = -0.5;
                }
                else {
                  if (effects[effectIndex].frame == 8) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                    field3154[effectIndex] = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1c7:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x12d) && (field0008 != 0x133)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame > 3 &&
effects[effectIndex].frame < 8 &&
                (effects[effectIndex].vy += 0.0035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 8;
              pendingContextSoundSlot = 7;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                if ((3 < effects[effectIndex].frame) &&
                   (effects[effectIndex].frame < 9)) {
                  spawn.type = (0x32 < (unsigned short)RandomRange(0,100)) + 0x1cf;
                  spawn.x = (double)(int)(((unsigned short)RandomRange(0,0x28) & 0xffff) *
                                          (int)(char)effects[effectIndex].flag0048) +
                             effects[effectIndex].x;
                  frameDuration = RandomRange(0,0x78);
                  spawn.y = ((effects[effectIndex].y - (double)frameDuration) +
                             60.0) - 30.0;
                  spawn.flag0018 = (unsigned char)effects[effectIndex].flag0048;
                  spawn.layer = 1;
                  spawn.group = 2;
                  EmitLocalEffect(&spawn);
                }
                if (((effects[effectIndex].frame == 1) ||
                    (effects[effectIndex].frame == 5)) ||
                   (effects[effectIndex].frame == 7)) {
                  effects[effectIndex].field0080 = 0;
                }
                if (effects[effectIndex].frame == 4) {
                  effects[effectIndex].field0084 = 99;
                  effects[effectIndex].vx = 0.65;
                  effects[effectIndex].vy = -0.52;
                }
                else {
                  if (effects[effectIndex].frame == 8) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                    field3154[effectIndex] = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1c8:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x12e) && (field0008 != 0x134)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame > 3 &&
effects[effectIndex].frame < 8 &&
                (effects[effectIndex].vy += 0.003,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 8;
              pendingContextSoundSlot = 7;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                if ((3 < effects[effectIndex].frame) &&
                   (effects[effectIndex].frame < 9)) {
                  frameDuration = RandomRange(0,100);
                  uVar5 = RandomRange(0,100);

                  spawn.type = (0x46 < frameDuration) + 0x1cf + (unsigned short)(0x1e < uVar5);
                  uVar6 = RandomRange(0,0x28);

                  spawn.x = (double)(int)((uVar6 & 0xffff) *
                                          (int)(char)effects[effectIndex].flag0048) +
                             effects[effectIndex].x;
                  frameDuration = RandomRange(0,0x8c);
                  spawn.y = ((effects[effectIndex].y - (double)frameDuration) +
                             70.0) - 30.0;
                  spawn.flag0018 = (unsigned char)effects[effectIndex].flag0048;
                  spawn.layer = 1;
                  spawn.group = 2;
                  EmitLocalEffect(&spawn);
                }
                if (((effects[effectIndex].frame == 1) ||
                    (effects[effectIndex].frame == 5)) ||
                   (effects[effectIndex].frame == 7)) {
                  effects[effectIndex].field0080 = 0;
                }
                if (effects[effectIndex].frame == 4) {
                  effects[effectIndex].field0084 = 99;
                  effects[effectIndex].vx = 0.85;
                  effects[effectIndex].vy = -0.55;
                }
                else {
                  if (effects[effectIndex].frame == 8) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                    field3154[effectIndex] = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1c9:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x13c) && (field0008 != 0x13f)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 4 &&
effects[effectIndex].frame <= 7 &&
                (effects[effectIndex].vy += 0.025,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 8;
              pendingContextSoundSlot = 7;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                if (((effects[effectIndex].frame == 1) ||
                    (effects[effectIndex].frame == 5)) ||
                   (effects[effectIndex].frame == 7)) {
                  effects[effectIndex].field0080 = 0;
                }
                if (effects[effectIndex].frame == 4) {
                  effects[effectIndex].field0084 = 5;
                  effects[effectIndex].vx = 1.5;
                  effects[effectIndex].vy = -1.4;
                }
                else {
                  if (effects[effectIndex].frame == 8) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1ca:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x13d) && (field0008 != 0x140)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 4 &&
effects[effectIndex].frame <= 7 &&
                (effects[effectIndex].vy += 0.025,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 8;
              pendingContextSoundSlot = 7;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                if (((effects[effectIndex].frame == 1) ||
                    (effects[effectIndex].frame == 5)) ||
                   (effects[effectIndex].frame == 7)) {
                  effects[effectIndex].field0080 = 0;
                }
                if (effects[effectIndex].frame == 4) {
                  effects[effectIndex].field0084 = 8;
                  effects[effectIndex].vx = 1.8;
                  effects[effectIndex].vy = -1.4;
                }
                else {
                  if (effects[effectIndex].frame == 8) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1cb:
          field3148 = 4;
          contextOwner->SetSceneTimer(15);
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x13e) && (field0008 != 0x141)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 4 &&
effects[effectIndex].frame <= 7 &&
                (effects[effectIndex].vy += 0.025,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 8;
              pendingContextSoundSlot = 7;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                if (((effects[effectIndex].frame == 1) ||
                    (effects[effectIndex].frame == 5)) ||
                   (effects[effectIndex].frame == 7)) {
                  effects[effectIndex].field0080 = 0;
                }
                if (effects[effectIndex].frame == 4) {
                  effects[effectIndex].field0084 = 0xc;
                  effects[effectIndex].vx = 2.1;
                  effects[effectIndex].vy = -1.4;
                }
                else {
                  if (effects[effectIndex].frame == 8) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1cc:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x10) {
            SetHorizontalShake(50,30);
          }
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 300) && (field0008 != 0x132)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 17 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x14;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 10) {
                  effects[effectIndex].field0084 = 99;
                  field3254[effectIndex] = 0;
                  field3154[effectIndex] = 0;
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + 4;
                }
                else {
                  if ((effects[effectIndex].frame == 0xe) &&
                     (field3254[effectIndex] < 2)) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3254[effectIndex] = field3254[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame == 0xf) {
                    effects[effectIndex].vx = 0.5;
                    effects[effectIndex].vy = -2.2;
                  }
                  if ((effects[effectIndex].frame == 0x10) &&
                     (field3154[effectIndex] < 2)) {
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -1;
                  }
                  if (effects[effectIndex].frame == 0x14) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1cd:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x14) {
            SetHorizontalShake(50,30);
          }
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x12d) && (field0008 != 0x133)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 17 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x17;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 10) {
                  effects[effectIndex].field0084 = 99;
                  field3254[effectIndex] = 0;
                  field3154[effectIndex] = 0;
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + 4;
                }
                else {
                  if ((effects[effectIndex].frame == 0xe) &&
                     (field3254[effectIndex] < 3)) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3254[effectIndex] = field3254[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame == 0xf) {
                    effects[effectIndex].vx = 0.5;
                    effects[effectIndex].vy = -2.6;
                  }
                  if ((effects[effectIndex].frame == 0x10) &&
                     (field3154[effectIndex] < 3)) {
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -1;
                  }
                  if (effects[effectIndex].frame == 0x17) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1ce:
          field3148 = 4;
          if (effects[effectIndex].frame < 0x17) {
            SetHorizontalShake(50,30);
            contextOwner->SetSceneTimer(15);
          }
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].field0088 = 1;
            }
            if ((field0008 != 0x12e) && (field0008 != 0x134)) {
              effects[effectIndex].field0088 = 0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 17 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0))) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x1a;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 10) {
                  effects[effectIndex].field0084 = 99;
                  field3254[effectIndex] = 0;
                  field3154[effectIndex] = 0;
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + 4;
                }
                else {
                  if ((effects[effectIndex].frame == 0xe) &&
                     (field3254[effectIndex] < 3)) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -4;
                    field3254[effectIndex] = field3254[effectIndex] + 1;
                  }
                  if (effects[effectIndex].frame == 0xf) {
                    effects[effectIndex].vx = 0.5;
                    effects[effectIndex].vy = -2.6;
                  }
                  if ((effects[effectIndex].frame == 0x10) &&
                     (field3154[effectIndex] < 4)) {
                    field3154[effectIndex] = field3154[effectIndex] + 1;
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -1;
                  }
                  if (effects[effectIndex].frame == 0x1a) {
                    effects[effectIndex].frame =
                         effects[effectIndex].frame + -2;
                  }
                  if (effects[effectIndex].frame >= frameCount) {
                    effects[effectIndex].type = 400;
                    effects[effectIndex].frame = 0;
                    field3148 = 0;
                  }
                }
              }
            }
          }
          break;
        case 0x1cf:
          effects[effectIndex].vx = 2.0;
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1d0:
          effects[effectIndex].vx = 2.5;
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1d1:
          effects[effectIndex].vx = 3.0;
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
          break;
        case 0x1d2:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 12 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0)) &&
                effects[effectIndex].frame <= 0xf) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x10;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 0xb) {
                  effects[effectIndex].field0084 = 99;
                  effects[effectIndex].vx = 0.5;
                  effects[effectIndex].vy = -2.0;
                }
                if (effects[effectIndex].frame == 0x10) {
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + -2;
                }
                if (effects[effectIndex].frame >= frameCount) {
                  effects[effectIndex].type = 400;
                  effects[effectIndex].frame = 0;
                  field3148 = 0;
                }
              }
            }
          }
          break;
        case 0x1d3:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 12 &&
                (effects[effectIndex].vy += 0.035,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0)) &&
                effects[effectIndex].frame <= 0xf) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x10;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 0xb) {
                  effects[effectIndex].field0084 = 99;
                  effects[effectIndex].vx = 0.5;
                  effects[effectIndex].vy = -2.0;
                }
                if (effects[effectIndex].frame == 0x10) {
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + -2;
                }
                if (effects[effectIndex].frame >= frameCount) {
                  effects[effectIndex].type = 400;
                  effects[effectIndex].frame = 0;
                  field3148 = 0;
                }
              }
            }
          }
          break;
        case 0x1d4:
          field3148 = 4;
          if ((effects[effectIndex].field0080 == 4) || (effects[effectIndex].field0080 == 5)) {
            effects[effectIndex].type = 0x193;
            effects[effectIndex].frame = 0;
            effects[effectIndex].tick = 0;
          }
          else {
            if ((effects[effectIndex].frame == 0) &&
               (effects[effectIndex].tick == 0)) {
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].vy = 0.0;
            }
            if (!(0.0 <= effects[effectIndex].y) &&
                effects[effectIndex].frame >= 12 &&
                (effects[effectIndex].vy += 0.025,
                 !(effects[effectIndex].vy + effects[effectIndex].y <= 0.0)) &&
                effects[effectIndex].frame <= 0x15) {
              effects[effectIndex].y = 0.0;
              effects[effectIndex].vy = 0.0;
              effects[effectIndex].vx = 0.0;
              effects[effectIndex].tick = 0;
              effects[effectIndex].frame = 0x16;
            }
            else {
              if (effects[effectIndex].x > 620.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 620.0;
              }
              if (effects[effectIndex].x < 20.0) {
                effects[effectIndex].vx = 0.0;
                effects[effectIndex].x = 20.0;
              }
              ++effects[effectIndex].tick;
              if (effects[effectIndex].tick >= frameDuration) {
                effects[effectIndex].tick = 0;
                ++effects[effectIndex].frame;
                effects[effectIndex].field0080 = 0;
                if (effects[effectIndex].frame == 0xb) {
                  effects[effectIndex].field0084 = 99;
                  effects[effectIndex].vx = 0.5;
                  effects[effectIndex].vy = -2.0;
                }
                if ((effects[effectIndex].frame == 0xc) &&
                   (field3154[effectIndex] < 3)) {
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + -1;
                  field3154[effectIndex] = field3154[effectIndex] + 1;
                }
                if (effects[effectIndex].frame == 0x16) {
                  effects[effectIndex].frame =
                       effects[effectIndex].frame + -2;
                }
                if (effects[effectIndex].frame >= frameCount) {
                  effects[effectIndex].type = 400;
                  effects[effectIndex].frame = 0;
                  field3148 = 0;
                }
              }
            }
          }
          break;
        case 0x1d5:
          field3148 = 4;
          effects[effectIndex].field0088 = 0;
          field3154[effectIndex] = 0;
          field3254[effectIndex] = 0;
          field3354[effectIndex] = 0;
          if ((effects[effectIndex].frame == 0xb) &&
             (effects[effectIndex].tick == 0)) {
            effects[effectIndex].x =
                 (double)((char)facing * 0x3c) + positionX;
          }
          if (effects[effectIndex].x > 620.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 620.0;
          }
          if (effects[effectIndex].x < 20.0) {
            effects[effectIndex].vx = 0.0;
            effects[effectIndex].x = 20.0;
          }
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              effects[effectIndex].type = 400;
              effects[effectIndex].frame = 0;
              field3148 = 0;
            }
          }
          break;
        case 0x1ef:
          effects[effectIndex].vx = -0.02;
          effects[effectIndex].field008c = 30000;
          ++effects[effectIndex].tick;
          if (field0008 != 0x57) {
            RemoveLocalEffect((short)effectIndex);
          }
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              effects[effectIndex].frame = 0;
            }
          }
          break;
        case 0x1f0:
          if (!((((((field0008 == 0x53) || (field0008 == 0x54)) ||
                (field0008 == 0x55)) || (field0008 == 0x56)) &&
              ((field0008 != 0x53 || (field000a <= 1)))) &&
             ((field0008 != 0x54 || (field000a <= 1))))) {
            spawn.type = 0x1f1;
            spawn.x = (double)((int)(positionX) + (char)facing * 0x17);
            spawn.y = (double)((int)(positionY) + -4);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            spawn.x = (double)((int)(positionX) + (char)facing * -4);
            spawn.y = (double)((int)(positionY) + -6);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            spawn.x = (double)((int)(positionX) + (char)facing * -0xe);
            spawn.y = (double)((int)(positionY) + -0x1a);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            spawn.x = (double)(int)(positionX);
            spawn.y = (double)(int)(positionY);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            spawn.x = (double)((int)(positionX) + (char)facing * 0x1e);
            spawn.y = (double)((int)(positionY) + -0x28);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f1;
            spawn.x = (double)((int)(positionX) + (char)facing * -0x19);
            spawn.y = (double)((int)(positionY) + -0x50);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            spawn.x = (double)((int)(positionX) + (char)facing * -0x23);
            spawn.y = (double)((int)(positionY) + -0x2a);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            spawn.x = (double)((int)(positionX) + (char)facing * -0x12);
            spawn.y = (double)((int)(positionY) + -0x14);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            spawn.x = (double)((int)(positionX) + (char)facing * 2);
            spawn.y = (double)((int)(positionY) + -0x41);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            spawn.type = 0x1f2;
            spawn.x = (double)((int)(positionX) + (char)facing * 0x10);
            spawn.y = (double)((int)(positionY) + -0x50);
            spawn.group = 0;
            spawn.layer = 1;
            spawn.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&spawn);
            pendingContextSoundSlot = 0x22;
            RemoveLocalEffect((short)effectIndex);
            field3144 = 0;
          }
          else {
            ++effects[effectIndex].tick;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
              }
            }
          }
          break;
        case 0x1f1:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
            iVar7 = std::rand();
            iVar8 = std::rand();
            field3254[effectIndex] =
                 (unsigned int)(16000 < iVar7) * 0x28 + 0x50 + (unsigned int)(16000 < iVar8) * 0x14;
            field3154[effectIndex] = field3154[effectIndex] + 1;
            dVar1 = (double)(16000 < std::rand()) * 1.2;
            dVar2 = (double)(16000 < std::rand()) * 0.7;
            effects[effectIndex].vx =
                 (double)(16000 < std::rand()) * 1.7 + dVar2 + dVar1 + -1.8;
            dVar1 = (double)(16000 < std::rand()) * 0.6;
            dVar2 = (double)(16000 < std::rand()) * 0.9;
            effects[effectIndex].vy =
                 -1.2 - ((double)(16000 < std::rand()) * 1.4 + dVar2 + dVar1);
          }
          effects[effectIndex].vy =
               effects[effectIndex].vy + 0.05;
          if ((effects[effectIndex].y > 0.0) &&
             (effects[effectIndex].vy > 0.0)) {
            effects[effectIndex].vy =
                 -effects[effectIndex].vy;
          }
          if (field3254[effectIndex] < 10) {
            effects[effectIndex].group = 1;
          }
          if (field3254[effectIndex] < 0) {
            RemoveLocalEffect((short)effectIndex);
          }
          else {
            ++effects[effectIndex].tick;
            field3254[effectIndex] = field3254[effectIndex] + -1;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
              }
            }
          }
          break;
        case 0x1f2:
          if (((effects[effectIndex].frame == 0) &&
              (effects[effectIndex].tick == 0)) && (field3154[effectIndex] == 0)) {
            iVar7 = std::rand();
            iVar8 = std::rand();
            field3254[effectIndex] =
                 (unsigned int)(16000 < iVar7) * 0x3c + 0x78 + (unsigned int)(16000 < iVar8) * 0x28;
            field3154[effectIndex] = field3154[effectIndex] + 1;
            iVar7 = std::rand();
            iVar8 = std::rand();
            dVar1 = (double)(16000 < iVar8) * 0.5;
            effects[effectIndex].vx =
                 (double)(16000 < std::rand()) * 1.5 + dVar1 + (double)(16000 < iVar7) +
                 -1.5;
            dVar1 = (double)(16000 < std::rand()) * 0.5;
            dVar2 = (double)(16000 < std::rand()) * 0.8;
            effects[effectIndex].vy =
                 -1.0 - ((double)(16000 < std::rand()) * 1.2 + dVar2 + dVar1);
          }
          effects[effectIndex].vy =
               effects[effectIndex].vy + 0.03;
          if ((effects[effectIndex].y > 0.0) &&
             (effects[effectIndex].vy > 0.0)) {
            effects[effectIndex].vy =
                 -effects[effectIndex].vy;
          }
          if (field3254[effectIndex] < 10) {
            effects[effectIndex].group = 1;
          }
          if (field3254[effectIndex] < 0) {
            RemoveLocalEffect((short)effectIndex);
          }
          else {
            ++effects[effectIndex].tick;
            field3254[effectIndex] = field3254[effectIndex] + -1;
            if (effects[effectIndex].tick >= frameDuration) {
              effects[effectIndex].tick = 0;
              ++effects[effectIndex].frame;
              effects[effectIndex].field0080 = 0;
              if (effects[effectIndex].frame >= frameCount) {
                effects[effectIndex].frame = 0;
              }
            }
          }
          break;
        case 499:
          effects[effectIndex].x = positionX;
          effects[effectIndex].y = positionY;
          ++effects[effectIndex].tick;
          if (effects[effectIndex].tick >= frameDuration) {
            effects[effectIndex].tick = 0;
            ++effects[effectIndex].frame;
            effects[effectIndex].field0080 = 0;
            if (effects[effectIndex].frame >= frameCount) {
              RemoveLocalEffect((short)effectIndex);
            }
          }
        }
      }
      ++effectIndex;
      if (effectIndex >= 64) {
        effectIndex = 0;
      }
    }
  return;
}
