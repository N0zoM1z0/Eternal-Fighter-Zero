// Mio's original character construction, including double-precision defaults.
#include "CharacterViews.h"
#include <cstring>

Character11::Character11(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "mio");
    surfaceCount = 852;
    field3138 = 0;
    field3140 = 0.0;
    field3148 = 0.0;
    field3150 = 0;
    field3154 = 0;
    field2ad0[0] = -22;
    field2af8[0] = -56;
    field2ad0[1] = 17;
    field2af8[1] = 0;
    field2ad0[2] = 15;
    field2af8[2] = -23;
    field2ad0[3] = 22;
    field2af8[3] = -26;
    field2ad0[4] = 33;
    field2af8[4] = -52;
    commandCount = 5;
    commands[0] = 4;
    commands[1] = 7;
    commands[2] = 1;
    commands[10] = 11;
    for (int i = 0; i < 64; ++i) {
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
}
