// Shiori's original virtual passive-frame hook has no per-frame action.
// Keep the real vtable owner rather than falsely attributing inherited code.
#include "CharacterViews.h"

void Character08::Slot08()
{
}
