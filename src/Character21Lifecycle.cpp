// Minagi's original state initialization, wakeup and local effects.
#include "CharacterViews.h"

void Character21::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field2ad0[0] = -13;
    field2af8[0] = -60;
    field2ad0[1] = 14;
    field2af8[1] = 0;
    field2ad0[2] = 17;
    field2af8[2] = -6;
    field2ad0[3] = 7;
    field2af8[3] = -25;
    field2ad0[4] = 27;
    field2af8[4] = -25;
    for (int i = 0; i < 64; ++i) {
        field3154[i] = 0;
        field3254[i] = 0;
        field3354[i] = 0;
    }
    Secondary::InitializeState();
    EffectSpawn effect;
    ResetLocalEffectSpawn(&effect);
    effect.type = 0x190;
    effect.x = (double)((int)positionX - (int)facing * 40);
    effect.y = (double)(int)positionY;
    effect.group = 0;
    effect.payload = 0;
    effect.layer = 0;
    effect.field0028 = 1;
    effect.owner = 1;
    effect.flag0018 = (unsigned char)facing;
    EmitLocalEffect(&effect);
}

void Character21::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character21::RemoveLocalEffect(short index)
{
    field3154[index] = 0;
    field3254[index] = 0;
    field3354[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character21::Slot01()
{
}

void Character21::Slot03()
{
    UpdateLocomotionState();
}

void Character21::Slot08()
{
}

void Character21::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
