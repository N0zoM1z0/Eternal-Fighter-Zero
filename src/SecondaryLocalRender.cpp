// Character-local effect rendering, including mirrored placement and clipping.
#include "Engine.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Secondary::RenderLocalEffects(int offsetX, int offsetY, unsigned char layer)
{
    int i;
    {
        SurfaceRect destination;
        {
            PatternFrame *frame;
            {
                SurfaceRect source;
                {
                    i = effectRead;
                    while (i != effectWrite) {
                        if (effectActive[i] != 0 && layer == effects[i].layer
                        && (effects[i].field008c != 0 || contextOwner->state1420e == 0)) {
                            frame = &patterns[effects[i].type].frames[effects[i].frame];
                            source = MakeSurfaceRect(0, 0, frame->width, frame->height);
                            if (effects[i].flag0048 == -1) {
                                destination.left = int(effects[i].x) + (effects[i].payload == 0) * offsetX
                                - (frame->width - frame->u);
                                destination.top = (offsetY + 210) * (effects[i].payload == 0)
                                + int(effects[i].y) - frame->v;
                                destination.right = frame->width + destination.left;
                                destination.bottom = frame->height + destination.top;
                            } else {
                                destination.left = int(effects[i].x) + (effects[i].payload == 0) * offsetX - frame->u;
                                destination.top = (offsetY + 210) * (effects[i].payload == 0)
                                + int(effects[i].y) - frame->v;
                                destination.right = frame->width + destination.left;
                                destination.bottom = frame->height + destination.top;
                            }
                            if (effects[i].bounds.top != effects[i].bounds.bottom) {
                                if (destination.left < effects[i].bounds.left) {
                                    source.left = (effects[i].bounds.left - destination.left) + source.left;
                                    destination.left = effects[i].bounds.left;
                                }
                                if (destination.right > effects[i].bounds.right) {
                                    source.right = source.right - (destination.right - effects[i].bounds.right);
                                    destination.right = effects[i].bounds.right;
                                }
                                if (destination.top < effects[i].bounds.top) {
                                    source.top = (effects[i].bounds.top - destination.top) + source.top;
                                    destination.top = effects[i].bounds.top;
                                }
                                if (destination.bottom > effects[i].bounds.bottom) {
                                    source.bottom = source.bottom - (destination.bottom - effects[i].bounds.bottom);
                                    destination.bottom = effects[i].bounds.bottom;
                                }
                            }
                            if (effects[i].group == 3) {
                                videoOwner->DrawCharacterSpecial(destination, surfaces[frame->texture], source,
                                colorKey, effects[i].flag0048 == -1);
                            } else if (effects[i].group > 0) {
                                videoOwner->DrawBlendedSurface(destination, surfaces[frame->texture], source,
                                colorKey, effects[i].flag0048 == -1, effects[i].group - 1);
                            } else {
                                videoOwner->DrawSurface(destination, surfaces[frame->texture], source,
                                colorKey, effects[i].flag0048 == -1);
                            }
                        }
                        ++i;
                        if (i >= 64) i = 0;
                    }
                }
            }
        }
    }
}
