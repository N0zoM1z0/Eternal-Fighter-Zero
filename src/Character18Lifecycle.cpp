// MizukaB's original lifecycle, effect-pool overrides and momentum timer.
#include "CharacterViews.h"

void Character18::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field2ad0[0] = -13;
    field2af8[0] = -60;
    field2ad0[1] = 14;
    field2af8[1] = 0;
    field3448 = 0;
    field344c = 0;
    field3450 = 0;
    field3454 = 0;
    field3458 = 0;
    field345c = 0;
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
    Secondary::InitializeState();
}

void Character18::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character18::RemoveLocalEffect(short index)
{
    field3148[index] = 0;
    field3248[index] = 0;
    field3348[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character18::Slot01()
{
}

void Character18::Slot03()
{
    UpdateLocomotionState();
}

void Character18::Slot08()
{
    if (field3458 > 0) {
        ++field345c;
        if (field345c > 0) {
            field0118 -= 1.0;
            field345c = 0;
        }
        if (field0118 <= 0.0 ||
            (field0008 < 49 && field0008 < 150) ||
            positionY == 0.0) {
            field3458 = 0;
        }
    }
}

void Character18::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
