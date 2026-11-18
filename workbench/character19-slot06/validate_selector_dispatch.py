"""Validate Kanna Slot06's 310-byte selector and 118-entry target tables."""
import csv
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes

rows = list(csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open()))
assert len(rows) == 118
selector = [None] * 310
case_targets = []
for row in rows:
    case = int(row["case_index"], 16)
    case_targets.append(int(row["native_entry"], 16))
    for state in (int(value) for value in row["state_ids"].split(";") if value):
        assert 1 <= state <= 310
        assert selector[state - 1] is None
        selector[state - 1] = case
assert all(value is not None for value in selector)

pe = verify_target()
native_selector = target_bytes(pe, 0x00675B43, 310)
native_targets = struct.unpack("<118I", target_bytes(pe, 0x0067596B, 472))
assert bytes(selector) == native_selector
assert tuple(case_targets) == native_targets

source = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
match = re.search(
    r"static const unsigned char Character19Slot06SelectorCases\[0x136\] = \{(.*?)\};",
    source,
    re.S,
)
assert match is not None
compiled_literals = [int(value, 16) for value in re.findall(r"0x([0-9a-fA-F]{2})", match.group(1))]
assert compiled_literals == selector
assert "switch (selectorCase)" in source
assert "selectorCase = Character19Slot06SelectorCases[field0008 - 1];" in source
assert "selectorCase = 0x75;" in source
assert "switch (field0008)" not in source

labels = [int(value) for value in re.findall(r"^    case (\d+):$", source, re.M)]
assert sorted(set(labels)) == list(range(118))
assert len(labels) == 118
assert "case 300:" not in source and "case 310:" not in source

def resolve_state(state_id):
    if state_id == 0 or state_id > 0x136:
        return 0x75
    return selector[state_id - 1]

assert [resolve_state(state) for state in (0, 1, 10, 11, 310, 311, 0xFFFF)] == [
    0x75, 0x00, 0x09, 0x75, 0x74, 0x75, 0x75
]
fallback_count = len([value for value in selector if value == 0x75])
assert fallback_count == 193
print({
    "selector_table_bytes": len(selector),
    "selector_table_matches_native": True,
    "case_target_entries": len(native_targets),
    "case_targets_match_native": True,
    "switch_cases": len(set(labels)),
    "fallback_state_ids": fallback_count,
})
