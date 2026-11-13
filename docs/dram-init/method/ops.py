#!/usr/bin/env python3
"""Turn a pair of traces (normal, complemented reads) into a normalised operation script."""
import json, sys, bisect, glob, os, hashlib
cfg = sys.argv[1]
A = [json.loads(l) for l in open(f"emu/A.{cfg}.jsonl")]
B = [json.loads(l) for l in open(f"emu/B.{cfg}.jsonl")]
blob = open("blobs/boot0.bin", "rb").read()
PAY0, PAY1 = 0x196b0, 0x3ae98
starts = sorted(int(os.path.basename(p)[:-2], 16) for p in glob.glob("dec/boot0/functions/*.c"))
def fn(pc):
    i = bisect.bisect_right(starts, pc) - 1
    return starts[i]
PHY = 0x0A900000
def blk(a):
    if PHY <= a < 0x0AB00000: return "PHY", (a - PHY) >> 1
    if 0x0A100000 <= a < 0x0A500000: return "CTL0", a - 0x0A100000
    if 0x0A500000 <= a < 0x0A900000: return "CTL1", a - 0x0A500000
    if 0x0A020000 <= a < 0x0A100000: return "GLUE", a - 0x0A020000
    if 0x02002000 <= a < 0x02003000: return "CCU", a - 0x02002000
    if 0x02020000 <= a < 0x02030000: return "SYS2", a - 0x02020000
    if 0x03000000 <= a < 0x03001000: return "SYSCFG", a - 0x03000000
    if 0x07010000 <= a < 0x07011000: return "PRCM", a - 0x07010000
    return "ABS", a
Bw = [e for e in B if e["t"] == "w"]
# last read per address before each write, in B
def last_reads(tr, allow_forced=False):
    out = []; last = {}
    lastany = None
    for e in tr:
        if e["t"] == "r" and (allow_forced or not e.get("forced")) and e.get("polls", 0) == 0:
            last[e["a"]] = e["v"]; lastany = (e["a"], e["v"])
        elif e["t"] == "w":
            out.append((last.get(e["a"]), lastany))
    return out
LA, LB = last_reads(A), last_reads(B, True)
ops = []
wi = 0
pend_read = None
i = 0
n = len(A)
def is_mem(a): return PHY + (0x50000 << 1) <= a < PHY + (0x60000 << 1)
while i < n:
    e = A[i]; t = e["t"]
    if t == "print": ops.append(("MSG", "", "", e["s"].strip(), "", ""))
    elif t == "delay": ops.append(("DELAY", "", "", str(e["us"]), "", ""))
    elif t == "pmic": ops.append(("PMIC", e["rail"], "", str(e["mv"]), "", ""))
    elif t == "dramw": pass
    elif t == "phase":
        ar = "r0=%x r1=%x r2=%x r3=%x" % (e["r0"], e["r1"], e["r2"], e["r3"]) if e["name"] in ("mr_write", "mr_read", "phy_pstate_cfg", "pstate_clock", "phy_pstate_misc", "phy_run_fw", "phy_post_train", "ctl_static", "ctl_pre", "ctl_lp5_post", "ctl_timing", "ctl_addrmap", "dfs_setup") else ""
        ops.append(("PHASE", e["name"], "", ar, "", ""))
    elif t == "end": ops.append(("END", "", "", "ret=%d" % e["r0"], "", ""))
    elif t == "r":
        b, off = blk(e["a"])
        if e.get("forced") or e.get("polls", 0) > 0:
            if not (ops and ops[-1][0] == "WAIT" and ops[-1][1] == b and ops[-1][2] == "%x" % off):
                ops.append(["WAIT", b, "%x" % off, "", "", ""])
            ops[-1][3] = "exit_on=%x" % e["v"]
        else:
            # plain read: keep only if the next event is not a write to the same address
            nx = A[i + 1] if i + 1 < n else None
            if not (nx and nx["t"] == "w" and nx["a"] == e["a"]):
                ops.append(("READ", b, "%x" % off, "", "", ""))
    elif t == "w":
        j = i; run = []; a0 = e["a"]
        if PHY <= a0 < 0x0AB00000 and e["s"] == 2:
            while j < n and A[j]["t"] == "w" and A[j]["a"] == a0 + 2 * len(run):
                run.append(A[j]["v"]); j += 1
        if is_mem(e["a"]) or len(run) >= 16:
            data = b"".join(v.to_bytes(2, "little") for v in run)
            k = 0; pa = (a0 - PHY) >> 1
            while k < len(data):
                if data[k:k + 2] == b"\0\0":
                    m = k
                    while m < len(data) and data[m:m + 2] == b"\0\0": m += 2
                    if m - k >= 16:
                        ops.append(("ZERO16", "PHY", "%x" % (pa + k // 2), str((m - k) // 2), "", "")); k = m; continue
                best_off, best_m = -1, 0
                if k + 16 <= len(data):
                    off = blob.find(data[k:k + 16], PAY0, PAY1)
                    while off >= 0:
                        m = 0
                        while k + m < len(data) and off + m < PAY1 and data[k + m:k + m + 2] == blob[off + m:off + m + 2]: m += 2
                        if m > best_m: best_off, best_m = off, m
                        off = blob.find(data[k:k + 16], off + 1, PAY1)
                thr = 16 if is_mem(e["a"]) else 32
                if best_m >= thr:
                    off, m = best_off, best_m
                    ops.append(("LOAD16", "PHY", "%x" % (pa + k // 2), str(m // 2), "payload+0x%x" % (off - PAY0), "")); k += m
                else:
                    ops.append(("W16", "PHY", "%x" % (pa + k // 2), "%x" % int.from_bytes(data[k:k + 2], "little"), "", "")); k += 2
            wi += len(run); i = j; continue
        b, off = blk(e["a"]); vb = Bw[wi]["v"]; va = e["v"]
        op = "W16" if e["s"] == 2 else "W32"
        if va == vb:
            ops.append((op, b, "%x" % off, "%x" % va, "", ""))
        else:
            pa_, pb_ = LA[wi][0], LB[wi][0]
            full = (1 << (8 * e["s"])) - 1
            if pa_ is None or pb_ is None or (pa_ ^ pb_) != full:
                src = LA[wi][1]
                sb, so = blk(src[0]) if src else ("?", 0)
                ops.append(("RMW" + op[1:], b, "%x" % off, "set=?", "clear=? written=%x derived" % va, ""))
            else:
                keep = (va ^ vb) & full
                st = va & ~keep & full
                ok = (va & keep) == (pa_ & keep) and (vb & keep) == (pb_ & keep)
                ops.append(("RMW" + op[1:], b, "%x" % off, "set=%x" % st, "clear=%x written=%x" % ((~keep & full) & ~st, va) + ("" if ok else " derived"), ""))
        wi += 1
    i += 1
with open(f"emu/ops.{cfg}.tsv", "w") as f:
    f.write("op\tblock\taddr\tvalue\textra\n")
    for o in ops: f.write("\t".join(o[:5]) + "\n")
import collections
print(cfg, len(ops), collections.Counter(o[0] for o in ops))
