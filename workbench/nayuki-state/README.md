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

Verified code [0x00451850,0x0046078A): **61,242 / 62,693 native bytes**,
**16,767 x86 instructions**, SHA-256
aad384707a503f97a57588b45583442a84084b41d0389bddf9a3bcda138f11fe.
The original default plus **136/137 live case bodies** now have
selected native-bound natural C++ implementations, including
formerly absent cases263–281 and super cases300–305.

**State305 (932 bytes)** recovers the highest-cost steerable aerial
super: at frame3/tick0 it spends 3000 meter, applies hitstun120 and
tint(0xB0,3), emits global type0x46/palette0x40 at Y-40 and requests
context sound0x25. From frame4 it invokes accepted
`Context::SetSceneTimer(15)` (original target 0x4080C0). Frames6–7
zero motion and select vertical/horizontal ±0.8 speed from input;
late gravity/landing skip to frame12, frame6 dual effects0x19D/0x19E,
frame8 repeats frame6 for 20 cycles before gravity0.015, and
frame12 loops to10. Exit is state7 via FaceOpponent/ResetPose.
All original IEEE-754 and call relocations were audited.

    scripts/repo-python workbench/nayuki-state/check_prefix.py

Pinned VC7.1 `/Od /G6 /MT /Gy /W3` verifies **16,767 original
instruction offsets/widths/normalized forms** except the partial
stack allocation (candidate 0x288 versus original 0x2B4), **1,564
internal branches**, **234 outbound**, **1,256 original-bound
nonlocal COFF call/float references**, 2 local switch references,
and **136 original case entry points**. Selected prefix is NOT Exact.

## Last native case and owner closure

Only original **state306** is still an inherited unverified source
body, starting at **0x0046078A** with **1,451 original code bytes**
to the common-return boundary 0x00460D35. Complete original 0x2B4
stack, adjacent switch DATA, remaining relocations and common return
remain unverified. Reconstruct 306 and prove owner closure with
local target checks, not all-unit cold replay.
