// Sayuri's animation reset and complete character-specific state initialization.
#include "CharacterViews.h"

void Character09::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character09::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field314c = 0;
    field3148 = 0;
    field3150 = 999;

    field2ad0[0] = 0;
    field2af8[0] = -64;
    field2ad0[1] = 19;
    field2af8[1] = 0;
    field2ad0[2] = -24;
    field2af8[2] = -13;
    field2ad0[3] = 12;
    field2af8[3] = -16;
    field2ad0[4] = 21;
    field2af8[4] = -47;

    for (int i = 0; i < 64; ++i) {
        field3154[i] = 0;
        field3254[i] = 0;
        field3354[i] = 0;
    }
    Secondary::InitializeState();
}
