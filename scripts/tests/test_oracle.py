"""Target-free falsification checks for the exact acceptance mechanisms."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import common
from coff import coff_object, object_function
from oracle import complete_compare, replay_relocations, verify_receipt


def binding(offset=0, kind="DIR32", symbol="_global", target=0x790100):
    return dict(offset=offset, type=kind, symbol=symbol, target=target, evidence="synthetic independent binding")


def actual(row):
    return dict(offset=row["offset"], type_id={"DIR32": 6, "REL32": 20}[row["type"]], symbol=row["symbol"])


def object_fixture(code=b"\xC3", relocation=False, function_count=1):
    """Construct a minimal documented COFF shape, without invoking a compiler."""
    raw_offset = 60
    reloc_offset = raw_offset + len(code)
    symbols_offset = reloc_offset + (10 if relocation else 0)
    header = struct.pack("<HHIIIHH", 0x14C, 1, 0, symbols_offset, function_count + int(relocation), 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text\0\0\0", 0, 0, len(code), raw_offset,
                          reloc_offset if relocation else 0, 0, int(relocation), 0, 0x60001020)
    records = b""
    for index in range(function_count):
        records += struct.pack("<8sIhHBB", ("_f" + str(index)).encode(), 0, 1, 0x20, 2, 0)
    if relocation:
        records += struct.pack("<8sIhHBB", b"_global", 0, 0, 0, 2, 0)
    reloc = struct.pack("<IIH", 0, function_count, 6) if relocation else b""
    return header + section + code + reloc + records + struct.pack("<I", 4)


def object_with_bss_fixture():
    """A file-backed function beside a large, unbacked VC7.1 .bss section."""
    original = object_fixture()
    header = bytearray(original[:20])
    struct.pack_into("<H", header, 2, 2)
    struct.pack_into("<I", header, 8, struct.unpack_from("<I", header, 8)[0] + 40)
    text = bytearray(original[20:60])
    struct.pack_into("<I", text, 20, 100)
    bss = struct.pack("<8sIIIIIIHHI", b".bss\0\0\0\0", 0, 0, 0x20818,
                      0, 0, 0, 0, 0, 0xC0400080)
    return header + text + bss + original[60:]


class ExactOracleTests(unittest.TestCase):
    def test_replays_all_addends_without_masking(self):
        rows = [binding(), binding(4, "REL32", "_callee", 0x405000)]
        code = struct.pack("<II", 12, 0xFFFFFFFC)
        expected = struct.pack("<II", 0x79010C, 0x405000 - 4 - (0x401000 + 4 + 4))
        report = complete_compare(code, expected, list(map(actual, rows)), rows, 0x401000)
        self.assertEqual((report["result"], report["matched_bytes"]), ("exact", 8))

    def test_wrong_bound_address_is_a_real_byte_mismatch(self):
        row = binding(target=0x790104)
        report = complete_compare(b"\0" * 4, struct.pack("<I", 0x790100), [actual(row)], [row], 0x401000)
        self.assertEqual(report["result"], "mismatch")

    def test_internal_binding_must_preserve_the_compiled_local_destination(self):
        row = binding(target=0x401010)
        observed = dict(actual(row), local_target_offset=16)
        replay_relocations(b"\0" * 20, [observed], [row], 0x401000)
        with self.assertRaisesRegex(ValueError, "compiled offset"):
            replay_relocations(b"\0" * 20, [observed], [dict(row, target=0x402000)], 0x401000)

    def test_one_symbol_cannot_resolve_to_two_addresses(self):
        rows = [binding(), binding(4, target=0x790200)]
        with self.assertRaisesRegex(ValueError, "inconsistent destinations"):
            replay_relocations(b"\0" * 8, list(map(actual, rows)), rows, 0x401000)

    def test_recipe_cannot_rebind_self_or_a_shared_symbol(self):
        unit = dict(source="a.cpp", profile="p", symbol="_self", target_address=0x401000,
                    relocations=[binding(symbol="_self", target=0x402000)])
        with self.assertRaisesRegex(ValueError, "inconsistent destinations"):
            common.validate_unit_bindings({"u": unit})
        first = dict(unit, relocations=[binding()])
        second = dict(unit, symbol="_other", target_address=0x402000,
                      relocations=[binding(target=0x790200)])
        with self.assertRaisesRegex(ValueError, "inconsistent destinations"):
            common.validate_unit_bindings({"u": first, "v": second})

    def test_all_complete_extents_are_required(self):
        for code, original in [(b"", b""), (b"\xc3", b"\xc3\xcc"), (b"\xc3\xcc", b"\xc3")]:
            with self.subTest(code=code), self.assertRaises(ValueError):
                complete_compare(code, original, [], [], 0x401000)

    def test_local_table_attribution_never_accepts_a_matching_code_prefix(self):
        unit = dict(size=5, code_size=1, local_data=[dict(
            offset=1, size=4, kind="switch-address-table", evidence="reviewed synthetic table")])
        self.assertEqual(common.contribution_layout(unit)[0], 1)
        self.assertEqual(complete_compare(b"\xc3\0\0\0\0", b"\xc3\0\0\0\1",
                                          [], [], 0x401000)["result"], "mismatch")
        bad_units = [dict(unit, code_size=0), dict(unit, code_size=6),
                     dict(unit, local_data=[])]
        for change in [dict(offset=2), dict(size=0), dict(size=5),
                       dict(kind="unreviewed"), dict(evidence="")]:
            table = dict(unit["local_data"][0], **change)
            bad_units.append(dict(unit, local_data=[table]))
        for bad in bad_units:
            with self.subTest(unit=bad), self.assertRaises(ValueError):
                common.contribution_layout(bad)

    def test_missing_extra_wrong_symbol_and_unknown_relocations_reject(self):
        row = binding()
        for observed, declared in [([actual(row)], []), ([], [row]),
                                    ([actual(row)], [binding(symbol="_other")]),
                                    ([dict(offset=0, type_id=99, symbol="_global")], [row]),
                                    ([actual(row)], [dict(row, type="REL16")])]:
            with self.subTest(observed=observed, declared=declared), self.assertRaises(ValueError):
                replay_relocations(b"\0" * 4, observed, declared, 0x401000)

    def test_overlap_outside_and_unproven_bindings_reject(self):
        cases = [[binding(), binding(2)], [binding(-1)], [binding(5)],
                 [dict(binding(), evidence="")], [binding(target=0x100000000)]]
        for rows in cases:
            with self.subTest(rows=rows), self.assertRaises(ValueError):
                replay_relocations(b"\0" * 8, [], rows, 0x401000)

    def test_coff_extent_and_relocations_are_read_from_object(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "x.obj"
            path.write_bytes(object_fixture(b"\0" * 4, relocation=True))
            code, relocations = object_function(path, "_f0")
            self.assertEqual(code, b"\0" * 4)
            self.assertEqual(relocations[0]["symbol"], "_global")
            self.assertEqual(relocations[0]["type_id"], 6)
            data = bytearray(object_fixture(b"\0" * 4, relocation=True))
            # Bind the relocation to the function defined in this same section.
            struct.pack_into("<I", data, 68, 0)
            path.write_bytes(data)
            _, relocations = object_function(path, "_f0")
            self.assertEqual(relocations[0]["local_target_offset"], 0)

    def test_coff_ambiguous_extents_and_truncated_relocation_reject(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "x.obj"
            for data in [object_fixture(function_count=2), object_fixture(b"\0", relocation=True)]:
                path.write_bytes(data)
                with self.assertRaises(ValueError):
                    object_function(path, "_f0")

    def test_coff_non_i386_and_out_of_file_tables_reject(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "x.obj"
            for offset, payload in [(0, struct.pack("<H", 0)), (24 + 20, struct.pack("<I", 0x7FFFFFFF))]:
                data = bytearray(object_fixture())
                data[offset:offset + len(payload)] = payload
                path.write_bytes(data)
                with self.assertRaises(ValueError):
                    coff_object(path)

    def test_coff_bss_storage_is_not_read_as_file_bytes(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "x.obj"
            path.write_bytes(object_with_bss_fixture())
            _, sections, _ = coff_object(path)
            self.assertEqual((sections[1]["size"], sections[1]["raw_offset"]), (0x20818, 0))
            self.assertEqual(object_function(path, "_f0"), (b"\xc3", []))

    def test_coff_unbacked_code_and_malformed_bss_reject(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "x.obj"
            # Missing code bytes, mixed BSS/code or initialized flags, raw BSS
            # bytes and BSS relocations must not bypass file-backed validation.
            mutations = [(40, "I", 0), (96, "I", 0xC04000A0),
                         (96, "I", 0xC04000C0), (80, "I", 100), (92, "H", 1)]
            for offset, kind, value in mutations:
                data = object_with_bss_fixture()
                struct.pack_into("<" + kind, data, offset, value)
                path.write_bytes(data)
                with self.subTest(offset=offset, value=value), self.assertRaises(ValueError):
                    coff_object(path)

    def test_unit_manifest_is_bound_to_canonical_target(self):
        with patch.object(common, "load_toml", side_effect=[{"target_sha256": "other", "units": {}}, {"target": {"sha256": "canonical"}}]):
            with self.assertRaisesRegex(ValueError, "another target"):
                common.load_units()

    def test_target_mismatch_rejects_before_analysis(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "wrong.exe"
            path.write_bytes(b"untrusted target")
            manifest = {"target": {"filename": "wrong.exe", "size": 16, "sha256": "0" * 64}}
            with patch.object(common, "load_toml", return_value=manifest):
                with self.assertRaisesRegex(ValueError, "SHA-256 mismatch"):
                    common.verify_target(path)

    def test_stale_source_object_profile_and_manifest_receipts_reject(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "config").mkdir()
            for name in ["source.cpp", "object.obj", "config/tools.lock.toml", "config/build.toml", "config/match-units.toml"]:
                (root / name).write_text(name)
            unit = dict(source="source.cpp", object="object.obj", profile="p", dependencies=[])
            receipt = dict(unit="u", source=unit["source"], object=unit["object"], profile="p", dependencies={}, flags=["/Od"], compiler_sha256="compiler")
            for key, file in [("source_sha256", "source.cpp"), ("object_sha256", "object.obj"),
                              ("toolchain_lock_sha256", "config/tools.lock.toml"),
                              ("build_manifest_sha256", "config/build.toml"),
                              ("units_manifest_sha256", "config/match-units.toml")]:
                receipt[key] = common.sha256(root / file)
            profile = {"profiles": {"p": {"artifact_kind": "coff", "flags": ["/Od"]}}}
            receipt.update(unit_sha256=common.record_digest(unit), profile_sha256=common.record_digest(profile["profiles"]["p"]))
            lock = {"files": {"Vc7/bin/cl.exe": "compiler"}}
            path = root / "object.obj"
            with patch("oracle.ROOT", root), patch("oracle.load_toml", side_effect=lambda p: profile if p.name == "build.toml" else lock):
                path.with_suffix(".build.json").write_text(json.dumps(receipt))
                verify_receipt("u", unit, path)
                for key in ["source_sha256", "object_sha256", "toolchain_lock_sha256", "unit_sha256", "profile_sha256", "flags", "compiler_sha256"]:
                    changed = copy.deepcopy(receipt)
                    changed[key] = "changed"
                    path.with_suffix(".build.json").write_text(json.dumps(changed))
                    with self.subTest(key=key), self.assertRaises(ValueError):
                        verify_receipt("u", unit, path)
                # Full manifest hashes are historical provenance. Adding an unrelated
                # unit/profile must not force a rebuild of an unchanged selected recipe.
                receipt["units_manifest_sha256"] = "historical manifest"
                receipt["build_manifest_sha256"] = "historical manifest"
                path.with_suffix(".build.json").write_text(json.dumps(receipt))
                verify_receipt("u", unit, path)


if __name__ == "__main__":
    unittest.main()
