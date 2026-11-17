// Complete natural C++ reconstruction of Scene9 results renderer, 0x00772800.
// Original layout, wrap-around panels and numeric result display.
#include "Engine.h"

extern SurfaceRect __cdecl MakeSurfaceRect(int left, int top, int width, int height);
extern double __cdecl IntegerPowerAsDouble(int base, int exponent);

typedef char Scene9ResultsRendererLayout[(sizeof(Scene9) == 0x474) ? 1 : -1];

#define DRAW(dest, surface, source, color) \
    videoOwner->DrawSurface(MakeSurfaceRect dest, surface, MakeSurfaceRect source, color, 0)
#define FILL(rect, color) videoOwner->FillRectangle(MakeSurfaceRect rect, color)

void Scene9::Slot0()
{
    // Background and top view of the victorious character.
    DRAW((0, 0, 320, 160), contextOwner->extraA,
         ((int)resultPanelY, 320, 320, 160), 0);
    FILL((0, 160, 320, 80), 0xb0);
    if (contextOwner->winner134c == 1) {
        secondary[0]->Render(-resultPanelY, -80);
    } else {
        secondary[1]->Render(-resultPanelY, -80);
    }
    FILL((320 - resultPanelAcceleration, 0, resultPanelAcceleration, 240), 0xe7);
    FILL((0, 0, resultPanelAcceleration, 240), 0xe7);

    // Two bands of seven strips with wrapping, each source area is 160 wide.
    int shift;
    for (shift = -240; shift <= 240; shift += 80) {
        if (resultScrollC <= 160) {
            DRAW((resultPanelAcceleration - 160, resultScrollD + shift, 160, 48), winnerSurface,
                 (resultScrollC, 48, 160, 48), contextOwner->colorKey);
            DRAW((((160 - resultPanelAcceleration) + 160), resultScrollD + shift,
                  160 - resultScrollC, 48), winnerSurface,
                 (resultScrollC + 160, 48, 160 - resultScrollC, 48), contextOwner->colorKey);
            DRAW((((160 - resultPanelAcceleration) + 320) - resultScrollC, resultScrollD + shift,
                  resultScrollC, 48), winnerSurface,
                 (0, 48, resultScrollC, 48), contextOwner->colorKey);
        } else {
            DRAW((resultPanelAcceleration - 160, resultScrollD + shift,
                  320 - resultScrollC, 48), winnerSurface,
                 (resultScrollC, 48, 320 - resultScrollC, 48), contextOwner->colorKey);
            DRAW(((resultPanelAcceleration + 160) - resultScrollC, resultScrollD + shift,
                  resultScrollC - 160, 48), winnerSurface,
                 (0, 48, resultScrollC - 160, 48), contextOwner->colorKey);
            DRAW((((160 - resultPanelAcceleration) + 160), resultScrollD + shift, 160, 48),
                 winnerSurface, (resultScrollC - 160, 48, 160, 48), contextOwner->colorKey);
        }
    }
    for (shift = -240; shift <= 240; shift += 80) {
        if (resultScrollA <= 160) {
            DRAW((resultPanelAcceleration - 160, resultScrollB + shift, 160, 48), winnerSurface,
                 (resultScrollA, 0, 160, 48), contextOwner->colorKey);
            DRAW((((160 - resultPanelAcceleration) + 160), resultScrollB + shift,
                  160 - resultScrollA, 48), winnerSurface,
                 (resultScrollA + 160, 0, 160 - resultScrollA, 48), contextOwner->colorKey);
            DRAW((((160 - resultPanelAcceleration) + 320) - resultScrollA, resultScrollB + shift,
                  resultScrollA, 48), winnerSurface,
                 (0, 0, resultScrollA, 48), contextOwner->colorKey);
        } else {
            DRAW((resultPanelAcceleration - 160, resultScrollB + shift,
                  320 - resultScrollA, 48), winnerSurface,
                 (resultScrollA, 0, 320 - resultScrollA, 48), contextOwner->colorKey);
            DRAW(((resultPanelAcceleration + 160) - resultScrollA, resultScrollB + shift,
                  resultScrollA - 160, 48), winnerSurface,
                 (0, 0, resultScrollA - 160, 48), contextOwner->colorKey);
            DRAW((((160 - resultPanelAcceleration) + 160), resultScrollB + shift, 160, 48),
                 winnerSurface, (resultScrollA - 160, 0, 160, 48), contextOwner->colorKey);
        }
    }

    DRAW((resultPanelX + 80, 0, 320, 240), resultBackdropSurface,
         (0, 0, 320, 240), colorKey);
    if (resultPhase < 2) {
        DRAW((0, resultPanelYStart, 320, 240), resultOverlaySurface,
             (0, 0, 320, 240), contextOwner->colorKey);
    } else if (resultPhase == 2) {
        DRAW((87, 90, 153, 25), resultSurface,
             (0, 474, 153, 25), contextOwner->colorKey);
        if (resultTransitionState == 0) {
            DRAW((104, 124, 51, 21), resultSurface,
                 (0, 499, 51, 21), contextOwner->colorKey);
            DRAW((180, 126, 30, 16), resultSurface,
                 (38, 520, 30, 16), contextOwner->colorKey);
        } else {
            DRAW((110, 126, 38, 15), resultSurface,
                 (0, 520, 38, 15), contextOwner->colorKey);
            DRAW((175, 124, 39, 20), resultSurface,
                 (51, 500, 39, 20), contextOwner->colorKey);
        }
    } else if (resultPhase == 3) {
        DRAW((73, 9, 214, 42), resultSurface,
             (0, ((int)contextOwner->flag1358 - 1) * 42, 214, 42), contextOwner->colorKey);
        DRAW((9, 59, 52, 18), resultSurface,
             (0, 353, 52, 18), contextOwner->colorKey);
        DrawResultNumber(310, 58, healthBonus);
        DRAW((9, 86, 106, 29), resultSurface,
             (0, 371, 106, 29), contextOwner->colorKey);
        DrawResultNumber(310, 91, comboBonus);
        DRAW((9, 117, 117, 33), resultSurface,
             (0, 400, 117, 33), contextOwner->colorKey);
        DrawResultNumber(310, 124, damageBonus);
        DRAW((9, 156, 126, 22), resultSurface,
             (0, 433, 126, 22), contextOwner->colorKey);
        DrawResultNumber(310, 157, winBonus);
        DRAW((9, 190, 74, 18), resultSurface,
             (52, 353, 74, 18), contextOwner->colorKey);
        DRAW((298, 187, 11, 17), resultSurface,
             (178, 456, 11, 17), contextOwner->colorKey);
        DrawResultNumber(296, 186, secondary[(char)contextOwner->selectedPlayer]->field30d0);
        DrawResultNumber(310, 215, secondary[(char)contextOwner->selectedPlayer]->field30c8);
        if (secondary[(char)contextOwner->selectedPlayer]->field30cc > 0) {
            DrawResultNumber(198, 215, secondary[(char)contextOwner->selectedPlayer]->field30cc);
            for (int digit = 1; digit < 8; ++digit) {
                if ((double)secondary[(char)contextOwner->selectedPlayer]->field30c8 / IntegerPowerAsDouble(10, 8 - digit) < 1.0) {
                    DrawResultNumber(digit * 14 + 198, 215, 0);
                }
            }
        }
    }
    videoOwner->Present();
}
#undef DRAW
#undef FILL
