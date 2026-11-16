#!/usr/bin/env python3
"""Rebuild and relocation-bind the natural-C++ PrepareBattle candidate.

This is a deliberately scoped comparison: it builds only SceneLoading.cpp
once with the retained default-first scale expression and once with the
previous if/else expression. The latter is used only to recover canonical
external symbol destinations because it has one extra two-byte receiver
copy in its first LoadResources dispatch.
"""
from __future__ import annotations

import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))

from common import ROOT as REPO_ROOT, sha256, target_bytes, verify_target
from coff import object_function
from native_build import compile_source

assert ROOT == REPO_ROOT

SOURCE = ROOT / "workbench/prepare-battle/SceneLoading.cpp"
BASELINE_OBJECT = ROOT / "build/scene-loading/PrepareBattle.ifelse-comparison.obj"
CANDIDATE_OBJECT = ROOT / "build/scene-loading/PrepareBattle.default-first-comparison.obj"
EVIDENCE = ROOT / "docs/evidence/prepare-battle-natural-cpp-progress-v2.json"
LOG_DIR = ROOT / ".analysis/build"
FLAGS = ["/Od", "/G6", "/MT", "/Gy", "/GS", "/W3"]
BASE = 0x0076CA50
OWNER_SIZE = 4029
CODE_SIZE = 3893
TABLE_SIZE = 136
EXTRA_MOVE_VA = 0x0076D883

DEFAULT_FIRST = """            contextOwner->backgroundScale = 1.0;
            if (contextOwner->flag0f32 == 16) contextOwner->backgroundScale = 0.125;
"""
IF_ELSE = """            if (contextOwner->flag0f32 == 16) contextOwner->backgroundScale = 0.125;
            else contextOwner->backgroundScale = 1.0;
"""


def relocation_value(target: int, offset: int, kind: str) -> bytes:
    if kind == "REL32":
        value = (target - (BASE + offset + 4)) & 0xFFFFFFFF
    elif kind == "DIR32":
        value = target
    else:
        raise AssertionError(f"unsupported COFF relocation type: {kind}")
    return struct.pack("<I", value)


def mismatch_runs(candidate: bytes, native: bytes) -> list[dict[str, object]]:
    runs: list[dict[str, object]] = []
    i = 0
    while i < len(native):
        if candidate[i] == native[i]:
            i += 1
            continue
        start = i
        while i < len(native) and candidate[i] != native[i]:
            i += 1
        runs.append({
            "start_offset": start,
            "end_offset": i,
            "va": hex(BASE + start),
            "length": i - start,
            "native_hex": native[start:i].hex(),
            "candidate_hex": candidate[start:i].hex(),
        })
    return runs


