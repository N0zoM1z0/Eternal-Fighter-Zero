// Mishio construction, initialization, indicators and frame control.
#include "CharacterViews.h"
#include <cstring>
SurfaceRect MakeSurfaceRect(int, int, int, int);

Character15::Character15(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, "mishio");
    surfaceCount = 1303;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field3158 = 0;
    field315c = 0;
    field3160 = 0;
    field3164 = 0;
    field3168 = 0;
    field316c = 0;
    field3170 = 0;
    field2ad0[0] = -4;
    field2af8[0] = -57;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 21;
    field2af8[2] = -12;
    field2ad0[3] = 18;
    field2af8[3] = -15;
    field2ad0[4] = 38;
    field2af8[4] = -39;
    commandCount = 7;
    commands[0] = 3;
    commands[10] = 15;
    for (int i = 0; i < 64; ++i) {
        field3174[i] = 0;
        field3274[i] = 0;
        field3374[i] = 0;
    }
}

void Character15::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
    field3158 = 0;
    field315c = 0;
    field3160 = 0;
    field3164 = 0;
    field3168 = 0;
    field316c = 0;
    field3170 = 0;
    field2ad0[0] = -4;
    field2af8[0] = -57;
    field2ad0[1] = 18;
    field2af8[1] = 0;
    field2ad0[2] = 21;
    field2af8[2] = -12;
    field2ad0[3] = 18;
    field2af8[3] = -15;
    field2ad0[4] = 38;
    field2af8[4] = -39;
    for (int i = 0; i < 64; ++i) {
        field3174[i] = 0;
        field3274[i] = 0;
        field3374[i] = 0;
    }
    Secondary::InitializeState();
}

void Character15::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character15::RemoveLocalEffect(short slot)
{
    field3174[slot] = 0;
    field3274[slot] = 0;
    field3374[slot] = 0;
    Secondary::RemoveLocalEffect(slot);
}

void Character15::Slot03() { UpdateLocomotionState(); }

void Character15::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}

void Character15::Slot08()
{
    EffectSpawn spawn;
    ResetLocalEffectSpawn(&spawn);
    if (field3168 > 0 && field3158 == 3) {
        if (field0008 != 318) {
            --field3168;
        }
        if (field3168 <= 0) {
            field3158 = 0;
        }
    }
    if (field3158 > 0) {
        --field315c;
        if (field3158 == 3) {
            ++field3160;
            if (field3160 > 144) {
                field3160 = 0;
            }
            if (field3160 == 18) {
                SetCharacterTint(209, 27);
            }
            if (field3160 == 36) {
                SetCharacterTint(208, 27);
            }
            if (field3160 == 54) {
                SetCharacterTint(207, 27);
            }
            if (field3160 == 72) {
                SetCharacterTint(177, 27);
            }
            if (field3160 == 90) {
                SetCharacterTint(207, 27);
            }
            if (field3160 == 108) {
                SetCharacterTint(208, 27);
            }
            if (field3160 == 126) {
                SetCharacterTint(209, 27);
            }
            if (field3160 == 144) {
                SetCharacterTint(210, 27);
            }
        }
        if (field315c <= 0 && (field0008 < 50 || field0008 > 149)) {
            if (field3158 == 1) {
                spawn.type = 34;
            }
            if (field3158 == 2) {
                spawn.type = 36;
            }
            if (field3158 == 3) {
                if ((unsigned short)RandomRange(0, 100) <= 50) {
                    spawn.type = 34;
                } else {
                    spawn.type = 36;
                }
            }
            spawn.x = (double)(int(positionX) + (20 - (unsigned short)RandomRange(0, 40)) * facing);
            spawn.y = (double)(int(field0028) - (unsigned short)RandomRange(0, 90));
            spawn.group = 2;
            spawn.layer = 1;
            contextOwner->EmitEffect(&spawn);
            field315c = 2;
        }
    }
}

void Character15::Slot01()
{
    SurfaceRect destination, source;
    PatternFrame frame;
    ++field3164;
    if (field3164 > 29) {
        field3164 = 0;
    }
    if (field3158 == 0) {
        frame = patterns[39].frames[0];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(11 - frame.u, 196 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 310) - frame.width, 196 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3158 == 1) {
        frame = patterns[40].frames[field3164 / 6];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(11 - frame.u, 196 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 310) - frame.width, 196 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3158 == 2) {
        frame = patterns[41].frames[field3164 / 6];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(11 - frame.u, 196 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 310) - frame.width, 196 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3158 == 3) {
        frame = patterns[42].frames[field3164 / 6];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(11 - frame.u, 196 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 310) - frame.width, 196 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3168 > 0) {
        frame = patterns[43].frames[0];
        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, frame.width, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 271) - frame.width, 31 - frame.v, frame.width, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
    if (field3168 > 0) {
        frame = patterns[44].frames[0];
        source = MakeSurfaceRect(0, 0, (field3168 * frame.width) / 4500, frame.height);
        if (player == 0) {
            destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, (field3168 * frame.width) / 4500, frame.height);
        } else {
            destination = MakeSurfaceRect((frame.u + 271) - (field3168 * frame.width) / 4500, 31 - frame.v, (field3168 * frame.width) / 4500, frame.height);
        }
        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
    }
}
