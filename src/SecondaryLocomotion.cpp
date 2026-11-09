// Shared grounded idle, walking, crouching and jump-state transitions.
#include "Engine.h"

void Secondary::UpdateLocomotionState()
{
    if (positionY == 0.0) {
        field0159 = 0;
        field015a = 0;
    }
    if (positionY >= 0.0 && field0008 != 4 && field0008 != 5 && field0008 != 6
    && field0008 != 10 && field0008 != 11 && field0008 != 12) {
        if (field015c < 3 && inputY == -1) {
            FaceOpponent();
            if (field0262 >= 3 && field0262 <= 5) {
                if (field0262 == 3) {
                    if (field0008 != 10) ResetPose();
                    field0008 = 10;
                    return;
                }
                if (field0262 == 4) {
                    if (field0008 != 11) ResetPose();
                    field0008 = 11;
                    return;
                }
                if (field0262 == 5) {
                    if (field0008 != 12) ResetPose();
                    field0008 = 12;
                    return;
                }
            } else {
                if (inputX == 0) {
                    if (field0008 != 4) ResetPose();
                    field0008 = 4;
                    return;
                }
                if (inputX == facing) {
                    if (field0008 != 5) ResetPose();
                    field0008 = 5;
                    return;
                }
                if (inputX == -facing) {
                    if (field0008 != 6) ResetPose();
                    field0008 = 6;
                    return;
                }
            }
        }
        if (inputY == 1) {
            if (field0008 != 8 && field0008 != 3) {
                field0008 = 8;
                ResetPose();
                FaceOpponent();
                return;
            } else if (field0008 != 8) {
                field0008 = 3;
                FaceOpponent();
                return;
            }
            return;
        } else if (inputX != 0) {
            FaceOpponent();
            if (inputX == facing) {
                if (field0008 != 1) ResetPose();
                field0008 = 1;
                return;
            } else {
                if (field0008 != 2) ResetPose();
                field0008 = 2;
                return;
            }
        } else if (field0008 == 3 || field0008 == 8) {
            field0008 = 7;
            FaceOpponent();
            ResetPose();
        } else if (field0008 == 7 || field0008 == 13) {
            FaceOpponent();
        } else {
            if (field0008 != 0) ResetPose();
            field0008 = 0;
            FaceOpponent();
        }
    }
}
