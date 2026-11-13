import subprocess,json,sys,collections,struct
img=open("blobs/boot0.bin","rb").read()
ext5=struct.unpack_from("<32I",img,0x374+4*0x80)
def writes(f): return [(e["a"],e["v"]) for e in map(json.loads,open(f)) if e["t"]=="w" and not (0x0a9a0000<=e["a"]<0x0a9c0000 and False)]
def run(over,out):
    para=",".join(["ext:5"]+["%d=0x%x"%(k,v) for k,v in over.items()])
    r=subprocess.run([".venv/bin/python","emu/emu.py","--para",para,"--out",out],capture_output=True,text=True)
    return r.stdout.strip().split("\n")[-1]
base=writes("emu/A.ext:5.jsonl")
PHY=0x0A900000
def name(a):
    if PHY<=a<0x0AB00000: return "PHY:%05x"%((a-PHY)>>1)
    return "%08x"%a
from multiprocessing import Pool
def job(wb):
    w,bit=wb
    tmp="emu/tmp.%d.%d.jsonl"%(w,bit)
    st=run({w:ext5[w]^(1<<bit)},tmp)
    ws=writes(tmp) if st.startswith("ok") else []
    import os
    try: os.remove(tmp)
    except OSError: pass
    if len(ws)==len(base):
        ch=collections.Counter(name(a) for (a,v),(a2,v2) in zip(ws,base) if v!=v2 or a!=a2)
        return "%d\t%d\t%s\t%d\t%s\n"%(w,bit,"ok",sum(ch.values())," ".join(sorted(ch)[:40]))
    return "%d\t%d\t%s\t%d\t%s\n"%(w,bit,"flow-changed" if st.startswith("ok") else "fail",len(ws)-len(base),st[:60])
if __name__=="__main__":
    jobs=[(w,b) for w in range(2,32) for b in range(32)]
    with Pool(6) as pool, open("emu/sensitivity.tsv","w") as res:
        res.write("word\tbit\tstatus\tchanged_writes\tregisters\n")
        for line in pool.imap(job,jobs,chunksize=1):
            res.write(line); res.flush()
