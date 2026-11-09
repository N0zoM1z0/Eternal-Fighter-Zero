// Misaki complete local-effect update and lifetime dispatch.
#include "CharacterViews.h"
#include <cstdlib>

void Character07::Slot07()
{
    int i;
    if ((*opponentSlot)->hitstunFrames > 0) return;
    i = (unsigned int)effectRead;
    // This reused descriptor supplies every local emission.
    EffectSpawn spawn;
    while (i != (int)effectWrite) {
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
                effects[i].field0084 = 1;
                if (((effects[i].frame == 1) &&
                    (effects[i].tick == 0)) && (field3248[i] == 0)) {
                    if (effects[i].y < -80.0) {
                        spawn.type = 0x193;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = (double)((int(effects[i].y)) + 0x28);
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].y >= -80.0) {
                        spawn.type = 0x194;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = 0.0;
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                    }
                    ++field3248[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (field3248[i] == 1) {
                            effects[i].frame = 0;
                        }
                        if (field3248[i] == 2) {
                            RemoveLocalEffect((short)i);
                        }
                        ++field3248[i];
                    }
                }
                break;
            case 0x194:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3248[i] == 0)) {
                    spawn.type = 0x195;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (1 < field3248[i]) {
                            RemoveLocalEffect((short)i);
                        }
                        effects[i].frame = 0;
                        ++field3248[i];
                    }
                }
                break;
            case 0x195:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 1)) {
                    effects[i].field0084 = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (field3148[i] < 0xf) {
                        effects[i].frame = 0;
                        ++field3148[i];
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
                    effects[i].vx = 1.5;
                    effects[i].vy = 0.0;
                }
                if (effects[i].field0080 >= 2 || (field0008 > 49 && field0008 < 150)) {
                    effects[i].type = 0x19a;
                    effects[i].field0084 = 0;
                    break;
                }
                effects[i].vx =
                effects[i].vx - 0.015;
                if (effects[i].vx < 0.2) {
                    effects[i].vx = 0.2;
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
            case 0x197:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].vx = 2.2;
                    effects[i].vy = 0.0;
                }
                if (effects[i].field0080 >= 2 || (field0008 > 49 && field0008 < 150)) {
                    effects[i].type = 0x19a;
                    effects[i].field0084 = 0;
                    break;
                }
                effects[i].vx =
                effects[i].vx - 0.015;
                if (effects[i].vx < 0.4) {
                    effects[i].vx = 0.4;
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
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 10)) * 0.1 + 2.5;
                    effects[i].vy =
                    -1.2 - (double)((unsigned short)RandomRange(0, 0x14)) * 0.1;
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if (effects[i].y >= 0.0 && effects[i].vy > 0.0 && effects[i].frame == 1) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                if (((effects[i].y >= 0.0) ||
                    (1 < effects[i].field0080)) &&
                    (effects[i].frame == 0)) {
                    effects[i].y =
                    effects[i].y - 1.0;
                    effects[i].frame = 1;
                    effects[i].vy = -1.5;
                    spawn.type = 0x19c;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field02c8 = 1;
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
            case 0x19c:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 10)) * 0.1 + 1.5;
                    effects[i].vy = -1.5;
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if (effects[i].y >= 0.0 && effects[i].vy > 0.0) {
                    RemoveLocalEffect((short)i);
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
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 0x14)) * 0.1 + 1.7;
                    effects[i].vy =
                    -0.5 - (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if (effects[i].y >= 0.0 && effects[i].vy > 0.0 && effects[i].frame == 1) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                if (((effects[i].y >= 0.0) ||
                    (1 < effects[i].field0080)) &&
                    (effects[i].frame == 0)) {
                    effects[i].y =
                    effects[i].y - 1.0;
                    effects[i].frame = 1;
                    effects[i].vy = -1.5;
                    spawn.type = 0x19e;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field02c8 = 1;
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
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 10)) * 0.1 + 1.5;
                    effects[i].vy = -1.5;
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if (effects[i].y >= 0.0 && effects[i].vy > 0.0) {
                    RemoveLocalEffect((short)i);
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
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 10)) * 0.1 + 1.0;
                    effects[i].vy =
                    -1.8 - (double)((unsigned short)RandomRange(0, 0x14)) * 0.1;
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if (effects[i].y >= 0.0 && effects[i].vy > 0.0 && effects[i].frame == 1) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                if (((effects[i].y >= 0.0) ||
                    (1 < effects[i].field0080)) &&
                    (effects[i].frame == 0)) {
                    effects[i].y =
                    effects[i].y - 1.0;
                    effects[i].frame = 1;
                    effects[i].vy = -1.5;
                    spawn.type = 0x1a0;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 0;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field02c8 = 1;
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
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].vx =
                    (double)((unsigned short)RandomRange(0, 10)) * 0.1 + 1.5;
                    effects[i].vy = -1.5;
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if (effects[i].y >= 0.0 && effects[i].vy > 0.0) {
                    RemoveLocalEffect((short)i);
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
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    field02c9 = 0x12;
                    effects[i].vx = 1.0;
                    spawn.type = 0x198;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = 0.0;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    ++field3148[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (field3148[i] == 5) {
                            RemoveLocalEffect((short)i);
                            break;
                        }
                        else {
                            effects[i].frame = 0;
                        }
                    }
                }
                break;
            case 0x1a2:
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
            case 0x1a3:
                effects[i].field0084 = 1;
                if (((effects[i].frame == 1) &&
                    (effects[i].tick == 0)) && (field3248[i] == 0)) {
                    if (effects[i].y < -80.0) {
                        spawn.type = 0x1a3;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = (double)((int(effects[i].y)) + 0x28);
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].y >= -80.0) {
                        spawn.type = 0x1a5;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = 0.0;
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                    }
                    ++field3248[i];
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
            case 0x1a5:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3248[i] == 0)) {
                    spawn.type = 0x1a6;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
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
            case 0x1a6:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 1)) {
                    effects[i].field0084 = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (field3148[i] < 8) {
                        effects[i].frame = 0;
                        ++field3148[i];
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a7:
                effects[i].field0084 = 1;
                if (((effects[i].frame == 1) &&
                    (effects[i].tick == 0)) && (field3248[i] == 0)) {
                    if (effects[i].y < -80.0) {
                        spawn.type = 0x1a7;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = (double)((int(effects[i].y)) + 0x28);
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                    }
                    if (effects[i].y >= -80.0) {
                        spawn.type = 0x1a9;
                        spawn.x = (double)(int(effects[i].x));
                        spawn.y = 0.0;
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                    }
                    ++field3248[i];
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (field3248[i] < 3) {
                            effects[i].frame = 0;
                        }
                        if (field3248[i] == 3) {
                            RemoveLocalEffect((short)i);
                        }
                        ++field3248[i];
                    }
                }
                break;
            case 0x1a9:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3248[i] == 0)) {
                    spawn.type = 0x1aa;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (field3248[i] < 3) {
                            ++field3248[i];
                            effects[i].frame = 0;
                            break;
                        }
                        else {
                            RemoveLocalEffect((short)i);
                        }
                    }
                }
                break;
            case 0x1aa:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 1)) {
                    effects[i].field0084 = 1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (field3148[i] < 0x1c) {
                        effects[i].frame = 0;
                        ++field3148[i];
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
