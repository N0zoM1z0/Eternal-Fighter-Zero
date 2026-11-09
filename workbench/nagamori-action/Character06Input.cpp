// Nagamori's 12,277-byte priority-ordered action state boss.
// WIP natural C++: only the original input-buffer preparation and first
// guarded cancellation/airborne transition are reconstructed here.
// Not an accepted source or complete matching owner.
#include "../../src/CharacterViews.h"

void Character06::Slot04()
{
    if (field0008 < 200) {
        actionBufferedInput = 0;
    }
    if (stateGroupCBufferFrames <= 0) {
        stateGroupCBufferedInput = 0;
    } else {
        --stateGroupCBufferFrames;
    }
    if (stateGroupCBufferedInput == 0) {
        stateGroupCBufferFrames = 0;
    }
    if ((recognizedCommand == 0x34) &&
        (((field0118 >= 500.0 && attackCollisionResult > 1 && attackCollisionResult != 6) ||
          (field0120 > 0 && attackCollisionResult > 1)) &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        field3150 == 0 &&
        sequences[field0008].field0002 <= sequences[167].field0000) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0) {
            field0008 = 0xab;
        }
        return;
    }
    if (field015c < 2) {
        if (health < 0xd05 && recognizedCommand == 0x5b &&
            meter >= 3000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && attackCollisionResult != 6 &&
            sequences[field0008].field0002 <= sequences[312].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x138;
            return;
        }
        if (recognizedCommand == 0x7a && meter >= 3000 && field3148 == 0 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[315].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13b;
            return;
        }
        if ((recognizedCommand == 0x79 || recognizedCommand == 0x7a) &&
            field3148 == 0 && meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[314].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13a;
            return;
        }
        if ((recognizedCommand == 0x78 || recognizedCommand == 0x79 ||
             recognizedCommand == 0x7a) && field3148 == 0 &&
            meter >= 1000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[313].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x139;
            return;
        }
        if (recognizedCommand == 0x70 && meter >= 1000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && field3168 == 0 && positionY == 0.0 &&
            sequences[field0008].field0002 <= sequences[308].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x134;
            if (positionY < 0.0) {
                field0008 = 0x137;
            }
            return;
        }
        if (recognizedCommand == 0x6f && meter >= 1000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[306].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x132;
            if (positionY < 0.0) {
                field0008 = 0x135;
            }
            return;
        }
        if (recognizedCommand == 0x6e && meter >= 1000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[307].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x133;
            if (positionY < 0.0) {
                field0008 = 0x136;
            }
            return;
        }
    }
    // Other priority-ordered actions and the final original default remain open.
}
