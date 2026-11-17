// Scene10 staff-scroll frame renderer, original 0x00775B80.
#include "Engine.h"

extern SurfaceRect __cdecl MakeSurfaceRect(int left, int top, int width, int height);

void Scene10::Slot0()
{
    if (staffTime > 2280.0) {
        videoOwner->DrawSurface(MakeSurfaceRect(0, 0, 320, 240), staffSurface,
                                MakeSurfaceRect(0, 2280, 320, 240), 0, 0);
    } else {
        videoOwner->DrawSurface(MakeSurfaceRect(0, 0, 320, 240), staffSurface,
                                MakeSurfaceRect(0, (int)staffTime, 320, 240), 0, 0);
    }
    videoOwner->Present();
}
