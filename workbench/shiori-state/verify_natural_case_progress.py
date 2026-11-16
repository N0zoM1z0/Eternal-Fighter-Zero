#!/usr/bin/env python3
"""Focused target-backed progress audit for natural Shiori Slot06 cases 303-319.

This is not a whole-function Exact certificate. It verifies the natural-C++
source range, native frame, switch metadata, case extents and (where extents
match) original-bound relocation operands and byte differences.
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

from audit_case_codegen import ADDRESS, CODE_SIZE, TABLE_SIZE, SELECTOR_SIZE, SYMBOL
from coff import object_function
from common import sha256, target_bytes, verify_target
from native_build import compile_source
from verify_exact_regions import CALL_TARGETS, FLOAT_SYMBOL_TARGETS

SOURCE = ROOT / "workbench/shiori-state/ShioriState-natural-cases303-319.cpp"
OBJECT = ROOT / "build/shiori-state/ShioriState-natural-cases303-319.obj"
FLAGS = ["/Od", "/G6", "/MT", "/Gy", "/W3"]
FIRST_CASE = 303
LAST_CASE = 319


def case_body(text: str, case: int) -> str:
    start = text.index(f"    case {case}:")
    if case == LAST_CASE:
        end = text.index("\n\n  }\n}", start)
    else:
        end = text.index(f"    case {case + 1}:", start)
    return text[start:end]


def relocation_target(image: bytes, native_code: bytes, native_off: int,
                      reloc: dict) -> tuple[int | None, str]:
    operand = native_code[native_off:native_off + 4]
    if len(operand) != 4:
        raise AssertionError(("truncated native relocation operand", reloc, native_off))
    symbol = reloc["symbol"]
    if reloc["type"] == "REL32":
        target = (ADDRESS + native_off + 4 + struct.unpack("<i", operand)[0]) & 0xFFFFFFFF
        expected = CALL_TARGETS.get(symbol)
        if expected is None:
            return target, "unlisted-rel32-symbol"
        if target != expected:
            return target, "rel32-target-mismatch"
        return target, "bound-call"
    if reloc["type"] != "DIR32":
        raise AssertionError(("unknown COFF relocation type", reloc))
    target = struct.unpack("<I", operand)[0]
    if symbol.startswith("__real@"):
        payload = bytes.fromhex(symbol[len("__real@"):])[::-1]
        if target_bytes(image, target, len(payload)) != payload:
            return target, "literal-target-mismatch"
        return target, "bound-literal"
    if symbol == "_ShioriZeroOperand":
        payload = bytes(8)
        if target != 0x007872F8 or target_bytes(image, target, 8) != payload:
            return target, "zero-target-mismatch"
        return target, "bound-zero"
    if symbol in FLOAT_SYMBOL_TARGETS:
        expected, payload = FLOAT_SYMBOL_TARGETS[symbol]
        if target != expected or target_bytes(image, target, len(payload)) != payload:
            return target, "named-float-target-mismatch"
        return target, "bound-named-float"
    if "local_target_offset" in reloc:
        expected = ADDRESS + reloc["local_target_offset"]
        if target != expected:
            return target, "local-label-target-mismatch"
        return target, "bound-local-label"
    return target, "unlisted-dir32-symbol"


def mismatch_runs(left: bytes, right: bytes) -> list[dict]:
    runs = []
    i = 0
    while i < min(len(left), len(right)):
        if left[i] == right[i]:
            i += 1
            continue
        start = i
        while i < min(len(left), len(right)) and left[i] != right[i]:
            i += 1
        runs.append({"offset": hex(start), "length": i - start,
                     "native_hex": right[start:i].hex(),
                     "candidate_hex": left[start:i].hex()})
    return runs


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rebuild", action="store_true", help="compile only the natural Slot06 translation unit")
    parser.add_argument("--output", default="docs/evidence/shiori-slot06-natural-cases303-319-progress.json")
    args = parser.parse_args()

    if args.rebuild:
        compile_source(SOURCE, OBJECT, FLAGS, ROOT / ".analysis/build/shiori-natural-cases303-319.log")
    receipt = OBJECT.with_suffix(".build.json")
    if not OBJECT.is_file() or not receipt.is_file():
        raise SystemExit("missing selected natural-C++ object receipt; use --rebuild")
    identity = json.loads(receipt.read_text())
    if identity["source_sha256"] != sha256(SOURCE) or identity["object_sha256"] != sha256(OBJECT):
        raise SystemExit("stale natural-C++ object receipt; use --rebuild")

    source_text = SOURCE.read_text()
    cases_without_assembly = []
    for case in range(FIRST_CASE, LAST_CASE + 1):
        body = case_body(source_text, case)
        if "__asm" in body or "_emit" in body or "__emit" in body:
            raise AssertionError(("assembly/emission remains in selected case", case))
        cases_without_assembly.append(case)

    image = verify_target()
    native_code = target_bytes(image, ADDRESS, CODE_SIZE)
    native_table = target_bytes(image, ADDRESS + CODE_SIZE, TABLE_SIZE)
    native_selector = target_bytes(image, ADDRESS + CODE_SIZE + TABLE_SIZE, SELECTOR_SIZE)
    native_starts = [x - ADDRESS for x in struct.unpack("<135I", native_table)]

    compiled, relocations = object_function(OBJECT, SYMBOL)
    table_start = len(compiled) - TABLE_SIZE - SELECTOR_SIZE
    if compiled[:9] != native_code[:9]:
        raise AssertionError(("native frame/prologue differs", native_code[:9].hex(), compiled[:9].hex()))
    table_relocations = sorted(
        (r for r in relocations if table_start <= r["offset"] < table_start + TABLE_SIZE),
        key=lambda r: r["offset"],
    )
    if len(table_relocations) != 135:
        raise AssertionError(("unexpected switch table relocation count", len(table_relocations)))
    candidate_starts = [r["local_target_offset"] for r in table_relocations]
    if len(set(candidate_starts)) != 135:
        raise AssertionError("candidate switch table has duplicate case destinations")
    selector_byte_equal = compiled[table_start + TABLE_SIZE:] == native_selector

    cases = []
    all_unlisted = []
    for case in range(FIRST_CASE, LAST_CASE + 1):
        selector_index = native_selector[case - 1]
        native_start = native_starts[selector_index]
        native_end = min((x for x in native_starts if x > native_start), default=CODE_SIZE)
        candidate_start = candidate_starts[selector_index]
        candidate_end = min((x for x in candidate_starts if x > candidate_start), default=table_start)
        native_size = native_end - native_start
        candidate_size = candidate_end - candidate_start
        case_relocations = [r for r in relocations if candidate_start <= r["offset"] < candidate_end]
        row = {
            "case": case,
            "native_start": hex(ADDRESS + native_start),
            "candidate_start_offset": hex(candidate_start),
            "candidate_start_delta": candidate_start - native_start,
            "native_bytes": native_size,
            "candidate_bytes": candidate_size,
            "extent_equal": candidate_size == native_size,
            "coff_relocations": len(case_relocations),
        }
        if candidate_size == native_size:
            resolved = bytearray(compiled[candidate_start:candidate_end])
            bindings = []
            for reloc in case_relocations:
                off = reloc["offset"]
                local_off = off - candidate_start
                native_off = native_start + local_off
                target, kind = relocation_target(image, native_code, native_off, reloc)
                binding_verified = kind.startswith("bound-")
                if not binding_verified:
                    all_unlisted.append({"case": case, "relocation": reloc, "target": hex(target or 0), "kind": kind})
                operand = native_code[native_off:native_off + 4]
                resolved[local_off:local_off + 4] = operand
                bindings.append({"candidate_offset": hex(off), "native_va": hex(ADDRESS + native_off),
                                 "symbol": reloc["symbol"], "kind": kind,
                                 "target_verified": binding_verified,
                                 "target": hex(target) if target is not None else None})
            runs = mismatch_runs(bytes(resolved), native_code[native_start:native_end])
            row.update({
                "relocation_operands_offset_materialized": len(bindings),
                "relocation_targets_verified": sum(bool(b["target_verified"]) for b in bindings),
                "relocation_bindings": bindings,
                "difference_bytes_after_offset_operand_materialization": sum(r["length"] for r in runs),
                "difference_runs": len(runs),
                "first_mismatch_va": hex(ADDRESS + native_start + int(runs[0]["offset"], 16)) if runs else None,
                "whole_case_exact": not runs,
            })
        else:
            row.update({"relocation_operands_materialized": 0,
                        "difference_bytes_after_offset_operand_materialization": None,
                        "difference_runs": None, "whole_case_exact": False,
                        "qualification": "case extents differ; no offset-based relocation comparison claimed"})
        cases.append(row)

    native_frame = struct.unpack("<I", native_code[5:9])[0]
    candidate_frame = struct.unpack("<I", compiled[5:9])[0]
    native_owner = native_code + native_table + native_selector
    evidence = {
        "schema_version": 1,
        "status": "natural-cpp-progress-not-exact",
        "owner": SYMBOL,
        "target": {"address": hex(ADDRESS), "code_bytes": CODE_SIZE,
                   "table_bytes": TABLE_SIZE, "selector_bytes": SELECTOR_SIZE,
                   "owner_bytes": len(native_owner),
                   "sha256": hashlib.sha256(native_owner).hexdigest()},
        "candidate": {"source": str(SOURCE.relative_to(ROOT)), "source_sha256": sha256(SOURCE),
                      "object": str(OBJECT.relative_to(ROOT)), "object_sha256": sha256(OBJECT),
                      "owner_bytes": len(compiled), "code_bytes": table_start,
                      "compiler_flags": FLAGS, "frame_bytes": candidate_frame,
                      "toolchain_lock_sha256": identity["toolchain_lock_sha256"]},
        "natural_cpp_cases": cases_without_assembly,
        "source_has_inline_assembly_or_emitted_opcodes": False,
        "frame": {"native_bytes": native_frame, "candidate_bytes": candidate_frame,
                  "byte_exact": native_frame == candidate_frame},
        "switch": {"native_unique_destinations": len(set(native_starts)),
                   "candidate_unique_destinations": len(set(candidate_starts)),
                   "table_relocations": len(table_relocations),
                   "selector_byte_equal": selector_byte_equal},
        "relocation_accounting": {"total_coff_relocations": len(relocations),
                                   "case_relocations_offset_compared": sum(r["coff_relocations"] for r in cases),
                                   "case_relocation_targets_verified": sum(r.get("relocation_targets_verified", 0) for r in cases),
                                   "unverified_relocation_sites": all_unlisted},
        "summary": {
            "natural_cpp_cases": len(cases_without_assembly),
            "case_extents_equal": sum(r["extent_equal"] for r in cases),
            "case_bodies_byte_exact": sum(bool(r["whole_case_exact"]) for r in cases),
            "case_extent_mismatch_bytes": sum(r["candidate_bytes"] - r["native_bytes"] for r in cases),
            "candidate_code_size_delta": table_start - CODE_SIZE,
            "candidate_owner_size_delta": len(compiled) - len(native_owner),
        },
        "cases": cases,
        "qualification": (
            "The 17 selected case bodies are ordinary C++ with no inline assembly or emitted opcodes. "
            "The compiler naturally reproduces the native 0x384-byte frame. This is progress evidence, "
            "not a whole-owner Exact certificate; case extents and instruction bytes still differ."
        ),
    }
    output = ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(evidence, indent=2) + "\n")
    print(json.dumps({"status": evidence["status"], "source_sha256": evidence["candidate"]["source_sha256"],
                      "object_sha256": evidence["candidate"]["object_sha256"],
                      "frame": evidence["frame"], "switch": evidence["switch"],
                      "summary": evidence["summary"],
                      "unverified_relocation_sites": len(all_unlisted)}, indent=2))


if __name__ == "__main__":
    main()
