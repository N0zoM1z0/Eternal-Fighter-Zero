#!/usr/bin/env python3
"""Run bounded, target-attested local EFZ Ghidra workflows."""

from __future__ import annotations

import argparse
from datetime import datetime, timezone
import fcntl
import hashlib
import json
import os
from pathlib import Path
import signal
import struct
import subprocess
import sys
import tomllib
import uuid


ROOT = Path(__file__).resolve().parents[1]
PRIVATE = ROOT / ".analysis" / "ghidra"
PROJECT = ROOT / "ghidra-project"
LOCK = ROOT / "config" / "analysis-tools.lock.json"
MARKER = "EFZ_GHIDRA_ATTESTATION_V1:"


def digest(path: Path) -> str:
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def tools() -> tuple[Path, dict[str, str]]:
    lock = json.loads(LOCK.read_text(encoding="utf-8"))
    if lock.get("schema_version") != 1:
        raise ValueError("unsupported analysis tool lock schema")
    ghidra = (ROOT / ".tools" / "ghidra").resolve(strict=True)
    jdk = (ROOT / ".tools" / "jdk").resolve(strict=True)
    for name, selected in (("ghidra", ghidra), ("jdk", jdk)):
        for relative, expected in lock[name]["files"].items():
            candidate = selected / relative
            if digest(candidate) != expected:
                raise ValueError(f"analysis tool hash mismatch: {candidate}")
    banner = subprocess.run(
        [str(jdk / "bin" / "java"), "-version"],
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
        timeout=15, check=True,
    ).stdout
    if lock["jdk"]["banner_substring"] not in banner:
        raise ValueError("JDK banner differs from analysis tool lock")
    environment = os.environ.copy()
    environment.update({"JAVA_HOME": str(jdk), "GHIDRA_HOME": str(ghidra)})
    return ghidra / "support" / "analyzeHeadless", environment


def number(value: object) -> int:
    return int(str(value), 0) if not isinstance(value, int) else value


def target() -> tuple[Path, dict[str, object], list[tuple[int, bytes, bool]]]:
    with (ROOT / "config" / "target.toml").open("rb") as stream:
        document = tomllib.load(stream)
    expected = document["target"]
    manifest = document["pe"]
    path = ROOT / "resources" / str(expected["filename"])
    # Use the repository's independent verifier before interpreting any bytes.
    subprocess.run(
        [sys.executable, str(ROOT / "scripts" / "verify-target.py")],
        cwd=ROOT, check=True, timeout=30,
    )
    data = path.read_bytes()
    if len(data) != number(expected["size"]) or hashlib.sha256(data).hexdigest() != expected["sha256"]:
        raise ValueError("canonical target identity mismatch")
    if data[:2] != b"MZ" or len(data) < 0x40:
        raise ValueError("invalid target DOS header")
    pe = struct.unpack_from("<I", data, 0x3c)[0]
    if pe + 24 > len(data) or data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("invalid target PE header")
    machine, count = struct.unpack_from("<HH", data, pe + 4)
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    optional = pe + 24
    if machine != 0x14c or optional_size < 96 or optional + optional_size > len(data):
        raise ValueError("target must be a complete i386 PE32")
    if struct.unpack_from("<H", data, optional)[0] != 0x10b:
        raise ValueError("target optional header is not PE32")
    base = struct.unpack_from("<I", data, optional + 28)[0]
    entry = base + struct.unpack_from("<I", data, optional + 16)[0]
    image_size = struct.unpack_from("<I", data, optional + 56)[0]
    for key, actual in (("image_base", base), ("entry_point", entry), ("size_of_image", image_size)):
        if actual != number(manifest[key]):
            raise ValueError(f"target PE {key} differs from target manifest")
    regions = []
    for index in range(count):
        offset = optional + optional_size + index * 40
        if offset + 40 > len(data):
            raise ValueError("truncated PE section table")
        _, virtual_size, rva, raw_size, raw_offset, _, _, _, _, flags = struct.unpack_from("<8sIIIIIIHHI", data, offset)
        length = min(virtual_size, raw_size)
        if rva + virtual_size > image_size or raw_offset + raw_size > len(data):
            raise ValueError("PE section leaves file or image")
        if length:
            regions.append((base + rva, data[raw_offset:raw_offset + length], bool(flags & 0x20000000)))
    if not regions or not any(executable and address <= entry < address + len(payload) for address, payload, executable in regions):
        raise ValueError("target entry is outside file-backed executable sections")
    return path, {**expected, **manifest}, regions


