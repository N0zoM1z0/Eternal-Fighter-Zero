// Misuzu complete local-effect update and lifetime dispatch.
#include "CharacterViews.h"
#include <cstdlib>

void Character23::Slot07()
{
    int i;
    if ((*opponentSlot)->hitstunFrames > 0) return;
    i = (int)effectRead;
    // Both emitter kinds use this real descriptor and its shared base view.
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
                field314c = (int(effects[i].y));
                field3148 = (int(effects[i].x));
                effects[i].flag0048 = facing;
                if ((field0008 == 0x100) && (field000a == 5)) {
                    effects[i].type = 0x199;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    break;
                }
                else if ((field0008 == 0x101) && (field000a == 5)) {
                    effects[i].type = 0x19a;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    break;
                }
                else if ((field0008 == 0x102) && (field000a == 5)) {
                    effects[i].type = 0x19b;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    break;
                }
                else if ((field0008 == 0x139) &&
                    ((field000a == 2 && ((unsigned short)field000c == 0)))) {
                    effects[i].type = 0x1bb;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].field0088 = 1;
                    break;
                }
                else if ((field0008 == 0x13a) &&
                    ((field000a == 2 && ((unsigned short)field000c == 0)))) {
                    effects[i].type = 0x1bc;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].field0088 = 1;
                    break;
                }
                else if (field0008 == 0x13b) {
                    effects[i].type = 0x1bd;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].field0088 = 1;
                    break;
                }
                else {
                    effects[i].vx =
                    (((positionX - (double)(facing * 0x2d)) -
                        effects[i].x) / 640.0) * 12.0 * effects[i].flag0048;
                    if ((effects[i].vx < 0.02) &&
                        (effects[i].vx > -0.02)) {
                        effects[i].vx = 0.0;
                    }
                    if (effects[i].vx < -1.6) {
                        effects[i].vx = -1.6;
                    }
                    if (effects[i].vx > 1.6) {
                        effects[i].vx = 1.6;
                    }
                    effects[i].vy =
                    (((positionY - 100.0) -
                        effects[i].y) / 480.0) * 12.0;
                    if ((effects[i].vy < 0.002) &&
                        (effects[i].vy > -0.002)) {
                        effects[i].vy = 0.0;
                    }
                    if (effects[i].vy > 0.6) {
                        effects[i].vy = 0.6;
                    }
                    if (effects[i].vy < -0.6) {
                        effects[i].vy = -0.6;
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
                }
                break;
            case 0x191:
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
            case 0x192:
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
            case 0x193:
                field346c = 1;
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3258[i] == 0)) {
                    effects[i].field0084 = 1;
                    ++field3258[i];
                }
                if (effects[i].frame == 1) {
                    if (((((*opponentSlot)->positionX <
                        effects[i].x + 50.0) &&
                        ((*opponentSlot)->positionX > effects[i].x - 50.0)) &&
                        (((*opponentSlot)->positionY - 40.0 <
                        effects[i].y + 50.0 &&
                        (((*opponentSlot)->positionY - 40.0 > effects[i].y - 50.0 &&
                        ((*opponentSlot)->positionY < 0.0)))))) &&
                        ((*opponentSlot)->field0008 != 0x60)) {
                        effects[i].frame = 2;
                        pendingCharacterSoundSlot = 2;
                        effects[i].tick = 0;
                    }
                    if ((((field0008 == 0xfa) || (field0008 == 0xfc)) &&
                        (field000a <= 1)) ||
                        ((effects[i].field0080 == 4 || (effects[i].field0080 == 5)))) {
                        RemoveLocalEffect((short)i);
                        field346c = 0;
                        break;
                    }
                }
                if ((effects[i].field0080 == 3) && (field3158[i] == 0)) {
                    (*opponentSlot)->hitstopFrames = 0x3c;
                    effects[i].field0086 = 0x3c;
                    ++field3158[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 2) {
                        RemoveLocalEffect((short)i);
                        field346c = 0;
                        break;
                    }
                    else if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field346c = 0;
                    }
                }
                break;
            case 0x194:
                field3470 = 1;
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3258[i] == 0)) {
                    effects[i].field0084 = 1;
                    ++field3258[i];
                }
                if (effects[i].frame == 1) {
                    if ((((((*opponentSlot)->positionX <
                        effects[i].x + 50.0) &&
                        ((*opponentSlot)->positionX > effects[i].x - 50.0)) &&
                        ((*opponentSlot)->positionY - 40.0 <
                        effects[i].y + 50.0)) &&
                        (((*opponentSlot)->positionY - 40.0 > effects[i].y - 50.0 &&
                        ((*opponentSlot)->positionY < 0.0)))) &&
                        ((*opponentSlot)->field0008 != 0x60)) {
                        effects[i].frame = 2;
                        effects[i].tick = 0;
                        pendingCharacterSoundSlot = 2;
                    }
                    if ((((field0008 == 0xfb) || (field0008 == 0xfc)) &&
                        (field000a <= 1)) ||
                        ((effects[i].field0080 == 4 || (effects[i].field0080 == 5)))) {
                        RemoveLocalEffect((short)i);
                        field3470 = 0;
                        break;
                    }
                }
                if ((effects[i].field0080 == 3) && (field3158[i] == 0)) {
                    (*opponentSlot)->hitstopFrames = 0x3c;
                    effects[i].field0086 = 0x3c;
                    ++field3158[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 2) {
                        RemoveLocalEffect((short)i);
                        field3470 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3470 = 0;
                    }
                }
                break;
            case 0x195:
                field3474 = 1;
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3258[i] == 0)) {
                    effects[i].field0084 = 1;
                    ++field3258[i];
                }
                if (effects[i].frame == 1) {
                    if (((((*opponentSlot)->positionX <
                        effects[i].x + 50.0) &&
                        ((*opponentSlot)->positionX > effects[i].x - 50.0)) &&
                        (((*opponentSlot)->positionY - 40.0 <
                        effects[i].y + 50.0 &&
                        (((*opponentSlot)->positionY - 40.0 > effects[i].y - 50.0 &&
                        ((*opponentSlot)->positionY < 0.0)))))) &&
                        ((*opponentSlot)->field0008 != 0x60)) {
                        effects[i].frame = 2;
                        effects[i].tick = 0;
                        pendingCharacterSoundSlot = 2;
                    }
                    if ((((field0008 == 0xfc) && (field000a <= 1)) ||
                        (effects[i].field0080 == 4)) || (effects[i].field0080 == 5)) {
                        RemoveLocalEffect((short)i);
                        field3474 = 0;
                    }
                }
                if ((effects[i].field0080 == 3) && (field3158[i] == 0)) {
                    (*opponentSlot)->hitstopFrames = 0x5a;
                    effects[i].field0086 = 0x5a;
                    ++field3158[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 2) {
                        RemoveLocalEffect((short)i);
                        field3474 = 0;
                        break;
                    }
                    else if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3474 = 0;
                    }
                }
                break;
            case 0x196:
                field3478 = 1;
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3258[i] == 0)) {
                    effects[i].field0084 = 1;
                    ++field3258[i];
                }
                if ((effects[i].frame == 0) &&
                    (0x14 < effects[i].tick)) {
                    if (((*opponentSlot)->positionX <
                        effects[i].x + 50.0) &&
                        ((*opponentSlot)->positionX > effects[i].x - 50.0)) {
                        effects[i].frame = 1;
                        effects[i].tick = 0;
                    }
                    if ((((field0008 == 0xfd) || (field0008 == 0xff)) &&
                        (field000a == 0)) ||
                        (((effects[i].field0080 == 4 || (effects[i].field0080 == 5)) ||
                        ((0x31 < field0008 && (field0008 < 0x96)))))) {
                        spawn.type = 0;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = (double)(int(effects[i].y));
                        spawn.group = 2;
                        spawn.layer = 1;
                        contextOwner->EmitEffect(&spawn);
                        RemoveLocalEffect((short)i);
                        field3478 = 0;
                        break;
                    }
                }
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    pendingCharacterSoundSlot = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 1) {
                        RemoveLocalEffect((short)i);
                        field3478 = 0;
                    }
                    if ((effects[i].frame == 0xc) &&
                        (field3258[i] < 3)) {
                        effects[i].frame -= 2;
                        ++field3258[i];
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3478 = 0;
                    }
                }
                break;
            case 0x197:
                field347c = 1;
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3258[i] == 0)) {
                    effects[i].field0084 = 1;
                    ++field3258[i];
                }
                if ((effects[i].frame == 0) &&
                    (0x14 < effects[i].tick)) {
                    if (((*opponentSlot)->positionX <
                        effects[i].x + 50.0) &&
                        ((*opponentSlot)->positionX > effects[i].x - 50.0)) {
                        effects[i].frame = 1;
                        effects[i].tick = 0;
                    }
                    if (((((field0008 == 0xfe) || (field0008 == 0xff)) &&
                        (field000a == 0)) ||
                        ((effects[i].field0080 == 4 || (effects[i].field0080 == 5))))
                        || ((0x31 < field0008 && (field0008 < 0x96)))) {
                        spawn.type = 0;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = (double)(int(effects[i].y));
                        spawn.group = 2;
                        spawn.layer = 1;
                        contextOwner->EmitEffect(&spawn);
                        RemoveLocalEffect((short)i);
                        field347c = 0;
                        break;
                    }
                }
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    pendingCharacterSoundSlot = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 1) {
                        RemoveLocalEffect((short)i);
                        field347c = 0;
                    }
                    if ((effects[i].frame == 0xc) &&
                        (field3258[i] < 3)) {
                        effects[i].frame -= 2;
                        ++field3258[i];
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field347c = 0;
                    }
                }
                break;
            case 0x198:
                field3480 = 1;
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3258[i] == 0)) {
                    effects[i].field0084 = 1;
                    ++field3258[i];
                }
                if ((effects[i].frame == 0) &&
                    (0x14 < effects[i].tick)) {
                    if (((*opponentSlot)->positionX <
                        effects[i].x + 70.0) &&
                        ((*opponentSlot)->positionX > effects[i].x - 70.0)) {
                        effects[i].frame = 1;
                        effects[i].tick = 0;
                    }
                    if (((field0008 == 0xff) && (field000a == 0)) ||
                        ((effects[i].field0080 == 4 || (effects[i].field0080 == 5)))) {
                        RemoveLocalEffect((short)i);
                        field3480 = 0;
                        break;
                    }
                }
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    pendingCharacterSoundSlot = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 1) {
                        RemoveLocalEffect((short)i);
                        field3480 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3480 = 0;
                    }
                }
                break;
            case 0x199:
                field3148 = (int(effects[i].x));
                field314c = (int(effects[i].y));
                field3150 = 1;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].field0084 = 1;
                    pendingCharacterSoundSlot = 4;
                }
                if (effects[i].frame < 4) {
                    effects[i].vy =
                    effects[i].vy + 0.025;
                }
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    pendingCharacterSoundSlot = 5;
                    effects[i].vy = 0.0;
                    effects[i].vx = 4.0;
                }
                if (4 < effects[i].frame) {
                    effects[i].vx =
                    effects[i].vx - 0.06;
                }
                if (effects[i].vx < 0.0) {
                    effects[i].vx = 0.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 400;
                        field3150 = 0;
                    }
                }
                break;
            case 0x19a:
                field3148 = (int(effects[i].x));
                field314c = (int(effects[i].y));
                field3150 = 1;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    pendingCharacterSoundSlot = 4;
                    effects[i].field0084 = 1;
                }
                if (effects[i].frame < 4) {
                    effects[i].vy =
                    effects[i].vy + 0.02;
                }
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = 0.0;
                    effects[i].vx = 4.0;
                    pendingCharacterSoundSlot = 5;
                }
                if (4 < effects[i].frame) {
                    effects[i].vx =
                    effects[i].vx - 0.06;
                }
                if (effects[i].vx < 0.0) {
                    effects[i].vx = 0.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 400;
                        field3150 = 0;
                    }
                }
                break;
            case 0x19b:
                field3148 = (int(effects[i].x));
                field314c = (int(effects[i].y));
                field3150 = 1;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].field0084 = 5;
                    pendingCharacterSoundSlot = 4;
                }
                if (effects[i].frame < 4) {
                    effects[i].vy =
                    effects[i].vy + 0.04;
                }
                if (4 < effects[i].frame) {
                    effects[i].vx =
                    effects[i].vx - 0.015;
                }
                if (effects[i].vx < 0.0) {
                    effects[i].vx = 0.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 4) {
                        effects[i].vy = 1.0;
                        effects[i].vx = 3.4;
                        pendingCharacterSoundSlot = 5;
                        spawn.type = 0x19c;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = (double)(int(effects[i].y));
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                    }
                    if ((effects[i].frame == 5) &&
                        (effects[i].y < 0.0)) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 400;
                        field3150 = 0;
                    }
                }
                break;
            case 0x19c:
                effects[i].x = (double)field3148;
                effects[i].y = (double)field314c;
                if (field314c > 0) {
                    RemoveLocalEffect((short)i);
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
            case 0x19d:
                effects[i].x = positionX;
                effects[i].y = positionY;
                if (field000a > 24 || (field0008 > 49 && field0008 < 150) || field0008 != 265) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0xb) {
                        spawn.type = 0x19e;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y - 55.0;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        pendingCharacterSoundSlot = 7;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 2;
                    }
                }
                break;
            case 0x19e:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3158[i] = 0;
                }
                if (((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) {
                    field3158[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 10) &&
                        (field3158[i] != 1)) {
                        spawn.type = 0x1c8;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19f:
                if (field3158[i] == 0) {
                    effects[i].vx = 0.125;
                    effects[i].vy = -1.35;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                }
                ++field3258[i];
                if (((((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((0x14 < field3358[i] ||
                    ((0 < effects[i].field0080 || (0x4b0 < field3258[i])))))) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) ||
                    ((effects[i].x > 760.0 ||
                    (effects[i].x < -120.0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        if (field345c == 0) {
                            field345c = 3000;
                        }
                        else {
                            field345c = field345c + 1000;
                            if (3000 < field345c) {
                                field345c = 3000;
                            }
                        }
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                if ((field3158[i] == 1) &&
                    (effects[i].vy =
                    effects[i].vy + 0.01,
                    effects[i].vy > 0.0)) {
                    ++field3158[i];
                    effects[i].ay = 0.01;
                }
                if (effects[i].vy > 0.5) {
                    effects[i].ay = -0.01;
                }
                if (effects[i].vy < -0.5) {
                    effects[i].ay = 0.01;
                }
                if (1 < field3158[i]) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        ++field3358[i];
                    }
                }
                break;
            case 0x1a0:
                effects[i].x = positionX;
                effects[i].y = positionY;
                if (field000a > 24 || (field0008 > 49 && field0008 < 150) || field0008 != 266) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0xb) {
                        spawn.type = 0x1a1;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y - 55.0;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                        pendingCharacterSoundSlot = 7;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 2;
                    }
                }
                break;
            case 0x1a1:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3158[i] = 0;
                }
                if (((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) {
                    field3158[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 10) &&
                        (field3158[i] != 1)) {
                        spawn.type = 0x1c9;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a2:
                if (field3158[i] == 0) {
                    effects[i].vx = 0.15;
                    effects[i].vy = -1.5;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                }
                ++field3258[i];
                if (((((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((6 < field3358[i] ||
                    ((0 < effects[i].field0080 || (0x4b0 < field3258[i])))))) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) ||
                    ((effects[i].x > 760.0 ||
                    (effects[i].x < -120.0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        if (field345c == 0) {
                            field345c = 3000;
                        }
                        else {
                            field345c = field345c + 1000;
                            if (3000 < field345c) {
                                field345c = 3000;
                            }
                        }
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                else {
                    if ((field3158[i] == 1) &&
                        (effects[i].vy =
                        effects[i].vy + 0.01,
                        effects[i].vy > 0.0)) {
                        ++field3158[i];
                        effects[i].ay = 0.01;
                    }
                    if (effects[i].vy > 0.7) {
                        effects[i].ay = -0.01;
                    }
                    if (effects[i].vy < -0.5) {
                        effects[i].ay = 0.01;
                    }
                    if (1 < field3158[i]) {
                        effects[i].vy =
                        effects[i].vy +
                        effects[i].ay;
                    }
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        effects[i].field0080 = 0;
                        if (effects[i].frame >= frameCount) {
                            effects[i].frame = 0;
                            ++field3358[i];
                        }
                    }
                }
                break;
            case 0x1a3:
                effects[i].x = positionX;
                effects[i].y = positionY;
                if (field000a > 24 || (field0008 > 49 && field0008 < 150) || field0008 != 267) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0xb) {
                        spawn.type = 0x1a4;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y - 55.0;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                        pendingCharacterSoundSlot = 8;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 2;
                    }
                }
                break;
            case 0x1a4:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3158[i] = 0;
                }
                if (((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) {
                    field3158[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 10) &&
                        (field3158[i] != 1)) {
                        spawn.type = 0x1ca;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a5:
                if (field3158[i] == 0) {
                    effects[i].vx = 0.2;
                    effects[i].vy = -1.5;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                }
                ++field3258[i];
                if ((((0x31 < field0008) && (field0008 < 0x96)) ||
                    (0x12 < field3358[i])) ||
                    (((((0 < effects[i].field0080 || (0x4b0 < field3258[i])) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) ||
                    (effects[i].x > 760.0)) ||
                    (effects[i].x < -120.0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        if (field345c == 0) {
                            field345c = 3000;
                        }
                        else {
                            field345c = field345c + 1000;
                            if (3000 < field345c) {
                                field345c = 3000;
                            }
                        }
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                if ((field3158[i] == 1) &&
                    (effects[i].vy =
                    effects[i].vy + 0.01,
                    effects[i].vy > 0.0)) {
                    ++field3158[i];
                    effects[i].ay = 0.01;
                }
                if (effects[i].vy > 0.58) {
                    effects[i].ay = -0.01;
                }
                if (effects[i].vy < -0.5) {
                    effects[i].ay = 0.01;
                }
                if (1 < field3158[i]) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        ++field3358[i];
                    }
                }
                break;
            case 0x1a6:
                if (field3158[i] == 0) {
                    effects[i].vx = 0.4;
                    effects[i].vy = -1.7;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                }
                ++field3258[i];
                if (((((0x31 < field0008) && (field0008 < 0x96)) ||
                    (0x12 < field3358[i])) ||
                    (((0 < effects[i].field0080 || (0x4b0 < field3258[i])) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))))) ||
                    ((effects[i].x > 760.0 ||
                    (effects[i].x < -120.0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        if (field345c == 0) {
                            field345c = 3000;
                        }
                        else {
                            field345c = field345c + 1000;
                            if (3000 < field345c) {
                                field345c = 3000;
                            }
                        }
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                if ((field3158[i] == 1) &&
                    (effects[i].vy =
                    effects[i].vy + 0.01,
                    effects[i].vy > 0.0)) {
                    ++field3158[i];
                    effects[i].ay = 0.01;
                }
                if (effects[i].vy > 0.58) {
                    effects[i].ay = -0.01;
                }
                if (effects[i].vy < -0.5) {
                    effects[i].ay = 0.01;
                }
                if (1 < field3158[i]) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        ++field3358[i];
                    }
                }
                break;
            case 0x1a7:
                if (field3158[i] == 0) {
                    effects[i].vx = 0.3;
                    effects[i].vy = -1.6;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                }
                ++field3258[i];
                if (((((0x31 < field0008) && (field0008 < 0x96)) ||
                    (0x12 < field3358[i])) ||
                    ((0 < effects[i].field0080 || (0x4b0 < field3258[i])))) ||
                    (((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))) ||
                    ((effects[i].x > 760.0 ||
                    (effects[i].x < -120.0)))))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        field345c = 3000;
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                if ((field3158[i] == 1) &&
                    (effects[i].vy =
                    effects[i].vy + 0.01,
                    effects[i].vy > 0.0)) {
                    ++field3158[i];
                    effects[i].ay = 0.01;
                }
                if (effects[i].vy > 0.7) {
                    effects[i].ay = -0.01;
                }
                if (effects[i].vy < -0.5) {
                    effects[i].ay = 0.01;
                }
                if (1 < field3158[i]) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        ++field3358[i];
                    }
                }
                break;
            case 0x1a8:
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
            case 0x1a9:
                if (field3158[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3158[i];
                    effects[i].vy = -1.5;
                }
                effects[i].vy =
                effects[i].vy + 0.035;
                if (effects[i].field0080 == 3) {
                    ++field3460;
                    field345c = 3000;
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    effects[i].field0080 = 0;
                }
                if ((effects[i].tick == 0) &&
                    (effects[i].frame == 1)) {
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
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
            case 0x1aa:
                if (field3158[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3158[i];
                    effects[i].vy = -1.5;
                }
                effects[i].vy =
                effects[i].vy + 0.035;
                if (effects[i].field0080 == 3) {
                    field3460 = field3460 + 3;
                    field345c = 3000;
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    effects[i].field0080 = 0;
                }
                if ((effects[i].tick == 0) &&
                    (effects[i].frame == 1)) {
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
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
            case 0x1ab:
                if (field3158[i] == 0) {
                    effects[i].field0084 = 1;
                    ++field3158[i];
                    effects[i].vy = -1.5;
                }
                effects[i].vy =
                effects[i].vy + 0.035;
                if (effects[i].field0080 == 3) {
                    field3460 = field3460 + 5;
                    field345c = 3000;
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    effects[i].field0080 = 0;
                }
                if ((effects[i].tick == 0) &&
                    (effects[i].frame == 1)) {
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 3) + 0x1ac;
                    spawn.x = (effects[i].x - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    spawn.y = (effects[i].y - 50.0) + (double)((unsigned short)RandomRange(0, 100));
                    EmitLocalEffect(&spawn);
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
            case 0x1ac:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x28)) * 0.1 + -2.0;
                    effects[i].vy =
                    -0.8 - (double)((unsigned short)RandomRange(0, 0x28)) * 0.1;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.04;
                }
                if (effects[i].vy + effects[i].y > 0.0) {
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    pendingCharacterSoundSlot = 0xb;
                    RemoveLocalEffect((short)i);
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
            case 0x1ad:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x28)) * 0.1 + -2.0;
                    effects[i].vy =
                    -0.8 - (double)((unsigned short)RandomRange(0, 0x28)) * 0.1;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.04;
                }
                if (effects[i].vy + effects[i].y > 0.0) {
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    pendingCharacterSoundSlot = 0xb;
                    RemoveLocalEffect((short)i);
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
            case 0x1ae:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x28)) * 0.1 + -2.0;
                    effects[i].vy =
                    -0.8 - (double)((unsigned short)RandomRange(0, 0x28)) * 0.1;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.04;
                }
                if (effects[i].vy + effects[i].y > 0.0) {
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    spawn.type = (unsigned short)RandomRange(0, 4) + 0x1af;
                    spawn.x = (effects[i].x - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    spawn.y = (effects[i].y - 10.0) + (double)(unsigned short)RandomRange(0, 0x14);
                    EmitLocalEffect(&spawn);
                    pendingCharacterSoundSlot = 0xb;
                    RemoveLocalEffect((short)i);
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
            case 0x1af:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.1 + -1.0;
                    effects[i].vy =
                    -0.8 - (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
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
            case 0x1b0:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.1 + -1.0;
                    effects[i].vy =
                    -0.8 - (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
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
            case 0x1b1:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.1 + -1.0;
                    effects[i].vy =
                    -0.8 - (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
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
            case 0x1b2:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.1 + -1.0;
                    effects[i].vy =
                    -0.8 - (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
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
            case 0x1b3:
                if ((effects[i].tick == 0) &&
                    (effects[i].frame == 10)) {
                    spawn.type = 0x1c0;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y - 120.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
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
            case 0x1b4:
                if (field0008 != 307) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].type = 0x1ba;
                    break;
                }
                if ((effects[i].frame == 7) &&
                    (effects[i].tick == 0)) {
                    spawn.type = 0x1b5;
                    spawn.x = effects[i].x + (double)(effects[i].flag0048 * 0x23);
                    spawn.y = effects[i].y - 6.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 8) &&
                        (field3158[i] < 0x14)) {
                        ++field3158[i];
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].vx = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].frame = 0;
                        effects[i].tick = 0;
                        effects[i].type = 0x1ba;
                    }
                }
                break;
            case 0x1b5:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 10)) * 0.1 + 1.0;
                    effects[i].vy =
                    (double)(int)-(((unsigned short)RandomRange(0, 5))) * 0.1;
                    effects[i].field0084 = 1;
                }
                effects[i].vy =
                effects[i].vy - 0.007;
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
            case 0x1b6:
                if (field0008 != 308) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].type = 0x1ba;
                    break;
                }
                if ((effects[i].frame == 8) &&
                    (effects[i].tick == 0)) {
                    spawn.type = 0x1b7;
                    spawn.x = effects[i].x + (double)(effects[i].flag0048 * 0x14);
                    spawn.y = effects[i].y - 30.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 9) &&
                        (field3158[i] < 0x14)) {
                        ++field3158[i];
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].vx = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].frame = 0;
                        effects[i].tick = 0;
                        effects[i].type = 0x1ba;
                    }
                }
                break;
            case 0x1b7:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 10)) * 0.1 + 1.5;
                    effects[i].vy = (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                    effects[i].field0084 = 1;
                }
                effects[i].vy =
                effects[i].vy - 0.01;
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
            case 0x1b8:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = -6.8;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].vy =
                    effects[i].vy + 0.059,
                    effects[i].vy > 0.0)) {
                    effects[i].vy = 0.0;
                }
                if (effects[i].frame == 4) {
                    effects[i].vy = 5.0;
                }
                if (field0008 != 309 && effects[i].frame < 4) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].frame = 4;
                    effects[i].tick = 0;
                    break;
                }
                if (((effects[i].frame == 1) ||
                    (effects[i].frame == 2)) &&
                    (effects[i].tick == 0)) {
                    spawn.type = 0x1b9;
                    spawn.x = effects[i].x + (double)(effects[i].flag0048 * 0x14);
                    spawn.y = effects[i].y + 55.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    EmitLocalEffect(&spawn);
                    ++field3154;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 3) &&
                        (field3158[i] < 0xf)) {
                        ++field3158[i];
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3154 = 0;
                    }
                }
                break;
            case 0x1b9:
                if (field3158[i] == 0) {
                    ++field3158[i];
                    effects[i].SetVelocityPolar((double)(45 - field3154 * 2),
                        4.0);
                    effects[i].vx += (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                    effects[i].vy += (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                    effects[i].field0084 = 1;
                }
                effects[i].vy =
                effects[i].vy - 0.03;
                effects[i].vx =
                effects[i].vx - 0.025;
                if (effects[i].vx < 0.5) {
                    effects[i].vx = 0.5;
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
            case 0x1ba:
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
            case 0x1bb:
                field3150 = 1;
                if (field0008 != 0x139) {
                    effects[i].field0088 = 0;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].ay = 0.05;
                    effects[i].field0084 = 99;
                    spawn.type = 0x1bf;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.field0030 = 1;
                    EmitLocalEffect(&spawn);
                }
                if (effects[i].frame == 1) {
                    effects[i].vx = 0.7;
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                    if (effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].tick = 0;
                        effects[i].frame = 2;
                        break;
                    }
                }
                if (((effects[i].frame == 0xe) &&
                    (hitstunFrames == 0)) && (effects[i].tick >= 30)
                    ) {
                    effects[i].tick = 0;
                    effects[i].frame = 0xf;
                    effects[i].field0088 = 0;
                }
                if ((0 < field3138) && (effects[i].frame == 0)) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].field0084 = 6;
                    effects[i].vy = 0.0;
                    effects[i].vx = 4.0;
                }
                if ((effects[i].frame == 0x1b) &&
                    (effects[i].tick == 0)) {
                    spawn.type = 0x1bf;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y - 40.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 0x15) {
                        effects[i].field0080 = 0;
                    }
                    if ((effects[i].frame == 0x16) &&
                        (field3158[i] < 10)) {
                        effects[i].frame -= 4;
                        ++field3158[i];
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].tick = 0;
                        effects[i].frame = 0;
                        effects[i].type = 400;
                        field3158[i] = 0;
                        field3150 = 0;
                    }
                }
                break;
            case 0x1bc:
                field3150 = 1;
                if (field0008 != 0x13a) {
                    effects[i].field0088 = 0;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].ay = 0.035;
                    effects[i].field0084 = 99;
                    spawn.type = 0x1bf;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.field0030 = 1;
                    EmitLocalEffect(&spawn);
                }
                if (effects[i].frame == 1) {
                    effects[i].vx = 0.7;
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                    if (effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].tick = 0;
                        effects[i].frame = 2;
                        break;
                    }
                }
                if ((effects[i].frame == 3) &&
                    (hitstunFrames == 0)) {
                    effects[i].tick = 0;
                    effects[i].frame = 4;
                    effects[i].field0088 = 0;
                }
                if ((effects[i].frame == 9) &&
                    (effects[i].tick == 0)) {
                    spawn.type = 0x1be;
                    spawn.x = effects[i].x + (double)(effects[i].flag0048 * 0x24);
                    spawn.y = effects[i].y - 56.0;
                    spawn.flag0018 = (unsigned char)effects[i].flag0048;
                    spawn.group = 0;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                }
                if ((effects[i].frame == 0xe) &&
                    (effects[i].tick == 0)) {
                    field3468 = 1;
                }
                if ((effects[i].frame == 0x12) &&
                    (effects[i].tick == 0)) {
                    spawn.type = 0x1bf;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y - 40.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        effects[i].tick = 0;
                        effects[i].frame = 0;
                        effects[i].type = 400;
                        field3158[i] = 0;
                        field3468 = 0;
                        field3150 = 0;
                    }
                }
                break;
            case 0x1bd:
                field3150 = 1;
                if (field0008 != 0x13b) {
                    effects[i].field0088 = 0;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].ay = 0.035;
                    effects[i].field0084 = 10;
                    spawn.type = 0x1bf;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.field0030 = 1;
                    EmitLocalEffect(&spawn);
                }
                if (effects[i].frame == 1) {
                    effects[i].vx = 0.7;
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                    if (effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].tick = 0;
                        effects[i].frame = 2;
                        break;
                    }
                }
                if ((effects[i].frame == 3) &&
                    (hitstunFrames == 0)) {
                    effects[i].tick = 0;
                    effects[i].frame = 4;
                    effects[i].field0088 = 0;
                }
                if ((effects[i].frame == 7) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 1.5;
                    effects[i].vy = -3.5;
                    effects[i].ay = 0.052;
                }
                if ((7 < effects[i].frame) &&
                    (effects[i].frame < 0xb)) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                    effects[i].vx =
                    effects[i].vx - 0.015;
                    if (effects[i].vx < 0.0) {
                        effects[i].vx = 0.0;
                    }
                    if (effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].tick = 0;
                        effects[i].frame = 0xb;
                    }
                }
                if ((effects[i].frame == 0xe) &&
                    (effects[i].tick == 0)) {
                    spawn.type = 0x1bf;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y - 40.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 9) &&
                        (field3258[i] < 4)) {
                        --effects[i].frame;
                        ++field3258[i];
                    }
                    if (effects[i].frame == 0xb) {
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].tick = 0;
                        effects[i].frame = 0;
                        effects[i].type = 400;
                        field3158[i] = 0;
                        field3258[i] = 0;
                        field3468 = 0;
                        field3150 = 0;
                    }
                }
                break;
            case 0x1be:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.2;
                    effects[i].vy = -0.3;
                    effects[i].ay = 0.01;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                if ((field3468 == 1) && (effects[i].frame == 0)) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].field0084 = 99;
                    effects[i].vy = 0.0;
                    effects[i].vx = 3.5;
                    spawn.type = 0;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    pendingContextSoundSlot = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                }
                if ((effects[i].x > 680.0) ||
                    (effects[i].x < -40.0)) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        effects[i].field0080 = 0;
                        if (effects[i].frame >= frameCount) {
                            effects[i].frame -= 2;
                        }
                    }
                }
                break;
            case 0x1bf:
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
            case 0x1c0:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = -3.0;
                }
                effects[i].vy =
                effects[i].vy + 0.045;
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
            case 0x1c1:
                effects[i].field008c = 30000;
                if ((effects[i].frame == 0x10) &&
                    (effects[i].tick == 0)) {
                    (*opponentSlot)->field0108 =
                    (*opponentSlot)->field0108 + -5000;
                    (*opponentSlot)->koDelayFrames = 30000;
                    if ((field00ac + 1 < (int)(char)contextOwner->selection134e) ||
                        (0 < (*opponentSlot)->field0108)) {
                        (*opponentSlot)->field0008 = 99;
                        (*opponentSlot)->field000c = 0;
                        (*opponentSlot)->field000a = 0;
                        (*opponentSlot)->hitstopFrames = 0;
                        field000a = 0;
                        field000c = 0;
                        field0008 = 0x13d;
                    }
                }
                hitstunFrames = 2;
                if ((((effects[i].frame == 0x10) &&
                    (effects[i].tick == 0x1c2)) &&
                    (contextOwner->StartFade(0x32,100,100),
                    (*opponentSlot)->field0108 <= 0)) &&
                    (field00ac + 1 == (int)(char)contextOwner->selection134e)) {
                    contextOwner->StartFade(0x32,100,0x50);
                }
                if ((effects[i].frame == 0x11) &&
                    (effects[i].tick == 600)) {
                    contextOwner->StartFade(0x32,100,0x50);
                }
                if ((effects[i].frame == 0x12) &&
                    (effects[i].tick == 900)) {
                    (*opponentSlot)->koDelayFrames = 0;
                    (*opponentSlot)->hitstopFrames = 0;
                    hitstunFrames = 0;
                    break;
                }
                else {
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        effects[i].field0080 = 0;
                        if (((effects[i].frame == 1) &&
                            ((*opponentSlot)->field0108 <= 5000)) &&
                            (field00ac + 1 == (int)(char)contextOwner->selection134e)) {
                            pendingCharacterSoundSlot = 0xd;
                        }
                        if (effects[i].frame == 0x11) {
                            if (((*opponentSlot)->field0108 <= 0) &&
                                (field00ac + 1 == (int)(char)contextOwner->selection134e)) {
                                effects[i].frame = 0x11;
                            }
                            else {
                                RemoveLocalEffect((short)i);
                                contextOwner->state1420e = 0;
                                (*opponentSlot)->contextOwner->state1420e = 0;
                                contextOwner->state1420c = 0;
                            }
                        }
                        if (effects[i].frame >= frameCount) {
                            RemoveLocalEffect((short)i);
                        }
                    }
                }
                break;
            case 0x1c2:
                effects[i].x =
                (double)(facing * 7) + positionX;
                effects[i].y = positionY - 42.0;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 0x1c3;
                    }
                }
                break;
            case 0x1c3:
                effects[i].x =
                (double)(facing * 7) + positionX;
                effects[i].y = positionY - 42.0;
                if ((effects[i].frame == 1) &&
                    (effects[i].tick == 0)) {
                    pendingCharacterSoundSlot = 0xc;
                    spawn.type = 0x1c4;
                    spawn.x = (double)(facing * 9) + positionX;
                    spawn.y = positionY - 53.0;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.field0030 = 1;
                    EmitLocalEffect(&spawn);
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
            case 0x1c4:
                effects[i].x =
                (double)(facing * 9) + positionX;
                effects[i].y = positionY - 53.0;
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
            case 0x1c5:
                if (field3158[i] == 0) {
                    effects[i].vy = 0.15;
                    effects[i].vx = -1.0;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                }
                ++field3258[i];
                if ((((-75.0 <=
                    effects[i].vy +
                    effects[i].y) ||
                    (((0x31 < field0008 && (field0008 < 0x96)) ||
                    (0x14 < field3358[i])))) ||
                    (((0 < effects[i].field0080 || (0x4b0 < field3258[i])) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))))) ||
                    ((effects[i].x > 760.0 ||
                    (effects[i].x < -120.0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        if (field345c == 0) {
                            field345c = 3000;
                        }
                        else {
                            field345c = field345c + 1000;
                            if (3000 < field345c) {
                                field345c = 3000;
                            }
                        }
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                if ((field3158[i] == 1) &&
                    (effects[i].vx =
                    effects[i].vx + 0.01,
                    effects[i].vx > 0.0)) {
                    ++field3158[i];
                    effects[i].ax = 0.01;
                }
                if (effects[i].vx > 0.7) {
                    effects[i].ax = -0.01;
                }
                if (effects[i].vx < -0.7) {
                    effects[i].ax = 0.01;
                }
                if (1 < field3158[i]) {
                    effects[i].vx =
                    effects[i].vx +
                    effects[i].ax;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        ++field3358[i];
                    }
                }
                break;
            case 0x1c6:
                if (field3158[i] == 0) {
                    effects[i].vx = -0.3;
                    effects[i].vy = 0.0;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                }
                ++field3258[i];
                if ((((((0x31 < field0008) && (field0008 < 0x96)) ||
                    (6 < field3358[i])) ||
                    ((0 < effects[i].field0080 || (0x4b0 < field3258[i])))) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) ||
                    ((effects[i].x > 760.0 ||
                    (effects[i].x < -120.0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        if (field345c == 0) {
                            field345c = 3000;
                        }
                        else {
                            field345c = field345c + 1000;
                            if (3000 < field345c) {
                                field345c = 3000;
                            }
                        }
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                if ((field3158[i] == 1) &&
                    (effects[i].vy =
                    effects[i].vy + 0.01,
                    effects[i].vy > 0.0)) {
                    ++field3158[i];
                    effects[i].ay = 0.01;
                }
                if (effects[i].vy > 0.7) {
                    effects[i].ay = -0.01;
                }
                if (effects[i].vy < -0.7) {
                    effects[i].ay = 0.01;
                }
                if (1 < field3158[i]) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        ++field3358[i];
                    }
                }
                break;
            case 0x1c7:
                if (field3158[i] == 0) {
                    effects[i].vy =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + 0.05;
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 200)) * 0.01 - 1.0;
                    ++field3158[i];
                    effects[i].field0084 = 1;
                    if (effects[i].vx > 0.0) {
                        effects[i].ax = -0.01;
                    } else {
                        effects[i].ax = 0.01;
                    }
                }
                ++field3258[i];
                if (((((-75.0 <=
                    effects[i].vy +
                    effects[i].y) ||
                    ((0x31 < field0008 && (field0008 < 0x96)))) ||
                    (0x14 < field3358[i])) ||
                    (((0 < effects[i].field0080 || (0x4b0 < field3258[i])) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))))) ||
                    ((effects[i].x > 760.0 ||
                    (effects[i].x < -120.0)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    if (effects[i].field0080 == 3) {
                        ++field3460;
                        if (field345c == 0) {
                            field345c = 3000;
                        }
                        else {
                            field345c = field345c + 1000;
                            if (3000 < field345c) {
                                field345c = 3000;
                            }
                        }
                    }
                    if (5 < field3460) {
                        field3460 = 5;
                    }
                    break;
                }
                if (effects[i].vx > 1.0) {
                    effects[i].ax = -0.01;
                }
                if (effects[i].vx < -1.0) {
                    effects[i].ax = 0.01;
                }
                if (0 < field3158[i]) {
                    effects[i].vx =
                    effects[i].vx +
                    effects[i].ax;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        ++field3358[i];
                    }
                }
                break;
            case 0x1c8:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 4.0;
                    effects[i].vy = -2.5;
                }
                if ((field0008 > 49 && field0008 < 150) || (field0008 > 264 && field0008 < 268 && field000a == 0)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    break;
                }
                if (effects[i].frame == 1 && effects[i].x - (*opponentSlot)->positionX < 5.0 && effects[i].x - (*opponentSlot)->positionX > -5.0) {
                    spawn.type = 0x1cb;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        spawn.type = 0x1cb;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1c9:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 4.0;
                }
                if ((effects[i].frame == 1) &&
                    (((0.0 <
                    effects[i].x -
                    (*opponentSlot)->positionX &&
                    (effects[i].flag0048 == '\x01')) ||
                    ((effects[i].x -
                    (*opponentSlot)->positionX < 0.0 &&
                    (effects[i].flag0048 == -1)))))) {
                    effects[i].tick = 0;
                    effects[i].frame = 2;
                }
                if ((field0008 > 49 && field0008 < 150) || (field0008 > 264 && field0008 < 268 && field000a == 0)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        spawn.type = 0x1cc;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                break;
            case 0x1ca:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 4.0;
                    effects[i].vy = -2.5;
                }
                if (effects[i].frame == 1 && effects[i].x - (*opponentSlot)->positionX < 5.0 && effects[i].x - (*opponentSlot)->positionX > -5.0) {
                    spawn.type = 0x1cd;
                    spawn.x = effects[i].x;
                    spawn.y = effects[i].y;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.group = 2;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                    RemoveLocalEffect((short)i);
                    break;
                }
                if ((field0008 > 49 && field0008 < 150) || (field0008 > 264 && field0008 < 268 && field000a == 0)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].type = 0x1a8;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        spawn.type = 0x1cd;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1cb:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3158[i] = 0;
                }
                if (((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) {
                    field3158[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 10) &&
                        (field3158[i] != 1)) {
                        spawn.type = 0x1c5;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1cc:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3158[i] = 0;
                }
                if (((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) {
                    field3158[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 10) &&
                        (field3158[i] != 1)) {
                        spawn.type = 0x1c6;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1cd:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field3158[i] = 0;
                }
                if (((0x31 < field0008) && (field0008 < 0x96)) ||
                    ((0x108 < field0008 &&
                    ((field0008 < 0x10c && (field000a == 0)))))) {
                    field3158[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 10) &&
                        (field3158[i] != 1)) {
                        spawn.type = 0x1c7;
                        spawn.x = effects[i].x;
                        spawn.y = effects[i].y;
                        spawn.flag0018 = (unsigned char)facing;
                        spawn.group = 2;
                        spawn.layer = 1;
                        EmitLocalEffect(&spawn);
                        EmitLocalEffect(&spawn);
                    }
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
                    pendingContextSoundSlot = 0x22;
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
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3158[i];
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
                if (field3258[i] < 10) {
                    effects[i].group = 1;
                }
                if (field3258[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field3258[i];
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        effects[i].field0080 = 0;
                        if (effects[i].frame >= frameCount) {
                            effects[i].frame = 0;
                        }
                    }
                }
                break;
            case 0x1f2:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x3c + 0x78 + (unsigned int)(16000 < (std::rand())) * 0x28;
                    ++field3158[i];
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
                if (field3258[i] < 10) {
                    effects[i].group = 1;
                }
                if (field3258[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field3258[i];
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        effects[i].field0080 = 0;
                        if (effects[i].frame >= frameCount) {
                            effects[i].frame = 0;
                        }
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
