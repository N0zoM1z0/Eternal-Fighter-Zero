// Shared facing update with the original equal-position behavior.
#include "Engine.h"

int Secondary::FaceOpponent()
{
    char previous = facing;
    if (field0020 < (*opponentSlot)->field0020) {
        facing = 1;
        return facing != previous;
    }
    if (field0020 > (*opponentSlot)->field0020) {
        facing = -1;
        return facing != previous;
    }
    return 0;
}
