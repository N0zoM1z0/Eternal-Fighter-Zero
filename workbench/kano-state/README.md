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
