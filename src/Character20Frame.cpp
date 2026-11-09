// Kano's original child-state constructor and collision/command defaults.
#include "CharacterViews.h"
#include <cstring>

Character20::Character20(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "kano");
    surfaceCount = 1076;
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
    field3164 = 0;
    field3168 = 0;
    field316c = 0;
    field3170 = 0;
    field2ad0[0] = -13;
    field2af8[0] = -56;
    field2ad0[1] = 19;
    field2af8[1] = 0;
    field2ad0[2] = 11;
    field2af8[2] = -7;
    field2ad0[3] = -3;
    field2af8[3] = -19;
    field2ad0[4] = -22;
    field2af8[4] = -38;
    commandCount = 5;
    commands[0] = 23;
    commands[1] = 24;
    commands[10] = 20;
    for (int i = 0; i < 64; ++i) {
        field3174[i] = 0;
        field3274[i] = 0;
        field3374[i] = 0;
    }
}
