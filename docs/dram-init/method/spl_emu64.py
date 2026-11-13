import sys, json, struct, collections
from unicorn import *
from unicorn.arm64_const import *
elf = open("spl/art/u-boot-spl","rb").read()
uc = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
uc.mem_map(0x0, 0x200000)
uc.mem_write(0x40000, elf[0:0x29818])
SYM = dict(sunxi_dram_init=0x47c24, a733_pmic_set=0x479f0, a733_strap=0x47708, a733_log=0x4771c, a733_wait=0x477e8,
           udelay=0x4d91c, __udelay=0x4d8dc, printf=0x4df80, puts=0x4c2a8, putc=0x4c260, hang=0x4d558, panic=0x4d990)
STOP = 0x1ff000
mapped=set(); ev=[]; bss=[]
def ensure(a):
    pg=a&~0xfff
    if pg not in mapped:
        try: uc.mem_map(pg,0x1000)
        except UcError: pass
        mapped.add(pg)
def rd(a,s): return int.from_bytes(uc.mem_read(a,s),"little")
def cstr(a):
    s=b""
    while len(s)<200:
        c=uc.mem_read(a,1)[0]
        if not c: break
        s+=bytes([c]); a+=1
    return s.decode("latin1")
RAW=int(sys.argv[3]) if len(sys.argv)>3 else 2992
FIXED={0x0aaa0064:7,0x0aaa0068:0,0x02521038:2,0x02521084:RAW}
restore=[]
TW=0x07083000
tw=dict(stat=0xf8,intx=False,phase=None,bytes=[],newdata=None,reg=0,data=0)
PM={0x0e:3}
def tw_write(off,val):
    if off==0x08: tw["newdata"]=val&0xff
    elif off==0x0c:
        if val&0x20:
            tw["stat"]=0x10 if tw["intx"] else 0x08; tw["intx"]=True; tw["phase"]="addr"; tw["newdata"]=None
        elif val&0x10:
            b=tw["bytes"]
            if len(b)>=2: PM[b[0]]=b[1]; ev.append(("pmw",b[0],b[1]))
            tw.update(stat=0xf8,intx=False,phase=None,bytes=[],newdata=None)
        elif tw["intx"]:
            d=tw["newdata"]; tw["newdata"]=None
            if tw["phase"]=="addr" and d is not None:
                if d&1: tw["phase"]="read"; tw["stat"]=0x40
                else: tw["phase"]="data"; tw["stat"]=0x18
            elif tw["phase"]=="data" and d is not None:
                tw["bytes"].append(d); tw["stat"]=0x28
                if len(tw["bytes"])==1: tw["reg"]=d
            elif tw["phase"]=="read":
                tw["data"]=PM.get(tw["reg"],0); ev.append(("pmr",tw["reg"],tw["data"])); tw["stat"]=0x50 if val&4 else 0x58
def tw_read(off,cur):
    if off==0x0c: return cur|8
    if off==0x10: return tw["stat"]
    if off==0x08 and tw["phase"]=="read": return tw["data"]
    return cur
def unm(u,acc,addr,size,val,ud): ensure(addr); ensure(addr+size-1); return True
def mem(u,acc,addr,size,val,ud):
    while restore:
        a,s,v=restore.pop(); uc.mem_write(a,v.to_bytes(s,"little"))
    if 0x40000000<=addr: 
        if 0x4ff80000<=addr<0x4ff90000: bss.append((uc.reg_read(UC_ARM64_REG_PC),addr,acc==UC_MEM_WRITE))
        return
    if not (0x01000000<=addr<0x10000000): return
    if TW<=addr<TW+0x400:
        if acc==UC_MEM_WRITE: tw_write(addr-TW,val)
        else:
            cur=rd(addr,size); v=tw_read(addr-TW,cur)
            if v!=cur:
                if addr-TW!=0x0c: restore.append((addr,size,cur))
                uc.mem_write(addr,(v&((1<<(8*size))-1)).to_bytes(size,"little")) if addr-TW!=0x0c else (restore.append((addr,size,cur)), uc.mem_write(addr,v.to_bytes(size,"little")))
        return
    if acc==UC_MEM_WRITE: ev.append(("w",addr,size,val&((1<<(8*size))-1)))
    else:
        cur=rd(addr,size)
        if addr in FIXED and cur!=FIXED[addr]:
            restore.append((addr,size,cur)); uc.mem_write(addr,FIXED[addr].to_bytes(size,"little"))
        ev.append(("r",addr,size,FIXED.get(addr,cur)))
def ret(v=None):
    if v is not None: uc.reg_write(UC_ARM64_REG_X0,v)
    uc.reg_write(UC_ARM64_REG_PC,uc.reg_read(UC_ARM64_REG_X30))
def code(u,addr,size,ud):
    x=[uc.reg_read(r) for r in (UC_ARM64_REG_X0,UC_ARM64_REG_X1,UC_ARM64_REG_X2,UC_ARM64_REG_X3,UC_ARM64_REG_X4)]
    if addr==SYM["a733_pmic_set"]: ev.append(("pmic",x[0],x[1],x[2],x[3]))
    elif addr==SYM["a733_strap"]: ev.append(("strap",)); ret(int(sys.argv[1]))
    elif addr==SYM["a733_wait"]: ev.append(("wait",x[0],x[1],x[2],x[3],x[4])); ret(0)
    elif addr in (SYM["udelay"],SYM["__udelay"]): ev.append(("delay",x[0])); ret()
    elif addr==SYM["a733_log"]: ev.append(("log",cstr(x[1]) if x[1]>0x40000 and x[1]<0x200000 else hex(x[1]),x[2],x[3])); ret()
    elif addr in (SYM["printf"],SYM["puts"]): ev.append(("print",cstr(x[0]),x[1],x[2])); ret(0)
    elif addr==SYM["putc"]: ret()
    elif addr in (SYM["hang"],SYM["panic"]): ev.append(("hang",)); uc.emu_stop()
for a in set(SYM.values())-{SYM["sunxi_dram_init"]}: uc.hook_add(UC_HOOK_CODE,code,begin=a,end=a)
uc.hook_add(UC_HOOK_MEM_READ|UC_HOOK_MEM_WRITE,mem)
uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED|UC_HOOK_MEM_WRITE_UNMAPPED|UC_HOOK_MEM_FETCH_UNMAPPED,unm)
uc.reg_write(UC_ARM64_REG_SP,0x8f000); uc.reg_write(UC_ARM64_REG_X30,STOP)
uc.reg_write(UC_ARM64_REG_CPACR_EL1, 3<<20)
try:
    uc.emu_start(SYM["sunxi_dram_init"],STOP,count=3_000_000_000); st="ok"
except UcError as e: st="err %s"%e
print(st,hex(uc.reg_read(UC_ARM64_REG_PC)),"x0=",hex(uc.reg_read(UC_ARM64_REG_X0)),"events",len(ev),"bss touches",len(bss), [(hex(p),hex(a),w) for p,a,w in bss[:4]])
json.dump(ev,open(sys.argv[2],"w"))
