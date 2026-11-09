// Nayuki's original child constructor, including the nonzero state default.
#include "CharacterViews.h"
#include <cstring>

Character10::Character10(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "nayuki");
    surfaceCount = 509;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 3;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field3158 = 0;
    field2ad0[0] = -5;
    field2af8[0] = -58;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 14;
    field2af8[2] = -17;
    field2ad0[3] = 20;
    field2af8[3] = -25;
    field2ad0[4] = 36;
    field2af8[4] = -44;
    commandCount = 7;
    commands[0] = 1;
    commands[1] = 6;
    commands[2] = 16;
    commands[10] = 10;
    for (int i = 0; i < 64; ++i) {
        field315c[i] = 0;
        field325c[i] = 0;
        field335c[i] = 0;
    }
}
