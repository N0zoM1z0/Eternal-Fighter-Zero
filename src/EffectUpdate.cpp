// Complete effect-state dispatcher; names remain provisional.
// Preserve integer truncation, x87 evaluation order, and separate case lifetimes.
#include "Engine.h"
#include <cmath>
#include <cstdlib>

void Context::UpdateEffect(short slot)
{
    EffectSpawn spawn;
    int i;
    double horizontal, y; // Shared rotation components; names affect /Od stack layout.
    spawn.owner = 0;
    spawn.payload = 0;
    spawn.palette = 255;
    switch (effects[slot].type) {
        case 0x0: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 3; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 10;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
                for (i = 0; i < 3; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 35;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
                for (i = 0; i < 8; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 36;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
                for (i = 0; i < 2; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 47;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0x2: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 8; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 39;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0x5: {
            ++effects[slot].tick;
            if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
                effects[slot].tick = 0;
                ++effects[slot].frame;
                if (effects[slot].frame == 10) {
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 0;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 21;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 0;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = effectSelector + 56;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                }
                if (effects[slot].frame == 15) {
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 2;
                    spawn.layer = 1;
                    spawn.payload = 1;
                    spawn.type = 26;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                }
                if (effects[slot].frame >= patterns[effects[slot].type].count) RemoveEffect(slot);
            }
            return;
        }
        case 0xa: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (std::rand() * 3.141592 * 2) / 32768.0;
                double speed = std::rand() / 2000;
                effects[slot].vx = std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0xb: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 5; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 34;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0xc: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 8; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 34;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0xd: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 8; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 37;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
                for (i = 0; i < 5; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 34;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0xe: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 16; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 42;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0xf: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 8; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 44;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0x10: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 8; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 43;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0x15: {
            ++effects[slot].tick;
            if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
                effects[slot].tick = 0;
                ++effects[slot].frame;
                if (effects[slot].frame >= patterns[effects[slot].type].count) {
                    RemoveEffect(slot);
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 2;
                    spawn.layer = 3;
                    spawn.payload = 1;
                    spawn.type = 6;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 0;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 22;
                    spawn.palette = 23;
                    EmitEffect(&spawn);
                }
            }
            return;
        }
        case 0x16: {
            ++effects[slot].tick;
            if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
                effects[slot].tick = 0;
                ++effects[slot].frame;
                if (effects[slot].frame >= patterns[effects[slot].type].count) {
                    RemoveEffect(slot);
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 0;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 23;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                }
            }
            return;
        }
        case 0x17: {
            ++effects[slot].tick;
            if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
                effects[slot].tick = 0;
                ++effects[slot].frame;
                if (effects[slot].frame >= patterns[effects[slot].type].count) {
                    RemoveEffect(slot);
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 2;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 7;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 0;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 24;
                    spawn.palette = 24;
                    EmitEffect(&spawn);
                }
            }
            return;
        }
        case 0x18: {
            ++effects[slot].tick;
            if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
                effects[slot].tick = 0;
                ++effects[slot].frame;
                if (effects[slot].frame >= patterns[effects[slot].type].count) {
                    RemoveEffect(slot);
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 0;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 25;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                }
            }
            return;
        }
        case 0x19: {
            ++effects[slot].tick;
            if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
                effects[slot].tick = 0;
                ++effects[slot].frame;
                if (effects[slot].frame >= patterns[effects[slot].type].count) {
                    RemoveEffect(slot);
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 2;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 18;
                    spawn.palette = 255;
                    EmitEffect(&spawn);
                    effectFlag1350 = 0;
                }
            }
            return;
        }
        case 0x1a: {
            copiedEffectFrame = effects[slot].frame;
            copiedEffectTick = effects[slot].tick;
            break;
        }
        case 0x1b: {
            ++effects[slot].tick;
            if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
                effects[slot].tick = 0;
                ++effects[slot].frame;
                if (effects[slot].frame == 26) {
                    spawn.owner = 0;
                    spawn.x = 160.0;
                    spawn.y = 120.0;
                    spawn.facing = 0;
                    spawn.group = 2;
                    spawn.layer = 2;
                    spawn.payload = 1;
                    spawn.type = 5;
                    spawn.palette = effectSelector + 11;
                    EmitEffect(&spawn);
                }
                if (effects[slot].frame >= patterns[effects[slot].type].count) RemoveEffect(slot);
            }
            return;
        }
        case 0x21: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                effectPhase = 0;
                for (i = 0; i < 40; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 38;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0x22: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (std::rand() * 3.141592 * 2) / 32768.0;
                double speed = std::rand() / 20000.0;
                effects[slot].vx = std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x23: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (std::rand() * 3.141592 * 2) / 32768.0;
                double speed = std::rand() / 20000.0;
                effects[slot].vx = std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x24: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (std::rand() * 3.141592 * 2) / 32768.0;
                double speed = std::rand() / 13000.0;
                effects[slot].vx = std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x25: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (std::rand() * 3.141592 * 2) / 32768.0;
                double speed = std::rand() / 13000.0;
                effects[slot].vx = std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x26: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (effectPhase * 9 * 3.141592) / 180.0;
                double speed = 3.0;
                horizontal = std::cos(angle) * speed;
                y = std::sin(angle) * speed / 3.0;
                effects[slot].vx = std::cos(-0.43633222222222223) * horizontal - std::sin(-0.43633222222222223) * y;
                effects[slot].vy = (effects[slot].facing * 2 - 1) * (std::cos(-0.43633222222222223) * y + std::sin(-0.43633222222222223) * horizontal);
                effectPhase = effectPhase + 1;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x27: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (std::rand() * 3.141592 * 2) / 32768.0;
                double speed = std::rand() / 13000.0;
                effects[slot].vx = (effects[slot].facing * 2 - 1) * std::cos(angle / 2.0 - 1.570796) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x2a: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = ((std::rand() * 20) / 32768 + 35 + (std::rand() < 16384) * 180) * 0.01745328888888889;
                double speed = std::rand() / 13000.0;
                effects[slot].vx = (effects[slot].facing * 2 - 1) * std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x2b: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = ((std::rand() * 40) / 32768 + 25 + (std::rand() < 16384) * 180) * 0.01745328888888889;
                double speed = std::rand() / 13000.0;
                effects[slot].vx = (effects[slot].facing * 2 - 1) * std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x2c: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = ((std::rand() * 20) / 32768 + -10 + (std::rand() < 16384) * 180) * 0.01745328888888889;
                double speed = std::rand() / 13000.0;
                effects[slot].vx = (effects[slot].facing * 2 - 1) * std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x2d: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = ((std::rand() * 40) / 32768 + -20 + (std::rand() < 16384) * 180) * 0.01745328888888889;
                double speed = std::rand() / 13000.0;
                effects[slot].vx = (effects[slot].facing * 2 - 1) * std::cos(angle) * speed;
                effects[slot].vy = std::sin(angle) * speed;
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x2e: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                effects[slot].vx = std::sin((float)std::rand()) * 6.0f;
                effects[slot].vy = -(double)std::rand() / 4000.0 - 2.0;
            }
            effects[slot].vy = effects[slot].vy + 0.2;
            if (std::rand() < 16384) ++effects[slot].tick;
            if (effects[slot].y + effects[slot].vy >= 0.0) {
                effects[slot].vy = -effects[slot].vy * (0.9 - (std::rand() / 32768.0) * 0.3);
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x2f: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                effects[slot].vx = (effects[slot].facing * 2 - 1) * -std::sqrt(std::sin((float)std::rand()) * 4.0f);
                effects[slot].vy = -(double)std::rand() / 7000.0 - 2.0;
            }
            effects[slot].vy = effects[slot].vy + 0.2;
            if (std::rand() < 16384) ++effects[slot].tick;
            if (effects[slot].y + effects[slot].vy >= 0.0) {
                effects[slot].vy = -effects[slot].vy * (0.9 - (std::rand() / 32768.0) * 0.3);
            }
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x34: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0 && setting1366 != 0) {
                for (i = 0; i < 16; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 46;
                    EmitEffect(&spawn);
                    spawn.layer = 1;
                    EmitEffect(&spawn);
                }
                effectPhase = 0;
                effectAngleStart = (short)(std::rand() / 91.02);
                effectAngleEnd = effectAngleStart + 30 + (short)(std::rand() / 273.07);
                for (i = 0; i < 40; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 53;
                    EmitEffect(&spawn);
                }
                for (i = 0; i < 40; ++i) {
                    spawn.x = (int)effects[slot].x;
                    spawn.y = (int)effects[slot].y;
                    spawn.facing = effects[slot].facing;
                    spawn.group = 2;
                    spawn.layer = 0;
                    spawn.type = 54;
                    EmitEffect(&spawn);
                }
            }
            break;
        }
        case 0x35: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (effectPhase * 9 * 3.141592) / 180.0;
                double speed = 3.0;
                horizontal = std::cos(angle) * speed * 5.0;
                y = std::sin(angle) * speed / 3.0 * 5.0;
                effects[slot].vx = std::cos((effectAngleStart * 3.141592) / 180.0) * horizontal - std::sin((effectAngleStart * 3.141592) / 180.0) * y;
                effects[slot].vy = (effects[slot].facing * 2 - 1) * (std::cos((effectAngleStart * 3.141592) / 180.0) * y + std::sin((effectAngleStart * 3.141592) / 180.0) * horizontal);
                effectPhase = effectPhase + 1;
            }
            effects[slot].vx = effects[slot].vx * 0.94;
            effects[slot].vy = effects[slot].vy * 0.94;
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
        case 0x36: {
            if (effects[slot].frame == 0 && effects[slot].tick == 0) {
                double angle = (effectPhase * 9 * 3.141592) / 180.0;
                double speed = 3.0;
                horizontal = std::cos(angle) * speed * 5.0;
                y = std::sin(angle) * speed / 3.0 * 5.0;
                effects[slot].vx = std::cos((effectAngleEnd * 3.141592) / 180.0) * horizontal - std::sin((effectAngleEnd * 3.141592) / 180.0) * y;
                effects[slot].vy = (effects[slot].facing * 2 - 1) * (std::cos((effectAngleEnd * 3.141592) / 180.0) * y + std::sin((effectAngleEnd * 3.141592) / 180.0) * horizontal);
                effectPhase = effectPhase + 1;
            }
            effects[slot].vx = effects[slot].vx * 0.94;
            effects[slot].vy = effects[slot].vy * 0.94;
            effects[slot].x = effects[slot].x + effects[slot].vx;
            effects[slot].y = effects[slot].y + effects[slot].vy;
            break;
        }
    }
    ++effects[slot].tick;
    if (effects[slot].tick >= patterns[effects[slot].type].frames[effects[slot].frame].duration) {
        effects[slot].tick = 0;
        ++effects[slot].frame;
        if (effects[slot].frame >= patterns[effects[slot].type].count) RemoveEffect(slot);
    }
}
