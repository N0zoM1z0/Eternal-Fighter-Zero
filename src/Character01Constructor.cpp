#include "CharacterViews.h"
#include <cstring>

struct Character01ConstructorFields {
    unsigned char base[0x3138];
    int field3138, field313c, field3140, field3144;
    int field3148, field314c;
    int field3150[64], field3250[64], field3350[64];
};

Character01::Character01(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "ayu");
    surfaceCount = 0x2CA;
#define C01 (reinterpret_cast<Character01ConstructorFields *>(this))
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
    commandCount = 4;
    commands[0] = 1;
    commands[2] = 2;
    commands[3] = 3;
    commands[4] = 4;
    commands[5] = 0xA;
    commands[6] = 0x10;
    for (int i = 0; i < 64; ++i) {
        C01->field3150[i] = 0;
        C01->field3250[i] = 0;
        C01->field3350[i] = 0;
    }
#undef C01
}
