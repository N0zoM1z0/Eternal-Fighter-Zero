// Makoto complete local-effect update and lifetime dispatch.
#include "CharacterViews.h"
#include <cstdlib>

void Character03::Slot07()
{
    int i;
    if ((*opponentSlot)->field014c > 0) return;
    i = effectRead;
    // This reused descriptor supplies every local emission.
    EffectSpawn spawn;
    while (i != (int)effectWrite) {
        if (((effectActive[i] != 0) && (effects[i].field0086 == 0))
            && ((field014c == 0 ||
            ((0 < field014c && (effects[i].field0088 != 0)))))) {
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
                --field324c[i];
                if ((effects[i].frame < 6) &&
                    (field324c[i] <= 0)) {
                    spawn.type = 0x22;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                    field324c[i] = 3;
                }
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].vx = 0.5;
                    effects[i].vy = -2.7;
                    effects[i].ax = 0.18;
                    ++field314c[i];
                }
                if (effects[i].y + effects[i].vy > 0.0 && effects[i].frame < 3) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].vx = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 3;
                    break;
                }
                if (((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 199) &&
                    effects[i].frame > 2 && effects[i].frame < 6 &&
                    ((effects[i].x - (*opponentSlot)->positionX < 25.0 &&
                    effects[i].x - (*opponentSlot)->positionX > -25.0 &&
                    (*opponentSlot)->positionY > -20.0 &&
                    ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 150)) ||
                    (field0008 > 249 && field0008 < 253))) {
                    effects[i].group = 2;
                    field02c8 = 0;
                    effects[i].field0084 = 1;
                    effects[i].frame = 6;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                    break;
                }
                if ((2 < effects[i].frame) &&
                    (effects[i].frame < 6)) {
                    if (effects[i].vx > 2.0) {
                        effects[i].ax = -0.18;
                    }
                    if (effects[i].vx < -2.0) {
                        effects[i].ax = 0.18;
                    }
                    effects[i].vx =
                    effects[i].vx +
                    effects[i].ax;
                }
                ++effects[i].tick;
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 3) {
                        effects[i].frame -= 3;
                    }
                    if ((effects[i].frame == 6) &&
                        (field314c[i] < 6)) {
                        effects[i].frame -= 3;
                        ++field314c[i];
                    }
                    if (effects[i].frame == 6) {
                        effects[i].group = 2;
                        field02c8 = 0;
                        effects[i].field0084 = 1;
                        effects[i].vx = 0.0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x194:
                --field324c[i];
                if ((effects[i].frame < 6) &&
                    (field324c[i] <= 0)) {
                    spawn.type = 0x22;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                    field324c[i] = 3;
                }
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].vx = 1.1;
                    effects[i].vy = -2.2;
                    effects[i].ax = 0.18;
                    ++field314c[i];
                }
                if (effects[i].y + effects[i].vy > 0.0 && effects[i].frame < 3) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].vx = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 3;
                    break;
                }
                if (((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 199) &&
                    effects[i].frame > 2 && effects[i].frame < 6 &&
                    ((effects[i].x - (*opponentSlot)->positionX < 25.0 &&
                    effects[i].x - (*opponentSlot)->positionX > -25.0 &&
                    (*opponentSlot)->positionY > -20.0 &&
                    ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 150)) ||
                    (field0008 > 249 && field0008 < 253))) {
                    effects[i].group = 2;
                    effects[i].group = 2;
                    field02c8 = 0;
                    effects[i].field0084 = 1;
                    effects[i].frame = 6;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                    break;
                }
                if ((2 < effects[i].frame) &&
                    (effects[i].frame < 6)) {
                    if (effects[i].vx > 2.0) {
                        effects[i].ax = -0.18;
                    }
                    if (effects[i].vx < -2.0) {
                        effects[i].ax = 0.18;
                    }
                    effects[i].vx =
                    effects[i].vx +
                    effects[i].ax;
                }
                ++effects[i].tick;
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 3) {
                        effects[i].frame -= 3;
                    }
                    if ((effects[i].frame == 6) &&
                        (field314c[i] < 8)) {
                        effects[i].frame -= 3;
                        ++field314c[i];
                    }
                    if (effects[i].frame == 6) {
                        effects[i].group = 2;
                        field02c8 = 0;
                        effects[i].field0084 = 1;
                        effects[i].vx = 0.0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x195:
                --field324c[i];
                if ((effects[i].frame < 6) &&
                    (field324c[i] <= 0)) {
                    spawn.type = 0x22;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = (double)(int(effects[i].y));
                    spawn.group = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                    field324c[i] = 3;
                }
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].vx = (double)((unsigned short)RandomRange(0, 0xf)) * 0.1 + 0.5;
                    effects[i].vy = -1.5 - (double)((unsigned short)RandomRange(0, 10)) * 0.1;
                    effects[i].ax = 0.18;
                    ++field314c[i];
                }
                if (effects[i].y + effects[i].vy > 0.0 && effects[i].frame < 3) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].vx = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 3;
                    break;
                }
                if (((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 199) &&
                    effects[i].frame > 2 && effects[i].frame < 6 &&
                    ((effects[i].x - (*opponentSlot)->positionX < 25.0 &&
                    effects[i].x - (*opponentSlot)->positionX > -25.0 &&
                    (*opponentSlot)->positionY > -20.0 &&
                    ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 150)) ||
                    (field0008 > 249 && field0008 < 253))) {
                    effects[i].group = 2;
                    effects[i].group = 2;
                    field02c8 = 0;
                    effects[i].field0084 = 1;
                    effects[i].frame = 6;
                    effects[i].tick = 0;
                    effects[i].vx = 0.0;
                    break;
                }
                if ((2 < effects[i].frame) &&
                    (effects[i].frame < 6)) {
                    if (effects[i].vx > 2.0) {
                        effects[i].ax = -0.18;
                    }
                    if (effects[i].vx < -2.0) {
                        effects[i].ax = 0.18;
                    }
                    effects[i].vx =
                    effects[i].vx +
                    effects[i].ax;
                }
                ++effects[i].tick;
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 3) {
                        effects[i].frame -= 3;
                    }
                    if ((effects[i].frame == 6) &&
                        (field314c[i] < 0x1e)) {
                        effects[i].frame -= 3;
                        ++field314c[i];
                    }
                    if (effects[i].frame == 6) {
                        effects[i].group = 2;
                        field02c8 = 0;
                        effects[i].field0084 = 1;
                        effects[i].vx = 0.0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x196:
                --field324c[i];
                if ((((effects[i].field0080 == 4) || (effects[i].field0080 == 5)) ||
                    ((field0008 < 0x100 &&
                    ((0xfc < field0008 && (field000a == 0)))))) &&
                    (effects[i].frame < 3)) {
                    effects[i].frame = 3;
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].vx = -0.8;
                    effects[i].vy = -1.0;
                    effects[i].group = 1;
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].vx = 0.2;
                    effects[i].vy = -0.5;
                    ++field314c[i];
                }
                if ((effects[i].frame == 2) &&
                    (field324c[i] <= 0)) {
                    spawn.type = 0x199;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = 0.0;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field324c[i] = 0xf;
                }
                if (effects[i].y + effects[i].vy > 0.0 && effects[i].frame == 0) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 1;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 3) {
                        if (field314c[i] < 3) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                        }
                        else {
                            spawn.type = 0x199;
                            spawn.x = (double)(int(effects[i].x));
                            spawn.y = 5.0;
                            spawn.group = 2;
                            spawn.layer = 1;
                            spawn.flag0018 = (unsigned char)facing;
                            EmitLocalEffect(&spawn);
                            spawn.x = (double)((int(effects[i].x)) + -5);
                            spawn.y = 0.0;
                            EmitLocalEffect(&spawn);
                            spawn.x = (double)((int(effects[i].x)) + 5);
                            spawn.y = 0.0;
                            EmitLocalEffect(&spawn);
                            spawn.x = (double)(int(effects[i].x));
                            spawn.y = -5.0;
                            EmitLocalEffect(&spawn);
                            RemoveLocalEffect((short)i);
                        }
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x197:
                --field324c[i];
                if ((((effects[i].field0080 == 4) || (effects[i].field0080 == 5)) ||
                    ((field0008 < 0x100 &&
                    ((0xfc < field0008 && (field000a == 0)))))) &&
                    (effects[i].frame < 3)) {
                    effects[i].frame = 3;
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].vx = -0.8;
                    effects[i].vy = -1.0;
                    effects[i].group = 1;
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].vx = 0.4;
                    effects[i].vy = -0.5;
                    ++field314c[i];
                }
                if ((effects[i].frame == 2) &&
                    (field324c[i] <= 0)) {
                    spawn.type = 0x199;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = 0.0;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field324c[i] = 0x15;
                }
                --field324c[i];
                if (effects[i].y + effects[i].vy > 0.0 && effects[i].frame == 0) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 1;
                    effects[i].vx = 0.0;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
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
                --field324c[i];
                if ((((effects[i].field0080 == 4) || (effects[i].field0080 == 5)) ||
                    ((field0008 < 0x100 &&
                    ((0xfc < field0008 && (field000a == 0)))))) &&
                    (effects[i].frame < 3)) {
                    effects[i].frame = 3;
                    effects[i].tick = 0;
                    effects[i].field0080 = 0;
                    effects[i].vx = -0.8;
                    effects[i].vy = -1.0;
                    effects[i].group = 1;
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].vx = 0.3;
                    effects[i].vy = -0.5;
                    ++field314c[i];
                }
                if ((effects[i].frame == 2) &&
                    (field324c[i] <= 0)) {
                    spawn.type = 0x199;
                    spawn.x = (double)(int(effects[i].x));
                    spawn.y = 0.0;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&spawn);
                    field324c[i] = 0xf;
                }
                if (effects[i].y + effects[i].vy > 0.0 && effects[i].frame == 0) {
                    effects[i].y = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].tick = 0;
                    effects[i].frame = 1;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].y < 0.0) {
                    effects[i].vy =
                    effects[i].vy + 0.035;
                }
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 3) {
                        if (field314c[i] < 6) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                        }
                        else {
                            spawn.type = 0x199;
                            spawn.x = (double)(int(effects[i].x));
                            spawn.y = 5.0;
                            spawn.group = 2;
                            spawn.layer = 1;
                            spawn.flag0018 = (unsigned char)facing;
                            EmitLocalEffect(&spawn);
                            spawn.x = (double)((int(effects[i].x)) + -5);
                            spawn.y = 0.0;
                            EmitLocalEffect(&spawn);
                            spawn.x = (double)((int(effects[i].x)) + 5);
                            spawn.y = 0.0;
                            EmitLocalEffect(&spawn);
                            spawn.x = (double)(int(effects[i].x));
                            spawn.y = -5.0;
                            EmitLocalEffect(&spawn);
                            RemoveLocalEffect((short)i);
                        }
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x199:
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].vy = -1.5;
                    effects[i].field0084 = 1;
                    ++field314c[i];
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
                if ((effects[i].frame == 0) &&
                    (field314c[i] == 0)) {
                    effects[i].field0084 = 1;
                    field314c[i] = 1;
                }
                if (effects[i].field0084 == 0) {
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                }
                if (effects[i].flag0048 == 1) {
                    if ((effects[i].frame == 0) ||
                        (effects[i].frame == 1)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            field02c8 = 1;
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame =
                            effects[i].frame + 6;
                            ++field314c[i];
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            field02c8 = 1;
                            break;
                        }
                    }
                    if ((effects[i].frame == 2) ||
                        (effects[i].frame == 3)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 4) ||
                        (effects[i].frame == 5)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 6) ||
                        (effects[i].frame == 7)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame -= 6;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                }
                if (effects[i].flag0048 == -1) {
                    if ((effects[i].frame == 0) ||
                        (effects[i].frame == 1)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame =
                            effects[i].frame + 6;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 2) ||
                        (effects[i].frame == 3)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 4) ||
                        (effects[i].frame == 5)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 6) ||
                        (effects[i].frame == 7)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame -= 6;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((((effects[i].frame == 2) ||
                        (effects[i].frame == 4)) ||
                        (effects[i].frame == 6)) ||
                        (effects[i].frame == 8)) {
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3148 = 0;
                    }
                }
                break;
            case 0x19b:
                if ((effects[i].frame == 0) &&
                    (field324c[i] == 0)) {
                    effects[i].field0084 = 1;
                    field324c[i] = 1;
                    effects[i].frame = 6;
                }
                if (effects[i].field0084 == 0) {
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                }
                if (effects[i].flag0048 == 1) {
                    if ((effects[i].frame == 0) ||
                        (effects[i].frame == 1)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame =
                            effects[i].frame + 6;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 2) ||
                        (effects[i].frame == 3)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 4) ||
                        (effects[i].frame == 5)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 6) ||
                        (effects[i].frame == 7)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame -= 6;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                }
                if (effects[i].flag0048 == -1) {
                    if ((effects[i].frame == 0) ||
                        (effects[i].frame == 1)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame =
                            effects[i].frame + 6;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 2) ||
                        (effects[i].frame == 3)) {
                        effects[i].vx = 1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 4) ||
                        (effects[i].frame == 5)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = 1.5;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 6) ||
                        (effects[i].frame == 7)) {
                        effects[i].vx = -1.5;
                        effects[i].vy = -1.5;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame -= 6;
                            ++field314c[i];
                            field02c8 = 1;
                            if (3 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((((effects[i].frame == 2) ||
                        (effects[i].frame == 4)) ||
                        (effects[i].frame == 6)) ||
                        (effects[i].frame == 8)) {
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3148 = 0;
                    }
                }
                break;
            case 0x19c:
                if ((effects[i].frame == 0) &&
                    (field324c[i] == 0)) {
                    effects[i].field0084 = 1;
                    field324c[i] = 1;
                }
                if (effects[i].flag0048 == 1) {
                    if ((effects[i].frame == 0) ||
                        (effects[i].frame == 1)) {
                        effects[i].vx = 3.0;
                        effects[i].vy = -3.0;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame =
                            effects[i].frame + 6;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 2) ||
                        (effects[i].frame == 3)) {
                        effects[i].vx = 3.0;
                        effects[i].vy = 3.0;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 4) ||
                        (effects[i].frame == 5)) {
                        effects[i].vx = -3.0;
                        effects[i].vy = 3.0;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            effects[i].field0084 = 1;
                            field02c8 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 6) ||
                        (effects[i].frame == 7)) {
                        effects[i].vx = -3.0;
                        effects[i].vy = -3.0;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame -= 6;
                            ++field314c[i];
                            effects[i].field0084 = 1;
                            field02c8 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                }
                if (effects[i].flag0048 == -1) {
                    if ((effects[i].frame == 0) ||
                        (effects[i].frame == 1)) {
                        effects[i].vx = 3.0;
                        effects[i].vy = -3.0;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame =
                            effects[i].frame + 6;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 2) ||
                        (effects[i].frame == 3)) {
                        effects[i].vx = 3.0;
                        effects[i].vy = 3.0;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x < (double)contextOwner->cameraBounds.left) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 4) ||
                        (effects[i].frame == 5)) {
                        effects[i].vx = -3.0;
                        effects[i].vy = 3.0;
                        if (effects[i].y > (double)contextOwner->cameraBounds.bottom) {
                            effects[i].frame =
                            effects[i].frame + 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                    if ((effects[i].frame == 6) ||
                        (effects[i].frame == 7)) {
                        effects[i].vx = -3.0;
                        effects[i].vy = -3.0;
                        if (effects[i].y < (double)contextOwner->cameraBounds.top) {
                            effects[i].frame -= 2;
                            ++field314c[i];
                            field02c8 = 1;
                            effects[i].field0084 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                        if (effects[i].x > (double)contextOwner->cameraBounds.right) {
                            effects[i].frame -= 6;
                            ++field314c[i];
                            effects[i].field0084 = 1;
                            field02c8 = 1;
                            if (7 < field314c[i]) {
                                RemoveLocalEffect((short)i);
                                field3148 = 0;
                            }
                            break;
                        }
                    }
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((((effects[i].frame == 2) ||
                        (effects[i].frame == 4)) ||
                        (effects[i].frame == 6)) ||
                        (effects[i].frame == 8)) {
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3148 = 0;
                    }
                }
                break;
            case 0x19d:
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        spawn.type = 0x19e;
                        spawn.x = (double)((int(effects[i].x)) + effects[i].flag0048 * 0x3c);
                        spawn.y = 5.0;
                        spawn.group = 2;
                        spawn.layer = 1;
                        spawn.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&spawn);
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x19e:
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
                effects[i].field0084 = 99;
                if ((field0008 != 0x12f) ||
                    ((field0008 == 0x12f && (0x13 < field000a)))) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        --effects[i].frame;
                    }
                }
                break;
            case 0x1a0:
                effects[i].field0084 = 99;
                if ((field0008 != 0x130) ||
                    ((field0008 == 0x130 && (0x13 < field000a)))) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        --effects[i].frame;
                    }
                }
                break;
            case 0x1a1:
                effects[i].field0084 = 99;
                if ((field0008 != 0x131) ||
                    ((field0008 == 0x131 && (0x13 < field000a)))) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        --effects[i].frame;
                    }
                }
                break;
            case 0x1a2:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field314c[i] == 0)) {
                    effects[i].field0084 = 5;
                    effects[i].vy = -0.45;
                    effects[i].vx = 0.02;
                    ++field314c[i];
                }
                if (effects[i].field0084 == 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    effects[i].vy =
                    effects[i].vy + 0.0012;
                    effects[i].vx =
                    effects[i].vx - 1e-05;
                    if (effects[i].vx < 0.0) {
                        effects[i].vx = 0.0;
                    }
                    if (0x5a < field324c[i]) {
                        effects[i].field0080 = 0;
                        field324c[i] = 0;
                    }
                    ++field324c[i];
                    if (0.0 < effects[i].y +
                        effects[i].vy) {
                        RemoveLocalEffect((short)i);
                    }
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        if (effects[i].frame >= frameCount) {
                            effects[i].frame = 0;
                        }
                    }
                }
                break;
            case 0x1a3:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field314c[i] == 0)) {
                    effects[i].field0084 = 5;
                    effects[i].vy = 0.0;
                    effects[i].vx = 0.0;
                    effects[i].ay = 0.005;
                    ++field314c[i];
                }
                if (effects[i].field0084 == 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    if (0x5a < field324c[i]) {
                        effects[i].field0080 = 0;
                        field324c[i] = 0;
                    }
                    ++field324c[i];
                    if (effects[i].vy > 0.3) {
                        effects[i].ay = -0.005;
                    }
                    if (effects[i].vy < -0.3) {
                        effects[i].ay = 0.005;
                    }
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        if (effects[i].frame >= frameCount) {
                            if (field334c[i] < 0xc) {
                                effects[i].frame = 0;
                                ++field334c[i];
                            }
                            else {
                                RemoveLocalEffect((short)i);
                            }
                        }
                    }
                }
                break;
            case 0x1a4:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field314c[i] == 0)) {
                    effects[i].field0084 = 5;
                    effects[i].vy = -0.5;
                    effects[i].vx = 0.3;
                    ++field314c[i];
                }
                if (effects[i].field0084 == 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    effects[i].vy =
                    effects[i].vy + 0.0015;
                    if (0x5a < field324c[i]) {
                        effects[i].field0080 = 0;
                        field324c[i] = 0;
                    }
                    ++field324c[i];
                    if (0.0 < effects[i].y +
                        effects[i].vy) {
                        RemoveLocalEffect((short)i);
                    }
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        if (effects[i].frame >= frameCount) {
                            effects[i].frame = 0;
                        }
                    }
                }
                break;
            case 0x1a5:
                if (field314c[i] == 0) {
                    effects[i].vy = (double)((unsigned short)RandomRange(0, 0x14)) * 0.01 + -2.6;
                    effects[i].vx = -1.0 - (double)((unsigned short)RandomRange(0, 0x14)) * 0.01;
                }
                if (effects[i].y + effects[i].vy > 0.0) {
                    field02c8 = 2;
                    effects[i].y = 0.0;
                    effects[i].vy =
                    -effects[i].vy * 0.5;
                    if (effects[i].vy > -1.0) {
                        RemoveLocalEffect((short)i);
                        break;
                    }
                }
                ++field314c[i];
                effects[i].vy =
                effects[i].vy + 0.05;
                if (field314c[i] > 180) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                    }
                }
                break;
            case 0x1a6:
                if (field314c[i] == 0) {
                    effects[i].vy = -3.2;
                    effects[i].vx = -0.07;
                }
                if ((effects[i].field0080 == 5) &&
                    (effects[i].frame == 0)) {
                    effects[i].frame = 1;
                    effects[i].tick = 0;
                    field313c = 2;
                    effects[i].vx =
                    (double)(int)facing * 1.5 * (double)(int)(*opponentSlot)->facing;
                    effects[i].vy = -1.5;
                    break;
                }
                if (effects[i].y + effects[i].vy > -70.0 && effects[i].frame == 0) {
                    field313c = 1;
                    RemoveLocalEffect((short)i);
                    break;
                }
                ++field314c[i];
                effects[i].vy =
                effects[i].vy + 0.035;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame == 1) {
                        --effects[i].frame;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a7:
                if (effects[i].frame < 0x1d) {
                    effects[i].x =
                    (double)(facing * 0xc) + positionX;
                    effects[i].y = positionY - 50.0;
                }
                if ((effects[i].frame < 0x1d) &&
                    (field324c[i] <= 0)) {
                    spawn.type = 0x22;
                    spawn.x = (double)(int)((int(effects[i].x)) + -(char)(effects[i].flag0048) * 0x2f + (((unsigned short)RandomRange(0, 10))));
                    spawn.y = (double)(int)((int(effects[i].y)) + 0xc + (((unsigned short)RandomRange(0, 10))));
                    spawn.group = 2;
                    spawn.layer = 1;
                    contextOwner->EmitEffect(&spawn);
                    field324c[i] = 2;
                }
                if (((effects[i].frame < 0x1d) &&
                    ((unsigned short)RandomRange(0, 100 - (field0008 == 0x134) * 50) < 10)) && (0x132 < field0008)) {
                    spawn.type = 0x1a8;
                    spawn.x = (double)(int)((int(effects[i].x)) + -(char)(effects[i].flag0048) * 0x3c + (((unsigned short)RandomRange(0, 0x28))));
                    spawn.y = (double)(int)((int(effects[i].y)) + -0x20 + (((unsigned short)RandomRange(0, 0x3c))));
                    spawn.group = 2;
                    spawn.flag0018 = (unsigned char)facing;
                    spawn.layer = 1;
                    EmitLocalEffect(&spawn);
                }
                --field324c[i];
                if (((0.0 <= positionY + velocityY) &&
                    (5 < field000a)) && (field314c[i] == 0)) {
                    effects[i].tick = 0;
                    effects[i].frame = 0x1d;
                    ++field314c[i];
                }
                if (((field0008 < 0x132) || (0x134 < field0008)) &&
                    (effects[i].frame < 0x1d)) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (0 < field014a) {
                    --effects[i].tick;
                }
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 0x1d) {
                        effects[i].frame -= 2;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a8:
                ++effects[i].tick;
                if (0 < field014a) {
                    --effects[i].tick;
                }
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
                    (effects[i].tick == 0)) && (field314c[i] == 0)) {
                    field324c[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field314c[i];
                    effects[i].vx =
                    (double)(16000 < (std::rand())) * 1.2 +
                    (double)(16000 < (std::rand())) * 0.7 + (double)(16000 < (std::rand())) * 1.7 + -1.8;
                    effects[i].vy =
                    -1.2 - ((double)(16000 < (std::rand())) * 0.6 +
                        (double)(16000 < (std::rand())) * 0.9 + (double)(16000 < (std::rand())) * 1.4);
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if ((effects[i].y > 0.0) &&
                    (effects[i].vy > 0.0)) {
                    effects[i].vy =
                    -effects[i].vy;
                }
                if (field324c[i] < 10) {
                    effects[i].group = 1;
                }
                if (field324c[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field324c[i];
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
                    (effects[i].tick == 0)) && (field314c[i] == 0)) {
                    field324c[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x3c + 0x78 + (unsigned int)(16000 < (std::rand())) * 0x28;
                    ++field314c[i];
                    effects[i].vx =
                    (double)(16000 < (std::rand())) +
                    (double)(16000 < (std::rand())) * 0.5 + (double)(16000 < (std::rand())) * 1.5 + -1.5;
                    effects[i].vy =
                    -1.0 - ((double)(16000 < (std::rand())) * 0.5 +
                        (double)(16000 < (std::rand())) * 0.8 + (double)(16000 < (std::rand())) * 1.2);
                }
                effects[i].vy =
                effects[i].vy + 0.03;
                if ((effects[i].y > 0.0) &&
                    (effects[i].vy > 0.0)) {
                    effects[i].vy =
                    -effects[i].vy;
                }
                if (field324c[i] < 10) {
                    effects[i].group = 1;
                }
                if (field324c[i] < 0) {
                    RemoveLocalEffect((short)i);
                    break;
                }
                else {
                    ++effects[i].tick;
                    --field324c[i];
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
