"""Pinned VC7.1 execution with an isolated Wine prefix and retained logs."""
from __future__ import annotations

from shared_runtime import command as shared_command

import fcntl
import json
import os
from pathlib import Path
import signal
import subprocess
import time

from common import ROOT, load_toml, sha256, tree_digest

TOOL_ROOT = ROOT / ".tools/msvc710"
LOCK = ROOT / "config/tools.lock.toml"


def verify_toolchain() -> dict:
    lock = load_toml(LOCK)
    for relative, expected in lock["files"].items():
        path = TOOL_ROOT / relative
        if sha256(path) != expected:
            raise ValueError(f"compiler tool identity mismatch: {relative}")
    for relative, expected in lock["trees"].items():
        if tree_digest(TOOL_ROOT / relative) != expected:
            raise ValueError(f"compiler headers/libraries identity mismatch: {relative}")
    wine = Path("/usr/bin/wine").resolve()
    if sha256(wine) != lock["wine"]["launcher_sha256"]:
        raise ValueError("Wine launcher identity mismatch")
    if sha256(Path(lock["wine"]["loader"])) != lock["wine"]["loader_sha256"]:
        raise ValueError("Wine i386 loader identity mismatch")
    return lock


def winpath(path: Path) -> str:
    return "Z:" + str(path.resolve()).replace("/", "\\")


def run_tool(tool: str, arguments: list[str], log: Path, timeout: int = 120,
             expected_codes: tuple[int, ...] = (0,)) -> dict:
    if tool not in {"cl.exe", "link.exe", "rc.exe"}:
        raise ValueError(f"unsupported tool {tool}")
    binary = TOOL_ROOT / "Vc7/bin" / tool
    env = os.environ.copy()
    env.update(WINEARCH="win32", WINEPREFIX=str(ROOT / ".tools/wine-msvc710"),
               WINEDEBUG="-all", WINEDLLOVERRIDES="mscoree,mshtml=",
               INCLUDE=";".join(winpath(TOOL_ROOT / p) for p in ["Vc7/include", "Vc7/PlatformSDK/Include"]),
               LIB=";".join(winpath(TOOL_ROOT / p) for p in ["Vc7/lib", "Vc7/PlatformSDK/Lib"]))
    # Ambient compiler flags must never change a locked build profile.
    for key in ("CL", "_CL_", "LINK", "_LINK_", "WINEPATH"):
        env.pop(key, None)
    (ROOT / ".tools").mkdir(exist_ok=True)
    log.parent.mkdir(parents=True, exist_ok=True)
    command = ["xvfb-run", "-a", "-s", "-screen 0 1024x768x24 -nolisten tcp",
               *shared_command("wine"), str(binary.resolve()), *arguments]

    def constrain() -> None:
        os.nice(10)
        os.sched_setaffinity(0, {min(os.sched_getaffinity(0))})

    with (ROOT / ".tools/native-build.lock").open("a") as mutex:
        fcntl.flock(mutex, fcntl.LOCK_EX)
        started = time.monotonic()
        with log.open("wb") as output:
            process = subprocess.Popen(command, cwd=ROOT, env=env, stdout=output,
                                       stderr=subprocess.STDOUT, start_new_session=True,
                                       preexec_fn=constrain)
            try:
                code = process.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
                process.wait()
                raise TimeoutError(f"{tool} timed out; retained log: {log}") from None
        result = dict(tool=tool, command=command, exit_code=code,
                      elapsed_seconds=round(time.monotonic() - started, 3),
                      log=str(log.relative_to(ROOT)), cpu_count=1, nice=10)
        log.with_suffix(".json").write_text(json.dumps(result, indent=2) + "\n")
        if code not in expected_codes:
            raise ValueError(f"{tool} exited {code}; see {log}\n{log.read_text(errors='replace')[-4000:]}")
        return result


def compile_source(source: Path, output: Path, flags: list[str], log: Path) -> dict:
    source.resolve().relative_to(ROOT)
    output.resolve().relative_to(ROOT / "build")
    if any(flag.lower().startswith(("/gl", "/fo", "/fd", "/fa")) for flag in flags):
        raise ValueError("normal COFF builds require explicit non-LTCG flags and managed outputs")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.unlink(missing_ok=True)
    run_tool("cl.exe", ["/nologo", "/c", *flags, winpath(source),
                        "/Fo" + winpath(output), "/Fd" + winpath(output.with_suffix(".pdb"))], log)
    if not output.is_file():
        raise ValueError("compiler did not produce the requested object")
    receipt = dict(source=str(source.relative_to(ROOT)), source_sha256=sha256(source),
                   object=str(output.relative_to(ROOT)), object_sha256=sha256(output),
                   toolchain_lock_sha256=sha256(LOCK), compiler_sha256=sha256(TOOL_ROOT / "Vc7/bin/cl.exe"),
                   flags=flags, log=str(log.relative_to(ROOT)))
    output.with_suffix(".build.json").write_text(json.dumps(receipt, indent=2) + "\n")
    return receipt
