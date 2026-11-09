// Ikumi resets her alternate animation bank and child-state scratch values.
#include "CharacterViews.h"

void Character14::InitializeState()
{
    SetAlternateMode(0);
    alternateMode = 0;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field3158 = 0;
    field315c = 0;
    field2ad0[0] = -4;
    field2af8[0] = -57;
    field2ad0[1] = -25;
    field2af8[1] = 0;
    field2ad0[2] = 21;
    field2af8[2] = -12;
    field2ad0[3] = 18;
    field2af8[3] = -15;
    field2ad0[4] = 38;
    field2af8[4] = -39;
    for (int i = 0; i < 64; ++i) {
        field3160[i] = 0;
        field3260[i] = 0;
        field3360[i] = 0;
    }
    Secondary::InitializeState();
}
