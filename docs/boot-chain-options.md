# Boot chain for the mainline variants: options

A proposal for the open firmware decision (`SPEC.md` D2): what `bootloader/` and
`modules/sd-image.nix` would need for each of the two boot chains known to work on A733 boards.
Nothing here is implemented, and nothing was run on the board. Revisions are those of
`docs/mainline-notes.md`, re-read on 2026-11-12; re-check them before pinning.

## Where `bootloader/` stands

| File | What it does today |
|---|---|
| `sources.json` | three entries, `boot0`, `tf-a`, `u-boot`, every field null |
| `boot0.nix` | cuts boot0 out of an official image at a byte offset, as a fixed-output derivation |
| `tf-a.nix` | `buildArmTrustedFirmware` from one git source, no patches, installs `bl31.bin` |
| `u-boot.nix` | `buildUBoot` from one git source, no patches, `BL31=` set, installs `u-boot-sunxi-with-spl.bin` |
| `modules/sd-image.nix` | writes boot0, then `u-boot-sunxi-with-spl.bin`, raw, each at its `sdOffsetKiB`; first partition at 32 MiB |

Once pinned, that is "vendor boot0, then a raw `u-boot-sunxi-with-spl.bin`". Neither working
chain is built that way:

- chain 1 has no boot0 at all;
- chain 2 has boot0 load a packed `boot_package.fex`, not a raw U-Boot image.

So the layout has to change whichever chain is chosen.

## Chain 1: U-Boot SPL with the DRAM blob

```
BROM -> U-Boot SPL (calls ddr.bin) -> BL31 (TF-A from source, SRAM 0x62000) -> U-Boot -> kernel
```

Source: `DockSeed/a733-bootchain` @ `b6f6872be250` (2026-11-04), built and booted on two Radxa
Cubie A7S boards.

### Inputs

| Input | Origin | Pin | Licence |
|---|---|---|---|
| U-Boot | `radxa/u-boot`, branch `u-boot-dlan17` | `9da4b3e82d64` (v2026.07 plus 73 commits) | GPL-2.0-or-later |
| U-Boot patches | `patches/u-boot/` of the recipe | 18 patches, order in `series` | GPL-2.0-or-later |
| TF-A | upstream master | `3d425f4f4598` | BSD-3-Clause |
| TF-A patches | `patches/tf-a/` of the recipe | 17 patches, order in `series` | BSD-3-Clause |
| `awbin/a733/ddr.bin` | `radxa-pkg/u-boot-dlan17` @ `b1cec0a90c79` | sha256 `d89804f404f2eef6ef5b03d82a310ef0906c4db8ded760be221b131f5c813a05`, 232 409 bytes | none; no redistribution grant |

The recipe builds with `make ... BL31=<bl31.bin> SUNXI_LIBDRAM=<ddr.bin>`, TF-A with
`PLAT=sun60i_a733`, U-Boot with `radxa-cubie-a7s_defconfig`. It needs no boot0, no SCP image
and no packing tool: binman writes the one file.

### What would change

| File | Change |
|---|---|
| `sources.json` `boot0` | removed |
| `sources.json` `ddr` (new) | `url`, `rev`, `path` (`awbin/a733/ddr.bin`), `hash` |
| `sources.json` `tf-a` | keeps `url`, `rev`, `hash`, `platform` (`sun60i_a733`); gains `patches` (ordered list of file names) |
| `sources.json` `u-boot` | keeps `url`, `rev`, `hash`, `defconfig`, `sdOffsetKiB` (128); gains `patches` |
| `bootloader/patches/tf-a/`, `bootloader/patches/u-boot/` (new) | the vendored series, plus ours for the board |
| `bootloader/ddr.nix` (new) | fixed-output fetch of the one file, replacing `boot0.nix` |
| `tf-a.nix` | applies `patches` |
| `u-boot.nix` | applies `patches`; adds `SUNXI_LIBDRAM=${ddr}` to `extraMakeFlags` |
| `modules/sd-image.nix` | one blob at 128 KiB; the boot0 entry goes |
| `flake.nix` | `packages.boot0` goes; `uboot` is exported once `u-boot`, `tf-a` and `ddr` are pinned |

Board work, not in any tree today:

- a Zero 3W defconfig and U-Boot device tree. Minimum: microSD on `mmc0`, UART0 on PB9 and PB10.
  `docs/zero3w-wiring.md` (branch `feature/zero3w-wiring`) has the pins.
- Of the 18 U-Boot patches, 12 are named for the Cubie A7S (`sunxi-cubie-a7s-*`): each has to be
  read and either ported to the Zero 3W board files or dropped. One of them sets the PCIe
  control pins, which on the Zero 3W are PD20 to PD23.
