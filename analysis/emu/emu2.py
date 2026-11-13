#!/usr/bin/env python3
"""Run boot0's DRAM init under Unicorn against a register model; log every MMIO access."""
import sys, struct, json, collections, argparse
from unicorn import *
from unicorn.arm_const import *

ap = argparse.ArgumentParser()
ap.add_argument("--blob", default="blobs/boot0.bin")
ap.add_argument("--base", type=lambda x: int(x, 0), default=0x47000)
ap.add_argument("--entry", type=lambda x: int(x, 0), default=0x49bdc)
ap.add_argument("--para", default=None, help="comma list idx=val overrides, or 'ext:N' to use DRAM.ext block N")
ap.add_argument("--out", default="emu/trace.jsonl")
ap.add_argument("--maxinsn", type=int, default=400_000_000)
ap.add_argument("--chipflag", type=int, default=0)
ap.add_argument("--invert-from", default=None)
ap.add_argument("--arm", action="store_true")
ap.add_argument("--stop", default="")
ap.add_argument("--nostub", default="")
ap.add_argument("--time", default="")
a = ap.parse_args()

img = bytearray(open(a.blob, "rb").read())
PARA = 0x38
if a.para:
    for item in a.para.split(","):
        if item.startswith("ext:"):
            n = int(item[4:]); src = 0x374 + (n - 1) * 0x80
            img[PARA:PARA + 0x80] = img[src:src + 0x80]
        else:
            k, v = item.split("="); struct.pack_into("<I", img, PARA + 4 * int(k, 0), int(v, 0))

uc = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
RAM0, RAMSZ = 0x00000000, 0x00200000
uc.mem_map(RAM0, RAMSZ)
uc.mem_write(a.base, bytes(img))
uc.mem_write(0x83620, bytes([a.chipflag]))
STACK = 0x1f0000
STOP = 0x1ff000
uc.mem_write(STOP, b"\xfe\xe7" * 8)  # b .
mapped = set()
def ensure(addr):
    pg = addr & ~0xfff
    if pg not in mapped:
        try: uc.mem_map(pg, 0x1000)
        except UcError: pass
        mapped.add(pg)

out = open(a.out, "w")
seq = 0
def log(**kw):
    global seq
    kw["n"] = seq; seq += 1
    out.write(json.dumps(kw) + "\n")

def rd(addr, size):
    return int.from_bytes(uc.mem_read(addr, size), "little")
def cstr(addr):
    s = b""
    while True:
        c = uc.mem_read(addr, 1)[0]
        if c == 0 or len(s) > 300: break
        s += bytes([c]); addr += 1
    return s.decode("latin1")

def is_mmio(addr): return 0x01000000 <= addr < 0x10000000
def is_dram(addr): return addr >= 0x40000000

poll = {"key": None, "count": 0, "cand": 0}
INV = None
if a.invert_from:
    INV = collections.defaultdict(list)
    for l in open(a.invert_from):
        e = json.loads(l)
        if e["t"] == "r" and not e.get("forced") and e.get("polls") == 0 and e["a"] not in (0x0aaa0064, 0x0aaa0068):
            INV[(e["pc"], e["a"])].append(e["v"])
    INVI = collections.Counter()
restore = []
CANDS = [0] + [1 << k for k in range(32)] + [0xffffffff] + [0xffffffff ^ (1 << k) for k in range(32)]
FIXED = {0x0aaa0064: 7, 0x0aaa0068: 0}

def do_restore():
    while restore:
        ad, sz, val = restore.pop()
        uc.mem_write(ad, val.to_bytes(sz, "little"))

def on_unmapped(uc_, access, addr, size, value, ud):
    ensure(addr); ensure(addr + size - 1)
    return True

