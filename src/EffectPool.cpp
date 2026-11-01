// Effect allocation records and the original 640-entry ring lifetime.
#include "Engine.h"
#include <cstring>

EffectSpawn::EffectSpawn()
{
    std::memset(this, 0, sizeof(*this));
}

void Context::EmitEffect(EffectSpawn *spawn)
{
    effectActive[field1380] = 1;
    effectOwner[field1380] = spawn->owner;
    effectFlags[field1380] = 0;
    effects[field1380].type = spawn->type;
    effects[field1380].frame = 0;
    effects[field1380].tick = 0;
    effects[field1380].x = spawn->x;
    effects[field1380].y = spawn->y;
    effects[field1380].flag0048 = spawn->flag0018;
    effects[field1380].facing = spawn->facing;
    effects[field1380].group = spawn->group;
    effects[field1380].palette = spawn->palette;
    effects[field1380].payload = spawn->payload;
    effects[field1380].layer = spawn->layer;
    AdvanceEffectWrite();
}

void Context::RemoveEffect(short slot)
{
    effectActive[slot] = 0;
    effectOwner[slot] = 0;
    if (slot == field1382) {
        while (field1382 != field1380 && effectActive[field1382] == 0) {
            effectOwner[field1382] = 0;
            ++field1382;
            if (field1382 >= 640) field1382 = 0;
        }
    }
}

void Context::AdvanceEffectWrite()
{
    int count = 0;
    do {
        ++field1380;
        if (field1380 >= 640) field1380 = 0;
        if (field1380 == field1382) {
            ++field1382;
            if (field1382 >= 640) field1382 = 0;
            while (field1382 != field1380 && effectActive[field1382] == 0) {
                effectOwner[field1382] = 0;
                ++field1382;
                if (field1382 >= 640) field1382 = 0;
            }
        }
        ++count;
    } while (effectOwner[field1380] != 0 && count < 640);
}
