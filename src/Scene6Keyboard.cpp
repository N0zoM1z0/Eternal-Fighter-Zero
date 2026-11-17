// Original settings-scene DirectInput keyboard scan (0x0075D350).
// Native profile: VC7.1 /Od with /GS; stack-owned 256-byte device state.
#include "Engine.h"

void Scene6::PollKeyboard()
{
    char state[256];
    {
        HRESULT result;
        result = inputOwner->keyboard->GetDeviceState(256, state);
        if (result < 0) {
            if (result == DIERR_INPUTLOST)
                inputOwner->keyboard->Acquire();
        }
        if (state[1] & 0x80)
            flag002d = 1;
    }
}
