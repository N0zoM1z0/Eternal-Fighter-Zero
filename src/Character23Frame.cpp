// Misuzu construction, initialization and local-effect ownership.
#include "CharacterViews.h"
#include <cstring>
SurfaceRect MakeSurfaceRect(int, int, int, int);

Character23::Character23(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "misuzu");
    surfaceCount = 872;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3460 = 0;
    field3154 = 0;
    field3150 = 0;
    field3458 = 0;
    field345c = 0;
    field3464 = 0;
    field3468 = 0;
    field346c = 0;
    field3470 = 0;
    field3474 = 0;
    field3478 = 0;
    field347c = 0;
    field3480 = 0;
    field2ad0[0] = -2;
    field2af8[0] = -62;
    field2ad0[1] = 1;
    field2af8[1] = -10;
    field2ad0[2] = 24;
    field2af8[2] = -18;
    field2ad0[3] = -11;
    field2af8[3] = -23;
    field2ad0[4] = 21;
    field2af8[4] = -22;
    commandCount = 5;
    commands[0] = 1;
    commands[1] = 19;
    commands[2] = 2;
    commands[3] = 0;
    commands[4] = 1;
    commands[5] = 6;
    commands[10] = 23;
    for (int i = 0; i < 64; ++i) {
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
}

void Character23::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3460 = 0;
    field3458 = 0;
    field345c = 0;
    field3154 = 0;
    field3150 = 0;
    field3464 = 0;
    field3468 = 0;
    field346c = 0;
    field3470 = 0;
    field3474 = 0;
    field3478 = 0;
    field347c = 0;
    field3480 = 0;
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
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
    Secondary::InitializeState();
    EffectSpawn spawn;
    ResetLocalEffectSpawn(&spawn);
    spawn.type = 400;
    spawn.x = 320.0;
    spawn.y = -320.0;
    spawn.group = 0;
    spawn.layer = 1;
    spawn.field0028 = 1;
    spawn.owner = 1;
    spawn.flag0018 = facing;
    EmitLocalEffect(&spawn);
}

void Character23::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character23::RemoveLocalEffect(short slot)
{
    field3158[slot] = 0;
    field3258[slot] = 0;
    field3358[slot] = 0;
    Secondary::RemoveLocalEffect(slot);
}

void Character23::Slot03() { UpdateLocomotionState(); }

void Character23::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}

void Character23::Slot08()
{
    if (field345c > 0) {
        --field345c;
    }
    if (field3460 > 0) {
        (*opponentSlot)->SetCharacterTint(203, 3);
        ++field3458;
        if (field3458 > 45 - field3460 * 7) {
            (*opponentSlot)->field0108 = (*opponentSlot)->field0108 - 10;
            if ((*opponentSlot)->field0108 <= 0) {
                (*opponentSlot)->field0108 = 1;
            }
            field3458 = 0;
        }
        if (field0008 > 49 && field0008 < 150) {
            field3460 = 0;
            field345c = 0;
        }
    }
    if ((field345c <= 0 && field3460 > 0) || (*opponentSlot)->field0108 <= 0) {
        field3460 = 0;
        field345c = 0;
    }
}

void Character23::Slot01()
{
    SurfaceRect destination, source;
    PatternFrame frame;
    if (field3464 > 0) {
        frame = patterns[42].frames[0];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(32 - frame.u, 218 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 277) - frame.width, 218 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3464 > 1) {
        frame = patterns[42].frames[0];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(42 - frame.u, 218 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 267) - frame.width, 218 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3464 > 2) {
        frame = patterns[42].frames[0];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(52 - frame.u, 218 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 257) - frame.width, 218 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3460 > 0) {
        frame = patterns[43].frames[0];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 271) - frame.width, 31 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3460 > 0) {
        frame = patterns[44].frames[0];
        source = MakeSurfaceRect(0, 0, (field345c * frame.width) / 3000, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, (field345c * frame.width) / 3000,
                frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 271) - (field345c * frame.width) / 3000, 31 - frame.v,
                (field345c * frame.width) / 3000, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
}
