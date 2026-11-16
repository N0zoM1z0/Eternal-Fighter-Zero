// Nanase pattern-bank construction and native alternate-bank switching.
#include "CharacterViews.h"
#include <cstring>

struct Character00EffectSlotView {
    unsigned char unknown_0000[8];
    PatternSequence *patterns;
    unsigned char unknown_000c[0x8c];
};

struct Character00Layout {
    unsigned char unknown_0000[0x10];
    PatternSequence *patterns;
    unsigned char unknown_0014[0x150];
    SecondarySequence *sequences;
    unsigned char unknown_0168[0x368];
    Character00EffectSlotView effects[64];
    unsigned char unknown_2ad0[0x668];
    int field3138, field313c, field3140, field3144, field3148;
    int field314c[64], field324c[64], field334c[64];
    int field344c, field3450, field3454;
    char alternateMode;
    unsigned char unknown_3459[3];
    PatternSequence *basePatterns;
    SecondarySequence *baseSequences;
    PatternSequence *alternatePatterns;
    SecondarySequence *alternateSequences;
    unsigned char unknown_346c[4];
    void SetAlternateMode(char mode);
};

void Character00Layout::SetAlternateMode(char mode)
{
    if (mode == 1 && alternateMode == 0) {
        patterns = basePatterns;
        for (int i = 0; i < 64; ++i) {
            effects[i].patterns = basePatterns;
        }
        sequences = baseSequences;
        alternateMode = 1;
    } else if (mode == 0 && alternateMode == 1) {
        patterns = alternatePatterns;
        for (int i = 0; i < 64; ++i) {
            effects[i].patterns = alternatePatterns;
        }
        sequences = alternateSequences;
        alternateMode = 0;
    }
}

Character00::Character00(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "nanase");
    surfaceCount = 0x29C;
#define C00 (reinterpret_cast<Character00Layout *>(this))
    C00->basePatterns = new PatternSequence[0x1F9];
    C00->baseSequences = new SecondarySequence[0x1F9];
    C00->alternateMode = 0;
    C00->field3138 = 0;
    C00->field313c = 0;
    C00->field3140 = 0;
    C00->field3144 = 0;
    C00->field3148 = 0;
    C00->field344c = 0;
    C00->field3450 = 0;
    C00->field3454 = 0;
    C00->SetAlternateMode(0);
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
    commands[3] = 0xC;
    commands[10] = 0;
    for (int i = 0; i < 64; ++i) {
        C00->field314c[i] = 0;
        C00->field324c[i] = 0;
        C00->field334c[i] = 0;
    }
#undef C00
}
