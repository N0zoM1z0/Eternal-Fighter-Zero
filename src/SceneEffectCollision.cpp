// Complete effect collision outcomes for the battle scene.
#include "SceneBattle.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Scene3::ResolveEffectHit(Secondary *first, Secondary *second, int index, BattleCollisionSnapshot *pose)
{
    struct EffectHitWork {
        SecondaryEffectSlot *slot;
        int i, j;
        SecondaryFrame *attack, *defense;
    } work;
    work.slot = &first->effects[index];
    work.attack = &first->sequences[work.slot->type].data[work.slot->frame];
    work.defense = &pose->frame;
    if (work.slot->field0080 == 0 && (work.defense->frameFlags & 0x20) == 0 &&
        work.slot->field0084 > 0 &&
        !(second->field0130 > 0 && (work.attack->attackFlags & 0x40) > 0) &&
        second->AirActionReady() == 0 && second->field013c == 0) {
        struct CollisionBoxes {
            int overlap[4][5];
            SurfaceRect defenseBoxes[5], attackBoxes[4];
        } boxes;
        {
            int found;
            {
                SurfaceRect intersection;
                {
                    SurfaceRect specialBounds;
                    found = 0;
                    for (work.i = 0; work.i < 4; ++work.i) {
                        // The full effect slot shares the reviewed prefix read by this helper.
                        boxes.attackBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.slot), &work.attack->attackBoxes[work.i]);
                    }
                    for (work.i = 0; work.i < 5; ++work.i) {
                        boxes.defenseBoxes[work.i] = TransformSnapshotBox(pose, &work.defense->hurtBoxes[work.i]);
                    }
                    specialBounds = TransformSnapshotBox(pose, &work.defense->bodyBox);
                    if ((work.attack->attackFlags & 0x40) > 0) {
                        for (work.i = 0; work.i < 4; ++work.i) {
                            boxes.overlap[work.i][0] = 1;
                            found |= BoxesOverlap(&boxes.attackBoxes[work.i], &specialBounds);
                        }
                    } else {
                        for (work.i = 0; work.i < 4; ++work.i) {
                            for (work.j = 0; work.j < 5; ++work.j) {
                                boxes.overlap[work.i][work.j] = BoxesOverlap(&boxes.attackBoxes[work.i], &boxes.defenseBoxes[work.j]);
                                found |= boxes.overlap[work.i][work.j];
                            }
                        }
                    }
                    if (found != 0) {
                        EffectSpawn effect;
                        intersection = MakeSurfaceRect(-10000, -10000, 20000, 20000);
                        for (work.i = 0; work.i < 4; ++work.i) {
                            for (work.j = 0; work.j < 5; ++work.j) {
                                if (boxes.overlap[work.i][work.j] != 0) {
                                    if (intersection.left < boxes.attackBoxes[work.i].left) intersection.left = boxes.attackBoxes[work.i].left;
                                    if (intersection.top < boxes.attackBoxes[work.i].top) intersection.top = boxes.attackBoxes[work.i].top;
                                    if (intersection.right > boxes.attackBoxes[work.i].right) intersection.right = boxes.attackBoxes[work.i].right;
                                    if (intersection.bottom > boxes.attackBoxes[work.i].bottom) intersection.bottom = boxes.attackBoxes[work.i].bottom;
                                    if (intersection.left < boxes.defenseBoxes[work.j].left) intersection.left = boxes.defenseBoxes[work.j].left;
                                    if (intersection.top < boxes.defenseBoxes[work.j].top) intersection.top = boxes.defenseBoxes[work.j].top;
                                    if (intersection.right > boxes.defenseBoxes[work.j].right) intersection.right = boxes.defenseBoxes[work.j].right;
                                    if (intersection.bottom > boxes.defenseBoxes[work.j].bottom) intersection.bottom = boxes.defenseBoxes[work.j].bottom;
                                }
                            }
                        }
                        if (((work.defense->frameFlags & 0x400) > 0) && ((work.attack->attackFlags & 0x100) == 0)) {
                            --work.slot->field0084;
                            work.slot->field0080 = 2;
                            first->attackCollisionResult = 6;
                            second->attackCollisionResult = 6;
                        } else if (((second->attackWasGuarded != 0) && (((second->guardInputFrames >= 0x1e) && (second->field013a == 0)) && (second->GuardInput(work.attack) != 0))) && ((work.attack->attackFlags & 0x80) == 0)) {
                            work.slot->field0080 = 2;
                            first->meter += work.attack->guardMeterGain;
                            --work.slot->field0084;
                            second->outgoingPushbackActive = 1;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(second->facing == -1);
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.type = 0x11;
                            effect.palette = 10;
                            contextOwner->EmitEffect(&effect);
                            second->ResetPose();
                            second->facing = -work.slot->flag0048;
                            if (second->positionY == 0.0) {
                                second->field0008 = 0xa8 + (second->inputY == 1);
                            } else {
                                second->field0008 = 0xaa;
                            }
                            first->ClearInputHistory();
                            second->ClearInputHistory();
                            second->hitstunFrames = 0x3c;
                            second->attackWasGuarded = 0;
                            first->attackWasGuarded = 1;
                        } else if (((second->guardInputFrames >= 0x1e) && (second->positionY < 0.0)) && (second->CanGuard(work.attack, work.defense) != 0)) {
                            work.slot->field0080 = 2;
                            first->meter += work.attack->guardMeterGain;
                            --work.slot->field0084;
                            second->outgoingPushbackActive = 1;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(second->facing == -1);
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.type = 0x11;
                            effect.palette = 10;
                            contextOwner->EmitEffect(&effect);
                            second->ResetPose();
                            second->facing = -work.slot->flag0048;
                            second->field0008 = 0xaa;
                            first->ClearInputHistory();
                            second->ClearInputHistory();
                            second->hitstunFrames = 0x3c;
                            first->attackWasGuarded = 1;
                        } else if (((second->CanGuard(work.attack, work.defense) != 0) && (second->guardInputFrames >= 0x1e)) && ((second->positionY == 0.0) && ((second->field0008 != 0xa8) && (second->field0008 != 0xa9)))) {
                            work.slot->field0080 = 2;
                            first->meter += work.attack->guardMeterGain;
                            --work.slot->field0084;
                            second->outgoingPushbackActive = 1;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(second->facing == -1);
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.type = 0x11;
                            effect.palette = 10;
                            contextOwner->EmitEffect(&effect);
                            second->ResetPose();
                            second->facing = -work.slot->flag0048;
                            second->field0008 = 0xa8 + (second->inputY == 1);
                            first->ClearInputHistory();
                            second->ClearInputHistory();
                            second->hitstunFrames = 0x3c;
                            first->attackWasGuarded = 1;
                        } else if (((work.defense->frameFlags & 0x200) > 0) && (((work.defense->attackFlags & 1) > 0) && ((work.attack->attackFlags & 1) > 0))) {
                            --work.slot->field0084;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(second->facing == -1);
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.type = 2;
                            effect.palette = 3;
                            contextOwner->EmitEffect(&effect);
                            first->attackCollisionResult = 2;
                            first->hitstopFrames = work.attack->attackerHitstopFrames;
                            second->hitstopFrames = work.attack->defenderHitstopFrames;
                            second->field0108 = second->field0108 - (int)work.attack->guardDamage;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            second->airActionGauge =
                            (float)((int)work.attack->damage / 0x1e) + (float)second->airActionGauge;
                            if (second->airActionGauge > 360.0f) {
                                second->airActionGauge = 360.0f;
                            }
                        } else if (((work.defense->frameFlags & 0x200) > 0) && (((work.defense->attackFlags & 2) > 0) && ((work.attack->attackFlags & 2) > 0))) {
                            --work.slot->field0084;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(second->facing == -1);
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.type = 2;
                            effect.palette = 3;
                            contextOwner->EmitEffect(&effect);
                            first->attackCollisionResult = 2;
                            first->hitstopFrames = work.attack->attackerHitstopFrames;
                            second->hitstopFrames = work.attack->defenderHitstopFrames;
                            second->field0108 = second->field0108 - (int)work.attack->guardDamage;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            second->airActionGauge =
                            (float)((int)work.attack->damage / 0x1e) + (float)second->airActionGauge;
                            if (second->airActionGauge > 360.0f) {
                                second->airActionGauge = 360.0f;
                            }
                        } else if (((work.defense->frameFlags & 0x200) > 0) && ((((work.defense->attackFlags & 4) > 0) && ((work.attack->attackFlags & 4) > 0)) && (second->positionY < 0.0))) {
                            --work.slot->field0084;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(second->facing == -1);
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.type = 2;
                            effect.palette = 3;
                            contextOwner->EmitEffect(&effect);
                            first->attackCollisionResult = 2;
                            first->hitstopFrames = work.attack->attackerHitstopFrames;
                            second->hitstopFrames = work.attack->defenderHitstopFrames;
                            second->field0108 = second->field0108 - (int)work.attack->guardDamage;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            second->airActionGauge =
                            (float)((int)work.attack->damage / 0x1e) + (float)second->airActionGauge;
                            if (second->airActionGauge > 360.0f) {
                                second->airActionGauge = 360.0f;
                            }
                        } else if (second->CanGuard(work.attack, work.defense) != 0) {
                            second->field0008 =
                            ((work.attack->attackFlags & 0x10) / 16) + 0x96 +
                            ((work.attack->attackFlags & 0x20) / 32) * 2 +
                            (((second->inputY == '\x01') ||
                                (((work.attack->attackFlags & work.defense->frameFlags & 5) == 0 &&
                                (second->cpuControlled != 0)))) ? 1 : 0) * 3;
                            if (second->positionY < 0.0) {
                                second->field0008 = 0x9c;
                            }
                            second->ResetPose();
                            second->facing = -work.slot->flag0048;
                            work.slot->field0080 = 2;
                            work.slot->field0086 = work.attack->attackerHitstopFrames;
                            second->hitstopFrames = work.attack->defenderHitstopFrames;
                            first->meter += work.attack->guardMeterGain;
                            --work.slot->field0084;
                            second->outgoingPushbackActive = 0;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(first->facing < '\0');
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            second->field0108 = second->field0108 - (int)work.attack->guardDamage;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            if (first->airActionGauge > 0.0f) {
                                first->airActionGauge =
                                first->airActionGauge -
                                (float)((int)work.attack->damage / 0x1e);
                                if (first->airActionGauge < 0.0f) {
                                    second->airActionGauge = (float)second->airActionGauge - first->airActionGauge;
                                    first->airActionGauge = 0;
                                }
                            } else {
                                second->airActionGauge =
                                (float)((int)work.attack->damage / 0x1e) + (float)second->airActionGauge;
                                if (second->airActionGauge > 360.0f) {
                                    second->airActionGauge = 360.0f;
                                }
                            }
                            second->field0154 = 1;
                            effect.type = 2;
                            effect.palette = 3;
                            contextOwner->EmitEffect(&effect);
                        } else {
                            if ((((work.defense->frameFlags & 4) == 0) &&
                                (second->field0138 == 0)) ||
                                (((((work.defense->frameFlags & 4) > 0 ||
                                (0 < second->field0138)) &&
                                ((work.attack->attackFlags & 0x100) > 0)) ||
                                ((work.attack->attackFlags & 0x40) > 0)))) {
                                if (second->positionY >= 0.0) {
                                    if (work.attack->groundHitState > 0) {
                                        second->field0008 = work.attack->groundHitState;
                                    } else {
                                        if ((work.defense->frameFlags & 3) == 3) second->field0008 = 59;
                                        else if ((work.defense->frameFlags & 1) != 0) {
                                            second->field0008 = ((work.attack->attackFlags & 8) > 0) * 3 + 50
                                            + ((work.attack->attackFlags & 0x10) > 0) + ((work.attack->attackFlags & 0x20) > 0) * 2;
                                        } else if ((work.defense->frameFlags & 2) != 0) {
                                            second->field0008 = ((work.attack->attackFlags & 0x10) > 0) + 56
                                            + ((work.attack->attackFlags & 0x20) > 0) * 2;
                                        }
                                    }
                                } else {
                                    if (work.attack->airHitState > 0) second->field0008 = work.attack->airHitState;
                                    else second->field0008 = 59;
                                }
                                work.slot->field0080 = 3;
                                second->ResetPose();
                                second->facing = -work.slot->flag0048;
                            } else {
                                first->comboHitCount = 0;
                                second->SetCharacterTint(0xe9,3);
                                work.slot->field0080 = 7;
                            }
                            if ((work.defense->frameFlags & 0x10) > 0) {
                                first->comboHitCount = 0;
                                if (first->comboDamageScale > 10000.0) {
                                    first->comboDamageScale =
                                    first->comboDamageScale - 20.0;
                                } else {
                                    first->comboDamageScale = 10000.0;
                                }
                            }
                            second->knockbackVelocityX = (double)work.attack->outgoingPushbackVelocityX;
                            second->knockbackVelocityY = (double)work.attack->outgoingPushbackVelocityY;
                            second->outgoingPushbackActive = 0;
                            if (first->comboHitCount == 0) {
                                second->field010c = second->field0108;
                            }
                            second->field0108 -= (int)(work.attack->damage * first->DamageFactor() * second->HealthFactor() * first->ComboFactor());
                            second->airActionLockFrames = (short)(work.attack->airActionLockFrames * (first->comboDamageScale / 10000.0)
                                * ((((work.attack->attackFlags & 0x2000) > 0 && (work.defense->frameFlags & 0x2000) > 0) ? 1 : 0) + 1));
                            second->airActionDisabled = (unsigned int)((work.attack->attackFlags & 0x400) > 0);
                            second->knockdownOnLanding = (unsigned int)((work.attack->attackFlags & 0x800) > 0);
                            second->dashMomentumFlag = 0;
                            second->airDashCount = 0;
                            second->airActionCount = 0;
                            first->comboDamageScaleDisplay = first->comboDamageScale / 100.0;
                            first->comboDamageScale =
                            (double)((work.attack->comboDamageScale / 1000.0f) *
                                first->comboDamageScale);
                            if (first->comboDamageScale > 10000.0) {
                                first->comboDamageScale =
                                (double)((work.attack->comboDamageScale / 1000.0f) *
                                    first->comboDamageScale);
                            }
                            ++first->comboHitCount;
                            first->comboDisplayHitCount = first->comboHitCount;
                            first->comboDisplayTimer = 0xb4;
                            first->comboDamage = second->field010c - second->field0108;
                            first->meter += work.attack->hitMeterGain;
                            work.slot->field0086 = work.attack->attackerHitstopFrames;
                            second->hitstopFrames = work.attack->defenderHitstopFrames;
                            --work.slot->field0084;
                            effect.owner = 0;
                            effect.type = (short)work.attack->hitEffectType;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(first->facing < '\0');
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.palette = work.attack->hitEffectPalette;
                            contextOwner->EmitEffect(&effect);
                            if ((second->field0108 <= 0) && (second->field0140 == 0)) {
                                second->field0008 = work.attack->airHitState;
                                second->ResetPose();
                                second->FaceOpponent();
                            }
                            first->AwardComboScore(work.attack);
                        }
                    }
                }
            }
        }
    }
}

