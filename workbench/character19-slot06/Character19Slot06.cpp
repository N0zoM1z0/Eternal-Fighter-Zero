// Partial natural-C++ reconstruction of Character19::Slot06.
// State IDs are grouped using the native 310-byte selector table.
// Cases 0-0x2f, 0x30, 0x31, 0x32, 0x70-0x74, and the shared 0x75 fallback are restored.
// are implemented; remaining native handlers are explicitly TODO.
#include "CharacterViews.h"

void Character19::Slot06()
{
    if (hitstopFrames > 0) {
        return;
    }
    if ((*opponentSlot)->hitstunFrames > 0) {
        return;
    }

    EffectSpawn spawn;
    struct FrameTiming {
        __declspec(align(4)) unsigned short animationFrameCount;
        __declspec(align(4)) unsigned short frameDuration;
    } timing;

    timing.frameDuration = patterns[field0008].frames[field000a].duration;
    timing.animationFrameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&spawn);

    switch (field0008) {
    case 1:
        dashMomentumFlag = 0;
        velocityX = 0.8;
        velocityY = 0.0;
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
            }
        }
        break;
    case 2:
        dashMomentumFlag = 0;
        velocityX = -0.8;
        velocityY = 0.0;
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
            }
        }
        break;
    case 3:
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
            }
        }
        break;
    case 7:
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
                field0008 = 0;
                ResetPose();
            }
        }
        break;

    case 8:
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
                field0008 = 3;
                ResetPose();
            }
        }
        break;

    case 13:
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;

    case 14:
        Slot06UpdateAirMovement(
            timing.frameDuration, timing.animationFrameCount,
            3, 0.0, -3.5,
            2, 0);
        break;

    case 15:
        Slot06UpdateAirMovement(
            timing.frameDuration, timing.animationFrameCount,
            3, 1.5, -2.5,
            2, 0);
        break;

    case 16:
        Slot06UpdateAirMovement(
            timing.frameDuration, timing.animationFrameCount,
            2, -1.5, -2.5,
            1, 0);
        break;

    case 17:
        Slot06UpdateAirMovement(
            timing.frameDuration, timing.animationFrameCount,
            3, 2.0, -0.5,
            2, 1);
        break;

    case 18:
        Slot06UpdateAirMovement(
            timing.frameDuration, timing.animationFrameCount,
            3, 1.5, -0.5,
            2, 0);
        break;

    case 19:
        Slot06UpdateAirMovement(
            timing.frameDuration, timing.animationFrameCount,
            2, -2.0, -0.5,
            1, 1);
        break;

    case 20:
        Slot06UpdateAirMovement(
            timing.frameDuration, timing.animationFrameCount,
            2, -1.5, -0.5,
            1, 0);
        break;

    case 47:
        if ((field000a == 0) && (field000c == 0)) {
            velocityX = 0.0;
            gravity = 0.035;
        }
        velocityY = velocityY + gravity;
        if (((positionY + velocityY) > 0.0) && (field000a < 2)) {
            field000c = 0;
            field000a = 2;
            reinterpret_cast<unsigned char *>(&soundSlots[49])[1] = 7;
            positionY = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            velocityX = 0.0;
        }
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (field000a == 2) {
                field000a = field000a - 2;
            }
            if (timing.animationFrameCount <= field000a) {
                field000a = field000a - 1;
            }
        }
        break;

    case 68:
        Slot06UpdateKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 69:
        Slot06UpdateKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 72:
        Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 73:
        Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 74:
        Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 75:
        Slot06UpdateGroundSkid(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 76:
        Slot06UpdateGroundSkid(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 77:
        Slot06UpdateGroundSkid(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 81:
        Slot06UpdateAirKnockback(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 82:
        Slot06UpdateRepeatedAirKnockback(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 83:
        Slot06UpdateAirborneRebound(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 84:
        Slot06UpdateAirborneRebound(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 70:
        if (field0120 != 0) {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && (field000c == 0) && (field3138 == 0)) {
            meter = meter + 30;
            field3138 = field3138 + 1;
            airActionLockFrames = airActionLockFrames + 0x78;
            velocityX = 0.5;
            velocityY = -2.5;
            gravity = 0.025;
            pendingContextSoundSlot = 0x1f;
            spawn.type = 0;
            spawn.x = (double)(int)positionX;
            spawn.y = (double)(int)positionY;
            spawn.group = 2;
            spawn.layer = 1;
            contextOwner->EmitEffect(&spawn);
        }
        velocityY = velocityY + gravity;
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
            }
        }
        if (((positionY + velocityY) >= 0.0) && (field000a > 1)) {
            positionY = 0.0;
            if (knockdownOnLanding == 0) {
                field0008 = 0x62;
            } else {
                field0008 = 0x61;
            }
            ResetPose();
        }
        break;

    case 59:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            -2.0, 1,
            0.75, 0.032, 0);
        break;

    case 60:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            -4.0, 1,
            0.75, 0.032, 0);
        break;

    case 61:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            -6.0, 1,
            0.75, 0.032, 0);
        break;

    case 62:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            0.0, 0,
            0.75, 0.032, 0);
        break;

    case 63:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            0.0, 0,
            0.0, 0.032, 0);
        break;

    case 64:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            -2.0, 1,
            0.75, 0.032, 1);
        break;

    case 65:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            -4.0, 1,
            0.75, 0.032, 1);
        break;

    case 66:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            0.0, 0,
            0.75, 0.032, 1);
        break;

    case 67:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            0.0, 0,
            0.0, 0.032, 1);
        break;

    case 71:
        Slot06UpdateKnockbackFall(
            timing.frameDuration, timing.animationFrameCount,
            0.0, 0,
            0.0, 0.072, 0);
        break;

    case 50:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.1, 10.0,
            0);
        break;

    case 51:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.5, 20.0,
            0);
        break;

    case 52:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            20, -1.8, 30.0,
            0);
        break;

    case 53:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.1, 10.0,
            0);
        break;

    case 54:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.5, 20.0,
            0);
        break;

    case 55:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            20, -1.8, 30.0,
            0);
        break;

    case 56:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.1, 10.0,
            1);
        break;

    case 57:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.5, 20.0,
            1);
        break;

    case 58:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            20, -1.8, 30.0,
            1);
        break;

    case 4:
        Slot06Case03();
        break;

    case 5:
        Slot06Case04();
        break;

    case 6:
        Slot06Case05();
        break;

    case 9:
        Slot06Case08();
        break;

    case 10:
        Slot06Case09();
        break;

    case 300:
        Slot06Case70();
        break;

    case 303:
        Slot06Case71();
        break;

    case 306:
        Slot06Case72();
        break;

    case 309:
        Slot06Case73();
        break;

    case 310:
        Slot06Case74();
        break;

    case 11:
    case 12:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 48:
    case 49:
    case 78:
    case 79:
    case 80:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
    case 136:
    case 137:
    case 138:
    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:
    case 146:
    case 147:
    case 148:
    case 149:
    case 159:
    case 160:
    case 161:
    case 162:
    case 172:
    case 173:
    case 174:
    case 175:
    case 176:
    case 177:
    case 179:
    case 180:
    case 181:
    case 182:
    case 183:
    case 184:
    case 185:
    case 186:
    case 187:
    case 188:
    case 189:
    case 190:
    case 191:
    case 192:
    case 193:
    case 194:
    case 195:
    case 196:
    case 197:
    case 198:
    case 199:
    case 215:
    case 216:
    case 217:
    case 218:
    case 219:
    case 222:
    case 223:
    case 224:
    case 225:
    case 226:
    case 227:
    case 228:
    case 229:
    case 236:
    case 237:
    case 238:
    case 239:
    case 240:
    case 241:
    case 242:
    case 243:
    case 244:
    case 245:
    case 246:
    case 247:
    case 248:
    case 252:
    case 254:
    case 255:
    case 258:
    case 260:
    case 261:
    case 262:
    case 268:
    case 269:
    case 270:
    case 271:
    case 272:
    case 273:
    case 274:
    case 275:
    case 276:
    case 277:
    case 278:
    case 279:
    case 280:
    case 281:
    case 282:
    case 283:
    case 284:
    case 285:
    case 286:
    case 287:
    case 288:
    case 289:
    case 290:
    case 291:
    case 292:
    case 293:
    case 294:
    case 295:
    case 296:
    case 297:
    case 298:
    case 299:
    case 301:
    case 302:
    case 304:
    case 305:
    case 307:
    case 308:
        dashMomentumFlag = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
            }
        }
        break;

    case 85:
    case 86:
    case 87:
    case 96:
    case 97:
    case 98:
    case 99:
    case 150:
    case 151:
    case 152:
    case 153:
    case 154:
    case 155:
    case 156:
    case 157:
    case 158:
    case 163:
    case 164:
    case 165:
    case 166:
    case 167:
    case 168:
    case 169:
    case 170:
    case 171:
    case 178:
    case 200:
    case 201:
    case 202:
    case 203:
    case 204:
    case 205:
    case 206:
    case 207:
    case 208:
    case 209:
    case 210:
    case 211:
    case 212:
    case 213:
    case 214:
    case 220:
    case 221:
    case 230:
    case 231:
    case 232:
    case 233:
    case 234:
    case 235:
    case 249:
    case 250:
    case 251:
    case 253:
    case 256:
    case 257:
    case 259:
    case 263:
    case 264:
    case 265:
    case 266:
    case 267:
        // This valid state belongs to an untranslated native case group.
        break;

    default:
        // Native out-of-range states use the same 0x75 fallback.
        dashMomentumFlag = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        field000c = field000c + 1;
        if (timing.frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (timing.animationFrameCount <= field000a) {
                field000a = 0;
            }
        }
        break;
    }
}
