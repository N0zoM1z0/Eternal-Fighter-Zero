// Battle decimal glyph output and compressed player/effect shadows.
#include "SceneBattle.h"

void Scene3::DrawNumber(int x, int y, unsigned int value, unsigned char style, unsigned char spacing, int mode)
{
    struct NumberWork {
        SurfaceRect source;
        unsigned int digit;
        SurfaceRect destination;
        unsigned int remaining;
        int edge;
    } work;
    work.remaining = value;
    work.edge = x;
    do {
        work.digit = work.remaining % 10;
        work.source.top = numberStyles[style].top;
        work.source.bottom = numberStyles[style].bottom;
        work.source.left = numberStyles[style].right * work.digit;
        work.source.right = numberStyles[style].right * (work.digit + 1);
        work.destination.top = y;
        work.destination.bottom = (numberStyles[style].bottom - numberStyles[style].top) + y;
        work.destination.right = work.edge;
        work.destination.left = work.edge - numberStyles[style].right;
        if (mode != 0) videoOwner->DrawBlendedSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0, 0);
        else videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        work.edge = work.edge - (numberStyles[style].right + (unsigned int)spacing);
        work.remaining = work.remaining / 10;
    } while (work.remaining > 0);
}

void Scene3::RenderShadows()
{
    struct ShadowWork {
        int effect;
        SurfaceRect source;
        int height;
        PatternFrame *frame;
        int player;
        SurfaceRect destination;
        int offset;
    } work;
    for (work.player = 0; work.player < 2; ++work.player) {
        if (secondary[work.player]->field0060 != 0) {
            work.frame = &secondary[work.player]->patterns[secondary[work.player]->field0008].frames[secondary[work.player]->field000a];
            if (work.frame->v < work.frame->height) {
                work.height = work.frame->v;
                work.offset = 0;
            } else {
                work.height = work.frame->height;
                work.offset = work.frame->v - work.frame->height;
            }
            work.source.left = 0;
            work.source.top = 0;
            work.source.right = work.frame->width;
            work.source.bottom = work.height;
            work.destination.left = (int)secondary[work.player]->positionX + field045c
            - work.frame->u * (secondary[work.player]->facing == 1)
            - (work.frame->width - work.frame->u) * (secondary[work.player]->facing == -1);
            work.destination.top = (210 - ((int)secondary[work.player]->positionY - (secondary[work.player]->positionY < 0.0))) + field0460 + work.offset;
            work.destination.right = work.frame->width + work.destination.left;
            work.destination.bottom = work.height / 3 + work.destination.top;
            if (work.destination.top < 240 && work.destination.bottom > 0) {
                videoOwner->DrawShadowSurface(work.destination, secondary[work.player]->surfaces[work.frame->texture], work.source,
                    secondary[work.player]->colorKey, secondary[work.player]->facing == -1, 0xb0);
            }
        }
        work.effect = secondary[work.player]->effectRead;
        while (work.effect != secondary[work.player]->effectWrite) {
            if (secondary[work.player]->effectActive[work.effect] != 0 && secondary[work.player]->effects[work.effect].field0058 != 0 &&
                (secondary[work.player]->effects[work.effect].field008c != 0 || contextOwner->state1420e == 0)) {
                work.frame = &secondary[work.player]->patterns[secondary[work.player]->effects[work.effect].type].frames[secondary[work.player]->effects[work.effect].frame];
                if (work.frame->v < work.frame->height) {
                    work.height = work.frame->v;
                    work.offset = 0;
                } else {
                    work.height = work.frame->height;
                    work.offset = work.frame->v - work.frame->height;
                }
                work.source.left = 0;
                work.source.top = 0;
                work.source.right = work.frame->width;
                work.source.bottom = work.height;
                if (secondary[work.player]->effects[work.effect].flag0048 == -1) {
                    work.destination.left = (int)secondary[work.player]->effects[work.effect].x + field045c - (work.frame->width - work.frame->u);
                    work.destination.top = ((field0460 + 210) - (int)secondary[work.player]->effects[work.effect].y) + work.offset;
                    work.destination.right = work.frame->width + work.destination.left;
                    work.destination.bottom = work.height / 3 + work.destination.top;
                } else {
                    work.destination.left = (int)secondary[work.player]->effects[work.effect].x + field045c - work.frame->u;
                    work.destination.top = ((field0460 + 210) - (int)secondary[work.player]->effects[work.effect].y) + work.offset;
                    work.destination.right = work.frame->width + work.destination.left;
                    work.destination.bottom = work.height / 3 + work.destination.top;
                }
                if (work.destination.top < 240 && work.destination.bottom > 0) {
                    videoOwner->DrawShadowSurface(work.destination, secondary[work.player]->surfaces[work.frame->texture], work.source,
                        secondary[work.player]->colorKey, secondary[work.player]->effects[work.effect].flag0048 == -1, 0xb0);
                }
            }
            ++work.effect;
            if (work.effect >= 64) work.effect = 0;
        }
    }
}
