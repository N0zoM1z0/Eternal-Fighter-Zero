// Staff roll's DirectDraw release owner, native 0x007759A0.
#include "Engine.h"
typedef char Scene10DtorLayout[(sizeof(Scene10) == 0x448) ? 1 : -1];

Scene10::~Scene10()
{
    if (staffSurface) {
        staffSurface->Release();
        staffSurface = 0;
    }
}
