// PROVISIONAL RECONSTRUCTION DRAFT — NOT INCLUDED IN THE BUILD.
// Target: Character03::Slot06 at 0x005E85F0.
// The 124 explicit animation labels below are recovered from the target selector
// map. Only animation IDs 1, 2 and 3 have source bodies reconstructed so far;
// the other labels are deliberate placeholders, not semantic implementations.
// Do not register this file as a match unit or claim source/codegen exactness.
#include "CharacterViews.h"

void Character03::Slot06()
{
    if (field014a > 0) return;
    if ((*opponentSlot)->field014c > 0) return;

    unsigned short frameDuration, frameCount;
    EffectSpawn effect;
    frameDuration = patterns[field0008].frames[field000a].duration;
    frameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&effect);

    switch (field0008) {
    default:
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) field000a = 0;
        }
        break;
    case 1: // dispatch 0, target 0x005E8718
        field0158 = 0;
        field0030 = 0.7;
        field0038 = 0.0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) field000a = 0;
        }
        break;
    case 2: // dispatch 1, target 0x005E8793
        field0158 = 0;
        field0030 = -0.7;
        field0038 = 0.0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) field000a = 0;
        }
        break;
    case 3: // dispatch 2, target 0x005E880E
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        FaceOpponent();
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) field000a = 0;
        }
        break;
    case 4: // dispatch 3, target 0x005E8891
        // TODO: reconstruct this target animation body.
        break;
    case 5: // dispatch 4, target 0x005E89F4
        // TODO: reconstruct this target animation body.
        break;
    case 6: // dispatch 5, target 0x005E8B61
        // TODO: reconstruct this target animation body.
        break;
    case 7: // dispatch 6, target 0x005E8CA9
        // TODO: reconstruct this target animation body.
        break;
    case 8: // dispatch 7, target 0x005E8D36
        // TODO: reconstruct this target animation body.
        break;
    case 9: // dispatch 8, target 0x005E8DC3
        // TODO: reconstruct this target animation body.
        break;
    case 13: // dispatch 9, target 0x005E8E7A
        // TODO: reconstruct this target animation body.
        break;
    case 14: // dispatch 10, target 0x005E8F1F
        // TODO: reconstruct this target animation body.
        break;
    case 15: // dispatch 11, target 0x005E902E
        // TODO: reconstruct this target animation body.
        break;
    case 16: // dispatch 12, target 0x005E913B
        // TODO: reconstruct this target animation body.
        break;
    case 47: // dispatch 13, target 0x005E9248
        // TODO: reconstruct this target animation body.
        break;
    case 50: // dispatch 14, target 0x005E9378
        // TODO: reconstruct this target animation body.
        break;
    case 51: // dispatch 15, target 0x005E9569
        // TODO: reconstruct this target animation body.
        break;
    case 52: // dispatch 16, target 0x005E975A
        // TODO: reconstruct this target animation body.
        break;
    case 53: // dispatch 17, target 0x005E994B
        // TODO: reconstruct this target animation body.
        break;
    case 54: // dispatch 18, target 0x005E9B3C
        // TODO: reconstruct this target animation body.
        break;
    case 55: // dispatch 19, target 0x005E9D2D
        // TODO: reconstruct this target animation body.
        break;
    case 56: // dispatch 20, target 0x005E9F1E
        // TODO: reconstruct this target animation body.
        break;
    case 57: // dispatch 21, target 0x005EA0F7
        // TODO: reconstruct this target animation body.
        break;
    case 58: // dispatch 22, target 0x005EA2D0
        // TODO: reconstruct this target animation body.
        break;
    case 59: // dispatch 23, target 0x005EA4A9
        // TODO: reconstruct this target animation body.
        break;
    case 60: // dispatch 24, target 0x005EA6A8
        // TODO: reconstruct this target animation body.
        break;
    case 61: // dispatch 25, target 0x005EA8A7
        // TODO: reconstruct this target animation body.
        break;
    case 62: // dispatch 26, target 0x005EAAA6
        // TODO: reconstruct this target animation body.
        break;
    case 63: // dispatch 27, target 0x005EAC5D
        // TODO: reconstruct this target animation body.
        break;
    case 64: // dispatch 28, target 0x005EAE08
        // TODO: reconstruct this target animation body.
        break;
    case 65: // dispatch 29, target 0x005EB039
        // TODO: reconstruct this target animation body.
        break;
    case 66: // dispatch 30, target 0x005EB26A
        // TODO: reconstruct this target animation body.
        break;
    case 67: // dispatch 31, target 0x005EB453
        // TODO: reconstruct this target animation body.
        break;
    case 68: // dispatch 32, target 0x005EB630
        // TODO: reconstruct this target animation body.
        break;
    case 69: // dispatch 33, target 0x005EB76C
        // TODO: reconstruct this target animation body.
        break;
    case 70: // dispatch 34, target 0x005EB881
        // TODO: reconstruct this target animation body.
        break;
    case 71: // dispatch 35, target 0x005EBA61
        // TODO: reconstruct this target animation body.
        break;
    case 72: // dispatch 36, target 0x005EBC0C
        // TODO: reconstruct this target animation body.
        break;
    case 73: // dispatch 37, target 0x005EBD61
        // TODO: reconstruct this target animation body.
        break;
    case 74: // dispatch 38, target 0x005EBEB6
        // TODO: reconstruct this target animation body.
        break;
    case 75: // dispatch 39, target 0x005EBFF3
        // TODO: reconstruct this target animation body.
        break;
    case 76: // dispatch 40, target 0x005EC1F0
        // TODO: reconstruct this target animation body.
        break;
    case 77: // dispatch 41, target 0x005EC3ED
        // TODO: reconstruct this target animation body.
        break;
    case 81: // dispatch 42, target 0x005EC5D2
        // TODO: reconstruct this target animation body.
        break;
    case 82: // dispatch 43, target 0x005EC7B7
        // TODO: reconstruct this target animation body.
        break;
    case 83: // dispatch 44, target 0x005EC9D9
        // TODO: reconstruct this target animation body.
        break;
    case 84: // dispatch 45, target 0x005ECC1E
        // TODO: reconstruct this target animation body.
        break;
    case 85: // dispatch 46, target 0x005ECE63
        // TODO: reconstruct this target animation body.
        break;
    case 86: // dispatch 47, target 0x005ED036
        // TODO: reconstruct this target animation body.
        break;
    case 87: // dispatch 48, target 0x005ED218
        // TODO: reconstruct this target animation body.
        break;
    case 96: // dispatch 49, target 0x005ED2CB
        // TODO: reconstruct this target animation body.
        break;
    case 97: // dispatch 50, target 0x005ED360
        // TODO: reconstruct this target animation body.
        break;
    case 98: // dispatch 51, target 0x005ED458
        // TODO: reconstruct this target animation body.
        break;
    case 99: // dispatch 52, target 0x005ED550
        // TODO: reconstruct this target animation body.
        break;
    case 150: // dispatch 53, target 0x005ED5FF
        // TODO: reconstruct this target animation body.
        break;
    case 151: // dispatch 54, target 0x005ED7AB
        // TODO: reconstruct this target animation body.
        break;
    case 152: // dispatch 55, target 0x005ED957
        // TODO: reconstruct this target animation body.
        break;
    case 153: // dispatch 56, target 0x005EDB03
        // TODO: reconstruct this target animation body.
        break;
    case 154: // dispatch 57, target 0x005EDC97
        // TODO: reconstruct this target animation body.
        break;
    case 155: // dispatch 58, target 0x005EDE2B
        // TODO: reconstruct this target animation body.
        break;
    case 156: // dispatch 59, target 0x005EDFBF
        // TODO: reconstruct this target animation body.
        break;
    case 157: // dispatch 60, target 0x005EE0CF
        // TODO: reconstruct this target animation body.
        break;
    case 158: // dispatch 61, target 0x005EE223
        // TODO: reconstruct this target animation body.
        break;
    case 161: // dispatch 62, target 0x005EE377
        // TODO: reconstruct this target animation body.
        break;
    case 162: // dispatch 63, target 0x005EE48B
        // TODO: reconstruct this target animation body.
        break;
    case 163: // dispatch 64, target 0x005EE676
        // TODO: reconstruct this target animation body.
        break;
    case 164: // dispatch 65, target 0x005EE867
        // TODO: reconstruct this target animation body.
        break;
    case 165: // dispatch 66, target 0x005EE9B2
        // TODO: reconstruct this target animation body.
        break;
    case 166: // dispatch 67, target 0x005EEBB9
        // TODO: reconstruct this target animation body.
        break;
    case 167: // dispatch 68, target 0x005EEDC4
        // TODO: reconstruct this target animation body.
        break;
    case 168: // dispatch 69, target 0x005EEFAC
        // TODO: reconstruct this target animation body.
        break;
    case 169: // dispatch 70, target 0x005EF0F6
        // TODO: reconstruct this target animation body.
        break;
    case 170: // dispatch 71, target 0x005EF240
        // TODO: reconstruct this target animation body.
        break;
    case 171: // dispatch 72, target 0x005EF409
        // TODO: reconstruct this target animation body.
        break;
    case 178: // dispatch 73, target 0x005EF5E8
        // TODO: reconstruct this target animation body.
        break;
    case 180: // dispatch 74, target 0x005EF70A
        // TODO: reconstruct this target animation body.
        break;
    case 200: // dispatch 75, target 0x005EF87C
        // TODO: reconstruct this target animation body.
        break;
    case 201: // dispatch 76, target 0x005EFA4F
        // TODO: reconstruct this target animation body.
        break;
    case 202: // dispatch 77, target 0x005EFC22
        // TODO: reconstruct this target animation body.
        break;
    case 203: // dispatch 78, target 0x005EFDDF
        // TODO: reconstruct this target animation body.
        break;
    case 204: // dispatch 79, target 0x005F008D
        // TODO: reconstruct this target animation body.
        break;
    case 205: // dispatch 80, target 0x005F0278
        // TODO: reconstruct this target animation body.
        break;
    case 206: // dispatch 81, target 0x005F0463
        // TODO: reconstruct this target animation body.
        break;
    case 207: // dispatch 82, target 0x005F0669
        // TODO: reconstruct this target animation body.
        break;
    case 208: // dispatch 83, target 0x005F0840
        // TODO: reconstruct this target animation body.
        break;
    case 209: // dispatch 84, target 0x005F0A17
        // TODO: reconstruct this target animation body.
        break;
    case 210: // dispatch 85, target 0x005F0CB7
        // TODO: reconstruct this target animation body.
        break;
    case 211: // dispatch 86, target 0x005F0E5C
        // TODO: reconstruct this target animation body.
        break;
    case 212: // dispatch 87, target 0x005F10A0
        // TODO: reconstruct this target animation body.
        break;
    case 213: // dispatch 88, target 0x005F1265
        // TODO: reconstruct this target animation body.
        break;
    case 214: // dispatch 89, target 0x005F1321
        // TODO: reconstruct this target animation body.
        break;
    case 220: // dispatch 90, target 0x005F1440
        // TODO: reconstruct this target animation body.
        break;
    case 221: // dispatch 91, target 0x005F160E
        // TODO: reconstruct this target animation body.
        break;
    case 230: // dispatch 92, target 0x005F182F
        // TODO: reconstruct this target animation body.
        break;
    case 231: // dispatch 93, target 0x005F1975
        // TODO: reconstruct this target animation body.
        break;
    case 232: // dispatch 94, target 0x005F1ABB
        // TODO: reconstruct this target animation body.
        break;
    case 233: // dispatch 95, target 0x005F1C6F
        // TODO: reconstruct this target animation body.
        break;
    case 234: // dispatch 96, target 0x005F1DB5
        // TODO: reconstruct this target animation body.
        break;
    case 235: // dispatch 97, target 0x005F1EFB
        // TODO: reconstruct this target animation body.
        break;
    case 248: // dispatch 98, target 0x005F2090
        // TODO: reconstruct this target animation body.
        break;
    case 249: // dispatch 99, target 0x005F223A
        // TODO: reconstruct this target animation body.
        break;
    case 250: // dispatch 100, target 0x005F2562
        // TODO: reconstruct this target animation body.
        break;
    case 251: // dispatch 101, target 0x005F26A9
        // TODO: reconstruct this target animation body.
        break;
    case 252: // dispatch 102, target 0x005F27F0
        // TODO: reconstruct this target animation body.
        break;
    case 253: // dispatch 103, target 0x005F2A5D
        // TODO: reconstruct this target animation body.
        break;
    case 254: // dispatch 104, target 0x005F2BA1
        // TODO: reconstruct this target animation body.
        break;
    case 255: // dispatch 105, target 0x005F2CE5
        // TODO: reconstruct this target animation body.
        break;
    case 256: // dispatch 106, target 0x005F2EC9
        // TODO: reconstruct this target animation body.
        break;
    case 257: // dispatch 107, target 0x005F30D8
        // TODO: reconstruct this target animation body.
        break;
    case 258: // dispatch 108, target 0x005F32E7
        // TODO: reconstruct this target animation body.
        break;
    case 259: // dispatch 109, target 0x005F36BF
        // TODO: reconstruct this target animation body.
        break;
    case 260: // dispatch 110, target 0x005F386E
        // TODO: reconstruct this target animation body.
        break;
    case 261: // dispatch 111, target 0x005F3A20
        // TODO: reconstruct this target animation body.
        break;
    case 262: // dispatch 112, target 0x005F3C6F
        // TODO: reconstruct this target animation body.
        break;
    case 300: // dispatch 113, target 0x005F3DC5
        // TODO: reconstruct this target animation body.
        break;
    case 301: // dispatch 114, target 0x005F405D
        // TODO: reconstruct this target animation body.
        break;
    case 302: // dispatch 115, target 0x005F42F5
        // TODO: reconstruct this target animation body.
        break;
    case 303: // dispatch 116, target 0x005F458D
        // TODO: reconstruct this target animation body.
        break;
    case 304: // dispatch 117, target 0x005F4C63
        // TODO: reconstruct this target animation body.
        break;
    case 305: // dispatch 118, target 0x005F5341
        // TODO: reconstruct this target animation body.
        break;
    case 306: // dispatch 119, target 0x005F5A42
        // TODO: reconstruct this target animation body.
        break;
    case 307: // dispatch 120, target 0x005F5DE3
        // TODO: reconstruct this target animation body.
        break;
    case 308: // dispatch 121, target 0x005F61E7
        // TODO: reconstruct this target animation body.
        break;
    case 309: // dispatch 122, target 0x005F662C
        // TODO: reconstruct this target animation body.
        break;
    case 310: // dispatch 123, target 0x005F698C
        // TODO: reconstruct this target animation body.
        break;
    }
}
