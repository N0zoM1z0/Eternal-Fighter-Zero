// Mishio complete local-effect update and lifetime dispatch.
#include "CharacterViews.h"
#include <cstdlib>

void Character15::Slot07()
{
    int i;
    if ((*opponentSlot)->hitstunFrames > 0) return;
    i = (int)effectRead;
    // This reused descriptor supplies every local emission.
    EffectSpawn spawn;
    while (i != effectWrite) {
        if (((effectActive[i] != 0) &&
            (effects[i].field0086 == 0)) &&
            ((hitstunFrames == 0 ||
            ((0 < hitstunFrames && (effects[i].field0088 != 0)))))) {
            unsigned short frameDuration = patterns[effects[i].type].frames[effects[i].frame].duration;
            unsigned short frameCount = patterns[effects[i].type].count;
            ResetLocalEffectSpawn(&spawn);
            switch(effects[i].type) {
            case 400:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].vx = 2.5;
                }
                if (effects[i].field0080 > 0 && effects[i].frame < 49) {
                    effects[i].frame = 0x31;
                    effects[i].tick = 0;
                    field3148 = 0;
                    break;
                }
                if ((0x31 < effects[i].frame) &&
                    (effects[i].vx =
                    effects[i].vx - 0.06,
                    effects[i].vx < 0.3)) {
                    effects[i].vx = 0.3;
                }
                if ((effects[i].x > 700.0) ||
                    (effects[i].x < -60.0)) {
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 0x31) &&
                        (field3174[i] < 5)) {
                        effects[i].frame = 0x1d;
                        ++field3174[i];
                    }
                    if (effects[i].frame == 0x31) {
                        field3148 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x191:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 3;
                    ++field3174[i];
                    effects[i].vx = 1.2;
                }
                if ((0x31 < effects[i].frame) &&
                    (effects[i].vx =
                    effects[i].vx - 0.02,
                    effects[i].vx < 0.3)) {
                    effects[i].vx = 0.3;
                }
                if (((0 < effects[i].field0080) &&
                    (effects[i].frame < 0x31)) &&
                    (field3274[i] = field3274[i] + 1,
                    effects[i].field0084 == 0)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x31;
                    field3148 = 0;
                }
                if ((effects[i].x > 700.0) ||
                    (effects[i].x < -60.0)) {
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (0x1e < field3274[i]) {
                        effects[i].field0080 = 0;
                        field3274[i] = 0;
                    }
                    if ((effects[i].frame == 0x31) &&
                        (field3174[i] < 7)) {
                        effects[i].frame = 0x1d;
                        ++field3174[i];
                    }
                    if (effects[i].frame == 0x31) {
                        field3148 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x192:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 99;
                    ++field3174[i];
                    effects[i].vx = 0.0;
                }
                effects[i].vx =
                effects[i].vx + 0.0025;
                if (0 < effects[i].field0080) {
                    ++field3274[i];
                }
                if ((effects[i].x > 700.0) ||
                    (effects[i].x < -60.0)) {
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (0xf < field3274[i]) {
                        effects[i].field0080 = 0;
                        field3274[i] = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x193:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                }
                if (!((((field0008 == 0x102) || (field0008 == 0x106)) &&
                    ((field0008 != 0x106 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x194:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                }
                if (!(((((field0008 == 0x101) || (field0008 == 0x100)) ||
                    (field0008 == 0x107)) &&
                    ((field0008 != 0x107 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x195:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                }
                if (!((((field0008 == 0x103) || (field0008 == 0x108)) &&
                    ((field0008 != 0x108 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x196:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                }
                if (!((((field0008 == 0x104) || (field0008 == 0x109)) &&
                    ((field0008 != 0x109 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x197:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                }
                if (!((((field0008 == 0x105) || (field0008 == 0x10a)) &&
                    ((field0008 != 0x10a || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x198:
                if (effects[i].tick == 0) {
                    if (effects[i].frame == 0) {
                        effects[i].field0084 = 1;
                    }
                    if (effects[i].frame == 0x12) {
                        effects[i].field0084 = 1;
                    }
                }
                if ((0x12 < effects[i].frame) &&
                    (field3174[i] = field3174[i] + -1, field3174[i] <= 0
                    )) {
                    spawn.type = 0x199;
                    spawn.x = (double)(int)(((int(effects[i].x)) + 0x32) - (((unsigned short)RandomRange(0, 100))));
                    spawn.y = (double)(int)(((int(effects[i].y)) + 0x32) - (((unsigned short)RandomRange(0, 100))));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field3174[i] = 0xf;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 0x10) {
                        field02c8 = 4;
                    }
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field314c = 0;
                    }
                }
                break;
            case 0x199:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19a:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19b:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19c:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                    --field3174[i];
                    if (field3174[i] <= 0) {
                        spawn.type = 0x19b;
                        spawn.x = (double)(int)((int(positionX)) + ((((unsigned short)RandomRange(0, 0x32))) + 0x1e) * (int)facing)
                        ;
                        spawn.y = (double)(int)(((int(positionY)) + -0x50) - (((unsigned short)RandomRange(0, 0x32))));
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                        field3174[i] = 0xc;
                    }
                }
                if (!(((field0008 == 0x132) &&
                    ((field0008 != 0x132 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19e:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                    --field3174[i];
                    if (field3174[i] <= 0) {
                        spawn.type = 0x19b;
                        spawn.x = (double)(int)((int(positionX)) + ((((unsigned short)RandomRange(0, 0x32))) + 7) * (int)facing);
                        spawn.y = (double)(int)(((int(positionY)) + -0x32) - (((unsigned short)RandomRange(0, 0x32))));
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                        field3174[i] = 0xc;
                    }
                }
                if (!((((((field0008 == 0x12f) || (field0008 == 0x130)) ||
                    (field0008 == 0x131)) || (field0008 == 0x133)) &&
                    ((field0008 != 0x133 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19d:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                    --field3174[i];
                    if (field3174[i] <= 0) {
                        spawn.type = 0x19b;
                        spawn.x = (double)(int)((int(positionX)) + ((((unsigned short)RandomRange(0, 0x32))) + 0x23) * (int)facing)
                        ;
                        spawn.y = (double)(int)(((int(positionY)) + -0x14) - (((unsigned short)RandomRange(0, 0x32))));
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                        field3174[i] = 0xc;
                    }
                }
                if (!((((field0008 == 0x134) || (field0008 == 0x134)) &&
                    ((field0008 != 0x134 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19f:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                    --field3174[i];
                    if (field3174[i] <= 0) {
                        spawn.type = 0x19b;
                        spawn.x = (double)(int)((int(positionX)) + ((((unsigned short)RandomRange(0, 0x32))) + 0x14) * (int)facing)
                        ;
                        spawn.y = (double)(int)(((int(positionY)) + 0x19) - (((unsigned short)RandomRange(0, 0x32))));
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                        field3174[i] = 0xc;
                    }
                }
                if (!((((field0008 == 0x135) || (field0008 == 0x135)) &&
                    ((field0008 != 0x135 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a0:
                if (effects[i].frame < 0x1a) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                    --field3174[i];
                    if (field3174[i] <= 0) {
                        spawn.type = 0x19b;
                        spawn.x = (double)(int)((int(positionX)) + ((((unsigned short)RandomRange(0, 0x32))) - 0x1e) * (int)facing)
                        ;
                        spawn.y = (double)(int)(((int(positionY)) + 0x14) - (((unsigned short)RandomRange(0, 0x32))));
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                        field3174[i] = 0xc;
                    }
                }
                if (!((((field0008 == 0x136) || (field0008 == 0x136)) &&
                    ((field0008 != 0x136 || (field000a >= 6)))) ||
                    (effects[i].frame >= 26))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a1:
                if (field0008 != 312 && field0008 != 313 && field0008 != 314 && effects[i].frame < 26) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    effects[i].field0084 = 0;
                    break;
                }
                if (field0008 != 312 && field0008 != 313 && field0008 != 314 && effects[i].frame < 26) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1a;
                    effects[i].field0084 = 0;
                    break;
                }
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                if ((field000a < 10) &&
                    (effects[i].frame < 0x1a)) {
                    effects[i].x =
                    (double)(facing * 0xf) + positionX;
                    effects[i].y =
                    positionY - 148.0;
                }
                if ((field000a == 0xb) &&
                    (effects[i].frame < 0x1a)) {
                    effects[i].x =
                    (double)((int)facing << 4) + positionX;
                    effects[i].y =
                    positionY - 147.0;
                    effects[i].field0084 = 0;
                }
                if ((field000a == 0xc) &&
                    (effects[i].frame < 0x1a)) {
                    effects[i].x =
                    (double)(facing * 0x68) + positionX;
                    effects[i].y =
                    positionY - 54.0;
                }
                if (((0xc < field000a) && (field000a < 0x12)
                    ) && (effects[i].frame < 0x1a)) {
                    effects[i].x =
                    (double)(facing * 0x68) + positionX;
                    effects[i].y =
                    positionY - 53.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if ((effects[i].frame == 0x1a) &&
                        (field313c < 4)) {
                        effects[i].frame = 0xb;
                        effects[i].field0080 = 0;
                        field02c8 = 7;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a2:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a3:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a4:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a5:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a6:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(50.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 2;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x14)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a7:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(55.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 3;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x1e)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a8:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(45.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 3;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x1e)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a9:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(60.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 4;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x28)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1aa:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(55.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 4;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x28)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1ab:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(45.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 4;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x28)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1ac:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(40.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 4;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x28)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1ad:
                if (((field0008 == 0x138) || (field0008 == 0x139)) ||
                    (field0008 == 0x13a)) {
                    effects[i].x =
                    (double)(facing * 0xf) + positionX;
                    effects[i].y =
                    positionY - 148.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1ae:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1af:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b0:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b1:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(50.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 3;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x1e)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b2:
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                    effects[i].SetVelocityPolar(50.0,2.5);
                }
                if (effects[i].frame < 29 && effects[i].y + effects[i].vy > 0.0) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    effects[i].field0084 = 4;
                    break;
                }
                if ((effects[i].frame < 0x2d) &&
                    ((effects[i].y == 0.0 &&
                    (effects[i].field0084 == 0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x2d;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y < 0.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 10;
                    }
                    if ((effects[i].frame == 0x2d) &&
                        (field3274[i] < 0x28)) {
                        effects[i].frame -= 10;
                        ++field3274[i];
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b3:
                if (field0008 == 0x13e) {
                    effects[i].x =
                    (double)(facing * 5) + positionX;
                    effects[i].y =
                    positionY - 45.0;
                }
                if (field3174[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3174[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b4:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b5:
                if ((field0008 < 0x111) || (0x113 < field0008)) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3174[i] = 0;
                    field3274[i] = 0x14;
                }
                field3174[i] = field3174[i] + field3274[i];
                --field3274[i];
                if (field3274[i] < 1) {
                    field3274[i] = 1;
                }
                effects[i].SetVelocityPolar((double)(field3174[i] + -0x78)
                    ,(double)((((unsigned short)RandomRange(0, 0x1e))) + 0x3c));
                spawn.type = 0x19b;
                spawn.x = (double)(int(positionX)) + (effects[i].vx + 20.0) * facing;
                spawn.y = (double)((int(positionY)) + -0x32) + effects[i].vy;
                spawn.group = 2;
                spawn.layer = 1;
                spawn.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&spawn);
                effects[i].vx = 0.0;
                effects[i].vy = 0.0;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b6:
                if ((field0008 < 0x114) || (0x116 < field0008)) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3174[i] = 0;
                    field3274[i] = 0x14;
                }
                field3174[i] = field3174[i] + field3274[i];
                --field3274[i];
                if (field3274[i] < 1) {
                    field3274[i] = 1;
                }
                effects[i].SetVelocityPolar((double)(field3174[i] + -0x78)
                    ,(double)((((unsigned short)RandomRange(0, 0x1e))) + 0x3c));
                spawn.type = 0x1b7;
                spawn.x = (double)(int(positionX)) + (effects[i].vx + 20.0) * facing;
                spawn.y = (double)((int(positionY)) + -0x32) + effects[i].vy;
                spawn.group = 2;
                spawn.layer = 1;
                spawn.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&spawn);
                effects[i].vx = 0.0;
                effects[i].vy = 0.0;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b7:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b8:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1b9:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1ba:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3174[i] = 0;
                    effects[i].field0084 = 5;
                }
                effects[i].vx = 0.5;
                if (effects[i].tick == 0) {
                    spawn.type = 0x1b9;
                    spawn.x = (double)(int)(((int(effects[i].x)) + 0x32) - (((unsigned short)RandomRange(0, 100))));
                    spawn.y = (double)(int)(((int(effects[i].y)) + 0x32) - (((unsigned short)RandomRange(0, 100))));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        if (field3174[i] < 5) {
                            effects[i].frame = 1;
                            ++field3174[i];
                            effects[i].field0080 = 0;
                        }
                        else {
                            RemoveLocalEffect((short)i);
                        }
                    }
                }
                break;
            case 0x1bb:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3174[i] = 0;
                    effects[i].field0084 = 10;
                }
                effects[i].vx = 0.5;
                if (effects[i].tick == 0) {
                    spawn.type = 0x1b9;
                    spawn.x = (double)(int)(((int(effects[i].x)) + 0x32) - (((unsigned short)RandomRange(0, 100))));
                    spawn.y = (double)(int)(((int(effects[i].y)) + 0x32) - (((unsigned short)RandomRange(0, 100))));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        if (field3174[i] < 10) {
                            effects[i].frame = 1;
                            ++field3174[i];
                            effects[i].field0080 = 0;
                        }
                        else {
                            RemoveLocalEffect((short)i);
                        }
                    }
                }
                break;
            case 0x1bc:
                if ((field0008 < 0x111) || (0x113 < field0008)) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3174[i] = 0;
                    field3274[i] = 0x14;
                }
                field3174[i] = field3174[i] + field3274[i];
                --field3274[i];
                if (field3274[i] < 1) {
                    field3274[i] = 1;
                }
                effects[i].SetVelocityPolar((double)(0x78 - field3174[i]),
                    (double)((((unsigned short)RandomRange(0, 0x1e))) + 0x3c));
                spawn.type = 0x19b;
                spawn.x = (double)(int(positionX)) + (effects[i].vx + 20.0) * facing;
                spawn.y = (double)((int(positionY)) + -0x32) + effects[i].vy;
                spawn.group = 2;
                spawn.layer = 1;
                spawn.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&spawn);
                effects[i].vx = 0.0;
                effects[i].vy = 0.0;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1bd:
                if ((field0008 < 0x114) || (0x116 < field0008)) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3174[i] = 0;
                    field3274[i] = 0x14;
                }
                field3174[i] = field3174[i] + field3274[i];
                --field3274[i];
                if (field3274[i] < 1) {
                    field3274[i] = 1;
                }
                effects[i].SetVelocityPolar((double)(0x78 - field3174[i]),
                    (double)((((unsigned short)RandomRange(0, 0x1e))) + 0x3c));
                spawn.type = 0x1b7;
                spawn.x = (double)(int(positionX)) + (effects[i].vx + 20.0) * facing;
                spawn.y = (double)((int(positionY)) + -0x32) + effects[i].vy;
                spawn.group = 2;
                spawn.layer = 1;
                spawn.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&spawn);
                effects[i].vx = 0.0;
                effects[i].vy = 0.0;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1ef:
                effects[i].vx = -0.02;
                effects[i].field008c = 30000;
                ++effects[i].tick;
                if (field0008 != 0x57) {
                    RemoveLocalEffect((short)i);
                }
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x1f0:
                if ((field0008 != 83 && field0008 != 84 && field0008 != 85 && field0008 != 86) || (field0008 == 83 && field000a > 1) || (field0008 == 84 && field000a > 1)) {
                    spawn.type = 0x1f1;
                    spawn.x = (double)((int(positionX)) + facing * 0x17);
                    spawn.y = (double)((int(positionY)) + -4);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f1;
                    spawn.x = (double)((int(positionX)) - facing * 4);
                    spawn.y = (double)((int(positionY)) + -6);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f1;
                    spawn.x = (double)((int(positionX)) - facing * 0xe);
                    spawn.y = (double)((int(positionY)) + -0x1a);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f1;
                    spawn.x = (double)(int(positionX));
                    spawn.y = (double)(int(positionY));
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f1;
                    spawn.x = (double)((int(positionX)) + facing * 0x1e);
                    spawn.y = (double)((int(positionY)) + -0x28);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f1;
                    spawn.x = (double)((int(positionX)) - facing * 0x19);
                    spawn.y = (double)((int(positionY)) + -0x50);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f2;
                    spawn.x = (double)((int(positionX)) - facing * 0x23);
                    spawn.y = (double)((int(positionY)) + -0x2a);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f2;
                    spawn.x = (double)((int(positionX)) - facing * 0x12);
                    spawn.y = (double)((int(positionY)) + -0x14);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f2;
                    spawn.x = (double)((int(positionX)) + facing * 2);
                    spawn.y = (double)((int(positionY)) + -0x41);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    spawn.type = 0x1f2;
                    spawn.x = (double)((int(positionX)) + facing * 0x10);
                    spawn.y = (double)((int(positionY)) + -0x50);
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field02c9 = 0x22;
                    RemoveLocalEffect((short)i);
                    field3144 = 0;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x1f1:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3174[i] == 0)) {
                    field3274[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3174[i];
                    effects[i].vx =
                    (double)(16000 < (std::rand())) * 1.2 + ((double)(16000 < (std::rand())) * 0.7) + ((double)(16000 < (std::rand())) * 1.7) + -1.8;
                    effects[i].vy =
                    -1.2 - ((double)(16000 < (std::rand())) * 0.6 + ((double)(16000 < (std::rand())) * 0.9) + ((double)(16000 < (std::rand())) * 1.4));
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if ((effects[i].y > 0.0) &&
                    (effects[i].vy > 0.0)) {
                    effects[i].vy =
                    -effects[i].vy;
                }
                if (field3274[i] < 10) {
                    effects[i].group = 1;
                }
                if (field3274[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++effects[i].tick;
                --field3274[i];
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x1f2:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3174[i] == 0)) {
                    field3274[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x3c + 0x78 + (unsigned int)(16000 < (std::rand())) * 0x28;
                    ++field3174[i];
                    effects[i].vx =
                    (double)(16000 < (std::rand())) + ((double)(16000 < (std::rand())) * 0.5) + (double)(16000 < (std::rand())) * 1.5 +
                    -1.5;
                    effects[i].vy =
                    -1.0 - ((double)(16000 < (std::rand())) * 0.5 + ((double)(16000 < (std::rand())) * 0.8) + ((double)(16000 < (std::rand())) * 1.2));
                }
                effects[i].vy =
                effects[i].vy + 0.03;
                if ((effects[i].y > 0.0) &&
                    (effects[i].vy > 0.0)) {
                    effects[i].vy =
                    -effects[i].vy;
                }
                if (field3274[i] < 10) {
                    effects[i].group = 1;
                }
                if (field3274[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++effects[i].tick;
                --field3274[i];
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 499:
                effects[i].x = positionX;
                effects[i].y = positionY;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
            }
        }
        i = i + 1;
        if (i >= 64) {
            i = 0;
        }
    }
    return;
}
