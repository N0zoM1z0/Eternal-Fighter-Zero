// Loading interlude and battle resource preparation.
#include "Engine.h"
#include <cstring>
#include <cstdlib>
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);
extern const char loadingPrefix[], loadingZeroHundreds[], loadingZeroTens[];
extern const char loadingDat[], loadingBmp[];
extern const char loadingReplayPrefix[], loadingReplaySeparator[], loadingReplayExtension[];
extern const char loadingBgZeroDat[], loadingBgDat[], loadingBgExtension[], loadingBgLayerDat[];
extern const char loadingBgLayerZeroDat[], loadingBgLayerPrefixDat[];
extern const char loadingBgZeroBmp[], loadingBgBmp[], loadingBgBitmapExtension[], loadingBgLayerBmp[];
class LoadingBackground01 {
    unsigned char unknown_0004[24];
public:
    LoadingBackground01(Video *);
    ~LoadingBackground01();
    virtual void Update(); virtual void Render(int, int, unsigned char);
};
class LoadingBackground10 {
    unsigned char unknown_0004[24];
public:
    LoadingBackground10(Video *);
    ~LoadingBackground10();
    virtual void Update(); virtual void Render(int, int, unsigned char);
};
class LoadingBackground12 {
    unsigned char unknown_0004[24];
public:
    LoadingBackground12(Video *);
    ~LoadingBackground12();
    virtual void Update(); virtual void Render(int, int, unsigned char);
};
class LoadingBackground16 {
    unsigned char unknown_0004[24];
public:
    LoadingBackground16(Video *);
    ~LoadingBackground16();
    virtual void Update(); virtual void Render(int, int, unsigned char);
};

