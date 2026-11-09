// Complete battle body-hit outcomes and character tint request.
#include "SceneBattle.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Scene3::ResolveBodyHit(Secondary *first, Secondary *second,
    BattleCollisionSnapshot *firstPose, BattleCollisionSnapshot *secondPose)
{
    struct HitPass {
        int j, found;
        int overlap[4][5];
        SurfaceRect defenseBoxes[5];
        SecondaryFrame firstFrame, secondFrame;
        SurfaceRect attackBoxes[4];
    } work;
    work.found = 0;
    work.firstFrame = firstPose->frame;
    work.secondFrame = secondPose->frame;
    {
        EffectSpawn effect;
        {
            SurfaceRect intersection;
            {
                int i;
                {
                    SurfaceRect specialBounds;
                    for (i = 0; i < 4; ++i) {
                        work.attackBoxes[i] = TransformSnapshotBox(firstPose, &work.firstFrame.attackBoxes[i]);
                    }
                    for (i = 0; i < 5; ++i) {
                        work.defenseBoxes[i] = TransformSnapshotBox(secondPose, &work.secondFrame.hurtBoxes[i]);
                    }
                    specialBounds = TransformSnapshotBox(secondPose, &work.secondFrame.bodyBox);
                    if (firstPose->state == 0 && (work.secondFrame.frameFlags & 0x20) == 0 &&
                        firstPose->command > 0 &&
                        !(second->field0130 > 0 && (work.firstFrame.attackFlags & 0x40) > 0) &&
                        second->AirActionReady() == 0 && second->field013c == 0) {
                        if ((work.firstFrame.attackFlags & 0x40) > 0) {
                            for (i = 0; i < 4; ++i) {
                                work.overlap[i][0] = 1;
                                work.found |= BoxesOverlap(&work.attackBoxes[i], &specialBounds);
                            }
                        } else {
                            for (i = 0; i < 4; ++i) {
                                for (work.j = 0; work.j < 5; ++work.j) {
                                    work.overlap[i][work.j] = BoxesOverlap(&work.attackBoxes[i], &work.defenseBoxes[work.j]);
                                    work.found |= work.overlap[i][work.j];
                                }
                            }
                        }
                        if (work.found != 0) {
                            intersection = MakeSurfaceRect(-10000, -10000, 20000, 20000);
                            for (i = 0; i < 4; ++i) {
                                for (work.j = 0; work.j < 5; ++work.j) {
                                    if (work.overlap[i][work.j] != 0) {
                                        if (intersection.left < work.attackBoxes[i].left) intersection.left = work.attackBoxes[i].left;
                                        if (intersection.top < work.attackBoxes[i].top) intersection.top = work.attackBoxes[i].top;
                                        if (intersection.right > work.attackBoxes[i].right) intersection.right = work.attackBoxes[i].right;
                                        if (intersection.bottom > work.attackBoxes[i].bottom) intersection.bottom = work.attackBoxes[i].bottom;
                                        if (intersection.left < work.defenseBoxes[work.j].left) intersection.left = work.defenseBoxes[work.j].left;
                                        if (intersection.top < work.defenseBoxes[work.j].top) intersection.top = work.defenseBoxes[work.j].top;
                                        if (intersection.right > work.defenseBoxes[work.j].right) intersection.right = work.defenseBoxes[work.j].right;
                                        if (intersection.bottom > work.defenseBoxes[work.j].bottom) intersection.bottom = work.defenseBoxes[work.j].bottom;
                                    }
                                }
                            }
                            if (((((work.secondFrame.frameFlags & 0x1000) > 0) && ((work.firstFrame.attackFlags & 0x100) == 0)) && ((work.firstFrame.attackFlags & 1) > 0))) {
                                --first->field016c;
                                first->field0168 = 2;
                                first->field0168 = 6;
                                second->field0168 = 6;
                            } else if (((((work.secondFrame.frameFlags & 0x800) > 0) && ((work.firstFrame.attackFlags & 0x100) == 0)) && ((work.firstFrame.attackFlags & 2) > 0))) {
                                --first->field016c;
                                first->field0168 = 2;
                                first->field0168 = 6;
                                second->field0168 = 6;
                            } else if ((((second->field0170 != 0) && (second->field014e >= 0x1e)) && ((second->field013a == 0) && ((second->GuardInput(&work.firstFrame) != 0) && ((work.firstFrame.attackFlags & 0x80) == 0))))) {
                                first->field0168 = 2;
                                first->meter += work.firstFrame.guardMeterGain;
                                --first->field016c;
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
                                second->FaceOpponent();
                                if (second->positionY == 0.0) {
                                    second->field0008 = 0xa8 + (second->inputY == 1);
                                } else {
                                    second->field0008 = 0xaa;
                                }
                                first->ClearInputHistory();
                                second->ClearInputHistory();
                                second->hitstunFrames = 0x3c;
                                second->field0170 = 0;
                                first->field0170 = 1;
                            } else if ((((second->field014e >= 0x1e) && (second->positionY < 0.0)) && (second->CanGuard(&work.firstFrame,&work.secondFrame) != 0))) {
                                first->field0168 = 2;
                                first->meter += work.firstFrame.guardMeterGain;
                                --first->field016c;
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
                                second->FaceOpponent();
                                second->field0008 = 0xaa;
                                first->ClearInputHistory();
                                second->ClearInputHistory();
                                second->hitstunFrames = 0x3c;
                                first->field0170 = 1;
                            } else if ((((second->CanGuard(&work.firstFrame,&work.secondFrame) != 0) && (second->field014e >= 0x1e)) && ((second->positionY == 0.0) && ((second->field0008 != 0xa8) && (second->field0008 != 0xa9))))) {
                                first->field0168 = 2;
                                first->meter += work.firstFrame.guardMeterGain;
                                --first->field016c;
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
                                second->FaceOpponent();
                                second->field0008 =
                                0xa8 + (second->inputY == 1);
                                first->ClearInputHistory();
                                second->ClearInputHistory();
                                second->hitstunFrames = 0x3c;
                                first->field0170 = 1;
                            } else if ((((work.secondFrame.frameFlags & 0x200) > 0) && (((work.secondFrame.attackFlags & 1) > 0) && ((work.firstFrame.attackFlags & 1) > 0)))) {
                                --first->field016c;
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
                                first->hitstopFrames = work.firstFrame.attackerHitstopFrames;
                                second->hitstopFrames = work.firstFrame.defenderHitstopFrames;
                                second->field0108 = second->field0108 - (int)work.firstFrame.guardDamage;
                                if (second->field0108 <= 0) {
                                    second->field0108 = 1;
                                }
                                second->field0134 = (float)((int)work.firstFrame.damage / 0x1e) + (float)second->field0134;
                                if (second->field0134 > 360.0f) {
                                    second->field0134 = 360.0f;
                                }
                            } else if ((((work.secondFrame.frameFlags & 0x200) > 0) && (((work.secondFrame.attackFlags & 2) > 0) && ((work.firstFrame.attackFlags & 2) > 0)))) {
                                --first->field016c;
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
                                first->hitstopFrames = work.firstFrame.attackerHitstopFrames;
                                second->hitstopFrames = work.firstFrame.defenderHitstopFrames;
                                second->field0108 = second->field0108 - (int)work.firstFrame.guardDamage;
                                if (second->field0108 <= 0) {
                                    second->field0108 = 1;
                                }
                                second->field0134 = (float)((int)work.firstFrame.damage / 0x1e) + (float)second->field0134;
                                if (second->field0134 > 360.0f) {
                                    second->field0134 = 360.0f;
                                }
                            } else if ((((work.secondFrame.frameFlags & 0x200) > 0) && ((((work.secondFrame.attackFlags & 4) > 0) && ((work.firstFrame.attackFlags & 4) > 0)) && (second->positionY < 0.0)))) {
                                --first->field016c;
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
                                first->hitstopFrames = work.firstFrame.attackerHitstopFrames;
                                second->hitstopFrames = work.firstFrame.defenderHitstopFrames;
                                second->field0108 = second->field0108 - (int)work.firstFrame.guardDamage;
                                if (second->field0108 <= 0) {
                                    second->field0108 = 1;
                                }
                            } else if ((second->CanGuard(&work.firstFrame,&work.secondFrame) != 0)) {
                                first->field0168 = 2;
                                first->meter += work.firstFrame.guardMeterGain;
                                --first->field016c;
                                second->outgoingPushbackActive = 1;
                                effect.owner = 0;
                                effect.x = (double)((intersection.right + intersection.left) / 2);
                                effect.y = (double)((intersection.bottom + intersection.top) / 2);
                                effect.facing = (unsigned int)(second->facing == -1);
                                effect.group = 2;
                                effect.layer = 1;
                                effect.payload = 0;
                                second->field0008 =
                                ((work.firstFrame.attackFlags & 0x10) / 16) + 0x96 +
                                ((work.firstFrame.attackFlags & 0x20) / 32) * 2 + (((second->inputY == '\x01') ||
                                    (((work.firstFrame.attackFlags & work.secondFrame.frameFlags & 5) == 0 && (second->cpuControlled != 0)))) ? 1 : 0) * 3;
                                if (second->positionY < 0.0) {
                                    second->field0008 = 0x9c;
                                }
                                second->ResetPose();
                                second->FaceOpponent();
                                first->hitstopFrames = work.firstFrame.attackerHitstopFrames;
                                second->hitstopFrames = work.firstFrame.defenderHitstopFrames;
                                second->field0108 = second->field0108 - (int)work.firstFrame.guardDamage;
                                if (second->field0108 <= 0) {
                                    second->field0108 = 1;
                                }
                                if (first->field0134 > 0.0f) {
                                    first->field0134 =
                                    first->field0134 - (float)((int)work.firstFrame.damage / 0x1e);
                                    if (first->field0134 < 0.0f) {
                                        second->field0134 = (float)second->field0134 - first->field0134;
                                        first->field0134 = 0;
                                    }
                                } else {
                                    second->field0134 = (float)((int)work.firstFrame.damage / 0x1e) + (float)second->field0134;
                                    if (second->field0134 > 360.0f) {
                                        second->field0134 = 360.0f;
                                    }
                                }
                                second->field0154 = 0;
                                effect.type = 2;
                                effect.palette = 3;
                                contextOwner->EmitEffect(&effect);
                            } else {
                                if (((work.secondFrame.frameFlags & 4) == 0 && second->field0138 == 0) ||
                                    (((work.secondFrame.frameFlags & 4) > 0 || second->field0138 > 0) && (work.firstFrame.attackFlags & 0x100) > 0) ||
                                    (work.firstFrame.attackFlags & 0x40) > 0) {
                                    if (second->positionY >= 0.0) {
                                        if (work.firstFrame.groundHitState > 0) {
                                            second->field0008 = work.firstFrame.groundHitState;
                                        } else if ((work.secondFrame.frameFlags & 3) == 3) {
                                            second->field0008 = 59;
                                        } else if ((work.secondFrame.frameFlags & 1) != 0) {
                                            second->field0008 = ((work.firstFrame.attackFlags & 8) > 0) * 3 + 50
                                            + ((work.firstFrame.attackFlags & 0x10) > 0) + ((work.firstFrame.attackFlags & 0x20) > 0) * 2;
                                        } else if ((work.secondFrame.frameFlags & 2) != 0) {
                                            second->field0008 = ((work.firstFrame.attackFlags & 0x10) > 0) + 56
                                            + ((work.firstFrame.attackFlags & 0x20) > 0) * 2;
                                        }
                                    } else {
                                        if (work.firstFrame.airHitState > 0) second->field0008 = work.firstFrame.airHitState;
                                        else second->field0008 = 59;
                                    }
                                    first->field0168 = 3;
                                    second->ResetPose();
                                    second->FaceOpponent();
                                } else {
                                    first->field0174 = 0;
                                    second->SetCharacterTint(0xdf,3);
                                    first->field0168 = 7;
                                }
                                if ((work.secondFrame.frameFlags & 0x10) > 0) {
                                    first->field0174 = 0;
                                    if (first->field0178 > 10000.0) {
                                        first->field0178 =
                                        first->field0178 - 20.0;
                                    } else {
                                        first->field0178 = 10000.0;
                                    }
                                }
                                second->knockbackVelocityX = (double)work.firstFrame.outgoingPushbackVelocityX;
                                second->knockbackVelocityY = (double)work.firstFrame.outgoingPushbackVelocityY;
                                second->outgoingPushbackActive = 1;
                                if (first->field0174 == 0) {
                                    second->field010c = second->field0108;
                                }
                                first->field0144 = (((work.firstFrame.attackFlags & 0x2000) > 0) && ((work.secondFrame.frameFlags & 0x2000) > 0)) ? 1 : 0;
                                second->field0108 -= (int)(work.firstFrame.damage * first->DamageFactor() * second->HealthFactor() * first->ComboFactor());
                                second->field0124 = (short)(work.firstFrame.airActionLockFrames * (first->field0178 / 10000.0 * 0.8));
                                second->field0128 = (unsigned int)((work.firstFrame.attackFlags & 0x400) > 0);
                                second->field012c = (unsigned int)((work.firstFrame.attackFlags & 0x800) > 0);
                                second->field0158 = 0;
                                second->field0159 = 0;
                                second->field015a = 0;
                                first->field00f8 = first->field0178 / 100.0;
                                first->field0178 =
                                (double)((work.firstFrame.comboDamageScale / 1000.0f) *
                                    first->field0178);
                                if (first->field0178 > 10000.0) {
                                    first->field0178 =
                                    (double)((work.firstFrame.comboDamageScale / 1000.0f) *
                                        first->field0178);
                                }
                                ++first->field0174;
                                first->field00f4 = first->field0174;
                                first->field0104 = 0xb4;
                                first->field0100 = second->field010c - second->field0108;
                                first->meter += work.firstFrame.hitMeterGain;
                                first->hitstopFrames = work.firstFrame.attackerHitstopFrames;
                                second->hitstopFrames = work.firstFrame.defenderHitstopFrames;
                                --first->field016c;
                                effect.owner = 0;
                                effect.type = (short)work.firstFrame.hitEffectType;
                                effect.x = (double)((intersection.right + intersection.left) / 2);
                                effect.y = (double)((intersection.bottom + intersection.top) / 2);
                                effect.facing = (unsigned int)(first->facing < '\0');
                                effect.group = 2;
                                effect.layer = 1;
                                effect.payload = 0;
                                effect.palette = work.firstFrame.hitEffectPalette;
                                contextOwner->EmitEffect(&effect);
                                if ((second->field0108 <= 0) && (second->field0140 == 0)) {
                                    second->field0008 = work.firstFrame.airHitState;
                                    second->ResetPose();
                                    second->FaceOpponent();
                                }
                                first->AwardComboScore(&work.firstFrame);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Secondary::SetCharacterTint(unsigned char value, int duration)
{
    tint30b8 = value;
    field30bc = duration;
    if (contextOwner->setting136c == 0) {
        field30bc = field30bc / 2;
    }
}
