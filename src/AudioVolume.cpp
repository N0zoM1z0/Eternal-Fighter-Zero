// Original per-buffer DirectSound volume forwarding.
#include "Engine.h"

void Audio::SetSoundVolume(unsigned short id, int volume)
{
    if (id == 150) return;
    if (buffers[id]) buffers[id]->SetVolume(volume);
}
