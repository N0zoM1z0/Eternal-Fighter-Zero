"""Target-bound, read-only per-case native disassembly audit for Shiori Slot06.

This is an investigation aid, NOT a strict COFF relocation oracle and NOT an
Exact match certificate. --rebuild compiles *only* the Shiori workbench TU.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from coff import object_function
from common import sha256, target_bytes, verify_target
from native_build import compile_source

ADDRESS = 0x004136D0
CODE_SIZE = 62273
TABLE_SIZE = 540
SELECTOR_SIZE = 319
SOURCE = ROOT / "workbench/shiori-state/ShioriState.cpp"
OBJECT = ROOT / "build/shiori-state/ShioriState.tracked-workbench.obj"
SYMBOL = "?Slot06@Character08@@UAEXXZ"


def disassemble(data: bytes, path: Path) -> list[tuple[int, int, str]]:
    path.write_bytes(data)
    result = subprocess.run(
        ["objdump", "-D", "-b", "binary", "-m", "i386", "-Mintel",
         "--insn-width=16", "--adjust-vma=" + hex(ADDRESS), str(path)],
        capture_output=True, text=True, check=True,
    )
    instructions = []
    for line in result.stdout.splitlines():
        match = re.match(r"^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*\t(.+)", line)
        if match:
            instructions.append((int(match[1], 16) - ADDRESS,
                                 len(bytes.fromhex(match[2])), match[3]))
    return instructions


def structural_normalization(asm: str) -> str:
    """Discard only operands that obscure *diagnostic* mnemonic similarity."""
    asm = re.sub(r"\b(j\w+)\s+(?:0x)?[0-9a-f]+", r"\1 TARGET", asm)
    asm = re.sub(r"\bcall\s+(?:0x)?[0-9a-f]+", "call DIRECT", asm)
    asm = re.sub(r"(QWORD|DWORD) PTR ds:0x[0-9a-f]+", r"\1 PTR ds:CONST", asm)
    for register, generic in (("eax", "R"), ("ecx", "R"), ("edx", "R"),
                              ("ax", "r"), ("cx", "r"), ("dx", "r"),
                              ("al", "l"), ("cl", "l"), ("dl", "l"),
                              ("ah", "h"), ("ch", "h"), ("dh", "h")):
        asm = re.sub(r"\b" + register + r"\b", generic, asm)
    return re.sub(r"\[ebp-0x[0-9a-f]+\]", "[stack-home]", asm)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rebuild", action="store_true", help="compile only this TU under pinned VC7.1")
    parser.add_argument("--start", type=int, default=300)
    parser.add_argument("--end", type=int, default=319)
    parser.add_argument("--output", default="workbench/shiori-state/case-codegen-audit.json")
    args = parser.parse_args()
    if args.rebuild:
        compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                       ROOT / ".analysis/build/shiori-tracked-workbench.log")
    receipt = OBJECT.with_suffix(".build.json")
    if not OBJECT.is_file() or not receipt.is_file():
        raise SystemExit("missing local VC7.1 object receipt; use --rebuild")
    identity = json.loads(receipt.read_text())
    if identity["source_sha256"] != sha256(SOURCE) or identity["object_sha256"] != sha256(OBJECT):
        raise SystemExit("stale object receipt or source; use --rebuild")
    original = verify_target()
    expected_code = target_bytes(original, ADDRESS, CODE_SIZE)
    addr_table = target_bytes(original, ADDRESS + CODE_SIZE, TABLE_SIZE)
    selector = target_bytes(original, ADDRESS + CODE_SIZE + TABLE_SIZE, SELECTOR_SIZE)
    assert len(selector) == 319 and set(selector) == set(range(135))
    original_starts = [a - ADDRESS for a in struct.unpack("<135I", addr_table)]
    assert len(set(original_starts)) == 135 and all(0 <= i < CODE_SIZE for i in original_starts)
    compiled, relocations = object_function(OBJECT, SYMBOL)
    table_start = len(compiled) - (TABLE_SIZE + SELECTOR_SIZE)
    reloc_by_offset = {r["offset"]: r for r in relocations if "local_target_offset" in r}
    assert all(table_start + 4*i in reloc_by_offset for i in range(135))
    compiled_starts = [reloc_by_offset[table_start + i*4]["local_target_offset"] for i in range(135)]
    assert len(set(compiled_starts)) == 135
    target_instr = disassemble(expected_code, ROOT / "build/shiori-state/Shiori-target-code-audit.bin")
    compiled_instr = disassemble(compiled[:table_start], ROOT / "build/shiori-state/Shiori-compiled-code-audit.bin")

    cases = []
    for number in range(args.start, args.end + 1):
        index = selector[number - 1]
        ts, cs = original_starts[index], compiled_starts[index]
        te = next((x for x in sorted(original_starts) if x > ts), CODE_SIZE)
        ce = next((x for x in sorted(compiled_starts) if x > cs), table_start)
        left = [r for r in target_instr if ts <= r[0] < te]
        right = [r for r in compiled_instr if cs <= r[0] < ce]
        normalized_equal = [structural_normalization(x[2]) for x in left] == [structural_normalization(x[2]) for x in right]
        widths = []
        if normalized_equal:
            widths = [{"index": i,
                       "target_va": hex(ADDRESS + t[0]),
                       "target_bytes": t[1], "compiled_bytes": c[1],
                       "target_insn": t[2], "compiled_insn": c[2]}
                      for i, (t, c) in enumerate(zip(left, right)) if t[1] != c[1]]
        cases.append({"animation_id": number, "target_size": te - ts,
                      "compiled_size": ce - cs,
                      "target_instruction_count": len(left), "compiled_instruction_count": len(right),
                      "normalized_opcode_sequence_equal": normalized_equal,
                      "instruction_width_differences": widths})

    evidence = {
        "status": "diagnostic-only-not-an-exact-match",
        "target_address": hex(ADDRESS),
        "target_extent_size": CODE_SIZE + TABLE_SIZE + SELECTOR_SIZE,
        "target_extent_sha256": hashlib.sha256(expected_code + addr_table + selector).hexdigest(),
        "compiled_extent_size": len(compiled),
        "compiler_object_sha256": sha256(OBJECT),
        "source_sha256": sha256(SOURCE),
        "compiled_relocations": len(relocations),
        "target_code_size": CODE_SIZE,
        "compiled_code_size": table_start,
        "selector_byte_equal": compiled[-SELECTOR_SIZE:] == selector,
        "case_range": [args.start, args.end],
        "cases_with_identical_normalized_opcode_sequence": sum(row["normalized_opcode_sequence_equal"] for row in cases),
        "cases": cases,
        "qualification": "Normalization erases GPR choices, branch destinations and stack homes. It never proves byte-exact codegen or binding of relocations.",
    }
    out = ROOT / args.output
    out.write_text(json.dumps(evidence, indent=2) + "\n")
    print("Shiori complete owner compiled:", len(compiled), "target:", CODE_SIZE + TABLE_SIZE + SELECTOR_SIZE)
    print("Target-relative address table/selector and local widths audited for cases", args.start, "through", args.end)
    print("Normalized opcode sequences:", evidence["cases_with_identical_normalized_opcode_sequence"], "/", len(cases))
    for row in cases:
        if row["target_size"] != row["compiled_size"] or not row["normalized_opcode_sequence_equal"]:
            print("case", row["animation_id"], "target", row["target_size"], "compiled", row["compiled_size"],
                  "width deltas", [(x["target_insn"], x["compiled_insn"]) for x in row["instruction_width_differences"]])
    print("Proof status: diagnostic-only, not Exact")

if __name__ == "__main__":
    main()
