// Palette file conversion and original nearest-color lookup construction.
#include "Engine.h"

Video::Video()
{
    flag0004 = 0;
    for (int i = 0; i < 512; ++i) squaredDifference[i] = (i - 256) * (i - 256) / 4;
}

int Video::LoadBitmapPalette(unsigned char *palette, const char *path, int source, int destination, int count)
{
    HANDLE file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    int offset;
    {
        DWORD size = GetFileSize(file, 0);
        DWORD bytesRead;
        {
            unsigned char *buffer = new unsigned char[size];
            ReadFile(file, buffer, size, &bytesRead, 0);
            offset = 54;
            for (int i = 0; i < count; ++i) {
                palette[(i + destination) * 4 + 2] = buffer[(i + source) * 4 + offset];
                palette[(i + destination) * 4 + 1] = buffer[(i + source) * 4 + (offset + 1)];
                palette[(i + destination) * 4] = buffer[(i + source) * 4 + (offset + 2)];
                palette[(i + destination) * 4 + 3] = 0;
            }
            CloseHandle(file);
            delete[] buffer;
            return 1;
        }
    }
}

int Video::LoadPalette(unsigned char *palette, const char *path, int source, int destination, int count)
{
    HANDLE file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (file == INVALID_HANDLE_VALUE) { CloseHandle(file); return 0; }
    int offset;
    {
        DWORD size = GetFileSize(file, 0);
        DWORD bytesRead;
        {
            unsigned char *buffer = new unsigned char[size];
            ReadFile(file, buffer, size, &bytesRead, 0);
            offset = 1;
            for (int i = 0; i < count; ++i) {
                palette[(i + destination) * 4 + 2] = buffer[(i + source) * 3 + offset];
                palette[(i + destination) * 4 + 1] = buffer[(i + source) * 3 + (offset + 1)];
                palette[(i + destination) * 4] = buffer[(i + source) * 3 + (offset + 2)];
                palette[(i + destination) * 4 + 3] = 0;
            }
            CloseHandle(file);
            delete[] buffer;
            return 1;
        }
    }
}

unsigned char Video::SurfaceProperty(IUnknown *surface)
{
    unsigned int value;
    int offset = 54; // Retain the original unused assignment.
    HRESULT result;
    {
        DDSURFACEDESC lock;
        lock.dwSize = sizeof(DDSURFACEDESC);
        result = reinterpret_cast<IDirectDrawSurface *>(surface)->Lock(0, &lock, DDLOCK_WAIT, 0);
        value = *static_cast<unsigned int *>(lock.lpSurface);
        value &= 0xff;
        reinterpret_cast<IDirectDrawSurface *>(surface)->Unlock(lock.lpSurface);
        return value;
    }
}

#define COLOR_DISTANCE(r,g,b) \
    (*(v3 + v12 - (r)) + *(v3 + v9 - (g)) + *(v3 + v20 - (b)))

// Numeric local names and declaration order reproduce the VC7.1 /Od layout.
// They describe reconstruction variables, not recovered original identifiers.
void Video::BuildBlendTables(unsigned char *palette)
{
    unsigned short v0; // Best saturated-sum distance.
    unsigned char *v1; // Inner blue cursor.
    unsigned short v2; // Saturated red sum.
    unsigned short *v3; // Signed-difference distance table midpoint.
    unsigned short v4; // Inner pair limit.
    unsigned char *v5; // Red cursor before the first entry.
    unsigned short v6; // Saturated green sum.
    unsigned short v7; // Mean blue channel.
    unsigned char *v8; // Outer red cursor.
    unsigned short v9; // Candidate green channel.
    unsigned char *v10; // Inner green cursor.
    unsigned char *v11; // Outer green cursor.
    unsigned short v12; // Candidate red channel.
    unsigned char *v13; // Green cursor before the first entry.
    unsigned short v14; // Mean red channel.
    unsigned char *v15; // Inner red cursor.
    unsigned short v16; // Saturated blue sum.
    unsigned char *v17; // Blue cursor before the first entry.
    unsigned short v18; // Best mean-color distance.
    unsigned char *v19; // Candidate red cursor.
    unsigned short v20; // Candidate blue channel.
    unsigned char *v21; // Saturated-sum output row.
    unsigned char *v22; // Outer blue cursor.
    unsigned char *v23; // Candidate green cursor.
    unsigned char *v24; // Candidate blue cursor.
    unsigned char *v25; // Mean-color output row.
    unsigned short v26; // Mean green channel.
    {
        unsigned short i;
        {
            unsigned char index0, index1, index2; // Mirror column, paired entry, candidate entry.
            v3 = squaredDifference + 256;
            v25 = reinterpret_cast<unsigned char *>(paletteEntries) + 0x300;
            v21 = reinterpret_cast<unsigned char *>(meanBlend) + 0xff00;
            v5 = palette - 4;
            v8 = v5;
            v13 = palette - 3;
            v11 = v13;
            v17 = palette - 2;
            v22 = v17;
            // Fill the lower triangle, including row 255 but excluding column 255.
            for (i = 0; i < 256; ++i) {
                v4 = i + 1;
                if (v4 > 255) v4 = 255;
                v25 += 256;
                v21 += 256;
                v8 += 4; v11 += 4; v22 += 4;
                v15 = v5; v10 = v13; v1 = v17;
                for (index1 = 0; index1 < v4; ++index1) {
                    v2 = *v8 + *(v15 += 4);
                    v6 = *v11 + *(v10 += 4);
                    v16 = *v22 + *(v1 += 4);
                    v14 = v2 >> 1; v26 = v6 >> 1; v7 = v16 >> 1;
                    v18 = 40000;
                    v0 = v18;
                    if (v2 > 254) v2 = 254;
                    if (v6 > 254) v6 = 254;
                    if (v16 > 254) v16 = 254;
                    v19 = v5 + 4;
                    v23 = v13 + 4;
                    v24 = v17 + 4;
                    for (index2 = 1; index2 < 255; ++index2) {
                        v19 += 4; v12 = *v19;
                        v23 += 4; v9 = *v23;
                        v24 += 4; v20 = *v24;
                        if (COLOR_DISTANCE(v14,v26,v7) < v18) {
                            v18 = COLOR_DISTANCE(v14,v26,v7);
                            v25[index1] = index2;
                        }
                        if (COLOR_DISTANCE(v2,v6,v16) < v0) {
                            v0 = COLOR_DISTANCE(v2,v6,v16);
                            v21[index1] = index2;
                        }
                    }
                }
            }
            // Mirror entries 0..254; the final column retains its previous contents.
            for (index0 = 0; index0 < 255; ++index0) {
                for (i = 0; i < index0; ++i) {
                    (reinterpret_cast<unsigned char *>(meanBlend) + i * 256)[index0] =
                    (reinterpret_cast<unsigned char *>(meanBlend) + index0 * 256)[i];
                    (reinterpret_cast<unsigned char *>(sumBlend) + i * 256)[index0] =
                    (reinterpret_cast<unsigned char *>(sumBlend) + index0 * 256)[i];
                }
            }
        }
    }
}
#undef COLOR_DISTANCE
