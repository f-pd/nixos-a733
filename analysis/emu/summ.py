import json,sys,collections,bisect,glob,os,re
tr=[json.loads(l) for l in open(sys.argv[1])]
# function starts from decompile dir
starts=sorted(int(os.path.basename(p)[:-2],16) for p in glob.glob("dec/boot0/functions/*.c"))
def fn(pc):
    i=bisect.bisect_right(starts,pc)-1
    return starts[i] if i>=0 else 0
def region(a):
    if 0x0a900000<=a<0x0ab00000: return "PHY"
    if 0x0a100000<=a<0x0a500000: return "CTL0"
    if 0x0a500000<=a<0x0a900000: return "CTL1"
    if 0x0a020000<=a<0x0a040000: return "GLUE"
    if 0x02002000<=a<0x02003000: return "CCU"
    return "%08x"%(a&0xfffff000)
c=collections.Counter(); seqs=[]
last=None
for e in tr:
    if e["t"] in("w","r"):
        k=(e["t"],region(e["a"]),hex(fn(e["pc"])))
        c[k]+=1
        if last and last[0]==k: last[1]+=1
        else:
            last=[k,1,e["n"]]; seqs.append(last)
    else:
        last=None; seqs.append([(e["t"],json.dumps({k:v for k,v in e.items() if k not in("t","n","para")})[:90],""),1,e["n"]])
for k,n,s in seqs: print(s,k[0],k[1],k[2],n)