def main() -> None:
    source_text = SOURCE.read_text()
    if source_text.count(DEFAULT_FIRST) != 1 or IF_ELSE in source_text:
        raise SystemExit("tracked source is not the retained default-first candidate")

    LOG_DIR.mkdir(parents=True, exist_ok=True)
    baseline_text = source_text.replace(DEFAULT_FIRST, IF_ELSE)
    SOURCE.write_text(baseline_text)
    try:
        baseline_receipt = compile_source(
            SOURCE, BASELINE_OBJECT, FLAGS,
            LOG_DIR / "prepare-battle-ifelse-comparison.log",
        )
    finally:
        SOURCE.write_text(source_text)

    candidate_receipt = compile_source(
        SOURCE, CANDIDATE_OBJECT, FLAGS,
        LOG_DIR / "prepare-battle-default-first-comparison.log",
    )

    baseline, baseline_relocs = object_function(
        BASELINE_OBJECT, "?PrepareBattle@Scene2@@QAEXXZ"
    )
    candidate, candidate_relocs = object_function(
        CANDIDATE_OBJECT, "?PrepareBattle@Scene2@@QAEXXZ"
    )
    if len(baseline) - TABLE_SIZE != CODE_SIZE + 2:
        raise SystemExit("if/else baseline no longer has the known two-byte extent delta")
    if len(candidate) != OWNER_SIZE or len(candidate) - TABLE_SIZE != CODE_SIZE:
        raise SystemExit("candidate owner/code extent changed")
    extra = EXTRA_MOVE_VA - BASE
    if baseline[extra:extra + 2] != bytes.fromhex("8bca"):
        raise SystemExit("expected baseline mov ecx,edx at 0x0076D883 was not found")
    if len(baseline_relocs) != 115 or len(candidate_relocs) != 115:
        raise SystemExit("unexpected relocation count")

    image = verify_target()
    native_owner = target_bytes(image, BASE, OWNER_SIZE)
    native_code = native_owner[:CODE_SIZE]
    native_tables = native_owner[CODE_SIZE:]

    # Recover canonical destinations for non-local symbols from the baseline
    # object's original-linked operands. Shift code operands after the extra
    # two-byte instruction back by two; the appended table is likewise shifted.
    external_targets: dict[str, int] = {}
    for reloc in baseline_relocs:
        off = reloc["offset"]
        native_off = off if off < len(baseline) - TABLE_SIZE else off - 2
        if off < len(baseline) - TABLE_SIZE and off >= extra + 2:
            native_off -= 2
        if native_off < CODE_SIZE:
            operand = native_code[native_off:native_off + 4]
        else:
            table_off = native_off - CODE_SIZE
            operand = native_tables[table_off:table_off + 4]
        if len(operand) != 4:
            raise SystemExit(f"baseline relocation operand out of range: {reloc}")
        if reloc["type"] == "REL32":
            target = (BASE + native_off + 4 + struct.unpack("<i", operand)[0]) & 0xFFFFFFFF
        elif reloc["type"] == "DIR32":
            target = struct.unpack("<I", operand)[0]
        else:
            raise AssertionError(reloc)
        if not reloc["symbol"].startswith("$L"):
            prior = external_targets.setdefault(reloc["symbol"], target)
            if prior != target:
                raise SystemExit(f"conflicting baseline target for {reloc['symbol']}")

    resolved = bytearray(candidate)
    counts = {"external": 0, "local": 0, "code": 0, "tables": 0}
    for reloc in candidate_relocs:
        off = reloc["offset"]
        symbol = reloc["symbol"]
        if symbol.startswith("$L"):
            if "local_target_offset" not in reloc:
                raise SystemExit(f"local COFF target missing: {reloc}")
            target = BASE + reloc["local_target_offset"]
            counts["local"] += 1
        else:
            if symbol not in external_targets:
                raise SystemExit(f"no canonical external target for {symbol}")
            target = external_targets[symbol]
            counts["external"] += 1
        resolved[off:off + 4] = relocation_value(target, off, reloc["type"])
        counts["code" if off < CODE_SIZE else "tables"] += 1

    resolved_code = bytes(resolved[:CODE_SIZE])
    resolved_tables = bytes(resolved[CODE_SIZE:])
    runs = mismatch_runs(resolved_code, native_code)
    mismatch_bytes = sum(int(run["length"]) for run in runs)
    if counts != {"external": 82, "local": 33, "code": 85, "tables": 30}:
        raise SystemExit(f"unexpected relocation classification: {counts}")
    if resolved_tables != native_tables:
        raise SystemExit("switch tables/selector differ after relocation binding")
    if (mismatch_bytes, len(runs), runs[0]["va"]) != (87, 37, "0x76d744"):
        raise SystemExit("candidate mismatch signature changed; review before updating evidence")
    if any(token in source_text for token in ("__asm", "_emit", "__emit")):
        raise SystemExit("assembly or emitted opcode token found in source")

    evidence = {
        "schema_version": 1,
        "status": "natural-cpp-candidate-progress-not-exact",
        "owner": "Scene2::PrepareBattle",
        "target": {
            "address": hex(BASE),
            "owner_bytes": OWNER_SIZE,
            "code_bytes": CODE_SIZE,
            "sha256": hashlib.sha256(native_owner).hexdigest(),
        },
        "candidate": {
            "source": str(SOURCE.relative_to(ROOT)),
            "source_sha256": sha256(SOURCE),
            "object": str(CANDIDATE_OBJECT.relative_to(ROOT)),
            "object_sha256": sha256(CANDIDATE_OBJECT),
            "owner_bytes": len(candidate),
            "code_bytes": CODE_SIZE,
            "code_size_delta": 0,
            "compiler_flags": FLAGS,
            "toolchain_lock_sha256": candidate_receipt["toolchain_lock_sha256"],
        },
        "baseline": {
            "object": str(BASELINE_OBJECT.relative_to(ROOT)),
            "object_sha256": sha256(BASELINE_OBJECT),
            "code_bytes": CODE_SIZE + 2,
            "extra_receiver_move_va": hex(EXTRA_MOVE_VA),
            "compiler_flags": FLAGS,
        },
        "coff_relocations": {
            "total": len(candidate_relocs),
            **counts,
            "all_candidate_relocations_resolved": True,
        },
        "comparison": {
            "method": (
                "Materialize all candidate COFF relocations. External symbol targets "
                "are resolved from the previous natural-C++ if/else object against "
                "canonical target operands, accounting for its known two-byte receiver "
                "move; compiler-local labels use candidate COFF target offsets. Compare "
                "all 3,893 code bytes and all 136 table bytes against the canonical PE."
            ),
            "mismatch_bytes": mismatch_bytes,
            "mismatch_runs": len(runs),
            "first_mismatch_va": runs[0]["va"],
            "strict_exact": False,
            "switch_tables_and_selector_exact": True,
            "table_bytes": len(resolved_tables),
            "table_sha256": hashlib.sha256(resolved_tables).hexdigest(),
            "runs": runs,
        },
        "source_has_inline_assembly": False,
        "qualification": (
            "Natural-C++ candidate has the exact original owner and code extents. "
            "Both switch tables and selector are exact after relocation materialization. "
            "The code still differs at 87 bytes in 37 runs; this is progress evidence, "
            "not a codegen Exact certificate."
        ),
        "improvement_from_previous_candidate": {
            "previous_code_bytes": 3895,
            "previous_owner_bytes": 4031,
            "previous_relocation_aware_code_mismatch_bytes": 269,
            "previous_mismatch_runs": 64,
            "current_code_bytes": 3893,
            "current_owner_bytes": 4029,
            "current_relocation_aware_code_mismatch_bytes": mismatch_bytes,
            "current_mismatch_runs": len(runs),
            "owner_extent_gap_closed": True,
            "mismatch_bytes_reduced_by": 182,
        },
    }
    EVIDENCE.write_text(json.dumps(evidence, indent=2) + "\n")
    print(json.dumps({
        "candidate": evidence["candidate"],
        "coff_relocations": evidence["coff_relocations"],
        "comparison": {
            key: value for key, value in evidence["comparison"].items()
            if key != "runs"
        },
    }, indent=2))


if __name__ == "__main__":
    main()
