// Kanna's character construction and its original child-state defaults.
#include "CharacterViews.h"
#include <cstring>

Character19::Character19(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "kanna");
    surfaceCount = 1243;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 60;
    field2ad0[0] = -4;
    field2af8[0] = -59;
    field2ad0[1] = 27;
    field2af8[1] = 0;
    field2ad0[2] = 11;
    field2af8[2] = -18;
    field2ad0[3] = 11;
    field2af8[3] = -13;
    field2ad0[4] = 33;
    field2af8[4] = -35;
    commandCount = 4;
    commands[0] = 1;
    commands[1] = 6;
    commands[2] = 23;
    commands[3] = 16;
    for (int i = 0; i < 64; ++i) {
        field3154[i] = 0;
        field3254[i] = 0;
        field3354[i] = 0;
    }
}
