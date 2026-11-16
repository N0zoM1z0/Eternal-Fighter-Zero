# EFZ reconstruction handoff

Follow [AGENTS.md](../AGENTS.md). Current accepted source is `src/`; counts
come from [PROGRESS.md](PROGRESS.md) and the canonical ledgers. Search the
relevant sections of [KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md) for target facts
and failed hypotheses. Inspect current Git changes before starting.

## Receiving agent — Nayuki state boss completed (2026-11-11)

**Character10::Slot06 now has a COMPLETE original-bound Exact codegen
certificate**, not just a selected prefix. Its authored source is
`src/Character10State.cpp` with 62,693 canonical code bytes plus
all 858 local switch-table bytes, **63,551 / 63,551 matched** and
**1,433 original-bound COFF relocations independently verified**.
All 137 original live case IDs, original physical code order, complete
0x2B4 stack frame, both native switch tables and shared return are
closed. Formal evidence:
`docs/evidence/character-10-state-slot06-exact.json`.
Read [the full reconstruction record](../workbench/nayuki-state/README.md)
for the original incremental state and repair history.

Run ONLY selected checks when working on this owner:

    git status --short --branch
    scripts/repo-python scripts/replay-exact-units.py --unit character-10-state-slot06
    scripts/repo-python scripts/validate-tracking.py --check-proofs --unit character-10-state-slot06
    scripts/repo-python scripts/ci.py

Do not run all-unit cold replay, do not push without permission.
Continue attacking other substantial unimplemented functions and
small exact leaf owners. Preserve dirty edits (single writer).
Native codegen Exact is *not* a whole-product/runtime completion claim.

## Active next boss: Kano Character20::Slot06 (partial)

Original Kano `Character20::Slot06` owns **68,853 native code bytes**;
its authored C++ `workbench/kano-state/Character20State.cpp` now
reproduces selected original `[0x006429C0,0x0064C750)`, **40,336
bytes / 11,096 x86 instructions**. Default plus **102 live cases**
reviewed. The strict checker binds **1,032 internal / 136 outbound
original branch targets**, **906 native-bound nonlocal COFF calls/
IEEE-754 references** and two original switch addresses.

The new **822-byte state249** implements a long original airborne
throw: opponent facing/position and animation changes on frames0–5,
damage `ApplyDamage(1200,500.0)`, opponent knockback (-1.0,-2.3),
original horizontal shake and offset, strict landing threshold,
frame12 gravity and frame-loop exit. **Next case250 starts at
`0x0064C750`**. Candidate stack0x148 vs original0x4A4 uses equal
six-byte allocation width without offset normalization.
**34 missing native case bodies**, original full frame, local switch
DATA and shared return are OPEN; NOT whole Exact. Markers unaccepted.
Only scoped Kano checker, no full all-unit cold replay or push.

The next Kano state250 at `0x0064C750` has authored exploratory
charge/dual-effect C++ but is **not native-reviewed yet**. The local
probe first differs in register assignment at `0x0064C955` during
the animation rewind tail; the original 585-byte case is not accepted.
See `workbench/kano-state/README.md`; preserve and refine this work.

Kano experimental case251 has also been authored in
`workbench/kano-state/Character20State.cpp`, including the original
500/250 resource reduction and two local effects. The new scoped
`workbench/kano-state/check_case251_shape.py` checks all 454 native
bytes' instruction locations/widths, 117 register-abstracted opcode
forms, 7 original internal jump edges and 7 independently bound
native COFF operands. It is **NOT Exact** because scratch registers
and one equivalent ADD encoding differ; original case250's tail also
remains open. No new complete function or selected-prefix credit.
See the Kano README for the precise scope and mismatch evidence.

Kano case254 now also has **835 bytes / 223 original instruction
positions and register-abstracted shapes** from authored natural C++.
The separate `workbench/kano-state/check_case254_shape.py` verifies
20 native internal branches, 3 shared-return jumps and 10 independently
original-bound COFF call/float operands. This is **NOT Exact**:
concrete register bytes still differ after the unresolved case250.
The contiguous selected prefix remains 40,336 bytes; Kano state251
and state254 are structural islands, not formally accepted owners.
Real original code correction included grouped facing/input offset
arithmetic and the `owner` (not `field0028`) effect field.

Kano cases255/256 are now also authored as full separate tiered
charged attack bodies (858 bytes each). Their dedicated original-bound
`check_case255_256_shape.py` audit verifies **456 x86 original
instruction offsets and register-abstracted forms**, **40 native
internal and 6 canonical shared-return jumps**, **20 independently
bound original COFF call/float operands**. Correct distinct full-
charge fallback values 5000/2500, launch types 0x1BC/0x1BD, meter
spend 20/50, and effect owner/coordinate grouping are coded.
**NOT Exact**: concrete native registers still differ due unresolved
state250. The strict Kano selected prefix remains 40,336 bytes.
See Kano README. No cold all-unit replay.

Kano case257 is now also authored as a **899-byte complete natural
C++ state body** with dedicated original-bound *structural* diagnostic
`workbench/kano-state/check_case257_shape.py`: all 241 x86 native
instruction offsets/register-abstracted forms, 22 internal branches,
3 shared-return targets and 10 original-bound native COFF call/float
operands match. Its frame17 0x191 effect differs from other charged
tiers, as does frame19 rewind and `field316c` counter.
**NOT Exact**: the contiguous strict prefix remains 40,336 bytes
because state250's concrete-register mismatch is still open. This
work is documented and committed, not added to Exact ledgers.

Kano state257 adds another **899 bytes of natural C++ source** with
original native structural proof: 241 instruction positions/forms,
22 internal and 3 canonical return branches, ten original-bound COFF
call/float references. The tier-specific frame17 effect0x191 and
frame19 repeat differ substantially from prior tiers. The dedicated
`workbench/kano-state/check_case257_shape.py` passes and documents
the exact canonical extent/SHA. **This is NOT Exact**: concrete
register bytes still differ after original case250, so the strict
selected prefix remains **40,336 bytes**. See Kano README. No cold
all-unit replay.

Kano charged state258 now also has actual authored natural C++,
**1,254 native original bytes / 330 original instruction positions**
with a dedicated `check_case258_shape.py` audit. It independently
validates **23 native internal branches, 3 shared return paths,
14 original-bound COFF/IEEE-754 operands**, and all register-abstracted
instruction forms. Three impact effects have distinct Y offsets,
resource deduction, sound and facing/owner write order. The
**state250 register divergence remains open**, so case258 is an
unaccepted structural island, NOT complete Exact; strict contiguous
Boss prefix remains 40,336 original bytes. No cold all-unit replay.

Kano state259 has now also been authored as a **1,586-byte / 414
native-instruction** five-impact charged finisher with three
state-dependent branches. Dedicated `check_case259_shape.py`
independently validates **24 original internal and 3 shared-return
jumps**, **18 native COFF/float references**, every original x86
instruction offset/width and register-abstracted form. C++ preserves
five original Y-impact offsets, -10 meter per hit, sound and exact
conditional loop count. **NOT Exact**: the case250 compiler-phase
register divergence remains; strict Kano prefix still 40,336 bytes.
No full all-unit cold replay.

Kano state259 has additionally been reconstructed as **1,586 native
code bytes / 414 x86 instructions** with the separate original-bound
`workbench/kano-state/check_case259_shape.py` island: **24 original
internal jumps, 3 shared-return edges and 18 verified native COFF
calls/float literal references**. It restores the three staged frame17
`0x191` effect volleys (five impact effects total), frame19→16 loop,
charge residue2500 and meter10 deductions; correct original effect
owner/facing assignment order is significant. **Not Exact**:
concrete original registers remain mismatched after state250.
Selected strict prefix still ends before state250 at 40,336 bytes.
No full cold replay; do not count structural-island bytes as Exact.

Kano state260 is now also authored as an **821-byte actual C++
charged attack**, with the dedicated non-accepting original-bound
`check_case260_shape.py` checking **220 x86 original instruction
shapes/offsets**, 20 native branches, 3 shared-return jumps and
9 independently original-bound call/float operands. Its original
frame12 local effect0x1B8 uses raw X and Y=-80.0, with precise
owner/facing order, sound4, field313c=21 and field3168 counter.
**Not Exact**: state250's concrete-register discrepancy remains,
strict selected native prefix remains 40,336 bytes. Kano Slot08
independent render/periodic-effect source is also under exploration,
but has not passed original native comparison and is not registered.

