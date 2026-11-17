// Fade the palette toward its inverted colors, preserving the original
// DirectDraw 255-entry update and the three RGB channel arithmetic paths.
// Native function: 0x0040C070, 321 bytes.
#include "Engine.h"

void Video::InvertPalette(const unsigned char *palette,
                          unsigned char begin, unsigned char end,
                          unsigned char amount)
{
    PALETTEENTRY entries[256];
    int i;
    paletteInterface->GetEntries(0, 0, 255, entries);
    for (i = begin; i < end; ++i) {
        entries[i].peRed =
            ((255 - 2 * palette[i * 4]) * amount) / 100 +
            palette[i * 4];
        entries[i].peGreen =
            ((255 - 2 * palette[i * 4 + 1]) * amount) / 100 +
            palette[i * 4 + 1];
        entries[i].peBlue =
            ((255 - 2 * palette[i * 4 + 2]) * amount) / 100 +
            palette[i * 4 + 2];
    }
    paletteInterface->SetEntries(0, 0, 255, entries);
}
