// Character selection scene; provisional fields follow reviewed target accesses.
#include "Engine.h"
extern const char selectBackgroundDat[], selectObjectsDat[], selectStagesDat[], selectPaletteDat[];
extern const char selectBackgroundBmp[], selectObjectsBmp[], selectStagesBmp[], selectPaletteBmp[];

Scene1::Scene1(HWND handle, Secondary **first, Secondary **second, Context *context, Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    if (true) {
        contextOwner->LoadObjectFile(&backgroundSurface, selectBackgroundDat, 0, 1);
        contextOwner->LoadObjectFile(&objectSurface, selectObjectsDat, 0, 1);
        contextOwner->LoadObjectFile(&stageSurface, selectStagesDat, 0, 0xaf);
        videoOwner->LoadPalette(palette, selectPaletteDat, 0, 1, 0xae);
    } else {
        videoOwner->LoadSurface(&backgroundSurface, selectBackgroundBmp, 1);
        videoOwner->LoadSurface(&objectSurface, selectObjectsBmp, 1);
        videoOwner->LoadSurface(&stageSurface, selectStagesBmp, 0xaf);
        videoOwner->LoadBitmapPalette(palette, selectPaletteBmp, 0, 1, 0xae);
    }
    colorKey = videoOwner->SurfaceProperty(objectSurface);
    stageColorKey = videoOwner->SurfaceProperty(stageSurface);
    playerSurfaces[0] = 0;
    playerSurfaces[1] = 0;
    portraitSurface = 0;
    phase = 1;
    flag002d = 0;
    field049c[0] = 0;
    field049c[1] = 0;
    field0450 = 0.0;
    field0478 = 60;
    field0458 = 50.0;
    playerDelta[0] = 0;
    field0460 = 50.0;
    playerDelta[1] = 0;
    field0468 = 0.0;
    field0484 = 0;
    field0470 = -240.0;
    field0488 = 60;
    field048c = 0;
    field0490 = 0;
    field0498[0] = 300;
    field0498[1] = 300;
    field0494[0] = 180;
    field0494[1] = 180;
    field049e[0] = 5;
    field049e[1] = 5;
    field053c[0] = 2;
    field053c[1] = 9;
    field053e[0] = 0;
    field053e[1] = 0;
    field0540[0] = 0;
    field0540[1] = 0;
    field0538[0] = 0;
    field053a[0] = 0;
    field0538[1] = 2;
    field053a[1] = 0;
    gridCharacters[0] = 6;
    gridCharacters[1] = 0;
    gridCharacters[2] = 4;
    gridCharacters[3] = 7;
    gridCharacters[4] = 5;
    gridCharacters[5] = 11;
    gridCharacters[6] = 1;
    gridCharacters[7] = 10;
    gridCharacters[8] = 3;
    gridCharacters[9] = 8;
    gridCharacters[10] = 2;
    gridCharacters[11] = 9;
    gridCharacters[12] = 23;
    gridCharacters[13] = 20;
    gridCharacters[14] = 21;
    gridCharacters[15] = 14;
    gridCharacters[16] = 12;
    gridCharacters[17] = 18;
    gridCharacters[18] = 17;
    gridCharacters[19] = 15;
    gridCharacters[20] = 13;
    gridCharacters[21] = 16;
    gridCharacters[22] = -1;
    gridCharacters[23] = 19;
    portraitOffsets[0] = -40;
    portraitOffsets[1] = -10;
    portraitOffsets[2] = -5;
    portraitOffsets[3] = 0;
    portraitOffsets[4] = -5;
    portraitOffsets[5] = -5;
    portraitOffsets[6] = -30;
    portraitOffsets[7] = -30;
    portraitOffsets[8] = -20;
    portraitOffsets[9] = -10;
    portraitOffsets[10] = -40;
    portraitOffsets[11] = -5;
    portraitOffsets[12] = -50;
    portraitOffsets[13] = 0;
    portraitOffsets[14] = -15;
    portraitOffsets[15] = -15;
    portraitOffsets[16] = -20;
    portraitOffsets[17] = -20;
    portraitOffsets[18] = -45;
    portraitOffsets[19] = 10;
    portraitOffsets[20] = -20;
    portraitOffsets[21] = 0;
    portraitOffsets[22] = 0;
    portraitOffsets[23] = -20;
    characterOrder[0] = 5;
    characterOrder[1] = 7;
    characterOrder[2] = 11;
    characterOrder[3] = 9;
    characterOrder[4] = 0;
    characterOrder[5] = 4;
    characterOrder[6] = 2;
    characterOrder[7] = 1;
    characterOrder[8] = 10;
    characterOrder[9] = 12;
    characterOrder[10] = 8;
    characterOrder[11] = 3;
    characterOrder[12] = 21;
    characterOrder[13] = 13;
    characterOrder[14] = 20;
    characterOrder[15] = 14;
    characterOrder[16] = 15;
    characterOrder[17] = 8;
    characterOrder[18] = 6;
    characterOrder[19] = 19;
    characterOrder[20] = 17;
    characterOrder[21] = 18;
    characterOrder[22] = -1;
    characterOrder[23] = 16;
    characterOrder[24] = 6;
}

