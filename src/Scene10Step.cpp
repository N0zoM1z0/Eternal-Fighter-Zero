// Staff-roll music, timing and input transition, native 0x007759F0.
#include "Engine.h"

unsigned char Scene10::Step()
{
    if (staffTime == 0.0) {
        contextOwner->LoadMusic(5);
        Slot0();
        FadeIn(palette, 0);
        staffTime = staffTime + 0.5;
        return 7;
    }
    if (staffTime > 2800.0 || exitRequested != 0) {
        FadeOut(palette, 0, -500, 200);
        contextOwner->ReleaseMusic();
        staffTime = 0.0;
        exitRequested = 0;
        return 0;
    }
    contextOwner->PollInput();
    if (contextOwner->buttonA[0] != 0 || contextOwner->buttonB[0] != 0 ||
        contextOwner->buttonC[0] != 0 || contextOwner->buttonD[0] != 0) {
        exitRequested = 1;
    } else if (contextOwner->buttonA[1] != 0 || contextOwner->buttonB[1] != 0 ||
               contextOwner->buttonC[1] != 0 || contextOwner->buttonD[1] != 0) {
        exitRequested = 1;
    }
    staffTime = staffTime + 0.3;
    Slot0();
    return 7;
}
