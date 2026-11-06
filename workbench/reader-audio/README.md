# Archived reader and Audio reconstruction drafts

Both owners were integrated and accepted on 2026-11-06. Reader contributes
20 functions / 1,370 code bytes; Audio contributes 12 / 3,159. The two AudioGlobal
helpers contribute 43 auxiliary bytes and no authored credit. That integration
checkpoint reached 85 functions / 35,244 code bytes. Public proofs are in docs/evidence/;
these historical scratch diagnostics independently confer no progress credit.

## Preserved contents

`PatternReader.cpp`, `PatternReader.h`, `AudioResources.cpp` and `AudioGlobal.cpp`
are the original draft files, preserved byte-for-byte. `integration.patch`
contains the original changes to Context.cpp, Engine.h and Startup.cpp against
commit `4540d24`. `snapshot.json` records all seven original working-source
hashes and the patch hash. The accepted versions of those three files were
restored so existing certificates remain current. No draft code was discarded.

All three integration.patch hunks are now integrated into accepted sources.
Do not apply the patch or copy these drafts over src/: AudioResources.cpp here
predates the verified scope, initialization and branch corrections. The original
snapshot remains byte-for-byte evidence; current implementation is authoritative
in src/PatternReader.cpp/.h and src/AudioResources.cpp/AudioGlobal.cpp.

## Historical diagnostic state at 2026-11-01 handoff

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

## Historical findings and hypotheses

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

## Completed integration

The reader checkpoint (b811817) independently reviewed twenty complete bodies,
41 relocations and nine affected Context.cpp bodies using two cold artifacts.
The int-returning Read declaration and all Context dependencies were corrected.

The subsequent Audio checkpoint resolved all five differing bodies, reviewed
all twelve complete boundaries and 85 relocations, and accepted both generated
global wrappers with six explicit bindings. Sixteen cold source/profile artifacts
covered 14 new bodies and 62 Engine.h-dependent units. Reader and Config were
unaffected. No original destination, body extent or dispatcher local-offset check
was shortened or masked. Current evidence and the explanation of scopes, repeated
shifts, initialization and early returns are in
[the knowledge base](../../docs/KNOWLEDGE_BASE.md#audio-resource-and-loop-owner).

Private final replay is .analysis/exact/audio-and-affected.json; corrected draft
trials and complete differences remain in .analysis/probes/audio-next/.
The original table above describes the archived draft only. Future work starts
from accepted src/ and the current handoff, without rerunning historical writers
or a full cold cohort.