Scene1::~Scene1()
{
    if (backgroundSurface) { backgroundSurface->Release(); backgroundSurface = 0; }
    if (objectSurface) { objectSurface->Release(); objectSurface = 0; }
    if (stageSurface) { stageSurface->Release(); stageSurface = 0; }
    if (portraitSurface) { portraitSurface->Release(); portraitSurface = 0; }
    if (playerSurfaces[0]) { playerSurfaces[0]->Release(); playerSurfaces[0] = 0; }
    if (playerSurfaces[1]) { playerSurfaces[1]->Release(); playerSurfaces[1] = 0; }
}

#include <cmath>
#include <cstdlib>
#include <cstring>
extern const char selectStagePrefixZero[], selectStagePrefix[], selectDatExtension[], selectStagePaletteDat[];
extern const char selectBmpExtension[], selectStagePaletteBmp[];

unsigned char Scene1::Step()
{
    int i;
    if (phase > 0) Enter();
    if (flag002d > 0) {
        FadeOut(palette, 0, 0, 100);
        phase = 1;
        contextOwner->flag0f32 = 0;
        flag002d = 0;
        contextOwner->ReleaseMusic();
        if (contextOwner->mode1364 == 5) return 8;
        return 0;
    }
    PollKeyboard();
    contextOwner->PollInput();
    for (i = 0; i < 2; ++i) {
        if (contextOwner->mode1364 == 0 && contextOwner->cpuPlayer[i] == 1) {
            contextOwner->directionX[i] = 0;
            contextOwner->directionY[i] = 0;
            contextOwner->buttonA[i] = 0;
            contextOwner->buttonB[i] = 0;
            contextOwner->buttonC[i] = 0;
            contextOwner->buttonD[i] = 0;
        }
        if (contextOwner->cpuPlayer[i] == 1 &&
            (contextOwner->mode1364 == 1 || contextOwner->mode1364 == 3 || contextOwner->mode1364 == 5)) {
            if (field049e[i] < 4 && field049e[1 - i] == 6) {
                contextOwner->directionX[i] = contextOwner->directionX[1 - i];
                contextOwner->directionY[i] = contextOwner->directionY[1 - i];
                contextOwner->buttonA[i] = contextOwner->buttonA[1 - i];
                contextOwner->buttonC[i] = contextOwner->buttonC[1 - i];
                contextOwner->buttonD[i] = contextOwner->buttonD[1 - i];
                contextOwner->directionX[1 - i] = 0;
                contextOwner->directionY[1 - i] = 0;
                contextOwner->buttonA[1 - i] = 0;
                contextOwner->buttonC[1 - i] = 0;
                contextOwner->buttonD[1 - i] = 0;
            }
            contextOwner->buttonB[i] = contextOwner->buttonB[1 - i];
        }
    }
    for (i = 0; i < 2; ++i) {
        switch (field049e[i]) {
        case 0:
            contextOwner->alternateStyle[i] = 0;
            playerDelta[i] = 2;
            if ((contextOwner->buttonC[i] != 0 && field0540[i] == 0) ||
                (contextOwner->buttonA[i] != 0 && field0538[i] == 1 && field053a[i] == 7))
                field0540[i] = 60;
            if (field0540[i] > 0) {
                --field0540[i];
                contextOwner->directionX[i] = std::rand() % 3 - 1;
                contextOwner->directionY[i] = std::rand() % 2;
                contextOwner->buttonA[i] = 0;
                field049c[i] = 0;
                if (field0540[i] == 0) {
                    field053c[i] = gridCharacters[field0538[i] + field053a[i] * 3];
                    if (field053c[i] < 0) ++field0540[i];
                    if (contextOwner->characterDataMode == 0 &&
                        (field053c[i] == 19 || field053c[i] == 20 || field053c[i] == 21 || field053c[i] == 23)) ++field0540[i];
                    if (contextOwner->characterDataMode == -1 &&
                        (field053c[i] == 12 || field053c[i] == 13 || field053c[i] == 14 || field053c[i] == 15)) ++field0540[i];
                }
                if (field0540[i] == 0) {
                    contextOwner->directionX[i] = 0;
                    contextOwner->directionY[i] = 0;
                    contextOwner->buttonA[i] = 1;
                }
            }
            if (field049c[i] == 0) {
                if (contextOwner->directionY[i] < 0) {
                    field053a[i] = (field053a[i] + 7) % 8;
                    contextOwner->PlayEffectSound(8);
                    field049c[i] = 1;
                } else if (contextOwner->directionY[i] > 0) {
                    field053a[i] = (field053a[i] + 1) % 8;
                    contextOwner->PlayEffectSound(8);
                    field0494[i] = 40;
                    field049c[i] = 1;
                } else if (contextOwner->directionX[i] < 0) {
                    field0538[i] = (field0538[i] + 2) % 3;
                    contextOwner->PlayEffectSound(8);
                    field0494[i] = 40;
                    field049c[i] = 1;
                } else if (contextOwner->directionX[i] > 0) {
                    field0538[i] = (field0538[i] + 1) % 3;
                    contextOwner->PlayEffectSound(8);
                    field0494[i] = 40;
                    field049c[i] = 1;
                }
                field053c[i] = gridCharacters[field0538[i] + field053a[i] * 3];
            } else if (contextOwner->directionX[i] == 0 && contextOwner->directionY[i] == 0) field049c[i] = 0;
            if (contextOwner->characterDataMode == 0 &&
                (field053c[i] == 19 || field053c[i] == 20 || field053c[i] == 21 || field053c[i] == 23)) contextOwner->buttonA[i] = 0;
            if (contextOwner->characterDataMode == -1 &&
                (field053c[i] == 12 || field053c[i] == 13 || field053c[i] == 14 || field053c[i] == 15)) contextOwner->buttonA[i] = 0;
            if (contextOwner->buttonA[i] != 0 && contextOwner->directionY[i] == 0 && contextOwner->directionX[i] == 0) {
                if (field049e[1 - i] < 7 && field049e[1 - i] > 0 && field053e[0] == field053e[1] && field053c[0] == field053c[1]) {
                    ++field053e[i];
                    if (field053e[i] >= 6) field053e[i] = 0;
                }
                contextOwner->PlayEffectSound(6);
                if (i == 0) LoadCharacter(secondarySlotA, secondarySlotB, 0);
                else LoadCharacter(secondarySlotB, secondarySlotA, 1);
                field049e[i] = 1;
                field0494[i] = 90;
            }
            break;
        case 1:
            playerDelta[i] = -2;
            field0498[i] = (std::cos(field0494[i] / (180.0 / 3.141592)) + 1.0) * 300.0;
            field0494[i] += 5;
            if (field0494[i] > 180) {
                field049e[i] = 3;
                contextOwner->PlayEffectSound(field053c[i] + 40);
            }
            if (contextOwner->buttonB[i] != 0) {
                field049e[i] = 2;
                field0540[i] = 0;
            }
            break;
        case 2:
            if (field0494[i] >= 90) {
                field0498[i] = (std::cos(field0494[i] / (180.0 / 3.141592)) + 1.0) * 300.0;
                field0494[i] -= 5;
            } else field049e[i] = 0;
            break;
        case 3:
            contextOwner->alternateStyle[i] = contextOwner->directionY[i] > 0;
            if (field049c[i] == 0 && contextOwner->directionX[i] != 0) {
                contextOwner->PlayEffectSound(8);
                field053e[i] += contextOwner->directionX[i];
                if (field053e[i] >= 6) field053e[i] = 0;
                else if (field053e[i] < 0) field053e[i] = 5;
                if (field049e[1 - i] > 0 && field053e[0] == field053e[1] && field053c[0] == field053c[1]) {
                    field053e[i] += contextOwner->directionX[i];
                    if (field053e[i] >= 6) field053e[i] = 0;
                    else if (field053e[i] < 0) field053e[i] = 5;
                }
                LoadPlayerPalette(i);
            }
            if (contextOwner->buttonA[i] != 0 || contextOwner->buttonD[i] != 0) {
                if (contextOwner->buttonD[i] != 0) contextOwner->alternateStyle[i] = 1;
                secondary[i]->paletteIndex = field053e[i];
                contextOwner->PlayEffectSound(6);
                field049e[i] = 6;
                if (contextOwner->mode1364 == 0 || contextOwner->mode1364 == 2) {
                    FadeOut(palette, 0, 0, 50);
                    phase = 2;
                    contextOwner->flag1358 = 1;
                    contextOwner->field135c = 0;
                    contextOwner->field1360 = 0;
                    return 2;
                }
            }
            if (contextOwner->buttonB[i] != 0) field049e[i] = 2;
            break;
        case 4:
            if (field049e[1 - i] == 4) {
                if (field0540[0] > 0) {
                    --field0540[0];
                    if (field0540[0] == 0) {
                        if (contextOwner->characterDataMode == 0 && contextOwner->flag0f32 >= 13 && contextOwner->flag0f32 <= 16)
                            field0540[0] = std::rand() % 23 + 1;
                        if (contextOwner->characterDataMode == -1 && contextOwner->flag0f32 >= 18 && contextOwner->flag0f32 <= 22)
                            field0540[0] = std::rand() % 23 + 1;
                    }
                    if (field0540[0] == 0) {
                        contextOwner->PlayEffectSound(6);
                        LoadStage();
                        FadeOut(palette, 0, 0, 50);
                        phase = 2;
                        contextOwner->flag1358 = 1;
                        contextOwner->field135c = 0;
                        contextOwner->field1360 = 0;
                        return 2;
                    }
                    ++contextOwner->flag0f32;
                    if (contextOwner->flag0f32 >= 23) contextOwner->flag0f32 = 0;
                } else {
                    if (contextOwner->directionY[i] > 0 || contextOwner->directionX[i] > 0) {
                        contextOwner->PlayEffectSound(8);
                        field049e[0] = 10;
                        field049e[1] = 10;
                    } else if (contextOwner->directionX[i] < 0 || contextOwner->directionY[i] < 0) {
                        contextOwner->PlayEffectSound(8);
                        field049e[0] = 9;
                        field049e[1] = 9;
                    }
                    if (contextOwner->characterDataMode == 0 && contextOwner->flag0f32 >= 13 && contextOwner->flag0f32 <= 16) contextOwner->buttonA[i] = 0;
                    if (contextOwner->characterDataMode == -1 && contextOwner->flag0f32 >= 18 && contextOwner->flag0f32 <= 22) contextOwner->buttonA[i] = 0;
                    if (contextOwner->buttonA[i] != 0) {
                        contextOwner->PlayEffectSound(6);
                        FadeOut(palette, 0, 0, 50);
                        phase = 2;
                        contextOwner->flag1358 = 1;
                        contextOwner->field135c = 0;
                        contextOwner->field1360 = 0;
                        return 2;
                    }
                }
                if (contextOwner->buttonC[i] != 0 && field0540[0] == 0 && true) field0540[0] = std::rand() % 23 + 60;
            }
            if (contextOwner->buttonB[i] != 0) {
                field049e[i] = 8;
                field049e[1 - i] = 8;
                field0540[0] = 0;
                field0540[1] = 0;
            }
            break;
        }
        if ((field049e[0] == 0 && contextOwner->buttonB[0] != 0 && contextOwner->cpuPlayer[0] == 0) ||
            (field049e[1] == 0 && contextOwner->buttonB[1] != 0 && contextOwner->cpuPlayer[1] == 0)) flag002d = 1;
        field049c[i] = contextOwner->directionX[i] != 0 || contextOwner->directionY[i] != 0;
    }
    if (field049e[0] == 6 && field049e[1] == 6) {
        if (field0494[0] >= 90) {
            field0498[0] = (std::cos(field0494[0] / (180.0 / 3.141592)) + 1.0) * 300.0;
            field0498[1] = (std::cos(field0494[1] / (180.0 / 3.141592)) + 1.0) * 300.0;
            field0494[0] -= 5;
            field0494[1] -= 5;
        } else if (field0488 < 60) {
            field0470 = (int)(((std::cos(field0488 / (180.0 / 3.141592)) - 0.5) * 2.0 - 1.0) * 240.0);
            field0488 += 3;
        } else {
            char path[40];
            {
                char digits[8];
                field049e[0] = 7;
                field049e[1] = 7;
                if (contextOwner->flag0f32 < 10) std::strcpy(path, selectStagePrefixZero);
                else std::strcpy(path, selectStagePrefix);
                _itoa(contextOwner->flag0f32, digits, 10);
                std::strcat(path, digits);
                if (true) {
                    std::strcat(path, selectDatExtension);
                    contextOwner->LoadObjectFile(&portraitSurface, path, 0, 0xbf);
                    videoOwner->LoadPalette(palette, selectStagePaletteDat, 0, 0xaf, 0x10);
                    videoOwner->LoadPalette(palette, path, 0, 0xbf, 0x40);
                } else {
                    std::strcat(path, selectBmpExtension);
                    videoOwner->LoadSurface(&portraitSurface, path, 0xbf);
                    videoOwner->LoadBitmapPalette(palette, selectStagePaletteBmp, 0, 0xaf, 0x50);
                    videoOwner->LoadBitmapPalette(palette, path, 0, 0xbf, 0x40);
                }
                portraitColorKey = videoOwner->SurfaceProperty(portraitSurface);
                videoOwner->ApplyPaletteRange(palette, 0xaf, 0x50);
            }
        }
    } else if (field049e[0] == 6) {
        if (contextOwner->buttonB[0] != 0) field049e[0] = 2;
    } else if (field049e[1] == 6) {
        if (contextOwner->buttonB[1] != 0) field049e[1] = 2;
    } else if (field049e[0] == 7) {
        if (field048c < 85) field048c += 5;
        else {
            field048c = 90;
            field049e[0] = 4;
            field049e[1] = 4;
        }
    } else if (field049e[0] == 8 || field049e[1] == 8) {
        if (field048c > 0) field048c -= 4;
        else if (field0488 > 0) {
            field0470 = (int)(((std::cos(field0488 / (180.0 / 3.141592)) - 0.5) * 2.0 - 1.0) * 240.0);
            field0488 -= 3;
        } else {
            field049e[0] = 0;
            field049e[1] = 0;
        }
    }
    if (field049e[0] == 5 || field049e[1] == 5) {
        if (field0478 > 0) {
            field0450 = (int)(std::cos(field0478 * 1.5 / (180.0 / 3.141592)) * 240.0);
            --field0478;
        }
        if (field0488 > 0) {
            field0470 = (int)(((std::cos(field0488 / (180.0 / 3.141592)) - 0.5) * 2.0 - 1.0) * 240.0);
            --field0488;
            if (field0488 == 0) {
                field049e[0] = 0;
                field049e[1] = 0;
            }
        }
    }
    field0458 -= playerDelta[0];
    if (field0458 < 0.0) field0458 = 0.0;
    if (field0458 > 50.0) field0458 = 50.0;
    field0460 -= playerDelta[1];
    if (field0460 < 0.0) field0460 = 0.0;
    if (field0460 > 50.0) field0460 = 50.0;
    field0468 += 1.0;
    if (field0468 >= 240.0) field0468 -= 240.0;
    Slot0();
    if (field049e[0] == 9) {
        if (field0490 < 90) field0490 += 10;
        else {
            field0490 = 0;
            field049e[0] = 4;
            field049e[1] = 4;
            ++contextOwner->flag0f32;
            if (contextOwner->characterDataMode == 0 && contextOwner->flag0f32 == 13) contextOwner->flag0f32 = 17;
            if (contextOwner->characterDataMode == -1 && contextOwner->flag0f32 == 18) contextOwner->flag0f32 = 0;
            if (contextOwner->flag0f32 >= 23) contextOwner->flag0f32 = 0;
            LoadStage();
        }
    } else if (field049e[0] == 10) {
        if (field0490 < 90) field0490 += 10;
        else {
            field0490 = 0;
            field049e[0] = 4;
            field049e[1] = 4;
            --contextOwner->flag0f32;
            if (contextOwner->flag0f32 < 0) contextOwner->flag0f32 = 22;
            if (contextOwner->characterDataMode == 0 && contextOwner->flag0f32 == 16) contextOwner->flag0f32 = 12;
            if (contextOwner->characterDataMode == -1 && contextOwner->flag0f32 == 22) contextOwner->flag0f32 = 17;
            LoadStage();
        }
    }
    return 1;
}


