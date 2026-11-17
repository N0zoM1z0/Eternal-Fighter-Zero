// Natural C++ reconstruction of Scene6::ReloadSelectedPreview at 0x0075D400.
// The original builds system\<name>\<name>.dat and loads its 8-bit preview,
// palette, indexed color key and persistent per-character statistics.
#include "Engine.h"
#include <cstring>

extern const char scene6PreviewPrefix[];
extern const char scene6PreviewDirectorySeparator[];
extern const char scene6PreviewDataExtension[];
extern const char scene6PreviewBitmapExtension[];

typedef char Scene6PreviewSizeMustMatch[(sizeof(Scene6) == 0x760) ? 1 : -1];

void Scene6::ReloadSelectedPreview()
{
    char path[52];
    std::strcpy(path, scene6PreviewPrefix);
    std::strcat(path, previewNames[previewSelection]);
    std::strcat(path, scene6PreviewDirectorySeparator);
    std::strcat(path, previewNames[previewSelection]);
    if (1) {
        std::strcat(path, scene6PreviewDataExtension);
        contextOwner->LoadObjectFile(&previewSurface, path, 0, 0xd6);
        videoOwner->LoadPalette(palette, path, 0, 0xd6, 0x28);
    } else {
        std::strcat(path, scene6PreviewBitmapExtension);
        videoOwner->LoadSurface(&previewSurface, path, 0xd6);
        videoOwner->LoadBitmapPalette(palette, path, 0, 0xd6, 0x28);
    }
    previewColorKey = videoOwner->SurfaceProperty(previewSurface);
    previewStatistics.Read(previewNames[previewSelection]);
}
