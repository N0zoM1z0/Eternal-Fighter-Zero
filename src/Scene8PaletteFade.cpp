// Native Scene8 replay UI dual-band palette fade, 0x00771170 / 0x00771230.
// Both transitions redraw on each step and use the WinMM 16/15 ms frame clock.
// Ordinary C++ with no inline assembly, emitted instructions or padding.
#include "Engine.h"

typedef char Scene8PaletteOwnerSize[(sizeof(Scene8)==0x758) ? 1 : -1];

void Scene8::FadeReplayPaletteOut()
{
    struct AnimationClock {
        DWORD lastTick;
        unsigned int alternatingDelay;
    } clock;
    clock.lastTick = timeGetTime();
    clock.alternatingDelay = 0;
    for (int frame = 20; frame >= 0; --frame) {
        Slot0();
        videoOwner->DarkenPalette(palette, 1, 0xc1, frame << 1);
        videoOwner->DarkenPalette(palette, 0xc2, 255, frame * 5);
        while (timeGetTime() - clock.lastTick <
               static_cast<unsigned char>(16 - clock.alternatingDelay)) {
        }
        clock.lastTick = timeGetTime();
        clock.alternatingDelay = (clock.alternatingDelay == 0);
    }
}

void Scene8::FadeReplayPaletteIn()
{
    struct AnimationClock {
        DWORD lastTick;
        unsigned int alternatingDelay;
    } clock;
    clock.lastTick = timeGetTime();
    clock.alternatingDelay = 0;
    for (int frame = 0; frame <= 20; ++frame) {
        Slot0();
        videoOwner->DarkenPalette(palette, 1, 0xc1, frame << 1);
        videoOwner->DarkenPalette(palette, 0xc2, 255, frame * 5);
        while (timeGetTime() - clock.lastTick <
               static_cast<unsigned char>(16 - clock.alternatingDelay)) {
        }
        clock.lastTick = timeGetTime();
        clock.alternatingDelay = (clock.alternatingDelay == 0);
    }
}
