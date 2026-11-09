// Nagamori reset of original child-state banks and collision defaults.
#include "CharacterViews.h"

void Character06::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3148 = 0;
    field3144 = 0;
    field314c = 0;
    field3150 = 0;
    field3158 = 0;
    field3160 = 0;
    field315c = 0;
    field3164 = 0;
    field3168 = 0;
    field2ad0[0] = -2;
    field2af8[0] = -61;
    field2ad0[1] = 21;
    field2af8[1] = 0;
    field2ad0[2] = 12;
    field2af8[2] = -5;
    field2ad0[3] = 22;
    field2af8[3] = -18;
    field2ad0[4] = 25;
    field2af8[4] = -23;
    for (int i = 0; i < 64; ++i) {
        field316c[i] = 0;
        field31ac[i] = 0;
        field32ac[i] = 0;
        field33ac[i] = 0;
    }
    Secondary::InitializeState();
}
