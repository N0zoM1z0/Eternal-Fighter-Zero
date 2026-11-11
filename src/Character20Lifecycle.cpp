// Kano's original character-specific state initializer and effect management.
#include "CharacterViews.h"

void Character20::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field3158 = 0;
    field315c = 0;
    field3160 = 0;
    field3164 = 0;
    field3168 = 0;
    field316c = 0;
    field3170 = 0;
    field2ad0[0] = -4;
    field2af8[0] = -57;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 21;
    field2af8[2] = -12;
    field2ad0[3] = 18;
    field2af8[3] = -15;
    field2ad0[4] = 38;
    field2af8[4] = -39;
    for (int i = 0; i < 64; ++i) {
        field3174[i] = 0;
        field3274[i] = 0;
        field3374[i] = 0;
    }
    Secondary::InitializeState();
}

void Character20::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character20::RemoveLocalEffect(short index)
{
    field3174[index] = 0;
    field3274[index] = 0;
    field3374[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character20::Slot03()
{
    UpdateLocomotionState();
}

void Character20::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
