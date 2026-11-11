# Nayuki Character10::Slot06 — partial native state-machine reconstruction

**Status: PARTIAL, NOT full Exact.** Work in
`workbench/nayuki-state/Character10State.cpp` and preserve every local
change. The accepted `src/` tree remains separate, and unrecovered
sibling-derived states must never be counted as original source.

## Original owner

Character10 Slot06 vtable entry at 0x00788288 targets code
[0x00451850,0x00460D35), **62,693 bytes**, SHA-256:
4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9.
Adjacent separately owned switch DATA: 138 four-byte destinations at
0x00460D35, then 306 selector bytes at 0x00460F5D.
The switch maps 137 live animation IDs and 169 default IDs.

## Selected original-bound native checkpoint

Native [0x00451850,0x0045DDCF): **50,559 / 62,693 original code bytes**,
**13,869 x86 instructions**, SHA-256
1780630d3483d240ac6feeb78210d3ebfb15a928481a3c8122749d6b4e301b94.
Default and **117 live states** through 268 have been reviewed.

**State268 is an authored 932-byte command-selector state**, not
synthetic switch-label scaffolding. First-tick ResetFrame precedes the
frame7 command gates. It examines `recognizedCommand` (signed short
at 0x262) values 1, 0, 10, 11, 20 with facing and `field3148` tier
checks, then four original `buttonPulse` bytes at 0x18A–0x18D.
Transitions reset pose, clear buffered buttons, select state IDs
0xA3/0xA4, 250/251/260, 269/275, 274, 276/281, or directional
277/278/271/280/268. The frame7 button3 fallback may rewrite
frame to8 when field3148==9. The native code also preserves
redundant tier>4 writes of 277/278, required for exact VC7.1 forms.
Non-transition frames advance the animation and `field313c`, exiting
to state0 through ResetFrame/ResetPose.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` checks **13,869 same-offset,
same-width normalized instructions**, **1,297 internal branches**,
**188 outbound targets**, **1,071 original-bound external COFF
call/float references**, two local switch operands, and **117 original
case entries**. Only the partial stack allocation differs (0x308
vs original 0x2B4). This is NOT whole-function Exact.

## Next original state and remaining scope

State269 starts **0x0045DDCF**. **13 missing IDs 269–281**, seven
unreviewed 300–306 and the canonical stack/switch data/return are
still open. Workbench has 124 of 137 live state labels, 117 verified.
**12,134 remaining original code bytes**. Continue native-driven
`probe_prefix.py --through 269 --context 12`; markers are not source.
Do not run all-unit cold replay or claim runtime equivalence.
