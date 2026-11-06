// Mizuka initialization, pose reset and local-effect ownership.
#include "Character24.h"

void Character24::InitializeState()
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
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
    Secondary::InitializeState();
}
void Character24::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}
void Character24::RemoveLocalEffect(short slot)
{
    field3148[slot] = 0;
    field3248[slot] = 0;
    field3348[slot] = 0;
    Secondary::RemoveLocalEffect(slot);
}
void Character24::Slot03() { UpdateLocomotionState(); }
void Character24::Slot01() {}
void Character24::Slot08() {}
void Character24::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}
