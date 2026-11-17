// Settings interface 0x0075D580: one cosine pulse over the selected art,
// with a resource reload and palette submit at the midpoint.
// This is ordinary C++ operating on the real Scene6 object layout.
#include "Engine.h"
#include <math.h>

typedef char Scene6SettingsPreviewSizeMustMatch[(sizeof(Scene6) == 0x760) ? 1 : -1];

void Scene6::AnimateSettingsPreview()
{
    struct AnimationClock {
        DWORD lastTick;
        unsigned int alternatingDelay;
    } clock;
    clock.lastTick = timeGetTime();
    clock.alternatingDelay = 0;
    for (int frame = 0; frame <= 360; frame += 10) {
        Slot0();
        settingsPulseOffset = (int)(160.0 - cos((double)frame / 57.29579143313326) * 160.0);
        if (frame == 180) {
            ReloadSelectedPreview();
            videoOwner->ApplyPalette(palette);
        }
        while (timeGetTime() - clock.lastTick <
               static_cast<unsigned char>(16 - clock.alternatingDelay)) {
        }
        clock.lastTick = timeGetTime();
        clock.alternatingDelay = (clock.alternatingDelay == 0);
    }
    settingsPulseOffset = 0;
}
