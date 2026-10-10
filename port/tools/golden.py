"""Reader for oracle golden files (SVGOLD1)."""
import struct

def read(path):
    d = open(path, 'rb').read()
    assert d.startswith(b'SVGOLD1\n')
    i, cases, cur = 8, [], None
    while i < len(d):
        tag = d[i:i+4].decode(); n = struct.unpack_from('<I', d, i+4)[0]; body = d[i+8:i+8+n]; i += 8 + n
        if tag == 'CASE':
            kv = dict(l.split('=', 1) for l in body.decode('utf-8').split('\n'))
            cur = {'meta': kv, 'snaps': [], 'stages': []}; cases.append(cur)
        elif tag in ('SNAP', 'STAG'):
            o = 0; stage = None
            if tag == 'STAG': stage = struct.unpack_from('<I', body, 0)[0]; o = 4
            ctx = struct.unpack_from('<I', body, o)[0]; o += 4; blocks = []
            for _ in range(5):
                addr, ln = struct.unpack_from('<II', body, o); o += 8
                blocks.append((addr, body[o:o+ln])); o += ln
            snap = dict(ctx=ctx, ctxmem=blocks[0], recs=blocks[1], syll=blocks[2], frames=blocks[3], cmds=blocks[4])
            if stage is None: cur['snaps'].append(snap)
            else: snap['stage'] = stage; cur['stages'].append(snap)
        elif tag == 'MODS': cur['mods'] = struct.unpack('<3I', body)
        elif tag == 'TTPR': cur['ttpr'] = struct.unpack('<i', body)[0]
        elif tag == 'PHON': cur['phon'] = body
        elif tag == 'PCM_': cur['pcm'] = body
        elif tag == 'DONE': cur['done'] = struct.unpack('<3I', body)
    return cases
