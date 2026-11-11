// Kaori's character-specific state reset, local effects and virtual delegates.
#include "CharacterViews.h"

void Character13::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field2ad0[0] = -8;
    field2af8[0] = -53;
    field2ad0[1] = -25;
    field2af8[1] = 0;
    field2ad0[2] = 0;
    field2af8[2] = -5;
    field2ad0[3] = 2;
    field2af8[3] = -13;
    field2ad0[4] = 31;
    field2af8[4] = -29;
    for (int i = 0; i < 64; ++i) {
        field314c[i] = 0;
        field324c[i] = 0;
        field334c[i] = 0;
    }
    Secondary::InitializeState();
}

void Character13::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character13::RemoveLocalEffect(short index)
{
    field314c[index] = 0;
    field324c[index] = 0;
    field334c[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character13::Slot01()
{
}

void Character13::Slot03()
{
    UpdateLocomotionState();
}

void Character13::Slot08()
{
}

void Character13::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
