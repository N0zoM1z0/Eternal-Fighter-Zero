// Original 21-frame title palette transitions, native 0x00776820 / 0x007768D0.
// Both transitions redraw with the original 16/15 ms alternating WinMM clock.
#include "Engine.h"

typedef char Scene0PaletteOwnerSize[(sizeof(Scene0)==0x44c) ? 1 : -1];

void Scene0::FadeTitlePaletteOut()
{
    struct AnimationClock {
        DWORD lastTick;
        unsigned int alternatingDelay;
    } clock;
    clock.lastTick = timeGetTime();
    clock.alternatingDelay = 0;
    field0448 = 1;
    for (int frame = 20; frame >= 0; --frame) {
        Slot0();
        videoOwner->DarkenPalette(palette, 1, 0xc1, frame * 3 + 40);
        while (timeGetTime() - clock.lastTick <
               static_cast<unsigned char>(16 - clock.alternatingDelay)) {
        }
        clock.lastTick = timeGetTime();
        clock.alternatingDelay = (clock.alternatingDelay == 0);
    }
    field0448 = 0;
}

void Scene0::FadeTitlePaletteIn()
{
    struct AnimationClock {
        DWORD lastTick;
        unsigned int alternatingDelay;
    } clock;
    clock.lastTick = timeGetTime();
    clock.alternatingDelay = 0;
    field0448 = 1;
    for (int frame = 0; frame <= 20; ++frame) {
        Slot0();
        videoOwner->DarkenPalette(palette, 1, 0xc1, frame * 3 + 40);
        while (timeGetTime() - clock.lastTick <
               static_cast<unsigned char>(16 - clock.alternatingDelay)) {
        }
        clock.lastTick = timeGetTime();
        clock.alternatingDelay = (clock.alternatingDelay == 0);
    }
    field0448 = 0;
}
