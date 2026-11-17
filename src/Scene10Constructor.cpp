// Staff roll scene resource constructor, original 0x007758B0.
#include "Engine.h"

extern const char staffDatSurface[], staffDatPalette[];
extern const char staffBmpSurface[], staffBmpPalette[];
typedef char Scene10CtorLayout[(sizeof(Scene10) == 0x448) ? 1 : -1];

Scene10::Scene10(HWND handle, Secondary **first, Secondary **second, Context *context,
                 Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    if (true) {
        contextOwner->LoadObjectFile(&staffSurface, staffDatSurface, 0, 1);
        videoOwner->LoadPalette(palette, staffDatPalette, 0, 1, 254);
    } else {
        videoOwner->LoadSurface(&staffSurface, staffBmpSurface, 1);
        videoOwner->LoadBitmapPalette(palette, staffBmpPalette, 0, 1, 254);
    }
    staffTime = 0.0;
    exitRequested = 0;
}
