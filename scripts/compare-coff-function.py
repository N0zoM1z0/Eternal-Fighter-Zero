#!/usr/bin/env python3
"""Compare a complete manifest-bound COFF function, or list diagnostic symbols."""
import argparse
import json
from pathlib import Path
from coff import object_functions
from oracle import compare_unit

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--unit")
parser.add_argument("--list-functions", type=Path, metavar="OBJECT")
args = parser.parse_args()
if bool(args.unit) == bool(args.list_functions):
    parser.error("select exactly one of --unit or --list-functions OBJECT")
try:
    report = compare_unit(args.unit) if args.unit else dict(result="inventory", acceptance_authority="none", functions=object_functions(args.list_functions))
except (OSError, ValueError, KeyError) as error:
    parser.exit(1, f"comparison failed: {error}\n")
print(json.dumps(report, indent=2))
raise SystemExit(0 if report["result"] in {"inventory", "exact"} else 1)
