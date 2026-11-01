#!/usr/bin/env python3
"""Build one explicit normal-COFF recipe; no complete product is implied."""
import argparse
import json
from common import ROOT, load_toml, load_units, record_digest, sha256, verify_target
from native_build import compile_source, verify_toolchain


def build_unit(name: str) -> dict:
    verify_target()
    verify_toolchain()
    unit = load_units()[name]
    profile = load_toml(ROOT / "config/build.toml")["profiles"][unit["profile"]]
    if profile["artifact_kind"] != "coff" or unit["artifact_kind"] != "coff":
        raise ValueError("only complete normal-COFF functions are supported")
    source = ROOT / unit["source"]
    receipt = compile_source(source, ROOT / unit["object"], profile["flags"],
                             ROOT / ".analysis/build" / (name + ".log"))
    receipt.update(unit=name, profile=unit["profile"],
                   unit_sha256=record_digest(unit), profile_sha256=record_digest(profile),
                   build_manifest_sha256=sha256(ROOT / "config/build.toml"),
                   units_manifest_sha256=sha256(ROOT / "config/match-units.toml"),
                   dependencies={p: sha256(ROOT / p) for p in unit.get("dependencies", [])})
    (ROOT / unit["object"]).with_suffix(".build.json").write_text(json.dumps(receipt, indent=2) + "\n")
    return receipt


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--unit", required=True)
    args = parser.parse_args()
    try:
        print(json.dumps(build_unit(args.unit), indent=2))
    except (OSError, ValueError, KeyError, TimeoutError) as error:
        parser.exit(1, f"build failed: {error}\n")
