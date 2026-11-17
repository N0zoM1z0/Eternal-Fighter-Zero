// Akane's pose, local effects, and no-op virtual entry points.
// Akane's object-specific state and local-effect arrays have typed owner members.
#include "CharacterViews.h"

void Character02::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character02::RemoveLocalEffect(short index)
{
    field314c[index] = 0;
    field324c[index] = 0;
    field334c[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character02::Slot03()
{
    UpdateLocomotionState();
}

void Character02::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}

void Character02::Slot01()
{
}

void Character02::Slot08()
{
}
