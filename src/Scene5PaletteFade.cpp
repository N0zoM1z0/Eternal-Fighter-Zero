// Scene5 settings/options palette fade, native 0x0075D8D0, 146 bytes.
// Ordinary C++: Draw the scene and fade its 255-entry 8-bit color palette
// from intensity 100 down to zero while alternating 16/15 ms delays.
// The source executable's sole byte argument is not read by this routine.
#include "Engine.h"

// Verify that replacing the old Scene5 declaration macro did not change
// the actual scene layout. Compile-time check only; no padding or code.
typedef char Scene5NativeLayoutMustMatch[(sizeof(Scene5) == 0x474) ? 1 : -1];

// The existing Scene5 class owns the same Scene::palette and videoOwner
// offsets used by the original WINMM-timed rendering loop.
void Scene5::FadeConfigPalette(unsigned char unusedFadeMode)
{
    DWORD lastTick = timeGetTime();
    unsigned int alternation = 0;
    for (int brightness = 20; brightness >= 0; --brightness) {
        Slot0();
        videoOwner->DarkenPalette(palette, 1, 255, brightness * 5);
        while (timeGetTime() - lastTick <
               static_cast<unsigned char>(16 - alternation)) {
        }
        lastTick = timeGetTime();
        alternation = (alternation == 0);
    }
}


// Companion native settings-scene two-range palette fade at 0x0075D970.
void Scene5::FadeConfigPaletteIn(unsigned char transition)
{
    DWORD lastTick = timeGetTime();
    unsigned int alternation = 0;
    for (int brightness = 0; brightness <= 20; ++brightness) {
        Slot0();
        videoOwner->DarkenPalette(palette, 1, transition, brightness << 1);
        videoOwner->DarkenPalette(palette, transition, 255, brightness * 5);
        while (timeGetTime() - lastTick <
               static_cast<unsigned char>(16 - alternation)) {
        }
        lastTick = timeGetTime();
        alternation = (alternation == 0);
    }
}
