# Kano Character20::Slot06 — partial real native reconstruction

**Status: PARTIAL — NOT whole-function Exact.** The function vtable
`0x00788C90` selects original code `[0x006429C0,0x006536B5)` of
**68,853 bytes**, with 137 original four-byte jump destinations
`[0x006536B5,0x006538D9)` (548 bytes), and 316 selector indices
`[0x006538D9,0x00653A15)` (316 bytes). Original selector holds
**136 live cases and 180 default IDs**.

Kano `Character20State.cpp` now contains original default and
**102 native-reviewed live cases** through state249. The selected
original code `[0x006429C0,0x0064C750)` covers **40,336 native
bytes / 11,096 original x86 instructions**, SHA-256
`c919786c0a1cb38c73818936db0dd297c6f02574021224c7a636f59ad7b31f75`.
The next physical native case250 begins at **`0x0064C750`**.

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` strict selected checker verifies
**11,096 original instruction positions, widths, normalized forms**,
**1,032 original internal and 136 outbound branch destinations**,
**906 independently original-bound COFF calls/IEEE-754 operands** and
two local switch table references. The incomplete candidate uses
stack0x148 versus original0x4A4, both six-byte allocations with no
position normalization. This is a strict selected prefix, **NOT full
Exact**: **34 missing real state bodies**, the canonical complete
stack frame, adjacent native switch DATA, remaining relocations and
shared return still need verification. Neutral probe case markers
are not accepted as authored source.

New **state249 (822 bytes)** reconstructs an original complex aerial
throw sequence: while frames<5 it requests native horizontal offset
and shake (50,3); frame0/tick1 reverses the grabbed fighter's facing;
X/Y velocity advances under gravity. At frames2/3/4 it moves the
opponent to X+facing*(28/20/29), Y-(47/38/62), and assigns original
opponent states101/101/100 and facing. On frame5/tick0 it sets the
opponent position to own X,Y-72, state63 and facing, calls accepted
`ApplyDamage(1200,500.0)`, resets opponent pose, and assigns original
knockback velocities -1.0/-2.3; at frame12 it sets gravity0.035.
A native landing branch only fires on **strict Y+velocityY >0** and
frame>5, doing own ResetFrame, zeroing Y, virtual own ResetPose,
then switching to state13. Animation end repeats the last two frames.
The full code path, direct call targets and canonical IEEE-754 values
match in selected VC7.1 native comparison.

### Experimental case257 — 899-byte native finisher, unaccepted island

Kano original state257 `[0x0064D556,0x0064D8D9)` has **899 native
code bytes / 241 x86 instructions**. Its full natural C++ has now
been authored in the workbench with distinctly staged behavior:
frame0/7 resets; native charge buildup with cap10000 and tier residue
7500; command13 resource cancel into state251 only after frame16;
frame3 paired local effects 0x196/0x197; frame17 launches effect
**0x191** at integer X+facing*38 / integer Y−45, `owner=1`,
character sound5 and `field316c` increment. It uniquely performs
frame19→16 rewind and increments `field3138` once before animation
completion. This is not a copy of the 254–256 frame16 effect paths.

Use only the dedicated original-bound structural audit:

    scripts/repo-python workbench/kano-state/check_case257_shape.py
    scripts/repo-python workbench/kano-state/check_case258_shape.py
    scripts/repo-python workbench/kano-state/check_case259_shape.py
    scripts/repo-python workbench/kano-state/check_case261_262_shape.py
    scripts/repo-python workbench/kano-state/check_case263_264_shape.py
    scripts/repo-python workbench/kano-state/check_case265_267_shape.py
    scripts/repo-python workbench/kano-state/check_case268_269_shape.py
    scripts/repo-python workbench/kano-state/check_case270_shape.py
    scripts/repo-python workbench/kano-state/check_case300_shape.py
    scripts/repo-python workbench/kano-state/check_case301_shape.py
    scripts/repo-python workbench/kano-state/check_case303_shape.py
    scripts/repo-python workbench/kano-state/check_case302_shape.py
    scripts/repo-python workbench/kano-state/check_case260_shape.py
    scripts/repo-python workbench/kano-state/check_case259_shape.py

The selected VC7.1 candidate matches **all 241 original instruction
offsets, lengths and register-abstracted instruction forms**, **22
exact native in-state branch destinations**, **3 genuine original
shared-return jumps**, and **10 independently original-bound COFF
call/IEEE-754 operands** (three ResetFrame, six `__ftol2` and one
native double500.0). Original SHA-256 for the 899-byte case:
`7f13ea29ee1f9c768e845bb8f412b7c6919bcc00bbe9e25cf3ed278e940d4013`.

**NOT Exact**: the concrete register allocation does not match the
native case because state250's compiler phase remains unresolved.
These island checks do not grow the 40,336-byte strict contiguous
prefix or register any complete owner. Never count later diagnostic
neutral marker states as original code.

### Experimental state302 — shaken 894-byte super with independent impacts

Kano state302 original `[0x00650992,0x00650D10)` spans **894
native bytes / 235 x86 instructions**. Natural C++ authors its
frame0 dash/frame reset, unconditional `SetHorizontalShake(50,3)`,
frame7 reset, charge+100 on frames3–6 with early escape to frame7,
and paired frame3 effects0x196/0x197. Frame10 consumes **3000
meter**, applies original tint0xB0 duration0xA4, hits for 120
frames, emits stage effect0x46/palette0x40 with Y−43 and requests
context sound37. Frame13 produces native effect0x1C1 with
`owner=1`, `field0030=1` (not field0028), and original facing
flags. Animation advances attackCollisionResult0 with frame7->3
rewind and state0 completion.

Targeted independent oracle:

    scripts/repo-python workbench/kano-state/check_case302_shape.py

Original SHA-256
`81b236428e7ff7d17099d0ca571c8b138db00c4c5a60a60477d6dfcc6672d5a2`
is pinned. The checker verifies **235 original instruction
offsets/widths/register-abstracted forms**, **18 internal and 2
shared-return original branches**, plus **13 independently
original-bound REL32 calls** including original
SetHorizontalShake, SetTint, ResetFrame, Context::EmitEffect and
`__ftol2`. It is **native structural evidence only, NOT complete
Exact**: original case250 register-allocation phase remains open;
strict contiguous Boss prefix is still **40,336 bytes**.

### Experimental case303 — 884-byte second-stage super launcher

Original Kano state303 `[0x00650D10,0x00651084)` is **884 native
code bytes / 233 x86 instructions**, now authored in natural C++.
Its original frame13 freeze/tint/palette0x13 effect costs1,000 meter;
frame3 emits paired effects0x196/0x197, frame3–6 charge increases by
100, full charge switches to frame8, and frame14 launches native
local effect **0x19C** at integer Y−110 and X=integer positionX.
It preserves original frame0/7 resets, face flag and final pose0.

Run the scoped original-bound case check:

    scripts/repo-python workbench/kano-state/check_case303_shape.py

The native SHA-256
`3e6a9667b4b4ae0785f0815d512889fc40f30478c52092306c5957f8fe825cc6`
is fixed. This audits **all 233 original instruction positions,
widths and register-abstracted opcodes**, **18 original internal
branches**, **2 shared returns**, and **13 native-bound COFF calls**
(ResetFrame, SetTint, EmitEffect and floating integer conversion).
The source has not solved case250's concrete register phase, so
**this is a structural island, NOT full Exact** and does not advance
the 40,336-byte original contiguous prefix.

### Experimental case301 — 962-byte tier-two original super

Kano original state301 `[0x006505D0,0x00650992)` is **962 original
code bytes / 254 x86 instructions** with fully authored natural C++.
It retains the frame0/7 reset and frame3 paired 0x196/0x197
local effects but differs from state300: frame13 spends **2,000
meter**, uses context effect0x45/palette5 and native tint/freeze,
then frame15 emits local effect0x1A3 at integer X+facing×40,
integer Y−40. It charges+100 through frames3–6 and, at full
charge10000, resets to zero and selects frame7. Frame19 rewinds
three poses up to six times, not state300's shorter iteration.

Scoped checker (NEVER all-unit cold replay):

    scripts/repo-python workbench/kano-state/check_case301_shape.py

Canonical native SHA-256
`976a8b842aa8a6b6b74d67165d60923b40b8798bbaf2af18c91946fc0349b4dc`
is pinned. The checker independently verifies **254 x86 native
instruction offsets/widths/register-abstracted forms**, **20
canonical in-case jumps**, **2 shared-return targets**, and all
**13 original-bound COFF call/IEEE-754 operand references**. This
is a **structural island only, NOT complete Exact**: original
case250's register phase is still open and the formal strict
continuous prefix remains 40,336 code bytes.

### Experimental case300 — 1,168-byte original super and shockwave

Kano state300 `[0x00650140,0x006505D0)` has fully authored natural
C++ covering **1,168 original code bytes / 305 x86 instructions**.
Frame13 freezes hitstun120, spends 1,000 meter, calls SetTint,
emits context effect0x44/palette0x13 at integer Y−100 and restores
the timing frame. Frame0/7 reset, frame3–6 charge+100, full-charge
10000 early loop to frame8, frame3 dual effects0x196/0x197,
frame16 sound29 and guarded effect0x1C7, frame7/18 animation
rewinds and state0 return are all authored in their original order.

Scoped original-bound checker:

    scripts/repo-python workbench/kano-state/check_case300_shape.py

It pins native SHA-256
`9773fc66dde7c1b53a78b118c26031eb45a4d7e4f88691fed2774fa61b07367e`,
**305 original instruction positions/widths/register-abstracted
forms**, **27 internal and 2 shared-return original jumps**, and
**13 independently original-bound COFF call/IEEE-754 operands**.
No ASM/byte wrapper was used. This remains a **structural island,
NOT full owner Exact**: original state250's concrete-register
allocation still blocks the 40,336-byte strict continuous prefix.

### Experimental case270 — 991-byte resource-backed airborne pulse

Original Kano state270 `[0x0064FD61,0x00650140)` contains **991
code bytes / 265 original x86 instructions**. Its authored natural
C++ reconstructs the original airborne rebound (initial X/Y
velocity each ×0.5, gravity0.01, meter+45), followed by resource
spend of 500 or 250 depending on the original field0120 gate.
The first tick emits context effect0x21 (palette11); frame2
emits local effect0x197 at X−facing×30,Y−30, while field313c
triggers three further original pulses at times16,32,48 with
positions X+facing×30/Y−30, X+facing×20/Y−10, and
X−facing×20/Y−10. Frame7 repeats until the state counter reaches3,
then restores state9 and gravity0.035 in original call order.

Run only the independent selected original-bound shape audit:

    scripts/repo-python workbench/kano-state/check_case270_shape.py

It verifies original SHA-256
`4b6c89fa0b1f03b0679e5d93ac001b93484ca454472cc69d625d989ce80e08df`,
all **265 native instruction offsets/widths/register-abstracted
forms**, **14 exact internal original branches**, **2 real shared-
return jumps**, and **17 independently original-bound COFF call /
IEEE-754 operands**, including five native `double` constants and
`Context::EmitEffect` at 0x00407100. It intentionally does NOT claim
byte-wise equality for concrete registers. **NOT full Exact**:
the original case250 phase still blocks advancing the strict
40,336-byte contiguous prefix.

### Experimental state300 — 1,168-byte native super sequence

Original Kano case300 `[0x00650140,0x006505D0)` comprises **1,168
native code bytes / 305 original x86 instructions**. Authored
natural C++ in `Character20State.cpp` reconstructs its full
frame0 and frame7 reset behavior, frame13 hitstop120 and meter−1000,
`SetTint(0xB0,3)` call, stage effect0x44/palette0x13 at
X=int(positionX), Y=int(positionY)−100, group2/layer1/owner1,
then hit count5 and ResetFrame. It accumulates field3150 by100 on
frames3–6, fast-forwards frame8 at charge10000, and emits original
paired 0x196/0x197 local effects on frame3. Frame16 sets original
sound29; frame16 after animation step emits 0x1C7 with multiple
facing-dependent X-branch alternatives, and frame18 can rewind one
pose until field3138 reaches3. Native reset ends at state0.

Focused canonical test:

    scripts/repo-python workbench/kano-state/check_case300_shape.py

The independent checker freezes original SHA-256
`9773fc66dde7c1b53a78b118c26031eb45a4d7e4f88691fed2774fa61b07367e`
and verifies **all 305 native instruction offsets/widths and
register-abstracted forms**, **27 original internal jump targets**,
**2 shared-return branches** and **13 independently original-bound
COFF direct-call / IEEE-754 operands** (three `ResetFrame`, `SetTint`,
`Context::EmitEffect`, seven `__ftol2`, and native zero double).
This is a *native-bound structural island*, NOT full Exact: the
upstream state250 register-phase divergence still prevents advancing
the strictly verified 40,336-byte continuous prefix. No ledger credit
for complete owner or artificial code padding.

### Experimental state270 — 991-byte multiwave airborne finisher

Original Kano state270 occupies `[0x0064FD61,0x00650140)`:
**991 native code bytes / 265 true x86 instructions**. Its
natural C++ is authored in `Character20State.cpp`, preserving the
frame0 velocity half-life, gravity0.01, meter+45 and conditional
500.0/250.0 resource cost; it emits stage effect0x21 palette11
at native Y−50. The special also emits four distinct local effect
0x197 waves: frame2 X−facing×30/Y−30, then field313c=16
X+facing×30/Y−30, 32 X+facing×20/Y−10 and 48
X−facing×20/Y−10. Animation frame7 repeats poses until the native
field3138 limit and eventually recovers into state9/gravity0.035.

The dedicated test:

    scripts/repo-python workbench/kano-state/check_case270_shape.py

independently binds original SHA-256
`4b6c89fa0b1f03b0679e5d93ac001b93484ca454472cc69d625d989ce80e08df`,
all **265 native instruction offsets/widths/register-abstracted forms**,
**14 original internal branches, 2 native shared-return branches and
17 original-bound COFF/IEEE-754 operands**. This is a structural
native island, **NOT concrete-register or full-function Exact**:
original case250 still blocks the strict continuous Kano prefix at
40,336 bytes. It does not change accepted function/Exact ledgers.

### Experimental cases268–269 — two 447-byte airborne recovery attacks

The original Kano state268 `[0x0064F9E3,0x0064FBA2)` and269
`[0x0064FBA2,0x0064FD61)` are two independent **447-byte /
123-instruction** airborne recovery paths. Natural C++ in
`Character20State.cpp` reconstructs both: on frame0 each halves
horizontal/vertical velocity by0.5, installs gravity0.01, gains
45 meter and initializes field3138=3. Every tick then advances
velocityY by gravity. At frame2, effect0x197 is emitted at
integer X−facing×30, integer Y−30, with original flag/layer/group
write order. On animation frame7, at most three times, it advances
field3138 and rewinds four poses. When the animation ends it calls
native virtual ResetPose, sets state9 and restores gravity0.035.

Reproducible original-bound scope checker:

    scripts/repo-python workbench/kano-state/check_case268_269_shape.py

Both canonical SHA-256 extents and all **246 original instruction
offsets, widths, register-abstracted forms** are matched with
**16 exact native internal and 4 canonical shared-return branches**,
plus **12 independent COFF float/call operand bindings**: original
0.5 twice, 0.01, two __ftol2 calls and 0.035 per state. This is a
structural island **NOT concrete-byte or full-function Exact**;
original case250 register mismatch still blocks the strict native
prefix beyond 40,336 bytes. No accepted function credit.

### Experimental cases265–267 — triple image effects (1,488 native bytes)

Original Kano state265 `[0x0064F413,0x0064F5FF)` is **492 bytes**;
states266 `[0x0064F5FF,0x0064F7F1)` and267
`[0x0064F7F1,0x0064F9E3)` are **498 bytes each**, all three with
**132 original x86 instructions**. Three substantial natural-C++
case bodies are authored in `Character20State.cpp`. Frame0 resets
motion, calls ResetFrame and sets `field3138=2`. At frame3 tick0,
all use sound6, effect `0x1A2`, layer1/group2 and three distinct
`EmitLocalEffect` calls, each with facing-sensitive X coordinates
and original Y offsets −480, −520, −530:

| State | Three facing-scaled X offsets |
| --- | --- |
| 265 | 100, 80, 130 |
| 266 | 180, 160, 210 |
| 267 | 260, 240, 290 |

On frame advancement each clears collisionResult; completion sets
state0 and invokes ResetPose **before** FaceOpponent, as in original.
No speculative meter or status change is introduced.

Run the dedicated native shape/branch/oracle check:

    scripts/repo-python workbench/kano-state/check_case265_267_shape.py

Each native 132-instruction subrange matches the selected VC7.1 C++
by **all original offsets/widths/register-abstracted forms**, **six
original internal jumps and one shared-return jump**, plus **eight
independently original-bound COFF REL32 calls** (1 ResetFrame,
6 `__ftol2`, 1 FaceOpponent). The complete three-island audit covers
**1,488 bytes / 396 x86 instructions, 18 original internal and 3
outbound branches, and 24 call bindings**. The native original SHA
for each subrange is pinned in the checker. This is NOT concrete
register or full-owner Exact because case250 register-phase mismatch
remains unresolved. Strict prefix stays **40,336 native bytes**.

### Experimental cases263–264 — 1,621-byte native-bound paired lances

The original native Kano cases263 and264 are
`[0x0064EDBE,0x0064F0E7)` (**809 code bytes**) and
`[0x0064F0E7,0x0064F413)` (**812 bytes**). They now have separate
fully authored C++ branches. Their original charge sequence uses
frame6 instead of 7, adds **300 per frame** during frames3–5,
resets charge to0 upon reaching10000, and conditionally rewinds
frame16 twice. At frame12 they launch effect **0x199** with
positionY fixed at **−40.0**, native X+
**facing×110** (263) or **facing×160** (264), and play sound2.
On frame15 each decrements field313c; frame3 emits paired local
effects0x196/0x197. These are not copies of prior 261/262 tier
behavior, and the 160-width IMUL adds three native bytes.

Run the original-bound checker:

    scripts/repo-python workbench/kano-state/check_case263_264_shape.py

It fixes both native SHA-256 values and independently checks all
**434 original instruction offsets/widths/register-abstracted forms**,
**38 internal and 4 original shared-return branches**, and **16
original-bound COFF calls/IEEE-754 constants** (ResetFrame,
`__ftol2`, original −40.0). This is a structural island **NOT
concrete-byte or whole-function Exact**; native case250's unresolved
compiler register phase prevents moving the independently strict
40,336-byte continuous prefix.

### Experimental cases261–262 — paired charged effect launchers

The original Kano states261 and262 occupy native
`[0x0064E726,0x0064EA72)` and `[0x0064EA72,0x0064EDBE)`,
**844 bytes / 225 x86 instructions each**. Both now have authored
natural C++ code. Their original state0/frame7 resets and frame3
paired 0x196/0x197 local effects match, but the distinct charge
residue, effect type and resource cost are Kano-specific:
**261: charge5000, launch0x1B9, meter−20**;
**262: charge2500, launch0x1BA, meter−50**. Frame12 launches at
X=positionX,Y=-80 and the native sound4/field3168/field313c/
field3138 write order differs between these two tiers.

Run:

    scripts/repo-python workbench/kano-state/check_case261_262_shape.py

This selected native-bound checker verifies both original SHA-256
extents, **450 real instruction offsets/widths/register-abstracted
forms**, **40 exact internal branch targets**, **6 canonical shared
returns**, and **18 original-bound COFF call/IEEE-754 references**.
Both original bodies match these structural properties; concrete
compiler registers remain different because case250 is still open,
so **NOT whole-Exact and no new formal ledger credit**. The independently
strict contiguous Kano prefix remains **40,336 bytes**.

### Experimental case259 — 1,586-byte five-impact charged finisher

Original Kano state259 `[0x0064DDBF,0x0064E3F1)` is **1,586 code
bytes / 414 x86 instructions**, the largest restored post-state250
special thus far. The authored natural C++ includes the original
state0/7 motion reset, 75-per-frame charging, full10000 charge with
residue2500, command13/resource gate, and two frame3 local effects
0x196/0x197. At animation frame17 the three distinct tier cases
(`field3138` == 0/1/2) emit the original **five impact effects**
(type 0x191) at Y−45, Y−20, Y−70, Y+5 and Y−95. Each uses the
original facing-X offset38, owner/facing assignment order, character
sound5 and **10-meter** deductions after each hit; frame19 rewinds
three frames for up to three rounds, then returns to state0.

Run the focused audit:

    scripts/repo-python workbench/kano-state/check_case259_shape.py

Original-bound SHA-256
`0cea3ab88f212da9516f5a88a6bfcbb086a08736f7aee22e01ed81f396fdd6c8`
is frozen, together with **414 exact instruction offsets/widths and
register-abstracted forms, 24 original internal branches, 3 shared
return branches and 18 original-bound COFF call/IEEE-754 operands**
(3 ResetFrame, 14 __ftol2, 1 original 500.0 double literal).
The native `owner`/facing-write order differs between its original
effect branches; preserving that order was essential for the 414
matching instruction positions and widths.

This is an independently verified **structural island, NOT concrete
register or whole-function Exact**. Original state250's register
phase still prevents expanding the strict contiguous 40,336-byte
prefix; formal Exact counters remain unchanged.

### Experimental case260 — 821-byte charged fixed-height strike

Kano state260 original `[0x0064E3F1,0x0064E726)` spans **821 native
code bytes / 220 original x86 instructions**. Its natural C++ source
is now authored in `Character20State.cpp`. Unlike the preceding tier,
its native frame7 reset precedes the frame3 pair of local effects
0x196/0x197, then a charge +75 / cap10000 / residual7500. Original
command13 cancellation becomes permitted after frame11. When
animation reaches frame12 with tick0, it emits original local
`0x1B8` at **raw positionX and Y=-80.0**, facing flag before owner,
with group2/layer1/owner1; sets sound4, increments `field3168`,
sets `field313c=21`, and increments `field3138`.

Run only the independent original-bound diagnostic:

    scripts/repo-python workbench/kano-state/check_case260_shape.py

This pins original source SHA-256
`969f7e5aa8c2ac6f4ece7f972603f627cd1d5bfae4b85375632f276a9e9707c9`
and validates **all 220 native x86 instruction addresses, widths,
register-abstracted forms**, **20 native in-state branch targets**,
**3 canonical return jumps**, and **9 independently original-bound
COFF/IEEE-754 operands** (three ResetFrame, four `__ftol2`, original
500.0 and -80.0 double literals). Original assignment order was
necessary to obtain full structural matching.

This remains **NOT native byte Exact**, because the compiler's
concrete register choices differ beyond unresolved state250. Strict
contiguous accepted source prefix stays **40,336 bytes**. No original
function Exact ledger entry, fake wrappers, or diagnostic marker
acceptance is claimed.

### Experimental case259 — 1,586-byte multi-tier five-impact finisher

Kano original state259 `[0x0064DDBF,0x0064E3F1)` is **1,586 code
bytes / 414 native x86 instructions**. The authored natural C++
models the full charged attack: original charge saturation10000 ->
2500 fallback, animation frame7→3 looping, real command13/resource
cancel to state251, and frame17 stages keyed by field3138.
First stage emits original `0x191` effect at Y−45; second emits
Y−20 and Y−70; third emits Y+5 and Y−95. All five impact effects
use facing*38 horizontal displacement, native `owner=1` and
`group2/layer1`, and the original tier-dependent character sound,
`field316c` increment and meter −10. State259 uniquely loops
frame19→16 while field3138 is below 3.

Run the independent, *non-accepting* original-bound diagnostic:

    scripts/repo-python workbench/kano-state/check_case259_shape.py

This pins original SHA-256
`0cea3ab88f212da9516f5a88a6bfcbb086a08736f7aee22e01ed81f396fdd6c8`
and all **414 native x86 instruction offsets/widths/register-
abstracted opcode shapes**, **24 exact original internal branch
targets**, **3 canonical shared return targets**, and **18 independently
original-bound COFF call/IEEE-754 operands** (three ResetFrame,
fourteen `__ftol2`, and native 500.0 double). Correcting the precise
ordering of `effect.owner` and facing flag assignments in stages0/1
was necessary for original instruction-shape parity.

**NOT native Exact**: the concrete register choices continue to
differ after state250. This structural-island evidence neither
advances the 40,336-byte strict selected original prefix nor changes
complete function ledgers. No wrapper/padding or synthetic marker
code has been accepted.

### Experimental case258 — 1,254 native bytes, distinct triple-impact finisher

Original Kano state258 is the **1,254-byte** native owner subrange
`[0x0064D8D9,0x0064DDBF)`, containing **330 original x86
instructions**. Natural C++ in `Character20State.cpp` has been
substantively reconstructed: charge accumulation+75, frame0/7 resets,
full charge10000 with residue5000, original command13 resource cancel,
paired 0x196/0x197 local effects, and three tiered frame17 **0x191**
impact launches at Y-45, Y-20 and Y-70 (facing-adjusted X+38).
It retains original per-impact sound, owner/facing-field assignment
order, `field316c` counters, repeated meter-7 deductions, frame19
three-pose rewind (up to two cycles), and original state0 return.

The dedicated native-bound checker is:

    scripts/repo-python workbench/kano-state/check_case258_shape.py

It independently checks canonical SHA-256
`d42c451e8c015bed1140a2636b84c2792b3fec83ea66f5222c8be91e4b6245d8`,
**all 330 original instruction offsets/widths and register-abstracted
forms**, **23 exact original internal branches**, **3 original
shared-return targets**, and **14 original-bound COFF call/IEEE-754
operands** (three `ResetFrame`, ten `__ftol2`, and double500.0).
Two native details needed explicit correction: a *single outer*
frame17 guard around the two field3138 branches, and different
`effect.owner` / `effect.flag0018` write ordering on the first versus
later impact effects. Both differences affect compiler layout.

This is a **native-bound structural island only, NOT whole-function
or concrete-register Exact**. Earlier state250 still prevents strict
continuous-prefix extension beyond **40,336 bytes**. The selected
Exact ledger and original native frame/return proof stay unchanged.

### Experimental case257 — 899 native bytes, original-bound structural island

Kano state257 native `[0x0064D556,0x0064D8D9)` is **899 original code
bytes / 241 x86 instructions**. Actual natural C++ in
`Character20State.cpp` reconstructs its charged finisher: it resets
frame0 and frame7 motion, accumulates charge by 75 through frames3–6,
uses the original threshold10000/residue7500, and permits original
command13/resource cancel after frame16. On frame3 it emits the two
`0x196`/`0x197` local effects. Frame17 emits the **0x191** effect at
X+facing×38, Y−45, `owner=1`, with original character sound5 and
`field316c` increment. Frame19 repeats three poses once, gated by
`field3138`, rather than the frame16 launch of previous tiers.

Run the dedicated diagnostic:

    scripts/repo-python workbench/kano-state/check_case257_shape.py

It binds original SHA-256
`7f13ea29ee1f9c768e845bb8f412b7c6919bcc00bbe9e25cf3ed278e940d4013`,
**all 241 original instruction addresses/widths/register-abstracted
forms**, **22 original internal branches**, **3 canonical shared-return
branches** and **10 original COFF call/IEEE-754 operands** (three
`ResetFrame`, six `__ftol2`, one 500.0 double). It deliberately does
NOT assert concrete-register bytes, as original case250 still causes
a different compiler register phase. **NOT Exact**, no formal ledger
credit and no advancement of the strict 40,336-byte prefix.

### Experimental cases255–256 — two additional 858-byte native islands

Kano state255 original `[0x0064CEA2,0x0064D1FC)` and state256
`[0x0064D1FC,0x0064D556)` each span **858 native code bytes /
228 original x86 instructions**. Natural C++ is fully authored in
`Character20State.cpp` and reproduces their distinct charged special
attack tiers. Both initialize original effects `0x196` and `0x197`,
reset and wind up on native frame7, accumulate charge by75, and on
full10000 charge select a distinct residue **5000 (state255)** or
**2500 (state256)**. Both preserve native command13 resource-cancel,
frame16 `owner=1` launch, group2/layer1, original grouped
X+facing*150+inputX*70 coordinate and animation/return logic.
The launch effect types are original **0x1BC** and **0x1BD**;
255 reduces meter by **20**, 256 by **50** at launch.

Run the separately scoped diagnostic:

    scripts/repo-python workbench/kano-state/check_case255_256_shape.py
    scripts/repo-python workbench/kano-state/check_case257_shape.py

The checker independently verifies both original SHA-256 extents,
all **456 instruction offsets/widths/register-abstracted forms**,
**40 original in-state branches**, **6 canonical shared-return
branches**, and **20 original native COFF call/double operand
bindings** (five `__ftol2`, three `ResetFrame`, and 500.0/0.0
double literals in each case). This is native-bound code evidence,
NOT whole-function or concrete-register Exact: the original case250
compiler-phase gap remains. These islands do NOT change accepted
ledgers, native Exact counts or the contiguous strict Kano
selected prefix (still 40,336 bytes).

### Experimental case254 island — 835 native bytes, source authored

Original Kano state254 `[0x0064CB5F,0x0064CEA2)` is **835 machine
code bytes / 223 original x86 instructions**. Natural C++ was
substantively authored in `Character20State.cpp`, restoring the two
native frame3 local effects `0x196`/`0x197`, frame7 reset, charge
counter accumulation by75, saturation-cancel threshold10000 and
charge reset to7500, native command13/resource-500 cancel to state251,
frame7->3 rewind, and frame16 `0x1BB` launch with original
positionX + (facing*150 + inputX*70) computation, `effect.owner=1`,
context sound3 and `field3170` increment.

Run **only the dedicated original-bound diagnostic**:

    scripts/repo-python workbench/kano-state/check_case254_shape.py
    scripts/repo-python workbench/kano-state/check_case255_256_shape.py

This checks the original canonical SHA-256
`77afeef263e2e92f5601f26e9dd92f44d17ddfc4f14b5f80e143790cc34a64bf`,
**223 original x86 instruction offsets/widths and register-abstracted
forms**, **20 exact original in-state branch targets**, **3 canonical
shared-return paths**, plus **10 original-bound COFF direct call /
IEEE-754 operands** (five `__ftol2`, three ResetFrame, native 500.0
and native 0.0 literals). A real correction was necessary: the two
facing/inputX terms must be grouped before addition to `positionX`,
and `owner`, not `field0028`, receives the value1.

This remains a **separate register-abstracted structural island, NOT
Exact**. Original and selected candidate concrete register allocation
still differ because the intervening case250 codegen phase is open.
The formal selected prefix MUST remain pinned at original case250
start `0x0064C750`; case254 is NOT credited as a complete/Exact owner.
Native cases252/253 map to default, not missing authored states.

### Experimental case251 island — native instruction-shape audit

The authored `Character20State.cpp` now also includes an original
454-byte special resource/dual-effect state251 at
`[0x0064C999,0x0064CB5F)`. It restores the original field0118
resource reduction by **500.0 or 250.0**, depending on field0120,
the 10000-point charge threshold, native effects 0x198/0x197,
Y−40 and Y coordinates, and one-shot sound1.

Run the **separate** `scripts/repo-python
workbench/kano-state/check_case251_shape.py` audit. With pinned
VC7.1 generated C++ and original EFZ.exe bytes, it verifies **all
117 original x86 instruction addresses and widths**, the same
register-abstracted opcode shapes, **seven internal original branch
destinations** and **seven independently original-bound COFF operands**
(2 native 500.0/250.0 IEEE-754 double DIR32 literals, 1 ResetFrame
call and 4 `__ftol2` calls). The candidate's 16-bit increment uses
`add ax,0x1` whereas original uses `add cx,byte +0x1`, with the
same effect and same instruction length. Other differences involve
scratch-register assignment following original case250's unresolved
compiler phase. **This is NOT Exact**, and native case251 is not
added to formal complete owners or selected-prefix byte totals.
Do not confuse this *register-abstracted island diagnostic* with
the stricter `check_prefix.py` instruction-exact proof pinned before
case250 at 0x0064C750.

### Experimental next state250 — NOT selected-prefix acceptance

Original Kano state250 is `[0x0064C750,0x0064C999)` (**585 code
bytes**). Actual natural C++ has been authored in
`Character20State.cpp`, including original charge counter cap10000,
frame3–6 button release/charge cancel, paired native local effects
`0x196`/`0x197`, four-frame animation rewind, and frame0 reset.
It is **experimental, not accepted**: `probe_prefix.py --through 250`
first diverges at **0x0064C955** (offset `0x9F95` from owner base)
during the tail animation-frame comparison. Native code begins
`mov edx,[ebp-0x54]; movzx eax,word [edx+0xa]`, while the current
VC7.1 candidate rotates scratch registers to EAX/ECX at the same
instruction boundary. Twelve-plus expression variants were tested,
including `==7` reversal, cast/assignment forms, frame-count
comparison order, member qualification and increment forms; none
closed this difference without disrupting earlier matching bytes.
The strict selected native checker remains **pinned at case249 end
0x0064C750** and must NOT be advanced to case250 until full original
instruction/branch/relocation parity is established. No ledger or
`src/` accepted function is changed on this hypothesis.

Important Kano-specific differences from the related Makoto dispatcher:
case1/2 speed `+0.6`/`-0.6`, cases4/5/6 jump start at frame2
not3, gravity `0.025`, vertical launch `-2.2`, optional carry velocity
`0.3` in case4. Cases5/6 terminate with state9 and ResetPose,
unlike Makoto's trailing frame loop. Cases13–16 have Kano's
own grounded/airborne recovery: zero/±0.7 X speed at start, gravity
0.025 and Y=-2.2, optional dash X speeds 0.4 / 1.1, and landing
state13. All these values and source branches were checked against
original code positions and IEEE-754 values. Cases7/8 reset to
state0/3, and case9 applies gravity/landing to state13.

Run ONLY focused checks, not full cold replay:

    scripts/repo-python scripts/verify-target.py
    scripts/repo-python workbench/kano-state/check_prefix.py
    scripts/repo-python workbench/kano-state/check_case251_shape.py
    scripts/repo-python workbench/kano-state/check_case254_shape.py
    scripts/repo-python workbench/kano-state/probe_prefix.py --through 250 --context 12
    scripts/repo-python scripts/ci.py

Next work begins at **Kano case250 `0x0064C750`**. Original
0x4A4 frame, 34 unverified native cases, local switch DATA,
shared return and complete relocation closure remain OPEN. The diagnostic probe generates *only* unaccepted
neutral markers for those later cases; source comments and the
selected checker must not be construed as whole-function completion.
