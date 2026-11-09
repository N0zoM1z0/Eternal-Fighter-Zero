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
        if (recognizedCommand == 0x66 && meter >= 3000 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[302].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if ((recognizedCommand == 0x65 || recognizedCommand == 0x66) &&
            meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[301].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((recognizedCommand == 100 || recognizedCommand == 0x65 ||
             recognizedCommand == 0x66) && meter >= 1000 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[300].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 300;
            return;
        }
        if (recognizedCommand == 0x2a &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[272].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x110;
            return;
        }
        if ((recognizedCommand == 0x29 || recognizedCommand == 0x2a) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[271].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10f;
            return;
        }
        if (recognizedCommand == 0x28 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[270].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10e;
            return;
        }
        if (recognizedCommand == 0x16 &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[252].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            return;
        }
        if ((recognizedCommand == 0x15 || recognizedCommand == 0x16) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[251].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            return;
        }
        if (recognizedCommand == 0x14 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[250].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            return;
        }
        if (recognizedCommand == 0x20 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[257].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            if (positionY < 0.0) {
                field0008 = 0x115;
            }
            return;
        }
        if (recognizedCommand == 0x1f &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[256].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            if (positionY < 0.0) {
                field0008 = 0x114;
            }
            return;
        }
        if (recognizedCommand == 0x1e &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[255].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            if (positionY < 0.0) {
                field0008 = 0x113;
            }
            return;
        }
        if (recognizedCommand == 0x0c &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 && field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[262].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x106;
            return;
        }
        if (recognizedCommand == 0x0b &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 && field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[261].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            return;
        }
        if (recognizedCommand == 0x0a &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 && field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[260].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            return;
        }
    }
    // Other priority-ordered actions and the final original default remain open.
}
