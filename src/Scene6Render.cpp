// Natural C++ settings and statistics renderer, original 0x0075B0A0.
// Complete natural VC7.1 C++ owner: 8,608 code bytes and original eight-entry switch table.
#include "Engine.h"

extern SurfaceRect __cdecl MakeSurfaceRect(int left, int top, int width, int height);
typedef char Scene6RenderLayout[(sizeof(Scene6)==0x760)?1:-1];

// Original source and destination are reusable real rectangle values. Every
// expression is a meaningful sprite region, not artificial frame padding.
#define DRAW(SURFACE,KEY,SRC,DST) \
    videoOwner->DrawSurface(MakeSurfaceRect DST, SURFACE, MakeSurfaceRect SRC, KEY, 0)
#define DRAW_FIRST(SURFACE,KEY,SRC,DST) \
    work.source = MakeSurfaceRect SRC; \
    work.destination = MakeSurfaceRect DST; \
    videoOwner->DrawSurface(work.destination, SURFACE, work.source, KEY, 0)

void Scene6::Slot0()
{
    struct RenderWork { SurfaceRect destination, source; } work;
    if (numberBackdropPhase == 0) {
        DRAW_FIRST(menuBackgroundSurface, 0xff, (0, 0, 320, 240), (0, 0, 320, 240));
        DRAW(menuOverlaySurface, colorKey, (0, 0, 320, 40), (0, 0 - settingsSlideOffset, 320, 40));
        DRAW(menuOverlaySurface, colorKey, (0, 40, 320, 200), (0, settingsSlideOffset + 40, 320, 200));
        switch (unknown_0448) {
        case 0:
            DRAW(menuOverlaySurface, colorKey, (0, 261, 112, 14),
                 (0, settingsSlideOffset + 95, 112, 14));
            break;
        case 1:
            DRAW(menuOverlaySurface, colorKey, (0, 279, 112, 14),
                 (0, settingsSlideOffset + 113, 112, 14));
            break;
        case 2:
            DRAW(menuOverlaySurface, colorKey, (0, 297, 112, 14),
                 (0, settingsSlideOffset + 131, 112, 14));
            break;
        case 3:
            DRAW(menuOverlaySurface, colorKey, (0, 315, 112, 14),
                 (0, settingsSlideOffset + 149, 112, 14));
            break;
        case 4:
            DRAW(menuOverlaySurface, colorKey, (0, 333, 112, 14),
                 (0, settingsSlideOffset + 167, 112, 14));
            break;
        case 5:
            DRAW(menuOverlaySurface, colorKey, (0, 351, 320, 14),
                 (0, settingsSlideOffset + 185, 320, 14));
            break;
        case 6:
            DRAW(menuOverlaySurface, colorKey, (0, 369, 320, 14),
                 (0, settingsSlideOffset + 203, 320, 14));
            break;
        case 7:
            DRAW(menuOverlaySurface, colorKey, (0, 387, 320, 14),
                 (0, settingsSlideOffset + 221, 320, 14));
            break;
        }
        if (contextOwner->setting136c == 0) {
            DRAW(menuOverlaySurface, colorKey, (0x70, 0x105, 80, 14),
                 (0x70, settingsSlideOffset + 0x5f, 80, 14));
        } else if (contextOwner->setting136c == 1) {
            DRAW(menuOverlaySurface, colorKey, (0xc0, 0x105, 80, 14),
                 (0xc0, settingsSlideOffset + 0x5f, 80, 14));
        }
        if (contextOwner->setting1370 == 1) {
            DRAW(menuOverlaySurface, colorKey, (0x70, 0x117, 64, 14),
                 (0x70, settingsSlideOffset + 0x71, 64, 14));
        } else if (contextOwner->setting1370 == 2) {
            DRAW(menuOverlaySurface, colorKey, (0xb0, 0x117, 64, 14),
                 (0xb0, settingsSlideOffset + 0x71, 64, 14));
        } else if (contextOwner->setting1370 == 3) {
            DRAW(menuOverlaySurface, colorKey, (0xf0, 0x117, 64, 14),
                 (0xf0, settingsSlideOffset + 0x71, 64, 14));
        }
        if (contextOwner->setting1366 == 0) {
            DRAW(menuOverlaySurface, colorKey, (0x70, 0x129, 48, 14),
                 (0x70, settingsSlideOffset + 0x83, 48, 14));
        } else if (contextOwner->setting1366 == 1) {
            DRAW(menuOverlaySurface, colorKey, (0xa0, 0x129, 48, 14),
                 (0xa0, settingsSlideOffset + 0x83, 48, 14));
        }
        if (contextOwner->setting1365 == 1) {
            DRAW(menuOverlaySurface, colorKey, (128, 315, 24, 14),
                 (128, settingsSlideOffset + 149, 24, 14));
        }
        else if (contextOwner->setting1365 == 2) {
            DRAW(menuOverlaySurface, colorKey, (152, 315, 24, 14),
                 (152, settingsSlideOffset + 149, 24, 14));
        }
        else if (contextOwner->setting1365 == 3) {
            DRAW(menuOverlaySurface, colorKey, (176, 315, 24, 14),
                 (176, settingsSlideOffset + 149, 24, 14));
        }
        else if (contextOwner->setting1365 == 4) {
            DRAW(menuOverlaySurface, colorKey, (200, 315, 24, 14),
                 (200, settingsSlideOffset + 149, 24, 14));
        }
        if (contextOwner->setting134f == 1) {
            DRAW(menuOverlaySurface, colorKey, (128, 333, 24, 14),
                 (128, settingsSlideOffset + 167, 24, 14));
        }
        else if (contextOwner->setting134f == 2) {
            DRAW(menuOverlaySurface, colorKey, (152, 333, 24, 14),
                 (152, settingsSlideOffset + 167, 24, 14));
        }
        else if (contextOwner->setting134f == 3) {
            DRAW(menuOverlaySurface, colorKey, (176, 333, 24, 14),
                 (176, settingsSlideOffset + 167, 24, 14));
        }
    } else if (numberBackdropPhase == 1) {
        DRAW_FIRST(menuBackgroundSurface, 0xff, (0, 0, 320, 240), (0, 0, 320, 240));
        DRAW(numberSurface, numberColorKey, (0, 0, 320, 40),
             (0, 0 - settingsSlideOffset, 320, 40));
        DRAW(numberSurface, numberColorKey, (0, 40, 320, 200),
             (0, settingsSlideOffset + 40, 320, 200));
        DRAW(previewSurface, previewColorKey, (0, 0, 320, 240),
             (settingsPulseOffset + 80, settingsSlideOffset, 320, 240));
        DrawConfigNumber(160, settingsSlideOffset + 0x8f, previewStatistics.values[0]);
        DrawConfigNumber(160, settingsSlideOffset + 0xa1, previewStatistics.values[1]);
        DrawConfigNumber(160, settingsSlideOffset + 0xb3, previewStatistics.values[2]);
        DrawConfigNumber(160, settingsSlideOffset + 0xc5, previewStatistics.values[7]);
        DrawConfigNumber(160, settingsSlideOffset + 0xd7, previewStatistics.values[6]);
    } else if (numberBackdropPhase == 2) {
        DRAW(numberBackdrop, 0, (0, 0, 320, 240), (0, 0, 320, 240));
    }
    videoOwner->Present();
}
#undef DRAW
#undef DRAW_FIRST
