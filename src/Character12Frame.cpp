// EX Nanase's original child-state constructor, collision and command defaults.
#include "CharacterViews.h"
#include <cstring>

Character12::Character12(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "EXnanase");
    surfaceCount = 965;
    field3460 = 0;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field3454 = 0;
    field314c = 0;
    field3150 = 0;
    field2ad0[0] = -12;
    field2af8[0] = -58;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 16;
    field2af8[2] = -9;
    field2ad0[3] = 21;
    field2af8[3] = -14;
    field2ad0[4] = 33;
    field2af8[4] = -26;
    commandCount = 5;
    commands[0] = 6;
    commands[1] = 2;
    commands[2] = 5;
    commands[10] = 0;
    for (int i = 0; i < 64; ++i) {
        field3154[i] = 0;
        field3254[i] = 0;
        field3354[i] = 0;
    }
}