extern const char selectReloadStagePrefixZero[], selectReloadStagePrefix[];
extern const char selectReloadDatExtension[], selectReloadBmpExtension[];
extern const char selectPlayerPrefixDat[], selectPlayerSeparatorDat[], selectPlayerExtensionDat[];
extern const char selectPlayerPrefixBmp[], selectPlayerSeparatorBmp[], selectPlayerExtensionBmp[];
extern const char selectEnterPaletteDat[], selectEnterPaletteBmp[];
extern "C" unsigned char __cdecl ReadConfigByte(unsigned char);

void Scene1::LoadStage()
{
    char path[40];
    {
        char digits[8];
        if (contextOwner->flag0f32 < 10) std::strcpy(path, selectReloadStagePrefixZero);
        else std::strcpy(path, selectReloadStagePrefix);
        _itoa(contextOwner->flag0f32, digits, 10);
        std::strcat(path, digits);
        if (true) {
            std::strcat(path, selectReloadDatExtension);
            contextOwner->LoadObjectFile(&portraitSurface, path, 0, 0xbf);
            videoOwner->LoadPalette(palette, path, 0, 0xbf, 0x40);
        } else {
            std::strcat(path, selectReloadBmpExtension);
            videoOwner->LoadSurface(&portraitSurface, path, 0xbf);
            videoOwner->LoadBitmapPalette(palette, path, 0, 0xbf, 0x40);
        }
        portraitColorKey = videoOwner->SurfaceProperty(portraitSurface);
        videoOwner->ApplyPaletteRange(palette, 0xaf, 0x50);
    }
}

