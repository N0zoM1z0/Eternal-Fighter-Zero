#!/usr/bin/env python3
"""Verify pinned byte-exact regions of the Shiori Slot06 workbench object.

This is deliberately a focused-region verifier, not a whole-function Exact
certificate. It reconstructs ten complete case bodies from original-bound
COFF operands and checks four late-state meter arithmetic blocks byte-for-byte.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
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
    "?SetSceneTimer@Context@@QAEXH@Z": 0x004080C0,
    "?SetVerticalShake@Secondary@@QAEXHH@Z": 0x00410A10,
    "?SetHorizontalShake@Secondary@@QAEXHH@Z": 0x00410A80,
    "?RequestTransition@Context@@QAEXD@Z": 0x00407CE0,
}
CASE_RELOCATIONS = {
    300: (13, 10), 301: (2, 0), 302: (2, 0), 303: (9, 9),
    304: (9, 9), 305: (10, 10), 310: (8, 8), 311: (9, 9),
    312: (24, 11), 319: (17, 6),
}
PINNED_ARITHMETIC = {
    306: (0x0042038B, 25, "sub eax,0x3E8"),
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
    native_starts = [x - ADDRESS for x in struct.unpack("<135I", native_table)]

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
    candidate_starts = [r["local_target_offset"] for r in table_relocations]
    if candidate_starts != native_starts:
        raise AssertionError("native and candidate case-entry offsets differ")
    if compiled[table_start + TABLE_SIZE:] != native_selector:
        raise AssertionError("selector bytes differ")

    def verify_case(case: int) -> dict:
        selector_index = native_selector[case - 1]
        native_start = native_starts[selector_index]
        native_end = min((x for x in native_starts if x > native_start), default=CODE_SIZE)
        candidate_start = candidate_starts[selector_index]
        candidate_end = min((x for x in candidate_starts if x > candidate_start), default=table_start)
        if candidate_end - candidate_start != native_end - native_start:
            raise AssertionError((case, candidate_end - candidate_start, native_end - native_start))
        resolved = bytearray(compiled[candidate_start:candidate_end])
        bound_calls = []
        bound_floats = []
        for reloc in relocations:
            off = reloc["offset"]
            if not candidate_start <= off < candidate_end:
                continue
            local_off = off - candidate_start
            native_off = native_start + local_off
            operand = native_code[native_off:native_off + 4]
            if len(operand) != 4:
                raise AssertionError((case, reloc, native_off))
            if reloc["type"] == "REL32":
                native_target = (ADDRESS + native_off + 4 + struct.unpack("<i", operand)[0]) & 0xFFFFFFFF
                expected_target = CALL_TARGETS.get(reloc["symbol"])
                if expected_target != native_target:
                    raise AssertionError((case, reloc["symbol"], hex(native_target), expected_target))
                bound_calls.append({"offset": hex(ADDRESS + native_off), "symbol": reloc["symbol"],
                                    "target": hex(native_target)})
            elif reloc["type"] == "DIR32":
                native_target = struct.unpack("<I", operand)[0]
                if reloc["symbol"].startswith("__real@"):
                    payload = bytes.fromhex(reloc["symbol"][len("__real@"):])[::-1]
                    if target_bytes(image, native_target, len(payload)) != payload:
                        raise AssertionError((case, reloc, hex(native_target)))
                    bound_floats.append({"offset": hex(ADDRESS + native_off),
                                         "target": hex(native_target), "payload": payload.hex()})
                elif "local_target_offset" in reloc:
                    if native_target != ADDRESS + reloc["local_target_offset"]:
                        raise AssertionError((case, reloc, hex(native_target)))
                else:
                    raise AssertionError((case, "unclassified DIR32", reloc, hex(native_target)))
            else:
                raise AssertionError((case, "unknown relocation", reloc))
            resolved[local_off:local_off + 4] = operand
        expected_relocations, expected_calls = CASE_RELOCATIONS[case]
        if len(bound_calls) != expected_calls or len(bound_calls) + len(bound_floats) != expected_relocations:
            raise AssertionError((case, len(bound_calls), len(bound_floats), expected_relocations, expected_calls))
        if bytes(resolved) != native_code[native_start:native_end]:
            raise AssertionError((case, "case bytes differ after relocation materialization"))
        return {"native_start": hex(ADDRESS + native_start), "bytes": native_end - native_start,
                "whole_case_byte_exact": True, "relocations_materialized": expected_relocations,
                "rel32_calls_materialized": len(bound_calls), "float_operands_materialized": len(bound_floats),
                "calls": bound_calls, "float_operands": bound_floats}

    exact_cases = {str(case): verify_case(case) for case in CASE_RELOCATIONS}
    arithmetic = []
    for case, (native_va, size, operation) in PINNED_ARITHMETIC.items():
        index = native_selector[case - 1]
        native_start = native_starts[index]
        candidate_start = candidate_starts[index]
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
        "whole_case_exact": exact_cases,
        "late_meter_arithmetic": arithmetic,
        "dispatch": {"table_relocations": len(table_relocations),
                     "case_entry_order_exact": True, "selector_bytes_exact": True},
        "qualification": "Ten complete case bodies are byte-exact after original-bound relocation materialization, and four additional meter arithmetic regions are byte-exact. Other Shiori Slot06 states still contain register-allocation differences. This is not a whole-function Exact certificate.",
    }
    output = ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(evidence, indent=2) + "\n")
    for case, result in exact_cases.items():
        print(f"case{case}: {result['bytes']} bytes exact; {result['relocations_materialized']} relocations ({result['rel32_calls_materialized']} calls, {result['float_operands_materialized']} floats)")
    print("meter blocks:", ", ".join(f"case{x['case']}={x['bytes']}B exact" for x in arithmetic))
    print("owner extent:", len(compiled), "bytes; table/selector order exact; other cases remain open")


if __name__ == "__main__":
    main()
