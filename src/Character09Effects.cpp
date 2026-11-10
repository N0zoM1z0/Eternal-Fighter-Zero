// Sayuri's targeted recovery of a hit-state tint transition and local-effect
// accounting; source and addresses follow the original Character09 vtable.
#include "CharacterViews.h"

void Character09::Slot08()
{
    if (field000a == 0 && field000c == 0 &&
        field0008 > 0x95 && field0008 < 0x9c &&
        (*opponentSlot)->attackCollisionResult == 2 &&
        (*opponentSlot)->field0008 == field3150) {
        field3138 = 1;
        SetCharacterTint(0xb1, 10);
    }
}

void Character09::RemoveLocalEffect(short index)
{
    field3154[index] = 0;
    field3254[index] = 0;
    field3354[index] = 0;
    Secondary::RemoveLocalEffect(index);
}
