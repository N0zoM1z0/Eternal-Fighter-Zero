"""Target-bound, standard-library primitives shared by the EFZ control plane."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import struct
import tomllib

ROOT = Path(__file__).resolve().parents[1]


def sha256(path: Path) -> str:
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def tree_digest(path: Path) -> str:
    """Bind names and contents; timestamps and machine-specific roots are excluded."""
    digest = hashlib.sha256()
    files = sorted(p for p in path.rglob("*") if p.is_file())
    if not files:
        raise ValueError(f"missing/empty tool tree: {path}")
    for file in files:
        digest.update(file.relative_to(path).as_posix().encode("utf-8") + b"\0")
        digest.update(bytes.fromhex(sha256(file)))
    return digest.hexdigest()


def load_toml(path: Path) -> dict:
    with path.open("rb") as stream:
        return tomllib.load(stream)


def record_digest(record: dict) -> str:
    return hashlib.sha256(json.dumps(record, sort_keys=True, separators=(",", ":")).encode()).hexdigest()


def number(value: str | int) -> int:
    return int(value, 0) if isinstance(value, str) else int(value)


def pe_layout(data: bytes) -> dict:
    if len(data) < 64 or data[:2] != b"MZ":
        raise ValueError("not a DOS/PE image")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if pe + 24 > len(data) or data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("invalid PE signature")
    machine, count, timestamp, _, _, opt_size, _ = struct.unpack_from("<HHIIIHH", data, pe + 4)
    opt = pe + 24
    if opt_size < 96 or opt + opt_size + count * 40 > len(data):
        raise ValueError("truncated PE header")
    magic = struct.unpack_from("<H", data, opt)[0]
    if machine != 0x14C or magic != 0x10B:
        raise ValueError("expected i386 PE32")
    base = struct.unpack_from("<I", data, opt + 28)[0]
    result = dict(machine=machine, optional_magic=magic, timestamp=timestamp,
                  image_base=base, entry_point=base + struct.unpack_from("<I", data, opt + 16)[0],
                  size_of_image=struct.unpack_from("<I", data, opt + 56)[0],
                  headers_raw_size=struct.unpack_from("<I", data, opt + 60)[0],
                  linker_major=data[opt + 2], linker_minor=data[opt + 3], sections=[])
    for index in range(count):
        off = opt + opt_size + index * 40
        name, vs, rva, rs, ro = struct.unpack_from("<8sIIII", data, off)
        if ro + rs > len(data):
            raise ValueError("section raw extent leaves file")
        result["sections"].append(dict(name=name.rstrip(b"\0").decode("ascii"),
                                       virtual_size=vs, rva=rva, raw_size=rs, raw_offset=ro))
    return result


def verify_target(path: Path | None = None) -> bytes:
    manifest = load_toml(ROOT / "config/target.toml")
    target = manifest["target"]
    data = (path or ROOT / "resources" / target["filename"]).read_bytes()
    if len(data) != target["size"] or hashlib.sha256(data).hexdigest() != target["sha256"]:
        raise ValueError("target size/SHA-256 mismatch")
    observed = pe_layout(data)
    for key, expected in manifest["pe"].items():
        actual = observed[key]
        if key == "sections":
            if actual != expected:
                raise ValueError("PE section mapping differs from target manifest")
        elif actual != number(expected):
            raise ValueError(f"PE {key} differs from target manifest")
    return data


def target_bytes(data: bytes, address: int, size: int) -> bytes:
    if size <= 0:
        raise ValueError("extent must be positive")
    layout = pe_layout(data)
    rva = address - layout["image_base"]
    for section in layout["sections"]:
        relative = rva - section["rva"]
        if 0 <= relative and relative + size <= min(section["virtual_size"], section["raw_size"]):
            off = section["raw_offset"] + relative
            return data[off:off + size]
    raise ValueError("target extent leaves initialized PE section")


def load_units() -> dict:
    manifest = load_toml(ROOT / "config/match-units.toml")
    if manifest["target_sha256"] != load_toml(ROOT / "config/target.toml")["target"]["sha256"]:
        raise ValueError("match-unit manifest is bound to another target")
    units = manifest["units"]
    for unit in units.values():
        contribution_layout(unit)
    validate_unit_bindings(units)
    return units


def contribution_layout(unit: dict) -> tuple[int, list[dict]]:
    """Attribute code/local tables; never shorten the compared contribution."""
    size = number(unit["size"])
    code_size = number(unit.get("code_size", size))
    tables = unit.get("local_data", [])
    if not 0 < code_size <= size:
        raise ValueError("invalid contribution code extent")
    end = code_size
    for table in tables:
        if (number(table["offset"]) != end or number(table["size"]) <= 0
                or table.get("kind") not in {"switch-address-table", "switch-index-table"}
                or not table.get("evidence")):
            raise ValueError("unreviewed or noncontiguous local table extent")
        end += number(table["size"])
    if end != size:
        raise ValueError("local table extents do not cover the complete contribution")
    return code_size, tables


def validate_unit_bindings(units: dict) -> None:
    """One source/profile recipe cannot give one linker symbol two addresses."""
    recipes: dict[tuple, dict[str, int]] = {}
    for unit in units.values():
        recipe = (unit["source"], unit["profile"], tuple(unit.get("dependencies", [])))
        bindings = recipes.setdefault(recipe, {})
        symbols = [(unit["symbol"], number(unit["target_address"]))]
        symbols.extend((r["symbol"], number(r["target"])) for r in unit.get("relocations", []))
        for symbol, address in symbols:
            if not symbol or not 0 <= address <= 0xFFFFFFFF:
                raise ValueError("invalid recipe symbol binding")
            if symbol in bindings and bindings[symbol] != address:
                raise ValueError(f"one recipe symbol has inconsistent destinations: {symbol}")
            bindings[symbol] = address
