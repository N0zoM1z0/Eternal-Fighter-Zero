// Original character resource reuse, palette alternatives and play-count persistence.
#include "Engine.h"
#include <cstring>
#include <cstdlib>
extern const char secondaryDatAltSeparator[], secondaryDatAltExtension[];
extern const char secondaryDatFallbackSeparator[], secondaryDatFallbackExtension[];
extern const char secondaryDatSeparator[], secondaryDatExtension[];
extern const char secondaryBmpAltSeparator[], secondaryBmpAltExtension[];
extern const char secondaryBmpFallbackSeparator[], secondaryBmpSeparator[];

void Secondary::LoadResources()
{
    char path[32];
    char digits[8];
    if (field30e8 == 0) {
        LoadImages();
        LoadPatterns();
        LoadSounds();
        field30e8 = 1;
    } else {
        if (true) {
            if (contextOwner->alternateStyle[player] != 0) {
                std::strcpy(path, resourceName);
                std::strcat(path, secondaryDatAltSeparator);
                std::strcat(path, resourceName);
                _itoa(paletteIndex + 1, digits, 10);
                std::strcat(path, digits);
                std::strcat(path, secondaryDatAltExtension);
                if (videoOwner->LoadPalette(contextOwner->characterPalette, path, 0, player * 40 + 0x5f, 40) == 0) {
                    std::strcpy(path, resourceName);
                    std::strcat(path, secondaryDatFallbackSeparator);
                    std::strcat(path, resourceName);
                    std::strcat(path, secondaryDatFallbackExtension);
                    videoOwner->LoadPalette(contextOwner->characterPalette, path, paletteIndex * 40, player * 40 + 0x5f, 40);
                }
            } else {
                std::strcpy(path, resourceName);
                std::strcat(path, secondaryDatSeparator);
                std::strcat(path, resourceName);
                std::strcat(path, secondaryDatExtension);
                videoOwner->LoadPalette(contextOwner->characterPalette, path, paletteIndex * 40, player * 40 + 0x5f, 40);
            }
        } else {
            if (contextOwner->alternateStyle[player] != 0) {
                std::strcpy(path, resourceName);
                std::strcat(path, secondaryBmpAltSeparator);
                std::strcat(path, resourceName);
                _itoa(paletteIndex + 1, digits, 10);
                std::strcat(path, digits);
                std::strcat(path, secondaryBmpAltExtension);
                if (videoOwner->LoadPalette(contextOwner->characterPalette, path, 0, player * 40 + 0x5f, 40) == 0) {
                    std::strcpy(path, resourceName);
                    std::strcat(path, secondaryBmpFallbackSeparator);
                    videoOwner->LoadBitmapPalette(contextOwner->characterPalette, path, paletteIndex * 40, player * 40 + 0x5f, 40);
                }
            } else {
                std::strcpy(path, resourceName);
                std::strcat(path, secondaryBmpSeparator);
                videoOwner->LoadBitmapPalette(contextOwner->characterPalette, path, paletteIndex * 40, player * 40 + 0x5f, 40);
            }
        }
    }
    InitializeState();
    if (cpuControlled == 0) {
        if ((contextOwner->mode1364 == 0 || contextOwner->mode1364 == 2) && contextOwner->flag1358 == 1) {
            statistics.Read(resourceName);
            ++statistics.values[0];
            statistics.Write(resourceName);
        } else if (contextOwner->mode1364 == 1 || contextOwner->mode1364 == 3 || contextOwner->mode1364 == 4) {
            statistics.Read(resourceName);
            ++statistics.values[0];
            statistics.Write(resourceName);
        }
    }
}
