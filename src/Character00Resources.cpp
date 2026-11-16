// Nanase loads alternate pattern resources before common character resources.
#include "CharacterViews.h"

struct Character00ResourceView {
    unsigned char inherited_0000[0x10];
    PatternSequence *patterns;
    unsigned char inherited_0014[0x150];
    SecondarySequence *sequences;
    unsigned char child_and_effects[0x345c - 0x168];
    PatternSequence *basePatterns;
    SecondarySequence *baseSequences;
    PatternSequence *alternatePatterns;
    SecondarySequence *alternateSequences;

    void LoadAlternateResources();
};
#define C00 (reinterpret_cast<Character00ResourceView *>(this))

void Character00::LoadResources()
{
    C00->LoadAlternateResources();
    Secondary::LoadResources();
    C00->alternatePatterns = patterns;
    C00->alternateSequences = sequences;
}
#undef C00