def on_mem(uc_, access, addr, size, value, ud):
    pc = uc.reg_read(UC_ARM_REG_PC)
    do_restore()
    if not is_mmio(addr):
        if is_dram(addr) and access == UC_MEM_WRITE and (addr & 0xfff) == 0:
            log(t="dramw", pc=pc, a=addr, v=value & 0xffffffff)
        return
    if access == UC_MEM_WRITE:
        poll["key"] = None
        log(t="w", pc=pc, a=addr, s=size, v=value & ((1 << (8 * size)) - 1))
    else:
        key = (pc, addr)
        cur = rd(addr, size)
        ret = cur
        if addr in FIXED:
            ret = FIXED[addr]
        if poll["key"] == key:
            poll["count"] += 1
            if poll["count"] > 40:
                c = CANDS[((poll["count"] - 41) // 3) % len(CANDS)]
                ret = c & ((1 << (8 * size)) - 1)
                if (poll["count"] - 41) // 3 >= len(CANDS) * 2:
                    log(t="stuck", pc=pc, a=addr); uc.emu_stop()
        else:
            poll["key"] = key; poll["count"] = 0
            if INV is not None and addr not in FIXED:
                lst = INV.get(key); i = INVI[key]; INVI[key] += 1
                if lst and i < len(lst):
                    ret = (~lst[i]) & ((1 << (8 * size)) - 1)
        if ret != cur:
            restore.append((addr, size, cur))
            uc.mem_write(addr, ret.to_bytes(size, "little"))
        if poll["count"] in (0, 41) or ret != cur:
            poll["last"] = ret
            log(t="r", pc=pc, a=addr, s=size, v=ret, forced=(ret != cur), polls=poll["count"])

def fmt(s, args):
    res = ""; i = 0; ai = 0
    while i < len(s):
        if s[i] == "%" and i + 1 < len(s):
            j = i + 1
            while j < len(s) and s[j] in "0123456789l.-": j += 1
            c = s[j] if j < len(s) else ""
            v = args[ai] if ai < len(args) else 0
            if c in "dxXuc s".replace(" ", ""):
                ai += 1
                res += {"d": lambda: str(v if v < 2**31 else v - 2**32), "u": lambda: str(v), "x": lambda: "%x" % v,
                        "X": lambda: "%X" % v, "c": lambda: chr(v & 0xff), "s": lambda: cstr(v)}[c]()
            else: res += s[i:j + 1]
            i = j + 1
        else:
            res += s[i]; i += 1
    return res

def ret_from(r0=None):
    if r0 is not None: uc.reg_write(UC_ARM_REG_R0, r0 & 0xffffffff)
    lr = uc.reg_read(UC_ARM_REG_LR)
    uc.reg_write(UC_ARM_REG_PC, lr)

def h_printf(pc):
    r = [uc.reg_read(x) for x in (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3)]
    sp = uc.reg_read(UC_ARM_REG_SP)
    args = r[1:] + [rd(sp + 4 * i, 4) for i in range(6)]
    log(t="print", s=fmt(cstr(r[0]), args)); ret_from(0)
def h_delay(pc):
    log(t="delay", us=uc.reg_read(UC_ARM_REG_R0), lr=uc.reg_read(UC_ARM_REG_LR)); ret_from()
def h_pmic(pc):
    log(t="pmic", rail=cstr(uc.reg_read(UC_ARM_REG_R0)), mv=uc.reg_read(UC_ARM_REG_R1), on=uc.reg_read(UC_ARM_REG_R2)); ret_from(0)

PHASES = {0x4b618: "power", 0x57a4c: "clocks", 0x57b7c: "init_core", 0x57238: "ctl_pre", 0x570d4: "ctl_static",
  0x56dd8: "ctl_addrmap", 0x562dc: "ctl_timing", 0x55990: "phy_train_all", 0x55654: "phy_common", 0x4f57c: "phy_load_imem",
  0x4f58c: "phy_pstate_cfg", 0x4f500: "pstate_clock", 0x4f4f0: "phy_pstate_misc", 0x4bbb8: "phy_swap_ca", 0x4b97c: "phy_swap_dq",
  0x4f47c: "phy_run_fw", 0x4bca8: "phy_post_train", 0x4f46c: "phy_final", 0x57310: "ctl_lp5_post", 0x4b7ec: "dfi_handover",
  0x561a0: "remap", 0x581b4: "dfs_setup", 0x576e4: "readback", 0x4b74c: "size", 0x4b4cc: "memtest", 0x4b554: "mr_write",
  0x4b5ac: "mr_read", 0x57e44: "autoscan", 0x57ea4: "glue_tbl_a", 0x58048: "glue_tbl_b", 0x4b7a0: "pll", 0x49a9c:"m_49a9c",0x4a4ec:"m_uart",0x48fac:"m_48fac",0x4a990:"m_4a990",0x4aa08:"m_4aa08",0x49a5c:"m_getc",0x49aa8:"m_49aa8",0x49bdc:"init_dram",0x48dfc:"m_48dfc",0x49d14:"m_malloc",0x5dc30:"m_loadpkg",0x4a5cc:"m_gpio",0x5d744:"pmu_probe",0x4b2e8:"dram_ext",0x4b1bc:"adc_read"}
def h_phase(pc):
    log(t="phase", name=PHASES[pc], r0=uc.reg_read(UC_ARM_REG_R0), r1=uc.reg_read(UC_ARM_REG_R1), r2=uc.reg_read(UC_ARM_REG_R2), r3=uc.reg_read(UC_ARM_REG_R3))
HOOKS = {0x4993c: h_printf, 0x498e4: h_printf, 0x48d80: h_delay, 0x4b4a4: h_delay, 0x5d72c: h_pmic}
calls = collections.Counter()
def on_code(uc_, addr, size, ud):
    h = HOOKS.get(addr)
    if h: h(addr)
    elif addr in PHASES: h_phase(addr)
PMREG = {0x0e: 0x03}
def h_i2c_init(pc): log(t="i2c_init"); ret_from(0)
def h_i2c_rd(pc):
    ad, reg, ptr = uc.reg_read(UC_ARM_REG_R0), uc.reg_read(UC_ARM_REG_R1) & 0xff, uc.reg_read(UC_ARM_REG_R2)
    v = PMREG.get(reg, 0); uc.mem_write(ptr, bytes([v])); log(t="i2c_r", dev=ad, reg=reg, v=v); ret_from(0)
def h_i2c_wr(pc):
    ad, reg, v = uc.reg_read(UC_ARM_REG_R0), uc.reg_read(UC_ARM_REG_R1) & 0xff, uc.reg_read(UC_ARM_REG_R2) & 0xff
    PMREG[reg] = v; log(t="i2c_w", dev=ad, reg=reg, v=v); ret_from(0)
HOOKS.update({0x4af20: h_i2c_init, 0x4af2a: h_i2c_rd, 0x4af3e: h_i2c_wr})
def h_ret0(pc): log(t="skip", pc=pc); ret_from(0)
HOOKS[0x4b290] = h_ret0
HOOKS[0x49ab4] = h_ret0
STOPS = [int(x, 0) for x in a.stop.split(",") if x]
for x in a.nostub.split(","):
    if x: HOOKS.pop(int(x, 0), None)
TICK = [0]
def h_time(pc):
    TICK[0] += 5; ret_from(TICK[0])
for x in a.time.split(","):
    if x: HOOKS[int(x, 0)] = h_time
def h_stop(pc):
    log(t="stop", pc=pc); uc.emu_stop()
for x in STOPS: HOOKS[x] = h_stop
for ad in list(HOOKS) + list(PHASES):
    uc.hook_add(UC_HOOK_CODE, on_code, begin=ad, end=ad + 1)
uc.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, on_mem)
uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED | UC_HOOK_MEM_FETCH_UNMAPPED, on_unmapped)

