"""Independent candidate, boundary, origin, source and exact ledgers."""
import csv
import json
from common import ROOT, contribution_layout, load_toml, load_units, number, record_digest, sha256


def rows(name: str) -> list[dict]:
    with (ROOT / "config" / name).open(newline="") as stream:
        return list(csv.DictReader(stream))


def summary() -> dict:
    boundaries = rows("function-boundaries.csv")
    exact = rows("matches.csv")
    units = load_units()
    code_bytes = sum(contribution_layout(units[r["unit"]])[0] for r in exact)
    return dict(candidate_functions=len(rows("functions.csv")),
                reviewed_boundaries=sum(r["status"] == "reviewed" for r in boundaries),
                reviewed_origins=sum(r["status"] == "reviewed" for r in rows("function-origins.csv")),
                source_functions=len(rows("implemented.csv")), exact_functions=len(exact),
                exact_bytes=code_bytes,
                exact_local_data_bytes=sum(number(r["size"]) for r in exact) - code_bytes,
                whole_product="open", runtime_validation="open", portability="not started")


def validate(*, check_proofs: bool = False, proof_units: set[str] | None = None) -> None:
    units = load_units()
    profiles = load_toml(ROOT / "config/build.toml")["profiles"]
    toolchain_hash = sha256(ROOT / "config/tools.lock.toml")
    source_hashes = {}
    certificates = {}
    if proof_units is not None and (unknown := proof_units - units.keys()):
        raise ValueError(f"unknown proof units: {sorted(unknown)}")
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
        for source in [unit["source"], *unit.get("dependencies", [])]:
            if not (ROOT / source).is_file():
                raise ValueError(f"missing source/dependency for {name}: {source}")
        (ROOT / unit["object"]).resolve().relative_to((ROOT / "build").resolve())
        profile = profiles[unit["profile"]]
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
        if match["target_sha256"] != canonical:
            raise ValueError("exact claim is bound to another target")
        for key in ("source_sha256", "unit_sha256", "profile_sha256",
                    "toolchain_lock_sha256", "target_extent_sha256"):
            digest = match[key]
            if len(digest) != 64 or any(c not in "0123456789abcdef" for c in digest):
                raise ValueError(f"invalid exact ledger digest: {name}: {key}")
        if not match["evidence"] or len(match["target_extent_sha256"]) != 64:
            raise ValueError("exact claim lacks comparison evidence")
        proof_path = (ROOT / match["evidence"]).resolve()
        proof_path.relative_to((ROOT / "docs/evidence").resolve())
        if not proof_path.is_file():
            raise ValueError(f"missing comparison certificate: {proof_path}")
        claimed.append((address, address + unit["size"]))
        if not check_proofs or (proof_units is not None and name not in proof_units):
            continue
        source = unit["source"]
        if source not in source_hashes:
            source_hashes[source] = sha256(ROOT / source)
        for key, expected in [("target_sha256", canonical), ("source_sha256", source_hashes[source]),
                              ("unit_sha256", record_digest(unit)),
                              ("profile_sha256", record_digest(profiles[unit["profile"]])),
                              ("toolchain_lock_sha256", toolchain_hash)]:
            if match[key] != expected:
                raise ValueError(f"stale exact ledger {name}: {key}")
        if proof_path not in certificates:
            certificates[proof_path] = json.loads(proof_path.read_text())["reports"]
        reports = [r for r in certificates[proof_path] if r["unit"] == name]
        if len(reports) != 1:
            raise ValueError("exact ledger lacks one public comparison certificate")
        proof = reports[0]
        code_size, tables = contribution_layout(unit)
        if (proof.get("code_size", proof["size"]) != code_size
                or proof.get("local_data", []) != tables
                or proof.get("local_data_bytes", 0) != unit["size"] - code_size):
            raise ValueError("public comparison certificate has different contribution attribution")
        if (proof["result"] != "exact" or proof["difference_count"] != 0
                or proof["size"] != unit["size"] or proof["matched_bytes"] != unit["size"]
                or number(proof["target_address"]) != address):
            raise ValueError("public comparison certificate is not complete/exact")
        for key in ["target_sha256", "source_sha256", "unit_sha256", "profile_sha256", "toolchain_lock_sha256", "target_extent_sha256"]:
            if proof[key] != match[key]:
                raise ValueError(f"public comparison certificate differs: {key}")
        if proof["dependencies"] != {p: sha256(ROOT / p) for p in unit.get("dependencies", [])}:
            raise ValueError("public comparison certificate has stale source dependencies")
    if proof_units is not None and (unclaimed := proof_units - seen_units):
        raise ValueError(f"units have no exact ledger claim: {sorted(unclaimed)}")
    claimed.sort()
    if any(a[1] > b[0] for a, b in zip(claimed, claimed[1:])):
        raise ValueError("exact claims overlap")
