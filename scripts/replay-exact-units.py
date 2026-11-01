#!/usr/bin/env python3
"""Cold-build and compare only explicitly selected exact units."""
import argparse
import importlib.util
import json
from common import ROOT
from oracle import compare_unit

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--unit", action="append", required=True)
args = parser.parse_args()
spec = importlib.util.spec_from_file_location("build_unit", ROOT / "scripts/build-match-unit.py")
builder = importlib.util.module_from_spec(spec)
spec.loader.exec_module(builder)
reports = []
try:
    for name in args.unit:
        builder.build_unit(name)
        report = compare_unit(name)
        output = ROOT / ".analysis/exact" / (name + ".json")
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(report, indent=2) + "\n")
        reports.append(report)
except (OSError, ValueError, KeyError, TimeoutError) as error:
    parser.exit(1, f"exact replay failed: {error}\n")
print(json.dumps(reports, indent=2))
raise SystemExit(0 if all(r["result"] == "exact" for r in reports) else 1)