Kano charged special states261/262 have also been reconstructed
in natural C++ and native-bound structurally checked. Each original
844-byte / 225-instruction case matches the register-abstracted
original with **20 internal + 3 shared-return native branches**
and **9 original COFF call/float bindings**. The completed
`check_case261_262_shape.py` records both native SHA-256 extents,
original charge5000 vs2500, launch effects0x1B9 vs0x1BA, and
meter cost20 vs50 with distinct write ordering. The two islands are
**NOT Exact** due original state250's unresolved register phase.
The strict 40,336-byte Kano prefix is unchanged; no cold replay.

Kano cases263/264 are now also authored and independently checked as
original-bound structural islands: **809+812=1,621 native code bytes /
434 x86 instruction positions**, **38 native internal and 4 shared-
return branches**, **16 original-bound COFF/float references**.
Original distinct lance offsets X+facing110/160, frame6 charge,
full-charge reset0 and frame16 repeat are recovered in natural C++.
Focused `check_case263_264_shape.py` and fast CI pass. These are
**NOT Exact**, and do not move the strict 40,336-byte Kano prefix.
No cold all-unit replay.

Kano cases265/266/267 now have genuine authored C++ for native
triple-effect attack variants, original **492+498+498=1,488 bytes**.
The focused `workbench/kano-state/check_case265_267_shape.py` checker
verifies 396 original instruction offsets/widths/register-abstracted
forms, **18 native in-state and 3 shared-return jumps**, 24 native-
bound direct calls, and all three original SHA extents. Frame3
triple effect0x1A2 uses facing-dependent X offsets 100/80/130,
180/160/210, 260/240/290 and Y offsets -480/-520/-530; original
sound6 and ResetPose/FaceOpponent order match. Structural island
ONLY, NOT Exact; strict prefix remains 40,336. No all-unit replay.

Kano state268/269 now also have real natural-C++ bodies, **447 bytes
and 123 original x86 instructions each**. Original entry halved X/Y
velocity, gravity0.01, +45 meter, a frame2 effect0x197 at X−facing30
and Y−30, frame7 up-to-three rewinds and state9/gravity0.035 exit
are source-authored. The native-bound `check_case268_269_shape.py`
audits **246 instruction positions/forms**, **16 internal and 4
shared-return branches** and **12 exact original COFF/float operands**.
Still NOT whole Exact: 40,336-byte strict prefix stops at case250.
No all-unit cold replay.

Kano state270 now has **991 original-bound code bytes / 265 native
instruction forms/widths/offsets** under authored natural C++, plus
a dedicated `check_case270_shape.py` that audits **14 internal and
2 shared-return branches** and **17 original COFF call/double
references**. The four-stage airborne0x197 effect chain, context
resource spending and frame7 recovery are reconstructed. It is an
independent structural island, **NOT concrete-register Exact**;
formal Kano selected prefix remains 40,336 bytes until case250
compiler-phase closure. No cold all-unit replay.

Kano state270 has been authored as **991 native bytes / 265
original x86 instruction locations** of a resource-costly airborne
multiwave. The scoped `check_case270_shape.py` checks all native
register-abstracted forms and widths, **14 original internal plus 2
shared return branches**, and **17 independently bound original COFF
call/float operands**. This is NOT Exact: the unresolved case250
register phase means the strict contiguous Kano prefix remains
**40,336 bytes**. Real C++ and verification are both saved; no
all-unit cold replay was run.

Kano case300 is now an independently reconstructed **1,168-byte
native super sequence**, with original SHA-256 and
`check_case300_shape.py` auditing **305 original x86 instruction
positions/widths/forms**, **27 internal and 2 shared-return branches**
and **13 original-bound COFF call/float operands**. It includes
original meter−1000, stage impact/tint, charge10000, paired local
effects, and animation loop. **NOT full Exact**: original case250
register-phase difference still blocks the 40,336-byte continuous
prefix. This is real authored C++, not neutral marker filler.

Kano state300 now has a **1,168-byte / 305-instruction original-bound
super-attack structural island**. Its C++ restores frame13 tint,
hitstun and meter spend, 0x44 context effect, frame3 dual effects,
frame16 special pulse and independent frame rewind conditions.
The dedicated `check_case300_shape.py` confirms **27 internal and
2 shared-return native branches** and **13 bound call/float operands**.
This is NOT full Exact because original state250's register mismatch
remains; strict contiguous prefix stays at 40,336 bytes.

Kano state301 C++ now reconstructs an additional **962 native
bytes / 254 original instruction forms**, including its 2,000-meter
tier, frame13 tint/freeze, frame15 effect0x1A3 and independent
six-round animation rewind. The scoped `check_case301_shape.py`
original-binds **20 internal and 2 shared-return native branches**
and **13 real call/float COFF operands**. State301 is an unaccepted
structural island, NOT full Exact; original case250 still blocks the
strict 40,336-byte continuous Boss prefix. No cold replay.

Kano state302 adds another **894 bytes / 235 native
instructions** of authored super-move code. Targeted
`check_case302_shape.py` freezes all native forms, **18 internal and
2 shared-return original jumps**, **13 original REL32 call targets**,
including SetHorizontalShake/Tint and frame13 effect0x1C1.
It is **NOT concrete-byte Exact** due state250's remaining register
phase; the strict Kano 40,336-byte prefix is unchanged. No full
cold replay or unaccepted case-marker credit.

Kano state303 has now also been authored: original **884 code bytes /
233 x86 instruction positions** of a frame14 0x19C launcher after
a 1,000-meter freeze/tint sequence. Dedicated
`check_case303_shape.py` verifies **18 in-state native branches,
2 original shared-return jumps, 13 original call/float operands**
and all register-abstracted instruction offsets/widths/forms. This
is NOT concrete-register or complete Exact; native state250 still
blocks strict Boss contiguous prefix beyond 40,336 bytes.

Kano state304 has also been fully authored in natural C++ with
**1,199 original native code bytes / 316 instruction positions**.
It has a distinct four-wave frame13 local impact chain, a
2,000-meter frame9 freeze/effect and original vertical screen shake.
`check_case304_shape.py` verifies **18 original internal and 2
shared-return jumps**, **20 original-bound native call/float
operands**, and every native register-abstracted instruction form.
Structural island only, **NOT concrete-byte or full owner Exact**;
the strict Boss prefix remains 40,336 bytes until case250 closure.

Kano state305 is now authored as a **1,109-byte / 292-instruction
native-bound structural island**. It implements original
3,000-meter super freeze, a 0x1C2 local aura and 600-tick timer,
Context::SetSceneTimer(15) and separate frame12/17 repeat gates.
Dedicated `check_case305_shape.py` verifies **23 original internal
and 2 native shared-return jumps**, **14 independently original-bound
COFF call/float operands**, all instruction widths/offsets/forms and
canonical SHA. This is **NOT Exact**: state250's concrete register
allocation divergence remains and the continuous Boss prefix is
40,336 bytes. No full cold replay.

Kano state305 original `[0x00651533,0x00651988)` is now
reconstructed in C++ with **1,109 bytes / 292 native instruction
positions** checked by `check_case305_shape.py`, including **23
internal+2 shared-return branches** and **14 independently original-
bound COFF/float operands** (including SetSceneTimer). Its timed
charge/0x1C2 aura and animation rewinds are real source, but case250
still blocks concrete-register Exact; continuous strict prefix stays
40,336 bytes. No all-unit cold replay.

Kano states306 and307 have now been reconstructed in natural
C++ as **1,658 native code bytes / 416 original instructions** with
tier-dependent meter costs, hitstop, cooldown aura launch and original
frame16 invulnerability15/45. Dedicated
`check_case306_307_shape.py` audits 38 internal and 2 original
shared-return branch targets, 18 native direct-call operands and
all instruction shapes/offsets. **NOT whole Exact**, as unresolved
case250 still blocks the 40,336-byte strict continuous Kano prefix.
No all-unit cold replay.

Kano states308/309 are now native-authored natural C++:
**1,757 original code bytes / 454 original x86 instructions**,
with focused `check_case308_309_shape.py` validation of **38 internal,
3 shared-return original branches and 23 native-bound REL32 calls**.
Case308 uses original stage timing, `SetSceneTimer(15)` and frame16
invulnerability180; 309 uses a single frame12 effect0x1AE and
sound18. Case312 source is present but its return-size closure
needs a real following case313. This is **NOT full Exact** and does
not advance the strict original-bound 40,336-byte Kano prefix.
No all-unit cold replay was run.

### Kano Slot06 136-case full native shape milestone (not Exact)

