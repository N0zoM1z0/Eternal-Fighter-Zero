# Reader archive and pending Audio reconstruction

The reader was integrated and accepted on 2026-11-06: twenty complete functions,
1,370 code bytes. Its archived files remain unchanged here. Audio remains an
unaccepted draft outside `src/` and reconstruction ledgers. The accepted total
is 73 functions / 32,085 code bytes. Scratch diagnostics confer no exact credit.

## Contents and restore

`PatternReader.cpp`, `PatternReader.h`, `AudioResources.cpp` and `AudioGlobal.cpp`
are the original draft files, preserved byte-for-byte. `integration.patch`
contains the original changes to Context.cpp, Engine.h and Startup.cpp against
commit `4540d24`. `snapshot.json` records all seven original working-source
hashes and the patch hash. The accepted versions of those three files were
restored so existing certificates remain current. No draft code was discarded.

Context.cpp and PatternReader.cpp/.h are already integrated. After reviewing
the remaining Audio patch and checking for new source changes, restore only
the Audio integration from the repository root:

```bash
git apply --check --include=src/Engine.h --include=src/Startup.cpp workbench/reader-audio/integration.patch
git apply --include=src/Engine.h --include=src/Startup.cpp workbench/reader-audio/integration.patch
cp workbench/reader-audio/AudioResources.cpp src/
cp workbench/reader-audio/AudioGlobal.cpp src/
```

The remaining patch introduces `<mmsystem.h>`, expands the provisional Audio
layout and renames SetMode to MaintainLoop. It deliberately does not update
Audio recipes or certificates; that integration is pending.
Retain existing block scopes in Open and ReadLine when formatting: scopes affect
VC7.1 /Od local allocation. No inert code padding or invented ABI is permitted.

## Diagnostic state at handoff

Retained objects and source receipts are in `build/reader/`; logs are in
`.analysis/build/`. Reader and AudioResources used
`/Od /G6 /MT /Gy /GS /W3`; AudioGlobal used `/Od /G6 /MT /Gy /W3`.
These receipts do not attest all header dependencies or replace formal replay.

| Draft group / target | Compiled / target bytes | Current diagnostic |
| --- | ---: | --- |
| PatternReader, 20 bodies | 1,370 / 1,370 total | All equal lengths and zero byte differences after explicit scratch relocation |
| Audio ctor 0x40D810 | 95 / 95 | Zero differences |
| Audio dtor 0x40D870 | 190 / 190 | Zero differences |
| Shutdown 0x40D930 | 190 / 190 | Zero differences |
| Initialize 0x40D9F0 | 188 / 188 | Zero differences |
| FillBuffer 0x40DAB0 | 403 / 403 | Local allocation differences remain |
| ReleaseBuffer 0x40DC50 | 118 / 118 | Zero differences |
| CreateBuffer 0x40DCD0 | 245 / 245 | Local allocation differences remain |
| FindFreeSlot 0x40DDD0 | 107 / 107 | Zero differences |
| ReleaseSound 0x40DF50 | 83 / 83 | Zero differences |
| LoadWave 0x40DFB0 | 741 / 755 | Complete body still differs |
| ReadLoopMarkers 0x40E2B0 | 510 / 530 | Complete body still differs |
| MaintainLoop 0x40E4D0 | 251 / 255 | Complete body still differs |
| AudioGlobal | 28 + 15 | Generated helper acceptance pending |

Private `.analysis/probes/reader.py` and `audio-resources.py` use host Python
pefile/capstone. They are scratch diagnostics, including zip-based mismatch
counts that are insufficient for unequal extents. Inventories/bindings/diffs are
`reader-units.json`, `audio-units.json`, `reader-*.json/.diff`, `audio-*.json/.diff`.
Original instruction dumps are `raw-004054*.txt` through `raw-004059*.txt`,
`raw-00408330.txt`, `raw-00408360.txt`, `raw-0040d*.txt`, `raw-0040e*.txt` and
`raw-00786420.txt`. Ghidra queries are retained in `.analysis/ghidra/`.
Do not rerun `write-audio-first.py`: it would overwrite the draft.

## Findings and remaining hypotheses

ReadInt reads four raw bytes; ReadShort/ReadFloat read two/four. Read returns the
transfer count, not void. Reset at 0x405970 is not evidence for a base constructor.
The 12-byte reader view preserves the accepted caller layout, but only two fields
at offsets 0/4 are known; the last word/type alignment is unresolved. An 8-byte
trial changed Context::Load stack offsets. The complete original class size is
not proven. WordFile is a distinct class.

ReadLine retains its original `i - 1` return and unchecked 1,000-byte local
capacity. Printf retains vsprintf and its 256-byte local. Both carry stack cookies.
Do not repair original edge behavior while seeking exact reconstruction.

The draft Audio layout has pointers/sizes/buffers at 0x10/0x268/0x4C0, 150 entries
each, minimum view 0x718. The constructor initializes loop fields and sample/
buffer arrays, leaving window, DirectSound and size members untouched. Review
static BSS initialization separately. Cleanup is conditional on buffer presence;
WAV error paths can leak. Preserve observed behavior, not a cleaned-up redesign.

The complete WAV owner is at 0x40DFB0. It reads an 18-byte WAVEFORMATEX, requires
PCM, keeps the original fmt-descend flags of zero, selects a slot without a new
sentinel guard and creates/fills a DirectSound buffer. Its stack variables/scopes
still need comparison against the retained original disassembly.

The marker parser scans a 320-byte tail for cue/adtl and computes byte positions.
Original multi-byte assembly uses repeated shifts by 8; the draft's multipliers
are a hypothesis for its 20-byte size shortfall. This is not a verified fix.
MaintainLoop's four-byte shortfall also remains unexplained; inspect complete
branch order rather than accepting a size-only match.

Both FillBuffer memcpy calls in the original target go to 0x778600. A prior
scratch guess of 0x778410 was wrong and has been corrected in the private script.
Independently review all destinations before formalizing relocation bindings.
Audio's generated initialization/destruction wrappers are candidates at 0x786460
(28 bytes) and 0x7864A0 (15 bytes), global Audio at 0x7B0B60 and atexit at 0x777F05.
Verify them and classify as generated, not authored.

## Integration gate

1. Finish complete Audio comparisons and independently review all Audio
   boundaries, origins and relocation destinations. Reader acceptance is in
   docs/evidence/reader-exact.json; do not republish archived scratch diagnostics.
2. Replace the startup callee `?SetMode@Audio@@QAEXF@Z` with
   `?MaintainLoop@Audio@@QAEXG@Z`. Its target stays 0x40E4D0.
3. Audio recipes depend on Engine.h. Reader/Context dependencies and the Read
   return-type symbol correction were completed in the reader checkpoint.
   Use explicit profiles and complete COFF extents.
4. Engine.h changes involve 62 existing units; Config and reader are untouched.
   Select only the involved old and new units. Recompile the effect dispatcher
   and refresh compiler-local symbol IDs without changing target destinations,
   the complete 14,305-byte extent, or its internal local-offset checks.
5. Use complete strict oracle reports and cold source/dependency identities
   before changing ledgers, public certificates or generated progress. Existing
   private `replay-shared-header.py` and `publish-frame-certificates.py` are
   examples to adapt, not commands to run blindly: selection/output paths and
   proof grouping are still specific to earlier checkpoints.
6. Run target-bound tracking validation and CI. Commit verified progress locally;
   push only on a new explicit operator instruction.
