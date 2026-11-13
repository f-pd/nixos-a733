# Kernel patches

Patches are applied on top of the latest stable kernel.org release, in the order
they appear in `index.json`, in two layers:

| Layer | Directory | Scope | When it does not apply |
|-------|-----------|-------|------------------------|
| base | `base/` | boot, clocks, pinctrl, MMC, PCIe, USB, networking, security | the build fails and CI opens an issue |
| optional | `optional/` | display, GPU, NPU, audio and the rest | the patch is skipped, the build goes on and CI opens an issue |

Every patch needs an entry in `index.json`:

```json
{
  "patches": [
    {
      "file": "0001-clk-sunxi-ng-add-a733-ccu.patch",
      "layer": "base",
      "origin": "https://lore.kernel.org/...",
      "description": "A733 clock controller"
    }
  ]
}
```

- `file`: name of the file inside the layer directory.
- `layer`: `base` or `optional`.
- `origin`: where the patch comes from (mailing list thread, vendor tree commit).
- `description`: one line on what it does.

A patch file without an entry is ignored, and an entry without a file fails
evaluation. Patches apply with `patch -p1` from the root of the kernel tree.

## Where the patches come from

The numbered files are a vendored copy of `DockSeed/a7s-linux-mainline`, written by
`import-stack.py` together with their index entries (which carry a `stack` field); do not
edit them by hand. The `zero3w-*` files are ours and come last in the base layer.
`docs/kernel-zero3w.md` has the details, the split into layers and how to refresh the copy.
