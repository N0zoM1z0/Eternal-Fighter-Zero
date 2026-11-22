import csv
import re
from pathlib import Path

root = Path(__file__).resolve().parents[2]
rows = list(csv.DictReader((root / "workbench/character19-slot06/case-map.csv").open()))
states_by_case = {
    int(row["case_index"], 16): [
        int(value) for value in row["state_ids"].split(";") if value
    ]
    for row in rows
}
implemented = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75}
mapped = {
    state
    for case, states in states_by_case.items()
    if case in implemented
    for state in states
}
unimplemented = sorted(set(range(1, 0x137)) - mapped)

# The native owner performs two-level dispatch: a 310-byte state->selector
# table followed by a 118-entry switch. Rebuild the exact byte table from the
# reviewed native case map rather than expanding 310 state labels in C++.
selector_by_state = [None] * 0x136
for selector_case, state_ids in states_by_case.items():
    for state_id in state_ids:
        assert 1 <= state_id <= 0x136
        assert selector_by_state[state_id - 1] is None
        selector_by_state[state_id - 1] = selector_case
assert all(value is not None for value in selector_by_state)
assert not unimplemented

lines = [
    "// Natural-C++ reconstruction of Character19::Slot06.",
    "// State IDs are grouped using the native 310-byte selector table.",
    "// All 310 native state IDs map through 118 selector cases; 193 use shared 0x75.",
    "// The 0x70-0x74 super/KO handlers share the native dispatcher frame.",
    '#include "CharacterViews.h"',
    "",
    "static const unsigned char Character19Slot06SelectorCases[0x136] = {",
]
for offset in range(0, len(selector_by_state), 16):
    values = selector_by_state[offset:offset + 16]
    lines.append("    " + ", ".join(f"0x{value:02x}" for value in values) + ",")
lines += [
    "};",
    "",
    "void Character19::Slot06()",
    "{",
    "    if (hitstopFrames > 0) {",
    "        return;",
    "    }",
    "    if ((*opponentSlot)->hitstunFrames > 0) {",
    "        return;",
    "    }",
    "",
    "    EffectSpawn spawn;",
    "    int stateIndex;",
    "    unsigned char selectorCase;",
    "    struct FrameTiming {",
    "        __declspec(align(4)) unsigned short animationFrameCount;",
    "        __declspec(align(4)) unsigned short frameDuration;",
    "    } timing;",
    "",
    "    timing.frameDuration = patterns[field0008].frames[field000a].duration;",
    "    timing.animationFrameCount = patterns[field0008].count;",
    "    ResetLocalEffectSpawn(&spawn);",
    "    selectorCase = 0x75;",
    "    stateIndex = (int)field0008;",
    "    if (stateIndex != 0) {",
    "        --stateIndex;",
    "        if ((unsigned int)stateIndex <= 0x135) {",
    "            selectorCase = Character19Slot06SelectorCases[stateIndex];",
    "        }",
    "    }",
    "",
    "    switch (selectorCase) {",
]

def labels(case):
    return [f"    case {case}:"]

def advance_frame():
    return [
        "        ++field000c;",
        "        if (field000c >= timing.frameDuration) {",
        "            field000c = 0;",
        "            ++field000a;",
        "            if (field000a >= timing.animationFrameCount) {",
        "                field000a = 0;",
        "            }",
        "        }",
        "        break;",
    ]

lines += labels(0)
lines += [
    "        dashMomentumFlag = 0;",
    "        velocityX = 0.8;",
    "        velocityY = 0.0;",
]
lines += advance_frame()

lines += labels(1)
lines += [
    "        dashMomentumFlag = 0;",
    "        velocityX = -0.8;",
    "        velocityY = 0.0;",
]
lines += advance_frame()

lines += labels(2)
lines += [
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
    "        dashMomentumFlag = 0;",
    "        FaceOpponent();",
]
lines += advance_frame()

lines += labels(6)
lines += [
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
    "        dashMomentumFlag = 0;",
    "        FaceOpponent();",
    "        field000c = field000c + 1;",
    "        if (timing.frameDuration <= field000c) {",
    "            field000c = 0;",
    "            field000a = field000a + 1;",
    "            if (timing.animationFrameCount <= field000a) {",
    "                field000a = 0;",
    "                field0008 = 0;",
    "                ResetPose();",
    "            }",
    "        }",
    "        break;",
    "",
]

