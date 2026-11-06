// Shiori's constructor; individual virtual bodies remain separate reconstruction units.
#include "CharacterViews.h"
#include <cstring>

Character08::Character08(Secondary **opponent, Context *context, Video *video,
Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "shiori");
    surfaceCount = 782;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field2ad0[0] = -4;
    field2af8[0] = -57;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 21;
    field2af8[2] = -12;
    field2ad0[3] = 18;
    field2af8[3] = -15;
    field2ad0[4] = 38;
    field2af8[4] = -39;
    commandCount = 5;
    commands[0] = 1;
    // The original constructor writes command slot 1 twice.
    commands[1] = 7;
    commands[1] = 11;
    commands[2] = 0;
    commands[3] = 13;
    commands[10] = 8;
    for (int i = 0; i < 64; ++i) {
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
}
