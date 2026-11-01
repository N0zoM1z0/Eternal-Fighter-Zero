#!/usr/bin/env python3
import argparse
from common import verify_target
from tracking import validate

parser = argparse.ArgumentParser(description="Validate independent EFZ progress ledgers")
parser.add_argument("--require-target", action="store_true")
args = parser.parse_args()
try:
    validate()
    if args.require_target:
        verify_target()
except (OSError, ValueError, KeyError) as error:
    parser.exit(1, f"tracking validation failed: {error}\n")
print("tracking ledgers OK")