lines += labels(7)
lines += [
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
    "        dashMomentumFlag = 0;",
    "        FaceOpponent();",
    "        field000c = field000c + 1;",
    "        if (timing.frameDuration <= field000c) {",
    "            field000c = 0;",
    "            field000a = field000a + 1;",
    "            if (timing.animationFrameCount <= field000a) {",
    "                field000a = 0;",
    "                field0008 = 3;",
    "                ResetPose();",
    "            }",
    "        }",
    "        break;",
    "",
]

lines += labels(10)
lines += [
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
    "        dashMomentumFlag = 0;",
    "        FaceOpponent();",
    "        field000c = field000c + 1;",
    "        if (timing.frameDuration <= field000c) {",
    "            field000c = 0;",
    "            field000a = field000a + 1;",
    "            if (timing.animationFrameCount <= field000a) {",
    "                field000a = 0;",
    "                field0008 = 7;",
    "                if (inputY == 1) {",
    "                    field0008 = 3;",
    "                }",
    "                ResetPose();",
    "            }",
    "        }",
    "        break;",
    "",
]

for case, config in [
    (0x0b, (3, 0.0, -3.5, 2, 0)),
    (0x0c, (3, 1.5, -2.5, 2, 0)),
    (0x0d, (2, -1.5, -2.5, 1, 0)),
    (0x0e, (3, 2.0, -0.5, 2, 1)),
    (0x0f, (3, 1.5, -0.5, 2, 0)),
    (0x10, (2, -2.0, -0.5, 1, 1)),
    (0x11, (2, -1.5, -0.5, 1, 0)),
]:
    launch_frame, velocity_x, velocity_y, acceleration_frame, fixed_acceleration = config
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x12)
lines += [
    "        if ((field000a == 0) && (field000c == 0)) {",
    "            velocityX = 0.0;",
    "            gravity = 0.035;",
    "        }",
    "        velocityY = velocityY + gravity;",
    "        if (((positionY + velocityY) > 0.0) && (field000a < 2)) {",
    "            field000c = 0;",
    "            field000a = 2;",
    "            reinterpret_cast<unsigned char *>(&soundSlots[49])[1] = 7;",
    "            positionY = 0.0;",
    "            velocityY = 0.0;",
    "            gravity = 0.0;",
    "            velocityX = 0.0;",
    "        }",
    "        field000c = field000c + 1;",
    "        if (timing.frameDuration <= field000c) {",
    "            field000c = 0;",
    "            field000a = field000a + 1;",
    "            if (field000a == 2) {",
    "                field000a = field000a - 2;",
    "            }",
    "            if (timing.animationFrameCount <= field000a) {",
    "                field000a = field000a - 1;",
    "            }",
    "        }",
    "        break;",
    "",
]

for case in (0x25, 0x26):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

for case in (0x29, 0x2a, 0x2b):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

