// Nanase foreground gauge and charge overlay, reconstructed in natural C++.
#include "CharacterViews.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);
struct Character00RenderFields {
    unsigned char inherited[0x3138];
    int field3138, field313c, field3140, field3144, field3148;
};
#define C00 (reinterpret_cast<Character00RenderFields *>(this))

void Character00::Slot01()
{
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            if (C00->field3148 > 0) {
                frame = patterns[43].frames[0];
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
            if (C00->field3148 > 0) {
                frame = patterns[44].frames[0];
                source = MakeSurfaceRect(0, 0,
                        C00->field3148 * frame.width / 3000, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v,
                            C00->field3148 * frame.width / 3000, frame.height);
                } else {
                    destination = MakeSurfaceRect((frame.u + 271) - C00->field3148 * frame.width / 3000,
                                                  31 - frame.v, C00->field3148 * frame.width / 3000, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
        }
    }
}

#undef C00
