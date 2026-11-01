// Live effect queue traversal and frame-to-surface rendering.
#include "Engine.h"

extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Context::ClearEffects()
{
    for (int i = 0; i < 640; ++i) {
        effectActive[i] = 0;
        effectOwner[i] = 0;
    }
}

void Context::UpdateEffects()
{
    int i = field1382;
    while (i != field1380) {
        if (effectActive[i]) UpdateEffect(i);
        ++i;
        if (i >= 640) i = 0;
    }
}

void Context::RemoveEffectsOfType(int type)
{
    int i = field1382;
    do {
        if (effects[i].type == type && effectActive[i]) RemoveEffect(i);
        ++i;
        if (i >= 640) i = 0;
    } while (i != field1380 + 1 - 640 * (field1380 == 639));
}

void Context::RenderEffects(int cameraX, int cameraY, unsigned char layer)
{
    int i = field1382;
    SurfaceRect destination;
    PatternFrame *frame;
    SurfaceRect source;
    while (i != field1380) {
        if (effectActive[i] && layer == effects[i].layer) {
            frame = &patterns[effects[i].type].frames[effects[i].frame];
            source = MakeSurfaceRect(0, 0, frame->width, frame->height);
            if (effects[i].facing) {
                destination.left = (int)effects[i].x + (effects[i].payload == 0) * cameraX - (frame->width - frame->u);
                destination.top = (effects[i].payload == 0) * 210 + (int)effects[i].y - frame->v + (effects[i].payload == 0) * cameraY;
                destination.right = frame->width + destination.left;
                destination.bottom = frame->height + destination.top;
            } else {
                destination.left = (int)effects[i].x + (effects[i].payload == 0) * cameraX - frame->u;
                destination.top = (effects[i].payload == 0) * 210 + (int)effects[i].y - frame->v + (effects[i].payload == 0) * cameraY;
                destination.right = frame->width + destination.left;
                destination.bottom = frame->height + destination.top;
            }
            if (effects[i].group > 0) {
                videoOwner->DrawBlendedSurface(destination, textures[frame->texture], source, colorKey, effects[i].facing, effects[i].group - 1);
            } else {
                videoOwner->DrawSurface(destination, textures[frame->texture], source, colorKey, effects[i].facing);
            }
        }
        ++i;
        if (i >= 640) i = 0;
    }
}
