// Shared character reset state and the complete 64-slot local effect owner.
#include "Engine.h"

void Secondary::ResetFrame()
{
    velocityX = 0.0;
    velocityY = 0.0;
    horizontalDeceleration = 0.0;
    gravity = 0.0;
    field00b8 = 0.0;
}

void Secondary::InitializeState()
{
    int i;
    positionX = player * 160 + 240;
    positionY = 0.0;
    facing = 1 - player * 2;
    ResetFrame();
    field00b0 = 0.0;
    field00d0 = 0;
    field0008 = 0;
    field000a = 0;
    field000c = 0;
    field30bc = 0;
    field30c4 = 0;
    field0108 = 9999;
    field010c = 9999;
    field0110 = 9999;
    field0148 = 0;
    field0118 = 0.0;
    field0120 = 0;
    field014c = 0;
    field0159 = 0;
    field0158 = 0;
    field015a = 0;
    field014e = 0;
    field0150 = 0;
    field00ac = 0;
    field0138 = 0;
    field013a = 0;
    field013c = 0;
    field013e = 0;
    field0140 = 0;
    field015c = 0;
    field0160 = 0;
    field0168 = 0;
    field014a = 0;
    field0134 = 0;
    field0174 = 0;
    field00f4 = 0;
    field0104 = 0;
    field0178 = 10000.0;
    field00f8 = 10000.0;
    field0170 = 0;
    field0180 = 1.0;
    field01a8 = 0;
    field01a9 = 0;
    field0262 = 99;
    field0260 = 0;
    for (i = 0; i < 180; ++i) history[i] = 0;
    field02c8 = -1;
    field02c9 = -1;
    effectWrite = 0;
    effectRead = 0;
    ClearLocalEffects();
    trail.position = 0;
    trail.pending = 0;
    trail.held = 0;
    field30f0 = 0;
    field30ec = 0;
    field0058 = 0;
    field0060 = 1;
    field30dc = 0;
    field30d4 = 0;
    field30d8 = 0;
}

void Secondary::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    effectActive[effectWrite] = 1;
    effectOwner[effectWrite] = spawn->owner;
    effects[effectWrite].type = spawn->type;
    effects[effectWrite].frame = 0;
    effects[effectWrite].tick = 0;
    effects[effectWrite].x = spawn->x;
    effects[effectWrite].y = spawn->y;
    effects[effectWrite].vx = 0.0;
    effects[effectWrite].vy = 0.0;
    effects[effectWrite].ax = 0.0;
    effects[effectWrite].ay = 0.0;
    effects[effectWrite].flag0048 = spawn->flag0018;
    effects[effectWrite].facing = spawn->facing;
    effects[effectWrite].group = spawn->group;
    effects[effectWrite].palette = spawn->palette;
    effects[effectWrite].payload = spawn->payload;
    effects[effectWrite].layer = spawn->layer;
    effects[effectWrite].field0058 = spawn->field0028;
    effects[effectWrite].field0088 = spawn->field0030;
    effects[effectWrite].field008c = 0;
    effects[effectWrite].bounds = spawn->bounds;
    effects[effectWrite].field0080 = 0;
    effects[effectWrite].field0084 = 0;
    effects[effectWrite].field0086 = 0;
    effects[effectWrite].field0070 = 0.0;
    effects[effectWrite].field0078 = 0.0;
    AdvanceEffectWrite();
}

void Secondary::RemoveLocalEffect(short index)
{
    effectActive[index] = 0;
    effectOwner[index] = 0;
    if (index == effectRead) {
        while (effectRead != effectWrite && effectActive[effectRead] == 0) {
            ++effectRead;
            if (effectRead >= 64) effectRead = 0;
        }
    }
}

void Secondary::AdvanceEffectWrite()
{
    int scanned = 0;
    do {
        ++effectWrite;
        if (effectWrite >= 64) effectWrite = 0;
        if (effectWrite == effectRead) {
            ++effectRead;
            if (effectRead >= 64) effectRead = 0;
            while (effectRead != effectWrite && effectActive[effectRead] == 0) {
                ++effectRead;
                if (effectRead >= 64) effectRead = 0;
            }
        }
        ++scanned;
    } while (effectOwner[effectWrite] != 0 && scanned < 63);
}

void Secondary::ClearLocalEffects()
{
    for (int i = 0; i < 64; ++i) {
        effectActive[i] = 0;
        effectOwner[i] = 0;
    }
}