void Scene1::LoadPlayerPalette(char player)
{
    char path[40];
    if (true) {
        std::strcpy(path, selectPlayerPrefixDat);
        std::strcat(path, secondary[player]->resourceName);
        std::strcat(path, selectPlayerSeparatorDat);
        std::strcat(path, secondary[player]->resourceName);
        std::strcat(path, selectPlayerExtensionDat);
        videoOwner->LoadPalette(palette, path, field053e[player] * 40, player * 40 + 0xaf, 40);
    } else {
        std::strcpy(path, selectPlayerPrefixBmp);
        std::strcat(path, secondary[player]->resourceName);
        std::strcat(path, selectPlayerSeparatorBmp);
        std::strcat(path, secondary[player]->resourceName);
        std::strcat(path, selectPlayerExtensionBmp);
        videoOwner->LoadBitmapPalette(palette, path, field053e[player] * 40, player * 40 + 0xaf, 40);
    }
    videoOwner->ApplyPaletteRange(palette, player * 40 + 0xaf, 40);
}

void Scene1::PollKeyboard()
{
    char state[256];
    {
        HRESULT result;
        result = inputOwner->keyboard->GetDeviceState(256, state);
        if (result < 0) { if (result == DIERR_INPUTLOST) inputOwner->keyboard->Acquire(); }
        if (state[1] & 0x80) flag002d = 1;
        if (state[0x3b] & 0x80) inputOwner->Defaults();
        if (state[0x3c] & 0x80) { if (ReadConfigByte(0x98) > 0) inputOwner->Configure(1); }
        if (state[0x3d] & 0x80) { if (ReadConfigByte(0x98) > 0) inputOwner->Configure(2); }
        if (state[0x3e] & 0x80) { if (ReadConfigByte(0x98) > 0) inputOwner->Configure(3); }
    }
}

