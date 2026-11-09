// Ikumi second pattern-bank parser and character resource-wrapper, natural C++.
// These two functions are original owners, verified separately.
#include "CharacterViews.h"
#include "PatternReader.h"

void Character14::LoadAlternatePatterns()
{
    int count;
    PatternReader reader("ikumi\\ikumi2.pat", 1);
    count = reader.ReadInt();
    {
        int id;
        {
            int frames;
            {
                int i;
                {
                    int j;
                    {
                        PatternFrame *frame;
                        {
                            SecondaryFrame *extra;
                            {
                                int k;
                                for (i = 0; i < count; ++i) {
                                    id = reader.ReadInt();
                                    alternateSequences[id].field0000 = reader.ReadInt();
                                    alternateSequences[id].field0002 = reader.ReadInt();
                                    alternatePatterns[id].count = reader.ReadInt();
                                    frames = alternatePatterns[id].count;
                                    alternateSequences[id].Allocate(frames);
                                    alternatePatterns[id].Allocate(frames);
                                    for (j = 0; j < frames; ++j) {
                                        frame = &alternatePatterns[id].frames[j];
                                        extra = &alternateSequences[id].data[j];
                                        frame->duration = (short)reader.ReadInt() * 3;
                                        frame->texture = reader.ReadInt();
                                        frame->width = reader.ReadInt();
                                        frame->height = reader.ReadInt();
                                        frame->u = reader.ReadInt();
                                        frame->v = reader.ReadInt();
                                        extra->damage = reader.ReadInt();
                                        extra->attackFlags = reader.ReadInt();
                                        extra->airHitState = reader.ReadInt();
                                        extra->frameFlags = reader.ReadInt();
                                        extra->airActionLockFrames = reader.ReadInt();
                                        extra->guardDamage = reader.ReadInt();
                                        extra->hitMeterGain = reader.ReadInt();
                                        extra->guardMeterGain = reader.ReadInt();
                                        extra->outgoingPushbackVelocityY = reader.ReadShort();
                                        extra->outgoingPushbackVelocityY = extra->outgoingPushbackVelocityY / 100.0f;
                                        extra->outgoingPushbackVelocityX = reader.ReadShort();
                                        extra->outgoingPushbackVelocityX = extra->outgoingPushbackVelocityX / -100.0f;
                                        extra->hitEffectPalette = reader.ReadShort();
                                        extra->hitEffectType = reader.ReadShort();
                                        extra->attackerHitstopFrames = reader.ReadInt();
                                        extra->defenderHitstopFrames = reader.ReadInt();
                                        extra->comboDamageScale = reader.ReadInt();
                                        extra->groundHitState = reader.ReadInt();
                                        reader.Read(&extra->bodyBox, 16);
                                        for (k = 0; k < 2; ++k) reader.Read(&extra->hurtBoxes[k], 16);
                                        reader.Read(&extra->attackBoxes[0], 16);
                                        for (k = 2; k < 5; ++k) reader.Read(&extra->hurtBoxes[k], 16);
                                        for (k = 1; k < 4; ++k) reader.Read(&extra->attackBoxes[k], 16);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Character14::LoadResources()
{
    LoadAlternatePatterns();
    Secondary::LoadResources();
    savedPatterns = patterns;
    savedSequences = sequences;
}
