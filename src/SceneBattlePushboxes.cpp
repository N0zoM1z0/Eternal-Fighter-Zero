// Asymmetric two-player pushbox separation and velocity response.
#include "SceneBattle.h"
#include "SceneBattleGlobals.h"

void Scene3::ResolvePushboxes()
{
    {
        int displacement;
        struct PushboxLocals { SurfaceRect first; SurfaceRect second; double secondVelocity; double firstVelocity; double average; } locals;

    locals.firstVelocity = this->secondary[0]->field0030;
    locals.secondVelocity = this->secondary[1]->field0030;
    this->secondary[0]->field00b0 = collisionZero;
    this->secondary[1]->field00b0 = collisionZero;
    {
        locals.first = this->TransformPoseBox(
            this->secondary[0] != 0 ? (SecondaryPose *)((int)this->secondary[0] + 8) : 0,
            &this->secondary[0]->sequences[this->secondary[0]->field0008].data[this->secondary[0]->field000a].box0090);
        locals.second = this->TransformPoseBox(
            this->secondary[1] != 0 ? (SecondaryPose *)((int)this->secondary[1] + 8) : 0,
            &this->secondary[1]->sequences[this->secondary[1]->field0008].data[this->secondary[1]->field000a].box0090);
    }
    if (this->BoxesOverlap(&locals.first, &locals.second) != 0) {
        if ((locals.first.left + locals.first.right) -
            (locals.second.left + locals.second.right) > 0) {
            volatile int leftBefore, leftAfter;
            displacement = locals.second.right - locals.first.left;
            if (this->secondary[0]->field0020 <= collisionLeftBoundary) leftBefore = 1; else leftBefore = 0;
            this->secondary[0]->field0020 = this->secondary[0]->field0020 + (double)displacement / collisionTwo;
            if (this->secondary[0]->field0020 > collisionLeftBoundary) leftAfter = 1; else leftAfter = 0;
            this->secondary[1]->field0020 = this->secondary[1]->field0020 - (double)displacement / collisionTwo;
            if (this->secondary[0]->CollisionSide() == -1) {
                locals.firstVelocity = (double)((double)(int)this->secondary[0]->facing * locals.firstVelocity < collisionZero) * locals.firstVelocity;
                locals.secondVelocity = (double)((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                    (double)(int)this->secondary[1]->facing * locals.secondVelocity < collisionZero) * locals.secondVelocity;
                if ((double)(int)this->secondary[0]->facing * locals.firstVelocity <
                    (double)(int)this->secondary[1]->facing * locals.secondVelocity) {
                    locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                    locals.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * locals.average;
                    this->secondary[0]->field00b0 = locals.firstVelocity - this->secondary[0]->field0030;
                    this->secondary[1]->field00b0 = locals.secondVelocity - this->secondary[1]->field0030;
                }
            } else {
                if (this->secondary[1]->CollisionSide() == 1) {
                    locals.secondVelocity = (double)(collisionZero < (double)(int)this->secondary[1]->facing * locals.secondVelocity) * locals.secondVelocity;
                    locals.firstVelocity = (double)(collisionZero <
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity +
                        (double)(int)this->secondary[0]->facing * locals.firstVelocity) * locals.firstVelocity;
                    if ((double)(int)this->secondary[0]->facing * locals.firstVelocity >
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity) {
                        locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                            (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                        locals.firstVelocity = (double)(int)this->secondary[0]->facing * locals.average;
                        this->secondary[0]->field00b0 = locals.firstVelocity - this->secondary[0]->field0030;
                        this->secondary[1]->field00b0 = locals.secondVelocity - this->secondary[1]->field0030;
                    }
                } else {
                    if ((collisionZero <= (double)(int)this->secondary[1]->facing * locals.secondVelocity) &&
                        ((double)(int)this->secondary[0]->facing * locals.firstVelocity < collisionZero)) {
                        locals.average = ((double)(int)this->secondary[1]->facing * locals.secondVelocity +
                            (double)(int)this->secondary[0]->facing * locals.firstVelocity) / collisionTwo;
                        locals.firstVelocity = (double)(int)this->secondary[0]->facing * locals.average;
                        locals.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * locals.average;
                        this->secondary[0]->field00b0 = locals.firstVelocity - this->secondary[0]->field0030;
                        this->secondary[1]->field00b0 = locals.secondVelocity - this->secondary[1]->field0030;
                        return;
                    }
                }
            }
        } else {
            volatile int rightBefore, rightAfter;
            displacement = locals.second.left - locals.first.right;
            if (this->secondary[1]->field0020 >= collisionRightBoundary) rightBefore = 1; else rightBefore = 0;
            this->secondary[0]->field0020 = this->secondary[0]->field0020 + (double)displacement / collisionTwo;
            if (this->secondary[1]->field0020 < collisionRightBoundary) rightAfter = 1; else rightAfter = 0;
            this->secondary[1]->field0020 = this->secondary[1]->field0020 - (double)displacement / collisionTwo;
            if (this->secondary[0]->CollisionSide() == 1) {
                locals.firstVelocity = (double)(collisionZero < (double)(int)this->secondary[0]->facing * locals.firstVelocity) * locals.firstVelocity;
                locals.secondVelocity = (double)(collisionZero <
                    (double)(int)this->secondary[0]->facing * locals.firstVelocity +
                    (double)(int)this->secondary[1]->facing * locals.secondVelocity) * locals.secondVelocity;
                if ((double)(int)this->secondary[0]->facing * locals.firstVelocity >
                    (double)(int)this->secondary[1]->facing * locals.secondVelocity) {
                    locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                    locals.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * locals.average;
                    this->secondary[0]->field00b0 = locals.firstVelocity - this->secondary[0]->field0030;
                    this->secondary[1]->field00b0 = locals.secondVelocity - this->secondary[1]->field0030;
                }
            } else {
                if (this->secondary[1]->CollisionSide() == -1) {
                    locals.secondVelocity = (double)((double)(int)this->secondary[1]->facing * locals.secondVelocity < collisionZero) * locals.secondVelocity;
                    locals.firstVelocity = (double)((double)(int)this->secondary[1]->facing * locals.secondVelocity +
                        (double)(int)this->secondary[0]->facing * locals.firstVelocity < collisionZero) * locals.firstVelocity;
                    if ((double)(int)this->secondary[0]->facing * locals.firstVelocity <
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity) {
                        locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                            (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                                                locals.firstVelocity = (double)(int)this->secondary[0]->facing * locals.average;
                    this->secondary[0]->field00b0 = locals.firstVelocity - this->secondary[0]->field0030;
                        this->secondary[1]->field00b0 = locals.secondVelocity - this->secondary[1]->field0030;
                    }
                } else if (((double)(int)this->secondary[1]->facing * locals.secondVelocity < collisionZero) &&
                    (collisionZero <= (double)(int)this->secondary[0]->facing * locals.firstVelocity)) {
                    locals.average = ((double)(int)this->secondary[1]->facing * locals.secondVelocity +
                        (double)(int)this->secondary[0]->facing * locals.firstVelocity) / collisionTwo;
                    locals.firstVelocity = (double)(int)this->secondary[0]->facing * locals.average;
                    locals.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * locals.average;
                    this->secondary[0]->field00b0 = locals.firstVelocity - this->secondary[0]->field0030;
                    this->secondary[1]->field00b0 = locals.secondVelocity - this->secondary[1]->field0030;
                }
            }
        }
    }
    }
}
