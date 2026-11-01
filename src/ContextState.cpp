// Original context reset and character-data availability probes.
#include "Engine.h"
#include <cmath>

extern const char characterPath0[], characterPath1[], characterPath2[];
extern const char characterPath3[], characterPath4[], characterPath5[];

void Context::ResetState()
{
    field1382 = 0;
    field1380 = 0;
    ClearEffects();
    state14210 = 0.0;
    state14218 = 0;
    state1421c = 0;
    state14220 = 0;
    state14228 = 0.0;
    state14230 = 0.0;
    state1427c = 0;
    flag1346 = 0;
    counter1348 = 0;
    fadeLevel = 0.0;
    fadeHold = 0;
    fadeAttack = 0;
    fadeRelease = 0;
    fadeDirection = 0;
    state14278 = 0;
    state1420e = 0;
    state1420c = 0;
    volumeStep = 0;
    currentVolume = 0;
    effectSelector = 1;
    effectFlag1350 = 1;
    counter1354 = 0;
}

void Context::ProbeCharacterData()
{
    HANDLE file = 0;
    const char *second[3];
    {
        const char *first[3] = { characterPath0, characterPath1, characterPath2 };
        second[0] = characterPath3;
        second[1] = characterPath4;
        second[2] = characterPath5;
        characterDataMode = 1;
        for (int i = 0; i < 3; ++i) {
            file = CreateFileA(first[i], GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
            if (file == INVALID_HANDLE_VALUE) characterDataMode = 0;
            CloseHandle(file);
        }
        for (int j = 0; j < 3; ++j) {
            file = CreateFileA(second[j], GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
            if (file == INVALID_HANDLE_VALUE) characterDataMode = -1;
            CloseHandle(file);
        }
    }
}

void Context::UpdateFrameControls()
{
    if (state1420e > 0) --state1420e;
    if (state1420e < 0) state1420e = 0;
    if (state1420c > 0) --state1420c;
    if (state1420c < 0) state1420c = 0;
    if (volumeStep > 0) {
        if (targetVolume > currentVolume) {
            currentVolume = volumeStep + currentVolume;
            if (targetVolume <= currentVolume) {
                currentVolume = targetVolume;
                volumeStep = 0;
            }
        } else {
            currentVolume = currentVolume - volumeStep;
            if (targetVolume >= currentVolume) {
                currentVolume = targetVolume;
                volumeStep = 0;
            }
        }
        audioOwner->SetSoundVolume(audioMode, currentVolume);
    }
}

void Context::UpdateCameraShake()
{
    if (state14210 >= 1.0) {
        state1421c = (int)(std::cos(state14228 * 3.141592 / 180.0) * state14210);
        state14220 = (int)(std::sin(state14230 * 3.141592 / 180.0) * state14210);
        state14228 = state14228 + 83.0;
        if (state14228 >= 360.0) state14228 = state14228 - 360.0;
        state14230 = state14230 + 107.0;
        if (state14230 >= 360.0) state14230 = state14230 - 360.0;
        if (state14218 > 0) --state14218;
        else state14210 = state14210 * 0.95;
        if (state14210 < 1.0) {
            state14210 = 0.0;
            state1421c = 0;
            state14220 = 0;
        }
    }
}
