// MizukaB natural constructor, from the complete reviewed target owner.
#include "CharacterViews.h"
#include <cstring>

Character18::Character18(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "mizukaB");
    surfaceCount = 851;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field2ad0[0] = -13;
    field2af8[0] = -60;
    field2ad0[1] = 14;
    field2af8[1] = 0;
    field3448 = 0;
    field344c = 0;
    field3450 = 0;
    field3454 = 0;
    field3458 = 0;
    field345c = 0;
    commandCount = 6;
    commands[0] = 6;
    commands[1] = 1;
    commands[2] = 7;
    commands[10] = 18;
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
}
