// Natural C++ settings scene menu, character records and score state machine.
// Native 0x0075A4C0 state owner, followed by its eight-entry C++ switch table.
#include "Engine.h"

extern unsigned char __cdecl WriteSettingsIniByte(unsigned char key, unsigned char value);
extern const char scene6StepMenuDat[], scene6StepMenuBmp[];
extern const char scene6StepScoreDat[], scene6StepScoreBmp[];
extern const char scene6StepMenuRestoreDat[], scene6StepMenuRestoreBmp[];
extern const char scene6StepBackgroundRestoreDat[], scene6StepOverlayRestoreDat[];
extern const char scene6StepBackgroundRestoreBmp[], scene6StepOverlayRestoreBmp[];

typedef char Scene6MenuLayout[(sizeof(Scene6)==0x760)?1:-1];

unsigned char Scene6::Step()
{
    PollKeyboard();
    if (phase == 1) {
        unknown_0448 = 0;
        previewSelection = 0;
        unknown_044a[0] = 0;
        phase = 0;
        numberBackdropPhase = 0;
        if (true) {
            videoOwner->LoadPalette(palette, scene6StepMenuDat, 0, 0xa1, 0x20);
        } else {
            videoOwner->LoadBitmapPalette(palette, scene6StepMenuBmp, 0, 0xa1, 0x20);
        }
        if (contextOwner->characterDataMode == 0) contextOwner->LoadMusic(6);
        else contextOwner->LoadMusic(7);
        FadeIn(palette, 1);
    }
    if (flag002d == 1) {
        FadeOut(palette, 1, 0, 100);
        contextOwner->ReleaseMusic();
        phase = 1;
        flag002d = 0;
        numberBackdropPhase = 0;
        return 0;
    }
    if (numberBackdropPhase == 0) {
        contextOwner->PollInput();
        for (int player = 0; player < 2; ++player) {
            if (contextOwner->directionY[player] != 0 && unknown_044a[1 + player] == 0) {
                unknown_0448 += contextOwner->directionY[player];
                if ((char)unknown_0448 > 7) unknown_0448 = 0;
                if ((char)unknown_0448 < 0) unknown_0448 = 7;
                contextOwner->PlayEffectSound(8);
                unknown_044a[1 + player] = 1;
            }
            if (contextOwner->directionX[player] == 0 && contextOwner->directionY[player] == 0)
                unknown_044a[1 + player] = 0;
            switch ((char)unknown_0448) {
            case 0:
                if (contextOwner->directionX[player] != 0 && unknown_044a[1 + player] == 0) {
                    contextOwner->setting136c += contextOwner->directionX[player];
                    if (contextOwner->setting136c > 1) contextOwner->setting136c = 0;
                    if (contextOwner->setting136c < 0) contextOwner->setting136c = 1;
                    WriteSettingsIniByte(0x22, contextOwner->setting136c + 1);
                    contextOwner->PlayEffectSound(8);
                    unknown_044a[1 + player] = 1;
                }
                break;
            case 1:
                if (contextOwner->directionX[player] != 0 && unknown_044a[1 + player] == 0) {
                    contextOwner->setting1370 += contextOwner->directionX[player];
                    if ((char)contextOwner->setting1370 > 3) contextOwner->setting1370 = 1;
                    if ((char)contextOwner->setting1370 < 1) contextOwner->setting1370 = 3;
                    WriteSettingsIniByte(0x24, contextOwner->setting1370);
                    contextOwner->PlayEffectSound(8);
                    unknown_044a[1 + player] = 1;
                }
                break;
            case 2:
                if (contextOwner->directionX[player] != 0 && unknown_044a[1 + player] == 0) {
                    contextOwner->setting1366 += contextOwner->directionX[player];
                    if (contextOwner->setting1366 > 1) contextOwner->setting1366 = 0;
                    if (contextOwner->setting1366 < 0) contextOwner->setting1366 = 1;
                    WriteSettingsIniByte(0x23, contextOwner->setting1366 + 1);
                    contextOwner->PlayEffectSound(8);
                    unknown_044a[1 + player] = 1;
                }
                break;
            case 3:
                if (contextOwner->directionX[player] != 0 && unknown_044a[1 + player] == 0) {
                    contextOwner->setting1365 += contextOwner->directionX[player];
                    if ((char)contextOwner->setting1365 > 4) contextOwner->setting1365 = 1;
                    if ((char)contextOwner->setting1365 < 1) contextOwner->setting1365 = 4;
                    WriteSettingsIniByte(0x21, contextOwner->setting1365);
                    contextOwner->PlayEffectSound(8);
                    unknown_044a[1 + player] = 1;
                }
                break;
            case 4:
                if (contextOwner->directionX[player] != 0 && unknown_044a[1 + player] == 0) {
                    contextOwner->setting134f += contextOwner->directionX[player];
                    if ((char)contextOwner->setting134f > 3) contextOwner->setting134f = 1;
                    if ((char)contextOwner->setting134f < 1) contextOwner->setting134f = 3;
                    WriteSettingsIniByte(0x26, contextOwner->setting134f);
                    contextOwner->PlayEffectSound(8);
                    unknown_044a[1 + player] = 1;
                }
                break;
            case 5:
                if (contextOwner->buttonA[player] == 1) {
                    contextOwner->PlayEffectSound(6);
                    TransitionNumberBackdrop();
                }
                break;
            case 6:
                if (contextOwner->buttonA[player] == 1) {
                    contextOwner->PlayEffectSound(6);
                    AnimateSettingsSlide(0);
                    if (true) {
                        videoOwner->LoadPalette(palette, scene6StepScoreDat, 0, 0xa1, 0x20);
                    } else {
                        videoOwner->LoadBitmapPalette(palette, scene6StepScoreBmp, 0, 0xa1, 0x20);
                    }
                    numberBackdropPhase = 1;
                    ReloadSelectedPreview();
                    videoOwner->ApplyPalette(palette);
                    AnimateSettingsSlide(1);
                }
                break;
            case 7:
                if (contextOwner->buttonA[player] == 1) flag002d = 1;
                break;
            }
            if (contextOwner->buttonB[player] == 1) flag002d = 1;
        }
    } else if (numberBackdropPhase == 1) {
        contextOwner->PollInput();
        for (int player = 0; player < 2; ++player) {
            if (contextOwner->directionX[player] != 0 && unknown_044a[1 + player] == 0) {
                contextOwner->PlayEffectSound(8);
                previewSelection += contextOwner->directionX[player];
                if (contextOwner->characterDataMode == 0) {
                    if (previewSelection == 12) previewSelection = 15;
                    if (previewSelection == 14) previewSelection = 11;
                }
                if (contextOwner->characterDataMode == -1) {
                    if (previewSelection == 16) previewSelection = 20;
                    if (previewSelection == 19) previewSelection = 15;
                    if (previewSelection == 22) {
                        if (contextOwner->directionX[player] > 0) previewSelection = 0;
                        else previewSelection = 20;
                    }
                }
                if (previewSelection > 22) previewSelection = 0;
                if (previewSelection < 0) previewSelection = 22;
                AnimateSettingsPreview();
                unknown_044a[1 + player] = 1;
            }
            if (contextOwner->directionX[player] == 0 && contextOwner->directionY[player] == 0)
                unknown_044a[1 + player] = 0;
            if (contextOwner->buttonA[player] != 0 || contextOwner->buttonB[player] != 0) {
                if (contextOwner->buttonA[player] != 0) contextOwner->PlayEffectSound(6);
                AnimateSettingsSlide(0);
                if (true) {
                    videoOwner->LoadPalette(palette, scene6StepMenuRestoreDat, 0, 0xa1, 0x20);
                } else {
                    videoOwner->LoadBitmapPalette(palette, scene6StepMenuRestoreBmp, 0, 0xa1, 0x20);
                }
                videoOwner->ApplyPalette(palette);
                numberBackdropPhase = 0;
                AnimateSettingsSlide(1);
            }
        }
    } else if (numberBackdropPhase == 2) {
        contextOwner->PollInput();
        for (int player = 0; player < 2; ++player) {
            if (contextOwner->directionX[player] != 0 || contextOwner->directionY[player] != 0) {
                contextOwner->PlayEffectSound(8);
                numberBackdropIndex += contextOwner->directionX[player] + contextOwner->directionY[player] * 10;
                if (numberBackdropIndex > 174) numberBackdropIndex = 0;
                if (numberBackdropIndex < 0) numberBackdropIndex = 174;
                TransitionNumberBackdrop();
            }
            if (contextOwner->buttonA[player] != 0 || contextOwner->buttonB[player] != 0) {
                if (contextOwner->buttonA[player] != 0) contextOwner->PlayEffectSound(6);
                FadeConfigPalette(1);
                if (true) {
                    videoOwner->LoadPalette(palette, scene6StepBackgroundRestoreDat, 0, 1, 0xa0);
                    videoOwner->LoadPalette(palette, scene6StepOverlayRestoreDat, 0, 0xa1, 0x20);
                } else {
                    videoOwner->LoadBitmapPalette(palette, scene6StepBackgroundRestoreBmp, 0, 1, 0xa0);
                    videoOwner->LoadBitmapPalette(palette, scene6StepOverlayRestoreBmp, 0, 0xa1, 0x20);
                }
                numberBackdropPhase = 0;
                FadeConfigPaletteIn(0);
            }
        }
    }
    Slot0();
    return 6;
}
