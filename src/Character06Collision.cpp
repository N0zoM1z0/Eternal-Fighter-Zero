// Nagamori effect-pool proximity test, original owner 0x004AE1D0.
#include "../workbench/nagamori-helper/CharacterViews.h"
#include <math.h>

void Character06::MarkEffectCollision(short x, short y, short width, short height)
{
    int i = effectRead;
    while (i != effectWrite) {
        if (effectActive[i] != 0 &&
            fabs((double)(int)x - effects[i].x) < (double)(int)width &&
            fabs((double)(int)y - effects[i].y) < (double)(int)height) {
            field316c[i] = 1;
        }
        ++i;
        if (i >= 64) i = 0;
    }
}
