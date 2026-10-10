"""Generate oracle corpora into port/corpus/.

  python tools/mkcorpus.py synth     -> corpus/synth.txt
  python tools/mkcorpus.py stages    -> corpus/stages.txt (per-stage snapshots)
"""
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
CORPUS = os.path.join(HERE, '..', 'corpus')

EN = [
    "Hello, world.",
    "I am a talking computer from 1996!",
    "Is it raining? Yes, it is.",
    "The quick brown fox jumps over the lazy dog.",
    "She sells sea shells by the sea shore.",
    "Peter Piper picked a peck of pickled peppers.",
    "How much wood would a woodchuck chuck if a woodchuck could chuck wood?",
    "Please call me at 555-1234 before noon.",
    "It costs $19.95, or about twenty dollars.",
    "My birthday is on 7/4/86, and I was born at 10:30.",
    "Wow! That was amazing.",
    "Well... I don't know; maybe, maybe not.",
    "Twinkle, twinkle, little star, how I wonder what you are.",
    "The rain in Spain stays mainly in the plain.",
    "Can you hear me now? Good.",
    "One, two, three, four, five, six, seven, eight, nine, ten.",
    "Dr. Smith lives on Elm St. near the old mill.",
    "Zebras, xylophones and yo-yos are fun.",
    "Thirteen thousand four hundred and fifty-two.",
    "The year 2000 will be exciting.",
    "Measure twice, cut once.",
    "Judge Judy and church bells ring at night.",
    "Butter, bottle, button, kitten, little, mountain.",
    "Strength, twelfths, sixths, glimpsed.",
    "Oh, oh, ah, ee, oo, uh, eh.",
    "Shh! Hush now, sleep tight.",
    "Ready, set, go!",
    "Why? Because I said so.",
    "This is a very, very, very long sentence that keeps going and going so that the synthesizer has to produce many frames without a single pause anywhere.",
    "a",
    "I.",
    "No.",
    "Hmm.",
    "Supercalifragilisticexpialidocious!",
    "The 3 little pigs had 24 bricks and 100 sticks.",
    "Mississippi, Massachusetts, Connecticut.",
    "Whoa, whoa, whoa, slow down there, partner.",
    "Thank you very much for listening.",
    "Is this the real life? Is this just fantasy?",
    "Good morning, Mrs. Jones. How are you today?",
]

ES = [
    "Hola señor, ¿cómo está usted?",
    "Mañana llueve en Jerez.",
    "El perro de San Roque no tiene rabo.",
    "Tres tristes tigres tragaban trigo en un trigal.",
    "¿Dónde está la biblioteca?",
    "Me gusta mucho la música y el chocolate.",
    "Uno, dos, tres, cuatro, cinco.",
    "La lluvia en Sevilla es una maravilla.",
    "¡Qué bonito día hace hoy!",
    "Erre con erre cigarro, erre con erre barril.",
    "El niño come una manzana roja.",
    "Buenos días, señora García.",
    "Cuesta 25 pesos y 50 centavos.",
    "¿Por qué? Porque sí.",
    "Guillermo y Jorge juegan al ajedrez.",
    "Año, caña, piña, señal.",
    "Hoy es el 12 de octubre de 1996.",
    "Muchas gracias por escuchar.",
    "Ay, ay, ay, canta y no llores.",
    "Paso a paso se va lejos.",
]

# (directive, values) sweeps applied to a few sentences with voice 0.
SWEEPS = [
    ('gender', [0, 1, 2, 3]),
    ('glot', list(range(9))),
    ('voicing', [0, 1, 2]),
    ('f0style', list(range(5))),
    ('f0range', [0, 50, 250, 500]),
    ('perturb', [0, 100, 250, 500]),
    ('vfactor', [30, 60, 100, 200, 300]),
    ('avbias', [-30, -10, 0, 10, 20]),
    ('ahbias', [-30, -10, 0, 10, 20]),
    ('afbias', [-30, -10, 0, 10, 20]),
    ('speakmode', [1, 2, 4]),
    ('pitch', [10, 40, 75, 400, 1000, 2000]),
    ('rate', [20, 40, 80, 300, 400, 500]),
]
SWEEP_EN = [EN[0], EN[3], EN[5], EN[22], EN[28]]
SWEEP_ES = [ES[0], ES[3]]