**All 136 native live cases are now source-authored**, not generated
neutral markers; state316 ends in the canonical shared return.
`workbench/kano-state/check_full_shape.py` compiles the whole one
function with pinned VC7.1 and original-binds **68,853 code bytes,
548 table bytes, 316 selectors**, the original **0x4A4 stack**, all
**18,634 x86 instruction positions/widths/register-abstracted forms**,
**1,810 native branch targets**, **1,271 direct-call/float COFF
operands**, and **139 native-local address relocations**. The 316
selector bytes are byte-for-byte identical; all 137 original
switch destinations match native local symbol offsets.

**Not whole-function Exact:** **125 unmasked concrete opcode bytes**
remain different, concentrated in cases250/251/254 (123 instructions).
No byte substitution/masking or false accepted source receipt.
`check_prefix.py` still proves the earlier **40,336 original
byte** strict selected prefix; full-shape progress is separate. The
next priority is the register-allocation phase around state250, then
complete strict full original-bound replay. Do not run cold all-unit
replay, do not push.

## Additional newly accepted leaf owners

Kaori `Character13` now has seven complete strict Exact normal-C++
virtual/lifecycle owners in `src/Character13Lifecycle.cpp`: full
283-byte initializer, 58-byte reset, 80-byte effect removal,
19-byte Slot03, two 11-byte delegates and 47-byte emitter.
All **509/509 original bytes**, five original-bound direct call
relocations, seven vtable targets and reviewed function boundaries
are confirmed by selected replay. Evidence:
`docs/evidence/character-13-lifecycle-exact.json`. No shared header
or accepted constructor was edited. Targeted unit IDs start with
`character-13-`; no full cold replay was run.

MizukaB `Character18` now also has **seven complete native Exact
functions / 670 bytes**, including the nontrivial 179-byte Slot08
resource timer in `src/Character18Lifecycle.cpp`. Eight original-
bound COFF calls/float references and seven vtable targets were
independently checked. Public selected proof:
`docs/evidence/character-18-lifecycle-exact.json`. The strict replay
ran only these seven new functions, not a whole repository cold replay.

Kanna `Character19` additionally has **six complete Exact lifecycle/
virtual owners / 490 machine-code bytes** in
`src/Character19Lifecycle.cpp`. The six canonical vtable targets and
four base-method calls were independently verified, with strict
selected receipts at `docs/evidence/character-19-lifecycle-exact.json`.
No full all-unit cold replay was run; no whole-game claim.

Kano `Character20` now additionally has **five complete native Exact
lifecycle/local-effect owners / 617 code bytes** in
`src/Character20Lifecycle.cpp`, including a 413-byte initializer
and five independently reviewed original vtable/call bindings.
Evidence: `docs/evidence/character-20-lifecycle-exact.json`.
Only those five units were replayed, not an all-unit cold replay.

Minagi `Character21` now has **seven complete Exact lifecycle
and local-effect functions / 666 original code bytes** in
`src/Character21Lifecycle.cpp`. The 440-byte initializer constructs
and emits real effect0x190 after clearing original state/arrays.
All nine original REL32 calls and vtable targets were reviewed; formal
selected proof `docs/evidence/character-21-lifecycle-exact.json`.
Only these seven units were replayed, not a repository-wide cold replay.

NayukiB `Character17` has **six complete exact lifecycle/timer
owners / 767 original machine-code bytes** in
`src/Character17Lifecycle.cpp`. The meaningful 241-byte `Slot08`
countdown has the original surprising 50–149 state gate; all five
base-method call operands and six canonical vtable locations are
verified. Certificate: `docs/evidence/character-17-lifecycle-exact.json`.
Only these six units were replayed, not all-unit cold replay.

Akiko `Character16` now has **five complete Exact lifecycle and
local-effect owners / 565 native code bytes** in
`src/Character16Lifecycle.cpp`. Each original vtable and five base
calls were independently checked; strict selected replay proved
565/565 and zero differences. Certificate:
`docs/evidence/character-16-lifecycle-exact.json`. Only these five
units were replayed, never full all-unit cold replay.

Mio `Character11` now has **six complete Exact lifecycle and effect
owners / 506 original code bytes** in `src/Character11Lifecycle.cpp`.
Nine reviewed original-bound COFF operands include four double-zero
DIR32 literals and five direct base calls. Six complete owners pass
strict selected replay 506/506, zero differences. Proof:
`docs/evidence/character-11-lifecycle-exact.json`.
Only these six units were replayed; no full cold replay.

EX Nanase `Character12` now has **six complete native Exact
lifecycle/effect owners / 537 original code bytes** in
`src/Character12Lifecycle.cpp`. Five original base method direct
calls and six canonical original vtable pointers are reviewed;
selected strict replay gives 537/537 bytes with zero differences.
Evidence `docs/evidence/character-12-lifecycle-exact.json`.
Only the six selected units were replayed, not all-unit cold.

EX Nanase `Character12::Slot08` has also been reconstructed as a
**complete original 789-byte Exact virtual**, not a partial prefix,
in `src/Character12Slot08.cpp`. It builds an EffectSpawn, gates special
state0x140, cycles eight tint stages and emits randomized effects.
Its **18 independently original-bound relocations**, all complete
789 native code bytes, and real original vtable slot0x788E04
pass selected strict replay with zero differences.
Evidence: `docs/evidence/character-12-slot08-exact.json`.
Only this unit was replayed, no all-unit cold replay.

Mio `Character11::Slot01` is now a **complete native Exact
975-byte dual sprite-gauge render function** in
`src/Character11Render.cpp`. It reads original pattern 43/44 frame0,
computes real source/destination rectangles and draws to Video using
the original two direct calls. All **8 original COFF REL32 targets**
(six MakeSurfaceRect and two DrawSurface) are independently bound;
975/975 native code bytes match, no differences. The called Video
render routine remains separately unaccepted. Proof:
`docs/evidence/character-11-slot01-exact.json`.
Selected one-unit replay only; no cold all-unit replay.

Kano `Character20::Slot08` has now been reconstructed as a
**complete 765-byte original Exact meter/effect controller** in
`src/Character20Slot08.cpp`. Selected-only strict replay independently
confirms the real vtable slot0x788C98, all **16 native COFF/float
relocations**, **765/765 original code bytes** and zero differences.
A key reconstruction detail is the original `velocityX == 0.0`
x87 condition; a single combined random-effect X calculation is
also required to reproduce the native ESI register allocation.
Certificate `docs/evidence/character-20-slot08-exact.json`.
This complete leaf Exact is independent from the unfinished 68,853-
byte Kano Slot06 boss and from its structural island diagnostics.
Only this unit was replayed; no full cold all-unit replay.

NayukiB `Character17::Slot01` is now a **complete 1,080-byte
native Exact render function** authored as natural C++ in
`src/Character17Render.cpp`. It uses two real pattern43/44 gauge
draws, the original 3000-denominator width scale and the full
player-dependent rectangle calculation. Strict selected one-unit
replay matches 1080/1080 with zero differences, including eight
independently original-bound calls (six MakeSurfaceRect, two
Video::DrawSurface). The source multiplication order must be
`field3150 * frame.width` to reproduce the original VC7.1 register
moves. Proof: `docs/evidence/character-17-slot01-exact.json`.
Only this unit was replayed, no full cold replay.

Kano `Character20::Slot01` is also **complete native Exact** in
`src/Character20Render.cpp`: **1,643 original code bytes, 12
independently original-bound REL32 calls and zero differences**. The
natural C++ renders pattern42 fully at charge10000, full pattern43
and width-clipped pattern44 at intermediate charge, with player-
specific 49/271 source/destination rectangle geometry and three
real Video::DrawSurface calls. Original vtable slot0x788C7C and
all nine MakeSurfaceRect/three DrawSurface native call destinations
are separately checked. Certificate:
`docs/evidence/character-20-slot01-exact.json`.
This complete caller's codegen Exact does not establish the Video
callee's own Exact status or whole-game runtime equivalence.
Only selected original one-unit replay, never full cold replay.

Akiko `Character16::Slot08` is now a **complete Exact 1,310-byte
opponent/timer special** authored in `src/Character16Slot08.cpp`.
Original vtable0x788F78 and all 5 original REL32 targets (3x
`Context::FadeMusic`, `Secondary::SetCharacterTint`,
`Context::SetSceneTimer`) are independently verified; strict
one-unit replay gives **1310/1310** bytes, zero differences. The
natural source restores the original dual-fighter health gates,
field0160/field3148 opponent state and layered timer/counter,
scoreboard/musical fade and exit behavior. Evidence:
`docs/evidence/character-16-slot08-exact.json`.
Only the Akiko selected owner was replayed; no all-unit cold replay.

