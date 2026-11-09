// Ikumi's extra pattern/sequence construction and original command defaults.
#include "CharacterViews.h"
#include <cstring>

Character14::Character14(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    alternatePatterns = new PatternSequence[505];
    alternateSequences = new SecondarySequence[505];
    SetAlternateMode(0);
    alternateMode = 0;
    std::strcpy(resourceName, "ikumi");
    surfaceCount = 1148;
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
    field2ad0[0] = -22;
    field2af8[0] = -50;
    field2ad0[1] = -25;
    field2af8[1] = 0;
    field2ad0[2] = -25;
    field2af8[2] = -10;
    field2ad0[3] = 5;
    field2af8[3] = -9;
    field2ad0[4] = 32;
    field2af8[4] = -27;
    commandCount = 7;
    commands[0] = 8;
    commands[1] = 13;
    commands[10] = 14;
    for (int i = 0; i < 64; ++i) {
        field3160[i] = 0;
        field3260[i] = 0;
        field3360[i] = 0;
    }
}
