// Native settings resource, menu state and 23 name-table constructor at 0x00759F30.
#include "Engine.h"
#include <cstring>
typedef char Scene6ConstructLayout[(sizeof(Scene6)==0x760) ? 1 : -1];
extern const char scene6CtorconfigBackgroundDat[];
extern const char scene6CtorconfigOverlayDat[];
extern const char scene6CtorconfigScoreDat[];
extern const char scene6CtorconfigBackgroundPaletteDat[];
extern const char scene6CtorconfigOverlayPaletteDat[];
extern const char scene6CtorconfigBackgroundBmp[];
extern const char scene6CtorconfigOverlayBmp[];
extern const char scene6CtorconfigScoreBmp[];
extern const char scene6CtorconfigBackgroundPaletteBmp[];
extern const char scene6CtorconfigOverlayPaletteBmp[];
extern const char scene6CtorName00[];
extern const char scene6CtorName01[];
extern const char scene6CtorName02[];
extern const char scene6CtorName03[];
extern const char scene6CtorName04[];
extern const char scene6CtorName05[];
extern const char scene6CtorName06[];
extern const char scene6CtorName07[];
extern const char scene6CtorName08[];
extern const char scene6CtorName09[];
extern const char scene6CtorName10[];
extern const char scene6CtorName11[];
extern const char scene6CtorName12[];
extern const char scene6CtorName13[];
extern const char scene6CtorName14[];
extern const char scene6CtorName15[];
extern const char scene6CtorName16[];
extern const char scene6CtorName17[];
extern const char scene6CtorName18[];
extern const char scene6CtorName19[];
extern const char scene6CtorName20[];
extern const char scene6CtorName21[];
extern const char scene6CtorName22[];

Scene6::Scene6(HWND handle, Secondary **first, Secondary **second, Context *context,
               Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    previewSurface = 0;
    numberBackdrop = 0;
    if (true) {
        contextOwner->LoadObjectFile(&menuBackgroundSurface, scene6CtorconfigBackgroundDat, 0, 1);
        contextOwner->LoadObjectFile(&menuOverlaySurface, scene6CtorconfigOverlayDat, 0, 0xa1);
        contextOwner->LoadObjectFile(&numberSurface, scene6CtorconfigScoreDat, 0, 0xa1);
        videoOwner->LoadPalette(palette, scene6CtorconfigBackgroundPaletteDat, 0, 1, 0xa1);
        videoOwner->LoadPalette(palette, scene6CtorconfigOverlayPaletteDat, 0, 0xa2, 0x20);
    } else {
        videoOwner->LoadSurface(&menuBackgroundSurface, scene6CtorconfigBackgroundBmp, 1);
        videoOwner->LoadSurface(&menuOverlaySurface, scene6CtorconfigOverlayBmp, 0xa1);
        videoOwner->LoadSurface(&numberSurface, scene6CtorconfigScoreBmp, 0xa1);
        videoOwner->LoadBitmapPalette(palette, scene6CtorconfigBackgroundPaletteBmp, 0, 1, 0xa1);
        videoOwner->LoadBitmapPalette(palette, scene6CtorconfigOverlayPaletteBmp, 0, 0xa1, 0x20);
    }
    colorKey = videoOwner->SurfaceProperty(menuOverlaySurface);
    numberColorKey = videoOwner->SurfaceProperty(numberSurface);
    unknown_0448 = 0;
    previewSelection = 0;
    unknown_044a[0] = 0;
    unknown_044a[1] = 0;
    unknown_044a[2] = 0;
    numberBackdropPhase = 0;
    phase = 1;
    flag002d = 0;
    settingsAnimationTime = 0.0;
    settingsPulseOffset = 0;
    settingsSlideOffset = 0;
    numberBackdropIndex = 0;
    std::strcpy(previewNames[0], scene6CtorName00);
    std::strcpy(previewNames[1], scene6CtorName01);
    std::strcpy(previewNames[2], scene6CtorName02);
    std::strcpy(previewNames[3], scene6CtorName03);
    std::strcpy(previewNames[4], scene6CtorName04);
    std::strcpy(previewNames[5], scene6CtorName05);
    std::strcpy(previewNames[6], scene6CtorName06);
    std::strcpy(previewNames[7], scene6CtorName07);
    std::strcpy(previewNames[8], scene6CtorName08);
    std::strcpy(previewNames[9], scene6CtorName09);
    std::strcpy(previewNames[10], scene6CtorName10);
    std::strcpy(previewNames[11], scene6CtorName11);
    std::strcpy(previewNames[12], scene6CtorName12);
    std::strcpy(previewNames[13], scene6CtorName13);
    std::strcpy(previewNames[14], scene6CtorName14);
    std::strcpy(previewNames[15], scene6CtorName15);
    std::strcpy(previewNames[16], scene6CtorName16);
    std::strcpy(previewNames[17], scene6CtorName17);
    std::strcpy(previewNames[18], scene6CtorName18);
    std::strcpy(previewNames[19], scene6CtorName19);
    std::strcpy(previewNames[20], scene6CtorName20);
    std::strcpy(previewNames[21], scene6CtorName21);
    std::strcpy(previewNames[22], scene6CtorName22);
}
