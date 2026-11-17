# Character19::Slot05 CPU decision reconstruction

Target: `Character19::Slot05`, native entry `0x00678C30`, original extent
17,176 bytes. `Character19Cpu-decomp.cpp` is a complete ordinary C++
reconstruction of the full decision owner, including the large state/command
branches and the neutral-input fallback. It contains no inline assembly,
synthetic padding, or placeholder function bodies.

The current VC7.1 `/Od /G6 /MT /Gy` candidate is 17,180 bytes (4 bytes over
native) with the original `0xCC` stack frame, matching `this` spill and
prologue. It is a strong work-in-progress, **not Exact**. The remaining
instruction differences are concentrated in floating comparison operand
order, a few signed/unsigned promotions, and the final state-range branch.

Rebuild only this function with:

```sh
scripts/repo-python workbench/character19-cpu/check-decomp.py
```

The workbench `CharacterViews.h` is byte-identical to `src/CharacterViews.h`;
its two named cooldown fields preserve the original object offsets `+0x314C`
and `+0x3150`.
