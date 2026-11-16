// Ayu's full native pose, collision-box and local-effects initializer.
#include "CharacterViews.h"

// Separate child-only view, retaining the extra 0x314C state word.
struct Character01InitFields {
    unsigned char inherited[0x3138];
    int field3138, field313c, field3140, field3144, field3148, field314c;
    int field3150[64], field3250[64], field3350[64];
};
#define C01 (reinterpret_cast<Character01InitFields *>(this))

void Character01::InitializeState()
{
    C01->field3138 = 0;
    C01->field313c = 0;
    C01->field3140 = 0;
    C01->field3144 = 0;
    C01->field3148 = 0;
    C01->field314c = 0;
    field2ad0[0] = -17;
    field2af8[0] = -51;
    field2ad0[1] = 13;
    field2af8[1] = 0;
    field2ad0[2] = 12;
    field2af8[2] = -14;
    field2ad0[3] = 22;
    field2af8[3] = -19;
    field2ad0[4] = 27;
    field2af8[4] = -41;
    for (int i = 0; i < 64; ++i) {
        C01->field3150[i] = 0;
        C01->field3250[i] = 0;
        C01->field3350[i] = 0;
    }
    Secondary::InitializeState();
}
#undef C01
