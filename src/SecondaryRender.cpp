// Complete character body/trail rendering dispatcher; pixel kernels remain explicit callees.
#include "Engine.h"

void Secondary::Render(int offsetX, int offsetY)
{
    int i;
    {
        SurfaceRect destination;
        {
            PatternFrame frame;
            {
                SurfaceRect source;
                {
                    int index;
                    if (trail.pending > 0 || trail.held > 0) {
                        index = trail.position - (trail.pending * 3 + trail.held);
                        for (i = 0; i < trail.held + trail.pending * 3; i += trail.stride) {
                            if (index >= 60) index -= 60;
                            if (index < 0) index += 60;
                            frame = patterns[trail.type[index]].frames[trail.frame[index]];
                            source.left = 0;
                            source.top = 0;
                            source.right = frame.width;
                            source.bottom = frame.height;
                            destination.left = int(trail.x[index]) + offsetX - frame.u * (trail.facing[index] == 1)
                            - (frame.width - frame.u) * (trail.facing[index] == -1);
                            destination.top = int(trail.y[index]) + 210 - (trail.y[index] < 0.0) - frame.v + offsetY;
                            destination.right = frame.width + destination.left;
                            destination.bottom = frame.height + destination.top;
                            videoOwner->DrawBlendedSurface(destination, surfaces[frame.texture], source, colorKey,
                            trail.facing[index] == -1, 0);
                            index += trail.stride;
                        }
                    }
                    frame = patterns[field0008].frames[field000a];
                    source.left = 0;
                    source.top = 0;
                    source.right = frame.width;
                    source.bottom = frame.height;
                    destination.left = int(field0020) + offsetX - frame.u * (facing == 1)
                    - (frame.width - frame.u) * (facing == -1);
                    destination.top = int(field0028) + 210 - (field0028 < 0.0) - frame.v + offsetY;
                    destination.right = frame.width + destination.left;
                    destination.bottom = frame.height + destination.top;
                    if (destination.top < 240) {
                        if (field30bc == 0) {
                            if (field0058 == 3) videoOwner->DrawCharacterSpecial(destination, surfaces[frame.texture], source, colorKey, facing == -1);
                            else if (field0058 > 0) videoOwner->DrawBlendedSurface(destination, surfaces[frame.texture], source, colorKey, facing == -1, field0058 - 1);
                            else videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, facing == -1);
                        } else {
                            videoOwner->DrawCharacterTint(destination, surfaces[frame.texture], source, colorKey, facing == -1, tint30b8);
                            --field30bc;
                        }
                    } else if (field013e == 0) {
                        frame = patterns[49].frames[0];
                        source.left = 0;
                        source.top = 0;
                        source.right = frame.width;
                        source.bottom = frame.height;
                        destination.left = int(field0020) + offsetX - frame.u * (facing == 1)
                        - (frame.width - frame.u) * (facing == -1);
                        destination.top = 239 - frame.v;
                        destination.right = frame.width + destination.left;
                        destination.bottom = frame.height + destination.top;
                        videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, facing == -1);
                    }
                }
            }
        }
    }
}
