// Nanase's initialization restores the active pattern bank and pose defaults.
#include "CharacterViews.h"

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
#define C00 (reinterpret_cast<Character00Layout *>(this))

void Character00::InitializeState()
{
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
    for (int i = 0; i < 64; ++i) {
        C00->field314c[i] = 0;
        C00->field324c[i] = 0;
        C00->field334c[i] = 0;
    }
    Secondary::InitializeState();
}

void Character00::Slot08()
{
}
#undef C00
