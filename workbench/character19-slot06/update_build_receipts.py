"""Rebuild only the two Slot06 workbench objects and refresh their local receipts."""
import ast
import csv
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from native_build import compile_source
from coff import object_function

workbench = ROOT / "workbench/character19-slot06"
build_dir = ROOT / "build/character19-slot06"
flags = [
    "/Od", "/G6", "/MT", "/Gy", "/W3",
    "/I" + str(workbench),
    "/I" + str(ROOT / "src"),
]

helper_source = workbench / "Character19Slot06Cases.cpp"
helper_object = build_dir / "Character19Slot06Cases.obj"
helper_receipt = compile_source(
    helper_source, helper_object, flags,
    ROOT / ".analysis/build/Character19Slot06Cases.log"
)
helper_symbols_text = subprocess.check_output(
    ["objdump", "-t", str(helper_object)], text=True
)
helper_symbols = sorted(set(re.findall(
    r"\?Slot06[A-Za-z0-9_]+@Character19@@[^\s]+",
    helper_symbols_text
)))
helper_members = {}
for symbol in helper_symbols:
    try:
        body, relocations = object_function(helper_object, symbol)
    except Exception:
        continue
    helper_members[symbol] = {
        "candidate_size": len(body),
        "relocations": len(relocations),
    }
assert "?Slot06UpdateGroundRecovery@Character19@@QAEXGGH@Z" in helper_members
assert "?Slot06UpdateGroundSkid@Character19@@QAEXGGH@Z" in helper_members
assert any(symbol.startswith("?Slot06UpdateAirKnockback@Character19@@") for symbol in helper_members)
assert "?Slot06UpdateRepeatedAirKnockback@Character19@@QAEXGG@Z" in helper_members
assert any(symbol.startswith("?Slot06UpdateAirborneRebound@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAirborneKnockbackLanding@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateLocalEffectRecovery@Character19@@") for symbol in helper_members)
assert "?Slot06UpdateFaceRecovery@Character19@@QAEXGG@Z" in helper_members
assert any(symbol.startswith("?Slot06UpdateDefeatImpact@Character19@@") for symbol in helper_members)
assert "?Slot06UpdateDefeatWait@Character19@@QAEXGG@Z" in helper_members
assert any(symbol.startswith("?Slot06UpdateHorizontalRecovery@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAirborneKnockdown@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAirborneBounce@Character19@@") for symbol in helper_members)

main_source = workbench / "Character19Slot06.cpp"
main_object = build_dir / "Character19Slot06.obj"
main_receipt = compile_source(
    main_source, main_object, flags,
    ROOT / ".analysis/build/Character19Slot06.log"
)
main_body, main_relocations = object_function(
    main_object, "?Slot06@Character19@@UAEXXZ"
)

renderer = (workbench / "render_partial_slot06.py").read_text()
match = re.search(r"^implemented\s*=\s*(\{[^\n]+\})", renderer, re.M)
assert match
implemented_cases = ast.literal_eval(match.group(1))
case_rows = list(csv.DictReader((workbench / "case-map.csv").open()))
states_by_case = {
    int(row["case_index"], 16): [
        int(value) for value in row["state_ids"].split(";") if value
    ]
    for row in case_rows
}
implemented_states = {
    state
    for case in implemented_cases
    for state in states_by_case.get(case, [])
}
assert len(implemented_states) == 267

helper_record = {
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
    "source_sha256": helper_receipt["source_sha256"],
    "object": "build/character19-slot06/Character19Slot06Cases.obj",
    "object_sha256": helper_receipt["object_sha256"],
    "compiler_flags": flags,
    "handlers": helper_members,
    "status": "semantic-workbench-only-not-exact",
}
(workbench / "case-handlers-build.json").write_text(
    json.dumps(helper_record, indent=2) + "\n"
)

dispatcher_record = {
    "source": "workbench/character19-slot06/Character19Slot06.cpp",
    "source_sha256": main_receipt["source_sha256"],
    "object": "build/character19-slot06/Character19Slot06.obj",
    "object_sha256": main_receipt["object_sha256"],
    "symbol": "?Slot06@Character19@@UAEXXZ",
    "symbol_size": len(main_body),
    "relocation_count": len(main_relocations),
    "implemented_state_ids": len(implemented_states),
    "unimplemented_state_ids": 310 - len(implemented_states),
    "status": "partial-semantic-workbench-not-exact",
}
slot06_path = workbench / "slot06-build.json"
slot06 = json.loads(slot06_path.read_text())
slot06["partial_candidate"].update(dispatcher_record)
slot06["partial_candidate"].pop("source", None)
slot06["partial_candidate"].pop("object", None)
slot06_path.write_text(json.dumps(slot06, indent=2) + "\n")

