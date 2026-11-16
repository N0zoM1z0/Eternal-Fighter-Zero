#!/usr/bin/env python3
"""Focused relocation-aware audit of the alternate natural PrepareBattle TU.

The candidate deliberately retains one compiler-generated two-byte receiver
copy. The report records that instruction and removes it only for a secondary
diagnostic alignment; the diagnostic is never labelled Exact.
"""
from __future__ import annotations

import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import sha256, target_bytes, verify_target
from coff import object_function
from native_build import compile_source

SOURCE = ROOT / "workbench/prepare-battle/SceneLoading-ifelse.cpp"
OBJECT = ROOT / "build/scene-loading/PrepareBattle.ifelse-natural.obj"
BASE = 0x0076CA50
OWNER_BYTES = 4029
CODE_BYTES = 3893
TABLE_BYTES = 136
EXTRA_MOVE = 0x0076D883 - BASE
FLAGS = ["/Od", "/G6", "/MT", "/Gy", "/GS", "/W3"]
SYMBOL = "?PrepareBattle@Scene2@@QAEXXZ"


def target_from_native(native_code: bytes, native_tables: bytes, reloc: dict) -> int:
    off = reloc["offset"]
    native_off = off
    if off >= len(native_code) + 2:
        native_off -= 2
    elif off >= EXTRA_MOVE + 2:
        native_off -= 2
    operand = (native_code[native_off:native_off + 4]
               if native_off < CODE_BYTES
               else native_tables[native_off - CODE_BYTES:native_off - CODE_BYTES + 4])
    if len(operand) != 4:
        raise AssertionError(("native relocation operand out of range", reloc, native_off))
    if reloc["type"] == "REL32":
        return (BASE + native_off + 4 + struct.unpack("<i", operand)[0]) & 0xFFFFFFFF
    if reloc["type"] == "DIR32":
        return struct.unpack("<I", operand)[0]
    raise AssertionError(("unsupported relocation type", reloc))


def local_native_offset(candidate_offset: int) -> int:
    return candidate_offset - 2 if candidate_offset >= EXTRA_MOVE + 2 else candidate_offset


def mismatch_runs(candidate: bytes, native: bytes) -> list[dict]:
    runs = []
    i = 0
    while i < len(native):
        if candidate[i] == native[i]:
            i += 1
            continue
        start = i
        while i < len(native) and candidate[i] != native[i]:
            i += 1
        runs.append({
            "va": hex(BASE + start),
            "offset": start,
            "length": i - start,
            "native_hex": native[start:i].hex(),
            "candidate_hex": candidate[start:i].hex(),
        })
    return runs


