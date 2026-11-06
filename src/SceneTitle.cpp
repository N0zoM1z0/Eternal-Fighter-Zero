// Title/menu scene; retain original resource alternatives and state transitions.
#include "Engine.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);
extern const char titleDat[], titleObjectsDat[], titlePaletteDat[], titleObjectsPaletteDat[];
extern const char titleBmp[], titleObjectsBmp[], titlePaletteBmp[], titleObjectsPaletteBmp[];

Scene0::Scene0(HWND handle, Secondary **first, Secondary **second, Context *context, Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    if (true) {
        contextOwner->LoadObjectFile(&titleSurface, titleDat, 0, 1);
        contextOwner->LoadObjectFile(&objectSurface, titleObjectsDat, 0, 0xc1);
        videoOwner->LoadPalette(palette, titlePaletteDat, 0, 1, 0xc0);
        videoOwner->LoadPalette(palette, titleObjectsPaletteDat, 0, 0xc1, 0x30);
    } else {
        videoOwner->LoadSurface(&titleSurface, titleBmp, 1);
        videoOwner->LoadSurface(&objectSurface, titleObjectsBmp, 0xc1);
        videoOwner->LoadBitmapPalette(palette, titlePaletteBmp, 0, 1, 0xc0);
        videoOwner->LoadBitmapPalette(palette, titleObjectsPaletteBmp, 0, 0xc1, 0x30);
    }
    colorKey = videoOwner->SurfaceProperty(objectSurface);
    selection = 0;
    animationTick = 0;
    flag0442 = 0;
    directionHeld[0] = 0;
    directionHeld[1] = 0;
    phase = 1;
    flag002d = 0;
    field0448 = 0;
    idleTicks = 0;
}

Scene0::~Scene0()
{
    if (titleSurface) { titleSurface->Release(); titleSurface = 0; }
    if (objectSurface) { objectSurface->Release(); objectSurface = 0; }
}

unsigned char Scene0::Step()
{
    if (phase == 1) {
        flag0442 = 0;
        phase = 0;
        videoOwner->ApplyPalette(palette);
    } else if (phase == 2) {
        FadeIn(palette, 1);
        phase = 0;
    } else if (phase == 3) {
        videoOwner->ApplyPalette(palette);
        FadeIn(palette, 1);
        phase = 0;
    }
    // Preserve the original build's enabled inactivity guard.
    if (idleTicks > 1800 && true) {
        idleTicks = 0;
        contextOwner->mode1364 = 6;
        FadeOut(palette, 1, 0, 0);
        phase = 2;
        return 2;
    }
    PollKeyboard();
    contextOwner->PollInput();
    for (int i = 0; i < 2; ++i) {
        if (directionHeld[i] == 0 && contextOwner->directionY[i] != 0) {
            contextOwner->PlayEffectSound(8);
            selection += contextOwner->directionY[i];
            if (selection > 6) selection = 0;
            if (selection < 0) selection = 6;
            animationTick = 0;
            directionHeld[i] = 1;
        }
        if (contextOwner->directionY[i] == 0) {
            directionHeld[i] = 0;
            ++idleTicks;
        } else idleTicks = 0;
        if (contextOwner->buttonA[i] == 1) {
            switch (selection) {
            case 0:
                contextOwner->cpuPlayer[0] = i == 1;
                contextOwner->cpuPlayer[1] = i == 0;
                contextOwner->selectedPlayer = i;
                contextOwner->PlayEffectSound(6);
                contextOwner->mode1364 = 0;
                contextOwner->selection134e = 2;
                FadeOut(palette, 1, 0, 0);
                phase = 2;
                return 1;
            case 1:
                contextOwner->cpuPlayer[0] = i == 1;
                contextOwner->cpuPlayer[1] = i == 0;
                contextOwner->PlayEffectSound(6);
                contextOwner->mode1364 = 3;
                contextOwner->selection134e = contextOwner->setting134f;
                FadeOut(palette, 1, 0, 0);
                phase = 2;
                return 1;
            case 2:
                contextOwner->cpuPlayer[0] = 0;
                contextOwner->cpuPlayer[1] = 0;
                contextOwner->PlayEffectSound(6);
                contextOwner->mode1364 = 4;
                contextOwner->selection134e = contextOwner->setting134f;
                FadeOut(palette, 1, 0, 0);
                phase = 2;
                return 1;
            case 3:
                contextOwner->cpuPlayer[0] = i == 1;
                contextOwner->cpuPlayer[1] = i == 0;
                contextOwner->selectedPlayer = i;
                contextOwner->PlayEffectSound(6);
                contextOwner->mode1364 = 1;
                contextOwner->selection134e = 2;
                FadeOut(palette, 1, 0, 0);
                phase = 2;
                return 1;
            case 4:
                contextOwner->cpuPlayer[0] = 0;
                contextOwner->cpuPlayer[1] = 0;
                contextOwner->PlayEffectSound(6);
                contextOwner->mode1364 = 5;
                contextOwner->selection134e = 2;
                FadeOut(palette, 1, 0, 0);
                phase = 3;
                return 8;
            case 5:
                contextOwner->PlayEffectSound(6);
                FadeOut(palette, 1, 0, 0);
                phase = 3;
                return 6;
            case 6:
                PostMessageA(window, WM_CLOSE, 0, 0);
                break;
            }
        }
    }
    Slot0();
    return 0;
}

void Scene0::Slot0()
{
    videoOwner->DrawSurface(MakeSurfaceRect(0, 0, 320, 240), titleSurface,
    MakeSurfaceRect(0, 0, 320, 240), 0, 0);
    videoOwner->DrawSurface(MakeSurfaceRect(195, 130, 120, 98), objectSurface,
    MakeSurfaceRect(0, 0, 120, 98), colorKey, 0);
    videoOwner->DrawSurface(MakeSurfaceRect(195, 130 + selection * 14, 120, 14), objectSurface,
    MakeSurfaceRect(0, 98 + selection * 14, 120, 14), colorKey, 0);
    videoOwner->Present();
}

void Scene0::PollKeyboard()
{
    char state[256];
    {
        HRESULT result;
        result = inputOwner->keyboard->GetDeviceState(256, state);
        if (result < 0) { if (result == DIERR_INPUTLOST) inputOwner->keyboard->Acquire(); }
        if (state[1] & 0x80) PostMessageA(window, WM_CLOSE, 0, 0);
    }
}
