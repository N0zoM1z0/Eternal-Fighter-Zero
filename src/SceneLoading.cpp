// Loading interlude and battle resource preparation.
#include "Engine.h"
#include <cstring>
#include <cstdlib>
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);
extern const char loadingPrefix[], loadingZeroHundreds[], loadingZeroTens[];
extern const char loadingDat[], loadingBmp[];
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
