"""Rebuild only the two Slot06 workbench objects and refresh their local receipts."""
import ast
import csv
import json
import hashlib
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
assert any(symbol.startswith("?Slot06UpdateDefeatImpactEffect@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateKnockbackImpactFinish@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAirborneHitstunRestore@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateDefeatImpactVelocityRestore@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateDashRecovery@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAirborneDashFollowup@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAerialLaunchLanding@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateDashFollowupCancel@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAerialGroundSlam@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAerialKickback@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateGroundImpactRecovery@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateOpponentCaptureImpact@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateOpponentStageCombo@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateTrailDashFinish@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateDashTrailCharge@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateAirborneTrailDash@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateStunEffectRecovery@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateImpactEffectPair@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateDampedImpactFinish@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateLoopingAerialBounce@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateComboAerialBounce@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateFinalFaceTransition@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateLocalEffectFinish@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateFinalEffectPair@Character19@@") for symbol in helper_members)
assert any(symbol.startswith("?Slot06UpdateTrailEffectFinish@Character19@@") for symbol in helper_members)


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
assert len(implemented_states) == 310

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
    "included_sources": {
        f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc": hashlib.sha256(
            (workbench / f"Character19Slot06Case{case:02X}.inc").read_bytes()
        ).hexdigest()
        for case in (3, 4, 5, 8, 9, 0x45, 0x46, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x66, 0x70, 0x71, 0x72, 0x73, 0x74)
    },
    "status": "partial-semantic-workbench-not-exact",
}
air_path = workbench / "air-movement-build.json"
air = json.loads(air_path.read_text())
air["candidate"].update({
    "source": "workbench/character19-slot06/Character19Slot06.cpp",
    "source_sha256": main_receipt["source_sha256"],
    "object": "build/character19-slot06/Character19Slot06.obj",
    "object_sha256": main_receipt["object_sha256"],
    "members": {},
    "inlined_case_sources": {
        f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc": hashlib.sha256(
            (workbench / f"Character19Slot06Case{case:02X}.inc").read_bytes()
        ).hexdigest()
        for case in (3, 4, 5, 8, 9, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11)
    },
    "status": "semantic-workbench-only-not-exact",
})
air["dispatcher"] = {
    **dispatcher_record,
    "symbol_bytes": len(main_body),
}
air_path.write_text(json.dumps(air, indent=2) + "\n")

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

(workbench / "airborne-followup-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x45": {"entry": "0x0066F719", "bytes": 932, "state_id": 165, "launch_frame": 3, "launch_vx": 2.0, "launch_vy": -0.5, "gravity": 0.045, "vertical_acceleration": 0.01},
        "0x46": {"entry": "0x0066FABD", "bytes": 931, "state_id": 166, "launch_frame": 2, "launch_vx": -2.0, "launch_vy": -0.5, "gravity": 0.045, "vertical_acceleration": 0.01},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06.cpp",
        "source_sha256": main_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06.obj",
        "object_sha256": main_receipt["object_sha256"],
        "inlined_case_sources": {
            f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc": hashlib.sha256(
                (workbench / f"Character19Slot06Case{case:02X}.inc").read_bytes()
            ).hexdigest()
            for case in (0x45, 0x46)
        },
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

