# Exact oracle contract

The initial authority is complete native function codegen against the locked
original executable. It does not establish a runnable reconstructed game.

## Accepted normal COFF lane

1. Verify canonical target size, SHA-256 and PE section mapping.
2. Verify `match-units.toml` is bound to that target.
3. Require a reviewed complete target boundary and one unambiguous COFF
   function-definition extent, or a single-function COMDAT section.
4. Require identical positive object/target lengths. No prefix or extra-tail
   override exists.
5. Match the exhaustive relocation inventory by offset, type and exact symbol.
   Reject missing, extra, unknown, overlapping or out-of-range fields. One
   symbol must have one destination within a recipe, including self references
   and bindings shared by functions from the same source/profile.
6. Replay explicit symbol bindings, preserving the object's encoded addends:
   DIR32 = `target + addend`; REL32 = `target + addend - (site + 4)`.
7. Compare every byte after replay, including all local branches and address
   fields. Only zero differences grant `complete-function-codegen` authority.
8. Bind the report to source, dependencies, object, compiler/toolchain lock,
   flags, unit manifest, build manifest, boundary ledger and target identity.
   Stale build receipts are rejected. Selected unit/profile content digests
   control freshness; whole-manifest hashes retain historical provenance, so
   adding an unrelated recipe does not invalidate an unchanged selected unit.

`scripts/replay-exact-units.py --unit NAME` removes the old object, compiles the
selected recipe and runs this comparator. Reports live in `.analysis/exact/`.
The checker never writes `matches.csv`; acceptance is an explicit reviewed
ledger update. Public compact evidence lives in `docs/evidence/`.

`--list-functions OBJECT` is a diagnostic symbol inventory and grants no credit.
There is no address-masked exact mode. Bindings must come from original PE IAT,
mapped strings/data, complete disassembly, or other reviewed target evidence;
the strict comparator does not infer destinations from comparison bytes.

## Claim limits

COFF exactness is conditioned on the explicit original destinations. It proves
the selected function body under those bindings, not its unresolved callee
implementations or a newly linked image. The configuration seed references
three distinct original `key.ini` string locations and original allocation/
deallocation entrypoints; these are not definitions in a runnable product.

LTCG object records, linked PE/PDB contributions, EH metadata, jump-table/data
owners, import/export/resource closure and full production linking require
additional lanes and are not accepted by this oracle. Win32 smoke only proves
the toolchain can build and run its own small C/C++/resource program.

Static Ghidra observations are a separate analysis aid. The wrapper verifies
target identity and memory bytes, while function boundaries/types and origin
remain review work. Runtime behavior has not been validated against the original.

## Target-free self-tests

```bash
scripts/repo-python -m unittest discover -s scripts/tests -v
```

The focused checks falsify incomplete extents, missing/extra/misnamed/unsupported
relocations, overlapping fields, wrong binding addresses, stale source/object/
manifest receipts, wrong target identity and ambiguous/truncated COFF records.
They also verify DIR32 and REL32 replay with positive and negative addends.

## COFF uninitialized storage

Normal VC7.1 objects may contain a large `.bss` allocation with no raw bytes.
The reader accepts the uninitialized-data flag with raw pointer and relocation
count zero; it does not read that storage from the file or fabricate code.
Code and initialized sections still require file-backed bytes. Mixed BSS/code
or initialized flags, file-backed BSS and BSS relocations remain unsupported
and fail closed. This allows the natural global Video definition's generated
initializer/exit functions to use the existing complete-code lane. It does not
accept linked BSS layout, CRT table placement or general data closure.
