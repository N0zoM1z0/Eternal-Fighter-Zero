# EFZ knowledge base

Only conclusions supported by the locked EFZ input belong here. Compiler and
engine similarities with other games are hypotheses until compared with EFZ.

Use [PROGRESS.md](PROGRESS.md) and the ledgers for current acceptance, and
[RE_HANDOFF.md](RE_HANDOFF.md) for active blockers. Compiler observations below
apply to the pinned VC7.1 RTM 13.10.3077 and canonical EFZ target unless stated
otherwise. Historical comparisons record their original inputs; obtain current
exactness by rebuilding and comparing the selected unit. Disposable generated
files are not required to use these findings. Older sections record historical
intermediate candidate sizes and superseded progress counts; use the generated
progress report, active handoff and selected native receipts for current status.

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

`scripts/inspect-target.py` exports imports, Rich records and CodeView metadata
using standard-library PE parsing.

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

Public comparison: [configuration](evidence/config-exact.json).

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

Public comparison: `docs/evidence/startup-exact.json`.

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

Public comparison: `docs/evidence/context-exact.json`.

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

Public comparison: `docs/evidence/activation-exact.json`.

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

Public comparison: `docs/evidence/surface-exact.json`. The rectangle factory
has no relocations; raw/packed bodies have ten/two. Error data bindings are
`0x7877D4` and `0x787824`.

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

<a id="character-surface-rendering-kernels"></a>

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

## Raw file reader and audio loading

Reader and Audio integration is complete; accepted code lives in `src/`.

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
memcpy binding to `0x778410` was incorrect. The source corrections are described below.

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

Reader uses `/Od /G6 /MT /Gy /GS /W3`; Context uses `/Od /G6 /MT /Gy /W3`.
Public comparisons are `docs/evidence/reader-exact.json` and `context-exact.json`.

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

AudioResources uses `/Od /G6 /MT /Gy /GS /W3`; AudioGlobal uses the profile
without `/GS`. Public comparisons: `audio-exact.json` and `audio-global-exact.json`.

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

Input.h is shared through Engine.h and is an explicit transitive recipe
dependency. InputResources/InputGlobal depend directly on Input.h. The original
Input constructor is at `0x40C5E0`, established from global initialization;
`0x40C610` is an interior address. Input uses `/Od /G6 /MT /Gy /W3`.

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
operands compare exactly. Public comparison: `docs/evidence/frame-thread-exact.json`.

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
renaming the same-scope buffers did not fix it. The
four adjacent functions' first complete source was exact except for three
keyboard branches: explicit > 0 recovered the original signed TEST/JLE shape
following unsigned byte promotion. No byte wrappers, padding or partial claims
were used. Every involved unit was compared after the final source/header edits.

The subsequent render review at 0x755500 covers its complete 12,720-byte
contiguous contribution independently. The provisional Ghidra body lists only
12,231 addresses: omitted intervals 0x757946..0x75794F and 0x75795F..0x757B3F
contain normal loop instructions in the target, not accepted gaps or table
padding. Do not copy that incomplete body extent into a comparison recipe.
The character-loading owner at `0x7586B0` dispatches 24 allocation paths to 23 constructor destinations; arbitrary opaque constructor/size guesses are not
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
[character-create-exact.json](evidence/nagamori-affected-consumers-exact.json). The first
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

### Kaori constructor: complete exact native code generation (2026-11-09)

The selection-ID 13 constructor `Character13::Character13` at `0x00638D90`
now has a complete natural C++ implementation in
`src/Character13Frame.cpp`. Its selected VC7.1 `character-13-constructor`
comparison matches **383/383 bytes** with zero differences and all four
reviewed relocations: Secondary construction at `0x0040EAE0`, the
13-slot child vtable at `0x00788BF8`, the original `kaori` string at
`0x00788BF0`, and CRT `strcpy` at `0x00778080`. The code initializes
surfaceCount=430, five child state integers, five pairs of collision
parameters, two command slots and three 64-int scratch arrays. The
class view retains the original total size `0x3450` with four unknown
trailing bytes. None of the unknown fields were fabricated as initialized.

Two direct construction consumers, `Scene1::LoadCharacter` at `0x007586B0`
and `Scene2::LoadCharacter` at `0x0076DA20`, were rebuilt and compared
individually against their complete **3,495-byte/97-relocation** and
**2,651-byte/76-relocation** target contributions, including their
96- and 100-byte switch tables. Both are still Exact with zero
differences. The new Character13 view shifted compiler-local switch-label
numbers by seven; the 25 and 26 changed symbols were rebound only after
checking identical relocation offsets, internal target destinations and
complete target bytes. The new public receipts are
`docs/evidence/kaori-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`. Existing historical
certificates were left unchanged; unrelated `CharacterViews.h` users still
have earlier stale dependency metadata and were not cold-replayed.

### Kaori Character13 lifecycle and virtual delegates

The original `Character13` Kaori vtable at `0x00788BF8` and canonical
complete function boundaries identify **seven additional authored Exact
owners** with ordinary C++ in `src/Character13Lifecycle.cpp`. Pinned
VC7.1 `/Od /G6 /MT /Gy /W3` selected strict comparisons reproduced
**509/509 original machine-code bytes**, five independently bound
nonlocal call relocations, and **zero byte differences**:

| Kaori owner | Target | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x00638F10` | 283 |
| ResetPose | `0x00639030` | 58 |
| RemoveLocalEffect | `0x00639070` | 80 |
| Slot03 | `0x006390C0` | 19 |
| Slot01 | `0x0063B610` | 11 |
| Slot08 | `0x0063B620` | 11 |
| EmitLocalEffect | `0x0063B630` | 47 |

Original initializer zeroes five character integers, writes all ten
collision offset shorts, clears each of three 64-int arrays, and invokes
`Secondary::InitializeState` (`0x0040EDF0`). The reset clears just
three child integers before `Secondary::ResetPose` (`0x0040F110`).
Effect removal clears three arrays indexed by signed `short` before
`Secondary::RemoveLocalEffect` (`0x00412E60`); emission calls its
virtual removal on `effectWrite`, then the base emitter (`0x00412B10`).
Slot03 delegates to `UpdateLocomotionState` (`0x0040E740`); Slot01 and
Slot08 are authentic empty member overrides with 11 bytes each.

All seven original vtable entries, complete function extents, nonlocal
call operands and return instructions were reviewed before registering
Exact. Source uses the accepted Character13 class layout without
changing any shared header or accepted other owners. The public strict
selected receipts are `docs/evidence/character-13-lifecycle-exact.json`.
These seven codegen results do not demonstrate full game linkage,
runtime or portability.

### MizukaB constructor: complete exact native code generation (2026-11-09)

The reviewed selection-ID 18 constructor `Character18::Character18` at
`0x004D2850` now has authored natural source in `src/Character18Frame.cpp`.
The selected `character-18-constructor` unit rebuilt under VC7.1
`/Od /G6 /MT /Gy /W3` and matched **396/396 original bytes** with zero
code differences and all **four** checked relocations: Secondary base
constructor `0x40EAE0`, child vtable `0x7884F0`, `mizukaB` resource
literal `0x7884E8`, and CRT `strcpy` `0x778080`. Source initializes
surfaceCount=851, four child state integers, two collision coordinate
pairs, six trailing state integers, four command IDs, and three sets
of 64 scratch slots. The class remains exactly the observed 0x3460
allocation size, without speculative writes to unknown fields.

Both original direct construction consumers were selectively rebuilt:
`Scene1::LoadCharacter` at `0x007586B0` still matches its complete
3,495-byte function plus switch table with **97/97** bound relocations,
and `Scene2::LoadCharacter` at `0x0076DA20` still matches its 2,651
bytes with **76/76** relocations. The modified class view shifts
compiler-local switch labels by +11; the 25 and 26 changed labels
were mapped by unchanged relocation offsets and original target
jump destinations before independently comparing *all* caller bytes.
Proof: `docs/evidence/mizukab-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`.
Unrelated `CharacterViews.h` dependents still have historical proof
freshness issues, not re-certified by this targeted check.

### MizukaB Character18 lifecycle and Slot08: seven exact native functions

Original `Character18` vtable at `0x007884F0` identifies seven newly
recovered complete ordinary C++ owners in `src/Character18Lifecycle.cpp`.
The selected strict original-bound VC7.1 `/Od /G6 /MT /Gy /W3` replay
reproduces **670/670 canonical code bytes**, **eight independently
bound COFF relocations**, and **zero differences**, including all
three IEEE-754 literal operands in the nontrivial Slot08.

| MizukaB owner | Original address | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x004D29E0` | 276 |
| ResetPose | `0x004D2B00` | 58 |
| RemoveLocalEffect | `0x004D2B40` | 80 |
| Slot03 | `0x004D2B90` | 19 |
| Slot01 | `0x004D59D0` | 11 |
| Slot08 | `0x004D59E0` | 179 |
| EmitLocalEffect | `0x004D5AA0` | 47 |

InitializeState writes four character integers, two collision offset
pairs and six trailing state fields, clears three 64-int arrays, then
calls `Secondary::InitializeState` at `0x40EDF0`. ResetPose clears
three child integers before calling base `ResetPose` at `0x40F110`.
RemoveLocalEffect clears the signed-short index in all three child
arrays before base `RemoveLocalEffect` at `0x412E60`. Slot03 delegates
to `Secondary::UpdateLocomotionState` (`0x40E740`), Slot01 is genuinely
empty, and EmitLocalEffect calls virtual RemoveLocalEffect on
`effectWrite` before the base emitter at `0x412B10`.

Slot08 is a **real 179-byte state/resource timer**, not an empty leaf.
When `field3458 > 0`, it increments `field345c`; on a positive count
it subtracts 1.0 from `field0118` and resets `field345c`.
It then clears `field3458` when `field0118 <= 0.0`, or a two-test
state condition `field0008 < 49 && field0008 < 150`, or
`positionY == 0.0`. Preserving one shared assignment, rather than
three separate C++ assignments, exactly recovered the original 179
code bytes and its x87 compare/branch structure. The three original
literal bindings are `1.0` at `0x7875C0` and `0.0` twice at
`0x7872F8`. All original owner addresses were independently read
from vtable entries before Exact registration.

Proof: `docs/evidence/character-18-lifecycle-exact.json`. Selected
complete-function Exact still does not assert whole-game linkage or
runtime equivalence; no unrelated sources or shared headers changed.


### Kanna Character19 lifecycle: six complete Exact native functions

Original `Character19` vtable at `0x00788CE0` identifies six new
complete natural C++ functions in `src/Character19Lifecycle.cpp`.
Pinned VC7.1 `/Od /G6 /MT /Gy /W3` strict selected replay matched
**490/490 native code bytes**, **four independently bound original
call relocations**, and **zero differences**:

| Owner | Native address | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x00675E20` | 283 |
| ResetPose | `0x00675F40` | 58 |
| RemoveLocalEffect | `0x00675F80` | 80 |
| Slot01 | `0x00677E10` | 11 |
| Slot08 | `0x00677E20` | 11 |
| EmitLocalEffect | `0x00677E30` | 47 |

InitializeState resets five character fields (including field3148=60),
sets all ten collision-offset shorts, zeroes each of three 64-int
arrays and calls reviewed `Secondary::InitializeState` at `0x40EDF0`.
ResetPose clears three child integers then calls `0x40F110`.
RemoveLocalEffect zeros the signed-short index in three child arrays
and invokes base `0x412E60`. Slot01/Slot08 are authentically empty;
EmitLocalEffect calls virtual RemoveLocalEffect on `effectWrite` then
base EmitLocalEffect at `0x412B10`. Full original owner boundaries,
original vtable addresses and four call operands were checked before
registering these as Exact. Proof:
`docs/evidence/character-19-lifecycle-exact.json`. No shared header
or other accepted source was altered. Full game linkage, runtime and
portability remain open.

### Kanna constructor: complete exact native code generation (2026-11-09)

The authored selection-ID 19 constructor `Character19::Character19` at
`0x00675C80` is now natural C++ in `src/Character19Frame.cpp`, accepted
via `character-19-constructor`: **403/403 original code bytes**, zero
mismatches, **four reviewed relocations**. Original ELF/PE evidence was
independently confirmed using the canonical EFZ.exe: Secondary base
constructor at `0x40EAE0`, child vptr at `0x788CE0` (13 slots), exact
`kanna` NUL literal at `0x788CD8`, and CRT `strcpy` at `0x778080`.
The class view retains the reviewed **0x3458** allocation and makes
five child state integers (last = 60), five pairs of collision
coordinates, four command IDs and three 64-int scratch arrays visible.
Eight bytes at +0x314C and four trailing bytes at +0x3454 remain
unknown and uninitialized rather than being invented.

The only two original constructor callers were rebuilt with the new
class view. The 3,495-byte `Scene1::LoadCharacter` and 2,651-byte
`Scene2::LoadCharacter` remain **fully Exact** (97/97 and 76/76
relocations) including complete switch-table ownership. Compiler-local
label numbers shifted by **+8** for 25/26 operands; symbols were
rebound simultaneously by their *unchanged offsets and original target
destinations*, avoiding text-substitution cascades, then all bytes
were strictly compared. New public proofs:
`docs/evidence/kanna-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`.
The unrelated historical stale-header certificates were not
silently refreshed, and no full cold replay was run.

### NayukiB Character17 lifecycle and special timer: six complete Exact owners

Canonical `Character17` vtable `0x00788FB8` identifies six original
full native owners, now authored in `src/Character17Lifecycle.cpp`.
The pinned VC7.1 `/Od /G6 /MT /Gy /W3` **selected-only strict native
replay proves 767/767 original bytes, five bound original calls and
zero differences**, including the full nontrivial timer Slot08:

| NayukiB method | Native address | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x0073E970` | 322 |
| ResetPose | `0x0073EAC0` | 58 |
| RemoveLocalEffect | `0x0073EB00` | 80 |
| Slot03 | `0x0073EB50` | 19 |
| Slot08 | `0x00741AC0` | 241 |
| EmitLocalEffect | `0x00741BC0` | 47 |

