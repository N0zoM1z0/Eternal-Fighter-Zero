// Nayuki Character10 lifecycle, lightweight virtuals and local effect plumbing.
#include "CharacterViews.h"

void Character10::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character10::Slot03()
{
    UpdateLocomotionState();
}

void Character10::Slot08()
{
}

void Character10::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}

void Character10::RemoveLocalEffect(short index)
{
    field315c[index] = 0;
    field325c[index] = 0;
    field335c[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character10::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 3;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field3158 = 0;
    field2ad0[0] = -5;
    field2af8[0] = -58;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 14;
    field2af8[2] = -17;
    field2ad0[3] = 20;
    field2af8[3] = -25;
    field2ad0[4] = 36;
    field2af8[4] = -44;
    for (int i = 0; i < 64; ++i) {
        field315c[i] = 0;
        field325c[i] = 0;
        field335c[i] = 0;
    }
    Secondary::InitializeState();
}
