# EFZ knowledge base

Only conclusions supported by the locked EFZ input belong here. Compiler and
engine similarities with other games are hypotheses until compared with EFZ.

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
An original 865-byte rendering candidate at `0x40A440` was also inspected:
its inner loops explicitly manipulate AH/AL and push/pop ESI/EDI within branch
bodies. A faithful natural-C++ exact strategy remains open. The 14,114-byte
`0x401C20` state dispatcher was subsequently accepted as described below;
the rendering inspection independently confers no source or exact credit.

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
callees at `0x409A90` / `0x40A0B0` remain explicit external bindings; their
implementations and complete rendering runtime are still open.

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

The original DrawSurface/DrawBlendedSurface bodies at 0x409A90/0x40A0B0 were
inspected completely (799/897 bytes through their RET 0x2C/0x30). Their pixel
branches also contain body-local ESI/EDI push/pop pairs and direct AH/AL loops,
consistent with handwritten assembly. The earlier 865-byte 0x40A440 rendering
candidate is not an isolated case. No permitted natural-C++ exact strategy is
proven for these kernels; retain them open instead of accepting only their
clipping/COM prefixes or introducing assembly wrappers. Private evidence is
.analysis/probes/draw-00409a90-review.txt/draw-0040a0b0-review.txt and the local
Ghidra decompile-00409a90.txt. The blended body's last argument is loaded as a
signed byte before accepting modes 0/1; existing external names/types remain
provisional until complete owner and caller review.

Timer thread 0x401850 has a 157-byte complete body. It writes three zero locals,
updates lastTick at 0x790100, waits on tickEvent 0x79013C with the byte at
0x78F040 as timeout, and signals frameEvent 0x790140. Every elapsed second it
increments that byte only when the signed count exceeds 64, resets the count
and samples time again. Two initialized locals have no later reads in this
body. It remains unimplemented; do not add inert source merely to force its
frame. Complete original disassembly is timing-00401850-review.txt. These
follow-up observations confer no exact credit or automatic ledger changes.
