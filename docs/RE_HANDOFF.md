# Current handoff — 2026-11-07

## Operator state and starting point

The operator explicitly resumed active EFZ reconstruction on 2026-11-06,
requesting fast, careful exact recovery with focused checks and selected cold
replays only. Continue from accepted sources and reviewed target evidence;
never infer game completion from a successful unit.

Start with `git status --short --branch`, the diff, this file and AGENTS.md.
Use accepted `src/` and the reviewed ledgers. Preserve unrelated changes and
unfinished private drafts. Local checkpoints have not been pushed; never push
without an explicit instruction. Repository:
https://github.com/N0zoM1z0/Eternal-Fighter-Zero.

Use Bash and local `scripts/ghidra.py`; no REA, Factory prerequisites or subagents.
Keep code, comments, documentation and metadata English. Commit prefix:
`gpt-6.1-sol: `. Conversation may be Chinese.

## Accepted baseline

| Fact | Accepted result at this handoff |
| --- | ---: |
| Authored complete exact functions | 315 |
| Authored exact instruction bytes | 931,962 |
| Associated exact local-table bytes | 6,621 |
| Reviewed boundaries / origins | 351 / 351 |
| Compiler-generated auxiliary helpers | 14 functions / 579 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

[PROGRESS.md](PROGRESS.md) is generated from the live ledgers. Acceptance authority
is config/matches.csv plus docs/evidence/ and the per-unit recipes. Auxiliary
helpers are excluded from authored totals; candidates are not a coverage
denominator. A runnable product, linked data/resources, original TU partitioning,
original/reconstructed runtime comparison and portability remain open.

Accepted source covers reader/Audio/Input/Context owners, title and selection
scenes, substantial shared Secondary character code, the Shiori constructor and
ten child virtual bodies, and substantial battle scene control/collision/display.
Do not interpret this as full character, renderer or game closure. Historical
checkpoint facts and detailed target findings live in
[KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md); its older totals/open statements describe
those checkpoints, not today's queue.

## Latest Mayu animation/state checkpoint

