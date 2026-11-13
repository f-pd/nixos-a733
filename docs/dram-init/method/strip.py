import sys,re,struct,glob,os
blob,base,decdir,out=sys.argv[1],int(sys.argv[2],16),sys.argv[3],sys.argv[4]
d=open(blob,"rb").read()
def val(a):
    o=a-base
    if 0<=o<=len(d)-4: return struct.unpack_from("<I",d,o)[0]
def cstr(a):
    o=a-base
    if 0<=o<len(d):
        e=d.find(b"\0",o)
        s=d[o:e]
        if 4<=len(s)<=120 and all(32<=c<127 or c in(10,13,9) for c in s): return s.decode()
def ann(m):
    a=int(m.group(1),16); v=val(a)
    if v is None: return m.group(0)
    s=cstr(v)
    if s: return '%s/*"%s"*/'%(m.group(0),s.replace("\n","\\n")[:70])
    return "%s/*=0x%x*/"%(m.group(0),v)
with open(out,"w") as f:
    for p in sorted(glob.glob(decdir+"/functions/*.c"),key=lambda p:int(os.path.basename(p)[:-2],16)):
        t=open(p).read()
        i=t.find("// pseudocode:")
        body=t[t.find("\n",i)+1:]
        rng=re.search(r"// range: (.*)",t)
        body=re.sub(r"\bDAT_([0-9a-f]{8})\b",ann,body)
        f.write("\n//==== %s  %s\n"%(os.path.basename(p)[:-2],rng.group(1) if rng else "")+body.strip()+"\n")
