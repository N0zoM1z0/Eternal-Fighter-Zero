// Nayuki native render layer Slot01, original 0x00463DD0 (939 bytes).
#include "CharacterViews.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Character10::Slot01()
{
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            frame = patterns[44].frames[0];
            source = MakeSurfaceRect(0, 0, frame.width, frame.height);
            if (player == 0) {
                destination = MakeSurfaceRect(2 - frame.u, 191 - frame.v, frame.width, frame.height);
            } else {
                destination = MakeSurfaceRect(frame.u + 280, 191 - frame.v, frame.width, frame.height);
            }
            videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);

            frame = patterns[34 + field3148].frames[0];
            source = MakeSurfaceRect(0, 0, frame.width, frame.height);
            if (player == 0) {
                destination = MakeSurfaceRect(2 - frame.u, 191 - frame.v, frame.width, frame.height);
            } else {
                destination = MakeSurfaceRect(280 - frame.u, 191 - frame.v, frame.width, frame.height);
            }
            videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
        }
    }
}