InitializeState zeros eight character-specific ints, sets five
native X/Y collision pairs, clears three 64-int effect arrays, then
calls reviewed `Secondary::InitializeState` at `0x40EDF0`.
ResetPose zeros three child ints and delegates to `0x40F110`;
RemoveLocalEffect zeroes all three indexed arrays and calls base
`0x412E60`. Slot03 calls `Secondary::UpdateLocomotionState` at
`0x40E740`; EmitLocalEffect first invokes virtual removal for
`effectWrite` then base `0x412B10`.

**Slot08 is a complete 241-byte resource/timer handler, not an empty
leaf**. It clears `field3150` and `field314c` when its countdown is
nonpositive, either fighter is no longer alive, or the animation
is within state IDs 50–149. If the countdown remains positive, it
adds `field3154` to `field3148`, wraps values above359 by subtracting
360, and decreases `field3150` by2 before clearing both state fields
on expiry. The **50–149 branch is original and deliberately opposite
to an initially plausible outside-range hypothesis**; two branch
displacements differ until fixed. No relocations exist in Slot08.

Evidence: `docs/evidence/character-17-lifecycle-exact.json`.
All six original vtable pointers and complete function extents are
independently checked; this is original-bound codegen Exact, not
whole-game linkage/runtime equivalence.

### NayukiB constructor: complete exact code generation (2026-11-09)

`Character17::Character17` at `0x0073E790` is now a natural C++ source
owner (`src/Character17Frame.cpp`) matching **472/472 bytes** with
**4/4 reviewed original relocations** under VC7.1. The four bindings
are the reviewed Secondary base constructor at `0x40EAE0`, the
13-slot child vtable at `0x788FB8`, original `nayukiB` NUL literal
at `0x788FB0`, and CRT `strcpy` at `0x778080`. The 0x3458 view
contains eight explicit initial state integers and three 64-int
scratch arrays. The remaining child defaults are five pairs of
collision coordinates, seven command bytes, and surfaceCount=641.
The original command byte sequence belongs to **commands[0..6]**;
initially assigning some of them at [10..13] produced seven literal
code-byte differences despite the correct overall function length.
Correcting their offsets produced an exact complete comparison.

Both actual constructor consumers were selectively rebuilt and still
exact: `scene-create-character` has **3495/3495** bytes with **97**
relocations and `scene-loading-character` has **2651/2651** with
**76** relocations, including owned local tables. Compiler-local
label numbers shifted +9; all 25/26 changed symbols were rebound
simultaneously at the same relocation positions to the exact original
jump destinations before complete byte checks. Canonical evidence:
`docs/evidence/nayukib-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`. These focused
checks neither refresh unrelated stale certificates nor imply full
linked/runtime equivalence; no full cold replay was run.

### Kano Slot06 partial original-bound state reconstruction

Original Kano `Character20::Slot06` vtable `0x00788C90` selects
`[0x006429C0,0x006536B5)` (**68,853 native code bytes**) plus
137 four-byte switch entries and 316 selector bytes (136 live,
180 default). Natural source `workbench/kano-state/Character20State.cpp`
now matches `[0x006429C0,0x0064C750)` = **40,336 original bytes /
11,096 x86 instructions**, selected SHA-256
`c919786c0a1cb38c73818936db0dd297c6f02574021224c7a636f59ad7b31f75`.
Default plus **102 reviewed native live cases** through249.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected checker validates all
**11,096 original instruction offsets/widths/forms**, **1,032
internal / 136 outbound native branch targets**, **906 original-
bound COFF call/float refs** and two switch table operands. The
candidate stack0x148 differs from full canonical0x4A4 but uses the
same six-byte instruction width. Selected prefix ONLY, NOT Exact.

State249 (822 bytes) now implements Kano's actual complex aerial
throw: early screen offset/shake, opponent facing inversion,
frame2/3/4 positional tracking and action state changes, frame5
`ApplyDamage(1200,500.0)` and opponent X/Y knockback (-1.0,-2.3),
strict landing >0 and frame12 gravity0.035. The original animations
and relative/float/direct call operands are native-reviewed.
**Next state250 begins at `0x0064C750`**. Remaining 34 original
case bodies, full stack/switch tables/shared return open.
No cold full replay or credit for neutral probe markers.

### Kano Character20 lifecycle and local effect management: five Exact owners

The canonical `Character20` vtable at `0x00788C78` selects five
new original-owner complete implementations in
`src/Character20Lifecycle.cpp`. The pinned VC7.1
`/Od /G6 /MT /Gy /W3` selected original-bound strict oracle matched
**617/617 complete native bytes**, with **five original REL32 base
calls** and **zero differences**:

| Kano owner | Original address | Exact code bytes |
| --- | --- | ---: |
| InitializeState | `0x00653C30` | 413 |
| ResetPose | `0x00653DD0` | 58 |
| RemoveLocalEffect | `0x00653E10` | 80 |
| Slot03 | `0x00653E60` | 19 |
| EmitLocalEffect | `0x00657E70` | 47 |

InitializeState resets fifteen child integer fields at offsets
`0x3138..0x3170`, writes the five original X/Y collision offsets
(-4,-57), (18,0), (21,-12), (18,-15), (38,-39), zeros three
64-int local-effect arrays `field3174`/`field3274`/`field3374`, and
calls `Secondary::InitializeState` at `0x40EDF0`. ResetPose clears
three child integers then calls `Secondary::ResetPose` (`0x40F110`).
RemoveLocalEffect clears the signed-short index in all three child
arrays before base `RemoveLocalEffect` (`0x412E60`). Slot03 delegates
to `Secondary::UpdateLocomotionState` (`0x40E740`). EmitLocalEffect
calls virtual RemoveLocalEffect on `effectWrite`, then the base
emitter at `0x412B10`. Canonical vtable slots, the five complete
owner boundaries and every direct call destination were checked.

Evidence: `docs/evidence/character-20-lifecycle-exact.json`.
Selected codegen Exact does not establish whole-game linkage,
original compilation partition or runtime equivalence.

### Kano constructor: complete exact code generation (2026-11-09)

`Character20::Character20` at `0x00653A20` now has a reviewed natural
source implementation `src/Character20Frame.cpp`. The entire original
**523-byte** function matches the native VC7.1 result byte-for-byte
with **four** original-bound relocations: Secondary constructor at
`0x40EAE0`, Kano vtable at `0x788C78`, `kano` NUL literal at
`0x788C70`, and CRT strcpy at `0x778080`. Its 0x3478-byte class
view exposes fifteen initially zero state integers, three 64-int
scratch arrays, exact collision offsets and three command bytes,
retaining the four uninitialized trailing bytes rather than
inventing fields. This is a full constructor, not an unverified stub.

The two actual direct callers were rebuilt selectively and remain
**3495/3495 Exact with 97 relocations** (`scene-create-character`)
and **2651/2651 Exact with 76 relocations**
(`scene-loading-character`), including their owned jump tables.
A changed shared header renumbered 25/26 compiler-local labels by +17.
Their unchanged original target offsets and exact relocation positions
were verified before simultaneous symbol mapping, then the complete
caller bytes were compared independently. Public evidence:
`docs/evidence/kano-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`. Unrelated
stale-header certificates and whole-image/runtime checks remain open.

### Akiko Character16 lifecycle and effects: five complete Exact owners

The canonical Akiko Character16 vtable at `0x00788F58` independently
identifies five complete original functions in
`src/Character16Lifecycle.cpp`. Pinned VC7.1 `/Od /G6 /MT /Gy /W3`
selected-only original-bound replay matches **565 / 565 complete
native code bytes**, **five independent original REL32 call
relocations**, zero differences:

| Character16 method | Original address | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x00721BA0` | 361 |
| ResetPose | `0x00721D10` | 58 |
| RemoveLocalEffect | `0x00721D50` | 80 |
| Slot03 | `0x00721DA0` | 19 |
| EmitLocalEffect | `0x00725BD0` | 47 |

The nontrivial 361-byte InitializeState clears eleven Akiko-specific
integer fields, restores five original X/Y collision offset pairs
(-6,-72), (-22,0), (12,-14), (22,-19), (27,-41), zeros each of
three 64-element effect arrays and calls reviewed base
`Secondary::InitializeState` at 0x40EDF0. ResetPose and
RemoveLocalEffect maintain the original three-field/three-array
zeroing order before their base calls at 0x40F110 and 0x412E60.
Slot03 delegates to `Secondary::UpdateLocomotionState` (0x40E740),
and EmitLocalEffect first invokes virtual RemoveLocalEffect then
base emitter at 0x412B10. All five original vtable pointers and
entire owner boundaries were verified independently of compiler
output before recording Exact. Proof:
`docs/evidence/character-16-lifecycle-exact.json`.
Codegen Exact does not establish full product linkage or runtime.

### Akiko constructor: complete exact native proof (2026-11-09)

`Character16::Character16` at `0x007219A0` now has authored natural
C++ source in `src/Character16Frame.cpp` and a complete selected
`character-16-constructor` match under VC7.1. All **511 original
bytes** and four reviewed relocations are exact: Secondary base
constructor `0x40EAE0`, Akiko child vtable `0x788F58`, original
`akiko` string `0x788F50`, and CRT `strcpy` `0x778080`.
Its 0x3468 view exposes eleven zero-initialized state integers,
three arrays of 64 slots, five collision pairs, seven explicit
command bytes and four deliberately unwritten unknown trailing bytes.
The command byte placements were independently compared against the
target, not inferred merely from other characters' layouts.

Both direct creation callers were rebuilt selectively: the full
`scene-create-character` owned contribution remains **3495/3495
Exact with 97 relocations**, and `scene-loading-character` remains
**2651/2651 Exact with 76 relocations**. Their 25/26 compiler-local
label references shift by +13 after this same-size view change;
they were rebound simultaneously at unchanged original target offsets
and exact branch destinations before full byte comparison, including
both owned switch tables. Public proof:
`docs/evidence/akiko-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`. This does not
refresh unrelated historical stale-header certificates or prove
whole-game runtime equivalence. No full cold replay was performed.

### Minagi Character21 lifecycle: seven native Exact owners

The original `Character21` vtable at `0x00788940` selects seven newly
authored complete normal-C++ functions in `src/Character21Lifecycle.cpp`.
Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected strict replay proves
**666 / 666 native bytes**, **nine original-bound COFF REL32 call
operands**, and **zero differences**:

| Minagi owner | Native address | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x005AA180` | 440 |
| ResetPose | `0x005AA340` | 58 |
| RemoveLocalEffect | `0x005AA380` | 80 |
| Slot03 | `0x005AA3D0` | 19 |
| Slot01 | `0x005AD500` | 11 |
| Slot08 | `0x005AD510` | 11 |
| EmitLocalEffect | `0x005AD520` | 47 |

The nontrivial **440-byte InitializeState** resets seven child ints,
sets all ten original Minagi X/Y collision offsets, clears three
64-int arrays, then calls `Secondary::InitializeState`. It also
constructs and initializes an `EffectSpawn`, emits original local
effect **0x190** at integer X minus facing×40 and integer Y,
with the original `owner`, `group`, `layer`, `payload`, `field0028`
and facing-flag assignments. The five initializer REL32 operands
bind original `Secondary::InitializeState` (0x40EDF0), `EffectSpawn`
constructor (0x405490), `ResetLocalEffectSpawn` (0x413090), and two
`__ftol2` calls (0x7783B8). ResetPose, RemoveLocalEffect, Slot03 and
EmitLocalEffect preserve their individually checked base-method
call targets; Slot01 and Slot08 are authentic empty 11-byte overrides.

Independent vtable target addresses, complete extents, nonrelocated
bytes and original direct-call operands were reviewed before
registration. Certificate:
`docs/evidence/character-21-lifecycle-exact.json`. Codegen Exact
is not whole-game linkage/runtime parity or portability.

### Minagi constructor: independently accepted exact source (2026-11-09)

`Character21::Character21` at `0x005A9FA0` now has authored natural C++
`src/Character21Frame.cpp`. A selected VC7.1 compile matched **469/469
original bytes** with **four reviewed relocations**: the six-argument
Secondary constructor at `0x40EAE0`, Minagi 13-slot child vtable
`0x788940`, original `minagi` NUL string `0x788938`, and CRT `strcpy`
`0x778080`. The 0x3458 class retains seven state integers, five
collision coordinate pairs, eight command bytes, three 64-int scratch
arrays and four unknown trailing bytes. Independent original offsets,
not another character's guessed layout, determine the assignments.