# Refresh dispatcher identity in all accumulated subfamily records.
for filename in (
    "counter-movement-build.json",
    "knockback-fall-build.json",
    "knockback-landing-build.json",
    "ground-recovery-build.json",
    "case27-build.json",
):
    path = workbench / filename
    data = json.loads(path.read_text())
    data.setdefault("dispatcher", {}).update({
        "source_sha256": main_receipt["source_sha256"],
        "object_sha256": main_receipt["object_sha256"],
        "symbol_size": len(main_body),
        "relocations": len(main_relocations),
        "implemented_state_ids": len(implemented_states),
        "unimplemented_state_ids": 310 - len(implemented_states),
    })
    if filename == "case27-build.json":
        data["candidate"].update({
            "source_sha256": main_receipt["source_sha256"],
            "object_sha256": main_receipt["object_sha256"],
            "symbol_size": len(main_body),
            "relocations": len(main_relocations),
        })
    path.write_text(json.dumps(data, indent=2) + "\n")

ground_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateGroundRecovery@")
)
skid_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateGroundSkid@")
)
(workbench / "ground-recovery-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x29": {"bytes": 341, "state_id": 72, "completion_state": "inputY==1 ? 3 : 7"},
        "0x2A": {"bytes": 341, "state_id": 73, "completion_state": "inputY==1 ? 3 : 7"},
        "0x2B": {"bytes": 317, "state_id": 74, "completion_state": "3"},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": ground_helper,
        **helper_members[ground_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

air_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirKnockback@")
)
(workbench / "air-knockback-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x2F",
        "entry": "0x0066D7AC",
        "bytes": 485,
        "state_id": 81,
        "local_effect_type": 499,
        "landing_states": [0x61, 0x62],
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": air_helper,
        **helper_members[air_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

repeated_helper = "?Slot06UpdateRepeatedAirKnockback@Character19@@QAEXGG@Z"
(workbench / "repeated-air-knockback-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x30",
        "entry": "0x0066D991",
        "bytes": 546,
        "state_id": 82,
        "sound_request": 0x1e,
        "repeat_limit": 8,
        "landing_states": [0x61, 0x62],
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": repeated_helper,
        **helper_members[repeated_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

rebound_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneRebound@")
)
(workbench / "airborne-rebound-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x31": {"entry": "0x0066DBB3", "bytes": 581, "state_id": 83},
        "0x32": {"entry": "0x0066DDF8", "bytes": 581, "state_id": 84},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": rebound_helper,
        **helper_members[rebound_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

landing_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneKnockbackLanding@")
)
(workbench / "airborne-knockback-landing-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x33": {"entry": "0x0066E03D", "bytes": 467, "state_id": 85, "acceleration": 0.04},
        "0x34": {"entry": "0x0066E210", "bytes": 482, "state_id": 86, "acceleration": 0.06},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": landing_helper,
        **helper_members[landing_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

landing_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneKnockbackLanding@")
)
(workbench / "airborne-knockback-landing-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x33": {"entry": "0x0066E03D", "bytes": 467, "state_id": 85, "acceleration": 0.04},
        "0x34": {"entry": "0x0066E210", "bytes": 482, "state_id": 86, "acceleration": 0.06},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": landing_helper,
        **helper_members[landing_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

local_effect_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateLocalEffectRecovery@")
)
face_helper = "?Slot06UpdateFaceRecovery@Character19@@QAEXGG@Z"
defeat_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDefeatImpact@")
)
(workbench / "final-transition-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x35": {"entry": "0x0066E3F2", "bytes": 179, "state_id": 87, "effect_type": 0x1ef},
        "0x36": {"entry": "0x0066E4A5", "bytes": 149, "state_id": 96},
        "0x37": {"entry": "0x0066E53A", "bytes": 248, "state_id": 97, "end_state": 99},
    },
    "candidates": {
        local_effect_helper: helper_members[local_effect_helper],
        face_helper: helper_members[face_helper],
        defeat_helper: helper_members[defeat_helper],
    },
    "source_sha256": helper_receipt["source_sha256"],
    "object_sha256": helper_receipt["object_sha256"],
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
    "status": "semantic-workbench-only-not-exact",
}, indent=2) + "\n")

local_effect_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateLocalEffectRecovery@")
)
face_helper = "?Slot06UpdateFaceRecovery@Character19@@QAEXGG@Z"
defeat_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDefeatImpact@")
)
(workbench / "final-transition-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x35": {"entry": "0x0066E3F2", "bytes": 179, "state_id": 87, "effect_type": 0x1ef},
        "0x36": {"entry": "0x0066E4A5", "bytes": 149, "state_id": 96},
        "0x37": {"entry": "0x0066E53A", "bytes": 248, "state_id": 97, "end_state": 99},
    },
    "candidates": {
        local_effect_helper: helper_members[local_effect_helper],
        face_helper: helper_members[face_helper],
        defeat_helper: helper_members[defeat_helper],
    },
    "source_sha256": helper_receipt["source_sha256"],
    "object_sha256": helper_receipt["object_sha256"],
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
    "status": "semantic-workbench-only-not-exact",
}, indent=2) + "\n")

