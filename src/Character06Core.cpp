// Nagamori's original pose reset and per-slot effect ownership cleanup.
#include "CharacterViews.h"

void Character06::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character06::RemoveLocalEffect(short index)
{
    field316c[index] = 0;
    field31ac[index] = 0;
    field32ac[index] = 0;
    field33ac[index] = 0;
    Secondary::RemoveLocalEffect(index);
}
