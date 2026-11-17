// Native winner/result scene initialization at original 0x007712F0.
// Both packed .dat and fallback .bmp paths remain normal C++ source.
#include "Engine.h"

extern const char resultsWinnerDat[], resultsSummaryDat[];
extern const char resultsWinnerBmp[], resultsSummaryBmp[];

typedef char Scene9ConstructorLocalLayout[(sizeof(Scene9)==0x474) ? 1 : -1];

Scene9::Scene9(HWND handle, Secondary **first, Secondary **second, Context *context,
               Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    if (true) {
        contextOwner->LoadObjectFile(&winnerSurface, resultsWinnerDat, 0, 0xaf);
        contextOwner->LoadObjectFile(&resultSurface, resultsSummaryDat, 0, 0xaf);
    } else {
        videoOwner->LoadSurface(&winnerSurface, resultsWinnerBmp, 0xaf);
        videoOwner->LoadSurface(&resultSurface, resultsSummaryBmp, 0xaf);
    }
    resultOverlaySurface = 0;
    resultBackdropSurface = 0;
    phase = 1;
    flag002d = 0;
    resultTransitionState = 0;
}