Character04 `Slot08` is now a **complete native Exact 528-byte
passive state controller**, `src/Character04Slot08.cpp`. It uses an
original-offset provisional typed view only in this source to avoid
modifying shared class layout dependencies. Original vtable slot
`0x00788B9C`, 528/528 code bytes and all seven original-bound
call/float operands pass one-unit strict replay, zero differences.
A necessary real-world correctness fix was **positionY−40.0**, not
30.0: the first compiled candidate had matching code forms but the
wrong float constant, independently rejected by native binding.
Certificate `docs/evidence/character-04-slot08-exact.json`.
No all-unit cold replay.

Character04 has five more complete original Exact lifecycle/effect
owners in `src/Character04Lifecycle.cpp`: InitializeState322,
ResetPose58, RemoveLocalEffect80, Slot03 19, EmitLocalEffect47,
total **526/526 native code bytes**, five original-bound base-call
REL32 operands and zero differences. The real initializer restores
five original X/Y collision pairs and three 64-int effect arrays;
effect emission does virtual per-index removal before base delivery.
Original vtable slots12/0/10/3/9 are independently reviewed.
Certificate `docs/evidence/character-04-lifecycle-exact.json`.
Together with the earlier accepted 528-byte Character04 Slot08,
there are six complete accepted child virtuals and 1,054 original
code bytes for this role. Only five selected strict units were
replayed here; no cold all-unit replay.

`Character04::Slot01` is now a **complete 2,248-byte native Exact
four-layer renderer** in `src/Character04Render.cpp`. Original vtable
slot0x788B80, **12 original MakeSurfaceRect** and **four Video::DrawSurface**
REL32 sites are independently bound; selected one-unit replay gives
**2,248/2,248 bytes, 16 calls, zero differences**. The real four
visual layers use patterns41/42 fully and patterns43/44 clipped by
field3148*frame.width/10000 or /1200. The multiplication operand
order matters to native VC7.1 register allocation: flipping it in
natural C++ changed candidate size from 2,230 to original 2,248.
The typed child view is local to this source; no accepted shared
class layouts were changed. Evidence:
`docs/evidence/character-04-slot01-exact.json`.
This is an accepted *caller* Exact; the video drawing callee and
Windows runtime are not thereby accepted. No all-unit cold replay.

### Active second large boss: Character04::Slot06 (whole-function code + dispatch final-image Exact)

