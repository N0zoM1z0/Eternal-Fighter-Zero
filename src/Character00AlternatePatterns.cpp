// Nanase's secondary bank parser uses the same 505-entry original pattern format.
// Separate owner/translation unit: no shared class layouts or accepted units changed.
#include "CharacterViews.h"
#include "PatternReader.h"

struct Character00ResourceView {
    unsigned char inherited_0000[0x10];
    PatternSequence *patterns;
    unsigned char inherited_0014[0x150];
    SecondarySequence *sequences;
    unsigned char child_and_effects[0x345c - 0x168];
    PatternSequence *basePatterns;
    SecondarySequence *baseSequences;
    PatternSequence *alternatePatterns;
    SecondarySequence *alternateSequences;

    void LoadAlternateResources();
};

void Character00ResourceView::LoadAlternateResources()
{
    int count;
    PatternReader reader("nanase\\nanase2.pat", 1);
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
                                    baseSequences[id].field0000 = reader.ReadInt();
                                    baseSequences[id].field0002 = reader.ReadInt();
                                    basePatterns[id].count = reader.ReadInt();
                                    frames = basePatterns[id].count;
                                    baseSequences[id].Allocate(frames);
                                    basePatterns[id].Allocate(frames);
                                    for (j = 0; j < frames; ++j) {
                                        frame = &basePatterns[id].frames[j];
                                        extra = &baseSequences[id].data[j];
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
