// Akane's complete original stance, collision pair, and local-effect initialization.
#include "CharacterViews.h"

void Character02::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field2ad0[0] = -8;
    field2af8[0] = -53;
    field2ad0[1] = 21;
    field2af8[1] = 0;
    field2ad0[2] = 0;
    field2af8[2] = -5;
    field2ad0[3] = 2;
    field2af8[3] = -13;
    field2ad0[4] = 31;
    field2af8[4] = -29;
    for (int i = 0; i < 64; ++i) {
        field314c[i] = 0;
        field324c[i] = 0;
        field334c[i] = 0;
    }
    Secondary::InitializeState();
}
