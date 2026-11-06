// Misaki construction, initialization and frame entry owners.
#include "CharacterViews.h"
#include <cstring>

Character07::Character07(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "misaki");
    surfaceCount = 474;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field2ad0[0] = -13;
    field2af8[0] = -60;
    field2ad0[1] = 14;
    field2af8[1] = 0;
    field2ad0[2] = 17;
    field2af8[2] = -6;
    field2ad0[3] = 7;
    field2af8[3] = -25;
    field2ad0[4] = 27;
    field2af8[4] = -25;
    commandCount = 5;
    commands[0] = 1;
    commands[1] = 11;
    commands[2] = 18;
    commands[3] = 7;
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
}

void Character07::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field2ad0[0] = -13;
    field2af8[0] = -60;
    field2ad0[1] = 14;
    field2af8[1] = 0;
    field2ad0[2] = 17;
    field2af8[2] = -6;
    field2ad0[3] = 7;
    field2af8[3] = -25;
    field2ad0[4] = 27;
    field2af8[4] = -25;
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
    Secondary::InitializeState();
}

void Character07::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character07::RemoveLocalEffect(short slot)
{
    field3148[slot] = 0;
    field3248[slot] = 0;
    field3348[slot] = 0;
    Secondary::RemoveLocalEffect(slot);
}

void Character07::Slot03() { UpdateLocomotionState(); }
void Character07::Slot01() {}
void Character07::Slot08() {}

void Character07::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}
