// Akiko's child construction and exact original command defaults.
#include "CharacterViews.h"
#include <cstring>

Character16::Character16(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "akiko");
    surfaceCount = 603;
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
    field3160 = 0;
    field2ad0[0] = -6;
    field2af8[0] = -72;
    field2ad0[1] = -22;
    field2af8[1] = 0;
    field2ad0[2] = 12;
    field2af8[2] = -14;
    field2ad0[3] = 22;
    field2af8[3] = -19;
    field2ad0[4] = 27;
    field2af8[4] = -41;
    commandCount = 4;
    commands[0] = 16;
    commands[1] = 1;
    commands[2] = 10;
    commands[3] = 3;
    commands[4] = 23;
    commands[5] = 19;
    commands[6] = 17;
    for (int i = 0; i < 64; ++i) {
        field3164[i] = 0;
        field3264[i] = 0;
        field3364[i] = 0;
    }
}
