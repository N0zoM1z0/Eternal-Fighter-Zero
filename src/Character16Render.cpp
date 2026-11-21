// Akiko's multi-layer gauge, charge meter and timed overlay renderer.
#include "CharacterViews.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Character16::Slot01()
{
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            if (field3148 > 0) {
                frame = patterns[43].frames[0];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(0x31 - frame.u, 0x1f - frame.v,
                                                  frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect((frame.u + 0x10f) - frame.width,
                                                  0x1f - frame.v, frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
            if (field3148 > 0) {
                frame = patterns[44].frames[0];
                source = MakeSurfaceRect(0, 0, field3148 * frame.width / 1000, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(0x31 - frame.u, 0x1f - frame.v,
                                                  field3148 * frame.width / 1000, frame.height);
                } else {
                    destination = MakeSurfaceRect((frame.u + 0x10f) - field3148 * frame.width / 1000,
                                                  0x1f - frame.v, field3148 * frame.width / 1000, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
            if (field0160 > 0) {
                frame = patterns[40].frames[field3154];
                if (field3160 > 0) frame = patterns[40].frames[10];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(0x5c - frame.u, 0xc5 - frame.v,
                                                  frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect(0x10d - frame.u, 0xc5 - frame.v,
                                                  frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);

                frame = patterns[40].frames[field3158];
                if (field3160 > 0) frame = patterns[40].frames[10];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(0x4a - frame.u, 0xc5 - frame.v,
                                                  frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect(0xfb - frame.u, 0xc5 - frame.v,
                                                  frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);

                frame = patterns[40].frames[field315c];
                if (field3160 > 0) frame = patterns[40].frames[10];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(0x38 - frame.u, 0xc5 - frame.v,
                                                  frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect(0xe9 - frame.u, 0xc5 - frame.v,
                                                  frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);

                frame = patterns[41].frames[0];
                if (field3160 > 0) frame = patterns[41].frames[1];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(0x24 - frame.u, 0xb0 - frame.v,
                                                  frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect(0xd5 - frame.u, 0xb0 - frame.v,
                                                  frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);

                if (field3160 > 0) {
                    frame = patterns[42].frames[0];
                    source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                    if (player == 0) {
                        destination = MakeSurfaceRect(0x1f + (int)(field3160 * 0.001) - frame.u,
                                                      0xb9 - frame.v, frame.width, frame.height);
                    } else {
                        destination = MakeSurfaceRect(0xda - (int)(field3160 * 0.001) - frame.u,
                                                      0xb9 - frame.v, frame.width, frame.height);
                    }
                    videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
                }
            }
        }
    }
}
