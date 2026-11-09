// Ikumi changes between the normal and additional pattern/sequence banks.
#include "CharacterViews.h"

// Each opponent/pattern reference lives in a 0x98-byte slot beginning at
// +0x04D8; the first word of each slot is its currently selected pattern.
struct IkumiPatternSlotView {
    PatternSequence *pattern;
    unsigned char unknown[0x94];
};

void Character14::SetAlternateMode(char selected)
{
    if (selected == 1 && (char)alternateMode == 0) {
        patterns = alternatePatterns;
        for (int i = 0; i < 64; ++i) {
            reinterpret_cast<IkumiPatternSlotView *>(
                reinterpret_cast<unsigned char *>(this) + 0x4d8)[i].pattern = alternatePatterns;
        }
        sequences = alternateSequences;
        alternateMode = 1;
    } else if (selected == 0 && (char)alternateMode == 1) {
        patterns = savedPatterns;
        for (int j = 0; j < 64; ++j) {
            reinterpret_cast<IkumiPatternSlotView *>(
                reinterpret_cast<unsigned char *>(this) + 0x4d8)[j].pattern = savedPatterns;
        }
        sequences = savedSequences;
        alternateMode = 0;
    }
}
