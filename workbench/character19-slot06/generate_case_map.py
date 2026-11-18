import csv
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes

native = verify_target()
function_start = 0x00667570
function_end = 0x0067596A
jump_table_start = 0x0067596B
selector_start = 0x00675B43
case_count = 0x76
state_count = 0x136

jump_data = target_bytes(native, jump_table_start, case_count * 4)
selector = target_bytes(native, selector_start, state_count)
case_addresses = [
    struct.unpack_from("<I", jump_data, i * 4)[0]
    for i in range(case_count)
]
states = {i: [] for i in range(case_count)}
for state_id, case_index in enumerate(selector, 1):
    if case_index not in states:
        raise SystemExit(f"state {state_id}: invalid selector {case_index:#x}")
    states[case_index].append(state_id)

# Recover the native code interval for each case from its actual switch target.
ordered = sorted(set(case_addresses))
ends = {
    address: (ordered[i + 1] if i + 1 < len(ordered) else function_end + 1)
    for i, address in enumerate(ordered)
}
out = ROOT / "workbench/character19-slot06/case-map.csv"
with out.open("w", newline="") as stream:
    writer = csv.writer(stream)
    writer.writerow([
        "case_index", "native_entry", "native_end_exclusive",
        "native_code_bytes", "state_count", "state_ids",
    ])
    for index, address in enumerate(case_addresses):
        end = ends[address]
        writer.writerow([
            f"0x{index:02X}", f"0x{address:08X}", f"0x{end:08X}",
            end - address, len(states[index]),
            ";".join(str(x) for x in states[index]),
        ])
print({
    "function_start": hex(function_start),
    "function_end_exclusive": hex(function_end + 1),
    "function_bytes": function_end + 1 - function_start,
    "jump_table_start": hex(jump_table_start),
    "jump_table_bytes": len(jump_data),
    "selector_start": hex(selector_start),
    "selector_bytes": len(selector),
    "case_count": len(case_addresses),
    "unique_native_case_entries": len(ordered),
    "mapped_states": len(selector),
    "fallback_states": len(states[0x75]),
    "case_0x73_entry": hex(case_addresses[0x73]),
    "case_0x73_end": hex(ends[case_addresses[0x73]]),
    "case_0x73_bytes": ends[case_addresses[0x73]] - case_addresses[0x73],
    "case_0x73_states": states[0x73],
    "output": str(out.relative_to(ROOT)),
})
