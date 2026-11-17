// Scene6 decimal glyph painter, native 0x0075D260.
// Blit each digit right-to-left from a fixed 12x14 sprite at row 240.
#include "Engine.h"

typedef char Scene6NumberLayoutMustMatch[(sizeof(Scene6) == 0x760) ? 1 : -1];

void Scene6::DrawConfigNumber(int x, int y, unsigned int value)
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
        work.source.top = 240;
        work.source.bottom = 254;
        work.source.left = work.digit * 16 + 2;
        work.source.right = work.digit * 16 + 14;
        work.destination.top = y;
        work.destination.bottom = y + 14;
        work.destination.right = work.edge - 2;
        work.destination.left = work.edge - 14;
        videoOwner->DrawSurface(work.destination, numberSurface,
                                work.source, numberColorKey, 0);
        work.edge = work.edge - 10;
        work.remaining = work.remaining / 10;
    } while (work.remaining > 0);
}
