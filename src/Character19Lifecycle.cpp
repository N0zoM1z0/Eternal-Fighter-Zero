// Kanna's original lifecycle, local-effect slots and empty virtual delegates.
#include "CharacterViews.h"

void Character19::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 60;
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
}

void Character19::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character19::RemoveLocalEffect(short index)
{
    field3154[index] = 0;
    field3254[index] = 0;
    field3354[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character19::Slot01()
{
}

void Character19::Slot08()
{
}

void Character19::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
