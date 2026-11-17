// Minagi Character21::Slot05 CPU input/state-decision boss, native 0x005AEA20.
// Native extent 17,127 bytes. This is a natural C++ prototype, NOT Exact.
#include "../../src/CharacterViews.h"
#include <math.h>

void Character21::Slot05()
{
  bool airborneForGuard;
  double forwardSeparation;
  char wallCollision;
  unsigned short randomRoll;
  short randomChoice;
  unsigned int randomValue;
  double verticalSeparation;
  int local_f4;
  int local_ec;
  int local_e8;
  int local_e0;
  int local_dc;
  int local_d4;
  int local_d0;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int guardRangeFactor;

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
  airborneForGuard = positionY < 0.0;
  randomRoll = RandomRange(0,1000);
  if ((float)randomRoll <
      (float)(unsigned char)(airborneForGuard * '\x1e') * field00a8 +
      25.0f * field00a8 +
      (float)((unsigned int)(field3114 == 3) * 400) +
      (float)((unsigned int)(field0008 == 0xaa) * 300)) {
    guardInputFrames = 0x3c;
  }
  if ((field0008 < 0x96) || (0x9c < field0008)) {
    guardRangeFactor = 0;
  }
  else {
    guardRangeFactor = 1;
  }
  randomRoll = RandomRange(0,2000);
  if ((double)randomRoll <
      (double)(guardRangeFactor * 2 + 1) *
      ((double)('\0' < throwInvulnerabilityFrames) * 4.0 + 1.0) * 8.0
      * (double)field00a8) {
    guardInputFrames = 0x3c;
  }
  randomRoll = RandomRange(0,1000);
  if (((float)randomRoll < 40.0f * field00a8) &&
     (199 < field0008)) {
    guardInputFrames = 0x3c;
  }
  if ((attackWasGuarded == 1) && (field3114 == 2)) {
    guardInputFrames = 0x1e;
    if (field0008 < 200) {
      field3114 = 0;
    }
  }
  else if ((*opponentSlot)->field0008 != 0x60) {
    forwardSeparation = (double)(int)facing *
            ((*opponentSlot)->positionX - positionX);
    verticalSeparation = fabs(positionY - (*opponentSlot)->positionY);
    if (((field0008 < 0x32) || (0x96 < field0008)) ||
       (field000c != 0)) {
      if (((((field0008 < 4) || (6 < field0008)) &&
           ((field0008 < 10 || (0xc < field0008)))) ||
          (positionY != 0.0)) &&
         ((((*opponentSlot)->field0008 < 0x32 ||
           (0x95 < (*opponentSlot)->field0008)) ||
          ((field0008 != 0x108 || (remainingHitCount < 2)))))) {
        if ((field0008 == 0xa8) && (field000c < 6)) {
          if (((*opponentSlot)->field0008 != 200) &&
             (((((*opponentSlot)->field0008 != 0xcc &&
                ((*opponentSlot)->field0008 < 0xfa)) &&
               ((*opponentSlot)->positionY == 0.0)) &&
              ((*opponentSlot)->remainingHitCount == 0)))) {
            if ((forwardSeparation < 45.0) &&
               (randomRoll = RandomRange(0,100),
               (float)randomRoll < field00a8 + field00a8)) {
              buttonPulse[0] = 1;
              inputY = 1;
              return;
            }
            if ((forwardSeparation < 60.0) &&
               (randomRoll = RandomRange(0,100),
               (float)randomRoll < field00a8 * 1.0f)) {
              buttonPulse[0] = 1;
              inputY = 0;
              return;
            }
          }
          if ((((((*opponentSlot)->field0008 == 0xc9) ||
                ((*opponentSlot)->field0008 == 0xca)) ||
               ((*opponentSlot)->field0008 == 0xcd)) &&
              ((((*opponentSlot)->field0008 < 0xfa &&
                ((*opponentSlot)->positionY == 0.0)) &&
               (((*opponentSlot)->remainingHitCount == 0 &&
                ((60.0 < forwardSeparation && (forwardSeparation < 80.0)))))))) &&
             (randomRoll = RandomRange(0,100), (float)randomRoll < field00a8 * 1.0f
             )) {
            buttonPulse[1] = 1;
            inputY = 1;
            inputX = 0;
            return;
          }
        }
        if ((field0008 == 0xa8) || (field0008 == 0xa9)) {
          if (forwardSeparation < 100.0) {
            randomRoll = RandomRange(0,100);
            if (((float)randomRoll < field00a8 * 4.0f) &&
               (500.0 < field0118)) {
              recognizedCommand = 0x20;
              return;
            }
            randomRoll = RandomRange(0,100);
            if (((float)randomRoll < field00a8 + field00a8) &&
               (500.0 < field0118)) {
              recognizedCommand = 0xc;
              return;
            }
            if ((forwardSeparation < 60.0) &&
               (randomRoll = RandomRange(0,100),
               (float)randomRoll < field00a8 * 1.0f)) {
              buttonPulse[0] = 1;
              inputY = 0;
              return;
            }
            randomRoll = RandomRange(0,100);
            if (((float)randomRoll < field00a8 * 1.0f) &&
               (meter == 3000)) {
              recognizedCommand = 0x5c;
              return;
            }
            randomRoll = RandomRange(0,100);
            if ((((float)randomRoll < field00a8 * 3.0f) &&
                (forwardSeparation < 80.0)) && (1999 < meter)) {
              randomChoice = RandomRange(0,2);
              recognizedCommand = randomChoice + 0x65;
              return;
            }
          }
          if ((forwardSeparation < 150.0) && (100.0 < forwardSeparation)) {
            randomRoll = RandomRange(0,100);
            if (((float)randomRoll < field00a8 * 3.0f) &&
               (500.0 < field0118)) {
              recognizedCommand = 0xc;
              return;
            }
            if ((forwardSeparation < 120.0) &&
               (randomRoll = RandomRange(0,100),
               (float)randomRoll < field00a8 * 1.0f)) {
              buttonPulse[0] = 2;
              inputY = 0;
              return;
            }
            randomRoll = RandomRange(0,100);
            if ((float)randomRoll < field00a8 * 1.0f) {
              buttonPulse[2] = 1;
              inputY = 1;
              return;
            }
            randomRoll = RandomRange(0,100);
            if ((((float)randomRoll < field00a8 * 1.0f) &&
                (meter == 3000)) &&
               ((*opponentSlot)->field0008 < 0xdc)) {
              recognizedCommand = 0x5c;
              return;
            }
          }
          if (150.0 < forwardSeparation) {
            randomRoll = RandomRange(0,100);
            if (((float)randomRoll < field00a8 * 1.0f) &&
               (500.0 < field0118)) {
              randomChoice = RandomRange(0,2);
              recognizedCommand = randomChoice + 0x1e;
              return;
            }
            randomRoll = RandomRange(0,100);
            if ((float)randomRoll < field00a8 * 1.0f) {
              randomChoice = RandomRange(0,2);
              recognizedCommand = randomChoice + 0xb;
              return;
            }
          }
        }
        if (((field0008 == 0xaa) && (field000a == 1)) &&
           (field000c == 0)) {
          randomRoll = RandomRange(0,100);
          if ((float)randomRoll < field00a8 * 5.0f) {
            field3114 = 3;
            return;
          }
          if ((((positionY - (*opponentSlot)->positionY <
                 0.0) &&
               (-40.0 <
                positionY - (*opponentSlot)->positionY)) &&
              (forwardSeparation < 80.0)) &&
             (randomRoll = RandomRange(0,100), (float)randomRoll < field00a8 * 5.0f
             )) {
            buttonPulse[0] = 1;
            return;
          }
          if (((-100.0 <
                positionY - (*opponentSlot)->positionY) &&
              (positionY - (*opponentSlot)->positionY <
               -50.0)) &&
             ((forwardSeparation < 80.0 &&
              (randomRoll = RandomRange(0,100),
              (float)randomRoll < field00a8 * 5.0f)))) {
            buttonPulse[1] = 1;
            return;
          }
          if (((-50.0 <
                positionY - (*opponentSlot)->positionY) &&
              (positionY - (*opponentSlot)->positionY <
               -50.0)) &&
             ((forwardSeparation < 120.0 &&
              (randomRoll = RandomRange(0,100),
              (float)randomRoll < field00a8 * 5.0f)))) {
            buttonPulse[2] = 1;
            inputY = 0;
            return;
          }
          if (((verticalSeparation < 50.0) && (forwardSeparation < 100.0)) &&
             (randomRoll = RandomRange(0,100),
             (float)randomRoll < field00a8 + field00a8)) {
            randomChoice = RandomRange(0,2);
            recognizedCommand = randomChoice + 0x1f;
            return;
          }
        }
        if (((((*opponentSlot)->field0008 == 0xa8) ||
             ((*opponentSlot)->field0008 == 0xa9)) ||
            ((*opponentSlot)->field0008 == 0xaa)) &&
           (((positionY == 0.0 &&
             (randomRoll = RandomRange(0,100), (float)randomRoll < 15.0f * field00a8
             )) && ((field3114 != 2 &&
                    ((*opponentSlot)->hitstunFrames == 0)))))) {
          randomValue = RandomRange(0,100);
          field3110 = randomValue & 0xffff;
          if ((field3110 < 3) && (500.0 < field0118)) {
            recognizedCommand = 0x20;
            return;
          }
          if ((field3110 < 5) && (500.0 < field0118)) {
            recognizedCommand = 0xc;
            return;
          }
          if (((field3110 < 0x11) && (0xc < field3110)) &&
             (999 < meter)) {
            randomChoice = RandomRange(0,3);
            recognizedCommand = randomChoice + 100;
            return;
          }
          if (((field3110 < 0x12) && (0x14 < field3110)) &&
             (meter == 3000)) {
            recognizedCommand = 0x5c;
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
              (randomRoll = RandomRange(0,100),
              (float)randomRoll < 15.0f * field00a8)) &&
             (field3114 != 2)) &&
            ((*opponentSlot)->hitstunFrames == 0)))) {
          randomValue = RandomRange(0,100);
          field3110 = randomValue & 0xffff;
          if ((field3110 < 2) && (500.0 < field0118)) {
            recognizedCommand = 0x20;
            return;
          }
          if (0x3a < field3110) {
            field3114 = 2;
            return;
          }
        }
        if ((((field0118 <= 500.0) &&
             (field0120 < '\x01')) ||
            ((randomRoll = RandomRange(0,100),
             8.0f * field00a8 <= (float)randomRoll ||
             (((*opponentSlot)->field0008 < 0x96 ||
              (0x9c < (*opponentSlot)->field0008)))))) ||
           (((field0008 != 0xfb &&
             ((field0008 != 0xe8 || (randomChoice = RandomRange(0,10), randomChoice != 0)))) &&
            (((field0008 != 0xfa || (randomRoll = RandomRange(0,100), 1 < randomRoll)) &&
             ((field0008 != 0xeb || (randomChoice = RandomRange(0,7), randomChoice != 0)))))))) {
          if ((0 < field3114) &&
             ((0x31 < field0008 && (field0008 < 0x9e)))) {
            field3114 = 0;
          }
          if ((field3114 == 1) && (field0008 < 200)) {
            field3114 = 0;
          }
          if ((field3114 == 2) && (attackWasGuarded != 1)) {
            field3114 = 0;
          }
          else {
            if (field3114 == 4) {
              inputY = 0xff;
              wallCollision = RandomRange(0,2);
              inputX = wallCollision + -1;
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
              recognizedCommand = (unsigned short)(facing == '\x01');
              if (field0008 == 0xa3) {
                field3114 = 7;
              }
            }
            else if ((field3114 == 7) && (field0008 == 0xa3)) {
              buttonPulse[0] = 1;
              if (field0008 == 0xe6) {
                field3114 = 0;
              }
            }
            else if ((field3114 == 8) && (field0008 < 0x32)) {
              recognizedCommand = (unsigned short)(facing == '\x01');
              if (field0008 == 0xa3) {
                field3114 = 9;
              }
            }
            else if ((field3114 == 9) && (field0008 == 0xa3)) {
              buttonPulse[1] = 1;
              if (field0008 == 0xe7) {
                field3114 = 0;
              }
            }
            else if ((field3114 == 10) && (field0008 < 0x32)) {
              recognizedCommand = (unsigned short)(facing == '\x01');
              if (field0008 == 0xa3) {
                field3114 = 0xb;
              }
            }
            else if ((field3114 == 0xb) && (field0008 == 0xa3)) {
              buttonPulse[2] = 1;
              if (field0008 == 0xe8) {
                field3114 = 0;
              }
            }
            else if ((field3114 == 0xc) && (field0008 < 0x32)) {
              recognizedCommand = (unsigned short)(facing == '\x01');
              if (field0008 == 0xa3) {
                field3114 = 0xd;
              }
            }
            else if ((field3114 == 0xd) && (field0008 == 0xa3)) {
              buttonPulse[0] = 1;
              inputY = 1;
              if (field0008 == 0xe6) {
                field3114 = 0;
              }
            }
            else if ((field3114 == 0xe) && (field0008 < 0x32)) {
              recognizedCommand = (unsigned short)(facing == '\x01');
              if (field0008 == 0xa3) {
                field3114 = 0xf;
              }
            }
            else if ((field3114 == 0xf) && (field0008 == 0xa3)) {
              buttonPulse[1] = 1;
              inputY = 1;
              if (field0008 == 0xe7) {
                field3114 = 0;
              }
            }
            else if ((field3114 == 0x10) && (field0008 < 0x32)) {
              recognizedCommand = (unsigned short)(facing == '\x01');
              if (field0008 == 0xa3) {
                field3114 = 0x11;
              }
            }
            else if ((field3114 == 0x11) && (field0008 == 0xa3)) {
              buttonPulse[2] = 1;
              inputY = 1;
              if (field0008 == 0xe8) {
                field3114 = 0;
              }
            }
            else if ((field3114 == 0x14) && (field0008 < 0x32)) {
              buttonPulse[0] = 1;
              inputY = 1;
              if (field0008 == 0xcc) {
                field3114 = 0;
              }
            }
            else {
              if ((((1 < attackCollisionResult) && (hitstopFrames == 0)) &&
                  (randomRoll = RandomRange(0,100),
                  (float)randomRoll < field00a8 * 25.0f)) &&
                 ((field3114 != 1 && (field3114 != 2)))) {
                randomValue = RandomRange(0,1000);
                field3110 = randomValue & 0xffff;
                if (field0008 == 200) {
                  if (((*opponentSlot)->positionY < 0.0) &&
                     (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if (((((*opponentSlot)->positionY < 0.0) &&
                       (forwardSeparation < 90.0)) && (field3110 < 600)) &&
                     (300 < field3110)) {
                    field3114 = 6;
                    return;
                  }
                  if (((forwardSeparation < 80.0) && (0 < field3110)) &&
                     (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                  }
                  if (((forwardSeparation < 70.0) && (300 < field3110)) &&
                     (field3110 < 600)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if (0x3ca < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    wallCollision = RandomRange(0,2);
                    inputX = wallCollision + -1;
                    return;
                  }
                  if (600 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,3);
                    if (randomChoice == 0) {
                      field3114 = 6;
                    }
                    randomChoice = RandomRange(0,3);
                    if (randomChoice == 0) {
                      field3114 = 8;
                    }
                    randomChoice = RandomRange(0,3);
                    if (randomChoice == 0) {
                      field3114 = 0xc;
                    }
                    randomChoice = RandomRange(0,3);
                    if (randomChoice == 0) {
                      field3114 = 0xe;
                    }
                    if (50.0 <= forwardSeparation) {
                      return;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 0x14;
                    return;
                  }
                }
                if (field0008 == 0xc9) {
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (field3110 < 300)) && (attackCollisionResult == 3)) {
                    randomChoice = RandomRange(0,2);
                    recognizedCommand = randomChoice + 0x14;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (300 < field3110)) && (field3110 < 0x226)) {
                    recognizedCommand = 0x1f;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (0x226 < field3110)) &&
                     ((field3110 < 600 && (999 < meter)))) {
                    randomChoice = RandomRange(0,3);
                    recognizedCommand = randomChoice + 100;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (600 < field3110)) && (field3110 < 0x2ee)) {
                    inputX = facing;
                    inputY = 0xff;
                    return;
                  }
                  if (field3110 < 100) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                  }
                  if (((100 < field3110) && (field3110 < 0x15e))
                     && (forwardSeparation < 110.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (0x1c2 < field3110)) &&
                     ((field3110 < 600 && (forwardSeparation < 80.0)))) {
                    buttonPulse[2] = 1;
                    return;
                  }
                  if (0x3b6 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    wallCollision = RandomRange(0,2);
                    inputX = wallCollision + -1;
                    return;
                  }
                  if (600 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 6;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 8;
                    }
                    randomChoice = RandomRange(0,3);
                    if (randomChoice == 0) {
                      field3114 = 0xc;
                    }
                    randomChoice = RandomRange(0,3);
                    if (randomChoice == 0) {
                      field3114 = 0xe;
                    }
                    if (50.0 <= forwardSeparation) {
                      return;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 0x14;
                    return;
                  }
                }
                if (field0008 == 0xca) {
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (0 < field3110)) && (field3110 < 0x96)) {
                    recognizedCommand = 0x1f;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (0x96 < field3110)) &&
                     ((field3110 < 200 && (999 < meter)))) {
                    randomChoice = RandomRange(0,3);
                    recognizedCommand = randomChoice + 100;
                    return;
                  }
                  if ((200 < field3110) && (field3110 < 400)) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                  }
                  if (500 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 6;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 8;
                    }
                    randomChoice = RandomRange(0,3);
                    if (randomChoice == 0) {
                      field3114 = 0xc;
                    }
                    randomChoice = RandomRange(0,3);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 0xe;
                    return;
                  }
                }
                if (field0008 == 0xcb) {
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (field3110 < 300)) && (attackCollisionResult == 3)) {
                    randomChoice = RandomRange(0,3);
                    recognizedCommand = randomChoice + 0x1e;
                    return;
                  }
                  if ((0 < field3110) && (field3110 < 300)) {
                    recognizedCommand = 10;
                    return;
                  }
                  if (((0x15e < field3110) && (field3110 < 300))
                     && (350.0 < field0118)) {
                    recognizedCommand = 0x34;
                    return;
                  }
                  if ((0x15e < field3110) && (field3110 < 600)) {
                    recognizedCommand = 0x1e;
                    return;
                  }
                  if (((600 < field3110) && (field3110 < 0x28a))
                     && (500.0 < field0118)) {
                    recognizedCommand = 0x1f;
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
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (forwardSeparation < 90.0)) &&
                     ((field3110 < 600 && (300 < field3110)))) {
                    field3114 = 6;
                    return;
                  }
                  if (((forwardSeparation < 70.0) && (0 < field3110)) &&
                     (field3110 < 200)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if (((forwardSeparation < 80.0) && (200 < field3110)) &&
                     (field3110 < 600)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                  }
                  if (0x3ca < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    wallCollision = RandomRange(0,2);
                    inputX = wallCollision + -1;
                    return;
                  }
                  if (800 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 6;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 8;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xc;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xe;
                    }
                    if (50.0 <= forwardSeparation) {
                      return;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 0x14;
                    return;
                  }
                }
                if (field0008 == 0xcd) {
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (300 < field3110)) && (field3110 < 0x226)) {
                    recognizedCommand = 0x1f;
                    return;
                  }
                  if (((((*opponentSlot)->positionY < 0.0) &&
                       (0x226 < field3110)) && (field3110 < 600))
                     && (999 < meter)) {
                    randomChoice = RandomRange(0,3);
                    recognizedCommand = randomChoice + 100;
                    return;
                  }
                  if (field3110 < 100) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                  }
                  if (((100 < field3110) && (field3110 < 0x15e))
                     && (forwardSeparation < 110.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                  }
                  if ((((*opponentSlot)->positionY < 0.0) &&
                      (0x15e < field3110)) &&
                     ((field3110 < 0x226 && (forwardSeparation < 90.0)))) {
                    buttonPulse[2] = 1;
                    return;
                  }
                  if (((0x226 < field3110) && (field3110 < 0x276))
                     && (attackCollisionResult == 2)) {
                    recognizedCommand = 0x1e;
                    return;
                  }
                  if (0x3b6 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    wallCollision = RandomRange(0,2);
                    inputX = wallCollision + -1;
                    return;
                  }
                  if (500 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 6;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 8;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xc;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xe;
                    }
                    if (50.0 <= forwardSeparation) {
                      return;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 0x14;
                    return;
                  }
                }
                if (field0008 == 0xce) {
                  if ((0 < field3110) && (field3110 < 600)) {
                    recognizedCommand = 10;
                    return;
                  }
                  if (((0x28a < field3110) && (field3110 < 600))
                     && (350.0 < field0118)) {
                    recognizedCommand = 0x34;
                    return;
                  }
                  if ((0x28a < field3110) && (field3110 < 800)) {
                    recognizedCommand = 0x1e;
                    return;
                  }
                  if (((800 < field3110) && (field3110 < 0x352))
                     && (500.0 < field0118)) {
                    recognizedCommand = 0x1f;
                    return;
                  }
                  if (900 < field3110) {
                    field3114 = 1;
                    return;
                  }
                }
                if (field0008 == 0xcf) {
                  if (((*opponentSlot)->positionY < 0.0) &&
                     (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    return;
                  }
                  if ((forwardSeparation < 60.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
                    return;
                  }
                  if (((forwardSeparation < 125.0) && (399 < field3110)) &&
                     (field3110 < 700)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                  }
                  if (699 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,4);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 3;
                    return;
                  }
                }
                if (field0008 == 0xd0) {
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
                  if (0x3b6 < field3110) {
                    wallCollision = RandomRange(0,2);
                    inputX = wallCollision + -1;
                    return;
                  }
                  if (0x289 < field3110) {
                    field3114 = 3;
                    return;
                  }
                }
                if (field0008 == 0xd1) {
                  if ((field3110 < 200) && (attackCollisionResult == 3)) {
                    randomChoice = RandomRange(0,2);
                    recognizedCommand = randomChoice + 0x1f;
                    return;
                  }
                  if (0x3b6 < field3110) {
                    wallCollision = RandomRange(0,2);
                    inputX = wallCollision + -1;
                    return;
                  }
                  if (0x289 < field3110) {
                    field3114 = 3;
                    return;
                  }
                }
                if (field0008 == 0xe7) {
                  if ((0 < field3110) && (field3110 < 400)) {
                    recognizedCommand = 10;
                    return;
                  }
                  if (((0x1c2 < field3110) && (field3110 < 400))
                     && (350.0 < field0118)) {
                    recognizedCommand = 0x34;
                    return;
                  }
                  if ((0x1c2 < field3110) && (field3110 < 600)) {
                    recognizedCommand = 0x1e;
                    return;
                  }
                  if (((600 < field3110) && (field3110 < 0x28a))
                     && (500.0 < field0118)) {
                    recognizedCommand = 0x1f;
                    return;
                  }
                  if (699 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 6;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 8;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xc;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xe;
                    }
                    if (50.0 <= forwardSeparation) {
                      return;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 0x14;
                    return;
                  }
                }
                if (((field0008 == 0xfa) && (600 < field3110)) &&
                   (positionY == 0.0)) {
                  field3114 = 1;
                  if (50.0 <= forwardSeparation) {
                    return;
                  }
                  field3114 = 0x14;
                  return;
                }
                if ((field0008 == 0xe9) && (500 < field3110)) {
                  field3114 = 1;
                  if (50.0 <= forwardSeparation) {
                    return;
                  }
                  field3114 = 0x14;
                  return;
                }
                if (field0008 == 0xea) {
                  if (((0 < field3110) && (field3110 < 400)) &&
                     (attackCollisionResult == 3)) {
                    recognizedCommand = 0x14;
                    return;
                  }
                  if ((0 < field3110) && (field3110 < 400)) {
                    recognizedCommand = 10;
                    return;
                  }
                  if (((0x1c2 < field3110) && (field3110 < 400))
                     && (350.0 < field0118)) {
                    recognizedCommand = 0x34;
                    return;
                  }
                  if ((0x1c2 < field3110) && (field3110 < 600)) {
                    recognizedCommand = 0x1e;
                    return;
                  }
                  if (((600 < field3110) && (field3110 < 0x28a))
                     && (500.0 < field0118)) {
                    recognizedCommand = 0x1f;
                    return;
                  }
                  if (700 < field3110) {
                    field3114 = 1;
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 6;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice == 0) {
                      field3114 = 8;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xc;
                    }
                    randomChoice = RandomRange(0,4);
                    if (randomChoice == 0) {
                      field3114 = 0xe;
                    }
                    if (50.0 <= forwardSeparation) {
                      return;
                    }
                    randomChoice = RandomRange(0,2);
                    if (randomChoice != 0) {
                      return;
                    }
                    field3114 = 0x14;
                    return;
                  }
                }
                if (((field0008 == 0xeb) && (0x1c2 < field3110)) &&
                   (field3110 < 600)) {
                  recognizedCommand = 0x1e;
                  return;
                }
              }
              randomRoll = RandomRange(0,100);
              if ((float)randomRoll < 25.0f * field00a8) {
                randomValue = RandomRange(0,1000);
                field3110 = randomValue & 0xffff;
                if (positionY == 0.0) {
                  if (((*opponentSlot)->positionY == 0.0) &&
                     ((*opponentSlot)->field0008 != 99)) {
                    if ((forwardSeparation < 40.0) &&
                       (((*opponentSlot)->positionY == 0.0 &&
                        (field3110 < 5)))) {
                      buttonPulse[2] = 1;
                      inputX = -facing;
                      inputY = 0;
                      return;
                    }
                    if (forwardSeparation < 50.0) {
                      if (((*opponentSlot)->field0008 < 0x32) ||
                         (0x9b < (*opponentSlot)->field0008)) {
                        local_bc = 0;
                      }
                      else {
                        local_bc = 1;
                      }
                      if (field3110 < local_bc * 0xf + 0xf) {
                        buttonPulse[0] = 1;
                        inputY = 1;
                        return;
                      }
                    }
                    if (forwardSeparation < 65.0) {
                      if (((*opponentSlot)->field0008 < 0x32) ||
                         (0x9b < (*opponentSlot)->field0008)) {
                        local_c0 = 0;
                      }
                      else {
                        local_c0 = 1;
                      }
                      if (field3110 < local_c0 * 0xf + 0x14) {
                        buttonPulse[0] = 1;
                        inputY = 0;
                        return;
                      }
                    }
                    if ((60.0 < forwardSeparation) && (forwardSeparation < 90.0)) {
                      if (((*opponentSlot)->field0008 < 0x32) ||
                         (0x9b < (*opponentSlot)->field0008)) {
                        local_c4 = 0;
                      }
                      else {
                        local_c4 = 1;
                      }
                      if ((field3110 < local_c4 * 0xf + 0x23) &&
                         (0x1e < field3110)) {
                        buttonPulse[1] = 1;
                        inputY = 1;
                        return;
                      }
                    }
                    if (((*opponentSlot)->field0008 < 0x32) ||
                       (0x9b < (*opponentSlot)->field0008)) {
                      local_c8 = 0;
                    }
                    else {
                      local_c8 = 1;
                    }
                    if (((double)(local_c8 * -0x46 + 0x46) < forwardSeparation) && (forwardSeparation < 100.0)) {
                      if (((*opponentSlot)->field0008 < 0x32) ||
                         (0x9b < (*opponentSlot)->field0008)) {
                        local_d0 = 0;
                      }
                      else {
                        local_d0 = 1;
                      }
                      if ((field3110 < local_d0 * 2 + 0x54) &&
                         (0x50 < field3110)) {
                        field3114 = 0xc;
                        return;
                      }
                    }
                    if (((*opponentSlot)->field0008 < 0x32) ||
                       (0x9b < (*opponentSlot)->field0008)) {
                      local_d4 = 0;
                    }
                    else {
                      local_d4 = 1;
                    }
                    if (((double)(local_d4 * -0x46 + 0x46) < forwardSeparation) && (forwardSeparation < 120.0)) {
                      if (((*opponentSlot)->field0008 < 0x32) ||
                         (0x9b < (*opponentSlot)->field0008)) {
                        local_dc = 0;
                      }
                      else {
                        local_dc = 1;
                      }
                      if ((field3110 < local_dc * 0xf + 0x80) &&
                         (0x78 < field3110)) {
                        field3114 = 8;
                        return;
                      }
                    }
                    if ((((forwardSeparation < 150.0) && (120.0 < forwardSeparation)) &&
                        (field3110 < 0x7e)) && (0x78 < field3110))
                    {
                      buttonPulse[2] = 1;
                      inputY = 1;
                      return;
                    }
                    if (((forwardSeparation < 120.0) && (70.0 < forwardSeparation)) &&
                       ((field3110 < 0x91 && (0x82 < field3110))))
                    {
                      buttonPulse[2] = 1;
                      inputY = 0;
                      return;
                    }
                    if (((*opponentSlot)->field0008 < 0x32) ||
                       (0x9b < (*opponentSlot)->field0008)) {
                      local_e0 = 0;
                    }
                    else {
                      local_e0 = 1;
                    }
                    if (((double)(local_e0 * -0x50 + 0x50) < forwardSeparation) && (forwardSeparation < 130.0)) {
                      if (((*opponentSlot)->field0008 < 0x32) ||
                         (0x9b < (*opponentSlot)->field0008)) {
                        local_e8 = 0;
                      }
                      else {
                        local_e8 = 1;
                      }
                      if ((field3110 < local_e8 * 0xf + 0x9b) &&
                         (0x91 < field3110)) {
                        field3114 = 0xe;
                        return;
                      }
                    }
                    if (((*opponentSlot)->field0008 < 0x32) ||
                       (0x9b < (*opponentSlot)->field0008)) {
                      local_ec = 0;
                    }
                    else {
                      local_ec = 1;
                    }
                    if (((double)(local_ec * -0x5a + 0x5a) < forwardSeparation) && (forwardSeparation < 140.0)) {
                      if (((*opponentSlot)->field0008 < 0x32) ||
                         (0x9b < (*opponentSlot)->field0008)) {
                        local_f4 = 0;
                      }
                      else {
                        local_f4 = 1;
                      }
                      if ((field3110 < local_f4 * 0xf + 0xb4) &&
                         (0xa5 < field3110)) {
                        field3114 = 10;
                        return;
                      }
                    }
                    if ((((110.0 < forwardSeparation) && (forwardSeparation < 160.0)) &&
                        (field3110 < 0xcd)) && (200 < field3110))
                    {
                      field3114 = 10;
                      return;
                    }
                    if (((forwardSeparation < 80.0) && (field3110 < 0xeb)) &&
                       ((0xdc < field3110 &&
                        ((500.0 < field0118 &&
                         (199 < (*opponentSlot)->field0008)))))) {
                      recognizedCommand = 0x20;
                      return;
                    }
                    if ((((forwardSeparation < 80.0) && (field3110 < 0xf0)) &&
                        (0xeb < field3110)) &&
                       ((1999 < meter &&
                        (199 < (*opponentSlot)->field0008)))) {
                      randomChoice = RandomRange(0,3);
                      recognizedCommand = randomChoice + 0x65;
                      return;
                    }
                    if (((forwardSeparation < 100.0) && (field3110 < 0xf2)) &&
                       ((0xf0 < field3110 &&
                        ((meter == 3000 &&
                         (199 < (*opponentSlot)->field0008)))))) {
                      recognizedCommand = 0x5c;
                      return;
                    }
                    if ((((100.0 < forwardSeparation) && (forwardSeparation < 130.0)) &&
                        (field3110 < 0x136)) && (300 < field3110))
                    {
                      recognizedCommand = 10;
                      return;
                    }
                    if (((130.0 < forwardSeparation) && (forwardSeparation < 180.0)) &&
                       ((field3110 < 0x13b && (0x136 < field3110))
                       )) {
                      recognizedCommand = 0xb;
                      return;
                    }
                    if (((90.0 < forwardSeparation) && (forwardSeparation < 140.0)) &&
                       ((field3110 < 0x14a && (0x140 < field3110))
                       )) {
                      recognizedCommand = 0x1e;
                      return;
                    }
                    if ((((90.0 < forwardSeparation) && (forwardSeparation < 140.0)) &&
                        (field3110 < 0x154)) &&
                       ((0x14a < field3110 &&
                        (500.0 < field0118)))) {
                      recognizedCommand = 0x1f;
                      return;
                    }
                    if (((field3110 < 0x2ee) && (700 < field3110))
                       && ((0x31 < (*opponentSlot)->field0008 &&
                           (((*opponentSlot)->field0008 < 0x9c &&
                            (100.0 < forwardSeparation)))))) {
                      field3114 = 5;
                      return;
                    }
                  }
                  if ((*opponentSlot)->positionY < 0.0) {
                    if (((((*opponentSlot)->velocityY < 0.0) &&
                         (forwardSeparation < 80.0)) && (verticalSeparation < 120.0)) &&
                       (field3110 < 10)) {
                      inputY = 0xff;
                      inputX = -facing;
                      return;
                    }
                    if (0.0 < (*opponentSlot)->velocityY) {
                      if (((forwardSeparation < 90.0) && (verticalSeparation < 140.0)) &&
                         (((80.0 < verticalSeparation && (field3110 < 6)) &&
                          ((500.0 < field0118 ||
                           ('\0' < field0120)))))) {
                        recognizedCommand = 0x16;
                        return;
                      }
                      if ((((forwardSeparation < 80.0) && (verticalSeparation < 140.0)) &&
                          (100.0 < verticalSeparation)) &&
                         ((field3110 < 0x2d && (10 < field3110))))
                      {
                        buttonPulse[1] = 1;
                        inputY = 0;
                        return;
                      }
                      if (((forwardSeparation < 90.0) && (verticalSeparation < 170.0)) &&
                         ((150.0 < verticalSeparation &&
                          ((field3110 < 0x50 && (0x2d < field3110)
                           ))))) {
                        buttonPulse[2] = 1;
                        inputY = 0;
                        return;
                      }
                      if ((((120.0 < forwardSeparation) && (forwardSeparation < 140.0)) &&
                          (verticalSeparation < 150.0)) &&
                         (((120.0 < verticalSeparation && (field3110 < 0x6e)) &&
                          (0x50 < field3110)))) {
                        buttonPulse[1] = 1;
                        inputY = 0;
                        return;
                      }
                      if (((forwardSeparation < 70.0) && (field3110 < 0xd2)) &&
                         ((200 < field3110 &&
                          ((((*opponentSlot)->positionY < -50.0 &&
                            (verticalSeparation < 90.0)) && (1999 < meter)))))) {
                        randomChoice = RandomRange(0,2);
                        recognizedCommand = randomChoice + 0x65;
                        return;
                      }
                      if ((((forwardSeparation < 100.0) && (field3110 < 0x12e)) &&
                          ((300 < field3110 &&
                           (((*opponentSlot)->positionY < -50.0 &&
                            (verticalSeparation < 100.0)))))) && (meter == 3000)) {
                        recognizedCommand = 0x5c;
                        return;
                      }
                    }
                  }
                }
                if ((positionY < 0.0) &&
                   (field3114 != 3)) {
                  if ((*opponentSlot)->positionY == 0.0) {
                    if (((forwardSeparation < 80.0) && (verticalSeparation < 100.0)) &&
                       (field3110 < 100)) {
                      buttonPulse[0] = 1;
                      return;
                    }
                    if ((((forwardSeparation < 80.0) && (90.0 < verticalSeparation)) &&
                        ((verticalSeparation < 120.0 &&
                         (((*opponentSlot)->positionY <
                           positionY && (100 < field3110)))))) &&
                       (field3110 < 0xb4)) {
                      buttonPulse[1] = 1;
                      return;
                    }
                    if (((((80.0 < forwardSeparation) && (forwardSeparation < 110.0)) &&
                         (0.0 < verticalSeparation)) &&
                        ((verticalSeparation < 70.0 && (0xb4 < field3110)))) &&
                       (field3110 < 0xf0)) {
                      buttonPulse[2] = 1;
                      return;
                    }
                    if (((forwardSeparation < 80.0) && (0xf0 < field3110)) &&
                       ((field3110 < 0xf2 && (80.0 < verticalSeparation)))) {
                      randomChoice = RandomRange(0,3);
                      recognizedCommand = randomChoice + 0x6e;
                      return;
                    }
                  }
                  if ((*opponentSlot)->positionY < 0.0) {
                    if (((forwardSeparation < 80.0) && (verticalSeparation < 100.0)) &&
                       (field3110 < 0x14)) {
                      buttonPulse[0] = 1;
                      return;
                    }
                    if ((((20.0 < forwardSeparation) && (forwardSeparation < 90.0)) &&
                        ((90.0 < verticalSeparation &&
                         ((verticalSeparation < 120.0 &&
                          ((*opponentSlot)->positionY <
                           positionY)))))) &&
                       ((0x14 < field3110 && (field3110 < 0x28))))
                    {
                      buttonPulse[1] = 1;
                      return;
                    }
                    if (((((80.0 < forwardSeparation) && (forwardSeparation < 110.0)) &&
                         (0.0 < verticalSeparation)) &&
                        ((verticalSeparation < 50.0 && (0x28 < field3110)))) &&
                       (field3110 < 0x32)) {
                      buttonPulse[2] = 1;
                      return;
                    }
                  }
                }
              }
              if (((0x31 < field0008) ||
                  ((((*opponentSlot)->field0008 < 0x96 ||
                    (0x9b < (*opponentSlot)->field0008)) &&
                   (((*opponentSlot)->field0008 < 0x32 ||
                    (0x3a < (*opponentSlot)->field0008)))))) ||
                 (((positionY != 0.0 ||
                   (randomRoll = RandomRange(0,100),
                   4.0f * field00a8 <= (float)randomRoll)) ||
                  (forwardSeparation <= 120.0)))) {
                if (((0x31 < field0008) ||
                    (0x31 < (*opponentSlot)->field0008)) ||
                   ((forwardSeparation <= 800.0 ||
                    (((120.0 <= forwardSeparation ||
                      (randomRoll = RandomRange(0,100),
                      2.0f * field00a8 <= (float)randomRoll)) ||
                     ((positionX <= 150.0 ||
                      (490.0 <= positionX)))))))) {
                  randomRoll = RandomRange(0,1000);
                  if (randomRoll < 2) {
                    field3114 = 4;
                  }
                  else {
                    randomRoll = RandomRange(0,100);
                    if (randomRoll < 2) {
                      randomRoll = RandomRange(0,100);
                      if (8.0f * field00a8 <= (float)randomRoll) {
                        field3114 = 0;
                      }
                      else {
                        field3114 = 3;
                      }
                      if (((180.0 < forwardSeparation) && (positionY == 0.0)
                          ) && (randomRoll = RandomRange(0,100), randomRoll < 2)) {
                        inputX = 0;
                        inputY = 0xff;
                        return;
                      }
                      if (((forwardSeparation < 170.0) && (140.0 < forwardSeparation)) &&
                         ((positionY == 0.0 &&
                          ((*opponentSlot)->field0008 < 0x32)))) {
                        inputX = facing;
                        inputY = 0xff;
                        return;
                      }
                    }
                    if (cpuMoveRightFrames > 0) {
                      wallCollision = CollisionSide();
                      if ((wallCollision != '\0') && (0xf < cpuMoveRightFrames)) {
                        cpuMoveRightFrames = 0xf;
                      }
                      inputX = 1;
                      return;
                    }
                    if (cpuMoveLeftFrames > 0) {
                      wallCollision = CollisionSide();
                      if ((wallCollision != '\0') && (0xf < cpuMoveLeftFrames)) {
                        cpuMoveLeftFrames = 0xf;
                      }
                      inputX = 0xff;
                      return;
                    }
                    randomRoll = RandomRange(0,100);
                    if ((randomRoll < 0x32) && (forwardSeparation < 120.0)) {
                      if (facing == '\x01') {
                        randomValue = RandomRange(0,200);
                        cpuMoveLeftFrames = (randomValue & 0xffff) + 0x3c;
                      }
                      else {
                        randomValue = RandomRange(0,200);
                        cpuMoveRightFrames = (randomValue & 0xffff) + 0x3c;
                      }
                    }
                    randomRoll = RandomRange(0,100);
                    if (randomRoll < 0x32) {
                      if (facing == '\x01') {
                        randomValue = RandomRange(0,200);
                        cpuMoveRightFrames = (randomValue & 0xffff) + 0x3c;
                      }
                      else {
                        randomValue = RandomRange(0,200);
                        cpuMoveLeftFrames = (randomValue & 0xffff) + 0x3c;
                      }
                    }
                    else if (facing == -1) {
                      randomValue = RandomRange(0,200);
                      cpuMoveRightFrames = (randomValue & 0xffff) + 0x3c;
                    }
                    else {
                      randomValue = RandomRange(0,200);
                      cpuMoveLeftFrames = (randomValue & 0xffff) + 0x3c;
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
        else {
          recognizedCommand = 0x34;
        }
      }
    }
    else {
      randomRoll = RandomRange(0,100);
      if (8.0f * field00a8 <= (float)randomRoll) {
        field3114 = 0;
      }
      else {
        field3114 = 3;
      }
      randomRoll = RandomRange(0,100);
      inputX = (randomRoll < 0x32) * -2 + '\x01';
      randomRoll = RandomRange(0,0xf0);
      buttonPulse[3] = (double)randomRoll < verticalSeparation;
      randomRoll = RandomRange(0,0x140);
      buttonPulse[3] = (double)randomRoll < forwardSeparation;
      if ((((199 < (*opponentSlot)->field0008) &&
           ((*opponentSlot)->field0008 < 0xfa)) &&
          ((*opponentSlot)->field000a < 3)) &&
         ((verticalSeparation < 100.0 && (forwardSeparation < 150.0)))) {
        buttonPulse[3] = 0;
      }
    }
  }
  return;
}
