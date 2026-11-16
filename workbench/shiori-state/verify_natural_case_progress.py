#!/usr/bin/env python3
"""Focused target-backed progress audit for natural Shiori Slot06 cases 303-319.

This is not a whole-function Exact certificate. It checks natural-C++ source,
the native frame/switch, global instruction alignment, local branch targets,
COFF relocation targets and per-instruction byte differences.
"""
from __future__ import annotations

import argparse
import bisect
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
sys.path.insert(0, str(ROOT / "workbench/shiori-state"))

from audit_case_codegen import ADDRESS, CODE_SIZE, TABLE_SIZE, SELECTOR_SIZE, SYMBOL
from coff import object_function
from common import sha256, target_bytes, verify_target
from native_build import compile_source
from verify_exact_regions import CALL_TARGETS as _CALL_TARGETS, FLOAT_SYMBOL_TARGETS

SOURCE = ROOT / "workbench/shiori-state/ShioriState-natural-cases303-319.cpp"
OBJECT = ROOT / "build/shiori-state/ShioriState-natural-cases303-319.obj"
FLAGS = ["/Od", "/G6", "/MT", "/Gy", "/W3"]
FIRST_CASE = 303
LAST_CASE = 319
CALL_TARGETS = dict(_CALL_TARGETS)
# The original Shiori disassembly and original Slot06 source identify this
# runtime conversion helper at 0x7783B8; the candidate has a normal REL32 site.
CALL_TARGETS.setdefault("__ftol2", 0x007783B8)
GPRS = (
    "eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp",
    "ax", "bx", "cx", "dx", "si", "di", "bp", "sp",
    "al", "ah", "bl", "bh", "cl", "ch", "dl", "dh",
)
INSTRUCTION_RE = re.compile(
    r"^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*\t(.+)$"
)
BRANCH_RE = re.compile(r"\b(?:j[a-z]{1,4}|jmp|call)\s+0x([0-9a-f]+)\b")


def case_body(text: str, case: int) -> str:
    start = text.index(f"    case {case}:")
    if case == LAST_CASE:
        end = text.index("\n\n  }\n}", start)
    else:
        end = text.index(f"    case {case + 1}:", start)
    return text[start:end]


def relocation_target(image: bytes, native_code: bytes, native_off: int,
                      reloc: dict, expected_local_target: int | None = None
                      ) -> tuple[int | None, str]:
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
        expected = expected_local_target
        if expected is None:
            expected = ADDRESS + reloc["local_target_offset"]
        if target != expected:
            return target, "local-label-target-mismatch"
        return target, "bound-local-label"
    return target, "unlisted-dir32-symbol"


def disassemble(code: bytes, label: str) -> list[dict]:
    probe_dir = ROOT / ".analysis/probes/shiori-state"
    probe_dir.mkdir(parents=True, exist_ok=True)
    path = probe_dir / f"natural-progress-{label}.bin"
    path.write_bytes(code)
    try:
        output = subprocess.run(
            ["objdump", "-w", "-D", "-b", "binary", "-m", "i386", "-Mintel",
             "--adjust-vma=" + hex(ADDRESS), str(path)],
            capture_output=True, text=True, check=True,
        ).stdout
    finally:
        path.unlink(missing_ok=True)
    rows = []
    for line in output.splitlines():
        match = INSTRUCTION_RE.match(line)
        if not match:
            continue
        rows.append({
            "offset": int(match.group(1), 16) - ADDRESS,
            "bytes": bytes.fromhex(match.group(2)),
            "asm": match.group(3).strip(),
        })
    decoded_bytes = sum(len(row["bytes"]) for row in rows)
    if decoded_bytes != len(code):
        raise AssertionError(("objdump did not decode the complete code range",
                              label, len(code), decoded_bytes))
    return rows


def normalize_instruction(asm: str, relocation_count: int = 0) -> str:
    # COFF placeholders are zero in the .obj. Replace exactly the number of
    # zero-valued operands that have relocation records on this instruction.
    for _ in range(relocation_count):
        asm, count = re.subn(r"\b0x0\b", "TARGET", asm, count=1)
        if not count:
            break
    asm = re.sub(r"\b0x[0-9a-f]{5,}\b", "TARGET", asm)
    for register in GPRS:
        asm = re.sub(r"\b" + register + r"\b", "REG", asm)
    return re.sub(r"\s+", " ", asm).strip()


