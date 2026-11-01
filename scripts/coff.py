"""Normal i386 COFF reader adapted from the TH10 reconstruction (MIT).

Copyright (c) 2026 N0zoM1z0. See LICENSE.
LTCG and ambiguous extents deliberately fail closed.
"""
from pathlib import Path
import struct

RELOCATION_IDS = {"DIR32": 0x0006, "REL32": 0x0014}


def c_string(data: bytes) -> str:
    return data.split(b"\0", 1)[0].decode("ascii")


def symbol_name(raw: bytes, strings: bytes) -> str:
    if raw[:4] == b"\0\0\0\0":
        offset = struct.unpack_from("<I", raw, 4)[0]
        if not 4 <= offset < len(strings):
            raise ValueError(f"invalid COFF string-table offset {offset}")
        return c_string(strings[offset:])
    return c_string(raw)


def coff_object(
    path: Path,
) -> tuple[bytes, list[dict[str, object]], dict[int, dict[str, object]]]:
    data = path.read_bytes()
    if len(data) < 20:
        raise ValueError("truncated COFF object")
    machine, section_count, _, symbol_offset, symbol_count, optional_size, _ = struct.unpack_from(
        "<HHIIIHH", data, 0
    )
    if machine != 0x14C or optional_size != 0:
        raise ValueError("expected a normal i386 COFF object, not LTCG or PE")
    if symbol_offset < 20 + section_count * 40:
        raise ValueError("COFF symbol table overlaps section headers")
    sections = []
    for index in range(section_count):
        offset = 20 + index * 40
        if offset + 40 > len(data):
            raise ValueError("truncated COFF section table")
        fields = struct.unpack_from("<8sIIIIIIHHI", data, offset)
        # VC7.1 records .bss storage size without emitting raw bytes. It must
        # never turn missing code/initialized bytes into an accepted extent.
        uninitialized = bool(fields[9] & 0x80)
        if uninitialized:
            if fields[9] & 0x60 or fields[4] or fields[7]:
                raise ValueError("unsupported uninitialized COFF section")
        elif fields[3] and (not fields[4] or fields[4] + fields[3] > len(data)):
            raise ValueError("COFF section data leaves object file")
        if fields[5] + fields[7] * 10 > len(data):
            raise ValueError("COFF section/relocation table leaves object file")
        if fields[9] & 0x01000000:
            raise ValueError("extended COFF relocation counts are unsupported")
        sections.append(
            {
                "name": c_string(fields[0]),
                "size": fields[3],
                "raw_offset": fields[4],
                "reloc_offset": fields[5],
                "reloc_count": fields[7],
                "flags": fields[9],
            }
        )
    strings_offset = symbol_offset + symbol_count * 18
    if strings_offset + 4 > len(data):
        raise ValueError("truncated COFF symbol table")
    strings_size = struct.unpack_from("<I", data, strings_offset)[0]
    if strings_size < 4 or strings_offset + strings_size > len(data):
        raise ValueError("invalid COFF string table")
    strings = data[strings_offset : strings_offset + strings_size]
    symbols: dict[int, dict[str, object]] = {}
    raw_index = 0
    while raw_index < symbol_count:
        offset = symbol_offset + raw_index * 18
        raw_name, value, section, type_id, storage, aux_count = struct.unpack_from(
            "<8sIhHBB", data, offset
        )
        if section > section_count:
            raise ValueError("COFF symbol references an unknown section")
        if offset + 18 * (aux_count + 1) > strings_offset:
            raise ValueError("truncated COFF auxiliary symbol records")
        aux = data[offset + 18 : offset + 18 * (aux_count + 1)]
        symbols[raw_index] = {
            "name": symbol_name(raw_name, strings),
            "value": value,
            "section": section,
            "type": type_id,
            "storage": storage,
            "aux_count": aux_count,
            "aux": aux,
        }
        raw_index += 1 + aux_count
    return data, sections, symbols