- The watchdog: this chain starts the watchdog on `WDT_CPUS` and hands it over running. The
  kernel device tree must drive it, or the board resets about 16 s into boot.

### Offsets

| Item | Offset | Size |
|---|---|---|
| `u-boot-sunxi-with-spl.bin` | 128 KiB (sector 256) | about 1.2 MiB; FIT at 0x4a000 inside the file |
| first partition | 32 MiB (`firmwarePartitionOffset`) | the recipe asks for 16 MiB or later |

### What must stay out of the cache and the releases

- `ddr.bin` has no redistribution grant. The fetch, the SPL, `u-boot-sunxi-with-spl.bin` and any
  image that contains it must not reach Cachix or a GitHub Release.
- Today the CI `pushFilter` keeps only sources and `.img` files out of Cachix. A U-Boot output
  would be pushed. The filter needs an entry for these derivations, which is easiest if their
  names share a marker (for example a `-nopublish` suffix in `pname`).
- `release.yml` publishes an image on every push to `main`. A mainline image built on this chain
  cannot go through it as is.
- Consequence: users build the firmware themselves, as the `SPEC.md` section 5 already says.

### Unknowns

- Whether Radxa's `ddr.bin` trains the Zero 3W's LPDDR5. It reports its own version and the
  detected size; it was run on 6 GiB and 8 GiB Cubie A7S boards only. The maintainer's unit has 12 GiB.
- The blob is opaque: the recipe states that the DRAM clock and the rails it touches are known
  only by readback. The Zero 3W feeds its DRAM from DCDC6, DCDC7 and ELDO1 (see the wiring
  document); whether the blob expects the same PMIC setup is not known.
- 34 of the 35 patches of the recipe carry an `Assisted-by` trailer. Importing them unchanged
  brings the trailer into this repository. That is the maintainer's call before any import.
- The recipe has one author and its last commit is of 2026-11-04. It is tested on one board model.

## Chain 2: vendor boot0 loading mainline U-Boot

```
BROM -> boot0 (vendor, trains DRAM) -> boot_package.fex -> U-Boot SPL -> BL31 -> U-Boot -> kernel
```

Source: `dlan17/a733`, `boot-sdcard.md` @ `0feb1a77f9b1`, written for the Radxa Cubie A7A.

### Inputs

| Input | Origin | Pin | Licence |
|---|---|---|---|
| boot0 | `orangepi-build`, `boot0_sdcard_orangepizero3w.fex`, already in `vendor/blobs/` | hash in `vendor/sources.json`; 245 760 bytes | none |
| U-Boot | `dlan17/u-boot`, branch `allwinner/A733/boot-2026.04` | `c85cef956235` | GPL-2.0-or-later |
| TF-A | `dlan17/trusted-firmware-a`, branch `A733` | `f4c0b0dba78a`, `PLAT=sun60i_a733` | BSD-3-Clause |
| header | first 1600 bytes of the vendor U-Boot binary | from `vendor/u-boot.nix` | GPL-2.0-or-later (built from source) |
| `dragonsecboot` | `orangepi-build`, already in `vendor/blobs/` | hash in `vendor/sources.json` | none; static x86-64 binary |

The document names branch `allwinner/A733/boot`; `docs/mainline-notes.md` also lists
`allwinner/A733/boot-2026.04` and `allwinner/A733/next`. Which one to pin is part of the port.

### Packing step

1. Take the first 1600 bytes of the vendor U-Boot binary as header.
2. Write `0x48000000` (little endian, 4 bytes) at offset `0x2c` of the header: the load address.
   The vendor value is `0x4a000000`, where mainline U-Boot itself runs.
3. Concatenate the header and `u-boot-sunxi-with-spl.bin`.
4. Pack with `dragonsecboot -pack` and a two-item `boot_package.cfg`: `u-boot` = the file of
   step 3, `dtb` = `u-boot-sunxi-with-spl.fit.fit`. The `dtb` item is loaded 2 MiB above the
   `u-boot` item, at `0x48200000`.

The vendor package of this repository has three items (`u-boot`, `monitor`, `scp`); this one has
no vendor monitor and no SCP firmware.

### What would change

