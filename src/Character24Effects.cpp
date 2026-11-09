// Mizuka complete local-effect update and lifetime dispatch.
#include "Character24.h"
#include <cstdlib>

void Character24::Slot07()
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
                if (field0008 != 0xd0) {
                    RemoveLocalEffect((short)i);
                }
                effects[i].x =
                (double)(facing * 0x25) + positionX;
                effects[i].y = positionY - 72.0;
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
                effects[i].x =
                (double)((int)facing << 2) + positionX;
                effects[i].y = positionY + 5.0;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (((effects[i].frame == 4) &&
                        (field0008 == 0xd1)) && (field000a < 8)) {
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x196:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    field02c8 = 0;
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
            case 0x198:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    field02c8 = 0;
                }
                if ((((effects[i].frame == 9) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].x > 0.0)) &&
                    (effects[i].x < 640.0)) {
                    spawn.type = 0x199;
                    spawn.x = (double)((int(effects[i].x)) + effects[i].flag0048 * 0x3c);
                    spawn.y = 0.0;
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)effects[i].flag0048;
                    EmitLocalEffect(&spawn);
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
            case 0x199:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    field02c8 = 0;
                }
                if (((effects[i].frame == 9) &&
                    (effects[i].tick == 0)) &&
                    ((effects[i].x > 0.0 &&
                    (effects[i].x < 640.0)))) {
                    spawn.type = 0x19a;
                    spawn.x = (double)((int(effects[i].x)) + effects[i].flag0048 * 0x3c);
                    spawn.y = 0.0;
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)effects[i].flag0048;
                    EmitLocalEffect(&spawn);
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
            case 0x19a:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    field02c8 = 0;
                }
                if ((((effects[i].frame == 9) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].x > 0.0)) &&
                    (effects[i].x < 640.0)) {
                    spawn.type = 0x198;
                    spawn.x = (double)((int(effects[i].x)) + effects[i].flag0048 * 0x3c);
                    spawn.y = 0.0;
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)effects[i].flag0048;
                    EmitLocalEffect(&spawn);
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
            case 0x19b:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + 0.7;
                    effects[i].field0084 = 1;
                    ++field3148[i];
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
                if (((effects[i].x < -30.0) &&
                    (effects[i].flag0048 == -1)) ||
                    ((effects[i].x > 670.0 &&
                    (effects[i].flag0048 == '\x01')))) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x19c:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + 0.7;
                    effects[i].field0084 = 1;
                    ++field3148[i];
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
                if (((effects[i].x < -30.0) &&
                    (effects[i].flag0048 == -1)) ||
                    ((effects[i].x > 670.0 &&
                    (effects[i].flag0048 == '\x01')))) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x19d:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + 0.7;
                    effects[i].field0084 = 1;
                    ++field3148[i];
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
                if (((effects[i].x < -30.0) &&
                    (effects[i].flag0048 == -1)) ||
                    ((effects[i].x > 670.0 &&
                    (effects[i].flag0048 == '\x01')))) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x19e:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + 0.7;
                    effects[i].field0084 = 1;
                    ++field3148[i];
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
                if (((effects[i].x < -30.0) &&
                    (effects[i].flag0048 == -1)) ||
                    ((effects[i].x > 670.0 &&
                    (effects[i].flag0048 == '\x01')))) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x19f:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + 0.7;
                    effects[i].field0084 = 1;
                    ++field3148[i];
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
                if (((effects[i].x < -30.0) &&
                    (effects[i].flag0048 == -1)) ||
                    ((effects[i].x > 670.0 &&
                    (effects[i].flag0048 == '\x01')))) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1a0:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + 0.7;
                    effects[i].field0084 = 1;
                    ++field3148[i];
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
                if (((effects[i].x < -30.0) &&
                    (effects[i].flag0048 == -1)) ||
                    ((effects[i].x > 670.0 &&
                    (effects[i].flag0048 == '\x01')))) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1a1:
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.5;
                    effects[i].vy = 0.0;
                    effects[i].field0084 = 1;
                }
                if ((effects[i].field0080 == 3) &&
                    (effects[i].frame < 0x25)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x25;
                    effects[i].vx = 0.0;
                    field02c8 = 0xc;
                    break;
                }
                if (effects[i].field0080 > 1 && effects[i].frame < 37) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x28;
                    effects[i].vx = 0.0;
                    break;
                }
                if ((effects[i].frame == 0x25) &&
                    (effects[i].field0080 == 3)) {
                    (*opponentSlot)->ResetFrame();
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->field0008 = 0x79;
                    effects[i].field0080 = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0x25) {
                        if (field3148[i] < 6) {
                            effects[i].frame = 4;
                            ++field3148[i];
                        }
                        else {
                            effects[i].vx = 0.0;
                            effects[i].frame = 0x28;
                        }
                    }
                    if ((effects[i].frame >= frameCount) &&
                        (RemoveLocalEffect((short)i), (*opponentSlot)->field0008 == 0x79))
                    {
                        (*opponentSlot)->ResetPose();
                        (*opponentSlot)->ResetFrame();
                        (*opponentSlot)->positionY = -480.0;
                        (*opponentSlot)->positionX = positionX;
                        (*opponentSlot)->field0008 = 0x3b;
                    }
                }
                break;
            case 0x1a2:
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.35;
                    effects[i].vy = -0.35;
                    effects[i].field0084 = 1;
                }
                if ((effects[i].field0080 == 3) &&
                    (effects[i].frame < 0x25)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x25;
                    effects[i].vx = 0.0;
                    field02c8 = 0xc;
                    break;
                }
                if (effects[i].field0080 > 1 && effects[i].frame < 37) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x28;
                    effects[i].vx = 0.0;
                    break;
                }
                if ((effects[i].frame == 0x25) &&
                    (effects[i].field0080 == 3)) {
                    (*opponentSlot)->ResetFrame();
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->field0008 = 0x79;
                    effects[i].field0080 = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0x25) {
                        if (field3148[i] < 6) {
                            effects[i].frame = 4;
                            ++field3148[i];
                        }
                        else {
                            effects[i].vx = 0.0;
                            effects[i].frame = 0x28;
                        }
                    }
                    if ((effects[i].frame >= frameCount) &&
                        (RemoveLocalEffect((short)i), (*opponentSlot)->field0008 == 0x79))
                    {
                        (*opponentSlot)->ResetPose();
                        (*opponentSlot)->ResetFrame();
                        (*opponentSlot)->positionY = -480.0;
                        (*opponentSlot)->positionX = positionX;
                        (*opponentSlot)->field0008 = 0x3b;
                    }
                }
                break;
            case 0x1a3:
                if ((effects[i].frame >= 4) &&
                    (effects[i].frame < 0x25)) {
                    field3348[i] = (int(VectorAngle( (*opponentSlot)->positionX - effects[i].x, ((*opponentSlot)->positionY - 50.0 ) - effects[i].y)));
                    effects[i].SetVelocityPolar((double)field3348[i],
                        -0.00875);
                    effects[i].ax =
                    effects[i].vx;
                    effects[i].ay =
                    effects[i].vy;
                    effects[i].SetVelocityPolar((double)field3348[i],
                        1.4);
                    if (effects[i].flag0048 == -1) {
                        effects[i].ax =
                        -effects[i].ax;
                        effects[i].vx =
                        -effects[i].vx;
                    }
                    effects[i].field0084 = 1;
                }
                if ((effects[i].field0080 == 3) &&
                    (effects[i].frame < 0x25)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x25;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    field3454 = 1;
                    field02c8 = 0xc;
                    break;
                }
                if (effects[i].field0080 > 1 && effects[i].frame < 37) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x28;
                    effects[i].vx = 0.0;
                    break;
                }
                if ((effects[i].frame == 0x25) &&
                    (effects[i].field0080 == 3)) {
                    (*opponentSlot)->ResetFrame();
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->field0008 = 0x79;
                    effects[i].field0080 = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0x25) {
                        if (field3148[i] < 6) {
                            effects[i].frame = 4;
                            ++field3148[i];
                        }
                        else {
                            effects[i].vx = 0.0;
                            effects[i].frame = 0x28;
                        }
                    }
                    if ((effects[i].frame >= frameCount) &&
                        (RemoveLocalEffect((short)i), (*opponentSlot)->field0008 == 0x79))
                    {
                        (*opponentSlot)->ResetPose();
                        (*opponentSlot)->ResetFrame();
                        (*opponentSlot)->positionY = -480.0;
                        (*opponentSlot)->positionX = positionX;
                        (*opponentSlot)->field0008 = 0x3b;
                    }
                }
                if ((field3454 == 1) && (effects[i].frame < 0x25)
                    ) {
                    effects[i].frame = 0x25;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                }
                break;
            case 0x1a4:
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.35;
                    effects[i].vy = 0.35;
                    effects[i].field0084 = 1;
                }
                if ((effects[i].field0080 == 3) &&
                    (effects[i].frame < 0x25)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x25;
                    effects[i].vx = 0.0;
                    field02c8 = 0xc;
                    break;
                }
                if (effects[i].field0080 > 1 && effects[i].frame < 37) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x28;
                    effects[i].vx = 0.0;
                    break;
                }
                if ((effects[i].frame == 0x25) &&
                    (effects[i].field0080 == 3)) {
                    (*opponentSlot)->ResetFrame();
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->field0008 = 0x79;
                    effects[i].field0080 = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0x25) {
                        if (field3148[i] < 6) {
                            effects[i].frame = 4;
                            ++field3148[i];
                        }
                        else {
                            effects[i].vx = 0.0;
                            effects[i].frame = 0x28;
                        }
                    }
                    if ((effects[i].frame >= frameCount) &&
                        (RemoveLocalEffect((short)i), (*opponentSlot)->field0008 == 0x79))
                    {
                        (*opponentSlot)->ResetPose();
                        (*opponentSlot)->ResetFrame();
                        (*opponentSlot)->positionY = -480.0;
                        (*opponentSlot)->positionX = positionX;
                        (*opponentSlot)->field0008 = 0x3b;
                    }
                }
                break;
            // The target places type437 between420 and421.
        case 0x1b5:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    field02c8 = 1;
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
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].field0084 = 1, field3148[i] == 0))
                {
                    effects[i].vy = -1.1;
                    effects[i].vx = 0.3;
                    ++field3148[i];
                }
                if ((field000a == 1) && (field3138 == 0x1e)) {
                    RemoveLocalEffect((short)i);
                }
                effects[i].vx =
                effects[i].vx - 0.002;
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
            case 0x1a6:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].field0084 = 1, field3148[i] == 0))
                {
                    effects[i].vy = -1.1;
                    effects[i].vx = 0.3;
                    ++field3148[i];
                }
                if ((field000a == 1) && (field3138 == 0x1e)) {
                    RemoveLocalEffect((short)i);
                }
                effects[i].vx =
                effects[i].vx - 0.002;
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
            case 0x1a7:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].field0084 = 1, field3148[i] == 0))
                {
                    effects[i].vy = -1.1;
                    effects[i].vx = 0.3;
                    ++field3148[i];
                }
                if ((field000a == 1) && (field3138 == 0x1e)) {
                    RemoveLocalEffect((short)i);
                }
                effects[i].vx =
                effects[i].vx - 0.002;
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
            case 0x1a8:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].field0084 = 1, field3148[i] == 0))
                {
                    effects[i].vy = -1.1;
                    effects[i].vx = 0.3;
                    ++field3148[i];
                }
                if ((field000a == 1) && (field3138 == 0x1e)) {
                    RemoveLocalEffect((short)i);
                }
                effects[i].vx =
                effects[i].vx - 0.002;
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
            case 0x1a9:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].field0084 = 1, field3148[i] == 0))
                {
                    effects[i].vy = -1.1;
                    effects[i].vx = 0.3;
                    ++field3148[i];
                }
                if ((field000a == 1) && (field3138 == 0x1e)) {
                    RemoveLocalEffect((short)i);
                }
                effects[i].vx =
                effects[i].vx - 0.002;
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
            case 0x1aa:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) &&
                    (effects[i].field0084 = 1, field3148[i] == 0))
                {
                    effects[i].vy = -1.1;
                    effects[i].vx = 0.3;
                    ++field3148[i];
                }
                if ((field000a == 1) && (field3138 == 0x1e)) {
                    RemoveLocalEffect((short)i);
                }
                effects[i].vx =
                effects[i].vx - 0.002;
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
            case 0x1ac:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = 0.5;
                    effects[i].vx = 2.5;
                }
                if ((field3140 == 1) && (field3348[i] == 0)) {
                    effects[i].field0084 = 1;
                    field3148[i] = (int(effects[i].vx * 100.0));
                    field3248[i] = (int(effects[i].vy * 100.0));
                    field3348[i] = 1;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                }
                if ((field3140 == 0) && (field3348[i] == 1)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)field3148[i] * 0.01;
                    effects[i].vy =
                    (double)field3248[i] * 0.01;
                    field3348[i] = 2;
                }
                if (1 < field000a) {
                    RemoveLocalEffect((short)i);
                }
                if (field3140 != 1) {
                    effects[i].vy =
                    effects[i].vy - 0.01;
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
            case 0x1ad:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = 0.5;
                    effects[i].vx = 2.5;
                }
                if ((field3140 == 1) && (field3348[i] == 0)) {
                    effects[i].field0084 = 1;
                    field3148[i] = (int(effects[i].vx * 100.0));
                    field3248[i] = (int(effects[i].vy * 100.0));
                    field3348[i] = 1;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                }
                if ((field3140 == 0) && (field3348[i] == 1)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)field3148[i] * 0.01;
                    effects[i].vy =
                    (double)field3248[i] * 0.01;
                    field3348[i] = 2;
                }
                if (1 < field000a) {
                    RemoveLocalEffect((short)i);
                }
                if (field3140 != 1) {
                    effects[i].vy =
                    effects[i].vy - 0.01;
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
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = 0.5;
                    effects[i].vx = 2.5;
                }
                if ((field3140 == 1) && (field3348[i] == 0)) {
                    effects[i].field0084 = 1;
                    field3148[i] = (int(effects[i].vx * 100.0));
                    field3248[i] = (int(effects[i].vy * 100.0));
                    field3348[i] = 1;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                }
                if ((field3140 == 0) && (field3348[i] == 1)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)field3148[i] * 0.01;
                    effects[i].vy =
                    (double)field3248[i] * 0.01;
                    field3348[i] = 2;
                }
                if (1 < field000a) {
                    RemoveLocalEffect((short)i);
                }
                if (field3140 != 1) {
                    effects[i].vy =
                    effects[i].vy - 0.01;
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
            case 0x1af:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = 0.5;
                    effects[i].vx = 2.5;
                }
                if ((field3140 == 1) && (field3348[i] == 0)) {
                    effects[i].field0084 = 1;
                    field3148[i] = (int(effects[i].vx * 100.0));
                    field3248[i] = (int(effects[i].vy * 100.0));
                    field3348[i] = 1;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                }
                if ((field3140 == 0) && (field3348[i] == 1)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)field3148[i] * 0.01;
                    effects[i].vy =
                    (double)field3248[i] * 0.01;
                    field3348[i] = 2;
                }
                if (1 < field000a) {
                    RemoveLocalEffect((short)i);
                }
                if (field3140 != 1) {
                    effects[i].vy =
                    effects[i].vy - 0.01;
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
            case 0x1b0:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = 0.5;
                    effects[i].vx = 2.5;
                }
                if ((field3140 == 1) && (field3348[i] == 0)) {
                    effects[i].field0084 = 1;
                    field3148[i] = (int(effects[i].vx * 100.0));
                    field3248[i] = (int(effects[i].vy * 100.0));
                    field3348[i] = 1;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                }
                if ((field3140 == 0) && (field3348[i] == 1)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)field3148[i] * 0.01;
                    effects[i].vy =
                    (double)field3248[i] * 0.01;
                    field3348[i] = 2;
                }
                if (1 < field000a) {
                    RemoveLocalEffect((short)i);
                }
                if (field3140 != 1) {
                    effects[i].vy =
                    effects[i].vy - 0.01;
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
            case 0x1b2:
                if (field000a == 1) {
                    RemoveLocalEffect((short)i);
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
            case 0x1b6:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = 0.5;
                    effects[i].vx = 2.5;
                }
                if ((effects[i].frame == 2) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    field3148[i] = (int(effects[i].vx * 100.0));
                    field3248[i] = (int(effects[i].vy * 100.0));
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    (*opponentSlot)->field0008 = 0x45;
                    (*opponentSlot)->positionY =
                    effects[i].y - 81.0;
                    (*opponentSlot)->positionX =
                    effects[i].x;
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->ResetFrame();
                    (*opponentSlot)->knockbackVelocityX = -6.0;
                    (*opponentSlot)->knockbackVelocityY = 4.0;
                    (*opponentSlot)->facing = -effects[i].flag0048;
                }
                if ((effects[i].frame == 2) ||
                    (effects[i].frame == 3)) {
                    --field3138;
                }
                if ((((*opponentSlot)->positionY == 0.0) &&
                    (field3348[i] == 0)) &&
                    (effects[i].frame == 2)) {
                    ApplyDamage(0x170c,500.0);
                    ++field3348[i];
                    field02c9 = 0x16;
                }
                if ((*opponentSlot)->field0008 == 99) {
                    (*opponentSlot)->field000c = 0;
                }
                if ((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx =
                    (double)field3148[i] * 0.01;
                    effects[i].vy =
                    (double)field3248[i] * 0.01;
                }
                if (((effects[i].frame == 4) &&
                    ((unsigned int)effects[i].tick == frameDuration - 0xc)) &&
                    ((field00ac == '\0' ||
                    ((field00ac == '\x01' && (0 < (*opponentSlot)->field0108))))))
                {
                    contextOwner->StartFade(9,3,0xc);
                }
                if (effects[i].frame != 2) {
                    effects[i].vy =
                    effects[i].vy - 0.01;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 2) {
                        field3140 = 1;
                    }
                    if (effects[i].frame == 4) {
                        field3140 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field313c = (int(effects[i].x));
                        field3140 = (int(effects[i].y - 130.0));
                    }
                }
                break;
            case 0x1b7:
                if (((field0008 == 0x132) || (field0008 == 0x133)) ||
                    (field0008 == 0x134)) {
                    if (field000a == 0x1c) {
                        effects[i].frame = 2;
                    }
                    if ((field000a != 0x1c) &&
                        (effects[i].frame == 2)) {
                        effects[i].frame = 1;
                    }
                }
                if (((field0008 < 0x132) || (0x134 < field0008)) &&
                    (effects[i].frame < 4)) {
                    effects[i].frame = 4;
                    effects[i].tick = 0;
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
            case 0x1b8:
                if ((field0008 < 0x132) || (0x134 < field0008)) {
                    field3448 = 0;
                }
                if (effects[i].frame == 9) {
                    (*opponentSlot)->field000a = 1;
                }
                if (effects[i].frame == 10) {
                    (*opponentSlot)->field000a = 2;
                }
                if (effects[i].frame == 0xc) {
                    (*opponentSlot)->field000a = 3;
                }
                if (effects[i].frame == 0xd) {
                    (*opponentSlot)->field000a = 4;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].vy = 1.5;
                    field02c8 = 5;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                    if ((effects[i].field0080 == 3) &&
                        (0 < (*opponentSlot)->field0108)) {
                        effects[i].layer = 0;
                        field3448 = 1;
                        effects[i].field0086 = 0x3c;
                        (*opponentSlot)->hitstopFrames = 0x3c;
                        effects[i].field0080 = 0;
                        break;
                    }
                    if (0.0 <
                        effects[i].y +
                        effects[i].vy) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].frame = 1;
                        effects[i].tick = 0;
                    }
                }
                if ((effects[i].frame == 2) &&
                    (effects[i].tick == 0)) {
                    effects[i].vy = -0.8;
                }
                if (((effects[i].frame == 2) ||
                    (effects[i].frame == 3)) &&
                    (effects[i].vy =
                    effects[i].vy + 0.035,
                    0.0 <
                    effects[i].vy +
                    effects[i].y)) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].frame = 4;
                    effects[i].tick = 0;
                }
                if (((field0008 == 0x132) || (field0008 == 0x133)) ||
                    (field0008 == 0x134)) {
                    if ((effects[i].frame == 1) &&
                        (effects[i].tick == 0)) {
                        effects[i].x = 420.0;
                        effects[i].frame = 7;
                        effects[i].tick = 0;
                        effects[i].flag0048 = facing;
                    }
                    if ((effects[i].frame == 7) && (field344c == 1)) {
                        effects[i].frame = 8;
                        effects[i].tick = 0;
                        break;
                    }
                    if ((effects[i].frame == 10) &&
                        (field344c == 1)) {
                        effects[i].frame = 0xb;
                        effects[i].tick = 0;
                        break;
                    }
                    if ((effects[i].frame == 0xd) &&
                        (field344c == 1)) {
                        effects[i].frame = 0xe;
                        effects[i].tick = 0;
                        break;
                    }
                    if ((field344c == 1) &&
                        (((effects[i].frame == 8 ||
                        (effects[i].frame == 0xb)) ||
                        (effects[i].frame == 0xe)))) {
                        effects[i].field0086 = 0x1e;
                        (*opponentSlot)->hitstopFrames = 0x1e;
                        field344c = 0;
                        if (effects[i].frame == 0xe) {
                            field02c8 = 9;
                        }
                    }
                    if ((((effects[i].frame == 8) ||
                        (effects[i].frame == 0xb)) &&
                        (effects[i].tick == 0xd2)) ||
                        ((effects[i].frame == 0xe &&
                        (effects[i].tick == 0x294)))) {
                        if (((unsigned short)RandomRange(0, 9)) < 5) {
                            field02c8 = 6;
                            field3448 = 3;
                            ++effects[i].tick;
                            break;
                        }
                        field02c8 = 7;
                        field3448 = 4;
                    }
                    if ((((effects[i].frame == 8) ||
                        (effects[i].frame == 0xb)) &&
                        (effects[i].tick == 0x14a)) ||
                        ((effects[i].frame == 0xe &&
                        (effects[i].tick == 0x30c)))) {
                        if (field3448 == 4) {
                            spawn.type = 0;
                            spawn.x = (double)(int((*opponentSlot)->positionX));
                            spawn.y = -80.0;
                            spawn.group = 2;
                            spawn.layer = 1;
                            spawn.palette = 0x16;
                            contextOwner->EmitEffect(&spawn);
                            field3448 = 5;
                            effects[i].layer = 1;
                            (*opponentSlot)->field0008 = 0x47;
                            (*opponentSlot)->ResetPose();
                            (*opponentSlot)->knockbackVelocityY = -13.0;
                            (*opponentSlot)->knockbackVelocityX = 0.0;
                            if (effects[i].frame == 8) {
                                ApplyDamage(0x708,50.0);
                                effects[i].frame = 0xf;
                            }
                            if (effects[i].frame == 0xb) {
                                ApplyDamage(0xdac,50.0);
                                effects[i].frame = 0x12;
                            }
                            if (effects[i].frame == 0xe) {
                                ApplyDamage(0x1964,50.0);
                                effects[i].frame = 0x15;
                            }
                            effects[i].tick = 0;
                            field313c = 0xb;
                        }
                        if ((field3448 == 3) &&
                            (((field0008 == 0x132 ||
                            ((field0008 == 0x133 && (field3138 == 1)))) ||
                            ((field0008 == 0x134 && (field3138 == 2)))))) {
                            effects[i].group = 1;
                            (*opponentSlot)->field0008 = 0x3b;
                            (*opponentSlot)->ResetPose();
                            (*opponentSlot)->knockbackVelocityY = -2.0;
                            (*opponentSlot)->knockbackVelocityX = 0.0;
                        }
                    }
                    if (((((effects[i].frame == 8 || effects[i].frame == 11) && effects[i].tick == 345) ||
                        (effects[i].frame == 14 && effects[i].tick == 795))) && effects[i].group == 1) {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                    if (((field0008 == 0x133) || (field0008 == 0x134)) &&
                        ((field000a == 0x1c && ((unsigned short)field000c == 0)))) {
                        field02c8 = 8;
                        effects[i].tick = 0;
                        ++effects[i].frame;
                    }
                }
                ++effects[i].tick;
                if ((((effects[i].frame == 0x11) ||
                    (effects[i].frame == 0x14)) ||
                    (effects[i].frame == 0x17)) &&
                    ((unsigned int)effects[i].tick == frameDuration - 0xf)) {
                    effects[i].group = 1;
                }
                if ((((effects[i].frame == 0x11) ||
                    (effects[i].frame == 0x14)) ||
                    (effects[i].frame == 0x17)) &&
                    (effects[i].tick == frameDuration)) {
                    RemoveLocalEffect((short)i);
                    field3448 = 5;
                    break;
                }
                else if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 6) {
                        effects[i].group = 1;
                    }
                    if (effects[i].frame == 7) {
                        RemoveLocalEffect((short)i);
                    }
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
                effects[i].x =
                positionX - (double)(facing * 7);
                effects[i].y = positionY - 41.0;
                if (field0008 != 0xcf) {
                    RemoveLocalEffect((short)i);
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
            case 0x1bc:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(0.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1bd:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(0.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1be:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(0.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1bf:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(0.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1c0:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(-35.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1c1:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(-60.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1c2:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(-60.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1c3:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].SetVelocityPolar(-85.0,3.6);
                }
                if (effects[i].field0080 > 0 && effects[i].frame == 0) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    effects[i].vx = -0.9;
                    effects[i].vy = -2.7;
                    break;
                }
                if (effects[i].frame > 0) {
                    effects[i].vy =
                    effects[i].vy + 0.045;
                }
                if (0.0 <
                    effects[i].y +
                    effects[i].vy) {
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -0.5 * effects[i].vy;
                    if (effects[i].group == 0) {
                        effects[i].group = 1;
                    } else {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) ||
                    (effects[i].y < -510.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x1c4:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    field02c8 = 4;
                }
                if ((((effects[i].frame == 4) &&
                    (effects[i].tick == 0)) &&
                    (field000a < 0xc)) && (field3148[i] == 2)) {
                    spawn.type = 0x1c4;
                    spawn.x = (double)((int(effects[i].x)) + effects[i].flag0048 * 0x3c);
                    spawn.y = effects[i].y;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)effects[i].flag0048;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if ((effects[i].frame == 5) &&
                        (field3148[i] < 4)) {
                        ++field3148[i];
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1c5:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].SetVelocityPolar(0.0,3.6);
                }
                if (effects[i].x > 370.0) {
                    spawn.type = 0;
                    spawn.x = (double)((int(positionX)) + facing * 0x14);
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.palette = 2;
                    contextOwner->EmitEffect(&spawn);
                    RemoveLocalEffect((short)i);
                    field344c = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x1c6:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].SetVelocityPolar(0.0,3.6);
                }
                if (effects[i].x > 370.0) {
                    spawn.type = 0;
                    spawn.x = (double)((int(positionX)) + facing * 0x14);
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.palette = 2;
                    contextOwner->EmitEffect(&spawn);
                    RemoveLocalEffect((short)i);
                    field344c = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x1c7:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].SetVelocityPolar(0.0,3.6);
                }
                if (effects[i].x > 370.0) {
                    spawn.type = 0;
                    spawn.x = (double)((int(positionX)) + facing * 0x14);
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.palette = 2;
                    contextOwner->EmitEffect(&spawn);
                    RemoveLocalEffect((short)i);
                    field344c = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x1c8:
                effects[i].flag0048 = field3450;
                if ((effects[i].frame == 1) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 1.5;
                    effects[i].vy = -2.3;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if ((effects[i].frame == 1) &&
                    ((*opponentSlot)->field0008 == 0x71)) {
                    effects[i].frame = 2;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                }
                if ((effects[i].frame == 2) &&
                    (0.0 <
                    effects[i].vy +
                    effects[i].y)) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].vx = 0.0;
                    effects[i].frame = 3;
                    effects[i].tick = 0;
                }
                if ((((2 < effects[i].frame) &&
                    (effects[i].frame < 6)) &&
                    (field3148[i] == 0)) &&
                    (effects[i].vx = 2.1,
                    (*opponentSlot)->field0008 == 0x40)) {
                    effects[i].vx = 0.0;
                    effects[i].frame = 6;
                    effects[i].tick = 0;
                }
                if (7 < effects[i].frame) {
                    effects[i].vx = 3.1;
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) &&
                    (7 < effects[i].frame)) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 6) {
                        effects[i].frame -= 3;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 3;
                    }
                }
                break;
            case 0x1c9:
                field3450 = (int)effects[i].flag0048;
                if ((effects[i].frame == 1) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = -2.3;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if ((effects[i].frame == 1) &&
                    (0.0 <
                    (*opponentSlot)->positionY -
                    effects[i].y)) {
                    spawn.type = 0;
                    spawn.x = (double)((int(positionX)) + facing * 0x25);
                    spawn.y = (double)((int(positionY)) + -0x2a);
                    spawn.group = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                    field02c9 = 0x1a;
                    (*opponentSlot)->field0008 = 0x71;
                    (*opponentSlot)->field000c = 0;
                    (*opponentSlot)->field000a = 0;
                    (*opponentSlot)->ResetFrame();
                    effects[i].frame = 2;
                    effects[i].tick = 0;
                }
                if (effects[i].frame == 2) {
                    (*opponentSlot)->positionY =
                    effects[i].y - 50.0;
                    (*opponentSlot)->positionX =
                    effects[i].x;
                    if (0.0 <
                        effects[i].vy +
                        effects[i].y) {
                        effects[i].y = 0.0;
                        effects[i].vy = 0.0;
                        effects[i].vx = 0.0;
                        effects[i].frame = 3;
                        effects[i].tick = 0;
                        effects[i].flag0048 = 1;
                        field3450 = 1;
                        if (effects[i].x > 320.0) {
                            effects[i].flag0048 = 0xff;
                            field3450 = -1;
                        }
                    }
                }
                if (((2 < effects[i].frame) &&
                    (effects[i].frame < 6)) &&
                    (field3148[i] == 0)) {
                    effects[i].vx = 2.1;
                    (*opponentSlot)->positionY =
                    effects[i].y - 50.0;
                    (*opponentSlot)->positionX =
                    effects[i].x;
                    if ((160.0 <
                        effects[i].x - positionX) ||
                        (effects[i].x - positionX <
                        -160.0)) {
                        effects[i].frame = 6;
                        effects[i].vx = 0.0;
                        effects[i].tick = 0;
                        (*opponentSlot)->field000a = 0;
                        (*opponentSlot)->field000c = 0;
                        (*opponentSlot)->facing = -effects[i].flag0048;
                        (*opponentSlot)->knockbackVelocityX = -2.1;
                        (*opponentSlot)->knockbackVelocityY = -1.5;
                        (*opponentSlot)->field0008 = 0x40;
                        ApplyDamage(0x4b0,750.0);
                    }
                }
                if (7 < effects[i].frame) {
                    effects[i].vx = 3.1;
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) &&
                    (7 < effects[i].frame)) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 6) {
                        effects[i].frame -= 3;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 3;
                    }
                }
                break;
            case 0x1ca:
                effects[i].flag0048 = field3450;
                if ((effects[i].frame == 1) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = -1.5;
                    effects[i].vy = -2.3;
                }
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if ((effects[i].frame == 1) &&
                    ((*opponentSlot)->field0008 == 0x71)) {
                    effects[i].frame = 2;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                }
                if ((effects[i].frame == 2) &&
                    (0.0 <
                    effects[i].vy +
                    effects[i].y)) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].vx = 0.0;
                    effects[i].frame = 3;
                    effects[i].tick = 0;
                }
                if ((((2 < effects[i].frame) &&
                    (effects[i].frame < 6)) &&
                    (field3148[i] == 0)) &&
                    (effects[i].vx = 2.1,
                    (*opponentSlot)->field0008 == 0x40)) {
                    effects[i].vx = 0.0;
                    effects[i].frame = 6;
                    effects[i].tick = 0;
                }
                if (7 < effects[i].frame) {
                    effects[i].vx = 3.1;
                }
                if (((effects[i].x < -30.0) ||
                    (effects[i].x > 670.0)) &&
                    (7 < effects[i].frame)) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 6) {
                        effects[i].frame -= 3;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 3;
                    }
                }
                break;
            case 0x1cb:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 99;
                    field02c8 = 0xd;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].field0080 = 0;
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1cc:
                effects[i].x =
                (double)(facing * 0x38) + positionX;
                effects[i].y = positionY - 44.0;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (((effects[i].frame == 4) &&
                        (field0008 == 0xd2)) && (field000a < 9)) {
                        effects[i].frame -= 2;
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
                if ((field0008 != 83 && field0008 != 84 && field0008 != 85 && field0008 != 86) ||
                    (field0008 == 83 && field000a > 1) || (field0008 == 84 && field000a > 1)) {
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
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    field3248[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3148[i];
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
                if (field3248[i] < 10) {
                    effects[i].group = 1;
                }
                if (field3248[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field3248[i];
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
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    field3248[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x3c + 0x78 + (unsigned int)(16000 < (std::rand())) * 0x28;
                    ++field3148[i];
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
                if (field3248[i] < 10) {
                    effects[i].group = 1;
                }
                if (field3248[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field3248[i];
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
