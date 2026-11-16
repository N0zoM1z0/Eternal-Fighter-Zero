// Akane's complete original stance, collision pair, and local-effect initialization.
#include "CharacterViews.h"

struct Character02InitializeFields {
    unsigned char inherited[0x3138];
    int field3138, field313c, field3140, field3144, field3148;
    int effectA[64], effectB[64], effectC[64];
};
#define C02 (reinterpret_cast<Character02InitializeFields *>(this))

void Character02::InitializeState()
{
    C02->field3138 = 0;
    C02->field313c = 0;
    C02->field3140 = 0;
    C02->field3144 = 0;
    C02->field3148 = 0;
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
        C02->effectA[i] = 0;
        C02->effectB[i] = 0;
        C02->effectC[i] = 0;
    }
    Secondary::InitializeState();
}
#undef C02
