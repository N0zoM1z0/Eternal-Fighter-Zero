// Replay file selection initialization, native 0x00770E30. natural C++ reconstruction.
#include "Engine.h"
#include <cstring>
#include <cstdlib>

extern const char replayInitialPaletteDat[], replayInitialPaletteBmp[];
extern const char replayFilePrefix[], replayFileSeparator[], replayFileExtension[];
extern const char replayRestoredPaletteDat[], replayRestoredPaletteBmp[];

typedef char Scene8PrepareLayout[(sizeof(Scene8) == 0x758) ? 1 : -1];

void Scene8::PrepareReplayList()
{
    char digits[8];
    {
        char filename[32];
        {
            int opened;
            {
                int row;
                {
                    int column;
                    heldDirection[0] = 0;
                    heldDirection[1] = 0;
                    scrollLeft = 300;
                    scrollRight = 300;
                    scrollTop = 180;
                    scrollBottom = 180;
                    replayMenuPhase = 0;
                    replayMenuSubchoice = 0;
                    replayOverwriteChoice = 0;
                    replayScrollX = 0.0;
                    replayScrollY = 0.0;
                    contextOwner->flag1358 = 0;
                    contextOwner->playerFlag1378[0] = 0;
                    contextOwner->playerFlag1378[1] = 0;
                    contextOwner->alternateStyle[0] = 0;
                    contextOwner->alternateStyle[1] = 0;
                    if (true) {
                        videoOwner->LoadPalette(palette, replayInitialPaletteDat, 0, 193, 62);
                    } else {
                        videoOwner->LoadBitmapPalette(palette, replayInitialPaletteBmp, 0, 193, 62);
                    }
                    for (row = 0; row < 9; ++row) {
                        for (column = 0; column < 9; ++column) {
                            std::strcpy(filename, replayFilePrefix);
                            _itoa(row + 1, digits, 10);
                            std::strcat(filename, digits);
                            std::strcat(filename, replayFileSeparator);
                            _itoa(column + 1, digits, 10);
                            std::strcat(filename, digits);
                            std::strcat(filename, replayFileExtension);
                            opened = contextOwner->replayFile.OpenRead(filename);
                            if (opened == 0) {
                                replayAvailable[row][column] = 0;
                            } else {
                                replayCharacters[row][column][0] = (unsigned char)contextOwner->replayFile.ReadWord();
                                replayCharacters[row][column][1] = (unsigned char)contextOwner->replayFile.ReadWord();
                                replayAvailable[row][column] = 1;
                            }
                            contextOwner->replayFile.Close();
                        }
                    }
                    if (phase == 2) {
                        Slot0();
                        FadeIn(palette, 1);
                    } else {
                        if (true) {
                            videoOwner->LoadPalette(palette, replayRestoredPaletteDat, 0, 193, 62);
                        } else {
                            videoOwner->LoadBitmapPalette(palette, replayRestoredPaletteBmp, 0, 193, 62);
                        }
                        videoOwner->ApplyPalette(palette);
                        FadeIn(palette, 1);
                    }
                    phase = 0;
                }
            }
        }
    }
}
