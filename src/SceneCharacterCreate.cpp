// Complete character selection allocation and resource-loading dispatcher.
#include "CharacterViews.h"
#include <cstring>
extern const char characterSystemDat[], characterSeparatorDat[], characterExtensionDat[];
extern const char characterSystemBmp[], characterSeparatorBmp[], characterExtensionBmp[];

void Scene1::LoadCharacter(Secondary **created, Secondary **opponent, char player)
{
    char path[40];
    switch (field053c[player]) {
    case 0: *created = new Character00(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 1: *created = new Character01(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 2: *created = new Character02(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 3: *created = new Character03(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 4: *created = new Character04(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 5: *created = new Character05(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 6: *created = new Character06(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 7: *created = new Character07(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 8: *created = new Character08(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 9: *created = new Character09(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 10: *created = new Character10(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 11: *created = new Character11(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 12: *created = new Character12(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 13: *created = new Character13(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 14: *created = new Character14(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 15: *created = new Character15(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 16: *created = new Character16(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 17: *created = new Character17(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 18: *created = new Character18(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 19: *created = new Character19(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 20: *created = new Character20(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 21: *created = new Character21(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 22: *created = new Character10(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 23: *created = new Character23(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    }
    (*created)->characterId = field053c[player];
    secondary[player] = *created;
    (*created)->cpuControlled = contextOwner->cpuPlayer[player];
    if (true) {
        std::strcpy(path, characterSystemDat);
        std::strcat(path, (*created)->resourceName);
        std::strcat(path, characterSeparatorDat);
        std::strcat(path, (*created)->resourceName);
        std::strcat(path, characterExtensionDat);
        contextOwner->LoadObjectFile(&playerSurfaces[player], path, 0, player * 40 + 0xaf);
        videoOwner->LoadPalette(palette, path, field053e[player] * 40, player * 40 + 0xaf, 40);
    } else {
        std::strcpy(path, characterSystemBmp);
        std::strcat(path, (*created)->resourceName);
        std::strcat(path, characterSeparatorBmp);
        std::strcat(path, (*created)->resourceName);
        std::strcat(path, characterExtensionBmp);
        videoOwner->LoadSurface(&playerSurfaces[player], path, player * 40 + 0xaf);
        videoOwner->LoadBitmapPalette(palette, path, field053e[player] * 40, player * 40 + 0xaf, 40);
    }
    videoOwner->ApplyPalette(palette);
    playerColorKey[player] = videoOwner->SurfaceProperty(playerSurfaces[player]);
}
