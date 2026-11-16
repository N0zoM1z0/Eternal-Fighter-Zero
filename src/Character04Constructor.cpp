#include "CharacterViews.h"
#include <cstring>

struct Character04ConstructorFields {
    unsigned char base[0x3138];
    int field3138, field313c, field3140, field3144;
    int field3148, field314c, field3150, field3154;
    int field3158[64], field3258[64], field3358[64];
};

Character04::Character04(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "mai");
    surfaceCount = 0x3A0;
#define C04 (reinterpret_cast<Character04ConstructorFields *>(this))
    C04->field3138 = 0;
    C04->field313c = 0;
    C04->field3140 = 0;
    field2ad0[0] = -20;
    field2af8[0] = -58;
    field2ad0[1] = -24;
    field2af8[1] = 0;
    field2ad0[2] = 4;
    field2af8[2] = -8;
    field2ad0[3] = 7;
    field2af8[3] = -12;
    field2ad0[4] = 30;
    field2af8[4] = -22;
    C04->field3144 = 0;
    C04->field3148 = 0;
    C04->field314c = 0;
    C04->field3150 = 0;
    C04->field3154 = 0;
    commandCount = 3;
    commands[0] = 0;
    commands[1] = 1;
    commands[2] = 9;
    commands[3] = 2;
    for (int i = 0; i < 64; ++i) {
        C04->field3158[i] = 0;
        C04->field3258[i] = 0;
        C04->field3358[i] = 0;
    }
#undef C04
}
