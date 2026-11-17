// Native Scene6 options number-background transition, 0x0075D660.
// A two-part timed 11-frame palette fade wraps in-place asset replacement,
// including the original alternate bitmap path and DirectDraw palette updates.
#include "Engine.h"
#include <cstring>
#include <cstdlib>

extern const char scene6BackdropNumberPrefix[];
extern const char scene6BackdropHundredsZero[];
extern const char scene6BackdropTensZero[];
extern const char scene6BackdropPackedExtension[];
extern const char scene6BackdropBitmapExtension[];

typedef char Scene6NumberBackdropLayoutCheck[(sizeof(Scene6) == 0x760) ? 1 : -1];

void Scene6::TransitionNumberBackdrop()
{
    char filename[52];
    char decimalNumber[20];
    struct AnimationClock {
        DWORD lastTick;
        unsigned int alternateDelay;
    } clock;
    clock.lastTick = timeGetTime();
    clock.alternateDelay = 0;
    int frame;
    for (frame = 10; frame >= 0; --frame) {
        Slot0();
        videoOwner->DarkenPalette(palette, 0, 255, frame * 10);
        while (timeGetTime() - clock.lastTick <
               static_cast<unsigned char>(16 - clock.alternateDelay)) {
        }
        clock.lastTick = timeGetTime();
        clock.alternateDelay = (clock.alternateDelay == 0);
    }

    std::strcpy(filename, scene6BackdropNumberPrefix);
    if (numberBackdropIndex < 100) std::strcat(filename, scene6BackdropHundredsZero);
    if (numberBackdropIndex < 10) std::strcat(filename, scene6BackdropTensZero);
    _itoa(numberBackdropIndex, decimalNumber, 10);
    std::strcat(filename, decimalNumber);
    if (numberBackdrop != 0) {
        numberBackdrop->Release();
        numberBackdrop = 0;
    }
    if (1) {
        std::strcat(filename, scene6BackdropPackedExtension);
        contextOwner->LoadObjectFile(&numberBackdrop, filename, 0, 1);
        videoOwner->LoadPalette(palette, filename, 0, 1, 254);
    } else {
        std::strcat(filename, scene6BackdropBitmapExtension);
        videoOwner->LoadSurface(&numberBackdrop, filename, 1);
        videoOwner->LoadBitmapPalette(palette, filename, 0, 1, 254);
    }
    numberBackdropPhase = 2;
    for (frame = 0; frame <= 10; ++frame) {
        Slot0();
        videoOwner->DarkenPalette(palette, 0, 255, frame * 10);
        while (timeGetTime() - clock.lastTick <
               static_cast<unsigned char>(16 - clock.alternateDelay)) {
        }
        clock.lastTick = timeGetTime();
        clock.alternateDelay = (clock.alternateDelay == 0);
    }
}
