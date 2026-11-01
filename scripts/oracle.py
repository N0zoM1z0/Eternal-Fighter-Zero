"""Strict complete-function oracle; relocations are bound, never masked."""
from __future__ import annotations

import csv
import hashlib
import json
from pathlib import Path
import struct

from common import ROOT, contribution_layout, load_toml, load_units, number, record_digest, sha256, target_bytes, verify_target
from coff import RELOCATION_IDS, object_function


def replay_relocations(code: bytes, actual: list[dict], declared: list[dict], address: int) -> tuple[bytes, list[dict]]:
    expected = []
    occupied: set[int] = set()
    bindings: dict[str, int] = {}
    for row in declared:
        if row["type"] not in RELOCATION_IDS:
            raise ValueError("unsupported relocation type")
        offset = number(row["offset"])
        target = number(row["target"])
        symbol = row["symbol"]
        if not symbol or (symbol in bindings and bindings[symbol] != target):
            raise ValueError("one COFF symbol cannot bind to inconsistent destinations")
        bindings[symbol] = target
        if not 0 <= target <= 0xFFFFFFFF or offset < 0 or offset + 4 > len(code):
            raise ValueError("relocation target/field outside valid extent")
        field = set(range(offset, offset + 4))
        if field & occupied:
            raise ValueError("duplicate/overlapping relocation fields")
        occupied.update(field)
        if not row.get("evidence"):
            raise ValueError("relocation binding requires explicit evidence")
        expected.append(dict(offset=offset, target=target, type=row["type"],
                             type_id=RELOCATION_IDS[row["type"]], symbol=row["symbol"],
                             evidence=row["evidence"]))
    keys = lambda rows: sorted((r["offset"], r["type_id"], r["symbol"]) for r in rows)
    if keys(actual) != keys(expected):
        raise ValueError(f"COFF relocation inventory differs: {keys(actual)!r} != {keys(expected)!r}")
    observed = {r["offset"]: r for r in actual}
    for row in expected:
        local_offset = observed[row["offset"]].get("local_target_offset")
        if local_offset is not None:
            if row["target"] != address + local_offset:
                raise ValueError("internal COFF symbol binding differs from its compiled offset")
            row["local_target_offset"] = local_offset
    relocated = bytearray(code)
    for row in expected:
        offset = row["offset"]
        addend = struct.unpack_from("<I", code, offset)[0]
        value = row["target"] + addend
        if row["type"] == "REL32":
            value -= address + offset + 4
        struct.pack_into("<I", relocated, offset, value & 0xFFFFFFFF)
        row["addend"] = addend
    return bytes(relocated), expected


def complete_compare(code: bytes, original: bytes, actual: list[dict], declared: list[dict], address: int) -> dict:
    if not code or len(code) != len(original):
        raise ValueError("complete object and target extents must have identical positive sizes")
    relocated, relocations = replay_relocations(code, actual, declared, address)
    differences = [dict(offset=i, object=a, target=b) for i, (a, b) in enumerate(zip(relocated, original)) if a != b]
    return dict(result="exact" if not differences else "mismatch", size=len(code),
                matched_bytes=len(code) - len(differences), difference_count=len(differences),
                first_differences=differences[:32], relocations=relocations,
                relocated_sha256=hashlib.sha256(relocated).hexdigest(),
                target_extent_sha256=hashlib.sha256(original).hexdigest())


def verify_boundary(unit: dict) -> None:
    with (ROOT / "config/function-boundaries.csv").open(newline="") as stream:
        boundaries = list(csv.DictReader(stream))
    rows = [r for r in boundaries if number(r["address"]) == number(unit["target_address"])]
    if len(rows) != 1 or rows[0]["status"] != "reviewed" or number(rows[0]["size"]) != unit["size"]:
        raise ValueError("unit does not have one reviewed complete target boundary")
    if number(rows[0]["end"]) != number(unit["target_address"]) + unit["size"]:
        raise ValueError("reviewed boundary end/size disagree")
    if not rows[0]["evidence"]:
        raise ValueError("reviewed boundary lacks evidence")


def verify_receipt(name: str, unit: dict, object_path: Path) -> dict:
    receipt = json.loads(object_path.with_suffix(".build.json").read_text())
    if receipt["unit"] != name or receipt["source"] != unit["source"] or receipt["object"] != unit["object"]:
        raise ValueError("build receipt identity differs from match unit")
    for key, path in [("object_sha256", object_path), ("source_sha256", ROOT / unit["source"]),
                      ("toolchain_lock_sha256", ROOT / "config/tools.lock.toml")]:
        if receipt[key] != sha256(path):
            raise ValueError(f"stale/mismatched build receipt: {key}")
    dependencies = {p: sha256(ROOT / p) for p in unit.get("dependencies", [])}
    if receipt["dependencies"] != dependencies:
        raise ValueError("stale source dependency identity")
    profile = load_toml(ROOT / "config/build.toml")["profiles"][unit["profile"]]
    if receipt["unit_sha256"] != record_digest(unit) or receipt["profile_sha256"] != record_digest(profile):
        raise ValueError("stale selected unit/profile recipe")
    if receipt["profile"] != unit["profile"] or receipt["flags"] != profile["flags"]:
        raise ValueError("build receipt profile/flags differ")
    if profile["artifact_kind"] != "coff":
        raise ValueError("unsupported profile artifact kind")
    compiler_lock = load_toml(ROOT / "config/tools.lock.toml")["files"]["Vc7/bin/cl.exe"]
    if receipt["compiler_sha256"] != compiler_lock:
        raise ValueError("build receipt compiler identity differs")
    return receipt


def compare_unit(name: str) -> dict:
    original = verify_target()
    unit = load_units()[name]
    if unit["artifact_kind"] != "coff" or "compare_size" in unit:
        raise ValueError("only complete normal COFF extents are accepted")
    verify_boundary(unit)
    path = (ROOT / unit["object"]).resolve()
    path.relative_to((ROOT / "build").resolve())
    receipt = verify_receipt(name, unit, path)
    code, relocations = object_function(path, unit["symbol"])
    address = number(unit["target_address"])
    report = complete_compare(code, target_bytes(original, address, unit["size"]),
                              relocations, unit.get("relocations", []), address)
    code_size, tables = contribution_layout(unit)
    if tables:
        report.update(code_size=code_size, local_data_bytes=unit["size"] - code_size,
                      local_data=tables)
    report.update(unit=name, symbol=unit["symbol"], target_address=f"0x{address:08X}",
                  target_sha256=hashlib.sha256(original).hexdigest(),
                  boundary_ledger_sha256=sha256(ROOT / "config/function-boundaries.csv"),
                  object_sha256=sha256(path), source_sha256=receipt["source_sha256"],
                  dependencies=receipt["dependencies"],
                  toolchain_lock_sha256=receipt["toolchain_lock_sha256"],
                  units_manifest_sha256=receipt["units_manifest_sha256"],
                  build_manifest_sha256=receipt["build_manifest_sha256"],
                  unit_sha256=receipt["unit_sha256"], profile_sha256=receipt["profile_sha256"],
                  acceptance_authority="complete-function-codegen" if report["result"] == "exact" else "none")
    return report
