import struct, sys
def rd(f):
    d=open(f,'rb').read()
    pe=struct.unpack_from('<I',d,0x3c)[0]
    mach,nsec,ts=struct.unpack_from('<HHI',d,pe+4)
    optsz=struct.unpack_from('<H',d,pe+20)[0]; ch=struct.unpack_from('<H',d,pe+22)[0]
    opt=pe+24
    lmaj,lmin=d[opt+2],d[opt+3]
    ep,=struct.unpack_from('<I',d,opt+16); ib,=struct.unpack_from('<I',d,opt+28)
    dd=opt+96
    secs=[]
    so=opt+optsz
    for i in range(nsec):
        n=d[so+i*40:so+i*40+8].rstrip(b'\0').decode()
        vs,va,rs,ra=struct.unpack_from('<IIII',d,so+i*40+8)
        secs.append((n,va,vs,ra,rs))
    def off(rva):
        for n,va,vs,ra,rs in secs:
            if va<=rva<va+max(vs,rs): return rva-va+ra
    def cstr(rva):
        o=off(rva); return d[o:d.index(b'\0',o)].decode('latin1')
    import time
    print(f'== {f}\n machine={mach:#x} ts={time.strftime("%Y-%m-%d",time.gmtime(ts))} linker={lmaj}.{lmin} chars={ch:#x} base={ib:#x} ep={ep:#x}')
    print(' sections:',[(s[0],hex(s[1]),s[2]) for s in secs])
    erva,esz=struct.unpack_from('<II',d,dd)
    if erva:
        e=off(erva); nf,nn,af,an,ao=struct.unpack_from('<IIIII',e and d,e+20)
        name=cstr(struct.unpack_from('<I',d,e+12)[0])
        names=[cstr(struct.unpack_from('<I',d,off(an)+4*i)[0]) for i in range(nn)]
        print(f' exports ({name}): {nf} funcs, {nn} named'); print('  ',names)
    irva,_=struct.unpack_from('<II',d,dd+8)
    if irva:
        o=off(irva)
        while True:
            olt,t,fc,nm,ft=struct.unpack_from('<IIIII',d,o)
            if nm==0: break
            t=olt or ft; fns=[]; p=off(t)
            while True:
                v,=struct.unpack_from('<I',d,p)
                if v==0: break
                fns.append(f'#{v&0xffff}' if v&0x80000000 else cstr(v+2)); p+=4
            print(f'  import {cstr(nm)}: {len(fns)}', fns if len(fns)<40 else fns[:40]+['...'])
            o+=20
for f in sys.argv[1:]: rd(f)
