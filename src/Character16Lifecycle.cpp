// Akiko original lifecycle reset and local-effect virtual methods.
#include "CharacterViews.h"

void Character16::InitializeState()
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
    field2ad0[0] = -6;
    field2af8[0] = -72;
    field2ad0[1] = -22;
    field2af8[1] = 0;
    field2ad0[2] = 12;
    field2af8[2] = -14;
    field2ad0[3] = 22;
    field2af8[3] = -19;
    field2ad0[4] = 27;
    field2af8[4] = -41;
    for (int i = 0; i < 64; ++i) {
        field3164[i] = 0;
        field3264[i] = 0;
        field3364[i] = 0;
    }
    Secondary::InitializeState();
}

void Character16::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character16::RemoveLocalEffect(short index)
{
    field3164[index] = 0;
    field3264[index] = 0;
    field3364[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character16::Slot03()
{
    UpdateLocomotionState();
}

void Character16::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
