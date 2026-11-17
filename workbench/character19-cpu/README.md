# Character19::Slot05 CPU decision reconstruction

Target: `Character19::Slot05`, native entry `0x00678C30`, original extent
17,176 bytes. `Character19Cpu-decomp.cpp` is a complete ordinary C++
reconstruction of the full decision owner, including the large state/command
branches and the neutral-input fallback. It contains no inline assembly,
synthetic padding, or placeholder function bodies.

The current VC7.1 `/Od /G6 /MT /Gy` candidate is 17,173 bytes (3 bytes
shorter than native) with the original `0xCC` stack frame and matching entry
prologue. It is a strong work-in-progress, **not Exact**. The large guard/AI
gate is expressed as a natural early command return, with signed-byte tests,
exact opponent-state boundaries, unsigned RNG promotions, and signed
air-action lock tests normalized to native `TEST/JG` boundaries, and
velocity-sign tests use the operand order emitted by the native x87 compare. Targeted
instruction alignment reports 4,192 of 4,447 candidate instructions aligned
with native order/semantics. The native x87 unordered-compare paths are preserved with explicit negated
relational tests where the native branches treat unordered values as true;
`positionY == 0.0` remains a true equality test. The state-0xc9 lock fallback
uses `!(lockFrames > 0x3c)` to retain the native `cmp 0x3c` / `jg` branch.
The ground-range random direction now uses an explicit integer-valued ternary,
recovering the native zeroed-register plus `setl` boolean materialization. The
final AI gate now uses natural early-return guards for both facing-command
fallthroughs; their byte-to-command conversions are emitted at the native
branch sites instead of a synthesized tail block. The state-0x11 aerial decision tree now has explicit native-order short-circuit
branches and early exits, with unordered-aware x87 relational expressions and
exact signed/unsigned byte/word bounds. All 4,447 candidate instructions now align in native order and semantics after
branch-target normalization. The only remaining byte-size discrepancy is one
three-byte near-versus-short return jump in the state-0x20 handler; all 298
COFF relocations and the original stack frame remain intact. The large AI gate now preserves native unsigned
state-code bounds and unordered-aware floating-point range predicates, including the two AI
probability-gate comparisons against RNG values. The early CPU-state gates
now use the native `0x31`/`0x96` comparison boundaries directly.
Rebuild only this function with:

```sh
scripts/repo-python workbench/character19-cpu/check-decomp.py
```

The workbench `CharacterViews.h` is byte-identical to `src/CharacterViews.h`;
its two named cooldown fields preserve the original object offsets `+0x314C`
and `+0x3150`.
