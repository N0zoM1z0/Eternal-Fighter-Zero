// NayukiB original state initializer and local-effect lifecycle.
#include "CharacterViews.h"

void Character17::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field2ad0[0] = -5;
    field2af8[0] = -61;
    field2ad0[1] = 8;
    field2af8[1] = 0;
    field2ad0[2] = 17;
    field2af8[2] = -15;
    field2ad0[3] = 19;
    field2af8[3] = -11;
    field2ad0[4] = 22;
    field2af8[4] = -30;
    for (int i = 0; i < 64; ++i) {
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
    Secondary::InitializeState();
}

void Character17::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character17::RemoveLocalEffect(short index)
{
    field3158[index] = 0;
    field3258[index] = 0;
    field3358[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character17::Slot03()
{
    UpdateLocomotionState();
}

void Character17::Slot08()
{
    if (field3150 <= 0 || health <= 0 || (*opponentSlot)->health <= 0 ||
        (field0008 > 49 && field0008 < 150)) {
        field3150 = 0;
        field314c = 0;
    }
    if (field3150 > 0) {
        field3148 += field3154;
        if (field3148 > 359)
            field3148 -= 360;
        field3150 -= 2;
        if (field3150 <= 0) {
            field3150 = 0;
            field314c = 0;
        }
    }
}

void Character17::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
