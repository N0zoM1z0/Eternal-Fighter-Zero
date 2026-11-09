// Ikumi's state reset, effect-pool removal and the base pose reset.
#include "CharacterViews.h"

void Character14::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3154 = 0;
    Secondary::ResetPose();
}

void Character14::RemoveLocalEffect(short index)
{
    field3160[index] = 0;
    field3260[index] = 0;
    field3360[index] = 0;
    Secondary::RemoveLocalEffect(index);
}