// Compare the two live effect sequence strengths after their special boxes overlap.
void Scene3::ResolveEffectClash(Secondary *first, Secondary *second, int firstIndex, int secondIndex)
{
    struct EffectClashWork {
        SurfaceRect secondBounds, firstBounds;
        SecondaryEffectSlot *secondSlot, *firstSlot;
        SecondaryFrame *attack, *defense;
    } work;
    work.firstSlot = &first->effects[firstIndex];
    work.secondSlot = &second->effects[secondIndex];
    work.attack = &first->sequences[work.firstSlot->type].data[work.firstSlot->frame];
    work.defense = &second->sequences[work.secondSlot->type].data[work.secondSlot->frame];
    if (work.firstSlot->field0080 == 0 && work.secondSlot->field0080 == 0 &&
        work.firstSlot->field0084 > 0 && work.secondSlot->field0084 > 0 &&
        first->sequences[work.firstSlot->type].field0000 > 0 &&
        second->sequences[work.secondSlot->type].field0000 > 0) {
        work.firstBounds = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.firstSlot), &work.attack->bodyBox);
        work.secondBounds = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.secondSlot), &work.defense->bodyBox);
        if (BoxesOverlap(&work.firstBounds, &work.secondBounds) != 0) {
            if (second->sequences[work.secondSlot->type].field0000 == first->sequences[work.firstSlot->type].field0000) {
                work.firstSlot->field0080 = 4;
                work.secondSlot->field0080 = 4;
            } else if (second->sequences[work.secondSlot->type].field0000 > first->sequences[work.firstSlot->type].field0000) {
                work.firstSlot->field0080 = 4;
            } else if (second->sequences[work.secondSlot->type].field0000 < first->sequences[work.firstSlot->type].field0000) {
                work.secondSlot->field0080 = 4;
            }
            if (second->sequences[work.secondSlot->type].field0000 > 1) --work.firstSlot->field0084;
            if (first->sequences[work.firstSlot->type].field0000 > 1) --work.secondSlot->field0084;
        }
    }
}

