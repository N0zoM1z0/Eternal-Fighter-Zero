// Winner/results keyboard exit. Native Scene9::PollKeyboard at 0x00775750.
#include "Engine.h"

void Scene9::PollKeyboard()
{
    char state[256];
    {
        HRESULT result;
        result = inputOwner->keyboard->GetDeviceState(256, state);
        if (result < 0) {
            if (result == DIERR_INPUTLOST)
                inputOwner->keyboard->Acquire();
        }
        if (state[1] & 0x80) {
            flag002d = 1;
            contextOwner->playerFlag1378[0] = 0;
        }
    }
}
