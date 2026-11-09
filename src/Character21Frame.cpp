// Minagi's child constructor and canonical collision / command initialization.
#include "CharacterViews.h"
#include <cstring>

Character21::Character21(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "minagi");
    surfaceCount = 692;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field2ad0[0] = -8;
    field2af8[0] = -66;
    field2ad0[1] = -19;
    field2af8[1] = 0;
    field2ad0[2] = 3;
    field2af8[2] = -7;
    field2ad0[3] = 9;
    field2af8[3] = -2;
    field2ad0[4] = 35;
    field2af8[4] = -37;
    commandCount = 8;
    commands[0] = 1;
    commands[1] = 0;
    commands[2] = 11;
    commands[3] = 24;
    commands[4] = 2;
    commands[5] = 19;
    commands[6] = 23;
    commands[10] = 7;
    for (int i = 0; i < 64; ++i) {
        field3154[i] = 0;
        field3254[i] = 0;
        field3354[i] = 0;
    }
}
