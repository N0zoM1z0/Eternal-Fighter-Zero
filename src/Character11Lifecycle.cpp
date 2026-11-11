// Mio original state initialization and local-effect lifecycle overrides.
#include "CharacterViews.h"

void Character11::InitializeState()
{
    field3138 = 0;
    field3140 = 0.0;
    field3148 = 0.0;
    field3150 = 0;
    field3154 = 0;
    field2ad0[0] = -22;
    field2af8[0] = -56;
    field2ad0[1] = 17;
    field2af8[1] = 0;
    field2ad0[2] = 15;
    field2af8[2] = -23;
    field2ad0[3] = 22;
    field2af8[3] = -26;
    field2ad0[4] = 33;
    field2af8[4] = -52;
    for (int i = 0; i < 64; ++i) {
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
    Secondary::InitializeState();
}

void Character11::ResetPose()
{
    field3138 = 0;
    field3140 = 0.0;
    field3148 = 0.0;
    Secondary::ResetPose();
}

void Character11::RemoveLocalEffect(short index)
{
    field3158[index] = 0;
    field3258[index] = 0;
    field3358[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character11::Slot03()
{
    UpdateLocomotionState();
}

void Character11::Slot08()
{
}

void Character11::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
