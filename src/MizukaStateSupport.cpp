// Shared camera, reverse fade and scene-timer controls used by Mizuka states.
#include "Engine.h"

void Secondary::SetHorizontalOffset(int magnitude, int hold)
{
    contextOwner->state14238 = (1 - player * 2) * magnitude;
    contextOwner->state14240 = hold;
}

void Context::StartReverseFade(int attack, int hold, int release)
{
    fadeDirection = -1;
    fadeAttack = attack;
    fadeHold = hold;
    fadeRelease = release;
}

void Context::SetSceneTimer(int duration)
{
    state14278 = duration;
    if (setting136c == 0) {
        state14278 = state14278 / 2;
    }
}
