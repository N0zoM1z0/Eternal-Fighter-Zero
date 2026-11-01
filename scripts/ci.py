#!/usr/bin/env python3
"""Target-free repository checks; native replay is an explicit separate command."""
import argparse
import ast
import json
import subprocess
import sys
from common import ROOT, load_toml
from tracking import validate


def syntax():
    for path in (ROOT / "scripts").rglob("*.py"):
        ast.parse(path.read_text(), filename=str(path))


def declarations():
    for path in (ROOT / "config").glob("*.toml"):
        load_toml(path)
    lock = json.loads((ROOT / "config/analysis-tools.lock.json").read_text())
    if lock["schema_version"] != 1:
        raise ValueError("unknown analysis lock schema")
    toolchain = load_toml(ROOT / "config/tools.lock.toml")
    if toolchain["msvc71"]["compiler_version"] != "13.10.3077":
        raise ValueError("unexpected compiler declaration")
    for expected in [*toolchain["files"].values(), *toolchain["trees"].values()]:
        if len(expected) != 64 or any(c not in "0123456789abcdef" for c in expected):
            raise ValueError("invalid tool digest")


def command(*args):
    subprocess.run(args, cwd=ROOT, check=True)


def whitespace():
    command("git", "diff", "--check")
    command("git", "diff", "--cached", "--check")


parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--only", choices=["syntax", "declarations", "ledgers", "progress", "oracle", "whitespace"])
args = parser.parse_args()
checks = dict(syntax=syntax, declarations=declarations, ledgers=validate,
              progress=lambda: command(sys.executable, "scripts/progress.py", "--check"),
              oracle=lambda: command(sys.executable, "-m", "unittest", "discover", "-s", "scripts/tests"),
              whitespace=whitespace)
try:
    for name, check in checks.items():
        if args.only is None or args.only == name:
            check()
            print(f"PASS {name}", flush=True)
except (OSError, ValueError, KeyError, SyntaxError, subprocess.SubprocessError) as error:
    parser.exit(1, f"CI failed: {error}\n")