The actual affected constructor callers, `scene-create-character`
(**3495/3495** bytes with 97 bound relocations) and
`scene-loading-character` (**2651/2651**, 76), were rebuilt and
strictly compared including both owned switch tables. The shared
header also affects `Character03::Slot06`; its complete **59292/59292**
source and both tables were recompiled, preserving all **1,386**
original-bound relocations. The changed compiler-local switch-label
symbols numbered 25, 26 and 127, each shifted +9 and rebound at the
same original offsets/targets using simultaneous non-cascading
replacement. Certificates:
`docs/evidence/minagi-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`; the Makoto
full-owner certificate was independently refreshed. These selected
checks do not assert freshness of unrelated older header proofs.

### EX Nanase Character12 Slot08: 789-byte original Exact special timer

Canonical EX Nanase vtable `0x00788DE4`, slot8 `0x00788E04`,
points to a complete **789-byte native `Character12::Slot08` at
`0x006D2420`**. New *natural C++* owner
`src/Character12Slot08.cpp` compiles using pinned VC7.1
`/Od /G6 /MT /Gy /W3`; the strict selected-only oracle validates
**789 / 789 original code bytes**, **18 original-bound relocations**
(17 REL32 direct calls and one native zero-valued double DIR32),
and **zero differences**, with all original control-flow forms and
function extent matched.

This is an original stateful special-effect/timer virtual, not a
trivial leaf. Each invocation constructs a real EffectSpawn and resets
its defaults; if `field3454 == 0` and all original meter/health,
opponent-alive, context selection, grounded and pose gates hold,
it resets the pose/frame and switches to special state0x140.
When `field3454 == 1`, it increments meter, calls `StartTrail(1)`,
decrements field3150, increments field314c and wraps the latter
past144. Every18 ticks it chooses original palette `0xD1,0xD0,
0xCF,0xB1,0xCF,0xD0,0xD1,0xD2` in exact order, calling native
`Secondary::SetCharacterTint(...,27)` eight separate times.
When the counter expires outside pose IDs50–149, it emits effect
0x22 at original signed facing-adjusted random X and random Y,
using two original `RandomRange` calls and four original conversion
paths before setting field3150=2.

Independently confirmed original direct targets include
`EffectSpawn` ctor0x405490, reset0x413090, frame reset0x40F1E0,
trail0x4109D0, tint0x410AC0 (8 references), `RandomRange`
0x4108A0 (2), `__ftol2`0x7783B8 (2), and `Context::EmitEffect`
0x407100. The literal DIR32 at 0x7872F8 contains an exact
IEEE-754 `0.0` payload. Original vtable selection, branch ordering,
full extent and all relocation operands were reviewed before entry.
Proof: `docs/evidence/character-12-slot08-exact.json`.
This is codegen Exact, not whole-game runtime/linkage parity.

### EX Nanase Character12 lifecycle: six complete original Exact owners

The canonical EX Nanase `Character12` vtable at `0x00788DE4`
identifies six new complete natural-C++ owners in
`src/Character12Lifecycle.cpp`. Pinned VC7.1
`/Od /G6 /MT /Gy /W3` **selected strict original-bound replay proves
537/537 native code bytes, five original COFF REL32 calls, and
zero differences**:

