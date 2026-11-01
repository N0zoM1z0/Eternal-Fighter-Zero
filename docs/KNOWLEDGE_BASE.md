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
