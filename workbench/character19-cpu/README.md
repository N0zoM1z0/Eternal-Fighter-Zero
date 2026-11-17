# Character19::Slot05 CPU decision reconstruction

Target: `Character19::Slot05`, native entry `0x00678C30`, original extent
17,176 bytes. `Character19Cpu-decomp.cpp` is a complete ordinary C++
reconstruction of the full decision owner, including the large state/command
branches and the neutral-input fallback. It contains no inline assembly,
synthetic padding, or placeholder function bodies.

The current VC7.1 `/Od /G6 /MT /Gy` candidate is 17,166 bytes (10 bytes
shorter than native) with the original `0xCC` stack frame and matching entry
prologue. It is a strong work-in-progress, **not Exact**. The large guard/AI
gate is expressed as a natural early command return, with signed-byte tests,
exact opponent-state boundaries, and unsigned RNG promotions. Targeted
instruction alignment reports 3,723 of 4,450 candidate instructions aligned
with native order/semantics. The native `FUCOMPP` sequences confirm that the
observed `positionY == 0.0` branches are true equality tests (including their
unordered handling), so those source predicates remain equality checks.
Remaining differences span float comparison lowering, RNG temporaries, and
later state branches.
Rebuild only this function with:

```sh
scripts/repo-python workbench/character19-cpu/check-decomp.py
```

The workbench `CharacterViews.h` is byte-identical to `src/CharacterViews.h`;
its two named cooldown fields preserve the original object offsets `+0x314C`
and `+0x3150`.
