// Makoto construction, initialization and frame entry owners.
#include "CharacterViews.h"
#include <cstring>

Character03::Character03(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "makoto");
    surfaceCount = 459;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field2ad0[0] = -7;
    field2af8[0] = -51;
    field2ad0[1] = 6;
    field2af8[1] = 0;
    field2ad0[2] = 17;
    field2af8[2] = -15;
    field2ad0[3] = 19;
    field2af8[3] = -11;
    field2ad0[4] = 22;
    field2af8[4] = -30;
    commandCount = 5;
    commands[0] = 1;
    commands[1] = 5;
    commands[10] = 3;
    for (int i = 0; i < 64; ++i) {
        field314c[i] = 0;
        field324c[i] = 0;
        field334c[i] = 0;
    }
}

void Character03::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field2ad0[0] = -7;
    field2af8[0] = -51;
    field2ad0[1] = 6;
    field2af8[1] = 0;
    field2ad0[2] = 17;
    field2af8[2] = -15;
    field2ad0[3] = 19;
    field2af8[3] = -11;
    field2ad0[4] = 22;
    field2af8[4] = -30;
    for (int i = 0; i < 64; ++i) {
        field314c[i] = 0;
        field324c[i] = 0;
        field334c[i] = 0;
    }
    Secondary::InitializeState();
}

void Character03::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character03::RemoveLocalEffect(short slot)
{
    field314c[slot] = 0;
    field324c[slot] = 0;
    field334c[slot] = 0;
    Secondary::RemoveLocalEffect(slot);
}

void Character03::Slot03() { UpdateLocomotionState(); }
void Character03::Slot01() {}
void Character03::Slot08() {}

void Character03::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}