def output_path(raw: Path) -> Path:
    path = raw.expanduser().resolve()
    path.relative_to((ROOT / ".analysis").resolve())
    path.parent.mkdir(parents=True, exist_ok=True)
    return path


def run_headless(command: list[str], environment: dict[str, str], label: str, timeout: int, required: list[str]) -> Path:
    PRIVATE.mkdir(parents=True, exist_ok=True)
    with (PRIVATE / "headless.lock").open("a+", encoding="utf-8") as gate:
        try:
            fcntl.flock(gate, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError as exc:
            raise RuntimeError("another local Ghidra job holds .analysis/ghidra/headless.lock") from exc
        gate.seek(0)
        gate.truncate()
        gate.write(f"pid={os.getpid()}\n")
        gate.flush()
        return run_headless_locked(command, environment, label, timeout, required)


def run_headless_locked(command: list[str], environment: dict[str, str], label: str, timeout: int, required: list[str]) -> Path:
    log_dir = PRIVATE / "logs"
    log_dir.mkdir(parents=True, exist_ok=True)
    stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    log = log_dir / f"{stamp}-{label}-{uuid.uuid4().hex[:8]}.log"
    cpu = min(os.sched_getaffinity(0))

    def constrain_child() -> None:
        os.setpriority(os.PRIO_PROCESS, 0, max(10, os.getpriority(os.PRIO_PROCESS, 0)))
        os.sched_setaffinity(0, {cpu})

    print(f"Ghidra {label}; retained log: {log.relative_to(ROOT)}", flush=True)
    with log.open("w", encoding="utf-8") as stream:
        stream.write(json.dumps({"command": command, "timeout_seconds": timeout,
            "nice_at_least": 10, "cpu_affinity": [cpu]}) + "\n")
        stream.flush()
        process = subprocess.Popen(command, cwd=ROOT, env=environment, stdout=stream,
            stderr=subprocess.STDOUT, start_new_session=True, preexec_fn=constrain_child)
        try:
            status = process.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            os.killpg(process.pid, signal.SIGTERM)
            try:
                process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
                process.wait()
            raise RuntimeError(f"Ghidra timed out; inspect {log.relative_to(ROOT)}")
        stream.write(f"\nprocess_exit_status={status}\n")
    report = "\n".join(log.read_text(encoding="utf-8", errors="replace").splitlines()[1:])
    if status != 0 or any(line.startswith("ERROR ") for line in report.splitlines()):
        raise RuntimeError(f"Ghidra process/script failed; inspect {log.relative_to(ROOT)}")
    if "Analysis timed out" in report or "analysis timed out" in report:
        raise RuntimeError(f"Ghidra analysis incomplete; inspect {log.relative_to(ROOT)}")
    for marker in required:
        if marker not in report:
            raise RuntimeError(f"Ghidra omitted success marker {marker!r}; inspect {log.relative_to(ROOT)}")
    print(f"Ghidra {label} OK", flush=True)
    return log


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--timeout", type=int, default=2100, help="whole headless job deadline, seconds")
    sub = parser.add_subparsers(dest="command", required=True)
    sub.add_parser("tools", help="verify locked Ghidra/JDK surfaces without the target")
    sub.add_parser("import", help="initialize and analyze private ghidra-project/EFZ")
    sub.add_parser("verify", help="attest existing project and every file-backed section")
    inventory = sub.add_parser("inventory", help="export provisional candidates privately")
    inventory.add_argument("--output", type=Path, default=PRIVATE / "functions.csv")
    for name in ("decompile", "disasm", "function", "callers", "callees", "xrefs", "refs"):
        operation = sub.add_parser(name)
        operation.add_argument("address", type=lambda value: int(value, 0))
        operation.add_argument("--output", type=Path)
        if name in {"disasm", "callers", "callees", "xrefs", "refs"}:
            operation.add_argument("--limit", type=int, default=1000)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        if not 30 <= args.timeout <= 7200:
            raise ValueError("--timeout must be between 30 and 7200 seconds")
        analyzer, environment = tools()
        if args.command == "tools":
            print("Ghidra/JDK locked surfaces OK")
            return 0
        _, expected, regions = target()
        PROJECT.mkdir(parents=True, exist_ok=True)
        exists = (PROJECT / "EFZ.gpr").is_file()
        if args.command == "import" and exists:
            raise ValueError("Ghidra project already exists; use verify/inventory")
        if args.command != "import" and not exists:
            raise ValueError("missing Ghidra project; run scripts/ghidra.py import")
        attestation = [
            "-postScript", "EFZVerifyTarget.java", str(expected["sha256"]),
            str(expected["filename"]), hex(number(expected["image_base"])),
            hex(number(expected["entry_point"])), str(len(regions)),
        ]
        for address, payload, _ in regions:
            attestation.extend([hex(address), str(len(payload)), hashlib.sha256(payload).hexdigest()])
        command = [str(analyzer), str(PROJECT), "EFZ", "-max-cpu", "1"]
        if args.command == "import":
            command += ["-import", str((ROOT / "resources" / str(expected["filename"])).resolve()), "-analysisTimeoutPerFile", str(max(10, args.timeout - 120))]
        else:
            command += ["-process", str(expected["filename"]), "-readOnly", "-noanalysis"]
        command += ["-scriptPath", str(ROOT / "scripts" / "ghidra"), *attestation]
        required = [MARKER + str(expected["sha256"])]
        if args.command == "import":
            required += ["REPORT: Analysis succeeded", "REPORT: Save succeeded", "REPORT: Import succeeded"]
        temporary = None
        destination = None
        if args.command == "inventory":
            destination = output_path(args.output)
            temporary = destination.with_name(destination.name + ".pending-" + uuid.uuid4().hex[:8])
            command += ["-postScript", "EFZExportInventory.java", str(temporary)]
            required.append("EFZ_GHIDRA_INVENTORY_COMPLETE_V1")
        elif args.command not in {"import", "verify"}:
            if not 0 <= args.address <= 0xffffffff:
                raise ValueError("address must fit PE32")
            limit = getattr(args, "limit", 1000)
            if not 1 <= limit <= 10000:
                raise ValueError("--limit must be between 1 and 10000")
            destination = output_path(args.output or PRIVATE / f"{args.command}-{args.address:08x}.txt")
            temporary = destination.with_name(destination.name + ".pending-" + uuid.uuid4().hex[:8])
            command += ["-postScript", "EFZQueryFunction.java", str(temporary), args.command, hex(args.address), str(limit)]
            required.append("EFZ_GHIDRA_QUERY_COMPLETE_V1:" + args.command)
        run_headless(command, environment, args.command, args.timeout, required)
        if temporary is not None and destination is not None:
            if not temporary.is_file() or temporary.stat().st_size == 0:
                raise RuntimeError("Ghidra query output is missing or empty")
            temporary.replace(destination)
            print(f"Output: {destination.relative_to(ROOT)}")
        return 0
    except (OSError, KeyError, TypeError, ValueError, RuntimeError, struct.error, subprocess.SubprocessError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