Scene2::Scene2(HWND handle, Secondary **first, Secondary **second, Context *context, Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    loadingSurface = 0;
}
Scene2::~Scene2()
{
    if (loadingSurface) { loadingSurface->Release(); loadingSurface = 0; }
}
void Scene2::PollKeyboard() {}
void Scene2::Slot0()
{
    videoOwner->DrawSurface(MakeSurfaceRect(0, 0, 320, 240), loadingSurface,
        MakeSurfaceRect(0, 0, 320, 240), 0, 0);
    videoOwner->Present();
}
unsigned char Scene2::Step()
{
    char path[40];
    {
        char digits[8];
        {
            int image;
            image = std::rand() % 175;
            if (false) image = 112;
            secondary[0] = *secondarySlotA;
            secondary[1] = *secondarySlotB;
            std::strcpy(path, loadingPrefix);
            if (image < 100) std::strcat(path, loadingZeroHundreds);
            if (image < 10) std::strcat(path, loadingZeroTens);
            _itoa(image, digits, 10);
            std::strcat(path, digits);
            if (true) {
                std::strcat(path, loadingDat);
                contextOwner->LoadObjectFile(&loadingSurface, path, 0, 1);
                videoOwner->LoadPalette(palette, path, 0, 1, 254);
            } else {
                std::strcat(path, loadingBmp);
                videoOwner->LoadSurface(&loadingSurface, path, 1);
                videoOwner->LoadBitmapPalette(palette, path, 0, 1, 254);
            }
            Slot0();
            FadeIn(palette, 0);
            PrepareBattle();
            FadeOut(palette, 0, -500, 200);
            if (loadingSurface) { loadingSurface->Release(); loadingSurface = 0; }
            contextOwner->LoadMusic(contextOwner->flag0f32 + 10);
            return 3;
        }
    }
}
void Scene2::PrepareBattle()
{
    char digits[8];
    {
        int choice;
        {
            char path[40];
            if (contextOwner->mode1364 == 6) {
                choice = 22;
                while (choice == 19 || choice == 22) {
                    choice = std::rand() % 24;
                    if (contextOwner->characterDataMode == 0 && (choice == 20 || choice == 21 || choice == 23)) choice = 22;
                    if (contextOwner->characterDataMode == -1 && (choice == 12 || choice == 13 || choice == 14 || choice == 15)) choice = 22;
                }
                LoadCharacter(secondarySlotA, secondarySlotB, 0, (char)choice);
                choice = 22;
                while (choice == 19 || choice == 22) {
                    choice = std::rand() % 24;
                    if (contextOwner->characterDataMode == 0 && (choice == 20 || choice == 21 || choice == 23)) choice = 22;
                    if (contextOwner->characterDataMode == -1 && (choice == 12 || choice == 13 || choice == 14 || choice == 15)) choice = 22;
                }
                LoadCharacter(secondarySlotB, secondarySlotA, 1, (char)choice);
                (*secondarySlotA)->paletteIndex = 0;
                (*secondarySlotB)->paletteIndex = (*secondarySlotB)->characterId == (*secondarySlotA)->characterId;
                (*secondarySlotA)->cpuControlled = 1;
                (*secondarySlotB)->cpuControlled = 1;
                choice = 23;
                while (choice == 23) {
                    choice = std::rand() % 23;
                    if (contextOwner->characterDataMode == 0 && choice >= 13 && choice <= 16) choice = 23;
                    if (contextOwner->characterDataMode == -1 && choice >= 18 && choice <= 22) choice = 23;
                }
                contextOwner->flag0f32 = (char)choice;
                contextOwner->alternateStyle[0] = 0;
                contextOwner->alternateStyle[1] = 0;
            } else if (contextOwner->mode1364 == 5) {
                std::strcpy(path, loadingReplayPrefix);
                _itoa(contextOwner->field14282 + 1, digits, 10);
                std::strcat(path, digits);
                std::strcat(path, loadingReplaySeparator);
                _itoa(contextOwner->field14281 + 1, digits, 10);
                std::strcat(path, digits);
                std::strcat(path, loadingReplayExtension);
                if (contextOwner->flag14283 == 1) {
                    contextOwner->replayFile.OpenRead(path);
                    LoadCharacter(secondarySlotA, secondarySlotB, 0, (char)contextOwner->replayFile.ReadWord());
                    LoadCharacter(secondarySlotB, secondarySlotA, 1, (char)contextOwner->replayFile.ReadWord());
                    contextOwner->flag0f32 = (char)contextOwner->replayFile.ReadWord();
                    if (contextOwner->flag0f32 > 100) {
                        contextOwner->flag1340 = contextOwner->flag0f32;
                        contextOwner->flag0f32 = (char)contextOwner->replayFile.ReadWord();
                    } else contextOwner->flag1340 = 0;
                    (*secondarySlotA)->paletteIndex = (char)contextOwner->replayFile.ReadWord();
                    (*secondarySlotB)->paletteIndex = (char)contextOwner->replayFile.ReadWord();
                } else if (contextOwner->flag14283 == 2) {
                    contextOwner->replayFile.OpenWrite(path);
                    contextOwner->replayFile.WriteWord((short)(*secondarySlotA)->characterId);
                    contextOwner->replayFile.WriteWord((short)(*secondarySlotB)->characterId);
                    contextOwner->replayFile.WriteWord(104);
                    contextOwner->replayFile.WriteWord((short)contextOwner->flag0f32);
                    contextOwner->replayFile.WriteWord((short)(*secondarySlotA)->paletteIndex);
                    contextOwner->replayFile.WriteWord((short)(*secondarySlotB)->paletteIndex);
                }
            } else if ((contextOwner->mode1364 == 0 && (unsigned char)contextOwner->playerFlag1378[0] == 0) || contextOwner->mode1364 == 2) {
                choice = 22;
                while (((1 << choice) & contextOwner->field135c) != 0 || choice == 18 || choice == 19 || choice == 22) {
                    choice = std::rand() % 24;
                    if (contextOwner->characterDataMode == 0 && (choice == 20 || choice == 21 || choice == 23)) choice = 22;
                    if (contextOwner->characterDataMode == -1 && (choice == 12 || choice == 13 || choice == 14 || choice == 15)) choice = 22;
                }
                if (contextOwner->mode1364 == 0) {
                    if (contextOwner->flag1358 == 8) {
                        if ((unsigned char)contextOwner->playerFlag1378[1] == 0 || (unsigned char)contextOwner->playerFlag1378[1] == 8) choice = 19;
                        else choice = 24;
                        if (contextOwner->characterDataMode == 0) choice = 24;
                    }
                } else if (contextOwner->characterDataMode == 0) {
                    if (contextOwner->flag1358 == 8) choice = 24;
                } else {
                    if (contextOwner->flag1358 == 8) choice = 19;
                    if (contextOwner->flag1358 == 7) choice = 24;
                }
                if (contextOwner->cpuPlayer[0] == 1) {
                    LoadCharacter(secondarySlotA, secondarySlotB, 0, (char)choice);
                    (*secondarySlotA)->paletteIndex = 0;
                    if ((*secondarySlotA)->characterId == (*secondarySlotB)->characterId && (*secondarySlotB)->paletteIndex == 0) (*secondarySlotA)->paletteIndex = 1;
                } else {
                    LoadCharacter(secondarySlotB, secondarySlotA, 1, (char)choice);
                    (*secondarySlotB)->paletteIndex = 0;
                    if ((*secondarySlotB)->characterId == (*secondarySlotA)->characterId && (*secondarySlotA)->paletteIndex == 0) (*secondarySlotB)->paletteIndex = 1;
                }
                switch (choice) {
                case 0: contextOwner->flag0f32 = 4; break;
                case 1: contextOwner->flag0f32 = 7; break;
                case 2: contextOwner->flag0f32 = 0; break;
                case 3: contextOwner->flag0f32 = 6; break;
                case 4: contextOwner->flag0f32 = 10; break;
                case 5: contextOwner->flag0f32 = 11; break;
                case 6: contextOwner->flag0f32 = 3; break;
                case 7: contextOwner->flag0f32 = 5; break;
                case 8: contextOwner->flag0f32 = 22; break;
                case 9: contextOwner->flag0f32 = 2; break;
                case 10: contextOwner->flag0f32 = 8; break;
                case 11: contextOwner->flag0f32 = 9; break;
                case 12: contextOwner->flag0f32 = 4; break;
                case 13: contextOwner->flag0f32 = 1; break;
                case 14: contextOwner->flag0f32 = 19; break;
                case 15: contextOwner->flag0f32 = 20; break;
                case 16: contextOwner->flag0f32 = 17; break;
                case 17: contextOwner->flag0f32 = 8; break;
                case 18: contextOwner->flag0f32 = 12; break;
                case 19: contextOwner->flag0f32 = 16; break;
                case 20: contextOwner->flag0f32 = 14; break;
                case 21: contextOwner->flag0f32 = 13; break;
                case 23: contextOwner->flag0f32 = 15; break;
                case 24: contextOwner->flag0f32 = 12; break;
                }
            }
            _itoa(contextOwner->flag0f32, digits, 10);
            if (contextOwner->flag0f32 < 10) std::strcpy(path, loadingBgZeroDat);
            else std::strcpy(path, loadingBgDat);
            std::strcat(path, digits);
            if (true) {
                std::strcat(path, loadingBgExtension);
                if (contextOwner->extraA) { contextOwner->extraA->Release(); contextOwner->extraA = 0; }
                contextOwner->LoadObjectFile(&contextOwner->extraA, path, 0, 1);
                videoOwner->LoadPalette(contextOwner->characterPalette, path, 0, 1, 94);
                _itoa(contextOwner->flag0f32, digits, 10);
                if (contextOwner->flag0f32 < 10) std::strcpy(path, loadingBgLayerZeroDat);
                else std::strcpy(path, loadingBgLayerPrefixDat);
                std::strcat(path, digits);
                std::strcat(path, loadingBgLayerDat);
                if (contextOwner->extraB) { contextOwner->extraB->Release(); contextOwner->extraB = 0; }
                contextOwner->LoadObjectFile(&contextOwner->extraB, path, 0, 175);
            } else {
                std::strcat(path, loadingBgBitmapExtension);
                if (contextOwner->extraA) { contextOwner->extraA->Release(); contextOwner->extraA = 0; }
                videoOwner->LoadSurface(&contextOwner->extraA, path, 1);
                videoOwner->LoadBitmapPalette(contextOwner->characterPalette, path, 0, 1, 94);
                _itoa(contextOwner->flag0f32, digits, 10);
                if (contextOwner->flag0f32 < 10) std::strcpy(path, loadingBgZeroBmp);
                else std::strcpy(path, loadingBgBmp);
                std::strcat(path, digits);
                std::strcat(path, loadingBgLayerBmp);
                if (contextOwner->extraB) { contextOwner->extraB->Release(); contextOwner->extraB = 0; }
                videoOwner->LoadSurface(&contextOwner->extraB, path, 175);
            }
            switch (contextOwner->flag0f32) {
            case 1: { contextOwner->blob = reinterpret_cast<unsigned char *>(new LoadingBackground01(videoOwner)); break; }
            case 10: { contextOwner->blob = reinterpret_cast<unsigned char *>(new LoadingBackground10(videoOwner)); break; }
            case 12: { contextOwner->blob = reinterpret_cast<unsigned char *>(new LoadingBackground12(videoOwner)); break; }
            case 16: { contextOwner->blob = reinterpret_cast<unsigned char *>(new LoadingBackground16(videoOwner)); break; }
            }
            if (contextOwner->flag0f32 == 16) contextOwner->backgroundScale = 0.125;
            else contextOwner->backgroundScale = 1.0;
            (*secondarySlotA)->LoadResources();
            (*secondarySlotB)->LoadResources();
            if (contextOwner->mode1364 == 2) {
                (*secondarySlotA)->field00a8 = (float)contextOwner->flag1358 / 1.5f;
                (*secondarySlotB)->field00a8 = (float)contextOwner->flag1358 / 1.5f;
            } else {
                (*secondarySlotA)->field00a8 = (float)(char)contextOwner->setting1365;
                (*secondarySlotB)->field00a8 = (float)(char)contextOwner->setting1365;
            }
            contextOwner->ResetState();
            videoOwner->BuildBlendTables(contextOwner->characterPalette);
        }
    }
}
