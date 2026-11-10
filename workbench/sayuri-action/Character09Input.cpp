// Natural C++ reconstruction of the Sayuri action/command boss.
// Canonical 11,119-byte owner: Character09::Slot04 at 0x00446780.
// Only the reviewed opening is implemented in this workbench so far.
#include "../../src/CharacterViews.h"

void Character09::Slot04()
{
    if (field0008 < 200)
        actionBufferedInput = 0;
    if (stateGroupCBufferFrames <= 0)
        stateGroupCBufferedInput = 0;
    else
        --stateGroupCBufferFrames;
    if (stateGroupCBufferedInput == '\0')
        stateGroupCBufferFrames = 0;

    if (field015c < 2 && field0008 > 149 && field0008 < 156 &&
        field000a == 0 && field000c == 0) {
        if ((*opponentSlot)->field0008 == field3150) {
            field3138 = 1;
            SetCharacterTint(0xb1, 10);
        } else {
            field3138 = 0;
        }
    }
    if (recognizedCommand == 0x34 &&
        (field0118 >= 500.0 || field0120 > 0) &&
        attackCollisionResult > 1 && attackCollisionResult != 6 &&
        (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
        sequences[field0008].field0002 <= sequences[167].field0000) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0)
            field0008 = 0xab;
        return;
    }
    if (field015c < 2) {
        if (health < 0xd05 && recognizedCommand == 0x62 && meter >= 3000 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[315].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13b;
            return;
        }
        if (recognizedCommand == 0xac && meter >= 3000 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[302].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if ((recognizedCommand == 0xab || recognizedCommand == 0xac) &&
            meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[301].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((recognizedCommand == 0xaa || recognizedCommand == 0xab ||
             recognizedCommand == 0xac) &&
            meter >= 1000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[300].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12c;
            return;
        }
        if (recognizedCommand == 0xa2 &&
            meter >= 3000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[313].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x139;
            return;
        }
        if ((recognizedCommand == 0xa1 || recognizedCommand == 0xa2) &&
            meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[311].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x137;
            return;
        }
        if ((recognizedCommand == 0xa0 || recognizedCommand == 0xa1 ||
             recognizedCommand == 0xa2) &&
            meter >= 1000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[309].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x135;
            return;
        }
        if (recognizedCommand == 0x70 &&
            meter >= 3000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[308].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x134;
            return;
        }
        if ((recognizedCommand == 0x6f || recognizedCommand == 0x70) &&
            meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[307].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x133;
            return;
        }
        if ((recognizedCommand == 0x6e || recognizedCommand == 0x6f ||
             recognizedCommand == 0x70) &&
            meter >= 1000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[306].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x132;
            return;
        }
        if (recognizedCommand == 0x2a &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[261].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            return;
        }
        if ((recognizedCommand == 0x29 || recognizedCommand == 0x2a) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            field0008 != 0x10c &&
            sequences[field0008].field0002 <= sequences[260].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            return;
        }
        if (recognizedCommand == 0x28 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[259].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x103;
            return;
        }
        // Command-16 meter permission and three grounded follow-up tiers.
        if (recognizedCommand == 0x16 &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[264].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x108;
            return;
        }
        if ((recognizedCommand == 0x15 || recognizedCommand == 0x16) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[263].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x107;
            return;
        }
        if (recognizedCommand == 0x14 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[262].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x106;
            return;
        }
        // Standard grounded special-command families, after the air tiers.
        if ((recognizedCommand == 0x1e || recognizedCommand == 0x1f ||
             recognizedCommand == 0x20) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[256].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            return;
        }
        if (recognizedCommand == 0x48 &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[255].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            return;
        }
        if ((recognizedCommand == 0x47 || recognizedCommand == 0x48) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[254].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfe;
            return;
        }
        if (recognizedCommand == 0x46 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[253].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfd;
            return;
        }
        // Action 0x0C permits meter, alternate meter, or already-airborne
        // execution; the lower tiers have independent EX-mode suppression.
        if (recognizedCommand == 0x0c &&
            (field0118 >= 500.0 || field0120 > 0 || positionY < 0.0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field314c == 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[252].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            if (positionY < 0.0)
                field0008 = 0x10b;
            return;
        }
        if ((recognizedCommand == 0x0b || recognizedCommand == 0x0c) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field314c == 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[251].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            if (positionY < 0.0)
                field0008 = 0x10a;
            return;
        }
        if (recognizedCommand == 0x0a &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field314c == 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[250].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            if (positionY < 0.0)
                field0008 = 0x109;
            return;
        }
    }
    // Air dash when the opponent lies on the command's chosen side.
    if (field015c < 1 && (recognizedCommand == 0 || recognizedCommand == 1)) {
        if (positionY < 0.0 && airDashCount < 1) {
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) < 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2) * -1)) &&
                sequences[field0008].field0002 <= sequences[165].field0000 &&
                field0008 != 0xaa && positionY < -40.0 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                if (field0008 != 0xa5)
                    ResetPose();
                field0008 = 0xa5;
                FaceOpponent();
                ++airDashCount;
                ++airActionCount;
                actionBufferedInput = 0;
                return;
            }
            // Mirrored air dash: the opposite horizontal side and the
            // matching facing condition choose the A6 movement state.
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) > 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2))) &&
                sequences[field0008].field0002 <= sequences[166].field0000 &&
                field0008 != 0xaa &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                if (field0008 != 0xa6)
                    ResetPose();
                field0008 = 0xa6;
                FaceOpponent();
                ++airDashCount;
                ++airActionCount;
                actionBufferedInput = 0;
                return;
            }
        }
        // Grounded direction changes use the same command orientation but
        // distinct ground action priorities and air-dash flags.
        if (positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0) {
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) < 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2) * -1)) &&
                sequences[field0008].field0002 <= sequences[163].field0000 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                if (field0008 != 0xa3)
                    ResetPose();
                field0008 = 0xa3;
                FaceOpponent();
                ++dashMomentumFlag;
                actionBufferedInput = 0;
                return;
            }
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) > 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2))) &&
                sequences[field0008].field0002 <= sequences[164].field0000 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                if (field0008 != 0xa4)
                    ResetPose();
                field0008 = 0xa4;
                FaceOpponent();
                actionBufferedInput = 0;
                return;
            }
        }
    }
    // Aerial command 6: one action-count slot selects neutral/forward/back
    // from the buffered horizontal input, after the original frame guard.
    if (field015c < 3 && recognizedCommand == 6 &&
        (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
        positionY < 0.0 && airActionCount < 1 &&
        sequences[field0008].field0002 <= sequences[14].field0000 &&
        ((field0008 >= 200 && attackCollisionResult >= 2 &&
          attackCollisionResult != 6) || field0008 < 200)) {
        ResetPose();
        ClearBufferedButtons();
        ++airActionCount;
        field0008 = 0x0e;
        if (inputX == facing)
            field0008 = 0x0f;
        if (inputX == -facing)
            field0008 = 0x10;
        return;
    }
    // Remaining original action guards and command dispatch are open.
}