The authored `workbench/character04-state/Character04State.cpp`
now covers original default plus **138 genuine native live states**,
most recently reconstructed states220–221 two-character grab/throw,
230–232 aerial attack tiers, 240's collision-result-3 grab handoff,
241's complete multi-stage airborne throw, 249's special-move
hitstun/effect initialization, 250's airborne startup/frame loop, 251's
second airborne startup variant, 252's charged airborne special, 253's
post-landing recovery bridge, 254's held-input charge/launch, 255's
alternate held-input charge/aerial launch, 256's aerial special
follow-through, 257's special-effect follow-through, 258's wider
local-effect follow-through, and 259's farthest-reaching local-effect
variant, and 260's aerial capture/dual-effect initialization, plus 261's aerial deceleration recovery and 262's aerial fall/landing reset, plus 263's aerial capture effect pair and 264's alternate local-effect variant, plus 265's charge-capture/resource-cost sequence and 266's effect0x1B0 aerial follow-through, plus 267's extended-offset variant and 268's farthest-reaching effect0x1B0 follow-through, plus 269's zero-velocity aerial recovery, 303's multi-stage capture throw, 304's alternate cost/effect throw and 305's dual-effect aerial throw and 306's multi-loop opponent-repositioning throw and 307's field3138-gated looping variant and 308's higher-damage meter-scaled hitstun variant and 309's triple-effect capture with timed frame-6 loop and 312's higher-damage scaled loop throw, plus 315/316's two independently encoded zero-velocity hitstun recoveries, 317's third register variant and 318's two-effect aerial launch and 319's simple zero-velocity aerial recovery and 320's alternate-cost dual-effect launch, 321's third simple recovery reset and 322's 3000-cost dual-effect launch, 323's third simple aerial recovery reset and 324's partner-handoff aerial throw and 325's final multi-stage partner capture/launch. State240 resets both fighters' frame/pose state, advances the
owner to state241 and the opponent to state100, emits effect0 at
integer-truncated X+facing×31/Y−82, and preserves the native airborne/
state-range test for `remainingHitCount`. State241 applies horizontal
offset/shake `(50,3)`, positions the opponent in states103/104/69 at
three native offsets, applies `ApplyDamage(1300,500.0)`, sets opponent
knockback velocities `(-3.0,3.0)`, and loops its last two frames until
landing. State249 sets `field00dc=4`, `field00de=0xEC`, zeroes horizontal
velocity, clears guard-input frames, sets hitstun60 and remainingHitCount1,
and emits effect0x28 at integer-truncated X+facing×10/Y−40 with
palette0x13. State250's 436 native bytes preserve the ground-vs-air
startup distinction, frame1 meter/velocity/gravity setup, early
final-three-tick animation gate for airborne starts, frame11 loop, and
state253 landing handoff. State251's 471 native bytes use gravity0.035
on frame1, set private `field313c`, clear collision result when advancing
into frame1, and invoke virtual ResetPose at animation completion.
State252's 790 native bytes initialize trail3 and effect0x21 at
integer-truncated `(X,Y−20)`, apply the field3144/field3148 or
field0120/field0118 resource-cost branch, add25 meter and two remaining
hits at frame1 with gravity0.025, emit local effect0x1A2 at frame7, and
preserve the airborne early-frame and state253 landing gates. State253's
204 native bytes zero both velocities, faces the opponent every tick,
adds tick21 as a special frame-advance point when frame2 inherits
`field313c==1`, and selects state3 vs state7 from `inputY` before
ResetPose. State254's 615 native bytes maintain attackCollisionResult2,
increment `field313c` while buttonHeld0 is down, emit effect0x20 at
frame2, latch `field3138` after the frame5 charge threshold, apply the
native velocity/deceleration values, and branch at frame6 to state261 or
the opponent-relative repositioning path. State255's 739 native bytes
maintain attackCollisionResult2, count `buttonHeld[1]` into `field313c`,
emit frame2 effect0x20 at `(X+facing×60,Y)`, reset the frame and latch
charge above30 at frame5, apply the uncharged opponent-relative X offset
at frame5/tick20, and install velocity1.5/deceleration−0.05 at frame6.
The charged frame6 branch hands off to state0x106 at
`opponentX−facing×100`, clamps X to540/100 and sets Y=−100; the uncharged
animation-completion path clears the collision result, faces the opponent
and invokes virtual ResetPose. Its register-sensitive x87 launch path is
kept in a narrow inline-assembly block for exact VC7.1 instruction order.
State256's 747 native bytes emit effect0x21/trail3 and apply the native
resource cost on frame0, set one remaining hit, emit effect0x20 on frame2,
and skip directly from frame4 to frame6 when `attackCollisionResult==2`
without a tick-zero requirement. Its normal path resets frame at frame5,
advances horizontal velocity by `horizontalDeceleration` with a zero
floor, installs velocityX8.0 at frame5/tick20 and velocityX3.5 plus
deceleration−0.05 at frame6/tick0, and clears collision result only on
advances into frames below2. Animation completion faces the opponent
and invokes virtual ResetPose. State257's 491 native bytes set
attackCollisionResult2, reset frame at frame0/tick0, and at frame2/tick0
choose a local effect from `field3144`: value4 spends1000 from
`field3148` (clamped at zero) and emits effect0x1A8 at
integer-truncated `(X+facing×80,Y)`; otherwise it sets `field3144=2` and
emits effect0x19C at `(X+facing×40,Y)`. Both local effects use owner1,
group2, current facing and layer1. Every frame advance sets
attackCollisionResult3; animation completion clears state, invokes the
virtual ResetPose slot and faces the opponent. State258's 494 native bytes
set attackCollisionResult2, call ResetFrame at frame0/tick0, and at
frame2/tick0 choose a local effect from `field3144`: value4 spends1000
from `field3148` (clamped at zero) and emits effect0x1A8 at
integer-truncated `(X+facing×160,Y)`; otherwise it sets `field3144=2` and
emits effect0x19C at `(X+facing×120,Y)`. Both effects use owner1, group2,
current facing and layer1. Every frame advance sets attackCollisionResult3;
animation completion clears state, invokes virtual ResetPose and faces the
opponent. State259's 501 native bytes set attackCollisionResult2, call
ResetFrame at frame0/tick0, and at frame2/tick0 choose a local effect
from `field3144`: value4 spends1000 from `field3148` (clamped at zero)
and emits effect0x1A8 at integer-truncated `(X+facing×240,Y)`; otherwise
it sets `field3144=2` and emits effect0x19C at `(X+facing×200,Y)`. Both
effects use owner1, group2, current facing and layer1. Every frame advance
sets attackCollisionResult3; animation completion clears state, invokes
the virtual ResetPose slot and faces the opponent. The case255 x87 launch
and case257–269 and 303–309,312,315–325 inline-assembly state blocks use narrow inline
assembly to preserve native VC7.1 instruction order. The original-bound
State260's 674 native bytes initialize an aerial capture on frame0/tick0:
they zero both velocities, set byte0x2C8 to5, initialize field3148=10000,
field314c=1 and field3150=1, then emit global effect0x1F at integer
(X,Y) with facing flag facing==-1. A second local effect0x191 is emitted
at integer (X,Y−17): field3140==1 offsets X by facing×60, value2 offsets
by −facing×60, and both paths clamp X to40–600. The local effect uses
owner1, group2, current facing and layer1. Each frame advance clears the
collision result; animation completion clears state, invokes virtual
ResetPose and faces the opponent. Case260's x87 coordinate conversions,
effect record construction and frame tail are emitted in a narrow assembly
block to preserve the native instruction/register sequence.
State261's 239 native bytes initialize horizontalDeceleration to2.0 and
set one remaining hit at frame0/tick0. After frame6 they subtract0.055
from horizontalDeceleration and clamp it at zero. Every frame advance
increments the frame; entering frame1 clears the collision result. At
animation completion the state is cleared, FaceOpponent runs, and the
virtual ResetPose slot is invoked.
State262's 288 native bytes initialize velocityX=1.0, velocityY=0.0 and
one remaining hit on frame0/tick0. After frame2 they add gravity0.035 to
velocityY. If positionY+velocityY remains above zero and the frame is
below12, the state jumps to frame12, clears tick, sets positionY=0 and
calls ResetFrame. Otherwise it advances the normal frame counter and
clears collision result on every advance. Animation completion clears
state, calls FaceOpponent, then invokes virtual ResetPose.
State263's 403 native bytes call ResetFrame at frame0/tick0. At frame3/
tick0 they set field3144=2 and byte0x2C8=5, emit global effect0x1F at
integer-truncated (X,Y) with facing flag facing==-1, then emit local
effect0x1AC at integer-truncated (X,Y−20) using owner1, group2, current
facing and layer1. Every frame advance sets attackCollisionResult=3;
animation completion clears state, invokes virtual ResetPose and faces the
opponent.
State264's 403 native bytes repeat state263's capture sequence with local
effect0x1AD replacing effect0x1AC. It calls ResetFrame at frame0/tick0;
frame3/tick0 sets field3144=2 and byte0x2C8=5, emits global effect0x1F
at integer-truncated (X,Y), then local effect0x1AD at integer-truncated
(X,Y−20) using owner1, group2, current facing and layer1. Every frame
advance sets attackCollisionResult=3; animation completion clears state,
invokes virtual ResetPose and faces the opponent.
State265's 658 native bytes initialize a charge capture at frame0/tick0.
They emit global effect0x21 at integer-truncated (X,Y−40) with palette
0x0B, group2 and layer1, then start trail3. The `field3144==4` branch spends
1000 from `field3148` and clamps at zero; the alternate branch subtracts
500.0 or250.0 from `field0118` according to `field0120`. At frame3/tick0
it sets `field3144=2` and byte0x2C8=5, emits global effect0x1F at (X,Y)
with facing flag `facing==-1`, then local effect0x1AE at (X,Y−20) using
owner1, group2, current facing and layer1. Every frame advance sets
`attackCollisionResult=3`; animation completion clears state, invokes
virtual ResetPose and faces the opponent. The 500.0 and250.0 x87 operands
are pinned to original absolute constants at 0x787C30 and 0x787C70 and
verified against their original data bytes; inline assembly preserves the
native register and instruction positions.
State266's 315 native bytes set `attackCollisionResult=2` each tick and
call ResetFrame at frame0/tick0. At frame3/tick0 they set `field3144=2`
and emit local effect0x1B0 at integer-truncated `(X+facing×80,Y−20)` using
owner1, group2, current facing and layer1. Every frame advance sets
`attackCollisionResult=3`; animation completion clears state, invokes
virtual ResetPose and faces the opponent.
State267's 322 native bytes repeat state266's effect0x1B0 follow-through
with a wider horizontal offset. They set `attackCollisionResult=2` each
tick, call ResetFrame at frame0/tick0, and at frame3/tick0 set
`field3144=2` and emit local effect0x1B0 at integer-truncated
`(X+facing×160,Y−20)` using owner1, group2, current facing and layer1.
The longer `imul` and near conditional branch preserve native instruction
widths. Every frame advance sets `attackCollisionResult=3`; animation
completion clears state, invokes virtual ResetPose and faces the opponent.
State268's 322 native bytes repeat the effect0x1B0 follow-through with
a 240-pixel horizontal offset. They set `attackCollisionResult=2` each
tick, call ResetFrame at frame0/tick0, and at frame3/tick0 set
`field3144=2` and emit local effect0x1B0 at integer-truncated
`(X+facing×240,Y−20)` using owner1, group2, current facing and layer1.
Every frame advance sets `attackCollisionResult=3`; animation completion
clears state, invokes virtual ResetPose and faces the opponent.
State269's 176 native bytes zero horizontal and vertical velocity on
frame0/tick0 and set byte0x2C8 to5. Each frame advance clears
`attackCollisionResult` to zero; animation completion clears state, invokes
virtual ResetPose and faces the opponent. Both x87 zero operands are pinned
to original address 0x7872F8 and verified against the original data value.
State303's 763 native bytes form a multi-stage aerial capture throw. At
frame0/tick0 they zero three movement fields. Frame2 applies horizontal
shake `(50,3)`; frame2/tick0 sets field0x16C=1 and field0x14C=120,
subtracts1000 from field0x148, applies tint0xB0 for3 ticks, and emits
global effect0x44 at integer-truncated (X,Y−40) with palette0x13, group2
and layer1. Frame4/tick0 clears byte0x2C8. Frame8/tick0 sets velocityX=5.0;
frame9/tick0 sets velocityX=1.8 and horizontal acceleration−0.05. After
frame8 it integrates that acceleration and clamps velocityX at zero. At
frame8, collision result2 or5 resets tick and advances to frame9; result3
sets opponent hitstop9999, resets both poses, sets opponent Y=0/state0x6C
and owner state0x132. Frames1–17 retain horizontal shake; frame advances
clear collision result, and animation completion clears state and invokes
virtual ResetPose.
State304's 763 native bytes preserve the same frame gates and hit branches,
but subtract2000 from field0x148, emit effect0x45 with palette0x05, start
frame8 at velocityX=7.0, and hand the owner to state0x133 on a successful
frame8 hit. It retains frame9 velocityX=1.8, acceleration−0.05, the
zero-floor integration, opponent hitstop9999 and opponent state0x6C.
Both states match all 212 native x86 instructions; their absolute 0.0,
5.0, 7.0, 1.8 and −0.05 operands are pinned to original PE data.
State305's 940 native bytes are an aerial capture that branches into a
two-effect throw. Frame0/tick0 calls ResetFrame. Frame2/tick0 zeroes
three movement fields, sets field0x16C=1 and field0x14C=120, subtracts
3000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effect0x46 at integer-truncated (X,Y−40) with palette0x40, group2 and
layer1. It sets byte0x2C9=0x25. Frames above1 call
`Context::SetSceneTimer(15)`; frames below3 apply horizontal shake
`(50,3)`. Frame4/tick0 clears byte0x2C8. Frame8/tick0 sets velocityX=10.0
and one remaining hit; frame9/tick0 sets velocityX=1.8 and horizontal
acceleration−0.05, integrated after frame8 with a zero floor. At frame8,
collision result2 or5 advances to frame9; result3 sets opponent hitstop9999,
resets both poses, sets opponent Y=0/state0x6C and owner state0x134, then
emits local effects0x1A3 at (0,20) and0x1A4 at (0,38) with owner1 and
layer1. Frame advances clear collision result; animation completion clears
state and invokes virtual ResetPose. Its 10.0, 1.8, −0.05, 20.0 and38.0
operands are pinned to original PE data.
State306's 755 native bytes implement a multi-loop aerial throw with
opponent repositioning. Frame0/tick0 sets velocityX=0.3, places owner X at
`opponentX+facing×30`, and clears attackCollisionResult. Frame9/tick0 adds
the original zero constant to owner X and sets velocityX=0. Frame11/tick0
sets byte0x2C9=0x14; frame15/tick0 sets byte0x2C8=2. At frame15/tick90 it
puts the opponent in state0x47, clears opponent hitstop, sets opponent
fields0xC0=0 and0xC8=−4.0, sets attackCollisionResult=2, applies
`ApplyDamage(2400,400.0)`, and emits effect0x34 at (opponentX,opponentY−40)
with palette0x16, group2 and layer1. Frames1–14 apply horizontal shake
`(50,10)`. On frame advances, frame6 loops backward by2 while field0x3138
is below9; frame9 adds `facing×80` to owner X and clears the loop counter;
frame13 loops backward by2 while the counter is below12. Animation
completion clears state, faces the opponent and invokes virtual ResetPose.
All 208 native instructions match.
State307's 836 native bytes are the looping variant of state306. Frame0/
tick0 clears field0x3138, sets velocityX=0.3, places owner X at
`opponentX+facing×30`, and clears attackCollisionResult. Frame9/tick0 adds
zero to owner X and sets velocityX=0. Frame11/tick0 sets byte0x2C9=0x14;
frame14/tick0 sets byte0x2C8=2. At frame15/tick0, only when field0x3138
is exactly7, it puts the opponent in state0x47, clears opponent hitstop,
sets opponent fields0xC0=0 and0xC8=−4.0, sets attackCollisionResult=2,
applies `ApplyDamage(3200,400.0)`, and emits effect0x34 at
(opponentX,opponentY−40) with palette0x16, group2 and layer1. Frames1–14
apply horizontal shake `(50,10)`. Frame6 loops back to4 while the counter
is below9; frame9 adds `facing×80` to owner X and clears the counter; frame13
loops back to11 while the counter is below12; frame14 latches the counter
at12. At animation completion, a nonzero counter loops back two frames
and decrements; only a zero counter clears state and invokes virtual
ResetPose. All 225 native instructions match.
State308's 877 native bytes are the higher-damage, meter-scaled hitstun
variant of state307. It preserves frame0 repositioning, frame9 velocity
stop, frame11/14 setup, frames1–14 horizontal shake and the field0x3138
frame6/9/13/14 loops. At frame15/tick0, only when field0x3138==7, it puts
the opponent in state0x47, clears opponent hitstop, sets opponent fields
0xC0=0 and0xC8=−4.0, sets attackCollisionResult=2, applies
`ApplyDamage(4500,400.0)`, then calculates opponent field0x124 as
`ftol2(200.0 × field0x178 / 10000.0)`. It emits effect0x34 at
(opponentX,opponentY−40) with palette0x16, group2 and layer1. The looping
animation only clears state and invokes virtual ResetPose after field0x3138
reaches zero. All 234 native instructions match.
State309's 518 native bytes implement a triple-effect capture with a
frame-6 hitstun loop. Every invocation applies horizontal shake `(50,3)`.
At frame0/tick0 it sets byte0x2C8=3, calls ResetFrame, sets field0x14C=120,
subtracts3000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effects0x46 and0x47 at integer-truncated (X,Y−40) with palette0x40, group2
and layer1. It then sets byte0x2C9=0x25 and emits local effect0x1AB at
(X+facing×20,0) using owner1, current facing, group2 and layer1. On frame
advance, frame6 loops back four frames while field0x14C remains positive
and increments field0x3138. Animation completion clears state and invokes
the native virtual reset. All 133 native instructions match.
State312's 851 native bytes are the scaled-damage looping throw variant
of states307/308. Frame0/tick0 clears field0x3138, sets velocityX=0.3,
places owner X at `opponentX+facing×30`, and clears attackCollisionResult.
Frame9/tick0 sets velocityX=0; frame11/tick0 sets byte0x2C9=0x14;
frame14/tick0 sets byte0x2C8=2. At frame15/tick0, only when field0x3138==7,
it puts the opponent in state0x47, clears opponent hitstop, sets opponent
X=0 and Y=−8.0, sets attackCollisionResult=2, applies
`ApplyDamage(4200,750.0)`, then writes opponent field0x124 as
`ftol2(200.0×comboDamageScale/10000.0)`. It emits effect0x34 at
(opponentX,opponentY−40) with palette0x16, group2 and layer1. Frames1–14
apply horizontal shake `(50,10)`. Frame6 loops back to4 while the counter
is below9; frame9 adds `facing×80` to owner X and clears the counter;
frame13 loops back to11 while the counter is below12; frame14 latches12.
At animation completion, a nonzero counter loops back two frames and
decrements; only zero clears state and invokes virtual ResetPose. All 230
native instructions match.
States315 and316's 220 native bytes each are two separate zero-velocity
hitstun-recovery variants. Both zero velocityX and velocityY at frame0/tick0,
clear field0x3148 at frame1/tick0, and advance native frame/tick counters.
At animation completion, if field0x3144==1 they reset the frame to0 and
return while retaining the current state; otherwise they clear state and
invoke the native virtual reset. Their register allocation and direct-epilogue rel32 operands differ by
variant, so both blocks are independently reconstructed and checked: 61
native instructions each.
State317's 220 native bytes are the third zero-velocity hitstun recovery
variant. It zeros velocityX/Y at frame0/tick0, clears field0x3148 at
frame1/tick0, and advances frame/tick counters. At animation completion,
field0x3144==1 resets frame to0 and returns while retaining the current
state; otherwise it clears state and invokes the native virtual reset.
Its register allocation and direct-epilogue rel32 operand are distinct from
315/316. All 61 native instructions match.
State318's 468 native bytes are a two-effect aerial hitstun launch.
Frame0/tick0 zeros velocityX/Y. Frame3/tick0 sets field0x14C=120,
subtracts1000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effect0x44 at integer-truncated (X−facing×13,Y−51) with palette0x13,
group2 and layer1. It then emits local effect0x1B6 at (X,Y−15) with owner1,
current facing, group2, layer0 and lifetime300, and sets field0x3144=2.
Animation completion clears state and invokes the native virtual reset.
All 120 native instructions match.
State319's 158 native bytes implement a simple aerial recovery reset.
At frame0/tick0 they zero velocityX and velocityY. The state advances the
native tick/frame counters; when animation completes it clears state and
invokes the native virtual reset. All 45 native instructions match.
State320's 468 native bytes are the alternate-cost/effect variant of
state318. Frame0/tick0 zeros velocityX/Y. Frame3/tick0 sets field0x14C=120,
subtracts2000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effect0x45 at integer-truncated (X−facing×13,Y−51) with palette0x05,
group2 and layer1. It then emits local effect0x1BA at (X,Y−15) with owner1,
current facing, group2, layer0 and lifetime300, and sets field0x3144=2.
Animation completion clears state and invokes the native virtual reset.
All 120 native instructions match.
State321's 158 native bytes are another simple aerial recovery reset.
Frame0/tick0 zeros velocityX/Y; the state advances tick/frame counters,
then clears state and invokes the native virtual reset at animation
completion. All 45 native instructions match.
State322's 468 native bytes are a 3000-cost two-effect aerial launch.
Frame0/tick0 zeros velocityX/Y. Frame3/tick0 sets field0x14C=120,
subtracts3000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effect0x46 at integer-truncated (X−facing×13,Y−51) with palette0x40,
group2 and layer1. It then emits local effect0x1BE at (X,Y−15) with owner1,
current facing, group2, layer0 and lifetime300, and sets field0x3144=2.
Animation completion clears state and invokes the native virtual reset.
All 120 native instructions match.
State323's 158 native bytes are a third simple aerial recovery reset.
Frame0/tick0 zeros velocityX/Y, then native tick/frame counters advance;
completion clears state and invokes the native virtual reset. All 45
native instructions match.
State324's 643 native bytes are the partner-handoff aerial throw. Before
frame5 it applies horizontal shake (50,3). Frame0/tick0 resets the frame,
sets field0x14C=120, subtracts3000 from field0x148, applies tint0xB0 for3
ticks, and emits global effects0x46/0x47 at integer-truncated
(X−facing×19,Y−50) with palette0x40, group2 and layer1. It sets byte0x2C9
=0x25 and clears field0x16C. At frame4 when field0x168==3, it zeros owner
velocityX/Y and the extra double at +0xB8, invokes owner virtual Reset and
ResetFrame, resets the partner via its virtual function, sets owner state
0x145 and partner state0x79, and reapplies tint0xB0. Frame5/tick0 clears
field0x3148 and sets field0x16C=1. On each completed animation frame it
advances the frame counter and clears field0x168; at frame4 it compares the
partner's +0x28 double to original 0.0 and sets field0x16C. Animation
completion clears state and invokes native virtual reset. All 170 native
instructions match.
State325's 771 native bytes are the final partner-capture and staged launch.
Every tick applies horizontal shake (50,3). Frames0–1 use tint0xB0; frames
2–9 use owner tint0xB1 and partner character tint0xB0. Frame1/tick0 sets
byte0x2C8=3 and spawns local effect0x1C2 at (0,0) with owner1, group2,
layer1 and native one-valued spawn flags. Frame2/tick0 sets partner state
0x6B; frame11/tick0 sets byte0x2C8=2. Frame12/tick0 puts the partner in
state0x47, sets partner X velocity0 and Y velocity−5.0, clears partner
frame/tick, sets partner field0x128=1, and applies
`ApplyDamage(ftol2(field3148×0.15+3500.0),500.0)`. It sets owner byte0x2C9
=0x16, reverses partner facing, clears partner field0x14A, emits global
effect0x34 at (partnerX,partnerY−40), and clears owner field0x3148. After
each completed animation frame it clears field0x168; at frame6 it loops
back four frames and increments field0x3138 while that counter is below4.
Animation completion clears state and invokes native virtual reset. All
210 native instructions match.
The original-bound strict checker caught and corrected state220's subtle
reset: when animation advances outside pose1, it must set
`remainingHitCount=0`, not leave it unchanged. Native 221 applies 1200/750.0 damage and places both
fighters at four distinct pose-specific coordinates. `check_prefix.py` proves **59,139 continuous native code bytes / 16,127
original x86 instruction locations/widths/forms**, **1,417 native internal
branches and 187 direct shared-return branches** (all target and displacement
bytes exact), **1,080 original-bound COFF call/float operands +7 pinned
state256 literal x87 operands**, and 2 canonical native-local dispatch
pointers. State256 (747 bytes) and state257 (491 bytes) now match their native
instruction bytes, including all scratch slots. All 138 live case bodies,
the exact 139-entry table/325-byte selector and all 187 direct epilogue
returns are covered. All 338 direct calls resolve to the 14 independently
Exact leaf dependencies or the original-bound `__ftol2` runtime helper.
The deterministic final-image resolver materializes all **1,082 code COFF
relocations / 4,328 operand bytes** and **139 jump-table relocations / 556
operand bytes**, then collapses the intermediate split stack prologue into
the native single `sub esp,0x2E8`. The complete **59,143-byte function code
+ 556-byte jump table + 325-byte selector (60,024 bytes total)** is
byte-identical to the original. The split compiler prologue and COFF
placeholders remain differences only in the relocatable object, not the
resolved final image. No whole-project cold replay/push. Evidence:
`docs/evidence/character04-slot06-prefix.json`.
A selected cold replay of the 14 source-level leaf dependencies used by this
boss is also **1,918/1,918 native bytes exact, zero differences**. Evidence:
`docs/evidence/character04-slot06-leaf-dependencies-exact.json`; no all-unit
cold replay.