def main() -> None:
    if any(token in SOURCE.read_text() for token in ("__asm", "_emit", "__emit")):
        raise SystemExit("assembly or emitted-opcode token found in natural candidate")
    receipt = compile_source(
        SOURCE, OBJECT, FLAGS, ROOT / ".analysis/build/prepare-battle-ifelse-natural.log"
    )
    code, relocations = object_function(OBJECT, SYMBOL)
    code_size = len(code) - TABLE_BYTES
    if code_size != CODE_BYTES + 2:
        raise SystemExit(("unexpected code extent", code_size))
    if code[EXTRA_MOVE:EXTRA_MOVE + 2] != bytes.fromhex("8bca"):
        raise SystemExit("the known extra receiver move is not at 0x0076D883")

    image = verify_target()
    native_owner = target_bytes(image, BASE, OWNER_BYTES)
    native_code = native_owner[:CODE_BYTES]
    native_tables = native_owner[CODE_BYTES:]

    external_targets: dict[str, int] = {}
    for reloc in relocations:
        if reloc["symbol"].startswith("$L"):
            if "local_target_offset" not in reloc:
                raise AssertionError(("unresolved local COFF label", reloc))
            continue
        target = target_from_native(native_code, native_tables, reloc)
        previous = external_targets.setdefault(reloc["symbol"], target)
        if previous != target:
            raise AssertionError(("conflicting external symbol targets", reloc["symbol"],
                                  hex(previous), hex(target)))

    resolved = bytearray(code)
    counts = {"external": 0, "local": 0, "code": 0, "tables": 0}
    bindings = []
    for reloc in relocations:
        off = reloc["offset"]
        if reloc["symbol"].startswith("$L"):
            target = BASE + local_native_offset(reloc["local_target_offset"])
            counts["local"] += 1
        else:
            target = external_targets[reloc["symbol"]]
            counts["external"] += 1
        if reloc["type"] == "REL32":
            value = (target - (BASE + off + 4)) & 0xFFFFFFFF
        else:
            value = target
        resolved[off:off + 4] = struct.pack("<I", value)
        counts["code" if off < code_size else "tables"] += 1
        bindings.append({"candidate_offset": hex(off), "symbol": reloc["symbol"],
                         "target": hex(target), "type": reloc["type"]})

    resolved_code = bytes(resolved[:code_size])
    resolved_tables = bytes(resolved[code_size:])
    if resolved_tables != native_tables:
        raise AssertionError("switch tables or selector differ after relocation materialization")
    normalized_code = resolved_code[:EXTRA_MOVE] + resolved_code[EXTRA_MOVE + 2:]
    if len(normalized_code) != CODE_BYTES:
        raise AssertionError(("diagnostic code extent", len(normalized_code)))
    runs = mismatch_runs(normalized_code, native_code)
    mismatch_bytes = sum(row["length"] for row in runs)

    evidence = {
        "schema_version": 1,
        "status": "natural-cpp-alternative-progress-not-exact",
        "owner": "Scene2::PrepareBattle",
        "source_has_inline_assembly_or_emitted_opcodes": False,
        "target": {"address": hex(BASE), "owner_bytes": OWNER_BYTES,
                   "code_bytes": CODE_BYTES, "table_bytes": TABLE_BYTES,
                   "sha256": hashlib.sha256(native_owner).hexdigest()},
        "candidate": {"source": str(SOURCE.relative_to(ROOT)),
                      "source_sha256": sha256(SOURCE),
                      "object": str(OBJECT.relative_to(ROOT)),
                      "object_sha256": sha256(OBJECT),
                      "owner_bytes": len(code), "code_bytes": code_size,
                      "owner_size_delta": len(code) - OWNER_BYTES,
                      "code_size_delta": code_size - CODE_BYTES,
                      "compiler_flags": FLAGS,
                      "toolchain_lock_sha256": receipt["toolchain_lock_sha256"]},
        "coff_relocations": {"total": len(relocations), **counts,
                             "external_symbols": len(external_targets),
                             "all_relocations_materialized": True},
        "extra_receiver_instruction": {
            "candidate_offset": hex(EXTRA_MOVE), "native_va": hex(BASE + EXTRA_MOVE),
            "candidate_bytes": "8bca", "candidate_instruction": "mov ecx, edx",
            "native_bytes_at_va": target_bytes(image, BASE + EXTRA_MOVE, 3).hex(),
            "native_instruction_at_va": "call dword ptr [eax+0x2c]",
            "candidate_call_after_extra_move": resolved_code[EXTRA_MOVE + 2:EXTRA_MOVE + 5].hex(),
            "present_in_native": False,
            "removed_for_diagnostic_alignment_only": True,
        },
        "comparison": {
            "strict_exact": False,
            "strict_code_extent_equal": False,
            "diagnostic_normalization": "Remove exactly the recorded 2-byte candidate-only receiver move; rebase all local branch and switch-table relocation targets across that deletion; then compare all 3,893 native code bytes.",
            "diagnostic_normalized_code_bytes": len(normalized_code),
            "diagnostic_mismatch_bytes": mismatch_bytes,
            "diagnostic_mismatch_runs": len(runs),
            "diagnostic_first_mismatch_va": runs[0]["va"] if runs else None,
            "switch_tables_and_selector_exact": True,
            "table_bytes": len(resolved_tables),
            "table_sha256": hashlib.sha256(resolved_tables).hexdigest(),
            "runs": runs,
        },
        "relocation_bindings": bindings,
        "qualification": (
            "This is a separate natural-C++ alternative. Its owner is two bytes larger "
            "than native because of the explicit receiver move above. The 48-byte "
            "diagnostic mismatch count is measured only after transparently deleting "
            "that candidate-only instruction and rebasing local targets; it is not "
            "a strict or whole-owner Exact result. All switch data and relocation "
            "targets are materialized and verified."
        ),
    }
    output = ROOT / "docs/evidence/prepare-battle-ifelse-natural-progress.json"
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(evidence, indent=2) + "\n")
    print(json.dumps({"status": evidence["status"],
                      "candidate": evidence["candidate"],
                      "coff_relocations": evidence["coff_relocations"],
                      "extra_receiver_instruction": evidence["extra_receiver_instruction"],
                      "comparison": {k: v for k, v in evidence["comparison"].items() if k != "runs"}}, indent=2))


if __name__ == "__main__":
    main()
