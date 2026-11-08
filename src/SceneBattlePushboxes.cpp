// Asymmetric two-player pushbox separation and velocity response.
#include "SceneBattle.h"
#include "SceneBattleGlobals.h"

void Scene3::ResolvePushboxes()
{
    {
        SurfaceRect firstBox;
        SurfaceRect secondBox;
        struct VelocityLocals { double secondVelocity; double firstVelocity; double average; } velocity;

    velocity.firstVelocity = this->secondary[0]->field0030;
    velocity.secondVelocity = this->secondary[1]->field0030;
    this->secondary[0]->field00b0 = collisionZero;
    this->secondary[1]->field00b0 = collisionZero;
    {
        if (this->secondary[0] != 0) poses.first = (SecondaryPose *)((int)this->secondary[0] + 8);
        else poses.first = 0;
        firstBox = this->TransformPoseBox(poses.first,
            &this->secondary[0]->sequences[this->secondary[0]->field0008].data[this->secondary[0]->field000a].box0090);
        if (this->secondary[1] != 0) poses.second = (SecondaryPose *)((int)this->secondary[1] + 8);
        else poses.second = 0;
        secondBox = this->TransformPoseBox(poses.second,
            &this->secondary[1]->sequences[this->secondary[1]->field0008].data[this->secondary[1]->field000a].box0090);
    }
    if (this->BoxesOverlap(&firstBox, &secondBox) != 0) {
        int displacement;
        if ((firstBox.left + firstBox.right) -
            (secondBox.left + secondBox.right) > 0) {
            volatile int leftBefore, leftAfter;
            if (this->secondary[0]->field0020 <= collisionLeftBoundary) leftBefore = 1; else leftBefore = 0;
            displacement = secondBox.left - firstBox.right;
            this->secondary[0]->field0020 = (double)displacement / collisionTwo + this->secondary[0]->field0020;
            this->secondary[1]->field0020 = this->secondary[1]->field0020 - (double)displacement / collisionTwo;
            if (this->secondary[0]->field0020 > collisionLeftBoundary) leftAfter = 1; else leftAfter = 0;
            if (this->secondary[0]->CollisionSide() == -1) {
                velocity.firstVelocity = (double)((double)(int)this->secondary[0]->facing * velocity.firstVelocity < collisionZero) * velocity.firstVelocity;
                velocity.secondVelocity = (double)((double)(int)this->secondary[0]->facing * velocity.firstVelocity +
                    (double)(int)this->secondary[1]->facing * velocity.secondVelocity < collisionZero) * velocity.secondVelocity;
                if ((double)(int)this->secondary[1]->facing * velocity.secondVelocity >
                    (double)(int)this->secondary[0]->facing * velocity.firstVelocity) {
                    velocity.average = ((double)(int)this->secondary[0]->facing * velocity.firstVelocity +
                        (double)(int)this->secondary[1]->facing * velocity.secondVelocity) / collisionTwo;
                                        this->secondary[0]->field00b0 = velocity.firstVelocity - this->secondary[0]->field0030;
                    velocity.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * velocity.average;
                    this->secondary[1]->field00b0 = velocity.secondVelocity - this->secondary[1]->field0030;
                }
            } else {
                if (this->secondary[1]->CollisionSide() == 1) {
                    velocity.secondVelocity = (double)(collisionZero < (double)(int)this->secondary[1]->facing * velocity.secondVelocity) * velocity.secondVelocity;
                    velocity.firstVelocity = (double)(collisionZero <
                        (double)(int)this->secondary[1]->facing * velocity.secondVelocity +
                        (double)(int)this->secondary[0]->facing * velocity.firstVelocity) * velocity.firstVelocity;
                    if ((double)(int)this->secondary[0]->facing * velocity.firstVelocity <
                        (double)(int)this->secondary[1]->facing * velocity.secondVelocity) {
                        velocity.average = ((double)(int)this->secondary[0]->facing * velocity.firstVelocity +
                            (double)(int)this->secondary[1]->facing * velocity.secondVelocity) / collisionTwo;
                        this->secondary[0]->field00b0 = (double)(int)this->secondary[0]->facing * velocity.average - this->secondary[0]->field0030;
                        this->secondary[1]->field00b0 = velocity.secondVelocity - this->secondary[1]->field0030;
                    }
                } else {
                    velocity.average = (double)(int)this->secondary[1]->facing * velocity.secondVelocity;
                    if ((velocity.average <= collisionZero) &&
                        (collisionZero <= (double)(int)this->secondary[0]->facing * velocity.firstVelocity)) {
                        velocity.average = ((double)(int)this->secondary[1]->facing * velocity.secondVelocity +
                            (double)(int)this->secondary[0]->facing * velocity.firstVelocity) / collisionTwo;
                                                velocity.firstVelocity = (double)(int)this->secondary[0]->facing * velocity.average;
                    this->secondary[0]->field00b0 = velocity.firstVelocity - this->secondary[0]->field0030;
                        velocity.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * velocity.average;
                    this->secondary[1]->field00b0 = velocity.secondVelocity - this->secondary[1]->field0030;
                        return;
                    }
                }
            }
        } else {
            volatile int rightBefore, rightAfter;
            if (this->secondary[1]->field0020 >= collisionRightBoundary) rightBefore = 1; else rightBefore = 0;
            displacement = secondBox.right - firstBox.left;
            this->secondary[0]->field0020 = (double)displacement / collisionTwo + this->secondary[0]->field0020;
            this->secondary[1]->field0020 = this->secondary[1]->field0020 - (double)displacement / collisionTwo;
            if (this->secondary[1]->field0020 < collisionRightBoundary) rightAfter = 1; else rightAfter = 0;
            if (this->secondary[0]->CollisionSide() == 1) {
                velocity.firstVelocity = (double)(collisionZero < (double)(int)this->secondary[0]->facing * velocity.firstVelocity) * velocity.firstVelocity;
                velocity.secondVelocity = (double)(collisionZero <
                    (double)(int)this->secondary[0]->facing * velocity.firstVelocity +
                    (double)(int)this->secondary[1]->facing * velocity.secondVelocity) * velocity.secondVelocity;
                if ((double)(int)this->secondary[1]->facing * velocity.secondVelocity <
                    (double)(int)this->secondary[0]->facing * velocity.firstVelocity) {
                    velocity.average = ((double)(int)this->secondary[0]->facing * velocity.firstVelocity +
                        (double)(int)this->secondary[1]->facing * velocity.secondVelocity) / collisionTwo;
                                        this->secondary[0]->field00b0 = velocity.firstVelocity - this->secondary[0]->field0030;
                    velocity.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * velocity.average;
                    this->secondary[1]->field00b0 = velocity.secondVelocity - this->secondary[1]->field0030;
                }
            } else {
                if (this->secondary[1]->CollisionSide() == -1) {
                    velocity.secondVelocity = (double)((double)(int)this->secondary[1]->facing * velocity.secondVelocity < collisionZero) * velocity.secondVelocity;
                    velocity.firstVelocity = (double)((double)(int)this->secondary[1]->facing * velocity.secondVelocity +
                        (double)(int)this->secondary[0]->facing * velocity.firstVelocity < collisionZero) * velocity.firstVelocity;
                    if ((double)(int)this->secondary[0]->facing * velocity.firstVelocity >
                        (double)(int)this->secondary[1]->facing * velocity.secondVelocity) {
                        velocity.average = ((double)(int)this->secondary[0]->facing * velocity.firstVelocity +
                            (double)(int)this->secondary[1]->facing * velocity.secondVelocity) / collisionTwo;
                                                velocity.firstVelocity = (double)(int)this->secondary[0]->facing * velocity.average;
                    this->secondary[0]->field00b0 = velocity.firstVelocity - this->secondary[0]->field0030;
                        this->secondary[1]->field00b0 = velocity.secondVelocity - this->secondary[1]->field0030;
                    }
                } else if ((collisionZero <= (double)(int)this->secondary[1]->facing * velocity.secondVelocity) &&
                    ((double)(int)this->secondary[0]->facing * velocity.firstVelocity) <= collisionZero) {
                    velocity.average = ((double)(int)this->secondary[1]->facing * velocity.secondVelocity +
                        (double)(int)this->secondary[0]->facing * velocity.firstVelocity) / collisionTwo;
                                        velocity.firstVelocity = (double)(int)this->secondary[0]->facing * velocity.average;
                    this->secondary[0]->field00b0 = velocity.firstVelocity - this->secondary[0]->field0030;
                    velocity.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * velocity.average;
                    this->secondary[1]->field00b0 = velocity.secondVelocity - this->secondary[1]->field0030;
                }
            }
        }
    }
    }
}