// Attack boxes against a second live effect, including delegated character damage.
void Scene3::ResolveEffectPair(Secondary *first, Secondary *second, int firstIndex, int secondIndex)
{
    struct EffectPairWork {
        SecondaryEffectSlot *secondSlot;
        int i;
        SecondaryEffectSlot *firstSlot;
        int j;
        SecondaryFrame *attack, *defense;
    } work;
    work.firstSlot = &first->effects[firstIndex];
    work.secondSlot = &second->effects[secondIndex];
    work.attack = &first->sequences[work.firstSlot->type].data[work.firstSlot->frame];
    work.defense = &second->sequences[work.secondSlot->type].data[work.secondSlot->frame];
    if (work.firstSlot->field0080 == 0 && work.firstSlot->field0084 > 0 && (work.attack->attackFlags & 0x40) == 0) {
        struct CollisionBoxes {
            int overlap[4][5];
            SurfaceRect defenseBoxes[5], attackBoxes[4];
        } boxes;
        {
            int found;
            {
                SurfaceRect intersection;
                found = 0;
                for (work.i = 0; work.i < 4; ++work.i) {
                    boxes.attackBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.firstSlot), &work.attack->attackBoxes[work.i]);
                }
                for (work.i = 0; work.i < 5; ++work.i) {
                    boxes.defenseBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.secondSlot), &work.defense->hurtBoxes[work.i]);
                }
                for (work.i = 0; work.i < 4; ++work.i) {
                    for (work.j = 0; work.j < 5; ++work.j) {
                        boxes.overlap[work.i][work.j] = BoxesOverlap(&boxes.attackBoxes[work.i], &boxes.defenseBoxes[work.j]);
                        found |= boxes.overlap[work.i][work.j];
                    }
                }
                if (found != 0) {
                    intersection = MakeSurfaceRect(-10000, -10000, 20000, 20000);
                    for (work.i = 0; work.i < 4; ++work.i) {
                        for (work.j = 0; work.j < 5; ++work.j) {
                            if (boxes.overlap[work.i][work.j] != 0) {
                                if (intersection.left < boxes.attackBoxes[work.i].left) intersection.left = boxes.attackBoxes[work.i].left;
                                if (intersection.top < boxes.attackBoxes[work.i].top) intersection.top = boxes.attackBoxes[work.i].top;
                                if (intersection.right > boxes.attackBoxes[work.i].right) intersection.right = boxes.attackBoxes[work.i].right;
                                if (intersection.bottom > boxes.attackBoxes[work.i].bottom) intersection.bottom = boxes.attackBoxes[work.i].bottom;
                                if (intersection.left < boxes.defenseBoxes[work.j].left) intersection.left = boxes.defenseBoxes[work.j].left;
                                if (intersection.top < boxes.defenseBoxes[work.j].top) intersection.top = boxes.defenseBoxes[work.j].top;
                                if (intersection.right > boxes.defenseBoxes[work.j].right) intersection.right = boxes.defenseBoxes[work.j].right;
                                if (intersection.bottom > boxes.defenseBoxes[work.j].bottom) intersection.bottom = boxes.defenseBoxes[work.j].bottom;
                            }
                        }
                    }
                    if ((work.defense->frameFlags & 0x10) == 0) {
                        --work.firstSlot->field0084;
                        work.firstSlot->field0080 = 5;
                    }
                    work.secondSlot->field0080 = 5;
                    if ((work.defense->frameFlags & 0x2000) > 0) {
                        // This path overwrites the live effect frame with the character frame.
                        *work.defense = second->sequences[second->field0008].data[second->field000a];
                        if (((work.defense->frameFlags & 4) == 0 && second->field0138 == 0) ||
                            (((work.defense->frameFlags & 4) > 0 || second->field0138 > 0) && (work.attack->attackFlags & 0x100) > 0) ||
                            (work.attack->attackFlags & 0x40) > 0) {
                            if (second->positionY >= 0.0) {
                                if (work.attack->groundHitState > 0) {
                                    second->field0008 = work.attack->groundHitState;
                                } else if ((work.defense->frameFlags & 3) == 3) {
                                    second->field0008 = 59;
                                } else if ((work.defense->frameFlags & 1) != 0) {
                                    second->field0008 = ((work.attack->attackFlags & 8) > 0) * 3 + 50
                                    + ((work.attack->attackFlags & 0x10) > 0) + ((work.attack->attackFlags & 0x20) > 0) * 2;
                                } else if ((work.defense->frameFlags & 2) != 0) {
                                    second->field0008 = ((work.attack->attackFlags & 0x10) > 0) + 56 + ((work.attack->attackFlags & 0x20) > 0) * 2;
                                }
                            } else {
                                if (work.attack->airHitState > 0) second->field0008 = work.attack->airHitState;
                                else second->field0008 = 59;
                            }
                            second->ResetPose();
                            second->FaceOpponent();
                        } else {
                            first->comboHitCount = 0;
                            second->SetCharacterTint(0xdf, 2);
                        }
                        if ((work.defense->frameFlags & 0x10) > 0) {
                            first->comboHitCount = 0;
                            if (first->comboDamageScale > 10000.0) first->comboDamageScale = first->comboDamageScale - 20.0;
                            else first->comboDamageScale = 10000.0;
                        }
                        second->knockbackVelocityX = (double)work.attack->outgoingPushbackVelocityX;
                        second->knockbackVelocityY = (double)work.attack->outgoingPushbackVelocityY;
                        second->outgoingPushbackActive = 1;
                        if (first->comboHitCount == 0) second->field010c = second->field0108;
                        second->field0108 -= (int)(work.attack->damage * first->DamageFactor() * second->HealthFactor() * first->ComboFactor());
                        second->airActionLockFrames = (short)(work.attack->airActionLockFrames * (first->comboDamageScale / 10000.0 * 0.8));
                        second->airActionDisabled = (work.attack->attackFlags & 0x400) > 0;
                        second->knockdownOnLanding = (work.attack->attackFlags & 0x800) > 0;
                        second->dashMomentumFlag = 0;
                        second->airDashCount = 0;
                        second->airActionCount = 0;
                        first->comboDamageScaleDisplay = first->comboDamageScale / 100.0;
                        first->comboDamageScale = (work.attack->comboDamageScale / 1000.0f) * first->comboDamageScale;
                        if (first->comboDamageScale > 10000.0) first->comboDamageScale = (work.attack->comboDamageScale / 1000.0f) * first->comboDamageScale;
                        ++first->comboHitCount;
                        first->comboDisplayHitCount = first->comboHitCount;
                        first->comboDisplayTimer = 180;
                        first->comboDamage = second->field010c - second->field0108;
                        first->meter += work.attack->hitMeterGain;
                        first->hitstopFrames = work.attack->attackerHitstopFrames;
                        second->hitstopFrames = work.attack->defenderHitstopFrames;
                        if (second->field0108 <= 0 && second->field0140 == 0) {
                            second->field0008 = work.attack->airHitState;
                            second->ResetPose();
                            second->FaceOpponent();
                        }
                        first->AwardComboScore(work.attack);
                    }
                    EffectSpawn effect;
                    effect.owner = 0;
                    effect.type = (short)work.attack->hitEffectType;
                    effect.x = (double)((intersection.right + intersection.left) / 2);
                    effect.y = (double)((intersection.bottom + intersection.top) / 2);
                    effect.facing = (unsigned int)(first->facing < 0);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.payload = 0;
                    effect.palette = work.attack->hitEffectPalette;
                    contextOwner->EmitEffect(&effect);
                }
            }
        }
    }
}

