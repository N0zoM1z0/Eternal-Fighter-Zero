// Kano's native passive meter and periodic effect logic.
#include "CharacterViews.h"

void Character20::Slot08()
{
    EffectSpawn effect;
    ResetLocalEffectSpawn(&effect);

    if ((*opponentSlot)->hitstunFrames == 0 && field0008 < 300)
        ++field3154;

    if (field3154 > 30 - (28 - ((int)((double)meter * 0.001) << 2))) {
        ++meter;
        field3154 = 0;
    }
    if (((field3154 > 30 - (28 - ((int)((double)meter * 0.001) << 2))) * 0.5) != 0.0 &&
        field0008 == 3) {
        ++meter;
        field3154 = 0;
    }
    if (velocityX == 0.0 && (*opponentSlot)->hitstunFrames == 0 &&
        field0008 < 300 && (field0008 < 50 || field0008 > 200)) {
        ++field3158;
    } else {
        field3158 = 0;
    }
    if (field3158 > 630) {
        meter = (short)(meter + 300);
        field3158 = 0;
        effect.type = 0x19b;
        effect.x = (double)(int)positionX;
        effect.y = positionY - 50.0;
        effect.flag0018 = 1;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
    }
    --field3160;
    if (field315c > 0 && field3160 <= 0) {
        effect.type = 0x1c3;
        effect.x = (double)((int)positionX + 120 -
                            (unsigned short)RandomRange(0,240) -
                            (int)((double)field3164 * 192.0));
        effect.y = -480.0;
        effect.flag0018 = (unsigned char)field3164;
        effect.group = 2;
        effect.layer = 1;
        effect.owner = 1;
        EmitLocalEffect(&effect);
        --field315c;
        field3160 = 180;
    }
}
