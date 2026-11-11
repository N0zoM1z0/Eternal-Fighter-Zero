// Character04 four-layer native resource indicator with mode-dependent
// full sprites and separately clipped overlays.
#include "CharacterViews.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

struct Character04RenderFields {
    unsigned char base[0x3138];
    int field3138, field313c, field3140, field3144, field3148;
};
#define C04 (reinterpret_cast<Character04RenderFields *>(this))

void Character04::Slot01()
{
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            if (C04->field3148 > 0 && C04->field3144 != 3) {
                frame = patterns[41].frames[0];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v,
                                                  frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect((frame.u + 271) - frame.width,
                                                  31 - frame.v, frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
            if (C04->field3144 == 3) {
                frame = patterns[42].frames[0];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v,
                                                  frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect((frame.u + 271) - frame.width,
                                                  31 - frame.v, frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
            if (C04->field3148 > 0 && C04->field3144 != 3) {
                frame = patterns[43].frames[0];
                source = MakeSurfaceRect(0, 0,
                            C04->field3148 * frame.width / 10000, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v,
                            C04->field3148 * frame.width / 10000, frame.height);
                } else {
                    destination = MakeSurfaceRect((frame.u + 271) - C04->field3148 * frame.width / 10000,
                                                  31 - frame.v, C04->field3148 * frame.width / 10000, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
            if (C04->field3144 == 3) {
                frame = patterns[44].frames[0];
                source = MakeSurfaceRect(0, 0,
                            C04->field3148 * frame.width / 1200, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v,
                            C04->field3148 * frame.width / 1200, frame.height);
                } else {
                    destination = MakeSurfaceRect((frame.u + 271) - C04->field3148 * frame.width / 1200,
                                                  31 - frame.v, C04->field3148 * frame.width / 1200, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
        }
    }
}
#undef C04
