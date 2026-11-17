// Scene9 winner/result number glyph drawing, native 0x00774A10.
// 16-pixel-wide digits in the sprite sheet's row 455..474, right-to-left.
#include "Engine.h"

typedef char Scene9ResultNumberLayout[(sizeof(Scene9)==0x474) ? 1 : -1];

void Scene9::DrawResultNumber(int x, int y, unsigned int value)
{
    struct NumberWork {
        SurfaceRect source;
        unsigned int digit;
        SurfaceRect destination;
        unsigned int remaining;
        int edge;
    } work;
    work.remaining = value;
    work.edge = x;
    do {
        work.digit = work.remaining % 10;
        work.source.top = 0x1c7;
        work.source.bottom = 0x1da;
        work.source.left = work.digit << 4;
        work.source.right = (work.digit + 1) << 4;
        work.destination.top = y;
        work.destination.bottom = y + 0x13;
        work.destination.right = work.edge;
        work.destination.left = work.edge - 0x10;
        videoOwner->DrawSurface(work.destination, resultSurface,
                                work.source, contextOwner->colorKey, 0);
        work.edge -= 0xe;
        work.remaining /= 10;
    } while (work.remaining > 0);
}
