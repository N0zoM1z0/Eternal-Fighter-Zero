// Palette submission and the complete original presentation wrapper.
#include "Engine.h"

int Video::ApplyPalette(unsigned char *colors)
{
    paletteInterface->SetEntries(0, 0, 255, reinterpret_cast<PALETTEENTRY *>(colors));
    return 1;
}

int Video::ApplyPaletteRange(unsigned char *colors, unsigned char first, unsigned char count)
{
    paletteInterface->SetEntries(0, first, count, reinterpret_cast<PALETTEENTRY *>(colors + first * 4));
    return 1;
}

int Video::ClearPaletteRGB(unsigned char *colors)
{
    for (int i = 0; i < 256; ++i) {
        colors[i * 4] = 0;
        colors[i * 4 + 1] = 0;
        colors[i * 4 + 2] = 0;
    }
    return 1;
}

int Video::Present()
{
    HRESULT result;
    if (flag0004) ConvertBackBuffer();
    result = primarySurface->Flip(0, 1);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }
    return 1;
}
