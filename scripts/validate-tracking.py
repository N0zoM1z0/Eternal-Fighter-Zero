#!/usr/bin/env python3
import argparse
from common import verify_target
from tracking import validate

parser = argparse.ArgumentParser(description="Validate independent EFZ progress ledgers")
parser.add_argument("--require-target", action="store_true")
parser.add_argument("--check-proofs", action="store_true",
                    help="audit historical certificates against current inputs (may be stale)")
parser.add_argument("--unit", action="append", help="limit proof audit to this exact unit; repeatable")
args = parser.parse_args()
if args.unit and not args.check_proofs:
    parser.error("--unit requires --check-proofs")
try:
    validate(check_proofs=args.check_proofs, proof_units=set(args.unit) if args.unit else None)
    if args.require_target:
        verify_target()
except (OSError, ValueError, KeyError) as error:
    parser.exit(1, f"tracking validation failed: {error}\n")
print("tracking ledgers OK")
