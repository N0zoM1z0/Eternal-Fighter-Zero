// Natural C++ replay browser renderer, original owner 0x0076F780.
// Original replay scrolling/menu/character UI, compiled as a normal C++ owner.
#include "Engine.h"
#include <math.h>

extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);
typedef char Scene8RenderLayout[(sizeof(Scene8) == 0x758) ? 1 : -1];

void Scene8::Slot0()
{
    struct RenderWork {
        int easedRow;
        int row;
        int easedX;
        SurfaceRect destination;
        SurfaceRect source;
    } work;

    work.source = MakeSurfaceRect(0, 0, 320, 240);
    work.destination = MakeSurfaceRect(0, 0, 320, 240);
    videoOwner->DrawSurface(work.destination, replayBackgroundSurface, work.source, 0, 0);

    work.source = MakeSurfaceRect(0, 25, 320, 16);
    work.destination = MakeSurfaceRect(0, 4, 320, 16);
    videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);

    if (replayRow == 9) {
        work.source = MakeSurfaceRect(replayRow * 16 + 80, 6, 40, 15);
        work.destination = MakeSurfaceRect(replayRow * 16 + 80, 4, 40, 15);
    } else {
        work.source = MakeSurfaceRect(replayRow * 16 + 80, 6, 16, 15);
        work.destination = MakeSurfaceRect(replayRow * 16 + 80, 4, 16, 15);
    }
    videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);

    if (replayMenuPhase != 4) {
        work.easedX = 319 - (int)(160.0 - cos(replayScrollX / 57.29579143313326) * 160.0);
        if (replayMenuSubchoice == 0) {
            work.source = MakeSurfaceRect(0, 852, 320, 16);
        } else {
            work.source = MakeSurfaceRect(0, 716, 320, 16);
        }
        work.destination = MakeSurfaceRect(0, work.easedX + 112, 320, 16);
        videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);

        if (replayMenuSubchoice == 1) {
            work.source = MakeSurfaceRect(0, 868, 320, 16);
        } else {
            work.source = MakeSurfaceRect(0, 732, 320, 16);
        }
        work.destination = MakeSurfaceRect(0, work.easedX + 128, 320, 16);
        videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);

        if (replayMenuSubchoice == 2) {
            work.source = MakeSurfaceRect(0, 884, 320, 16);
        } else {
            work.source = MakeSurfaceRect(0, 748, 320, 16);
        }
        work.destination = MakeSurfaceRect(0, work.easedX + 144, 320, 16);
        videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);
    } else {
        if (replayMenuPhase == 4) {
            work.source = MakeSurfaceRect(0, 768, 320, 44);
            work.destination = MakeSurfaceRect(0, 112, 320, 44);
            videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);

            work.source = MakeSurfaceRect(0, replayOverwriteChoice * 16 + 820, 320, 16);
            work.destination = MakeSurfaceRect(0, 160, 320, 16);
            videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);
        }
    }

    for (work.row = 0; work.row < 9; ++work.row) {
        if (replayColumn == work.row && work.row < 9) {
            work.source = MakeSurfaceRect(0, work.row * 16 + 92, 320, 16);
            work.destination = MakeSurfaceRect(0, (work.row * 16 + 96) - (int)replayScrollY, 320, 16);
            videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);
            if (replayRow < 9 && replayAvailable[replayRow][work.row] > 0) {
                work.source = MakeSurfaceRect(((int)replayCharacters[replayRow][work.row][0] / 10) * 80 + 64,
                                         ((int)replayCharacters[replayRow][work.row][0] % 10) * 16 + 396, 80, 16);
                work.destination = MakeSurfaceRect(90, (work.row * 16 + 96) - (int)replayScrollY, 80, 16);
                videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);

                work.source = MakeSurfaceRect(((int)replayCharacters[replayRow][work.row][1] / 10) * 80 + 64,
                                         ((int)replayCharacters[replayRow][work.row][1] % 10) * 16 + 396, 80, 16);
                work.destination = MakeSurfaceRect(205, (work.row * 16 + 96) - (int)replayScrollY, 80, 16);
                videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);
            }
        } else {
            work.easedRow = (int)(160.0 - cos(replayScrollX / 57.29579143313326) * 160.0);
            work.source = MakeSurfaceRect(0, work.row * 16 + 252, 320, 16);
            work.destination = MakeSurfaceRect(0, work.row * 16 + 96 + work.easedRow, 320, 16);
            videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);
            if (replayRow < 9 && replayAvailable[replayRow][work.row] > 0) {
                work.source = MakeSurfaceRect(((int)replayCharacters[replayRow][work.row][0] / 10) * 80 + 64,
                                         ((int)replayCharacters[replayRow][work.row][0] % 10) * 16 + 556, 80, 16);
                work.destination = MakeSurfaceRect(90, work.row * 16 + 96 + work.easedRow, 80, 16);
                videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);

                work.source = MakeSurfaceRect(((int)replayCharacters[replayRow][work.row][1] / 10) * 80 + 64,
                                         ((int)replayCharacters[replayRow][work.row][1] % 10) * 16 + 556, 80, 16);
                work.destination = MakeSurfaceRect(205, work.row * 16 + 96 + work.easedRow, 80, 16);
                videoOwner->DrawSurface(work.destination, replayOverlaySurface, work.source, colorKey, 0);
            }
        }
    }
    videoOwner->Present();
}
