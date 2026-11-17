// Native replay/menu scene destructor at 0x0076EFE0, normal C++.
// The original vtable is at 0x007897DC: Slot0 0x0076F780,
// Step 0x0076F060, PollKeyboard 0x00770D80.
#include "Engine.h"

typedef char Scene8LayoutMustMatch[(sizeof(Scene8)==0x758) ? 1 : -1];

Scene8::~Scene8()
{
    if (replayBackgroundSurface) {
        replayBackgroundSurface->Release();
        replayBackgroundSurface = 0;
    }
    if (replayOverlaySurface) {
        replayOverlaySurface->Release();
        replayOverlaySurface = 0;
    }
}
