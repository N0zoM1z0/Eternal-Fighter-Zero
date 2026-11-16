// Nanase's per-state reset, effect bookkeeping and locomotion entry.
// The child-only fields are local views at their reviewed object offsets.
#include "CharacterViews.h"

struct Character00LifecycleFields {
    unsigned char inherited[0x3138];
    int field3138, field313c, field3140, field3144, field3148;
    int localEffectA[64], localEffectB[64], localEffectC[64];
};
#define C00 (reinterpret_cast<Character00LifecycleFields *>(this))

void Character00::ResetPose()
{
    C00->field3138 = 0;
    C00->field313c = 0;
    C00->field3140 = 0;
    Secondary::ResetPose();
}

void Character00::RemoveLocalEffect(short index)
{
    C00->localEffectA[index] = 0;
    C00->localEffectB[index] = 0;
    C00->localEffectC[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character00::Slot03()
{
    UpdateLocomotionState();
}

void Character00::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}
#undef C00
