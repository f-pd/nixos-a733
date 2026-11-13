# Analysis material for the vendor DRAM init

Working data behind `docs/dram-init-spec.md`: what was produced while analysing Orange Pi's
`boot0` and Radxa's `ddr.bin`. It is kept here so that the analysis can be resumed from any
machine.

**If you are implementing or changing `bootloader/dram/` or the SPL glue, do not read this
directory.** That code was written from the specification alone, by a session that never saw
this material, and its history shows it (the library was merged before this directory
existed). Reading the decompiler output and then touching that code ends that separation.
`docs/dram-init/HANDOFF.md` has the rules.

## Contents

| Path | What |
|---|---|
| `dec/boot0/`, `dec/ddr/` | Ghidra 12.2 decompiler output, one file per function, as written by `rea decompile-all` on the raw AArch32 images (load addresses `0x47000` and `0x90000`), with the journals |
| `notes/boot0.all.c`, `notes/ddr.all.c` | the same, merged into one file each, with literal-pool values and strings annotated (`notes/strip.py`) |
| `notes/ddr.bin.38040.dts` | the device tree appended to `ddr.bin` |
| `emu/emu.py` | runs boot0's DRAM routine under Unicorn against a register model and logs every access |
| `emu/emu2.py` | the same from boot0's entry point, with a PMIC register model and stop points |
| `emu/ops.py`, `emu/sens.py`, `emu/summ.py` | turn traces into the operation scripts, the parameter sweep, and a summary |
| `emu/early.txt` | boot0's register activity before the DRAM routine |
| `spl/emu64.py`, `spl/cmp.py` | run the SPL built by CI through its DRAM entry and compare it with a script |
| `fetch-blobs.sh` | puts the two binaries into `blobs/` |

Not here, on purpose: the binaries themselves (`ddr.bin` has no redistribution grant; boot0 is
under `vendor/blobs/`), and the raw traces, which contain the PHY firmware words. Both come
back with `fetch-blobs.sh` and the scripts.

## Setting up again

```sh
analysis/fetch-blobs.sh
cd analysis && uv venv .venv && uv pip install --python .venv/bin/python unicorn
.venv/bin/python emu/emu.py --para ext:5 --out emu/A.ext:5.jsonl     # 12 GiB block
```

The scripts use paths relative to `analysis/` (`blobs/`, `dec/`, `emu/`). Decompiling again
needs Ghidra 12.1 or later and REA (`rea-agents`):
`rea decompile-all blobs/boot0.bin --output dec/boot0 --target-format raw-binary --architecture arm --entry-point 0x47000 --provider ghidra`.

The public vendor kernel sources used for the oscillator question are
`bsp/drivers/clk/sunxi-ng/ccu-sun60iw2.c` and `ccu-sun60iw2-rtc.c` in
`orangepi-xunlong/linux-orangepi` at the revision pinned in `vendor/sources.json`.
