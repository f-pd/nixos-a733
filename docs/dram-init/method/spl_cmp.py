import json,sys
ev=json.load(open(sys.argv[1])); ops=sys.argv[2]
BASES={"PHY":0x0A900000,"CTL0":0x0A100000,"CTL1":0x0A500000,"GLUE":0x0A020000,"CCU":0x02002000,"SYS2":0x02020000,"SYSCFG":0x03000000,"PRCM":0x07010000,"ABS":0}
exp=[]
for line in list(open(ops))[1:]:
    op,block,addr,value,extra=(line.rstrip("\n").split("\t")+[""]*5)[:5]
    ab=lambda o: BASES[block]+((o<<1) if block=="PHY" else o)
    if op in("W16","W32"): exp.append((ab(int(addr,16)),int(op[1:])//8,int(value,16)))
    elif op.startswith("RMW"): exp.append((ab(int(addr,16)),int(op[3:])//8,int([t for t in extra.split() if t.startswith("written=")][0][8:],16)))
    elif op in("ZERO16","LOAD16"):
        for i in range(int(value)): exp.append((ab(int(addr,16)+i),2,0))
got=[(e[1],e[2],e[3]) for e in ev if e[0]=="w"]
i0=next((i for i,g in enumerate(got) if g[0]==0x03000160),None)
g=got[i0:] if i0 is not None else []
d=[(k,[hex(v) for v in x],[hex(v) for v in y]) for k,(x,y) in enumerate(zip(g,exp)) if x!=y]
print(ops.split("/")[-1],"got",len(g),"expected",len(exp),"differences",len(d),d[:3], [e for e in ev if e[0]=="print" and "strap" in e[1]][:1])
