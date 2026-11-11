// Character04 original lifecycle and local effect array resets. The currently
// provisional child-field offsets are represented only in this translation
// unit, keeping the shared class declarations and all accepted units intact.
#include "CharacterViews.h"

struct Character04LifecycleFields {
    unsigned char base[0x3138];
    int field3138, field313c, field3140, field3144, field3148;
    int field314c, field3150, field3154;
    int field3158[64], field3258[64], field3358[64];
};
#define C04 (reinterpret_cast<Character04LifecycleFields *>(this))

void Character04::InitializeState()
{
    C04->field3138 = 0;
    C04->field313c = 0;
    C04->field3140 = 0;
    field2ad0[0] = -23;
    field2af8[0] = -58;
    field2ad0[1] = -24;
    field2af8[1] = 0;
    field2ad0[2] = 4;
    field2af8[2] = -8;
    field2ad0[3] = 7;
    field2af8[3] = -12;
    field2ad0[4] = 30;
    field2af8[4] = -22;
    C04->field3144 = 0;
    C04->field3148 = 0;
    C04->field314c = 0;
    C04->field3150 = 0;
    C04->field3154 = 0;
    for (int i = 0; i < 64; ++i) {
        C04->field3158[i] = 0;
        C04->field3258[i] = 0;
        C04->field3358[i] = 0;
    }
    Secondary::InitializeState();
}

void Character04::ResetPose()
{
    C04->field3138 = 0;
    C04->field313c = 0;
    C04->field3140 = 0;
    Secondary::ResetPose();
}

void Character04::RemoveLocalEffect(short index)
{
    C04->field3158[index] = 0;
    C04->field3258[index] = 0;
    C04->field3358[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character04::Slot03()
{
    UpdateLocomotionState();
}

void Character04::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
#undef C04
