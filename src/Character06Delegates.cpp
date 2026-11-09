// Nagamori's locomotion delegate, timer update and effect-pool writer.
#include "CharacterViews.h"

void Character06::Slot03()
{
    UpdateLocomotionState();
}

void Character06::Slot08()
{
    if (field315c > 0) {
        --field315c;
    }
}

void Character06::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}
