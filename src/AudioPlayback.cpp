// Original stop and restart/play operations; preserve the sentinel check order.
#include "Engine.h"
extern const char audioPlayTitle[], audioPlayError[];

void Audio::StopSound(unsigned short id)
{
    if (buffers[id]) buffers[id]->Stop();
}

void Audio::StartSound(unsigned short id, int loop)
{
    HRESULT result;
    if (buffers[id] && id != 150) {
        buffers[id]->Stop();
        buffers[id]->SetCurrentPosition(0);
        result = buffers[id]->Play(0, 0, loop == 1);
        if (result != DS_OK) MessageBoxA(window, audioPlayError, audioPlayTitle, 0);
    }
}