defeat_impact_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDefeatImpactEffect@")
)
(workbench / "defeat-impact-effect-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x47",
        "entry": "0x0066FE60",
        "bytes": 488,
        "state_id": 167,
        "tint": [0xb0, 3],
        "context_effect_types": [1, 4],
        "context_sound": 0x12,
        "combo_damage_scale_multiplier": 5.0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": defeat_impact_helper,
        **helper_members[defeat_impact_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

impact_finish_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateKnockbackImpactFinish@")
)
(workbench / "knockback-impact-finish-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x48": {"entry": "0x00670048", "bytes": 330, "state_id": 168, "effect_type": 8, "group": 2, "layer": 1, "completion_state": 0},
        "0x49": {"entry": "0x00670192", "bytes": 330, "state_id": 169, "effect_type": 8, "group": 2, "layer": 1, "completion_state": 3},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": impact_finish_helper,
        **helper_members[impact_finish_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")



hitstun_restore_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneHitstunRestore@")
)
(workbench / "airborne-hitstun-restore-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x4A",
        "entry": "0x006702DC",
        "bytes": 457,
        "state_id": 170,
        "stored_velocity_scale": 100.0,
        "default_gravity": 0.035,
        "hitstun_frames": 60,
        "release_scale": 0.01,
        "landing_state": "0xA9",
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": hitstun_restore_helper,
        **helper_members[hitstun_restore_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

defeat_velocity_restore_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDefeatImpactVelocityRestore@")
)
(workbench / "defeat-impact-velocity-restore-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x4B",
        "entry": "0x006704A5",
        "bytes": 584,
        "state_id": 171,
        "stored_velocity_scale": 100.0,
        "combo_damage_scale_multiplier": 5.0,
        "hitstun_frames": 90,
        "tint": [0xB0, 3],
        "context_effect_types": [1, 4],
        "context_sound": 0x12,
        "release_scale": 0.01,
        "release_gravity": 0.035,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": defeat_velocity_restore_helper,
        **helper_members[defeat_velocity_restore_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


dash_recovery_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDashRecovery@")
)
(workbench / "dash-recovery-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x4C",
        "entry": "0x006706ED",
        "bytes": 312,
        "state_id": 178,
        "horizontal_deceleration": 0.03,
        "cancel": "inputY==-1 && field000a!=0 && field015c<3",
        "cancel_states": [4, 5, 6],
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": dash_recovery_helper,
        **helper_members[dash_recovery_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


(workbench / "dash-attack-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x4D": {"entry": "0x00670825", "bytes": 467, "state_id": 200, "deceleration": 0.06, "cancel": "attackCollisionResult>1", "meter_frame": 2, "meter_gain": 5, "sound": 21},
        "0x4E": {"entry": "0x006709F8", "bytes": 587, "state_id": 201, "deceleration": 0.03, "cancel": "attackCollisionResult>1", "effect_frame": 1, "effect_type": 420, "meter_frame": 3, "meter_gain": 15, "sound": 20},
        "0x4F": {"entry": "0x00670C43", "bytes": 434, "state_id": 202, "deceleration": 0.06, "cancel": None, "effect_frame": 3, "effect_type": 421, "meter_frame": 4, "meter_gain": 15, "sound": 20},
        "0x50": {"entry": "0x00670DF5", "bytes": 587, "state_id": 203, "deceleration": 0.06, "cancel": "attackCollisionResult==3", "meter_frame": 4, "meter_gain": 35, "sound": 35, "effect_frame": 6, "effect_type": 424},
        "0x51": {"entry": "0x00671040", "bytes": 491, "state_id": 204, "deceleration": 0.03, "cancel": "attackCollisionResult>1", "meter_frame": 1, "meter_gain": 5, "sound": 21, "completion": "inputY==1 ? 3 : 0"},
        "0x52": {"entry": "0x0067122B", "bytes": 611, "state_id": 205, "deceleration": 0.03, "cancel": "attackCollisionResult>1", "meter_frame": 2, "meter_gain": 13, "sound": 20, "effect_frame": 1, "effect_type": 422, "completion": "inputY==1 ? 3 : 0"},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06.cpp",
        "source_sha256": main_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06.obj",
        "object_sha256": main_receipt["object_sha256"],
        "inlined_case_sources": {
            f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc": hashlib.sha256(
                (workbench / f"Character19Slot06Case{case:02X}.inc").read_bytes()
            ).hexdigest()
            for case in (0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52)
        },
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

(workbench / "dash-attack-sustain-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x53",
        "entry": "0x0067148E",
        "bytes": 435,
        "state_id": 206,
        "deceleration": 0.03,
        "meter_frame": 3,
        "meter_gain": 25,
        "sound_slot": 0x14,
        "one_shot_gate": "field3138 == 0",
        "completion": "inputY == 1 ? 3 : 0",
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06.cpp",
        "source_sha256": main_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06.obj",
        "object_sha256": main_receipt["object_sha256"],
        "inlined_case_sources": {
            "workbench/character19-slot06/Character19Slot06Case53.inc": hashlib.sha256(
                (workbench / "Character19Slot06Case53.inc").read_bytes()
            ).hexdigest(),
        },
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

airborne_dash_followup_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneDashFollowup@")
)
(workbench / "airborne-dash-followup-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x54": {"entry": "0x00671641", "bytes": 675, "state_id": 207, "meter_frame": 2, "meter_gain": 5, "sound": 0x15, "effect_type": 0, "collision_clear_frame": 3},
        "0x55": {"entry": "0x006718E4", "bytes": 797, "state_id": 208, "meter_frame": 2, "meter_gain": 13, "sound": 0x14, "effect_frame": 3, "effect_type": 0x1A7, "collision_clear_frame": 4},
        "0x56": {"entry": "0x00671C01", "bytes": 797, "state_id": 209, "meter_frame": 1, "meter_gain": 30, "sound": 0x14, "effect_frame": 1, "effect_type": 0x1A9, "collision_clear_frame": 3},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": airborne_dash_followup_helper,
        **helper_members[airborne_dash_followup_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


aerial_launch_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAerialLaunchLanding@")
)
(workbench / "aerial-launch-landing-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x57",
        "entry": "0x00671F1E",
        "bytes": 454,
        "state_id": 210,
        "launch_frame": 1,
        "launch_velocity": [1.4, -1.5],
        "gravity": 0.08,
        "meter_frame": 2,
        "meter_gain": 15,
        "stop_frame": 5,
        "landing_gate": "frame-5 holds at frame-4 until positionY+velocityY>=0",
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": aerial_launch_helper,
        **helper_members[aerial_launch_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

dash_followup_cancel_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDashFollowupCancel@")
)
(workbench / "dash-followup-cancel-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x58",
        "entry": "0x006720E4",
        "bytes": 387,
        "state_id": 211,
        "cancel": "inputY==-1 && field000a>0 && field015c<3 && attackCollisionResult>1",
        "cancel_states": [4, 5, 6],
        "meter_frame": 3,
        "meter_gain": 30,
        "sound": 0x14,
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": dash_followup_cancel_helper,
        **helper_members[dash_followup_cancel_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


aerial_ground_slam_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAerialGroundSlam@")
)
(workbench / "aerial-ground-slam-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x59",
        "entry": "0x00672267",
        "bytes": 443,
        "state_id": 212,
        "meter_frame": 0,
        "meter_gain": 30,
        "sound": 0x14,
        "velocity_x_scale": 0.5,
        "gravity": 0.07,
        "collision_exit_state": "0xD5",
        "landing_state": "0xD6",
        "landing_effect": {"owner": 0, "type": 3, "group": 2, "layer": 0, "palette": 7},
        "animation_repeat_back": 2,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": aerial_ground_slam_helper,
        **helper_members[aerial_ground_slam_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

aerial_kickback_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAerialKickback@")
)
(workbench / "aerial-kickback-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x5A",
        "entry": "0x00672422",
        "bytes": 188,
        "state_id": 213,
        "velocity_x": -1.0,
        "velocity_y": -2.4,
        "gravity": 0.042,
        "completion_state": 9,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": aerial_kickback_helper,
        **helper_members[aerial_kickback_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

ground_impact_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateGroundImpactRecovery@")
)
(workbench / "ground-impact-recovery-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x5B",
        "entry": "0x006724DE",
        "bytes": 287,
        "state_id": 214,
        "vertical_shake": [3, 0],
        "effect": {"owner": 0, "type": 3, "group": 2, "layer": 0, "palette": 7},
        "completion": "inputY==1 ? 3 : 7",
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": ground_impact_helper,
        **helper_members[ground_impact_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


opponent_capture_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateOpponentCaptureImpact@")
)
(workbench / "opponent-capture-impact-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x5C",
        "entry": "0x006725FD",
        "bytes": 480,
        "state_id": 220,
        "hit_gate": "field000a==1 && attackCollisionResult==3",
        "remaining_hit_gate": "field000a==1 && field000c==0 && opponent.positionY==0",
        "own_state": "0xDD",
        "opponent_air_action_disabled": 1,
        "effect": {"owner": 0, "type": 0, "x_offset": "trunc(positionX)+facing*37", "y_offset": "trunc(positionY)-42", "group": 2, "layer": 1},
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": opponent_capture_helper,
        **helper_members[opponent_capture_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

opponent_stage_combo_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateOpponentStageCombo@")
)
(workbench / "opponent-stage-combo-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x5D",
        "entry": "0x006727DD",
        "bytes": 594,
        "state_id": 221,
        "damage_frame": 4,
        "damage": 0x4E2,
        "damage_scale": 750.0,
        "opponent_frames": {
            "1": {"state": 0x67, "x_offset": 0x29, "y": -86.0},
            "2": {"x_offset": 0x24, "y": -97.0},
            "3": {"x_offset": 0x22, "y": -97.0, "facing": "-facing"},
            "4": {"state": 0x61, "x_offset": 0x24, "y": 0.0, "vertical_shake": [3,0]},
        },
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": opponent_stage_combo_helper,
        **helper_members[opponent_stage_combo_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


trail_dash_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateTrailDashFinish@")
)
(workbench / "trail-dash-finish-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x5E": {"entry": "0x00672A2F", "bytes": 307, "state_id": 230, "meter_frame": 2, "meter_gain": 5, "sound": 0x15, "collision_clear_frame": 3, "completion_state": 0},
        "0x5F": {"entry": "0x00672B62", "bytes": 307, "state_id": 231, "meter_frame": 2, "meter_gain": 10, "sound": 0x14, "collision_clear_frame": 3, "completion_state": 0},
        "0x61": {"entry": "0x00672E47", "bytes": 307, "state_id": 233, "meter_frame": 1, "meter_gain": 5, "sound": 0x15, "collision_clear_frame": 5, "completion_state": 3},
        "0x62": {"entry": "0x00672F7A", "bytes": 307, "state_id": 234, "meter_frame": 2, "meter_gain": 10, "sound": 0x14, "collision_clear_frame": 3, "completion_state": 3},
    },
    "shared_native_behavior": {
        "trail_spacing": 3,
        "clear_dash_momentum": True,
        "horizontal_deceleration": 0.03,
        "initial_velocity": [2.0, 0.0],
        "collision_clear_before_frame": 3,
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": trail_dash_helper,
        **helper_members[trail_dash_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


dash_trail_charge_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDashTrailCharge@")
)
(workbench / "dash-trail-charge-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x60",
        "entry": "0x00672C95",
        "bytes": 434,
        "state_id": 232,
        "trail_spacing": 3,
        "frame_3_velocity_x": 3.0,
        "post_burst_decay": 0.07,
        "meter_frame": 3,
        "meter_gain": 35,
        "sound": 0x14,
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": dash_trail_charge_helper,
        **helper_members[dash_trail_charge_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

airborne_trail_dash_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateAirborneTrailDash@")
)
(workbench / "airborne-trail-dash-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x63",
        "entry": "0x006730AD",
        "bytes": 483,
        "state_id": 235,
        "trail_spacing": 3,
        "launch_frame": 3,
        "launch_velocity": [1.5, -1.5],
        "gravity": 0.032,
        "landing_predicate": "positionY+velocityY>0",
        "landing_frame": 15,
        "meter_frame": 7,
        "meter_gain": 35,
        "sound": 0x14,
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": airborne_trail_dash_helper,
        **helper_members[airborne_trail_dash_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


stun_effect_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateStunEffectRecovery@")
)
(workbench / "stun-effect-recovery-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x64",
        "entry": "0x00673290",
        "bytes": 320,
        "state_id": 249,
        "opening_fields": {"field00dc": 4, "field00de": 0xec, "velocityX": 0.0, "remainingHitCount": 1, "guardInputFrames": 0, "hitstunFrames": 60},
        "context_effect": {"owner": 0, "type": 0x28, "x_offset": "trunc(positionX)+facing*10", "y_offset": "trunc(positionY)-40", "group": 2, "layer": 1, "palette": 0x13},
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": stun_effect_helper,
        **helper_members[stun_effect_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

impact_pair_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateImpactEffectPair@")
)
(workbench / "impact-effect-pair-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x65",
        "entry": "0x006733D0",
        "bytes": 465,
        "state_id": 250,
        "opening": "ResetFrame",
        "frame4_meter_gain": 45,
        "character_sound": 1,
        "context_effect": {"owner": 0, "type": 0x1f, "group": 0, "layer": 1},
        "local_effect": {"owner": 1, "type": 0x194, "x_offset": "trunc(positionX)-facing*80", "y_offset": "trunc(positionY)-40", "group": 2, "layer": 1},
        "collision_clear_before_frame": 5,
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": impact_pair_helper,
        **helper_members[impact_pair_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

(workbench / "combo-impact-burst-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x66",
        "entry": "0x006735A1",
        "bytes": 708,
        "state_id": 251,
        "opening": "ResetFrame; StartTrail(3)",
        "field0118_decay": {"field0120_zero": 500.0, "field0120_nonzero": 250.0},
        "opening_context_effect": {"owner": 0, "type": 0x21, "y_offset": -50, "group": 2, "layer": 1, "palette": 0xb},
        "frame2_local_effect": {"owner": 1, "type": 0x1ab},
        "frame4_meter_gain": 45,
        "frame4_context_effect": {"owner": 0, "type": 0x1f},
        "frame4_local_effect": {"owner": 1, "type": 0x194},
        "collision_clear_before_frame": 5,
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06.cpp",
        "source_sha256": main_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06.obj",
        "object_sha256": main_receipt["object_sha256"],
        "inlined_case_sources": {
            "workbench/character19-slot06/Character19Slot06Case66.inc": hashlib.sha256(
                (workbench / "Character19Slot06Case66.inc").read_bytes()
            ).hexdigest(),
        },
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

damped_finish_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateDampedImpactFinish@")
)
(workbench / "damped-impact-finish-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x67",
        "entry": "0x00673865",
        "bytes": 434,
        "state_id": 253,
        "opening_velocity_scale": 0.3,
        "vertical_acceleration": 0.01,
        "positive_vertical_velocity_cap": 0.3,
        "frame4_meter_gain": 45,
        "character_sound": 1,
        "frame4_local_effect": {"owner": 1, "type": 0x194},
        "collision_clear_before_frame": 5,
        "completion_state": 9,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": damped_finish_helper,
        **helper_members[damped_finish_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


looping_aerial_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateLoopingAerialBounce@")
)
(workbench / "looping-aerial-bounce-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x68",
        "entry": "0x00673A17",
        "bytes": 361,
        "state_id": 256,
        "opening": "ResetFrame; remainingHitCount=2",
        "airborne_predicate": "positionY>=0 || positionY+velocityY<0 after gravity integration",
        "frame3_launch": {"velocityY": -2.5, "gravity": 0.045},
        "frame3_local_effect": {"owner": 1, "type": 0x1b9, "group": 2, "layer": 1},
        "loop_back": 2,
        "landing_state": 0x103,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": looping_aerial_helper,
        **helper_members[looping_aerial_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

combo_aerial_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateComboAerialBounce@")
)
(workbench / "combo-aerial-bounce-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x69",
        "entry": "0x00673B80",
        "bytes": 704,
        "state_id": 257,
        "trail_spacing": 1,
        "one_shot_opening_gate": "field313c==0",
        "field0118_decay": {"field0120_zero": 500.0, "field0120_nonzero": 250.0},
        "opening_context_effect": {"owner": 0, "type": 0x21, "y_offset": -50, "group": 2, "layer": 1, "palette": 0xb},
        "frame1_local_effect": {"owner": 1, "type": 0x1b9, "group": 2, "layer": 1},
        "frame3_launch": {"velocityY": -3.5, "gravity": 0.015, "one_shot_gate": "field313c==1"},
        "loop_back": {"frame": 8, "counter": "field3138<5"},
        "landing_state": 0x103,
        "completion_state": 9,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": combo_aerial_helper,
        **helper_members[combo_aerial_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

face_transition_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateFinalFaceTransition@")
)
(workbench / "final-face-transition-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x6A",
        "entry": "0x00673E40",
        "bytes": 120,
        "state_id": 259,
        "completion_state": 3,
        "completion_actions": ["FaceOpponent", "ResetPose"],
        "collision_clear": "every animation-frame transition",
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": face_transition_helper,
        **helper_members[face_transition_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

local_finish_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateLocalEffectFinish@")
)
(workbench / "local-effect-finishes-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": {
        "0x6B": {"entry": "0x00673EB8", "bytes": 355, "state_id": 263, "effect_type": 0x190},
        "0x6C": {"entry": "0x0067401B", "bytes": 355, "state_id": 264, "effect_type": 0x191},
        "0x6D": {"entry": "0x0067417E", "bytes": 355, "state_id": 265, "effect_type": 0x192},
    },
    "shared_native_behavior": {
        "opening": "ResetFrame",
        "effect": {"owner": 1, "x_offset": "round(positionX)+facing*30", "y_offset": "round(positionY)-40", "group": 0, "layer": 1, "facing": "facing!=1", "flag0018": "facing", "field0028": 1},
        "meter_gain": 45,
        "character_sound": 2,
        "collision_clear_after_frame": 9,
        "completion_state": 0,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": local_finish_helper,
        **helper_members[local_finish_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


final_effect_pair_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateFinalEffectPair@")
)
(workbench / "final-effect-pair-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x6E",
        "entry": "0x006742E1",
        "bytes": 500,
        "state_id": 266,
        "frame7_local_effect": {"owner": 1, "type": 0x195, "x_offset": "round(positionX)+facing*35", "y_offset": "round(positionY)-63", "group": 2, "layer": 1, "field0028": 0},
        "frame8_local_effect": {"owner": 1, "type": 0x196, "x_offset": "round(positionX)+facing*80", "y_offset": "round(positionY)-63", "group": 2, "layer": 1, "field0028": 0},
        "frame8_meter_gain": 45,
        "character_sound": 2,
        "completion_state": 0,
        "collision_clear": False,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": final_effect_pair_helper,
        **helper_members[final_effect_pair_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")

trail_effect_finish_helper = next(
    symbol for symbol in helper_members
    if symbol.startswith("?Slot06UpdateTrailEffectFinish@")
)
(workbench / "trail-effect-finish-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_case": {
        "selector": "0x6F",
        "entry": "0x006744D5",
        "bytes": 524,
        "state_id": 267,
        "opening": "ResetFrame; StartTrail(3); field0118-=field0120==0?500:250",
        "opening_context_effect": {"owner": 0, "type": 0x21, "y_offset": -50, "group": 2, "layer": 1, "palette": 0xb},
        "frame7_local_effect": {"owner": 1, "type": 0x1ad, "x_offset": "round(positionX)+facing*35", "y_offset": "round(positionY)-63", "group": 2, "layer": 1, "field0028": 0},
        "frame8_meter_gain": 45,
        "character_sound": 2,
        "completion_state": 0,
        "collision_clear": False,
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06Cases.cpp",
        "source_sha256": helper_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06Cases.obj",
        "object_sha256": helper_receipt["object_sha256"],
        "symbol": trail_effect_finish_helper,
        **helper_members[trail_effect_finish_helper],
        "status": "semantic-workbench-only-not-exact",
    },
    "dispatcher": dispatcher_record,
    "compiler_flags": flags,
}, indent=2) + "\n")


super_state_symbols = {
    f"0x{case:02X}": {
        "entry": entry,
        "bytes": native_bytes,
        "state_id": state,
        "symbol": f"?Slot06Case{case:02X}@Character19@@QAEXXZ",
    }
    for case, entry, native_bytes, state in (
        (0x70, "0x006746E1", 970, 300),
        (0x71, "0x00674AAB", 698, 303),
        (0x72, "0x00674D65", 501, 306),
        (0x73, "0x00674F5A", 2400, 309),
        (0x74, "0x006758BA", 177, 310),
    )
}
for case, record in super_state_symbols.items():
    record["symbol"] = None
    case_number = int(case, 16)
    record["inline_source"] = f"workbench/character19-slot06/Character19Slot06Case{case_number:02X}.inc"
    record["inline_source_sha256"] = hashlib.sha256(
        (ROOT / record["inline_source"]).read_bytes()
    ).hexdigest()
    record["candidate_status"] = "inlined-natural-cpp-semantic-candidate"
(workbench / "super-move-states-build.json").write_text(json.dumps({
    "target_sha256": "3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481",
    "native_cases": super_state_symbols,
    "case_0x71_loop": {
        "initial_field3138": 10,
        "loop_frame": 13,
        "loop_condition": "field3138>0",
        "frame_rewind": 2,
        "counter_delta": -1,
    },
    "shared_leafs": {
        "RandomRange": "FUN_004108a0",
        "SetSceneTimer": "FUN_004080c0",
        "SetHorizontalOffset": "FUN_00410a40",
        "SetHorizontalShake": "FUN_00410a80",
        "SetVerticalShake": "FUN_00410a10",
        "SetTint": "FUN_00410b10",
        "ResetFrame": "FUN_0040f1e0",
    },
    "candidate": {
        "source": "workbench/character19-slot06/Character19Slot06.cpp",
        "source_sha256": main_receipt["source_sha256"],
        "object": "build/character19-slot06/Character19Slot06.obj",
        "object_sha256": main_receipt["object_sha256"],
        "inlined_case_body": "workbench/character19-slot06/Character19Slot06Case73.inc",
        "inlined_case_body_sha256": super_state_symbols["0x73"]["inline_source_sha256"],
        "status": "natural-cpp-semantic-workbench-not-exact",
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
