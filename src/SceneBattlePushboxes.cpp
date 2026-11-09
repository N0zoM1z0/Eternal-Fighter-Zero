// Asymmetric two-player pushbox separation and velocity response.
#include "SceneBattle.h"
#include "SceneBattleGlobals.h"

void Scene3::ResolvePushboxes()
{
    {
        int displacement;
        struct PushboxLocals { SurfaceRect first; SurfaceRect second; double secondVelocity; double firstVelocity; double average; } locals;

    locals.firstVelocity = this->secondary[0]->velocityX;
    locals.secondVelocity = this->secondary[1]->velocityX;
    this->secondary[0]->velocityXCorrection = collisionZero;
    this->secondary[1]->velocityXCorrection = collisionZero;
    {
        locals.first = this->TransformPoseBox(
            this->secondary[0] != 0 ? (SecondaryPose *)((int)this->secondary[0] + 8) : 0,
            &this->secondary[0]->sequences[this->secondary[0]->field0008].data[this->secondary[0]->field000a].bodyBox);
        locals.second = this->TransformPoseBox(
            this->secondary[1] != 0 ? (SecondaryPose *)((int)this->secondary[1] + 8) : 0,
            &this->secondary[1]->sequences[this->secondary[1]->field0008].data[this->secondary[1]->field000a].bodyBox);
    }
    // Leave the boundary tests as discarded conditional expressions. VC7.1
    // places their compiler-generated temporaries after the pose-box returns;
    // naming local flags changes the stack layout of this function.
    if (this->BoxesOverlap(&locals.first, &locals.second) != 0) {
        if ((locals.first.left + locals.first.right) -
            (locals.second.left + locals.second.right) > 0) {
            displacement = locals.second.right - locals.first.left;
            (this->secondary[0]->positionX <= collisionLeftBoundary) ? 1 : 0;
            this->secondary[0]->positionX = this->secondary[0]->positionX + (double)displacement / collisionTwo;
            (this->secondary[0]->positionX > collisionLeftBoundary) ? 1 : 0;
            this->secondary[1]->positionX = this->secondary[1]->positionX - (double)displacement / collisionTwo;
            if (this->secondary[0]->CollisionSide() == -1) {
                locals.firstVelocity = (double)((double)(int)this->secondary[0]->facing * locals.firstVelocity < collisionZero) * locals.firstVelocity;
                locals.secondVelocity = (double)((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                    (double)(int)this->secondary[1]->facing * locals.secondVelocity < collisionZero) * locals.secondVelocity;
                if ((double)(int)this->secondary[0]->facing * locals.firstVelocity <
                    (double)(int)this->secondary[1]->facing * locals.secondVelocity) {
                    locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                    locals.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * locals.average;
                    this->secondary[0]->velocityXCorrection = locals.firstVelocity - this->secondary[0]->velocityX;
                    this->secondary[1]->velocityXCorrection = locals.secondVelocity - this->secondary[1]->velocityX;
                }
                return;
            } else {
                if (this->secondary[1]->CollisionSide() == 1) {
                    locals.secondVelocity = (double)(collisionZero < (double)(int)this->secondary[1]->facing * locals.secondVelocity) * locals.secondVelocity;
                    locals.firstVelocity = (double)(collisionZero <
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity +
                        (double)(int)this->secondary[0]->facing * locals.firstVelocity) * locals.firstVelocity;
                    if ((double)(int)this->secondary[1]->facing * locals.secondVelocity >
                        (double)(int)this->secondary[0]->facing * locals.firstVelocity) {
                        locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                            (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                        locals.firstVelocity = (double)(int)this->secondary[0]->facing * locals.average;
                        this->secondary[0]->velocityXCorrection = locals.firstVelocity - this->secondary[0]->velocityX;
                        this->secondary[1]->velocityXCorrection = locals.secondVelocity - this->secondary[1]->velocityX;
                    }
                    return;
                } else {
                    if ((collisionZero <= (double)(int)this->secondary[1]->facing * locals.secondVelocity) &&
                        ((double)(int)this->secondary[0]->facing * locals.firstVelocity <= collisionZero)) {
                        locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                            (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                        locals.firstVelocity = (double)(int)this->secondary[0]->facing * locals.average;
                        locals.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * locals.average;
                        this->secondary[0]->velocityXCorrection = locals.firstVelocity - this->secondary[0]->velocityX;
                        this->secondary[1]->velocityXCorrection = locals.secondVelocity - this->secondary[1]->velocityX;
                        return;
                    }
                }
            }
        } else {
            displacement = locals.second.left - locals.first.right;
            (this->secondary[1]->positionX >= collisionRightBoundary) ? 1 : 0;
            this->secondary[0]->positionX = this->secondary[0]->positionX + (double)displacement / collisionTwo;
            (this->secondary[1]->positionX < collisionRightBoundary) ? 1 : 0;
            this->secondary[1]->positionX = this->secondary[1]->positionX - (double)displacement / collisionTwo;
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
                    this->secondary[0]->velocityXCorrection = locals.firstVelocity - this->secondary[0]->velocityX;
                    this->secondary[1]->velocityXCorrection = locals.secondVelocity - this->secondary[1]->velocityX;
                }
                return;
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
                        this->secondary[0]->velocityXCorrection = locals.firstVelocity - this->secondary[0]->velocityX;
                        this->secondary[1]->velocityXCorrection = locals.secondVelocity - this->secondary[1]->velocityX;
                    }
                } else if (((double)(int)this->secondary[1]->facing * locals.secondVelocity <= collisionZero) &&
                    (collisionZero <= (double)(int)this->secondary[0]->facing * locals.firstVelocity)) {
                    locals.average = ((double)(int)this->secondary[0]->facing * locals.firstVelocity +
                        (double)(int)this->secondary[1]->facing * locals.secondVelocity) / collisionTwo;
                    locals.firstVelocity = (double)(int)this->secondary[0]->facing * locals.average;
                    locals.secondVelocity = (double)(int)(signed char)this->secondary[1]->facing * locals.average;
                    this->secondary[0]->velocityXCorrection = locals.firstVelocity - this->secondary[0]->velocityX;
                    this->secondary[1]->velocityXCorrection = locals.secondVelocity - this->secondary[1]->velocityX;
                }
            }
        }
    }
    }
}
