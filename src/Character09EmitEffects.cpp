// Sayuri clears the indexed effect slot before adding the next local effect.
#include "CharacterViews.h"

void Character09::EmitLocalEffect(SecondaryEffectSpawn *effect)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(effect);
}
