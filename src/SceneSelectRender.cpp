// Complete character-selection composition, including all original stage-list loops.
#include "Engine.h"
#include <cmath>
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Scene1::Slot0()
{
    SurfaceRect source;
    {
        SurfaceRect destination;
        source = MakeSurfaceRect(0, (int)field0450, 320, 240);
        destination = MakeSurfaceRect(0, 0, 320, 240);
        videoOwner->DrawSurface(destination, backgroundSurface, source, 0, 0);
        if (contextOwner->cpuPlayer[0] != 1 || contextOwner->mode1364 != 0) {
            source = MakeSurfaceRect(133, 128, 22, 240);
            destination = MakeSurfaceRect(5 - (int)field0458, (int)field0468, 22, 240);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect(5 - (int)field0458, (int)field0468 - 240, 22, 240);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
        }
        if (contextOwner->cpuPlayer[1] != 1 || contextOwner->mode1364 != 0) {
            source = MakeSurfaceRect(165, 128, 22, 240);
            destination = MakeSurfaceRect((int)field0460 + 292, 0 - (int)field0468, 22, 240);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect((int)field0460 + 292, 0 - (int)field0468 + 240, 22, 240);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
        }
        if (field049e[0] > 0) {
            if ((contextOwner->mode1364 != 0 && contextOwner->mode1364 != 2) || contextOwner->cpuPlayer[0] != 1) {
                source = MakeSurfaceRect(0, 0, 320, 240);
                destination = MakeSurfaceRect(-80 - field0498[0] + portraitOffsets[field0538[0] + field053a[0] * 3], 0, 320, 240);
                videoOwner->DrawSurface(destination, playerSurfaces[0], source, playerColorKey[0], 1);
                source = MakeSurfaceRect(192, 9, 122, 95);
                destination = MakeSurfaceRect(0 - field0498[0] / 2, 137, 122, 95);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
                source = MakeSurfaceRect(0, characterOrder[field053c[0]] * 32 + 256, 122, 32);
                destination = MakeSurfaceRect(0 - field0498[0] / 2, 192, 122, 32);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            }
            if (contextOwner->alternateStyle[0]) {
                source = MakeSurfaceRect(0, 224, 128, 32);
                destination = MakeSurfaceRect(-16 - field0498[0] / 2, 5, 128, 32);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            }
        }
        if (field049e[1] > 0) {
            if ((contextOwner->mode1364 != 0 && contextOwner->mode1364 != 2) || contextOwner->cpuPlayer[1] != 1) {
                source = MakeSurfaceRect(0, 0, 320, 240);
                destination = MakeSurfaceRect(field0498[1] + 80 - portraitOffsets[field0538[1] + field053a[1] * 3], 0, 320, 240);
                videoOwner->DrawSurface(destination, playerSurfaces[1], source, playerColorKey[1], 0);
                source = MakeSurfaceRect(198, 137, 122, 95);
                destination = MakeSurfaceRect(field0498[1] / 2 + 198, 137, 122, 95);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
                source = MakeSurfaceRect(198, characterOrder[field053c[1]] * 32 + 256, 122, 32);
                destination = MakeSurfaceRect(field0498[1] / 2 + 198, 192, 122, 32);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            }
            if (contextOwner->alternateStyle[1]) {
                source = MakeSurfaceRect(0, 224, 128, 32);
                destination = MakeSurfaceRect(field0498[1] / 2 + 207, 5, 128, 32);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            }
        }
        source = MakeSurfaceRect(0, 0, 128, 217);
        destination = MakeSurfaceRect(96, (int)field0470, 128, 217);
        videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
        source = MakeSurfaceRect(138, 96, 41, 25);
        if (contextOwner->characterDataMode == 0) {
            destination = MakeSurfaceRect(103, (int)field0470 + 114, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect(143, (int)field0470 + 114, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect(183, (int)field0470 + 114, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect(177, (int)field0470 + 192, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
        }
        if (contextOwner->characterDataMode == -1) {
            destination = MakeSurfaceRect(97, (int)field0470 + 140, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect(137, (int)field0470 + 140, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect(143, (int)field0470 + 166, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            destination = MakeSurfaceRect(183, (int)field0470 + 166, 41, 25);
            videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
        }
        if (field0470 == 0.0) {
            if (field053c[0] == field053c[1] &&
                (contextOwner->cpuPlayer[0] != 1 || contextOwner->mode1364 != 0) &&
                (contextOwner->cpuPlayer[1] != 1 || contextOwner->mode1364 != 0)) {
                source = MakeSurfaceRect(129, 64, 63, 24);
                destination = MakeSurfaceRect(field0538[0] * 40 + 88 + (field053a[0] % 2 == 0) * 6, field053a[0] * 26 + 10, 63, 24);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            } else {
                if (contextOwner->cpuPlayer[1] != 1 || contextOwner->mode1364 != 0) {
                    source = MakeSurfaceRect(129, 32, 63, 24);
                    destination = MakeSurfaceRect(field0538[1] * 40 + 88 + (field053a[1] % 2 == 0) * 6, field053a[1] * 26 + 10, 63, 24);
                    videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
                }
                if (contextOwner->cpuPlayer[0] != 1 || contextOwner->mode1364 != 0) {
                    source = MakeSurfaceRect(129, 0, 63, 24);
                    destination = MakeSurfaceRect(field0538[0] * 40 + 88 + (field053a[0] % 2 == 0) * 6, field053a[0] * 26 + 10, 63, 24);
                    videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
                }
            }
        }
        if ((field049e[0] == 7 || field049e[0] == 8 || field049e[0] == 4) &&
            contextOwner->mode1364 != 0 && contextOwner->mode1364 != 2) {
            if (field0540[0] == 0) {
                int skipped = 0;
                for (int row = 1; row <= 7; ++row) {
                    while (stageUnavailable[(contextOwner->flag0f32 + row + skipped) % 23]) ++skipped;
                    source = MakeSurfaceRect(0, ((contextOwner->flag0f32 + row + skipped) % 23) * 32, 160, 32);
                    destination = MakeSurfaceRect(row * 11 + 170, 205 - row * 33 + (int)((190 + row * 33) * std::cos(field048c / (180.0 / 3.141592))), 160, 32);
                    videoOwner->DrawSurface(destination, stageSurface, source, stageColorKey, 0);
                }
                source = MakeSurfaceRect(160, contextOwner->flag0f32 * 32, 160, 32);
                destination = MakeSurfaceRect(170, (int)(std::cos(field048c / (180.0 / 3.141592)) * 190.0) + 205, 160, 32);
                videoOwner->DrawSurface(destination, stageSurface, source, stageColorKey, 0);
                source = MakeSurfaceRect(1, 0, 195, 222);
                destination = MakeSurfaceRect(0 - (int)(std::cos(field048c / (180.0 / 3.141592)) * 230.0), 0, 195, 222);
                videoOwner->DrawSurface(destination, portraitSurface, source, portraitColorKey, 0);
            } else {
                int skipped = 0;
                for (int row = 0; row <= 8; ++row) {
                    while (stageUnavailable[(contextOwner->flag0f32 + row + skipped) % 23]) ++skipped;
                    source = MakeSurfaceRect(0, ((contextOwner->flag0f32 + row + skipped) % 23) * 32, 160, 32);
                    destination = MakeSurfaceRect(row * 11 + 170, 205 - row * 33 + (int)((190 + row * 33) * std::cos(field048c / (180.0 / 3.141592))), 160, 32);
                    videoOwner->DrawSurface(destination, stageSurface, source, stageColorKey, 0);
                }
                source = MakeSurfaceRect(0, 985, 195, 222);
                destination = MakeSurfaceRect(0 - (int)(std::cos(field048c / (180.0 / 3.141592)) * 230.0), 0, 195, 222);
                videoOwner->DrawSurface(destination, objectSurface, source, colorKey, 0);
            }
        } else if (field049e[0] == 9) {
            int skipped = 0;
            for (int row = 0; row <= 8; ++row) {
                while (stageUnavailable[(contextOwner->flag0f32 + row + skipped) % 23]) ++skipped;
                source = MakeSurfaceRect(0, ((contextOwner->flag0f32 + row + skipped) % 23) * 32, 160, 32);
                destination = MakeSurfaceRect(row * 11 + 170 - (int)(std::sin(field0490 / (180.0 / 3.141592)) * 11.0),
                    205 - row * 33 + (int)((190 + row * 33) * std::cos(field048c / (180.0 / 3.141592))) + (int)(std::sin(field0490 / (180.0 / 3.141592)) * 33.0), 160, 32);
                videoOwner->DrawSurface(destination, stageSurface, source, stageColorKey, 0);
            }
            source = MakeSurfaceRect(1, 0, 195, 222);
            destination = MakeSurfaceRect(0 - (int)(std::cos(field048c / (180.0 / 3.141592)) * 230.0), 0, 195, 222);
            videoOwner->DrawSurface(destination, portraitSurface, source, portraitColorKey, 0);
        } else if (field049e[0] == 10) {
            int skipped = 0;
            int row;
            for (row = 0; row <= 8; ++row) {
                while (stageUnavailable[(contextOwner->flag0f32 + row + 23 + skipped) % 23]) ++skipped;
                source = MakeSurfaceRect(0, ((contextOwner->flag0f32 + row + 23 + skipped) % 23) * 32, 160, 32);
                destination = MakeSurfaceRect(row * 11 + (int)(std::sin(field0490 / (180.0 / 3.141592)) * 11.0) + 170,
                    205 - row * 33 + (int)((190 + row * 33) * std::cos(field048c / (180.0 / 3.141592))) - (int)(std::sin(field0490 / (180.0 / 3.141592)) * 33.0), 160, 32);
                videoOwner->DrawSurface(destination, stageSurface, source, stageColorKey, 0);
            }
            row = -1;
            skipped = 0;
            while (stageUnavailable[(contextOwner->flag0f32 + row + 23 + skipped) % 23]) --skipped;
            source = MakeSurfaceRect(0, ((contextOwner->flag0f32 + row + 23 + skipped) % 23) * 32, 160, 32);
            destination = MakeSurfaceRect(row * 11 + (int)(std::sin(field0490 / (180.0 / 3.141592)) * 11.0) + 170,
                205 - row * 33 + (int)((190 + row * 33) * std::cos(field048c / (180.0 / 3.141592))) - (int)(std::sin(field0490 / (180.0 / 3.141592)) * 33.0), 160, 32);
            videoOwner->DrawSurface(destination, stageSurface, source, stageColorKey, 0);
            source = MakeSurfaceRect(1, 0, 195, 222);
            destination = MakeSurfaceRect(0 - (int)(std::cos(field048c / (180.0 / 3.141592)) * 230.0), 0, 195, 222);
            videoOwner->DrawSurface(destination, portraitSurface, source, portraitColorKey, 0);
        }
        videoOwner->Present();
    }
}
