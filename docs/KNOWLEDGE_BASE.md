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
and the software conversion kernel remain open despite their exact callers.

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
transition are also exact. At that checkpoint render and character-object construction remained open;
the subsequent rendering section records its acceptance. The later creation-dispatch section records its acceptance; the external
character constructors and pixel kernels still prevent callee/product closure. Public proof is
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
accepted. DrawSurface and its software conversion callee also remain open.


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
additional 501-element arrays or initialize different state/resource fields;
those complete bodies remain separate recovery work. Reuse of Nayuki's
constructor by ID 22 is target evidence, not a guessed extra subclass or name.
The canonical original resource literals and every constructor's raw disassembly
are retained privately with the independent boundary/allocation review.

The common base constructor candidate 0x40EAE0 is 463 bytes and lifetime body
0x40ECB0 is 313 bytes. Their local target-attested decompiles are retained, not
accepted C++ source. The base vtable at 0x787BCC has thirteen observed entries:
0x40F110, eight 0x77893D purecall entries, then 0x412B10, 0x412E60, 0x410B70 and
0x40EDF0. Full virtual signatures and source declarations need caller/body review
before implementing constructor vptr writes naturally. Do not use fabricated
ABI declarations or manually assign a vptr to bypass that work. The existing
minimum Secondary view does not model those virtual methods or imply their
absence from the original class.

The original base constructor stores the opponent slot at 78 before calling the
embedded constructor on this+2BC0, then stores Context/Video/Input/Audio at
7C/80/84/88 and the player byte at 8C. This ordering suggests a pointer member
initializer followed by automatic embedded-member construction before the body;
recheck that ordinary C++ model with the first full native build. The embedded
constructor writes a short at offset 4F4 and bytes at 0/2, while both distinct
8-byte array-element constructor bodies clear only their dword at +4 and return
this. Virtual slot zero at 0x40F110 resets shorts at A/C, a double at B8 and ints
at 168/170, then calls 0x412910. These target facts are not implementation credit.