defeat_wait_helper = "?Slot06UpdateDefeatWait@Character19@@QAEXGG@Z"
(workbench / "final-defeat-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x38": {"entry": "0x0066E632", "bytes": 248, "state_id": 98, "same_body_as": "0x37"},
        "0x39": {"entry": "0x0066E72A", "bytes": 186, "state_id": 99, "transition_state": 0x60, "health_timeout_frames": 60},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": defeat_wait_helper,
        **helper_members[defeat_wait_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

horizontal_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateHorizontalRecovery@")
)
(workbench / "horizontal-recovery-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x3A": {"entry": "0x0066E7E4", "bytes": 380, "state_id": 150, "meter_gain": 10, "initial_velocity_x": -1.5, "force_standing": False},
        "0x3B": {"entry": "0x0066E960", "bytes": 380, "state_id": 151, "meter_gain": 15, "initial_velocity_x": -1.8, "force_standing": False},
        "0x3C": {"entry": "0x0066EADC", "bytes": 380, "state_id": 152, "meter_gain": 20, "initial_velocity_x": -2.3, "force_standing": False},
        "0x3D": {"entry": "0x0066EC58", "bytes": 356, "state_id": 153, "meter_gain": 10, "initial_velocity_x": -1.5, "force_standing": True},
        "0x3E": {"entry": "0x0066EDBC", "bytes": 356, "state_id": 154, "meter_gain": 15, "initial_velocity_x": -1.8, "force_standing": True},
        "0x3F": {"entry": "0x0066EF20", "bytes": 356, "state_id": 155, "meter_gain": 20, "initial_velocity_x": -2.3, "force_standing": True},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": horizontal_helper,
        **helper_members[horizontal_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

airborne_knockdown_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneKnockdown@")
)
(workbench / "knockback-followup-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x40": {"entry": "0x0066F084", "bytes": 272, "state_id": 156, "initial_vx": -1.2, "initial_vy": -2.6, "gravity": 0.06, "meter_gain": 15, "effect_type": 0},
        "0x41": {"entry": "0x0066F194", "bytes": 342, "state_id": 157, "initial_vx": 1.0, "initial_vy": -2.3, "gravity": 0.045, "meter_gain": 0, "effect_type": 8},
        "0x42": {"entry": "0x0066F2EA", "bytes": 342, "state_id": 158, "initial_vx": -1.0, "initial_vy": -2.3, "gravity": 0.045, "meter_gain": 0, "effect_type": 8},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": airborne_knockdown_helper,
        **helper_members[airborne_knockdown_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

airborne_bounce_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneBounce@")
)
(workbench / "airborne-bounce-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x43": {"entry": "0x0066F440", "bytes": 412, "state_id": 163, "trail_spacing": 3, "launch_frame": 3, "launch_vx": 2.0, "launch_vy": -1.0, "gravity": 0.02, "late_deceleration": 0.04},
        "0x44": {"entry": "0x0066F5DC", "bytes": 317, "state_id": 164, "trail_spacing": 2, "launch_frame": 2, "launch_vx": -2.0, "launch_vy": -1.0, "gravity": 0.035, "landing_state": 13},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": airborne_bounce_helper,
        **helper_members[airborne_bounce_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

print({
    "helper_source_sha256": helper_receipt["source_sha256"],
    "helper_object_sha256": helper_receipt["object_sha256"],
    "helper_members": len(helper_members),
    "ground_recovery_member": helper_members[ground_helper],
    "dispatcher_source_sha256": main_receipt["source_sha256"],
    "dispatcher_object_sha256": main_receipt["object_sha256"],
    "dispatcher_bytes": len(main_body),
    "dispatcher_relocations": len(main_relocations),
    "implemented_state_ids": len(implemented_states),
    "unimplemented_state_ids": 310 - len(implemented_states),
})


(workbench / "ground-skid-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x2C": {"bytes": 509, "state_id": 75, "completion_state": "inputY==1 ? 3 : 7"},
        "0x2D": {"bytes": 509, "state_id": 76, "completion_state": "inputY==1 ? 3 : 7"},
        "0x2E": {"bytes": 485, "state_id": 77, "completion_state": "3"},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": skid_helper,
        **helper_members[skid_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")
