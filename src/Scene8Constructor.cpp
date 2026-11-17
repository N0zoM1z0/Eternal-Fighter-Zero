// Native replay browser resource constructor at 0x0076E480.
// Original DAT/BMP paths, replay controls, character-icon order, 19 sprite rectangles.
#include "Engine.h"

extern SurfaceRect __cdecl MakeSurfaceRect(int left, int top, int width, int height);
extern const char replayCtorBackgroundDat[], replayCtorOverlayDat[];
extern const char replayCtorBackgroundPaletteDat[], replayCtorOverlayPaletteDat[];
extern const char replayCtorBackgroundBmp[], replayCtorOverlayBmp[];
extern const char replayCtorBackgroundPaletteBmp[], replayCtorOverlayPaletteBmp[];

typedef char Scene8ReplayCtorSize[(sizeof(Scene8)==0x758) ? 1 : -1];

Scene8::Scene8(HWND handle, Secondary **first, Secondary **second, Context *context,
               Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    if (true) {
        contextOwner->LoadObjectFile(&replayBackgroundSurface, replayCtorBackgroundDat, 0, 1);
        contextOwner->LoadObjectFile(&replayOverlaySurface, replayCtorOverlayDat, 0, 0xc1);
        videoOwner->LoadPalette(palette, replayCtorBackgroundPaletteDat, 0, 1, 0xc0);
        videoOwner->LoadPalette(palette, replayCtorOverlayPaletteDat, 0, 0xc1, 0x3e);
    } else {
        videoOwner->LoadSurface(&replayBackgroundSurface, replayCtorBackgroundBmp, 1);
        videoOwner->LoadSurface(&replayOverlaySurface, replayCtorOverlayBmp, 0xc1);
        videoOwner->LoadBitmapPalette(palette, replayCtorBackgroundPaletteBmp, 0, 1, 0xc0);
        videoOwner->LoadBitmapPalette(palette, replayCtorOverlayPaletteBmp, 0, 0xc1, 0x3e);
    }
    colorKey = videoOwner->SurfaceProperty(replayOverlaySurface);
    replayUnusedPointerA = 0;
    replayUnusedPointerB = 0;
    phase = 1;
    flag002d = 0;
    heldDirection[0] = 0;
    heldDirection[1] = 0;
    scrollLeft = 300;
    scrollRight = 300;
    scrollTop = 180;
    scrollBottom = 180;
    replayMenuPhase = 0;
    replayColumn = 0;
    replayMenuSubchoice = 0;
    replayOverwriteChoice = 0;
    replayRow = 0;
    replayScrollX = 0.0;
    replayScrollY = 0.0;
    replayNavigationSprite[0] = 1;
    replayNavigationSprite[1] = 7;
    replayNavigationSprite[2] = 9;
    replayNavigationSprite[3] = 13;
    replayNavigationSprite[4] = 4;
    replayNavigationSprite[5] = 2;
    replayNavigationSprite[6] = 0;
    replayNavigationSprite[7] = 3;
    replayNavigationSprite[8] = 11;
    replayNavigationSprite[9] = 10;
    replayNavigationSprite[10] = 8;
    replayNavigationSprite[11] = 5;
    replayNavigationSprite[12] = 20;
    replayNavigationSprite[13] = 12;
    replayNavigationSprite[14] = 19;
    replayNavigationSprite[15] = 14;
    replayNavigationSprite[16] = 18;
    replayNavigationSprite[18] = 6;
    replayNavigationSprite[19] = 21;
    replayNavigationSprite[20] = 16;
    replayNavigationSprite[21] = 17;
    replayNavigationSprite[23] = 15;

    // Separate source rectangles are real sprite-sheet tiles, not code padding.
    replayChoiceRects[0] = MakeSurfaceRect(0, 47, 90, 24);
    replayChoiceRects[1] = MakeSurfaceRect(0, 71, 90, 24);
    replayChoiceRects[2] = MakeSurfaceRect(0, 95, 90, 24);
    replayChoiceRects[3] = MakeSurfaceRect(0, 119, 90, 24);
    replayChoiceRects[4] = MakeSurfaceRect(0, 143, 90, 24);
    replayChoiceRects[5] = MakeSurfaceRect(0, 167, 90, 24);
    replayChoiceRects[6] = MakeSurfaceRect(0, 191, 90, 24);
    replayChoiceRects[7] = MakeSurfaceRect(0, 215, 90, 24);
    replayChoiceRects[8] = MakeSurfaceRect(0, 239, 90, 24);
    replayChoiceRects[9] = MakeSurfaceRect(0, 263, 90, 24);
    replayChoiceRects[10] = MakeSurfaceRect(0, 287, 90, 24);
    replayChoiceRects[11] = MakeSurfaceRect(0, 311, 90, 24);
    replayChoiceRects[12] = MakeSurfaceRect(0, 335, 90, 24);
    replayChoiceRects[13] = MakeSurfaceRect(0, 239, 90, 24);
    replayConfirmRects[0] = MakeSurfaceRect(0, 479, 90, 24);
    replayConfirmRects[1] = MakeSurfaceRect(0, 503, 90, 24);
    replayConfirmRects[2] = MakeSurfaceRect(0, 527, 90, 24);
    replayConfirmRects[3] = MakeSurfaceRect(0, 551, 90, 24);
    replayLastRect = MakeSurfaceRect(0, 599, 90, 24);
}
