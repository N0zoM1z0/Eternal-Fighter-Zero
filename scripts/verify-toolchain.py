#!/usr/bin/env python3
"""Check pinned compiler surfaces; --execute also compiles, links and runs smoke."""
import argparse

from shared_runtime import command as shared_command
import json
from common import ROOT, sha256
from native_build import TOOL_ROOT, compile_source, run_tool, verify_toolchain, winpath


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--execute", action="store_true")
    args = parser.parse_args()
    try:
        lock = verify_toolchain()
        result = {"result": "ok", "compiler": lock["msvc71"]["compiler_version"],
                  "profile_authority": "candidate; flags and production partitioning remain per-unit"}
        if args.execute:
            logdir = ROOT / ".analysis/toolchain"
            run_tool("cl.exe", [], logdir / "compiler-banner.log")
            if lock["msvc71"]["compiler_version"] not in (logdir / "compiler-banner.log").read_text(errors="replace"):
                raise ValueError("compiler banner differs from lock")
            # VC7.1 LINK /? returns 1100, truncated to 76 by Unix, even on success.
            run_tool("link.exe", ["/?"], logdir / "linker-banner.log", expected_codes=(0, 76))
            if lock["msvc71"]["linker_version"] not in (logdir / "linker-banner.log").read_text(errors="replace"):
                raise ValueError("linker banner differs from lock")
            output = ROOT / "build/toolchain"
            flags = ["/Od", "/G6", "/MD", "/Gy", "/W3"]
            for name in ["smoke.c", "smoke.cpp"]:
                compile_source(ROOT / "probes" / name, output / (name + ".obj"), flags,
                               logdir / (name + ".log"))
            run_tool("rc.exe", ["/fo" + winpath(output / "smoke.res"), winpath(ROOT / "probes/smoke.rc")], logdir / "resource.log")
            executable = output / "smoke.exe"
            executable.unlink(missing_ok=True)
            run_tool("link.exe", ["/nologo", "/subsystem:console", "/machine:x86", "/incremental:no",
                                  "/out:" + winpath(executable), winpath(output / "smoke.c.obj"),
                                  winpath(output / "smoke.cpp.obj"), winpath(output / "smoke.res")], logdir / "link.log")
            # Reuse the same bounded Wine execution policy for our own smoke executable.
            import os, subprocess
            env = os.environ.copy()
            env.update(WINEARCH="win32", WINEPREFIX=str(ROOT / ".tools/wine-msvc710"), WINEDEBUG="-all")
            completed = subprocess.run(["xvfb-run", "-a", *shared_command("wine"), str(executable)],
                                       cwd=ROOT, env=env, capture_output=True, timeout=30)
            (logdir / "run.log").write_bytes(completed.stdout + completed.stderr)
            if completed.returncode != 0 or b"EFZ compiler smoke OK" not in completed.stdout:
                raise ValueError("compiled smoke execution failed")
            result["smoke"] = "C, C++, Windows headers, CRT, resources, link, execution passed"
            result["executable_sha256"] = sha256(executable)
            (logdir / "smoke.json").write_text(json.dumps(result, indent=2) + "\n")
    except (OSError, ValueError, KeyError, TimeoutError) as error:
        parser.exit(1, f"toolchain verification failed: {error}\n")
    print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
