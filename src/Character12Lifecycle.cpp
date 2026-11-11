// EX Nanase original per-state initialization and virtual local-effect lifecycle.
#include "CharacterViews.h"

void Character12::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field3454 = 0;
    field314c = 0;
    field3150 = 0;
    field2ad0[0] = -12;
    field2af8[0] = -58;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 16;
    field2af8[2] = -9;
    field2ad0[3] = 21;
    field2af8[3] = -14;
    field2ad0[4] = 33;
    field2af8[4] = -26;
    for (int i = 0; i < 64; ++i) {
        field3154[i] = 0;
        field3254[i] = 0;
        field3354[i] = 0;
    }
    Secondary::InitializeState();
}

void Character12::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character12::RemoveLocalEffect(short index)
{
    field3154[index] = 0;
    field3254[index] = 0;
    field3354[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character12::Slot03()
{
    UpdateLocomotionState();
}

void Character12::Slot01()
{
}

void Character12::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
