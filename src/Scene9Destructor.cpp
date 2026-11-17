// Original results/winner scene resource release at 0x00771400.
// Native vtable 0x00789874, with renderer/step/keyboard entries at
// 0x00772800 / 0x007714E0 / 0x00775750.
#include "Engine.h"

typedef char Scene9MinimumNativeLayout[(sizeof(Scene9)==0x474) ? 1 : -1];

Scene9::~Scene9()
{
    if (winnerSurface) {
        winnerSurface->Release();
        winnerSurface = 0;
    }
    if (resultSurface) {
        resultSurface->Release();
        resultSurface = 0;
    }
    if (resultOverlaySurface) {
        resultOverlaySurface->Release();
        resultOverlaySurface = 0;
    }
    if (resultBackdropSurface) {
        resultBackdropSurface->Release();
        resultBackdropSurface = 0;
    }
}
