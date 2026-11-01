#!/usr/bin/env python3
"""Verify the one canonical EFZ input and its complete PE section mapping."""
import argparse
from pathlib import Path
from common import verify_target

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("path", nargs="?", type=Path)
args = parser.parse_args()
try:
    data = verify_target(args.path)
except (OSError, ValueError, KeyError) as error:
    parser.exit(1, f"target verification failed: {error}\n")
print(f"EFZ target OK: {len(data):,} bytes, SHA-256 and PE mapping verified")
