// Kanna CPU input generation and command/state selection, reconstructed as
// natural C++ from the complete native Slot05 decompilation.
#include "CharacterViews.h"
#include <math.h>





void Character19::Slot05()
{


  recognizedCommand = 99;
  if (0 < cpuMoveRightFrames) {
    cpuMoveRightFrames = cpuMoveRightFrames + -1;
  }
  if (0 < cpuMoveLeftFrames) {
    cpuMoveLeftFrames = cpuMoveLeftFrames + -1;
  }
  inputX = 0;
  inputY = 0;
  buttonPulse[0] = 0;
  buttonPulse[1] = 0;
  buttonPulse[2] = 0;
  buttonPulse[3] = 0;
  guardInputFrames = 0;
  field314c = field314c + -1;
  field3150 = field3150 + -1;
  if (field314c < 0) {
    field314c = 0;
  }
  if ((0x31 < field0008) && (field0008 < 0xa1)) {
    field314c = 0xb4;
  }
  if (field3150 < 0) {
    field3150 = 0;
  }
  if ((float)(unsigned short)RandomRange(0,1000) <
      25.0f * field00a8 +
      ((int)(positionY < 0.0) * 30) * field00a8 +
      (field3114 == 3) * 400 +
      (field0008 == 0xaa) * 300) {
    guardInputFrames = 0x3c;
  }
  if ((double)(unsigned short)RandomRange(0,2000) <
      ((double)('\0' < throwInvulnerabilityFrames) * 4.0 + 1.0) * 8.0
      * (double)field00a8 *
      (double)(((int)(field0008 > 0x95 && field0008 < 0x9d) * 2) + 1)) {
    guardInputFrames = 0x3c;
  }
  if (((float)(unsigned short)RandomRange(0,1000) < 40.0f * field00a8) &&
      (199 < field0008)) {
    guardInputFrames = 0x3c;
  }
  if ((attackWasGuarded == 1) && (field3114 == 2)) {
    guardInputFrames = 0x1e;
    if (field0008 < 200) {
      field3114 = 0;
    }
  }
  else {
    struct { double forward; double vertical; } distance;
    distance.forward = ((*opponentSlot)->positionX - positionX) *
            (double)(int)facing;
    distance.vertical = fabs(positionY - (*opponentSlot)->positionY);
    if (field0008 >= 0x32 && field0008 <= 0x96 && field000c == 0) {


      if ((float)(unsigned short)RandomRange(0,100) < 8.0f * field00a8) {
        field3114 = 3;
      }
      else {
        field3114 = 0;
      }

      inputX = 1 - (((unsigned short)RandomRange(0,100) < 0x32) << 1);

      buttonPulse[3] = (double)(unsigned short)RandomRange(0,0xf0) < distance.vertical;

      buttonPulse[3] = (double)(unsigned short)RandomRange(0,0x140) < distance.forward;
      if ((((199 < (*opponentSlot)->field0008) &&
           ((*opponentSlot)->field0008 < 0xfa)) &&
          ((*opponentSlot)->field000a < 3)) &&
         ((distance.vertical < 100.0 && (distance.forward < 150.0)))) {
        buttonPulse[3] = 0;
      }

    return;
  }

      if ((field0008 == 0xa8) && (field000c < 6)) {
        if (((((*opponentSlot)->field0008 != 200) &&
             ((*opponentSlot)->field0008 != 0xcc)) &&
            ((*opponentSlot)->field0008 < 0xfa)) &&
           (((*opponentSlot)->positionY == 0.0 &&
            ((*opponentSlot)->remainingHitCount == 0)))) {
          if ((distance.forward < 45.0) &&
             (
             (float)(unsigned short)RandomRange(0,100) < field00a8 * 2.0f)) {
            buttonPulse[0] = 1;
            inputY = 1;
            return;
          }
          if ((distance.forward < 60.0) &&
             ( (float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f
             )) {
            buttonPulse[0] = 1;
            inputY = 0;
            return;
          }
        }
        if (((((((*opponentSlot)->field0008 == 0xc9) ||
               ((*opponentSlot)->field0008 == 0xca)) ||
              ((*opponentSlot)->field0008 == 0xcd)) &&
             (((*opponentSlot)->field0008 < 0xfa &&
              ((*opponentSlot)->positionY == 0.0)))) &&
            (((*opponentSlot)->remainingHitCount == 0 &&
             ((distance.forward > 60.0 && (distance.forward < 80.0)))))) &&
           ( (float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f))
        {
          buttonPulse[1] = 1;
          inputY = 1;
          inputX = 0;
          return;
        }
      }
      if ((field0008 == 0xa8) || (field0008 == 0xa9)) {

        if (((float)(unsigned short)RandomRange(0,8000) < field00a8 * field00a8 * 4.0f)
           && (field0118 > 500.0)) {
          recognizedCommand = 0xc;
          return;
        }
        if (distance.forward < 20.0) {

          if (((float)(unsigned short)RandomRange(0,0x708) < field00a8 * 4.0f) &&
             (field0118 > 500.0)) {
            recognizedCommand = 0x14;
            return;
          }
          if ((distance.forward < 60.0) &&
             ( (float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f
             )) {
            buttonPulse[0] = 1;
            inputY = 0;
            return;
          }

          if (((float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f) &&
             (meter == 3000)) {
            recognizedCommand = 0x5c;
            return;
          }

          if ((((float)(unsigned short)RandomRange(0,100) < field00a8 * 3.0f) &&
              (distance.forward < 120.0)) && (meter >= 2000)) {
            recognizedCommand = 0x65;
            return;
          }
        }
        if ((distance.forward < 150.0) && (distance.forward > 100.0)) {

          if (((float)(unsigned short)RandomRange(0,100) < field00a8 * 3.0f) &&
             (field0118 > 500.0)) {
            recognizedCommand = 0xc;
            return;
          }
          if ((distance.forward < 120.0) &&
             ( (float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f
             )) {
            buttonPulse[0] = 2;
            inputY = 0;
            return;
          }

          if ((float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f) {
            buttonPulse[2] = 1;
            inputY = 1;
            return;
          }

          if ((((float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f) &&
              (meter == 3000)) &&
             ((*opponentSlot)->field0008 < 0xdc)) {
            recognizedCommand = 100;
            return;
          }
        }
        if (distance.forward > 150.0) {

          if (((float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f) &&
             (field0118 > 500.0)) {
            recognizedCommand = 0xc;
            return;
          }

          if ((float)(unsigned short)RandomRange(0,100) < field00a8 * 1.0f) {
            recognizedCommand = 100;
            return;
          }
        }
      }
      if (((field0008 == 0xaa) && (field000a == 1)) &&
         (field000c == 0)) {

        if ((float)(unsigned short)RandomRange(0,100) < field00a8 * 5.0f) {
          field3114 = 3;
          return;
        }
        if ((((positionY - (*opponentSlot)->positionY <
               0.0) &&
             (-40.0 <
              positionY - (*opponentSlot)->positionY)) &&
            (distance.forward < 80.0)) &&
           ( (float)(unsigned short)RandomRange(0,100) < field00a8 * 5.0f))
        {
          buttonPulse[0] = 1;
          return;
        }
        if (((-100.0 <
              positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY <
             -50.0)) &&
           ((distance.forward < 80.0 &&
            ( (float)(unsigned short)RandomRange(0,100) < field00a8 * 5.0f)
            ))) {
          buttonPulse[1] = 1;
          return;
        }
        if (((-50.0 <
              positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY <
             -50.0)) &&
           ((distance.forward < 120.0 &&
            ( (float)(unsigned short)RandomRange(0,100) < field00a8 * 5.0f)
            ))) {
          buttonPulse[1] = 1;
          inputY = 0;
          return;
        }
        if (((distance.vertical < 50.0) && (distance.forward < 100.0)) &&
           (
           (float)(unsigned short)RandomRange(0,100) < field00a8 * 2.0f)) {

          recognizedCommand = (unsigned short)RandomRange(0,2) + 10;
          return;
        }

        if ((float)(unsigned short)RandomRange(0,1000) < field00a8 * 2.0f) {
          recognizedCommand = 100;
          return;
        }
      }
      if ((((((*opponentSlot)->field0008 == 0xa8) ||
            ((*opponentSlot)->field0008 == 0xa9)) ||
           ((*opponentSlot)->field0008 == 0xaa)) &&
          ((positionY == 0.0 &&
           ( (float)(unsigned short)RandomRange(0,100) < 15.0f * field00a8))
          )) && ((field3114 != 2 &&
                 ((*opponentSlot)->hitstunFrames == 0)))) {

        field3110 = (unsigned int)(unsigned short)RandomRange(0,100);
        if ((field3110 < 3) && (field0118 > 500.0)) {
          recognizedCommand = 0x16;
          return;
        }
        if (((field3110 < 0x11) && (0xc < field3110)) &&
           (meter >= 3000)) {
          recognizedCommand = 100;
          return;
        }
        if (((field3110 < 0x12) && (0x14 < field3110)) &&
           (meter == 3000)) {
          recognizedCommand = 0x65;
          return;
        }
        if (0x41 < field3110) {
          field3114 = 2;
          return;
        }
      }
      if (((((*opponentSlot)->field0008 == 0xa8) ||
           ((*opponentSlot)->field0008 == 0xa9)) ||
          ((*opponentSlot)->field0008 == 0xaa)) &&
         ((((positionY < 0.0 &&
            ( (float)(unsigned short)RandomRange(0,100) < 15.0f * field00a8)
            ) && (field3114 != 2)) &&
          ((*opponentSlot)->hitstunFrames == 0)))) {

        field3110 = (unsigned int)(unsigned short)RandomRange(0,1000);
        if ((field3110 < 2) && (meter >= 3000)) {
          recognizedCommand = 100;
          return;
        }
        if ((field3110 < 4) && (meter >= 3000)) {
          recognizedCommand = 0x65;
          return;
        }
        if (0x3a < field3110) {
          field3114 = 2;
          return;
        }
      }
      if ((((field0118 > 500.0) || (field0120 > 0)) &&
           ((float)(unsigned short)RandomRange(0,100) < 8.0f * field00a8) &&
           ((*opponentSlot)->field0008 > 0x95 && (*opponentSlot)->field0008 < 0x9d) &&
           ((field0008 == 0x100) ||
            ((field0008 == 0xe8) && ((unsigned short)RandomRange(0,10) == 0)) ||
            ((field0008 == 0xeb) && ((unsigned short)RandomRange(0,7) == 0))))) {
        recognizedCommand = 0x34;
        return;
      }

        if ((((positionY == 0.0) && (field0008 < 4)) &&
            (0x31 < (*opponentSlot)->field0008)) &&
           (((*opponentSlot)->field0008 < 0x96 && (field3114 == 0)
            ))) {
          if ((((*opponentSlot)->positionY < 0.0) &&
              ((distance.vertical < 100.0 && (distance.forward < 130.0)))) &&
             ((0x18 < (*opponentSlot)->airActionLockFrames ||
              (((*opponentSlot)->airActionDisabled == 1 ||
               (((*opponentSlot)->field0008 == 0x52 &&
                ((*opponentSlot)->field000a < 4)))))))) {
            field3114 = 0x1f;
            return;
          }
          if (((((*opponentSlot)->positionY < 0.0) &&
               (distance.vertical < 50.0)) && (distance.forward < 70.0)) &&
             (((0x12 < (*opponentSlot)->airActionLockFrames ||
               ((*opponentSlot)->airActionDisabled == 1)) ||
              (((*opponentSlot)->field0008 == 0x52 &&
               ((*opponentSlot)->field000a < 4)))))) {
            field3114 = 0x1e;
            return;
          }
          if ((((*opponentSlot)->field0008 == 0x46) &&
              (meter >= 3000)) && ( (unsigned short)RandomRange(0,0) != 0)) {
            if (distance.forward < 150.0) {
              recognizedCommand = 0x65;
              return;
            }
            if (distance.forward > 150.0) {
              recognizedCommand = 100;
              return;
            }
          }
        }
        if (((0 < field3114) && (0x31 < field0008)) &&
           (field0008 < 0x9e)) {
          field3114 = 0;
        }
        if ((field3114 == 1) && (field0008 < 200)) {
          field3114 = 0;
        }
        if ((field3114 == 2) && (attackWasGuarded != 1)) {
          field3114 = 0;
        }
        else {
          if ((field3114 == 3) && (field0008 == 0xd)) {
            field3114 = 0;
          }
          if (field3114 == 4) {
            inputY = 0xff;
            inputX = (unsigned short)RandomRange(0,2) - 1;
            if (((field0008 == 4) || (field0008 == 5)) ||
               (field0008 == 6)) {
              recognizedCommand = (unsigned short)(facing == '\x01');
              if (field0008 == 0xa5) {
                field3114 = 0;
              }
              inputY = 0;
              inputX = 0;
              return;
            }
          }
          if ((field3114 == 5) && (field0008 < 0x32)) {
            recognizedCommand = (unsigned short)(facing == '\x01');
            if (field0008 == 0xa3) {
              field3114 = 0;
            }
          }
          else if ((field3114 == 6) && (field0008 < 0x32)) {
            inputX = 0;
            inputY = 0xff;
            if (field0008 == 4) {
              field3114 = 8;
            }
          }
          else if ((field3114 == 7) && (field0008 < 0x32)) {
            inputX = facing;
            inputY = 0xff;
            if (field0008 == 5) {
              field3114 = 8;
            }
          }
          else if ((field3114 == 8) && (field0008 < 0x32)) {
            inputX = facing;
            inputY = 1;
            if (field0008 == 0x12) {
              field3114 = 0;
            }
          }
          else if ((field3114 == 9) && (field0008 < 0x32)) {
            inputX = facing;
            inputY = 0xff;
            if (field0008 == 5) {
              field3114 = 10;
            }
          }
          else if ((field3114 == 10) && (field0008 < 0x32)) {
            buttonPulse[1] = 1;
            if ((field0008 == 0xd0) || (positionY == 0.0))
            {
              field3114 = 0;
            }
          }
          else if ((field3114 == 0xb) && (field0008 < 0x32)) {
            inputX = 0;
            inputY = 0xff;
            if (field0008 == 4) {
              field3114 = 0xc;
            }
          }
          else if ((field3114 == 0xc) && (field0008 < 0x32)) {
            buttonPulse[0] = 1;
            if ((field0008 == 0xcf) || (positionY == 0.0))
            {
              field3114 = 0;
            }
          }
          else if ((field3114 == 0xd) && (field0008 < 0x32)) {
            buttonPulse[0] = 1;
            if ((field0008 == 0xd0) || (positionY == 0.0))
            {
              field3114 = 0;
            }
          }
          else if (field3114 == 0xe) {
            inputY = 0xff;
            inputX = facing;
            if (field0008 == 5) {
              field3114 = 0xf;
            }
          }
          else if (field3114 == 0xf) {
            if ((*opponentSlot)->airActionLockFrames <= 0) {
              field3114 = 0;
            }
            if ((distance.vertical < 80.0) &&
                ((*opponentSlot)->positionY < positionY)) {
              buttonPulse[0] = 1;
              if (field0008 == 0xcf) {
                field3114 = 0x10;
                return;
              }
            }
            if (distance.vertical < 100.0) {
              buttonPulse[1] = 1;
              if ((*opponentSlot)->airActionLockFrames < 0x18) {
                buttonPulse[0] = 1;
              }
              if ((field0008 == 0xd0) || (field0008 == 0xcf)) {
                field3114 = 0x10;
              }
            }
          }
          else if (field3114 == 0x10) {
            if ((*opponentSlot)->airActionLockFrames <= 0) {
              field3114 = 0;
            }
            if ((field0008 == 0xcf) && (attackCollisionResult == 3)) {
              buttonPulse[1] = 1;
            }
            else if (field0008 == 0xd0) {
              field3114 = 0x11;
            }
          }
          else if (field3114 == 0x11) {
            if (((*opponentSlot)->airActionLockFrames <= 0) ||
               (positionY == 0.0)) {
              field3114 = 0;
            }

            if (((unsigned short)RandomRange(0,200) == 1) && (meter == 3000)) {
              recognizedCommand = 0x65;
            }
            else if (field0008 == 0xd1) {
              field3114 = 0;
            }
            else if (field0008 == 0xfd) {
              field3114 = 0;
            }
            else if (field0008 == 0xa5) {
              field3114 = 0x14;
            }
            else if (field0008 == 0xf) {
              field3114 = 0x14;
            }
            else if (((field0008 == 0xd0) && (attackCollisionResult == 3)) &&
                    (5 < field000a)) {
              if (distance.forward > 80.0) {
                if (velocityX < 0.0) {
                  if ((*opponentSlot)->positionY - positionY > -40.0) {
                    recognizedCommand = 10;
                    return;
                  }
                }
              }
              goto kanna_state11_outer;

kanna_state11_outer:
              if ((*opponentSlot)->airActionLockFrames < 0x2d) {
                if (airActionCount > 0) {
                  if (distance.vertical < 40.0) {
                    if ((*opponentSlot)->positionY - positionY < 0.0) {
                      recognizedCommand = 10;
                      return;
                    }
                  }
                }
              }
              goto kanna_state11_second;

kanna_state11_second:
              if ((*opponentSlot)->airActionLockFrames < 0x2d) {
                if (velocityX >= 0.0) {
                  buttonPulse[2] = 1;
                  return;
                }
              }
              goto kanna_state11_deeper;
kanna_state11_deeper:
              if ((((distance.vertical < 20.0) &&
                    ((*opponentSlot)->positionY > positionY)) ||
                   ((*opponentSlot)->positionY < positionY)) &&
                  ((*opponentSlot)->airActionLockFrames > 0x54) &&
                  (airActionCount < 2)) {
                inputX = facing;
                inputY = 0;
                return;
              }
              if ((distance.vertical > 90.0) &&
                  ((*opponentSlot)->positionY < positionY) &&
                  (0x2d < (*opponentSlot)->airActionLockFrames) &&
                  (airActionCount < 2)) {
                inputX = facing;
                inputY = 0xff;
              }
            }
          }
          else if (field3114 == 0x14) {
            if (((*opponentSlot)->airActionLockFrames <= 0) ||
               (positionY == 0.0)) {
              field3114 = 0;
            }
            if (field0008 == 0xd0) {
              field3114 = 0x11;
            }
            else if (distance.forward < 130.0) {
              buttonPulse[1] = 1;
            }
          }
          else if (field3114 == 0x15) {
            if (((*opponentSlot)->airActionLockFrames <= 0) ||
               (positionY == 0.0)) {
              field3114 = 0;
            }
            if (field0008 == 0xd0) {
              field3114 = 0x16;
            }
            else if (distance.forward < 130.0) {
              buttonPulse[1] = 1;
            }
          }
          else if (field3114 == 0x16) {
            if (((*opponentSlot)->airActionLockFrames <= 0) ||
               (positionY == 0.0)) {
              field3114 = 0;
            }
            if (field0008 == 0xd1) {
              field3114 = 0;
            }
            else if (distance.forward < 130.0) {
              buttonPulse[2] = 1;
            }
          }
          else if (field3114 == 0x1e) {
            if (((*opponentSlot)->airActionLockFrames <= 0) ||
               ((*opponentSlot)->positionY == 0.0)) {
              field3114 = 0;
            }
            if (field0008 == 200) {
              field3114 = 0x1f;
            }
            else if (distance.forward < 130.0) {
              buttonPulse[0] = 1;
            }
          }
          else if (field3114 == 0x1f) {
            if (((*opponentSlot)->airActionLockFrames <= 0) ||
               ((*opponentSlot)->positionY == 0.0)) {
              field3114 = 0;
            }
            if ((field0008 == 0xc9) || (field0008 == 0xca)) {
              field3114 = 0x20;
            }
            else {
              buttonPulse[1] = 1;
            }
          }
          else if (field3114 == 0x20) {
            if (((*opponentSlot)->airActionLockFrames <= 0) ||
               ((*opponentSlot)->positionY == 0.0)) {
              field3114 = 0;
            }
            if (field0008 == 0xcb) {
              field3114 = 0x21;
            }
            else if ((*opponentSlot)->airActionLockFrames < 0x3c) {
              buttonPulse[2] = 1;
            }
            else {
              field3114 = 0xe;
            }
          }
          else {
            if (field3114 == 0x21) {
              if (((*opponentSlot)->airActionLockFrames <= 0) ||
                 ((*opponentSlot)->positionY == 0.0)) {
                field3114 = 0;
              }
              if (((field0008 == 0xfa) || (field0008 == 0xfb)) ||
                 (field0008 == 0x12f)) {
                field3114 = 0;
                return;
              }

              if (((unsigned short)RandomRange(0,100) < 2) && (meter >= 3000)) {
                recognizedCommand = 0x65;
                return;
              }

              if (((unsigned short)RandomRange(0,100) < 4) &&
                 ((field0118 > 500.0 ||
                  ('\0' < field0120)))) {
                recognizedCommand = 0xc;
                return;
              }

              if ((unsigned short)RandomRange(0,100) < 10) {
                recognizedCommand = 10;
                return;
              }
            }
            if (field3114 == 0x22) {
              if (4 < field0008) {
                field3114 = 0;
              }
              if (distance.forward < 50.0) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
              }
              if (distance.forward < 90.0) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
              }
            }
            if (field3114 == 0x24) {
              if (field0008 < 4) {
                field3114 = 0;
              }
              if ((field0008 == 0xab) || (field0008 == 0xa7)) {
                field3114 = 0x25;
              }
              else {
                recognizedCommand = 0x34;
              }
            }
            else if (field3114 == 0x25) {
              if (positionY == 0.0) {
                field3114 = 0;
              }
              if (field0008 == 0xd0) {
                field3114 = 0;
              }
              else {
                buttonPulse[1] = 1;
              }
            }
            else {
              if ((((1 < attackCollisionResult) && (hitstopFrames == 0)) &&
                  (
                  (float)(unsigned short)RandomRange(0,100) < field00a8 * 25.0f)) &&
                 ((field3114 != 1 && (field3114 != 2)))) {

                field3110 = (unsigned int)(unsigned short)RandomRange(0,1000);
                if (field0008 == 200) {
                  if (((*opponentSlot)->positionY < 0.0) &&
                     (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if (((distance.forward < 130.0) && (0 < field3110)) &&
                     (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                  }
                  if (((distance.forward < 100.0) && (300 < field3110)) &&
                     (field3110 < 600)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                }
                if (field0008 == 0xc9) {
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (field3110 < 300)) &&
                     ((attackCollisionResult == 3 &&
                      (0x3c < (*opponentSlot)->airActionLockFrames)))) {
                    field3114 = 0xe;
                    return;
                  }
                  if (((((*opponentSlot)->positionY < 0.0) &&
                       (field3110 < 300)) && (attackCollisionResult == 3)) &&
                     ((*opponentSlot)->airActionLockFrames < 0x3d)) {
                    field3114 = 0x1e;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (600 < field3110)) && (field3110 < 0x2ee)) {
                    inputX = facing;
                    inputY = 0xff;
                    field3114 = 0xd;
                    return;
                  }
                  if (((100 < field3110) && (field3110 < 0x15e))
                     && (distance.forward < 110.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if (((attackCollisionResult == 2) && (0x15e < field3110)) &&
                     (field3110 < 0x163)) {
                    inputX = facing;
                    inputY = 0xff;

                    if (0x31 < (unsigned short)RandomRange(0,100)) {
                      return;
                    }
                    field3114 = 6;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (0x1c2 < field3110)) &&
                     ((field3110 < 700 && (distance.forward < 150.0)))) {
                    buttonPulse[2] = 1;
                    return;
                  }
                }
                if (field0008 == 0xca) {
                  if ((0 < field3110) && (field3110 < 10)) {

                    recognizedCommand = (unsigned short)RandomRange(1,3) + 0x46;
                    return;
                  }
                  if (((((*opponentSlot)->positionY < 0.0) &&
                       (0xfa < field3110)) && (field3110 < 0xff))
                     && ((meter >= 3000 && (attackCollisionResult == 3))))
                  {
                    recognizedCommand = 0x65;
                    return;
                  }
                  if (((300 < field3110) && (field3110 < 600)) &&
                     (distance.forward < 140.0)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                  }
                }
                if (field0008 == 0xcb) {
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (field3110 < 300)) && (attackCollisionResult == 3)) {

                    recognizedCommand = (unsigned short)RandomRange(0,3) + 10;
                    return;
                  }
                  if ((300 < field3110) && (field3110 < 600)) {

                    recognizedCommand = (unsigned short)RandomRange(0,5) + 0x46;
                    return;
                  }
                  if (((0x15e < field3110) && (field3110 < 600))
                     && (attackCollisionResult == 2)) {
                    recognizedCommand = 0x1f;
                    if (120.0 <= distance.forward) {
                      return;
                    }
                    recognizedCommand = 0x1e;
                    return;
                  }
                  if (900 < field3110) {
                    field3114 = 1;
                    return;
                  }
                }
                if (field0008 == 0xcc) {
                  if (((*opponentSlot)->positionY < 0.0) &&
                     (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if (((distance.forward < 70.0) && (0 < field3110)) &&
                     (field3110 < 200)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if (((distance.forward < 130.0) && (200 < field3110)) &&
                     (field3110 < 600)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                  }
                }
                if (field0008 == 0xcd) {
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (0 < field3110)) && (field3110 < 500)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                  }
                  if (field3110 < 300) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                  }
                  if (((300 < field3110) && (field3110 < 0x1c2))
                     && (distance.forward < 120.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if ((0x1c2 < field3110) && (field3110 < 0x28a))
                  {
                    buttonPulse[2] = 1;
                    return;
                  }
                  if ((0x226 < field3110) && (field3110 < 0x276))
                  {

                    recognizedCommand = (unsigned short)RandomRange(0,5) + 0x46;
                    return;
                  }
                }
                if (field0008 == 0xce) {
                  if ((0 < field3110) && (field3110 < 0x32)) {

                    recognizedCommand = (unsigned short)RandomRange(0,3) + 0x46;
                    return;
                  }
                  if ((((300 < field3110) && (field3110 < 800)) &&
                      (attackCollisionResult == 3)) &&
                     ((field0118 > 500.0 ||
                      (field0120 == '\x01')))) {
                    recognizedCommand = 0x16;
                    return;
                  }
                  if (900 < field3110) {
                    field3114 = 1;
                    return;
                  }
                }
                if (field0008 == 0xcf) {
                  if ((attackCollisionResult == 3) &&
                     ((*opponentSlot)->positionY < 0.0)) {
                    field3114 = 0x10;
                    return;
                  }
                  if (((*opponentSlot)->positionY < 0.0) &&
                     (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    return;
                  }
                  if ((distance.forward < 60.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
                    return;
                  }
                  if (((distance.forward < 125.0) && (399 < field3110)) &&
                     (field3110 < 700)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                  }
                  if (699 < field3110) {
                    field3114 = 1;

                    if ((unsigned short)RandomRange(0,4) != 0) {
                      return;
                    }
                    field3114 = 3;
                    return;
                  }
                }
                if (field0008 == 0xd0) {
                  if ((attackCollisionResult == 3) &&
                     ((*opponentSlot)->positionY < 0.0)) {
                    field3114 = 0x11;
                    return;
                  }
                  if (((0x14 < field3110) && (field3110 < 0x3c))
                     && ((attackCollisionResult == 3 &&
                         ((*opponentSlot)->positionY < 0.0)))) {
                    recognizedCommand = 10;
                    return;
                  }
                  if ((0x50 < field3110) && (field3110 < 300)) {
                    buttonPulse[2] = 1;
                    return;
                  }
                  if ((0x3b6 < field3110) && (attackCollisionResult != 3)) {
                    inputX = (unsigned short)RandomRange(0,2) - 1;
                    return;
                  }
                  if (((((*opponentSlot)->positionY == 0.0) &&
                       (0x15e < field3110)) && (field3110 < 0x28a)
                      ) && ((-40.0 < positionY &&
                            (attackCollisionResult == 3)))) {
                    field3114 = 0x22;
                    return;
                  }
                  if (0x289 < field3110) {
                    field3114 = 3;
                    return;
                  }
                }
                if (field0008 == 0xd1) {
                  if ((field3110 < 200) && (attackCollisionResult == 3)) {

                    recognizedCommand = (unsigned short)RandomRange(0,2) + 0x1f;
                    return;
                  }
                  if ((900 < field3110) && (attackCollisionResult != 3)) {
                    inputX = facing;
                    return;
                  }
                  if (((((*opponentSlot)->positionY == 0.0) &&
                       (field3110 < 0x15e)) &&
                      ((field0118 > 500.0 ||
                       ('\0' < field0120)))) &&
                     (((attackCollisionResult == 3 && (field000c < 3)) &&
                      (field000a == 4)))) {
                    field3114 = 0x24;
                    return;
                  }
                  if ((((*opponentSlot)->positionY == 0.0) &&
                      (0x96 < field3110)) &&
                     ((field3110 < 0x28a &&
                      ((-70.0 < positionY &&
                       (attackCollisionResult == 3)))))) {
                    field3114 = 0x22;
                    return;
                  }
                  if (0x289 < field3110) {
                    field3114 = 3;
                    return;
                  }
                }
                if ((((field0008 == 0xfa) && (distance.forward < 120.0)) &&
                    (field0118 > 500.0)) &&
                   ((field000a == 5 && (field3110 < 100)))) {
                  recognizedCommand = 0x34;
                  return;
                }
                if (((0x106 < field0008) && (field0008 < 0x10b)) &&
                   ( (unsigned short)RandomRange(0,100) < 0x28)) {
                  field3114 = 5;
                  return;
                }
              }

              if ((float)(unsigned short)RandomRange(0,0x100) <
                  field00a8 * field00a8 *
                  field00a8 * field00a8) {

                field3110 = (unsigned int)(unsigned short)RandomRange(0,1000);
                if ((((distance.forward < 40.0) && (distance.vertical < 90.0)) &&
                    (199 < (*opponentSlot)->field0008)) &&
                   ( (unsigned short)RandomRange(0,0x9c4) < 10)) {
                  recognizedCommand = 0x14;
                  return;
                }
                if (((distance.vertical < 90.0) && (199 < (*opponentSlot)->field0008))
                   && (( (unsigned short)RandomRange(0,10000) < 10 &&
                       ((field0118 > 500.0 ||
                        (field0120 == '\x01')))))) {
                  recognizedCommand = 0xc;
                  return;
                }
                if (positionY == 0.0) {
                  if (((*opponentSlot)->positionY == 0.0) &&
                     ((*opponentSlot)->field0008 != 99)) {
                    if (distance.forward < 80.0) {
                      if ((field3110 < (((*opponentSlot)->field0008 >= 0x32 && (*opponentSlot)->field0008 <= 0x9b) ? 1 : 0) * 0xf + 0xf) &&
                         (field314c == 0)) {
                        buttonPulse[0] = 1;
                        inputY = 1;
                        return;
                      }
                    }
                    if (distance.forward < 75.0) {
                      if ((field3110 < (((*opponentSlot)->field0008 >= 0x32 && (*opponentSlot)->field0008 <= 0x9b) ? 1 : 0) * 0xf + 0x14) &&
                         (field314c == 0)) {
                        buttonPulse[0] = 1;
                        inputY = 0;
                        return;
                      }
                    }
                    if ((distance.forward > 40.0) && (distance.forward < 140.0)) {
                      if (((field3110 < (((*opponentSlot)->field0008 >= 0x32 && (*opponentSlot)->field0008 <= 0x9b) ? 1 : 0) * 0xf + 0x2d) &&
                          (0x1e < field3110)) && (field314c == 0))
                      {
                        buttonPulse[1] = 1;
                        inputY = 1;
                        return;
                      }
                    }
                    if (((distance.forward < 140.0) && (distance.forward > 60.0)) &&
                       ((field3110 < 0x82 &&
                        ((0x50 < field3110 && (field314c == 0)))))
                       ) {
                      buttonPulse[1] = 1;

                      inputY = (unsigned short)RandomRange(0,10) < 5;
                      return;
                    }
                    if ((((distance.forward < 70.0) && (field3110 < 0x87)) &&
                        (0x82 < field3110)) && (field314c == 0)) {
                      field3114 = 9;
                      return;
                    }
                    if (((distance.forward < 120.0) && (field3110 < 0x96)) &&
                       ((0x91 < field3110 && (field314c == 0)))) {
                      field3114 = 0xb;
                      return;
                    }
                    if (((distance.forward > 50.0) && (distance.forward < 180.0)) &&
                       ((distance.vertical < 50.0 &&
                        (((field3110 < 300 && (0xfa < field3110))
                         && (field314c == 0)))))) {
                      recognizedCommand = 10;
                      return;
                    }
                    if (((distance.vertical < 90.0) &&
                        (field3110 <
                         (int)((unsigned int)(199 < (*opponentSlot)->field0008) * 0xf +
                              0x131))) &&
                       ((300 < field3110 &&
                        ((field314c == 0 &&
                         (field0118 > 500.0)))))) {
                      recognizedCommand = 0xc;
                      return;
                    }
                    if ((((distance.forward > 130.0) && (field3110 < 0x145)) &&
                        (0x136 < field3110)) && (field314c == 0))
                    {
                      recognizedCommand = 0x46;
                      return;
                    }
                    if (((distance.forward > 130.0) && (field3110 < 0x14a)) &&
                       ((0x145 < field3110 && (field314c == 0))))
                    {
                      recognizedCommand = 0x48;
                      return;
                    }
                    if (((distance.forward < 130.0) && (field3110 < 0x159)) &&
                       ((0x154 < field3110 &&
                        ((field314c == 0 &&
                         (field0118 > 500.0)))))) {
                      recognizedCommand = 0x48;
                      return;
                    }
                    if ((((distance.forward > 200.0) && (distance.forward < 240.0)) &&
                        (field3110 < 0x172)) &&
                       ((0x16d < field3110 && (field314c == 0))))
                    {
                      recognizedCommand = 0x1e;
                      return;
                    }
                    if (((distance.forward > 180.0) && (distance.forward < 320.0)) &&
                       ((field3110 < 0x17c &&
                        ((0x172 < field3110 && (field314c == 0))))
                       )) {
                      recognizedCommand = 0x1f;
                      return;
                    }
                    if ((((distance.forward > 240.0) && (distance.forward < 320.0)) &&
                        (field3110 < 400)) &&
                       ((0x17c < field3110 && (field314c == 0))))
                    {
                      recognizedCommand = 0x20;
                      return;
                    }
                    if (((distance.forward < 120.0) && (field3110 < 0x195)) &&
                       ((400 < field3110 &&
                        (((field314c == 0 && (meter >= 3000))
                         && ((*opponentSlot)->field00ac != '\0')))))) {
                      recognizedCommand = 0x5c;
                      return;
                    }
                  }
                  if ((*opponentSlot)->positionY < 0.0) {
                    if (((distance.forward < 80.0) && (field0118 > 500.0))
                       && (field3110 < 2)) {
                      recognizedCommand = 0x16;
                      return;
                    }
                    if ((*opponentSlot)->velocityY < 0.0) {
                      if (((distance.forward < 80.0) && (distance.vertical < 120.0)) &&
                         (field3110 < 10)) {
                        inputY = 0xff;
                        inputX = -facing;
                        return;
                      }
                      if (((distance.forward < 40.0) && (distance.vertical < 120.0)) &&
                         (field3110 < 0x1e)) {
                        inputY = 0;
                        buttonPulse[1] = 1;
                        return;
                      }
                    }
                    if (0.0 < (*opponentSlot)->velocityY) {
                      if (((distance.forward < 90.0) && (distance.vertical < 140.0)) &&
                         ((field3110 <
                           (int)((unsigned int)(199 < (*opponentSlot)->field0008) * 0x2d +
                                0xf) &&
                          ((field0118 > 500.0 ||
                           ('\0' < field0120)))))) {
                        recognizedCommand = 0x14;
                        return;
                      }
                      if ((((distance.forward < 100.0) && (distance.vertical < 170.0)) &&
                          (80.0 < distance.vertical)) &&
                         ((field3110 < 0x6e && (0x3c < field3110))
                         )) {
                        buttonPulse[1] = 1;
                        inputY = 0;
                        return;
                      }
                      if (((distance.forward < 60.0) && (distance.vertical < 210.0)) &&
                         ((120.0 < distance.vertical &&
                          ((field3110 < 0xb4 && (100 < field3110))
                          )))) {
                        buttonPulse[2] = 1;
                        inputY = 1;
                        return;
                      }
                    }
                  }
                }
                if ((positionY < 0.0) &&
                   (field3114 != 3)) {
                  if (((distance.forward < 180.0) &&
                      (((distance.vertical < 180.0 &&
                        (200 < (*opponentSlot)->field0008)) &&
                       (field3110 < 5)))) && (meter >= 3000))
                  {
                    recognizedCommand = 0x65;
                    return;
                  }
                  if ((*opponentSlot)->positionY == 0.0) {
                    if (((distance.forward < 100.0) && (distance.vertical < 100.0)) &&
                       ((0 < field3110 && (field3110 < 600)))) {
                      buttonPulse[1] = 1;
                      return;
                    }
                    if (((distance.forward < 110.0) && (distance.vertical < 180.0)) &&
                       ((600 < field3110 && (field3110 < 0x28a))))
                    {
                      buttonPulse[2] = 1;
                      return;
                    }
                  }
                  if ((*opponentSlot)->positionY < 0.0) {
                    if ((((distance.forward < 80.0) && (distance.vertical < 100.0)) &&
                        (field3110 < 200)) &&
                       ((*opponentSlot)->positionY < positionY
                       )) {
                      buttonPulse[0] = 1;
                      return;
                    }
                    if (((((distance.forward > 20.0) && (distance.forward < 140.0)) &&
                         ((60.0 < distance.vertical &&
                          ((distance.vertical < 140.0 &&
                           (positionY <
                            (*opponentSlot)->positionY)))))) &&
                        (200 < field3110)) && (field3110 < 0xfa))
                    {
                      buttonPulse[1] = 1;
                      return;
                    }
                  }
                }
              }
              if (((unsigned short)field0008 >= 0x32) ||
                 (((((unsigned short)(*opponentSlot)->field0008 <= 0x95 ||
                    ((unsigned short)(*opponentSlot)->field0008 >= 0x9c)) &&
                   (((unsigned short)(*opponentSlot)->field0008 <= 0x31 ||
                    ((unsigned short)(*opponentSlot)->field0008 >= 0x3b)))) ||
                  (((positionY != 0.0 ||
                    (
                    !((float)(unsigned short)RandomRange(0,5000) <
                      4.0f * field00a8 * field00a8 * field00a8))) ||
                   (field314c != 0)))))) {
                if (((unsigned short)field0008 >= 0x32) ||
                    ((unsigned short)(*opponentSlot)->field0008 >= 0x32) ||
                    !(distance.forward > 80.0) ||
                    !(distance.forward < 120.0) ||
                    (!((float)(unsigned short)RandomRange(0,10000) <
                       field00a8 * field00a8 * field00a8)) ||
                    !(positionX > 150.0) ||
                    !(positionX < 490.0)) {
                  if (((field0008 == 9) || (field0008 == 10)) ||
                     ((0xd < field0008 && (field0008 < 0x15)))) {
                    if (distance.forward > 100.0) {

                      if (((unsigned short)RandomRange(0,0x44c) < 2) && (field3150 == 0)) {
                        field3150 = 0xb4;
                      }

                      if ((((unsigned short)RandomRange(0,100) < 2) && (-180.0 < positionY)) &&
                         (field3150 == 0)) {
                        inputY = 0xff;
                        inputX = (unsigned short)RandomRange(0,2) - 1;
                        return;
                      }

                      if (((unsigned short)RandomRange(0,100) < 4) && (field3150 == 0)) {
                        inputX = facing;
                        return;
                      }

                      if (((unsigned short)RandomRange(0,100) < 2) && (field3150 == 0)) {
                        inputX = facing;
                        inputY = 1;
                        return;
                      }

                      if ((unsigned short)RandomRange(0,0) != 0) {
                        inputX = facing;
                        inputY = 1;
                        return;
                      }
                    }
                    if (distance.forward < 100.0) {

                      if ((unsigned short)RandomRange(0,1000) < 2) {
                        inputY = 1;
                        inputX = (unsigned short)RandomRange(0,2) - 1;
                        return;
                      }

                      if (((unsigned short)RandomRange(0,500) < 2) && (field3150 == 0)) {
                        inputX = -facing;
                        return;
                      }

                      if (((unsigned short)RandomRange(0,100) < 2) && (field3150 == 0)) {
                        inputX = facing;
                        return;
                      }

                      if (((unsigned short)RandomRange(0,100) < 4) && (field3150 == 0)) {
                        inputX = facing;
                        inputY = 1;
                        return;
                      }
                    }
                  }

                  if (((unsigned short)RandomRange(0,500) < 10) && (positionY == 0.0)) {

                    if ((unsigned short)RandomRange(0,100) < 4) {
                      inputX = 0;
                      inputY = 0xff;
                      return;
                    }
                    if (((distance.forward > 40.0) && (distance.forward < 150.0)) &&
                       ( (unsigned short)RandomRange(0,500) < 2)) {
                      field3114 = 6;
                      return;
                    }
                    if ((distance.forward > 150.0) && ( (unsigned short)RandomRange(0,500) < 2)) {
                      field3114 = 7;
                      return;
                    }
                    if ((distance.forward > 200.0) && ( (unsigned short)RandomRange(0,500) < 2)) {
                      inputX = facing;
                      inputY = 0xff;
                      return;
                    }
                    if ((distance.forward < 100.0) && ( (unsigned short)RandomRange(0,500) < 2)) {
                      inputX = -facing;
                      inputY = 0xff;
                      return;
                    }
                  }
                  if (positionY == 0.0) {
                    if (cpuMoveRightFrames > 0) {
                      if ((CollisionSide() != '\0') && (cpuMoveRightFrames > 0xf)) {
                        cpuMoveRightFrames = 0xf;
                      }
                      inputX = 1;
                      return;
                    }
                    if (cpuMoveLeftFrames > 0) {
                      if ((CollisionSide() != '\0') && (cpuMoveLeftFrames > 0xf)) {
                        cpuMoveLeftFrames = 0xf;
                      }
                      inputX = 0xff;
                      return;
                    }

                    if ((unsigned short)RandomRange(0,1000) < 2) {
                      if (facing == '\x01') {
                        cpuMoveLeftFrames = (unsigned short)RandomRange(0,200) + 0x3c;
                      }
                      else {
                        cpuMoveRightFrames = (unsigned short)RandomRange(0,200) + 0x3c;
                      }
                    }

                    if ((unsigned short)RandomRange(0,100) < 2) {
                      if (facing == '\x01') {
                        cpuMoveRightFrames = (unsigned short)RandomRange(0,400) + 0x3c;
                      }
                      else {
                        cpuMoveLeftFrames = (unsigned short)RandomRange(0,400) + 0x3c;
                      }
                    }
                  }
                }
                else {
                  recognizedCommand = (unsigned short)(facing != '\x01');
                }
              }
              else {
                recognizedCommand = (unsigned short)(facing == '\x01');
              }
            }
          }
        }


  }
  return;
}


