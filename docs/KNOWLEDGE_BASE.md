# EFZ knowledge base

Only conclusions supported by the locked EFZ input belong here. Compiler and
engine similarities with other games are hypotheses until compared with EFZ.

This file preserves target findings and historical checkpoints in order. Counts,
"open" statements and proposed next steps in an older checkpoint describe that
checkpoint. Consult [PROGRESS.md](PROGRESS.md), the live reviewed ledgers and
[RE_HANDOFF.md](RE_HANDOFF.md) for current acceptance and operator task state.
Later findings explicitly supersede earlier provisional names or interpretations.
The 2026-11-07 statement that reconstruction had stopped is a historical
checkpoint, superseded by the 2026-11-08 request to continue through a receiving
agent. Follow `RE_HANDOFF.md` for current task state and operator instructions.

## Target identity

The supplied RAR has SHA-256
`d6ee77ec446c9a66667c666ad4c8075eb86dc1100c85788de39dbeb33fcc2279`.
Its root `EFZ.exe` and nested `EFZ/EFZ.exe` are identical:
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`,
3,743,744 bytes. This is the canonical reconstruction input.

`EFZ.OLD` has SHA-256
`b2bb32abeb883d6371ff4ee4f7a7fb94a4c60f66f5ee48fb70b976c2513f92fd`
and PE timestamp 2005-10-28 11:45:44 UTC; it is excluded. Bundled netplay
assistants, dxwnd and patch tools are separate artifacts. The archive contains
mixed version descriptions and modifications. The exact upstream release and
whether the main executable carries third-party changes are still unresolved;
do not label it verified unmodified Japanese 4.02.

The canonical PE is i386/PE32, image base `0x400000`, entry `0x778A4A`, linker
7.10 and timestamp 2005-11-25 04:56:47 UTC. CodeView references
`D:\nonotaro\works\EFZ\EFZ.pdb`, GUID
`7327281c-dee2-495c-bb17-c3b43b19b436`, age 1. No original PDB is supplied or
loaded by this workflow. Names in `src/` are provisional reconstruction names.

`scripts/inspect-target.py` independently exports imports, Rich records and
CodeView metadata using only standard-library PE parsing. Its private output
is `.analysis/bootstrap/pe-observations.json`; the archive inventory is beside it.

## Compiler and analysis observations

The Rich records include build 3077 counts at product IDs `0x60`, `0x0f`,
`0x5f`, `0x62` and `0x5a`, alongside 4035/2067/2179/3052 and unversioned
records. Record these numeric observations rather than claiming that one build
compiled every component. The selected existing VC7.1 RTM tree reports
13.10.3077 / 7.10.3077 and is hash-pinned. The initial codegen profile matches
the two functions below; production TU partitions and global flags remain open.

Local Ghidra 12.1.3 completed default analysis and produced **950 non-external
function candidates**. This count excludes imported external functions and is
not a reviewed authored-code denominator. All automatic candidate rows remain
`unreviewed`; reviewed boundaries and origins have separate ledgers.

The local attestation verifies the imported executable SHA, x86 Windows
specification, image base, actual entrypoint and the complete initialized
file-backed bytes of `.text`, `.rdata`, `.data` and `.rsrc`. It does not make
automatic decompilation or inferred types authoritative. Some default-analysis
warnings mention `0x03020100`; retain and inspect those for selected owners.

## Configuration file access

| Original extent, exclusive end | Reconstruction | Exact code bytes | Relocations |
| --- | --- | ---: | ---: |
| `0x405A20..0x405AD4` | `ReadConfigByte` | 180 | 8 |
| `0x405AE0..0x405BDE` | `WriteConfigByte` | 254 | 12 |

Both are complete contiguous Ghidra bodies. Full original disassembly confirms
their frame prologues, conditional paths, final byte return and `ret`, followed
by INT3 alignment before the next entry. The two `__cdecl` parameter loads and
caller-cleanup returns agree with the natural source ABI. These are game-authored
file helpers: they reference the specific `key.ini` data and coordinate Win32
file operations rather than implement a generic CRT primitive.

Three distinct initialized original addresses contain `key.ini\0`:
`0x787378` for the reader and `0x787380` / `0x787388` for the writer's open and
recreate paths. The source deliberately declares three external string bindings;
it does not claim a linked reconstructed data owner yet.

The PE KERNEL32 import table independently binds the following IAT fields:

| IAT address | API |
| --- | --- |
| `0x787038` | `CloseHandle` |
| `0x787040` | `WriteFile` |
| `0x787044` | `ReadFile` |
| `0x787048` | `GetFileSize` |
| `0x78704C` | `CreateFileA` |

Complete original call operands bind the allocation wrapper at `0x777D46` and
deallocation thunk at `0x777E20`. The wrapper pushes the requested size and a
constant before calling its allocation implementation; the deallocation entry
jumps to its implementation. The compiled natural `new unsigned char[size]` /
`delete[]` expressions emit `??2@YAPAXI@Z` / `??3@YAXPAX@Z` under this VC7.1
profile. Exact caller bodies are conditional on these explicit bindings; the
callee bodies themselves are not reconstructed/exact claims.

The reader opens with read/write access, requires file size at least 32, reads
the whole buffer, returns the indexed byte and releases it. The writer reads
the buffer, closes the read handle, changes the indexed byte, recreates and
writes the file, releases the buffer and returns a zero byte. The source keeps
the observed invalid-handle close paths and unchecked transfer behavior. It
does not add error handling absent from the original body.

Initial natural source had the correct 180-byte extent and eight relocations
but 14 different stack-displacement bytes. Moving scalar file state to the
outer scope while retaining the allocated buffer in the conditional scope,
with ordinary local names, produced a complete exact body. Source scope/local
names affect this VC7.1 `/Od` allocation. No target bytes, padding, inline
assembly or instruction patching were used. `/GS` and `/Zi` controls were byte
neutral for this mismatch and are parked.

Cold native replay passed both complete functions with **434/434 bytes** after
all 20 explicitly declared relocations were replayed. Source, manifest, toolchain,
object and target identities are retained in
[`evidence/config-exact.json`](evidence/config-exact.json). Private disassembly,
references and build logs are retained under `.analysis/` and are reproducible
using the documented commands.

## Next owner leads

`0x405BE0..0x405CEC` is the next 268-byte contiguous candidate. It builds a
path through string operations, saves fields from an object and checks a stack
cookie. Its source type/layout and full ownership remain open. Review it with
the local Ghidra wrapper before extending the Config lane. The startup entry
and DirectDraw/DirectInput/DirectSound imports are additional navigation leads,
not recovered subsystem ownership.

## Startup and window ownership

The complete startup entry at `0x401000..0x401666` is 1,638 bytes. Its final
instruction is the three-byte `ret 0x10` at `0x401663`; the following INT3 bytes
are outside the owner. The callback at `0x401670..0x401844` is 468 bytes with
another stdcall return. Both boundaries were rechecked against actual decoded
instructions, rather than adopting the candidate size without inspection.

`src/Startup.cpp` represents both complete bodies. The startup registers the
window class, creates the window and timing events/thread, initializes three
device owners, allocates the context and eight scenes in a nine-slot table,
and runs the Windows message/frame loop. Slot four is null. The frame loop
toggles the context field at `0x1368`, passes its signed 16-bit field at `0xF26`
to the audio owner, dispatches virtual slot one, and waits on the frame event.
The provisional class names do not establish the original class identities.
Opaque storage describes observed allocation sizes/field offsets only.

Ghidra removes the unreachable `0x401564..0x401582` scene-zeroing block from
its pseudocode. The original function still owns those bytes. The recovered
constant conditional retains that complete branch; no target bytes or padding
are embedded. A first complete build was compared before acceptance: `/MD`
introduced DLL-import CRT calls, unlike the original direct `srand` and `time`
calls. The startup-specific `/MT` profile fixes those header declarations.
The previous configuration profile is retained and was not globally replaced.

The complete `/MT` startup initially had 33 stack-displacement differences.
Keeping the MSG/WNDCLASS window state in the outer function and the HWND's use
inside its post-registration scope recovers the original natural local layout:
MSG at EBP-0x1C, WNDCLASS at EBP-0x44, HWND at EBP-0x48. No fake parameters,
register controls or extra dummy locals are used. The input configuration
callee receives an unsigned integer; conversion of the byte result accounts
for the original explicit zero-extension before the call.

Window destruction first gates scene message forwarding with the ready flag,
then frees the nonvirtual scene base allocations, deletes the context and
optional secondary owners, shuts down audio/input/video in that order,
terminates the timing thread and closes three handles. Independent PE import
inspection establishes **timeEndPeriod(1), PostQuitMessage(1000)**. Reading the
literal arguments without resolving their IAT destinations would incorrectly
suggest a sleep call. Default messages delegate to DefWindowProcA.

Reviewed bindings include globals at `0x790100..0x790150`, input/audio owners
at `0x7B0968`/`0x7B0B60`, device methods and eight constructor destinations.
Every relocation has an explicit named binding in the manifest. Allocation
sizes are 0x142F0 for the context and 0x44C/0x560/0x438/0x598/0x474/0x760/
0x448/0x758 for scenes. These exact callers remain conditional on the original
callee/data addresses; their implementations and linked initialization are open.

The compiler also reproduces the complete 44-byte scalar-deleting helpers at
`0x4018F0..0x40191C` and `0x401920..0x40194C`. Their destructor destinations are
`0x406260` and `0x40ECB0`, followed by the original conditional deallocation.
These are reviewed **compiler-generated** origins, not authored progress.
Their strict units and comparison reports are retained as auxiliary ABI proof.

Private evidence: `.analysis/ghidra/disasm-00401000.txt`, the corresponding
startup decompile, `.analysis/probes/startup.py` (independent named binding
inventory), native build logs and `.analysis/exact/startup-selected.json`.
Public complete comparisons are in `docs/evidence/startup-exact.json`.

## Context and pattern lifetime

The original constructor at `0x406070..0x40625D` (493 bytes), destructor at
`0x406260..0x40643D` (477 bytes), and pattern loader at
`0x406E60..0x4070FC` (668 bytes) were reviewed as complete contiguous bodies.
The return instructions and following alignment were checked independently of
Ghidra candidate labels. `src/Context.cpp` provides natural C++ definitions;
`src/Engine.h` now shares the observed layouts with the startup owner.

The context has a nontrivial tail subobject at offset `0x14284`, whose constructor and
destructor bind to `0x405E60` and `0x405F80`. The reconstruction represents it as a member; original inheritance/composition
is not yet established. Natural member lifetime emits those
calls in the correct order. The first three pointers are video/input/audio
owners. The destructor releases 920 COM-style interface pointers at `0x38`
and three additional pointers at `0xE98..0xEA0`, using stdcall virtual slot two.
It releases non-sentinel audio slots (65 entries and the `0xF26` slot), deletes
the pattern array and optional byte buffer, then destroys the tail member.
The interface calling convention is taken from the explicit original pushes
and vtable call, not from inferred decompiler class names.

The constructor initializes sound slots to 150 and preserves the original
configuration-byte/default branches. Bytes `0x21..0x24` and `0x26` drive the
observed fields; numeric/offset field names remain provisional. The full shared
layout preserves the original 0x142F0 allocation size used by startup. Unknown
storage is represented as unknown data, without pretending those fields are
semantically recovered.

The 8-byte pattern element contains an uninitialized count byte, three unknown
bytes and a pointer to 12-byte frames. Its constructor at `0x408310` is 24 bytes
and initializes only that pointer. Its destructor at `0x408270` is 43 bytes;
allocation at `0x4082D0` is 56 bytes and stores the low count byte while using
the signed full integer allocation argument. Reallocating a populated element
is not hardened or silently repaired. The frames contain six 16-bit fields.

This directly contradicts the automatic names suggesting ATL string dispatch
and Concurrency TaskStack at the pattern array cleanup/element destructor.
The 106-byte vector-deleting helper at `0x408200` and 48/35-byte destructor/
constructor iterators at `0x4082A0`/`0x408380` are reproduced by the compiler
from ordinary `new[]`/`delete[]`; those helper bodies are separate generated
origin evidence and are excluded from authored progress.

The loader uses a provisional 12-byte reader view for the pattern-path binding
at `0x787510`, reads the element count, constructs the counted array and fills
frames in the exact original order: offsets 0, 2, 8, 10, 4, 6. It retains the
original unused type read/store, fourteen discarded integer reads and ten
16-byte reads per frame. Reader construction/destruction and integer/raw-read
bindings are `0x408330`, `0x408360`, `0x405700` and `0x405600`. Subsequent original
instruction review establishes that ReadInt reads four raw bytes: the earlier
custom integer-decoder hypothesis was incorrect. The complete file format and
reader class size/alignment remain open; these accepted caller bodies do not
establish complete callee ownership. See the pending reader/audio findings below.

First complete comparisons matched constructor/destructor and the three small
pattern members immediately. The loader initially had 63 stack-offset byte
differences. Natural lifetimes for the scratch buffer, reader/count state and
loop parsing state resolved those differences, without changing instructions,
adding dummy variables or masking fields. Array cookies and generated cleanup
were retained in complete comparison.

Private evidence is in `.analysis/ghidra/decompile-00406*.txt`,
`.analysis/probes/raw-00406*.txt`, `.analysis/probes/context.py` (named original
bindings), and `.analysis/exact/context-selected.json`. Public proofs are in
`docs/evidence/context-exact.json`; the shared-header startup revalidation is
in the refreshed `docs/evidence/startup-exact.json`. No configuration unit needed
replay because it does not include the new shared header.

## Effect activation

`0x406AA0..0x406DA7` is a complete 775-byte activation owner, including the
original integer-constant branch, inactive raw-BMP path and stack-cookie check.
`src/Activation.cpp` preserves both branches. Ghidra pseudocode removes the
entire `0x406C45..0x406D75` raw branch and replaces the cookie call with an
injection; neither is sufficient evidence for reconstructing this owner.

The packed path reads the original effect file and advances past its
`first_byte * 3 + 1` prefix. It decodes all 920 texture slots, advancing only
when the decoder returns a nonzero consumed length; zero reports the decimal
slot index through MessageBoxA. It then loads the object surface and palette.
The retained inactive path formats zero-padded three-digit bitmap paths,
loads each texture and the object bitmap, and uses the bitmap palette entry.
The final surface-property byte is stored at context offset `0xF34`; palette
storage is passed at `0xF35`. No extra file/error handling was invented.

The nine distinct original filename/prefix bindings occupy
`0x787460..0x7874FC`; duplicate object filenames retain distinct addresses.
Decoder, raw surface loader, packed/raw palette loaders and final property
bindings are `0x409470`, `0x408D00`, `0x40B760`/`0x40B640` and `0x40BCC0`.
The raw surface loader writes four 32-bit return values through a hidden
result pointer and returns that pointer. A normal 16-byte `SurfaceRect`
return reproduces both ignored return temporaries in activation; the semantic
field names and complete Video implementation remain provisional.

The new `/GS` profile binds the cookie at `0x78F050` and compiler-injected
fastcall check at `0x7781DC`. Both relocation fields are included in strict
comparison. The first source was 820 bytes; correcting buffer/state lifetimes
and using a 100-byte source error buffer reproduces the original 775-byte
body and EBP-0xE4 frame. That source array capacity is not claimed as a uniquely
recovered original declaration. Ordinary nested scopes retain the original
handle, decode cursor, allocation and formatting-buffer lifetimes; there are
no dummy locals, assembly wrappers or byte padding.

`Context::LoadObjectFile` at `0x406DB0..0x406E5D` is a complete 173-byte helper.
It opens/reads the file, skips the same prefix, calls the decoder with its
original byte arguments, closes the handle and deletes the buffer. An early
size-only check was insufficient: full relocation replay exposed eight stack
bytes that still differed. Scalar/buffer scoping resolved them, and only the
complete final zero-difference result is accepted.

Public proof is `docs/evidence/activation-exact.json`. Private full original
Ghidra disassembly and binding inventory are in `.analysis/ghidra/` and
`.analysis/probes/activation.py`. The shared Video declarations changed in
`src/Engine.h`, so the 13 dependent startup/context/pattern bodies were checked
again using unchanged compiled COFF artifacts grouped by identical recipe.
That first verification required only three cold source/profile builds,
including activation. Final activation source cleanup rebuilt only its one
recipe. Configuration units were untouched. Existing recipes can reproduce
the comparisons using the standard explicit `--unit` replay interface.

## Surface transfer

`src/Surface.cpp` recovers the complete 905-byte raw bitmap loader at
`0x408D00..0x409089`, 711-byte packed decoder at `0x409470..0x409737`, and
69-byte rectangle factory at `0x40C590..0x40C5D5`. Return instructions and
following alignment were reviewed. The factory is an ordinary cdecl function
returning four integers by value, not a thiscall rectangle constructor.
It sets left/top to x/y and right/bottom to x+width/y+height. This recovers
the otherwise externally bound rectangle-return behavior in the surface path.

The minimum Video view now includes the DirectDraw pointer at `0x20808`;
its complete object extent and initialization remain open. The pinned historical
SDK reproduces standard IDirectDraw::CreateSurface (slot 6) and surface Lock /
Unlock (slots 25 / 32), with stdcall COM arguments. Descriptors have dwSize
108, flags 7, caps 0x840, and lock flag 1. Only the original assigned fields
are initialized; the source does not zero descriptor storage absent from the
original code. Full native comparison covers the fixed slot offsets too.

The bitmap path reconstructs dimensions from independent byte pairs at 18/19
and 22/23. Width uses signed remainder in
`width += (4 - width % 4) * (width % 4 > 0)`, including both negative-remainder
correction branches that Ghidra removes as unreachable. The rounded width is
used for allocation, row transfer and the returned rectangle. Pixel offset is
only the low byte pair at 10/11, not a silently corrected 32-bit BMP field.
Rows are copied bottom-up, adding the byte palette offset before truncation.
The original unchecked read/lock behavior and create-failure path (which
returns a zero rectangle without closing/freeing the file allocation) remain.

The packed path reads little-endian width/height byte pairs and starts its
consumed-byte counter at four. Marker zero selects bottom-up uncompressed
transfer. Nonzero marker selects forward-row RLE: literals at or below the
marker replace the palette-biased current pixel; larger bytes set the repeat
count to encoded-marker-1. Each branch advances the input counter separately.
Repeat count and current pixel persist across row boundaries. Palette sums
truncate on byte storage. Creation failure reports the original error binding
and returns zero; success returns the consumed byte count. Unlock's original
unused HRESULT assignment is preserved.

First complete source comparisons were obtained early: bitmap 902 versus 905
bytes, packed 708 versus 711, rectangle factory already exact. SDK interface
slots and substantive decode expressions agreed; exact original branch order,
duplicated cursor increments, stored HRESULT, and ordinary descriptor/state
lifetimes resolved remaining differences. A two-field Dimensions aggregate
recovers the bitmap width/height slots without dummy locals. Source scopes and
names are reconstruction choices, not uniquely recovered original declarations.
No target bytes, inert padding or forced-register ABI declarations were used.

The complete final bodies match all bytes after explicit relocations. Public
proof is `docs/evidence/surface-exact.json`. Private original disassembly and
named binding inventory are `.analysis/ghidra/disasm-00408d00.txt`,
`disasm-00409470.txt` and `.analysis/probes/surface.py`. The rectangle factory
has no relocations; raw/packed bodies have ten/two. Error data bindings are
`0x7877D4` and `0x787824`. Source grouping required four cold translation-unit
artifacts for new and shared-header-dependent comparisons, rather than one
compiler invocation per function. Configuration units were not replayed.

## Palette and blend tables

The reviewed original bodies below are represented in `src/Palette.cpp`.
Ends exclude the following alignment bytes. All five complete bodies pass
strict comparison in `docs/evidence/palette-exact.json`.

| Provisional owner | Complete range | Bytes |
| --- | --- | ---: |
| Video constructor | `0x401950..0x4019AF` | 95 |
| Bitmap palette loader | `0x40B640..0x40B75C` | 284 |
| Packed palette loader | `0x40B760..0x40B89C` | 316 |
| Blend table builder | `0x40B8A0..0x40BCBE` | 1,054 |
| Surface property reader | `0x40BCC0..0x40BD25` | 101 |

The constructor clears byte `0x4` and fills 512 unsigned-short entries at
`0x20406` with `(i - 256) * (i - 256) / 4`. The table builder uses its midpoint
at `0x20606` for signed channel differences. This evidence extends the minimum
Video layout while preserving the DirectDraw pointer at `0x20808`; it does
not close the object's full extent or all initialization.

Both palette loaders return an integer and take three full-width integer
source/destination/count arguments. Earlier void-return/byte-argument declarations
were hypotheses contradicted by the complete callees. Corrected COFF symbols
are recorded in the activation recipe; activation still compares exactly.
The bitmap loader begins at fixed offset 54 and reads BGRx entries with stride
four. The packed loader begins at one and reads BGR triples with stride three.
Both write red/green/blue/zero into four-byte destination entries. Neither
validates the read length. The packed invalid-handle path closes that invalid
handle and returns zero; the bitmap path has no such check. Success returns
one. These behaviors are retained rather than replaced with a general parser.

The actual ignored archive resources provide an independent format check:

| Resource | Bytes | First byte | SHA-256 |
| --- | ---: | ---: | --- |
| `SYSTEM/object.dat` | 154,628 | 254 | `9fb3e71425963fea2d0b6cb5f525ef4bbd87a6477679b5c06ada4f6abd5ce27c` |
| `SYSTEM/EFFECT/effect.dat` | 5,202,559 | 80 | `434b6d73d185e3f6fcf1b11747288975bb3344525ad495cbdd1518160a47cda7` |

The palette loader ignores that first byte and uses its supplied count.
Activation requests source zero, destination 175 and count 80. In contrast,
the packed texture callers skip `first_byte * 3 + 1` bytes before decoding.
The archive contains no object bitmap for the inactive raw path. These file
observations do not resolve upstream release/modification provenance.

The substantial table builder searches nearest colors for both channel means
and channel sums clamped to **254**, using the constructor's quantized squared
distance. Mean/sum output matrices start at Video offsets `0x405`/`0x10405`.
For outer entries 0..255 it visits paired entries below `min(i + 1, 255)`;
each candidate search visits entries **1..254**. Best distances start at 40,000,
updates require strict improvement, and equal-distance ties keep the first
winner. The original repeated distance expressions remain repeated. Finally
it mirrors the triangle only for entries 0..254. Column 255 retains its prior
contents. A destination also remains untouched if no candidate improves the
initial distance. The source does not silently fill these retained entries.

The surface property reader locks a 108-byte historical SDK descriptor, reads
one full 32-bit word, masks to the low byte, unlocks, and returns that byte.
Its unused offset-54 assignment and stored Lock HRESULT are original code,
not invented state. The COM slots and all instructions compare exactly.

Initial complete table source was close in size but had different stack
allocation. Once expression grouping, embedded cursor increments and pointer
formation agreed, diagnostic instruction alignment isolated scope/name layout.
Separate normal counter scopes recover the 0x78-byte frame. Numeric locals,
semantic comments and a stable declaration order recover VC7.1 `/Od` slot
ordering. They are reconstruction choices, not original variable identities.
A controlled name permutation also required preserving name declaration order;
permuting names alone left 59 differing bytes. The final unmodified compiler
output passes all 1,054 bytes, including frame, slots and branches. No normalized
or masked comparison is used for acceptance, and no padding, extra locals,
assembly or target-byte arrays are present.

Private supporting evidence is `.analysis/ghidra/decompile-0040b8a0.txt`,
`.analysis/probes/raw-0040b8a0.txt`, `palette.py`, `palette-slots.py` and
`palette-assets.json`. New and shared-header-dependent revalidation checked
23 complete bodies with five cold source/profile artifacts reused unchanged
within each recipe. Configuration units were not rebuilt. Public certificates
for startup, context, activation and surface transfer have refreshed dependency
identities. The original game and a reconstructed whole product remain unrun.

## Display device lifetime

Direct original call-operand review corrects an earlier handoff hypothesis:
`0x4019B0` is a 614-byte file transformation utility, not device initialization.
It reads `system0\\object.bmp`, XORs bytes after its ten-byte prefix with 100,
and writes `system\\object.dat`; its analyzed caller set is empty. This does
not prove it is unreachable through every possible indirect path. Startup
actually calls **`0x4083B0`**, whose complete code returns an integer, so the
previous void-return declaration was also corrected. Startup still compares
exactly under the corrected COFF symbol.

`src/Device.cpp` recovers the following complete authored bodies. The original
return instructions and following alignment were reviewed independently of
Ghidra's candidate names and calling-convention guesses.

| Provisional owner | Address | Bytes |
| --- | --- | ---: |
| Initialize | `0x4083B0` | 654 |
| Recreate8Bit | `0x408640` | 519 |
| Recreate16Bit | `0x408850` | 519 |
| Shutdown | `0x408A60` | 231 |
| Destructor | `0x408B50` | 231 |
| ReleaseSurface | `0x408C40` | 46 |
| RequestClose | `0x408C70` | 34 |
| RestorePrimarySurface | `0x408CA0` | 48 |
| RestoreSurface | `0x408CD0` | 42 |

Initialization stores the raw mode byte at offset four and HWND at zero,
creates DirectDraw through its original import thunk at `0x776A62`, and sets
cooperative flags `0x13`. Mode equal to one selects 640x480; other values
select 320x240. Initial depth is eight. The primary descriptor has size 108,
flags `0x21`, caps `0xA18` and one back buffer. Its width/height use the raw
byte in `mode * 320 + 320` / `mode * 240 + 240`; they do not normalize it to
a boolean. Back-buffer caps are four. Initialization creates a palette from
256 PALETTEENTRY values at offset five and attaches it to the primary surface.
The two final palette calls retain their original unchecked results.

Every checked failure displays its distinct original message/title binding and
calls RequestClose. That helper posts WM_CLOSE to the stored window and returns
**one**, as do successful initialization and recreation. The code does not
invent zero failure returns or add cleanup before posting. Both recreation
functions release back and primary surfaces first, retain the palette interface,
and rebuild at their selected depth without creating or reattaching a palette.
The exact descriptor assignments and original error branches are preserved.

Shutdown and destruction independently release palette, back surface and primary
surface, zeroing each nonnull pointer. They then restore the display mode,
release DirectDraw and zero its pointer. The surface helper releases and zeros
its caller's pointer. Restore helpers call the historical surface Restore slot
27 and return zero for any nonzero HRESULT, one for zero. RequestClose uses the
independently verified USER32 PostMessageA IAT entry `0x787180`.

The shared Video view now represents HWND, the palette at `0x5`, both previously
recovered blend matrices at `0x405`/`0x10405`, the distance table at `0x20406`,
and DirectDraw/primary/back/palette interfaces at
`0x20808`/`0x2080C`/`0x20810`/`0x20814`. The native model occupies `0x20818`
bytes, the interval from original Video global `0x790150` to the neighboring
Input global `0x7B0968`. This is compatible with the observed allocation and
consumers; it does not uniquely recover original declarations or TU grouping.

Global lifetime establishes why `0x408B50` is destruction rather than a second
arbitrarily named shutdown. Original initializer `0x786420` constructs Video
at `0x790150` and registers wrapper `0x786480` through the CRT exit routine at
`0x777F05`. That wrapper calls `0x408B50` on the same object. A natural
`Video video;` definition in `src/VideoGlobal.cpp` reproduces the complete
28-byte initializer and 15-byte exit wrapper. These two compiler-generated
helpers are auxiliary evidence, excluded from authored exact totals. Their
public proof is `docs/evidence/video-global-exact.json`. Linked CRT table
placement, all other globals and complete product startup remain open.

The first complete Device.cpp comparison already had the original lengths.
Only 21/17/17 stack-displacement bytes differed in initialization/recreation;
the five initially included smaller bodies were already exact. Keeping scalar
HRESULT/caps outside the normal descriptor scope recovers the original frame
and slots, without dummy locals or byte padding. All nine final bodies are
complete strict exact in `docs/evidence/device-exact.json`. Revalidation used
seven cold source/profile artifacts for 34 new/shared-header-dependent bodies;
configuration recipes were untouched.

The global definition exposed a COFF-reader defect: VC7.1 advertises the `.bss`
allocation size (133,144 bytes) with raw pointer zero, while the previous reader
required that allocation to fit inside the object file. The reader now accepts
this unbacked, uninitialized-data shape without synthesizing file bytes. It
still rejects missing raw code/data, mixed BSS/code or initialized flags, raw
BSS storage and BSS relocations. Two new target-free tests cover a real-shaped
large BSS neighbor and malformed variants. Microsoft's
[section table and data specification](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#section-table-section-headers)
describes the uninitialized-data flag and zero raw pointer; the retained
nonzero allocation size here is directly observed VC7.1 object evidence.
This adds no linked-data acceptance lane or relaxation to function comparison.

Private evidence includes `.analysis/ghidra/decompile-004083b0.txt`,
`decompile-00408850.txt`, `callers-00408b50.txt`, `callers-00401950.txt`,
`callers-004019b0.txt`, and `.analysis/probes/raw-00408*.txt`,
`raw-00786420.txt`, `Device-first.cpp`, `device.py`, and `video-global.py`.
The 865-byte target at `0x40A440` is now boundary-reviewed as
`Video::DrawCharacterTint`. Its `ret 0x30` is at `0x40A79E`, so the body ends at
`0x40A7A1`; the next Video method starts at `0x40A7B0` after 15 INT3 alignment
bytes. A natural C++ owner is present in `src/VideoCharacterDraw.cpp` under the
focused `video-draw-character-tint` unit. It reconstructs the four-sided clip,
the source-right-relative mirror transform, source/destination DirectDraw lock
flags (`0x11` and `1`), the special `DDERR_SURFACELOST` return, color-key
handling, `sumBlend[pixel][tint]` lookup and destination-then-source unlock
order. It also preserves the original early return on a failed destination lock
without unlocking the already-locked source surface.

This is a semantic source candidate, not an exact reconstruction. The pinned
VC7.1 `/Od` object is 1,202 bytes versus the target's 865 bytes, with no
relocations; strict comparison rejects the differing complete extents. A
register-oriented pointer-loop control is 1,237 bytes. The target's inner loops
explicitly manipulate AH/AL and push/pop ESI/EDI within branch bodies, while
ordinary C++ emits stack-based loop state. No exactness credit is assigned;
continue exploring natural C++ layouts before considering any assembly-based
recovery. The 14,114-byte `0x401C20` state dispatcher was subsequently accepted
as described below; that acceptance is independent of this rendering owner.

The adjacent 799-byte `0x409A90` target is now boundary-reviewed as
`Video::DrawSurface`. Its `ret 0x2c` is at `0x409DAC`, ending at `0x409DAF`;
the next Video method starts at `0x409DB0` after one INT3 byte. The natural C++
owner is in the same `src/VideoCharacterDraw.cpp` file under unit
`video-draw-surface`. It preserves the same clipping and original-right-relative
mirror transform, source/destination DirectDraw lock flags, lost-surface return,
transparent-key branches, and destination-then-source unlock order. The pinned
VC7.1 `/Od` object is 1,098 bytes; a pointer-row/register-hint probe is 1,079
bytes. Both remain larger than the 799-byte target and strict comparison
rejects the complete extents. These are semantic C++ candidates, not exact
owners; the target's body-local ESI/EDI saves and AH/AL loops remain unrecovered.

The 897-byte target at `0x40A0B0` is boundary-reviewed as
`Video::DrawBlendedSurface`. Its `ret 0x30` is at `0x40A42E`, ending at
`0x40A431`; the next method begins at `0x40A440` after 15 INT3 bytes. The
natural C++ owner is in `src/VideoCharacterDraw.cpp` under unit
`video-draw-blended-surface`. It reproduces the low-signed-byte mode check
(only 0/1 accepted), selects the adjacent `meanBlend`/`sumBlend` 64 KiB table,
indexes it with source pixel in the high byte and destination pixel in the low
byte, and preserves the key/flip, clipping, Lock and Unlock paths. The pinned
VC7.1 `/Od` object is 1,362 bytes versus the 897-byte target, with no
relocations; strict comparison rejects the complete extents. All five pixel
kernels now have independent reviewed boundaries, focused units and natural
C++ semantic owners, but none has exactness credit.

The 808-byte target at `0x40AAE0` is now boundary-reviewed as
`Video::DrawCharacterSpecial`. Its `ret 0x2c` is at `0x40AE05`, ending at
`0x40AE08`; the next Video method starts at `0x40AE10` after eight INT3 bytes.
The natural C++ owner is in `src/VideoCharacterDraw.cpp` under unit
`video-draw-character-special`. It preserves the unusual three-pixel minimum
left edge, source-rectangle clipping/mirror transform, DirectDraw lock/error
flow and destination-then-source unlock order. With a nonzero color key, the
source surface is a mask: non-key mask pixels copy the destination pixel at
`x-3` into `x`; mirror reverses the mask read, not the destination shift. With
key zero, every destination pixel is shifted from `x-3` and the mask is not
read (the source surface is still locked). The left-edge clamp protects those
three-byte look-behind reads. The pinned `/Od` candidate is 1,167 bytes; a
pointer-row/do-while control is 1,066 bytes, while the `/O2` pointer-row control
is 601 bytes. All are larger or smaller than the 808-byte target and strict
comparison rejects the complete extents. No exactness credit is assigned.

The target's 3-pixel source of the destination copy is not a palette blend or
an offset in the source mask: it is a rightward in-place shift of the back
surface, gated by the mask only when the color key is nonzero. The descending
column loop is important because each pixel reads three bytes to its left;
processing right-to-left preserves the unmodified input pixels.

The ordinary, blended, tint, shadow and special rendering kernels now all have
natural C++ semantic owners in `src/VideoCharacterDraw.cpp` and focused build
units. None has passed complete strict code comparison. The target bodies use
hand-shaped register loops and local ESI/EDI saves that remain open research;
these semantic implementations are not byte-exact claims.

A focused tracking audit also exposed a pre-existing certificate problem.
`17edf49` changed `SecondaryPose::field000c` in `src/Engine.h` from `short`
to `unsigned short` after the prior exact certificates were generated. The
current header hash is `6a561f04...`, while the public certificates still bind
`33ba6c7d...`. Of 328 exact-ledger entries, 296 have stale dependency hashes.
This is not caused by the new tint unit, which is not in the exact ledger. No
full cold replay or blind receipt rewrite was run; the affected exact units need
selective rebuild/revalidation before the public tracking validator can pass.

## Effect state dispatch

`src/EffectUpdate.cpp` recovers the complete large owner at `0x401C20`.
Its **14,114 instruction bytes** end at `0x405342`, immediately followed by
136 bytes of switch destinations and 55 bytes of compressed case indices.
The complete 14,305-byte contribution ends at `0x405401`; the following
alignment before `0x405410` is excluded. Both original tables were independently
reviewed: 33 explicit cases within state values 0..54, one default destination,
34 destination pointers and 55 index bytes. Ghidra's 14,114-byte body inventory
remains unchanged; the reviewed contribution boundary also includes its tables.

This owner handles a 640-slot effect queue. Initial character-state naming was
a hypothesis, replaced after reviewing the actual spawn/delete consumers and
slot-array extent. No original class or member identifiers are claimed.
The corresponding reviewed authored helpers in `src/EffectPool.cpp` are:

| Owner | Address | Bytes |
| --- | --- | ---: |
| EffectSpawn constructor | `0x405490` | 30 |
| EmitEffect | `0x407100` | 406 |
| RemoveEffect | `0x4072A0` | 193 |
| AdvanceEffectWrite | `0x407370` | 327 |

The 72-byte spawn record is naturally initialized with memset. EmitEffect
copies only the observed fields, initializes frame/tick to zero, records active
and owner values and advances the write cursor. It does not clear the remaining
slot storage. Active/owner arrays start at `0x1384`/`0x1D84`, byte flags at
`0x2784`, and 640 112-byte slots at `0x2A08`, ending exactly at the existing
pattern pointer `0x14208`. Fields include unsigned-short type/frame/tick,
double position/velocity, facing, group, layer, payload and palette. Unknown
regions remain data. Signed-short queue cursors retain their original wrap at
640 and original handling of owned versus inactive entries. Deletion clears
active/owner and skips inactive entries at the read cursor. Advancement always
moves at least once, adjusts a colliding read cursor, and stops after finding
an owner-zero slot or trying 640 entries.

The dispatcher preserves all child-effect parameters that Ghidra's pseudocode
omits, including integer-truncated positions, facing, group/layer, selector-
derived type and palette values, and the order of removal and subsequent
emission. Special frame events at 10/15/26, conditional emission flag `0x1366`,
shared angular phase/limits, drag, gravity and bounce branches remain intact.
The first pattern-frame word is a duration, as demonstrated by tick comparisons;
the earlier provisional `x` field was renamed accordingly. The loader's native
bytes remain exact. Selector `0x134D` and emission flag `0x1366` use signed-char
loads, which corrected the shared provisional declarations.

Floating-point details are part of the recovered behavior. State 10 uses an
integer `rand() / 2000` speed before double conversion. Other states retain
double division, signed integer angular division, float sin/sqrt overloads,
short truncation, original approximate constants, expression grouping and
x87 spill/evaluation order. No replacement random source, trigonometric
simplification, saturation or extra failure handling was introduced.

The first complete contribution was 14,172 bytes against 14,305. Full original
review corrected completion-only emissions, palette/group values, short prefix
increments and float conversion order. Writing the facing factor before the
trigonometric subexpression reproduces its original temporary spills. Ordinary
case scopes retain all local lifetimes; renaming the shared horizontal scalar
recovers root-slot ordering without extra locals. The final frame is the original
0x2DC bytes. Source names/scopes are reconstruction choices. A private normalized
instruction diagnostic helped locate differences, but acceptance compares every
unmodified COFF byte, including all 191 local-table bytes and all 301 explicitly
bound relocation fields. There is no prefix credit or masked-address mode.

Public proof is `docs/evidence/effect-exact.json`, covering the owner and all
four helpers. Four float-overload/sinf/sqrtf bodies at `0x405410`, `0x405430`,
`0x405450`, `0x405470` also reproduce exactly (90 bytes total) from the pinned
VC7.1 math.h implementation. They are classified standard-library, excluded
from authored totals, and recorded in `docs/evidence/effect-math-exact.json`.
The seven earlier compiler-generated helpers remain separately excluded.

The oracle still compares the entire positive COFF contribution. Optional
`code_size` and reviewed contiguous `local_data` segments attribute instruction
and local-table bytes; they never shorten that comparison. Tracking validates
the certificate's attribution, reports code and associated data separately,
and rejects incomplete/gapped/overlapping/unreviewed splits. The focused test
also changes a table byte under a matching code prefix and requires mismatch.
All 36 internally defined dispatcher symbols must retain their actual COFF
relative offsets under relocation; a second focused test rejects rebinding them
to invented destinations. The existing 43 compiled artifacts still pass this
stronger gate, without any additional cold build.
This supports compiler-generated tables inside a single reviewed contribution;
general cross-contribution linked data and whole-product linking remain open.

Final selected verification used nine cold source/profile artifacts for 43 new
or shared-header-dependent functions. All compare exactly; configuration units
were untouched. Retained evidence includes `.analysis/probes/raw-00401c20.txt`
(full instruction dump), `effect-case-*.txt`, `EffectUpdate-first.cpp`,
`EffectUpdate-operator-baseline.cpp`, `effect-update.py`, `effect-pool.py`,
and `.analysis/ghidra/decompile-00407100.txt`, `decompile-00407370.txt`.
No game runtime comparison has been performed.

## Effect frame and word files

`src/EffectFrame.cpp`, `ContextState.cpp`, `PaletteFade.cpp`, `WordFile.cpp`
and `AudioVolume.cpp` recover 19 complete authored functions / 4,537 instruction
bytes. Public proof is `docs/evidence/frame-exact.json`.

| Owner | Address | Bytes |
| --- | --- | ---: |
| RemoveEffectsOfType | `0x4074C0` | 150 |
| ClearEffects | `0x407560` | 76 |
| UpdateEffects | `0x4075B0` | 97 |
| RenderEffects | `0x407620` | 919 |
| ResetState | `0x406440` | 322 |
| ProbeCharacterData | `0x408100` | 246 |
| UpdateFrameControls | `0x4079C0` | 369 |
| UpdateCameraShake | `0x407B40` | 415 |
| UpdatePaletteFade | `0x407D10` | 811 |
| DarkenPalette | `0x40BE20` | 249 |
| LightenPalette | `0x40BF20` | 336 |
| WordFile constructor | `0x405E60` | 33 |
| WordFile destructor | `0x405F80` | 33 |
| OpenRead | `0x405E90` | 106 |
| OpenWrite | `0x405F00` | 67 |
| Close | `0x405F50` | 43 |
| ReadWord | `0x405FB0` | 112 |
| WriteWord | `0x406020` | 72 |
| Audio SetSoundVolume | `0x40E5D0` | 81 |

Several earlier names/layout hypotheses required correction. `0x408100` probes
six character data paths, rather than performing generic state initialization.
The first group is misuzu/minagi/kano, the second exnanase/ikumi/kaori. Mode byte
`0x1341` starts at one; any failed first-group open sets zero, and any failed
second-group open sets -1, overriding the first group's result. Both groups
attempt every path and close even INVALID_HANDLE_VALUE. Original distinct string
bindings occupy `0x78752C..0x78758C`. The constructor's method name and relocation
were corrected, with complete native revalidation.

The former 0x6C-byte ContextTail view conflated a file-state prefix with later
Context effect counters. The observed four-word file state is now represented
by WordFile at Context `0x14284`: exhausted flag, HANDLE, remaining bytes and
transferred bytes. Effect phase/angle/frame fields start separately at `0x14294`.
The model still occupies original Context allocation size `0x142F0`, independently
visible in startup's allocation operand. Names and this source partition are
reconstruction choices, not uniquely recovered original declarations. Moving
the effect fields out of the former tail type preserves every byte of the large
dispatcher; changed compiler-local symbol identities were refreshed without
changing their reviewed original destinations or local-offset checks.

Rendering proves the pattern frame's second word is an unsigned texture index,
not the former provisional y coordinate. Following u/v/width/height words are
signed shorts. The slot layer is an unsigned byte, while group remains signed.
The loader/producer code and all dependent functions still compare exactly.
RenderEffects follows the live read/write ring, filters active entries by layer,
constructs the source rectangle through the ordinary hidden structure return,
and retains both copies generated by VC7.1 assignment. Mirrored positioning,
integer-truncated positions, payload-dependent camera offsets, baseline 210,
color key and group-dependent normal/blended draw calls are preserved. Draw
callees at 0x409A90 /0x40A0B0 now have natural C++ semantic owners in
src/VideoCharacterDraw.cpp; strict exact codegen and the complete rendering
runtime remain open.

UpdateEffects also uses the live write cursor while UpdateEffect may emit new
entries. It does not snapshot the queue boundary. RemoveEffectsOfType executes
its do/while body even for an initially empty ring and scans through the write
slot, stopping at `write + 1 - 640 * (write == 639)`. ClearEffects clears only
active/owner arrays; ResetState separately resets cursors and the observed
camera, fade, counter, selector and timing fields. No additional clearing or
input validation was added.

Frame controls retain signed-short countdowns and volume interpolation toward
the target, with original comparison operand order. Camera shake uses amplitude
threshold one, separate cosine/sine phases, increments 83/107, single 360-degree
subtractions, hold time and decay 0.95. Ghidra's pseudocode omitted multiplication
by amplitude before integer conversion; original x87 instructions recover it.
The signed fade-direction owner retains attack/hold/release branches, integer
percentage truncation and the original x87 comparisons at 0/100/-100.

Palette helpers use natural 256-entry PALETTEENTRY buffers. GetEntries/SetEntries
both cover 255 entries, the supplied begin/end range is end-exclusive, flags
remain from GetEntries, and entry 255 is not changed. Darkening computes
`channel * amount / 100`; lightening computes
`(255 - channel) * (100 - amount) / 100 + channel`. Signed integer division and
byte truncation remain intact. HRESULTs are unchecked as in the original.
Audio's minimum view exposes the buffer array at `0x4C0`; SetSoundVolume skips
sentinel 150, checks the selected pointer, and forwards through DirectSound
buffer SetVolume slot 15. Complete Audio layout/lifetime is still open.

WordFile read-open uses GENERIC_READ with **OPEN_ALWAYS**, records GetFileSize,
and resets transfer/exhaustion state. Write-open uses CREATE_ALWAYS. Close clears
the handle; destruction closes a nonzero handle without clearing it. ReadWord
checks only the unsigned remaining-byte count, reads two bytes, subtracts two
on success and returns the word. It does not validate actual transfer length;
write uses its own local word copy/count and reports failure with the original
message bindings. These original edge behaviors are retained. The unused initial
remaining/transfer members are not invented constructor initializations.

The 919-byte renderer and most smaller bodies matched on their first complete
build. ProbeCharacterData initially had fifteen stack differences; ordinary
file/table scopes resolved them. WriteWord required recovering its real local
copy/count and failure branch. The 369-byte control owner initially had nine
operand-order differences, corrected by restoring the original comparisons.
The 811-byte fade owner, 415-byte shake owner and both palette helpers matched
on their first complete builds. No padding, dummy locals or forced ABI wrappers
were used.

Final selected verification used fourteen cold source/profile artifacts reused
unchanged for 62 new/shared-header-dependent functions. Every function is strict
exact; configuration units were untouched. Private original evidence includes
`.analysis/ghidra/callers-00401c20.txt`, `decompile-00407620.txt`,
`decompile-00407d10.txt`, and `.analysis/probes/raw-00407*.txt`, `frame.py`,
`EffectFrame-first.cpp`, `ContextState-first.cpp`, `WordFile-first.cpp`.
Existing dispatcher/local-table and standard-library certificates were refreshed.
Whole-product linking and original/reconstructed game runtime remain open.


## Raw file reader and audio loading

These instruction-review findings postdate the accepted frame checkpoint.
The reader and Audio owners were subsequently accepted on 2026-11-06 as
described below. Their earlier drafts remain archived in `workbench/reader-audio/`.

PatternReader::ReadInt at `0x405700` reads four raw bytes through `0x405600`;
ReadShort/ReadFloat read two/four. There is no custom integer decoder here.
Read returns the transfer count. Context now shares the corrected declaration
and matching relocation symbol; its complete translation unit was replayed.
`0x405970` resets two fields and returns 1,
not a demonstrated base-class constructor. Only the reader's handle/buffer at
0/4 are identified; its provisional 12-byte caller view does not prove a third
field or complete original size/alignment.

Audio `0x40E4D0` maintains looping: it checks a selected buffer/sample and loop
end, queries playback position, then stops/repositions/restarts after the end.
The earlier SetMode(short) name was a provisional mislabel. The accepted source
now uses MaintainLoop(unsigned short), with the complete caller replayed. Reviewed
accesses expose loopStart/loopEnd at 0/4, window/DirectSound at 8/0xC, samples
at 0x10, sample sizes at 0x268 and buffers at 0x4C0 (150 entries, minimum view
0x718). This expands the earlier buffer-only view without establishing full
original typing or linked global placement.

The WAV owner at `0x40DFB0` uses MMIO, reads an 18-byte WAVEFORMATEX and requires
PCM before allocation and DirectSound buffer creation/fill. Its complete codegen
is now accepted; whole-product resource closure remains open. Preserve missing checks and
cleanup behavior rather than hardening them during exact reconstruction.
Original FillBuffer calls at `0x40DBBC`/`0x40DBE1` target `0x778600`; a scratch
memcpy binding to `0x778410` was incorrect. The archived workbench records the
earlier mismatches; their resolution is described below.

## Pattern reader exact

On 2026-11-06, twenty complete PatternReader members were accepted from ordinary
C++: 1,370 instruction bytes, with no local tables. The target bodies and all
41 relocation operands were reviewed separately from their cold native
comparison. The provisional names identify an application file-ownership API;
they do not recover original symbols. Constructor/destructor bodies explicitly
invoke Reset/Open and Close; they are authored members, not generated iterators.

| Member | Entry | Complete bytes |
| --- | --- | ---: |
| Open | 0x4054B0 | 235 |
| Close | 0x4055A0 | 95 |
| Read | 0x405600 | 60 |
| ReadLine | 0x405640 | 182 |
| ReadInt | 0x405700 | 30 |
| ReadShort | 0x405720 | 31 |
| ReadFloat | 0x405740 | 30 |
| Write | 0x405760 | 60 |
| WriteInt | 0x4057A0 | 27 |
| WriteFloat | 0x4057C0 | 27 |
| Printf | 0x4057E0 | 110 |
| Seek | 0x405850 | 105 |
| SeekStart | 0x4058C0 | 45 |
| SeekEnd | 0x4058F0 | 45 |
| Size | 0x405920 | 41 |
| IsOpen | 0x405950 | 28 |
| Reset | 0x405970 | 35 |
| LoadBuffer | 0x4059A0 | 125 |
| Constructor | 0x408330 | 40 |
| Destructor | 0x408360 | 19 |

Each body ends at its complete RET instruction; following alignment bytes are
excluded. Conditional branches stay within their reviewed body. No target data
or EH contribution is hidden in these extents. ReadLine and Printf use the
original cookie at 0x78F050 and check at 0x7781DC. Original CRT destinations are
strcpy 0x778080, strlen 0x7784E0, vsprintf 0x77856B, allocation 0x777D46 and
deallocation 0x777E20. The corresponding CRT bodies, original call operands and
PE IAT names support explicit bindings; no relocation fields are masked.

Open closes prior state, derives access/creation flags in their original order,
uses share flags 3 and inheritable SECURITY_ATTRIBUTES, and normalizes an
INVALID_HANDLE_VALUE result to zero. Close frees the optional buffer and resets
the handle/buffer pair. Read/Write preserve unchecked API-result handling and
return the transferred count. ReadLine retains the 1,000-byte local, unchecked
capacity, newline handling and i - 1 return. Printf retains its 256-byte local
and vsprintf. Seek preserves the repeated origin-zero tests and unspecified
method for unsupported origins. LoadBuffer retains repeated Size calls,
size-plus-one allocation and the trailing zero. No original edge behavior was
hardened. Open and ReadLine block scopes preserve observed /Od local allocation.

The complete original class size/alignment remains unresolved: only offsets
0/4 are identified. The provisional 12-byte view preserves the accepted loader
stack layout; the last four bytes remain explicitly unknown. The Read return
type correction changes the Context relocation symbol, not its destination
0x405600. All nine Context.cpp recipes now depend on PatternReader.h.

Formal verification compiled exactly two source/profile artifacts: reader with
/Od /G6 /MT /Gy /GS /W3 and Context with /Od /G6 /MT /Gy /W3. Their 29 complete
units are strict exact, including the three existing generated pattern helpers
which receive no authored credit. Engine.h, Audio and all other source units
were untouched. Public proofs are docs/evidence/reader-exact.json and the
refreshed docs/evidence/context-exact.json. Private replay is retained at
.analysis/exact/reader-and-affected.json; original review includes raw-00405*.txt,
raw-00408330.txt/raw-00408360.txt, reader-pe-review.json and the target-attested
Ghidra reader-open-review-20261106.txt.

## Audio resource and loop owner

On 2026-11-06, twelve complete Audio members were accepted: 3,159 instruction
bytes from normal C++, plus two generated global-lifetime wrappers totaling
43 auxiliary bytes. All 85 authored-body and six wrapper relocations have
explicit reviewed symbols and destinations; complete native comparison includes
every operand. These results do not establish a runnable audio subsystem or
linked global/data closure.

| Member | Entry | Complete bytes |
| --- | --- | ---: |
| Constructor | 0x40D810 | 95 |
| Destructor | 0x40D870 | 190 |
| Shutdown | 0x40D930 | 190 |
| Initialize | 0x40D9F0 | 188 |
| FillBuffer | 0x40DAB0 | 403 |
| ReleaseBuffer | 0x40DC50 | 118 |
| CreateBuffer | 0x40DCD0 | 245 |
| FindFreeSlot | 0x40DDD0 | 107 |
| ReleaseSound | 0x40DF50 | 83 |
| LoadWave | 0x40DFB0 | 755 |
| ReadLoopMarkers | 0x40E2B0 | 530 |
| MaintainLoop | 0x40E4D0 | 255 |
| Generated global initializer | 0x786460 | 28 |
| Generated global destructor | 0x7864A0 | 15 |

All extents include the complete final RET; following alignment bytes are
excluded. Reviewed direct branches remain within each body. No local table or
EH contribution is omitted. The constructor initializes loopEnd/loopStart and
the two pointer arrays; it leaves window, DirectSound and size fields untouched.
Destructor/Shutdown release samples only inside the buffer-present branch,
then release DirectSound. ReleaseBuffer treats a nonzero COM reference count
as an error and clears the slot. FillBuffer retries Lock after buffer loss,
reports errors and still follows the original copy/unlock path. Both memcpy
calls bind to 0x778600. None of these failure behaviors was hardened.

CreateBuffer builds a 16-byte PCMWAVEFORMAT inside a 36-byte DSBUFFERDESC scope,
uses flags 0x80 and computes sample width through the original signed division.
Its cookie is at EBP-4, description at -0x28, PCM at -0x38 and result at -0x3C.
FillBuffer retains first/second pointers at EBP-4/-0x10, lengths at -0xC/-8 and
result at -0x14. Natural block scopes, rather than padding or new ABI types,
reproduce these allocations. A standard DirectSound local-name trial changed
offsets without fixing the complete function and was not retained.

LoadWave explicitly zeros the five RIFF fields, then copies the descriptor.
Aggregate initialization with {0} generated a different instruction sequence.
Format/chunk/RIFF/file/slot use EBP-0x14/-0x28/-0x3C/-0x40/-0x44. Nested format,
chunk, file and sample-allocation lifetimes resolved the earlier stack mismatch.
The owner opens MMIO with 0x10000, locates WAVE, descends fmt with flags zero,
reads exactly 18 format bytes, requires PCM, ascends, then locates data with
0x10. It does not add a guard after the 150-slot sentinel, and retains the
original allocation/read error cleanup and leaks.

ReadLoopMarkers allocates 320 bytes, queries file size before checking the
handle, reads the last 320 bytes and scans cue/adtl without new bounds checks.
Two/three repeated shifts by eight reproduce the original byte assembly;
single shifts by 16/24 shortened the body by eighteen bytes. The original early
return for missing cue/annotation accounts for the remaining two bytes. Its
file/cue/size/transferred/annotation/data locals use EBP-4/-8/-0xC/-0x10/-0x14/
-0x18. Only the successful marker path deletes the allocation. It sets loopEnd
to (cue + annotation) * 4 and loopStart to annotation * 4. Marker meanings and
the fixed four-byte conversion remain provisional, rather than a general RIFF
parser specification.

MaintainLoop tests loopEnd, the 150 sentinel, buffer and sample through four
separate early returns. Combining them into one conjunction shortened the body
by four bytes. After GetCurrentPosition, position > loopEnd causes Stop,
SetCurrentPosition(position - loopStart), then Play(0, 0, 1). Startup now uses
the unsigned-short MaintainLoop symbol at the original destination 0x40E4D0.
SetMode(short) is retired from the accepted declaration and relocation recipe.

The reconstructed Audio view has loop fields at 0/4, window at 8, DirectSound
at 0xC and 150-entry sample/size/buffer arrays at 0x10/0x268/0x4C0 (minimum
0x718 bytes). Generated normal C++ global initialization binds audio at
0x7B0B60, constructor 0x40D810, destructor 0x40D870, exit wrapper 0x7864A0 and
atexit 0x777F05. It does not prove the complete original BSS allocation graph.

The original DirectSoundCreate thunk at 0x777D40 jumps through IAT 0x787010
(DSOUND ordinal 1). The compiler's import-library symbol and locked SDK header
identify the API; ordinal metadata alone does not identify every original type.
MMIO imports are mmioOpenA 0x7871C4, mmioDescend 0x7871C8, mmioClose 0x7871CC,
mmioRead 0x7871D0 and mmioAscend 0x7871D4. Other bindings use reviewed existing
Win32/CRT destinations, including memset 0x777DC0 and the CreateBuffer cookie/
check at 0x78F050/0x7781DC. Error-title/message data operands span 0x7878C4
through 0x787AEC and remain explicit external data bindings. The full-slot title
at 0x78798C includes text following DS; it was not normalized to the other titles.

Final verification used sixteen cold source/profile artifacts for 14 new bodies
and the 62 existing Engine.h-dependent units. AudioResources uses the explicit
/Od /G6 /MT /Gy /GS /W3 profile; AudioGlobal uses the profile without /GS.
All 76 complete comparisons are strict exact. Reader and Config recipes were
unaffected and were not replayed. The dispatcher still compares all 14,305 bytes,
301 relocations and 36 compiler-local offset bindings; only compiler-local
symbol identities changed with the header. Public Audio proofs are
docs/evidence/audio-exact.json and audio-global-exact.json; affected owner
proofs were refreshed. Private evidence is .analysis/exact/audio-and-affected.json,
.analysis/probes/audio-next/, the retained raw-0040d*.txt/raw-0040e*.txt and the
target-attested Ghidra audio-load-wave-review-20261106.txt.

## DirectInput owner

On 2026-11-06, nine complete Input functions were accepted for 4,552 authored
instruction bytes. Two normal compiler-generated global-lifetime wrappers add
43 auxiliary bytes. All 63 member/callback and six wrapper relocations were
independently checked against complete original operands, mapped GUID/format/
global data, PE imports and the CRT exit registration destination. Every direct
branch stays inside its complete reviewed body, which ends at the final RET;
following alignment bytes are excluded. There are no hidden tables or EH extents.

| Member | Entry | Complete bytes |
| --- | --- | ---: |
| Constructor | 0x40C5E0 | 258 |
| Initialize | 0x40C6F0 | 389 |
| Shutdown | 0x40C880 | 262 |
| Destructor | 0x40C990 | 262 |
| ReportFailure | 0x40CAA0 | 53 |
| EnumerateInputDevice callback | 0x40CAE0 | 531 |
| ReadState | 0x40CD00 | 1,079 |
| Defaults | 0x40D140 | 786 |
| Configure | 0x40D460 | 932 |
| Generated global initializer | 0x786440 | 28 |
| Generated global destructor | 0x786490 | 15 |

Names and recovered field types remain provisional. The callback's two-argument
stdcall ABI follows the
EnumDevices call, SDK callback type and complete RET 8; Ghidra's one-argument
prototype was insufficient. Initialize returns int, replacing the earlier void
caller declaration and relocation symbol. Its original destination is unchanged;
the complete startup contribution was recompiled and strictly compared.

The minimum Input view is 0x1F4 bytes: signed keyboard bytes at 0, 32 unknown
bytes at 0x100, two 80-byte DIJOYSTATE records at 0x120/0x170, two sets of eight
signed-short bindings at 0x1C0/0x1D0, HWND at 0x1E0 and DirectInput/keyboard/two
joystick interfaces at 0x1E4/0x1E8/0x1EC/0x1F0. The four-byte gap before the
neighboring Audio global does not establish a larger class or another field.
Constructor sets the sixteen default key words and four interface pointers;
keyboard/joystick state and window are not initialized by that member. The
normal global definition does not prove linked BSS or original TU partitioning.

The locked SDK's DirectInput 7 declarations and original GUID bytes identify
IID_IDirectInput7A at 0x78AD6C, IID_IDirectInputDevice7A at 0x78ACEC and
GUID_SysKeyboard at 0x78ABDC. Source explicitly sets DIRECTINPUT_VERSION 0x0700.
The DirectInputCreateEx import thunk is 0x777A70. Original data-format headers
at 0x78998C/0x7899A4 have sizes 24/16, state sizes 256/80 and object counts
256/44, supporting c_dfDIKeyboard/c_dfDIJoystick bindings. These data remain
explicit external destinations; no linked-data acceptance is claimed.

Initialize obtains the instance with GetWindowLongA(window, -6), creates
DirectInput 7, creates the keyboard, sets its format/cooperative flags 0x15 and
acquires it. It deliberately does not assign the keyboard CreateDeviceEx return
value: the following comparison uses the prior DirectInputCreateEx HRESULT.
Preserve this observed stale-result bug. After keyboard acquisition it records
this at global 0x7B1278 and enumerates type 4 devices with flags 1, passing the
DirectInput pointer as callback context. ReportFailure shows the original message
with null owner and posts WM_CLOSE to the stored window; it does not add cleanup.

The callback uses global Input/count at 0x7B1278/0x7B128C, ignoring its context
argument. It creates a joystick, sets its format and cooperative flags 0x16,
then sets DIPROP_RANGE on offsets 0 and 4 to [-1000, 1000] using a 24-byte
DIPROPRANGE with 16-byte header. Acquire succeeds before the byte counter is
incremented. It stops enumeration at two successful devices; every earlier
failure returns continue without releasing the partial device or advancing the
counter. No reset or new slot guard was added. Shutdown and destructor each
unacquire/release keyboard and joysticks only under the outer DirectInput-present
condition, then release DirectInput; they retain the original pointer clearing.

ReadState accepts player 0/1 and returns a packed eight-bit state. It reads
keyboard state and polls both joysticks, attempting reacquisition only for
DIERR_INPUTLOST. Mapping high bits select keyboard/first/second joystick;
low byte selects a key/button or direction code. Axis tests are strict <-500
or >500, and joystick button data is read before the key < 16 check. The source
retains this order and does not generalize the checked format. Each successful
joystick condition breaks directly from the switch; an else-if chain generated
a shorter complete function. Its exact frame keeps index/binding/key/device/
HRESULT/result byte at EBP-4/-8/-9/-0x10/-0x14/-0x15. Ordinary nested scopes
reproduce these slots without padding, assembly or dummy fields.

Defaults and Configure both read binary key.ini through distinct original path
operands 0x7878B4/0x7878BC. They request read/write access, require at least
32 bytes, allocate/read the full reported size and store eight words for each
player in binding order 3,2,1,0,4,5,6,7. Each word is
low + (high << 8) - (high > 0), preserving unsigned byte promotion. Configure
adds profile * 39 to each file offset without a new extent check. Reversing the
source index terms changed register allocation; profile * 39 + player * 16
matches the complete original expression order. Allocation/read lifetime scopes
keep file/size/transferred/data/index at EBP-4/-8/-0xC/-0x10/-0x14. Both functions
retain unchecked transfer handling and CloseHandle even on an invalid handle.
The provisional Defaults name identifies the first record reader, not a generic
reset-to-constructor-defaults operation.

Normal Input input; reproduces the 28-byte initializer/15-byte exit wrapper at
0x786440/0x786490, bound to Input 0x7B0968, ctor/dtor 0x40C5E0/0x40C990 and
atexit 0x777F05. These helpers are compiler-generated and excluded from authored
progress. Complete member proofs are docs/evidence/input-exact.json; auxiliary
proofs are input-global-exact.json.

Input.h is shared through Engine.h, and is an explicit transitive dependency
of every affected recipe. InputResources/InputGlobal depend directly on Input.h.
Final verification used nineteen cold source/profile artifacts for eleven new
authored members/callbacks (including the playback controls below), two generated
helpers and 76 affected existing units: all 89 complete comparisons are strict
exact. Reader and configuration units were not involved. The complete dispatcher
retains all 14,305 compared bytes, 301 relocations and 36 checked compiled-local
offsets; only local symbol IDs were refreshed. All new sources use explicit
/Od /G6 /MT /Gy /W3. Private evidence is .analysis/exact/input-and-affected.json,
.analysis/probes/input-next/ (complete boundaries and native trials), and
Ghidra decompile-40c5e0.txt through decompile-40d460.txt. The first Ghidra request
used interior address 0x40C610 and was rejected; the constructor was correctly
located at 0x40C5E0 from global initialization and reviewed independently.

## Audio playback controls

StopSound at 0x40DE40 (64 bytes) and StartSound at 0x40DE80 (204 bytes) complete
the remaining two members in the contiguous Audio code region. Both are normal
C++, compiled and compared as complete functions. StopSound conditionally calls
the existing buffer's Stop method. StartSound checks buffers[id] before testing
the 150 sentinel, then calls Stop, SetCurrentPosition(0) and Play(0, 0, loop == 1).
It preserves the original order, potential sentinel access and boolean loop flag;
no extra guards or cleanup were added. Only a nonzero Play result displays the
original window-owned error message.

All three playback relocations are reviewed: MessageBoxA IAT 0x787184 and original
title/message pointers 0x7879D4/0x7879E8. The title includes text following DS and
was not replaced with another title. Complete boundaries end at 0x40DE80/0x40DF4C;
following alignment is excluded. Public proof is audio-playback-exact.json.
The accepted Audio region now contains fifteen authored members (resource/loop,
volume and playback) totaling 3,508 bytes. This does not establish runtime device
behavior or whole-game audio closure. Playback declarations were incorporated
before the shared-header replay above, avoiding a second dependency cohort.

## Rendering and timer follow-up evidence

The five Video pixel kernels at 0x409A90, 0x40A0B0, 0x40A440,
0x40A7B0 and 0x40AAE0 have complete reviewed target boundaries and natural C++
semantic owners in src/VideoCharacterDraw.cpp, each with a focused match unit.
Their complete target extents are 799, 897, 865, 806 and 808 bytes respectively.
Strict complete comparisons reject every current candidate; none is byte-exact.
The target loops contain body-local ESI/EDI saves and direct AH/AL operations
that remain the main code-generation problem. Keep exploring natural C++ rather
than accepting clipping/COM prefixes or introducing assembly wrappers. The
blended body's last argument is loaded as a signed byte before accepting modes
0/1. Detailed clipping, mask, palette and shift behavior is recorded in the
character-rendering findings below.

Timer thread 0x401850 is reconstructed as a complete 157-byte natural C++
function in src/FrameThread.cpp. It initializes the three target locals, stores
timeGetTime() in lastTick at 0x790100, waits on tickEvent at 0x79013C using the
byte at 0x78F040 as the timeout, then signals frameEvent at 0x790140. Each
elapsed second it increments that timeout byte only when the signed loop count
exceeds 64, resets the count and samples time again. The byte at 0x78F040 is
initialized to 10 in the original .data section; it is not `active`. The active
WPARAM global is separately bound at 0x790134 by WindowProcedure. Two of the
three initialized stack locals have no later reads in this body; their source
names are unknown and the exact source uses nested scope to reproduce the
observed -4/-8/-C stack layout without padding. All 157 bytes and 13 relocation
operands compare exactly. Evidence: docs/evidence/frame-thread-exact.json and
.analysis/probes/timing/FrameThread-third-reviewed-relocations.json.

## Context input and audio transitions

On 2026-11-06, six complete Context members were accepted for 1,232 authored
instruction bytes. They connect the previously accepted Input and Audio owners
to startup and scenes. All 31 relocation operands were independently checked
against original call/data operands; complete branches stay inside their body
and the final RET is included. No padding, table, EH or prefix-only comparison
is involved. Public proof is docs/evidence/context-io-exact.json.

| Member | Entry | Complete bytes |
| --- | --- | ---: |
| PollInput | 0x406590 | 490 |
| Initialize | 0x406780 | 213 |
| PlayEffectSound | 0x406860 | 65 |
| LoadMusic | 0x4068B0 | 340 |
| ReleaseMusic | 0x406A10 | 85 |
| FadeMusic | 0x406A70 | 39 |

The former unknown Context interval 0xC..0x37 is now represented by two signed
horizontal and two vertical direction bytes at 0xC/0xE, four two-byte button
pulse arrays at 0x10/0x12/0x14/0x16, and four two-int held-state arrays at
0x18/0x20/0x28/0x30. Names/types remain provisional views of observed accesses;
they preserve the original complete Context layout and add no storage.
PollInput reads each player's eight-bit Input state into a two-byte local.
It clears direction/pulse bytes, gives up priority over down and left priority
over right, and emits one pulse for each newly pressed high-nibble button.
Held flags are set while pressed and cleared on release. The complete 490-byte
body has no cookie with this two-byte local under the explicit /GS profile.
Seven direct scene callers are recorded in callers-00406590.txt.

Initialize is the sound-effect loader: it constructs wave\\se\\00.wav through
wave\\se\\64.wav in a 32-byte path plus eight-byte decimal scratch, stores each
LoadWave result at soundSlots (0xEA4) and calls SetSoundVolume(result, -500).
It does not add a failure/sentinel check before setting volume. Path prefix,
zero and extension are distinct original data bindings at 0x78742C/0x787438/
0x78743C. _itoa at 0x777F55, strcpy at 0x778080 and strcat at 0x778090 were
reviewed separately from target function boundaries. Array sizes, cookie and
loop retain the complete original stack layout. PlayEffectSound checks the
stored slot against 150, then starts it without looping; its effect index has
no new bounds check.

LoadMusic builds wave\\bgm\\bgmNN.wav using original data bindings 0x787444,
0x787454 and 0x787458. It stops/releases a previous non-sentinel slot and stores
150 before loading the replacement. ReadLoopMarkers is called even if LoadWave
fails. A successful new slot starts with loop argument zero for IDs 2,3,4,9 and
one otherwise; the original integer ternary and subtraction are preserved.
The field still named audioMode at 0xF26 holds this buffer slot, not a general
mode enum. Six direct music-loading callers are recorded in callers-004068b0.txt.
ReleaseMusic performs the same stop/release/sentinel sequence without loading.
FadeMusic simply stores the int target and short step at 0xF28/0xF30; the
previously accepted UpdateFrameControls performs the actual volume ramp.
Neither method invents validation or changes original failure handling.

The first complete source, after supplying its transitive private Input.h,
matched all six bodies immediately. An earlier scratch build omitted that
header, reported C1083 and hit the existing 120-second process deadline; it
conferred no comparison credit. The error/timeout evidence is retained in
.analysis/build/context-io-next-first.log and its timeout summary. The required
post-failure --execute toolchain check passed C/C++, CRT, resources, linker and
smoke execution before native work resumed. No toolchain, Wine prefix, oracle
implementation or target was replaced.

Final verification uses eighteen cold source/profile artifacts for six new and
78 Engine.h-dependent existing units. Every one of the 84 complete comparisons
is strict exact. The standalone Input, reader and Config sources are unaffected
and were not replayed. New ContextIO uses /Od /G6 /MT /Gy /GS /W3, with both
Engine.h and Input.h explicitly tracked. The dispatcher still compares all
14,305 bytes, 301 relocations and 36 original-destination/local-offset bindings;
only compiler-local symbol IDs changed. Private replay and review are retained
at .analysis/exact/context-io-and-affected.json and
.analysis/probes/context-io-next/. Target-attested decompile-00406780.txt
corroborates startup's loader binding; it is not the boundary/acceptance authority.


## Title scene and shared scene base

On 2026-11-06, twelve complete functions recovered the title/menu Scene0 owner,
shared scene construction and palette transitions, and four Video palette/frame
wrappers. They add 3,769 authored instruction bytes and 28 associated local
switch-table bytes. Full target boundaries were reviewed independently of
compiler output, through each final RET; all 79 relocation operands were decoded
from the canonical target and checked against their named destinations. Public
proofs are scene-base-exact.json, scene-title-exact.json and video-frame-exact.json
under docs/evidence/.

| Member | Entry | Complete contribution bytes |
| --- | --- | ---: |
| Scene constructor | 0x759C10 | 124 |
| Scene::FadeOut | 0x759C90 | 390 |
| Scene::FadeIn | 0x759E20 | 272 |
| Scene0 constructor | 0x775D60 | 460 |
| Scene0 destructor | 0x775F30 | 118 |
| Scene0::Step | 0x775FB0 | 1,267 (1,239 code + 28 table) |
| Scene0::Slot0 (render) | 0x7764B0 | 688 |
| Scene0::PollKeyboard | 0x776760 | 183 |
| Video::ApplyPalette | 0x40BD30 | 55 |
| Video::ApplyPaletteRange | 0x40BD70 | 65 |
| Video::ClearPaletteRGB | 0x40BDC0 | 81 |
| Video::Present | 0x40B5E0 | 94 |

The base vtable at 0x7892CC contains three purecall destinations (0x77893D),
not the previous two-slot opaque view. Scene0's table at 0x789980 contains render,
Step and PollKeyboard in that order. Natural abstract-base/derived declarations
emit the constructor/destructor vptr writes. These reviewed address bindings
accept function code only: linked vtable/data placement remains unaccepted.
The observed base view has message at 4, HWND at 8, Secondary pointers at C/10,
pointer slots at 14/18, Context/Video/Input/Audio at 1C/20/24/28, phase/flag at
2C/2D, palette at 2E and color key at 42E. Its rounded minimum view is 0x430;
this does not establish a unique original class size or type grouping. Scene0
has surfaces at 434/438, selection at 43C, a short at 43E, held-direction bytes
at 440/441, a flag at 442, inactivity count at 444 and int at 448. Startup's
0x44C allocation and all other scene allocation sizes remain exact.

Base construction retains pointer-copy order, phase -1 and flag zero. FadeOut
runs 20 down through zero and FadeIn zero through 20, calling virtual render
before each palette operation. Mode 0 darkens; mode 1 lightens; other modes do
neither. The amount is index * 5 over palette entries 0..255. FadeOut also sets
the current music slot's volume to volume - (20-index)*step/2. Both alternate
16/15 millisecond timeGetTime busy waits, with the original byte conversion,
without adding Sleep, message pumping or new error handling.

The title constructor retains both original DAT and BMP resource paths under
the original constant condition. Eight distinct string addresses at 0x7898E0,
0x7898F4, 0x789908, 0x78991C, 0x789930, 0x789944, 0x789958 and 0x78996C bind the
title/title_ob files and palette paths, including duplicated DAT strings at
different destinations. The destructor releases and clears two surfaces.
Step handles the three palette-entry phases, input pulses, seven menu choices,
scene transitions and WM_CLOSE. The inactivity threshold is greater than 1800;
the counter increments per quiet player, twice in a fully quiet frame. Do not
infer a 30-second interval. The original enabled guard remains an ordinary
constant condition in source. Context's selectedPlayer at 1342, CPU flags at
1343/1344, selection at 134E and mode at 1364 expose previously unknown storage.
They are provisional names/types, with no layout growth. Byte CPU flags and signed buttonA retain target operations; the later character
selection owner establishes unsigned CPU-flag reads. Bool CPU flags introduced six extra
zeroing instructions before SETE in a rejected complete-source trial.

Step's final RET is at 0x776486. Its complete seven-entry address table occupies
0x776487..0x7764A3 (exclusive end), targeting 0x7761E9, 0x776268, 0x7762E3,
0x776352, 0x7763D1, 0x776432 and 0x77645F. The table-pointer relocation and all
seven entries retain explicit original destinations and checked function-relative
offsets. No prefix, masked address or code-only acceptance is used. The following
alignment bytes are outside the contribution; render begins at 0x7764B0.

Rendering draws the full 320x240 background, a 120x98 menu at (195,130), and a
120x14 selection row, then presents. PollKeyboard owns a 256-byte local and an
inner HRESULT scope matching the /GS stack. It only reacquires DIERR_INPUTLOST;
the Escape test still reads the buffer after failures, as in the target. The
initial same-scope local trial was nine bytes short and was not accepted.
ApplyPalette passes count 255, not 256; its range variant uses colors+first*4.
ClearPaletteRGB clears only RGB in 256 entries, preserving each fourth byte.
Present conditionally calls the external converter at 0x40B440 then Flip(0,1),
returning zero only for DDERR_SURFACELOST and one for success or other errors.
No surface restoration or converter implementation is inferred. DrawSurface
now has a natural C++ semantic owner in src/VideoCharacterDraw.cpp, but strict
exact codegen and the software conversion kernel remain open despite their
exact callers.

Final verification uses 23 cold source/profile/dependency artifacts for twelve
new and 95 Engine.h/Input.h-dependent existing units. All 107 full comparisons
are strict exact, including the 14,305-byte effect dispatcher with 301 relocations
and 36 original-offset bindings. Shared declarations only changed compiler-local
symbol identities there. Reader and Config sources were unaffected and omitted.
No full CI/cold cohort, runtime or redundant test matrix was requested or run.
Private full comparisons, rejected trials, boundary/operand reviews and logs
remain under .analysis/probes/scene-next/, .analysis/build/scene-next-* and
.analysis/exact/scene-and-affected.json. Ghidra candidates and original vtable
observations remain separate from function acceptance and linked-data closure.


## Character selection scene

On 2026-11-06, seven complete Scene1 functions were accepted for 10,780 authored
instruction bytes plus 20 associated local-table bytes. The character-selection
update body is the substantial owner in this checkpoint. Its constructor,
destructor, stage loading, player palette loading, keyboard handling and entry
transition are also exact. At that checkpoint render and character-object
construction remained open; the subsequent rendering section records its
acceptance. The later creation-dispatch section records its acceptance. External
character constructors and non-exact pixel-kernel codegen still prevent
callee/product closure. Public proof is
[scene-select-exact.json](evidence/scene-select-exact.json).

| Member | Entry | Complete contribution bytes |
| --- | --- | ---: |
| Scene1 constructor | 0x753260 | 1,609 |
| Scene1 destructor | 0x7538B0 | 314 |
| Scene1::Step | 0x7539F0 | 6,928 (6,908 code + 20 table) |
| Scene1::LoadStage | 0x759460 | 354 |
| Scene1::LoadPlayerPalette | 0x7595D0 | 415 |
| Scene1::PollKeyboard | 0x759770 | 350 |
| Scene1::Enter | 0x7598D0 | 830 |

Every complete boundary was independently reviewed through its final RET, with
original direct branches checked inside the instruction extent. All 199 new
relocation operands were decoded from the canonical original and checked against
explicit named destinations, including paths, ten floating constants, CRT calls,
accepted owner calls and the reviewed Scene1 vtable at 0x7892C0. That table points
to render 0x755500, Step 0x7539F0 and keyboard 0x759770. Natural C++ inheritance
emits its vptr writes; no vtable/data placement is accepted. Step's final RET is
0x7554EB; the five-case table occupies 0x7554EC..0x755500 (exclusive end). Entries
are 0x753D0C, 0x7543E8, 0x7544D2, 0x75455F and 0x754802. The table pointer plus all
five entries retain explicit original destinations and checked local offsets.
The 6,908-byte Ghidra body alone was not used as the acceptance extent.

The provisional Scene1 view preserves startup's 0x560 allocation. It has six
surface pointers at 434/438/43C/440/444/448; two later color keys at 44E/44F;
five doubles at 450..470; an entry counter at 478, two player deltas at 47C/480,
and remaining counters through 490; short pairs at 494/498; unsigned held bytes
at 49C and signed per-player state bytes at 49E; 25 character-order bytes at 4A0,
a 24-byte 3-column grid at 4B9 and 24 portrait offsets at 4D4; grid X/Y, character
and palette byte pairs at 538/53A/53C/53E; random-selection timers at 540; and
23 unavailable-stage flags at 544. These names/types are provisional observed
views, not proof of original member grouping or a unique source class design.

Constructor paths bind separate chr_sel_bg, chr_sel_ob and stage/all DAT/BMP
strings at 0x7890F0..0x789198. It preserves the constant resource branch and
individual initialization of grid order, portrait offsets and character order.
Initial display values are 0, 50, 50, 0 and -240, not arbitrary decompiler names.
Enter resets the animation and timers, uses -480 for the stage entrance, clears
Context's player flags and alternate-style ints, builds stage exclusions for
character-data modes 0/-1, selects music 0/1, renders and fades in. Mode 0/2 marks
one CPU selection as stage-ready; it retains the original asymmetric CPU test.
The destructor releases six surfaces in the original non-address order.

Step preserves CPU-input suppression and redirection, random character/stage
selection, restricted character and stage sets, palette collision avoidance,
confirmation/cancellation states, cosine transitions and scene return values.
It returns 8/0 after cancellation according to mode, 2 when entering combat,
and 1 while character selection continues. The original constant-enabled stage
randomization guard remains in source. Signed comparisons against 6/13/16/18/22/
23 retain the actual source operation shapes rather than equivalent rewritten
thresholds. Animation uses ordinary cos and integer conversions, with the
original 180/3.141592 degree divisor, (cos+1)*300 portrait motion and stage
expression ((cos-0.5)*2-1)*240. No fast math or custom conversion wrapper is used.

Context's B/C/D pulse bytes, stage byte at F32, menu mode at 1364 and Scene flag
at 2D now have signed char views from explicit MOVSX evidence; CPU flags at
1343/1344 have unsigned char views from MOVZX, without changing the already
exact title stores. Context exposes two int alternate-style fields at 1338,
flag 1358, ints 135C/1360, two player flags at 1378 and flag 14283 inside existing
unknown storage. The shared Scene pointer pair at C/10 is represented as an
array for the target's player indexing, with identical constructor stores.
Secondary exposes palette index 8E and a one-byte view of the NUL-terminated
resource-name start at 94. A reviewed character constructor (0x48A720) copies a
string to that address after calling base construction at 0x40EAE0. This minimum
view establishes neither the full resource-name capacity nor Secondary's size,
vtable or character inheritance. No new allocation uses that minimum size.

LoadStage retains its own duplicate prefix/extension bindings at 0x789238..
0x789260 and both compiled DAT/BMP paths. LoadPlayerPalette builds system plus
the character name twice, directory separator and extension, then loads/submits
40 entries beginning at AF+player*40 using palette*40 as source offset. Keyboard
retains the original 256-byte buffer, HRESULT inner scope, input-lost reacquire
and failure-buffer access. Escape sets the cancellation flag, F1 restores
bindings, and F2/F3/F4 select profiles 1/2/3 only when ReadConfigByte(0x98) > 0.
No bounds, cleanup or failure behavior was silently improved.

The first complete constructor/destructor source matched immediately. Step's
first 6,928-byte contribution had 338 byte differences; recovered byte types,
branch forms and integer bounds reduced those to eleven path-buffer offsets.
A naturally nested digits scope under the path buffer recovered the original
stack order and made the full function exact. Merely reversing declarations or
renaming the same-scope buffers did not fix it; those trials are retained. The
four adjacent functions' first complete source was exact except for three
keyboard branches: explicit > 0 recovered the original signed TEST/JLE shape
following unsigned byte promotion. No byte wrappers, padding or partial claims
were used. Every involved unit was compared after the final source/header edits.

Final verification uses 24 cold source/profile/dependency artifacts for seven
new and 107 Engine.h/Input.h-dependent existing units, all 114 complete strict
comparisons exact. The effect dispatcher still covers 14,305 bytes, 301
relocations and 36 original-offset bindings; the title Step still includes its
entire 28-byte table and eight offset bindings. Header changes refreshed their
44 compiler-local symbol IDs without changing any destinations or offsets.
Reader/Config were unaffected and omitted. Private source trials, operand and
boundary reviews are retained under .analysis/probes/scene-select/; final replay
is .analysis/exact/scene-select-and-affected.json. No oracle/toolchain change,
full CI/cold cohort or runtime matrix was needed.

The subsequent render review at 0x755500 covers its complete 12,720-byte
contiguous contribution independently. The provisional Ghidra body lists only
12,231 addresses: omitted intervals 0x757946..0x75794F and 0x75795F..0x757B3F
contain normal loop instructions in the target, not accepted gaps or table
padding. Do not copy that incomplete body extent into a comparison recipe.
Local render disassembly and decompile are retained, alongside the 3,399-byte
character-loading candidate at 0x7586B0. The latter dispatches 24 allocation paths to 23 constructor destinations; arbitrary opaque constructor/size guesses are not
accepted. DrawSurface now has a natural C++ semantic owner in
src/VideoCharacterDraw.cpp, but its strict codegen and the software conversion
callee remain open.


## Character selection rendering

On 2026-11-06, Scene1::Slot0 at 0x755500 was accepted as a complete 12,720-byte
authored rendering-composition function, ending with RET at 0x7586AF. Public
proof is [scene-select-render-exact.json](evidence/scene-select-render-exact.json).
It follows the seven previously accepted selection functions and is the second
largest accepted authored instruction body after Context::UpdateEffect. It does
not implement the still-external pixel rendering/conversion kernels or the
character-object constructor dispatcher.

Independent original review covers all 3,294 instructions without gaps, tables
or trailing alignment. All 63 direct branches land on instruction starts within
the complete extent. The old Ghidra body omitted nine bytes at 0x757946..0x75794F
and 480 bytes at 0x75795F..0x757B3F (exclusive ends). These are ordinary reachable
loop instructions, including its counter update, stage exclusion search, rectangle
construction and draw call. The source retains that entire random-stage-list
loop. A size derived only from the 12,231-address inventory would have been
incomplete; the separate reviewed boundary is 0x755500..0x7586B0. The candidate
inventory remains unchanged and is not the boundary authority.

The complete original body has 61 MakeSurfaceRect calls, 35 DrawSurface calls
and one Present call. It composes the scrolling selection background, left/right
player strips and portraits, character names, alternate-style badges, character
grid, restricted-character overlays, combined/separate player cursors, stage
cards, stage preview and random-stage panel. It preserves source-rectangle reuse
across multiple destinations instead of rebuilding the same source for each draw.
CPU/mode visibility tests, portrait mirroring, palette keys, all dimensions and
coordinates remain as compiled in the target. Existing Engine.h/Input.h layouts
were sufficient and were not changed.

Stage-list branches preserve four independent skipped-stage/counter pairs. The
normal list starts at row 1 and runs through 7; random selection and both slide
lists run rows 0..8. Unavailable stages are skipped with the original unbounded
while loops and signed modulo 23. The reverse slide also draws row -1 and uses
its original backward exclusion search. There are no new bounds guards, clamps,
extra frame operations or abstracted loop helpers. Background/portrait offsets,
zero-based coordinate subtraction and per-expression integer conversions retain
the original order.

All 175 relocation operands were independently decoded from canonical target
bytes before acceptance. Named destinations are MakeSurfaceRect 0x40C590,
DrawSurface 0x409A90, Present 0x40B5E0, cos 0x7782B4, sin 0x778204 and ftol2
0x7783B8, plus six reviewed double constants: zero at 0x7872F8, the degree divisor
180/3.141592 at 0x787FF8, 190 at 0x788450, 230 at 0x7884B0, 11 at 0x788750 and
33 at 0x7892D8. The source uses ordinary C++ casts and CRT math calls. No local
relocation, table, EH/LTCG exception or address mask is present.

The first complete source was 12,648 bytes, 72 short. Reversing the cosine
multiplication operands recovered five ordinary pre-call double spills and the
original 0x820 frame; separate rectangle declarations alone did not recover the
reused source/destination local positions. Keeping the source rectangle in an
outer scope and the destination in the inner composition scope restored those
positions naturally. Explicit zero-minus coordinate expressions recovered the
original XOR/SUB operations in place of NEG; after the last two portrait-offset
subtractions, the complete 12,720 bytes were zero difference. Every trial retained
a full comparison and all original loop bodies. No inert locals, padding, byte
wrappers, assembly or partial acceptance were used.

Final src/SceneSelectRender.cpp was compiled with the pinned VC7.1 /Od /G6 /MT
/Gy /GS /W3 profile and compared as one explicitly selected cold unit. Existing
sources and shared headers were unchanged, so no old cohort was replayed. The
complete strict result, private source trials, original boundary/operand review
and exit logs remain at .analysis/exact/scene-select-render.json,
.analysis/probes/scene-render/ and .analysis/build/scene-render-*. The ledger
preparation initially mistook the previous Step's end-address column for a render
entry and stopped on an assertion; the first compare correctly rejected the
missing reviewed boundary. After checking the actual entry column, the reviewed
row was added and the already compiled final source passed full strict comparison.
No target bytes, compiler/Wine state or oracle behavior were changed.

The subsequent LoadCharacter review at 0x7586B0 covers its original 3,399-byte
instruction body and complete 96-byte table. Twenty-four allocation paths use
23 distinct constructor destinations; see the creation-dispatch and external
constructor reviews below.
Character inheritance and full Secondary layout are still provisional. Linked
vtables/resources and whole-game/runtime closure remain separate work.


## Character creation dispatch

On 2026-11-06, Scene1::LoadCharacter at 0x7586B0 was accepted for 3,399 authored
instruction bytes and all 96 local switch-table bytes. Its full contribution is
3,495 bytes through 0x759457, with RET 0xC at 0x7593F4 and the 24-entry table
starting at 0x7593F7. Independent original review covers all 927 instructions,
74 internal direct branches and 97 original relocation operands. The table
pointer and all 24 entries have explicit original destinations and checked
function-relative offsets. Public proof is
[character-create-exact.json](evidence/character-create-exact.json). The first
complete natural C++ source was already strict exact, including the complete
table; there was no prefix, masked relocation or byte-size override.

This completes the nine reconstructed Scene1 function contributions: 26,899
instruction bytes plus 116 local-table bytes across selection lifecycle, update,
rendering, palette/stage resources and creation dispatch. It does not complete
the called character constructors, linked data or rendering kernels, and is
not a runnable-scene/game closure claim.

The dispatcher switches on the signed selected-character byte, creates the
chosen object with six original arguments (opponent pointer slot, Context,
Video, Input, Audio and signed player byte), writes its character ID, stores
the player's pointer and widens the unsigned CPU flag into an int. Twenty-four
case bodies use 23 concrete constructor destinations: IDs 10 and 22 both call
0x461090 with the same 0x3460 allocation. They remain separate cases/new
expressions in source, retaining the original individual compiler temporaries.
No default case or null/failure guard was added: the original post-switch
object dereferences occur after allocation failure or an out-of-range ID too.

Both compiled resource alternatives remain. The DAT path constructs
system plus the character resource name twice, separator and .dat, loads the
player portrait at palette base AF+player*40, loads 40 palette entries from
palette*40 and submits the full original palette wrapper. The BMP alternative
uses LoadSurface/LoadBitmapPalette with the same observed ranges. Six separate
string bindings at 0x789210/218/21C and 0x789224/22C/230 preserve original
addresses, including duplicated prefix/separator contents. Final SurfaceProperty
sets the selected player's color key. No cleanup, extra validation or error
behavior was inserted.

Secondary's minimum data view now exposes character ID at 8D, palette index at
8E, resource-name storage covering 94..A4 and the int CPU flag at A4. All 23
reviewed constructors copy 3..8 character ASCII resource names to offset 94;
this view does not prove a unique original array capacity or complete Secondary
size/alignment/virtual shape. Scene1's color keys at 44C/44D are a natural array
for player indexing; renderer reads use indices 0/1 and remain fully exact.

CharacterViews.h records only allocation-bounded partial object views and
external constructor declarations. Their extents are the original immediate
new sizes, and their zero-offset base relationship follows the reviewed common
base calls from all 23 complete constructor bodies. Unknown arrays represent
original object data, not added code padding. No new virtual signature, vptr
write, thunk, constructor implementation or linked vtable is invented. Each
new expression uses the ordinary pinned compiler allocation/constructor ABI.
The matching dispatcher accepts these calls, not the external function bodies.

Final verification uses 24 cold source/profile/dependency artifacts for one new
and 104 Engine.h-dependent existing units, all 105 complete comparisons strict
exact. Standalone Input, reader and Config were unaffected and omitted. The
only old source expression changes are renderer reads of the two color-key array
elements. The effect, title and selection dispatchers retain every reviewed
original destination and local offset after refreshing 50 compiler-local symbol
identities. The new recipe tracks CharacterViews.h, Engine.h and transitive
Input.h under the explicit VC7.1 /Od /G6 /MT /Gy /GS /W3 profile. Full CI/cold
cohorts and redundant test matrices were omitted as requested. Private full
results and evidence remain at .analysis/exact/character-create-and-affected.json
and .analysis/probes/character-create/.

## Character constructor allocation review

The following external constructors were independently reviewed across their
complete original boundaries, with every direct branch landing inside the
body, final RET 0x18 included, a common base-constructor call to 0x40EAE0 in the
first 64 bytes, and a byte player argument at the sixth original stack slot.
Each dispatcher table entry was separately decoded and checked against its
allocation immediate and constructor call. This adds 23 reviewed boundary/origin
rows only: none of these constructors has source implementation or exact credit.
Resource identifiers below are original asset strings, not claims about original
C++ class names. Character00..Character23 remain provisional names, with no
separate Character22 declaration because that case reuses Character10.

| Selection ID | Resource | Allocation | Constructor | Reviewed code bytes |
| --- | --- | ---: | --- | ---: |
| 0 | nanase | 0x3470 | 0x0048A720 | 642 |
| 1 | ayu | 0x3450 | 0x006E8130 | 436 |
| 2 | mai | 0x3458 | 0x006163B0 | 442 |
| 3 | makoto | 0x3450 | 0x005F6D90 | 393 |
| 4 | akane | 0x3450 | 0x007039D0 | 413 |
| 5 | mayu | 0x3448 | 0x005DDDF0 | 410 |
| 6 | nagamori | 0x34B0 | 0x004ADD90 | 517 |
| 7 | misaki | 0x3448 | 0x00567900 | 390 |
| 8 | shiori | 0x3458 | 0x00422D70 | 462 |
| 9 | sayuri | 0x3458 | 0x004463E0 | 419 |
| 10 | nayuki | 0x3460 | 0x00461090 | 455 |
| 11 | mio | 0x3458 | 0x00588310 | 407 |
| 12 | EXnanase | 0x3468 | 0x006CFBB0 | 452 |
| 13 | kaori | 0x3450 | 0x00638D90 | 383 |
| 14 | ikumi | 0x3478 | 0x006A59C0 | 647 |
| 15 | mishio | 0x3478 | 0x00546480 | 513 |
| 16 | akiko | 0x3468 | 0x007219A0 | 511 |
| 17 | nayukiB | 0x3458 | 0x0073E790 | 472 |
| 18 | mizukaB | 0x3460 | 0x004D2850 | 396 |
| 19 | kanna | 0x3458 | 0x00675C80 | 403 |
| 20 | kano | 0x3478 | 0x00653A20 | 523 |
| 21 | minagi | 0x3458 | 0x005A9FA0 | 469 |
| 22 | nayuki | 0x3460 | 0x00461090 | 455 |
| 23 | misuzu | 0x3488 | 0x00519E00 | 615 |

All observed allocation sizes are 0x3448..0x34B0. Some constructors allocate
additional 505-element arrays or initialize different state/resource fields;
those complete bodies remain separate recovery work. Reuse of Nayuki's
constructor by ID 22 is target evidence, not a guessed extra subclass or name.
The canonical original resource literals and every constructor's raw disassembly
are retained privately with the independent boundary/allocation review.

The common base constructor at 0x40EAE0, destructor at 0x40ECB0 and the
thirteen-slot table at 0x787BCC were investigated as the next coherent owner.
They are now recovered with natural virtual/member construction in the
[shared-character checkpoint](#shared-character-base). The earlier 501-element
array note was incorrect: both the base and the reviewed extra child allocations
use count 0x1F9 (505), with 0xFCC allocation bytes including the array cookie.
At this earlier checkpoint, the 23 child constructor bodies above remained
unimplemented; subsequent character-specific sections record later accepted
owners.

## Shared character base

Canonical target: resources/EFZ.exe, SHA-256
3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481.
This checkpoint accepts sixteen authored functions for 5,156 complete instruction
bytes, plus a separate 106-byte compiler-generated vector-deleting destructor.
All seventeen original extents were independently decoded through their final
RET, with contiguous instruction coverage and internal direct-branch targets.
All 117 new relocation operands were independently decoded and explicitly bound.
There are no local-table bytes or compiler-local bindings in the new functions.

| Original | Complete bytes | Recovered contribution |
| --- | ---: | --- |
| 0x40EAE0 | 463 | Secondary construction |
| 0x40ECB0 | 313 | Secondary destruction |
| 0x412820 | 24 | SecondarySequence construction |
| 0x4128E0 | 43 | SecondarySequence destruction |
| 0x412870 | 106 | Generated sequence vector-deleting destructor, auxiliary |
| 0x412840 | 39 | SecondaryTrail construction (previous InputHistory label) |
| 0x412910 | 32 | Input-history sample completion |
| 0x40F110 | 84 | ResetPose, virtual slot 0 |
| 0x40F1E0 | 74 | ResetFrame |
| 0x40EDF0 | 795 | InitializeState, virtual slot 12 |
| 0x412B10 | 846 | EmitLocalEffect, virtual slot 9 |
| 0x412E60 | 167 | RemoveLocalEffect, virtual slot 10 |
| 0x412F10 | 292 | AdvanceEffectWrite |
| 0x413040 | 73 | ClearLocalEffects |
| 0x410B70 | 1,286 | LoadResources, virtual slot 11 |
| 0x405BE0 | 268 | CharacterStatistics::Write |
| 0x405CF0 | 357 | CharacterStatistics::Read |

The base table at 0x787BCC contains ResetPose, eight purecall entries at
0x77893D, EmitLocalEffect, RemoveLocalEffect, LoadResources and InitializeState,
in that order. The source uses ordinary virtual declarations and no virtual
destructor; normal C++ construction/destruction emits the observed table writes.
EmitLocalEffect takes a spawn pointer, RemoveLocalEffect takes a signed short,
and the other recovered virtual members have no stack arguments. Reviewed
calls of provisional slots 1..8 and sampled complete child bodies support a
no-stack-argument, unused-result interface. Their numerical names and void
source view remain provisional, without claiming unique original declarations.
All 23 child tables were read to declare the observed override sets in
CharacterViews.h and keep the children concrete. A native COFF table inspection
confirms the same thirteen source slots. This is structural evidence, with no
linked-vtable/data placement acceptance or child-body credit.

The current Secondary data view extends through 0x3138. VC7.1 naturally places
its first short at offset 8 when the class has eight-byte alignment and a vptr;
adding an explicit four-byte field after the vptr was an incorrect first trial.
No artificial front gap, packing pragma or explicit vptr store is used.
The opponent-slot member initializer writes offset 78 before the automatic
embedded trail-history constructor at this+2BC0; Context/Video/Input/Audio stores
at 7C/80/84/88 occur in the constructor body afterward. Player, character ID and
palette are bytes 8C/8D/8E. The resource-name view occupies 94..A4 and the CPU
flag is an int at A4; original unique buffer capacity remains unproved.

Construction fills fifty ushort sound slots at 264 with sentinel 150 and twenty
command bytes at 30F5 with -1. The two arrays at 10 and 164 each hold 505
eight-byte records: allocation 0xFCC, count 0x1F9 and four-byte cookie.
The first uses the already accepted PatternSequence constructor at 0x408310;
that function receives no duplicate credit. The second uses SecondarySequence,
whose constructor clears only the pointer at +4 and whose destructor conditionally
deletes that byte array. Compiler folding explains common iterator/cleanup
bodies; Ghidra's ATL/string-dispatch names do not establish semantic origins.
Destruction releases surface indices 0 through surfaceCount inclusive, deletes
the pointer array, releases non-150 sounds and deletes both record arrays.

The owner previously called InputHistory occupies 0x4F8 bytes at 2BC0;
its trail/snapshot role is established in the following input/rendering checkpoint. Its constructor initializes byte 0,
byte 2 and short 4F4; FinishSample assigns held = pending * 3 and clears pending.
ResetPose clears shorts A/C, double B8 and ints 168/170 before finishing a sample.
ResetFrame clears five doubles. InitializeState recovers the full original
scalar sequence, spawn x = player * 160 + 240, y = 0, facing = 1 - player * 2,
the 180-byte history clear, local-effect reset and embedded trail reset.
Unobserved state remains explicit unknown data; no speculative initialization
or guards were added.

The local effect owner has 64 int owner entries at 2D0, 64 active entries at
3D0, and 64 records at 4D0, each 0x98 bytes, ending at 2AD0. Signed short
write/read indices are 2CA/2CC. The 0x48-byte spawn record carries owner/type,
position, flags, facing, grouping, palette, payload and bounds. Emit copies the
original fields in order and zeroes frame, tick, velocities and other observed
record state. Advance wraps at 64, handles read-index collisions, skips inactive
read entries and searches nonzero owners for at most 63 iterations. Remove and
Clear preserve the original active/owner updates. Complete comparisons include
all ring traversal and signed-index paths without added bounds checks.

LoadResources initially calls LoadImages 0x411080, LoadPatterns 0x4116A0
and LoadSounds 0x411AE0, then sets field30E8. The latter two provisional names
were corrected by the subsequent complete loader review below. Reuse follows the original
constant DAT/BMP alternatives, paletteIndex+1 digit suffix and alternate-style
fallbacks. The BMP alternative really calls LoadPalette on its first path,
then LoadBitmapPalette for its fallback; that oddity is preserved. Ten distinct
original resource strings at 0x787B14/18/20/24/2C/30/38/3C/44/50 are explicitly
bound. Context exposes the 1024-byte palette at F35 inside its existing storage,
without changing subsequent offsets. The virtual InitializeState call precedes
statistics handling. Only non-CPU players increment the first counter: modes
0/2 require flag1358 == 1, while modes 1/3/4 take the other original path.
At this checkpoint the three resource-loader callees were external; the
following checkpoint recovers all three and both called image-transfer methods.

The statistics object is eight ints at 3118..3138. Caller ECX values establish
member methods rather than the global-function hypothesis suggested by the
initial decompile. Write serializes nine ints (36 bytes), including a reserved
zero ninth word. Read clears the eight object words and copies the first eight
local record words after ReadFile. It passes GetFileSize's unchecked result to
ReadFile into the nine-word local buffer and closes the handle even after an
invalid open, retaining the original short-read/oversize/failure behavior.
Separate six string operands at 0x787390/398/39C/3A4/3AC/3B0 are explicitly bound.
Normal nested local scopes recover VC7.1's original stack allocation; complete
comparisons after the scope change are retained, without unused padding locals.

The final replay cold builds 28 distinct source/profile/dependency artifacts,
then compares 17 new and 105 shared-header-dependent existing units: all 122
complete comparisons are strict exact. The four existing dispatchers retain
all 75 local-offset checks and original destinations after compiler-local
symbol identity refreshes. Standalone Input, reader and Config are unaffected
and omitted. Public proofs are secondary-lifetime-exact.json,
secondary-state-exact.json, secondary-resources-exact.json and
character-statistics-exact.json, with involved owner proofs refreshed.
Private evidence, rejected trials, full disassembly and independent boundary,
operand and virtual-table reviews remain under .analysis/probes/secondary-base/;
the final replay is .analysis/exact/secondary-base-and-affected.json.

## Character resource loaders

The canonical EFZ.exe identity is unchanged. Six complete authored contributions
are accepted for 4,753 instruction bytes, without local tables or new auxiliary
credit. Complete target decoding covers 1285 instructions and 77 internal
direct branches; all 133 relocation operands were independently decoded and
explicitly bound. No masked fields, size overrides or prefix comparisons are used.

| Original | Complete bytes | Recovered contribution |
| --- | ---: | --- |
| 0x411080 | 1,560 | Secondary::LoadImages |
| 0x4116A0 | 1,079 | Secondary::LoadPatterns |
| 0x411AE0 | 241 | Secondary::LoadSounds |
| 0x412AD0 | 51 | SecondarySequence::Allocate |
| 0x409090 | 980 | Video::LoadBitmapSurface, character palette mapping |
| 0x409740 | 842 | Video::DecodeCharacterSurface, raw/RLE character palette mapping |

Full target review corrects two old provisional names: 0x4116A0 opens the
resource-name .pat file and loads animation/collision records; 0x411AE0 builds
wave-directory WAV paths and loads sounds. The shared LoadResources source and
its two relocation symbol names were corrected while retaining both original
call destinations and all 1,286 compared bytes. The call order remains image,
animation data, then sound. Names remain reconstruction identifiers.

LoadImages allocates surfaceCount+1 pointers and reads the complete resource-name
.dat file without adding open/read checks. The first byte selects the palette
header length: pixel data begins at data[0] * 3 + 1. The inclusive surface loop
passes marker 128 and player * 40 + 0x5F to the packed decoder. A zero consumption
result displays the original decimal-index message and leaves the byte offset
unchanged; otherwise it advances by the returned count. After close/delete,
the normal path submits the selected 40-color palette; alternate style uses a
paletteIndex+1 .pal suffix. SurfaceProperty on the first surface sets byte 1A.

All unreachable BMP alternatives removed by Ghidra are included in the complete
1,560-byte comparison. Indices below 1,000 have the original decimal zero-prefix
paths; larger indices use the A prefix and decimal index. Normal BMP palette
loading uses the original 000.bmp suffix. Its alternate .pal branch still calls
LoadPalette rather than LoadBitmapPalette. All thirteen image string operands
at 0x787B5C/60/68/6C/74/78/7C/84/88/8C/94/98/A0 are independently bound.
Source uses ordinary constant alternatives and observed local scopes; no dead
instruction bytes are omitted from acceptance.

LoadPatterns reads a count, then each integer ID, two shorts populated from
ReadInt results, and an unsigned byte frame count. It allocates the 200-byte
SecondaryFrame array and the existing 12-byte PatternFrame array separately.
SecondarySequence now exposes shorts at 0/2 and the frame pointer at 4; its
constructor/destructor code is unchanged and fully replayed. Allocate only
replaces the pointer for positive counts, preserving the original nonpositive
path and lack of prior deletion.

Each animation frame reads texture geometry in original order. Duration uses
a signed-short conversion of ReadInt before multiplication by three. The extra
record contains ten 16-byte rectangles spanning 0..9F followed by scalar fields through
C4 and two unresolved bytes to the 0xC8 stride. Rectangle reads occur in the
original order: 90, 00/10, 50, 20/30/40, then 60/70/80. No semantic hit/hurt-box
classification is claimed. Floats at BC/B8 are populated from signed ReadShort,
then divided by +100.0/-100.0 respectively, explicitly bound to 0x787C5C/58.
Bytes C1/C0 also consume ReadShort; A4 consumes ReadInt and converts to float.
Finally, all 64 local effect records receive the shared PatternSequence pointer
at record offset 8 (parent 4D8 plus 0x98 stride). The previous unknown intervals
are refined without changing any accepted object offsets or allocation extents.

LoadSounds loads all fifty wave-directory two-digit .wav paths, stores each
returned ushort slot at 264 and calls SetSoundVolume(slot, -500), retaining the
sentinel/failure behavior. The animation and sound string destinations are
0x787BAC/B0 and 0x787BB8/C0/C4. The existing PatternReader and Audio callee bodies
receive no duplicate implementation credit.

The 12-byte provisional PatternReader view retains known handle/buffer offsets
0/4. Its unknown final four bytes now use a word placeholder instead of the
previous character-array placeholder. The array incorrectly made VC7.1 classify
the local object for /GS stack reordering: reader at EBP-14 and cookie at -8,
instead of the target reader at -10, cookie at -14, count at -4 and path at -34.
The word view yields the complete 1,079-byte comparison; Context::Load and all
twenty reader methods remain complete strict exact. This distinguishes the two
source views for codegen without proving original field semantics, a unique
original declaration, or the complete original size/alignment. Normal scopes
also recover the image loader's local ordering. Full comparisons after these
source/type changes are retained.

Both newly recovered Video methods implement the character color partition:
input indices below 40 add the caller's unsigned palette offset; other indices
add 135, with byte conversion on storage. BMP/raw rows are inverted vertically;
RLE output is written top-down with the original repeat/value logic. Width and
height come from the original two-byte expressions, including the BMP width
padding calculation. DDSURFACEDESC creation, Lock and Unlock calls are natural
DirectDraw interface calls. Complete method sources compare exact on their first
build under vc71-od-static, independently of the loader's vc71-od-static-gs
profile. The separate failure strings are at 0x7877FC and 0x78784C. Original
unchecked lock results and bitmap failure-path file/buffer leaks are preserved.
The earlier general surface methods remain distinct accepted contributions.

The shared Engine.h and PatternReader.h changes require 142 existing units;
standalone Input and Config are unaffected and omitted. Thirty cold artifacts
cover four new loader units plus those 142 existing units, then one additional
cold artifact covers the two new Video methods: all 148 complete comparisons
are strict exact. The four existing dispatchers retain all 75 local-offset
checks and original destinations after compiler-local identity refreshes.
New public proofs are secondary-loaders-exact.json and character-surfaces-exact.json;
involved owner proofs, ledgers and progress are refreshed. Private final evidence
is .analysis/exact/secondary-loaders-and-affected.json, with the two-method stage
also retained at .analysis/exact/character-surfaces.json. Complete rejected trials,
target disassembly, Ghidra output and independent boundary/operand reviews remain
under .analysis/probes/secondary-loaders/ and .analysis/ghidra/.

## Character input, trails and rendering

Six authored contributions add 3,700 complete instruction bytes, with no local
tables or auxiliary credit. Independent review covers 1,052 target instructions,
82 internal direct branches, all final RET instructions and the following INT3
alignment, plus all 19 explicit relocation operands. The canonical EFZ.exe
identity is unchanged.

| Original | Complete bytes | Recovered contribution |
| --- | ---: | --- |
| 0x411BE0 | 1,467 | Secondary::UpdateInput |
| 0x4121A0 | 1,649 | Secondary::Render |
| 0x412930 | 212 | SecondaryTrail::Capture |
| 0x412A10 | 177 | SecondaryTrail::Begin |
| 0x410940 | 134 | Secondary::AdvanceTrail |
| 0x4109D0 | 61 | Secondary::StartTrail |

The second large body is a renderer, correcting the previous handoff's tentative
control-processing label. The embedded owner at 2BC0 stores visual trail poses,
not button history. Its reconstruction class/member are now SecondaryTrail/trail,
replacing SecondaryInputHistory/inputHistory. The already accepted 39-byte
constructor and 32-byte FinishSample have refreshed symbol bindings under their
historical unit IDs, with no duplicate credit. The 180-byte button history at
1AB is a separate owner.

The two original wrappers perform a null-preserving pointer adjustment of +8
before passing their pose argument. The callee reads words at pose+0/+2,
doubles at +18/+20 and a facing byte at +48. Ordinary inheritance from the
nonpolymorphic SecondaryPose view reproduces both complete wrappers, with no
manual pointer adjustment or vptr stores. The current pose base is 0x70 bytes
at Secondary+8: the former first data fields at 8..77 now belong to this base,
with the same inherited source identifiers. Vptr 0, opponent pointer 78,
embedded trail 2BC0, statistics 3118 and minimum Secondary extent 3138 remain
unchanged. The original 463-byte constructor also remains strict exact after
this structural change. This is a target-supported natural C++ model, without
claiming unique original class names, a unique inheritance graph, linked RTTI
or vtable/data acceptance.

SecondaryTrail is 0x4F8 bytes: unsigned pending/stride/held bytes at 0/1/2,
unknown bytes 3..7, sixty x doubles at 8, sixty y doubles at 1E8, sixty signed
facing bytes at 3C8, sixty ushort animation IDs at 404, sixty ushort frame IDs
at 47C, signed short position at 4F4 and two unresolved tail bytes. Embedded
coordinates are 2BC8/2DA8/2F88/2FC4/303C/30B4 respectively. Capture sets stride
from pending, clears held, writes one pose and advances/wraps position at 60.
Begin fills all sixty records from the pose only when both pending and held
are zero, then assigns its spacing byte to pending and stride. It does not reset
position. The constructor still leaves stride and all sample arrays untouched.
FinishSample sets held = pending * 3 and clears pending; its name is provisional.

AdvanceTrail only runs its update when the opponent's short 14C is zero.
Positive pending captures a pose and clears held again, retaining the duplicate
original store; otherwise positive held decrements. StartTrail delegates through
the implicit pose-base conversion. No null, range, zero-spacing or failure
guards were added to these original paths.

UpdateInput has distinct CPU and human branches. CPU mode 1 clears four pulse
bytes and horizontal direction, assigns vertical direction from signed reads
of Context byte 1346, and returns early. Other CPU modes invoke virtual slot 5;
Context effectFlag1350/counter1354 suppress pulses and set short 262 to 99.
Human input calls the accepted Input::ReadState, replaces its byte from replay
mode 1 or records it as a word in mode 2, then clears/translates direction and
pulse fields. The replay member remains at Context+14284. Opposing horizontal
button priority depends on facing. Four held ints produce rising-edge pulse
bytes. The same suppression runs before packing the separate 180-byte ring.
The CPU training early return was the sole three-byte difference in the first
complete source; recovering that return gives all 1,467 bytes.

The button ring packs four direction comparisons plus pulses weighted 16/32/64/128,
then advances the signed short position at 260 and wraps at 180. Values >=16
update byte 1A8 for unsigned animation IDs >=200, or 1A9 and counter byte 1AA
for IDs 163..166. The horizontal timer at 14E starts at 60 when direction equals
1 - 2 * (opponent.x - x > 0), with zero timer/latch; it decrements when the
opponent's short 14A is zero. The latch at 150 follows nonzero direction.
The human path then invokes virtual slot 2. These two pure-slot interfaces have
no stack arguments or consumed result; child implementations remain open.
Explicit signed conversion of Context 1346 retains the already accepted unsigned
reads elsewhere. Animation/frame indices at Secondary 8/A are unsigned from
MOVZX evidence; previous initialization/reset bodies retain identical stores.

Render first traverses trail.pending * 3 + trail.held samples with byte stride,
starting at position minus that span, applying single +/-60 normalization steps.
It copies each complete 12-byte PatternFrame and forms source/destination
rectangles with the original signed geometry. Horizontal placement uses facing
comparisons; vertical placement is int(y) + 210 - (y < 0) - frame.v + offsetY.
The corresponding _ftol2 and zero-double destinations are explicit bindings.
Trail draws use DrawBlendedSurface with mode zero.

The current body uses the same geometry. While top <240, nonzero counter 30BC
selects the tint kernel with byte 30B8 and decrements the counter. Otherwise
field58 ==3 selects the special kernel, positive field58 selects blended mode
field58-1, and other values select the normal draw. For top >=240 and short
13E ==0, frame zero of animation 49 is drawn at top 239-frame.v, without offsetY.
Normal, blended, tint and special destinations are 0x409A90, 0x40A0B0,
0x40A440 and 0x40AAE0; the tint parameter is a signed byte. DrawShadowSurface
is the separate 0x40A7B0 owner. All five have natural C++ semantic owners, but
none has complete strict codegen credit. Normal C++ scopes recover the 0x40
frame; the first complete renderer source was strict exact.
Original unchecked indices, zero-stride behavior and floating-point paths are
retained.

Final replay cold builds 32 distinct source/profile/dependency artifacts and
compares six new plus 128 Engine.h-dependent existing units: all 134 complete
comparisons are strict exact. The four dispatchers retain all 75 local-offset
checks and original destinations after compiler-local symbol identity refresh.
Standalone Input, Reader and Config are unaffected and omitted. New public proofs
are secondary-input-exact.json and secondary-render-exact.json; affected-owner
proofs and symbolic source mappings are refreshed. Private aggregate replay is
.analysis/exact/secondary-control-and-affected.json. Full trials, canonical raw
code, caller queries, successor/boundary/operand reviews and the constructor
diagnostic remain under .analysis/probes/secondary-control/ and .analysis/ghidra/.

The first private renderer compile lacked its two external method declarations
and exited with C2039. The declarations were completed, and the repository's
required post-compiler-failure --execute smoke passed C/C++, headers, CRT,
resources, linking and execution before reconstruction resumed. Retained logs
are secondary-control-SecondaryRender-first.log and
secondary-control-toolchain-recovery.log under .analysis/build/. No full CI,
unrequested cold cohort or runtime/failure-injection matrix was run.

## Character frame state and movement

Nine authored contributions add 3,895 instruction bytes under the pinned
vc71-od-static profile. Complete canonical target review covers 1,047 instructions,
144 internal direct branches, all nine final returns and following INT3
alignment, plus 46 explicitly bound relocation operands. No local tables,
auxiliary credit, masked fields or size overrides are involved.

| Original | Complete bytes | Recovered contribution |
| --- | ---: | --- |
| 0x40F230 | 575 | DispatchState |
| 0x40F470 | 262 | CheckAirAction |
| 0x40F580 | 1,012 | UpdateMovement |
| 0x40F980 | 1,509 | UpdateTimers |
| 0x40FF70 | 222 | CollisionSide, signed byte return |
| 0x410340 | 91 | IsStateGroupA |
| 0x4103A0 | 126 | IsStateGroupB |
| 0x40F170 | 31 | ClearBufferedButtons |
| 0x40F190 | 67 | ClearInputHistory |

All are Secondary members in SecondaryFrame.cpp. Names are provisional; the
state groups are defined numerically rather than assigned speculative gameplay
categories. Group A covers IDs 150..156 or 168..171. Group B requires own ID
50..149 and opponent ID other than 97/98/99/96. ClearBufferedButtons clears only
bytes 1A8/1A9. ClearInputHistory clears all 180 history bytes and sets short 262
to 99, without resetting the ring index at 260. These smaller functions complement
the substantial dispatch/movement/timer owners rather than replacing them.

DispatchState requires own short 14A and opponent short 14C to be zero. For IDs
outside 50..150 or exactly 96 it resets own 124/12C and opponent 174, then reduces
opponent double 178 by 20 when above 10,000, otherwise setting 10,000. IDs below
50 invoke virtual slot 3, clear both B8 doubles and apply the original signed
30EC/30EE configuration paths to short 148, int 108, double 118 and byte 120.
IDs 50..149 with float 134 <=0 and frame flag AA bit 0x400 clear call CheckAirAction.
The function ends through virtual slot 4. Both interfaces take no stack arguments
and consume no result; child bodies remain unimplemented.

CheckAirAction decrements positive short 124. Otherwise, negative y, zero int
128 and any of the four pulse bytes enable the facing/input test: matching
horizontal direction selects ID 157; opposite direction selects ID 158. A changed
ID invokes virtual ResetPose before assignment. Other paths retain state.

UpdateMovement gates body movement on own 14A and opponent 14C. Its horizontal
sum includes own velocity 30, own double B0 and opponent B8 multiplied by the
original D0/14C predicate; CollisionSide and signed facing control whether it is
applied. The edge predicates really call CollisionSide on the opponent, as shown
by original ECX setup, rather than on self as the initial decompile suggested.
The x limits are 20 plus a left-edge predicate and 619 minus a right-edge
predicate. Y advances by double 38 and clamps positive values to zero. Ordered
comparisons and original branch direction are preserved, including NaN paths.

The local-effect traversal is outside that body gate. It starts at signed read
index 2CC, stops at write index 2CA and wraps at 64. Active slots move only under
the original own-freeze/slot-88, slot-86 and opponent-freeze conditions. X adds
(vx + 0.0 * slot.double70) multiplied by signed byte slot48; Y adds vy. Slot48
is distinct from the int at 4C. The zero multiplication is real target floating-
point work and is retained, including its NaN/signed-zero implications. Source
expression grouping and compound assignment recover the original FPU evaluation
and register order without temporary padding or opcode wrappers.

CollisionSide returns signed byte +1/-1/0. Its original edge equations use own
x +/-20, opposite x predicates at 20/619, a 639 upper bound and distance constant
280.0 at 0x787C40. Complete AL return instructions and sign-extension at callers
establish the byte return view; Ghidra's reconstructed upper EAX flag fragments
are not a four-byte return contract.

Fresh isolated VC7.1 `/Od /G6 /MT /Gy /W3` recompiles reconfirm these two
collision leaves. `Secondary::CollisionSide` (0x40FF70) is 222 bytes; all
non-relocation bytes match the original, and all six DIR32 fields match by
offset and symbol (20.0, 20.0, 619.0, 639.0, 20.0, 619.0). `Scene3::BoxesOverlap`
(0x767930) is 128 bytes and matches the original byte-for-byte with no
relocations. These were fresh translation-unit compiles and focused function
extractions, not a full cold replay; the existing exact evidence/ledger remains
the authority for accepted ownership.

UpdateTimers skips its gated phase when opponent 14C is positive, then always
runs its final clamps/counters. The gated phase normalizes/decrements own 14A,
char 130, shorts 138/13A/13C/13E/140 and active local slot-86 delays. Frame B0
bit 0x40 sets byte 130 to 27. When not in group A, float 134 decreases by a float
conversion of 1.0/(4*(y==0)+1) for group B, otherwise by 0.075f, and negative values
clamp to zero. The original intermediate float store and extended FPU evaluation
are included in the strict comparison.

Double 118 grows through the original group/flag/500 threshold expression,
divided by 10.0, with byte-120 and 0/1,000 transition paths. The later group-B
query really uses the opponent receiver; it resets counters E4/E0 to 900/12.
When the opponent is outside IDs 50..199 and Context suppression is clear,
positive unsigned E4 decrements; otherwise positive E0/D0 decrement under their
original limits and E4 becomes E0 * 5 * 3. The two multiplications are retained.
The unconditional phase clamps short 148 to 0..3,000 and double 118 with the
original ordered comparisons, decrements int 30F0 with a 12,600 reset, and
conditionally decrements short 104. The 12,600 literal (0x3138) is a counter
constant, not sizeof(Secondary).

The new accesses refine unknown fields 124/128/12C/130, 30E0/E4 and 30EE. Field
134 is float, correcting the earlier int view supported only by zero stores;
the accepted InitializeState remains complete strict exact at 795 bytes. Counters
30D0/E0/E4 and per-frame AA/B0 flags follow explicit unsigned target reads/tests.
All offsets and the minimum 3138 Secondary view remain unchanged. No original
unique class/field names or unchecked-path repairs are claimed.

Reviewed constant destinations include double zero 0x7872F8, double one
0x7875C0, 10,000 at 0x787C00, float zero C08, double 20/619/1,000/10/500 at
C10/C18/C20/C28/C30, float 0.075 at C38 and double 280 at C40. Every relocation
is explicit in its complete unit recipe; no address masking is used.

Final replay cold builds 33 source/profile/dependency artifacts for nine new
and 134 Engine.h-dependent existing units: all 143 complete comparisons are
strict exact. The four dispatchers retain all 75 original local-offset checks
and destinations after compiler-local identity refreshes. Standalone Input,
Reader and Config are unaffected and omitted. New proof is
secondary-frame-exact.json; involved owner proofs, ledgers and progress are
refreshed. Private final replay is .analysis/exact/secondary-frame-and-affected.json.
Full first-source trials, target code, typed-constant/operand/boundary/successor
reviews and the initialization diagnostic are retained under
.analysis/probes/secondary-frame/. No full CI, unrequested cold cohort or redundant
runtime matrix was run; no compiler/Wine failure occurred in this checkpoint.

## Character guard, damage and score

Eleven authored contributions add exactly 2,000 instruction bytes under
vc71-od-static. Independent complete-target review covers 567 instructions,
72 internal direct branches, all final returns and 41 explicit relocation
operands. The 96-byte score routine ends immediately at the next reviewed random
routine entry; the other extents have following INT3 alignment. No local tables,
auxiliary credit or partial/masked comparisons are involved.

| Original | Complete bytes | Recovered Secondary member |
| --- | ---: | --- |
| 0x410050 | 149 | CanGuard(const SecondaryFrame *, const SecondaryFrame *) |
| 0x4100F0 | 494 | GuardInput(const SecondaryFrame *) |
| 0x4102E0 | 89 | AirActionReady |
| 0x410420 | 91 | IsStateGroupC |
| 0x410480 | 163 | DamageFactor, double return |
| 0x410530 | 47 | HealthFactor, double return |
| 0x410560 | 62 | ComboFactor, double return |
| 0x4105A0 | 489 | ApplyDamage(int, double) |
| 0x410790 | 172 | AwardComboScore(const SecondaryFrame *) |
| 0x410840 | 96 | AddScore(unsigned int) |
| 0x4108A0 | 148 | RandomRange(short, short), short return |

Source is SecondaryCombat.cpp. The frame pointer arguments use the existing
200-byte record view, with unsigned flag words AA/B0 and signed short A0.
The three floating helpers return through ST0; Ghidra's float10/undefined-call
presentation is not an integer-return interface. The damage caller's actual
receiver setup selects the opponent for HealthFactor, while DamageFactor and
ComboFactor use self. All names remain reconstruction identifiers.

CanGuard rejects positive short 13A, attack-AA bit 0x80, or missing defense-B0
bit 0x10. With attack-AA bit 4 clear, negative y and short 14E below 30, it also
rejects. Otherwise it delegates to GuardInput and returns int 0/1. GuardInput
retains separate CPU/human branches. CPU training mode 1 requires Context
counter1348; other CPU modes compare float(rand()) against float A8 * 10,000.0f,
then set vertical input from attack-AA bits 1/2. Both paths preserve the original
grounded high/low flag tests. Human horizontal input is checked against opponent
position and the already accepted numeric state-group A predicate. The repeated
grounded checks are retained in each branch rather than factored out.

AirActionReady returns the original int conditional result for nonpositive short
124, negative y, zero int 128 and state group B. Group C is exactly IDs
163/164/165/166, matching the earlier buffered-button range without introducing
a broader gameplay classification. Natural conditional-result form recovers the
AirActionReady stack result; guard floating comparison operand order recovers
rand evaluation and avoids an incorrect intermediate float spill.

DamageFactor is double 118 /10,000 +1, with Context mode 2 overriding setting
1370. Signed-byte setting 1 halves the result, setting 2 leaves it, and other
values double it. An explicit signed conversion preserves the existing unsigned
view/read behavior elsewhere. HealthFactor is
(HP *0.5 /10,000 +0.5) *double180. ComboFactor returns 1 when double178 /10,000
exceeds 1, otherwise returning that ratio, including the original unordered path.

ApplyDamage saves the opponent's initial HP at 10C on combo count zero, then
subtracts int(baseDamage *own.DamageFactor() *opponent.HealthFactor()
*own.ComboFactor()) from HP 108. The complete three-call FPU spill/evaluation
sequence and _ftol2 destination are preserved. It saves double178 /100 at F8,
multiplies 178 by scaling /1,000, and repeats that multiplication if the new value
exceeds 10,000; this really is a second multiplication rather than a clamp.
It advances signed short 174, copies it to F4, sets short104 to 180, records
initial-minus-current HP at 100, updates unsigned combo/damage maxima at
30D4/30D8, advances 30D0 and awards the original score product. Signed integer
division baseDamage /100 occurs before unsigned multiplications. AwardComboScore
performs the corresponding record/count/score updates using signed frame A0.
The complete first sources for all damage/factor/score routines were strict exact.

AddScore adds an unsigned amount to low word 30C8. Each unsigned 100,000,000 carry
subtracts that value and increments high word 30CC, preserving ordinary 32-bit
wrap behavior. The views at A8, 100, 30C8/30CC and 30D4/30D8 are refined as float/unsigned
words from the actual accesses, without changing layout or offsets. Existing
initialization and all involved owners remain exact; no speculative validation
or counter saturation is added.

RandomRange always calls CRT rand first, even when replay mode 1 replaces its
ushort value via WordFile::ReadWord. Mode 2 records the ushort. It returns a
signed short result of low +(high-low)*value /32,768, using the original signed
32-bit product/division and final short narrowing. The named short result and
normal local scope recover the original result/value stack slots; no unused
padding local is used. Source retains the raw interval/replay behavior without
new range guards or a replacement RNG. CPU guard's direct rand path remains
separate. The original WordFile helpers receive no duplicate credit.

Explicit destinations include rand 0x777D61, _ftol2 0x7783B8, WordFile ReadWord /
WriteWord 0x405FB0 /0x406020, and the reviewed member calls. Constants bind to
double zero 0x7872F8, double 2 at 0x787328, one/100 at 0x7875C0/D0,
double 10,000/1,000 at 0x787C00/20, float 10,000 at C48 and double 0.5 at C50.
All relocation bytes participate in the strict complete comparison.

Final replay cold builds 34 source/profile/dependency artifacts for eleven new
and 143 Engine.h-dependent existing units: all 154 full comparisons are strict
exact. Four dispatchers retain all 75 original local-offset checks/destinations
after compiler-local symbol identity refreshes. Standalone Input, Reader and
Config are unaffected and omitted. New proof is secondary-combat-exact.json;
involved owner proofs, ledgers and progress are refreshed. Private final replay
is .analysis/exact/secondary-combat-and-affected.json. Complete initial sources,
trials, canonical code, typed constants and boundary/operand/successor reviews
remain under .analysis/probes/secondary-combat/. No compiler/Wine failure, full
CI, unrequested cold cohort or redundant runtime matrix occurred in this checkpoint.

## Character local effects and Shiori construction

The complete local-effect renderer at 0x413100 (1,488 bytes), descriptor reset at
0x413090 (106 bytes), and Character08 / Shiori constructor at 0x422D70 (462 bytes)
are strict native exact. All twelve new relocation operands were independently
read from the canonical target. These add three authored functions /2,056
instruction bytes, bringing the accepted baseline to **174 authored complete
exact functions /93,524 instruction bytes**, with 335 associated local-table bytes.
Reviewed boundaries and origins are both 212. At that checkpoint the other 22 called character
constructors and all child virtual method bodies remained unimplemented; the
following Shiori checkpoint accepts seven of its virtual bodies.

### Shared local-effect renderer and descriptor reset

RenderLocalEffects takes two signed screen offsets and an unsigned byte layer;
RET 12 and direct calls at 0x764312/33 and 0x764497/4B8 establish the stack slots,
character receiver and unused-result view. It walks the existing 64-entry local
ring, selects active records by layer, and respects record 8C or Context short
1420E suppression. The frame pointer uses the character's pattern array and the
record's animation/frame indices. Mirroring changes horizontal placement;
payload zero enables the screen offsets, with 210 included in the vertical
coordinate. Position conversion uses the original int truncation through ftol2.

Clipping applies only when the record's top and bottom bounds differ. The source
rectangle and destination edges are adjusted in the original left/right/top/bottom
order. Group 3 calls DrawCharacterSpecial (0x40AAE0), positive groups call
DrawBlendedSurface (0x40A0B0) with group minus one, and other groups call
DrawSurface (0x409A90). These kernels now have natural C++ semantic owners in
src/VideoCharacterDraw.cpp, but their strict exact codegen remains open.
MakeSurfaceRect is the already-reviewed 0x40C590 helper; its return and assignment
temporaries explain both intermediate rectangle copies. Source uses two named
rectangles and a PatternFrame pointer, with normal scopes yielding the original
0x4C stack frame. No copied code bytes or artificial ABI locals are used.

ResetLocalEffectSpawn is an ordinary Secondary member taking one descriptor
pointer. The caller at 0x413745/49/4C supplies the same local descriptor first
constructed at 0x413704/07 and the owning character in ECX. The complete helper
saves an unused receiver, writes through [EBP+8], and ends with RET 4. It resets
owner, group, palette, payload, fields 28/30, then bounds top/bottom/left/right in
that order. It is not a this-only constructor. The accepted source keeps the
existing SecondaryEffectSpawn record; the large draft's shared EffectSpawn
inheritance view remains provisional and separate from this proof.

### Shiori constructor and object extent

The constructor calls Secondary's accepted common constructor, installs the
reviewed Character08 table at 0x787DF8, copies shiori from 0x787DF0, and sets the
surface count to 782. It clears eight ints at 3138..3154 and three 64-int arrays
at 3158/3258/3358, preserving the observed 0x3458 allocation extent. Two shared
short views at 2AD0 and 2AF8 expose only the five element pairs actually written;
unobserved storage is still opaque. Command count at 30F4 is five. The original
constructor writes command slot 1 first as 7 and then as 11; source preserves both
stores rather than repairing this observed behavior. Table ownership and all
thirteen original words were reread separately. Exact constructor codegen does
not accept linked virtual-table placement or implement the declared child methods.

The new proofs are secondary-local-render-exact.json and character-08-exact.json.
Thirty-seven cold source/profile/dependency artifacts cover three new and 154
Engine.h-dependent existing units: all **157 complete comparisons are strict
exact**. The four dispatcher recipes retain all 75 checked local offsets and
original destinations after symbol-identity refreshes. Standalone Input, Reader
and Config units were untouched. Private full replay is
.analysis/exact/secondary-local-render-and-affected.json; complete canonical
boundaries, successor/caller facts and operand/ownership reviews are retained in
.analysis/probes/secondary-local-render/. Only focused ledger/progress checks
and whitespace validation are needed for this checkpoint, not a full CI cohort.

### Complete Shiori slot-6 draft remains unaccepted

The thirteen-word Character08 table identifies the animation dispatcher through
slot operand 0x787E10, destination 0x4136D0. Its direct-caller query returns zero;
virtual-table ownership is independently established. Ghidra's 62,273-byte code
candidate ends at 0x422A10, but the complete contribution also includes the
540-byte jump-address table starting at 0x422A11 and 319-byte selector map at
0x422C2D. The full extent ends at 0x422D6C, before four INT3 alignment bytes and
the now-accepted constructor. All 16,876 instructions decode contiguously; direct
branches and all 135 address entries land on reviewed instruction starts. The
map selects 134 explicit branches plus the default over animation IDs 1..319.

A complete C++ source was built early, with all branches and both generated
switch tables retained in the comparison. Target-backed fixes recover the freeze
gate, real animation IDs, original clamp/landing order, immediate state exits,
integer particle-coordinate conversions, EAX-sized facing-helper result and
unsigned byte/word caller reads. The target stack frame is 0x384, with duration
at EBP-4, frame count at -8, a single effect descriptor at -50 and receiver at -54.
The private source and its provisional header recover those locations.

The parked complete contribution is **63,133 bytes versus 63,132 target bytes**.
This is a one-byte extent delta, not one remaining byte difference. The first
instruction/register divergence is 0x41FC1E, in animation 303 after a conditional
sound-selector write. Remaining diagnostic differences occur in animations
303..309 and 312..318; extent differences are +1 in 307/308 and -1 in 315.
Normalized per-case diagnostics confer no progress credit, and the complete
function remains outside matches.csv and implemented.csv. Private preservation
and exact resumption instructions are .analysis/probes/shiori-state/README.md
and parked-best/. The baseline's signed-short RandomRange declaration is kept;
the draft uses explicit unsigned-short caller conversions for its AX zero extends.

Pre/post increment, extra normal scope, combined tick comparisons, nested tests,
signed tick storage with unsigned reads, and the signed/unsigned random caller
views were neutral for the unresolved register divergence and are parked. A plain
increment assignment lowered differently; an explicit goto added a branch. Do
not repeat these controls or introduce padding, bytes, assembly or an acceptance
size override. The large private prototype/rename source errors were corrected
and pinned toolchain execution checks passed; all final accepted-unit builds and
comparisons above succeeded. Original translation-unit context and private draft
field/helper views remain hypotheses requiring fresh evidence before integration.

## Shiori command state and shared locomotion

Nine complete authored contributions add **13,965 instruction bytes**, including
Shiori's complete 11,306-byte command/state dispatcher. The accepted baseline is
now **183 authored exact functions /107,489 instruction bytes**, with the existing
335 associated local-table bytes. All 221 reviewed boundaries/origins remain
separate from the 950 provisional inventory candidates. No full-game or linked
virtual-table completion is claimed.

| Source view | Canonical entry | Complete bytes |
| --- | --- | ---: |
| Secondary::FaceOpponent | 0x40E630 | 130 |
| Secondary::UpdateLocomotionState | 0x40E740 | 923 |
| Character08::InitializeState | 0x422F40 | 322 |
| Character08::ResetPose | 0x423090 | 58 |
| Character08::RemoveLocalEffect | 0x4230D0 | 80 |
| Character08::Slot03 | 0x423120 | 19 |
| Character08::Slot04 | 0x423140 | 11,306 |
| Character08::Slot01 | 0x425D70 | 1,080 |
| Character08::EmitLocalEffect | 0x4261C0 | 47 |

### Owning table and exact function extents

A fresh canonical read of the thirteen-word table at 0x787DF8 identifies Shiori
slots 0/1/3/4/9/10/12 with the seven child bodies above. In particular the command
entry is slot 4 at operand 0x787E08. The already-accepted constructor installs
this table and copies resource name shiori; the object extent remains 0x3458.
All new boundaries decode contiguously through their final RET. Direct branch
targets remain within each complete function and land on decoded instruction
starts. The command body ends at 0x425D6A, followed by six alignment bytes before
slot 1 at 0x425D70; no local switch data is dropped from this owner. All **119 new
relocation operands** were independently read from the target before acceptance.
No address mask, prefix match, size override or artificial ABI local is used.

Character08 now has eight accepted source functions including its constructor,
seven of them virtual bodies, totaling 13,374 instruction bytes. The inherited
resource loader remains a shared accepted contribution, without duplicate credit.
The other Shiori virtual bodies, original linked table placement, other character
bodies and the complete Windows product remain separate work.

### Command priorities, action selection and byte flags

Slot04 consumes the signed command token at 262, current/queued input bitfields
at 1A8/1A9 and their unsigned byte lifetime at 1AA. It clears current bits below
animation 200, decrements the positive lifetime, and keeps lifetime/queued bits
consistent in the original order. Fields 159/15A are unsigned byte counters from
the actual MOVZX reads; these and 1A8/1A9/1AA refine prior store-oriented char
views without changing any offset or object extent. Existing input-history
producers and shared initialization/buffer clears remain exact.

Transitions compare the current sequence's signed field0002 against each target
sequence's signed field0000, test frame word B0 bit 8, and retain the original
animation/cancellation gates. Common attack gates allow animations below 200 or
cancellation value at least 2 other than 6; the first special transition retains
its distinct greater-than-1 comparisons. Health 3,333, power 1,000/2,000/3,000,
resource 500 and child state checks remain literal target-backed predicates.
Every reset, buffered-input clear, facing update and state write keeps its
original order. Ground/air choices preserve the separate less-than-zero and
exact-zero conditions, including the original unordered floating behavior.

The directional conditions evaluate opponent X minus self X before multiplying
by the integer factor 1 - command*2. The negative tie-direction uses an actual
multiply by -1 rather than an invented ABI cast or an altered test. The first
complete source was built early. Full target comparison exposed reversed
integer thresholds, decompiler return guards, operand order and byte signedness;
those were corrected from complete original branches. Redundant parentheses
and indentation were cleaned up and the complete contribution remained zero
difference. All early exits and complete button/normal/special paths are present.

FaceOpponent retains signed previous facing, compares self/opponent X, writes
+1 or -1 and returns an EAX-sized int indicating whether facing changed. Equal
or unordered positions leave facing unchanged and return zero. This corrects
the provisional decompiler bool-return view using full instructions and an
original caller that consumes EAX. UpdateLocomotionState clears the two air
counters at exactly zero height, then handles nonnegative height outside states
4/5/6/10/11/12. Its jump, crouch, stand-up, idle and directional walk transitions
preserve when the state ID is set before or after virtual ResetPose and facing
updates. Slot03 is the complete nineteen-byte direct delegation to this shared
owner, not a reconstruction of another character's bytes.

### Child initialization, local effects and meter

InitializeState clears all eight child state ints, both observed five-short
coordinate views and the three 64-int arrays, then calls the accepted shared
initializer. ResetPose clears the first three child state ints before calling
the shared pose reset. RemoveLocalEffect clears the three arrays at the signed
slot index before the shared ring removal; no new bounds guard changes original
behavior. EmitLocalEffect first dispatches virtual removal at effectWrite, then
calls the shared emitter. This preserves child ownership cleanup on ring reuse.

Slot01 renders the state-counter-314C meter from pattern sequences 43 and 44,
frame zero. Positive counter checks remain separate around the two draws. Player
placement uses anchors 49/271 and Y=31 with original frame offsets; it does not
add a mirror flag. Filled width is counter*frame.width/3,600 using signed integer
arithmetic with the original evaluation order and no added saturation. Two named
rectangles, a twelve-byte PatternFrame and the compiler's six return/assignment
temporary pairs naturally reproduce the complete 0xF4 stack frame. Reversing the
integer multiplication operands had the same arithmetic result but removed
required moves under VC7.1 /Od; retaining the original order matches all 1,080
bytes. MakeSurfaceRect and DrawSurface remain independently bound callees.

### Focused replay and next owner

Forty-one cold source/profile/dependency artifacts cover the nine new and 157
Engine.h-dependent existing units: all **166 complete comparisons are strict
exact**. The four dispatcher recipes retain all 75 local offsets/destinations;
the constructor's numbered string symbol was refreshed only after its COFF
literal was independently checked against the seven original shiori bytes.
This refresh changes symbol identity, not an accepted relocation field or its
destination. New Shiori reports join character-08-exact.json; shared facing and
locomotion proofs are secondary-locomotion-exact.json. Existing involved proofs
are refreshed; standalone Input, Reader and Config contributions were omitted.
Private full replay is .analysis/exact/shiori-command-and-affected.json. Full
sources, cold trials, contiguous boundaries, successor/table ownership and
operand reviews are retained in .analysis/probes/shiori-command/. No compiler or
Wine failure occurred in this checkpoint; only focused ledger/progress and
whitespace checks are required, without full CI or runtime matrices.

The following input-history, CPU and local-effect checkpoints accept the complete
slot-2, slot-5 and slot-7 owners described below. Their former discovery sizes
were not acceptance boundaries; the local-effect review also includes both
associated switch tables. The complete slot-6 animation draft remains unaccepted
in its private parked snapshot; neutral controls there are not reopened.

## Shiori input history recognition

Character08::Slot02 is the complete 5,299-byte input recognizer at
0x4261F0..0x4276A2, exclusive end 0x4276A3. All 1,536 instructions and 246 direct
internal jumps were reviewed; a single final RET is followed by thirteen INT3
bytes before 0x4276B0. There are no calls, COFF relocations or associated local
tables. The Shiori table at 0x787DF8 independently points slot 2, operand
0x787E00, at this entry. Source is src/Character08Input.cpp under the explicit
VC7.1 /Od /G6 /MT /Gy profile. Its complete cold native contribution is strict
exact: 5,299 of 5,299 bytes, zero differences, with no masked operands.

The decompiler's deeply nested loops are sixteen successive, priority-ordered
recognition scans. The function first sets signed command token field0262 to 99.
Each scan clears an unsigned progress byte and walks the history interval from
field0260 plus a fixed offset through field0260+179. Ring access subtracts 180
once when i>=180; the target does not compute general remainder. Facing at 0x50
is signed, the sample at history[180] is unsigned, and field0260 is signed short.
Low-nibble directions, button masks, progress stages and the original scan order
remain explicit. Meter field0148 and current animation field0008 gate specific
patterns. The accepted slot-4 dispatcher consumes the resulting token.

| Scan priority | Samples | Accepted token or button-dependent base |
| --- | ---: | --- |
| 1 | 90 | 0x5F; requires meter == 3000 |
| 2 | 90 | delayed 0xAA; same-sample 0xA0; requires meter >= 1000 |
| 3 | 75 | 0x78; requires meter >= 1000 |
| 4 | 90 | 0x65; requires meter == 3000 |
| 5 | 90 | 0x6E; requires meter >= 1000 |
| 6 | 60 | 0x14 |
| 7 | 45 | 0x0A |
| 8 | 45 | 0x28 |
| 9 | 45 | 0x1E |
| 10 | 5 | 6; separate release/press checks on bit 8 |
| 11 | 90 | 0x35; requires animation 0x60 |
| 12 | 90 | 0x34 |
| 13 | 45 | 0x33 |
| 14 | 45 | 0x32 |
| 15 | 45 | 1 |
| 16 | 45 | 0 |

Button-dependent results add ((sample&0xE0)>0), ((sample&0xC0)>0) and
((sample&0x80)>0) to the stated base. The second scan's delayed and same-sample
bases really differ in the original instructions; preserve this behavior.
Stage updates use consecutive checks rather than an else-if chain, so a sample
can advance multiple stages where the original predicates permit it.

The first complete draft was compiled early. Exact reconstruction required the
original single-wrap index, signed facing selection expressions, positive
button-mask comparisons without narrowing casts, >=1000 meter comparisons,
and stage==1 in the short release/press scan. The decompiler's boolean guess
for that stage loses an original comparison. Natural C++ reproduces the entire
function without wrappers, assembly, padding or target-byte injection.

One new formal cold artifact and one strict comparison suffice: no shared header
or previously accepted source changed. Eight earlier Shiori reports remain
unchanged in docs/evidence/character-08-exact.json; the new report is appended.
Private evidence, full source trials and boundary review are retained in
.analysis/probes/shiori-input/; formal report is .analysis/exact/shiori-input.json.
At the input-recognition checkpoint, authored acceptance is 184 complete functions /112,788 instruction bytes,
with 335 associated local-table bytes; reviewed boundaries and origins are 222.
Product closure, linked data placement, runtime equivalence and portability
remain independently open.

## Shiori CPU command and movement owner

Character08::Slot05 is the complete CPU input/command owner at 0x4276B0,
**15,066 instruction bytes**, exclusive end 0x42B18A. All 3,883 instructions,
722 internal direct branches, 93 direct calls and the single final RET were
reviewed against the canonical executable. Six following INT3 bytes precede
slot 7 at 0x42B190. There are no indirect dispatches or associated local tables.
The independently checked owning table is 0x787DF8, slot 5, operand 0x787E0C.
Source is src/Character08Cpu.cpp under VC7.1 RTM /Od /G6 /MT /Gy.

The owner initializes command token field0262 to 99, decrements two positive
signed movement timers at 1A0/1A4, clears directions and all four button pulses,
and resets short field014E. Three difficulty-weighted random checks can store
60 into field014E; the mode-2/field0170==1 path stores 30 and exits, clearing the
CPU mode when current animation is below 200. Opponent animation 96 is a
separate early exit. The function then computes facing-relative horizontal
separation and absolute vertical separation using the original external fabs.

Grounded/current-animation priority exits, meter/air-action checks, strategy
modes, per-animation random choices and fallback movement remain in their
original order. The animation-50..150/tick-zero branch first chooses a strategy
mode, then sets a random horizontal direction. Its two button-3 assignments
really occur consecutively: the second overwrites the first result, while both
random calls advance the generator. Do not merge them or drop a call. A later
opponent-animation/frame/distance predicate can clear that pulse again.

The priority command-52 path requires available air action or field0118>500,
a difficulty-weighted random check, opponent animation 150..156 and one of
current animations 250/251/252/270/271/272. Later strategy choices produce both
raw input pulses and the same numeric command tokens as the accepted input
recognizer. Two final movement-command gates precede fallback random movement.
Active timer 1A0 moves positively; otherwise active timer 1A4 moves negatively;
either can be shortened to 15 after CollisionSide. Only when neither is active
does the function choose new random timer durations. Both facing-dependent
branches and their original random-call order are preserved.

### Shared views and exact reconstruction

Five typed fields replace existing padding without changing any observed
extent: signed short field016C plus two retained unknown bytes, signed ints
field01A0/field01A4, and signed ints field3110/field3114 after the retained seven
bytes at 3109. Both this and opponent short reads at 16C are signed; movement
timer and random-bucket comparisons use signed ints. Field3110 holds random
selection buckets in this owner; field3114 selects CPU strategy modes. These
are provisional semantic descriptions, not claims about original member names.

All ninety RandomRange calls immediately zero extend AX in the original caller.
The source therefore retains the accepted signed-short declaration and casts
each caller result to unsigned short. CollisionSide remains the accepted
char-returning method. The fabs call binds at 0x77842D with an eight-byte cdecl
argument, caller cleanup and x87 return. The original implementation's ordinary
finite path clears the argument's high-word sign bit with 0x7FFFFFFF and loads
the resulting double; special-value/control handling is also present. This
binding does not claim that the CRT implementation is reconstructed.

All **297 relocations** were independently checked at their original operand
positions: 93 direct calls and 204 floating operands. The 38 distinct float or
double literal payloads were checked in both canonical data and the COFF
constant sections. Each relocation records its exact symbol, destination,
width/value evidence and type. There are no masked or inferred-by-size fields.

The first complete source was compiled early. Restoring original early exits,
positive short conditional tails and the two final command-priority gates
recovers the real branch ordering hidden by the decompiler's nested conditions.
Difficulty multiplied by two emits the original single load and FADD ST(0),ST(0),
where two separate member reads introduce an extra load. Original floating
operand order, >=1000 meter checks, unsigned random results and both exits in
the animation-204 branch are retained. A normal sixteen-byte local record groups
forward/vertical distances and preserves their observed stack positions with
the complete 0xC0 frame; it has no external ABI role and does not establish the
original source's record type. Both fields are used. No padding locals,
assembly, original-byte arrays or byte patches are introduced.

### Focused cold acceptance

One new unit and 167 Engine.h-dependent existing units compare strict exact
from **43 serial cold source/profile/dependency artifacts**. Every comparison
includes its complete code and local tables. All 75 existing compiler-local
symbol offsets/destinations were rechecked; changed local/string symbol names
are refreshed only after reviewing the COFF offset or literal bytes at the
same original destinations. Per-unit receipts retain the cold compiler/source
identity and the final reviewed recipe identity; relocation binding changes
are oracle inputs and do not alter compiler inputs. Unaffected standalone
Input, reader and configuration sources were omitted. Public involved proofs
are refreshed, with the new report in character-08-exact.json.

Private complete source trials, original code, boundary/operand reviews,
constant payload checks and binding-identity records are retained in
.analysis/probes/shiori-cpu/. The final formal reports are
.analysis/exact/shiori-cpu-and-affected.json. Focused ledger/progress and
whitespace checks pass; no full CI/cohort or runtime matrix was run. No native
compiler or Wine failure occurred during this checkpoint.

At this CPU checkpoint, authored acceptance is **185 complete functions /127,854
instruction bytes**, with 335 associated local-table bytes and 223 reviewed
boundaries/origins. Shiori has nine accepted child virtual bodies plus its
constructor, totaling 33,739 instruction bytes. The subsequent checkpoint below
accepts slot 7. Slots 6 and 8, original linked-data placement, runnable
product/runtime closure and portability remain independently open.

## Shiori local effect dispatch and controls

Character08::Slot07 is the complete local-effect update owner at **0x42B190**.
Its **36,467-byte contribution** contains 36,135 instruction bytes through the
RET at 0x433EB6, a 232-byte address table at 0x433EB7 and a 100-byte selector
map at 0x433F9F. Exclusive end is 0x434003; thirteen INT3 bytes precede the
following 77-byte polar-velocity helper at 0x434010. All 8,192 instructions,
516 direct branches and the single indirect dispatch were reviewed. Fifty-seven
explicit effect types in 400..499 select 57 case destinations; 43 selector
entries use the default destination. All 58 address entries point at reviewed
instruction starts. The owning Shiori virtual table at 0x787DF8 independently
points slot 7, operand 0x787E14, to the entry. Candidate code-only size never
substitutes for the complete code/data contribution.

The function exits if the opponent's signed field014C is positive, initializes
its signed ring index from effectRead and constructs one 72-byte descriptor.
It reads the current effectWrite on every loop condition, rather than taking a
snapshot. Active effects proceed only when short field0086 is zero and the
original self-field014C/field0088 freeze predicate permits updating. Duration
and frame count are read from this character's patterns using the effect's
unsigned type/frame. ResetLocalEffectSpawn receives this character and the
SAME descriptor address before dispatch. The loop advances and wraps at 64.

Cases control ticks/frames, velocity/acceleration, effect spawning/removal,
child counters, opponent capture/position/damage, camera/flash requests and
scene-transition requests. Some paths return from the whole function; others
leave only the current switch. Those distinctions and the original random-call
order are explicit in the source. The machine code physically places type 443
before 442, while the provisional Ghidra output sorts case labels numerically;
the C++ source restores the original 441/443/442 order. Shared exit destinations
are also preserved, even where a local skip would produce the same final state.

### Descriptor, fields and support owners

EffectSpawn now derives naturally from the existing SecondaryEffectSpawn view.
Both describe the same observed 72-byte local object, constructed at 0x405490,
reset via 0x413090 and passed to both character/local and Context/global effect
emitters. The nonvirtual base conversion preserves the original address and
introduces no helper call or displacement. This is a source representation of
reviewed common storage and usage, not proof of original class inheritance or
translation-unit partitioning. Existing constructor/emitter callers all retain
complete exact comparisons. No fake ABI declaration or padding member is used.

Existing Secondary padding at C0/C8 becomes two doubles; byte 30C0 replaces one
byte of its four-byte unknown region, keeping three bytes at 30C1. Context exposes
byte F33, ints 1423C/14244 and byte 14280 while preserving the intervening unknown
storage and every following offset. These numerical views are target facts;
behavioral names below are provisional.

| Support owner | Entry | Complete code bytes | Original behavior |
| --- | --- | ---: | --- |
| SecondaryEffectSlot::SetVelocityPolar | 0x434010 | 77 | vx=cos(angle/57.29579143313326)*speed; vy=sin(angle/57.29579143313326)*speed, using the independently checked exact divisor payload |
| Secondary::SetVerticalShake | 0x410A10 | 43 | Store signed magnitude as Context double 14210, then hold at 14218 |
| Secondary::SetHorizontalShake | 0x410A80 | 63 | Store (1-player*2)*magnitude at Context 1423C, then hold at 14244 |
| Secondary::SetTint | 0x410B10 | 96 | Store byte 30C0 and int duration 30C4; halve duration when setting136C==0; store player at Context F33 |
| Context::RequestTransition | 0x407CE0 | 38 | Store 1 at state1427C and the request byte at 14280 |

All five support owners are independent complete exact functions, totaling
317 instruction bytes. The tint parameter's unsigned-byte view retains the
original 0xB0 caller pushes; the callee copies the byte without extending it.
The polar helper's receiver is the complete effect slot, with writes at 28/30,
not a pointer to a fabricated velocity-only ABI object. Cos/sin/float-to-int/CRT
random bindings remain explicit callee dependencies, not reconstructed CRT credit.

### Source and comparison details

The first complete source was compiled early. Normal local scope places the
two unsigned duration/count words at EBP-54/-58, the loop index at -4, the
72-byte descriptor at -50 and this at -5C. The complete frame is 0x328. Locals
are real used values; no dummy object or inert stack padding is present. Natural
short increments/decrements preserve the original word-width operations.
Original clamp order, early lifetime/cancellation exits, layer stores and
floating/integer operand grouping are restored from instructions, not assumed
from the decompiler. In particular, center+(RandomRange-40) preserves both call
order and LEA base/index identity; indexed-position-plus-scalar expressions
must retain their original operand order under VC7.1 /Od.

The final particle cases demonstrate why equivalent algebra is insufficient.
For type 497, VX is 1.2*B1+0.7*B2+1.7*B3-1.8 and VY is
-1.2-(0.6*B4+0.9*B5+1.4*B6). For type 498, VX is
B1+0.5*B2+1.5*B3-1.5 and VY is -1.0-(0.5*B4+0.8*B5+1.2*B6).
Each B is a DISTINCT rand()>16000 evaluation in the listed order, after two
earlier lifespan-bucket calls. Coefficients are recovered from the exact
canonical payloads, including the distinct 0.8 and 0.9 data addresses. Reordering
the calls changes which random value receives each coefficient. Every source
trial retains its full native artifact; normalized diagnostics confer no credit.

All **430 new relocation fields** were independently checked: the main owner has
60 compiler-local bindings, 141 direct calls and 225 floating operands; the polar
helper adds two math calls and two divisor references. Every constant payload
was checked in both COFF and canonical data. Every local pointer/table entry
has an explicit symbol, canonical destination and checked compiled offset.
The full 36,467-byte strict comparison includes BOTH tables without masking.
There is no compare-size override, byte injection, assembly or linked-data
approximation. Code and associated data are counted separately in progress.

### Focused acceptance and remaining work

Six new units and 168 Engine.h-dependent existing units compare strict exact
from **45 serial cold source/profile/dependency artifacts**. All 135 selected
compiler-local offsets/destinations and the constructor's literal identity are
checked after the header change. Per-unit final receipts preserve the actual
cold compiler/source/profile and reviewed recipe identities; binding-name
refreshes do not modify compiler inputs or object bytes. Standalone Input,
reader and configuration sources were unchanged and omitted. Focused ledger,
progress and whitespace checks pass; no full CI/cohort or runtime matrix ran.

Public source is Character08Effects.cpp and SecondaryEffectControls.cpp.
The main proof joins character-08-exact.json; independent support proofs are
secondary-effect-controls-exact.json. Involved earlier certificates are
refreshed. Private original/source trials, complete boundaries, operand/payload
reviews, case-order diagnostics and final symbol-identity refreshes are retained
in .analysis/probes/shiori-effects/. Formal full reports are
.analysis/exact/shiori-effects-and-affected.json. Two draft member-renaming
compiler errors were corrected; each was followed by the required successful
toolchain execution check. Both failed inputs and compiler exit logs are retained.

Authored acceptance is now **191 complete functions /164,306 instruction bytes**,
plus **667 associated local-table bytes**. Reviewed boundaries/origins are 229.
The new checkpoint contributes 36,452 code bytes and 332 local-table bytes.
Shiori has ten accepted child virtual bodies plus its constructor, totaling
69,874 code bytes. Slot 6 remains an unaccepted complete private draft; slot 8
is still open. No whole-game, original linked-data, runnable replacement,
runtime equivalence or portability closure is claimed.

## Battle scene construction, camera and events

Scene ID 3 is the battle owner. Startup constructs Scene3 at 0x7633A0 with a
0x598-byte allocation and the seven established Scene base arguments. The
constructor stores table 0x7895DC, independently read as renderer 0x7642A0,
Step 0x763C20 and keyboard 0x765660. These bodies are accepted complete strict
exact in the SceneBattleLoop group (docs/evidence/battle-loop-exact.json); do
not treat them as open owners. The collision and round-resolution callees remain
independent targets and must be evaluated separately from the accepted caller.
Scene ID 2 is a loading interlude: its Step 0x76C790 chooses system\\nl\\nl000..174
resources, performs fades and returns scene ID 3. Do not conflate it with battle.

| Authored owner | Entry | Complete instruction bytes |
| --- | --- | ---: |
| Scene3 constructor | 0x7633A0 | 2,129 |
| Scene3::UpdateCamera | 0x7647B0 | 1,530 |
| Scene3::PlayCharacterSounds | 0x764DB0 | 337 |
| Scene3::PlayEffectSounds | 0x764F10 | 296 |
| Scene3::UpdateIntro | 0x766070 | 292 |

All five boundaries were reviewed from entry through final RET, including every
conditional path, direct call and following CC alignment. There is no associated
local table. The constructor has 517 instructions, the camera has 426, the two
sound consumers 93/81, and the intro owner 73. All 45 relocation operands have
explicit original destinations: 31 direct calls, one Scene3 vptr and 13 floating
constant operands. Callee receivers/arguments were checked against original
instructions and the accepted shared implementations. IEEE payloads were checked
independently; the vtable is a binding, not reconstructed linked-data credit.

The constructor initializes 17 real SurfaceRect members at 0x464..0x564 using the
accepted MakeSurfaceRect return ABI. Its actual 0x224-byte frame arises naturally
from the used struct-return/assignment temporaries and this pointer. Initial
state includes camera coordinates/weights, an unsigned-byte update count of 3,
shorts 0/9999 at 574/576, double zero at 580 and three counters at 434/438/43C.
Context counter1354 becomes zero and effectFlag1350 becomes one. Numeric field
names intentionally retain uncertainty about unimplemented consumers.

UpdateCamera preserves the original weighted horizontal target, -319..0 clamp,
integer easing divisors 15 and 10, and 0..240 vertical clamp. It reads Context
14238/14240 for the temporary horizontal weighting and 1423C/14244 for vertical
composition. Those hold counters decrement only when both characters' shorts
14A/14C are zero. The vertical expression deliberately repeats casts and negative
comparisons, including `(int)y - (y < 0.0)`; replacing it with a generic rounding
function would change behavior for negative integral values. Preserve signed
integer division before unary negation. Context::UpdateCameraShake is then called,
Context cameraBounds at 14248 receives the actual 320x240 world rectangle, and
shake offsets 1421C/14220 feed Scene3 draw offsets 45C/460. The new Context fields
replace retained unknown storage without moving later fields.

PlayCharacterSounds consumes signed bytes 2C9 (Context slots 0..64) and 2C8
(character slots 0..49) for both players, calling Audio::StartSound(slot,0) and
clearing each consumed request to -1. In scene flag state 2 it only clears both
requests. PlayEffectSounds walks the 640-entry Context ring from field1382 to
field1380 and consumes the signed-byte view of record offset 6C, likewise
clearing requests or suppressing playback in state 2. The existing record member
is provisionally named palette; its signed sound-consumer view is an explicit
cast, preserving existing accepted unsigned users and the actual record ABI.
Do not infer a final semantic record model from that older member name.

UpdateIntro constructs one genuine EffectSpawn only after the initial nonzero
flag test. Its byte switch handles flag 1 (effect type 27, sound byte 255, hold
300) and flag 2 (type 5, sound byte effectSelector+11, hold 270). Both emit at
(160.0,120.0), group/layer 2, payload 1, then store flag 99 and short hold at
Context 1352. The EffectSpawn constructor, emission and Audio functions are
already accepted complete dependencies; no fabricated call ABI is introduced.

The first complete constructor source matched immediately. Camera operand order
and integer-negation grouping were corrected using the full instruction trace.
Used local declarations/scopes reproduce the remaining VC7.1 /Od stack slots;
every trial retains a complete comparison. A draft referred to nonexistent
Secondary x/y names; the source was corrected to the accepted numerical fields
and the required compiler/Wine execution smoke check passed. This adds no tests
to ordinary unit acceptance.

Final source is src/SceneBattle.cpp. Five new and 174 Engine.h-dependent existing
units compare completely from 46 serial cold source/profile/dependency artifacts;
only explicit involved units were selected. All 135 existing compiler-local
bindings are checked against original destinations and actual COFF offsets.
Standalone Input, reader and configuration units remain outside this replay.
Public proof is docs/evidence/scene-battle-exact.json, with affected certificates
refreshed. Private complete boundaries, decompiler hypotheses, source attempts
and operand reviews remain in .analysis/probes/scene-battle/; the 179-unit
private affected report is preserved in
.analysis/cleanup/2026-11-07/retired-trials-and-reports.tar.gz as
.analysis/exact/scene-battle-and-affected.json. Ledger/progress and whitespace
checks are the only checkpoint checks; no full CI or runtime matrix was requested.

This checkpoint adds **5 complete functions /4,584 instruction bytes**, bringing
authored acceptance to **196 functions /168,890 instruction bytes**, plus the
unchanged 667 local-table bytes. Reviewed boundaries and origins are 234 each.
At this 2026-11-08 checkpoint, the complete battle loop, draw/keyboard entries,
collision and round-resolution owners remained open. Later sections record the
subsequent strict-exact acceptance of those owners; these five functions did not
by themselves establish a playable battle.

## Battle collision dispatch and world boxes

The battle owner now accepts five more complete Scene3 members, all on the
canonical target and explicit VC7.1 /Od /G6 /MT /Gy /W3 profile:

| Authored owner | Entry | Complete instruction bytes |
| --- | --- | ---: |
| DispatchCollisions | 0x766480 | 1,734 |
| TransformPoseBox | 0x767600 | 405 |
| TransformSnapshotBox | 0x7677A0 | 390 |
| BoxesOverlap | 0x767930 | 128 |
| TestBodyInteraction | 0x7679B0 | 1,456 |

Full boundary review covers 996 instructions, all 81 direct branches, 35 calls,
final RETs and following alignment. No local table belongs to these functions.
All 43 relocation fields were independently checked against original operands:
35 explicit callees and eight references to the exact double 0.5 at 0x787C50.
Callee ownership, receiver, stack arguments and result width are separate from
implementation credit. At this dispatcher-only checkpoint the large body/effect
hit owners remained open; their subsequent strict-exact source acceptance is
recorded in the later collision-owner section.

### Genuine snapshots and calling conventions

BattleCollisionSnapshot is the actual aggregate written by DispatchCollisions
and consumed by the collision helpers: SecondaryFrame at 0..C7, PatternFrame at
C8..D3, natural alignment before doubles X/Y at D8/E0, facing byte E8, state byte
E9 and signed command word EA. Its normal size is F0. The frame contains the five
body boxes at 0, four attack boxes at 50, special box at 90 and existing numerical
fields; it is not a fabricated ABI object. The dispatcher copies real 200-byte
frames and 12-byte image frames, then stores positions and facing independently.
Only after effect/body passes does it copy the low byte of Secondary field168
and the word at 16C into each snapshot. The original order and widths are retained.
Secondary field144 is the observed 32-bit reset field, replacing four of
the six unknown bytes after 142 while preserving the two-byte 142 region and all
later offsets.

Both box-transform functions are ordinary Scene3 members. ECX is the scene,
stack +8 is the hidden SurfaceRect return pointer, +C is the genuine pose or
snapshot pointer, and +10 is the EXPLICIT source-box pointer; each ends RET 0C.
Ghidra omitted that box argument and the x87 input values from its C output.
TransformPoseBox reads the existing SecondaryPose base view, including pattern
U/V, world X/Y and signed facing; TransformSnapshotBox uses the copied sprite
and pose. All values and widths are reviewed from instructions rather than the
incomplete decompiler signatures.

For facing==1, top/bottom are integer conversions of Y-V+sourceTop/Bottom, and
left/right are conversions of X-0.5-U+sourceLeft/Right. The other branch mirrors
horizontally: X+0.5+U-sourceRight/Left. Both branches keep the same vertical rule.
The original half-pixel operand is exactly 0.5; do not assume an epsilon or replace
the conversion with floor. The nested ordinary scopes retain the live horizontal
offset, real return rectangle and calculation-only vertical offset without dummy
locals or injected bytes. Each 3C-byte frame and all eight float-to-int calls are
part of the complete comparison.

BoxesOverlap rejects nonpositive width/height for either input, then returns
`~((b.right-a.left)|(a.right-b.left)|(b.bottom-a.top)|(a.bottom-b.top)) >> 31`.
Its signed result is -1 or 0, not Boolean 1. Edge contact counts when both boxes
are themselves nonempty. Keep all subtraction/bit operations and the signed
arithmetic shift; a conventional strict-overlap predicate changes behavior.
It is a member with two box pointers and RET 08, not an invented free-function ABI.
A fresh isolated SceneCollision.cpp compile reconfirmed all 128 target bytes and the zero-relocation contract.

### Pushbox response: local VC7.1 exact code generation

**Current 2026-11-09 result (supersedes the unsuccessful probes below):**
`Scene3::ResolvePushboxes` at 0x00766B50 is now a complete local
`scene-battle-resolve-pushboxes` exact match. The source fix is checkpointed
in `cabe2d9` (`gpt-web: exact match battle pushbox resolution`).
A fresh `scripts/repo-python scripts/build-match-unit.py --unit
scene-battle-resolve-pushboxes` followed by
`scripts/repo-python scripts/compare-coff-function.py --unit
scene-battle-resolve-pushboxes` returns `result: exact`, 2,727 of 2,727
matched bytes, `difference_count: 0`, and all 35 target COFF relocations
at identical offsets with matching owners. This is **local complete-function
code-generation evidence**, not a Factory-accepted canonical replay receipt
or proof of whole-image/runtime completion.

**Actual source-level breakthrough:** Four boundary checks originally
looked like unused named `int` locals, but declaring such locals before the
rest of the expression spills changes MSVC 7.1's stack allocation.
The exact C++ candidate instead evaluates the stand-alone conditional
expressions `(condition) ? 1 : 0;` with no named receiver; at `/Od` MSVC
still materializes their 32-bit comparison results at the original
stack locations. This moves `this` back from EBP-0x70 to EBP-0x60,
conditional pose pointers to EBP-0x64/-0x68, and the two hidden
`SurfaceRect` return buffers to EBP-0x4c/-0x5c. It also brings the x87
integer-to-float slots back inside the disp8 range: the former
function+0x269 relocation drift to 0x275 disappears.

**Final control-flow correction:** Two `return;` statements belong
*after* their inner velocity comparison blocks, but *inside* their
respective `CollisionSide()` branches. They select the original
function-end jump from offsets 0x35E and 0x4ED directly to 0xAA3;
putting the return inside the nested comparison instead introduces
extra unconditional jumps and expands the function to 2,737 bytes.
The completed source retains the asymmetric sign/clamping rules and
single shared-velocity average exactly as observed in x87 instructions.

The following paragraphs preserve the **historical pre-exact diagnosis**,
including rejected hypotheses, old source SHA-256s and earlier partial
replay scores. Their statements that the owner is "still open", that
the best source remains non-exact, or that relocation 617 still drifts to
629 are now superseded by the focused exact comparison above.

#### Pre-exact investigations (historical, superseded)


A fresh canonical-target review establishes the complete extent of the large
pushbox resolver at 0x766B50: 2,727 bytes, 708 instructions, ending with the
sole RET at 0x7675F6. All 48 direct branch instructions target addresses inside
that extent. Its seven direct calls are two TransformPoseBox calls, one
BoxesOverlap call and four CollisionSide calls. Its sole direct caller is
Scene3::Step at callsite 0x764136 (return address 0x76413B). Nine 0xCC
alignment bytes follow the RET; the next function
starts at 0x767600. The reviewed boundary is therefore [0x766B50, 0x7675F7),
not an assumed range inferred only from a candidate object.

The original operands were also checked against the canonical PE data bytes:
zero at 0x7872F8 is 0.0, the divisor at 0x787328 is 2.0, the left-side limit at
0x787370 is 160.0, and the right-side limit at 0x7895E8 is 479.0. These are
separate from CollisionSide's 20.0 / 619.0 / 280.0 constants. Do not substitute
those character-edge thresholds for the pushbox stage limits.

The resolver first transforms both current-pose boxes and tests their overlap.
On overlap it selects the separation direction from the box-center ordering,
computes an integer edge displacement, and splits that displacement between
the two world X positions. Its subsequent velocity response is asymmetric:
CollisionSide results select different sign-clamping and shared-velocity paths
for the two directions. Four before/after boundary comparisons are explicitly
materialized in separate stack slots. Preserve their order while reconstructing
the natural C++ scopes; their apparent lack of high-level consumers is not a
reason to delete them prematurely.

A full natural C++ candidate now lives in `src/SceneBattlePushboxes.cpp`, with
the four verified stage constants declared in `SceneBattleGlobals.h` and defined
in `SceneBattleGlobals.cpp`. The first probe had a reversed comparison in the
right-separation / secondary-1 `CollisionSide() == -1` path. Reading the actual
x87 FCOMPP operand load order and the following condition-code test shows that
the post-mask comparison is `facing1 * secondVelocity > facing0 * firstVelocity`;
the source candidate now reflects that raw-instruction result rather than the
old reversed expression.

The current candidate materializes the four before/after stage-boundary stores
in their respective separation branches as ordinary `int` locals. A focused
VC7.1 build confirmed that removing `volatile` leaves all 2,727 function bytes
and all 35 relocation records identical to the earlier volatile probe. Thus the
target proves four ordered 32-bit stores, not a source-level `volatile`
qualifier; `/Od` retains these unused locals. The shared four-`bool` approximation
is rejected because it changed store widths and/or stack ownership.

The focused `scene-battle-resolve-pushboxes` match unit is present in
`config/match-units.toml` and binds all 35 external relocations: the four
pushbox globals, two `TransformPoseBox` calls, `BoxesOverlap`, and four
`CollisionSide` calls. The VC7.1 unit build succeeds and records a
source/toolchain/dependency receipt. The current candidate now has the exact
2,727-byte target extent. This is only an extent match: the canonical focused
replay still rejects byte-for-byte comparison, so the function receives no
exactness credit yet.

The 28-byte excess in the previous 2,750-byte candidate was traced to an
incorrect extra facing-times-average assignment in the left-separation /
second-side-negative response. Removing it restored the target extent. A
separate explicit exit in the right-separation fallback reproduces the target's
second five-byte jump to the shared epilogue. These are semantic/control-flow
corrections, not padding.

The remaining mismatch is concentrated in local stack allocation and some
x87 temporary lifetimes. The target saves `this` at EBP-0x60, its two
conditional pose pointers at EBP-0x64/-0x68, and its hidden return buffers at
EBP-0x4c/-0x5c. Its left-branch boundary stores use EBP-0x6c/-0x70 and its
right-branch boundary stores use EBP-0xdc/-0xe0. The current candidate instead
saves `this` at EBP-0x70, places the pose pointers at EBP-0x74/-0x78, the return
buffers at EBP-0x5c/-0x6c, and the left/right boundary pairs at EBP-0x44/-0x40
and EBP-0x4c/-0x48 respectively. Keep using the focused
`scene-battle-resolve-pushboxes` unit; do not run a full cold replay for these
local experiments.

A fresh focused pass on 2026-11-08 independently reconfirmed the two most
important leaves: `TransformPoseBox` is exact at 405/405 bytes (its accepted
relocations include the x87 `__ftol2` conversions and original 0.5 operands),
and `BoxesOverlap` is exact at 128/128 bytes with no relocations. These results
do not confer exactness on the caller.

The first 11 relocation offsets in the current 2,727-byte resolver candidate
match the target. The next target relocation is at function+0x269 (offset 617),
while the candidate places it at 629. Instruction inspection traced this 12-byte
drift to two integer-to-x87 temporary slots: target uses disp8 accesses at
`[ebp-0x7c]` and `[ebp-0x80]`, while the candidate spills them at
`[ebp-0x84]` and `[ebp-0x88]`, forcing longer `mov` and `fild` encodings. A probe
that removes the aggregate's `average` field and inlines the average expression
moves the relocation back to 617, but duplicates the x87 average computation
and expands the function to 2,805 bytes; it is a rejected diagnostic, not a
candidate implementation. Retain the shared average computation and recover its
natural local lifetime/placement instead.

Changing the compiler's `/G5`, `/G7`, `/GB`, `/Gd`, `/Gz` or `/Gr` mode did not
change the current object's 2,727-byte layout or relocation offsets. Simple
reordering of the existing aggregate's declarations, moving its `average` to
another outer-scope declaration, and splitting `displacement` into direction
branches also failed to improve the match. These negative controls narrow the
search; they do not establish that the current local aggregate is the original
source declaration.

A further focused pass on 2026-11-08 tested natural alternatives rather than
assuming the aggregate was correct: independent `SurfaceRect`/velocity locals,
16-byte frame records containing the boundary flags and pose pointers, explicit
pose-pointer locals, function-scope versus branch-scope flags, and removal of
the outer/transform braces. Independent locals move `this` farther down to
EBP-0x74 and the hidden returns to EBP-0x60/-0x70; the frame-record variants
move `this` to EBP-0x78. None preserves the target's return-copy instructions
and stack ownership. A free `__fastcall ResolvePushboxes(Scene3 *)` control
produces the same prologue as the member function, so the current mismatch is
not explained by member-versus-free-function calling convention. Register and
ordinary `char`/ `signed char` facing locals, aggregate padding, and simple
scope-brace removal are also rejected controls.

The scan of 643 locally built objects containing this function found no
candidate with the target's combined prologue, pose-pointer, and hidden-return
buffer offsets. Three direct-initialization probes place the first return
buffer at the target EBP-0x4c, but they change the post-call copy sequence and
grow the function to 2,729 bytes; they are diagnostics, not source candidates.
The target's 12-byte drift at relocation 617 remains independently explained:
two integer-to-x87 spill slots are EBP-0x7c/-0x80 in the target but EBP-0x84/
-0x88 in the candidate, forcing longer `mov` and `fild` encodings. Keep the
average computed once and continue searching for the natural lifetime/layout
that moves those spills without changing the two aggregate-return call sites.

A canonical focused exact-unit replay on 2026-11-08 independently accepted
`scene-battle-transform-pose-box` (405/405 bytes, 11 reviewed relocations,
including eight `__ftol2` calls and three 0.5 operands) and
`scene-battle-boxes-overlap` (128/128 bytes, no relocations). Their receipts are
`.analysis/exact/scene-battle-transform-pose-box.json` and
`.analysis/exact/scene-battle-boxes-overlap.json`; both carry
`acceptance_authority: complete-function-codegen`. This is leaf-only evidence
and does not confer exactness on `ResolvePushboxes`.

One additional natural-layout control put `displacement` first in the local
record. It reproduced the target's displacement/rectangle/double stack slots
(EBP-0x40, -0x3c..-0x20, -0x1c/-0x14, -0x08), but expanded the frame to 0x14c
and moved `this` to EBP-0x74 and the hidden returns to -0x60/-0x70. It is a
useful layout clue, not a viable candidate; keep the accepted source untouched
until the entire call/return layout improves together.

The side-response fallthrough predicates were re-derived from the target's
x87 status-word branches, not from the old source comments. On the left-separation
path, the fallback is `facing1 * secondVelocity >= 0` and
`facing0 * firstVelocity <= 0`; on the right-separation path it is
`facing1 * secondVelocity <= 0` and `facing0 * firstVelocity >= 0`. The source
had strict `< 0` on the two inclusive sides. Changing only those two operators
to `<=` makes the corresponding target `test ah,0x41` / `test ah,0x1` branch
sequences line up. The targeted boss replay still rejects the relocation
inventory: candidate relocation 629 remains target 617, so this is a semantic
correction and a partial codegen improvement, not a completed function.

A fresh source-path rebuild on 2026-11-09 rechecked this conclusion against the
actual target instructions. In the right-separation fallback, target `0x767513`
compares `facing1 * secondVelocity` with zero, then `test ah,0x41; jp 0x7675f3`
exits on greater/unordered; the next comparison at `0x76753d` exits with
`test ah,0x1; jne 0x7675f3` when `facing0 * firstVelocity` is negative. Thus the
fallthrough is exactly `facing1 * secondVelocity <= 0` AND
`facing0 * firstVelocity >= 0`. A probe that reversed these signs to follow a
literal reading of the decompiler lost four more matching bytes (1652 to 1648)
and was reverted. Keep the current source predicate; the x87 status-word
sequence is the authority for this condition.

The saved exact report .analysis/exact/scene-battle-resolve-pushboxes.json is
stale: it describes source 9c1232e2..., object 35deac04..., and 1460/2727
matching bytes. After the 2026-11-09 whitespace-only source cleanup, the current
source SHA-256 is 86987a06a3c9d57bc892d126cb9fc10e377073196849868a0f834a6d4dc9566b.
The current focused build receipt is
.analysis/build/scene-battle-resolve-pushboxes.build.json. A relocation-normalized
diagnostic comparison gives 1652/2727, but the strict
comparator rejects the relocation inventory before full code comparison.
In particular, target relocation function+0x269 (617) is still at candidate
function+0x275 (629). The final strict failure is recorded in
.analysis/build/scene-battle-resolve-pushboxes.strict-final.log. Do not use the
old 1460-byte report as the current baseline, and do not claim acceptance from
the diagnostic rebound score.

A second stack-layout pass on 2026-11-09 inspected 911 built COFF objects that
contain `ResolvePushboxes`; 304 had the exact 2,727-byte extent. No same-size
object in that corpus has the target's combined `this` home and both hidden
return-buffer addresses. The target's first `TransformPoseBox` call uses the
EBP-0x4c hidden buffer and the second uses EBP-0x5c; the current candidate uses
EBP-0x5c and EBP-0x6c. The target saves `this` at EBP-0x60 and its conditional
pose pointers at EBP-0x64/-0x68, whereas the candidate saves `this` at
EBP-0x70 and the pointers at EBP-0x74/-0x78. The target's left boundary result
stores are at EBP-0x6c/-0x70 (right results at EBP-0xdc/-0xe0); the current
branch locals are at EBP-0x44/-0x40 and EBP-0x4c/-0x48. The common displacement
(-0x3c), rectangle locals (-0x38..-0x1c), and three double locals
(-0x18/-0x10/-0x08) already agree. This makes local lifetime/slot ownership,
not aggregate size, the remaining prologue and spill-layout problem.

The target's first facing-to-x87 integer spill is EBP-0x74, followed by the
EBP-0x7c/-0x80 pair that explains the target relocation at function+0x269
(offset 617). The candidate's corresponding first spill starts at EBP-0x7c and
its later pair is EBP-0x84/-0x88, producing the 12-byte relocation drift to
offset 629. Reversing the rectangle members while remapping logical player
references scored only 1615/2727; grouping boundary flags into a local struct
left the 1652/2727 score unchanged, while explicit pointer/flag scratch records
expanded the function to 2754 bytes. Four function-scope flag locals scored
1586/2727. These are retained negative controls, not accepted source changes.

### Complete dispatch and body-contact test

DispatchCollisions first tests both character directions with TestBodyInteraction
and clears field144 for both. Its 64-slot local-effect rings retain their signed
read/write indices, explicit wrap and active checks. Pass order is effect clash,
bidirectional effect-pair handling, player-1 effects against player 0, player-0
effects against player 1, then body hit processing in both directions. The last
calls are suppressed by the opposite initial contact-test result, preserving
which direction owns each result. All eleven direct calls bind explicitly to
0x7679B0, 0x76BAB0, 0x76B090, 0x7697D0, 0x76BD40 and 0x767F60. No unimplemented
callee receives credit through those calls.

TestBodyInteraction copies the two actual SecondaryFrames, transforms four attack
boxes and five defense boxes, and transforms the defender's special box. It
retains the original state/flag tests, the accepted AirActionReady call at
0x4102E0 and GuardInput call at 0x4100F0. The latter can consume random input and
alter CPU guard direction, so this owner is not a pure geometric predicate.
The ordinary branch builds a 4x5 overlap matrix. Attack flag 40 instead marks
only column zero and tests the special box. Other matrix cells are not initialized
by that path in the original; the subsequent intersection loop is preserved and
no clearing or failure behavior is added. Its starting rectangle is the genuine
MakeSurfaceRect(-10000,-10000,20000,20000) result. Return 1 requires the remaining
defender state, >=30 timer, guard input and attack-flag tests; otherwise return 0.

The source groups real per-pass snapshots, indices/results, frame copies, box
arrays and intersection state in local C++ work records. Every field is used;
these records are never passed as invented call ABI objects. Natural scopes
preserve the standalone loop index and special rectangle, including VC7.1's
actual aggregate/temporary alignment. Complete comparisons were retained after
every local-layout change. No explicit padding member, naked code, assembly,
original byte array, compare-size override or relocation mask is present. One
draft text edit accidentally qualified a local member declaration; it was fixed
and the required compiler/Wine execution check passed before final acceptance.

### Focused acceptance and next work

Scene3 and its genuine collision snapshot now live in src/SceneBattle.h, included
by Startup.cpp, SceneBattle.cpp and SceneCollision.cpp. Engine.h retains only the
Scene3 forward declaration. The nine existing Startup/battle unit recipes track
the new header precisely. Future changes confined to this battle declaration can
therefore select its actual consumer units rather than all Engine.h consumers.
This one-time shared-header change still receives complete affected comparison.

Five new and 179 Engine.h-dependent existing units compare strict exact from
47 serial cold source/profile/dependency artifacts. All 135 existing compiler-local
destination/offset bindings are checked before receipt finalization. Uninvolved
standalone Input, reader and configuration units remain outside this replay.
Focused ledger/progress and whitespace checks pass; no full CI, runtime matrix or
unrequested full cohort ran. New source is src/SceneCollision.cpp and public proof
is docs/evidence/scene-collision-exact.json, with affected certificates refreshed.
Private evidence and native attempts are retained in .analysis/probes/scene-collision/;
the 184-unit full formal report is preserved inside
.analysis/cleanup/2026-11-07/retired-trials-and-reports.tar.gz as
.analysis/exact/scene-collision-and-affected.json. This is a historical
acceptance snapshot, not a current dependency-freshness claim:
a later src/Engine.h change left 296 exact-unit certificates with stale
dependency hashes. Current tracking validation fails until affected units are
selectively replayed; see docs/RE_HANDOFF.md. Do not treat the old replay counts
as current fresh proof.

The old note below this point claiming that `ResolvePushboxes` had no source
owner or match-unit recipe is stale and superseded by the current state above:
`src/SceneBattlePushboxes.cpp` defines the member and
`config/match-units.toml` contains `scene-battle-resolve-pushboxes`. The source
builds to the correct 2,727-byte extent, but strict byte comparison still fails;
there is deliberately no exact-match receipt or exactness credit for the boss
function yet.

The target's `TransformPoseBox` call at `0x767600` uses ECX=`this`, stack `+8`
for the output `SurfaceRect *`, `+0xC` for the `SecondaryPose *`, and `+0x10`
for the source box pointer; it returns the output pointer in EAX and uses `RET
0xC`. Preserve this explicit caller contract when experimenting with natural
C++ aggregate-return declarations. `BoxesOverlap` at `0x767930` is an accepted
128-byte leaf with no relocations. `Secondary::CollisionSide` at `0x40FF70` is
also independently exact: all 222 bytes outside its six DIR32 fields match,
and all six relocation offsets/symbols are reviewed.

Raw target instructions, rather than the provisional Ghidra pseudocode, establish
these control-flow facts:

- The first horizontal correction is selected by
  `(first.left + first.right) - (second.left + second.right) > 0`; the opposite
  branch is `<= 0`. The target emits `sub; test; jle` at `0x766CAA..0x766CAE`.
- The four `CollisionSide()` tests are fighter 0 `-1`, fighter 1 `+1` in the
  first branch, then fighter 0 `+1`, fighter 1 `-1` in the opposite branch.
  Each branch masks both velocity locals before comparing them.
- Four additional x87 comparisons materialize boundary results even though the
  results are never read later in this function. First-fighter X is `<= 160.0`
  before and `> 160.0` after the first correction; second-fighter X is `>= 479.0`
  before and `< 479.0` after the opposite correction. The target stores four
  32-bit values at `[ebp-0x6c]`, `[ebp-0x70]`, `[ebp-0xdc]`, and `[ebp-0xe0]`.
  The x87 status tests are respectively `test ah,0x41; jp`,
  `test ah,0x41; jne`, `test ah,0x1; jne`, and `test ah,0x5; jp`.

Natural C++ probes have progressed beyond the old 150/174 inventory. The
important current controls are:

| Probe | `.text` | Frame | Instructions | Result |
| --- | ---: | ---: | ---: | --- |
| 150 | 2,725 | `0x148` | 708 | Full target mnemonic histogram; 35 relocations; stack ownership differs |
| 174 | 2,729 | `0x148` | 708 | Full target mnemonic histogram; 35 relocations; stack ownership differs |
| 259 | 2,535 | `0x140` | 708 | 276 `mov`, 16 `jmp`, 8 `jp`; velocity and rectangle result slots align better, but four boundary comparisons are absent |
| 276 | 2,711 | `0x148` | 708 | Full target mnemonic histogram; one reused volatile Boolean creates byte stores at the wrong slots |
| 277 | 2,726 | `0x150` | 708 | Full target mnemonic histogram; 35 relocations; four distinct volatile Booleans, but byte-store widths/stack slots and frame differ |

Probe 277 is a historical instruction-inventory control, not the current best
implementation. It is one byte shorter than the target and matches the complete
708-instruction mnemonic histogram, but it is not byte-exact: its frame is eight
bytes larger (0x150 vs 0x148), this is at [ebp-0x78] rather than [ebp-0x60],
and its four volatile bool stores are bytes at [ebp-0x79], [ebp-0x7a],
[ebp-0xe5] and [ebp-0xe6], unlike the target's four 32-bit stores. The
pose-pointer and output-temporary slots also differ. Probe 276 has the target
frame size but reuses one volatile Boolean and is 16 bytes short. Probe 259 is a
useful local-lifetime control: its initial velocity stores and rectangle-result
slots match the target more closely, but its frame/this/pose slots differ and
it omits the four boundary comparisons. The current source owner in
src/SceneBattlePushboxes.cpp is 2,727 bytes and has the best current diagnostic
result (1652/2727), but it remains non-exact.

The `WorkScratch` union in probes 276/277 aliases only the horizontal
`displacement` and the later `facing` byte; their live ranges do not overlap.
This is distinct from the withdrawn 2,898-byte `PushboxScratch::work` attempt,
which overwrote a still-live displacement with a boundary Boolean before both
position updates consumed it. That earlier attempt is semantically wrong and
must not be revived.

The next useful experiment is to recover the target's different lifetimes for
the left/right boundary results, pose pointers, and the two hidden SurfaceRect
return buffers. Simple declaration-order permutations and aggregate-versus-
independent locals are now negative controls. Focus on the target EBP-0x7c/
-0x80 x87 spill slots that explain relocation 617 while keeping the average
computed once and preserving both return-copy sequences. A further 2026-11-09
pass tested frame records, explicit pose-pointer lifetimes, local aggregate
order, function/branch scopes, flag declaration order and /O1-/O2 profiles;
none improved the current 1652/2727 diagnostic result. Compare the complete
function and every relocation after each focused build. Do not infer exactness
from size or histogram. The retired source variants and logs are in the
2026-11-09 archives documented in RE_ARTIFACTS.md; the 13 selected controls
listed above remain live.

The large battle-collision owners `ResolveBodyHit` (0x767F60),
`ResolveEffectHit` (0x7697D0), `ResolveEffectPair` (0x76B090),
`ResolveEffectClash` (0x76BAB0), and `ResolveBodyEffect` (0x76BD40) have since
been independently rebuilt and matched against their canonical target bytes
with reviewed relocation fields. `Scene3::Step`, round update/exit, replay reset,
intro update and battle input/control owners have also been accepted. Check the
current ledgers and `RE_HANDOFF.md` rather than treating this older open-work list
as current. The five Video pixel owners at 0x409A90, 0x40A0B0, 0x40A440,
0x40A7B0 and 0x40AAE0 now have natural C++ semantic owners in
src/VideoCharacterDraw.cpp; all five remain open for strict exact codegen.

This checkpoint adds **5 complete functions /4,113 instruction bytes**, for
**201 authored functions /173,003 instruction bytes**, plus unchanged 667 local-table
bytes. Reviewed boundaries/origins are 239 each. Complete game, linked resources,
original/reconstructed runtime and portability remain independently open phases.

## Battle body-hit resolution

Scene3::ResolveBodyHit at **0x767F60 /6,245 instruction bytes** is now complete
strict exact. It is the full character-versus-character hit owner called by the
accepted collision dispatcher, including all original special-defense, counter,
guard, chip, normal-hit, animation, freeze, combo and effect outcomes. Its entry
has the real Scene3 ECX receiver and four stack arguments: two complete Secondary
pointers and two genuine BattleCollisionSnapshot pointers, ending RET 10. The
exclusive end is 0x7697C5; eleven CC bytes precede the still-open effect-hit owner
at 0x7697D0. No associated local table belongs to this contribution.

The independently reviewed boundary contains **1,373 instructions, 124 direct
branches, 39 direct calls and six virtual slot-zero calls**. Every direct branch
lands on an instruction in the full body. Each virtual call uses the complete
defender Secondary receiver and the established ResetPose slot. All **59 relocation
fields** bind explicitly: 39 direct callees and 20 floating-data operands. The
original operand, symbol/destination and four/eight-byte IEEE payload are checked
independently for every floating binding. No address mask or prefix comparison
is used. Existing guard, facing, history, factors, scoring and effect functions
remain independent accepted dependencies; direct calls confer no linked-product
or runtime closure.

### Collision preparation and outcome order

The owner retains real 200-byte attacker/defender frame copies, the original
4x5 collision matrix, four attack boxes, five defense boxes and the special
box transform. An actual EffectSpawn is constructed after the frame copies and
before box transforms. The snapshot state BYTE at E9 and command WORD at EA
control eligibility here; the earlier TestBodyInteraction instead reads live
Secondary fields. Preserve that distinction and the original partially initialized
matrix path for attack flag 40. Intersection construction/updates are retained
and supply the hit-effect coordinates.

The full positive outcome chain follows original instruction order, which differs
from the decompiler's deeply nested negative form: defense flags 1000/800 with
matching attack direction and no attack flag 100; counter-ready guard; airborne
guard; grounded guard excluding animations 168/169; the three defense-200
attack-direction cases; ordinary guard; then normal hit or the original tint-only
state outcome. Numerical flag names and unimplemented consumers remain provisional.
Consecutive state168 writes 2 then 6 are actual target stores and remain present.
No extra state validation, clearing, bounds checks or failure behavior is added.

Guard/chip branches retain the original freeze words, effect emission, history
clears and minimum defender health of one. Normal guard preserves integer
`(damage / 30)` before conversion to float; its angle accumulation caps at the
actual 360.0f payload. The alternate angle-consumption path and field154 reset
are complete. Secondary field154 is a genuine observed 32-bit zero store, exposed
with a provisional int view in the previously unknown four-byte region; all later
fields and object extents remain unchanged.

Normal-hit animation selection first handles nonnegative Y, then the airborne
case. The explicit ground/air command shorts, fallback animation 59 and original
flag-derived animation arithmetic are retained. Counter/guard animation selection
uses `168 + (inputY == 1)` where the target does. The mathematically equivalent
`169 - (inputY != 1)` produces different VC7.1 /Od Boolean materialization and
changes subsequent GPR selection, so it is not substituted. Signed command-word
decrements and combo-word increments use natural --/++; field148 additions use
compound assignment to preserve the original right-hand-value/member evaluation
and word-result stores. These are real state operations, not inert codegen padding.

### Original x87 damage and combo expressions

The decompiler omitted two live x87 conversion arguments and incorrectly narrowed
an existing double in another expression. The complete original instructions
establish these source operations, including their evaluation order:

- Defender health decreases by integer conversion of frame damage * attacker
  DamageFactor() * defender HealthFactor() * attacker ComboFactor(). The three
  accepted member calls and intermediate double spills remain in that order.
- Defender field124 receives the signed-word conversion of frame fieldB2 *
  (attacker field178 /10000.0 *0.8). The 0.8 operand is its exact canonical
  eight-byte payload, not a guessed scaling factor.
- Frame float fieldA4 is divided by **1000.0f**, then multiplied by the existing
  **double** attacker field178. There is no intermediate conversion of that
  member to float. The operation repeats if the resulting double exceeds 10000.
- Defense flag 10 clears the combo word, subtracts the exact **20.0** payload
  when field178 is above 10000, and otherwise stores 10000. Preserve original
  ordered comparisons and branch directions.

The owner also preserves prior-health capture, flag-derived field144, field128/
12C, three byte clears, combo counters/scores, hit-stop words, command consumption,
midpoint hit-effect emission and the original KO pose/facing path. The complete
native comparison includes all of them rather than crediting an initial collision
or damage prefix.

### Character tint helper and native acceptance

Secondary::SetCharacterTint at **0x410AC0 /75 bytes** is independently complete
exact. It stores the byte at 30B8 and duration at 30BC, halving duration with signed
integer division when Context setting136C is zero. Its unsigned-byte argument view
reproduces the actual positive 0xDF caller push and byte store. It is distinct from
the accepted SetTint at 0x410B10, which writes 30C0/30C4 and Context F33.
The helper has 24 instructions, one direct branch, no relocations and RET 08;
five CC bytes precede the next accepted helper.

The first complete natural C++ body was built early at 6,250 bytes. Four successful
complete cold source/object trials, including the final readable else-if cleanup,
have retained full comparisons. Ordinary scopes and local work records preserve
the actual 3B4-byte body frame and genuine descriptor/frame ownership without
padding members, assembly or fabricated call ABI objects. One draft source-parser
edit misread a C++ member arrow as a relational operator; it was corrected and
the required pinned compiler/Wine --execute check passed before further comparison.

Final source is src/SceneBodyHit.cpp. The two new and 184 Engine.h-dependent
existing units compare strict exact from **48 serial cold source/profile/dependency
artifacts**, with all 135 existing compiler-local destination/offset bindings
checked before final receipts. Uninvolved standalone Input, reader and Config
units are omitted. Public proof is docs/evidence/body-hit-exact.json and affected
certificates are refreshed. Private complete bodies, typed-source derivation,
constant/operand reviews and attempts are retained in .analysis/probes/body-hit/;
full final reports are .analysis/exact/body-hit-and-affected.json. Only focused
ledger/progress and whitespace checks ran; no full CI or runtime matrix ran.

The checkpoint adds **2 complete authored functions /6,320 instruction bytes**,
bringing acceptance to **203 functions /179,323 instruction bytes**, plus unchanged
667 local-table bytes. Reviewed boundaries/origins are 241 each. At this body-hit
checkpoint, ResolveEffectHit 0x7697D0 /6334 and the remaining effect/body collision
owners were still open (subsequently recovered below), as were
the battle update/draw/keyboard entries and independently tracked product/runtime/
portability phases. The accepted body-hit owner does not complete battle or game
reconstruction.

## Battle effect collision resolution

Canonical target: `resources/EFZ.exe`, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Four complete Scene3 members are accepted from src/SceneEffectCollision.cpp under
explicit profile vc71-od-static and pinned VC7.1 RTM 13.10.3077:

| Member | Entry | Instruction bytes | Instructions | Direct branches | Direct calls | Slot-zero calls | Relocations |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| ResolveEffectHit | 0x7697D0 | 6,334 | 1,460 | 120 | 34 | 6 | 54 |
| ResolveEffectPair | 0x76B090 | 2,578 | 628 | 58 | 15 | 2 | 25 |
| ResolveEffectClash | 0x76BAB0 | 650 | 175 | 14 | 3 | 0 | 3 |
| ResolveBodyEffect | 0x76BD40 | 2,466 | 603 | 58 | 15 | 2 | 25 |

All **12,028 instruction bytes** compare strict exact through their original
RET 10/10/10/14 instructions and exclusive ends 0x76B08E, 0x76BAA2, 0x76BD3A
and 0x76C6E2. Following CC runs are respectively 2, 14, 6 and 14 bytes;
none belongs to the credited contribution. Original instructions are contiguous,
all 250 direct branch destinations are instruction starts inside their respective
complete contributions, and there are no indirect jumps or local tables.
All 107 relocation fields retain explicit reviewed symbols and canonical targets:
67 direct calls and 40 exact IEEE operands. The ten indirect calls are reviewed
Secondary defender slot-zero ResetPose calls with the real receiver, not fabricated
Ghidra register parameters. Compiler __ftol2 remains an explicit dependency without
new authored-function credit. Complete exact codegen does not establish runtime,
linked-data, original TU partitioning or whole-game closure.

### Effect hit eligibility and distinct outcomes

ResolveEffectHit uses a live SecondaryEffectSlot at Secondary+4D0+index*98,
its live 200-byte sequence frame, and the genuine defender collision snapshot.
Eligibility reads slot DWORD80 and signed WORD84, snapshot defense B0 flag20,
attack AA flag40 against live defender130, AirActionReady and live defender13C.
Unlike ResolveBodyHit, it does not copy both frames or construct EffectSpawn
before transforms: the descriptor is constructed only after nonzero collision.
The four attack boxes use TransformPoseBox with the full effect-slot pointer;
the five defense boxes and special90 box use TransformSnapshotBox.

The effect-slot cast is a reviewed source view of the actual common pose prefix:
type0, frame2, patterns8, X18/Y20 and signed facing BYTE48 are exactly the
positions read by TransformPoseBox. It does not claim original inheritance or
adjust the slot pointer by Secondary's eight-byte pose-base displacement. The
real slot has additional independent fields including integer facing4C.
The AA40 special path sets only matrix column zero before accumulating overlaps;
the target's remaining uninitialized cells and later reads are preserved.

The full positive outcome chain includes defense B0 flag400 with absent attack
AA100, special guards/counters, the three defense200 direction cases, ordinary
guard/chip, angle consumption and normal damage with alternate pose/tint
decisions. Original
slot states 2, 3 and 7, signed consumption/freeze words, history clears, minimum
chip health one, special live-attacker state168 writes, combo/score, descriptor
emission and KO are all included. Most ResetPose calls set defender facing to
**negative effect-slot BYTE48** instead of calling FaceOpponent; the KO path
still calls FaceOpponent. Its tint-only call is SetCharacterTint(E9,3), distinct
from BodyHit and the other effect-transfer paths using DF,2. Ordinary guard and
normal hit write defender D0=0, unlike the delegated-hit paths below.

Original x87 code supplies damage from frame A0 * attacker DamageFactor() *
defender HealthFactor() * attacker ComboFactor(), in that exact call/spill order.
The signed-word stun expression is frame B2 * (attacker178 /10000.0) *
(1 + ((attack AA2000 && defense B02000) ? 1 : 0)). Both masks are compared with
zero as in the original. This owner has **no 0.8 factor** in stun. The factor's
Boolean is materialized before signed B2 conversion, matching the actual frame.
Float A4 /1000.0f then multiplies the existing double attacker178 without an
intermediate float narrowing, and repeats above 10000. Defense flag10 subtracts
exact double20.0 above 10000 or stores 10000. These live x87 inputs were missing
or incorrectly narrowed in the provisional decompiler text.

### Effect pair, strength clash and body-to-effect ownership

ResolveEffectPair tests the first slot's state/remaining count and absent AA40,
then transforms its four attack boxes against five boxes of the second slot.
On overlap, absent second-frame B010 consumes the first slot and writes state5;
the second slot always receives state5. With second-frame B02000, the original
copies the defender character's current 200-byte frame **into the live second
effect sequence frame**, then uses that overwritten frame for flags. This is a
real target write to shared frame data; it is not a local snapshot substitution.
The delegated outcome may select/reset/face the character or tint DF,2, and
continues through real character damage, combo, hit-stop and KO. Stun uses
frame B2 * (attacker178 /10000.0 *0.8). D0 is one. The EffectSpawn constructor and
single midpoint descriptor emission occur after this optional character damage.

ResolveBodyEffect instead receives two genuine collision snapshots plus one
second-player slot index. Eligibility uses live attacker168/16C and the first
snapshot's AA40. It copies the second effect's frame into an ordinary local
SecondaryFrame before box testing. Four attack boxes use the first snapshot;
five defense boxes use the live slot's pose prefix with the local frame. Its
B02000 path replaces **only that local frame** with the second snapshot's frame,
then follows the corresponding delegated character damage/tint/KO operations.
The initial B010 test consumes live attacker16C/state168 rather than a first
effect slot. Full copy instructions, tests before/after replacement and the late
EffectSpawn construction are exact; the local and shared-frame owners are not
conflated.

ResolveEffectClash requires both live slots state zero, positive remaining counts
and positive signed sequence field0000 values. After special90 boxes overlap,
equal sequence values set both states to4; otherwise only the weaker side becomes4.
Each slot loses one remaining count only if the *opposite* sequence value exceeds
one. The meaning of numeric sequence field0000 remains provisional beyond these
observed comparisons.

### Focused native acceptance

The first complete EffectHit source was compiled at 6,311 bytes and its whole
comparison retained; real value scopes and branch/word expressions resolved the
remaining codegen. The first complete Pair source differed in two signed versus
equality condition jumps; original instructions determine the final != tests.
Clash and BodyEffect were complete exact on their first source builds. All work
records contain used pointers, indices, matrices, rectangles or real frame values;
there are no byte wrappers, assembly, padding fields or fake ABI declarations.
Readable else-if cleanup also received complete native comparisons.

The final public source, including its last formatting edits and actual filename,
received **one serial cold source/profile/dependency artifact** and four complete
manifest-bound comparisons, each with zero differences. Shared headers and all
previous source files are unchanged, so no unrelated unit replay was needed.
Proof is docs/evidence/effect-collision-exact.json; original full instructions,
decompiles, all source/object attempts, complete comparisons, independent constant/
call/branch/boundary reviews and final reports remain in
.analysis/probes/effect-hit/, .analysis/probes/scene-collision/ and
.analysis/exact/effect-collision.json. Only focused ledger/progress and whitespace
checks accompany the checkpoint; no full CI, full cold cohort or runtime matrix.

This checkpoint adds **4 authored complete exact functions /12,028 instruction
bytes**, bringing authored acceptance to **207 functions /191,351 instruction
bytes**, plus unchanged 667 local-table bytes. Reviewed boundaries and origins
are 245 each. At the effect-collision checkpoint, battle Step/render/keyboard and the parked
pushbox owner were still open; Step/render and further control are recovered
below. Product/runtime/portability closure and the whole game remain open.

## Battle main loop, rendering and round control

Canonical target: resources/EFZ.exe, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Six complete authored Scene3 members are accepted from src/SceneBattleLoop.cpp
under the explicit vc71-od-static profile and pinned VC7.1 RTM 13.10.3077:

| Member | Entry | Bytes | Exclusive end | Instructions | Direct branches | Direct calls | Virtual calls | Relocations |
| --- | --- | ---: | --- | ---: | ---: | ---: | ---: | ---: |
| Step | 0x763C20 | 1,653 | 0x764295 | 448 | 41 | 32 | 10 | 34 |
| UpdateRound | 0x765040 | 1,562 | 0x76565A | 396 | 29 | 5 | 6 | 11 |
| UpdateRoundExit | 0x765FA0 | 205 | 0x76606D | 58 | 3 | 4 | 0 | 10 |
| Slot0 / battle render | 0x7642A0 | 1,285 | 0x7647A5 | 397 | 19 | 34 | 3 | 34 |
| ClipFrame | 0x7631F0 | 431 | 0x76339F | 136 | 6 | 8 | 0 | 8 |
| RenderBackground | 0x75DD50 | 1,249 | 0x75E231 | 369 | 26 | 10 | 1 | 14 |

All **6,385 instruction bytes** compare complete strict exact. Every original
instruction, all 124 direct branch destinations, 20 virtual calls and 111
explicit relocation fields are reviewed. The relocations comprise 93 direct
calls, two named timeGetTime import operands and 16 independently checked IEEE
operands. The full bodies have no local tables or indirect jumps. All end in
RET, followed respectively by 11, 6, 3, 11, 1 and 15 CC bytes outside credited
extents. Scene3's constructor-established table at 7895DC independently identifies
the render/Step/PollKeyboard entries. PollKeyboard was open at this checkpoint
and is accepted in the later keyboard/replay-control section.

### Main frame sequencing and cleanup

Step performs the original unsigned elapsed-time comparison against 1000,
refreshes the sampled frame count and increments the live frame count. Entry
phase 1 captures the two externally owned Secondary pointers, initializes camera/
simulation fields, updates the camera, invokes the scene's actual render slot,
fades in the shared character palette and clears entry phase. Keyboard polling
uses scene vtable offset 8. Pause field588 returns scene ID 3 immediately, before
simulation, effect updates and the background object's update.

Exit flag 1 fades out, deletes both character pointers and clears their external
slots, deletes/clears the Context137C allocation when present and resets scene
phase. This is real C++ deletion: Secondary deletion uses the accepted scalar
deleting helper at 401920; Context137C cleanup calls operator delete at 777E20.
The decompiler's _free label and apparent extra character null guards are not
copied. The guards around Secondary deletion are compiler-generated parts of
the delete expression. Replay close/music release and the mode 6/normal scene
returns retain their original positive branch order. Final-round exit uses the
separate integer-returning UpdateRoundExit; replay cleanup occurs before deleting
characters, and normal round completion returns scene ID 5.

The live byte578 controls simulation iterations, with the original unsigned byte
promotion. Each iteration updates both inputs, intro, shared state dispatch,
then virtual Slot08, Slot06 and Slot07 for both characters. Conditional collision
dispatch precedes the still-open pushbox callee, movement, signed freeze-word
clamp/decrement, timers, character/effect sounds and round outcome. Palette fade,
frame controls, camera and conditional drawing follow the loop. Drawing retains
the original setting136C/framePhase tests; Context effects and the background
object update run afterward. Virtual call receivers are real Scene3, Secondary
or the object stored at Context137C, with no inferred register parameters added.

### Round outcomes and fade

UpdateRound returns early for nonzero custom-health field574 or mode 1. While
counter1354 is nonzero, it clears all eight player button-pulse bytes and waits
for both characters' state predicates and absence of exit flag 2, then restores
health 9999 and requests intro state 2. This nonzero-counter path physically
precedes the new-outcome path in the original code.

With counter zero, a genuine EffectSpawn is constructed before testing health.
Simultaneous KO increments both signed win bytes, clamps each below the signed
round-limit byte, resets both characters to state 59 and advances the event
selector. A single KO adds the winner's remaining health to field 30DC. A further
round increments wins, adds 180 to both freeze words, resets the loser and emits
the exact round descriptor at X 80 or 240, Y 100. Preserve the different original
reset/emission order for the two player directions. Match completion instead
sets exit flag 2, zeroes double580 and stores the winning player byte at
Context134C. Other pending outcome/control states retain their complete early
returns, state predicates and intro request.

UpdateRoundExit is an **int** result, tested in full EAX by Step; Ghidra's bool
candidate is not the caller contract. Before double580 reaches 100 it lightens
the actual palette with integer conversion of 100-T and changes music volume by
integer conversion of -T*100/2 plus currentVolume. It then increments T by exact
double 1.0 and returns 1 at T>=200, otherwise 0. The explicit returns preserve the
original branch/result sequence without introducing a stored Boolean temporary.

### Rendering, disabled diagnostics and background composition

Slot0 advances both trails, draws background/health bars and the sprite-shadow
prepass, then Context
and player local effects in their original layer order. Character render order
switches at player two's state 200. Each character's X offset includes the
accepted IsStateGroupB result times signed freeze-word remainder2 times2;
original signed remainder behavior is retained. The background object can draw
a foreground layer only with both character tint durations zero and Context
state14278 zero. Player Slot01 calls, the then-open HUD and combo helpers,
snapshot capture and final ClipFrame retain their complete order.

The original capture branch writes a screenshot every even signed frame index,
using index/2 and the shared palette, then increments the index. The reviewed
Video callee at 40C1C0 writes snap/sn bitmap files; the member declaration is
SaveScreenshot(int,const unsigned char*), and its implementation remains open.
The decompiler removed **eight disabled diagnostic DrawNumber calls** at
76469B..764798. The original /Od contribution retains an actual constant-false
branch and the full player health/type/frame/tick diagnostics. Natural
`if (false)` C++ reproduces that branch and all dormant calls exactly; they are
not omitted, copied as bytes, or replaced with padding. DrawNumber's six stack
arguments are two int coordinates, unsigned number, two formatting bytes and
an int blending mode, independently reviewed against its full callee.

RenderBackground reads the actual double at Context14258. Its X/Y calculations
are integer truncation of -cameraX*scale+(160-160*scale) and
(240-cameraY)*scale+(120-120*scale). Preserve both live x87 inputs and repeated
reads, followed by the real coordinate clamps, offsets and two rectangle
assignments. With two active tint durations it uses ContextF33 to select color,
then decrements both durations only when both freeze words are zero. With one
active tint it fills that side's color and conditionally decrements that side.
Otherwise it draws extraB and conditionally decrements state14278, or draws
extraA and the background object's layer 0. All original rectangles, argument
order, repeated freeze tests and branch directions compare exact.

ClipFrame clamps camera-derived coordinates and computes the original signed
edge offsets. It uses three CRT abs calls and two genuine MakeSurfaceRect
returns to fill horizontal/vertical out-of-view areas with color zero, then calls
Video::Present. FillRectangle at 40B300 has a genuine SurfaceRect value argument,
byte color and int result; its full original callee uses back-surface Lock/Unlock
and RET 14. Its implementation remains open. The rectangles and all intermediate
return copies are part of the complete native comparison.

### Layout views, dependencies and focused acceptance

Engine.h exposes the observed existing byte 134C as winner134c and existing
8-byte storage 14258 as double backgroundScale. The Context extent and subsequent
offsets remain unchanged. It adds the two observed nonvirtual Video declarations.
SceneBattle.h adds the reviewed Scene3 helper contracts. Numerical names and
helper names remain provisional; no unimplemented callee receives new function
credit merely because a caller is accepted. The provisional RenderMeters label
at762C50 was a misnomer. The later accepted RenderShadows implementation draws
compressed player/effect sprite shadows around the Y210 plane. The B0 argument
is a fixed palette color index used by the callee blend lookup, not an alpha
value. HUD760060 owns the meter/status bars; its later implementation is exact.

The private Background interface in SceneBattleLoop.cpp is the reviewed two-slot
source view of Context137C: update at slot 0 with no arguments, render at slot 4
with two camera ints and a layer byte. Original object storage remains separately
owned; no inheritance, original class name, destructor slot or concrete
implementation is claimed. This view introduces no receiver adjustment, wrapper
calls or extra stores. Complete codegen does not prove original TU partitioning,
linked data, downstream implementations or runtime closure.

The first complete Step draft was built at 1693 bytes; removing duplicated
source-level deletion guards and matching original result/early-return branches
resolved it. Round/exit also received early complete builds and full retained
comparisons. Render, ClipFrame and RenderBackground matched their first complete
source compilations. Initial private header access/declaration errors and their
inputs/logs are retained; pinned toolchain --execute smoke checks passed before
subsequent final comparisons. All native builds are bounded, serial, CPU1/nice10
and use EFZ's own Wine state. Work records contain only used real values.

The final six new and 190 actual Engine.h-dependent existing units compare strict
exact from **50 serial cold source/profile/dependency artifacts**, retaining every
original compiler-local destination/offset binding. The standalone Input, reader
and configuration cohorts are uninvolved. Final public proof is
docs/evidence/battle-loop-exact.json; private full reports are
.analysis/exact/battle-loop-and-affected.json. Full canonical instructions,
decompiles, source/object attempts and independent branch/call/constant/boundary
reviews remain in .analysis/probes/battle-loop/. Only selected new/affected native
units and focused ledger/progress/whitespace checks run, without full CI,
a full cold cohort or redundant runtime matrices.

This checkpoint adds **6 authored complete exact functions /6,385 instruction
bytes**, bringing acceptance to **213 functions /197,736 instruction bytes**
plus unchanged 667 local-table bytes. Reviewed boundaries and origins are 251 each.
At this loop checkpoint, battle keyboard and health/HUD/shadow/combo/number
drawing were open; those are accepted in the following sections. Screenshot/fill,
concrete background implementations and parked pushbox remain open, as do the
whole game and independent product/runtime/portability phases.

## Battle health, HUD and combo display

Canonical target: resources/EFZ.exe, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Three complete authored Scene3 display members are accepted from
src/SceneBattleDisplay.cpp under explicit profile vc71-od-static and pinned
VC7.1 RTM 13.10.3077:

| Member | Entry | Instruction bytes | Exclusive end | Instructions | Direct branches | Direct calls | Relocations |
| --- | --- | ---: | --- | ---: | ---: | ---: | ---: |
| RenderHealthBars | 0x75E240 | 7,707 | 0x76005B | 2,054 | 31 | 64 | 72 |
| RenderHud | 0x760060 | 9,032 | 0x7623A8 | 2,382 | 58 | 87 | 115 |
| RenderCombo | 0x7623B0 | 2,205 | 0x762C4D | 654 | 15 | 30 | 32 |

All **18,944 instruction bytes** compare complete strict exact. All 104 direct
branch destinations are reviewed instruction starts inside the complete bodies.
There are no indirect jumps, virtual calls or associated local tables. Original
RET /RET /RET04 exits and following CC runs of 5/8/3 bytes establish complete
extents; the CC bytes receive no progress credit. All 219 relocation fields have
explicit reviewed symbols, original destinations and operand evidence: 181 direct
calls plus 38 independently checked exact IEEE operands. Source width, local
scope, float/int evaluation and full original branch order are included in the
comparison. Callee declarations and codegen do not prove callee implementation,
original TU partitioning, linked data or runtime closure.

### Health tracking and top display

RenderHealthBars first updates both players' live display-health fields, even
when the later positive Context1420C flag suppresses drawing. Field110 moves
toward actual health108 in increments/decrements of200 with overshoot correction.
Field10C decreases by100 only when above actual health and the *opposite* player's
combo WORD174 is zero, then is clamped upward to actual health. Preserve both
players' update order, original repeated reads and real signed comparisons.
Natural compound subtraction matches the original Boolean-scaled decay; adding
a negative product changes VC7.1 register selection and instructions.

The complete display then composes player pattern48 and45 frames, using their
actual texture index and signed width/height with the existing Secondary pose/
PatternSequence layouts. Every repeated frame access, MakeSurfaceRect return,
rectangle assignment, player mirroring flag and color key is retained. Both
players' bar widths use signed integer conversion of the relevant field10C or110
multiplied by exact double120.0 and divided by exact double9999.0. The four live
x87 arguments were absent from provisional decompiler output.

Prior-health bars draw only at positive width. Smoothed bars use a fixed region
at width>=40, otherwise a positive-width low-health region animated by
(field30F0%36)/18. The original right-player low-health **source height is8**,
while its destination height is6; this asymmetry is retained and exact. Round
limit and per-player wins are read with the original signed-byte interpretation,
and the three threshold tests use >=1, >=2, >=3 as encoded. The owner ends with
the sampled frame counter's DrawNumber call. No extra clamps, validation or
resource substitutions are introduced.

### Bottom status and world-space overlays

RenderHud returns immediately for positive Context1420C. It draws the complete
bottom texture strip and both signed WORD148 meter values. Width is the original
integer expression value*108/3000. The four value tiers (<1000, <2000, <3000,
otherwise) select the original icons and source regions, including the five-frame
(field30F0%90)/18 animation. Source/destination coordinates, all 42 rectangle
assignments and all branch-specific calls are part of the complete contribution.

The separate double118 gauge uses exact double constants60.0,500.0 and1000.0.
With byte120 zero, the lower half draws width60*value*2/1000. At value>=500 it
first draws the full60 segment, then width(value-500)*60*2/1000. With byte120
nonzero it instead draws width60*value/1000 from the animated source region.
Keep variable-first x87 comparisons and the original lower-half-first physical
branch order, including its floating status tests. The initial source derivation
rechecked every constant against its canonical IEEE payload before compilation.

When Context counter1354 is zero, the full owner also draws per-character
world-space overlays. The stun overlay requires positive signed field124,
field128 zero, negative Y, state in[50,150), and absent400 in the live character
sequence frame's AA flags. It uses three strokes, the original facing-specific
X arithmetic, conditionally limited length100 and color
211-(field124>30)*3-(field124>60)*7, followed by the original dark strokes.
The threshold comparisons are the exact >=50 and >=100 forms encoded by the
target; equivalent49/99 comparisons generate different code.

The angle overlay requires nonzero float134 and accepted IsStateGroupA. Its
length uses **float100.0f /360.0f**, with the original nested integer conversion
and different facing-specific addition/subtraction. Both overlays retain
cameraX+(int)worldX and cameraY+210+(int)worldY-(worldY<0) arithmetic, every
original signed/unsigned promotion and the real rectangle member stores.
No fabricated Boolean locals, dummy stores or approximate coordinate helper
replace the observed code. These are live character-frame reads, not collision
snapshot ownership.

### Combo display and native source behavior

RenderCombo receives a real Secondary pointer and caps its signed combo count
at99 without adding a lower clamp. Positive player byte draws the right side
first; otherwise the left side. It displays count, damage and the integer and
one-decimal portions of doubleF8, using the actual signed integer conversion and
signed remainder of (int)(F8*10.0)%10. The exact10.0 constant and all four live
x87 conversion calls are independently reviewed. The provisional decompiler's
register-only DrawNumber arguments are not copied into source.

Signed timer104<=6 selects the original DrawBlendedSurface path and DrawNumber
blend-mode argument; other values use DrawSurface. The two original count>9
branches contain identical DrawNumber calls. Both branches are present in the
/Od target contribution and remain natural source control flow; they are not
removed, filled with padding or counted as additional functions. Decimal-point
rectangles and each side's fade/emission order are included through RET04.

At the display checkpoint, DrawNumber75DB70 was a reviewed dependency with six stack arguments
(two int coordinates, unsigned number, two byte formatting controls and int mode).
The existing Video DrawSurface/DrawBlendedSurface/FillRectangle contracts and
compiler __ftol2 dependency retain their reviewed original destinations. This
checkpoint grants no authored-function credit to those implementations; DrawNumber
is accepted separately in the later number/shadows/keyboard section.

### Focused acceptance and retained evidence

Complete health, HUD and combo sources were built early, at 7700,9028 and2205
bytes respectively. Genuine work records hold only used rectangles, widths,
player/stroke indices or counts. The health derivation initially had private
parser errors involving a frame width name and a spaced dereference; inputs/logs
are retained, and the pinned --execute smoke check passed before subsequent
comparisons. Original branch/literal order and ordinary subtraction resolved
the complete differences. Final formatting/comment cleanup also received full
native comparisons. There are no assembly, copied bytes, padding fields,
masked fields or shortened-prefix comparisons.

The final public source received **one serial cold source/profile/dependency
artifact** and three complete manifest-bound strict comparisons, all zero
at full extent. Existing source files and shared headers are unchanged, so
no previous-unit replay was involved. Public proof is
docs/evidence/battle-display-exact.json. Private complete target instructions,
source/object attempts, independent call/constant/branch/boundary reviews and
final reports remain in .analysis/probes/battle-display/ and
.analysis/exact/battle-display.json. The original decompiles remain in
.analysis/probes/battle-loop/. Only focused ledger/progress/whitespace checks
accompany the checkpoint; no full CI, full cold cohort or runtime matrix.

The checkpoint adds **3 authored complete exact functions /18,944 instruction
bytes**, bringing acceptance to **216 functions /216,680 instruction bytes**,
plus unchanged 667 local-table bytes. Reviewed boundaries and origins are 254 each.
DrawNumber, the shadow prepass and battle keyboard/replay reset were open at
this display checkpoint and are accepted below. Parked pushbox, concrete
background implementations and whole-game/product/runtime/portability closure
remain open. Complete display functions do not establish a runnable
replacement or whole-game completion.

## Battle number, shadows and keyboard replay control

Canonical resources/EFZ.exe and pinned VC7.1 RTM13.10.3077 only. The already-running
reconstruction comparison was completed for the final checkpoint after the
operator requested cleanup/handoff. Four complete authored functions add 4,998 code
bytes and no local tables:

| Member | Entry | Bytes | Exclusive end | Instructions | Direct branches | Direct calls | Virtual/COM calls | Relocations |
| --- | --- | ---: | --- | ---: | ---: | ---: | ---: | ---: |
| DrawNumber | 0x75DB70 | 466 | 0x75DD42 | 145 | 3 | 2 | 0 | 2 |
| RenderShadows | 0x762C50 | 1,440 | 0x7631F0 | 407 | 23 | 8 | 0 | 9 |
| PollKeyboard | 0x765660 | 2,358 | 0x765F96 | 456 | 65 | 8 | 2 | 19 |
| ResetReplay | 0x7661A0 | 734 | 0x76647E | 201 | 2 | 20 | 3 | 24 |

Complete contiguous instruction, branch, receiver, return and following alignment
review is retained in .analysis/probes/battle-controls/boundary-review.json.
The respective following CC lengths are 14,0,10,2, outside credited extents.
DrawNumber ends in RET18; the other three have no stack arguments. All 54
relocations are explicit: 38 direct REL32 calls and 16 DIR32 operands comprising
one IEEE double zero, two security-cookie references, ten actual DWORD latch
accesses and three independently checked NUL-terminated path literals.

### Number rectangles and shadow semantics

Scene3+464 holds seventeen 16-byte font rectangles, ending at +574. Constructor
stores and DrawNumber's indexed access agree on the genuine `numberStyles[17]`
view. No following field moves. DrawNumber uses unsigned remainder/division by10,
a do-while that draws zero, and right-to-left edge subtraction by glyph width
plus unsigned byte spacing. The source right edge is width*(digit+1), whose
original evaluation order matters to codegen. Nonzero mode selects blending.

RenderShadows replaces the incorrect RenderMeters name at762C50. It visits both
characters and their 64-slot effect rings. It uses min(signed frame v,height),
with offset v-height only in the latter branch, a source rectangle of full
frame width and that height, and destination height height/3. Character and
effect visibility gates, pattern/frame ownership and signed facing reads are
preserved. Ring wrap uses >=64 as encoded.

The actor Y formula is 210-((int)y-(y<0))+cameraY+offset; the effect formula is
(cameraY+210)-(int)effectY+offset, without the actor's negative-Y correction.
Effects read their signed facing BYTE at+48, distinct from the live character
facing field+4C. Original top<240/bottom>0 visibility tests and all conversions
remain intact. Work records contain only used indices, pointers and rectangles.

The complete 806-byte original Video callee at `0x40A7B0` independently
establishes `DrawShadowSurface(destination SurfaceRect, IUnknown*, source
SurfaceRect, unsigned byte color key, int mirror, unsigned byte color index)`,
the real Video receiver, int result and `RET 0x30`. Its natural C++ owner now
lives in `src/VideoCharacterDraw.cpp` under unit `video-draw-shadow-surface`.
The source preserves the asymmetric clipping rules (top and bottom only clamp
the destination, while left/right also adjust the source), source-right-relative
mirror transform, DirectDraw lock flags and lost-surface return. It reads the
mask bottom-up, stepping three source pitches for each destination row; mask
pixels equal to the key are skipped, and the others blend the current
 destination pixel through `meanBlend[destinationPixel][colorIndex]`. Destination
then source unlock order is preserved. `0xB0` is the fixed color index, not an
alpha parameter. This corrects the older interpretation.

This is a semantic candidate, not exact. The pinned VC7.1 `/Od` object is
1,091 bytes; the pointer-row/do-while control is 1,078 bytes. `/O2` variants
are 618 and 590 bytes respectively, versus the 806-byte target. Strict
comparison rejects all complete extents. The original body uses ESI/EDI/EBX,
body-local ESI/EDI saves, AH/AL comparisons and three repeated source-pitch
subtractions per row; those compiler-visible details remain unrecovered. No
exactness credit is assigned. Full original instructions and provisional
decompile are retained beside the caller reviews.

### Keyboard and replay behavior

PollKeyboard uses the actual DirectInput keyboard interface, char state[256],
GetDeviceState slot24 and Acquire slot1C only on DIERR_INPUTLOST. Original failure
flow does not zero the buffer or add a retry. Mode6 exit checks Context inputs
and Escape; normal Escape, music release, exhausted replay state and pause stores
retain their original branch order.

F4/F5 update the original control words and both players'30EC/30EE mirrors.
F5's positive equality branches and F6/F7 training controls are preserved. F8
stores the real DWORD key latch at7B1290 before later recomputation from F5..F8.
The missing decompiler store is included. No reconstructed linked global owner
is claimed for the external `battleKeyHeld` binding.

The original constant-true skip retains the FULL disabled F1/F2/F3 stepping,
F9/F10 capture, F11 counter reset and F12 health controls. Natural
`if (true) {} else { ... }` reproduces the original /Od branch and all fourteen
Ghidra-removed blocks; they are not padding. Playback reads the control words
only when signed Context byte1340>0, otherwise substitutes1000/9999. Recording
writes the two words only while unpaused. Genuine Scene3 friendship exposes
WordFile's actual exhausted field and Input's actual keyboard pointer.

ResetReplay is guarded by mode5 and recording flag2. Actual GS-protected path[40]
and number[8] buffers build replay\\data + (signed14282+1) + '-' + (signed14281+1)
+ '.rep'. After fade-out and close, it writes six words: both character IDs,
104, ContextF32 and both palette indices. Context reset, actual externally owned
character LoadResources virtual calls, control-word mirroring, intro/camera
reset, render and fade-in retain the original sequence. Context1340/14281/14282
replace existing unknown bytes without shifting layout. ResetReplay matched
its first complete 734-byte compilation.
A fresh targeted rebuild of `src/SceneBattleInput.cpp` also replayed
`Scene3::ResetReplay` (0x7661A0) at 734/734 bytes with all 24 relocation
bindings exact; no full cold replay was run.

### Acceptance and session closure

The public sources are src/SceneBattleVisuals.cpp (vc71-od-static) and
src/SceneBattleInput.cpp (vc71-od-static-gs). Final formatting also received full
native comparisons. Four new and 210 actual Engine/Input/SceneBattle header
consumers compare complete strict exact from 55 serial cold artifacts. All135
existing compiler-local destination/offset bindings were retained; the changed
Shiori constructor literal ID was independently checked against `shiori` at
787DF0 before receipts were finalized. No toolchain/Wine failure occurred.

Public proof: docs/evidence/battle-controls-exact.json, plus refreshed involved
older certificates. Final reports: .analysis/exact/battle-controls-and-affected.json.
All target dumps, attempts, independent operand/call/constant/boundary reviews
and native logs remain private. Derivation/publish scripts are one-time history;
do not rerun them on an evolving baseline.

Authored acceptance at this historical checkpoint totals 220 functions /
221,678 code bytes, with 667 local-table bytes and 258 reviewed boundaries and
origins. These figures describe that checkpoint, not the current generated
progress report. On 2026-11-09 the operator requested a receiving-agent handoff
and continuation of reconstruction. The earlier statement that no task remained
is superseded. Pushbox, Shiori slot6, other characters, pixel-kernel exactness
and product/runtime/portability closure remain open. Follow RE_HANDOFF.md.

## Video screenshot writer

`Video::SaveScreenshot` at 0x40C1C0 is a complete authored 962-byte member,
ending exclusively at 0x40C582 (RET8, followed by fourteen CC alignment bytes).
Final natural C++ source in `src/VideoScreenshot.cpp` passes complete strict
native comparison with the pinned VC7.1 static /Od /GS profile. All twenty
relocation fields bind explicit reviewed CRT, security-cookie, WINAPI IAT or
literal destinations. No local tables or assembly wrappers are involved.
The full boundary review covers 224 instructions, fifteen internal direct
branches, eleven direct calls, two DirectDraw COM calls and three WINAPI IAT
calls. Public proof is `docs/evidence/video-screenshot-exact.json`.

The filename starts with `snap\sn`, appends three independently stored `0`
literals when index <1000, <100 and <10, then decimal index and `.bmp`.
CreateFileA uses read/write, no sharing and OPEN_ALWAYS. It allocates 0x13036
bytes with new[], locks the actual back surface, and copies 320x240 byte
indices into vertically reversed BMP rows. The source stride is explicitly
(flag0004+1)*320 rather than the lock descriptor's pitch. It preserves the
unchecked Lock/Unlock HRESULT stores, byte sampling in the alternate mode,
and the original absence of file/allocation/error recovery.

Palette entries are written B,G,R,0 starting at 0x36, then the original loop
zeros 0x3A bytes, overwriting the first palette entry as well as the header.
Individual subsequent header byte stores, including the store at offset 47,
are target facts; do not replace them with a conventional BMP header. The
filename buffer is initially _strnset for thirty bytes, not all thirty-two.
Ordinary nested local scopes and a work record containing only live capture
values retain the original /GS frame and local storage; no inert padding is
present. Reformatting or changing these locals requires a new full comparison.

One final selected cold artifact proves the final public source. No accepted
header/source consumer changed and no full CI/cohort ran. Private complete
attempts, disassembly, operand audit and formal log are retained under
`.analysis/probes/video-output/`. FillRectangle at 0x40B300 remains open:
complete review found a second body-local EDI save/restore around a register
pixel loop, consistent with handwritten assembly. Its decompile alone is not
evidence for a permitted natural C++ exact implementation.

## Loading scene and Mizuka creation

Scene2 owns the loading interlude, with the reviewed three-entry table at
0x7896B4: Slot0 76C980, Step 76C790, PollKeyboard 76DA10. Its allocation
remains 0x438; the actual loading surface pointer is at +434, following four
unresolved bytes at +430. Replacing the opaque Scene2 declaration with this
layout preserves every existing member/owner offset.

Seven complete authored contributions are recovered in `src/SceneLoading.cpp`
and `src/SceneLoadingCharacter.cpp`:

| Member | Entry | Instruction bytes | Local table bytes |
| --- | --- | ---: | ---: |
| Scene2 constructor | 0x76C6F0 | 74 | 0 |
| Scene2 destructor | 0x76C740 | 69 | 0 |
| Scene2::Step | 0x76C790 | 488 | 0 |
| Scene2::Slot0 | 0x76C980 | 203 | 0 |
| Scene2::PollKeyboard | 0x76DA10 | 11 | 0 |
| Scene2::LoadCharacter | 0x76DA20 | 2,551 | 100 |
| Character24 constructor | 0x4F8300 | 383 | 0 |

Full native strict comparisons cover 3,779 instruction bytes and all 100 bytes
of the 25-entry address table at 76E417..76E47B. Independent boundary/operand
review covers 1,173 instructions, 85 direct internal branches, one computed
switch jump, 74 direct calls, three genuine virtual/COM calls and all 110
relocation fields. Complete RET boundaries and following CC alignment are
checked independently. Public proof: `docs/evidence/scene-loading-exact.json`.
The constructor, destructor, Step and no-op keyboard use the pinned static
/Od /GS recipe; renderer and creation/character constructors use static /Od.
Profiles remain per-unit codegen evidence, not original TU/build attribution.

Step chooses rand()%175, retaining the disabled override to image 112. It
refreshes both cached actor pointers and constructs system\nl\nlNNN.dat with
two distinct zero literals, retaining the disabled BMP alternative. It renders,
fades in, calls the still-open battle preparation owner at 0x76CA50, fades out
with arguments 0,-500,200, releases the loading surface, loads stage + 10 music
and returns scene ID 3. The renderer directly passes two MakeSurfaceRect return
values to DrawSurface, then presents. Named rectangle assignment temporaries
produce additional copies under VC7.1 /Od and are not equivalent exact source.

LoadCharacter switches on its explicit signed character byte, independently of
the selection scene's grid. All 25 branches retain allocation null paths and
call original constructors with opponent slot, Context/Video/Input/Audio and
player byte. ID 22 uses Character10; ID 24 creates an additional 0x3460-byte
Mizuka object via 0x4F8300, absent from the earlier selection dispatch. It stores
the requested ID, updates the cached actor slot, then copies the unsigned
Context CPU-player flag. The 25 address entries, including ID 22's
Character10 allocation, are part of the complete source contribution.
The called constructors remain open unless separately accepted.

Character24's resource name is the original `mizuka` literal at7885C8. Its
constructor calls Secondary, installs table7885D0, sets surfaceCount 668, four
state words at 0x3138..3144, three 64-word arrays at 0x3148/3248/3348, and five state
words at 0x3448..3458. Pose coordinates are -13,-60 and14,0. The six-command
configuration writes command slots 0/1/2/10 as 6/1/7/18. Its thirteen-entry table
uses inherited LoadResources at 0x410B70; other virtual bodies remain unaccepted.
The partial class view is local to the loading creation source. No new character
behavior/layout claim is inferred beyond the reviewed allocation and accesses.

PrepareBattle at 0x76CA50 remains OPEN. The complete target is 4,029 bytes: 3,893
code +100 address-table +20 address-table +16 selector bytes, ending at 0x76DA0D.
The retained complete C++ draft is 4,031 bytes, not a two-byte-away exact claim.
The first instruction operand difference beyond shifted local-table references
is at 0x76D743, the first background-constructor argument evaluation; later GPR
rotation adds a two-byte receiver move before the first LoadResources call.
Pointer casts/views, destructor declarations and case scopes were byte-neutral;
do not repeat them without new evidence. Its full random/replay/CPU/stage
preparation behavior and disabled BMP branch are retained privately. The
confirmed background scale for stage 16 is 0.125, otherwise 1.0; CPU division is
by 1.5f. These correct the decompiler's lost constant types and initial guesses.
Read `.analysis/probes/scene-loading/README.md` and parked-best before resuming.

## Animated background owners

The four animated background owners used by stages 1, 10, 12 and 16 now have
complete constructors, destructors, Update and Render bodies in
`src/Backgrounds.cpp`. Shared image/pattern loaders are complete in
`src/BackgroundResources.cpp`; `src/Backgrounds.h` records the target-bound
28-byte object layout. Eighteen authored functions add 9,248 instruction bytes
and the complete 16-byte stage16 Update address table. Two compiler-generated
auxiliaries (implicit abstract-base constructor /23 and PatternSequence scalar
-deleting destructor /44) are independently exact and excluded from authored
progress. Public proof: `docs/evidence/backgrounds-exact.json`.

| Owner | Constructor | Destructor | Update | Render |
| --- | --- | --- | --- | --- |
| Background01 | 751370 /390 | 751500 /194 | 7515D0 /337 | 751730 /694 |
| Background10 | 751A40 /384 | 751BC0 /194 | 751C90 /337 | 751DF0 /693 |
| Background12 | 7520B0 /394 | 752240 /194 | 752310 /347 | 752470 /1168 |
| Background16 | 752900 /393 | 752A90 /194 | 752B60 /588+16 | 752DC0 /1170 |

LoadImages is 750D30 /757; LoadPatterns is 751030 /820. Complete independent
boundary/operand review covers all twenty contributions: 2,929 instructions,
151 internal direct branches, one computed jump, 148 direct calls, eight actual
COM/IAT calls, all 216 relocation fields, and following CC alignment. Stage16
Update ends code at752DAC, followed by four reviewed table destinations through
752DBC. The Ghidra code-only /588 candidate is not the complete contribution.

The two actual virtual slots are Update and Render(int,int,char). Render's
layer argument is signed, while EffectSlot.layer is unsigned. The common fields
are signed stage /last-surface at4/6, Video* at8, surface array atC, EffectSlot*
at10, PatternSequence* at14 and unsigned color key at18. The base implicit
constructor installs the pure-call table7890B8; concrete tables are7890B0,
7890C0,7890C8,7890D0. No global table/data implementation credit is implied.
SceneBattleLoop now includes this shared declaration; its six actual accepted
source consumers all remained completely exact. Engine.h is unchanged.

Constructor surface counts are58/5/2/4 and active-effect counts2/1/2/4.
Effects start at x=0,y=-450, with frame/tick0, flag0048=1 and blend group2.
Layer values are respectively0,1,1-i,i>1. Image/pattern loading occurs before
these effect writes. Both animation updates for stages1 and10 retain switch
cases0 and1 even though stage10 has one active effect. Every Update reads actual
pattern duration/count metadata before dispatch, including the scrolling-only
owners. The two metadata words, and the pattern loader's stored serialized ID,
are original disk/memory reads; they are not invented initialized temporaries.

Stage12 deliberately falls through from type0 (advance0.5 and wrap at640) to
type1 (advance0.25 and wrap at640), so type0 advances twice. Stage16 types0..2
advance1.0/1.4/1.8 and subtract widths850/806/789 after the threshold. Type3
advances2.2 and clamps to947 instead of wrapping. Render01 returns for layer1;
Render10 returns for layer0. Render12/16 skip mismatching effect layers and
render a repeated rectangle displaced by640 or the current frame width.
All renderers preserve signed mirroring and blend-group >0 branch order,
original integer truncation, coordinate arithmetic and local frame copies.

Image loading retains the enabled packed-data branch and full disabled BMP
alternative. Paths are system\bg\bgNN\NNN.dat or .bmp, with independent original
prefix/separator literals. The loader processes indices0 through lastSurface,
reads whole files with the original unchecked WINAPI calls and decodes from
buffer + buffer[0]*3+1. Color key comes from surfaces[0]. Pattern paths use
system\bg\bgNN\bgNN.pat. It reads a count, allocates new PatternSequence[count],
reads/stores a serialized pattern ID then discards two words, narrows the frame
count to a byte, allocates frames using a separate int copy, then reads frame
fields in duration/texture/width/height/u/v order. Each frame then discards
fourteen ints and ten16-byte records. Retain exact narrowing, read order and
loop bounds; conventional format cleanup changes bytes and behavior.

Original ownership bugs remain: constructors allocate PatternSequence arrays
before LoadPatterns allocates a replacement, and destructors use scalar delete
on that pointer. The scalar-deleting helper at751A10 calls the original
PatternSequence destructor and optional operator delete; it is not a vector
-deleting helper. No runtime repair is part of this exact reconstruction.

Final public sources and their six affected battle consumers passed all26
complete strict comparisons from only three serial cold artifacts. All five
local address/table bindings were independently checked before symbol-name
refresh. Public certificates and per-unit dependencies were refreshed only for
this selection. No full CI/cohort or runtime matrix ran. Private decompiles,
full disassembly, attempts and reviews live in `.analysis/probes/backgrounds/`.

## Mizuka action selection and lifetime

Eight additional Character24/Mizuka virtual bodies are complete exact in
`src/Character24Input.cpp` and `src/Character24Frame.cpp`, adding 10,953
instruction bytes with no local tables. The existing partial view moved from
SceneLoadingCharacter.cpp into `src/Character24.h`; fields, allocation extent
and virtual contracts are preserved. Engine.h and CharacterViews.h are unchanged.
Public certificate: `docs/evidence/mizuka-exact.json`.

| Member | Entry | Complete bytes |
| --- | --- | ---: |
| InitializeState | 0x4F8480 | 263 |
| ResetPose | 0x4F8590 | 58 |
| RemoveLocalEffect | 0x4F85D0 | 80 |
| Slot03 locomotion delegation | 0x4F8620 | 19 |
| Slot04 action selection | 0x4F8640 | 10,464 |
| Slot01 render no-op | 0x4FAF20 | 11 |
| Slot08 frame no-op | 0x4FAF30 | 11 |
| EmitLocalEffect | 0x4FAF40 | 47 |

Independent boundary/operand review covers 2,783 instructions, 433 internal
branches, 47 direct calls, 43 actual virtual calls and all 92 relocation fields.
The action selector alone has 2,655 instructions, 430 branches, 42 direct calls,
42 genuine ResetPose slot0 calls and 87 relocation fields. Complete RET and
following CC boundaries were checked. The 13-slot table at 7885D0 confirms
these members and inherited Secondary::LoadResources at 410B70; other slot
bodies remain independently open, even where a destination is shared.

InitializeState resets four words at3138..3144, the four constructor pose
coordinates, five words at3448..3458 and all three64-word arrays, then calls
Secondary::InitializeState. ResetPose clears only3138/313C/3140 before the base
reset. RemoveLocalEffect clears the three arrays at the signed short index,
then calls the base removal routine. EmitLocalEffect first makes the actual
virtual removal call using effectWrite and then invokes Secondary::EmitLocalEffect.
The locomotion wrapper calls the already accepted UpdateLocomotionState.

Slot04 is the complete command-to-animation priority owner. It clears buffered
commands for animation <200, maintains the unsigned input latch/countdown and
resets field3458 on exact ground height. It preserves the original ordered
meter/command, animation phase, current-frame permission and frame-limit tests,
including all repeated field reads and original early returns. Transitions call
the real virtual ResetPose and shared ClearBufferedButtons; directional movement
transitions instead retain FaceOpponent and their original byte counters.
The owner handles ground/air commands, directional actions and button variants,
using actual current SecondarySequence/SecondaryFrame records, input pulses,
latched masks and the real opponent slot. No new offset view or fake ABI is used.

Exact source required recovering facts obscured by the decompiler: field01AA,
01A9 and0159/015A are unsigned, and their positive/<1 checks and byte increment
or decrement operations must retain original widths. Standard action checks use
field0168 >=2, but the first command52 special test retains >1. Frame permission
is a positive `(flags &8)>0` test. Meter comparisons are >=3000/>=2000/>=1000,
not the decompiler's adjacent strict inequalities. Airborne animation comparisons
use the unsigned animation field. Preserve the literal half-open ranges and
any seemingly redundant tests rather than algebraically simplifying them.

The directional product evaluates opponent.x-self.x before `(1-command*2)`;
its negative-facing test multiplies that integer factor by -1. Commuting x87
operands, replacing multiply with unary negation, reversing a floating-point
comparison or expressing the air-command branches as sequential failure returns
changes the complete VC7.1 /Od function. The final facing-dependent air animation
store uses an ordinary conditional assignment followed by the common return.
The entire 10,464-byte result, not a normalized instruction diagnostic, is the
acceptance authority.

Final formatted public sources passed all ten selected complete strict native
comparisons from three serial static /Od artifacts: eight new functions plus
the existing Scene2 creation dispatcher and Mizuka constructor that consume the
new header. All26 existing compiler-local table/destination offsets were audited
before symbol-only refresh; the original25-entry dispatcher table remains fully
compared. Tracking and ledger/progress CI are focused checks; no full cohort,
full CI or runtime matrix was requested or run. Private decompiles, complete
attempts, disassembly, derivation and reviews live in `.analysis/probes/mizuka/`.

The earlier PrepareBattle4031/4029 extent issue was tested once using the newly
accepted real background layout, base inheritance and declarations. Its complete
native result and first GPR divergence at76D743 were unchanged. The control is
now parked in `.analysis/probes/loading-owner/README.md`; do not repeat that
layout/type hypothesis without new evidence. It earns no implementation credit.

## Mizuka circular command recognition

Character24::Slot02 at 0x4FAF70 is complete exact: 11,423 instruction bytes,
ending exclusively at0x4FDC0F, followed by one CC byte and the next owner's
prologue. It occupies slot2 of the original table7885D0. Source is
`src/Character24Commands.cpp`; explicit recipe is character-24-recognize-commands
with pinned static /Od. Public proof: `docs/evidence/mizuka-command-exact.json`.

The complete function has 3,352 instructions, 547 direct internal branches and
32 backward loop edges corresponding to32 ordered scans. Every instruction,
branch destination, entry/RET/next-owner boundary and the source COFF extent was
reviewed. There are no calls, relocations, compiler-local bindings or associated
local tables. Acceptance compares all11,423 bytes; instruction normalization is
never used as evidence of a match.

The scanner writes default command99, then applies32 command recognizers in
priority order, returning immediately after a successful match. It reads the
unsigned180-byte history at `i - (i >=180)*180`, with signed field0260 as its
head. Scans use distinct start offsets0,45,90,100,110,125,135 and175 relative to
that head, each ending at head+180. Preserve the exact single-wrap index and
individual window start; replacing it with modulo or a common timeout changes
the target. The source keeps one int index and unsigned byte buttons/stage,
matching the original12-byte frame including the saved receiver.

Each recognizer uses sequential state tests, so a single input sample can
advance multiple stages. Failure masks, zero-input transitions and the sequence
of button/direction checks are significant. Facing is the real signed byte;
2+(facing==-1?0:-1), the6/5 selection and the other subtractive facing predicates
retain the original integer codegen. The final short release/press8 scan uses
the same byte stage with explicit ==1 and ==0 checks, rather than the decompiler's
inferred separate bool. The existing action selector consumes field0262; its
implementation and this scanner remain separate exact units.

The first complete natural C++ scanner already had the full11,423-byte extent,
with14 differing bytes. Original operands exposed the distinction between gate-mask predicates and
positive boolean command-ID sums, together with the true/false branch and store
order of the20-button stage6/7 selection. Those differences
were corrected from the target and the complete body then matched. In source,
gate masks retain !=0, while command-ID arithmetic retains >0 for each of the
E0/C0/80 masks without intermediate narrowing casts. Source scopes, scan
ordering and actual state transitions are preserved; there is no artificial
padding, byte wrapper or fake ABI.

A final cold artifact for the formatted public source passed strict complete
comparison. No existing source or header changed, so no old native units needed
replay. Focused tracking, ledger/progress CI and whitespace checks passed; no
full CI/cohort or runtime matrix ran. Private complete source/object attempts,
full target disassembly, derivation and independent review are retained in
`.analysis/probes/mizuka-command/`. Its generator is derivation evidence rather
than an idempotent tool for recreating refined accepted source.

## Mizuka CPU command and movement owner

Character24::Slot05 at0x4FDC10 is complete exact:16,912 instruction bytes,
exclusive end0x501E20. The next local-effect owner begins immediately, with no
alignment bytes or local tables. Original table7885D0 slot5 points from7885E4
to this entry. Source: `src/Character24Cpu.cpp`; recipe character-24-cpu-input
uses pinned VC7.1 static /Od. Public proof: `docs/evidence/mizuka-cpu-exact.json`.

The complete boundary review covers4,368 contiguous instructions,818 internal
branches and109 direct calls:104 RandomRange calls to4108A0, four CollisionSide
calls to40FF70 and one cdecl fabs call to77842D. All341 relocation operands are
explicitly bound and independently checked against the original instruction:
109 REL32 calls and232 DIR32 float/double operands. The38 distinct floating
payloads were checked in both the canonical target and the native COFF constant
sections, including operand width and symbol bits. No virtual/indirect calls or
local tables occur. The external fabs dependency is identified, not claimed as
an authored reconstruction.

The owner clears command/input pulses, decays both movement timers and derives
its forward and absolute vertical distances. Both real values occupy a natural
sixteen-byte local record; target stack slots are EBP-10 and EBP-8, receiver at
EBP-14 and complete frameD0. There is no padding member or fake declaration.
RandomRange returns short under the accepted ABI; every original caller here
zero-extends AX before integer/floating use, so source preserves the unsigned
short conversion. Consecutive buttonPulse[3] assignments consume two independent
random draws even though the second overwrites the first.

Preserve the priority exits before ordinary decisions: special mode2 handling,
opponent animation96, initial state50..150/tick0 input generation, grounded
movement/attack guards, command52 and the positive field3458 timer owner. The
latter has its own attack and movement decisions before returning; merging it
into the general CPU tree changes the original ordering. Active movement timers
also exit before selecting new random timers. Conditional tails and separate
state204 successful-choice/outer exits retain the original control flow.

Exact codegen depends on the target's floating operand order and original
integer thresholds: >=3000 and >=1000 meter checks, difficulty multiplication
by two, a signed integer boolean product in the initial threshold, and the
vertical-minus40 comparison against forward distance. Reassociating subtraction
or reversing floating operands changes behavior for exceptional values as well
as emitted x87 instructions. Do not normalize these tests from decompiler output.
Existing Shiori CPU source supplied field/ABI hypotheses; all Mizuka acceptance
comes from this canonical target's complete comparison and operand review.

The formatted public source passed one selected cold native artifact with all
16,912 bytes equal and zero differences after the341 reviewed relocations.
Public headers and existing sources are unchanged, so no old unit required
replay. Focused tracking, ledger/progress CI and whitespace checks passed; no
full CI/cohort or runtime matrix ran. Private decompile, complete source/header/
object attempts, retained compiler exits, full disassembly and independent
reviews are in `.analysis/probes/mizuka-cpu/`. Its one-time derivation scripts
must not be rerun over accepted or newer sources.

## Mizuka local effect dispatch and controls

Three new authored functions add42,383 exact instruction bytes and348 associated
local-table bytes. Main source is `src/Character24Effects.cpp`; support source
is `src/MizukaEffectSupport.cpp`. Public proof:
`docs/evidence/mizuka-effects-exact.json`. Explicit recipes use pinned VC7.1
static /Od, never masked or partial comparison.

| Complete owner | Canonical entry | Exact code bytes | Associated local tables |
| --- | --- | ---: | ---: |
| Character24::Slot07 | 0x501E20 | 42,279 | 348 |
| SecondaryPose::VectorAngle | 0x4C0480 | 45 | 0 |
| Context::StartFade | 0x408040 | 59 | 0 |

The Mizuka dispatcher ends its code at50C347. A62-destination address table
occupies50C347..50C43E, followed by the100-byte type400..499 selector map at
50C43F..50C4A2. The complete42,627-byte contribution ends exclusively at50C4A3;
thirteen following CC bytes precede the next function50C4B0. Original owner
7885D0 slot7 points from7885EC to501E20. Complete review covers9,600 contiguous
instructions,715 direct internal branches, one compressed indirect switch and
61 explicit effect cases;39 selector entries share the default. Every table
entry and destination was checked independently.

All505 new relocation operands are reviewed: main64 compiler-local fields,
108 direct calls and331 typed floating operands; VectorAngle adds one CALL and
one constant. Both native COFF constant bytes and canonical payloads agree for
65 distinct floating literals. Each field records a real symbol, destination
and evidence, including each table destination and compiler-local offset.
The main owner also makes104 real virtual calls to ResetPose, EmitLocalEffect
or RemoveLocalEffect; their original receiver and slot accesses remain intact.
They are indirect instruction operands, not invented relocations.

The real72-byte EffectSpawn descriptor is reused through its existing shared
SecondaryEffectSpawn base for local emission and Context effects. The ordinary
active-effect scope contains frameDuration/frameCount. Complete source recovers
index atEBP-4, descriptor atEBP-50, duration/count atEBP-54/-58, receiver atEBP-5C
and full frame17C without padding or a fake ABI. Animation increments/decrements
and frame rollback use the original word-width operations; field000C's specific
unsigned read and the ring-wrap >=64 threshold retain target codegen.

Type437 is physically placed between420 and421; sorting source labels changes
the full native contribution. Preserve the hit/cancel exits before normal work
for417..420, the positive first-hit branch for444..451, original group0/else
bounce ordering and the independent type440 transition/expiry exits. The expiry
branches in440,497 and498 jump directly out of the switch; a byte-identical-size
jump merely skipping an else body has a different destination and is rejected.
The first complete strict comparison exposed these three remaining jump fields;
normalized branch diagnostics could not establish acceptance.

Particle types497/498 consume independent random samples with ordered scalar
coefficients. Preserve the association between each actual rand CALL and its
coefficient rather than reusing an algebraically remembered formula. Floating
operand order, first/else ordering, integer center-minus-facing products and
short compound frame updates also matter. Type496 cancellation emits its full
particle sequence before returning; it is separate from the surviving frame
update. Original target evidence, rather than similarity with Shiori, proves
all of these emitted instructions.

VectorAngle is an ordinary method on the existing pose subobject. Its caller
passes ECX=this+8 and two doubles; the helper stores that receiver, calls
atan2(y,x), multiplies by the exact57.29579143313326 payload at787FF8 and returns
with RET10. The CRT entry778970 loads descriptor78F220, which explicitly names
atan2. This identifies an external CRT dependency, not an authored reconstruction
of the math runtime. StartFade writes fadeDirection=1, fadeAttack=arg1,
fadeHold=arg2 and fadeRelease=arg3 in that order, then RET0C. Layouts and original
class/type names remain reconstruction views, not claims about recovered names.

Only two nonvirtual method declarations change public Engine.h; data layout and
existing method bodies are unchanged. To keep dependency-bound exact evidence
current, formal replay selected three new units and241 actual Engine.h consumers,
compiled once per65 source/profile/dependency groups. Every complete comparison
passed strict zero-difference acceptance, including the main's full tables.
Generated local-symbol names were reviewed against unchanged original destinations,
local offsets and string payloads before refreshing receipts. Thirty-three
unaffected existing units (31 authored and two auxiliary) retained their earlier
evidence. This was an explicit affected
selection; no unrequested full cold cohort, full CI or runtime matrix ran.
Tracking, ledger/progress CI and whitespace checks passed. Private full attempts,
compiler exits, decompiles and independent reviews remain in
`.analysis/probes/mizuka-effects/`.

## Mizuka animation and state owner

Four new complete authored units add65,964 exact instruction bytes and836
associated local-table bytes. Main source: `src/Character24State.cpp`; support
source: `src/MizukaStateSupport.cpp`. Public proof:
`docs/evidence/mizuka-state-exact.json`. All four explicit recipes use pinned
VC7.1 static /Od and complete strict comparison.

| Complete owner | Canonical entry | Exact code bytes | Associated tables |
| --- | --- | ---: | ---: |
| Character24::Slot06 | 0x4E7EC0 | 65,782 | 836 |
| Secondary::SetHorizontalOffset | 0x410A40 | 63 | 0 |
| Context::StartReverseFade | 0x408080 | 59 | 0 |
| Context::SetSceneTimer | 0x4080C0 | 60 | 0 |

The main function has17,962 contiguous instructions,1,636 direct internal
branches and one compressed indirect switch. Code ends exclusively at4F7FB6;
the520-byte address table then ends at4F81BE, followed by316 selector bytes for
animation IDs1..316. Its complete66,618-byte contribution ends at4F82FA. Six CC
bytes precede the existing accepted constructor4F8300. All130 destinations are
reviewed:129 explicit animation cases and a default selected by187 entries.
Original vtable7885D0 slot6/operand7885E8 contains4E7EC0, independently checked.

All1,454 relocation fields are individually reviewed:442 direct CALL operands,
880 typed floating operands and132 compiler-local fields (130 table entries and
two dispatch operands). The83 distinct floating payloads match canonical memory,
native COFF bytes, symbol bits and original operand widths. The three support
functions have no relocations. No original byte arrays, patched code, padding,
fake ABI, masked addresses, size overrides or prefix acceptance are used.

The ordinary source has frameDuration/frameCount atEBP-4/-8, one real72-byte
EffectSpawn descriptor atEBP-50, receiver atEBP-54 and complete frame42C. Existing
shared member and virtual declarations supply the real receiver adjustments.
The source preserves signed-short RandomRange with explicit unsigned caller
conversion: all seven original AX results are zero-extended. Additional masks
on those already-converted values emitted unwanted AND instructions and were
removed only after checking the original operands.

Every promoted tick load in this owner uses MOVZX (328 occurrences), as do all
17 promoted field0158 loads. Public field declarations remain compatible with
prior accepted code; this source uses explicit unsigned short/byte read casts.
Original word/byte stores and increments retain their widths. A target-backed
view splits existing unknown storage into word field00DC and byte field00DE:
4F21AE stores4 toDC and4F21BA storesEC toDE. Remaining offsets and object size
are unchanged; signedness of unused read behavior is not claimed recovered.
The reserved-storage name had no existing source consumers.

Original control flow includes immediate collision, landing, action-cancel and
state-transition exits. Animation178 has both an inner completed-frame exit
and its outer case exit. Animations180/181,212,220,303..305 and313..315 preserve
their direct dispatch exits, positive first/else order and original thresholds.
Animation206's slide first checks positive velocity, flag1 and frame<3, then
subtracts its scalar; other paths clear the flag. Its floating comparison is
not the decompiler's negated <= expression. Integer center-minus-facing products,
short frame rollback, x87 operand order and random draws remain target-bound.

The first complete natural source contributed66,643 bytes against66,618. Full
comparison and per-case diagnostics exposed decompiler-normalized conditions,
unsigned reads and early exits. The last32 differing bytes came from two wrong
exit destinations and animation206's slide branch. Restoring these yielded a
strict whole-contribution exact result, retained after source formatting.
Per-case sizes and normalized branches never conferred progress credit.

The three concrete support bodies retain the real ABIs. SetHorizontalOffset
writes `(1-player*2)*magnitude` to Context14238 and hold to14240, returning RET08.
StartReverseFade writes direction-1 then attack/hold/release and returns RET0C.
SetSceneTimer stores Context14278, halves it with signed division only when
setting136C==0 and returns RET04. These methods retain existing provisional view
names rather than asserting recovered original source names.

Formal validation selected four new units and244 actual Engine.h consumers,
including existing auxiliaries, from67 serial cold source/profile/dependency
artifacts. All248 complete comparisons passed strict zero differences; both
main tables were compared in full. Compiler-local identities were refreshed
only after unchanged offsets, canonical destinations and literal bytes were
verified. Thirty-three unrelated prior units retained their evidence. Tracking,
ledger/progress CI and whitespace checks passed; no full CI/cohort or runtime
matrix ran. Private evidence, complete attempts and compiler exits remain in
`.analysis/probes/mizuka-state/`.

With this accepted owner, every one of the13 original Mizuka vtable destinations
has a complete exact source-bound proof, including the inherited shared resource
loader. This closes that virtual-entry code inventory only: linked data/assets,
original translation-unit partitioning, complete runtime behavior and whole-game
reconstruction remain independently open. The earlier parked Shiori dispatcher
receives no credit from this function's result and must not be retried without
new falsifiable evidence.

## Misuzu construction input and indicator owners

Ten complete authored functions add 21,917 exact instruction bytes without
associated local tables. Sources: `src/Character23Frame.cpp`,
`src/Character23Input.cpp` and `src/Character23Commands.cpp`. Public proof:
`docs/evidence/misuzu-exact.json`. Explicit recipes use pinned VC7.1 static /Od
and complete strict comparison, with no masks, size overrides or prefix credit.

| Complete owner | Canonical entry | Exact code bytes |
| --- | --- | ---: |
| Character23 constructor | 0x519E00 | 615 |
| Character23::InitializeState | 0x51A070 | 555 |
| Character23::ResetPose | 0x51A2A0 | 58 |
| Character23::RemoveLocalEffect | 0x51A2E0 | 80 |
| Character23::Slot03 locomotion | 0x51A330 | 19 |
| Character23::Slot04 action input | 0x51A350 | 12,340 |
| Character23::Slot01 indicators | 0x51D390 | 2,631 |
| Character23::Slot08 frame control | 0x51DDE0 | 330 |
| Character23::EmitLocalEffect | 0x51DF30 | 47 |
| Character23::Slot02 command scanning | 0x51DF60 | 5,242 |

The canonical selection ID is 23. Its creation dispatch allocates 0x3488 bytes
and calls 519E00; the constructor copies the NUL-terminated resource literal
"misuzu" from 788648 and installs vtable 788650. All 13 original destinations
were checked directly. Nine child virtuals above plus inherited LoadResources
410B70 now have exact proofs. Slot05 CPU 51F3E0/17127, slot06 state
50C4B0/54769 and slot07 local effects 5236D0/54139 remain open. Constructor
acceptance is an additional function, not a fourteenth virtual entry. This
inventory does not establish linked-resource, runtime or character closure.

Complete independent boundary review covers 5,766 contiguous instructions and
780 direct internal branches, all within the reviewed extents. Every following
padding interval and next entry is recorded. All 136 relocation fields have
explicit reviewed symbols, original destinations and evidence, including typed
floating payloads, the real vtable and resource string. No compiler-local tables
occur in these new functions. Existing source similarity supplied hypotheses;
only this canonical target's instructions and complete comparisons establish
acceptance.

The constructor sets surfaceCount to 872, commandCount to 5, command entries
0..5 to 1,19,2,0,1,6 and entry 10 to 23. It clears 19 scalar fields and three
64-int arrays at 3158,3258,3358. Constructor and InitializeState have distinct
store order and box values. Constructor boxes are (-2,-62), (1,-10), (24,-18),
(-11,-23), (21,-22); initialization uses (-13,-60), (14,0), (17,-6), (7,-25),
(27,-25). Only the existing opaque Character23 tail is expanded into observed
fields. The final field starts at 3480 and natural inherited alignment retains
size 3488; no explicit tail padding is added. Both existing creation consumers
retain their complete original allocation/call instructions.

InitializeState calls the shared initializer, constructs one real 72-byte
EffectSpawn descriptor, resets through the base and emits type400 at (320,-320),
group0, layer1, field0028=1, owner1 and flag0018=facing. Ordinary locals recover
frame50, receiver EBP-50, loop index EBP-4C and descriptor EBP-48. ResetPose
clears 3138,313c,3140 before the base reset. RemoveLocalEffect clears all three
arrays at the requested slot before the base removal. EmitLocalEffect removes
effectWrite through the real virtual slot before the shared emitter.

Frame control decays field345c, applies tint (203,3) to the opponent while
field3460 is positive and drives field3458's timer. It periodically reduces
opponent field0108 by ten, clamps at one and resets counters on the original
hurt-state, timer and opponent-health gates. An initial self-receiver draft
emitted 324 bytes; the target's actual opponent receiver yields all 330 bytes.
The indicator renderer draws three status sprites from pattern42, then an icon
and gauge from patterns43/44. It uses one PatternFrame and actual source/target
SurfaceRect records, 15 real MakeSurfaceRect calls and five DrawSurface calls.
The gauge width evaluates `field345c * frame.width / 3000` in that operand
order. Reversing the multiplication emitted 2619 bytes against 2631 by dropping
register moves. The real frame214 and saved ESI require no inert locals.

Action input has frame44, receiver EBP-4, 3,141 instructions, 507 internal
branches and 102 relocations: 44 direct calls and 58 floating operands. Preserve
unsigned latch/countdown reads, actual byte increments/decrements, field01aa
<=0 versus ==0, field0159/015a <1 and positive frame-permission masks. Meter
thresholds are >=3000/>=2000/>=1000; the first phase gate is >1 and the others
>=2. Directional products evaluate opponent.x-self.x before the integer factor
`1-field0262*2`. Positive combined air guards and the original special/normal
action priorities retain exact exits. Two final differing byte extents were
real field0158 byte increments, rather than widened read/add/store expressions.

Command scanning has frameC, receiver EBP-C, index EBP-4 and unsigned byte
buttons/stage at EBP-5/-6. Its 1,513 instructions and 243 internal branches
implement 16 ordered scans over the 180-entry circular history, with single-wrap
indexing `i-(i>=180)*180`. It defaults to command99; preserve each window,
sequential stage advancement, facing-dependent IDs, first meter3000 gate and
later >=1000 gates. Gate-mask !=0 and positive command-ID sums emit different
branches. The first complete source already had size5242 but seven differing
bytes; three gate jumps and two meter-threshold pairs required correction.
Size agreement alone never conferred acceptance.

Final formatted sources passed 37 complete strict comparisons from 17 serial
cold source/profile/dependency artifacts: ten new units and 27 actual consumers
of CharacterViews.h. All 308 refreshed generated-symbol identities across six
old units retain reviewed offsets, destinations or literal payloads. The other
254 existing units retain earlier evidence. Engine.h and Input.h are unchanged.
Focused tracking, ledger/progress CI and whitespace checks passed; no full
CI/cohort or runtime matrix ran. Full target dumps, read-only annotated
decompiles, source/object attempts, compiler exit logs and independent reviews
remain in `.analysis/probes/misuzu/`. Its one-time derivation/publication scripts
must not be rerun over accepted or newer sources.

## Misuzu CPU command and movement owner

Character23::Slot05 at 0x51F3E0 now has complete strict exact source in
`src/Character23Cpu.cpp`, profile vc71-od-static. Its 17,127 instruction bytes
end exclusively at 5236C7. Nine CC alignment bytes precede local effects
5236D0; they are excluded, and no local contribution tables occur. Original
vtable 788650 slot5/operand788664 contains 51F3E0, independently verified.
Public proof: `docs/evidence/misuzu-cpu-exact.json`. Names remain reconstruction
views rather than recovered original identifiers.

Independent full review covers 4,399 contiguous instructions, 809 direct
internal branches and all 318 relocation fields: 108 calls to accepted
Secondary::RandomRange 4108A0, two to CollisionSide 40FF70, one to external
fabs 77842D and 207 typed floating operands. Every original operand has an
explicit actual symbol, canonical destination and evidence. All 39 distinct
float/double payloads match target memory, native COFF bytes and symbol bits.
The fabs implementation's caller ABI and actual FABS operation are retained
as external dependency evidence without authored runtime credit.

The CPU clears command0262 to 99, decrements positive movement timers01a0/01a4
and clears input/button/guard outputs before its decisions. The random guard
thresholds preserve the original precomputed ternaries, float additions and
double multiplication order. The field0170==1/mode3114==2 exit and opponent
state96 exit precede distance calculation. A real used sixteen-byte distance
record recovers forward at EBP-10 and vertical at EBP-8, receiver at EBP-14 and
frame FC, without inert locals, fake declarations or padding.

Target branch order handles the current hurt-state/tick-zero path before the
regular decisions, then exits from grounded movement animations or the original
opponent/current animation guard. The special command52 gate tests own resource
or flag, a fresh random draw, opponent states150..156 and four current-state
alternatives with their separate random draws. Preserve all random samples and
unsigned AX caller conversions; no redundant AND mask is added to a converted
RandomRange result. Clearing an invalid mode2 returns before general choices.

The original mode choices and animation-specific command selections retain
their physical order, separate successful-choice exits and positive conditional
tails. The target computes thresholds as constant minus boolean times constant,
including 70,80,90; replacing these with negative multiplication plus a constant
changes register allocation and codegen. The late opponent-state predicate
really uses a 4.0f coefficient, and another late source condition requires
forward distance >800.0 and <120.0. Both canonical literal payloads and original
comparisons were checked. Apparently contradictory conditions are preserved;
logical cleanup would change target instructions. Positive active movement
timers own separate CollisionSide/clamp exits before new random choices.

The first compiling complete source contributed 17,267 bytes. Original entry
priority, early exits, positive conditional tails and integer arithmetic order
reduced it to 17,127. The final four differing bytes identified incorrect source
literals, corrected to the original 4.0f and 800.0 before acceptance. Final
formatted source retained the full zero-difference result. Diagnostic branch
normalization and size agreement supplied no acceptance credit.

One selected final cold artifact passed all 17,127 bytes with zero differences
after the 318 reviewed bindings. Public headers and existing source bodies are
unchanged, so no old native unit needed replay. Focused tracking, ledger/progress
CI and whitespace checks passed; no full CI/cohort or runtime matrix ran. One
initial generated-source syntax failure was fixed, and the required pinned
toolchain --execute C/C++/Windows/CRT/resource/link/execution smoke passed before
further native builds. All attempts and compiler exits remain retained under
`.analysis/probes/misuzu-cpu/` and `.analysis/build/`.

Eleven of the thirteen original Misuzu vtable destinations now have exact
source-bound proofs, including the inherited resource loader. State50C4B0/54769
and local effects5236D0/54139 remain open, as do linked data/assets, original
translation-unit partitioning, runtime behavior and whole-game reconstruction.

## Misuzu animation and state owner

Character23::Slot06 at 0x50C4B0 has complete strict exact source in
`src/Character23State.cpp`, profile vc71-od-static. It adds 54,769 instruction
bytes and 853 associated local-table bytes. Public proof:
`docs/evidence/misuzu-state-exact.json`. The complete 55,622-byte contribution
ends exclusively at 519DF6; ten CC alignment bytes precede constructor519E00
and are excluded. No size override, masked address or partial acceptance is used.

Code ends at 519AA1. Its 536-byte table holds 134 canonical destinations; the
317-byte compressed selector starts at 519CB9 and covers animation IDs1..317.
All 133 explicit cases have their own reviewed destination, with 184 selectors
using the shared default. Independent review covers 14,960 contiguous
instructions, 1,430 direct internal branches, one indirect switch and the
original vtable788650 slot6/operand788668 pointing to 50C4B0. Following tables,
padding and next entry were checked directly against canonical target bytes.

All 1,300 relocation fields are reviewed independently: 343 direct CALLs,
821 typed floating operands and 136 compiler-local fields (134 address entries
and two dispatch operands). Every declaration names the actual symbol,
canonical destination and evidence. All 77 distinct float/double payloads agree
in original memory, native COFF bytes and symbol bits; original operand widths
match. All calls use existing accepted shared declarations, including FadeMusic,
SetHorizontalOffset and SetSceneTimer. The 217 real virtual calls retain actual
owners and slot accesses and do not introduce invented relocation fields.

A real used 72-byte EffectSpawn descriptor and ordinary duration/count locals
yield frame2B4, receiver at EBP-54, descriptor at EBP-50 and duration/count at
EBP-4/-8. The four-byte epilogue has no saved nonvolatile register. Public
Engine.h, CharacterViews.h and Input.h remain byte-identical. Source views use
the existing actual class layout and methods, without extra ABI views or padding.

Every promoted word tick read in the target uses MOVZX, 305 occurrences; source
uses explicit unsigned reads while preserving the accepted shared declaration.
Original word increments/decrements and byte updates retain their actual widths.
Clamp branches, landing/collision exits and input cancellation preserve original
positive branch order, floating operand order and exact destinations. Restoring
>= thresholds for field3138/313c retains the original immediate operands rather
than only equivalent integer truth values.

Animation210 rolls back the frame on its original negative landing predicate.
Animation211 first tests field0028<0, updates vertical velocity
there and performs its positive landing exit before ordinary animation work.
Animation212's field0168>1 transition exits before normal landing/tick work.
Animation248 sets its follow-up flag using the original opponent-y<0 guard and
state alternatives; animation249's landing exit precedes grabbed-opponent
positioning. States259..261 retain their frame>8 positive landing exits.

Specials300..302 and304 have separate direct dispatch exits after success,
frame8 transitions and local effect emission. Repeat owners310..312 also exit
after frame rollback/counter updates. Replacing these with an else continuation
can preserve apparent behavior while changing branch bytes and destinations.
Particle coordinates use integer center-minus-facing products before double
conversion; negative multiplication plus addition changes codegen. The cutscene
writes actual Context state1420c/state1420e word fields through self/opponent
Context owners. Provisional integer-pointer decompile text must not become
scaled Context-pointer arithmetic in source.

The first complete source compiled successfully and contributed 55,578 bytes
against 55,622. Whole-function comparison and case diagnostics identified
unsigned reads, control polarity, direct exits, operand order and pointer views.
After target-backed corrections all 133 cases aligned diagnostically, and the
entire unmodified contribution passed strict zero differences. Final source
formatting retained that result. Case-local or branch-normalized diagnostics
confer no acceptance credit by themselves.

One final selected cold artifact passed all 55,622 bytes, including both complete
tables and all 1,300 reviewed bindings. Public headers and all prior source and
unit recipes are unchanged, so no old native unit needed replay. Focused tracking,
ledger/progress CI and whitespace checks passed; no full CI/cohort or runtime
matrix ran. All native builds succeeded under pinned VC7.1 RTM, EFZ-only Wine,
serial one-CPU nice10 bounded commands with retained exit logs. Complete target
dumps, read-only decompile, source/object attempts and reviews remain in
`.analysis/probes/misuzu-state/`. One-time derivation/publication scripts must
not be rerun over accepted or newer source.

Twelve of thirteen original Misuzu vtable destinations now have complete exact
source-bound proofs, including inherited LoadResources. Local effects5236D0/54139
remains open, as do linked data/assets, original translation-unit partitioning,
complete runtime behavior and whole-game reconstruction. This checkpoint gives
no credit to the parked Shiori state dispatcher.

## Misuzu local effect dispatch and controls

Character23::Slot07 at 0x5236D0 has complete strict exact source in
`src/Character23Effects.cpp`, profile vc71-od-static. It adds 54,139 instruction
bytes and 372 associated local-table bytes. Public proof:
`docs/evidence/misuzu-effects-exact.json`. Every byte of the complete 54,511-byte
contribution is compared; no prefix, size override or masked address acceptance
is used. Canonical vtable788650 slot7/operand78866C contains5236D0.

Code ends exclusively at530A4B. A 272-byte table holds 68 original destinations;
the 100-byte type400..499 selector starts at530B5B and ends at530BBF. There are
67 explicit effect cases and 33 default selectors. One CC alignment byte precedes
next prologue530BC0 and is excluded. Independent review covers all12,296
contiguous instructions, 832 direct internal branches, one indirect switch,
all table entries, selector values and following code boundary.

All662 relocation fields are independently reviewed:173 direct CALL operands,
419 typed floating operands and70 compiler-local fields (68 address entries and
two dispatch operands). Each records a real symbol, original destination and
evidence. All78 distinct float/double payloads agree in canonical memory, native
COFF bytes, symbol bits and operand widths. Direct calls include112 RandomRange,
36 real x87 integer conversions,16 external rand calls and existing shared
emitter, descriptor, fade and polar-velocity helpers. All112 original RandomRange
calls immediately zero-extend AX. There are128 real virtual emitter/removal
calls, using actual owners and slots rather than invented relocations.

The original freeze gate checks the opponent's field014c before traversing the
64-entry effect ring. Effect active/type/frame/tick and freeze-permission reads
use the existing actual slot view. The source has one real72-byte EffectSpawn
descriptor at EBP-50, ring index at EBP-4, active-scope duration/count at
EBP-54/-58 and receiver at EBP-5C. Sixty coordinate expressions compute and
spill x/y offsets before their RandomRange calls; recovering that original
operand evaluation order naturally yields full frame494 and saved EBX/ESI.
No inert locals, padding, byte wrappers or fake ABI declarations are introduced.

Word-width frame increments/decrements and rollbacks are retained. Float
comparisons keep actual operand order, including opponent-first collision bounds
and effect-coordinate-first orientation terms. The main follower multiplies its
computed velocity by effects[i].flag0048 only after the original scalar operations.
Particle coordinates preserve integer subtraction before conversion to double;
negative multiplication plus addition changes native code. Polar emission uses
`45 - field3154 * 2` and real compound velocity updates, retaining the original
address calculation across random calls.

Type400's six state transitions jump directly to the ring continuation. The
initial positive cancellations for412/413/416/419, the hit/lifetime transitions
for415/418/421..423/453..455, bounce emission for428..430 and the state/collision
exits for456..458 retain their original branch priority. Cases403/405 have their
own frame2 exits. Case457 retains distinct completed-frame and outer exits.
The final raw comparison exposed nine real jump fields that normalized branch
diagnostics concealed; every original destination was restored in natural
source before acceptance.

The cutscene449 owner reads Context selection134e through an explicit signed
char view and writes actual Context state1420c/state1420e members. Provisional
integer-address decompile expressions must not become scaled Context-pointer
arithmetic. Original opponent-health tests use <=0 and <=5000, retaining their
exact immediate values and conditional jumps. Its frame18/tick900 release exits
before ordinary animation work. Type496 emits all cancellation particles before
its original direct exit. Types497/498 preserve every independent rand sample's
coefficient association and their direct expiry exits; algebraically commutative
rewrites would assign coefficients to different draws.

The first compiling complete contribution was54,096 bytes. Full comparison
identified lost word updates, unsigned RandomRange reads, pre-call coordinate
spills, natural compound updates, operand order and original branch polarity.
The eventual54,511-byte source still had24 differing bytes: nine internal jump
fields and three threshold comparisons. Restoring original direct exits and
threshold expressions yielded complete strict zero differences, retained after
source formatting. Case extents, register-normalized shapes and branch-normalized
diagnostics never conferred acceptance credit.

One final selected cold artifact passed all54,511 bytes, both complete tables
and all662 reviewed bindings. Public Engine.h, CharacterViews.h and Input.h,
all275 earlier authored matches and293 earlier unit recipes remain unchanged;
no old native unit required replay. Focused tracking, ledger/progress CI and
whitespace checks passed; no full CI/cohort or runtime matrix ran. An initial
provisional Context cast syntax failure was corrected, and required toolchain
--execute C/C++/Windows/CRT/resource/link/execution smoke passed before further
native compilation. Full attempts, compiler exits, target dumps, read-only
decompile and independent reviews remain in `.analysis/probes/misuzu-effects/`.
One-time derivation/refinement/publication scripts must not be rerun over
accepted or newer sources.

Every one of the13 original Misuzu vtable destinations now has complete exact
source-bound evidence, including inherited LoadResources. This is a virtual-entry
code inventory milestone only. Linked data/assets, original translation-unit
partitioning, runtime behavior and whole-game reconstruction remain open.
The next constructor546480 uses original "mishio" literal788760 and table788768;
its creation ID, full virtual extents and exact source still require review.
## Mishio construction input and indicator owners

Ten complete authored functions add 23,968 exact instruction bytes without
associated local tables. Sources: `src/Character15Frame.cpp`,
`src/Character15Input.cpp` and `src/Character15Commands.cpp`. Public proof:
`docs/evidence/mishio-exact.json`. Explicit recipes use pinned VC7.1 static /Od
and complete strict comparison, without masks, size overrides or prefix credit.

| Complete owner | Canonical entry | Exact code bytes |
| --- | --- | ---: |
| Character15 constructor | 0x546480 | 513 |
| Character15::InitializeState | 0x546690 | 413 |
| Character15::ResetPose | 0x546830 | 58 |
| Character15::RemoveLocalEffect | 0x546870 | 80 |
| Character15::Slot03 locomotion | 0x5468C0 | 19 |
| Character15::Slot04 action input | 0x5468E0 | 13,534 |
| Character15::Slot01 indicators | 0x549DC0 | 3,278 |
| Character15::Slot08 frame control | 0x54AA90 | 701 |
| Character15::EmitLocalEffect | 0x54AD50 | 47 |
| Character15::Slot02 command scanning | 0x54AD80 | 5,325 |

Canonical selection ID15 allocates 0x3478 bytes and calls constructor546480.
The constructor copies the complete NUL-terminated resource literal "mishio"
from788760 and installs vtable788768. All13 original virtual destinations were
read directly. Nine new child virtuals plus inherited LoadResources410B70 now
have exact proofs. CPU54C250/15066, state530BC0/87313 instruction bytes and
effects54FD30/29568 instruction bytes remain open; the latter two associated
table extents still require review. Constructor acceptance is additional to the
13 virtual entries. This inventory does not establish character, resource or
runtime closure.

Independent complete boundary review covers6,271 contiguous instructions,
880 internal branches and all following padding/next entries. All156 relocation
fields have reviewed original operands, symbols and destinations:97 direct
calls,57 typed floating operands, one resource string and one vtable store.
All nine floating payloads agree independently in canonical target and COFF.
There are51 real virtual calls and no new compiler-local tables. Decompiler
annotations and prior characters supplied hypotheses; only original EFZ
instructions and complete native comparisons establish acceptance.

Constructor and initializer clear15 scalar ints at3138..3170 and three64-int
arrays at3174,3274,3374. Their final field ends3474; ordinary inherited
alignment retains allocation3478 without explicit padding. Only Character15's
opaque tail is expanded. Constructor surfaceCount is1303, commandCount is7,
commands[0] is3 and commands[10] is15. The observed byte stores are30F4,30F5
and30FF respectively. Both initialization paths use boxes(-4,-57),(18,0),
(21,-12),(18,-15),(38,-39) in that store order. InitializeState calls only the
shared initializer after its stores and loop. Both creation consumers retain
their original complete allocation/call instructions.

ResetPose clears3138,313c,3140 before the shared reset. RemoveLocalEffect
clears all three arrays at the requested slot, then calls the base. The emitter
removes effectWrite through the actual virtual slot before the shared emitter.
Locomotion calls the accepted shared movement owner.

Frame control constructs one used72-byte EffectSpawn and resets it through the
shared helper. State3's positive3168 timer decrements except during state318,
and exhaustion clears3158. Active states decrement315c. State3 advances3160
through144 and applies eight self tints at18-frame intervals, using the original
209,208,207,177,207,208,209,210 sequence and duration27. Outside hurt states
50..149, expired315c emits type34/36 according to3158; state3 uses an unsigned
RandomRange(0,100) result against50. Position casts, facing multiplication and
unsigned random returns retain the target's order; group2/layer1 emission
resets315c to2. Ordinary locals recover frame54, receiver EBP-4C, descriptor
EBP-48 and saved ESI, without inert locals.

Indicators advance3164 through29. Four independent state tests draw patterns
39..42; active states use frame3164/6. Two independent positive3168 tests draw
icon43 and gauge44. Mirrored player coordinates and all18 MakeSurfaceRect /
six DrawSurface calls are preserved. Gauge width evaluates
`field3168 * frame.width / 4500` in that order. Width-first multiplication
removed12 bytes of register moves; field-first source recovers all3278 bytes,
including frame274, receiver EBP-274 and saved ESI.

Action input has frame14, receiver EBP-4,3,397 instructions,583 branches and
107 relocations:46 ClearBufferedButtons calls, four FaceOpponent calls and
57 floating operands. Preserve unsigned latch reads, byte increments/decrements,
01aa<=0,0159/015a<1 and positive permission masks. The first two phase gates
are >1; later gates use >=2. Directional products evaluate opponent.x-self.x
before `1-field0262*2`; opposite facing uses multiplication by-1. Positive
combined air guards, the three independent3158==3 final assignments and the
original special/normal attack priorities recover all exits. Mishio's own
3158 state gates remain explicit rather than copied from another character.

Commands have frameC, receiver EBP-C, index EBP-4 and unsigned byte buttons /
stage at EBP-5/-6. Their1,541 instructions and249 branches implement16 ordered
scans over the180-entry history using single-wrap indexing. Command99 is the
default; command98's staged button sequence precedes the facing-dependent
motions. Preserve actual windows, sequential advancement, three >=1000 meter
gates and the distinction between gate-mask !=0 and positive command-ID sums.
The first complete source had the full5325-byte size but seven differing bytes;
three threshold pairs and one gate branch required original-instruction fixes.

Final formatted sources passed50 complete strict comparisons from23 serial
cold source/profile/dependency artifacts: ten new units and40 actual consumers
of CharacterViews.h. All515 refreshed generated-symbol identities across nine
old units retain reviewed destinations, local offsets or literal payloads
(513 local bindings and two strings). The other254 units retain earlier proofs.
Engine.h and Input.h remain unchanged. Focused tracking, ledger/progress CI and
whitespace checks passed; no full CI/cohort or runtime matrix ran.

Full attempts, read-only annotated decompiles, boundary/operand review and native
exit logs are retained in `.analysis/probes/mishio/`. Its one-time generation
scripts are derivation history and must not overwrite accepted/newer sources.

## Mishio CPU command and movement owner

Character15::Slot05 at 0x54C250 is complete strict exact in
`src/Character15Cpu.cpp`: 15,066 instruction bytes, exclusive end 0x54FD2A,
without local tables. Six following CC alignment bytes precede effect owner
0x54FD30 and are excluded. Public proof: `docs/evidence/mishio-cpu-exact.json`;
explicit recipe: character-15-cpu-input, pinned vc71-od-static.

Independent boundary review covers all 3,883 contiguous instructions and 722
internal branches. All 297 relocation fields have explicit reviewed symbols,
original destinations and typed evidence: 90 RandomRange calls, two CollisionSide
calls, one external fabs call and 204 floating operands. All 38 distinct literal
payloads agree independently between canonical target and native COFF. Every
RandomRange caller zero-extends AX. The fabs call preserves its real cdecl double
argument, caller cleanup and x87 return; the external implementation is ABI
evidence, without authored credit. There are no indirect calls or local tables.
The original virtual slot05 operand at 0x78877C points directly to this owner.

The entry defaults command99, decrements positive movement timers01a0/01a4,
clears directional/button output and resets014e. Three independent random
comparisons set014e to60; preserve 25.0f plus airborne30 scaling, the signed
integer mode3/400 and state170/300 terms, the hurt-state multiplier and the
original floating evaluation order. A provisional unsigned mode term added a
64-bit conversion and moved later spills. Signed inline ternaries recover the
original operations. CPU mode is the shared field3114; it is distinct from
Mishio's field3158 indicator/special state.

Ordinary used locals are one sixteen-byte forward/vertical distance record at
EBP-10/-8 and receiver EBP-14. The full natural frame is C0. Forward distance
evaluates opponent.x-self.x before facing multiplication; vertical distance is
fabs(self.y-opponent.y). Preserve the early opponent-state96 return, the positive
hurt-state owner before normal decisions and the grounded locomotion/guard exits.
Hurt-state inputX uses `1 - (RandomRange(0,100) < 50) * 2`; button3 is assigned
first from vertical and then forward distance, followed by the original cancel.
Both assignments are actual target behavior.

The positive special-command guard checks field0118>500 or field0120>0,
then the random8.0f gate, opponent state150..156 and self state250/251/252 or
270/271/272, assigning command52 and returning. Shared mode clearing and
mode4..12 priorities follow. State-specific command windows, meter gates and
random sample order remain explicit. Positive nested phase/random and distance
tails recover original jumps without inert locals. At 54E15D and 54E162, the
successful nested random path and its enclosing path each return to the epilogue;
retaining both source returns recovers the final five bytes. Merely merging the
exits produces15061 bytes and does not receive exact credit.

The airborne command40..42 window tests forward against vertical+40 and
vertical-40. Preserve subtraction from vertical before comparing forward;
algebraic reassociation changes the x87 operations. Positive movement timers
precede the final random movement owner. The original close/far facing-command
guards, thresholds and immediately returning branches are retained.

Final formatted public source passed one selected complete cold native replay
with all297 reviewed bindings and zero differing bytes. Public headers and all
304 existing recipes/source owners are unchanged, so no old unit required
replay. Focused tracking, ledger/progress CI and whitespace checks passed;
no full CI/cohort or runtime matrix ran. No native compiler/Wine failure occurred.
All decompile input, target review, source/object attempts and native exits are
retained in `.analysis/probes/mishio-cpu/`. One-time derivation scripts are
historical and must not overwrite accepted/newer sources.

Eleven of thirteen original Mishio virtual destinations now have exact proofs.
State530BC0 and effects54FD30 remain open, including unreviewed associated tables.
Linked resources/data, original TU partitioning, runtime and game remain open.

## Mishio animation and state owner

Character15::Slot06 at 0x530BC0 is complete strict exact in
`src/Character15State.cpp`: 87,313 instruction bytes plus 934 associated table
bytes, total contribution 88,247. Public proof: `docs/evidence/mishio-state-exact.json`;
explicit recipe: character-15-update-state, pinned vc71-od-static.

Code ends at 0x5460D1. The contiguous 154-destination address table occupies
0x5460D1..0x546338 (616 bytes); the 318-byte selector occupies
0x546339..0x546476 for animation IDs 1..318. Nine CC alignment bytes precede
accepted constructor546480 and are excluded. All 153 explicit state entries and
165 default selectors were checked directly; all destinations are instruction
starts. The original slot06 operand at788780 contains530BC0. A normal C++ switch
emits both complete tables; no original table bytes are copied into source.

Independent review covers 23,524 contiguous instructions, 2,363 direct internal
branches, one indirect switch and 418 virtual calls. All 1,612 relocation fields
have explicit reviewed symbols, original destinations and evidence: 516 direct
calls, 940 typed floating operands and 156 local table bindings. All 79 distinct
64-bit floating payloads agree independently in target and native COFF. All 12
RandomRange callers zero-extend AX. Relocation operands are compared without
masking, including every destination in the complete address table.

The used72-byte EffectSpawn is EBP-50, receiver EBP-54 and ordinary duration /
count locals EBP-4/-8. Natural source recovers the complete49C frame with saved
ESI and the five-byte epilogue. Promoted tick reads use unsigned short; byte
slide flags use explicit unsigned reads. Preserve real byte/word increments,
positive landing/collision branches, source operand order and actual immediate
thresholds rather than algebraically equivalent decompiler conditions.

Nineteen original calls to shared polar helper434010 add8 to the character
receiver, addressing the pose/velocity prefix beginning at field0008. The source
uses the existing reviewed SecondaryEffectSlot velocity view at that actual
address. The accepted callee accesses only vx/vy at prefix offsets28/30,
corresponding to character0030/0038; both arguments are real doubles and cleanup
is unchanged. No new ABI declaration or duplicate helper credit is introduced.
Original common class ownership and translation-unit partitioning remain open.

The physical slide branch decelerates only while horizontal velocity is positive
and the unsigned0158 flag equals1, otherwise clearing both. State178 retains
its inner completion break and outer dispatch break; merging these loses five
bytes. State212 takes the positive phase>1 hit exit before normal landing work.
State248's successful opponent grab exits directly, while its frame1 airborne
opponent predicate assigns016c positively. State249 tests frame>6 and negative
height before applying0.035 gravity; landing immediately resets to frame16.
States315..317 use their own frame>9 /0.02-gravity landing owners and direct exits.

State271 selects the opponent x coordinate inside the strict150/-150 range;
outside it, original opponent.x>self.x and opponent.x<self.x comparisons select
the two bounded positions. State272 retains its different range test and the
same physical operand order. Reversing relational operands changes x87 status
checks even where ordinary finite values appear equivalent.

States253/255/259..266 and306..310 retain direct dispatch exits for repeating
frame rollback. States300..302 first handle the positive phase3, airborne
opponent and frame<10 guard, resetting the opponent and exiting immediately.
Their frame10 repetition and failed-hit branches also exit directly. All original
meter costs, state3158 changes, descriptor values, action priority and repeated
emissions remain explicit. Integer particle coordinates subtract facing times
positive constants in the original order. Six decompiler &0xffff masks were
removed only after original MOVZX callers proved the actual unsigned return;
keeping those masks emits six extra AND instructions. Three register-result
comma assignments required explicit natural RandomRange expressions before
the first successful native source build.

The first complete successful native contribution had88,216 bytes; common
unsigned/branch restoration produced88,218, specific state control88,281, and
final byte reads/range ordering/random-mask corrections recovered all88,247.
All153 diagnostic cases align, followed by the unmodified complete strict
zero-difference comparison. Diagnostic case normalization alone has no acceptance
authority. Final formatting also received complete comparison and renewed operand
review before one selected final cold native replay.

Public headers and all305 previous recipes/source owners remain unchanged, so
no old native unit needed replay. Focused tracking, ledger/progress CI and
whitespace checks passed; no full CI/cohort or runtime matrix ran. The initial
provisional comma-assignment syntax failure was corrected, and required
verify-toolchain --execute smoke passed before subsequent native attempts.
All inputs, objects, compiler exits and independent reviews remain retained in
`.analysis/probes/mishio-state/`; its one-time derivation scripts must not overwrite
accepted/newer sources.

Twelve of thirteen original Mishio virtual destinations now have exact proofs.
Local effects54FD30/29568 instruction bytes remains open with associated tables
unreviewed. Its fresh annotated decompile is retained privately; it confers no
acceptance. Linked resources/data, original TU partitioning, runtime and game
reconstruction remain independently open.

## Mishio local effect dispatch and controls

Character15::Slot07 at 0x54FD30 is complete strict exact in
`src/Character15Effects.cpp`: 29,568 instruction bytes plus 308 associated table
bytes, total contribution 29,876. Public proof:
`docs/evidence/mishio-effects-exact.json`; explicit recipe:
character-15-update-local-effects, pinned vc71-od-static.

Code ends5570B0. The 52-destination address table occupies5570B0..55717F
(208 bytes), followed by the100-byte selector557180..5571E3 for effect types
400..499. Twelve CC alignment bytes precede next function5571F0 and are
excluded. All51 explicit types and49 default selectors were independently
checked; every destination is an instruction start. A normal C++ switch emits
both complete tables without original bytes in source. Original slot07 operand
788784 contains54FD30.

Complete review covers6,781 contiguous instructions,477 direct internal
branches, one indirect switch and79 virtual calls. All279 relocation fields
have explicit reviewed symbols, canonical destinations and evidence:95 direct
calls,130 typed floating operands and54 compiler-local bindings. All34 distinct
double payloads agree independently in target and native COFF. All20 RandomRange
callers zero-extend AX. The16 real rand calls retain original sample and
coefficient order; equal distributions would not establish exact codegen.

The freeze guard exits while the opponent's014c is positive. Otherwise, the
64-slot circular queue advances from effectRead to effectWrite, preserving
activity, palette and own-hit-stop gates. Each active slot reads its actual
pattern duration/count and resets one reused72-byte EffectSpawn. Natural locals
recover frame1C8, index EBP-4, receiver EBP-5C, descriptor EBP-50 and
frameDuration/frameCount EBP-54/-58, with saved EBX/ESI. The final epilogue is
six bytes. Shared helpers and public layout declarations remain unchanged.

Type400's positive hit/frame<49 branch resets frame49/tick0 and clears3148
before exiting the dispatch. Effects403..407 and412..416 retain original
character-state and frame6/26 cancellation guards. Type417 has two original
identical negative state/frame guards, each capable of writing its cancellation
state and directly exiting; do not collapse the duplicate source conditions.
The physical code order places type414 before413, despite numeric/decompiler
order. Reordering the source cases to that independently reviewed order preserves
VC7.1's original register allocation and complete table destinations.

Types422..428 and433/434 handle positive predicted-ground contact before normal
work. Their grounded flag/frame cancellation also exits directly; later rollback
and repeat counters retain their own original limits. Types437/438/444/445 use
the original invalid-state removal exit and x coordinate evaluation:
`double(int(field0020)) + (effects[i].vx + 20.0) * facing`.
The integer conversion precedes the effect velocity and orientation terms.
Type443 repeats only while3174[i]<10; exact immediates matter independently
of similar-looking branch shapes.

Type496 emits its original particle sequence when the character leaves the
specified83..86 states or advances past the frame1 guards for83/84. Integer
coordinates subtract positive facing products in the target order. Types497/498
retain all original rand draws, velocity coefficients, bounce conditions and
lifetime counters. Negative lifetime removal exits directly before normal tick
work. Fifteen original exits branch directly to queue advancement; routing via
a case-local final jump changes instruction operands despite equal function size.

The first complete native contribution had29,888 bytes; common word updates,
unsigned random returns and operand normalization produced29,857. Restored
positive cancellation/landing owners and original rand terms recovered the full
29,876 size. Canonical source case order and exact3174 thresholds then reduced
the raw mismatch to32 bytes. Unmodified complete comparison caught the remaining
direct-exit destinations and type443 immediate, which branch-normalized diagnostic
cases could conceal. Final source and both complete tables have zero differences;
formatting received another complete comparison and independent operand review.

One final selected cold native replay passed all29,876 bytes and279 reviewed
bindings. Public headers and all306 prior recipes/source owners remain unchanged,
so no old unit required replay. Focused tracking, ledger/progress CI and whitespace
checks passed; no full CI/cohort or runtime matrix ran. No native compiler/Wine
failure occurred in this effect checkpoint. All target evidence, source/object
attempts, compiler exits and independent reviews remain in
`.analysis/probes/mishio-effects/`; its one-time derivation scripts must not
be rerun over accepted/newer source.

All13 original Mishio vtable788768 destinations now have complete exact recipes,
including inherited LoadResources410B70. The constructor is additional to this
virtual-entry inventory. This closes only these entry-code proofs; linked
resources/data, original TU partitioning, runtime and game remain open.

## Misaki construction input and indicator owners

Ten complete authored functions add15,615 exact instruction bytes without local
tables. Sources: `src/Character07Frame.cpp`, `src/Character07Input.cpp` and
`src/Character07Commands.cpp`. Public proof: `docs/evidence/misaki-exact.json`.
Explicit recipes use pinned VC7.1 static /Od and complete strict comparison;
no masks, size overrides or partial-function credit are used.

| Complete owner | Canonical entry | Exact code bytes |
| --- | --- | ---: |
| Character07 constructor | 0x567900 | 390 |
| Character07::InitializeState | 0x567A90 | 270 |
| Character07::ResetPose | 0x567BA0 | 58 |
| Character07::RemoveLocalEffect | 0x567BE0 | 80 |
| Character07::Slot03 locomotion | 0x567C30 | 19 |
| Character07::Slot04 action input | 0x567C50 | 10,656 |
| Character07::Slot01 empty entry | 0x56A5F0 | 11 |
| Character07::Slot08 empty entry | 0x56A600 | 11 |
| Character07::EmitLocalEffect | 0x56A610 | 47 |
| Character07::Slot02 commands | 0x56A640 | 4,073 |

Canonical creation case7 allocates0x3448 and calls567900. The constructor
copies complete NUL-terminated literal "misaki" from788800 and installs
vtable788808. All13 canonical destinations were read directly. Nine child
virtuals above plus inherited LoadResources410B70 now have complete exact proofs.
CPU56B630/17127, state5571F0/66501 code and effects56F920/15562 code remain
open; associated table extents for the last two are unreviewed. Constructor
acceptance is additional to the virtual-entry inventory. Neither code inventory
nor source similarity establishes character/resource/runtime closure.

Independent complete boundary review covers4,100 contiguous instructions,
638 internal branches and every following padding/next-entry interval. All100
relocation fields have explicit reviewed original operands, symbols and
canonical destinations:49 direct calls,49 typed double operands, the constructor
resource string and vptr. All eight distinct floating payloads agree independently
in target and native COFF. There are no new local tables. Prior characters and
provisional decompiler output supplied hypotheses only.

Only Character07's opaque tail is expanded into four observed scalar ints at
3138..3144 and three64-int arrays at3148/3248/3348. The final array ends3448,
preserving actual allocation without padding. Constructor and initializer clear
those fields/arrays in the original order and use boxes(-13,-60),(14,0),
(17,-6),(7,-25),(27,-25). Constructor surfaceCount is474, commandCount is5,
and the four explicit command stores are1,11,18,7 at entries0..3. No extra
command-ID store is invented. InitializeState calls only the shared initializer.
Both creation consumers retain complete original allocation/call bytes.

ResetPose clears3138,313c,3140 before the base reset. RemoveLocalEffect clears
all three arrays at the actual short slot before the base removal. Locomotion
calls the accepted shared owner. EmitLocalEffect removes effectWrite through its
real virtual slot before the shared emitter. Slots01 and08 are actual empty
bodies: each has an ordinary receiver spill and RET,11 bytes including prologue/
epilogue. Their acceptance does not supply HUD or frame behavior absent in the
target.

Action input preserves unsigned latch/countdown reads, field01aa<=0, byte
increments/decrements and positive sequence permission masks. The first phase
gate is >1; later gates use >=2. Directional products evaluate opponent.x-self.x
before `1-field0262*2`, with multiplication by-1 for opposite facing. Positive
combined air guards and the original special/normal attack priorities retain
all exits. The normal second-button distance window is strict -70..70, while
the third-button grounded throw first checks opponent height then horizontal
input; its airborne special retains the original -100..100 range and state gates.
A first complete10702-byte source became10677 after common corrections, then
all10656 after target-backed arithmetic/branch/byte recovery.

Commands implement13 ordered scans over the180-entry circular history with
single-wrap indexing `i-(i>=180)*180`. Preserve each window and sequential stage
advance, facing-dependent IDs and the actual grounded floating guard. Gate-mask
!=0 and positive command-ID arithmetic emit distinct branches. The one1000-meter
threshold is >=1000. The first complete4073-byte source already had the full
size but four differing bytes: two gate jumps and one threshold pair required
original-instruction corrections. Equal size alone never conferred acceptance.

Full read-only annotations for all13 new bodies, target dumps, source/object
attempts, native exits and complete boundary/operand reviews are retained in
`.analysis/probes/misaki/`. One-time derivation scripts must not overwrite
accepted/newer source. Public Engine.h and Input.h remain unchanged.

Final formatted sources passed63 complete strict comparisons from29 serial cold
source/profile/dependency artifacts: ten new units and53 actual CharacterViews.h
consumers. All726 refreshed generated symbol identities across12 units retain
reviewed local offsets, destinations or literal payloads (723 local bindings,
three strings). The other254 existing units retain earlier artifacts. Focused
tracking, ledger/progress CI and whitespace checks passed; no full CI/cohort or
runtime matrix ran. No compiler/Wine failure occurred in this checkpoint.

## Misaki CPU command and movement owner

Character07::Slot05 at0x56B630 is complete strict exact in
`src/Character07Cpu.cpp`:17,127 instruction bytes, exclusive end56F917,
without associated local tables. Nine excluded CC alignment bytes precede
local-effect owner56F920. Public proof:`docs/evidence/misaki-cpu-exact.json`;
explicit recipe:character-07-cpu-input, pinned vc71-od-static.

Complete independent review covers4,399 contiguous instructions and809 internal
branches. All318 relocation fields have explicit reviewed symbols, actual
canonical destinations and evidence:108 RandomRange calls, two CollisionSide
calls, one external fabs call and207 typed floating operands. All39 distinct
literal payloads (nine floats,30 doubles) were freshly inventoried from this
canonical target and independently checked against native COFF. Every random
caller zero-extends AX. There are no indirect calls or local tables. Original
virtual slot05 operand78881C contains56B630.

The accepted Character23 CPU source provided a complete natural-source reuse
hypothesis. Changing only owner names/comments produced all17,127 exact bytes
on its first complete native build. Acceptance still required this Misaki
function's own boundary review, original relocation operands, typed literal
payloads, vptr operand, following padding and final selected cold comparison.
The relationship establishes shared instruction form and reviewed call/constant
bindings, not raw identical CALL displacement bytes at different addresses or
original translation-unit/class partitioning.

Used forward/vertical distance locals occupy EBP-10/-8 and receiver EBP-14;
the natural frame is FC. Preserve opponent.x-self.x before facing multiplication,
fabs vertical distance, actual random sample order, unsigned AX conversions,
positive hurt-state and action-selection priority, direct conditional-tail exits,
movement-timer priority and original integer constant-minus-boolean arithmetic.
The three independent guard/recovery comparisons, state-specific command windows,
meter checks and separate successful/outer exits remain explicit. The actual
late far-facing condition requires forward distance >800 and <120; the target
retains both comparisons, so do not simplify or repair their contradiction.
Shared CPU mode3114 and random selector3110 remain separate from Character07's
four child fields.

The external fabs call preserves the actual cdecl double argument, caller cleanup
and x87 return. Retained external callee bytes are ABI evidence only, without
new authored reconstruction credit. Existing real shared declarations remain
unchanged; no fake ABI or inert locals were introduced.

One final selected cold native replay passed all17,127 bytes and318 reviewed
bindings with zero differences. Public headers and all317 existing recipes /
source owners remain unchanged, so no old native unit needed replay. Focused
tracking, ledger/progress CI and whitespace checks passed; no full CI/cohort or
runtime matrix ran. No compiler/Wine failure occurred. Full annotations, target
review, source/object attempt and native exits remain retained in
`.analysis/probes/misaki-cpu/`; unused inherited derivation scripts are historical
templates and must not overwrite accepted/newer source.

Eleven of thirteen original Misaki virtual destinations now have complete exact
proofs, including inherited LoadResources. State5571F0 and effects56F920 remain
open with associated tables unreviewed. Resource/data/runtime/TU and game phases
remain independently open.

## Misaki animation and state owner

Character07::Slot06 at0x5571F0 is complete strict exact in
`src/Character07State.cpp`:66,501 instruction bytes followed by841 associated
table bytes, total67,342. Code ends exclusively at5675B5; the132-entry DWORD
address table occupies5675B5..5677C4 and the313-byte animation selector occupies
5677C5..5678FD. Two excluded CC bytes precede accepted constructor567900.
Original vtable788808 slot06 operand788820 contains5571F0. Public proof:
`docs/evidence/misaki-state-exact.json`; recipe:character-07-update-state,
pinned vc71-od-static.

Independent review covers18,119 contiguous instructions,1,658 internal direct
branches, the indirect dispatch and every original table destination. The
selector covers animation IDs1..313, with131 explicit cases and182 defaults.
Every destination starts an instruction; default entry131 reaches55729D.
All1,519 relocation fields have explicit reviewed symbols and canonical
destinations:432 direct calls,953 double operands and134 local bindings
(132 address entries plus the two selector/address dispatch operands).
All101 distinct64-bit literal payloads were freshly extracted from the target
and independently checked against native COFF. All eight RandomRange callers
zero-extend AX. Virtual calls comprise221 ResetPose calls and33 local emitters.

Natural C++ retains one real EffectSpawn descriptor at EBP-50, duration/count
at EBP-4/-8, receiver at EBP-54, saved ESI and frame414. Initial freeze guards,
unsigned frame ticks, signed facing, float operand order, positive action and
landing tails, and separate successful/outer exits remain explicit. The target
really compares promoted unsigned frame numbers against-1 twice in state164;
retain those guards despite their apparent redundancy. Its decompiler omitted
them. Preserve original particle arithmetic, random sample order and throwing
state transitions rather than simplifying equivalent expressions. Original
class/translation-unit provenance remains open.

The first complete native source was built early. Target-backed control and
expression refinements then yielded the full exact artifact; diagnostic case
normalization conferred no credit. After source formatting, the entire function
was rebuilt and compared again. One final selected cold native replay passed
all67,342 bytes and1,519 reviewed bindings with zero differences. Public headers,
all318 prior recipes and existing source owners are unchanged. Focused tracking,
ledger/progress CI and whitespace checks passed; no full CI/cohort or runtime
matrix ran. No compiler/Wine failure occurred. Retain all target evidence,
complete source/header/object attempts and bounded native exit logs in
`.analysis/probes/misaki-state/` and `.analysis/build/`. Inherited unused derivation
scripts are historical templates, not idempotent maintenance commands.

Twelve of thirteen Misaki virtual destinations now have complete exact proofs.
Effects56F920/15,562 instruction bytes remains open, with associated tables still
unreviewed. Resource/data/runtime/TU and game phases remain independently open.

## Misaki local effect dispatch and controls

Character07::Slot07 at0x56F920 is complete strict exact in
`src/Character07Effects.cpp`:15,562 instruction bytes plus224 associated table
bytes, total15,786; complete exclusive end5736CA. The31-entry DWORD address table
occupies5735EA..573665, followed by100 selector bytes573666..5736C9. Six excluded
CC bytes precede the next prologue5736D0. Vtable788808 slot07 operand788824
contains56F920. Public proof:`docs/evidence/misaki-effects-exact.json`;
recipe:character-07-update-local-effects, pinned vc71-od-static.

Independent review covers3,572 contiguous instructions,228 direct branches,
the full RET/data boundary and every compressed-switch destination. Effect
types400..499 select30 explicit cases and70 defaults. Default entry30 reaches
the shared next-effect tail5735C9. All193 relocation fields have reviewed symbols,
actual canonical destinations and evidence:69 direct calls,91 double operands
and33 local bindings (31 address entries and two dispatch operands). All26
distinct double payloads match freshly read canonical memory and native COFF.
Direct calls include42 __ftol2,16 CRT rand, nine RandomRange and the descriptor
constructor/reset. All nine RandomRange results zero-extend AX. Virtual calls
comprise36 removals and23 local emissions; these remain separate from direct
CALL relocation bindings.

Natural used locals retain frame19C, receiver EBP-5C, effect cursor EBP-4,
descriptor EBP-50, duration/count EBP-54/-58 and saved EBX/ESI. Keep the entry
opponent-freeze guard and per-slot own-freeze/activity checks separate. The ring
cursor wraps at64. Original lifecycle conversions, successful removal/restart
exits, unsigned frame/tick increments, signed facing particle subtraction and
float operand order remain explicit. CRT random multipliers must retain their
actual evaluation order; mathematical commutativity does not establish exact
codegen or random-draw correspondence. Existing field3148/3248 arrays and shared
effect-slot views suffice without public-header changes.

A complete source was compiled early, refined against original instructions,
then fully rebuilt and compared after formatting. One final selected cold replay
passed all15,786 bytes and193 reviewed bindings with zero differences. All319
prior recipes/source owners and public headers were audited unchanged. Focused
tracking, ledgers/progress CI and whitespace checks passed; no old replay, full
CI/cohort or runtime matrix ran. No compiler/Wine failure occurred. Full private
target/operand review, complete source/header/object attempts and native exits
remain in `.analysis/probes/misaki-effects/` and `.analysis/build/`. Unused inherited
derivation scripts are historical templates and must not overwrite accepted source.

All thirteen actual destinations of Misaki vtable788808 now map to complete exact
recipes, including inherited LoadResources. This closes the observed virtual-body
set, without claiming resource/linked-data, original TU, runtime or game closure.
Current authored totals:302 functions,801,974 instruction bytes and5,499 associated
table bytes;339 reviewed boundaries/origins and320 proof recipes.

## Mayu construction input and indicator owners

Ten complete Character05 owners add17,957 strict exact instruction bytes without
local tables: constructor5DDDF0/410, initializer5DDF90/270, reset5DE0A0/58,
removal5DE0E0/80, locomotion5DE130/19, input5DE150/12047, empty indicator/frame
slots5E1060/11 and5E1070/11, emitter5E1080/47, commands5E10B0/5004. Sources:
`src/Character05Frame.cpp`, `src/Character05Input.cpp` and
`src/Character05Commands.cpp`; pinned profile:vc71-od-static. Public proof:
`docs/evidence/mayu-exact.json`; explicit recipes:character-05-*.

Canonical creation ID5 allocates3448, calls5DDDF0, copies complete NUL-terminated
literal "mayu" from788A60 and installs vtable788A68. Both accepted creation
consumers retain their complete allocation/call bytes. Character05's opaque tail
is replaced only by four observed scalar ints3138/313C/3140/3144 and three64-int
arrays3148/3248/3348, ending naturally at3448. Public shared Engine/Input views
are unchanged. Constructor surfaceCount386 and commandCount5 follow actual stores.
Its explicit command entries are0/6/3, followed by commands[3]=2 and then4, and
commands[10]=5. Preserve both stores to commands[3] and the sparse later entry;
do not invent a corrected command list. Initialization restores real child
fields and calls the shared base; reset clears only the first three scalars.
Indicator/frame slots01/08 really are empty, and the emitter removes the current
write slot before forwarding to the shared emitter.

Independent review covers4,731 contiguous instructions,730 internal branches,
all complete RET boundaries, following padding/next prologues and all13 original
vtable destinations. All119 relocation fields have reviewed symbols and actual
canonical destinations:54 direct calls,63 typed double operands, one resource
string and one vptr. Eleven distinct64-bit double payloads and the complete
five-byte resource string match target and native COFF. There are48 indirect
virtual calls, separate from direct CALL bindings. Candidate inventory and fresh
read-only decompiler annotations remain private, without acceptance authority.

The eight complete frame/construction functions were exact on their first native
build. Input's first12,133-byte source was corrected from target evidence:
unsigned byte updates, original phase/meter thresholds, ordered distance and
direction products, air frame overrides and positive action/throw tails yield
all12,047 bytes. Commands preserve15 ordered circular-history scans, original
mask-gate versus positive-mask arithmetic, meter thresholds and facing-dependent
diagonal selection. Its first5,009-byte source yielded all5,004 exact bytes after
those operand/control corrections. Formatting changes received complete native
comparisons; no inert locals, fake ABI or original-byte wrappers were introduced.

The final selected cold comparison covers76 complete units from35 serial native
source/profile/dependency artifacts:ten new owners and66 actual CharacterViews.h
consumers. The other254 existing units retain earlier artifacts. Compiler-local
symbol identity changes are reviewed against identical canonical destinations,
actual local offsets and complete string payloads before strict comparison.
All selected units pass zero differences. Focused tracking, ledgers/progress CI
and whitespace checks pass; no full CI/cohort or runtime matrix ran. Preserve
private target/operand review, source/header/object attempts, Ghidra logs and
bounded native exits in `.analysis/probes/mayu/` and `.analysis/build/`.

Ten of thirteen Mayu virtual destinations now have complete exact proofs,
including inherited LoadResources. CPU5E2440/14310, state5C8580/87209 instruction
bytes and effects5E5C30/10512 instruction bytes remain open; their associated
table boundaries require independent review. Original class/TU provenance,
resource/linked-data, runtime and game phases remain independently open.

## Mayu CPU command and movement owner

Character05::Slot05 at0x5E2440 is complete strict exact in
`src/Character05Cpu.cpp`:14,310 instruction bytes, exclusive end5E5C26,
without local tables. Ten excluded CC bytes precede effects5E5C30.
Original vtable788A68 slot05 operand788A7C contains5E2440. Public proof:
`docs/evidence/mayu-cpu-exact.json`; recipe:character-05-cpu-input,
pinned vc71-od-static.

Independent review covers3,705 contiguous instructions,649 internal branches
and all275 relocation fields:100 RandomRange calls, two CollisionSide calls,
one external fabs and172 typed floating operands. All38 fresh literal payloads
(eight32-bit floats,30 doubles) match canonical memory and actual native COFF.
Every RandomRange result zero-extends AX. No indirect calls or tables occur.
The real used distance record occupies EBP-10/-8, receiver EBP-14 and frameCC.
The complete external fabs body at77842D..7784DD independently establishes
cdecl double input, caller cleanup, sign-bit handling, x87 return and RET0;
its bytes are ABI evidence only, without authored reconstruction credit.

The first complete14,466-byte native source was built early. Target-backed
entry/owner/tail refinements recover the full function. Preserve sample order,
unsigned conversions, float operand order, inlined real state predicates,
positive hurt/action exits and active movement-timer priority. The successful
near-facing owner performs its random guard before checking forward distance
<100; failure of that final distance test still exits this update. A single
remaining branch-destination byte exposed this distinction after all instruction
forms and extents matched. Keep that outer return explicit. No far-facing guard
from another character is inferred. Original class/TU provenance stays open.

Formatting received a complete native rebuild and strict comparison. One final
selected cold replay passes all14,310 bytes and275 reviewed bindings with zero
differences. Public headers and all330 prior recipes/source owners are unchanged;
no old replay is needed. Focused tracking, ledgers/progress CI and whitespace
checks pass; no full CI/cohort or runtime matrix ran. No compiler/Wine failure
occurred. Preserve all target/operand/ABI evidence and complete source/header /
object attempts with bounded native exits in `.analysis/probes/mayu-cpu/`.

Eleven of thirteen actual Mayu virtual destinations now have exact proofs.
State5C8580/87209 and effects5E5C30/10512 instruction bytes remain open, with
associated tables unreviewed. Resource/data/runtime/TU and game phases remain
independently open.

## Mayu local effect dispatch and controls

Character05::Slot07 at0x5E5C30 is complete strict exact in
`src/Character05Effects.cpp`:10,512 instruction bytes followed by168 local-table
bytes, total10,680; complete exclusive end5E85E8. The17-entry DWORD address table
occupies5E8540..5E8583 and100 selector bytes occupy5E8584..5E85E7. Eight excluded
CC bytes precede next prologue5E85F0. Vtable788A68 slot07 operand788A84 contains
5E5C30. Public proof:`docs/evidence/mayu-effects-exact.json`;
recipe:character-05-update-local-effects, pinned vc71-od-static.

Independent review covers2,374 contiguous instructions,146 direct branches,
the indirect dispatch, full RET/data boundary and every switch destination.
Effect types400..499 select16 explicit cases and84 defaults. Default entry16
reaches the shared next-effect tail5E851F. All144 relocation fields have explicit
reviewed symbols and actual canonical destinations:46 direct calls,79 double
operands and19 local bindings (17 address entries and two dispatch operands).
All36 fresh64-bit literal payloads match canonical memory and native COFF.
Direct calls comprise22 __ftol2,16 CRT rand, two ResetFrame, two ApplyDamage,
two Context emitters and descriptor construction/reset. Virtual calls comprise
12 removals,10 local emissions and two opponent ResetPose calls; they remain
separate from direct CALL relocation evidence. No RandomRange call occurs.

Natural used locals retain frame12C, receiver EBP-5C, ring cursor EBP-4,
descriptor EBP-50, duration/count EBP-54/-58 and saved EBX/ESI. Preserve the
separate entry opponent freeze and per-slot activity/own-freeze checks, cursor
wrap64, positive frame3/frame9 landing transitions and frame5 conversion exits.
The frame6 loop compares child counter3138<=730 directly. Original damage,
minimum-opponent-life clamp, effect conversion order and signed-facing coordinate
association remain explicit. Types408/409 really return from the complete update
after converting the slot, rather than continue the ring. CRT particle random
multiplier order follows target instructions. Existing child fields/shared views
suffice without public-header changes; original class/TU provenance stays open.

The first complete10,647-byte native source was built early. Target-backed word
updates, positive lifecycle exits, original threshold operands and arithmetic
order recover the full artifact. Formatting received a complete native rebuild /
strict comparison. One final selected cold replay passes all10,680 bytes and144
reviewed bindings with zero differences. Public headers and all331 prior recipes /
source owners remain unchanged; no old unit needs replay. Focused tracking,
ledgers/progress CI and whitespace checks pass; no full CI/cohort or runtime
matrix ran. No compiler/Wine failure occurred. Preserve all private evidence,
complete source/header/object attempts and bounded native exits in
`.analysis/probes/mayu-effects/` and `.analysis/build/`; unused inherited derivation
scripts must not overwrite accepted/newer source.

Twelve of thirteen actual Mayu virtual destinations now have exact proofs.
The substantial state owner5C8580/87,209 instruction bytes remains open, with
associated tables unreviewed; its complete fresh read-only annotation is retained.
Current authored totals:314 functions,844,753 instruction bytes and5,667 associated
table bytes;350 reviewed boundaries/origins and332 proof recipes. Resource/data /
runtime/TU and game phases remain independently open.


## Mayu animation and state owner

Character05::Slot06 at0x5C8580 is complete strict exact in
`src/Character05State.cpp`:87,209 instruction bytes followed by954 local-table
bytes, total88,163; complete exclusive end5DDDE3. Code ends5DDA29. The158-entry
DWORD address table occupies5DDA29..5DDCA0 and322 selector bytes occupy
5DDCA1..5DDDE2. Thirteen excluded CC bytes precede accepted constructor5DDDF0.
Vtable788A68 slot06 operand788A80 contains5C8580. Public proof:
`docs/evidence/mayu-state-exact.json`; recipe:character-05-update-state, pinned
vc71-od-static. The complete selector covers animation IDs1..322, with157 explicit
cases and165 default selections; address entry157 reaches default5C862C.

Independent original review covers24,252 contiguous instructions,2,361 direct
branches, the indirect dispatch, full RET/data boundary, all switch destinations
and following constructor/padding. All2,059 relocation fields have independently
checked symbols and actual canonical destinations:482 direct calls,1,417 double
operands and160 local bindings (158 address entries and two dispatch operands).
All135 fresh64-bit literal payloads match target memory and native COFF. Direct
calls comprise137 ResetFrame,111 __ftol2,79 FaceOpponent,49 Context emitters,
25 horizontal shakes,16 tints,13 CollisionSide,13 ApplyDamage,10 scene timers,
nine horizontal offsets,eight vertical shakes,seven trails,three RandomRange
and descriptor construction/reset. All three random results zero-extend AX.
The269 virtual calls comprise260 ResetPose and nine local emissions; these
remain separate from direct CALL relocation evidence.

Natural used locals retain frame0x448, receiver EBP-54, descriptor EBP-50 and
16-bit duration/count EBP-4/-8 without a saved ESI. Preserve positive landing,
action and throw exits, original frame thresholds and branch joins, integer
particle subtraction, opponent coordinate association, direction-expression
order and x87 comparisons. State307 tests frame equality9/15/20 for its three
landing transitions and compares child counter3138<=730 directly. State261's
frame6 repeat tests counter<4 before its terminating path. State303/304 and
308..310 retain the original signed-int lower bound before the frame<3 shake
range. The two WORD stores atF2 use the real existing opaque byte range through
a typed short reference; shared ABI/headers are unchanged. Original class/TU
provenance and field semantics remain separate from complete codegen evidence.

The first complete88,250-byte native source was built early. Target-backed
control flow, actual 16-bit updates, double operands and expression association
recover the full contribution. A broad private text rewrite accidentally changed
some hexadecimal !=0x... tests; direct original instruction review corrected
those draft errors before acceptance. Two native source errors were corrected,
each followed by the required successful verify-toolchain --execute smoke;
complete bounded logs and exit records remain private. No compiler/Wine failure
is outstanding. The read-only typed state decompile completed successfully but
still split double literals into DWORD stores; those hypotheses were checked
against fresh target operands rather than trusted as source declarations.

After final formatting, another complete native strict comparison passes.
One final selected cold replay passes all88,163 bytes and2,059 explicit reviewed
bindings with zero differences. Public headers and all332 prior recipes/source
owners remain unchanged; no old unit needs replay. Focused tracking,
ledgers/progress CI and whitespace checks pass. No full CI/cohort, runtime
matrix, REA or subagents ran. Preserve complete private evidence, source/header /
object attempts and native logs in `.analysis/probes/mayu-state/` and
`.analysis/build/`; derivation scripts are one-time records and must not overwrite
accepted/newer source.

All thirteen actual Mayu virtual destinations now have complete exact proofs,
including inherited LoadResources. This closes these code bodies only. Current
authored totals:315 functions,931,962 instruction bytes and6,621 associated table
bytes;351 reviewed boundaries/origins and333 proof recipes. Resource/data,
runtime, original TU partitioning, portability and game phases remain open.


## Makoto construction input and indicator owners

Ten complete Character03 owners add17,018 strict exact instruction bytes without
local tables:constructor5F6D90/393,initializer5F6F20/283,reset5F7040/58,
removal5F7080/80,locomotion5F70D0/19,input5F70F0/11312,empty slots01/08
at5F9D20/11 and5F9D30/11,emitter5F9D40/47,commands5F9D70/4804. Sources:
`src/Character03Frame.cpp`, `src/Character03Input.cpp`,
`src/Character03Commands.cpp`; profile:vc71-od-static; public proof:
`docs/evidence/makoto-exact.json`. These ten bodies were first built complete
before target-backed refinements; source formatting receives the selected final
cold complete comparison.

Both original creation paths select constructor5F6D90 for character ID3, push
allocation3450 at758849/76DB58 and CALL the constructor at758892/76DB95. The
constructor copies canonical "makoto\0" from788AC0 and installs13-entry table
788AC8. Only Character03's previously opaque body is expanded:five scalar ints
3138/313C/3140/3144/3148,three64-int arrays314C/324C/334C and the retained four
unmodeled bytes344C..344F. The complete allocation remains3450; no other class
layout or shared ABI is changed. Constructor/initializer clear all five scalars
and all three arrays. ResetPose clears only the first three scalars; removal
clears corresponding array entries. Preserve commandCount5 and the actual sparse
stores commands[0]=1,commands[1]=5,commands[10]=3; do not invent missing stores.

Independent complete boundary review covers4,478 contiguous instructions and
693 branches, every RET and following CC/next prologue interval. The already
reviewed393-byte constructor boundary is reused rather than counted again.
All105 relocation fields have reviewed canonical destinations:51 direct calls,
52 typed doubles,one string and one vptr. All nine64-bit literal payloads match
original target memory and actual native COFF. Input has40 ClearBufferedButtons,
four FaceOpponent and44 virtual ResetPose calls. Constructor/base entry owners
supply the remaining seven direct calls. Each original13-slot destination is
checked directly; resource loading remains the inherited accepted owner410B70.

Input preserves positive air/ground action guards, actual sequence/phase order,
byte updates and signed-facing direction/product association. Its three special
air frame adjustments set frame3. The heavy airborne normal first selects211,
then selects209 when inputY>0. Actual air/ground throw predicates retain opponent
position/state priority. Commands preserve15 ordered circular-history scans,
each original stage transition/window and directional expression form. Meter
guards compare>=1000 directly; original 0x80 branch tests remain !=0 while the
command ID sum retains positive-mask boolean arithmetic. Similarities with other
characters supplied hypotheses only; complete original bytes are the authority.

The final selected comparison covers89 units from41 serial cold native artifacts:
ten new bodies and79 actual CharacterViews.h consumers. The other254 units retain
their earlier proofs. Every compiler-generated local/string symbol rename is
checked against unchanged canonical destinations/local offsets and native string
bytes before accepting new receipts. Report:
`.analysis/exact/makoto-and-affected.json`; log:
`.analysis/build/makoto-formal-replay.log`. Focused target-required tracking,
ledgers/progress CI and whitespace checks pass; no full CI/cohort or runtime
matrix is needed. No native compiler/Wine failure, REA or subagents occurred.
Preserve all private source/header/object attempts, original disassembly,
read-only Ghidra annotations, complete boundary/operand reviews and logs in
`.analysis/probes/makoto/`. Derivation scripts are one-time records and must not
overwrite accepted/newer source.

At this 2026-11-07 checkpoint, ten of thirteen actual Makoto virtual
destinations had complete exact proofs, including inherited LoadResources.
Slot05 CPU, Slot06 state and Slot07 effects were then identified as the next
owners. Slot05 CPU and Slot07 effects have since been accepted strict exact in
the source sections below; Slot06 is the only remaining open Makoto virtual
owner. All thirteen fresh read-only annotations are retained and the Ghidra job
is terminal. Its state decompiler warning about 03020100 is provisional
analysis, not evidence of an accepted data dependency.
At that checkpoint authored totals were 325 functions, 948,980 instruction
bytes and 6,621 associated table bytes; 360 reviewed boundaries/origins and 343
proof recipes. Current repository totals are generated in docs/PROGRESS.md.
Resource/data, runtime, TU, portability and game phases remain independently
open.


## Makoto CPU command and movement owner

Character03::Slot05 at0x5FB040 is complete strict exact in
`src/Character03Cpu.cpp`:17,531 instruction bytes without local tables;
exclusive end5FF4BB. Five excluded CC bytes precede local-effect owner5FF4C0.
Original vtable788AC8 slot05 operand788ADC contains5FB040. Public proof:
`docs/evidence/makoto-cpu-exact.json`; recipe:character-03-cpu-input, pinned
vc71-od-static. Existing shared/member views suffice without header changes;
original TU/class provenance remains independently open.

Independent original review covers4,504 contiguous instructions,818 internal
branches, all returns and the complete next-entry/padding boundary. All329
relocations have independently checked symbols and canonical destinations:
122 RandomRange calls,two CollisionSide,one external fabs and204 typed floating
operands (26 DWORD floats and178 QWORD doubles). All39 fresh literal payloads
(seven floats,32 doubles) match canonical memory and actual native COFF. Random
returns zero-extend AX at120 calls and directly store low AL at two inputY
assignments. Full original177-byte external fabs implementation77842D..7784DD
is retained as ABI evidence only:cdecl double input,caller cleanup,x87 ST0 return,
RET0 and preserved classification/exception path; no extra authored credit.

Natural frameFC retains receiver EBP-14 and the used16-byte forward/vertical
distance record at EBP-10/-8 without saved ESI. Preserve the initial airborne
boolean before the random draw,25.0f factor and mode/state integer additions,
and the complete double-precision second decision product order. Later random
thresholds deliberately use different factor/coefficient orders in different
owners; blanket arithmetic rewrites are invalid. Four opponent-state-dependent
bounds retain positive constant-minus-condition products; state206 compares
counter3110 > 600 - (phase==3)*400. Two frame-normal distance>160 tails remain
positive guards. Opponent vertical velocity tests load the actual member first.

The entry mode/animation owner, special command52, close/far movement choices,
positive active timers and actual epilogue exits retain physical target order.
Special command52 checks states256,232-with-random-zero,257,238 in that order.
The far movement guard really tests distance>800 and distance<80; its contradictory
conditions are present in original instructions and must not be simplified away.
The two final timer random draws retain their separate conditions and original
nested facing/return joins. All of these are target facts rather than inferred
intent or another character's algorithm.

The first complete17,712-byte native draft was built early. Actual control flow,
scalar/constant order and integer subtraction recover the complete owner. One
private text rewrite initially matched the suffix of25.0f and caused a syntax
error; it was corrected and the required full verify-toolchain --execute smoke
passed. No compiler/Wine issue remains. After final formatting, another complete
native strict comparison passes. One final selected cold replay passes all17,531
bytes and329 reviewed bindings with zero differences. Public headers and all343
previous recipes/source owners remain unchanged; no old unit needs replay.
Focused target-required tracking,ledgers/progress CI and whitespace checks pass;
no full CI/cohort,runtime matrix,REA or subagents ran. Preserve all private
attempts,boundary/operand/random-return reviews,full fabs ABI and bounded build
logs in `.analysis/probes/makoto-cpu/` and `.analysis/build/`. Derivation scripts
remain one-time records and must not overwrite accepted/newer source.

At this post-CPU checkpoint, eleven of thirteen actual Makoto virtual
destinations had complete exact proofs. Slot07 local effects has since also
been accepted strict exact; Slot06 at 0x5E85F0 /58,482 code bytes plus 810 bytes
of reviewed tables (59,292 total) is the sole remaining open Makoto virtual
owner. Its fresh read-only annotations are retained in .analysis/probes/makoto/;
all Ghidra jobs are terminal. At this checkpoint authored totals were 326
functions, 966,511 instruction bytes and 6,621 associated table bytes; 361
reviewed boundaries/origins and 344 proof recipes. Current repository totals are
generated in docs/PROGRESS.md. Resource/data, runtime, TU, portability and game
phases remain independently open.


## Makoto local effect dispatch and controls

Character03::Slot07 at0x5FF4C0 is complete strict exact in
`src/Character03Effects.cpp`:33,673 instruction bytes plus224 local-table bytes,
total33,897; complete exclusive end607929. Code ends607849. The31-entry DWORD
address table occupies607849..6078C4 and100 selector bytes occupy6078C5..607928.
Seven excluded CC bytes precede next prologue607930. Vtable788AC8 slot07 operand
788AE4 contains5FF4C0. Public proof:`docs/evidence/makoto-effects-exact.json`;
recipe:character-03-update-local-effects, pinned vc71-od-static.

With Slot07 accepted, 12 of 13 actual Makoto virtual destinations now have
complete strict-exact proofs. Slot06 is the only remaining open virtual owner.

Independent review covers7,687 contiguous instructions,544 direct branches,
the indirect dispatch, full RET/data boundary and every canonical destination.
Types400..424 and495..499 supply30 explicit cases;70 selectors use default entry30,
shared next-effect tail607828. All308 relocation fields have independently
reviewed canonical destinations:73 direct calls,202 double operands and33 local
bindings (31 entries and two dispatch operands). All52 fresh64-bit payloads match
target memory and native COFF. Direct calls comprise42 __ftol2,16 CRT rand,nine
RandomRange,four Context emitters and descriptor construction/reset. Virtual
calls comprise88 removals and23 local emissions; they are distinct from CALL
relocation fields. Existing real headers suffice without layout/ABI changes.

Natural frame194 retains cursor EBP-4,receiver EBP-5C,descriptor EBP-50,duration /
count EBP-54/-58 and saved EBX/ESI. Preserve separate opponent freeze and per-slot
activity/own-freeze gates,ring wrap64,positive projectile landing/conversion
exits,and word-width frame/tick updates. Effects403..405 retain the original
opponent-state/position and own-state250..252 conversion priority. Effects406..408
retain the phase0 landing and shutdown transitions. Effects410..412 are three
coherent signed-direction wall-bounce owners. Vertical bounds are tested before
horizontal bounds; every successful bounce exits the current effect before
normal frame advancement. Their complete natural branches replace provisional
decompiler gotos while preserving exact original instructions.

Effects418..420 stop processing the current slot after inactive removal.
Effect421 removes on child counter>180. Effect422 multiplies own facing by1.5
before opponent facing. Effect423 negates its slot facing before positive
integer coordinate multipliers and preserves the actual random-call range.
Effect496 retains integer coordinate subtraction. Effects497/498 preserve each
CRT sample's original multiplier/order,the actual counter<10 group transition
and removal exits. Do not exchange independent random samples or rewrite these
expressions solely by mathematical equivalence.

The first complete33,862-byte native source was built early. A provisional
register rewrite initially produced an invalid assignment; the source and real
camera-bound fields were corrected and the required verify-toolchain --execute
smoke passed. A broad draft threshold replacement also altered <10; original
instruction review restored the exact predicate before acceptance. No compiler /
Wine issue remains. After final formatting, another complete strict comparison
passes. One final selected cold replay passes all33,897 bytes and308 reviewed
bindings with zero differences. Public headers and all344 previous recipes/source
owners remain unchanged; no old unit needs replay. Focused tracking,ledgers /
progress CI and whitespace checks pass. No full CI/cohort,runtime matrix,REA or
subagents ran. Complete private evidence and latest source/header/object snapshots
remain under `.analysis/probes/makoto-effects/`; historical trials are preserved
in the verified cleanup archive described in RE_ARTIFACTS.md. One-time derivation
scripts must not overwrite accepted/newer source.

Twelve of thirteen actual Makoto virtual destinations now have exact proofs.
State5E85F0/58,482 instruction bytes remains open,with associated tables still
unreviewed. Its fresh read-only annotation is retained. Current authored totals:
327 functions,1,000,184 instruction bytes and6,845 associated table bytes;
362 reviewed boundaries/origins and345 proof recipes. This codegen milestone
does not close resource/data,runtime,TU,portability or game phases.

## Cleanup and handoff on 2026-11-07 (historical checkpoint)

At that checkpoint the operator requested cleanup and stated that no further
owner should be started. This task-state statement is historical and was
superseded on 2026-11-08 by the request to prepare a handoff to another agent and
continue reconstruction. The final in-flight Makoto local-effect comparison
was completed and recorded at that earlier checkpoint.
README and AGENTS now reflect the current character coverage and task state.
Reader/audio integration was already accepted on2026-11-06; its workbench is an
archive,not an unfinished integration queue. Earlier contrary wording is
superseded by this clarification and the workbench's completed-integration notes.

The current handoff is condensed around live acceptance,tool state,parked work
and evidence paths. Historical checkpoint narratives remain here. Selected old
trial snapshots,retired diagnostic build directories and superseded aggregate
reports were preserved losslessly in a size/SHA-256-verified private archive
before redundant live copies were removed. Latest successful source/object
snapshots,current accepted objects/receipts,per-unit reports,the latest affected
header replay,and all parked Shiori/PrepareBattle work remain live. Original
target/toolchain/Wine/Ghidra state is preserved. Storage accounting and exact
restore commands are in `docs/RE_ARTIFACTS.md`; native logs remain available.

## Makoto state dispatch boundary and selector mapping

`Character03::Slot06` begins at `0x5E85F0`. The Character03 vtable at
`0x788AC8` has `ResetPose` at slot 0, `Slot01` through `Slot08` at slots 1
through 8, and the DWORD at slot-6 operand `0x788AE0` is exactly
`0x5E85F0`. This is an authored, non-thunk character state machine; the
`Character03` declaration and the neighboring accepted Character03 slot owners
confirm the class/slot interpretation.

The independently decoded code extent is `[0x5E85F0, 0x5F6A62)`: 58,482 bytes
ending with `RET` at `0x5F6A61`. The indirect dispatch at `0x5E8696` indexes a
125-entry DWORD jump table at `0x5F6A62` (500 bytes). Its destinations are all
unique instruction starts inside the code extent. The selector map begins at
`0x5F6C56` and contains 310 bytes for animation IDs 1 through 310. Its values
0 through 123 each occur exactly once; value 124 occurs 186 times and selects
the default path at `0x5E869D`. Thus there are 124 explicit animation cases and
186 defaulted IDs. Ghidra's normalized `case 0..124` values are dispatch-table
indices, not the original animation IDs; the exact animation-to-case mapping is
retained in `.analysis/probes/makoto/state-case-map.csv` and the full review in
`.analysis/probes/makoto/state-boundary-review.json`.

The selector map ends at `0x5F6D8C`. Four `CC` bytes follow, and the next
Character03 constructor begins at `0x5F6D90`. The complete owned code-plus-table
extent is therefore `[0x5E85F0, 0x5F6D8C)`, 59,292 bytes. The function boundary
and authored origin are now reviewed in the ledgers. The source reconstruction,
external/local relocation ownership, strict code-generation match, and runtime
validation remain open; this boundary review is not an exactness claim. The
Ghidra switch-normalization warning remains provisional and is not treated as a
source-level case map.

## VC7.1 x87 floating-to-integer helper

`0x007783B8` is a 117-byte compiler-generated VC7.1 floating-to-integer
support leaf, ending at `0x0077842D` (exclusive); `_fabs` begins immediately
at `0x0077842D`. Its input is already in x87 `ST(0)`, it uses `FISTP`/`FILD`
and an x87 fractional-correction sequence, returns the 64-bit integer in
`EDX:EAX`, and makes no calls. The Ghidra `FUN_007783b8(void)` signature is
therefore incomplete: the value is passed through the x87 stack, not ordinary
arguments. `Character03::Slot06` contains 178 direct calls to this helper.

Do not reconstruct this as a game-authored C++ leaf or call it explicitly from
source. Write the original floating-point expression and its natural integer
conversion; VC7.1 should emit the helper as a compiler-support dependency. Its
boundary and compiler-generated origin are now reviewed, but this does not
close the Makoto state function's code-generation or relocation proof.
