// Original background image and animation-pattern loading.
#include "Backgrounds.h"
#include "PatternReader.h"
#include <cstring>
#include <cstdlib>
extern const char bgImagePrefix[], bgImagePrefixZero[], bgImageSeparator[];
extern const char bgImageSeparatorZero[], bgImageSeparatorTwoZeros[], bgImageDat[];
extern const char bgBitmapPrefix[], bgBitmapPrefixZero[], bgBitmapSeparator[];
extern const char bgBitmapSeparatorZero[], bgBitmapSeparatorTwoZeros[], bgBitmapExtension[];
extern const char bgPatternPrefix[], bgPatternPrefixZero[], bgPatternSeparator[];
extern const char bgPatternSeparatorZero[], bgPatternExtension[];

void BattleBackground::LoadImages()
{
    char digits[8];
    {
        char path[32];
        {
            struct ImageReadWork {
                int bitmapIndex;
                unsigned char *data;
                DWORD transferred, size;
                HANDLE file;
                int index;
            } work;
            if (true) {
                for (work.index = 0; work.index <= lastSurface; ++work.index) {
                    if (stage >= 10) std::strcpy(path, bgImagePrefix);
                    else std::strcpy(path, bgImagePrefixZero);
                    _itoa(stage, digits, 10);
                    std::strcat(path, digits);
                    if (work.index >= 100) std::strcat(path, bgImageSeparator);
                    else if (work.index >= 10) std::strcat(path, bgImageSeparatorZero);
                    else std::strcat(path, bgImageSeparatorTwoZeros);
                    _itoa(work.index, digits, 10);
                    std::strcat(path, digits);
                    std::strcat(path, bgImageDat);
                    work.file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                    work.size = GetFileSize(work.file, 0);
                    work.data = new unsigned char[work.size];
                    ReadFile(work.file, work.data, work.size, &work.transferred, 0);
                    videoOwner->DecodeSurface(&surfaces[work.index], work.data + work.data[0] * 3 + 1, 0, 1);
                    CloseHandle(work.file);
                    delete[] work.data;
                }
            } else {
                for (work.bitmapIndex = 0; work.bitmapIndex <= lastSurface; ++work.bitmapIndex) {
                    if (stage >= 10) std::strcpy(path, bgBitmapPrefix);
                    else std::strcpy(path, bgBitmapPrefixZero);
                    _itoa(stage, digits, 10);
                    std::strcat(path, digits);
                    if (work.bitmapIndex >= 100) std::strcat(path, bgBitmapSeparator);
                    else if (work.bitmapIndex >= 10) std::strcat(path, bgBitmapSeparatorZero);
                    else std::strcat(path, bgBitmapSeparatorTwoZeros);
                    _itoa(work.bitmapIndex, digits, 10);
                    std::strcat(path, digits);
                    std::strcat(path, bgBitmapExtension);
                    videoOwner->LoadSurface(&surfaces[work.bitmapIndex], path, 1);
                }
            }
            colorKey = videoOwner->SurfaceProperty(surfaces[0]);
        }
    }
}

void BattleBackground::LoadPatterns()
{
    SurfaceRect discardedBox;
    {
        char digits[8];
        {
            int count;
            {
                char path[32];
                if (stage >= 10) std::strcpy(path, bgPatternPrefix);
                else std::strcpy(path, bgPatternPrefixZero);
                _itoa(stage, digits, 10);
                std::strcat(path, digits);
                if (stage >= 10) std::strcat(path, bgPatternSeparator);
                else std::strcat(path, bgPatternSeparatorZero);
                std::strcat(path, digits);
                std::strcat(path, bgPatternExtension);
                PatternReader reader(path, 1);
                {
                    struct PatternReadWork {
                        int ignoredIndex, frameIndex, patternIndex;
                        int frameCount, serializedId;
                    } work;
                    count = reader.ReadInt();
                    patterns = new PatternSequence[count];
                    for (work.patternIndex = 0; work.patternIndex < count; ++work.patternIndex) {
                        work.serializedId = reader.ReadInt();
                        reader.ReadInt();
                        reader.ReadInt();
                        patterns[work.patternIndex].count = reader.ReadInt();
                        work.frameCount = patterns[work.patternIndex].count;
                        patterns[work.patternIndex].Allocate(work.frameCount);
                        for (work.frameIndex = 0; work.frameIndex < work.frameCount; ++work.frameIndex) {
                            patterns[work.patternIndex].frames[work.frameIndex].duration = reader.ReadInt();
                            patterns[work.patternIndex].frames[work.frameIndex].texture = reader.ReadInt();
                            patterns[work.patternIndex].frames[work.frameIndex].width = reader.ReadInt();
                            patterns[work.patternIndex].frames[work.frameIndex].height = reader.ReadInt();
                            patterns[work.patternIndex].frames[work.frameIndex].u = reader.ReadInt();
                            patterns[work.patternIndex].frames[work.frameIndex].v = reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            reader.ReadInt();
                            for (work.ignoredIndex = 0; work.ignoredIndex < 10; ++work.ignoredIndex) reader.Read(&discardedBox, 16);
                        }
                    }
                }
            }
        }
    }
}
