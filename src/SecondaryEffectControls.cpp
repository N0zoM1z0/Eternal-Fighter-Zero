// Shared character camera/flash requests and context transition requests.
#include "Engine.h"

void Secondary::SetVerticalShake(int magnitude, int hold)
{
    contextOwner->state14210 = magnitude;
    contextOwner->state14218 = hold;
}

void Secondary::SetHorizontalShake(int magnitude, int hold)
{
    contextOwner->state1423c = (1 - player * 2) * magnitude;
    contextOwner->state14244 = hold;
}

void Secondary::SetTint(unsigned char value, int duration)
{
    field30c0 = value;
    field30c4 = duration;
    if (contextOwner->setting136c == 0) {
        field30c4 = field30c4 / 2;
    }
    contextOwner->field0f33 = player;
}

void Context::RequestTransition(char request)
{
    state1427c = 1;
    state14280 = request;
}