def object_functions(path: Path, contains: str = "") -> list[dict[str, object]]:
    data, sections, symbols = coff_object(path)
    needle = contains.lower()
    defined = [
        symbol
        for symbol in symbols.values()
        if int(symbol["section"]) > 0
        and int(symbol["type"]) == 0x20
        and int(sections[int(symbol["section"]) - 1]["flags"]) & 0x20
    ]
    functions_per_section: dict[int, int] = {}
    for symbol in defined:
        section_number = int(symbol["section"])
        functions_per_section[section_number] = (
            functions_per_section.get(section_number, 0) + 1
        )
    result = []
    for symbol in defined:
        name = str(symbol["name"])
        section_number = int(symbol["section"])
        if needle and needle not in name.lower():
            continue
        section = sections[section_number - 1]
        size = None
        extent_source = None
        if int(symbol["aux_count"]) >= 1 and len(symbol["aux"]) >= 8:
            auxiliary_size = struct.unpack_from("<I", symbol["aux"], 4)[0]
            if auxiliary_size:
                size = auxiliary_size
                extent_source = "function-definition-aux"
        if (
            size is None
            and functions_per_section[section_number] == 1
            and int(symbol["value"]) == 0
            and int(section["flags"]) & 0x1000
        ):
            size = int(section["size"])
            extent_source = "single-function-comdat-section"
        relocation_count = None
        if size is not None:
            start = int(symbol["value"])
            stop = start + size
            relocation_count = 0
            for index in range(int(section["reloc_count"])):
                offset = int(section["reloc_offset"]) + index * 10
                virtual_address = struct.unpack_from("<I", data, offset)[0]
                if start <= virtual_address < stop:
                    relocation_count += 1
        result.append(
            {
                "symbol": name,
                "size": size,
                "extent_source": extent_source,
                "relocation_count": relocation_count,
                "section": section["name"],
                "section_number": section_number,
                "section_offset": int(symbol["value"]),
                "storage_class": int(symbol["storage"]),
            }
        )
    result.sort(
        key=lambda row: (
            int(row["section_number"]),
            int(row["section_offset"]),
            str(row["symbol"]),
        )
    )
    return result


def object_function(
    path: Path, wanted: str
) -> tuple[bytearray, list[dict[str, object]]]:
    data, sections, symbols = coff_object(path)
    matches = [
        symbol
        for symbol in symbols.values()
        if symbol["name"] == wanted and int(symbol["section"]) > 0
    ]
    if len(matches) != 1:
        raise ValueError(f"expected one defined symbol {wanted!r}, found {len(matches)}")
    symbol = matches[0]
    section = sections[int(symbol["section"]) - 1]
    if int(symbol["type"]) != 0x20 or not int(section["flags"]) & 0x20:
        raise ValueError("selected COFF symbol is not a code function")
    size = 0
    if int(symbol["aux_count"]) >= 1 and len(symbol["aux"]) >= 8:
        size = struct.unpack_from("<I", symbol["aux"], 4)[0]
    if not size:
        section_number = int(symbol["section"])
        section_functions = [
            candidate
            for candidate in symbols.values()
            if int(candidate["section"]) == section_number
            and int(candidate["type"]) == 0x20
        ]
        if (
            len(section_functions) == 1
            and int(symbol["value"]) == 0
            and int(section["flags"]) & 0x20
            and int(section["flags"]) & 0x1000
        ):
            size = int(section["size"])
    if not size:
        raise ValueError("function symbol lacks a usable definition extent")
    if any(candidate is not symbol and candidate["section"] == symbol["section"]
           and candidate["type"] == 0x20
           and int(symbol["value"]) <= int(candidate["value"]) < int(symbol["value"]) + size
           for candidate in symbols.values()):
        raise ValueError("function extent overlaps another function symbol")
    start = int(section["raw_offset"]) + int(symbol["value"])
    section_end = int(section["raw_offset"]) + int(section["size"])
    if start + size > section_end or section_end > len(data):
        raise ValueError("function extends beyond its COFF section")
    code = bytearray(data[start : start + size])
    relocations = []
    for index in range(int(section["reloc_count"])):
        offset = int(section["reloc_offset"]) + index * 10
        virtual_address, target_index, type_id = struct.unpack_from("<IIH", data, offset)
        local = virtual_address - int(symbol["value"])
        if not 0 <= local < size:
            continue
        if local + 4 > size:
            raise ValueError("relocation leaves the COFF function extent")
        target = symbols.get(target_index)
        if target is None:
            raise ValueError("relocation references an auxiliary symbol")
        relocations.append(
            {
                "offset": local,
                "type_id": type_id,
                "type": next(
                    (
                        name
                        for name, value in RELOCATION_IDS.items()
                        if value == type_id
                    ),
                    f"0x{type_id:04X}",
                ),
                "symbol": target["name"],
            }
        )
    return code, relocations