for case in (0x2c, 0x2d, 0x2e):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x2f)
lines += [
    "        {",
    '#include "Character19Slot06Case2F.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x30)
lines += [
    "        {",
    '#include "Character19Slot06Case30.inc"',
    "        }",
    "        break;",
    "",
]

for case in (0x31, 0x32):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

for case in (0x33, 0x34):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

for case in (0x35, 0x36):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
]
for case in (0x37, 0x38):
    lines += labels(case)
    lines += [
        "        {",
        '#include "Character19Slot06Case37.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x39)
lines += [
    "        Slot06UpdateDefeatWait(",
    "            timing.frameDuration, timing.animationFrameCount);",
    "        break;",
    "",
]

for case, meter_gain, initial_velocity, force_standing in [
    (0x3a, 10, -1.5, 0),
    (0x3b, 15, -1.8, 0),
    (0x3c, 20, -2.3, 0),
    (0x3d, 10, -1.5, 1),
    (0x3e, 15, -1.8, 1),
    (0x3f, 20, -2.3, 1),
]:
    lines += labels(case)
    lines += [
        "        if ((field000a == 0) && (field000c == 0)) {",
        "            dashMomentumFlag = 0;",
        f"            meter = meter + {meter_gain};",
        f"            velocityX = {initial_velocity};",
        "            velocityY = 0.0;",
        "            positionY = 0.0;",
        "        }",
        "        velocityY = 0.0;",
        "        velocityX = velocityX + 0.06;",
        "        if (velocityX > 0.0) {",
        "            velocityX = 0.0;",
        "        }",
        "        if ((positionX - 20.0 <= 0.0) || (639.0 <= positionX + 20.0)) {",
        "            outgoingPushbackVelocityX = velocityX;",
        "        } else {",
        "            outgoingPushbackVelocityX = 0.0;",
        "        }",
        "        ++field000c;",
        "        if (field000c >= timing.frameDuration) {",
        "            field000c = 0;",
        "            ++field000a;",
        "            if (field000a == timing.animationFrameCount) {",
        "                FaceOpponent();",
        "            }",
        "            if (field000a >= timing.animationFrameCount) {",
    ]
    if force_standing:
        lines += ["                field0008 = 3;"]
    else:
        lines += [
            "                field0008 = 0;",
            "                if (inputY == 1) {",
            "                    field0008 = 3;",
            "                }",
        ]
    lines += [
        "                ResetPose();",
        "            }",
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x27)
lines += [
    "        if (field0120 != 0) {",
    "            field0118 = field0118 - 0.8;",
    "        }",
    "        if ((field000a == 0) && (field000c == 0) && (field3138 == 0)) {",
    "            meter = meter + 30;",
    "            field3138 = field3138 + 1;",
    "            airActionLockFrames = airActionLockFrames + 0x78;",
    "            velocityX = 0.5;",
    "            velocityY = -2.5;",
    "            gravity = 0.025;",
    "            pendingContextSoundSlot = 0x1f;",
    "            spawn.type = 0;",
    "            spawn.x = (double)(int)positionX;",
    "            spawn.y = (double)(int)positionY;",
    "            spawn.group = 2;",
    "            spawn.layer = 1;",
    "            contextOwner->EmitEffect(&spawn);",
    "        }",
    "        velocityY = velocityY + gravity;",
    "        field000c = field000c + 1;",
    "        if (timing.frameDuration <= field000c) {",
    "            field000c = 0;",
    "            field000a = field000a + 1;",
    "            if (timing.animationFrameCount <= field000a) {",
    "                field000a = 0;",
    "            }",
    "        }",
    "        if (((positionY + velocityY) >= 0.0) && (field000a > 1)) {",
    "            positionY = 0.0;",
    "            if (knockdownOnLanding == 0) {",
    "                field0008 = 0x62;",
    "            } else {",
    "                field0008 = 0x61;",
    "            }",
    "            ResetPose();",
    "        }",
    "        break;",
    "",
]

for case, horizontal_velocity in (
    (0x40, -1.2),
    (0x41, 1.0),
    (0x42, -1.0),
):
    lines += labels(case)
    lines += ["        {"]

    if case == 0x40:
        lines += [
            "            if ((field000a == 0) && (field000c == 0)) {",
            "                velocityY = -2.6;",
            "                meter = meter + 15;",
            "                gravity = 0.06;",
            "            }",
            "            velocityX = -1.2;",
            "            velocityY = velocityY + gravity;",
        ]
    else:
        lines += [
            f"            velocityX = {horizontal_velocity};",
            "            gravity = 0.045;",
            "            dashMomentumFlag = 0;",
            "            if ((field000a == 0) && (field000c == 0)) {",
            "                velocityY = -2.3;",
            "                spawn.type = 8;",
            "                stateIndex = (int)positionX;",
            "                spawn.x = (double)stateIndex;",
            "                stateIndex = (int)positionY;",
            "                spawn.y = (double)stateIndex;",
            "                spawn.group = 2;",
            "                spawn.layer = 0;",
            "                contextOwner->EmitEffect(&spawn);",
            "            } else {",
            "                velocityY = velocityY + gravity;",
            "            }",
        ]

    lines += [
        "            ++field000c;",
        "            if (field000c >= timing.frameDuration) {",
        "                field000c = 0;",
        "                ++field000a;",
        "                if (field000a >= timing.animationFrameCount) {",
        "                    field0008 = 9;",
        "                    ResetPose();",
        "                }",
        "            }",
        "            if ((positionY + velocityY) >= 0.0) {",
        "                positionY = 0.0;",
        "                pendingContextSoundSlot = 9;",
        "                FaceOpponent();",
        "                field0008 = 0x0d;",
        "                ResetPose();",
        "            }",
        "        }",
        "        break;",
        "",
    ]

for case in (0x43, 0x44):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

for case in (0x45, 0x46):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x47)
lines += [
    "        {",
    '#include "Character19Slot06Case47.inc"',
    "        }",
    "        break;",
    "",
]