Character05::Slot06 at5C8580 is complete strict exact:87,209 instruction bytes
plus954 local-table bytes, total88,163; complete exclusive end5DDDE3. Source:
src/Character05State.cpp; profile vc71-od-static; proof:
docs/evidence/mayu-state-exact.json. Durable facts:
[Mayu animation and state owner](KNOWLEDGE_BASE.md#mayu-animation-and-state-owner).
Private retained evidence:.analysis/probes/mayu-state/README.md.

Independent review covers24,252 instructions,2,361 branches and the complete
158-address /322-selector switch:157 explicit cases and165 defaults. Code ends
5DDA29; tables end5DDDE3;13 excluded CC bytes precede constructor5DDDF0. Original
vtable788A68 slot6 operand788A80 points5C8580. All2,059 relocation fields are
independently checked:482 calls,1,417 doubles,160 local bindings. All135 payloads
match target/COFF. Natural frame448 retains receiver EBP-54 and descriptor EBP-50;
duration/count occupy EBP-4/-8. Preserve positive exits, actual equality tests,
original branch joins and x87/integer operand association. Shared headers stay
unchanged; both F2 WORD stores use the existing opaque bytes through typed access.

The first complete source was built early and final formatting received a whole
comparison. One final selected cold replay passes all88,163 bytes and2,059
reviewed bindings. Public headers/all332 prior recipes/source owners remain
unchanged. Focused tracking, ledgers/progress CI and whitespace checks pass.
Two native source errors were fixed, each followed by a successful required
--execute toolchain smoke; no compiler/Wine issue remains. Retain all draft /
build logs and artifacts. No old/full replay, full CI or runtime matrix ran.

All thirteen actual Mayu virtual destinations are exact, including inherited
LoadResources. Next work should select another coherent target-bound character
owner from the canonical creation/table evidence, build a complete source early
and independently review every boundary/operand. Do not infer product/game
closure. All Ghidra jobs are terminal. Preserve parked PrepareBattle/Shiori
controls and the unaccepted reader-audio workbench.

## Previous Mayu local-effect checkpoint

Character05::Slot07 at5E5C30 is complete strict exact:10,512 instruction bytes
plus168 associated table bytes, total10,680; complete exclusive end5E85E8. Source:
src/Character05Effects.cpp; profile vc71-od-static; proof:
docs/evidence/mayu-effects-exact.json. Durable facts:
[Mayu local effect dispatch and controls](KNOWLEDGE_BASE.md#mayu-local-effect-dispatch-and-controls).
Private retained evidence:.analysis/probes/mayu-effects/README.md.

Independent review covers2,374 instructions,146 branches and the full17-address /
100-selector compressed switch:16 explicit types400..499 and84 defaults. All144
relocations are independently checked:46 direct calls,79 doubles,19 local bindings.
All36 payloads match target/COFF. Original vtable788A68 slot7/operand788A84 points
to5E5C30. Used descriptor/cursor/count locals retain natural frame12C and EBX/ESI.
Preserve frame3/9 landing exits, frame5 conversion, child counter<=730, coordinate
association and CRT sample/multiplier order. Types408/409 really return from the
complete effect update after conversion; do not turn those returns into breaks.

The first complete source was built early; final formatting received another
whole comparison. One final selected cold replay passes all10,680 bytes and144
reviewed bindings. Public headers/all331 previous recipes/source owners remain
unchanged. Focused tracking, ledgers/progress CI and whitespace checks pass.
No compiler/Wine failure, old/full cold replay, full CI or runtime matrix ran.

Twelve of thirteen actual Mayu virtual entries are exact. Next substantial owner:
state5C8580/87209 instruction bytes; associated tables remain unreviewed. Fresh
read-only annotation:.analysis/probes/mayu/calls-annotated-005c8580.txt. It was
successfully obtained with verified DecompileOptions.setMaxPayloadMBytes(128);
all Ghidra jobs are terminal. Build a complete source early and independently
review every original boundary/operand before credit. Resource/data/runtime/TU
and game phases remain open. Preserve parked PrepareBattle/Shiori controls.

## Previous Mayu CPU checkpoint

Character05::Slot05 at5E2440 is complete strict exact:14,310 instruction bytes,
exclusive end5E5C26, without local tables. Source:src/Character05Cpu.cpp;
profile vc71-od-static; proof:docs/evidence/mayu-cpu-exact.json. Durable facts:
[Mayu CPU command and movement owner](KNOWLEDGE_BASE.md#mayu-cpu-command-and-movement-owner).
Private retained evidence:.analysis/probes/mayu-cpu/README.md.

Independent review covers3,705 instructions,649 branches and275 relocations:
100 RandomRange, two CollisionSide, one external fabs and172 typed floating
operands. All38 payloads match target/COFF; all100 random results zero-extend AX.
Natural frameCC retains receiver EBP-14 and distance record EBP-10/-8. Preserve
original sample/expression order, positive exits and movement-timer priority.
The near-facing owner's final distance<100 failure still returns from this
update; do not merge that distance test into the outer successful guard.

The first full source was compiled early and fully compared after formatting.
One final selected cold replay passes all14,310 bytes and275 reviewed bindings.
Public headers and all330 prior recipes/source owners are unchanged. Focused
tracking, ledgers/progress CI and whitespace checks pass. No old/full replay,
full CI or runtime matrix ran; no compiler/Wine failure occurred.

Eleven of thirteen Mayu virtual entries are exact. State5C8580/87209 code and
effects5E5C30/10512 code remain OPEN, with associated tables unreviewed. All13
fresh read-only annotated decompiles are retained in .analysis/probes/mayu/;
the buffered state job completed and all Ghidra jobs are terminal. Continue
complete coherent owners and review canonical boundaries/operands before credit.
Resource/data/runtime/TU and game phases remain open. Preserve parked controls.

## Previous Mayu construction/input/command checkpoint

Ten complete Character05 owners add17,957 strict exact instruction bytes without
local tables:constructor5DDDF0/410, initializer5DDF90/270, reset5DE0A0/58,
removal5DE0E0/80, locomotion5DE130/19, input5DE150/12047, empty slots01/08
at5E1060/11 and5E1070/11, emitter5E1080/47, commands5E10B0/5004. Sources:
src/Character05Frame.cpp, Character05Input.cpp, Character05Commands.cpp;
profile vc71-od-static; proof:docs/evidence/mayu-exact.json. Durable facts:
[Mayu construction input and indicator owners](KNOWLEDGE_BASE.md#mayu-construction-input-and-indicator-owners).
Private evidence:.analysis/probes/mayu/README.md.

Canonical creation ID5 allocates3448, copies "mayu" from788A60 and installs
vtable788A68. Only Character05's opaque tail is expanded into four scalar ints
and three64-int arrays3148/3248/3348, ending3448 naturally. Preserve actual
commandCount5, duplicate commands[3]=2 then4 and sparse commands[10]=5.
Independent review covers4,731 instructions,730 branches and119 relocations
(54 calls,63 typed doubles, string/vptr). All11 double payloads match target/COFF.
Input preserves positive action/throw tails and directional product order;
commands preserve15 ordered circular-history scans and actual mask/threshold forms.

The final selected cold comparison passed76 complete units from35 serial native
artifacts:ten new and66 actual CharacterViews.h consumers. The other254 units
retain earlier proofs. All894 compiler-generated symbol renames are checked
against unchanged canonical targets/local offsets and string bytes. Report:
.analysis/exact/mayu-and-affected.json; log:.analysis/build/mayu-formal-replay.log.
Focused tracking, ledgers/progress CI and whitespace checks passed. No native
compiler/Wine failure, full CI/cohort or runtime matrix occurred.

Ten of thirteen Mayu virtual destinations now have complete exact proofs,
including inherited LoadResources. Next substantial owner:CPU5E2440/14310 bytes;
state5C8580/87209 code and effects5E5C30/10512 code remain OPEN with associated
tables unreviewed. All13 fresh read-only annotated decompiles are retained in
.analysis/probes/mayu/calls-annotated-*.txt. The first batch stopped when state
hit Ghidra's response-buffer limit; a separate state job with verified
DecompileOptions.setMaxPayloadMBytes(128) completed successfully. All jobs are
terminal; preserve their logs. No database/target changes were saved.
Resource/data/runtime/TU and game phases remain independently open. Keep parked
PrepareBattle/Shiori controls until new evidence predicts an instruction.

## Previous Misaki local-effect checkpoint

Character07::Slot07 at56F920 is complete strict exact:15,562 instruction bytes
and224 associated table bytes, total15,786; complete exclusive end5736CA. Source:
src/Character07Effects.cpp; profile vc71-od-static; public proof:
docs/evidence/misaki-effects-exact.json. Durable facts:
[Misaki local effect dispatch and controls](KNOWLEDGE_BASE.md#misaki-local-effect-dispatch-and-controls).
Private retained evidence:.analysis/probes/misaki-effects/README.md.

Independent review covers3,572 instructions,228 direct branches and the full
31-address /100-selector switch for30 explicit types400..499. All193 relocation
fields are independently checked:69 calls,91 double operands and33 local bindings.
All26 double payloads match target and COFF; all nine RandomRange callers zero-
extend AX. Preserve CRT random expression order, positive lifecycle exits and
ring wrap64. Natural frame19C retains the used descriptor and cursor/count locals.

Complete source was compiled early and fully compared again after formatting.
One final selected cold replay passed all15,786 bytes and193 reviewed bindings.
Public headers and all319 previous recipes/source owners remain unchanged; no
old unit needed replay. Focused tracking, ledgers/progress CI and whitespace
checks passed. No compiler/Wine failure, full CI/cohort or runtime matrix occurred.

All thirteen actual Misaki vtable788808 destinations now map to complete exact
recipes, including inherited LoadResources. Virtual-body closure does not close
resource/data/runtime/TU or game phases. Continue substantial coherent owners;
Mayu (ID5, constructor5DDDF0, allocation3448) is a useful next candidate. Recheck
its complete constructor, installed vptr and real fields against the canonical
target before source changes. No fresh Mayu decompile has been started. Preserve
parked PrepareBattle/Shiori controls until new evidence predicts an instruction.

## Previous Misaki animation/state checkpoint

Character07::Slot06 at5571F0 is complete strict exact:66,501 instruction bytes
and841 associated table bytes, total67,342; complete exclusive end5678FE. Source:
src/Character07State.cpp; profile vc71-od-static; public proof:
docs/evidence/misaki-state-exact.json. Durable facts:
[Misaki animation and state owner](KNOWLEDGE_BASE.md#misaki-animation-and-state-owner).
Private retained evidence:.analysis/probes/misaki-state/README.md.

Independent review covers18,119 instructions,1,658 branches,131 explicit cases,
the132-address /313-selector compressed switch and every canonical destination.
All1,519 relocation fields were independently checked:432 calls,953 double
operands and134 local bindings. All101 double payloads match target and COFF;
all eight random calls zero-extend AX. Vtable788808 slot06/operand788820 points
to5571F0. Natural frame414 retains the used descriptor, duration/count and ESI.
Preserve the two real frame>-1 guards in state164, positive tails, original
operand order and successful/outer exits. Original TU/class origin stays open.

Complete source was compiled early, refined against target instructions and
fully compared again after formatting. One final selected cold replay passed
all67,342 bytes and1,519 reviewed bindings with zero differences. Public headers
and all318 previous recipes/source owners remain unchanged; no old unit needed
replay. Focused tracking, ledgers/progress CI and whitespace checks passed.
No compiler/Wine failure, full CI/cohort or runtime matrix occurred.

Twelve of thirteen Misaki virtual destinations now have complete exact proofs.
Next substantial owner:effects56F920/15562 instruction bytes; associated tables
remain unreviewed. The fresh read-only annotated decompile is retained in
.analysis/probes/misaki/calls-annotated-0056f920.txt. Build a complete source early
and review all original boundaries/operands before credit. Game/resource/runtime
and TU phases stay independently open. Preserve parked PrepareBattle/Shiori
controls until new target evidence supplies a falsifiable instruction prediction.

## Previous Misaki CPU checkpoint

Character07::Slot05 at56B630 is complete exact:17,127 instruction bytes,
exclusive end56F917. Nine excluded CC bytes precede effects56F920; no local
tables occur. Source:src/Character07Cpu.cpp; profile vc71-od-static.
Public proof:docs/evidence/misaki-cpu-exact.json. Durable facts:
[Misaki CPU command and movement owner](KNOWLEDGE_BASE.md#misaki-cpu-command-and-movement-owner).
Private retained evidence:.analysis/probes/misaki-cpu/README.md.

Independent review covers4,399 instructions,809 internal branches and all318
relocation fields:108 RandomRange, two CollisionSide, one external fabs and207
typed floating operands. All39 fresh canonical literal payloads match native
COFF; all108 random callers zero-extend AX. There are no indirect calls/tables.
The real distance locals recover frameFC, receiver EBP-14 and distances EBP-10/-8.

Accepted Character23 CPU natural source, with only owner/comment changes,
matched the entire new target on its first native compile. This is independently
verified complete codegen reuse, not similarity credit. Preserve original action /
hurt priorities, random sample order, positive tails, movement timers and the
actual contradictory distance>800 /<120 guard. Original class/TU origin stays open.

One final selected cold native replay passed with all318 reviewed bindings.
Public headers and all317 prior recipes/source owners are unchanged; no old unit
needed replay. Focused tracking, ledgers/progress CI and whitespace checks passed;
no full CI/cohort or runtime matrix ran. No compiler/Wine failure occurred.
Preserve all private target evidence, external fabs ABI review and build exits.

Eleven of thirteen Misaki virtual destinations now have complete exact proofs.
Next substantial owner:state5571F0/66501 instruction bytes; associated tables
remain unreviewed. Effects56F920/15562 code bytes also remains OPEN. Fresh read-only
annotated decompiles are in .analysis/probes/misaki/. Build a complete source
early and review all original code/table boundaries and operands before credit.
Resource/data/runtime/TU and game reconstruction remain independent open phases.
Keep parked PrepareBattle/Shiori controls until new target evidence supplies a
falsifiable instruction prediction.

## Previous Misaki construction, input and command checkpoint

Ten Character07 owners add15,615 complete exact instruction bytes, no local
tables: constructor567900/390, initializer567A90/270, reset567BA0/58,
removal567BE0/80, locomotion567C30/19, input567C50/10656,
empty slots01/08 at56A5F0/11 and56A600/11, emitter56A610/47,
commands56A640/4073. Sources:src/Character07Frame.cpp, Character07Input.cpp,
Character07Commands.cpp; profile vc71-od-static. Proof:docs/evidence/misaki-exact.json.
Durable facts:
[Misaki construction input and indicator owners](KNOWLEDGE_BASE.md#misaki-construction-input-and-indicator-owners).
Private attempts/review:.analysis/probes/misaki/README.md.

Canonical creation ID7 allocates3448, copies resource literal788800 "misaki"
and installs vtable788808. Only Character07's existing opaque tail is expanded
into four scalar ints and three64-int arrays3148/3248/3348, ending3448 without
padding. Preserve constructor commandCount5 and four explicit command entries
1/11/18/7; no extra ID store is inferred. Initializer calls only the shared base.
Slots01 and08 really are empty; do not invent indicators/frame behavior.

Independent review covers4,100 contiguous instructions,638 internal branches
and all100 relocation fields:49 direct calls,49 typed double operands,string
and vptr. Input has frame14 /receiver EBP-4; commands frameC /receiver EBP-C.
Keep actual unsigned byte operations, positive air guards, directional product
order, first phase >1 and later >=2 gates. Thirteen ordered command scans
retain actual windows, grounded guard, one >=1000 threshold and mask semantics.

Formatted public sources passed63 complete strict comparisons from29 serial
cold source/profile/dependency artifacts: ten new units and53 actual header
consumers. All726 generated-name refreshes preserve reviewed offsets/destinations
or literal bytes;254 unrelated existing units retain earlier artifacts.
Engine.h and Input.h are unchanged. Focused tracking, ledgers/progress CI and
whitespace checks passed; no full CI/cohort or runtime matrix ran. No native
compiler/Wine failure occurred. Preserve all analysis/native exits.

Ten of thirteen original Misaki virtual destinations now have complete exact
proofs (nine new child bodies plus inherited LoadResources). Next substantial
owner: CPU56B630/17127. State5571F0/66501 and effects56F920/15562 code bytes
remain OPEN with associated tables unreviewed. Fresh canonical annotated
decompiles for all13 new bodies are retained in .analysis/probes/misaki/;
decompiler text confers no acceptance. Build complete first source early and
review all original boundaries/operands before credit. Resources, runtime, TU
partitioning and game remain independently open. Keep parked Shiori/PrepareBattle
controls until new target evidence supplies a falsifiable instruction prediction.

## Previous Mishio local-effect checkpoint

Character15::Slot07 at54FD30 is complete exact:29,568 instruction bytes plus
308 associated table bytes, total29,876. Code ends5570B0,52-destination address
table ends557180 and100-byte selector ends5571E4. Twelve excluded CC bytes
precede next function5571F0. Source:src/Character15Effects.cpp;
profile vc71-od-static. Public proof:docs/evidence/mishio-effects-exact.json.
Durable target findings:
[Mishio local effect dispatch and controls](KNOWLEDGE_BASE.md#mishio-local-effect-dispatch-and-controls).
Private attempts/reviews:.analysis/probes/mishio-effects/README.md.

Review covers6,781 contiguous instructions,477 internal branches,51 explicit
effect types and all279 relocation fields:95 direct calls,130 typed floating
operands,54 local bindings. All34 double payloads match target/COFF; all20
random callers zero-extend AX. All16 rand draws preserve original coefficient
order. There are79 real virtual calls. Natural used descriptor/index/duration/
count locals recover frame1C8, receiver EBP-5C, descriptor EBP-50, index EBP-4
and duration/count EBP-54/-58 with saved EBX/ESI.

Preserve type414-before413 physical order, both type417 cancellation guards,
positive landing owners, unsigned word updates, integer particle subtraction
and fifteen direct exits to queue advancement. Equal-size diagnostic cases
concealed some branch operands; final complete raw code/table comparison passed
zero differences after final formatting and renewed operand review.

One final selected cold native replay passed. All306 existing recipes/source
owners and public headers are unchanged; no old unit needed replay. Focused
tracking, ledgers/progress CI and whitespace checks passed; no full CI/cohort
or runtime matrix ran. No native compiler/Wine failure occurred in this effect
checkpoint. Preserve all private evidence and compiler exits.

All13 original Mishio vtable788768 destinations now have complete exact proofs,
including inherited LoadResources. Constructor acceptance is additional to the
virtual-entry inventory. Resource/data/runtime/TU and game closure remain open.
Next substantial character family may start with the already boundary-reviewed
constructor567900/390. Recheck canonical creation ID, resource string, allocation
and full virtual table before integrating; constructor review alone confers no
exact credit. Keep parked PrepareBattle/Shiori controls until new target evidence
supplies a falsifiable instruction prediction.

## Previous Mishio state checkpoint

Character15::Slot06 at530BC0 is complete exact:87,313 instruction bytes plus
934 associated local-table bytes, total88,247. Code ends5460D1,154-destination
address table ends546339 and318-byte selector ends546477. Nine excluded CC
bytes precede accepted constructor546480. Source:src/Character15State.cpp;
profile vc71-od-static. Public proof:docs/evidence/mishio-state-exact.json.
Durable target findings:
[Mishio animation and state owner](KNOWLEDGE_BASE.md#mishio-animation-and-state-owner).
Private attempts/reviews:.analysis/probes/mishio-state/README.md.

Independent review covers23,524 contiguous instructions,2,363 internal branches,
153 explicit states and all1,612 relocation fields:516 direct calls,940 typed
floating operands,156 compiler-local bindings. All79 double payloads agree in
canonical target/COFF. All12 random callers zero-extend AX;418 virtual calls
retain actual owners. The real72-byte descriptor and used duration/count locals
recover frame49C, receiver EBP-54, descriptor EBP-50 and duration/count EBP-4/-8,
with saved ESI. Preserve the five-byte epilogue and all934 table bytes.

Keep unsigned slide/tick reads, positive landing and collision exits, immediate
thresholds, integer particle subtraction and direct frame-rollback exits.
State178's nested/outer breaks both matter. States300..302 first handle the
positive phase3 airborne-opponent guard and exit; their repetition/failure
branches also leave the dispatch. All19 shared polar calls address the actual
velocity prefix at this+8 and preserve the already reviewed callee ABI.

Formatted public source passed one final selected complete cold native replay.
All305 prior recipes/source owners and public headers are unchanged; no old
unit required replay. Focused tracking, ledger/progress CI and whitespace checks
passed; no full CI/cohort or runtime matrix ran. Initial provisional comma
assignments failed syntax; corrected source followed a successful required
verify-toolchain --execute smoke. All native exits and evidence remain retained.

Twelve of thirteen Mishio virtual destinations now have complete exact proofs.
Next substantial owner:local effects54FD30/29568 instruction bytes, candidate
code end5570B0, with associated tables still unreviewed. Fresh read-only annotated
decompile:.analysis/probes/mishio/calls-annotated-0054fd30.txt. Build the complete
first source early and review all code/table boundaries and operands before
credit. Resource/runtime/game phases and original TU partitioning remain open.
Keep parked PrepareBattle/Shiori controls until new target evidence supplies a
falsifiable instruction prediction.

## Previous Mishio CPU checkpoint

Character15::Slot05 at54C250 is complete exact:15,066 instruction bytes,
exclusive end54FD2A, no local tables. Six excluded CC bytes precede54FD30.
Source: src/Character15Cpu.cpp; profile vc71-od-static; proof:
docs/evidence/mishio-cpu-exact.json. Durable target findings:
[Mishio CPU command and movement owner](KNOWLEDGE_BASE.md#mishio-cpu-command-and-movement-owner).
Private attempts and independent review: .analysis/probes/mishio-cpu/README.md.

Review covers3,883 contiguous instructions,722 internal branches and all297
relocations:90 RandomRange, two CollisionSide, one external fabs and204 typed
floating operands. All38 literal payloads match target/COFF; all90 random callers
zero-extend AX. Shared CPU mode3114 is distinct from Mishio's3158. Signed inline
ternaries, real forward/vertical distances and original evaluation order recover
frameC0 with receiver EBP-14. Preserve positive decision priorities and the two
natural returns at54E15D/54E162; merging them loses five bytes.

Formatted source passed one final selected complete cold native replay. All304
prior recipes and public headers are unchanged; no old unit required replay.
Focused tracking, ledgers/progress CI and whitespace checks passed; no full
CI/cohort or runtime matrix ran. No compiler/Wine failure occurred. Preserve
all native exits and private analysis.

Eleven of thirteen Mishio virtual destinations now have exact proofs. Next
substantial owner: state530BC0, candidate87313 instruction bytes ending5460D1,
with associated tables still unreviewed. Effects54FD30/29568 code bytes also
remains OPEN with associated tables unreviewed. Both read-only annotated
decompiles are in .analysis/probes/mishio/. Build a complete first source early;
review original instruction/table boundaries and all operands before credit.
Preserve parked PrepareBattle/Shiori controls until new evidence offers a
falsifiable instruction prediction. Resource/runtime/game phases remain open.

## Previous Mishio construction, input and indicator checkpoint

Ten complete Character15 owners add23,968 exact instruction bytes, without
associated tables: constructor546480/513, initializer546690/413,
reset546830/58, removal546870/80, locomotion5468C0/19,
action input5468E0/13534, indicators549DC0/3278, frame control54AA90/701,
emitter54AD50/47 and commands54AD80/5325. Sources:
src/Character15Frame.cpp, Character15Input.cpp and Character15Commands.cpp;
profile vc71-od-static. Public proof: docs/evidence/mishio-exact.json.
Durable target findings:
[Mishio construction input and indicator owners](KNOWLEDGE_BASE.md#mishio-construction-input-and-indicator-owners).
Private retained attempts/reviews: .analysis/probes/mishio/README.md.

Selection15 allocates3478; constructor resource literal788760 says "mishio"
and vptr788768 has13 reviewed destinations. The Character15 tail now contains
15 observed scalar ints and three64-int arrays3174/3274/3374. Natural alignment
retains3478. Both creation consumers preserve their complete original bytes.
No other class view, Engine.h or Input.h changed.

Independent review covers6,271 instructions,880 internal branches and all156
relocation fields (97 direct calls,57 typed floating operands,string and vptr).
Keep commandCount/commands stores30F4/30F5/30FF, the initializer's base-only
call, unsigned byte operations, first two phase >1 gates, and directional
product order. Frame control uses self tints and a real72-byte descriptor;
indicators multiply field3168 before frame.width, retaining frame274.

Formatted public sources passed50 complete strict comparisons from23 serial
cold source/profile/dependency artifacts: ten new units and40 actual header
consumers. All515 generated-symbol name refreshes preserve reviewed local
positions/destinations or literal bytes;254 unrelated existing units retain
prior artifacts. Focused tracking, ledgers/progress CI and whitespace checks
passed; no full CI/cohort or runtime matrix ran. No compiler/Wine failure
occurred in this checkpoint. All private evidence and build exit logs remain.

Ten of thirteen Mishio virtual destinations now have exact proofs (nine new
child bodies plus inherited LoadResources). Next substantial owner:
CPU54C250/15066. State530BC0/87313 code bytes and effects54FD30/29568 code
bytes remain OPEN with associated tables unreviewed. All13 annotated decompiles
are retained privately, but confer no acceptance. Continue with complete first
source and early native comparison, reviewing original boundaries/operands
before ledger credit. Preserve parked PrepareBattle/Shiori controls until new
evidence offers a falsifiable instruction prediction. Resources, original TU
partitioning, runtime and game reconstruction remain independently open.

## Previous Misuzu local-effect checkpoint

Character23::Slot07 at 5236D0 is complete exact: 54,139 instruction bytes plus
372 associated local-table bytes, total contribution 54,511. Code ends 530A4B;
the 68-destination address table ends 530B5B, followed by a 100-byte selector
ending 530BBF. One excluded CC byte precedes next entry530BC0. Source:
src/Character23Effects.cpp, profile vc71-od-static. Public proof:
docs/evidence/misuzu-effects-exact.json; durable findings:
[Misuzu local effect dispatch and controls](KNOWLEDGE_BASE.md#misuzu-local-effect-dispatch-and-controls).
Private full attempts and independent review: .analysis/probes/misuzu-effects/README.md.

Review covers 12,296 contiguous instructions, 832 internal branches, 67 explicit
effect cases and all 662 relocation fields: 173 direct calls, 419 typed floating
operands and 70 compiler-local bindings. All 78 literal payloads agree in target
and COFF. All 112 RandomRange callers zero-extend AX; the 16 rand calls retain
their original sample/coefficient order. There are 128 real virtual calls.

Preserve original direct case exits, threshold immediates, word frame updates,
effect/orientation operand order and integer particle subtraction. Sixty particle
coordinates evaluate and spill their arithmetic before calling RandomRange;
that natural evaluation order recovers the original frame494. The used72-byte
descriptor is EBP-50, index EBP-4, duration/count EBP-54/-58 and receiver EBP-5C,
with saved EBX/ESI. Context selection reads are explicitly signed; actual
state1420c/state1420e stores use existing fields, without scaled pointer arithmetic.

Formatted source passed one final selected cold complete zero-difference native
replay, including all table bytes. Public headers and all prior source/recipes
are unchanged; no old native unit needed replay. Focused tracking, ledger/
progress CI and whitespace checks passed; no full CI/cohort/runtime matrix ran.
The initial provisional Context cast syntax failure was corrected; required
toolchain --execute smoke passed before subsequent native attempts. All inputs,
objects and compiler exits remain retained.

All 13 original Misuzu table788650 destinations now have complete exact proofs,
including inherited LoadResources. This closes the virtual-entry code inventory
only; linked resources/data, original TU partitioning, runtime and game remain
open. Next substantial family: constructor546480/513 uses canonical "mishio"
literal788760 and vtable788768. Recheck its creation ID, actual owner and complete
virtual extents before integrating source; constructor origin/boundary review
alone is not accepted exact code. Preserve parked PrepareBattle/Shiori controls
until new target evidence provides a falsifiable instruction prediction.

## Previous Misuzu state checkpoint

Character23::Slot06 at 50C4B0 is complete exact: 54,769 instruction bytes plus
853 associated local-table bytes, total contribution 55,622. Code ends 519AA1;
the 134-destination address table ends 519CB9 and the 317-byte selector ends
519DF6. Ten following CC bytes precede accepted constructor 519E00 and are
excluded. Source: src/Character23State.cpp, profile vc71-od-static. Public proof:
docs/evidence/misuzu-state-exact.json; durable facts:
[Misuzu animation and state owner](KNOWLEDGE_BASE.md#misuzu-animation-and-state-owner).
Private attempts and full review: .analysis/probes/misuzu-state/README.md.

Independent review covers 14,960 contiguous instructions, 1,430 internal branches,
133 explicit animation cases and all 1,300 relocation fields: 343 direct calls,
821 typed floating operands and 136 local table bindings. All 77 literal
payloads and every original table destination agree. There are 217 real virtual
calls. The used 72-byte descriptor and ordinary duration/count locals recover
frame2B4, receiver EBP-54, descriptor EBP-50 and duration/count EBP-4/-8 without
padding or fake ABI declarations.

Preserve unsigned tick reads, actual byte/word updates, positive landing/collision
and cancel exits, original threshold immediates, frame rollback and integer
particle subtraction. Animation211's velocity update belongs inside its positive
airborne guard; animation212's positive hit exit precedes normal work. Specials
300..302/304 and repeat owners310..312 jump directly out of the dispatch. The
cutscene writes real Context state1420c/state1420e fields through actual owners;
do not reintroduce scaled pointer arithmetic from provisional decompiler text.

Formatted source passed one final selected cold complete strict zero-difference
native replay, including both complete tables. Public headers and all prior
source/recipes are unchanged; no old native unit needed replay. Focused tracking,
ledger/progress CI and whitespace checks passed. No native compiler/Wine failure,
full CI/cohort or runtime matrix occurred during this checkpoint.

Twelve of the 13 original table788650 destinations had exact source proofs at
this checkpoint, including inherited LoadResources. Local effects5236D0/54139
has since been accepted above. Fresh canonical read-only decompile remains at
.analysis/probes/misuzu/calls-annotated-005236d0.txt; it confers no progress credit.
Keep the parked PrepareBattle/Shiori controls until new target evidence supplies
a falsifiable instruction prediction. This is not character/runtime or game
closure.

## Previous Misuzu CPU checkpoint

Character23::Slot05 at 51F3E0 is complete exact /17,127 instruction bytes,
exclusive end 5236C7. Nine following CC alignment bytes precede local effects
5236D0 and are excluded. No local tables occur. Source: src/Character23Cpu.cpp,
profile vc71-od-static. Public proof: docs/evidence/misuzu-cpu-exact.json;
durable facts:
[Misuzu CPU command and movement owner](KNOWLEDGE_BASE.md#misuzu-cpu-command-and-movement-owner).
Private full attempts and independent review: .analysis/probes/misuzu-cpu/README.md.

Review covers 4,399 contiguous instructions, 809 internal branches and all 318
relocation fields: 108 RandomRange calls, two CollisionSide calls, one external
fabs call and 207 typed floating operands. All 39 literal payloads match the
native COFF and canonical target. The used forward/vertical distance record
recovers EBP-10/-8, receiver EBP-14 and complete frame FC without padding.
Preserve physical decision priority, positive conditional tails, integer
constant-minus-boolean products, all random draws and unsigned AX conversions.
The original late condition really requires distance.forward >800 and <120;
do not simplify or repair its apparently contradictory source conditions.

Final formatted public source passed one selected cold complete zero-difference
native replay. No public header or existing source changed, so no prior native
unit required replay. Tracking, ledger/progress CI and whitespace checks passed;
no full CI/cohort or runtime matrix ran. One initial generated-source syntax
failure was corrected; the required toolchain --execute smoke passed before
subsequent builds. All compiler exits and attempts remain retained.

Eleven of 13 original table 788650 destinations had exact proofs at this
checkpoint, including the shared resource loader. State50C4B0/54769 has since
been accepted above; local effects5236D0/54139 remains open. Review complete
extents before
acceptance and build the first complete natural source early. Fresh read-only
decompiles remain under .analysis/probes/misuzu/; they confer no progress credit.
Preserve parked PrepareBattle/Shiori controls without a new falsifiable target
instruction prediction. This checkpoint does not establish character/runtime
or game closure.

## Previous Misuzu construction, input and indicators checkpoint

Ten complete exact functions add 21,917 instruction bytes without local tables.
Sources: src/Character23Frame.cpp, Character23Input.cpp and Character23Commands.cpp.
The canonical constructor 519E00/615, resource literal "misuzu" at 788648,
allocation 3488 and vtable 788650 establish Character23 ownership. Public proof:
docs/evidence/misuzu-exact.json; durable facts:
[Misuzu construction input and indicator owners](KNOWLEDGE_BASE.md#misuzu-construction-input-and-indicator-owners).
Private complete attempts and reviews: .analysis/probes/misuzu/README.md.

Accepted bodies include InitializeState 51A070/555, ResetPose 51A2A0/58,
RemoveLocalEffect 51A2E0/80, locomotion 51A330/19, action input 51A350/12340,
HUD indicators 51D390/2631, frame control 51DDE0/330, EmitLocalEffect 51DF30/47
and command scanning 51DF60/5242. Complete review covers 5,766 instructions,
780 internal branches and all 136 relocation fields. All boundaries exclude
following padding; no local-table or partial-function acceptance is used.

Preserve opponent ownership of frame-control tint, field345c * frame.width
operand order in the gauge, constructor/initializer store order, actual byte
increments, positive air-action branches, unsigned command stages and every
scan's single-wrap 180-entry history indexing. The ordinary 72-byte effect
descriptor, real shared methods and natural class alignment retain the target
ABIs without padding or fake declarations. Only Character23's existing opaque
tail in CharacterViews.h is expanded; Engine.h and Input.h are unchanged.

Formal replay selected the ten new units and 27 actual CharacterViews.h
consumers from 17 serial cold artifacts. All 37 complete comparisons passed
strict zero differences. Refreshed local-symbol identities preserve reviewed
offsets, destinations and literal bytes. The other 254 existing units retain
their prior evidence. Focused tracking, ledger/progress CI and whitespace checks
passed; no full CI/cohort or runtime matrix ran.

Ten of the 13 original vtable destinations had exact proofs at this checkpoint,
including the inherited shared resource loader. CPU 51F3E0/17127 has since been
accepted above; state 50C4B0/54769 and local effects 5236D0/54139 remain open.
Fresh read-only decompiles are retained under the private Misuzu probe;
they confer no progress credit. Preserve parked PrepareBattle/Shiori
controls unless new evidence gives a falsifiable instruction prediction.

## Previous Mizuka state checkpoint

Four complete exact units add65,964 instruction bytes plus836 local-table bytes:
Character24::Slot06 at4E7EC0/65782 code, Secondary::SetHorizontalOffset410A40/63,
Context::StartReverseFade408080/59 and Context::SetSceneTimer4080C0/60. Source:
src/Character24State.cpp and src/MizukaStateSupport.cpp. Main complete contribution
66618 bytes ends4F82FA, including130-destination /316-selector tables; six CC
bytes precede the accepted constructor4F8300. Public proof:
docs/evidence/mizuka-state-exact.json; durable facts:
[Mizuka animation and state owner](KNOWLEDGE_BASE.md#mizuka-animation-and-state-owner).
Private full attempts/review: .analysis/probes/mizuka-state/README.md.

Complete review covers17,962 instructions,1,636 internal branches,129 animation
cases and1,454 relocation fields:442 calls,880 typed floating operands and132
local bindings. Preserve explicit unsigned tick/0158 reads, positive landing/
slide tests, direct state exits, animation178's separate completed-frame exit,
integer particle subtraction, all random draws and exact floating operand order.
The real used72-byte descriptor and ordinary duration/count locals yield frame42C,
receiverEBP-54, descriptorEBP-50 and duration/countEBP-4/-8 without padding.

Three nonvirtual method declarations and two canonical word/byte stores refine
Engine.h; remaining layout and existing method bodies are unchanged. Formal
replay selected4 new units plus244 actual Engine.h consumers from67 serial cold
artifacts; all248 strict whole-contribution comparisons passed. Local-symbol
identities were checked against unchanged offsets/destinations/literal bytes.
Thirty-three unrelated old units retained earlier evidence. Focused tracking,
ledger/progress CI and whitespace checks passed; no full CI/cohort/runtime matrix.

All13 original table7885D0 destinations now have complete exact source proofs,
including the inherited resource loader. This is a virtual-entry inventory
milestone, not linked-data/resource, runtime or game closure. The next character
is now target-bound to Misuzu/Character23 above, with accepted constructor and
nine child virtuals. Its state body50C4B0/54769 remains open; recheck the live
ledgers before selecting further owners.
Do not retry parked PrepareBattle/Shiori-state controls without a new target-
backed instruction prediction.

## Previous Mizuka local-effect checkpoint

Three complete exact units add42,383 instruction bytes plus348 local-table bytes:
Character24::Slot07 at501E20/42279 code, SecondaryPose::VectorAngle4C0480/45 and
Context::StartFade408040/59. Sources: src/Character24Effects.cpp and
src/MizukaEffectSupport.cpp. Main complete contribution42627 bytes ends at50C4A3,
with its full62-destination address table and100-byte selector; thirteen CC bytes
precede next function50C4B0. Public proof: docs/evidence/mizuka-effects-exact.json;
durable facts: [Mizuka local effect dispatch and controls](KNOWLEDGE_BASE.md#mizuka-local-effect-dispatch-and-controls).
Private attempts/review: .analysis/probes/mizuka-effects/README.md.

Review covers9,600 main instructions,715 direct branches, one indirect switch,
61 explicit effect cases and505 total new relocation fields. Preserve type437
between420 and421, positive hit/cancel/bounce branches, word frame arithmetic,
actual random-sample coefficient order and direct switch exits440/497/498.
Whole-contribution strict comparison includes all348 table bytes; normalized
branch/case diagnostics never confer acceptance. VectorAngle uses the real pose
receiver atthis+8; the external CRT descriptor78F220 explicitly names atan2.

Only two nonvirtual Engine.h declarations change; public data layout and old
method bodies are unchanged. Formal affected replay selected3 new units plus241
Engine.h consumers from65 serial cold source/profile/dependency artifacts; all
244 complete comparisons passed strict zero-difference. Generated local-symbol
identities were reviewed against unchanged offsets/destinations or literal bytes.
Thirty-three unrelated old units retain prior evidence. Focused tracking, ledger/
progress CI and whitespace checks passed; no full CI/cohort/runtime matrix ran.

Slot06 state4E7EC0/65782 has since been accepted above, completing the exact
virtual-entry code inventory for table7885D0. Linked data/resources, runtime and
game remain open. Preserve neutral parked PrepareBattle/Shiori-state controls.

## Previous Mizuka CPU checkpoint

Character24::Slot05 at4FDC10 is complete exact /16,912 instruction bytes,
exclusive end501E20; no local tables or following padding. Source:
src/Character24Cpu.cpp, profile vc71-od-static. Public proof:
docs/evidence/mizuka-cpu-exact.json; durable facts:
[Mizuka CPU command and movement owner](KNOWLEDGE_BASE.md#mizuka-cpu-command-and-movement-owner).
Private complete attempts and independent review: .analysis/probes/mizuka-cpu/README.md.
Review covers4,368 instructions,818 internal branches and341 relocation operands:
109 direct calls plus232 typed floating operands from38 distinct payloads.

The final formatted public source passed one selected cold strict complete
zero-difference native comparison. Public headers and existing sources are
unchanged; no old native unit replay was needed. Tracking, ledger/progress CI
and whitespace checks passed; no full CI/cohort or runtime matrix ran.
Preserve unsigned AX random conversions, x87 operand order, used distance record,
positive special-state timer priority, active movement timer exits and the
separate successful-choice/outer state204 exits. Original vtable is7885D0 slot5.

Slot07 local effects501E20/42279 and slot06 state4E7EC0/65782 have since been
accepted above. Existing exact owners do not establish runtime/character closure.

## Previous Mizuka command checkpoint

Character24::Slot02 at4FAF70 is now complete exact /11,423 instruction bytes,
exclusive end4FDC0F; no calls, relocations or local tables. Source:
src/Character24Commands.cpp, profile vc71-od-static. Public proof:
docs/evidence/mizuka-command-exact.json; durable facts:
[Mizuka circular command recognition](KNOWLEDGE_BASE.md#mizuka-circular-command-recognition).
Private full attempts and independent review: .analysis/probes/mizuka-command/README.md.
Review covers3352 instructions,547 internal branches and32 ordered scans.

One final selected cold artifact passed strict complete zero-difference
comparison after numeric-stage/whitespace formatting. Existing source and
headers are unchanged; no old unit replay was needed. Tracking, ledger/progress
CI and diff whitespace checks passed; no full cohort/CI/runtime matrix ran.
Preserve single-wrap history indexing, every scan window, sequential state
advancement, gate-mask !=0 versus positive command-ID terms, stage6/7 store
order and the short release/press scan's actual unsigned byte ==1/==0 checks.

Slot05 CPU4FDC10/16912, slot06 state4E7EC0/65782 and slot07 local
effects501E20/42279 have since been accepted above. Inspect the live ledgers
before selecting further units;
existing accepted virtuals do not imply a complete runnable character.

## Previous Mizuka action checkpoint

Eight new complete Character24/Mizuka virtuals add10,953 instruction bytes,
without local tables. Source: src/Character24.h, Character24Input.cpp and
Character24Frame.cpp. The partial view moved out of SceneLoadingCharacter.cpp;
Engine.h and CharacterViews.h are unchanged. Members: InitializeState4F8480/263,
ResetPose4F8590/58, RemoveLocalEffect4F85D0/80, Slot034F8620/19,
Slot04 action selection4F8640/10464, Slot014FAF20/11, Slot084FAF30/11,
EmitLocalEffect4FAF40/47. The original vtable remains7885D0.

Public proof: docs/evidence/mizuka-exact.json; durable findings:
[Mizuka action selection and lifetime](KNOWLEDGE_BASE.md#mizuka-action-selection-and-lifetime).
Private attempts and reviews: .analysis/probes/mizuka/README.md.
All ten selected complete strict native comparisons passed from three serial
cold artifacts: eight new functions and the two actual creation-source consumers.
All26 local table/destination bindings were independently checked; the original
25-entry character creation table is still compared completely. Focused tracking,
ledger/progress CI and diff whitespace checks passed. No full cohort or CI ran.

Keep original unsigned latch/countdown checks and byte increments/decrements,
positive frame-permission masks, >= meter thresholds, x87 operand order and
structured air-attack branches. Whole-function comparison after any source
change is essential. The large action selector alone reviews2655 instructions,
430 internal branches,42 direct calls,42 real virtual calls and87 relocations.

Mizuka Slot02 command scanner4FAF70/11423 has since been accepted above.
Slot05 CPU4FDC10/16912, slot06 state4E7EC0/65782 and slot07 local
effects501E20/42279 have since been accepted above. Inspect complete boundaries
and associated local tables for new owners.
A full target-bound character constructor and selected virtuals do not complete
that character's runtime implementation.

PrepareBattle was retested once with real accepted Backgrounds.h declarations,
base inheritance and layout. The full4031-byte compiled result against4029
remained unchanged, including first non-table GPR divergence76D743. Evidence:
.analysis/probes/loading-owner/README.md. That control is parked; no repeated
type/layout experiments without a new falsifiable prediction.

## Previous background checkpoint

All four animated background owners for stages1/10/12/16 now have complete
constructors, destructors, Update and Render implementations, plus both shared
resource loaders. Eighteen authored functions add9,248 instruction bytes and
16 local address-table bytes. The implicit abstract-base constructor /23 and
PatternSequence scalar-deleting helper /44 are auxiliary, without authored credit.
Source: src/Backgrounds.h, src/Backgrounds.cpp, src/BackgroundResources.cpp.
SceneBattleLoop now includes the real shared two-slot/28-byte declaration;
Engine.h and the other existing source owners are unchanged.

Public proof: docs/evidence/backgrounds-exact.json; target findings:
[Animated background owners](KNOWLEDGE_BASE.md#animated-background-owners).
Private full attempts, target dumps and reviews: .analysis/probes/backgrounds/README.md.
Final20 new and six actual SceneBattleLoop source consumers passed all26
complete strict comparisons from only three serial cold artifacts. All five
local table/destination bindings were independently checked before symbol-name
refresh. Tracking, ledger/progress CI and diff whitespace checks passed.
No whole cohort or runtime matrix ran.

Preserve the signed Render layer byte, stage01/10 different early returns,
stage12 switch fallthrough, stage16 type3 clamp to947, unconditional metadata
reads and full disabled BMP branch. The constructor's initial patterns array
is overwritten by LoadPatterns; the destructor uses scalar delete on the final
array pointer. These original behaviors are preserved, with no runtime repair.
Background16::Update is complete604 bytes (588 code +16 table), end752DBC.
The base implicit constructor has only a vptr store and receives auxiliary
compiler-generated origin rather than authored progress credit.

PrepareBattle remains open. This checkpoint supplies real background layout,
implicit-base and ownership evidence; any resumed experiment must make a
specific prediction from that evidence, not repeat its parked pointer/case controls.
Read both the background and scene-loading private READMEs before reuse.

## Previous loading checkpoint

Seven new complete authored functions add 3,779 instruction bytes and100 local
address-table bytes: Scene2 constructor76C6F0/74, destructor76C740/69,
Step76C790/488, renderer76C980/203, keyboard76DA10/11,
LoadCharacter76DA20/2551+100, and Mizuka/Character24 constructor4F8300/383.
Sources: src/SceneLoading.cpp and src/SceneLoadingCharacter.cpp. Scene2 now
exposes its genuine +434 loading surface while keeping allocation size438.
Character24's partial view has since moved into Character24.h; CharacterViews.h
is unchanged. Scene1 ID22 and Scene2 ID22 both create Character10; the loading
dispatch also handles the additional Mizuka ID24, allocation3460.

Public proof: docs/evidence/scene-loading-exact.json; durable findings:
[Loading scene and Mizuka creation](KNOWLEDGE_BASE.md#loading-scene-and-mizuka-creation).
Private evidence and parked substantial owner: .analysis/probes/scene-loading/README.md.
Final seven new and204 existing Engine.h consumers passed all211 complete strict
comparisons from57 selected serial cold source/profile/dependency artifacts.
All161 compiler-local destination/offset bindings and four original string
payloads were independently checked before any symbol-name refresh. The replay
resumed the existing cold artifacts after its initial inventory guard stopped on
three additional replay literals; no source/compiler failure or native restart.
Focused tracking, ledger/progress CI and diff whitespace checks passed.

PrepareBattle76CA50 remains OPEN. Complete target4029 bytes includes3893 code
and136 local address/selector bytes. parked-best preserves the complete4031-byte
draft and its full source/header/object context; this is not a two-byte-away
exact claim. First non-table operand mismatch is76D743 (background constructor
argument GPR choice); a later extra ECX receiver move adds2 bytes. Pointer
views/casts, destructor declarations and case scopes were byte-neutral and are
parked. Do not overwrite src with those private headers. Preserve full disabled
BMP branches and the independently confirmed stage16 scale0.125 and divisor1.5f.

## Previous screenshot checkpoint

`Video::SaveScreenshot` at 0x40C1C0 /962 is now complete exact in
`src/VideoScreenshot.cpp`, profile vc71-od-static-gs. One final selected cold
artifact passed with zero differences and twenty explicit relocation bindings.
Public proof: docs/evidence/video-screenshot-exact.json; complete target facts:
[Video screenshot writer](KNOWLEDGE_BASE.md#video-screenshot-writer).
Private attempts and audits: .analysis/probes/video-output/README.md.
No common header or accepted source changed, so no old units required replay.
Focused tracking, ledger/progress CI and diff whitespace checks passed.

Preserve its original palette/header overwrite order, stride calculation and
unchecked error behavior. Local scope or work-record changes require a complete
cold comparison. FillRectangle40B300 is also now confirmed to have a body-local
EDI save/restore around a handwritten-looking pixel loop; park it alongside the
other assembly-style blitters unless a permitted natural C++ strategy emerges.

## Previous battle checkpoint

Four complete authored members add 4,998 instruction bytes, with no local tables:

| Member | Entry | Bytes | Source / profile |
| --- | --- | ---: | --- |
| Scene3::DrawNumber | 0x75DB70 | 466 | SceneBattleVisuals.cpp / vc71-od-static |
| Scene3::RenderShadows | 0x762C50 | 1,440 | SceneBattleVisuals.cpp / vc71-od-static |
| Scene3::PollKeyboard | 0x765660 | 2,358 | SceneBattleInput.cpp / vc71-od-static-gs |
| Scene3::ResetReplay | 0x7661A0 | 734 | SceneBattleInput.cpp / vc71-od-static-gs |

The misleading RenderMeters declaration is now RenderShadows. The constructor's
17 adjacent font rectangles are represented as `numberStyles[17]` at +464,
without moving subsequent fields. Context exposes actual signed bytes 1340,
14281 and 14282; WordFile/Input grant the genuine Scene3 access. Video declares
the reviewed DrawShadowSurface callee at 40A7B0, whose implementation stays open.

Complete review covers 1,209 instructions, 93 internal direct branches,
38 direct calls, five actual virtual/COM calls and all 54 relocation fields.
Preserve the original disabled keyboard controls, F8 latch store, unsigned digit
arithmetic, signed replay-name bytes and actor/effect shadow-coordinate
asymmetry. These are target facts, not cleanup opportunities. See
[the durable findings](KNOWLEDGE_BASE.md#battle-number-shadows-and-keyboard-replay-control).

Final public sources, including their formatting edits, passed strict complete
comparison for four new and 210 actual Engine/Input/SceneBattle header consumers
from 55 serial cold source/profile/dependency artifacts. All 135 existing local
destination/offset bindings and the Shiori literal refresh were independently
checked. No full cold cohort or runtime test matrix ran.

- Public new proof: docs/evidence/battle-controls-exact.json; involved older
  owner certificates are refreshed, while unaffected reports retain prior proof.
- Private final reports: .analysis/exact/battle-controls-and-affected.json.
- Private target dumps, derivation attempts, boundary/operand review and replay
  selection: .analysis/probes/battle-controls/; read its README before reuse.
- Native log: .analysis/build/battle-controls-formal-replay.log and individual
  battle-controls-cold-* logs. Current accepted objects/receipts: build/match-units/.

Earlier accepted battle/display/collision checkpoints are documented under the
corresponding KNOWLEDGE_BASE headings. Their proof files include
battle-display-exact.json, battle-loop-exact.json, effect-collision-exact.json,
body-hit-exact.json, scene-collision-exact.json and scene-battle-exact.json.
Do not rerun private make/refine/add/prepare/publish/update-docs mutators on the
current baseline. They are retained derivation records, not idempotent tools.

## Parked work and possible follow-ups

Choose substantial owners and useful small functions as reconstruction continues.
Review complete boundaries and compile a complete source
before speculative flag/name sweeps. No future owner has acceptance merely
because its callers or declarations match.

- Shiori slot 6 at 0x4136D0 remains unaccepted. Read
  .analysis/probes/shiori-state/README.md and parked-best/ first. The full target
  is 63,132 bytes: 62,273 code +540 address-table +319 selector bytes, ending at
  0x422D6C. The best complete draft is 63,133 bytes; this is an extent delta,
  not one remaining byte difference. First divergence is 0x41FC1E, animation303.
  Repeated scope/increment/signedness controls were byte-neutral and are parked;
  the later slot-7 operand-order audit supplied no new falsifiable explanation.
  Its private headers predate accepted changes and must not overwrite src/.
- Pushbox 0x766B50 /2727 remains open. Four write-only temporary slots have
  immediate stores but no observed reads. Preserve
  .analysis/probes/scene-collision/pushbox-write-only-audit.json; do not invent
  dummy Booleans or padding to force bytes. Timing thread401850 /157 has a
  similar unresolved pair of initialized unused locals.
- Shiori's constructor is accepted; the 22 other called character constructors
  have reviewed boundaries/origins but no implementation credit. Constructor,
  allocation and 23-table evidence: .analysis/probes/character-create/.
  Other substantial character behavior remains available for recovery.
- Scene2 interlude and creation dispatcher are accepted, while PrepareBattle
  remains open as described above. Scene6 and other character behaviors remain
  possible follow-ups; the four concrete background owners listed above are now
  accepted, while unrelated owners still need their own complete proof.
- DrawSurface409A90, blended40A0B0 and kernel40A440 have reviewed body-local
  ESI/EDI saves and AH/AL pixel loops consistent with handwritten assembly.
  No permitted natural-C++ exact strategy is established. Read
  .analysis/probes/draw-*-review.txt; do not use naked/assembly/byte wrappers.
  Other open Video owners include DrawShadowSurface40A7B0 /806,
  FillRectangle40B300 /308 and buffer conversion.

The accepted Shiori slot7 contribution is 36,467 bytes including 332 table bytes,
ending at 0x434003; retain all 60 local bindings and the complete table comparison.
Context::UpdateEffect is a complete 14,305-byte contribution with 36 local-offset
bindings. Never substitute their Ghidra code-only candidates or normalized
case diagnostics for the accepted complete contribution.

## Verification when work resumes

Canonical ignored/read-only input: resources/EFZ.exe, 3,743,744 bytes, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Release/modification provenance remains unresolved. EFZ.OLD, netplay binaries
and archive labels cannot substitute for this identity.

```bash
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
scripts/repo-python scripts/ghidra.py verify
# Select only new/changed/header-dependent units; replace with actual unit IDs.
scripts/repo-python scripts/replay-exact-units.py --unit config-read-byte
scripts/repo-python scripts/validate-tracking.py --require-target
scripts/repo-python scripts/progress.py
scripts/repo-python scripts/ci.py --only ledgers
scripts/repo-python scripts/ci.py --only progress
git diff --check
```

Use CPython3.13.5 via scripts/repo-python. The pinned VC7.1 RTM compiler/linker
are 13.10.3077 /7.10.3077. Native builds are serial, CPU1, nice10, bounded/logged
and use EFZ's own win32 Wine prefix. Run --execute smoke for setup/tool changes
or actual compiler/Wine failures, not every unit. Ghidra12.1.3 queries are
serialized, read-only/noanalysis and target-attested. Keep per-unit profiles
and all explicit relocation symbols/destinations/evidence. No masked fields,
prefix/size-only comparisons, compare_size overrides or fake ABI declarations.

## Retained evidence and cleanup

The final cleanup corrected stale status/next-work claims, condensed this handoff
and retained durable historical findings. It did not reformat accepted function
bodies after their final native comparisons. The progress card's obsolete
"Initial checkpoint" label was removed. Only focused checks accompany this work.

[RE_ARTIFACTS.md](RE_ARTIFACTS.md) records storage cleanup, compressed evidence
recovery and private cleanup manifests. Preserve the canonical target, original
RAR, tool installations/links, Wine prefix, Ghidra database, analysis attempts,
logs, exact certificates and unfinished drafts. The reader/audio workbench is
historical and fully integrated; read its README before any reuse. Never apply
its old integration.patch or copy its drafts over accepted src/.
