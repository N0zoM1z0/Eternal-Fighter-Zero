// Akane's pose, local effects, and no-op virtual entry points.
// Child fields are addressed by their original offsets, independent of shared layouts.
#include "CharacterViews.h"

struct Character02LifecycleFields {
    unsigned char inherited[0x3138];
    int field3138, field313c, field3140, field3144, field3148;
    int localEffectA[64], localEffectB[64], localEffectC[64];
};
#define C02 (reinterpret_cast<Character02LifecycleFields *>(this))

void Character02::ResetPose()
{
    C02->field3138 = 0;
    C02->field313c = 0;
    C02->field3140 = 0;
    Secondary::ResetPose();
}

void Character02::RemoveLocalEffect(short index)
{
    C02->localEffectA[index] = 0;
    C02->localEffectB[index] = 0;
    C02->localEffectC[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character02::Slot03()
{
    UpdateLocomotionState();
}

void Character02::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}

void Character02::Slot01()
{
}

void Character02::Slot08()
{
}
#undef C02
