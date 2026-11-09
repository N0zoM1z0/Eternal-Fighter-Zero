// Complete character image, animation and sound resource loading.
#include "Engine.h"
#include "PatternReader.h"
#include <cstring>
#include <cstdlib>
extern const char characterImagesDatSeparator[], characterImagesDatExtension[];
extern const char characterImagesAltSeparator[], characterImagesAltExtension[];
extern const char characterImagesBmpSeparator[], characterImagesLargePrefix[], characterImagesLargeExtension[];
extern const char characterImagesHundredZero[], characterImagesTenZero[], characterImagesBmpExtension[];
extern const char characterImagesBmpAltSeparator[], characterImagesBmpAltExtension[], characterImagesPaletteBitmap[];
extern const char characterPatternSeparator[], characterPatternExtension[];
extern const char characterWaveSeparator[], characterWaveZero[], characterWaveExtension[];

void Secondary::LoadImages()
{
    char path[32];
    char digits[8];
    surfaces = new IUnknown *[surfaceCount + 1];
    if (true) {
        HANDLE file;
        {
            int consumed;
            {
                int offset = 0;
                {
                    DWORD size;
                    {
                        DWORD transferred;
                        {
                            unsigned char *data;
                            {
                                int i;
                                {
                                    char error[32];
                                    std::strcpy(path, resourceName);
                                    std::strcat(path, characterImagesDatSeparator);
                                    std::strcat(path, resourceName);
                                    std::strcat(path, characterImagesDatExtension);
                                    file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                                    size = GetFileSize(file, 0);
                                    data = new unsigned char[size];
                                    ReadFile(file, data, size, &transferred, 0);
                                    offset = data[0] * 3 + 1;
                                    for (i = 0; i <= surfaceCount; ++i) {
                                        consumed = videoOwner->DecodeCharacterSurface(&surfaces[i], data + offset, 128, player * 40 + 0x5f);
                                        if (consumed == 0) {
                                            _itoa(i, error, 10);
                                            MessageBoxA(0, error, 0, 0);
                                        } else offset += consumed;
                                    }
                                    CloseHandle(file);
                                    delete[] data;
                                    if (contextOwner->alternateStyle[player] != 0) {
                                        std::strcpy(path, resourceName);
                                        std::strcat(path, characterImagesAltSeparator);
                                        std::strcat(path, resourceName);
                                        _itoa(paletteIndex + 1, digits, 10);
                                        std::strcat(path, digits);
                                        std::strcat(path, characterImagesAltExtension);
                                        videoOwner->LoadPalette(contextOwner->characterPalette, path, 0, player * 40 + 0x5f, 40);
                                    } else {
                                        videoOwner->LoadPalette(contextOwner->characterPalette, path, paletteIndex * 40, player * 40 + 0x5f, 40);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        for (int i = 0; i <= surfaceCount; ++i) {
            std::strcpy(path, resourceName);
            std::strcat(path, characterImagesBmpSeparator);
            if (i >= 1000) {
                std::strcat(path, characterImagesLargePrefix);
                _itoa(i, digits, 10);
                std::strcat(path, digits);
                std::strcat(path, characterImagesLargeExtension);
                videoOwner->LoadBitmapSurface(&surfaces[i], path, player * 40 + 0x5f);
            } else {
                if (i < 100) std::strcat(path, characterImagesHundredZero);
                if (i < 10) std::strcat(path, characterImagesTenZero);
                _itoa(i, digits, 10);
                std::strcat(path, digits);
                std::strcat(path, characterImagesBmpExtension);
                videoOwner->LoadBitmapSurface(&surfaces[i], path, player * 40 + 0x5f);
            }
        }
        if (contextOwner->alternateStyle[player] != 0) {
            std::strcpy(path, resourceName);
            std::strcat(path, characterImagesBmpAltSeparator);
            std::strcat(path, resourceName);
            _itoa(paletteIndex + 1, digits, 10);
            std::strcat(path, digits);
            std::strcat(path, characterImagesBmpAltExtension);
            videoOwner->LoadPalette(contextOwner->characterPalette, path, 0, player * 40 + 0x5f, 40);
        } else {
            std::strcpy(path, resourceName);
            std::strcat(path, characterImagesPaletteBitmap);
            videoOwner->LoadBitmapPalette(contextOwner->characterPalette, path, paletteIndex * 40, player * 40 + 0x5f, 40);
        }
    }
    colorKey = videoOwner->SurfaceProperty(surfaces[0]);
}

void Secondary::LoadPatterns()
{
    int count;
    char path[32];
    std::strcpy(path, resourceName);
    std::strcat(path, characterPatternSeparator);
    std::strcat(path, resourceName);
    std::strcat(path, characterPatternExtension);
    PatternReader reader(path, 1);
    count = reader.ReadInt();
    {
        int id;
        {
            int frames;
            {
                int i;
                {
                    int j;
                    {
                        PatternFrame *frame;
                        {
                            SecondaryFrame *extra;
                            {
                                int k;
                                for (i = 0; i < count; ++i) {
                                    id = reader.ReadInt();
                                    sequences[id].field0000 = reader.ReadInt();
                                    sequences[id].field0002 = reader.ReadInt();
                                    patterns[id].count = reader.ReadInt();
                                    frames = patterns[id].count;
                                    sequences[id].Allocate(frames);
                                    patterns[id].Allocate(frames);
                                    for (j = 0; j < frames; ++j) {
                                        frame = &patterns[id].frames[j];
                                        extra = &sequences[id].data[j];
                                        frame->duration = (short)reader.ReadInt() * 3;
                                        frame->texture = reader.ReadInt();
                                        frame->width = reader.ReadInt();
                                        frame->height = reader.ReadInt();
                                        frame->u = reader.ReadInt();
                                        frame->v = reader.ReadInt();
                                        extra->damage = reader.ReadInt();
                                        extra->attackFlags = reader.ReadInt();
                                        extra->airHitState = reader.ReadInt();
                                        extra->frameFlags = reader.ReadInt();
                                        extra->airActionLockFrames = reader.ReadInt();
                                        extra->guardDamage = reader.ReadInt();
                                        extra->hitMeterGain = reader.ReadInt();
                                        extra->guardMeterGain = reader.ReadInt();
                                        extra->outgoingPushbackVelocityY = reader.ReadShort();
                                        extra->outgoingPushbackVelocityY = extra->outgoingPushbackVelocityY / 100.0f;
                                        extra->outgoingPushbackVelocityX = reader.ReadShort();
                                        extra->outgoingPushbackVelocityX = extra->outgoingPushbackVelocityX / -100.0f;
                                        extra->hitEffectPalette = reader.ReadShort();
                                        extra->hitEffectType = reader.ReadShort();
                                        extra->attackerHitstopFrames = reader.ReadInt();
                                        extra->defenderHitstopFrames = reader.ReadInt();
                                        extra->comboDamageScale = reader.ReadInt();
                                        extra->groundHitState = reader.ReadInt();
                                        reader.Read(&extra->bodyBox, 16);
                                        for (k = 0; k < 2; ++k) reader.Read(&extra->hurtBoxes[k], 16);
                                        reader.Read(&extra->attackBoxes[0], 16);
                                        for (k = 2; k < 5; ++k) reader.Read(&extra->hurtBoxes[k], 16);
                                        for (k = 1; k < 4; ++k) reader.Read(&extra->attackBoxes[k], 16);
                                    }
                                }
                                for (i = 0; i < 64; ++i) effects[i].patterns = patterns;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Secondary::LoadSounds()
{
    char path[32];
    char digits[8];
    for (int i = 0; i < 50; ++i) {
        std::strcpy(path, resourceName);
        std::strcat(path, characterWaveSeparator);
        if (i < 10) std::strcat(path, characterWaveZero);
        _itoa(i, digits, 10);
        std::strcat(path, digits);
        std::strcat(path, characterWaveExtension);
        soundSlots[i] = audioOwner->LoadWave(path);
        audioOwner->SetSoundVolume(soundSlots[i], -500);
    }
}

void SecondarySequence::Allocate(int count)
{
    if (count > 0) data = new SecondaryFrame[count];
}