# Hand-written phoneme strings exercising embedded commands.
PHON = [
    "{f0style sing; c4} LAA5 {e4} LAA5 {g4} LAA5 {c5} LAA5.",
    "{f0style sing; a3} LAA5 {a#3} LAA5 {b3} LAA5 {c0} LAA5 {g#8} LAA5.",
    "/HEH5LOW {voicing whispered} WER5LD.",
    "/HEH5LOW {voicing breathy} WER5LD {voicing normal} AXGEH5N.",
    "{pitch 200} /HEH5LOW {pitch 80} WER5LD.",
    "{rate 60} SLOW5 {rate 400} FAE5ST.",
    "{vibrato 50} AA5AA5AA5AA5.",
    "{tremelo 50} AA5AA5AA5AA5.",
    "{tone 100} AA5 {tonelo 50} AA5.",
    "{mod 50; modrate 10; modramp 5} AA5AA5.",
    "{perturb 300} /HEH5LOW.",
    "{vfactor 300} /HEH5LOW {vfactor 50} WER5LD.",
    "{avbias -10} AA5 {ahbias 10} AA5 {afbias 10} SSSS.",
    "{f1bias 100} AA5 {f2bias -100} IY5 {f3bias 200} UW5.",
    "{b1bias 50} AA5 {b2bias 50} IY5 {b3bias 50} UW5.",
    "{glot impulse} AA5 {glot mellow} AA5 {glot odd} AA5.",
    "{tract giant} AA5 {tract child} AA5.",
    "{voice robotoid} /HEH5LOW {voice thefly} WER5LD.",
    "{voice choirboy} LAA5 {voice tipsy} LAA5 {voice nerd} LAA5.",
    "{f0style monotone} DHIH5S IHZ FLAE5T.",
    "{f0style random} DHIH5S IHZ RAE5NDAXM.",
    "{pause 500} AA5 {comma 300}, AA5 {period 800}. AA5.",
    "{tempo 50} WAH5N TUW5 THRIY5.",
    "{transpose 5} AA5 {finetune 50} AA5.",
    "{hoarse 50} AA5 {diplo 50} AA5 {f0up 20} AA5 {f0down 20} AA5.",
    "{articeff 50} /HEH5LOW {articspd 50} WER5LD.",
    "{volume 50} SOFT5 {volume 150} LAW5D.",
    "AA5 IY5 UW5 EH5 OW5 AE5 AO5 UH5 ER5 AY5 AW5 OY5 EY5 YU5.",
    "PAA5 BAA5 TAA5 DAA5 KAA5 GAA5 FAA5 VAA5 THAA5 DHAA5 SAA5 ZAA5 SHAA5 ZHAA5.",
    "CHAA5 JAA5 /HAA5 MAA5 NAA5 LAA5 RAA5 WAA5 YAA5 AA5NX.",
    "BAH5TER BAH5TUN BAA5TUL KIH5TQUN.",
    "AA1 AA2 AA3 AA4 AA5 AA6 AA7 AA8 AA9.",
    "(AA5) AA5 )AA5 AA5-AA5: AA5?",
    "",
]


def synth():
    out = ['# Generated by tools/mkcorpus.py synth: presets, setter sweeps, embedded commands.']
    out.append('#lang en')
    for v in range(20):
        out.append(f'#voice {v}')
        out += EN
    out.append('#lang es')
    for v in range(20):
        out.append(f'#voice {v}')
        out += ES
    out.append('#voice 0')
    for lang, sents in (('en', SWEEP_EN), ('es', SWEEP_ES)):
        out.append(f'#lang {lang}')
        for key, values in SWEEPS:
            for val in values:
                out.append('#reset 1')
                out.append(f'#{key} {val}')
                out += sents
        out.append('#reset 1')
    out.append('#lang en')
    out.append('#mode phon')
    for v in (0, 1, 3, 9):
        out.append(f'#voice {v}')
        out += [p for p in PHON if p]
    out.append('#mode text')
    return out


def stages():
    """Smaller corpus with per-stage snapshots (#stages 1) for stage tests."""
    out = ['# Generated by tools/mkcorpus.py stages: per-stage snapshots.', '#stages 1', '#lang en']
    for v in range(20):
        out.append(f'#voice {v}')
        out += EN[v % 8::8][:3]
    out.append('#voice 0')
    for key, values in SWEEPS:
        for val in values:
            out += ['#reset 1', f'#{key} {val}', EN[(len(out) * 7) % len(EN)]]
    out.append('#reset 1')
    out.append('#lang es')
    for v in range(0, 20, 3):
        out.append(f'#voice {v}')
        out += ES[v % 4::4][:3]
    out.append('#voice 0')
    out.append('#lang en')
    out.append('#mode phon')
    for v in (0, 1, 3, 9):
        out.append(f'#voice {v}')
        out += [p for p in PHON if p]
    out.append('#mode text')
    return out


def persist():
    """One engine kept open across many utterances (#persist 1), like an
    application: language/preset/setter changes and stateful embedded
    commands between utterances."""
    out = ['# Generated by tools/mkcorpus.py persist: long-lived engines.']
    # Session 1: English, plain run of sentences on one voice.
    out += ['#persist 1', '#lang en', '#voice 0'] + EN[:20]
    # Session 2: switching presets and setters between utterances.
    out += ['#persist 0', '#persist 1']
    for i, sent in enumerate(EN[:30]):
        out.append(f'#voice {i % 20}')
        out.append('#reset 1')
        key, values = SWEEPS[i % len(SWEEPS)]
        out.append(f'#{key} {values[i % len(values)]}')
        out.append(sent)
    out.append('#reset 1')
    # Session 3: languages alternating on one engine.
    out += ['#persist 0', '#persist 1', '#voice 0']
    for e, s in zip(EN[:12], ES[:12]):
        out += ['#lang en', e, '#lang es', s]
    # Session 4: phoneme strings with embedded commands whose effects persist
    # in the engine ({vibrato}, {f0style}, {voice}...), then plain text.
    out += ['#persist 0', '#persist 1', '#lang en', '#voice 0', '#mode phon']
    out += [p for p in PHON if p and 'SOFT5' not in p and 'YU5' not in p]
    out += ['#mode text'] + EN[20:30]
    out += ['#persist 0']
    return out


def main():
    which = sys.argv[1] if len(sys.argv) > 1 else 'synth'
    lines = {'synth': synth, 'stages': stages, 'persist': persist}[which]()
    path = os.path.join(CORPUS, f'{which}.txt')
    with open(path, 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(lines) + '\n')
    print(path, sum(1 for l in lines if l and not l.startswith('#')), 'cases')


if __name__ == '__main__':
    main()
