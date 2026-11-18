"""Shared assertions for the native two-level Slot06 selector."""
import csv
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
_rows = list(csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open()))
STATE_TO_SELECTOR = {
    int(state): int(row["case_index"], 16)
    for row in _rows
    for state in row["state_ids"].split(";")
    if state
}


def selector_case_for_state(state_id):
    return STATE_TO_SELECTOR[state_id]


def assert_selector_case(dispatcher_source, state_id):
    selector = selector_case_for_state(state_id)
    marker = f"    case {selector}:"
    assert marker in dispatcher_source, (
        f"state {state_id} must route through selector case {selector:#x}"
    )
    return True
