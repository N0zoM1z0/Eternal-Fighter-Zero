// Shiori initialization, pose reset, effect ownership and character meter rendering.
#include "CharacterViews.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Character08::InitializeState()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field3148 = 0;
    field314c = 0;
    field3150 = 0;
    field3154 = 0;
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
        field3158[i] = 0;
        field3258[i] = 0;
        field3358[i] = 0;
    }
    Secondary::InitializeState();
}

void Character08::ResetPose()
{
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    Secondary::ResetPose();
}

void Character08::RemoveLocalEffect(short slot)
{
    field3158[slot] = 0;
    field3258[slot] = 0;
    field3358[slot] = 0;
    Secondary::RemoveLocalEffect(slot);
}

void Character08::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}

void Character08::Slot01()
{
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            if (field314c > 0) {
                frame = patterns[43].frames[0];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect(frame.u + 271 - frame.width, 31 - frame.v, frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
            if (field314c > 0) {
                frame = patterns[44].frames[0];
                source = MakeSurfaceRect(0, 0, (field314c * frame.width) / 3600, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, (field314c * frame.width) / 3600, frame.height);
                } else {
                    destination = MakeSurfaceRect(frame.u + 271 - (field314c * frame.width) / 3600,
                    31 - frame.v, (field314c * frame.width) / 3600, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
        }
    }
}

void Character08::Slot03()
{
    UpdateLocomotionState();
}
