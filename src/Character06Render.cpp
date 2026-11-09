// Original Nagamori meter overlay, using both animation-bank sprites.
#include "CharacterViews.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Character06::Slot01()
{
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            if (field3150 > 0) {
                frame = patterns[43].frames[0];
                source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, frame.width, frame.height);
                } else {
                    destination = MakeSurfaceRect(frame.u + 271 - frame.width, 31 - frame.v, frame.width, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
            if (field3150 > 0) {
                frame = patterns[44].frames[0];
                source = MakeSurfaceRect(0, 0, (field3150 * frame.width) / 1200, frame.height);
                if (player == 0) {
                    destination = MakeSurfaceRect(49 - frame.u, 31 - frame.v, (field3150 * frame.width) / 1200, frame.height);
                } else {
                    destination = MakeSurfaceRect(frame.u + 271 - (field3150 * frame.width) / 1200,
                    31 - frame.v, (field3150 * frame.width) / 1200, frame.height);
                }
                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, 0);
            }
        }
    }
}
