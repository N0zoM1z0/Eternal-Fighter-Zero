// Context ownership of translated input, effect samples and music playback.
#include "Engine.h"
#include <cstring>
#include <cstdlib>

extern const char effectSoundPrefix[], effectSoundZero[], effectSoundExtension[];
extern const char musicPrefix[], musicZero[], musicExtension[];

void Context::PollInput()
{
    unsigned char states[2];
    for (int i = 0; i < 2; ++i) {
        states[i] = inputOwner->ReadState(i);
        directionX[i] = 0;
        directionY[i] = 0;
        buttonA[i] = 0;
        buttonB[i] = 0;
        buttonC[i] = 0;
        buttonD[i] = 0;
        if ((states[i] & 8) > 0) directionY[i] = -1;
        else if ((states[i] & 4) > 0) directionY[i] = 1;
        if ((states[i] & 2) > 0) directionX[i] = -1;
        else if ((states[i] & 1) > 0) directionX[i] = 1;
        if ((states[i] & 0x10) > 0) { buttonA[i] = !heldA[i]; heldA[i] = 1; }
        else heldA[i] = 0;
        if ((states[i] & 0x20) > 0) { buttonB[i] = !heldB[i]; heldB[i] = 1; }
        else heldB[i] = 0;
        if ((states[i] & 0x40) > 0) { buttonC[i] = !heldC[i]; heldC[i] = 1; }
        else heldC[i] = 0;
        if ((states[i] & 0x80) > 0) { buttonD[i] = !heldD[i]; heldD[i] = 1; }
        else heldD[i] = 0;
    }
}

void Context::Initialize()
{
    char path[32];
    char digits[8];
    for (int i = 0; i < 65; ++i) {
        std::strcpy(path, effectSoundPrefix);
        if (i < 10) std::strcat(path, effectSoundZero);
        _itoa(i, digits, 10);
        std::strcat(path, digits);
        std::strcat(path, effectSoundExtension);
        soundSlots[i] = audioOwner->LoadWave(path);
        audioOwner->SetSoundVolume(soundSlots[i], -500);
    }
}

void Context::PlayEffectSound(unsigned short id)
{
    if (soundSlots[id] != 150) audioOwner->StartSound(soundSlots[id], 0);
}

void Context::LoadMusic(unsigned short id)
{
    char path[32];
    char digits[8];
    std::strcpy(path, musicPrefix);
    if (id < 10) std::strcat(path, musicZero);
    _itoa(id, digits, 10);
    std::strcat(path, digits);
    std::strcat(path, musicExtension);
    if (audioMode != 150) {
        audioOwner->StopSound(audioMode);
        audioOwner->ReleaseSound(audioMode);
        audioMode = 150;
    }
    audioMode = audioOwner->LoadWave(path);
    audioOwner->ReadLoopMarkers(path);
    if (audioMode != 150) audioOwner->StartSound(audioMode, 1 - ((id == 2 || id == 3 || id == 4 || id == 9) ? 1 : 0));
}

void Context::ReleaseMusic()
{
    if (audioMode != 150) {
        audioOwner->StopSound(audioMode);
        audioOwner->ReleaseSound(audioMode);
        audioMode = 150;
    }
}

void Context::FadeMusic(int target, short step)
{
    targetVolume = target;
    volumeStep = step;
}
