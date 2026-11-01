"""Independent candidate, boundary, origin, source and exact ledgers."""
import csv
import json
from common import ROOT, load_toml, load_units, number, record_digest, sha256


def rows(name: str) -> list[dict]:
    with (ROOT / "config" / name).open(newline="") as stream:
        return list(csv.DictReader(stream))


def summary() -> dict:
    boundaries = rows("function-boundaries.csv")
    exact = rows("matches.csv")
    return dict(candidate_functions=len(rows("functions.csv")),
                reviewed_boundaries=sum(r["status"] == "reviewed" for r in boundaries),
                reviewed_origins=sum(r["status"] == "reviewed" for r in rows("function-origins.csv")),
                source_functions=len(rows("implemented.csv")), exact_functions=len(exact),
                exact_bytes=sum(number(r["size"]) for r in exact),
                whole_product="open", runtime_validation="open", portability="not started")


def validate() -> None:
    units = load_units()
    canonical = load_toml(ROOT / "config/target.toml")["target"]["sha256"]
    boundaries = {number(r["address"]): r for r in rows("function-boundaries.csv")}
    origins = {number(r["address"]): r for r in rows("function-origins.csv")}
    implemented = {number(r["address"]): r for r in rows("implemented.csv")}
    candidate_addresses = [number(r["address"]) for r in rows("functions.csv")]
    if len(set(candidate_addresses)) != len(candidate_addresses):
        raise ValueError("duplicate candidate addresses")
    for ledger, mapping in [("function-boundaries.csv", boundaries), ("function-origins.csv", origins), ("implemented.csv", implemented)]:
        if len(mapping) != len(rows(ledger)):
            raise ValueError(f"duplicate address in {ledger}")
    for name, unit in units.items():
        if unit["artifact_kind"] != "coff" or "compare_size" in unit or unit["size"] <= 0:
            raise ValueError(f"unsupported/partial match unit {name}")
        if not (ROOT / unit["source"]).is_file():
            raise ValueError(f"missing source for {name}")
        (ROOT / unit["object"]).resolve().relative_to((ROOT / "build").resolve())
        profile = load_toml(ROOT / "config/build.toml")["profiles"][unit["profile"]]
        if profile["artifact_kind"] != "coff":
            raise ValueError("unsupported build profile")
        for binding in unit.get("relocations", []):
            if not binding.get("evidence") or binding["type"] not in {"DIR32", "REL32"}:
                raise ValueError("unproven/unsupported relocation")
    claimed = []
    seen_units = set()
    for match in rows("matches.csv"):
        name = match["unit"]
        if name in seen_units:
            raise ValueError("duplicate exact unit")
        seen_units.add(name)
        unit = units[name]
        if match["source"] != unit["source"] or match["symbol"] != unit["symbol"]:
            raise ValueError("exact ledger source/symbol differs from unit")
        address = number(match["address"])
        if address != number(unit["target_address"]) or number(match["size"]) != unit["size"]:
            raise ValueError("exact extent differs from unit")
        boundary = boundaries[address]
        if (boundary["status"] != "reviewed" or number(boundary["size"]) != unit["size"]
                or number(boundary["end"]) != address + unit["size"]):
            raise ValueError("exact claim lacks reviewed complete boundary")
        if origins[address]["origin"] != "authored" or origins[address]["status"] != "reviewed":
            raise ValueError("exact authored claim lacks reviewed origin")
        if implemented[address]["source"] != unit["source"] or implemented[address]["symbol"] != unit["symbol"]:
            raise ValueError("source ledger differs from exact unit")
        for key, expected in [("target_sha256", canonical), ("source_sha256", sha256(ROOT / unit["source"])),
                              ("unit_sha256", record_digest(unit)),
                              ("profile_sha256", record_digest(load_toml(ROOT / "config/build.toml")["profiles"][unit["profile"]])),
                              ("toolchain_lock_sha256", sha256(ROOT / "config/tools.lock.toml"))]:
            if match[key] != expected:
                raise ValueError(f"stale exact ledger {name}: {key}")
        if not match["evidence"] or len(match["target_extent_sha256"]) != 64:
            raise ValueError("exact claim lacks comparison evidence")
        proof_path = (ROOT / match["evidence"]).resolve()
        proof_path.relative_to((ROOT / "docs/evidence").resolve())
        reports = [r for r in json.loads(proof_path.read_text())["reports"] if r["unit"] == name]
        if len(reports) != 1:
            raise ValueError("exact ledger lacks one public comparison certificate")
        proof = reports[0]
        if (proof["result"] != "exact" or proof["difference_count"] != 0
                or proof["size"] != unit["size"] or proof["matched_bytes"] != unit["size"]
                or number(proof["target_address"]) != address):
            raise ValueError("public comparison certificate is not complete/exact")
        for key in ["target_sha256", "source_sha256", "unit_sha256", "profile_sha256", "toolchain_lock_sha256", "target_extent_sha256"]:
            if proof[key] != match[key]:
                raise ValueError(f"public comparison certificate differs: {key}")
        if proof["dependencies"] != {p: sha256(ROOT / p) for p in unit.get("dependencies", [])}:
            raise ValueError("public comparison certificate has stale source dependencies")
        claimed.append((address, address + unit["size"]))
    claimed.sort()
    if any(a[1] > b[0] for a, b in zip(claimed, claimed[1:])):
        raise ValueError("exact claims overlap")