| File | Change |
|---|---|
| `sources.json` `boot0` | replaced by a reference to the file already pinned in `vendor/sources.json`; `sdOffsetKiB` 8 or 128 |
| `sources.json` `tf-a` | `url`, `rev`, `hash`, `platform`; `patches` for the board, if any |
| `sources.json` `u-boot` | `url`, `rev`, `hash`, `defconfig`; `patches` for the board; `sdOffsetKiB` goes |
| `sources.json` `bootPackage` (new) | `sdOffsetKiB` 16400, `headerBytes` 1600, `loadAddress` `0x48000000` |
| `boot0.nix` | no longer cuts an image: takes the file from `vendor/files.nix` |
| `u-boot.nix` | also installs `u-boot-sunxi-with-spl.fit.fit` |
| `bootloader/boot-package.nix` (new) | the packing step above; modelled on `vendor/boot-package.nix` |
| `modules/sd-image.nix` | two blobs: boot0, then `boot_package.fex` at 16 400 KiB |
| `flake.nix` | exports the package once all three are pinned |

Board work: a Zero 3W defconfig and U-Boot device tree, as for chain 1.

### Offsets

| Item | Offset | Size |
|---|---|---|
| boot0 | 8 KiB (as the vendor variant writes it) or 128 KiB (as the document does) | 240 KiB |
| `boot_package.fex` | 16 400 KiB (sector 32800) | a few MiB; 16 368 KiB free before the first partition |
| first partition | 32 MiB | |

### Build constraints

- `dragonsecboot` is an x86-64 binary: on the ARM runners it runs under qemu-user, as the vendor
  package already does.
- The header comes from the vendor U-Boot, which only builds on x86-64 (`vendor/u-boot.nix`).
  The mainline variant would depend on that derivation. The dependency can be cut by pinning the
  1600 bytes as a fixed-output slice, at the price of one more blob-like input.

### What must stay out of the cache and the releases

- boot0 and `dragonsecboot` have no licence text. Both are already in the tree and boot0 is in
  the released vendor image. `SPEC.md` section 5 says no released artifact contains a blob. The
  two do not agree today; chain 2 would extend the current practice to the mainline variants.

### Unknowns

- Whether the Zero 3W boot0 accepts a package made this way. The document was written for
  Radxa's boot0 on the Cubie A7A.
- Whether the first 1600 bytes of the Orange Pi vendor U-Boot have the layout the document
  assumes (load address at `0x2c`). The Orange Pi tree is U-Boot 2018.05; the document's header
  comes from Radxa's vendor build.
- Whether boot0 hands over a state mainline U-Boot expects (the vendor flow passes through the
  vendor monitor and SCP, which this package leaves out).

## Side by side

| | Chain 1 | Chain 2 |
|---|---|---|
| DRAM init | Radxa `ddr.bin`, untested on this board | Orange Pi boot0, known to train this board |
| Binaries in the result | `ddr.bin` | boot0 |
| Binaries needed to build | none | `dragonsecboot` (x86-64) |
| Files on the card | one, at 128 KiB | two, at 8 or 128 KiB and at 16 400 KiB |
| Extra build steps | none | header, patch of one word, packing |
| Patches to vendor | 17 TF-A, 18 U-Boot (provenance to decide) | none known beyond the board port |
| Shown to boot on | Cubie A7S (two units) | Cubie A7A, per its author |
| Publishable result | no | same question as the vendor image today |
| Matches `SPEC.md` | the target chain | the fallback |

## Proposal

1. Decide on FEL, not on paper. FEL loads an SPL over USB without touching the card, so the one
   question that separates the chains, whether `ddr.bin` trains this board, can be answered
   before `bootloader/` is restructured. This needs the serial console and the board port
   (defconfig and device tree), which both chains need anyway. Loading this SPL over FEL on an
   A733 is described by `dlan17/a733` (`boot-fel.md`) and listed in the recipe's boot targets; it
   has not been tried here.
2. If `ddr.bin` trains the board and reports the full 12 GiB: chain 1. It is the simpler layout,
   needs no vendor tool, and is what `SPEC.md` names as the target.
3. If it does not: chain 2, whose DRAM init is known good on this board.
4. In both cases `boot0.nix` in its present form (cutting boot0 out of an official image) has no
   use and can go.

## Decisions asked of the maintainer

| Decision | Why it is needed |
|---|---|
| Chain 1 or chain 2, or "decide after the FEL test" | sets the shape of `sources.json` and `sd-image.nix` |
| For chain 1: import the recipe's patches as they are, re-author them, or write the board port on Radxa's tree alone | 34 of 35 carry an `Assisted-by` trailer |
| For chain 1: how firmware and images are kept out of Cachix and Releases | the current filter would push them |
| For chain 2: whether a mainline image with boot0 inside may be released | the vendor image already is; the spec says otherwise |
| Which U-Boot tree the Zero 3W port targets | Radxa's branch (chain 1) and dlan17's branches (chain 2) are different trees |
