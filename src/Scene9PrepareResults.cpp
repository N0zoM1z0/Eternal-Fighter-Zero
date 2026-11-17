// Reconstructed Scene9::PrepareResults, native 0x00774B00.
// Original winner/results initialization, statistics, score bonuses and pose reset.
#include "Engine.h"
#include <cstdlib>
#include <cstring>

extern const char resultsSystemPrefix[];
extern const char resultsOverlaySystemPrefix[];
extern const char resultsPathSeparator[];
extern const char resultsDataExtension[], resultsOverlayDatExtension[];
extern const char resultsNumberZero[];
extern const char resultsNumberExtension[];
extern const char resultsPortraitBmpExtension[], resultsOverlayBmpExtension[];

typedef char ResultOwnerSize[(sizeof(Scene9) == 0x474) ? 1 : -1];

void Scene9::PrepareResults()
{
    char digits[8];
    {
    char path[40];
    {
    int image;
    {
    int i;
    {
    image = std::rand() % secondary[(char)contextOwner->winner134c]->commandCount;
    if (resultBackdropSurface) { resultBackdropSurface->Release(); resultBackdropSurface = 0; }
    if (resultOverlaySurface) { resultOverlaySurface->Release(); resultOverlaySurface = 0; }
    std::strcpy(path, resultsSystemPrefix);
    std::strcat(path, secondary[(char)contextOwner->winner134c]->resourceName);
    std::strcat(path, resultsPathSeparator);
    std::strcat(path, secondary[(char)contextOwner->winner134c]->resourceName);
    if (true) {
        std::strcat(path, resultsDataExtension);
        contextOwner->LoadObjectFile(&resultBackdropSurface, path, 0, (char)contextOwner->winner134c * 40 + 95);
        videoOwner->LoadPalette(contextOwner->characterPalette, path,
            (char)secondary[(char)contextOwner->winner134c]->paletteIndex * 40,
            (char)contextOwner->winner134c * 40 + 95, 40);
    } else {
        std::strcat(path, resultsPortraitBmpExtension);
        videoOwner->LoadSurface(&resultBackdropSurface, path, (char)contextOwner->winner134c * 40 + 95);
        videoOwner->LoadBitmapPalette(contextOwner->characterPalette, path,
            (char)secondary[(char)contextOwner->winner134c]->paletteIndex * 40,
            (char)contextOwner->winner134c * 40 + 95, 40);
    }
    colorKey = videoOwner->SurfaceProperty(resultBackdropSurface);
    for (i = 0; i < 20; ++i) {
        if (secondary[1 - (char)contextOwner->winner134c]->characterId ==
            secondary[(char)contextOwner->winner134c]->commands[i]) {
            image = i + 10;
        }
    }
    std::strcpy(path, resultsOverlaySystemPrefix);
    std::strcat(path, secondary[(char)contextOwner->winner134c]->resourceName);
    std::strcat(path, resultsNumberExtension);  // separator for result variants
    _itoa(image, digits, 10);
    if (image < 10) std::strcat(path, resultsNumberZero);
    std::strcat(path, digits);
    if (true) {
        std::strcat(path, resultsOverlayDatExtension);
        contextOwner->LoadObjectFile(&resultOverlaySurface, path, 0, 175);
    } else {
        std::strcat(path, resultsOverlayBmpExtension);
        videoOwner->LoadSurface(&resultOverlaySurface, path, 175);
    }

    if (contextOwner->mode1364 == 4) {
        if (contextOwner->winner134c == 0) {
            secondary[0]->statistics.Read(secondary[0]->resourceName);
            ++secondary[0]->statistics.values[1];
            secondary[0]->statistics.Write(secondary[0]->resourceName);
            secondary[1]->statistics.Read(secondary[1]->resourceName);
            ++secondary[1]->statistics.values[2];
            secondary[1]->statistics.Write(secondary[1]->resourceName);
        } else {
            secondary[1]->statistics.Read(secondary[1]->resourceName);
            ++secondary[1]->statistics.values[1];
            secondary[1]->statistics.Write(secondary[1]->resourceName);
            secondary[0]->statistics.Read(secondary[0]->resourceName);
            ++secondary[0]->statistics.values[2];
            secondary[0]->statistics.Write(secondary[0]->resourceName);
        }
    }
    if (contextOwner->mode1364 == 2) {
        healthBonus = (unsigned)secondary[(char)contextOwner->selectedPlayer]->field30dc / 100;
        secondary[(char)contextOwner->selectedPlayer]->field30d0 += healthBonus;
        comboBonus = secondary[(char)contextOwner->selectedPlayer]->field30d4 << 1;
        secondary[(char)contextOwner->selectedPlayer]->field30d0 += comboBonus;
        damageBonus = secondary[(char)contextOwner->selectedPlayer]->field30d8 / 100;
        secondary[(char)contextOwner->selectedPlayer]->field30d0 += damageBonus;
        winBonus = (char)contextOwner->flag1358 * 50 *
                   (secondary[1 - (char)contextOwner->selectedPlayer]->field00ac == 0);
        secondary[(char)contextOwner->selectedPlayer]->field30d0 += winBonus;
        secondary[(char)contextOwner->selectedPlayer]->statistics.Read(
            secondary[(char)contextOwner->selectedPlayer]->resourceName);
        if ((unsigned)secondary[(char)contextOwner->selectedPlayer]->statistics.values[4] <
            secondary[(char)contextOwner->selectedPlayer]->field30cc) {
            secondary[(char)contextOwner->selectedPlayer]->statistics.values[3] =
                secondary[(char)contextOwner->selectedPlayer]->field30c8;
            secondary[(char)contextOwner->selectedPlayer]->statistics.values[4] =
                secondary[(char)contextOwner->selectedPlayer]->field30cc;
        } else if ((unsigned)secondary[(char)contextOwner->selectedPlayer]->statistics.values[4] ==
            secondary[(char)contextOwner->selectedPlayer]->field30cc &&
            (unsigned)secondary[(char)contextOwner->selectedPlayer]->statistics.values[3] <
            secondary[(char)contextOwner->selectedPlayer]->field30c8) {
            secondary[(char)contextOwner->selectedPlayer]->statistics.values[3] =
                secondary[(char)contextOwner->selectedPlayer]->field30c8;
        }
        secondary[(char)contextOwner->selectedPlayer]->statistics.Write(
            secondary[(char)contextOwner->selectedPlayer]->resourceName);
    }
    if ((char)contextOwner->setting1370 == 2) {
        if (contextOwner->cpuPlayer[0] == 0) {
            secondary[0]->statistics.Read(secondary[0]->resourceName);
            if ((unsigned)secondary[0]->statistics.values[6] < secondary[0]->field30d4)
                secondary[0]->statistics.values[6] = secondary[0]->field30d4;
            if ((unsigned)secondary[0]->statistics.values[7] < secondary[0]->field30d8)
                secondary[0]->statistics.values[7] = secondary[0]->field30d8;
            secondary[0]->statistics.Write(secondary[0]->resourceName);
        }
        if (contextOwner->cpuPlayer[1] == 0) {
            secondary[1]->statistics.Read(secondary[1]->resourceName);
            if ((unsigned)secondary[1]->statistics.values[6] < secondary[1]->field30d4)
                secondary[1]->statistics.values[6] = secondary[1]->field30d4;
            if ((unsigned)secondary[1]->statistics.values[7] < secondary[1]->field30d8)
                secondary[1]->statistics.values[7] = secondary[1]->field30d8;
            secondary[1]->statistics.Write(secondary[1]->resourceName);
        }
    }
    field0444 = 240;
    field0446 = 18;
    field0448 = 0;
    field044a = 0;
    field044c = 0;
    field044e = 0;
    field0450 = -2;
    field0454 = 320;
    field0458 = -240;
    field0452 = 9;
    field0456 = 15;
    field045a = 15;
    field045c = 0;
    if (contextOwner->winner134c == 1) {
        secondary[0]->positionX = 480.0;
        secondary[0]->positionY = -240.0;
        secondary[0]->facing = -1;
        secondary[0]->field0008 = 47;
        secondary[0]->ResetPose();
        secondary[0]->ResetFrame();
        secondary[0]->field30bc = 0;
        secondary[0]->trail.pending = 0;
        secondary[0]->trail.held = 0;
        secondary[0]->field0058 = 0;
        secondary[0]->outgoingPushbackVelocityX = 0.0;
        secondary[1]->outgoingPushbackVelocityX = 0.0;
    } else {
        secondary[1]->positionX = 480.0;
        secondary[1]->positionY = -240.0;
        secondary[1]->facing = -1;
        secondary[1]->field0008 = 47;
        secondary[1]->ResetPose();
        secondary[1]->ResetFrame();
        secondary[1]->field30bc = 0;
        secondary[1]->trail.pending = 0;
        secondary[1]->trail.held = 0;
        secondary[1]->field0058 = 0;
        secondary[0]->outgoingPushbackVelocityX = 0.0;
        secondary[1]->outgoingPushbackVelocityX = 0.0;
    }
    }
    }
    }
    }
}
