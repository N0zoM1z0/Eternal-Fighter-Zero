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
assert len(implemented_states) == 242

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
