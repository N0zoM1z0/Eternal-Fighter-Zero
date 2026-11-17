#!/usr/bin/env python3
"""Selected, original-bound comparison of the provisional Scene9::Step C++.

This is deliberately NOT an Exact acceptance tool: the full native owner is
larger than the candidate and internal jump displacements diverge. Never mask
bytes or claim the prefix as a complete matched function.
"""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import target_bytes, verify_target
from coff import object_function
from native_build import compile_source

SOURCE = ROOT / "workbench/scene9-step/Scene9Step.cpp"
OBJECT = ROOT / "build/scene9-step/Scene9Step.obj"
BASE = 0x007714E0
OWNER_BYTES = 4896
SYMBOL = "?Step@Scene9@@UAEEXZ"
FLAGS = ["/Od", "/G6", "/MT", "/Gy", "/GS", "/W3"]


def main() -> None:
    text = SOURCE.read_text()
    if any(token in text for token in ("__asm", "_emit", "__emit")):
        raise SystemExit("not a natural-C++ candidate")
    compile_source(SOURCE, OBJECT, FLAGS, ROOT / ".analysis/build/scene9-step.log")
    generated, relocs = object_function(OBJECT, SYMBOL)
    native = target_bytes(verify_target(), BASE, OWNER_BYTES)
    # Diagnostic alignment only: replace each true COFF operand with native
    # bytes at the same position. This cannot turn a wrong-sized owner Exact.
    diagnostic = bytearray(generated)
    for r in relocs:
        off = r["offset"]
        diagnostic[off:off + 4] = native[off:off + 4]
    prefix = next((i for i, (a, b) in enumerate(zip(diagnostic, native))
                   if a != b), min(len(generated), len(native)))
    result = {
        "status": "natural-cpp-workbench-not-exact",
        "native_address": hex(BASE),
        "native_bytes": len(native),
        "native_sha256": hashlib.sha256(native).hexdigest(),
        "candidate_bytes": len(generated),
        "candidate_sha256": hashlib.sha256(generated).hexdigest(),
        "size_deficit": len(native) - len(generated),
        "candidate_coff_relocations": len(relocs),
        "native_frame_size": int.from_bytes(native[5:9], "little"),
        "candidate_frame_size": int.from_bytes(generated[5:9], "little"),
        "initial_position_aligned_bytes_excluding_coff_operands": prefix,
        "first_position_mismatch_va": hex(BASE + prefix),
        "strict_exact": False,
        "qualification": "Complete owner is not matched. Prefix excludes actual COFF operand bytes for diagnostic alignment only, and the first subsequent discrepancy is in a long-jump displacement. No padding, ASM, byte patches, ledger credit or cold replay.",
    }
    print(json.dumps(result, indent=2))
    # Provisional candidates can grow/shrink and change their stack layout while
    # recovering missing native logic. Report this honestly, not as a failure.
    # Only fail on a lost natural function or an invalid native PE boundary.
    if len(generated) < 1000 or generated[:3] != native[:3]:
        raise SystemExit("candidate is no longer the native Scene9 function shape")


if __name__ == "__main__":
    main()
