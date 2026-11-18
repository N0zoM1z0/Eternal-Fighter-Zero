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
implemented = {0, 1, 2, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75}
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
    "// Only cases 0, 1, 2, 0x70-0x74, and the shared 0x75 fallback",
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
lines += advance_frame()[:-1]

lines += labels(1)
lines += [
    "        dashMomentumFlag = 0;",
    "        velocityX = -0.8;",
    "        velocityY = 0.0;",
]
lines += advance_frame()[:-1]

lines += labels(2)
lines += [
    "        velocityX = 0.0;",
    "        velocityY = 0.0;",
    "        dashMomentumFlag = 0;",
    "        FaceOpponent();",
]
lines += advance_frame()[:-1]

for case, method in [
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
lines += advance_frame()[:-1]

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
