// Nayuki Character10::Slot07: canonical 27-case effects switch, partial native codegen.
 // Unreviewed later case bodies remain workbench experiments, never full Exact.
#include "../../src/CharacterViews.h"
#include <cstdlib>
#include <cmath>

void Character10::Slot07()
{
    int i;
    if ((*opponentSlot)->hitstunFrames > 0) return;
    i = (int)effectRead;
    EffectSpawn effect;
    while (i != effectWrite) {
        if (((effectActive[i] != 0) &&
            (effects[i].field0086 == 0)) &&
            (hitstunFrames == 0 ||
            (0 < hitstunFrames && (effects[i].field0088 != 0)))) {
            unsigned short frameDuration = patterns[effects[i].type].frames[effects[i].frame].duration;
            unsigned short frameCount = patterns[effects[i].type].count;
            ResetLocalEffectSpawn(&effect);
            switch(effects[i].type) {
            case 400:
                if (effects[i].frame == 5 && field3138 == 0) {
                    field3138 = 1;
                    effect.type = 0;
                    effect.x = (double)((int)effects[i].x + effects[i].flag0048 * 23);
                    effect.y = (double)((int)effects[i].y - 9);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.palette = 2;
                    contextOwner->EmitEffect(&effect);
                    effects[i].vx = -0.9;
                    effects[i].vy = -1.0;
                    effects[i].ay = 0.035;
                }
                effects[i].vy += effects[i].ay;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 7)
                        effects[i].group = 1;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x191:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    effects[i].vx = 0.3;
                    effects[i].vy = -1.2;
                    pendingCharacterSoundSlot = 0;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy += 0.045;
                    if (effects[i].vy + effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].frame = 1;
                        effects[i].layer = 1;
                    }
                }
                if (effects[i].frame > 4 &&
                    effects[i].vy + effects[i].y > 0.0) {
                    effects[i].field0058 = 0;
                }
                if (effects[i].group == 0 && field000a == 6 &&
                    field0008 == 0xfa && effects[i].frame < 5 &&
                    (((positionX - effects[i].x < 60.0 &&
                       positionX - effects[i].x > 0.0 && facing == -1) ||
                      (positionX - effects[i].x > -60.0 &&
                       positionX - effects[i].x < 0.0 && facing == 1)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 5;
                    effect.type = 0;
                    effect.x = (double)((int)positionX + facing * 30);
                    effect.y = (double)((int)positionY - 20);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.palette = 2;
                    contextOwner->EmitEffect(&effect);
                    effects[i].vx = 1.8;
                    effects[i].vy = -0.9;
                    effects[i].ay = 0.025;
                }
                if (effects[i].frame > 4)
                    effects[i].vy += effects[i].ay;
                if (effects[i].field0080 > 1) {
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].frame = 6;
                    effects[i].vy = -1.5;
                    effects[i].vx = -effects[i].vx * 0.5;
                    effects[i].ay = 0.035;
                }
                if (effects[i].frame == 7)
                    effects[i].group = 1;
                if (effects[i].y > 60.0)
                    RemoveLocalEffect((short)i);
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 2)
                        effects[i].group = 1;
                    if (effects[i].frame == 3)
                        RemoveLocalEffect((short)i);
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x192:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    effects[i].vx = 0.3;
                    effects[i].vy = -1.2;
                    pendingCharacterSoundSlot = 0;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy += 0.045;
                    if (effects[i].vy + effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].frame = 1;
                        effects[i].layer = 1;
                    }
                }
                if (field000a == 6 &&
                    field0008 == 0xfb && effects[i].frame < 5 &&
                    (((positionX - effects[i].x < 60.0 &&
                       positionX - effects[i].x > 0.0 && facing == -1) ||
                      (positionX - effects[i].x > -60.0 &&
                       positionX - effects[i].x < 0.0 && facing == 1)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 5;
                    effect.type = 0;
                    effect.x = (double)((int)positionX + facing * 30);
                    effect.y = (double)((int)positionY - 20);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.palette = 2;
                    contextOwner->EmitEffect(&effect);
                    effects[i].vx = 2.0;
                    effects[i].vy = -3.5;
                    effects[i].ay = 0.025;
                }
                if (effects[i].frame > 4)
                    effects[i].vy += effects[i].ay;
                if (effects[i].field0080 > 1) {
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].frame = 6;
                    effects[i].vy = -1.5;
                    effects[i].vx = -effects[i].vx * 0.5;
                    effects[i].ay = 0.035;
                }
                if (effects[i].frame == 7)
                    effects[i].group = 1;
                if (effects[i].y > 60.0)
                    RemoveLocalEffect((short)i);
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 2)
                        effects[i].group = 1;
                    if (effects[i].frame == 3)
                        RemoveLocalEffect((short)i);
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x193:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 5;
                    effects[i].vx = 0.3;
                    effects[i].vy = -1.2;
                    pendingCharacterSoundSlot = 0;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy += 0.045;
                    if (effects[i].vy + effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].frame = 1;
                        effects[i].layer = 1;
                    }
                }
                if (effects[i].frame > 4 &&
                    effects[i].vy + effects[i].y > 0.0) {
                    effects[i].field0058 = 0;
                }
                if (field000a == 6 &&
                    field0008 == 0xfc && effects[i].frame < 5 &&
                    (((positionX - effects[i].x < 60.0 &&
                       positionX - effects[i].x > 0.0 && facing == -1) ||
                      (positionX - effects[i].x > -60.0 &&
                       positionX - effects[i].x < 0.0 && facing == 1)))) {
                    effects[i].tick = 0;
                    effects[i].frame = 5;
                    effect.type = 0;
                    effect.x = (double)((int)positionX + facing * 30);
                    effect.y = (double)((int)positionY - 20);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.palette = 2;
                    contextOwner->EmitEffect(&effect);
                    effects[i].vx = 2.2;
                    effects[i].vy = -1.6;
                    effects[i].ay = 0.025;
                }
                if (effects[i].frame > 4)
                    effects[i].vy += effects[i].ay;
                if (effects[i].field0084 == 0 && effects[i].field0080 > 1) {
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].frame = 6;
                    effects[i].vy = -1.5;
                    effects[i].vx = -effects[i].vx * 0.5;
                    effects[i].ay = 0.035;
                }
                if (effects[i].frame == 7)
                    effects[i].group = 1;
                if (effects[i].y > 60.0)
                    RemoveLocalEffect((short)i);
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 2)
                        effects[i].group = 1;
                    if (effects[i].frame == 3)
                        RemoveLocalEffect((short)i);
                    if (effects[i].frame == 6)
                        --effects[i].frame;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x194:
                if (field0008 == 0xfe) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                } else {
                    effects[i].vx = 1.7;
                    effects[i].vy = -1.7;
                }
                if (effects[i].y <
                    (double)(contextOwner->cameraBounds.top - 40)) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        --effects[i].frame;
                }
                break;
            case 0x195:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x196:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].vx = 0.3;
                    effects[i].vy = -1.2;
                    pendingCharacterSoundSlot = 0;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy += 0.045;
                    if (effects[i].vy + effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].frame = 1;
                        effects[i].layer = 1;
                    }
                }
                if (effects[i].frame == 5 && effects[i].tick == 30) {
                    SetVerticalShake(5, 0);
                    effect.type = 0x199;
                    effect.x = (double)(int)effects[i].x;
                    effect.y = (double)(int)effects[i].y;
                    effect.flag0018 = facing;
                    effect.group = 2;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                    pendingCharacterSoundSlot = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x197:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].vx = 0.3;
                    effects[i].vy = -1.2;
                    pendingCharacterSoundSlot = 0;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy += 0.045;
                    if (effects[i].vy + effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].frame = 1;
                        effects[i].layer = 1;
                    }
                }
                if (effects[i].frame == 5 && effects[i].tick == 24) {
                    SetVerticalShake(10, 0);
                    effect.type = 0x19a;
                    effect.x = (double)((int)effects[i].x + 40);
                    effect.y = (double)(int)effects[i].y;
                    effect.flag0018 = facing;
                    effect.group = 2;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                    pendingCharacterSoundSlot = 1;
                }
                if (effects[i].frame == 5 && effects[i].tick == 30) {
                    effect.type = 0x19a;
                    effect.flag0018 = facing;
                    effect.group = 2;
                    effect.layer = 1;
                    effect.x = (double)((int)effects[i].x - 40);
                    effect.y = (double)(int)effects[i].y;
                    EmitLocalEffect(&effect);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x198:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].vx = 0.3;
                    effects[i].vy = -1.2;
                    pendingCharacterSoundSlot = 0;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy += 0.045;
                    if (effects[i].vy + effects[i].y > 0.0) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].frame = 1;
                        effects[i].layer = 1;
                    }
                }
                if (effects[i].frame == 5 && effects[i].tick == 19) {
                    SetVerticalShake(15, 0);
                    effect.type = 0x19b;
                    effect.x = (double)(int)effects[i].x;
                    effect.y = (double)((int)effects[i].y + 15);
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                    pendingCharacterSoundSlot = 1;
                }
                if (effects[i].frame == 5 && effects[i].tick == 24) {
                    effect.type = 0x19b;
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    effect.x = (double)((int)effects[i].x + 50);
                    effect.y = (double)((int)effects[i].y - 10);
                    EmitLocalEffect(&effect);
                }
                if (effects[i].frame == 5 && effects[i].tick == 30) {
                    effect.type = 0x19b;
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    effect.x = (double)((int)effects[i].x - 50);
                    effect.y = (double)((int)effects[i].y - 10);
                    EmitLocalEffect(&effect);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x199:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    pendingCharacterSoundSlot = 1;
                }
                if (effects[i].frame < 12 &&
                    (unsigned short)RandomRange(0, 100) < 14) {
                    effect.type = 0x19c;
                    effect.x = (double)(int)((effects[i].x - 50.0) +
                        (unsigned short)RandomRange(0, 100));
                    effect.y = (double)(int)(effects[i].y -
                        (unsigned short)RandomRange(0, 100));
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x19a:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    pendingCharacterSoundSlot = 1;
                }
                if (effects[i].frame < 12 &&
                    (unsigned short)RandomRange(0, 100) < 12) {
                    effect.type = 0x19c;
                    effect.x = (double)(int)((effects[i].x - 50.0) +
                        (unsigned short)RandomRange(0, 100));
                    effect.y = (double)(int)(effects[i].y -
                        (unsigned short)RandomRange(0, 100));
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x19b:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    pendingCharacterSoundSlot = 1;
                }
                if (effects[i].frame < 12 &&
                    (unsigned short)RandomRange(0, 100) < 10) {
                    effect.type = 0x19c;
                    effect.x = (double)(int)((effects[i].x - 50.0) +
                        (unsigned short)RandomRange(0, 100));
                    effect.y = (double)(int)(effects[i].y -
                        (unsigned short)RandomRange(0, 100));
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x19c:
                if (field315c[i] <= 0) {
                    effect.type = 0x22;
                    effect.x = (double)((int)effects[i].x +
                        (20 - (unsigned short)RandomRange(0, 40)) * facing);
                    effect.y = (double)((int)effects[i].y + 20 -
                        (unsigned short)RandomRange(0, 40));
                    effect.group = 2;
                    effect.layer = 1;
                    contextOwner->EmitEffect(&effect);
                    field315c[i] = 2;
                }
                --field315c[i];
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x19d:
                if ((field0008 == 0x12f ||
                     field0008 == 0x130 ||
                     field0008 == 0x131) && field000a < 8) {
                    effects[i].x = positionX;
                    effects[i].y = positionY - 80.0;
                } else {
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].type = 0x195;
                }
                field314c = (int)effects[i].x;
                field3154 = (int)effects[i].y;
                if (effects[i].frame == 0 && effects[i].tick == 0 &&
                    field315c[i] <= 0) {
                    effect.type = 0x19f;
                    effect.x = (double)(int)effects[i].x;
                    effect.y = (double)(int)effects[i].y;
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                    field315c[i] = 3;
                    if (field0008 == 0x130)
                        field315c[i] = 2;
                    if (field0008 == 0x131)
                        field315c[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        --field315c[i];
                    }
                }
                break;
            case 0x19e:
                if ((field0008 == 0x12f ||
                     field0008 == 0x130 ||
                     field0008 == 0x131) && field000a < 8) {
                    effects[i].x = positionX;
                    effects[i].y = positionY;
                } else {
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].type = 0x195;
                }
                field3150 = (int)effects[i].x;
                field3158 = (int)effects[i].y;
                if (effects[i].frame == 0 && effects[i].tick == 0 &&
                    field315c[i] <= 0) {
                    effect.type = 0x1a0;
                    effect.x = (double)(int)effects[i].x;
                    effect.y = (double)(int)effects[i].y;
                    effect.group = 2;
                    effect.flag0018 = facing;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                    field315c[i] = 3;
                    if (field0008 == 0x130)
                        field315c[i] = 2;
                    if (field0008 == 0x131)
                        field315c[i] = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        --field315c[i];
                    }
                }
                break;
            case 0x19f:
                if (field0008 == 0x12f || field0008 == 0x130 ||
                    field0008 == 0x131) {
                    effects[i].x = (double)field314c;
                    effects[i].y = (double)field3154;
                }
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    pendingCharacterSoundSlot = 2;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x1a0:
                if (field0008 == 0x12f || field0008 == 0x130 ||
                    field0008 == 0x131) {
                    effects[i].x = (double)field3150;
                    effects[i].y = (double)field3158;
                }
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    pendingCharacterSoundSlot = 2;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x1a1:
                if (effects[i].frame == 0 && field315c[i] == 0) {
                    field315c[i] = 1;
                    effects[i].vx = -1.9;
                    effects[i].vy = -2.5;
                    effects[i].ay = 0.035;
                }
                effects[i].vy += effects[i].ay;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 7)
                        effects[i].group = 1;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x1ab:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    effects[i].vx = 0.3;
                    effects[i].vy = -3.5;
                    effects[i].ay = 0.045;
                }
                effects[i].vy += effects[i].ay;
                if (effects[i].vy + effects[i].y > 0.0)
                    effects[i].field0058 = 0;
                if (effects[i].field0080 > 1) {
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].frame = 1;
                    effects[i].vy = -1.5;
                    effects[i].vx = -effects[i].vx * 0.5;
                    effects[i].ay = 0.035;
                }
                if (effects[i].y > 60.0)
                    RemoveLocalEffect((short)i);
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x1ac:
                if (effects[i].frame == 0 && effects[i].tick == 0) {
                    effects[i].field0084 = 1;
                    effects[i].vx = 0.8;
                    effects[i].vy = -3.5;
                    effects[i].ay = 0.045;
                }
                effects[i].vy += effects[i].ay;
                if (effects[i].vy + effects[i].y > 0.0)
                    effects[i].field0058 = 0;
                if (effects[i].field0080 > 1) {
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].frame = 1;
                    effects[i].vy = -1.5;
                    effects[i].vx = -effects[i].vx * 0.5;
                    effects[i].ay = 0.035;
                }
                if (effects[i].y > 60.0)
                    RemoveLocalEffect((short)i);
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount)
                        RemoveLocalEffect((short)i);
                }
                break;
            case 0x1ad:
                if (((effects[i].frame == 0x1c) &&
                    (effects[i].tick == 0)) &&
                    (field000a < 0x10 && (200 < field0008))) {
                    effect.owner = 1;
                    effect.type = 0x1ad;
                    effect.x = (double)((int(positionX)) - facing * 0xf);
                    effect.y = effects[i].y;
                    effect.flag0018 = (unsigned char)facing;
                    effect.group = 2;
                    effect.layer = true;
                    EmitLocalEffect(&effect);
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
            case 0x1ae:
                if (((effects[i].frame == 8) &&
                    (effects[i].tick == 0)) &&
                    (field000a < 0x10 && (200 < field0008))) {
                    effect.owner = 1;
                    effect.type = 0x1ae;
                    effect.x = (double)((int(positionX)) - facing * 0xf);
                    effect.y = (double)(int(effects[i].y));
                    effect.flag0018 = (unsigned char)facing;
                    effect.group = 2;
                    effect.layer = true;
                    EmitLocalEffect(&effect);
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
                if ((field0008 != 83 && field0008 != 84 && field0008 != 85 && field0008 != 86) ||
                    (field0008 == 83 && field000a > 1) || (field0008 == 84 && field000a > 1)) {
                    effect.type = 0x1f1;
                    effect.x = (double)((int(positionX)) + facing * 0x17);
                    effect.y = (double)((int(positionY)) + -4);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f1;
                    effect.x = (double)((int(positionX)) - facing * 4);
                    effect.y = (double)((int(positionY)) + -6);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f1;
                    effect.x = (double)((int(positionX)) - facing * 0xe);
                    effect.y = (double)((int(positionY)) + -0x1a);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f1;
                    effect.x = (double)(int(positionX));
                    effect.y = (double)(int(positionY));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f1;
                    effect.x = (double)((int(positionX)) + facing * 0x1e);
                    effect.y = (double)((int(positionY)) + -0x28);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f1;
                    effect.x = (double)((int(positionX)) - facing * 0x19);
                    effect.y = (double)((int(positionY)) + -0x50);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f2;
                    effect.x = (double)((int(positionX)) - facing * 0x23);
                    effect.y = (double)((int(positionY)) + -0x2a);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f2;
                    effect.x = (double)((int(positionX)) - facing * 0x12);
                    effect.y = (double)((int(positionY)) + -0x14);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f2;
                    effect.x = (double)((int(positionX)) + facing * 2);
                    effect.y = (double)((int(positionY)) + -0x41);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1f2;
                    effect.x = (double)((int(positionX)) + facing * 0x10);
                    effect.y = (double)((int(positionY)) + -0x50);
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
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
                    (effects[i].tick == 0)) && (field315c[i] == 0)) {
                    field325c[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field315c[i];
                    effects[i].vx =
                    (double)(16000 < std::rand()) * 1.2 +
                    (double)(16000 < std::rand()) * 0.7 +
                    (double)(16000 < std::rand()) * 1.7 + -1.8;
                    effects[i].vy =
                    -1.2 - ((double)(16000 < std::rand()) * 0.6 +
                        (double)(16000 < std::rand()) * 0.9 +
                        (double)(16000 < std::rand()) * 1.4);
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if ((effects[i].y > 0.0) &&
                    (effects[i].vy > 0.0)) {
                    effects[i].vy =
                    -effects[i].vy;
                }
                if (field325c[i] < 10) {
                    effects[i].group = 1;
                }
                if (field325c[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field325c[i];
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
                    (effects[i].tick == 0)) && (field315c[i] == 0)) {
                    field325c[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x3c + 0x78 + (unsigned int)(16000 < (std::rand())) * 0x28;
                    ++field315c[i];
                    effects[i].vx =
                    (double)(16000 < std::rand()) +
                    (double)(16000 < std::rand()) * 0.5 +
                    (double)(16000 < std::rand()) * 1.5 + -1.5;
                    effects[i].vy =
                    -1.0 - ((double)(16000 < std::rand()) * 0.5 +
                        (double)(16000 < std::rand()) * 0.8 +
                        (double)(16000 < std::rand()) * 1.2);
                }
                effects[i].vy =
                effects[i].vy + 0.03;
                if ((effects[i].y > 0.0) &&
                    (effects[i].vy > 0.0)) {
                    effects[i].vy =
                    -effects[i].vy;
                }
                if (field325c[i] < 10) {
                    effects[i].group = 1;
                }
                if (field325c[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field325c[i];
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
