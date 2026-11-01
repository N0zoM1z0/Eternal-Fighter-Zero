#!/usr/bin/env python3
"""Export target-bound PE imports, Rich records and CodeView metadata offline."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import uuid
from common import ROOT, pe_layout, target_bytes, verify_target


def inspect(data: bytes) -> dict:
    layout = pe_layout(data)
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    opt = pe + 24
    base = layout["image_base"]

    def read(rva: int, size: int) -> bytes:
        return target_bytes(data, base + rva, size)

    def string(rva: int) -> str:
        chars = bytearray()
        for offset in range(4096):
            value = read(rva + offset, 1)[0]
            if not value:
                return chars.decode("ascii")
            chars.append(value)
        raise ValueError("unterminated PE name")

    imports = []
    rva, size = struct.unpack_from("<II", data, opt + 96 + 8)
    for offset in range(0, size, 20):
        original, stamp, chain, dll_name, iat = struct.unpack("<IIIII", read(rva + offset, 20))
        if not any((original, stamp, chain, dll_name, iat)):
            break
        symbols = []
        for index in range(65536):
            value = struct.unpack("<I", read((original or iat) + index * 4, 4))[0]
            if not value:
                break
            symbols.append(dict(iat=f"0x{base + iat + index * 4:08X}",
                                name=string(value + 2) if not value & 0x80000000 else None,
                                ordinal=value & 0xFFFF if value & 0x80000000 else None))
        else:
            raise ValueError("unterminated import thunk table")
        imports.append(dict(dll=string(dll_name), symbols=symbols))
    rich = []
    rich_end = data.find(b"Rich", 64, pe)
    if rich_end >= 0:
        key = struct.unpack_from("<I", data, rich_end + 4)[0]
        for start in range(64, rich_end, 4):
            if struct.unpack_from("<I", data, start)[0] ^ key == 0x536E6144:
                if (rich_end - start - 16) % 8:
                    raise ValueError("malformed Rich record extent")
                for offset in range(start + 16, rich_end, 8):
                    product, count = struct.unpack_from("<II", data, offset)
                    product ^= key
                    rich.append(dict(product_id=product >> 16, build=product & 0xFFFF, count=count ^ key))
                break
    codeview = []
    rva, size = struct.unpack_from("<II", data, opt + 96 + 6 * 8)
    for offset in range(0, size, 28):
        _, _, _, _, kind, length, _, raw = struct.unpack("<IIHHIIII", read(rva + offset, 28))
        if kind == 2 and data[raw:raw + 4] == b"RSDS":
            if raw + length > len(data) or length < 25:
                raise ValueError("truncated RSDS record")
            codeview.append(dict(guid=str(uuid.UUID(bytes_le=data[raw + 4:raw + 20])),
                                 age=struct.unpack_from("<I", data, raw + 20)[0],
                                 pdb_path=data[raw + 24:raw + length].split(b"\0")[0].decode("ascii")))
    return dict(target_sha256=hashlib.sha256(data).hexdigest(), pe=layout,
                imports=imports, rich_records=rich, codeview=codeview,
                authority="static PE metadata; original names, release provenance and production flags remain unproven")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, default=ROOT / ".analysis/bootstrap/pe-observations.json")
    args = parser.parse_args()
    try:
        output = args.output.resolve()
        output.relative_to(ROOT / ".analysis")
        result = inspect(verify_target())
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(result, indent=2) + "\n")
    except (OSError, ValueError, KeyError, struct.error) as error:
        parser.exit(1, f"PE inspection failed: {error}\n")
    print(f"PE metadata: {output.relative_to(ROOT)}, {sum(len(i['symbols']) for i in result['imports'])} imports")
