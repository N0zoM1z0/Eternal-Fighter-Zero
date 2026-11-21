// Natural C++ reconstruction of Akiko's 10,684-byte action-state transition and buffered-input dispatcher.
// Native owner: Character16::Slot04 at 0x00721DC0.
#include "CharacterViews.h"

typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;

extern "C" double _DAT_007872f8;
extern "C" double _DAT_007875c8;
extern "C" double _DAT_007875d0;
extern "C" double _DAT_00787c30;
extern "C" double _DAT_00787d88;
extern "C" double _DAT_00787e30;
extern "C" double _DAT_00787e38;
extern "C" double _DAT_00787e40;
extern "C" double _DAT_00787e48;

#define param_1 (reinterpret_cast<undefined4 *>(this))
void Character16::Slot04()
{

  if (*(ushort *)(param_1 + 2) < 200) {
    *(undefined1 *)(param_1 + 0x6a) = 0;
  }
  if (*(unsigned char *)((int)param_1 + 0x1aa) <= 0) {
    *(undefined1 *)((int)param_1 + 0x1a9) = 0;
  }
  else {
    --(*(unsigned char *)((int)param_1 + 0x1aa));
  }
  if (*(unsigned char *)((int)param_1 + 0x1a9) == '\0') {
    *(undefined1 *)((int)param_1 + 0x1aa) = 0;
  }
  if ((((*(short *)((int)param_1 + 0x262) == 0x34) &&
       ((((*(double *)(param_1 + 0x46) >= _DAT_00787c30 && (1 < (int)param_1[0x5a])) &&
         (param_1[0x5a] != 6)) || (('\0' < *(char *)(param_1 + 0x48) && (1 < (int)param_1[0x5a])))))
       ) && ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
     (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
      ((SecondarySequence *)param_1[0x59])[0xa7].field0000)) {
    ResetPose();
    ClearBufferedButtons();
    *(undefined2 *)(param_1 + 2) = 0xa7;
    if (*(double *)(param_1 + 10) < _DAT_007872f8) {
      *(undefined2 *)(param_1 + 2) = 0xab;
    }
    return;
  }
  if ((int)param_1[0x57] < 2) {
    if (((((int)param_1[0x42] < 0xd05) && (*(short *)((int)param_1 + 0x262) == 0x5d)) &&
        ((*(short *)(param_1 + 0x52) >= 3000 &&
         (((*(double *)(param_1 + 10) == _DAT_007872f8 && (param_1[0x5a] != 6)) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))))) &&
       (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
        *(short *)(param_1[0x59] + 0x9f0))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x13e;
      return;
    }
    if (((((*(short *)((int)param_1 + 0x262) == 0x7a) && (*(short *)(param_1 + 0x52) >= 3000)) &&
         ((param_1[0x58] == 0 &&
          ((*(double *)(param_1 + 10) == _DAT_007872f8 &&
           ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))))) &&
        (((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
         (*(ushort *)(param_1 + 2) < 200)))) &&
       (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
        *(short *)(param_1[0x59] + 0x9b8))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x137;
      return;
    }
    if (((((*(short *)((int)param_1 + 0x262) == 0x79) || (*(short *)((int)param_1 + 0x262) == 0x7a))
         && (*(short *)(param_1 + 0x52) >= 2000)) &&
        (((param_1[0x58] == 0 && (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x9b8))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x136;
      return;
    }
    if (((((((*(short *)((int)param_1 + 0x262) == 0x78) ||
            (*(short *)((int)param_1 + 0x262) == 0x79)) ||
           (*(short *)((int)param_1 + 0x262) == 0x7a)) &&
          ((param_1[0x58] == 0 && (*(short *)(param_1 + 0x52) >= 1000)))) &&
         (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
        ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x9a8))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x135;
      return;
    }
    if (((((*(short *)((int)param_1 + 0x262) == 0x66) && (*(short *)(param_1 + 0x52) >= 3000)) &&
         (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
        ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x970))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x12e;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0x65) || (*(short *)((int)param_1 + 0x262) == 0x66))
        && ((*(short *)(param_1 + 0x52) >= 2000 &&
            ((*(double *)(param_1 + 10) == _DAT_007872f8 &&
             ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))))) &&
       ((((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x968))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x12d;
      return;
    }
    if ((((((*(short *)((int)param_1 + 0x262) == 100) || (*(short *)((int)param_1 + 0x262) == 0x65))
          || (*(short *)((int)param_1 + 0x262) == 0x66)) &&
         (((*(short *)(param_1 + 0x52) >= 1000 && (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
        ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)))) &&
       (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
        *(short *)(param_1[0x59] + 0x960))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 300;
      return;
    }
    if ((((((*(short *)((int)param_1 + 0x262) == 0x70) && (*(short *)(param_1 + 0x52) >= 3000)) &&
          (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
        ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)))) &&
       (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
        *(short *)(param_1[0x59] + 0x998))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x133;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0x6f) || (*(short *)((int)param_1 + 0x262) == 0x70))
        && ((*(short *)(param_1 + 0x52) >= 2000 &&
            ((*(double *)(param_1 + 10) == _DAT_007872f8 &&
             ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))))) &&
       ((((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x988))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x131;
      return;
    }
    if ((((((*(short *)((int)param_1 + 0x262) == 0x6e) || (*(short *)((int)param_1 + 0x262) == 0x6f)
           ) || (*(short *)((int)param_1 + 0x262) == 0x70)) &&
         (((*(short *)(param_1 + 0x52) >= 1000 && (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
        ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)))) &&
       (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
        *(short *)(param_1[0x59] + 0x978))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x12f;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0x48) &&
         (((*(double *)(param_1 + 0x46) >= _DAT_00787c30 || ('\0' < *(char *)(param_1 + 0x48))) &&
          (*(double *)(param_1 + 10) == _DAT_007872f8)))) &&
        ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x858))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x10b;
      return;
    }
    if (((((*(short *)((int)param_1 + 0x262) == 0x47) || (*(short *)((int)param_1 + 0x262) == 0x48))
         && ((*(double *)(param_1 + 10) == _DAT_007872f8 &&
             ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
        ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)))) &&
       (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
        *(short *)(param_1[0x59] + 0x848))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x109;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0x46) && (*(double *)(param_1 + 10) == _DAT_007872f8)
         ) && ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x838))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x107;
      return;
    }
    if (((*(short *)((int)param_1 + 0x262) == 0x16) && (*(double *)(param_1 + 10) == _DAT_007872f8))
       && (((*(double *)(param_1 + 0x46) >= _DAT_00787c30 || ('\0' < *(char *)(param_1 + 0x48))) &&
           (((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0 &&
            (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)
               ) || (*(ushort *)(param_1 + 2) < 200)) &&
             (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
              *(short *)(param_1[0x59] + 0x808))))))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x101;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0x15) || (*(short *)((int)param_1 + 0x262) == 0x16))
        && ((*(double *)(param_1 + 10) == _DAT_007872f8 &&
            ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x800))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x100;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0x14) && (*(double *)(param_1 + 10) == _DAT_007872f8)
         ) && ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x7e8))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0xfd;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0x20) &&
         ((*(double *)(param_1 + 0x46) >= _DAT_00787c30 || ('\0' < *(char *)(param_1 + 0x48))))) &&
        (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
       (((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0 &&
        (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
          (*(ushort *)(param_1 + 2) < 200)) &&
         (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
          *(short *)(param_1[0x59] + 0x830))))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x106;
      return;
    }
    if (((*(short *)((int)param_1 + 0x262) == 0x1f) || (*(short *)((int)param_1 + 0x262) == 0x20))
       && ((((*(double *)(param_1 + 10) == _DAT_007872f8 &&
             ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
            ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6))
             || (*(ushort *)(param_1 + 2) < 200)))) &&
           (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
            *(short *)(param_1[0x59] + 0x828))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x105;
      return;
    }
    if (((((*(short *)((int)param_1 + 0x262) == 0x1e) &&
          (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
        ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)))) &&
       (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
        *(short *)(param_1[0x59] + 0x820))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0x104;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0xc) &&
         ((*(double *)(param_1 + 0x46) >= _DAT_00787c30 || ('\0' < *(char *)(param_1 + 0x48))))) &&
        ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
       (((*(double *)(param_1 + 10) == _DAT_007872f8 &&
         ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
          (*(ushort *)(param_1 + 2) < 200)))) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x7e0))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0xfc;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 0xb) || (*(short *)((int)param_1 + 0x262) == 0xc)) &&
        (((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0 &&
         (*(double *)(param_1 + 10) == _DAT_007872f8)))) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x7d8))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0xfb;
      return;
    }
    if ((((*(short *)((int)param_1 + 0x262) == 10) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
        (*(double *)(param_1 + 10) == _DAT_007872f8)) &&
       (((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
         (*(ushort *)(param_1 + 2) < 200)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 2000))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0xfa;
      return;
    }
  }
  if (((((int)param_1[0x57] < 3) && (*(short *)((int)param_1 + 0x262) == 6)) &&
      (((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0 &&
       (((*(double *)(param_1 + 10) < _DAT_007872f8 && (*(unsigned char *)((int)param_1 + 0x15a) < 1)) &&
        (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
         *(short *)(param_1[0x59] + 0x70))))))) &&
     ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
      (*(ushort *)(param_1 + 2) < 200)))) {
    ResetPose();
    ClearBufferedButtons();
    ++(*(unsigned char *)((int)param_1 + 0x15a));
    *(undefined2 *)(param_1 + 2) = 0xe;
    if (*(char *)(param_1 + 0x62) == *(char *)(param_1 + 0x14)) {
      *(undefined2 *)(param_1 + 2) = 0xf;
    }
    if ((int)*(char *)(param_1 + 0x62) == -(int)*(char *)(param_1 + 0x14)) {
      *(undefined2 *)(param_1 + 2) = 0x10;
    }
    return;
  }
  if (((int)param_1[0x57] < 1) &&
     ((*(short *)((int)param_1 + 0x262) == 0 || (*(short *)((int)param_1 + 0x262) == 1)))) {
    if ((*(double *)(param_1 + 10) < _DAT_007872f8) && (*(byte *)((int)param_1 + 0x159) < 2)) {
      if ((((((*(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8)) *
              (double)(1 - ((int)*(short *)((int)param_1 + 0x262) << 1)) < _DAT_007872f8
             ) || ((_DAT_007872f8 ==
                    *(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8) &&
                   ((int)*(char *)(param_1 + 0x14) == ((1 - ((int)*(short *)((int)param_1 + 0x262) << 1)) * -1)))
                  )) &&
           (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
            ((SecondarySequence *)param_1[0x59])[0xa5].field0000)) &&
          (((*(ushort *)(param_1 + 2) != 0xaa && (*(double *)(param_1 + 10) < _DAT_00787e48)) &&
           ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
         ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
          (*(ushort *)(param_1 + 2) < 200)))) {
        if (*(ushort *)(param_1 + 2) != 0xa5) {
          ResetPose();
        }
        *(undefined2 *)(param_1 + 2) = 0xa5;
        FaceOpponent();
        ++(*(unsigned char *)((int)param_1 + 0x159));
        ++(*(unsigned char *)((int)param_1 + 0x15a));
        *(undefined1 *)(param_1 + 0x6a) = 0;
        return;
      }
      if ((((_DAT_007872f8 <
             (*(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8)) *
             (double)(1 - ((int)*(short *)((int)param_1 + 0x262) << 1))) ||
           ((_DAT_007872f8 == *(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8)
            && ((int)*(char *)(param_1 + 0x14) == 1 - ((int)*(short *)((int)param_1 + 0x262) << 1))))) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
            ((SecondarySequence *)param_1[0x59])[0xa6].field0000 &&
           ((*(ushort *)(param_1 + 2) != 0xaa &&
            ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))))) &&
         (((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
          (*(ushort *)(param_1 + 2) < 200)))) {
        if (*(ushort *)(param_1 + 2) != 0xa6) {
          ResetPose();
        }
        *(undefined2 *)(param_1 + 2) = 0xa6;
        FaceOpponent();
        ++(*(unsigned char *)((int)param_1 + 0x159));
        ++(*(unsigned char *)((int)param_1 + 0x15a));
        *(undefined1 *)(param_1 + 0x6a) = 0;
        return;
      }
    }
    if ((*(double *)(param_1 + 10) == _DAT_007872f8) &&
       ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) {
      if (((((*(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8)) *
             (double)(1 - ((int)*(short *)((int)param_1 + 0x262) << 1)) < _DAT_007872f8)
           || ((_DAT_007872f8 ==
                *(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8) &&
               ((int)*(char *)(param_1 + 0x14) == ((1 - ((int)*(short *)((int)param_1 + 0x262) << 1)) * -1)))))
          && (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
              ((SecondarySequence *)param_1[0x59])[0xa3].field0000)) &&
         ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6)) ||
          (*(ushort *)(param_1 + 2) < 200)))) {
        if (*(ushort *)(param_1 + 2) != 0xa3) {
          ResetPose();
        }
        *(undefined2 *)(param_1 + 2) = 0xa3;
        FaceOpponent();
        (*(char *)(param_1 + 0x56))++;
        *(undefined1 *)(param_1 + 0x6a) = 0;
        return;
      }
      if (((_DAT_007872f8 <
            (*(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8)) *
            (double)(1 - ((int)*(short *)((int)param_1 + 0x262) << 1))) ||
          ((_DAT_007872f8 == *(double *)(*(int *)param_1[0x1e] + 0x20) - *(double *)(param_1 + 8) &&
           ((int)*(char *)(param_1 + 0x14) == 1 - ((int)*(short *)((int)param_1 + 0x262) << 1))))) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
           ((SecondarySequence *)param_1[0x59])[0xa4].field0000 &&
          ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6))
           || (*(ushort *)(param_1 + 2) < 200)))))) {
        if (*(ushort *)(param_1 + 2) != 0xa4) {
          ResetPose();
        }
        *(undefined2 *)(param_1 + 2) = 0xa4;
        FaceOpponent();
        (*(char *)(param_1 + 0x56))++;
        *(undefined1 *)(param_1 + 0x6a) = 0;
        return;
      }
    }
  }
  if (((*(char *)((int)param_1 + 0x18a) == '\x01') || ((*(byte *)(param_1 + 0x6a) & 0x10) != 0)) ||
     ((*(byte *)((int)param_1 + 0x1a9) & 0x10) != 0)) {
    if (*(double *)(param_1 + 10) < _DAT_007872f8) {
      if (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
              *(short *)(param_1[0x59] + 0x678) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0) &&
          ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) &&
             (param_1[0x5a] != 6)) || (*(ushort *)(param_1 + 2) < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        *(undefined2 *)(param_1 + 2) = 0xcf;
      }
      return;
    }
    if ((((*(char *)((int)param_1 + 0x189) == '\x01') || ((*(byte *)(param_1 + 0x6a) & 4) != 0)) ||
        ((*(byte *)((int)param_1 + 0x1a9) & 4) != 0)) &&
       (((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
          *(short *)(param_1[0x59] + 0x660) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
        (((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
         (*(ushort *)(param_1 + 2) < 200)))))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0xcc;
      return;
    }
    if (((((*(char *)((int)param_1 + 0x189) == '\0') || ((*(byte *)(param_1 + 0x6a) & 4) == 0)) ||
         ((*(byte *)((int)param_1 + 0x1a9) & 4) == 0)) &&
        ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
          *(short *)(param_1[0x59] + 0x640) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
       (((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
        (*(ushort *)(param_1 + 2) < 200)))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 200;
      return;
    }
  }
  if (((*(char *)((int)param_1 + 0x18b) == '\x01') || ((*(byte *)(param_1 + 0x6a) & 0x20) != 0)) ||
     ((*(byte *)((int)param_1 + 0x1a9) & 0x20) != 0)) {
    if (*(double *)(param_1 + 10) < _DAT_007872f8) {
      if (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
              *(short *)(param_1[0x59] + 0x680) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0) &&
          ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) &&
             (param_1[0x5a] != 6)) || (*(ushort *)(param_1 + 2) < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        *(undefined2 *)(param_1 + 2) = 0xd0;
      }
      return;
    }
    if (((((*(char *)((int)param_1 + 0x189) == '\x01') || ((*(byte *)(param_1 + 0x6a) & 4) != 0)) ||
         ((*(byte *)((int)param_1 + 0x1a9) & 4) != 0)) &&
        ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
          *(short *)(param_1[0x59] + 0x668) &&
         ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
       (((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
        (*(ushort *)(param_1 + 2) < 200)))) {
      ResetPose();
      ClearBufferedButtons();
      *(undefined2 *)(param_1 + 2) = 0xcd;
      return;
    }
    if (((*(char *)((int)param_1 + 0x189) == '\0') || ((*(byte *)(param_1 + 0x6a) & 4) == 0)) ||
       ((*(byte *)((int)param_1 + 0x1a9) & 4) == 0)) {
      if ((((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
             *(short *)(param_1[0x59] + 0x648)) &&
           ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
          ((_DAT_00787e40 < *(double *)(param_1 + 8) - *(double *)(*(int *)param_1[0x1e] + 0x20) &&
           (*(double *)(param_1 + 8) - *(double *)(*(int *)param_1[0x1e] + 0x20) < _DAT_00787e38))))
         && ((((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) && (param_1[0x5a] != 6))
             || (*(ushort *)(param_1 + 2) < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        *(undefined2 *)(param_1 + 2) = 0xc9;
        return;
      }
      if (((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
            *(short *)(param_1[0x59] + 0x650)) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
         (((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
          (*(ushort *)(param_1 + 2) < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        *(undefined2 *)(param_1 + 2) = 0xca;
        return;
      }
    }
  }
  if (((*(char *)(param_1 + 99) == '\x01') || ((*(byte *)(param_1 + 0x6a) & 0x40) != 0)) ||
     ((*(byte *)((int)param_1 + 0x1a9) & 0x40) != 0)) {
    if (*(double *)(param_1 + 10) < _DAT_007872f8) {
      if (
          (*(char *)(param_1 + 0x62) == *(char *)(param_1 + 0x14)) &&
          (*(char *)((int)param_1 + 0x189) == '\0') &&
          (*(double *)(param_1 + 8) - *(double *)(*(int *)param_1[0x1e] + 0x20) >
           _DAT_007875c8) &&
          (*(double *)(param_1 + 8) - *(double *)(*(int *)param_1[0x1e] + 0x20) <
           _DAT_007875d0) &&
          (*(double *)(*(int *)param_1[0x1e] + 0x28) < _DAT_007872f8) &&
          (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
           *(short *)(param_1[0x59] + 0x780)) &&
          ((*(ushort *)(*(int *)param_1[0x1e] + 8) < 0x32) ||
           (*(ushort *)(*(int *)param_1[0x1e] + 8) > 0x9c)) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0) &&
          (((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) &&
            (param_1[0x5a] != 6)) || (*(ushort *)(param_1 + 2) < 200))) {
        ResetPose();
        ClearBufferedButtons();
        *(undefined2 *)(param_1 + 2) = 0xf0;
        return;
      }
      else if (((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
                 *(short *)(param_1[0x59] + 0x688)) &&
                ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)) &&
               (((*(ushort *)(param_1 + 2) >= 200 &&
                  (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
                 (*(ushort *)(param_1 + 2) < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        *(undefined2 *)(param_1 + 2) = 0xd1;
      }
    }
    else {
      if (((((*(char *)((int)param_1 + 0x189) == '\x01') || ((*(byte *)(param_1 + 0x6a) & 4) != 0))
           || ((*(byte *)((int)param_1 + 0x1a9) & 4) != 0)) &&
          ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
            *(short *)(param_1[0x59] + 0x670) &&
           ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0)))) &&
         (((*(ushort *)(param_1 + 2) >= 200 && (((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6)))) ||
          (*(ushort *)(param_1 + 2) < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        *(undefined2 *)(param_1 + 2) = 0xce;
      }
      else if (((*(char *)((int)param_1 + 0x189) == '\0') || ((*(byte *)(param_1 + 0x6a) & 4) == 0))
              || ((*(byte *)((int)param_1 + 0x1a9) & 4) == 0)) {
        if (
            (*(char *)(param_1 + 0x62) != '\0') &&
            (*(double *)(*(int *)param_1[0x1e] + 0x28) == _DAT_007872f8) &&
            (*(double *)(param_1 + 8) - *(double *)(*(int *)param_1[0x1e] + 0x20) >
             _DAT_00787e30) &&
            (*(double *)(param_1 + 8) - *(double *)(*(int *)param_1[0x1e] + 0x20) <
             _DAT_00787d88) &&
            (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
             *(short *)(param_1[0x59] + 0x6e0)) &&
            (*(double *)(*(int *)param_1[0x1e] + 0x28) == _DAT_007872f8) &&
            ((*(ushort *)(*(int *)param_1[0x1e] + 8) < 0x32) ||
             (*(ushort *)(*(int *)param_1[0x1e] + 8) > 0x9c)) &&
            ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0) &&
            (((*(ushort *)(param_1 + 2) >= 200 && ((int)param_1[0x5a] >= 2)) &&
              (param_1[0x5a] != 6)) || (*(ushort *)(param_1 + 2) < 200))) {
          ResetPose();
          ClearBufferedButtons();
          *(undefined2 *)(param_1 + 2) = 0xdc;
        }
        else if (
            (((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].field0002 <=
             *(short *)(param_1[0x59] + 0x658)) &&
            ((((SecondarySequence *)param_1[0x59])[*(ushort *)(param_1 + 2)].data[*(ushort *)((int)param_1 + 10)].frameFlags & 8) > 0) &&
            (((*(ushort *)(param_1 + 2) >= 200 &&
               ((int)param_1[0x5a] >= 2 && (param_1[0x5a] != 6))) ||
              (*(ushort *)(param_1 + 2) < 200)))) {
          ResetPose();
          ClearBufferedButtons();
          *(undefined2 *)(param_1 + 2) = 0xcb;
        }
      }
    
    }
  }
  return;

}
