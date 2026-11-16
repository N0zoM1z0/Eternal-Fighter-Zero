#include "CharacterViews.h"
#include <cstring>

struct Character02ConstructorFields {
    unsigned char base[0x3138];
    int field3138, field313c, field3140, field3144, field3148;
    int field314c[64], field324c[64], field334c[64];
    unsigned char unknown_344c[12];
};

Character02::Character02(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "akane");
    surfaceCount = 0x26B;
#define C02 (reinterpret_cast<Character02ConstructorFields *>(this))
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
    commandCount = 4;
    commands[0] = 2;
    commands[1] = 0xB;
    commands[2] = 1;
    commands[3] = 0x12;
    commands[4] = 4;
    for (int i = 0; i < 64; ++i) {
        C02->field314c[i] = 0;
        C02->field324c[i] = 0;
        C02->field334c[i] = 0;
    }
#undef C02
}
