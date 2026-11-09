// Original Ikumi child destruction and restoration of the base-owned animation banks.
#include "CharacterViews.h"

Character14::~Character14()
{
    patterns = savedPatterns;
    sequences = savedSequences;
    delete[] alternatePatterns;
    delete[] alternateSequences;
    // The original child destructor explicitly calls its base destructor,
    // before the compiler-emitted implicit base-destructor call.
    Secondary::~Secondary();
}