Shiori `Character08::Slot08` original vtable slot0x787E18 is
now a complete **11-byte native Exact** virtual passive hook,
`src/Character08Slot08.cpp`. The native function is truly empty,
not an unresolved inherited method. Selected strict one-unit replay
gives **11/11 bytes, zero COFF calls/relocations and zero differences**.
Proof: `docs/evidence/character-08-slot08-exact.json`.
No all-unit cold replay.

`Character04::Slot02` has now been independently accepted as
**4,404 native bytes / 1,268 x86 original instructions exact** in
`src/Character04Commands.cpp`, original vtable slot `0x00788B84`.
The source reconstructs **14 prioritized 180-ring input history
patterns**, facing-dependent input codes and exact native command
priority. Original compared bytes are **4,404/4,404 with zero
COFF relocations and zero differences** under selected VC7.1
strict replay. Character04 intentionally removes a related
character's extra initial 0x78 command pattern, replaces a
0x60-special input loop, and removes two non-native meter/state
conditions. Proof: `docs/evidence/character-04-slot02-exact.json`.
This completes one substantial full owner independently of the now
**60,024/60,024-byte final-image-exact Character04 Slot06 function + dispatch
image**. No full cold replay.

## Tools and checks

Canonical target: ignored `resources/EFZ.exe`, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Use pinned VC7.1 RTM 13.10.3077, the EFZ Wine prefix and existing Ghidra project.
See [SHARED_TOOLS.md](SHARED_TOOLS.md) for local runtime access.

