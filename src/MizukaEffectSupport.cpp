// Shared pose-angle and context fade controls used by Mizuka local effects.
#include "Engine.h"
#include <cmath>

double SecondaryPose::VectorAngle(double x, double y)
{
    return std::atan2(y, x) * 57.29579143313326;
}

void Context::StartFade(int attack, int hold, int release)
{
    fadeDirection = 1;
    fadeAttack = attack;
    fadeHold = hold;
    fadeRelease = release;
}
