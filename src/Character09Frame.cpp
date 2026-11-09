// Sayuri's original character construction and default command slots.
#include "CharacterViews.h"
#include <cstring>

Character09::Character09(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "sayuri");
    surfaceCount = 576;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field314c = 0;
    field3148 = 0;
    field3150 = 999;
    field2ad0[0] = 0;
    field2af8[0] = -64;
    field2ad0[1] = 19;
    field2af8[1] = 0;
    field2ad0[2] = -24;
    field2af8[2] = -13;
    field2ad0[3] = 12;
    field2af8[3] = -16;
    field2ad0[4] = 21;
    field2af8[4] = -47;
    commandCount = 5;
    commands[0] = 1;
    commands[1] = 2;
    commands[10] = 9;
    for (int i = 0; i < 64; ++i) {
        field3154[i] = 0;
        field3254[i] = 0;
        field3354[i] = 0;
    }
}
