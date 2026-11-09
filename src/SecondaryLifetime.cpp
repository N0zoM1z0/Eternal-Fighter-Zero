// Shared character ownership and observed scalar/array construction.
#include "Engine.h"

Secondary::Secondary(Secondary **opponent, Context *context, Video *video, Input *input, Audio *audio, char id)
: opponentSlot(opponent)
{
    int i;
    contextOwner = context;
    videoOwner = video;
    inputOwner = input;
    audioOwner = audio;
    player = id;
    characterId = 0;
    paletteIndex = 0;
    for (i = 0; i < 50; ++i) soundSlots[i] = 150;
    for (i = 0; i < 20; ++i) commands[i] = -1;
    surfaces = 0;
    patterns = new PatternSequence[505];
    sequences = new SecondarySequence[505];
    field30c8 = 0;
    field30cc = 0;
    field30d0 = 0;
    field30d4 = 0;
    field30d8 = 0;
    field30e8 = 0;
}

Secondary::~Secondary()
{
    int i;
    if (surfaces) {
        for (i = 0; i < surfaceCount + 1; ++i) {
            if (surfaces[i]) { surfaces[i]->Release(); surfaces[i] = 0; }
        }
        delete[] surfaces;
    }
    for (i = 0; i < 50; ++i) {
        if (soundSlots[i] != 150) audioOwner->ReleaseSound(soundSlots[i]);
    }
    delete[] patterns;
    delete[] sequences;
}

SecondarySequence::SecondarySequence() { data = 0; }
SecondarySequence::~SecondarySequence() { if (data) delete[] data; }
SecondaryTrail::SecondaryTrail() { position = 0; pending = 0; held = 0; }
void SecondaryTrail::FinishSample() { held = pending * 3; pending = 0; }

void Secondary::ResetPose()
{
    field000a = 0;
    field000c = 0;
    outgoingPushbackVelocityX = 0.0;
    field0168 = 0;
    attackWasGuarded = 0;
    trail.FinishSample();
}
