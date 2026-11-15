#!/usr/bin/env python3
"""Verify pinned byte-exact regions of the Shiori Slot06 workbench object.

This is deliberately a focused-region verifier, not a whole-function Exact
certificate. It reconstructs the nine case-303 REL32 operands from the native
image and checks three late-state meter arithmetic blocks byte-for-byte.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
sys.path.insert(0, str(ROOT / "workbench/shiori-state"))

from audit_case_codegen import ADDRESS, CODE_SIZE, OBJECT, SELECTOR_SIZE, SOURCE, SYMBOL, TABLE_SIZE
from coff import object_function
from common import sha256, target_bytes, verify_target
from native_build import compile_source

CALL_TARGETS = {
    "?SetTint@Secondary@@QAEXEH@Z": 0x00410B10,
    "__ftol2": 0x007783B8,
    "?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z": 0x00407100,
    "?ResetFrame@Secondary@@QAEXXZ": 0x0040F1E0,
    "?RandomRange@Secondary@@QAEFFF@Z": 0x004108A0,
    "?FaceOpponent@Secondary@@QAEHXZ": 0x0040E630,
}
PINNED_ARITHMETIC = {
    307: (0x004205C2, 25, "sub eax,0x7D0"),
    308: (0x004207E0, 25, "sub eax,0xBB8"),
    315: (0x00421BEB, 26, "sub edx,0x3E8"),
}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rebuild", action="store_true", help="compile only the Shiori workbench TU")
    parser.add_argument("--output", default="docs/evidence/shiori-slot06-exact-regions.json")
    args = parser.parse_args()
    if args.rebuild:
        compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                       ROOT / ".analysis/build/shiori-exact-regions.log")
    receipt_path = OBJECT.with_suffix(".build.json")
    if not OBJECT.is_file() or not receipt_path.is_file():
        raise SystemExit("missing VC7.1 workbench object receipt; use --rebuild")
    receipt = json.loads(receipt_path.read_text())
    if receipt["source_sha256"] != sha256(SOURCE) or receipt["object_sha256"] != sha256(OBJECT):
        raise SystemExit("stale workbench object receipt; use --rebuild")

    image = verify_target()
    native_code = target_bytes(image, ADDRESS, CODE_SIZE)
    native_table = target_bytes(image, ADDRESS + CODE_SIZE, TABLE_SIZE)
    native_selector = target_bytes(image, ADDRESS + CODE_SIZE + TABLE_SIZE, SELECTOR_SIZE)
    original_starts = [x - ADDRESS for x in __import__("struct").unpack("<135I", native_table)]

    compiled, relocations = object_function(OBJECT, SYMBOL)
    table_start = len(compiled) - TABLE_SIZE - SELECTOR_SIZE
    if len(compiled) != CODE_SIZE + TABLE_SIZE + SELECTOR_SIZE or table_start != CODE_SIZE:
        raise AssertionError((len(compiled), table_start, CODE_SIZE))
    table_relocations = sorted(
        (r for r in relocations if table_start <= r["offset"] < table_start + TABLE_SIZE),
        key=lambda r: r["offset"],
    )
    if len(table_relocations) != 135:
        raise AssertionError(f"expected 135 switch-table relocations, got {len(table_relocations)}")
    compiled_starts = [r["local_target_offset"] for r in table_relocations]
    if compiled_starts != original_starts:
        raise AssertionError("native and candidate case-entry offsets differ")
    if compiled[table_start + TABLE_SIZE:] != native_selector:
        raise AssertionError("selector bytes differ")

    # Case 303 is now a complete 611-byte byte-exact block. Its nine direct
    # calls remain COFF REL32 placeholders in the .obj; bind them to original
    # native targets before comparing the complete block.
    selector_index = native_selector[302]
    case303_start = original_starts[selector_index]
    case303_end = min((x for x in original_starts if x > case303_start), default=CODE_SIZE)
    candidate303_start = compiled_starts[selector_index]
    candidate303_end = min((x for x in compiled_starts if x > candidate303_start), default=table_start)
    if candidate303_end - candidate303_start != case303_end - case303_start:
        raise AssertionError("case303 native/candidate extents differ")
    resolved303 = bytearray(compiled[candidate303_start:candidate303_end])
    bound_calls = []
    for reloc in relocations:
        off = reloc["offset"]
        if not candidate303_start <= off < candidate303_end:
            continue
        if reloc["type"] != "REL32":
            raise AssertionError(("unexpected case303 relocation", reloc))
        local_off = off - candidate303_start
        native_off = case303_start + local_off
        operand = native_code[native_off:native_off + 4]
        if len(operand) != 4:
            raise AssertionError((reloc, native_off))
        native_target = (ADDRESS + native_off + 4 + __import__("struct").unpack("<i", operand)[0]) & 0xFFFFFFFF
        expected_target = CALL_TARGETS.get(reloc["symbol"])
        if expected_target != native_target:
            raise AssertionError((reloc["symbol"], hex(native_target), expected_target))
        resolved303[local_off:local_off + 4] = operand
        bound_calls.append({"offset": hex(ADDRESS + native_off), "symbol": reloc["symbol"],
                            "target": hex(native_target)})
    if len(bound_calls) != 9:
        raise AssertionError(f"expected nine case303 direct-call bindings, got {len(bound_calls)}")
    if bytes(resolved303) != native_code[case303_start:case303_end]:
        raise AssertionError("case303 differs after original-bound REL32 materialization")

    arithmetic = []
    for case, (native_va, size, operation) in PINNED_ARITHMETIC.items():
        index = native_selector[case - 1]
        native_start = original_starts[index]
        candidate_start = compiled_starts[index]
        local_off = native_va - ADDRESS - native_start
        native_off = native_va - ADDRESS
        expected = native_code[native_off:native_off + size]
        actual = compiled[candidate_start + local_off:candidate_start + local_off + size]
        if len(expected) != size or actual != expected:
            raise AssertionError((case, hex(native_va), expected.hex(), actual.hex()))
        arithmetic.append({"case": case, "native_va": hex(native_va), "bytes": size,
                           "operation": operation, "byte_exact": True})

    evidence = {
        "schema_version": 1,
        "status": "focused-exact-regions-not-whole-function",
        "owner": {"symbol": SYMBOL, "entry": hex(ADDRESS), "code_bytes": CODE_SIZE,
                  "table_bytes": TABLE_SIZE, "selector_bytes": SELECTOR_SIZE,
                  "total_bytes": len(compiled), "native_candidate_extent_size_equal": True},
        "build": {"source_sha256": sha256(SOURCE), "object_sha256": sha256(OBJECT),
                  "target_image_sha256": hashlib.sha256(native_code + native_table + native_selector).hexdigest()},
        "case303": {"native_start": hex(ADDRESS + case303_start),
                    "bytes": case303_end - case303_start, "whole_case_byte_exact": True,
                    "rel32_relocations_materialized": len(bound_calls), "calls": bound_calls},
        "late_meter_arithmetic": arithmetic,
        "dispatch": {"table_relocations": len(table_relocations),
                     "case_entry_order_exact": True, "selector_bytes_exact": True},
        "qualification": "These pinned regions are byte-exact after original-bound relocation materialization. Other Shiori Slot06 states still contain register-allocation differences; this is not a whole-function Exact certificate.",
    }
    output = ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(evidence, indent=2) + "\n")
    print("case303:", evidence["case303"]["bytes"], "bytes exact;", len(bound_calls), "original-bound calls")
    print("meter blocks:", ", ".join(f"{x['case']}={x['bytes']}B exact" for x in arithmetic))
    print("owner extent:", len(compiled), "bytes; table/selector order exact; other cases remain open")


if __name__ == "__main__":
    main()