```bash
git status --short --branch
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
scripts/repo-python scripts/ci.py
# Compile/compare only a selected complete owner and actual affected consumers:
scripts/repo-python scripts/replay-exact-units.py --unit character-06-slot02
```

Daily CI checks basic consistency without private tools. Historical source and
header hashes in some certificates are stale. Audit a specific certificate with
`validate-tracking.py --check-proofs --unit NAME` when useful; establish current
exactness through its native comparison. Do not hand-edit historical hashes or
run a full cold cohort to tidy documentation.

## Accepted owners to leave accepted

Makoto Slot06, Nagamori Slot05/Slot04/Slot02, Ikumi Slot02 and Scene3 pushboxes are
complete Exact owners. The match ledger identifies their current certificates
and source recipes. Do not reopen them from obsolete partial-draft measurements.
Reader/audio integration is complete in `src/`.

Nayuki Character10::Slot07, its 20,517-byte native
effect-state boss, is **complete strict Exact**
with original 4,644 x86 code instructions and
both 112/100-byte local switch tables. Original
contribution 20,729/20,729 exact bytes, all
264 independently original-bound COFF relocations,
zero differences and full original 0x1D4 frame.
Source src/Character10Effects.cpp; proof
docs/evidence/character-10-slot07-exact.json.
Selected replay only:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot07.
The prior dirty workbench and extra sibling-only cases
were reconciled before retirement. Do not claim
whole-game runtime/linkage from this single Exact
native codegen unit; Nayuki Slot06 remains open.


Nayuki Character10::Slot01 render overlay is also strict
Exact: 939/939 bytes, 280 x86 instructions and 8/8
original-bound MakeSurfaceRect/Video::DrawSurface calls.
Accepted natural source src/Character10Render.cpp,
evidence docs/evidence/character-10-slot01-exact.json,
selected replay character-10-slot01. This is not
whole-game runtime/linkage equivalence.


Nayuki Character10::Slot04 action boss is now **complete
strict Exact native codegen**: 10,605 original bytes
/ 2,690 x86 instructions, original 0x14 frame/EBX
push-pop and full shared return, 86/86 original-bound
COFF relocations, zero differences. Complete source
src/Character10Action.cpp, acceptance evidence
docs/evidence/character-10-slot04-exact.json.
Run only:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot04.
The Nayuki action workbench was entirely reconciled
and retired; whole-game runtime/linkage is separate.


Nayuki Character10::Slot05 CPU boss is now **complete
native strict Exact**: 13,259/13,259 original code
bytes, 3,391 original x86 instructions, full 0xC0
stack frame/shared return, **232/232 original-bound
COFF relocations**, zero differences. Accepted natural
source src/Character10Cpu.cpp with proof
docs/evidence/character-10-slot05-exact.json.
Reproduce with the selected-only unit:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot05.
The formerly dirty Slot05 workbench was reconciled
into accepted source before retirement. Nayuki Slot04
was separately completed and accepted as Exact; the
remaining major Nayuki state boss is Slot06. Whole-game
linkage and runtime equivalence remain open.


Nayuki Character10::Slot02 is now full native strict
Exact: 4,827/4,827 code bytes, all 1,395 original
instructions, zero relocations/differences.
Full natural source src/Character10Commands.cpp,
proof docs/evidence/character-10-slot02-exact.json.
Run only selected replay:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot02.
The dirty prefix workbench was reconciled into
accepted source before removal; no full cold replay.


