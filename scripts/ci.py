#!/usr/bin/env python3
"""Fast, target-free checks. Native exact replay is a separate selected action."""
import argparse
import ast
import json
import os
from pathlib import Path
import subprocess
import sys
import tomllib

ROOT = Path(__file__).resolve().parents[1]


def command(*args):
    subprocess.run(args, cwd=ROOT, check=True)


def syntax():
    names = subprocess.check_output(
        ["git", "ls-files", "--cached", "--others", "--exclude-standard", "-z",
         "--", "scripts", "workbench", "config"], cwd=ROOT).decode().split("\0")
    for name in sorted(set(names) - {""}):
        path = ROOT / name
        if not path.is_file() or path.is_symlink():
            continue
        if path.suffix == ".py":
            ast.parse(path.read_text(), filename=name)
        elif path.suffix == ".json":
            json.loads(path.read_text())
        elif path.suffix == ".toml":
            tomllib.loads(path.read_text())
        elif path.suffix == ".sh" or name == "scripts/repo-python":
            command("bash", "-n", str(path))


def declarations():
    from common import load_toml
    lock = json.loads((ROOT / "config/analysis-tools.lock.json").read_text())
    if lock["schema_version"] != 1:
        raise ValueError("unknown analysis lock schema")
    toolchain = load_toml(ROOT / "config/tools.lock.toml")
    if toolchain["msvc71"]["compiler_version"] != "13.10.3077":
        raise ValueError("unexpected compiler declaration")
    for expected in [*toolchain["files"].values(), *toolchain["trees"].values()]:
        if len(expected) != 64 or any(c not in "0123456789abcdef" for c in expected):
            raise ValueError("invalid tool digest")


def ledgers():
    from tracking import validate
    validate()


def whitespace():
    command("git", "diff", "--check")
    command("git", "diff", "--cached", "--check")
    if os.environ.get("CI"):
        command("git", "show", "--format=", "--check", "HEAD")


def main():
    checks = dict(
        syntax=syntax, declarations=declarations, ledgers=ledgers,
        progress=lambda: command(sys.executable, "scripts/progress.py", "--check"),
        whitespace=whitespace,
        oracle=lambda: command(sys.executable, "-m", "unittest", "discover", "-s", "scripts/tests"),
    )
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--only", action="append", choices=checks,
                        help="run a named check; repeat to select several (oracle is opt-in)")
    args = parser.parse_args()
    try:
        for name in args.only or [n for n in checks if n != "oracle"]:
            checks[name]()
            print(f"PASS {name}", flush=True)
    except (OSError, ValueError, KeyError, SyntaxError, subprocess.SubprocessError) as error:
        parser.exit(1, f"CI failed: {error}\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
