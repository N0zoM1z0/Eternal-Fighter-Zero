// Shared scene ownership and the original timed palette/volume transitions.
#include "Engine.h"

Scene::Scene(HWND handle, Secondary **first, Secondary **second, Context *context, Video *video, Input *input, Audio *audio)
{
    secondarySlotA = first;
    secondarySlotB = second;
    window = handle;
    secondary[0] = *first;
    secondary[1] = *second;
    contextOwner = context;
    videoOwner = video;
    inputOwner = input;
    audioOwner = audio;
    phase = -1;
    flag002d = 0;
}

void Scene::FadeOut(unsigned char *colors, unsigned char mode, int volume, int step)
{
    DWORD tick = timeGetTime();
    int alternate = 0;
    if (mode == 0) {
        for (int i = 20; i >= 0; --i) {
            Slot0();
            videoOwner->DarkenPalette(colors, 0, 255, i * 5);
            audioOwner->SetSoundVolume(contextOwner->audioMode, volume - (20 - i) * step / 2);
            while (timeGetTime() - tick < static_cast<unsigned char>(16 - alternate)) { }
            tick = timeGetTime();
            alternate = !alternate;
        }
    }
    if (mode == 1) {
        for (int j = 20; j >= 0; --j) {
            Slot0();
            videoOwner->LightenPalette(colors, 0, 255, j * 5);
            audioOwner->SetSoundVolume(contextOwner->audioMode, volume - (20 - j) * step / 2);
            while (timeGetTime() - tick < static_cast<unsigned char>(16 - alternate)) { }
            tick = timeGetTime();
            alternate = !alternate;
        }
    }
}

void Scene::FadeIn(unsigned char *colors, unsigned char mode)
{
    DWORD tick = timeGetTime();
    int alternate = 0;
    if (mode == 0) {
        for (int i = 0; i <= 20; ++i) {
            Slot0();
            videoOwner->DarkenPalette(colors, 0, 255, i * 5);
            while (timeGetTime() - tick < static_cast<unsigned char>(16 - alternate)) { }
            tick = timeGetTime();
            alternate = !alternate;
        }
    }
    if (mode == 1) {
        for (int j = 0; j <= 20; ++j) {
            Slot0();
            videoOwner->LightenPalette(colors, 0, 255, j * 5);
            while (timeGetTime() - tick < static_cast<unsigned char>(16 - alternate)) { }
            tick = timeGetTime();
            alternate = !alternate;
        }
    }
}
