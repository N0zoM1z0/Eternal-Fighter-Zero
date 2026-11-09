// Shared facing update with the original equal-position behavior.
#include "Engine.h"

int Secondary::FaceOpponent()
{
    char previous = facing;
    if (positionX < (*opponentSlot)->positionX) {
        facing = 1;
        return facing != previous;
    }
    if (positionX > (*opponentSlot)->positionX) {
        facing = -1;
        return facing != previous;
    }
    return 0;
}