for case in (0x48, 0x49):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x4a)
lines += [
    "        {",
    '#include "Character19Slot06Case4A.inc"',
    "        }",
    "        break;",
    "",
]
lines += labels(0x4b)
lines += [
    "        {",
    '#include "Character19Slot06Case4B.inc"',
    "        }",
    "        break;",
    "",
]
lines += labels(0x4c)
lines += [
    "        {",
    '#include "Character19Slot06Case4C.inc"',
    "        }",
    "",
]
for case in (0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x53)
lines += [
    "        {",
    '#include "Character19Slot06Case53.inc"',
    "        }",
    "        break;",
    "",
]
for case in (0x54, 0x55, 0x56):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x57)
lines += [
    "        {",
    '#include "Character19Slot06Case57.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x58)
lines += [
    "        {",
    '#include "Character19Slot06Case58.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x59)
lines += [
    "        {",
    '#include "Character19Slot06Case59.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x5a)
lines += [
    "        Slot06UpdateAerialKickback(",
    "            timing.frameDuration, timing.animationFrameCount);",
    "        break;",
    "",
]

lines += labels(0x5b)
lines += [
    "        {",
    '#include "Character19Slot06Case5B.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x5c)
lines += [
    "        {",
    '#include "Character19Slot06Case5C.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x5d)
lines += [
    "        {",
    '#include "Character19Slot06Case5D.inc"',
    "        }",
    "        break;",
    "",
]

for case in (0x5e, 0x5f, 0x61, 0x62):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x60)
lines += [
    "        {",
    '#include "Character19Slot06Case60.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x63)
lines += [
    "        {",
    '#include "Character19Slot06Case63.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x64)
lines += [
    "        {",
    '#include "Character19Slot06Case64.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x65)
lines += [
    "        {",
    '#include "Character19Slot06Case65.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x66)
lines += [
    "        {",
    '#include "Character19Slot06Case66.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x67)
lines += [
    "        {",
    '#include "Character19Slot06Case67.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x68)
lines += [
    "        {",
    '#include "Character19Slot06Case68.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x69)
lines += [
    "        {",
    '#include "Character19Slot06Case69.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x6a)
lines += [
    "        Slot06UpdateFinalFaceTransition(",
    "            timing.frameDuration, timing.animationFrameCount);",
    "        break;",
    "",
]

for case in (0x6b, 0x6c, 0x6d):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

lines += labels(0x6e)
lines += [
    "        {",
    '#include "Character19Slot06Case6E.inc"',
    "        }",
    "        break;",
    "",
]

lines += labels(0x6f)
lines += [
    "        {",
    '#include "Character19Slot06Case6F.inc"',
    "        }",
    "        break;",
    "",
]

for case in (0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x28):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

for case in range(0x13, 0x1c):
    lines += labels(case)
    lines += [
        "        {",
        f'#include "Character19Slot06Case{case:02X}.inc"',
        "        }",
        "        break;",
        "",
    ]

for case, method in [
    (3, "Slot06Case03"),
    (4, "Slot06Case04"),
    (5, "Slot06Case05"),
    (8, "Slot06Case08"),
    (9, "Slot06Case09"),
    (0x70, "Slot06Case70"),
    (0x71, "Slot06Case71"),
    (0x72, "Slot06Case72"),
    (0x73, "Slot06Case73"),
    (0x74, "Slot06Case74"),
]:
    lines += labels(case)
    if case in (3, 4, 5, 8, 9, 0x70, 0x71, 0x72, 0x73, 0x74):
        lines += ["        {"]
        if case == 0x70:
            lines += ["            unsigned short randomValue;"]
        lines += [
            f'#include "Character19Slot06Case{case:02X}.inc"',
            "        }",
            "        break;",
            "",
        ]
    else:
        lines += [f"        {method}();", "        break;", ""]

lines += labels(0x75)
lines += [
    "        dashMomentumFlag = 0;",
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
]
lines += advance_frame()

lines += [
    "",
    "    default:",
    "        // Native out-of-range states use the same 0x75 fallback.",
    "        dashMomentumFlag = 0;",
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
    "        ++field000c;",
    "        if (field000c >= timing.frameDuration) {",
    "            field000c = 0;",
    "            ++field000a;",
    "            if (field000a >= timing.animationFrameCount) {",
    "                field000a = 0;",
    "            }",
    "        }",
    "        break;",
    "    }",
    "}",
]
# Keep one explicit C++ alias for the incoming Character19 pointer. The
# original Slot06 body reloads this from one stable stack slot throughout the
# large switch; using a named pointer gives VC7.1 the same short-displacement
# access shape without assembly or byte-level adjustments.
self_members = """
field0008 field000a field000c patterns positionX positionY velocityX velocityY horizontalDeceleration gravity facing field0060
opponentSlot contextOwner videoOwner inputOwner audioOwner player characterId paletteIndex resourceName cpuControlled field00a8 field00ac velocityXCorrection outgoingPushbackVelocityX knockbackVelocityX knockbackVelocityY outgoingPushbackActive field00dc field00de comboDisplayHitCount comboDamageScaleDisplay comboDamage comboDisplayTimer health damageTrailHealth animatedHealth field0118 field0120 airActionLockFrames airActionDisabled knockdownOnLanding throwInvulnerabilityFrames airActionGauge field0138 field013a hitInvulnerabilityFrames field013e koDelayFrames field0144 meter hitstopFrames hitstunFrames guardInputFrames guardInputLatched field0154 dashMomentumFlag airDashCount airActionCount field015c field0160 sequences attackCollisionResult remainingHitCount attackWasGuarded comboHitCount comboDamageScale field0180 inputX inputY buttonPulse buttonHeld cpuMoveRightFrames cpuMoveLeftFrames actionBufferedInput stateGroupCBufferedInput stateGroupCBufferFrames history inputHistoryWriteIndex recognizedCommand soundSlots pendingCharacterSoundSlot pendingContextSoundSlot effectWrite effectRead effectOwner effectActive effects field2ad0 field2af8 trail tint30b8 field30bc field30c0 field30c4 field30c8 field30cc field30d0 field30d4 field30d8 field30dc field30e0 field30e4 field30e8 field30ec field30ee field30f0 commandCount commands field3110 field3114 statistics
field3138 field313c field3140 field3144 field3148 field314c field3150 field3154 field3254 field3354 unknown_3454
EmitLocalEffect RemoveLocalEffect InitializeState UpdateLocomotionState
Slot06OpponentWithinKnockbackRange Slot06UpdateDefeatWait Slot06UpdateAerialKickback Slot06UpdateFinalFaceTransition
ResetPose ResetFrame ResetLocalEffectSpawn RandomRange SetTint SetCharacterTint SetVerticalShake SetHorizontalShake SetHorizontalOffset FaceOpponent FacePosition StartTrail
""".split()
self_member_pattern = re.compile(
    r"(?<![\w>.])(?<!:)(" +
    "|".join(sorted(map(re.escape, self_members), key=len, reverse=True)) +
    r")\b"
)
def alias_self_members(text):
    return self_member_pattern.sub(lambda match: "self->" + match.group(1), text)

main_source = alias_self_members("\n".join(lines) + "\n")
signature = "void Character19::Slot06()\n{"
assert main_source.count(signature) == 1
main_source = main_source.replace(
    signature, signature + "\n    Character19 *self = this;", 1
)
(root / "workbench/character19-slot06/Character19Slot06.cpp").write_text(main_source)

# The case fragments are included inside Slot06's lexical scope, so apply the
# same idempotent member qualification to each natural-C++ fragment.
for fragment in (root / "workbench/character19-slot06").glob("Character19Slot06Case*.inc"):
    fragment.write_text(alias_self_members(fragment.read_text()))
print({
    "implemented_selector_cases": sorted(implemented),
    "implemented_state_ids": len(mapped),
    "unimplemented_state_ids": len(unimplemented),
    "fallback_state_ids": len(states_by_case[0x75]),
    "output": "workbench/character19-slot06/Character19Slot06.cpp",
})
