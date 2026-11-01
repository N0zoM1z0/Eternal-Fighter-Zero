#!/usr/bin/env python3
"""Import an operator-supplied executable after checking its locked identity."""
import argparse
from pathlib import Path
import shutil
from common import ROOT, verify_target

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("source", type=Path)
args = parser.parse_args()
try:
    verify_target(args.source)
    destination = ROOT / "resources/EFZ.exe"
    if destination.exists():
        verify_target(destination)
    else:
        destination.parent.mkdir(exist_ok=True)
        shutil.copyfile(args.source, destination)
    destination.chmod(0o444)
except (OSError, ValueError, KeyError) as error:
    parser.exit(1, f"target import failed: {error}\n")
print("Imported verified, read-only resources/EFZ.exe")
