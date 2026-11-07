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