Nayuki Character10 now has six newly accepted native strict Exact
virtual/lifecycle functions from the original 0x00788270 vtable:
InitializeState (335 bytes), ResetPose (58), RemoveLocalEffect (80),
Slot03 (19), Slot08 (11) and EmitLocalEffect (47).
They are full natural C++ in src/Character10Lifecycle.cpp
and reproduce **550 original bytes, five canonical call relocations,
zero byte differences**. Each character-10-* unit was replayed
separately and has proof under docs/evidence/. Their addition
does not change class layout or imply whole-product linkage.


Sayuri Character09::Slot05 CPU is **complete native strict Exact**:
12,330 original bytes / 3,172 i386 instructions,
original 0xD8 frame and shared return, 237/237
original-bound relocations, zero byte differences.
Full natural C++ source src/Character09Cpu.cpp,
evidence docs/evidence/character-09-slot05-exact.json.
Reproduce just the selected unit:
scripts/repo-python scripts/replay-exact-units.py --unit character-09-slot05.
The original workbench was reconciled and retired;
whole-product linkage/runtime remains a separate task.


Sayuri Character09::Slot02 input-history command interpreter is now
complete native strict Exact: 5,995 bytes / 1,752 x86 instructions,
the original 0xC stack frame, 8/8 original-bound floating relocations,
zero differing bytes. Accepted full source is
src/Character09Commands.cpp, with proof
docs/evidence/character-09-slot02-exact.json.
Rebuild only using
scripts/repo-python scripts/replay-exact-units.py --unit character-09-slot02.
The original workbench candidate was reconciled into accepted source,
then retired. No full-game cold replay or runtime proof is claimed.


Sayuri Character09 now also has complete strict Exact
ResetPose (58 bytes at 0x004466D0) and InitializeState
(309 bytes at 0x00446590). Both source owners are in
src/Character09Lifecycle.cpp, with one original-bound
base-method relocation each. Selected replay units:
character-09-reset-pose and character-09-initialize-state.
The initializer includes all original signed short offsets
and the 64-entry effect-bank reset; no full cold replay was run.


Three more Sayuri Character09 virtual owners are complete native
strict Exact: Slot01 at 0x004492F0 (11 bytes, no relocations),
Slot03 at 0x00446760 (19 bytes, one original UpdateLocomotionState
call), and EmitLocalEffect at 0x00449390 (47 bytes, one original
direct base emitter call after virtual removal). Accepted sources
src/Character09Delegates.cpp and src/Character09EmitEffects.cpp;
selected units character-09-slot01, character-09-slot03,
character-09-emit-local-effect, with independent proof JSON under
docs/evidence/. No common headers or existing acceptance owners
were modified.


Sayuri Character09::Slot04 is now **complete native strict Exact**:
11,119/11,119 code bytes, 2,815 instructions, the full
0x14 native stack frame and 95/95 original-bound relocations,
zero differences. Its source is src/Character09Input.cpp;
certificate docs/evidence/character-09-slot04-exact.json.
Run only:
scripts/repo-python scripts/replay-exact-units.py --unit character-09-slot04.
The old partial workbench was retired and its dirty source
reconciled into accepted src/ prior to removal.


Sayuri Character09 now has two newly accepted native Exact owners:
Slot08 at 0x00449300 (131 bytes) and RemoveLocalEffect at 0x00446710
(80 bytes). Natural source is src/Character09Effects.cpp; each has
one original-bound REL32 and zero byte differences. Rebuild only
character-09-slot08 or character-09-remove-local-effect. No shared
class-layout changes were needed.


The explicit-X facing member Secondary::FacePosition(double) at
0x0040E6C0 is complete native Exact (116 bytes / zero relocations),
with source src/SecondaryFacePosition.cpp and proof
docs/evidence/secondary-face-position-exact.json. Its nonvirtual
declaration in Engine.h does not change object layout; selected
neighbor owners FaceOpponent and UpdateLocomotionState remain exact.


Ikumi Character14::Slot08 effects is now **complete native strict Exact**,
1,592 bytes / 434 instructions and 33/33 original-bound relocations.
Its old five rand() calls were replaced with the real x87
opponent-X to integer conversions before storing effect.x.
Accepted source is src/Character14Effects.cpp, proof is
docs/evidence/ikumi-slot08-exact.json; rebuild only
scripts/repo-python scripts/replay-exact-units.py --unit character-14-slot08.
The old partial workbench is retired.

Nagamori Character06::Slot05 CPU is now **complete native strict Exact**,
15,292 original bytes / 3,924 instructions, 300/300 original-bound
relocations and zero differences. The source is
`src/Character06Cpu.cpp` and the certificate
`docs/evidence/nagamori-slot05-exact.json`.
Rebuild only with
`scripts/repo-python scripts/replay-exact-units.py --unit character-06-slot05`.
The old partial workbench and prefix test are retired.

Legacy bitmap-to-object conversion at original `0x004019B0` is now
complete strict Exact (614 bytes, all 37 relocations); source is
`src/LegacyObjectConverter.cpp`, proof
`docs/evidence/legacy-object-converter-exact.json`. The original fixed
file paths and file-size-minus-ten behavior have been preserved. This helper
has no known incoming direct calls; do not infer that it is a runtime path.

Nagamori `MarkEffectCollision` at `0x004AE1D0` is an accepted 231-byte owner.
Its `character-06-effect-proximity` recipe uses the isolated declaration in
`workbench/nagamori-helper/CharacterViews.h`, included by
`src/Character06Collision.cpp`. Keep this header: whole-program integration
with the common class declaration remains a separate task.

## Active unfinished owners

| Owner | Canonical extent | Current candidate / next action |
| --- | --- | --- |
| Nayuki Character10::Slot06 state boss | `0x00451850`, 62,693 code bytes + 552/306 local data | `src/Character10State.cpp` and `docs/evidence/character-10-state-slot06-exact.json`: complete native codegen Exact; selected single-unit replay accepted. No whole-project cold replay implied. |
| Shiori `Character08::Slot06` | `0x004136D0`, 63,132 bytes including both tables | `workbench/shiori-state/`: candidate extent 63,132 bytes. Twelve complete cases (300–306, 310–312, 318–319) are byte-exact: 7,493 code bytes, 123 original-bound COFF relocations (88 calls/35 floats) plus two pinned `__ftol2` calls. Case306 is now a complete 567-byte exact body with all eight relocations; cases303/304/305/312/318/319 are 611/796/846/1,084/725/900-byte exact bodies. The final-image resolver restores the native `0x384` stack frame from `0x37C` and ten case318/319 conversion-temp displacements. Three additional meter regions in 307/308/315 are 25/25/26 bytes exact. Register-allocation differences remain in 307–309 and 313–317; attack case307 next. Focused proof: `verify_exact_regions.py`; not whole-function Exact yet. |
| `Scene2::PrepareBattle` | `0x0076CA50`, 4,029 bytes including two address tables and selector | `workbench/prepare-battle/`: complete candidate emits 4,031 bytes / 115 relocations. Investigate first-background allocation at `0x0076D743` and later virtual-load receiver move. Casts, named pointer locals and real background layouts did not fix it. |

Focused diagnostic / exact-region commands (no whole-project replay):

```bash
scripts/repo-python workbench/shiori-state/audit_case_codegen.py --rebuild --start 300 --end 319
scripts/repo-python workbench/shiori-state/verify_exact_regions.py --rebuild
```

These normalized diagnostics do not grant Exact credit. Other workbench READMEs
contain their selected compilation commands. Preserve each candidate's local
headers until its original codegen is resolved. Nagamori Slot07 and the Video
pixel kernels also remain open; current Video candidates are in `src/`.

## Retention

As of 2026-11-11, cleanup removed **365 stale root-level Wine reg*.tmp
registry snapshots**, totaling 398,450,169 bytes (about 380 MiB), after
checking for active Wine/compiler processes. The authoritative system.reg,
user.reg, userdef.reg, pinned VC7.1 toolchain, Ghidra project, original EFZ.exe,
tracked source/evidence and Git history were kept. Untracked build/ and
.analysis/ caches plus Python bytecode were also cleared; subsequent
verify-target, toolchain --check, selected Nayuki Slot06 native rebuild and
lightweight CI all passed. If the next agent needs an ignored artifact, rerun
the selected script rather than restoring the deleted cache.

Keep necessary inputs, current results and useful knowledge. Historical cleanup
archives, duplicate certificates, integrated drafts and superseded private
outputs have been removed. Recreate needed analysis from the canonical target
and selected recipes. No cleanup archive, deletion manifest or receipt refresh
is required for later housekeeping. Commit coherent increments as `gpt-web: `;
never push unless explicitly instructed.
