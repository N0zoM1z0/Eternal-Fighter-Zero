// Original replay/selection-scene DirectInput keyboard scan, native 0x00770D80.
// The 256-byte stack key-state buffer requires native /GS compiler protection.
#include "Engine.h"

void Scene8::PollKeyboard()
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