def branch_target(asm: str) -> int | None:
    match = BRANCH_RE.search(asm)
    return int(match.group(1), 16) if match else None


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
    candidate_code = compiled[:table_start]
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

    # One global instruction alignment lets us compare each case even when a
    # preceding case changes the code offset by a byte. GPR identities and
    # COFF-placeholder operands are normalized here; target bindings are
    # checked separately below.
    native_instructions = disassemble(native_code, "native")
    candidate_instructions = disassemble(candidate_code, "candidate")
    candidate_offsets = [row["offset"] for row in candidate_instructions]
    native_index_by_offset = {row["offset"]: i for i, row in enumerate(native_instructions)}
    candidate_index_by_offset = {row["offset"]: i for i, row in enumerate(candidate_instructions)}
    candidate_relocs_by_instruction: dict[int, list[dict]] = {}
    for reloc in relocations:
        if reloc["offset"] >= table_start:
            continue
        index = bisect.bisect_right(candidate_offsets, reloc["offset"]) - 1
        if index < 0:
            raise AssertionError(("relocation precedes first decoded instruction", reloc))
        instruction = candidate_instructions[index]
        if not instruction["offset"] <= reloc["offset"] < instruction["offset"] + len(instruction["bytes"]):
            raise AssertionError(("relocation is not contained by decoded instruction", reloc, instruction))
        candidate_relocs_by_instruction.setdefault(index, []).append(reloc)

    native_normalized = [normalize_instruction(row["asm"]) for row in native_instructions]
    candidate_normalized = [
        normalize_instruction(row["asm"], len(candidate_relocs_by_instruction.get(i, [])))
        for i, row in enumerate(candidate_instructions)
    ]
    global_instruction_shape_equal = native_normalized == candidate_normalized

    # Validate direct local branches by their paired instruction indices,
    # not by raw displacements (which legitimately move with case extents).
    branch_mismatches = []
    branch_checks = 0
    for index, (native_row, candidate_row) in enumerate(zip(native_instructions, candidate_instructions)):
        if index in candidate_relocs_by_instruction:
            continue  # REL32 targets are validated through the COFF record below.
        native_target = branch_target(native_row["asm"])
        candidate_target = branch_target(candidate_row["asm"])
        if native_target is None and candidate_target is None:
            continue
        branch_checks += 1
        if native_target is None or candidate_target is None:
            branch_mismatches.append({"instruction": index, "native": native_row["asm"],
                                      "candidate": candidate_row["asm"]})
            continue
        native_offset = native_target - ADDRESS
        candidate_offset = candidate_target - ADDRESS
        native_local = native_offset in native_index_by_offset
        candidate_local = candidate_offset in candidate_index_by_offset
        if native_local != candidate_local:
            branch_mismatches.append({"instruction": index, "native_target": hex(native_target),
                                      "candidate_target": hex(candidate_target)})
        elif native_local:
            if native_index_by_offset[native_offset] != candidate_index_by_offset[candidate_offset]:
                branch_mismatches.append({"instruction": index, "native_target_instruction": native_index_by_offset[native_offset],
                                          "candidate_target_instruction": candidate_index_by_offset[candidate_offset]})
        elif native_target != candidate_target:
            branch_mismatches.append({"instruction": index, "native_target": hex(native_target),
                                      "candidate_target": hex(candidate_target)})

    cases = []
    unverified_relocations = []
    for case in range(FIRST_CASE, LAST_CASE + 1):
        selector_index = native_selector[case - 1]
        native_start = native_starts[selector_index]
        native_end = min((x for x in native_starts if x > native_start), default=CODE_SIZE)
        candidate_start = candidate_starts[selector_index]
        candidate_end = min((x for x in candidate_starts if x > candidate_start), default=table_start)
        native_size = native_end - native_start
        candidate_size = candidate_end - candidate_start
        native_case_instructions = [r for r in native_instructions if native_start <= r["offset"] < native_end]
        candidate_case_instructions = [r for r in candidate_instructions if candidate_start <= r["offset"] < candidate_end]
        case_relocations = [r for r in relocations if candidate_start <= r["offset"] < candidate_end]
        instruction_shape_equal = (
            len(native_case_instructions) == len(candidate_case_instructions)
            and all(native_normalized[native_index_by_offset[native_case_instructions[i]["offset"]]]
                    == candidate_normalized[candidate_index_by_offset[candidate_case_instructions[i]["offset"]]]
                    for i in range(len(native_case_instructions)))
        )

        bindings = []
        resolved_candidate_instructions: dict[int, bytearray] = {
            candidate_index_by_offset[row["offset"]]: bytearray(row["bytes"])
            for row in candidate_case_instructions
        }
        for reloc in case_relocations:
            candidate_instruction_index = bisect.bisect_right(candidate_offsets, reloc["offset"]) - 1
            candidate_instruction = candidate_instructions[candidate_instruction_index]
            native_instruction = native_instructions[candidate_instruction_index]
            operand_relative_offset = reloc["offset"] - candidate_instruction["offset"]
            native_operand_offset = native_instruction["offset"] + operand_relative_offset
            expected_local_target = None
            if "local_target_offset" in reloc:
                target_index = candidate_index_by_offset.get(reloc["local_target_offset"])
                if target_index is not None:
                    expected_local_target = ADDRESS + native_instructions[target_index]["offset"]
            if operand_relative_offset + 4 > len(native_instruction["bytes"]):
                target, kind = None, "paired-native-operand-out-of-range"
            elif "local_target_offset" in reloc and expected_local_target is None:
                target, kind = None, "unmapped-local-label"
            else:
                target, kind = relocation_target(image, native_code, native_operand_offset,
                                                  reloc, expected_local_target)
            binding_verified = kind.startswith("bound-")
            if not binding_verified:
                unverified_relocations.append({"case": case, "relocation": reloc,
                                               "target": hex(target) if target is not None else None,
                                               "kind": kind})
            if operand_relative_offset + 4 <= len(resolved_candidate_instructions[candidate_instruction_index]):
                operand = native_code[native_operand_offset:native_operand_offset + 4]
                if len(operand) == 4:
                    resolved_candidate_instructions[candidate_instruction_index][
                        operand_relative_offset:operand_relative_offset + 4
                    ] = operand
            bindings.append({
                "candidate_offset": hex(reloc["offset"]),
                "candidate_instruction": candidate_instruction_index,
                "native_va": hex(ADDRESS + native_operand_offset),
                "symbol": reloc["symbol"],
                "kind": kind,
                "target_verified": binding_verified,
                "target": hex(target) if target is not None else None,
            })

        instruction_byte_differences = 0
        instruction_length_mismatches = 0
        first_instruction_mismatch = None
        if len(native_case_instructions) == len(candidate_case_instructions):
            for i, (native_instruction, candidate_instruction) in enumerate(
                    zip(native_case_instructions, candidate_case_instructions)):
                candidate_index = candidate_index_by_offset[candidate_instruction["offset"]]
                resolved = bytes(resolved_candidate_instructions[candidate_index])
                native_bytes = native_instruction["bytes"]
                if len(resolved) != len(native_bytes):
                    instruction_length_mismatches += 1
                    if first_instruction_mismatch is None:
                        first_instruction_mismatch = {
                            "instruction_in_case": i,
                            "native_va": hex(ADDRESS + native_instruction["offset"]),
                            "native_length": len(native_bytes),
                            "candidate_length": len(resolved),
                            "native_hex": native_bytes.hex(),
                            "candidate_hex": resolved.hex(),
                        }
                different = sum(a != b for a, b in zip(resolved, native_bytes))
                instruction_byte_differences += different
                if different and first_instruction_mismatch is None:
                    first_instruction_mismatch = {
                        "instruction_in_case": i,
                        "native_va": hex(ADDRESS + native_instruction["offset"]),
                        "native_length": len(native_bytes),
                        "candidate_length": len(resolved),
                        "native_hex": native_bytes.hex(),
                        "candidate_hex": resolved.hex(),
                    }

        relocation_targets_verified = sum(bool(b["target_verified"]) for b in bindings)
        whole_case_exact = (
            instruction_shape_equal
            and len(native_case_instructions) == len(candidate_case_instructions)
            and instruction_length_mismatches == 0
            and instruction_byte_differences == 0
            and relocation_targets_verified == len(case_relocations)
        )
        row = {
            "case": case,
            "native_start": hex(ADDRESS + native_start),
            "candidate_start_offset": hex(candidate_start),
            "candidate_start_delta": candidate_start - native_start,
            "native_bytes": native_size,
            "candidate_bytes": candidate_size,
            "extent_equal": candidate_size == native_size,
            "native_instruction_count": len(native_case_instructions),
            "candidate_instruction_count": len(candidate_case_instructions),
            "instruction_shape_equal_after_gpr_and_relocation_normalization": instruction_shape_equal,
            "instruction_length_mismatches": instruction_length_mismatches,
            "instruction_byte_differences_after_relocation_binding": instruction_byte_differences,
            "first_instruction_mismatch": first_instruction_mismatch,
            "coff_relocations": len(case_relocations),
            "relocation_targets_verified": relocation_targets_verified,
            "relocation_bindings": bindings,
            "whole_case_exact": whole_case_exact,
        }
        cases.append(row)

    native_frame = struct.unpack("<I", native_code[5:9])[0]
    candidate_frame = struct.unpack("<I", compiled[5:9])[0]
    native_owner = native_code + native_table + native_selector
    evidence = {
        "schema_version": 2,
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
        "instruction_alignment": {
            "native_instruction_count": len(native_instructions),
            "candidate_instruction_count": len(candidate_instructions),
            "global_instruction_shape_equal_after_gpr_and_relocation_normalization": global_instruction_shape_equal,
            "direct_branch_target_checks": branch_checks,
            "direct_branch_target_mismatches": branch_mismatches,
        },
        "relocation_accounting": {
            "total_coff_relocations": len(relocations),
            "case_relocations_instruction_aligned": sum(r["coff_relocations"] for r in cases),
            "case_relocation_targets_verified": sum(r["relocation_targets_verified"] for r in cases),
            "unverified_relocation_sites": unverified_relocations,
        },
        "summary": {
            "natural_cpp_cases": len(cases_without_assembly),
            "case_extents_equal": sum(r["extent_equal"] for r in cases),
            "case_instruction_shapes_equal": sum(bool(r["instruction_shape_equal_after_gpr_and_relocation_normalization"]) for r in cases),
            "case_bodies_byte_exact": sum(bool(r["whole_case_exact"]) for r in cases),
            "case_instruction_length_mismatches": sum(r["instruction_length_mismatches"] for r in cases),
            "case_instruction_byte_differences_after_relocation_binding": sum(r["instruction_byte_differences_after_relocation_binding"] for r in cases),
            "case_extent_mismatch_bytes": sum(r["candidate_bytes"] - r["native_bytes"] for r in cases),
            "candidate_code_size_delta": table_start - CODE_SIZE,
            "candidate_owner_size_delta": len(compiled) - len(native_owner),
        },
        "cases": cases,
        "qualification": (
            "All selected cases are ordinary C++ with no inline assembly or emitted opcodes. "
            "The VC7.1 compiler naturally reproduces the native 0x384-byte frame. "
            "Instruction-shape comparison ignores GPR identities and relocation operands; "
            "COFF targets and direct local branch destinations are checked separately. "
            "This is structural progress evidence, not a whole-owner Exact certificate."
        ),
    }
    output = ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(evidence, indent=2) + "\n")
    print(json.dumps({
        "status": evidence["status"],
        "source_sha256": evidence["candidate"]["source_sha256"],
        "object_sha256": evidence["candidate"]["object_sha256"],
        "frame": evidence["frame"],
        "switch": evidence["switch"],
        "instruction_alignment": evidence["instruction_alignment"],
        "summary": evidence["summary"],
        "unverified_relocation_sites": len(unverified_relocations),
    }, indent=2))


if __name__ == "__main__":
    main()
