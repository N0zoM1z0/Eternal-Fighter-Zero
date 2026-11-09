// NayukiB's complete child constructor, original collision and command defaults.
#include "CharacterViews.h"
#include <cstring>

Character17::Character17(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "nayukiB");
    surfaceCount = 641;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field2ad0[0] = -5;
    field2af8[0] = -61;
    field2ad0[1] = 8;
    field2af8[1] = 0;
    field2ad0[2] = 17;
    field2af8[2] = -15;
    field2ad0[3] = 19;
    field2af8[3] = -11;
    field2ad0[4] = 22;
    field2af8[4] = -30;
    commandCount = 7;
    commands[0] = 17;
    commands[1] = 1;
    commands[2] = 13;
    commands[3] = 16;
    commands[4] = 10;
    commands[5] = 3;
    commands[6] = 6;
    for (int i = 0; i < 64; ++i) {
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
}
