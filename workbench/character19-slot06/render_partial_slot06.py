import csv
from pathlib import Path

root = Path(__file__).resolve().parents[2]
rows = list(csv.DictReader((root / "workbench/character19-slot06/case-map.csv").open()))
states_by_case = {
    int(row["case_index"], 16): [
        int(value) for value in row["state_ids"].split(";") if value
    ]
    for row in rows
}
implemented = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75}
mapped = {
    state
    for case, states in states_by_case.items()
    if case in implemented
    for state in states
}
unimplemented = sorted(set(range(1, 0x137)) - mapped)

lines = [
    "// Partial natural-C++ reconstruction of Character19::Slot06.",
    "// State IDs are grouped using the native 310-byte selector table.",
    "// Cases 0-0x28, 0x70-0x74, and the shared 0x75 fallback are restored.",
    "// are implemented; remaining native handlers are explicitly TODO.",
    '#include "CharacterViews.h"',
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
    "    struct FrameTiming {",
    "        __declspec(align(4)) unsigned short animationFrameCount;",
    "        __declspec(align(4)) unsigned short frameDuration;",
    "    } timing;",
    "",
    "    timing.frameDuration = patterns[field0008].frames[field000a].duration;",
    "    timing.animationFrameCount = patterns[field0008].count;",
    "    ResetLocalEffectSpawn(&spawn);",
    "",
    "    switch (field0008) {",
]

def labels(case):
    return [f"    case {state}:" for state in states_by_case[case]]

def advance_frame():
    return [
        "        field000c = field000c + 1;",
        "        if (timing.frameDuration <= field000c) {",
        "            field000c = 0;",
        "            field000a = field000a + 1;",
        "            if (timing.animationFrameCount <= field000a) {",
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
        "        Slot06UpdateAirMovement(",
        "            timing.frameDuration, timing.animationFrameCount,",
        f"            {launch_frame}, {velocity_x}, {velocity_y},",
        f"            {acceleration_frame}, {fixed_acceleration});",
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

for case, interrupt in [
    (0x25, 1),
    (0x26, 0),
]:
    lines += labels(case)
    lines += [
        "        Slot06UpdateKnockbackLanding(",
        "            timing.frameDuration, timing.animationFrameCount,",
        f"            {interrupt});",
        "        break;",
        "",
    ]

for case, force_standing in [
    (0x29, 0),
    (0x2a, 0),
    (0x2b, 1),
]:
    lines += labels(case)
    lines += [
        "        Slot06UpdateGroundRecovery(",
        "            timing.frameDuration, timing.animationFrameCount,",
        f"            {force_standing});",
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

for case, config in [
    (0x1c, (-2.0, 1, 0.75, 0.032, 0)),
    (0x1d, (-4.0, 1, 0.75, 0.032, 0)),
    (0x1e, (-6.0, 1, 0.75, 0.032, 0)),
    (0x1f, (0.0, 0, 0.75, 0.032, 0)),
    (0x20, (0.0, 0, 0.0, 0.032, 0)),
    (0x21, (-2.0, 1, 0.75, 0.032, 1)),
    (0x22, (-4.0, 1, 0.75, 0.032, 1)),
    (0x23, (0.0, 0, 0.75, 0.032, 1)),
    (0x24, (0.0, 0, 0.0, 0.032, 1)),
    (0x28, (0.0, 0, 0.0, 0.072, 0)),
]:
    lower_velocity, clamp_velocity, velocity_blend, gravity_value, interrupt = config
    lines += labels(case)
    lines += [
        "        Slot06UpdateKnockbackFall(",
        "            timing.frameDuration, timing.animationFrameCount,",
        f"            {lower_velocity}, {clamp_velocity},",
        f"            {velocity_blend}, {gravity_value}, {interrupt});",
        "        break;",
        "",
    ]

for case, config in [
    (0x13, (10, -1.1, 10.0, 0)),
    (0x14, (15, -1.5, 20.0, 0)),
    (0x15, (20, -1.8, 30.0, 0)),
    (0x16, (10, -1.1, 10.0, 0)),
    (0x17, (15, -1.5, 20.0, 0)),
    (0x18, (20, -1.8, 30.0, 0)),
    (0x19, (10, -1.1, 10.0, 1)),
    (0x1a, (15, -1.5, 20.0, 1)),
    (0x1b, (20, -1.8, 30.0, 1)),
]:
    meter_gain, launch_scale, field_decay, force_standing = config
    lines += labels(case)
    lines += [
        "        Slot06UpdateCounterMove(",
        "            timing.frameDuration, timing.animationFrameCount,",
        f"            {meter_gain}, {launch_scale}, {field_decay},",
        f"            {force_standing});",
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
    lines += [f"        {method}();", "        break;", ""]

lines += labels(0x75)
lines += [
    "        dashMomentumFlag = 0;",
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
]
lines += advance_frame()

lines += [""]
for state in unimplemented:
    lines.append(f"    case {state}:")
lines += [
    "        // This valid state belongs to an untranslated native case group.",
    "        break;",
    "",
    "    default:",
    "        // Native out-of-range states use the same 0x75 fallback.",
    "        dashMomentumFlag = 0;",
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
    "        field000c = field000c + 1;",
    "        if (timing.frameDuration <= field000c) {",
    "            field000c = 0;",
    "            field000a = field000a + 1;",
    "            if (timing.animationFrameCount <= field000a) {",
    "                field000a = 0;",
    "            }",
    "        }",
    "        break;",
    "    }",
    "}",
]
(root / "workbench/character19-slot06/Character19Slot06.cpp").write_text(
    "\n".join(lines) + "\n"
)
print({
    "implemented_selector_cases": sorted(implemented),
    "implemented_state_ids": len(mapped),
    "unimplemented_state_ids": len(unimplemented),
    "fallback_state_ids": len(states_by_case[0x75]),
    "output": "workbench/character19-slot06/Character19Slot06.cpp",
})
