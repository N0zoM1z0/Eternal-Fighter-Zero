// Mayu complete local-effect update and lifetime dispatch.
#include "CharacterViews.h"
#include <cstdlib>

void Character05::Slot07()
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
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3148[i] == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].vx = 2.0;
                    ++field3148[i];
                }
                effects[i].vx =
                effects[i].vx - 0.03;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                if ((effects[i].x < -100.0) ||
                    (effects[i].x > 800.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x191:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].frame = 0;
                    effects[i].vx = 0.0;
                    effects[i].vy = -3.1;
                    effects[i].ay = 0.08;
                }
                if (effects[i].frame < 0xb) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                if (effects[i].frame == 3 && effects[i].vy + effects[i].y > 0.0) {
                    effects[i].vy = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 4;
                    effects[i].ay = 0.0;
                    (*opponentSlot)->ResetFrame();
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->field0008 = 0x62;
                    effects[i].y = 0.0;
                    ApplyDamage(300,960.0);
                    if ((*opponentSlot)->health <= 0) {
                        (*opponentSlot)->health = 1;
                    }
                    spawn.type = 0;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = 0.0;
                    spawn.palette = 2;
                    spawn.group = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                    break;
                }
                if ((effects[i].frame == 5) && (0x334 < field3138)
                    ) {
                    effects[i].frame = 6;
                    effects[i].tick = 0;
                    effects[i].vy = -5.0;
                    effects[i].ay = 0.06;
                    break;
                }
                if (effects[i].frame == 9 && effects[i].vy + effects[i].y > 0.0) {
                    effects[i].vy = 0.0;
                    effects[i].y = 0.0;
                    effects[i].ay = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 10;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 6) {
                        if (field3138 <= 730) {
                            effects[i].frame = 0;
                            effects[i].vx = 0.0;
                            effects[i].vy = -3.1;
                            effects[i].ay = 0.08;
                        }
                        else {
                            effects[i].frame = 5;
                        }
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].tick = 0;
                        effects[i].frame = 0;
                        effects[i].type = 0x193;
                    }
                }
                break;
            case 0x192:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].frame = 0;
                    effects[i].vx = 0.0;
                    effects[i].vy = -2.1;
                    effects[i].ay = 0.07;
                }
                if (effects[i].frame < 0xb) {
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                }
                if (effects[i].frame == 3 && effects[i].vy + effects[i].y > 0.0) {
                    effects[i].vy = 0.0;
                    effects[i].ay = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 4;
                    (*opponentSlot)->ResetFrame();
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->field0008 = 0x62;
                    effects[i].y = 0.0;
                    ApplyDamage(300,960.0);
                    if ((*opponentSlot)->health <= 0) {
                        (*opponentSlot)->health = 1;
                    }
                    spawn.type = 0;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = 0.0;
                    spawn.palette = 2;
                    spawn.group = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                    break;
                }
                if ((effects[i].frame == 5) && (0x334 < field3138)
                    ) {
                    effects[i].frame = 6;
                    effects[i].tick = 0;
                    effects[i].vy = -5.0;
                    effects[i].ay = 0.06;
                    break;
                }
                if (effects[i].frame == 9 && effects[i].vy + effects[i].y > 0.0) {
                    effects[i].vy = 0.0;
                    effects[i].ay = 0.0;
                    effects[i].y = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 10;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 6) {
                        if (field3138 <= 730) {
                            effects[i].frame = 0;
                            effects[i].vx = 0.0;
                            effects[i].vy = -2.1;
                            effects[i].ay = 0.07;
                        }
                        else {
                            effects[i].frame = 5;
                        }
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].tick = 0;
                        effects[i].frame = 0;
                        effects[i].type = 0x194;
                    }
                }
                break;
            case 0x193:
                if ((field3140 == 1) && (effects[i].frame == 0)) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    pendingContextSoundSlot = 0x1a;
                    effects[i].vx = 1.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 1;
                    }
                }
                if ((effects[i].x < -100.0) ||
                    (effects[i].x > 740.0)) {
                    RemoveLocalEffect((short)i);
                }
                break;
            case 0x194:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx = 0.8;
                    effects[i].vy = -2.0;
                }
                effects[i].vy =
                effects[i].vy + 0.043;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3140 = 1;
                    }
                }
                break;
            case 0x195:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x196:
                effects[i].x = positionX;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 7) &&
                        (field000a <= 11)) {
                        effects[i].frame -= 2;
                    }
                    else if ((effects[i].frame >= frameCount) ||
                        (field0008 != 0x132)) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x197:
                effects[i].x = positionX;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 7) &&
                        (field000a <= 11)) {
                        effects[i].frame -= 2;
                    }
                    else if ((effects[i].frame >= frameCount) ||
                        (field0008 != 0x132)) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x198:
                effects[i].vx = 2.0;
                effects[i].vy = -4.0;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 4;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].y > -480.0) {
                        effects[i].field0080 = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 4;
                    }
                }
                if (effects[i].y < -680.0) {
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].type = 0x199;
                    effects[i].x =
                    (*opponentSlot)->positionX + (double)(int)effects[i].flag0048 *
                    ((effects[i].y - (*opponentSlot)->positionY) / 2.0);
                    return;
                }
                break;
            case 0x199:
                effects[i].vx = 3.0;
                effects[i].vy = 6.0;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 4;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 4;
                    }
                }
                if (effects[i].y > 0.0) {
                    effects[i].vy = 0.0;
                    effects[i].vx = 0.0;
                    effects[i].y = 0.0;
                    effects[i].type = 0x19a;
                    effects[i].group = 2;
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    return;
                }
                break;
            case 0x19a:
                effects[i].field0084 = 1;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    pendingCharacterSoundSlot = 3;
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
