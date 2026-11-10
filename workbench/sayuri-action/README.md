# Sayuri Character09::Slot04 — in-progress command/action boss

This is a real **partial natural C++ reconstruction**, not an Exact owner.
The original Character09 vtable at 0x00788138 has Slot04 at
0x00788148 pointing to the 11,119-byte original function 0x00446780.
The complete canonical code extent is [0x00446780,0x004492EF),
SHA-256 fd248e424f2ebcdddb59462a3101f653e9931e4053d53eb2af9a067e2c0bb286.
All 2,815 original instructions decode contiguously and all 460
direct jumps stay on original instruction starts inside the function.
The shared return is at 0x004492EB. One CC byte separates the function
from the next prologue at 0x004492F0.

Natural C++ candidate Character09Input.cpp covers
[0x00446780,0x0044834C): **7,116 original bytes /
1,783 instructions**, SHA-256
b801b2fe234dcc8c4e04cb3558ef60898e4e808b01b1ee5d25eb125c1ba7e643.

It covers input-buffer decay, the Sayuri 150–155 opponent-state
gate, complete early special-command priorities through 0x0A–0x0C,
and both mirrored air-dash reactions for commands 0 and 1.
These reactions check the opponent/own X difference, command
direction and equal-position facing, meter/action permissions,
and initiate action 0xA5 or 0xA6. The original negative
direction test requires multiplication by -1 (which VC7.1
emits as IMUL), not unary negation (NEG).

One significant semantic correction was made when the prefix
passed 0x00447FC7. The original field015c >= 2 near JNL
at 0x00446963 skips the entire command priority chain.
Earlier partial C++ mistakenly closed the field015c < 2
guard immediately after action 0x12C, incorrectly permitting
later commands. That target was outside the old reviewed
prefix; the expanded checker now verifies it as an internal
edge and rejects the wrong scope.

Rebuild/review only this owner:

    scripts/repo-python workbench/sayuri-action/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits a
**7,115-byte draft / 1,785 instructions** including
the three-instruction temporary return, with 63 relocations.
Of 1,782 aligned, comparable original body instructions,
1,781 agree after normalizing direct call/jump and original
FP addresses; the remaining source-frame allocation
(sub esp,0xC vs original 0x14) is incomplete.
The original prefix ends with an unresolved jump to the
complete owner's shared exit. **261 internal branch targets
and all 63 original-bound relocations agree**, including
original double bit patterns. This is **not Exact**.

Continue at 0x0044834C (remaining grounded/movement and
defensive action selection). The remaining **4,003 bytes**,
final stack lifetime and whole-owner relocation closure
must be reconstructed before strict acceptance. No all-unit
cold replay was run.
