// Ikumi locomotion delegation and effect-pool emission override.
#include "CharacterViews.h"

void Character14::Slot03()
{
    UpdateLocomotionState();
}

void Character14::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}
