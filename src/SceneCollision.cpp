// Battle collision snapshots, dispatch, world-space transforms and contact tests.
#include "SceneBattle.h"

SurfaceRect Scene3::TransformPoseBox(const SecondaryPose *pose, const SurfaceRect *box)
{
    short offsetX;
    {
        SurfaceRect result;
        offsetX = pose->patterns[pose->field0008].frames[pose->field000a].u;
        {
            short offsetY = pose->patterns[pose->field0008].frames[pose->field000a].v;
            if (pose->facing == 1) {
                result.top = (int)(pose->positionY - offsetY + box->top);
                result.bottom = (int)(pose->positionY - offsetY + box->bottom);
                result.left = (int)(pose->positionX - 0.5 - offsetX + box->left);
                result.right = (int)(pose->positionX - 0.5 - offsetX + box->right);
            } else {
                result.top = (int)(pose->positionY - offsetY + box->top);
                result.bottom = (int)(pose->positionY - offsetY + box->bottom);
                result.left = (int)(pose->positionX + 0.5 + offsetX - box->right);
                result.right = (int)(pose->positionX + 0.5 + offsetX - box->left);
            }
            return result;
        }
    }
}

SurfaceRect Scene3::TransformSnapshotBox(const BattleCollisionSnapshot *pose, const SurfaceRect *box)
{
    short offsetX;
    {
        SurfaceRect result;
        offsetX = pose->sprite.u;
        {
            short offsetY = pose->sprite.v;
            if (pose->facing == 1) {
                result.top = (int)(pose->y - offsetY + box->top);
                result.bottom = (int)(pose->y - offsetY + box->bottom);
                result.left = (int)(pose->x - 0.5 - offsetX + box->left);
                result.right = (int)(pose->x - 0.5 - offsetX + box->right);
            } else {
                result.top = (int)(pose->y - offsetY + box->top);
                result.bottom = (int)(pose->y - offsetY + box->bottom);
                result.left = (int)(pose->x + 0.5 + offsetX - box->right);
                result.right = (int)(pose->x + 0.5 + offsetX - box->left);
            }
            return result;
        }
    }
}

int Scene3::BoxesOverlap(const SurfaceRect *first, const SurfaceRect *second)
{
    if (first->right <= first->left || first->top >= first->bottom ||
        second->right <= second->left || second->top >= second->bottom) return 0;
    return ~((second->right - first->left) | (first->right - second->left) |
        (second->bottom - first->top) | (first->bottom - second->top)) >> 31;
}

void Scene3::DispatchCollisions()
{
    struct CollisionPass {
        int j, secondResult;
        BattleCollisionSnapshot first;
        int i, firstResult;
        BattleCollisionSnapshot second;
    } pass;
    pass.first.frame = secondary[0]->sequences[secondary[0]->field0008].data[secondary[0]->field000a];
    pass.first.sprite = secondary[0]->patterns[secondary[0]->field0008].frames[secondary[0]->field000a];
    pass.first.x = secondary[0]->positionX;
    pass.first.y = secondary[0]->positionY;
    pass.first.facing = secondary[0]->facing;
    pass.second.frame = secondary[1]->sequences[secondary[1]->field0008].data[secondary[1]->field000a];
    pass.second.sprite = secondary[1]->patterns[secondary[1]->field0008].frames[secondary[1]->field000a];
    pass.second.x = secondary[1]->positionX;
    pass.second.y = secondary[1]->positionY;
    pass.second.facing = secondary[1]->facing;
    pass.firstResult = TestBodyInteraction(secondary[0], secondary[1], &pass.first, &pass.second);
    pass.secondResult = TestBodyInteraction(secondary[1], secondary[0], &pass.second, &pass.first);
    secondary[0]->field0144 = 0;
    secondary[1]->field0144 = 0;
    pass.i = secondary[0]->effectRead;
    while (pass.i != secondary[0]->effectWrite) {
        pass.j = secondary[1]->effectRead;
        while (pass.j != secondary[1]->effectWrite) {
            if (secondary[0]->effectActive[pass.i] != 0 && secondary[1]->effectActive[pass.j] != 0) {
                ResolveEffectClash(secondary[0], secondary[1], pass.i, pass.j);
            }
            ++pass.j;
            if (pass.j >= 64) pass.j = 0;
        }
        ++pass.i;
        if (pass.i >= 64) pass.i = 0;
    }
    pass.i = secondary[0]->effectRead;
    while (pass.i != secondary[0]->effectWrite) {
        pass.j = secondary[1]->effectRead;
        while (pass.j != secondary[1]->effectWrite) {
            if (secondary[0]->effectActive[pass.i] != 0 && secondary[1]->effectActive[pass.j] != 0) {
                ResolveEffectPair(secondary[0], secondary[1], pass.i, pass.j);
                ResolveEffectPair(secondary[1], secondary[0], pass.j, pass.i);
            }
            ++pass.j;
            if (pass.j >= 64) pass.j = 0;
        }
        ++pass.i;
        if (pass.i >= 64) pass.i = 0;
    }
    pass.i = secondary[1]->effectRead;
    while (pass.i != secondary[1]->effectWrite) {
        if (secondary[1]->effectActive[pass.i] != 0) {
            ResolveEffectHit(secondary[1], secondary[0], pass.i, &pass.first);
            ResolveBodyEffect(secondary[0], secondary[1], &pass.first, &pass.second, pass.i);
        }
        ++pass.i;
        if (pass.i >= 64) pass.i = 0;
    }
    pass.i = secondary[0]->effectRead;
    while (pass.i != secondary[0]->effectWrite) {
        if (secondary[0]->effectActive[pass.i] != 0) {
            ResolveEffectHit(secondary[0], secondary[1], pass.i, &pass.second);
            ResolveBodyEffect(secondary[1], secondary[0], &pass.second, &pass.first, pass.i);
        }
        ++pass.i;
        if (pass.i >= 64) pass.i = 0;
    }
    pass.first.state = (char)secondary[0]->field0168;
    pass.first.command = secondary[0]->field016c;
    pass.second.state = (char)secondary[1]->field0168;
    pass.second.command = secondary[1]->field016c;
    if (pass.secondResult == 0) ResolveBodyHit(secondary[0], secondary[1], &pass.first, &pass.second);
    if (pass.firstResult == 0) ResolveBodyHit(secondary[1], secondary[0], &pass.second, &pass.first);
}

extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

int Scene3::TestBodyInteraction(Secondary *first, Secondary *second,
    const BattleCollisionSnapshot *firstPose, const BattleCollisionSnapshot *secondPose)
{
    struct ContactPass {
        SurfaceRect intersection;
        int j, found;
        int overlap[4][5];
        SurfaceRect defenseBoxes[5];
        SecondaryFrame firstFrame, secondFrame;
        SurfaceRect attackBoxes[4];
    } pass;
    pass.found = 0;
    {
        int i;
        {
            SurfaceRect specialBounds;
            pass.firstFrame = firstPose->frame;
            pass.secondFrame = secondPose->frame;
            for (i = 0; i < 4; ++i) {
                pass.attackBoxes[i] = TransformSnapshotBox(firstPose, &pass.firstFrame.attackBoxes[i]);
            }
            for (i = 0; i < 5; ++i) {
                pass.defenseBoxes[i] = TransformSnapshotBox(secondPose, &pass.secondFrame.hurtBoxes[i]);
            }
            specialBounds = TransformSnapshotBox(secondPose, &pass.secondFrame.bodyBox);
            if (first->field0168 == 0 && (pass.secondFrame.frameFlags & 0x20) == 0 &&
                first->field016c > 0 &&
                !(second->field0130 > 0 && (pass.firstFrame.attackFlags & 0x40) > 0) &&
                second->AirActionReady() == 0 && second->field013c == 0) {
                if ((pass.firstFrame.attackFlags & 0x40) > 0) {
                    for (i = 0; i < 4; ++i) {
                        pass.overlap[i][0] = 1;
                        pass.found |= BoxesOverlap(&pass.attackBoxes[i], &specialBounds);
                    }
                } else {
                    for (i = 0; i < 4; ++i) {
                        for (pass.j = 0; pass.j < 5; ++pass.j) {
                            pass.overlap[i][pass.j] = BoxesOverlap(&pass.attackBoxes[i], &pass.defenseBoxes[pass.j]);
                            pass.found |= pass.overlap[i][pass.j];
                        }
                    }
                }
                if (pass.found != 0) {
                    pass.intersection = MakeSurfaceRect(-10000, -10000, 20000, 20000);
                    for (i = 0; i < 4; ++i) {
                        for (pass.j = 0; pass.j < 5; ++pass.j) {
                            if (pass.overlap[i][pass.j] != 0) {
                                if (pass.intersection.left < pass.attackBoxes[i].left) pass.intersection.left = pass.attackBoxes[i].left;
                                if (pass.intersection.top < pass.attackBoxes[i].top) pass.intersection.top = pass.attackBoxes[i].top;
                                if (pass.intersection.right > pass.attackBoxes[i].right) pass.intersection.right = pass.attackBoxes[i].right;
                                if (pass.intersection.bottom > pass.attackBoxes[i].bottom) pass.intersection.bottom = pass.attackBoxes[i].bottom;
                                if (pass.intersection.left < pass.defenseBoxes[pass.j].left) pass.intersection.left = pass.defenseBoxes[pass.j].left;
                                if (pass.intersection.top < pass.defenseBoxes[pass.j].top) pass.intersection.top = pass.defenseBoxes[pass.j].top;
                                if (pass.intersection.right > pass.defenseBoxes[pass.j].right) pass.intersection.right = pass.defenseBoxes[pass.j].right;
                                if (pass.intersection.bottom > pass.defenseBoxes[pass.j].bottom) pass.intersection.bottom = pass.defenseBoxes[pass.j].bottom;
                            }
                        }
                    }
                    if (second->field0170 != 0 && second->field014e >= 30 && second->field013a == 0 &&
                        second->GuardInput(&pass.firstFrame) != 0 && (pass.firstFrame.attackFlags & 0x80) == 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }
}
