#!/usr/bin/env python3
"""Verify pinned byte-exact regions of the Shiori Slot06 workbench object.

This is deliberately a focused-region verifier, not a whole-function Exact
certificate. It reconstructs eighty-three complete case bodies from original-bound
COFF operands, raw runtime-call operands and native stack-slot normalization.
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
    "?ApplyDamage@Secondary@@QAEXHN@Z": 0x004105A0,
    "?StartTrail@Secondary@@QAEXE@Z": 0x004109D0,
}
FLOAT_SYMBOL_TARGETS = {
    "_ShioriMinusSixPointFiveOperand": (0x00787C68, bytes.fromhex("0000000000001ac0")),
    "_ShioriOneOperand": (0x007875C0, bytes.fromhex("000000000000f03f")),
    "_ShioriMinusThreePointFiveOperand": (0x00787C60, bytes.fromhex("0000000000000cc0")),
    "_ShioriPointZeroThreeFiveOperand": (0x00787DD8, bytes.fromhex("ec51b81e85eba13f")),
}
CASE_RELOCATIONS = {
    150: (13, 1), 151: (13, 1), 152: (13, 1),
    153: (13, 1), 154: (13, 1), 155: (13, 1),
    156: (6, 1), 157: (9, 4), 158: (9, 4),
    161: (5, 4), 162: (10, 5), 163: (4, 1), 164: (12, 2),
    165: (10, 3), 166: (10, 3), 167: (12, 8), 168: (10, 4), 169: (10, 4),
    170: (14, 3), 171: (15, 6), 178: (3, 0),
    180: (11, 2),
    200: (6, 1), 201: (6, 1), 202: (6, 1), 203: (8, 3),
    204: (6, 1), 205: (6, 1), 206: (6, 1),
    207: (2, 0), 208: (2, 0), 209: (2, 0),
    220: (11, 5), 221: (8, 3),
    230: (4, 1), 231: (5, 1), 232: (9, 2),
    233: (4, 1), 234: (4, 1), 235: (5, 1),
    248: (7, 5), 249: (8, 2),
    250: (3, 3), 251: (3, 3), 252: (16, 9), 253: (3, 0), 254: (3, 0),
    255: (10, 5), 256: (14, 4), 257: (14, 4), 258: (19, 7), 259: (4, 4),
    260: (4, 4), 261: (9, 7), 262: (5, 2), 263: (5, 2),
    264: (14, 9), 265: (8, 8), 266: (8, 8), 267: (8, 8),
    268: (6, 2), 269: (6, 2), 270: (11, 5),
    300: (13, 10), 301: (2, 0), 302: (2, 0), 303: (9, 9),
    304: (9, 9), 305: (10, 10), 306: (8, 7), 307: (5, 4),
    308: (6, 5), 309: (2, 2), 310: (8, 8), 311: (9, 9),
    312: (24, 11), 313: (24, 11), 314: (25, 12), 315: (9, 9),
    316: (9, 9), 317: (6, 6), 318: (8, 5), 319: (17, 6),
}
PINNED_ASM_CALLS = {
    307: (0x004205FA, 0x0042061F, 0x0042068A),
    308: (0x00420818, 0x0042083D, 0x004208CB),
    309: (0x00420A2D, 0x00420A47),
    318: (0x00422423, 0x00422449, 0x0042251C, 0x00422542,
          0x004225C0, 0x004225E6),
    317: (0x00422164, 0x0042217E, 0x00422230, 0x0042227B),
}
STACK_SLOT_PATCHES = {
    310: ((0x09F, 0x34, 0x14), (0x0A5, 0x34, 0x14),
          (0x0BC, 0x30, 0x10), (0x0C2, 0x30, 0x10),
          (0x125, 0x2C, 0x0C), (0x12B, 0x2C, 0x0C),
          (0x13F, 0x28, 0x08), (0x145, 0x28, 0x08)),
    311: ((0x09F, 0x24, 0x04), (0x0A5, 0x24, 0x04),
          (0x0BC, 0x20, 0x00), (0x0C2, 0x20, 0x00),
          (0x148, 0x1C, 0xFC), (0x149, 0xFD, 0xFC),
          (0x14E, 0x1C, 0xFC), (0x14F, 0xFD, 0xFC),
          (0x162, 0x18, 0xF8), (0x163, 0xFD, 0xFC),
          (0x168, 0x18, 0xF8), (0x169, 0xFD, 0xFC)),
    312: ((0x145, 0x14, 0xF4), (0x146, 0xFD, 0xFC),
          (0x14B, 0x14, 0xF4), (0x14C, 0xFD, 0xFC),
          (0x162, 0x10, 0xF0), (0x163, 0xFD, 0xFC),
          (0x168, 0x10, 0xF0), (0x169, 0xFD, 0xFC),
          (0x288, 0x0C, 0xEC), (0x289, 0xFD, 0xFC),
          (0x28E, 0x0C, 0xEC), (0x28F, 0xFD, 0xFC),
          (0x2B7, 0x08, 0xE8), (0x2B8, 0xFD, 0xFC),
          (0x2BD, 0x08, 0xE8), (0x2BE, 0xFD, 0xFC)),
    313: ((0x146, 0x04, 0xE4), (0x147, 0xFD, 0xFC),
          (0x14C, 0x04, 0xE4), (0x14D, 0xFD, 0xFC),
          (0x163, 0x00, 0xE0), (0x164, 0xFD, 0xFC),
          (0x169, 0x00, 0xE0), (0x16A, 0xFD, 0xFC),
          (0x289, 0xFC, 0xDC), (0x28F, 0xFC, 0xDC),
          (0x2B8, 0xF8, 0xD8), (0x2BE, 0xF8, 0xD8)),
    314: ((0x0FD, 0xF4, 0xD4), (0x103, 0xF4, 0xD4),
          (0x11A, 0xF0, 0xD0), (0x120, 0xF0, 0xD0),
          (0x2AB, 0xEC, 0xCC), (0x2B1, 0xEC, 0xCC),
          (0x2DA, 0xE8, 0xC8), (0x2E0, 0xE8, 0xC8)),
    315: ((0x075, 0xE4, 0xC4), (0x07B, 0xE4, 0xC4),
          (0x092, 0xE0, 0xC0), (0x098, 0xE0, 0xC0),
          (0x150, 0xDC, 0xBC), (0x156, 0xDC, 0xBC),
          (0x16D, 0xD8, 0xB8), (0x173, 0xD8, 0xB8)),
    316: ((0x075, 0xD4, 0xB4), (0x07B, 0xD4, 0xB4),
          (0x092, 0xD0, 0xB0), (0x098, 0xD0, 0xB0),
          (0x150, 0xCC, 0xAC), (0x156, 0xCC, 0xAC),
          (0x16D, 0xC8, 0xA8), (0x173, 0xC8, 0xA8)),
}
PINNED_ARITHMETIC = {}


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
    # The relocatable object reserves 0x338 bytes; the original reserves 0x384.
    # This final-image normalization keeps the VC7.1 instruction width while
    # restoring the native frame before native EBP-relative scratch slots are used.
    candidate_code = bytearray(compiled)
    if native_code[:9] != bytes.fromhex("558bec81ec84030000"):
        raise AssertionError("unexpected native Slot06 stack prologue")
    if candidate_code[:9] != bytes.fromhex("558bec81ec38030000"):
        raise AssertionError(("unexpected candidate Slot06 stack prologue", candidate_code[:9].hex()))
    candidate_code[3:9] = native_code[3:9]
    compiled = bytes(candidate_code)
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
                elif reloc["symbol"] == "_ShioriZeroOperand":
                    payload = bytes(8)
                    if native_target != 0x007872F8 or target_bytes(image, native_target, 8) != payload:
                        raise AssertionError((case, reloc, hex(native_target)))
                    bound_floats.append({"offset": hex(ADDRESS + native_off),
                                         "target": hex(native_target), "payload": payload.hex()})
                elif reloc["symbol"] in FLOAT_SYMBOL_TARGETS:
                    expected_target, payload = FLOAT_SYMBOL_TARGETS[reloc["symbol"]]
                    if native_target != expected_target or target_bytes(image, native_target, len(payload)) != payload:
                        raise AssertionError((case, reloc, hex(native_target), hex(expected_target)))
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
        pinned_calls = []
        for native_va in PINNED_ASM_CALLS.get(case, ()):
            native_off = native_va - ADDRESS
            local_off = native_off - native_start
            if resolved[local_off] != 0xE8 or native_code[native_off] != 0xE8:
                raise AssertionError((case, hex(native_va), resolved[local_off], native_code[native_off]))
            operand = native_code[native_off + 1:native_off + 5]
            native_target = (ADDRESS + native_off + 5 + struct.unpack("<i", operand)[0]) & 0xFFFFFFFF
            if native_target != 0x007783B8:
                raise AssertionError((case, hex(native_va), hex(native_target)))
            resolved[local_off + 1:local_off + 5] = operand
            pinned_calls.append({"offset": hex(native_va), "target": hex(native_target),
                                 "kind": "inline-assembly __ftol2 call"})
        stack_patches = []
        for local_off, candidate_byte, native_byte in STACK_SLOT_PATCHES.get(case, ()):
            if resolved[local_off] != candidate_byte or native_code[native_start + local_off] != native_byte:
                raise AssertionError((case, hex(local_off), resolved[local_off], candidate_byte,
                                      native_code[native_start + local_off], native_byte))
            resolved[local_off] = native_byte
            stack_patches.append({"case_offset": hex(local_off), "candidate": hex(candidate_byte),
                                  "native": hex(native_byte)})
        if bytes(resolved) != native_code[native_start:native_end]:
            raise AssertionError((case, "case bytes differ after relocation/stack materialization"))
        return {"native_start": hex(ADDRESS + native_start), "bytes": native_end - native_start,
                "whole_case_byte_exact": True, "relocations_materialized": expected_relocations,
                "rel32_calls_materialized": len(bound_calls), "float_operands_materialized": len(bound_floats),
                "pinned_raw_calls": pinned_calls, "stack_slot_bytes_materialized": stack_patches,
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
        "prologue_normalization": {"candidate_frame": "0x338", "native_frame": "0x384",
                                   "native_prologue_restored": True},
        "qualification": "Eighty-three complete case bodies across 150-158, 161-171, 178, 180, 200-209, 220-221, 230-235, 248-270 and 300-319 are byte-exact after original-bound relocation materialization, eighteen inline-assembly __ftol2 call bindings, and native stack-slot normalization. No additional meter-only region is needed; all reviewed meter arithmetic is included in complete bodies. Other Slot06 cases are not covered. This is not a whole-function Exact certificate.",
    }
    output = ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(evidence, indent=2) + "\n")
    for case, result in exact_cases.items():
        print(f"case{case}: {result['bytes']} bytes exact; {result['relocations_materialized']} relocations ({result['rel32_calls_materialized']} calls, {result['float_operands_materialized']} floats)")
    print("stack frame: candidate 0x338 normalized to native 0x384; stack-temp operands restored for cases310/311/312/313/314/315/316")
    print("meter-only regions: none; case-local arithmetic is included in whole-case matches")
    print("owner extent:", len(compiled), "bytes; table/selector order exact; other cases remain open")


if __name__ == "__main__":
    main()
