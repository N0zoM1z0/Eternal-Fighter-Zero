// Mayu construction, initialization and frame entry owners.
#include "CharacterViews.h"
#include <cstring>

Character05::Character05(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "mayu");
    surfaceCount = 386;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field2ad0[0] = -8;
    field2af8[0] = -46;
    field2ad0[1] = -16;
    field2af8[1] = 0;
    field2ad0[2] = 14;
    field2af8[2] = -5;
    field2ad0[3] = 25;
    field2af8[3] = -19;
    field2ad0[4] = 28;
    field2af8[4] = -35;
    commandCount = 5;
    commands[0] = 0;
    commands[1] = 6;
    commands[2] = 3;
    commands[3] = 2;
    commands[3] = 4;
    commands[10] = 5;
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
}

void Character05::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field2ad0[0] = -8;
    field2af8[0] = -46;
    field2ad0[1] = -16;
    field2af8[1] = 0;
    field2ad0[2] = 14;
    field2af8[2] = -5;
    field2ad0[3] = 25;
    field2af8[3] = -19;
    field2ad0[4] = 28;
    field2af8[4] = -35;
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
    Secondary::InitializeState();
}

void Character05::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character05::RemoveLocalEffect(short slot)
{
    field3148[slot] = 0;
    field3248[slot] = 0;
    field3348[slot] = 0;
    Secondary::RemoveLocalEffect(slot);
}

void Character05::Slot03() { UpdateLocomotionState(); }
void Character05::Slot01() {}
void Character05::Slot08() {}

void Character05::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}
