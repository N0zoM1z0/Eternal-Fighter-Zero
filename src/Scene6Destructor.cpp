// Complete settings/options scene native resource release, 0x0075A3B0.
// C++ preserves five independently-owned DirectDraw surface lifetimes.
#include "Engine.h"

typedef char Scene6DestructorLayoutCheck[(sizeof(Scene6) == 0x760) ? 1 : -1];

Scene6::~Scene6()
{
    if (menuBackgroundSurface) {
        menuBackgroundSurface->Release();
        menuBackgroundSurface = 0;
    }
    if (menuOverlaySurface) {
        menuOverlaySurface->Release();
        menuOverlaySurface = 0;
    }
    if (numberSurface) {
        numberSurface->Release();
        numberSurface = 0;
    }
    if (previewSurface) {
        previewSurface->Release();
        previewSurface = 0;
    }
    if (numberBackdrop) {
        numberBackdrop->Release();
        numberBackdrop = 0;
    }
}