void Scene1::Enter()
{
    field049c[0] = 0;
    field049c[1] = 0;
    field0450 = 0.0;
    field0478 = 60;
    field0458 = 50.0;
    playerDelta[0] = 0;
    field0460 = 50.0;
    playerDelta[1] = 0;
    field0468 = 0.0;
    field0484 = 0;
    field0470 = -480.0;
    field0488 = 60;
    field048c = 0;
    field0490 = 0;
    field0498[0] = 300;
    field0498[1] = 300;
    field0494[0] = 180;
    field0494[1] = 180;
    field049e[0] = 5;
    field049e[1] = 5;
    field0540[0] = 0;
    field0540[1] = 0;
    field053e[0] = 0;
    field053e[1] = 0;
    contextOwner->playerFlag1378[0] = 0;
    contextOwner->playerFlag1378[1] = 0;
    contextOwner->alternateStyle[0] = 0;
    contextOwner->alternateStyle[1] = 0;
    if (contextOwner->mode1364 < 5) {
        if (true) videoOwner->LoadPalette(palette, selectEnterPaletteDat, 0, 1, 0x30);
        else videoOwner->LoadBitmapPalette(palette, selectEnterPaletteBmp, 0, 1, 0x30);
        if (contextOwner->mode1364 == 0 || contextOwner->mode1364 == 2) {
            if (contextOwner->cpuPlayer[0] == 1) {
                field049e[0] = 4;
                field053e[0] = -1;
            } else {
                field049e[1] = 4;
                field053e[1] = -1;
            }
        }
        contextOwner->flag14283 = 0;
    }
    std::memset(stageUnavailable, 0, 23);
    if (contextOwner->characterDataMode == 0) {
        stageUnavailable[13] = 1;
        stageUnavailable[14] = 1;
        stageUnavailable[15] = 1;
        stageUnavailable[16] = 1;
    } else if (contextOwner->characterDataMode == -1) {
        stageUnavailable[18] = 1;
        stageUnavailable[19] = 1;
        stageUnavailable[20] = 1;
        stageUnavailable[21] = 1;
        stageUnavailable[22] = 1;
    }
    if ((contextOwner->mode1364 == 5 || contextOwner->mode1364 == 1) && contextOwner->characterDataMode != 0) contextOwner->LoadMusic(1);
    else contextOwner->LoadMusic(0);
    Slot0();
    FadeIn(palette, 1);
    phase = 0;
}
