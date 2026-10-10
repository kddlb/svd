# tiny PE helper: va<->file offset, find refs to a VA in code, disassemble
import struct, re, capstone
class PE:
    def __init__(s,f):
        d=s.d=open(f,'rb').read(); pe=struct.unpack_from('<I',d,0x3c)[0]; opt=pe+24
        optsz=struct.unpack_from('<H',d,pe+20)[0]; s.ib=struct.unpack_from('<I',d,opt+28)[0]
        n=struct.unpack_from('<H',d,pe+6)[0]
        s.secs=[(d[opt+optsz+i*40:opt+optsz+i*40+8].rstrip(b'\0').decode(),)+struct.unpack_from('<IIII',d,opt+optsz+i*40+8) for i in range(n)]
        s.md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    def off(s,va):
        r=va-s.ib
        for n,vs,va_,rs,ra in s.secs:
            if va_<=r<va_+rs: return r-va_+ra
    def va(s,o):
        for n,vs,va_,rs,ra in s.secs:
            if ra<=o<ra+rs: return o-ra+va_+s.ib
    def text(s): n,vs,va_,rs,ra=s.secs[0]; return ra,ra+vs
    def refs(s,target):
        a,b=s.text(); pat=re.escape(struct.pack('<I',target))
        return [s.va(m.start()) for m in re.finditer(pat,s.d[a:b] and s.d) if a<=m.start()<b]
    def dis(s,start,end):
        o=s.off(start); out=[]
        for i in s.md.disasm(s.d[o:o+(end-start)],start): out.append(f'{i.address:08x}  {i.mnemonic} {i.op_str}')
        return out
    def u16(s,va): return struct.unpack_from('<H',s.d,s.off(va))[0]
    def u32(s,va): return struct.unpack_from('<I',s.d,s.off(va))[0]
    def cstr(s,va): o=s.off(va); return s.d[o:s.d.index(b'\0',o)].decode('latin1')