// Character attack snapshot against a live effect; copied defense remains local.
void Scene3::ResolveBodyEffect(Secondary *first, Secondary *second, BattleCollisionSnapshot *firstPose, BattleCollisionSnapshot *secondPose, int index)
{
    struct BodyEffectWork {
        SecondaryEffectSlot *slot;
        int i, j;
        SecondaryFrame *attack;
    } work;
    work.slot = &second->effects[index];
    work.attack = &firstPose->frame;
    if (first->attackCollisionResult == 0 && first->remainingHitCount > 0 && (work.attack->attackFlags & 0x40) == 0) {
        struct CollisionBoxes {
            int overlap[4][5];
            SurfaceRect defenseBoxes[5];
            SecondaryFrame defense;
            SurfaceRect attackBoxes[4];
        } boxes;
        {
            int found;
            {
                SurfaceRect intersection;
                boxes.defense = second->sequences[work.slot->type].data[work.slot->frame];
                found = 0;
                for (work.i = 0; work.i < 4; ++work.i) {
                    boxes.attackBoxes[work.i] = TransformSnapshotBox(firstPose, &work.attack->attackBoxes[work.i]);
                }
                for (work.i = 0; work.i < 5; ++work.i) {
                    boxes.defenseBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.slot), &boxes.defense.hurtBoxes[work.i]);
                }
                for (work.i = 0; work.i < 4; ++work.i) {
                    for (work.j = 0; work.j < 5; ++work.j) {
                        boxes.overlap[work.i][work.j] = BoxesOverlap(&boxes.attackBoxes[work.i], &boxes.defenseBoxes[work.j]);
                        found |= boxes.overlap[work.i][work.j];
                    }
                }
                if (found != 0) {
                    intersection = MakeSurfaceRect(-10000, -10000, 20000, 20000);
                    for (work.i = 0; work.i < 4; ++work.i) {
                        for (work.j = 0; work.j < 5; ++work.j) {
                            if (boxes.overlap[work.i][work.j] != 0) {
                                if (intersection.left < boxes.attackBoxes[work.i].left) intersection.left = boxes.attackBoxes[work.i].left;
                                if (intersection.top < boxes.attackBoxes[work.i].top) intersection.top = boxes.attackBoxes[work.i].top;
                                if (intersection.right > boxes.attackBoxes[work.i].right) intersection.right = boxes.attackBoxes[work.i].right;
                                if (intersection.bottom > boxes.attackBoxes[work.i].bottom) intersection.bottom = boxes.attackBoxes[work.i].bottom;
                                if (intersection.left < boxes.defenseBoxes[work.j].left) intersection.left = boxes.defenseBoxes[work.j].left;
                                if (intersection.top < boxes.defenseBoxes[work.j].top) intersection.top = boxes.defenseBoxes[work.j].top;
                                if (intersection.right > boxes.defenseBoxes[work.j].right) intersection.right = boxes.defenseBoxes[work.j].right;
                                if (intersection.bottom > boxes.defenseBoxes[work.j].bottom) intersection.bottom = boxes.defenseBoxes[work.j].bottom;
                            }
                        }
                    }
                    if ((boxes.defense.frameFlags & 0x10) == 0) {
                        --first->remainingHitCount;
                        first->attackCollisionResult = 5;
                    }
                    work.slot->field0080 = 5;
                    if ((boxes.defense.frameFlags & 0x2000) > 0) {
                        // Body attacks replace only the local defense copy.
                        boxes.defense = secondPose->frame;
                        if (((boxes.defense.frameFlags & 4) == 0 && second->field0138 == 0) ||
                            (((boxes.defense.frameFlags & 4) > 0 || second->field0138 > 0) && (work.attack->attackFlags & 0x100) > 0) ||
                            (work.attack->attackFlags & 0x40) > 0) {
                            if (second->positionY >= 0.0) {
                                if (work.attack->groundHitState > 0) {
                                    second->field0008 = work.attack->groundHitState;
                                } else if ((boxes.defense.frameFlags & 3) == 3) {
                                    second->field0008 = 59;
                                } else if ((boxes.defense.frameFlags & 1) != 0) {
                                    second->field0008 = ((work.attack->attackFlags & 8) > 0) * 3 + 50
                                    + ((work.attack->attackFlags & 0x10) > 0) + ((work.attack->attackFlags & 0x20) > 0) * 2;
                                } else if ((boxes.defense.frameFlags & 2) != 0) {
                                    second->field0008 = ((work.attack->attackFlags & 0x10) > 0) + 56 + ((work.attack->attackFlags & 0x20) > 0) * 2;
                                }
                            } else {
                                if (work.attack->airHitState > 0) second->field0008 = work.attack->airHitState;
                                else second->field0008 = 59;
                            }
                            second->ResetPose();
                            second->FaceOpponent();
                        } else {
                            first->comboHitCount = 0;
                            second->SetCharacterTint(0xdf, 2);
                        }
                        if ((boxes.defense.frameFlags & 0x10) > 0) {
                            first->comboHitCount = 0;
                            if (first->comboDamageScale > 10000.0) first->comboDamageScale = first->comboDamageScale - 20.0;
                            else first->comboDamageScale = 10000.0;
                        }
                        second->knockbackVelocityX = (double)work.attack->outgoingPushbackVelocityX;
                        second->knockbackVelocityY = (double)work.attack->outgoingPushbackVelocityY;
                        second->outgoingPushbackActive = 1;
                        if (first->comboHitCount == 0) second->field010c = second->field0108;
                        second->field0108 -= (int)(work.attack->damage * first->DamageFactor() * second->HealthFactor() * first->ComboFactor());
                        second->airActionLockFrames = (short)(work.attack->airActionLockFrames * (first->comboDamageScale / 10000.0 * 0.8));
                        second->airActionDisabled = (work.attack->attackFlags & 0x400) > 0;
                        second->knockdownOnLanding = (work.attack->attackFlags & 0x800) > 0;
                        second->dashMomentumFlag = 0;
                        second->airDashCount = 0;
                        second->airActionCount = 0;
                        first->comboDamageScaleDisplay = first->comboDamageScale / 100.0;
                        first->comboDamageScale = (work.attack->comboDamageScale / 1000.0f) * first->comboDamageScale;
                        if (first->comboDamageScale > 10000.0) first->comboDamageScale = (work.attack->comboDamageScale / 1000.0f) * first->comboDamageScale;
                        ++first->comboHitCount;
                        first->comboDisplayHitCount = first->comboHitCount;
                        first->comboDisplayTimer = 180;
                        first->comboDamage = second->field010c - second->field0108;
                        first->meter += work.attack->hitMeterGain;
                        first->hitstopFrames = work.attack->attackerHitstopFrames;
                        second->hitstopFrames = work.attack->defenderHitstopFrames;
                        if (second->field0108 <= 0 && second->field0140 == 0) {
                            second->field0008 = work.attack->airHitState;
                            second->ResetPose();
                            second->FaceOpponent();
                        }
                        first->AwardComboScore(work.attack);
                    }
                    EffectSpawn effect;
                    effect.owner = 0;
                    effect.type = (short)work.attack->hitEffectType;
                    effect.x = (double)((intersection.right + intersection.left) / 2);
                    effect.y = (double)((intersection.bottom + intersection.top) / 2);
                    effect.facing = (unsigned int)(first->facing < 0);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.payload = 0;
                    effect.palette = work.attack->hitEffectPalette;
                    contextOwner->EmitEffect(&effect);
                }
            }
        }
    }
}
