#include "../../src/CharacterViews.h"
#include <cstring>

struct Character00PatternBuffer {
    void *unknown0000;
    void *field0004;
    void *Construct() { field0004 = 0; return this; }
};

struct Character00SecondaryBuffer {
    void *unknown0000;
    void *field0004;
    void *Construct() { field0004 = 0; return this; }
};

typedef void *(Character00PatternBuffer::*Character00PatternConstructor)();
typedef void *(Character00SecondaryBuffer::*Character00SecondaryConstructor)();
union Character00PatternConstructorAddress {
    Character00PatternConstructor member;
    void *address;
};
union Character00SecondaryConstructorAddress {
    Character00SecondaryConstructor member;
    void *address;
};
extern "C" void __stdcall VectorConstructorIterator(
    void *first, unsigned int elementSize, int count, void *constructor);

struct Character00ObjectView {
    unsigned char unknown_0000[0x10];
    void *field0010;
    unsigned char unknown_0014[0x150];
    void *field0164;
    unsigned char unknown_0168[0x3138 - 0x168];
    int field3138, field313c, field3140, field3144, field3148;
    int field314c[64], field324c[64], field334c[64];
    int field344c, field3450, field3454;
    unsigned char modeFlag;
    unsigned char unknown_3459[3];
    Character00PatternBuffer *patternSequences;
    Character00SecondaryBuffer *secondarySequences;
    Character00PatternBuffer *alternatePatternSequences;
    Character00SecondaryBuffer *alternateSecondarySequences;

    void SetMode(char mode);
};

void Character00ObjectView::SetMode(char mode)
{
    if ((mode == 1) && (modeFlag == 0)) {
        field0010 = patternSequences;
        for (int i = 0; i < 64; ++i) {
            *(void **)((char *)this + 0x4D8 + i * 0x98) = patternSequences;
        }
        field0164 = secondarySequences;
        modeFlag = 1;
    }
    else if ((mode == 0) && (modeFlag == 1)) {
        field0010 = alternatePatternSequences;
        for (int j = 0; j < 64; ++j) {
            *(void **)((char *)this + 0x4D8 + j * 0x98) = alternatePatternSequences;
        }
        field0164 = alternateSecondarySequences;
        modeFlag = 0;
    }
}

Character00::Character00(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "nanase");
    surfaceCount = 0x29C;
#define C00 (reinterpret_cast<Character00ObjectView *>(this))
    void *patternSequences = ::operator new(0xFCC);
    if (patternSequences != 0) {
        *(unsigned int *)patternSequences = 0x1F9;
        patternSequences = (char *)patternSequences + 4;
        VectorConstructorIterator(patternSequences, 8, 0x1F9,
            reinterpret_cast<void *>(&Character00PatternBuffer::Construct));
    }
    C00->patternSequences = (Character00PatternBuffer *)patternSequences;
    void *secondarySequences = ::operator new(0xFCC);
    if (secondarySequences != 0) {
        *(unsigned int *)secondarySequences = 0x1F9;
        secondarySequences = (char *)secondarySequences + 4;
        VectorConstructorIterator(secondarySequences, 8, 0x1F9,
            reinterpret_cast<void *>(&Character00SecondaryBuffer::Construct));
    }
    C00->secondarySequences = (Character00SecondaryBuffer *)secondarySequences;
    C00->modeFlag = 0;
    C00->field3138 = 0;
    C00->field313c = 0;
    C00->field3140 = 0;
    C00->field3144 = 0;
    C00->field3148 = 0;
    C00->field344c = 0;
    C00->field3450 = 0;
    C00->field3454 = 0;
    C00->SetMode(0);
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
