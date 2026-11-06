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
    if (work.slot->field0080 == 0 && (work.defense->field00b0 & 0x20) == 0 &&
        work.slot->field0084 > 0 &&
        !(second->field0130 > 0 && (work.attack->field00aa & 0x40) > 0) &&
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
                        boxes.attackBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.slot), &work.attack->boxes0050[work.i]);
                    }
                    for (work.i = 0; work.i < 5; ++work.i) {
                        boxes.defenseBoxes[work.i] = TransformSnapshotBox(pose, &work.defense->boxes0000[work.i]);
                    }
                    specialBounds = TransformSnapshotBox(pose, &work.defense->box0090);
                    if ((work.attack->field00aa & 0x40) > 0) {
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
                        if (((work.defense->field00b0 & 0x400) > 0) && ((work.attack->field00aa & 0x100) == 0)) {
                            --work.slot->field0084;
                            work.slot->field0080 = 2;
                            first->field0168 = 6;
                            second->field0168 = 6;
                        } else if (((second->field0170 != 0) && (((second->field014e >= 0x1e) && (second->field013a == 0)) && (second->GuardInput(work.attack) != 0))) && ((work.attack->field00aa & 0x80) == 0)) {
                            work.slot->field0080 = 2;
                            first->field0148 += work.attack->field00b6;
                            --work.slot->field0084;
                            second->field00d0 = 1;
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
                            if (second->field0028 == 0.0) {
                                second->field0008 = 0xa8 + (second->inputY == 1);
                            } else {
                                second->field0008 = 0xaa;
                            }
                            first->ClearInputHistory();
                            second->ClearInputHistory();
                            second->field014c = 0x3c;
                            second->field0170 = 0;
                            first->field0170 = 1;
                        } else if (((second->field014e >= 0x1e) && (second->field0028 < 0.0)) && (second->CanGuard(work.attack, work.defense) != 0)) {
                            work.slot->field0080 = 2;
                            first->field0148 += work.attack->field00b6;
                            --work.slot->field0084;
                            second->field00d0 = 1;
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
                            second->field014c = 0x3c;
                            first->field0170 = 1;
                        } else if (((second->CanGuard(work.attack, work.defense) != 0) && (second->field014e >= 0x1e)) && ((second->field0028 == 0.0) && ((second->field0008 != 0xa8) && (second->field0008 != 0xa9)))) {
                            work.slot->field0080 = 2;
                            first->field0148 += work.attack->field00b6;
                            --work.slot->field0084;
                            second->field00d0 = 1;
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
                            second->field014c = 0x3c;
                            first->field0170 = 1;
                        } else if (((work.defense->field00b0 & 0x200) > 0) && (((work.defense->field00aa & 1) > 0) && ((work.attack->field00aa & 1) > 0))) {
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
                            first->field0168 = 2;
                            first->field014a = work.attack->field00c2;
                            second->field014a = work.attack->field00c4;
                            second->field0108 = second->field0108 - (int)work.attack->field00a8;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            second->field0134 =
                            (float)((int)work.attack->field00a0 / 0x1e) + (float)second->field0134;
                            if (second->field0134 > 360.0f) {
                                second->field0134 = 360.0f;
                            }
                        } else if (((work.defense->field00b0 & 0x200) > 0) && (((work.defense->field00aa & 2) > 0) && ((work.attack->field00aa & 2) > 0))) {
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
                            first->field0168 = 2;
                            first->field014a = work.attack->field00c2;
                            second->field014a = work.attack->field00c4;
                            second->field0108 = second->field0108 - (int)work.attack->field00a8;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            second->field0134 =
                            (float)((int)work.attack->field00a0 / 0x1e) + (float)second->field0134;
                            if (second->field0134 > 360.0f) {
                                second->field0134 = 360.0f;
                            }
                        } else if (((work.defense->field00b0 & 0x200) > 0) && ((((work.defense->field00aa & 4) > 0) && ((work.attack->field00aa & 4) > 0)) && (second->field0028 < 0.0))) {
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
                            first->field0168 = 2;
                            first->field014a = work.attack->field00c2;
                            second->field014a = work.attack->field00c4;
                            second->field0108 = second->field0108 - (int)work.attack->field00a8;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            second->field0134 =
                            (float)((int)work.attack->field00a0 / 0x1e) + (float)second->field0134;
                            if (second->field0134 > 360.0f) {
                                second->field0134 = 360.0f;
                            }
                        } else if (second->CanGuard(work.attack, work.defense) != 0) {
                            second->field0008 =
                            ((work.attack->field00aa & 0x10) / 16) + 0x96 +
                            ((work.attack->field00aa & 0x20) / 32) * 2 +
                            (((second->inputY == '\x01') ||
                                (((work.attack->field00aa & work.defense->field00b0 & 5) == 0 &&
                                (second->cpuControlled != 0)))) ? 1 : 0) * 3;
                            if (second->field0028 < 0.0) {
                                second->field0008 = 0x9c;
                            }
                            second->ResetPose();
                            second->facing = -work.slot->flag0048;
                            work.slot->field0080 = 2;
                            work.slot->field0086 = work.attack->field00c2;
                            second->field014a = work.attack->field00c4;
                            first->field0148 += work.attack->field00b6;
                            --work.slot->field0084;
                            second->field00d0 = 0;
                            effect.owner = 0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(first->facing < '\0');
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            second->field0108 = second->field0108 - (int)work.attack->field00a8;
                            if (second->field0108 <= 0) {
                                second->field0108 = 1;
                            }
                            if (first->field0134 > 0.0f) {
                                first->field0134 =
                                first->field0134 -
                                (float)((int)work.attack->field00a0 / 0x1e);
                                if (first->field0134 < 0.0f) {
                                    second->field0134 = (float)second->field0134 - first->field0134;
                                    first->field0134 = 0;
                                }
                            } else {
                                second->field0134 =
                                (float)((int)work.attack->field00a0 / 0x1e) + (float)second->field0134;
                                if (second->field0134 > 360.0f) {
                                    second->field0134 = 360.0f;
                                }
                            }
                            second->field0154 = 1;
                            effect.type = 2;
                            effect.palette = 3;
                            contextOwner->EmitEffect(&effect);
                        } else {
                            if ((((work.defense->field00b0 & 4) == 0) &&
                                (second->field0138 == 0)) ||
                                (((((work.defense->field00b0 & 4) > 0 ||
                                (0 < second->field0138)) &&
                                ((work.attack->field00aa & 0x100) > 0)) ||
                                ((work.attack->field00aa & 0x40) > 0)))) {
                                if (second->field0028 >= 0.0) {
                                    if (work.attack->field00ae > 0) {
                                        second->field0008 = work.attack->field00ae;
                                    } else {
                                        if ((work.defense->field00b0 & 3) == 3) second->field0008 = 59;
                                        else if ((work.defense->field00b0 & 1) != 0) {
                                            second->field0008 = ((work.attack->field00aa & 8) > 0) * 3 + 50
                                            + ((work.attack->field00aa & 0x10) > 0) + ((work.attack->field00aa & 0x20) > 0) * 2;
                                        } else if ((work.defense->field00b0 & 2) != 0) {
                                            second->field0008 = ((work.attack->field00aa & 0x10) > 0) + 56
                                            + ((work.attack->field00aa & 0x20) > 0) * 2;
                                        }
                                    }
                                } else {
                                    if (work.attack->field00ac > 0) second->field0008 = work.attack->field00ac;
                                    else second->field0008 = 59;
                                }
                                work.slot->field0080 = 3;
                                second->ResetPose();
                                second->facing = -work.slot->flag0048;
                            } else {
                                first->field0174 = 0;
                                second->SetCharacterTint(0xe9,3);
                                work.slot->field0080 = 7;
                            }
                            if ((work.defense->field00b0 & 0x10) > 0) {
                                first->field0174 = 0;
                                if (first->field0178 > 10000.0) {
                                    first->field0178 =
                                    first->field0178 - 20.0;
                                } else {
                                    first->field0178 = 10000.0;
                                }
                            }
                            second->field00c0 = (double)work.attack->field00b8;
                            second->field00c8 = (double)work.attack->field00bc;
                            second->field00d0 = 0;
                            if (first->field0174 == 0) {
                                second->field010c = second->field0108;
                            }
                            second->field0108 -= (int)(work.attack->field00a0 * first->DamageFactor() * second->HealthFactor() * first->ComboFactor());
                            second->field0124 = (short)(work.attack->field00b2 * (first->field0178 / 10000.0)
                                * ((((work.attack->field00aa & 0x2000) > 0 && (work.defense->field00b0 & 0x2000) > 0) ? 1 : 0) + 1));
                            second->field0128 = (unsigned int)((work.attack->field00aa & 0x400) > 0);
                            second->field012c = (unsigned int)((work.attack->field00aa & 0x800) > 0);
                            second->field0158 = 0;
                            second->field0159 = 0;
                            second->field015a = 0;
                            first->field00f8 = first->field0178 / 100.0;
                            first->field0178 =
                            (double)((work.attack->field00a4 / 1000.0f) *
                                first->field0178);
                            if (first->field0178 > 10000.0) {
                                first->field0178 =
                                (double)((work.attack->field00a4 / 1000.0f) *
                                    first->field0178);
                            }
                            ++first->field0174;
                            first->field00f4 = first->field0174;
                            first->field0104 = 0xb4;
                            first->field0100 = second->field010c - second->field0108;
                            first->field0148 += work.attack->field00b4;
                            work.slot->field0086 = work.attack->field00c2;
                            second->field014a = work.attack->field00c4;
                            --work.slot->field0084;
                            effect.owner = 0;
                            effect.type = (short)work.attack->field00c0;
                            effect.x = (double)((intersection.right + intersection.left) / 2);
                            effect.y = (double)((intersection.bottom + intersection.top) / 2);
                            effect.facing = (unsigned int)(first->facing < '\0');
                            effect.group = 2;
                            effect.layer = 1;
                            effect.payload = 0;
                            effect.palette = work.attack->field00c1;
                            contextOwner->EmitEffect(&effect);
                            if ((second->field0108 <= 0) && (second->field0140 == 0)) {
                                second->field0008 = work.attack->field00ac;
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
        work.firstBounds = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.firstSlot), &work.attack->box0090);
        work.secondBounds = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.secondSlot), &work.defense->box0090);
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
    if (work.firstSlot->field0080 == 0 && work.firstSlot->field0084 > 0 && (work.attack->field00aa & 0x40) == 0) {
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
                    boxes.attackBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.firstSlot), &work.attack->boxes0050[work.i]);
                }
                for (work.i = 0; work.i < 5; ++work.i) {
                    boxes.defenseBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.secondSlot), &work.defense->boxes0000[work.i]);
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
                    if ((work.defense->field00b0 & 0x10) == 0) {
                        --work.firstSlot->field0084;
                        work.firstSlot->field0080 = 5;
                    }
                    work.secondSlot->field0080 = 5;
                    if ((work.defense->field00b0 & 0x2000) > 0) {
                        // This path overwrites the live effect frame with the character frame.
                        *work.defense = second->sequences[second->field0008].data[second->field000a];
                        if (((work.defense->field00b0 & 4) == 0 && second->field0138 == 0) ||
                            (((work.defense->field00b0 & 4) > 0 || second->field0138 > 0) && (work.attack->field00aa & 0x100) > 0) ||
                            (work.attack->field00aa & 0x40) > 0) {
                            if (second->field0028 >= 0.0) {
                                if (work.attack->field00ae > 0) {
                                    second->field0008 = work.attack->field00ae;
                                } else if ((work.defense->field00b0 & 3) == 3) {
                                    second->field0008 = 59;
                                } else if ((work.defense->field00b0 & 1) != 0) {
                                    second->field0008 = ((work.attack->field00aa & 8) > 0) * 3 + 50
                                    + ((work.attack->field00aa & 0x10) > 0) + ((work.attack->field00aa & 0x20) > 0) * 2;
                                } else if ((work.defense->field00b0 & 2) != 0) {
                                    second->field0008 = ((work.attack->field00aa & 0x10) > 0) + 56 + ((work.attack->field00aa & 0x20) > 0) * 2;
                                }
                            } else {
                                if (work.attack->field00ac > 0) second->field0008 = work.attack->field00ac;
                                else second->field0008 = 59;
                            }
                            second->ResetPose();
                            second->FaceOpponent();
                        } else {
                            first->field0174 = 0;
                            second->SetCharacterTint(0xdf, 2);
                        }
                        if ((work.defense->field00b0 & 0x10) > 0) {
                            first->field0174 = 0;
                            if (first->field0178 > 10000.0) first->field0178 = first->field0178 - 20.0;
                            else first->field0178 = 10000.0;
                        }
                        second->field00c0 = (double)work.attack->field00b8;
                        second->field00c8 = (double)work.attack->field00bc;
                        second->field00d0 = 1;
                        if (first->field0174 == 0) second->field010c = second->field0108;
                        second->field0108 -= (int)(work.attack->field00a0 * first->DamageFactor() * second->HealthFactor() * first->ComboFactor());
                        second->field0124 = (short)(work.attack->field00b2 * (first->field0178 / 10000.0 * 0.8));
                        second->field0128 = (work.attack->field00aa & 0x400) > 0;
                        second->field012c = (work.attack->field00aa & 0x800) > 0;
                        second->field0158 = 0;
                        second->field0159 = 0;
                        second->field015a = 0;
                        first->field00f8 = first->field0178 / 100.0;
                        first->field0178 = (work.attack->field00a4 / 1000.0f) * first->field0178;
                        if (first->field0178 > 10000.0) first->field0178 = (work.attack->field00a4 / 1000.0f) * first->field0178;
                        ++first->field0174;
                        first->field00f4 = first->field0174;
                        first->field0104 = 180;
                        first->field0100 = second->field010c - second->field0108;
                        first->field0148 += work.attack->field00b4;
                        first->field014a = work.attack->field00c2;
                        second->field014a = work.attack->field00c4;
                        if (second->field0108 <= 0 && second->field0140 == 0) {
                            second->field0008 = work.attack->field00ac;
                            second->ResetPose();
                            second->FaceOpponent();
                        }
                        first->AwardComboScore(work.attack);
                    }
                    EffectSpawn effect;
                    effect.owner = 0;
                    effect.type = (short)work.attack->field00c0;
                    effect.x = (double)((intersection.right + intersection.left) / 2);
                    effect.y = (double)((intersection.bottom + intersection.top) / 2);
                    effect.facing = (unsigned int)(first->facing < 0);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.payload = 0;
                    effect.palette = work.attack->field00c1;
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
    if (first->field0168 == 0 && first->field016c > 0 && (work.attack->field00aa & 0x40) == 0) {
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
                    boxes.attackBoxes[work.i] = TransformSnapshotBox(firstPose, &work.attack->boxes0050[work.i]);
                }
                for (work.i = 0; work.i < 5; ++work.i) {
                    boxes.defenseBoxes[work.i] = TransformPoseBox(reinterpret_cast<const SecondaryPose *>(work.slot), &boxes.defense.boxes0000[work.i]);
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
                    if ((boxes.defense.field00b0 & 0x10) == 0) {
                        --first->field016c;
                        first->field0168 = 5;
                    }
                    work.slot->field0080 = 5;
                    if ((boxes.defense.field00b0 & 0x2000) > 0) {
                        // Body attacks replace only the local defense copy.
                        boxes.defense = secondPose->frame;
                        if (((boxes.defense.field00b0 & 4) == 0 && second->field0138 == 0) ||
                            (((boxes.defense.field00b0 & 4) > 0 || second->field0138 > 0) && (work.attack->field00aa & 0x100) > 0) ||
                            (work.attack->field00aa & 0x40) > 0) {
                            if (second->field0028 >= 0.0) {
                                if (work.attack->field00ae > 0) {
                                    second->field0008 = work.attack->field00ae;
                                } else if ((boxes.defense.field00b0 & 3) == 3) {
                                    second->field0008 = 59;
                                } else if ((boxes.defense.field00b0 & 1) != 0) {
                                    second->field0008 = ((work.attack->field00aa & 8) > 0) * 3 + 50
                                    + ((work.attack->field00aa & 0x10) > 0) + ((work.attack->field00aa & 0x20) > 0) * 2;
                                } else if ((boxes.defense.field00b0 & 2) != 0) {
                                    second->field0008 = ((work.attack->field00aa & 0x10) > 0) + 56 + ((work.attack->field00aa & 0x20) > 0) * 2;
                                }
                            } else {
                                if (work.attack->field00ac > 0) second->field0008 = work.attack->field00ac;
                                else second->field0008 = 59;
                            }
                            second->ResetPose();
                            second->FaceOpponent();
                        } else {
                            first->field0174 = 0;
                            second->SetCharacterTint(0xdf, 2);
                        }
                        if ((boxes.defense.field00b0 & 0x10) > 0) {
                            first->field0174 = 0;
                            if (first->field0178 > 10000.0) first->field0178 = first->field0178 - 20.0;
                            else first->field0178 = 10000.0;
                        }
                        second->field00c0 = (double)work.attack->field00b8;
                        second->field00c8 = (double)work.attack->field00bc;
                        second->field00d0 = 1;
                        if (first->field0174 == 0) second->field010c = second->field0108;
                        second->field0108 -= (int)(work.attack->field00a0 * first->DamageFactor() * second->HealthFactor() * first->ComboFactor());
                        second->field0124 = (short)(work.attack->field00b2 * (first->field0178 / 10000.0 * 0.8));
                        second->field0128 = (work.attack->field00aa & 0x400) > 0;
                        second->field012c = (work.attack->field00aa & 0x800) > 0;
                        second->field0158 = 0;
                        second->field0159 = 0;
                        second->field015a = 0;
                        first->field00f8 = first->field0178 / 100.0;
                        first->field0178 = (work.attack->field00a4 / 1000.0f) * first->field0178;
                        if (first->field0178 > 10000.0) first->field0178 = (work.attack->field00a4 / 1000.0f) * first->field0178;
                        ++first->field0174;
                        first->field00f4 = first->field0174;
                        first->field0104 = 180;
                        first->field0100 = second->field010c - second->field0108;
                        first->field0148 += work.attack->field00b4;
                        first->field014a = work.attack->field00c2;
                        second->field014a = work.attack->field00c4;
                        if (second->field0108 <= 0 && second->field0140 == 0) {
                            second->field0008 = work.attack->field00ac;
                            second->ResetPose();
                            second->FaceOpponent();
                        }
                        first->AwardComboScore(work.attack);
                    }
                    EffectSpawn effect;
                    effect.owner = 0;
                    effect.type = (short)work.attack->field00c0;
                    effect.x = (double)((intersection.right + intersection.left) / 2);
                    effect.y = (double)((intersection.bottom + intersection.top) / 2);
                    effect.facing = (unsigned int)(first->facing < 0);
                    effect.group = 2;
                    effect.layer = 1;
                    effect.payload = 0;
                    effect.palette = work.attack->field00c1;
                    contextOwner->EmitEffect(&effect);
                }
            }
        }
    }
}
