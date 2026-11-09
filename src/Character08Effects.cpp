// Shiori complete local-effect update and lifetime dispatch.
#include "CharacterViews.h"
#include <cstdlib>
#include <cmath>

void Character08::Slot07()
{
    int i;
    if ((*opponentSlot)->field014c > 0) return;
    i = (int)effectRead;
    EffectSpawn effect;
    while (i != effectWrite) {
        if (((effectActive[i] != 0) &&
            (effects[i].field0086 == 0)) &&
            (field014c == 0 ||
            (0 < field014c && (effects[i].field0088 != 0)))) {
            unsigned short frameDuration = patterns[effects[i].type].frames[effects[i].frame].duration;
            unsigned short frameCount = patterns[effects[i].type].count;
            ResetLocalEffectSpawn(&effect);
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
                if (effects[i].frame == 0) {
                    effects[i].field0084 = 3;
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
            case 0x192:
                if (effects[i].frame == 0) {
                    effects[i].vx = 2.0;
                    effects[i].vy = 2.0;
                    effects[i].field0084 = 1;
                }
                if ((effects[i].frame == 1) &&
                    (effects[i].tick == 0x5f)) {
                    effects[i].group = 1;
                }
                if ((effects[i].y > 0.0) &&
                    (effects[i].frame == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].frame = 1;
                    field02c9 = 4;
                    effects[i].tick = 0;
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
                if ((effects[i].frame == 0) &&
                    (field3158[i] == 0)) {
                    effects[i].vx = 2.0;
                    effects[i].vy = 2.0;
                    effects[i].field0084 = 4;
                    ++field3158[i];
                }
                if ((effects[i].frame == 1) &&
                    (effects[i].tick == 0x5f)) {
                    effects[i].group = 1;
                }
                if ((effects[i].y > 0.0) &&
                    (effects[i].frame == 0)) {
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].frame = 1;
                    field02c9 = 4;
                    effects[i].tick = 0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame == 1) {
                        effects[i].frame = 0;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x195:
                field3148 = 1;
                if (field0008 > 49 && field0008 < 150) {
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                    break;
                }
                if (field3158[i] >= 520) {
                    effects[i].type = 0x199;
                    effects[i].tick = 0;
                    effects[i].frame = 0;
                    effects[i].vx = 0.0;
                    effects[i].vy = 0.0;
                    effects[i].group = 2;
                    effects[i].field0084 = 1;
                    field02c8 = 5;
                    field3148 = 0;
                    break;
                }
                effects[i].vx =
                effects[i].vx +
                effects[i].ax;
                effects[i].vy =
                effects[i].vy +
                effects[i].ay;
                if (effects[i].vx < -0.7) {
                    effects[i].vx = -0.7;
                } else if (effects[i].vx > 0.7) {
                    effects[i].vx = 0.7;
                }
                if (effects[i].vy < -0.4) {
                    effects[i].vy = -0.4;
                } else if (effects[i].vy > 0.4) {
                    effects[i].vy = 0.4;
                }
                ++field3158[i];
                if (effects[i].flag0048 != facing) {
                    effects[i].vx =
                    -effects[i].vx;
                    effects[i].flag0048 = facing;
                }
                if (effects[i].x <= positionX) {
                    effects[i].ax =
                    (double)(int)facing * 0.01;
                }
                if (effects[i].x > positionX) {
                    effects[i].ax =
                    (double)(int)facing * -0.01;
                }
                if (effects[i].y <=
                    positionY - 40.0) {
                    effects[i].ay = 0.01;
                }
                if (effects[i].y > positionY - 40.0) {
                    effects[i].ay = -0.01;
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
            case 0x197:
                if ((effects[i].frame == 2) &&
                    (effects[i].tick == 0)) {
                    effect.type = 0x1b1;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.flag0018 = (unsigned char)effects[i].flag0048;
                    effect.layer = true;
                    effect.group = 0;
                    effect.owner = 1;
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
            case 0x198:
                if (((field0008 == 0x106) || (field0008 == 0x107)) ||
                    (field0008 == 0x108)) {
                    effects[i].x =
                    (double)(facing * 0x24) + positionX;
                    effects[i].y =
                    positionY - 48.0;
                }
                if (effects[i].frame == 0) {
                    effects[i].field0084 = 3;
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
            case 0x199:
                if (effects[i].frame == 0) {
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
                if ((effects[i].frame == 2) &&
                    (effects[i].tick == 0)) {
                    effect.type = 0x1b2;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.flag0018 = (unsigned char)effects[i].flag0048;
                    effect.layer = true;
                    effect.group = 0;
                    effect.owner = 1;
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
            case 0x19b:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] = 0xa0;
                    ++field3158[i];
                    effects[i].vx = -0.8;
                    effects[i].vy = -2.5;
                }
                effects[i].vy =
                effects[i].vy + 0.05;
                if ((effects[i].y > 0.0) &&
                    (effects[i].vy > 0.0)) {
                    effects[i].vy =
                    -effects[i].vy * 0.5;
                }
                if (field3258[i] < 0x3c) {
                    contextOwner->RequestTransition('\x02');
                }
                if (field3258[i] < 0x37) {
                    contextOwner->RequestTransition('\x03');
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
            case 0x19c:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3158[i];
                    effects[i].vx =
                    -0.5 - ((((double)(16000 < (std::rand())) * 1.2) - ((double)(16000 < (std::rand())) * 0.7)) - (double)(16000 < (std::rand())) * 1.7);
                    effects[i].vy =
                    -1.2 - ((((double)(16000 < (std::rand())) * 0.6) - ((double)(16000 < (std::rand())) * 0.5)) - (double)(16000 < (std::rand())) * 0.8);
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
            case 0x19d:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3158[i];
                    effects[i].vx =
                    -0.5 - ((((double)(16000 < (std::rand())) * 1.2) - ((double)(16000 < (std::rand())) * 0.7)) - (double)(16000 < (std::rand())) * 1.7);
                    effects[i].vy =
                    -1.2 - ((((double)(16000 < (std::rand())) * 0.6) - ((double)(16000 < (std::rand())) * 0.5)) - (double)(16000 < (std::rand())) * 0.8);
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
            case 0x19e:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3158[i];
                    effects[i].vx =
                    -0.5 - ((((double)(16000 < (std::rand())) * 1.2) - ((double)(16000 < (std::rand())) * 0.7)) - (double)(16000 < (std::rand())) * 1.7);
                    effects[i].vy =
                    -1.2 - ((((double)(16000 < (std::rand())) * 0.6) - ((double)(16000 < (std::rand())) * 0.5)) - (double)(16000 < (std::rand())) * 0.8);
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
            case 0x19f:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3158[i];
                    effects[i].vx =
                    -0.5 - ((((double)(16000 < (std::rand())) * 1.2) - ((double)(16000 < (std::rand())) * 0.7)) - (double)(16000 < (std::rand())) * 1.7);
                    effects[i].vy =
                    -1.2 - ((((double)(16000 < (std::rand())) * 0.6) - ((double)(16000 < (std::rand())) * 0.5)) - (double)(16000 < (std::rand())) * 0.8);
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
            case 0x1a0:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3158[i];
                    effects[i].vx =
                    -0.5 - ((((double)(16000 < (std::rand())) * 1.2) - ((double)(16000 < (std::rand())) * 0.7)) - (double)(16000 < (std::rand())) * 1.7);
                    effects[i].vy =
                    -1.2 - ((((double)(16000 < (std::rand())) * 0.6) - ((double)(16000 < (std::rand())) * 0.5)) - (double)(16000 < (std::rand())) * 0.8);
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
            case 0x1a1:
                if (field0008 == 0xff) {
                    effects[i].x =
                    (double)(facing * 0x17) + positionX;
                    effects[i].y =
                    positionY - 48.0;
                }
                if (field0008 != 0xff) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if ((effects[i].frame == 0x18) &&
                        (field000a < 7)) {
                        effects[i].frame = 0;
                    }
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                    }
                }
                break;
            case 0x1a2:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 1;
                    effects[i].vx = 0.0;
                    effects[i].vy = 2.0;
                    effects[i].ay = 0.035;
                }
                if (effects[i].frame == 0) {
                    effects[i].vy = effects[i].vy + effects[i].ay;
                    if (1 < effects[i].field0080 || effects[i].y >= 0.0) {
                        effects[i].frame = 1;
                        SetVerticalShake(3,0);
                        effects[i].tick = 0;
                        field02c9 = 0x22;
                        effects[i].vy = 0.0;
                    }
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
                if ((effects[i].frame == 0) &&
                    (field3158[i] == 0)) {
                    effects[i].vx = 0.5;
                    effects[i].vy = -0.4;
                    ++field3158[i];
                }
                effects[i].vy =
                effects[i].vy + 0.005;
                if (10 < field3158[i]) {
                    effects[i].group = 1;
                }
                if (0xf < field3158[i]) {
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame -= 2;
                        ++field3158[i];
                    }
                }
                break;
            case 0x1a4:
                if (effects[i].frame == 0) {
                    effects[i].field0084 = 1;
                }
                if ((effects[i].frame == 0xe) &&
                    (effects[i].tick == 0)) {
                    field02c8 = 7;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 0x1b0;
                    }
                }
                break;
            case 0x1a5:
                if (effects[i].frame == 0) {
                    effects[i].field0084 = 1;
                }
                if ((effects[i].frame == 0xe) &&
                    (effects[i].tick == 0)) {
                    field02c8 = 7;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 0x1b0;
                    }
                }
                break;
            case 0x1a6:
                if (effects[i].frame == 0) {
                    effects[i].field0084 = 1;
                }
                if ((effects[i].frame == 0xe) &&
                    (effects[i].tick == 0)) {
                    field02c8 = 7;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 0x1b0;
                    }
                }
                break;
            case 0x1a7:
                effects[i].x = positionX;
                effects[i].y = positionY - 50.0;
                effects[i].field0084 = 1;
                if ((field314c < 0) && (effects[i].frame < 0x1c)) {
                    effects[i].frame = 0x1c;
                    effects[i].tick = 0;
                    field314c = 0;
                    break;
                }
                else {
                    effects[i].flag0048 = facing;
                    effects[i].field0080 = 0;
                    field314c = field314c + -4;
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        if (effects[i].frame == 0x1c) {
                            effects[i].frame = 8;
                        }
                        if (effects[i].frame >= frameCount) {
                            RemoveLocalEffect((short)i);
                            field314c = 0;
                            break;
                        }
                    }
                }
                break;
            case 0x1a8:
                effects[i].x = positionX;
                effects[i].y = positionY - 50.0;
                effects[i].field0084 = 1;
                if ((field314c < 0) && (effects[i].frame < 0x1c)) {
                    effects[i].frame = 0x1c;
                    effects[i].tick = 0;
                    field314c = 0;
                    break;
                }
                else {
                    effects[i].flag0048 = facing;
                    effects[i].field0080 = 0;
                    field314c = field314c + -3;
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        if (effects[i].frame == 0x1c) {
                            effects[i].frame = 8;
                        }
                        if (effects[i].frame >= frameCount) {
                            RemoveLocalEffect((short)i);
                            field314c = 0;
                            break;
                        }
                    }
                }
                break;
            case 0x1a9:
                effects[i].x = positionX;
                effects[i].y = positionY - 50.0;
                effects[i].field0084 = 1;
                if ((field314c < 0) && (effects[i].frame < 0x1c)) {
                    effects[i].frame = 0x1c;
                    effects[i].tick = 0;
                    field314c = 0;
                    break;
                }
                else {
                    effects[i].flag0048 = facing;
                    effects[i].field0080 = 0;
                    field314c = field314c + -2;
                    ++effects[i].tick;
                    if (effects[i].tick >= frameDuration) {
                        effects[i].tick = 0;
                        ++effects[i].frame;
                        if (effects[i].frame == 0x1c) {
                            effects[i].frame = 8;
                        }
                        if (effects[i].frame >= frameCount) {
                            RemoveLocalEffect((short)i);
                            field314c = 0;
                            break;
                        }
                    }
                }
                break;
            case 0x1ab:
                if (effects[i].frame == 0) {
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
            case 0x1ac:
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    if (field3140 == 0) {
                        field3158[i] = 0x1d;
                        field3258[i] = -0x34;
                    }
                    if (field3140 == 1) {
                        field3158[i] = 0x24;
                        field3258[i] = -0x26;
                    }
                    if (field3140 == 2) {
                        field3158[i] = 0x24;
                        field3258[i] = -0x48;
                    }
                }
                if (((field0008 == 0x106) || (field0008 == 0x107)) ||
                    (field0008 == 0x108)) {
                    effects[i].x =
                    (double)((int)facing * field3158[i]) +
                    positionX;
                    effects[i].y =
                    (double)field3258[i] + positionY;
                }
                if (effects[i].frame == 0) {
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
            case 0x1af:
                if ((((effects[i].frame == 8) &&
                    (effects[i].tick == 0)) &&
                    (field000a < 0x10)) && (200 < field0008)) {
                    effect.owner = 1;
                    effect.type = 0x1af;
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
            case 0x1b0:
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
            case 0x1b1:
                field3148 = 1;
                if ((field0008 > 49 && field0008 < 150) ||
                    effects[i].field0080 == 4 || effects[i].field0080 == 5) {
                    effect.type = 0x19c;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19d;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19e;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19f;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1a0;
                    EmitLocalEffect(&effect);
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                    break;
                }
                if (effects[i].frame < 4) {
                    effects[i].vx =
                    effects[i].vx +
                    effects[i].ax;
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                    if (effects[i].vx < -0.7) {
                        effects[i].vx = -0.7;
                    } else if (effects[i].vx > 0.7) {
                        effects[i].vx = 0.7;
                    }
                    if (effects[i].vy < -0.4) {
                        effects[i].vy = -0.4;
                    } else if (effects[i].vy > 0.4) {
                        effects[i].vy = 0.4;
                    }
                    if (effects[i].flag0048 != facing) {
                        effects[i].vx =
                        -effects[i].vx;
                        effects[i].flag0048 = facing;
                    }
                    if (effects[i].x <= positionX) {
                        effects[i].ax =
                        (double)(int)facing * 0.01;
                    }
                    if (effects[i].x > positionX) {
                        effects[i].ax =
                        (double)(int)facing * -0.01;
                    }
                    if (effects[i].y <=
                        positionY - 40.0) {
                        effects[i].ay = 0.01;
                    }
                    if (effects[i].y > positionY - 40.0) {
                        effects[i].ay = -0.01;
                    }
                }
                if ((3 < effects[i].frame) &&
                    (effects[i].vx =
                    effects[i].vx - 0.15,
                    effects[i].vx < 0.1)) {
                    effects[i].vx = 0.1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 4) &&
                        (field3158[i] < 1)) {
                        effects[i].frame = 0;
                        ++field3158[i];
                        return;
                    }
                    if (effects[i].frame == 4) {
                        effects[i].field0084 = 1;
                        effects[i].vx = 4.0;
                        effects[i].vy = 0.0;
                        field02c9 = 0x14;
                        return;
                    }
                    if ((effects[i].frame == 7) &&
                        (field3158[i] < 3)) {
                        effects[i].frame = 3;
                        ++field3158[i];
                    }
                    if (effects[i].frame == 8) {
                        effects[i].group = 1;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3148 = 0;
                    }
                }
                break;
            case 0x1b2:
                field3148 = 1;
                if ((field0008 > 49 && field0008 < 150) ||
                    effects[i].field0080 == 4 || effects[i].field0080 == 5) {
                    effect.type = 0x19c;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19d;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19e;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19f;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1a0;
                    EmitLocalEffect(&effect);
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                    break;
                }
                if (effects[i].frame < 4) {
                    effects[i].vx =
                    effects[i].vx +
                    effects[i].ax;
                    effects[i].vy =
                    effects[i].vy +
                    effects[i].ay;
                    if (effects[i].vx < -0.8) {
                        effects[i].vx = -0.8;
                    } else if (effects[i].vx > 0.8) {
                        effects[i].vx = 0.8;
                    }
                    if (effects[i].vy < -0.4) {
                        effects[i].vy = -0.4;
                    } else if (effects[i].vy > 0.4) {
                        effects[i].vy = 0.4;
                    }
                    if (effects[i].flag0048 != facing) {
                        effects[i].vx =
                        -effects[i].vx;
                        effects[i].flag0048 = facing;
                    }
                    if (effects[i].x <= positionX) {
                        effects[i].ax =
                        (double)(int)facing * 0.01;
                    }
                    if (effects[i].x > positionX) {
                        effects[i].ax =
                        (double)(int)facing * -0.01;
                    }
                    if (effects[i].y <=
                        positionY - 40.0) {
                        effects[i].ay = 0.01;
                    }
                    if (effects[i].y > positionY - 40.0) {
                        effects[i].ay = -0.01;
                    }
                }
                if ((3 < effects[i].frame) &&
                    (effects[i].vx =
                    effects[i].vx - 0.15,
                    effects[i].vx < 0.1)) {
                    effects[i].vx = 0.1;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 4) &&
                        (field3158[i] < 2)) {
                        effects[i].frame = 0;
                        ++field3158[i];
                        return;
                    }
                    if ((effects[i].frame == 5) &&
                        (field3158[i] < 3)) {
                        --effects[i].frame;
                        ++field3158[i];
                        effects[i].vx = 0.0;
                        effects[i].vy = 0.0;
                        effect.type = 0x199;
                        effect.x = (double)((int(effects[i].x)) + effects[i].flag0048 * 0x13);
                        effect.y = (double)((int(effects[i].y)) + 2);
                        effect.group = 2;
                        effect.layer = true;
                        effect.flag0018 = (unsigned char)facing;
                        EmitLocalEffect(&effect);
                        field02c8 = 5;
                    }
                    if (effects[i].frame == 6) {
                        effects[i].group = 1;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3148 = 0;
                    }
                }
                break;
            case 0x1b3:
                if ((effects[i].frame == 0) &&
                    (field3158[i] == 0)) {
                    effects[i].field0084 = 1;
                    ++field3158[i];
                    effects[i].SetVelocityPolar((double)(int)(((unsigned short)RandomRange(0, 0x5a)) - 0x2d),
                        ((double)((unsigned short)RandomRange(0x1e,0x19)) * 0.1));
                }
                if ((effects[i].x > 660.0) ||
                    (effects[i].x < -20.0)) {
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
            case 0x1b4:
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
            case 0x1b5:
                effects[i].vx = 1.0;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effect.owner = 0;
                    effect.type = 0x1a4;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = 0.0;
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
                        if (field3158[i] < 2) {
                            ++field3158[i];
                            effects[i].frame = 0;
                            break;
                        }
                        else {
                            RemoveLocalEffect((short)i);
                        }
                    }
                }
                break;
            case 0x1b6:
                if (field3358[i] == 0) {
                    effects[i].vx = 1.5;
                    ++field3358[i];
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effect.owner = 0;
                    effect.type = 0x1a5;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = 0.0;
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
                        if (field3158[i] < 5) {
                            ++field3158[i];
                            effects[i].vx =
                            effects[i].vx + 0.5;
                            effects[i].frame = 0;
                            break;
                        }
                        else {
                            RemoveLocalEffect((short)i);
                        }
                    }
                }
                break;
            case 0x1b7:
                if (field3358[i] == 0) {
                    effects[i].vx = 1.5;
                    ++field3358[i];
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effect.owner = 0;
                    effect.type = 0x1a6;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = 10.0;
                    effect.layer = 1;
                    if (field3258[i] == 1) {
                        effect.y = -10.0;
                        effect.layer = 0;
                    }
                    effect.flag0018 = (unsigned char)facing;
                    effect.group = 2;
                    EmitLocalEffect(&effect);
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (field3158[i] < 0xe) {
                            ++field3158[i];
                            effects[i].frame = 0;
                            effects[i].vx =
                            effects[i].vx + 0.4;
                            if (field3258[i] == 0) {
                                field3258[i] = 1;
                            }
                            else {
                                field3258[i] = 0;
                            }
                            break;
                        }
                        else {
                            RemoveLocalEffect((short)i);
                        }
                    }
                }
                break;
            case 0x1b8:
                SetHorizontalShake(0x32,3);
                effects[i].x =
                (double)(facing * 0x14) + positionX;
                effects[i].y = positionY - 52.0;
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 99;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        effects[i].type = 0x1b9;
                    }
                }
                break;
            case 0x1b9:
                effects[i].x =
                (double)(facing * 0x14) + positionX;
                effects[i].y = positionY - 52.0;
                SetHorizontalShake(0x32,3);
                SetTint(0xb0,3);
                if (field0008 != 0x13e) {
                    effects[i].frame = 0;
                    effects[i].tick = 0;
                    effects[i].type = 0x1bb;
                    break;
                }
                if ((effects[i].field0080 == 3) && (field0008 == 0x13e)) {
                    effects[i].type = 0x1bc;
                    field3150 = (int((*opponentSlot)->positionX));
                    field3154 = (int((*opponentSlot)->positionY));
                    ResetPose();
                    field0008 = 0x13f;
                    break;
                }
                if ((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) {
                    effects[i].field0084 = 99;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (field3158[i] == 0) {
                            ++field3158[i];
                            effects[i].frame = 0;
                            break;
                        }
                        else {
                            effects[i].frame = 0;
                            effects[i].type = 0x1bb;
                        }
                    }
                }

                break;
            case 0x1bb:
                effects[i].x =
                (double)(facing * 0x14) + positionX;
                effects[i].y = positionY - 52.0;
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
                field013e = 3;
                if (6 < effects[i].frame) {
                    (*opponentSlot)->SetHorizontalShake(0x32,3);
                }
                if (effects[i].frame < 7) {
                    (*opponentSlot)->ResetFrame();
                }
                SetTint(0xb0,3);
                if ((0xb < effects[i].frame) &&
                    (effects[i].vy =
                    effects[i].vy + 0.055,
                    effects[i].vy > 0.0)) {
                    effects[i].vy = 0.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame < 7) {
                        (*opponentSlot)->positionX =
                        (double)(int)(field3150 + ((unsigned short)RandomRange(0, 0x50) - 0x28));
                        (*opponentSlot)->positionY =
                        (double)(int)(field3154 - ((unsigned short)RandomRange(10,0x3c)));
                        if ((*opponentSlot)->positionX > 620.0) {
                            (*opponentSlot)->positionX = 620.0;
                        }
                        if ((*opponentSlot)->positionX < 20.0) {
                            (*opponentSlot)->positionX = 20.0;
                        }
                        if ((*opponentSlot)->positionY > -10.0) {
                            (*opponentSlot)->positionY = -10.0;
                        }
                    }
                    if (effects[i].frame == 7) {
                        (*opponentSlot)->gravity = 0.035;
                        (*opponentSlot)->velocityY = -10.5;
                        (*opponentSlot)->velocityX = 0.5;
                    }
                    if (effects[i].frame == 9) {
                        (*opponentSlot)->positionX =
                        effects[i].x + (double)(effects[i].flag0048 * 0xdd);
                        (*opponentSlot)->positionY =
                        effects[i].y - 44.0;
                    }
                    if (effects[i].frame == 10) {
                        (*opponentSlot)->positionX =
                        effects[i].x + (double)(effects[i].flag0048 * 0xe6);
                        (*opponentSlot)->positionY =
                        effects[i].y - 62.0;
                    }
                    if (effects[i].frame == 0xb) {
                        (*opponentSlot)->positionX =
                        effects[i].x + (double)(effects[i].flag0048 * 0xa3);
                        (*opponentSlot)->positionY =
                        effects[i].y - 119.0;
                    }
                    if (effects[i].frame == 0xc) {
                        (*opponentSlot)->positionX =
                        effects[i].x + (double)(effects[i].flag0048 * 0x8b);
                        (*opponentSlot)->positionY =
                        effects[i].y - 160.0;
                        effects[i].vy = -3.0;
                    }
                    if (effects[i].frame >= frameCount) {
                        if (field3158[i] == 0) {
                            ++field3158[i];
                            effects[i].frame = 0;
                            break;
                        }
                        else {
                            RemoveLocalEffect((short)i);
                            field000c = 0x23a;
                        }
                    }
                }
                break;
            case 0x1bc:
                SetHorizontalShake(0x32,3);
                (*opponentSlot)->ResetFrame();
                SetTint(0xb0,3);
                (*opponentSlot)->field013c = 0x1e;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    (*opponentSlot)->positionX =
                    (double)(int)(field3150 + ((unsigned short)RandomRange(0, 0x50) - 0x28));
                    (*opponentSlot)->positionY =
                    (double)(int)(field3154 - ((unsigned short)RandomRange(10,0x3c)));
                    if ((*opponentSlot)->positionX > 620.0) {
                        (*opponentSlot)->positionX = 620.0;
                    }
                    if ((*opponentSlot)->positionX < 20.0) {
                        (*opponentSlot)->positionX = 20.0;
                    }
                    if ((*opponentSlot)->positionY > -5.0) {
                        (*opponentSlot)->positionY = -5.0;
                    }
                    if (effects[i].frame >= frameCount) {
                        if (field3158[i] == 0) {
                            ++field3158[i];
                            effects[i].frame = 0;
                            break;
                        }
                        else {
                            effects[i].frame = 0;
                            effects[i].type = 0x1ba;
                        }
                    }
                }
                break;
            case 0x1bd:
                effects[i].y =
                (*opponentSlot)->positionY;
                effects[i].x =
                (*opponentSlot)->positionX;
                if ((field0008 == 0x13f) && (field000a == 3)) {
                    (*opponentSlot)->facing = -facing;
                    ApplyDamage(5000,700.0);
                    SetVerticalShake(8,5);
                    contextOwner->RequestTransition('\x01');
                    (*opponentSlot)->field014a = 0;
                    (*opponentSlot)->field0008 = 0x3f;
                    (*opponentSlot)->field000a = 0;
                    (*opponentSlot)->field000c = 0;
                    (*opponentSlot)->knockbackVelocityX = -0.2;
                    (*opponentSlot)->knockbackVelocityY = -1.0;
                    (*opponentSlot)->field0128 = 1;
                    effect.type = 0x34;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)((int(effects[i].y)) + -0x28);
                    effect.group = 2;
                    effect.layer = true;
                    effect.palette = 0x16;
                    contextOwner->EmitEffect(&effect);
                    effect.type = 0x1be;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1bf;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1c0;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1c1;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    RemoveLocalEffect((short)i);
                }
                ++effects[i].tick;
                --field3258[i];
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        --effects[i].frame;
                    }
                }
                break;
            case 0x1be:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    ++field3158[i];
                    effects[i].vx = -1.0;
                    effects[i].vy = -1.0;
                }
                effects[i].vy =
                effects[i].vy + 0.035;
                ++effects[i].tick;
                --field3258[i];
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        if (effects[i].group == '\x01') {
                            RemoveLocalEffect((short)i);
                            break;
                        }
                        else if (effects[i].group == '\0') {
                            effects[i].group = 1;
                        }
                    }
                }
                break;
            case 0x1bf:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    ++field3158[i];
                    effects[i].vx = -0.7;
                    effects[i].vy = -0.5;
                }
                effects[i].vy =
                effects[i].vy + 0.035;
                ++effects[i].tick;
                --field3258[i];
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        if (effects[i].group == '\x01') {
                            RemoveLocalEffect((short)i);
                            break;
                        }
                        else if (effects[i].group == '\0') {
                            effects[i].group = 1;
                        }
                    }
                }
                break;
            case 0x1c0:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    ++field3158[i];
                    effects[i].vx = 0.85;
                    effects[i].vy = -0.7;
                }
                effects[i].vy =
                effects[i].vy + 0.035;
                ++effects[i].tick;
                --field3258[i];
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        if (effects[i].group == '\x01') {
                            RemoveLocalEffect((short)i);
                            break;
                        }
                        else if (effects[i].group == '\0') {
                            effects[i].group = 1;
                        }
                    }
                }
                break;
            case 0x1c1:
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    ++field3158[i];
                    effects[i].vx = 0.1;
                    effects[i].vy = -0.9;
                }
                effects[i].vy =
                effects[i].vy + 0.035;
                ++effects[i].tick;
                --field3258[i];
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        effects[i].frame = 0;
                        if (effects[i].group == '\x01') {
                            RemoveLocalEffect((short)i);
                            break;
                        }
                        else if (effects[i].group == '\0') {
                            effects[i].group = 1;
                        }
                    }
                }
                break;
            case 0x1c2:
                if ((effects[i].frame == 2) &&
                    (effects[i].tick == 0)) {
                    effect.type = 0x1c3;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.flag0018 = (unsigned char)effects[i].flag0048;
                    effect.layer = true;
                    effect.group = 0;
                    effect.owner = 1;
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
            case 0x1c3:
                field3148 = 1;
                effects[i].vx = 0.0;
                effects[i].vy = 0.0;
                if ((field0008 > 49 && field0008 < 150) ||
                    effects[i].field0080 == 4 || effects[i].field0080 == 5) {
                    effect.type = 0x19c;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)effects[i].flag0048;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19d;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19e;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19f;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1a0;
                    EmitLocalEffect(&effect);
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                    break;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if ((effects[i].frame == 4) &&
                        (field3158[i] < 2)) {
                        effects[i].frame = 0;
                        ++field3158[i];
                        return;
                    }
                    if ((effects[i].frame == 5) &&
                        (field3158[i] < 3)) {
                        --effects[i].frame;
                        ++field3158[i];
                        effects[i].vx = 0.0;
                        effects[i].vy = 0.0;
                        effect.type = 0x199;
                        effect.x = (double)((int(effects[i].x)) + effects[i].flag0048 * 0x13);
                        effect.y = (double)((int(effects[i].y)) + 2);
                        effect.group = 2;
                        effect.layer = true;
                        effect.flag0018 = (unsigned char)effects[i].flag0048;
                        EmitLocalEffect(&effect);
                        field02c8 = 5;
                    }
                    if (effects[i].frame == 6) {
                        effects[i].group = 1;
                    }
                    if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3148 = 0;
                    }
                }
                break;
            case 0x1c4:
                if ((effects[i].frame == 2) &&
                    (effects[i].tick == 0)) {
                    effect.type = 0x1c6;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.flag0018 = (unsigned char)effects[i].flag0048;
                    effect.layer = true;
                    effect.group = 0;
                    effect.owner = 1;
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
            case 0x1c5:
                field3148 = 1;
                effects[i].field0084 = 1;
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if ((effects[i].frame == 0xc) ||
                        (effects[i].frame == 0x18)) {
                        effects[i].field0080 = 0;
                    }
                    if ((effects[i].frame == 0x18) &&
                        (field3158[i] < 3)) {
                        effects[i].frame = 0;
                        ++field3158[i];
                        break;
                    }
                    else if (effects[i].frame >= frameCount) {
                        RemoveLocalEffect((short)i);
                        field3148 = 0;
                    }
                }
                break;
            case 0x1c6:
                field3148 = 1;
                if ((field0008 > 49 && field0008 < 150) ||
                    effects[i].field0080 == 4 || effects[i].field0080 == 5) {
                    effect.type = 0x19c;
                    effect.x = (double)(int(effects[i].x));
                    effect.y = (double)(int(effects[i].y));
                    effect.group = 0;
                    effect.layer = true;
                    effect.flag0018 = (unsigned char)facing;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19d;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19e;
                    EmitLocalEffect(&effect);
                    effect.type = 0x19f;
                    EmitLocalEffect(&effect);
                    effect.type = 0x1a0;
                    EmitLocalEffect(&effect);
                    RemoveLocalEffect((short)i);
                    field3148 = 0;
                    break;
                }
                if (((effects[i].frame == 0) &&
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    effects[i].vx = 1.65;
                    effects[i].vy = 0.5;
                }
                effects[i].vx =
                effects[i].vx - 0.01;
                effects[i].vy =
                effects[i].vy - 0.013;
                if (effects[i].vx < 0.0) {
                    effects[i].vx = 0.0;
                }
                ++effects[i].tick;
                if (effects[i].tick >= frameDuration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    effects[i].field0080 = 0;
                    if (effects[i].frame >= frameCount) {
                        if (field3158[i] < 0) {
                            ++field3158[i];
                            effects[i].frame = 0;
                            break;
                        }
                        effects[i].type = 0x1c5;
                        effects[i].frame = 0;
                        effects[i].tick = 0;
                        effects[i].group = 2;
                        effects[i].field0080 = 0;
                        effects[i].vx = 0.0;
                        effects[i].vy = 0.0;
                        field3158[i] = 0;
                        break;
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
                    (effects[i].tick == 0)) && (field3158[i] == 0)) {
                    field3258[i] =
                    (unsigned int)(16000 < (std::rand())) * 0x28 + 0x50 + (unsigned int)(16000 < (std::rand())) * 0x14;
                    ++field3158[i];
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
void SecondaryEffectSlot::SetVelocityPolar(double angle, double speed)
{
    vx = std::cos(angle / 57.29579143313326) * speed;
    vy = std::sin(angle / 57.29579143313326) * speed;
}
