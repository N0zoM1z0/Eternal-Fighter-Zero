// Scene6 timed menu reveal/hide, original function 0x0075DA30.
// The native frame counter is 0..90 in steps of 5 (forward or backward).
// A cosine easing curve determines a signed short-valued screen displacement.
#include "Engine.h"
#include <math.h>

typedef char Scene6AnimationLayoutMustMatch[(sizeof(Scene6) == 0x760) ? 1 : -1];

void Scene6::AnimateSettingsSlide(unsigned char reverse)
{
    struct AnimationClock {
        DWORD lastTick;
        unsigned int alternatingDelay;
    } clock;
    clock.lastTick = timeGetTime();
    clock.alternatingDelay = 0;
    if (reverse == 0) {
        for (int frame = 0; frame <= 90; frame += 5) {
            Slot0();
            settingsSlideOffset = (short)(int)
                ((1.0 - cos((double)frame / 57.29579143313326)) * 320.0);
            while (timeGetTime() - clock.lastTick <
                   static_cast<unsigned char>(16 - clock.alternatingDelay)) {
            }
            clock.lastTick = timeGetTime();
            clock.alternatingDelay = clock.alternatingDelay == 0;
        }
    } else {
        for (int frame = 90; frame >= 0; frame -= 5) {
            Slot0();
            settingsSlideOffset = (short)(int)
                ((1.0 - cos((double)frame / 57.29579143313326)) * 320.0);
            while (timeGetTime() - clock.lastTick <
                   static_cast<unsigned char>(16 - clock.alternatingDelay)) {
            }
            clock.lastTick = timeGetTime();
            clock.alternatingDelay = clock.alternatingDelay == 0;
        }
    }
}
