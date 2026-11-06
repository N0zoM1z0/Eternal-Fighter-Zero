// Defaults shared by character-specific local-effect producers.
#include "Engine.h"

void Secondary::ResetLocalEffectSpawn(SecondaryEffectSpawn *spawn)
{
    spawn->owner = 0;
    spawn->group = 0;
    spawn->palette = 255;
    spawn->payload = 0;
    spawn->field0028 = 0;
    spawn->field0030 = 0;
    spawn->bounds.top = 0;
    spawn->bounds.bottom = 0;
    spawn->bounds.left = 0;
    spawn->bounds.right = 0;
}
