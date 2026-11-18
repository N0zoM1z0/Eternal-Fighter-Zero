// Natural-C++ reconstruction of Character19::Slot06.
// State IDs are grouped using the native 310-byte selector table.
// All 310 native state IDs map through 118 selector cases; 193 use shared 0x75.
// The 0x70-0x74 super/KO handlers share the native dispatcher frame.
#include "CharacterViews.h"

static const unsigned char Character19Slot06SelectorCases[0x136] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x75, 0x75, 0x0a, 0x0b, 0x0c, 0x0d,
    0x0e, 0x0f, 0x10, 0x11, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x12, 0x75,
    0x75, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21,
    0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x75, 0x75, 0x75,
    0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x36,
    0x37, 0x38, 0x39, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x75, 0x75,
    0x75, 0x75, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x4c, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,
    0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x75, 0x75, 0x75, 0x75, 0x75, 0x5c, 0x5d, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x64, 0x65, 0x66, 0x75, 0x67, 0x75, 0x75, 0x68,
    0x69, 0x75, 0x6a, 0x75, 0x75, 0x75, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x70, 0x75, 0x75, 0x71, 0x75,
    0x75, 0x72, 0x75, 0x75, 0x73, 0x74,
};

void Character19::Slot06()
{
    if (hitstopFrames > 0) {
        return;
    }
    if ((*opponentSlot)->hitstunFrames > 0) {
        return;
    }

    EffectSpawn spawn;
    unsigned short randomValue;
    unsigned char selectorCase;
    struct FrameTiming {
        __declspec(align(4)) unsigned short animationFrameCount;
        __declspec(align(4)) unsigned short frameDuration;
    } timing;

    timing.frameDuration = patterns[field0008].frames[field000a].duration;
    timing.animationFrameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&spawn);
    selectorCase = 0x75;
    if ((field0008 != 0) && (field0008 <= 0x136)) {
        selectorCase = Character19Slot06SelectorCases[field0008 - 1];
    }

    switch (selectorCase) {
    case 0:
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
    case 1:
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
    case 2:
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
    case 6:
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
                field0008 = 3;
                ResetPose();
            }
        }
        break;

    case 10:
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

    case 11:
        {
#include "Character19Slot06Case0B.inc"
        }
        break;

    case 12:
        {
#include "Character19Slot06Case0C.inc"
        }
        break;

    case 13:
        {
#include "Character19Slot06Case0D.inc"
        }
        break;

    case 14:
        {
#include "Character19Slot06Case0E.inc"
        }
        break;

    case 15:
        {
#include "Character19Slot06Case0F.inc"
        }
        break;

    case 16:
        {
#include "Character19Slot06Case10.inc"
        }
        break;

    case 17:
        {
#include "Character19Slot06Case11.inc"
        }
        break;

    case 18:
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

    case 37:
        Slot06UpdateKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 38:
        Slot06UpdateKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 41:
        Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 42:
        Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 43:
        Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 44:
        Slot06UpdateGroundSkid(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 45:
        Slot06UpdateGroundSkid(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 46:
        Slot06UpdateGroundSkid(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 47:
        Slot06UpdateAirKnockback(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 48:
        Slot06UpdateRepeatedAirKnockback(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 49:
        {
#include "Character19Slot06Case31.inc"
        }
        break;

    case 50:
        {
#include "Character19Slot06Case32.inc"
        }
        break;

    case 51:
        Slot06UpdateAirborneKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount, &spawn, 0x21,
            0.04, 0, 1);
        break;

    case 52:
        Slot06UpdateAirborneKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount, &spawn, 0x21,
            0.06, 1, 0);
        break;

    case 53:
        Slot06UpdateLocalEffectRecovery(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 54:
        Slot06UpdateFaceRecovery(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 55:
        Slot06UpdateDefeatImpact(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 56:
        Slot06UpdateDefeatImpact(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 57:
        Slot06UpdateDefeatWait(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 58:
        Slot06UpdateHorizontalRecovery(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.5, 0);
        break;

    case 59:
        Slot06UpdateHorizontalRecovery(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.8, 0);
        break;

    case 60:
        Slot06UpdateHorizontalRecovery(
            timing.frameDuration, timing.animationFrameCount,
            20, -2.3, 0);
        break;

    case 61:
        Slot06UpdateHorizontalRecovery(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.5, 1);
        break;

    case 62:
        Slot06UpdateHorizontalRecovery(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.8, 1);
        break;

    case 63:
        Slot06UpdateHorizontalRecovery(
            timing.frameDuration, timing.animationFrameCount,
            20, -2.3, 1);
        break;

    case 39:
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

    case 64:
        Slot06UpdateAirborneKnockdown(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            -1.2, -2.6, 0.06,
            15, 0, 0, 0, 0);
        break;

    case 65:
        Slot06UpdateAirborneKnockdown(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            1.0, -2.3, 0.045,
            0, 8, 1, 1, 1);
        break;

    case 66:
        Slot06UpdateAirborneKnockdown(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            -1.0, -2.3, 0.045,
            0, 8, 1, 1, 1);
        break;

    case 67:
        Slot06UpdateAirborneBounce(
            timing.frameDuration, timing.animationFrameCount,
            3, 3, 2.0, -1.0,
            0.02, 0.04, 1, 0);
        break;

    case 68:
        Slot06UpdateAirborneBounce(
            timing.frameDuration, timing.animationFrameCount,
            2, 2, -2.0, -1.0,
            0.035, 0.0, 0, 13);
        break;

    case 69:
        {
#include "Character19Slot06Case45.inc"
        }
        break;

    case 70:
        {
#include "Character19Slot06Case46.inc"
        }
        break;

    case 71:
        Slot06UpdateDefeatImpactEffect(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 72:
        Slot06UpdateKnockbackImpactFinish(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            0);
        break;

    case 73:
        Slot06UpdateKnockbackImpactFinish(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            3);
        break;

    case 74:
        Slot06UpdateAirborneHitstunRestore(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 75:
        {
#include "Character19Slot06Case4B.inc"
        }
        break;

    case 76:
        Slot06UpdateDashRecovery(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 77:
        {
#include "Character19Slot06Case4D.inc"
        }
        break;

    case 78:
        {
#include "Character19Slot06Case4E.inc"
        }
        break;

    case 79:
        {
#include "Character19Slot06Case4F.inc"
        }
        break;

    case 80:
        {
#include "Character19Slot06Case50.inc"
        }
        break;

    case 81:
        {
#include "Character19Slot06Case51.inc"
        }
        break;

    case 82:
        {
#include "Character19Slot06Case52.inc"
        }
        break;

    case 83:
        {
#include "Character19Slot06Case53.inc"
        }
        break;

    case 84:
        {
#include "Character19Slot06Case54.inc"
        }
        break;

    case 85:
        {
#include "Character19Slot06Case55.inc"
        }
        break;

    case 86:
        {
#include "Character19Slot06Case56.inc"
        }
        break;

    case 87:
        Slot06UpdateAerialLaunchLanding(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 88:
        Slot06UpdateDashFollowupCancel(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 89:
        Slot06UpdateAerialGroundSlam(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 90:
        Slot06UpdateAerialKickback(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 91:
        Slot06UpdateGroundImpactRecovery(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 92:
        Slot06UpdateOpponentCaptureImpact(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 93:
        Slot06UpdateOpponentStageCombo(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 94:
        Slot06UpdateTrailDashFinish(
            timing.frameDuration, timing.animationFrameCount,
            2, 5, 21,
            3, 0);
        break;

    case 95:
        Slot06UpdateTrailDashFinish(
            timing.frameDuration, timing.animationFrameCount,
            2, 10, 20,
            3, 0);
        break;

    case 97:
        Slot06UpdateTrailDashFinish(
            timing.frameDuration, timing.animationFrameCount,
            1, 5, 21,
            5, 3);
        break;

    case 98:
        Slot06UpdateTrailDashFinish(
            timing.frameDuration, timing.animationFrameCount,
            2, 10, 20,
            3, 3);
        break;

    case 96:
        Slot06UpdateDashTrailCharge(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 99:
        Slot06UpdateAirborneTrailDash(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 100:
        Slot06UpdateStunEffectRecovery(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 101:
        Slot06UpdateImpactEffectPair(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 102:
        {
#include "Character19Slot06Case66.inc"
        }
        break;

    case 103:
        Slot06UpdateDampedImpactFinish(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 104:
        Slot06UpdateLoopingAerialBounce(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 105:
        {
#include "Character19Slot06Case69.inc"
        }
        break;

    case 106:
        Slot06UpdateFinalFaceTransition(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 107:
        Slot06UpdateLocalEffectFinish(
            timing.frameDuration, timing.animationFrameCount, 400);
        break;

    case 108:
        Slot06UpdateLocalEffectFinish(
            timing.frameDuration, timing.animationFrameCount, 401);
        break;

    case 109:
        Slot06UpdateLocalEffectFinish(
            timing.frameDuration, timing.animationFrameCount, 402);
        break;

    case 110:
        Slot06UpdateFinalEffectPair(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 111:
        Slot06UpdateTrailEffectFinish(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 28:
        {
#include "Character19Slot06Case1C.inc"
        }
        break;

    case 29:
        {
#include "Character19Slot06Case1D.inc"
        }
        break;

    case 30:
        {
#include "Character19Slot06Case1E.inc"
        }
        break;

    case 31:
        {
#include "Character19Slot06Case1F.inc"
        }
        break;

    case 32:
        {
#include "Character19Slot06Case20.inc"
        }
        break;

    case 33:
        {
#include "Character19Slot06Case21.inc"
        }
        break;

    case 34:
        {
#include "Character19Slot06Case22.inc"
        }
        break;

    case 35:
        {
#include "Character19Slot06Case23.inc"
        }
        break;

    case 36:
        {
#include "Character19Slot06Case24.inc"
        }
        break;

    case 40:
        {
#include "Character19Slot06Case28.inc"
        }
        break;

    case 19:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.1, 10.0,
            0);
        break;

    case 20:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.5, 20.0,
            0);
        break;

    case 21:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            20, -1.8, 30.0,
            0);
        break;

    case 22:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.1, 10.0,
            0);
        break;

    case 23:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.5, 20.0,
            0);
        break;

    case 24:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            20, -1.8, 30.0,
            0);
        break;

    case 25:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            10, -1.1, 10.0,
            1);
        break;

    case 26:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            15, -1.5, 20.0,
            1);
        break;

    case 27:
        Slot06UpdateCounterMove(
            timing.frameDuration, timing.animationFrameCount,
            20, -1.8, 30.0,
            1);
        break;

    case 3:
        {
#include "Character19Slot06Case03.inc"
        }
        break;

    case 4:
        {
#include "Character19Slot06Case04.inc"
        }
        break;

    case 5:
        {
#include "Character19Slot06Case05.inc"
        }
        break;

    case 8:
        {
#include "Character19Slot06Case08.inc"
        }
        break;

    case 9:
        {
#include "Character19Slot06Case09.inc"
        }
        break;

    case 112:
        {
#include "Character19Slot06Case70.inc"
        }
        break;

    case 113:
        {
#include "Character19Slot06Case71.inc"
        }
        break;

    case 114:
        {
#include "Character19Slot06Case72.inc"
        }
        break;

    case 115:
        {
#include "Character19Slot06Case73.inc"
        }
        break;

    case 116:
        {
#include "Character19Slot06Case74.inc"
        }
        break;

    case 117:
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
