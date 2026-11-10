// Reorient a Secondary toward an explicit world-space X coordinate.
// Returns true only when the facing byte changes.
#include "Engine.h"

int Secondary::FacePosition(double x)
{
    char previous = facing;
    if (positionX < x) {
        facing = 1;
        return facing != previous;
    }
    if (positionX > x) {
        facing = -1;
        return facing != previous;
    }
    return 0;
}
