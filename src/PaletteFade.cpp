// Original palette interpolation and signed fade-direction state machine.
#include "Engine.h"

void Video::DarkenPalette(const unsigned char *palette, unsigned char begin, unsigned char end, unsigned char amount)
{
    PALETTEENTRY entries[256];
    int i;
    paletteInterface->GetEntries(0, 0, 255, entries);
    for (i = begin; i < end; ++i) {
        entries[i].peRed = palette[i * 4] * amount / 100;
        entries[i].peGreen = palette[i * 4 + 1] * amount / 100;
        entries[i].peBlue = palette[i * 4 + 2] * amount / 100;
    }
    paletteInterface->SetEntries(0, 0, 255, entries);
}

void Video::LightenPalette(const unsigned char *palette, unsigned char begin, unsigned char end, unsigned char amount)
{
    PALETTEENTRY entries[256];
    int i;
    paletteInterface->GetEntries(0, 0, 255, entries);
    for (i = begin; i < end; ++i) {
        entries[i].peRed = (255 - palette[i * 4]) * (100 - amount) / 100 + palette[i * 4];
        entries[i].peGreen = (255 - palette[i * 4 + 1]) * (100 - amount) / 100 + palette[i * 4 + 1];
        entries[i].peBlue = (255 - palette[i * 4 + 2]) * (100 - amount) / 100 + palette[i * 4 + 2];
    }
    paletteInterface->SetEntries(0, 0, 255, entries);
}

void Context::UpdatePaletteFade()
{
    if (fadeDirection == 1) {
        if (fadeAttack > 0) {
            fadeLevel = (100.0 - fadeLevel) / fadeAttack + fadeLevel;
            if (fadeLevel > 100.0) fadeLevel = 100.0;
            if (fadeLevel > 0.0) videoOwner->LightenPalette(this->characterPalette, 1, 255, 100 - (int)fadeLevel);
            --fadeAttack;
        } else {
            if (fadeHold > 0) --fadeHold;
            else {
                if (fadeLevel > 0.0) {
                    fadeLevel = fadeLevel - 100.0 / fadeRelease;
                    if (fadeLevel <= 0.0) fadeLevel = 0.0;
                    videoOwner->LightenPalette(this->characterPalette, 1, 255, 100 - (int)fadeLevel);
                } else fadeDirection = 0;
            }
        }
    } else if (fadeDirection == -1) {
        if (fadeAttack > 0) {
            fadeLevel = fadeLevel - (fadeLevel + 100.0) / fadeAttack;
            if (fadeLevel < -100.0) fadeLevel = -100.0;
            if (fadeLevel < 0.0) videoOwner->DarkenPalette(this->characterPalette, 1, 255, (int)fadeLevel + 100);
            --fadeAttack;
        } else {
            if (fadeHold > 0) --fadeHold;
            else {
                if (fadeLevel < 0.0) {
                    fadeLevel = 100.0 / fadeRelease + fadeLevel;
                    if (fadeLevel >= 0.0) fadeLevel = 0.0;
                    videoOwner->DarkenPalette(this->characterPalette, 1, 255, (int)fadeLevel + 100);
                } else fadeDirection = 0;
            }
        }
    }
}