import os
for it in os.environ.get("EMU_PRESET","").split(","):
    if it:
        k,v=it.split("="); ensure(int(k,0)); uc.mem_write(int(k,0), int(v,0).to_bytes(4,"little"))
uc.reg_write(UC_ARM_REG_SP, STACK)
uc.reg_write(UC_ARM_REG_LR, STOP | 1)
uc.reg_write(UC_ARM_REG_R0, int(__import__("os").environ.get("EMU_R0","0"),0))
uc.reg_write(UC_ARM_REG_R1, a.base + PARA)
# enable VFP/NEON
uc.reg_write(UC_ARM_REG_C1_C0_2, uc.reg_read(UC_ARM_REG_C1_C0_2) | (0xf << 20))
uc.reg_write(UC_ARM_REG_FPEXC, 0x40000000)
try:
    uc.emu_start(a.entry if a.arm else (a.entry | 1), STOP, count=a.maxinsn)
    status = "ok"
except UcError as e:
    status = "err %s" % e
pc = uc.reg_read(UC_ARM_REG_PC)
log(t="end", status=status, pc=pc, r0=uc.reg_read(UC_ARM_REG_R0),
    para=[rd(a.base + PARA + 4 * i, 4) for i in range(0x34)])
out.close()
print(status, hex(pc), "r0=", uc.reg_read(UC_ARM_REG_R0), "events", seq)