| Character12 method | Native address | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x006CFD80` | 322 |
| ResetPose | `0x006CFED0` | 58 |
| RemoveLocalEffect | `0x006CFF10` | 80 |
| Slot03 | `0x006CFF60` | 19 |
| Slot01 | `0x006D2400` | 11 |
| EmitLocalEffect | `0x006D2740` | 47 |

The complete **322-byte InitializeState** resets eight original
child integer fields in native order, reinstalls five X/Y collision
short pairs (-12,-58), (18,0), (16,-9), (21,-14), (33,-26), clears
three 64-int local-effect arrays, and calls original base
`Secondary::InitializeState` at 0x40EDF0. ResetPose resets three
child fields and calls `Secondary::ResetPose` (0x40F110);
RemoveLocalEffect clears all three per-index array entries then
calls `Secondary::RemoveLocalEffect` (0x412E60); Slot03 delegates
to base UpdateLocomotionState (0x40E740); EmitLocalEffect first
invokes virtual removal for effectWrite, then base emitter at
0x412B10. The 11-byte Slot01 is a real empty override, not
synthetic filler. Each original vtable pointer, complete owner
boundary and all five original call targets were independently
reviewed. Proof: `docs/evidence/character-12-lifecycle-exact.json`.
Codegen Exact does not establish full-game linkage or runtime parity.

### EX Nanase constructor: complete exact source (2026-11-09)

`Character12::Character12` at `0x006CFBB0` now has authored natural
C++ in `src/Character12Frame.cpp`. A fresh VC7.1 selected native
rebuild matches **452/452 bytes**, zero differences, with all four
reviewed relocations: Secondary construction `0x40EAE0`, EXnanase
13-slot vtable `0x788DE4`, original `EXnanase` NUL resource name at
`0x788DD8` and CRT `strcpy` at `0x778080`. The original **0x3468**
object view preserves seven zeroed state integers, three 64-element
integer arrays, a trailing int at +0x3454, and a separately zeroed
byte at +0x3460. The remaining bytes are explicitly unknown,
not arbitrarily initialized. Five collision coordinate pairs and the
original sparse command assignments were checked against the complete
target instructions before accepting the source.

After updating the shared view, three genuine dependent exact units
were selectively rebuilt: `scene-create-character` **3495/3495**
bytes (97 relocations), `scene-loading-character` **2651/2651**
(76), and the complete Makoto Slot06 **59292/59292** (1,386).
Their 25/26/127 compiler-local labels shifted by +12, and were
bound simultaneously by unchanged relocation positions/types and
original target destinations, followed by strict complete comparison.
Public evidence: `docs/evidence/exnanase-constructor-exact.json`
and `docs/evidence/nagamori-affected-consumers-exact.json`; the Makoto
whole-owner certificate was separately refreshed. These targeted
checks do not certify unrelated historical header dependencies,
whole-game linkage or native runtime equivalence.

### Sayuri constructor: independent complete exact source (2026-11-09)

`Character09::Character09` at `0x004463E0` now has a full natural C++
implementation in `src/Character09Frame.cpp` matching **419/419**
original code bytes with four original-bound relocations under the
selected VC7.1 static /Od profile. The reviewed targets are the
Secondary constructor `0x40EAE0`, 13-slot Sayuri child vtable
`0x788138`, original `sayuri` literal `0x788130` and CRT strcpy
`0x778080`. The original-size 0x3458 view has seven explicit child
state integers, three arrays of 64 integers and four unwritten
trailing bytes. It initializes `field3150=999` after the surrounding
zeroed fields, five collision pairs, and sparse command indices
`[0],[1],[10]` rather than fabricating uniform command defaults.

After the same-size class-view change, three real dependent owners
were rebuilt and strictly compared: Scene creation **3495/3495
bytes with 97 relocations**, loading creation **2651/2651 with 76**,
and the full Makoto Slot06 boss **59292/59292 with 1,386**.
Compiler-local labels shifted +9 in 25/26/127 references, mapped
simultaneously at unchanged relocation positions and actual original
jump destinations. The complete reports are
`docs/evidence/sayuri-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`; the accepted
Makoto report was also refreshed from a new selected build. Other
legacy source-dependency freshness and runtime linkage remain open.

### Ikumi constructor: exact native vector-array initialization (2026-11-09)

`Character14::Character14` at `0x006A59C0` now has a **647/647-byte
Exact** natural C++ source owner `src/Character14Frame.cpp` and selected
`character-14-constructor` unit with all **11** original-bound
relocations. Unlike simple constructors, the native code allocates
**505 PatternSequence objects and 505 SecondarySequence objects** with
real C++ `new[]` vector-constructor headers and calls the member
`SetAlternateMode(0)` at the independently reviewed `0x006AB6A0`.
It then sets byte +0x3460 to zero, assigns original Ikumi resource
literal/collision/command defaults, and zeroes three 64-element arrays.
The child object remains the observed **0x3478 bytes** with separate
alternate and saved pattern/sequence pointer fields; unused bytes
remain explicitly unknown. Operator-new, vector iterator, child mode,
CRT and vptr operands all have independently verified original targets.

Three genuine dependents of `CharacterViews.h` were rebuilt:
`scene-create-character` **3495/3495 bytes with 97 relocations**,
`scene-loading-character` **2651/2651 with 76**, and complete Makoto
Slot06 **59292/59292 with 1,386**. Their compiler-local label symbols
shifted by +20 for 25/26/127 references, rebound at unchanged original
relocation positions and destinations before full byte comparison.
Certificates: `docs/evidence/ikumi-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`; the Makoto proof
was refreshed from this selected build. The called `SetAlternateMode` is a **separate owner** and now
has its own complete independently accepted Exact proof immediately
below; constructor proof alone was never treated as covering it.

<a id="ikumi-slot02-input-command-scanner"></a>

## Ikumi Slot02 input recognizer: complete 5,153-byte strict Exact

`Character14::Slot02` is now fully reconstructed in natural C++ at
`src/Character14Commands.cpp` and independently selected unit
`character-14-slot02` under VC7.1 `/Od /G6 /MT /Gy /W3`.
Original vtable slot 2 at `0x00788D7C` resolves to
`0x006AB7E0`; its complete original function owns **5,153 bytes**
through `0x006ACC01`, followed by 15 alignment `CC` bytes.
The complete rebuilt function **matches 5,153/5,153 source-code
bytes, all 1,508 original x86 instructions, and 0 relocation sites**.
Every original byte matches unmasked, including all 15 independently
reconstructed priority-ordered input-history scans and the common
function epilogue. Relocated/native and canonical original SHA-256
are both `752ea6e701bca768800303e3a6a370d0d0ce8f17d238378528e2e8f678e1466c`.

Each scan preserves signed-facing directional arithmetic, the
180-frame circular history, its distinct 5–135 tick window,
release/early-finish semantics and priority over later scans.
The third scan's meter threshold includes Ikumi's original
`field315c > 0` override; the early decompiler-based reversed
facing boolean was corrected from original `neg/sbb/add` assembly.
Complete comparison: `docs/evidence/ikumi-slot02-exact.json`. Individual scan
boundaries are in `docs/evidence/ikumi-slot02-command-scan-boundary.json`.

<a id="ikumi-slot08-effects-owner"></a>

## Ikumi Slot08 effects owner: 1,592-byte complete strict Exact

Character14::Slot08 (not Slot07) is confirmed by original vtable slot 8
at 0x00788D94. The target-bound extent [0x006AB060,0x006AB698)
owns exactly **1,592 instruction bytes / 434 instructions**, followed
by eight CC alignment bytes excluded from the function.
Original SHA-256 is
b1f3a40ab03af31d6a15b5f882f1efea4ccb1f3962fb490348aa9ad5002f7e29.
The independent boundary-only proof is retained in
docs/evidence/ikumi-slot08-boundary-review.json.

The **complete natural C++ owner** is now src/Character14Effects.cpp.
Pinned VC7.1 /Od /G6 /MT /Gy /W3 produces **strict Exact**:
1,592/1,592 original code bytes, 434 instructions and 33/33
original-bound relocations with zero differences. The proof is
docs/evidence/ikumi-slot08-exact.json; target-only selected build
unit character-14-slot08 in config/match-units.toml.

All state branches are reconstructed: EX-mode 8 entry/transition,
EX-mode 10 countdown and 186-tick cycle, 17 timed tint calls,
trail activation, zero-time mode restoration, and five independent
collision effect-spawn groups. Crucially, original code calls the
VC7.1 x87 integer-conversion helper __ftol2 after loading
opponent->positionX, then re-converts the integer to double before
storing effect.x. Earlier workbench code incorrectly called rand()
five times; this accounted for the missing eleven bytes in each
branch. Replacing those with five natural
(double)(int)(*opponentSlot)->positionX expressions restores
the exact x87 load/call/FILD/FSTP sequence and all stack homes.
The original countdown uses field3150 <= 0. No inert bytes or
assembly wrappers were introduced. The neighboring accepted
SetAlternateMode helper was not altered and whole-game/runtime
equivalence remains separate from this codegen acceptance.

<a id="ikumi-exact-alternate-pattern-resource-loader"></a>

### Ikumi exact alternate pattern resource loader (2026-11-09)

Ikumi's extra animation-bank file reader is a substantial independent
**949/949-byte strict Exact** function,
`Character14::LoadAlternatePatterns` at `0x006A5EB0`, reconstructed
entirely in natural C++ in `src/Character14Loader.cpp`. The original
entry is reached by Ikumi's vtable slot-11 `LoadResources` override;
it reads the original NUL-terminated resource path
`ikumi\ikumi2.pat` into the two existing 505-element pattern and
secondary-sequence banks. It decodes each frame's timing and texture
fields, attack/stun/guard parameters, two x87 float scaling values,
all body/hurt/attack rectangles and their original loop order, using
`PatternReader`. All **39 original relocation sites** were explicitly
bound and compared without masks, across ten distinct symbols:
`PatternReader` construction/destruction, ReadInt/ReadShort/Read,
two Allocate helpers, the canonical path, and IEEE-754 `100.0f`
/ `-100.0f` at `0x787C5C` / `0x787C58`. The compiled full function
matches every original byte through its unpadded RET at `0x006A6265`;
the following eleven `CC` bytes belong to alignment before reset.
Receipt: `docs/evidence/ikumi-extra-patterns-exact.json`.

The actual vtable slot-11 `Character14::LoadResources` at
`0x006A5E70` is another independently **60/60-byte Exact** natural
method in the same source file. It calls the 949-byte parser, the
already Exact base `Secondary::LoadResources` at `0x410B70`, then
saves the current pattern and sequence bank pointers at +0x346C/
+0x3470, in original order. Both original direct-call relocations
are bound: `docs/evidence/ikumi-load-resources-exact.json`.
The 60-byte function ends before four `CC` padding bytes that precede
the 949-byte helper. These are two **separate** original owners,
not one merged 1,009-byte function.

Adding only the nonvirtual `LoadAlternatePatterns` declaration to the
original-size Character14 view did not change object layout, but it
did renumber compiler-local labels. Ten actual affected accepted
units were selectively rebuilt and re-checked: the two creation
functions (3495/97, 2651/76), full Makoto Slot06 (59292/1386), and
seven previously accepted Ikumi source owners. The creation/Makoto
function-local symbols shifted +1 in 25/26/127 occurrences; all
original target destinations and all function/table bytes remained
strict Exact. The existing public receipts were refreshed from those
actual builds rather than assuming earlier evidence still applied.
Unrelated older proof-freshness debt and full game runtime remain open.

<a id="ikumi-exact-natural-destructor"></a>

### Ikumi natural derived destructor: original double base teardown (2026-11-09)

`Character14::~Character14` at `0x006A5DC0` is now an independently
accepted **163/163-byte strict Exact** natural C++ owner in
`src/Character14Destructor.cpp`. It restores the two saved
base-owned animation bank pointers, then performs real C++
`delete[] alternatePatterns` and `delete[] alternateSequences` using
the correct vector-deleting destructors. It has **5/5 original-bound
relocations**: Ikumi vtable `0x788D74`, the vector destructors at
`0x408200` and `0x412870`, and **two distinct calls** to the
base `Secondary::~Secondary` at `0x40ECB0`. An initial ordinary
C++ destructor matched only 155 bytes; original disassembly showed
an explicit base destructor before the compiler-added implicit call.
Preserving both calls (rather than making an ungrounded assumption
that the original implementation was more idiomatic) produced exactly
163 matching code bytes. The original body ends at exclusive
`0x006A5E63` and 13 `CC` alignment bytes lead to the separately
Exact resource wrapper at `0x006A5E70`.

The selected proof is `docs/evidence/ikumi-destructor-exact.json`.
Its class declaration does not change the original child allocation
size; the actual original call semantics are recorded, including the
unusual double base teardown. The affected scene creation and loading
owners, full Makoto Slot06, and nine accepted Ikumi methods were
selectively recompiled/recompared and remained Exact. This is not
a general full cold replay, runtime safety validation or whole image
linkage claim.

<a id="ikumi-exact-initialization-with-bank-reset"></a>

### Ikumi mode-aware InitializeState: complete 368-byte exact owner (2026-11-09)

Ikumi's original vtable slot 12 at `0x788DA4` points to the real
`Character14::InitializeState` at `0x6A5C50`, whose complete
un-padded function ends at **`0x6A5DC0`**. Newly authored natural
source `src/Character14Initialize.cpp` strictly matches **368/368
original bytes with 2/2 relocations**, targeting the separately Exact
`Character14::SetAlternateMode(0)` and the already-Exact base
`Secondary::InitializeState` (`0x40EDF0`). It restores the mode flag,
all ten child state integers, five original collision coordinate
pairs and three arrays of 64 zeroed integers, in original order.
The next original function begins immediately at `0x6A5DC0`; the
later resource/destructor code must **not** be attributed to this
368-byte owner. Canonical selected evidence:
`docs/evidence/ikumi-initialize-state-exact.json`, with no ignored
bytes or cold replay. The separate 1,592-byte Ikumi Slot08 boss
remains open.

<a id="ikumi-exact-locomotion-and-effect-emission"></a>

### Ikumi locomotion and local-effect delegates: two exact functions (2026-11-09)

Two more Ikumi overrides now have independently accepted normal C++
source `src/Character14Delegates.cpp`. Vtable slot 3
(`0x788D80`) selects `Character14::Slot03` at `0x6A6310`, an exact
**19/19-byte** delegate to the reviewed `Secondary::UpdateLocomotionState`
at `0x40E740`. Vtable slot 9 (`0x788D98`) selects
`Character14::EmitLocalEffect` at `0x6AB7B0`, **47/47 bytes Exact**
with one original-bound base call at `0x412B10`.

Importantly, the original emitter reads the **effectWrite** short
at object offset `+0x2CA`, then invokes the virtual slot-10
`RemoveLocalEffect` before the base `Secondary::EmitLocalEffect` call.
An earlier natural draft incorrectly used **effectRead** (`+0x2CC`):
only one displacement byte differed, but the pool behavior was wrong.
Correcting the member to `effectWrite` matches all 47 bytes without
masks, and the single direct relocation is bound. Both function
extents and vtable pointers were independently checked from EFZ.exe;
the selected full receipts are
`docs/evidence/ikumi-delegates-exact.json`. This does not confer
Exact status on Ikumi's 1,592-byte Slot08 effect-state boss.

<a id="ikumi-exact-reset-and-effect-pool-overrides"></a>

### Ikumi pose reset and effect-slot removal: two exact overrides (2026-11-09)

The original Ikumi child vtable at `0x788D74` confirms its
`Character14::ResetPose` entry at `0x6A6270` (slot 0) and
`Character14::RemoveLocalEffect` entry at `0x6A62C0` (slot 10).
Both now have normal C++ in `src/Character14Core.cpp`, with selected
**71/71** and **80/80** exact code bytes, respectively. Every byte
and one original-bound base-call relocation per function matched under
VC7.1. ResetPose clears only the four original child integers
`field3138`, `field313c`, `field3140`, `field3154` and then calls
`Secondary::ResetPose` at `0x40F110`. RemoveLocalEffect clears the
same signed-short index in three distinct 64-int child arrays before
calling `Secondary::RemoveLocalEffect` at `0x412E60`. It does not
replace the base pool-removal method. Their 9-byte/zero-byte alignment
padding is excluded from the reviewed original function extents.
Receipt: `docs/evidence/ikumi-core-overrides-exact.json`. These are
new independently accepted methods; the larger Ikumi `Slot08` effect
owner remains unaccepted in its separate workbench.

<a id="ikumi-alternate-mode-exact"></a>

### Ikumi alternate mode switch: 257-byte strict Exact (2026-11-09)

`Character14::SetAlternateMode(char)` at `0x006AB6A0` is now a natural
C++ member source in `src/Character14Mode.cpp`, accepted as selected
unit `character-14-alternate-mode`, with full **257/257 original code
bytes**, **zero different bytes and zero relocation entries**.
Its provenance is not inferred from a name: the exact Ikumi constructor
calls this real owner at `0x006A5AA1` with argument zero and an original
thiscall `RET 4` closes the target function at `0x006AB7A1`.

The source uses an explicit *partial* 0x98-byte pattern-slot view
located at +0x4D8 for each of 64 slots. Entering alternate mode swaps
the active patterns/sequences to the alternate banks, updates all
64 slot pointers, and sets the byte at +0x3460 to one; leaving it
restores the saved banks and resets the byte. Both separate loops and
the signed-char mode comparisons compile to the exact original stack
homes, pointer arithmetic and branches without inline assembly.
Full proof `docs/evidence/ikumi-alternate-mode-exact.json`.
The constructor, its called switch owner and all original source
extents are accepted **independently**, not by assuming the call
produces runtime-equivalent behavior for the entire game.

### Mio Character11 Slot01: 975-byte two-gauge render Exact

Canonical Mio `Character11` vtable slot1 at `0x00788880` points to
the full **975-byte** native `Character11::Slot01`, original
`[0x0058D6E0,0x0058DAAF)`. Natural C++ in `src/Character11Render.cpp`
implements **two real sprite-gauge render variants** selected by
field3150==0 or1. Each takes original `patterns[43/44].frames[0]`,
constructs source and left-/right-facing destination rectangles
using `frame.u/v/width/height`, and calls the original
`Video::DrawSurface` with selected texture and color key.

The pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected strict replay proves
**975/975 native code bytes, 8 independently original-bound COFF
REL32 operands, and zero differences**. The six real
`MakeSurfaceRect` call sites resolve to 0x0040C590; two
`Video::DrawSurface` calls resolve to 0x00409A90. The latter callee
is separately not yet accepted as Exact; this proof is specifically
the complete *caller* function, with native callee binding original-
bound. All source control-flow and nonrelocated machine bytes match.

Original sprite positions for the player==0 branch use 45-frame.u,
31-frame.v. The alternate player branch uses
(frame.u+275)-frame.width,31-frame.v, preserving source/destination
and texture selection, stack layout and draw ordering.
Proof: `docs/evidence/character-11-slot01-exact.json`.
Whole Windows runtime linkage, native video callee reconstruction and
portability remain separately open.

### Mio Character11 lifecycle: six complete native Exact owners

The original Mio `Character11` vtable at `0x0078887C` identifies six
newly authored natural-C++ methods in `src/Character11Lifecycle.cpp`.
Pinned VC7.1 `/Od /G6 /MT /Gy /W3` selected-only full-owner replay
proves **506 / 506 original native bytes, nine native original-bound
COFF operands, and zero differences**:

| Mio method | Original address | Exact bytes |
| --- | --- | ---: |
| InitializeState | `0x005884B0` | 287 |
| ResetPose | `0x005885D0` | 62 |
| RemoveLocalEffect | `0x00588610` | 80 |
| Slot03 | `0x00588660` | 19 |
| Slot08 | `0x0058DAB0` | 11 |
| EmitLocalEffect | `0x0058DAC0` | 47 |

The complete 287-byte initializer resets character field3138,
**double** states field3140/field3148, and two additional ints;
reinstalls ten exact native collision-offset shorts (-22,-56),
(17,0), (15,-23), (22,-26), (33,-52); zeros all three independent
64-int effect arrays and delegates to `Secondary::InitializeState`.
The 62-byte ResetPose also sets both doubles to zero before invoking
`Secondary::ResetPose`. **All four native double-zero constant
references** at original `0x007872F8` are checked as DIR32,
not skipped under a generic relocation mask. Five independently
bound base calls target 0x40EDF0, 0x40F110, 0x412E60, 0x40E740,
and 0x412B10; original Slot08 is an actual 11-byte empty override.
Each complete original boundary and vtable slot was checked before
registration. Certificate:
`docs/evidence/character-11-lifecycle-exact.json`.
Codegen Exact is not whole-game linkage or runtime equivalence.

### Mio constructor: original x87 double state initialization (2026-11-09)

`Character11::Character11` at `0x00588310` has new natural C++
`src/Character11Frame.cpp`, strict **407/407-byte Exact** under VC7.1
with **six reviewed original relocations**. The four direct bindings
are its Secondary constructor (`0x40EAE0`), 13-slot child vtable
(`0x78887C`), `mio` NUL literal (`0x788878`) and CRT `strcpy`
(`0x778080`). The two extra relocations are both references to the
**same original 64-bit IEEE-754 positive zero** at `0x7872F8`, used
for distinct `double` fields at object offsets **+0x3140** and
**+0x3148**. The explicit class view retains the original 0x3458
allocation and leaves the originally untouched +0x313C four bytes
unknown, rather than inventing an initialization. Five collision
coordinate pairs, four sparse command IDs and three 64-element
integer arrays compile to exact original instructions.

Because `CharacterViews.h` changed, only the three actual target-bound
Exact consumers were rebuilt: `scene-create-character` remains
**3495/3495** bytes / 97 relocations, `scene-loading-character`
**2651/2651** / 76 and Makoto `Slot06` **59292/59292** / 1,386.
Their 25/26/127 compiler-local labels shifted by +7 and were
rebound simultaneously at unchanged canonical positions and targets,
then each complete function plus owned tables compared strictly.
Public receipts: `docs/evidence/mio-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`; the existing Makoto
receipt was freshly updated. No unrelated full cold replay ran.

### Nayuki constructor: original nonzero state exactness (2026-11-09)

`Character10::Character10` at `0x00461090` now has accepted natural
C++ in `src/Character10Frame.cpp` with **455/455 code bytes** and
**4/4 independently reviewed original relocations**. The target
constructor initializes nine child state integers, including the
**nonzero +0x3148 value 3**, five collision coordinate pairs,
four sparse command IDs, and three complete 64-int scratch arrays.
The child class stays the observed **0x3460** bytes; its last four
bytes are explicitly unknown. Its resource literal `nayuki`,
child vtable at `0x788270`, six-argument Secondary constructor and
CRT `strcpy` match their actual original target locations.
This is separate from the already Exact `NayukiB` constructor.

After the class-view change, only three target-bound dependent Exact
functions were rebuilt: `scene-create-character` **3495/3495** bytes
with 97 relocations, `scene-loading-character` **2651/2651** with 76,
and the complete Makoto Slot06 boss **59292/59292** with 1,386.
The 25/26/127 changed compiler-local label references shifted by
+11. All were rebound simultaneously at unchanged original target
positions before strict byte comparison including local tables.
Public receipts: `docs/evidence/nayuki-constructor-exact.json` and
`docs/evidence/nagamori-affected-consumers-exact.json`; the Makoto
receipt was refreshed. No full cold replay or game runtime claim.

<a id="nagamori-exact-effect-proximity-helper"></a>

### Nagamori original effect-proximity helper: 231-byte strict Exact

The nonvirtual `Character06::MarkEffectCollision` at `0x004AE1D0`
is now fully reconstructed in normal C++ at
`src/Character06Collision.cpp` and accepted as an isolated source
function, unit `character-06-effect-proximity`.
It scans the effect pool from `effectRead` to `effectWrite` through
64 circular slots; if a slot is active and both `fabs` coordinate
differences fall inside the supplied half-width and half-height,
it sets Nagamori's matching +0x316C byte flag. The complete original
`[0x004AE1D0,0x004AE2B7)` extent is **231/231 strict Exact** under
pinned VC7.1, with both original `REL32` calls bound to CRT `fabs`
(`0x0077842D`), zero byte differences and nine external alignment
`CC` bytes excluded. Strict proof:
`docs/evidence/nagamori-effect-proximity-exact.json`.

Because adding a nonvirtual member declaration to shared
`src/CharacterViews.h` would change source hashes for **123 already
selected units**, the exact member is compiled using a dedicated
same-layout class view `workbench/nagamori-helper/CharacterViews.h`
while the shared header stays unchanged. This is an explicit
per-unit reconstruction boundary rather than claiming whole-program
ODR/linkage correctness; see `workbench/nagamori-helper/README.md`.
No global cold replay or unrelated certificate invalidation occurred.

<a id="nagamori-slot02-command-scanner-first-scan-recovered"></a>

## Nagamori Slot02 input command boss: complete 4,917-byte strict Exact

Nagamori's original virtual slot 2 at `0x00788404` resolves to
`Character06::Slot02` at `0x004B1780`. The complete **4,917-byte**
owner `[0x004B1780,0x004B2AB5)` is now reconstructed in natural
C++ at `src/Character06Commands.cpp` and accepted as selected
`character-06-slot02` Strict Exact: **4,917/4,917 original code bytes,
all 1,421 instructions, zero differences, and both original DIR32
relocations**. They resolve to the original IEEE-754 positive-zero
double at `0x007872F8`. Eleven following `CC` alignment bytes are
excluded. The original function SHA-256 is
`a3f3e30b48a3763a54ee34d5a3d35ea5f0f83e321e65f804ceaf5c33a815bb00`.

All fifteen original priority-ordered circular input-history scans
are implemented, including Nagamori's 3000-meter grounded 0x5B
command, 1000-meter grounded 0x64 branch, base 0x78/0x6E specials,
original signed facing and input-window conditions, and the 0x35
pattern gated by state `field0008 == 0x60`. Superficially similar
Ikumi source was only a test hypothesis; all resulting control flow,
register operands, full code bytes and literal bindings were checked
against Nagamori's own executable. Complete strict native certificate:
`docs/evidence/nagamori-slot02-exact.json`.

<a id="nagamori-slot05-cpu-decision-prefix"></a>

## Nagamori Slot05 CPU boss: complete 15,292-byte strict Exact

The original virtual Slot05 on Nagamori Character06
(vtable pointer 0x00788410) occupies the complete
[0x004B2AC0,0x004B667C) range, **15,292 code bytes /
3,924 x86 instructions**, followed by four CC alignment bytes
excluded from this owner. Original complete-function SHA-256:
14a83398918558355cd4ae747fa313b60f62771f1758ba870a593d29f596bfb9.

The complete natural C++ source is now
src/Character06Cpu.cpp. Pinned VC7.1 /Od /G6 /MT /Gy /W3
emits exactly **15,292/15,292 code bytes**, the original
**0xE8 stack frame** and all **3,924 original instructions**.
After binding every original relocation, a full strict normal-COFF
comparison reports **zero differing bytes**, including all
**300 / 300 original-bound relocations** (198 original
floating-point literal references, 99 Secondary::RandomRange
calls, two Secondary::CollisionSide calls and one CRT fabs).
The 37 unique COFF symbols each bind to a single original
address. Every real constant's exact 4/8-byte IEEE-754
payload was independently checked at its corresponding
original executable address; call targets were verified from
original direct call operands, not guessed from sibling sources.

The source reconstructs the defensive random checks, CPU
movement and grounded/airborne decisions, states 4..11,
collision follow-ups for actions 0xC8..0xD1 and 0xE7,
then all generic decision trees and the final walking timer
continuation. The original 0x004B3172 near-JNZ shares a guard
over two attacks, and floating evaluation order matters
in several tests (notably 0x004B5B75). An inline Boolean
expression in the opponent-airborne branch restores the
original EBP-0xD4 scratch register and avoids shifting the
this-pointer home; the final fallback naturally restores
the complete 0xE8 stack and shared exit. No padding,
handwritten machine code or fixed-register ABI was used.

The strict acceptance evidence is
docs/evidence/nagamori-slot05-exact.json, selected native
replay unit character-06-slot05 in config/match-units.toml.
Earlier normalized prefix checks are superseded: unlike
those partial diagnostics this certificate covers the entire
natural compiler function and every original relocation.
This establishes codegen Exact for one substantial authored
owner, not whole-product linkage, runtime equivalence or
the entire game's reconstruction.

## Nagamori Slot04 action boss: complete 12,277-byte strict Exact

The original Nagamori vtable slot 4 at `0x0078840C` points to
`Character06::Slot04` at `0x004AE2E0`; independently verified complete
extent `[0x004AE2E0,0x004B12D5)` is **12,277 code bytes**, followed
by 11 `CC` alignment bytes excluded from the function. The full
natural C++ owner `src/Character06Input.cpp` is now **strict Exact**
under selected pinned VC7.1: **12,277/12,277 code bytes, zero byte
differences and 100/100 original-bound relocations**. All 3,092
original x86 instructions match. The SHA-256 of the complete original
relocated contribution is
`bd59aef64acf8b517eb8075e1a43d4250ef28b95973f47e0132289979f0fe26f`.

The hundred relocations were checked from the canonical target byte
operands and independently validated for all 11 symbol/data kinds:
44 base `ClearBufferedButtons` calls at `0x40F170`, 4
`FaceOpponent` calls at `0x40E630`, and 52 `DIR32` references to
actual original IEEE-754 double bit patterns. In particular both
floating-point comparison boundaries and all signed numeric values
were checked, not masked. The normal source reconstructs the complete
original buffer management, priority-ordered action tree, special
meter tiers, airborne/ground cancels, X-coordinate comparison branches,
air-dash and ground-dash transitions, and all input-button paths. The
original Nagamori-only `0xD8`, `0xD1`, and `0xCE/0xD7` variants were
identified by independently checking the original function and
correcting an earlier sibling-derived trial. The final natural
function emits the original 20-byte stack frame without artificial
locals. Its exact source, relocation and target receipt is
`docs/evidence/nagamori-slot04-exact.json`.

<a id="nagamori-exact-meter-overlay-renderer"></a>

### Nagamori 1,080-byte meter overlay renderer: complete Exact (2026-11-09)

The substantial nontrivial `Character06::Slot01` at `0x004B12E0`
now has natural accepted C++ in `src/Character06Render.cpp` and a
selected **1,080/1,080-byte Strict Exact** certificate. Original
Nagamori vtable slot 1 at `0x788400` points directly to this entry.
Unlike an empty delegate, it draws both animation-bank sprites 43 and
44 with player-dependent horizontal mirroring, original texture,
color key, placement and the Nagamori-specific **`field3150 / 1200`**
width scale. The initial C++ source form was independently tested
against the original x86; only after all non-relocation bytes matched
were the **eight direct relocations** individually bound to their
actual original targets. Six calls resolve to
`MakeSurfaceRect` at `0x40C590`, and two to
`Video::DrawSurface` at `0x409A90`. All original and compiled bytes
then matched, without masks. Complete original owner is
`[0x004B12E0,0x004B1718)`; eight subsequent `CC` bytes belong to
alignment, not to the function. Public proof:
`docs/evidence/nagamori-meter-render-exact.json`.

<a id="nagamori-delegates-and-timer-overrides"></a>

### Nagamori locomotion, timer and effect emission: three exact methods (2026-11-09)

Three new independent Nagamori virtual functions have complete natural
C++ in `src/Character06Delegates.cpp`. Original vtable at `0x7883FC`
selects slot 3 `Slot03` at `0x004AE2C0`, **19/19 strict exact**
with one bound call to `Secondary::UpdateLocomotionState` at `0x40E740`;
slot 8 `Slot08` at `0x004B1720`, **44/44 strict exact** with no
relocations, decrementing child state +0x315C only when positive;
and slot 9 `EmitLocalEffect` at `0x004B1750`, **47/47 strict exact**
with one original direct base-emitter call at `0x412B10`.

The emitter first dispatches virtual `RemoveLocalEffect` at the
**effectWrite** short cursor +0x2CA, not the similarly placed
read cursor +0x2CC. Both original relocation destinations and all
three complete unpadded function boundaries were reviewed before
accepting them; all code differs by **zero bytes**. Public proof:
`docs/evidence/nagamori-delegates-exact.json`. These exact methods
are independently exact methods; Nagamori Slot04 is now also a
fully accepted 12,277-byte owner, while Slot06 remains open.

<a id="nagamori-exact-initialize-state"></a>

### Nagamori InitializeState: complete 387-byte owner (2026-11-09)

`Character06::InitializeState` at `0x004ADFA0` is now a complete
natural C++ source function in `src/Character06Initialize.cpp`, with
**387/387 bytes, zero differences and one original-bound relocation**
under VC7.1. Original Nagamori vtable slot 12 at `0x78842C` confirms
its identity. It resets twelve additional state integers (preserving
the non-monotonic original assignment order), five collision pairs,
64 one-byte flags and three 64-int scratch banks before the reviewed
base `Secondary::InitializeState` call at `0x40EDF0`. It deliberately
does not initialize the separate +0x3154 field, which the original
reset doesn't touch. The original function ends at `0x004AE123`;
13 following `CC` alignment bytes are excluded. Strict selected
proof: `docs/evidence/nagamori-initialize-state-exact.json`.

<a id="nagamori-reset-and-effect-cleanup-overrides"></a>

### Nagamori reset and effect cleanup overrides: two exact methods (2026-11-09)

Original Nagamori vtable `0x7883FC` slot 0 resolves to
`Character06::ResetPose` at `0x004AE130`, now complete natural C++
**58/58-byte Strict Exact** from `src/Character06Core.cpp`, with the
original one bound `Secondary::ResetPose` call at `0x40F110`. The
source clears exactly three child-state integers +0x3138/+0x313C/
+0x3140 before delegating, not the remaining eleven constructor fields.

Nagamori slot 10 at `0x788424` resolves to `RemoveLocalEffect` at
`0x004AE170`, **95/95-byte Strict Exact** with one original bound
call to `Secondary::RemoveLocalEffect` (`0x412E60`). It clears a
64-byte flag at +0x316C and the corresponding slot in three
64-int arrays at +0x31AC/+0x32AC/+0x33AC, using the original signed
short index. Both reviewed complete boundaries omit external `CC`
alignment, and both recompiled original target bytes have zero
differences. Focused certificates:
`docs/evidence/nagamori-core-overrides-exact.json`.

### Nagamori constructor: exact byte-flag and three scratch banks (2026-11-09)

The original `Character06::Character06` at `0x004ADD90` now has
complete natural C++ source in `src/Character06Frame.cpp`, selected
`character-06-constructor` unit and a strict original-bound
**517/517-byte Exact** certificate with **4/4 verified relocations**.
The source preserves the unusual **0x34B0-byte** object allocation:
13 explicit 32-bit child-state integers from +0x3138 through +0x3168,
64 bytes of per-frame flags starting at +0x316C, followed by three
64-element integer scratch banks at +0x31AC/+0x32AC/+0x33AC and a
four-byte uninitialized tail. The original zero-initialization
sequence deliberately sets the state fields in a non-monotonic order;
reordering those writes would alter VC7.1 code generation.

Five original collision-pair offsets, commandCount=5 and sparse
command indices `[0]=0`, `[1]=5`, `[2]=10`, `[3]=1`, `[10]=6`,
`surfaceCount=727` and the exact `nagamori` literal at `0x7883F0`
were verified from canonical EFZ.exe instructions. Its four direct
relocations target Secondary construction (`0x40EAE0`), the Nagamori
13-slot vtable (`0x7883FC`), the original string, and CRT strcpy
(`0x778080`). Proof: `docs/evidence/nagamori-constructor-exact.json`.

The shared view change retains the original size, but changes some
compiler-internal symbol numbering. Scene creation **3495/3495**
(97 relocation sites), scene loading **2651/2651** (76) and full
Makoto Slot06 **59292/59292** (1,386) were selectively rebuilt.
Their 25/26/127 compiler-local `$L` symbols shifted **+16** and
were rebound simultaneously using the *same original relocation
positions and actual branch destinations* before full strict byte
checks. All eleven existing Ikumi source owners, including the newly
accepted 5,153-byte Slot02 boss, were also selectively rebuilt and
retained Exact; two compiler-local string labels shifted +16 with
their canonical literal targets unchanged. Public focused proof:
`docs/evidence/nagamori-affected-consumers-exact.json`; all affected
older Ikumi receipts and the Makoto whole-owner receipt were refreshed
from actual rebuilt source. No full cold replay or game-runtime
closure follows from these individual Exact matches.

All observed allocation sizes are 0x3448..0x34B0. Some constructors allocate
additional 505-element arrays or initialize different state/resource fields;
those complete bodies remain separate recovery work. Reuse of Nayuki's
constructor by ID 22 is target evidence, not a guessed extra subclass or name.

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
function remains outside matches.csv and implemented.csv. The complete candidate and local headers are in `workbench/shiori-state/`.
The baseline's signed-short RandomRange declaration is kept; the draft uses
explicit unsigned-short caller conversions for its AX zero extends.

Pre/post increment, extra normal scope, combined tick comparisons, nested tests,
signed tick storage with unsigned reads, and the signed/unsigned random caller
views were neutral for the unresolved register divergence and are parked. A plain
increment assignment lowered differently; an explicit goto added a branch. Do
not repeat these controls or introduce padding, bytes, assembly or an acceptance
size override. The large private prototype/rename source errors were corrected
and pinned toolchain execution checks passed; all final accepted-unit builds and
comparisons above succeeded. Original translation-unit context and private draft
field/helper views remain hypotheses requiring fresh evidence before integration.

<a id="secondary-facing-explicit-x-coordinate"></a>

## Secondary explicit-X facing update: 116-byte strict Exact

The adjacent member at 0x0040E6C0 has original reviewed
extent [0x0040E6C0,0x0040E734) (116 instruction bytes),
followed by twelve CC alignment bytes before
Secondary::UpdateLocomotionState. It is a natural authored
nonvirtual int Secondary::FacePosition(double) method, accepting
an explicit world-space X coordinate and returning whether the
facing direction changed. For X greater than self positionX the
signed facing byte becomes +1, for smaller X it becomes -1,
and equal X preserves facing and returns 0.

src/SecondaryFacePosition.cpp compiled under pinned VC7.1
/Od /G6 /MT /Gy /W3 is **strict Exact**: all
116/116 original code bytes agree, with **zero relocations
and zero byte differences**. Evidence:
docs/evidence/secondary-face-position-exact.json; selected
single-unit recipe: secondary-face-position. The declaration
added to src/Engine.h is nonvirtual, without fields or ABI
layout changes. Its two nearest accepted consumers
secondary-face-opponent (130 bytes) and
secondary-update-locomotion-state (923 bytes) were also
rebuilt and both remain exact. An interim local
FacingSecondaryView::SetFacingToward draft was reconciled
into this standalone source, restoring the previously accepted
SecondaryFacing.cpp owner before replay. This exactness
does not imply complete product linkage or runtime equivalence.

<a id="sayuri-slot08-and-local-effect-removal"></a>

## Sayuri slot-8 tint trigger and local-effect removal: two strict Exact owners

Original Character09/Sayuri vtable 0x00788138 proves the slot-8
entry at 0x00788158 points to 0x00449300 and the slot-10
RemoveLocalEffect entry at 0x00788160 points to 0x00446710.
The respective complete code extents are
[0x00449300,0x00449383) (**131 bytes**) and
[0x00446710,0x00446760) (**80 bytes**). The former is followed
by thirteen CC alignment bytes; the latter is adjacent to a
different function's 55 8B EC prologue at 0x00446760.

Natural src/Character09Effects.cpp rebuilds both under pinned VC7.1
/Od /G6 /MT /Gy /W3 to **131/131 and 80/80 strict Exact**,
each with one verified original REL32 binding and **zero
differences**. The 131-byte Slot08 checks first pose/tick zero,
action 150–155, opponent collision state 2, and opponent action
equal to Character09 field3150; it sets field3138=1 and invokes
SetCharacterTint(0xB1,10). That original direct call resolves to
0x00410AC0. The 80-byte RemoveLocalEffect(short) clears the
indexed entries in all three field3154/field3254/field3354
effect-array banks, then calls the original Secondary base
RemoveLocalEffect at 0x00412E60. The class layout already
had those same fields; no provisional header edits are needed.

Reproducible selected match units character-09-slot08 and
character-09-remove-local-effect are in config/match-units.toml;
their full receipts are in
docs/evidence/character-09-slot08-exact.json and
docs/evidence/character-09-remove-local-effect-exact.json.
Each function was compiled and compared separately, not as
part of a whole-game cold replay. Whole-game linkage and
runtime behavior remain open.

<a id="sayuri-slot04-action-boss-reviewed-prefix"></a>

<a id="sayuri-slot05-cpu-reviewed-prefix"></a>

<a id="nayuki-lifecycle-and-virtual-leaves-exact"></a>

<a id="nayuki-slot02-command-reviewed-prefix"></a>

<a id="nayuki-slot05-cpu-reviewed-prefix"></a>

<a id="nayuki-slot04-action-reviewed-prefix"></a>

<a id="nayuki-slot01-render-exact"></a>

## Nayuki Character10 Slot01: complete 939-byte strict Exact render owner

Original Character10/Nayuki vtable slot01 at 0x00788274
points to 0x00463DD0. Complete owner
[0x00463DD0,0x0046417B) contains **939 original bytes /
280 original x86 instructions** and five trailing CC
alignment bytes. Canonical target SHA-256:
5b69c934c7e73d23c52e191823b171281fcd05ded00dc3ef112c9060e751bc35.

Complete natural C++ source is src/Character10Render.cpp.
Pinned VC7.1 /Od /G6 /MT /Gy /W3 compiles
**939/939 strict Exact original code bytes** with **8/8
original-bound REL32 calls**, zero differences, and the
original 0xF4 stack frame. Six calls are MakeSurfaceRect
at 0x0040C590 and two Video::DrawSurface at
0x00409A90. The complete original direct operands,
replay acceptances and full hash match are recorded at
docs/evidence/character-10-slot01-exact.json, selected
recipe character-10-slot01 in config/match-units.toml.

The native source reproduces two sprite layers:
patterns[44] and patterns[34 + field3148], both
using first animation frame; original left/right
coordinate formulas include 2−u, 280+u and 280−u,
with 191−v vertical coordinate. The original
source/destination SurfaceRect copies, texture and
palette arguments follow the exact original order.
No machine byte patches, hand-authored assembly,
full cold replay or whole-game runtime claim.

<a id="nayuki-slot07-effects-exact"></a>

<a id="nayuki-slot06-state-prefix"></a>

## Nayuki Character10 Slot06: COMPLETE 63,551-byte Exact native owner

The original `Character10::Slot06` vtable entry at **0x00788288**
selects all **62,693 code bytes** at `[0x00451850,0x00460D35)`,
SHA-256 `4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9`.
Its **two adjacent function-local switch tables** are owned by this
same original compiler contribution: 138 four-byte destination
addresses at `[0x00460D35,0x00460F5D)` (**552 bytes**) and 306
selector bytes at `[0x00460F5D,0x0046108F)` (**306 bytes**).
They dispatch **137 live and 169 default IDs**. The physical code
order includes state300 between states278 and279, not numerical order.

**All 63,551 bytes of this complete code-and-table contribution are
now formally Exact using authored natural C++** in
`src/Character10State.cpp`. Pinned VC7.1 `/Od /G6 /MT /Gy /W3`
reproduces the **original full 0x2B4 stack frame** and all 137 native
case bodies plus default, with the same internal switch-table layout
and shared function return. The strict original-bound single-unit
oracle replays **all 1,433 COFF relocations**, none masked: 951
original IEEE-754 references, 342 original external REL32 calls and
140 local DIR32 pointers (including all 138 destination entries and
two code-to-table pointers). Rebound object and original EFZ.exe
are exactly equal, **63,551 / 63,551 bytes, zero differences**,
complete extent SHA-256
`8f5e61f2f1d379fa9ab1f943e53a678fe4756886cb00129bcbaeae6dac8efec4`.

Strict selected evidence and frozen recipes:
`docs/evidence/character-10-state-slot06-exact.json`,
`config/match-units.toml` unit `character-10-state-slot06` and
`config/matches.csv`. Reproduce *only this unit* with:

    scripts/repo-python scripts/replay-exact-units.py --unit character-10-state-slot06
    scripts/repo-python scripts/validate-tracking.py --check-proofs --unit character-10-state-slot06

The prior incremental source remains in `workbench/nayuki-state` as
a construction history; production-tracked source is `src/Character10State.cpp`.
Unlike earlier partial snapshots, this certificate compares the
**full original owner**, not a prefix or placeholder case.
**Codegen Exact does not establish full game linkage, original
translation-unit partitioning, runtime parity or portability.**

## Nayuki Character10 Slot07: 20,517-byte native Exact effects boss plus owned switch tables

Original Nayuki Character10 virtual slot07 at vtable
0x0078828C selects [0x00468870,0x0046D895),
**20,517 exact original code bytes / 4,644 x86
instructions**, SHA-256
cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9.
The owner also contains exactly **212 adjacent
local table bytes**, comprising the original 28-entry
**112-byte switch-address table** [0x0046D895,0x0046D905)
and the **100-byte compact case-index table**
[0x0046D905,0x0046D969). Full native contribution
[0x00468870,0x0046D969): **20,729 bytes**,
SHA-256
4ec9ad4dc0449c55bcf3e36388c4a20c61274d359b2cf2686a201d6efc42e41c.
The tables are independently accounted for as
owned *data*, not code instructions.

Complete naturally authored C++ is
**src/Character10Effects.cpp**. It implements the
canonical **27 live switch cases** 0x190–0x1A1,
0x1AB–0x1AE and 0x1EF–0x1F3, including Nayuki
particle lifetimes, grounded and airborne bounce,
direction checks, camera bounds, child effects,
sound/shake output and the final owner return.
Original source reconstruction uncovered **32
unrelated sibling-only case labels** in the early
compilable experiment; removal recovered the
original 27-case dispatch ordering and the exact
canonical source-code layout. These old experimental
cases remain recoverable in Git history.

Pinned VC7.1 /Od /G6 /MT /Gy /W3 now emits
**20,729/20,729 Exact original code+local-data bytes**,
the original complete 0x1D4 stack frame and all
original control flow, with **264/264 original-bound
COFF relocations** across 73 uniquely bound symbols.
Of those 264 relocations, 30 refer to internal
switch labels/owned code and 234 to original
external calls or data references, all proven.
Both original 112/100-byte tables are exact.
No differing instruction, byte, float literal,
original call target or relocatable table entry
remains. Selected one-unit cold replay returns
**Exact** with zero differences.

Full proof: docs/evidence/character-10-slot07-exact.json.
Native recipe: character-10-slot07 in
config/match-units.toml; compare only this unit
with scripts/repo-python scripts/replay-exact-units.py
--unit character-10-slot07. No inline assembly,
manual padding or byte masks, and no full-game
cold replay was used. Whole-game linkage and
runtime-equivalence remain separate acceptance tasks.

## Nayuki Character10 Slot04: complete 10,605-byte strict Exact action boss

Original Nayuki vtable slot04 at 0x00788280 selects
[0x00461460,0x00463DCD), exactly **10,605 x86 code
bytes / 2,690 original x86 instructions**, with three
CC alignment bytes afterward. Original whole-function
SHA-256: 9b36e02745b63428693a1fd39258d2fbbbccfdc120f2d16d915073fedde5806d.

Full natural C++ is now **src/Character10Action.cpp**.
Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces the
original 0x14 stack frame, preserved EBX, original
shared exit, and **10,605/10,605 strict Exact code
bytes** with **86/86 verified original-bound COFF
relocations**. All eleven referenced symbols uniquely
bind their reviewed original targets, including IEEE-754
literals and Secondary::ClearBufferedButtons and
FaceOpponent direct calls. The full strict byte compare
and selected-only cold replay both yield **Exact,
zero byte differences** with matching SHA-256.
Full evidence: docs/evidence/character-10-slot04-exact.json;
rebuild recipe: character-10-slot04 in config/match-units.toml.

Original Nayuki-specific command priorities are restored:
0x34 cancel, meter moves 0x61 / 0x66/65/64 / 0x70/6F/6E,
0x48/47/46, 0x1E/1F/20, 0x16/15/14, unique 0x0D,
0x0C/0B/0A, air dash and ground dash, and the four
attack-button priorities. The 0x1E-family permitted
frame interval includes the original dynamic sequence
268 + (field3148>6)*10 and exceptions 0x108/0x109:
the natural expression made VC7.1 allocate EBX and
restore the original push/pop instructions. Nayuki's
variable air-dash count limit, A3→E6/E7/E8 and
CA→D6 action variants, C9 and CD permission
overrides, D2 special attack, final 0x103/0x118
fourth-button selector and ±80.0 attack spacing
are recovered with the correct original near JMP
return placement and original field inputY at 0x189.

No manual machine-code patches, inline asm or
artificial padding were used. The complete dirty
workbench C++ was reconciled into the accepted
source before retirement. This is exact native
codegen for one owner, not whole-game linkage
or runtime equivalence. No full all-unit replay.

## Nayuki Character10 Slot05: complete 13,259-byte strict Exact CPU boss

Original Nayuki Character10 vtable slot05 at 0x00788284
selects 0x004654A0, canonical complete owner
[0x004654A0,0x0046886B): **13,259 original x86
code bytes / 3,391 instructions**, followed by five CC
alignment bytes. Original full-owner SHA-256:
fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce.

The full natural C++ source is now **src/Character10Cpu.cpp**.
Pinned native VC7.1 /Od /G6 /MT /Gy /W3 reproduces
**13,259/13,259 original code bytes**, the complete
0xC0 stack frame and original shared return, and
**232/232 independently canonical-bound COFF relocations**
spanning **39 unique original symbol references**. Exact
IEEE-754 float literal payloads and RandomRange, CRT
fabs and CollisionSide callees were checked against
the original executable, with zero bytes differing.
The strict compare and **selected one-unit cold replay**
both return **Exact**. Evidence:
docs/evidence/character-10-slot05-exact.json;
reproducible recipe character-10-slot05 in
config/match-units.toml. No full-game cold replay or
runtime/linkage equivalence claim.

Restored natural behavior covers Nayuki-specific
A8/A9/AA special priorities, CPU state 4–10 recovery,
FA/FC timed counters, 0x10C four-button chain,
all C8/C9/CA/CB/CC/CD/CE/CF/D0/D1 collision
follow-up trees, and complete generic grounded/airborne
CPU policy and randomized movement cooldowns. Important
original distinctions were independently recovered:
35/50 near-range windows, meter/field3148-conditioned
action timing, dynamic opponent-state timers with
150/300/20 weighted offsets and **constant-first
addition needed for canonical register LEA ordering**,
grounded second proximity permission, original
3.0f/4.0f probabilities and 90-frame movement
generation with 40% branch threshold. The original
conditional priorities and even contradictory checks
remain in natural source. No byte patching or injected
assembler was used. The old dirty workbench C++ was
reconciled into the full accepted source before retirement.

## Nayuki Character10 Slot02: full 4,827-byte strict Exact command boss

Character10 vtable slot02 at 0x00788278 points to 0x004641C0.
The original full code range [0x004641C0,0x0046549B)
contains **4,827 bytes / 1,395 i386 instructions**,
followed by five CC alignment bytes. Target SHA-256:
0fed5a3c7f5af912bee361dd49a78286b10d147ef9ec10589627b5785213d6c6.

Complete natural C++ source is now src/Character10Commands.cpp;
pinned VC7.1 /Od /G6 /MT /Gy /W3 recreates **4,827 /
4,827 exact original code bytes**, original 0xC
stack frame and full shared return, with **zero
relocations and zero differing bytes**. Entire
one-unit selected replay returns strict Exact.
Acceptance evidence: docs/evidence/character-10-slot02-exact.json;
recipe: character-10-slot02 in config/match-units.toml.

The original 15 priority-ordered circular input-history
scans are restored: 0x6E, 0x64, special
0x61, 0x46, 0x14, 0x0A, 0x28, 0x1E,
five-frame button-6, 0x35/0x34/0x33/0x32
button combinations and final 1/0 alternating
direction patterns. The first two scans use distinct
left/right direction expressions, 0x61 requires
the original 0x40 button and 3000 meter,
and Nayuki 0x28 does not inherit the aerial
requirement of Sayuri. All 180-frame wrap,
staging and exact priority are preserved.
This is one full native codegen owner; no
whole-game linkage or runtime acceptance is implied.

## Nayuki Character10 lifecycle and virtual delegates: six strict Exact owners

Character10/Nayuki original vtable 0x00788270 confirms six
complete functions, reconstructed as natural C++ in
**src/Character10Lifecycle.cpp**. Complete original
code extents and selected original method identities:

- InitializeState, vtable slot 12: [0x00461260,0x004613AF),
  **335 bytes**, one original-bound Secondary::InitializeState call.
- ResetPose, slot 0: [0x004613B0,0x004613EA),
  **58 bytes**, one original-bound Secondary::ResetPose call.
- RemoveLocalEffect, slot 10: [0x004613F0,0x00461440),
  **80 bytes**, one original-bound Secondary::RemoveLocalEffect call.
- Slot03, slot 3: [0x00461440,0x00461453),
  **19 bytes**, one original UpdateLocomotionState call.
- Slot08, slot 8: [0x00464180,0x0046418B),
  **11 bytes**, no relocations, natural empty virtual.
- EmitLocalEffect, slot 9: [0x00464190,0x004641BF),
  **47 bytes**, virtual RemoveLocalEffect(effectWrite) followed
  by one original-bound direct Secondary::EmitLocalEffect call.

Pinned VC7.1 /Od /G6 /MT /Gy /W3 reproduces every
canonical native code byte: **550/550 strict Exact bytes
across six independent selected COFF units, five original
direct call relocations, zero differences**. Each selected
recipe (character-10-reset-pose, character-10-slot03,
character-10-slot08, character-10-emit-local-effect,
character-10-remove-local-effect, character-10-initialize-state)
was replayed independently with native strict Exact
acceptance. Complete provenance is in the corresponding
docs/evidence/character-10-*-exact.json receipts; there was
no full cold replay.

The 335-byte initializer resets nine Nayuki-specific
state integers (including original field3148 = 3),
sets all ten original signed-short movement/offset
constants from -58 to +36 as appropriate, and clears
all three 64-entry local effect tracking arrays before
calling Secondary::InitializeState. The effect-removal
function clears the matching indexed entries prior to
calling the original base method. These owners add no
fields or virtual declarations and leave existing
class layout untouched. Whole-product linkage and
runtime equivalence are not implied by native codegen
Exact acceptance.

## Sayuri Character09 Slot05: complete 12,330-byte strict Exact CPU boss

Original Character09/Sayuri vtable slot5 at 0x0078814C
selects 0x0044AB30; the complete code boundary is
[0x0044AB30,0x0044DB5A), exactly **12,330 original
instruction bytes / 3,172 i386 instructions**, followed
by six CC alignment bytes. Whole target SHA-256:
359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5.

The complete naturally authored source is now
**src/Character09Cpu.cpp**. Pinned native VC7.1
/Od /G6 /MT /Gy /W3 builds **12,330/12,330 byte
strict Exact** with the canonical 0xD8 stack frame,
the original shared return and **237/237 verified
original-bound COFF relocations**, zero differences.
All 36 distinct symbol references have a unique
verified original target: full IEEE-754 32/64-bit
literal payloads and the original RandomRange, CRT
fabs and CollisionSide callee addresses. The exact
certificate is docs/evidence/character-09-slot05-exact.json
and its one-unit rebuild recipe is
character-09-slot05 in config/match-units.toml.
No full-game cold replay or runtime equivalence claim.

The natural C++ restores the entire decision tree:
defensive random guards, the Sayuri-specific
140-distance 0x14 special, graded A8/A9 meter
actions, AA-state airborne reactions, CPU states
0..7, C8/C9/CA/CB/CC/CD/CE/CF/D0/D1 collision
priority, generic grounded and airborne responses,
distance windows, movement cooldown timers and
shared exit. The entire codegen was recovered
without machine-byte patches, padding or inline
assembler.

Several non-obvious original distinctions were
resolved by comparing actual source-generated
x87 instructions, branch destinations and all
relocation targets rather than accepting merely
matching function sizes. Examples: 1.0f rather
than 2.0f for the A8 early command; 15.0f
rather than 10.0f for opponent attack reaction;
opponent hitstunFrames +0x14C rather than
guardInputFrames +0x14E; the 100-unit check before
assigning the generic command; Sayuri-specific
45/60/90/110/140 grounded ranges and distinct
airborne comparison operand order; and the
movement cooldowns of 60 frames with an
80-percent branch threshold. The old partially
validated C++ workbench was reconciled into
the complete accepted source, then retired.

## Sayuri Character09 Slot04: complete 11,119-byte strict Exact

The original Character09/Sayuri vtable slot04 at 0x00788148
points to 0x00446780; the full canonical owner is
[0x00446780,0x004492EF), exactly **11,119 code bytes and
2,815 x86 instructions**, with 460 original direct jump
targets inside the function. The shared epilogue RET at
0x004492EE is followed by one CC alignment byte.
Whole-original target SHA-256:
fd248e424f2ebcdddb59462a3101f653e9931e4053d53eb2af9a067e2c0bb286.

Complete natural C++ source is now **src/Character09Input.cpp**.
The pinned VC7.1 /Od /G6 /MT /Gy /W3 compiled source
matches **11,119/11,119 original bytes, 2,815 original
instructions, the original 0x14 stack frame and 95/95
canonical COFF relocation fields with zero differences**.
All 12 unique symbol destinations are verified against original
PE operands, including original 500.0, 0.0, -40.0, +/-70.0,
+/-100.0 and +/-30.0 IEEE-754 literals and original calls
to SetCharacterTint, ClearBufferedButtons and FaceOpponent.
Proof: docs/evidence/character-09-slot04-exact.json.
Accepted selected unit: character-09-slot04 in
config/match-units.toml. No full-game cold replay or runtime
equivalence claim is involved.

The recovered source covers buffered-input expiration,
character command/animation gating, meter-based special
priority, aerial and grounded state transitions, mirrored
A3/A4 ground and A5/A6 air dashes, one-use command-6 air
action, and three independently buffered attack buttons
leading to 0xC8–0xD1, 0xF8 and 0xDC families.

Two critical original control-flow details were corrected
through prefix validation: the field015c < 2 early gate
skips the full high-priority command chain, not only the
first few commands; and airborne button attacks exit the
priority handler even when their eligibility test fails.
A final original operand review found inputX at +0x188
in the grounded third-button/0xDC decision, not
buttonPulse[0] at +0x18A. Source expresses the original
direction multiplications (including * -1 rather than
negation) to preserve VC7.1 register and x87 operations.
The earlier partial workbench is retired after verifying
that its effective changes are preserved in accepted source.
Whole-product linkage and runtime equivalence remain open.

<a id="sayuri-remaining-leaf-delegates-exact"></a>

<a id="sayuri-lifecycle-and-delegates-exact"></a>

<a id="sayuri-slot02-command-prefix"></a>

## Sayuri Character09 Slot02: complete 5,995-byte strict Exact

The original Character09/Sayuri vtable slot02 at 0x00788140
points to 0x004493C0, a complete natural code owner at
[0x004493C0,0x0044AB2B): **5,995 instruction bytes /
1,752 original i386 instructions**. Five following CC
alignment bytes precede the next 0x0044AB30 function.
Canonical original full-owner SHA-256:
e4aa3f06f35134fcecf1fc29caee30cacfc38fcad71244148689c41e17212436.

The full authored C++ source is now **src/Character09Commands.cpp**,
selected reproducible recipe character-09-slot02 in
config/match-units.toml. Pinned VC7.1 /Od /G6 /MT /Gy /W3
emits **5,995/5,995 matching original bytes** with
the full 0xC stack frame, all 1,752 original instructions
and **8/8 independently target-bound COFF relocations**.
All eight original double constant operands point to
the verified zero IEEE-754 payload at 0x007872F8.
The complete native strict comparison and single-unit
cold replay both return **Exact, zero differences**.
Proof: docs/evidence/character-09-slot02-exact.json.

The original ordered circular input-history interpreter is
fully reconstructed. It comprises scans for advanced meter
commands 0x62, 0xAA, 0xA0, 0x64, 0x6E, 0x46,
0x14, 0x0A, 0x28, 0x1E; a five-frame
0x06 button transition; four-stage 0x35, 0x34,
0x33, 0x32 buttons; and final alternating-direction
commands 1 and 0. The original 180-frame history
index wrapping, precise time windows, facing, stage,
meter, ground and aerial permissions are preserved.
Notably, the 0x14 scan starts grounded, while the
0x28 scan must start airborne: original x87 code
verified the semantic difference and rejected an
initial wrong ground check during reconstruction.
All intermediate prefix branch-target and float-literal
audits were superseded by this entire-function Exact
result, with no injected assembly or generated byte
patches. This acceptance covers one codegen owner,
not whole-product linkage or runtime equivalence.

## Sayuri Character09 native lifecycle: ResetPose and InitializeState exact

Two newly authored lifecycle functions are recovered from the
original Character09/Sayuri vtable. Slot 0 at
0x00788138 points to Character09::ResetPose at 0x004466D0
[0x004466D0,0x0044670A), **58 bytes**, with six following
CC alignment bytes. Slot 12 at 0x00788168 points to
Character09::InitializeState at 0x00446590
[0x00446590,0x004466C5), **309 bytes**, with eleven CC bytes
before the ResetPose function. Both target extents and
ownership were independently reviewed.

The natural source src/Character09Lifecycle.cpp compiles under
pinned VC7.1 /Od /G6 /MT /Gy /W3 to **58/58 and 309/309
strict Exact** with one original-bound REL32 relocation
per owner and zero differing bytes. ResetPose clears the three
Sayuri animation state dwords then delegates to the original
Secondary::ResetPose at 0x0040F110. InitializeState resets
the Sayuri-specific counters, sets field3150 to 999, reproduces
all ten signed short movement/offset constants in the original
field2ad0/field2af8 layout, clears the three 64-entry effect
owner banks, then calls Secondary::InitializeState at
0x0040EDF0. The loop's original unoptimized integer code and
stack homes agree without padding or handwritten instructions.

Only the two selected units character-09-reset-pose and
character-09-initialize-state were cold-replayed independently.
The receipts docs/evidence/character-09-reset-pose-exact.json
and docs/evidence/character-09-initialize-state-exact.json
are full-authority **per-function native codegen** acceptance,
not a claim of complete-game linkage or runtime equivalence.

## Sayuri remaining virtual leaf/delegate owners: three strict Exact matches

Three additional Sayuri/Character09 virtual functions have been restored
from the canonical vtable at 0x00788138. Slot01 at vtable 0x0078813C
selects [0x004492F0,0x004492FB), **11 bytes** of empty natural
C++ code in src/Character09Delegates.cpp; the five following CC
alignment bytes are excluded. Slot03 at 0x00788144 selects
[0x00446760,0x00446773), **19 bytes**, delegating to
Secondary::UpdateLocomotionState at original 0x0040E740.
The thirteen following CC bytes are excluded.
EmitLocalEffect at slot09 (vtable 0x0078815C) selects
[0x00449390,0x004493BF), **47 bytes**, in
src/Character09EmitEffects.cpp. It first calls Sayuri's
virtual RemoveLocalEffect(effectWrite) via the original
slot10 vtable dispatch, then directly calls the accepted
Secondary::EmitLocalEffect(effect) base implementation at
0x00412B10. Only the latter is an explicit COFF relocation;
one CC byte follows this owner.

All three were built and independently strict-compared under
pinned VC7.1 /Od /G6 /MT /Gy /W3:
**11/11, 19/19 and 47/47 matching code bytes**;
0, 1 and 1 original-bound relocations; **zero byte differences**.
Their selected recipes and evidence are respectively
character-09-slot01,
character-09-slot03,
character-09-emit-local-effect in config/match-units.toml and
docs/evidence/character-09-slot01-exact.json,
docs/evidence/character-09-slot03-exact.json,
docs/evidence/character-09-emit-local-effect-exact.json.
No other accepted sources or common class-layout declarations
were edited; runtime/whole-game linkage remains unverified.

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

Sources: `src/Character08Effects.cpp` and `src/SecondaryEffectControls.cpp`.
Public comparisons: `character-08-exact.json` and `secondary-effect-controls-exact.json`.

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

`Scene3::ResolvePushboxes` at `0x00766B50` is a complete 2,727-byte Exact
owner with 35 relocations. Source: `src/SceneBattlePushboxes.cpp`; recipe:
`scene-battle-resolve-pushboxes`; comparison: `docs/evidence/scene-pushboxes-exact.json`.
Reviewed game callees are `CollisionSide` at `0x0040FF70`, `TransformPoseBox`
at `0x00767600` and `BoxesOverlap` at `0x00767930`.

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

Earlier Pushboxes experiments tried declaration order, aggregate locals,
explicit pointer lifetimes, comparison rewrites and `/O1`/`/O2`. None solved
the original stack layout. The useful correction was to retain the standalone
conditional expressions and put both returns at the original branch scope,
as described above. Accepted source: `src/SceneBattlePushboxes.cpp`.

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

An earlier union experiment overwrote a still-live horizontal displacement
with a boundary Boolean before both position updates consumed it. Keep these
live values separate; instruction-count similarity did not expose that error.

The five Video pixel owners at `0x409A90`, `0x40A0B0`, `0x40A440`, `0x40A7B0`
and `0x40AAE0` have natural C++ candidates in `src/VideoCharacterDraw.cpp` and
remain open for strict exact codegen.

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
parser errors involving a frame width name and a spaced dereference; the errors were corrected before subsequent comparisons. Original branch/literal order and ordinary subtraction resolved
the complete differences. Final formatting/comment cleanup also received full
native comparisons. There are no assembly, copied bytes, padding fields,
masked fields or shortened-prefix comparisons.

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
exactness credit is assigned. Use target disassembly to review these instructions.

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

FillRectangle at `0x40B300` remains open: complete review found a second
body-local EDI save/restore around a register pixel loop, consistent with
handwritten assembly. Its decompile alone is not evidence for a permitted
natural C++ exact implementation.

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
do not repeat them without new evidence. The complete draft in `workbench/prepare-battle/` includes random/replay/CPU/stage
preparation and the disabled BMP branch. The
confirmed background scale for stage 16 is 0.125, otherwise 1.0; CPU division is
by 1.5f. These correct the decompiler's lost constant types and initial guesses.
Use the workbench README for its selected build command.

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

PrepareBattle was tested with the accepted real background layout, base
inheritance and declarations. Its 4,031/4,029 extent and first GPR divergence
at `0x76D743` were unchanged. Do not repeat this type/layout hypothesis
without new evidence.

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

## Makoto local effect dispatch and controls

Character03::Slot07 at0x5FF4C0 is complete strict exact in
`src/Character03Effects.cpp`:33,673 instruction bytes plus224 local-table bytes,
total33,897; complete exclusive end607929. Code ends607849. The31-entry DWORD
address table occupies607849..6078C4 and100 selector bytes occupy6078C5..607928.
Seven excluded CC bytes precede next prologue607930. Vtable788AC8 slot07 operand
788AE4 contains5FF4C0. Public proof:`docs/evidence/makoto-effects-exact.json`;
recipe:character-03-update-local-effects, pinned vc71-od-static.

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

## Scene2 PrepareBattle owner boundary

`Scene2::PrepareBattle` is a substantial, authored member function at
`0x0076CA50`. The accepted `Scene2::Step` directly calls this exact
address from instruction `0x0076C8FD` (`E8 4E 01 00 00`), proving
its real receiver/call-site relationship rather than relying on a
provisional decompiler signature. Independently rechecked canonical
EFZ.exe bytes establish the following **4,029-byte** full contribution:

- x86 code `[0x0076CA50,0x0076D985)`, **3,893 bytes**, original
  `55 8B EC` prologue and shared `RET` at `0x0076D984`;
- first address table `[0x0076D985,0x0076D9E9)`, **100 bytes** with
  25 distinct in-code branch destinations;
- background address table `[0x0076D9E9,0x0076D9FD)`, **20 bytes**
  with five more distinct in-code destinations;
- selector `[0x0076D9FD,0x0076DA0D)`, **16 bytes**, choosing
  index 4 (default) 12 times and indices 0–3 once each.

The full target SHA-256 is
`1b529588799198f4fd6d913e877c029fe53e129cccb391a928cea0a1dae03d99`,
followed by three `CC` alignment bytes and the next function's
prologue at `0x0076DA10`. The proof
`docs/evidence/prepare-battle-boundary-review.json` grounds every
boundary/table/caller claim. Origin and complete boundary are now
reviewed in the ledgers, **not the codegen or Exact source status**.

The complete natural C++ candidate, provisional local headers,
reproducible VC7.1 build and six tested background-construction
variants are tracked in `workbench/prepare-battle/`. Its selected
`/Od /G6 /MT /Gy /GS /W3` compile still has **4,031 bytes with
115 relocations**, versus the 4,029 original owned bytes; original
register choices at `0x0076D743` and an extra two-byte receiver move
remain. No target bytes have been masked, and no full cold replay
was performed. Do not copy private header views into accepted `src/`.

## Shiori state owner boundary and selector review

Target `0x004136D0` is an authored, non-thunk `Character08::Slot06`
state dispatcher. The original Character08 virtual table at
`0x00787DF8`, slot-6 pointer at `0x00787E10`, contains this exact
entry, and the original body contains 134 explicit animation
branches plus a true default path. An independent read of canonical
EFZ.exe bytes confirms the complete owned extent:

- **62,273 instruction bytes**, `[0x004136D0,0x00422A11)`, ending with
  the original `pop edi; pop esi; mov esp,ebp; pop ebp; ret` epilogue;
- **540 address-table bytes**, `[0x00422A11,0x00422C2D)`, with 135
  distinct DWORD branch destinations, *all* inside that code extent;
- **319 selector bytes**, `[0x00422C2D,0x00422D6C)`, mapping
  animation IDs 1–319 to those 135 entries; index 134 (default)
  occurs **185** times and each explicit index occurs once.

The complete 63,132-byte owner has SHA-256
`b677461e2b0e0104de11fc3ed40c47545c86ea0f02c4d6dc68437e0ea475aded`.
Four `CC` bytes align to the next constructor's `55 8B EC` prologue
at `0x00422D70`. Function origin and complete boundary are now
formally reviewed with the independently checked byte report
`docs/evidence/shiori-state-boundary-review.json`. This is a
**boundary/origin review, not a claim of source or codegen Exact**.
The full, still-unaccepted natural C++ candidate and its isolated
provisional views are tracked in `workbench/shiori-state/`. A fresh
single-unit VC7.1 build emits 63,133 bytes, not the target 63,132,
and register/branch-byte mismatches remain in the late states.
The candidate must not be accepted until the full code, both tables
and every relocation strictly compare. No cold replay was run.

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
recorded in `docs/evidence/makoto-state-case-map.csv`.

The selector map ends at `0x5F6D8C`. Four `CC` bytes follow, and the next
Character03 constructor begins at `0x5F6D90`. The complete owned code-plus-table
extent is therefore `[0x5E85F0, 0x5F6D8C)`, 59,292 bytes. The function boundary
and authored origin are reviewed in the ledgers. The complete natural
source and strict code-generation match have now been independently accepted
(see immediately below); only linked-product/runtime closure remains open.
The Ghidra switch-normalization warning remains provisional and was never
used as an authoritative animation-ID mapping.

### Exact acceptance of Makoto's full 59,292-byte state owner (2026-11-09)

Natural C++ accepted source: `src/Character03State.cpp` implementing
`Character03::Slot06`; selected VC7.1 unit `character-03-state-slot06`;
public strict proof `docs/evidence/nagamori-affected-consumers-exact.json`.
Unlike the earlier workbench-only checkpoint, this is a complete
**59,292/59,292 byte** source reconstruction: **58,482 code bytes**,
**500 switch-address bytes** and **310 selector bytes**. The full native
COFF has **1,386 explicitly declared relocation entries**, comprising
**369 REL32 external** operands, **890 DIR32 external** operands and
**127 DIR32 internal branch/table** operands. Original target bytes
and compiler addends give **220 distinct symbol target addresses**;
all multiple uses agree, and all 127 internal destinations match exact
compiled function-local offsets. Every original x87 double constant
was checked against its encoded IEEE-754 bytes in EFZ.exe. The complete
strict native oracle reports `result=exact`, zero different bytes and
relocated/target SHA-256
`430e18ae01c539e7b2b93228261cba667760633e16e0a10769910ece8aea3d2d`.
No relocation sites or selector bytes were masked, skipped or substituted.

The important natural-codegen change is a small `FrameTiming` struct
whose two 16-bit members are individually 4-byte-aligned. It puts the
source timing cache at original stack addresses `[ebp-0x8]` and
`[ebp-0x4]` while retaining the `EffectSpawn` local at `[ebp-0x50]`.
The prologue, all 125 dispatch addresses, complete code and both tables
then align exactly; this was verified after copying the source into
`src/` and using its actual selected unit, not just a workbench trial.
All 124 explicit state arms and the unmapped-state default are included.
Earlier attempt notes about an unresolved case-70 six-byte drift,
missing state branches or uncertain table ownership are superseded.
This does **not** claim complete game linkage, runtime equivalence or
freshness of unrelated historic receipts. Only targeted builds were run.

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
substitute for checking the accepted Makoto state function's own
strict code-generation and relocation proof.

## Legacy bitmap-to-object converter

The target contains a complete authored, zero-argument conversion helper at
0x004019B0 to 0x00401C16 (614 bytes), immediately followed by ten CC
alignment bytes and the next function at 0x00401C20. The canonical extent
SHA-256 is ad527aa021a9503f037a53e6ff18f211b04c3610f41de1a20f6d781ff76c0b1f.
The function has no known incoming direct calls; it may be a retained tool
routine rather than a production startup path. Origin is classified as authored,
not a C runtime or compiler-generated helper.

The natural C++ source src/LegacyObjectConverter.cpp reconstructs a one-pass
loop that builds numbered ayu0\ BMP and ayu\ DAT names but, remarkably,
actually opens the fixed paths system0\object.bmp for reading and
system\object.dat for writing with OPEN_ALWAYS. It reads the entire BMP,
allocates size - 10 output bytes, skips the first ten input bytes, XORs each
remaining byte with decimal 100, writes the result, closes both handles and
deallocates both arrays. No sanitization, error recovery or path substitution
was added: the unusual fixed path and size-underflow behavior are in the
original instructions. No claim is made that executing this helper is safe for
arbitrary external files.

VC7.1 /Od /G6 /MT /Gy /GS /W3 generates 202 instructions in exactly
614 bytes. Natural structures grouping the two filename buffers and the seven
per-iteration locals recover the original stack slots, including a distinct
WriteFile size copy. The complete native COFF contains 37 individually
reviewed relocations (original named CRT calls, Windows PE import-table slots,
the security cookie/checker and original string literal locations). The
original encoded operands, literal bytes and unique symbol destinations were
independently checked against EFZ.exe. A successful strict receipt is kept
in docs/evidence/legacy-object-converter-exact.json; it covers **all** bytes
and relocation sites, not merely the disassembled instruction forms. Neither
whole-product linkage nor runtime equivalence is established by this owner.
