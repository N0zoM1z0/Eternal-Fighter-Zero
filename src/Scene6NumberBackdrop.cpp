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
    // Actual nested buffer and frame lifetimes reproduce native VC7.1 slots.
    struct TransitionFrame {
        int frame;
        unsigned int alternateDelay;
        char filename[52];
    } transition;
    {
        char decimalNumber[20];
        DWORD lastTick;
        lastTick = timeGetTime();
        transition.alternateDelay = 0;
        for (transition.frame = 10; transition.frame >= 0; --transition.frame) {
            Slot0();
            videoOwner->DarkenPalette(palette, 0, 255, transition.frame * 10);
            while (timeGetTime() - lastTick <
                   static_cast<unsigned char>(16 - transition.alternateDelay)) {
            }
            lastTick = timeGetTime();
            transition.alternateDelay = (transition.alternateDelay == 0);
        }

        std::strcpy(transition.filename, scene6BackdropNumberPrefix);
        if (numberBackdropIndex < 100) std::strcat(transition.filename, scene6BackdropHundredsZero);
        if (numberBackdropIndex < 10) std::strcat(transition.filename, scene6BackdropTensZero);
        _itoa(numberBackdropIndex, decimalNumber, 10);
        std::strcat(transition.filename, decimalNumber);
        if (numberBackdrop != 0) {
            numberBackdrop->Release();
            numberBackdrop = 0;
        }
        if (1) {
            std::strcat(transition.filename, scene6BackdropPackedExtension);
            contextOwner->LoadObjectFile(&numberBackdrop, transition.filename, 0, 1);
            videoOwner->LoadPalette(palette, transition.filename, 0, 1, 254);
        } else {
            std::strcat(transition.filename, scene6BackdropBitmapExtension);
            videoOwner->LoadSurface(&numberBackdrop, transition.filename, 1);
            videoOwner->LoadBitmapPalette(palette, transition.filename, 0, 1, 254);
        }
        numberBackdropPhase = 2;
        for (transition.frame = 0; transition.frame <= 10; ++transition.frame) {
            Slot0();
            videoOwner->DarkenPalette(palette, 0, 255, transition.frame * 10);
            while (timeGetTime() - lastTick <
                   static_cast<unsigned char>(16 - transition.alternateDelay)) {
            }
            lastTick = timeGetTime();
            transition.alternateDelay = (transition.alternateDelay == 0);
        }
    }
}
