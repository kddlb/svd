"""Generate corpus/frames_es.txt: Spanish phrases with per-stage snapshots
for the Spanish frame-generator test (tests/frames.rs, `spanish`).

  python -I tools/mkcorpus_frames_es.py   -> corpus/frames_es.txt
  cd oracle/build && ./oracle.exe ../../corpus/frames_es.txt ../../golden/frames_es.svg

Covers all 20 presets, the setters, all Spanish letters (accents, ñ, ü,
rr, ll, ch, qu, gu/gü, x, w, k), numbers and punctuation in text mode, and
embedded commands ({voice}, {glot}, {tract}, {f0style}, notes, pauses,
biases, ...) in phoneme mode.  Each phrase costs ~0.75 MB of golden data,
so the corpus is kept to roughly 350 phrases.
"""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, '..', 'corpus', 'frames_es.txt')

SENT = [
    "Hola señor, ¿cómo está usted?",
    "El perro corre rápido por la carretera.",
    "Guillermo y Jorge juegan al ajedrez.",
    "La cigüeña bebe agua y vino.",
    "Queso, kilo, whisky, zapato, xilófono.",
    "Huevo, hielo, hueso, ahí, búho.",
    "Llama, lluvia, yate, yo, rey, muy, hoy.",
    "Fiesta, chocolate, gente, gigante, ñandú.",
    "Pingüino, vergüenza, guerra, guitarra.",
    "Un banco, un vaso, enfermo, inmenso.",
    "Treinta y cuatro mil quinientos sesenta y siete.",
    "¿Dónde está la biblioteca?",
    "¡Qué bonito día hace hoy!",
    "Tres tristes tigres tragaban trigo en un trigal.",
    "Me gusta mucho la música y el chocolate.",
    "Erre con erre cigarro, erre con erre barril.",
    "El niño come una manzana roja.",
    "Buenos días, señora García.",
    "Cuesta 25 pesos y 50 centavos.",
    "Hoy es el 12 de octubre de 1996.",
    "Ay, ay, ay, canta y no llores.",
    "Paso a paso se va lejos.",
    "La jirafa y el elefante viven en África.",
    "Ésta es la canción del pájaro azul.",
    "Él tenía frío, ella tenía sueño.",
    "Sí, no, quizá, también, después.",
    "El examen de matemáticas fue fácil.",
    "Los murciélagos vuelan en la oscuridad.",
    "Ahora mismo voy al aeropuerto.",
    "Un rinoceronte enorme cruzó el río.",
    "Ojalá que llueva café en el campo.",
    "Mi abuela hace tortillas con huevo.",
    "Pedro, Pablo y Paula pintan paredes.",
    "Fui a Madrid, Barcelona y Valencia.",
    "Dime con quién andas y te diré quién eres.",
    "Camarón que se duerme se lo lleva la corriente.",
    "El zorro feliz salta sobre el perezoso.",
    "¿Qué hora es? Son las tres y media.",
    "Nunca, jamás, siempre, ahora, ayer.",
    "Las ovejas pastan en el prado verde.",
]

WORDS = [
    "a", "e", "i", "o", "u", "y", "sí.", "no.", "ñu.", "ah.",
    "Arroz.", "Rosa.", "Honra.", "Israel.", "Enrique.", "Alrededor.",
    "Callo, cayo, calló.", "Ciento, siento.", "Hecho, echo.",
    "Pequeño, sueño, año, uña.", "Agua, antigua, averigüé.",
    "Psicología, ptolomeo, gnomo.", "Wenceslao y Kiko.",
    "Taxi, México, Xavier, examen.", "Ñoño ñame.",
    "1, 2, 3, 4, 5, 6, 7, 8, 9, 10.", "1.000.000", "3,14", "100%",
    "¡Ay!", "¿Eh?", "Mmm.", "Shh.", "Bueno... pues... no sé.",
    "Uno; dos: tres - cuatro (cinco).",
    "Atlántico, Pacífico, Índico.", "Él, tú, sé, más, aún, sólo.",
    "Fluir, cruel, dual, ruido, viuda.", "Oigo, aire, causa, reino, deuda.",
    "Construcción, instrucción, abstracto.",
]

# Phoneme-mode lines (Spanish phoneme names as produced by SVTextToPhon)
# exercising the embedded commands.
PHON = [
    "{f0style sing; c4} LAA5 {e4} LAA5 {g4} LAA5 {c5} LAA5.",
    "{f0style sing; a3} MAA5 {a#3} MAA5 {b3} NOH5 {c0} NOH5 {g#8} SOH5L.",
    "{f0style sing} {pitch 200} LAA5 {pitch 150} LAA5 {d4} RREH5.",
    "{f0style monotone} OH5LAA SEHNYOH5R.",
    "{f0style random} OH5LAA SEHNYOH5R KOH5MOH EHSTAA5.",
    "{f0style natural} OH5LAA SEHNYOH5R.",
    "{f0style style2} OH5LAA SEHNYOH5R {c4} KOH5MOH {pitch 300} EHSTAA5.",
    "{f0style style2; c4} LAA5 {e4} LAA5 {g4} LAA5.",
    "OH5LAA {voicing whispered} SEHNYOH5R.",
    "OH5LAA {voicing breathy} SEHNYOH5R {voicing normal} KOH5MOH.",
    "{pitch 200} OH5LAA {pitch 80} SEHNYOH5R.",
    "{rate 60} LEH5NTOH {rate 400} RAA5PIYDOH.",
    "{vibrato 50} AA5AA5AA5AA5.",
    "{tremelo 50} AA5AA5AA5AA5.",
    "{tone 100} AA5 {tonelo 50} AA5.",
    "{mod 50; modrate 10; modramp 5} AA5AA5.",
    "{perturb 300} OH5LAA.",
    "{vfactor 300} OH5LAA {vfactor 50} SEHNYOH5R.",
    "{avbias -10} AA5 {ahbias 10} AA5 {afbias 10} SSSS.",
    "{f1bias 100} AA5 {f2bias -100} IY5 {f3bias 200} UW5.",
    "{f1bias -100} AA5 {f2bias 300} EH5 {f3bias -200} OH5.",
    "{b1bias 50} AA5 {b2bias 50} IY5 {b3bias 50} UW5.",
    "{b4bias 50} OH5 {b5bias -20} EH5.",
    "{avspeed 5} AA5 {afspeed 5} SAA5 {ahspeed 5} HHAA5.",
    "{glot impulse} AA5 {glot mellow} AA5 {glot odd} AA5 {glot default} AA5.",
    "{glot odd} AA5 {glot mellow} EH5 {glot impulse} IY5 {glot default} OH5.",
    "{tract giant} AA5 {tract child} AA5 UW5.",
    "{voice robotoid} OH5LAA {voice thefly} SEHNYOH5R.",
    "{voice choirboy} LAA5 {voice tipsy} LAA5 {voice nerd} LAA5.",
    "{voice crispmale} PEH5RROH {voice mellowfemale} GAA5TOH {voice child} NYIY5NYOH.",
    "{voice martian} OH5LAA {voice colossus} SEHNYOH5R {voice oldwoman} KOH5MOH.",
    "{voice female} MAA5MAA {voice male} PAA5PAA.",
    "{pause 500} AA5 {comma 300}, AA5 {period 800}. AA5.",
    "{dash 200} UWN {pause 100} DOH5S {pause 1000} TREH5S.",
    "{tempo 50} UW5NOH DOH5S TREH5S.",
    "{tempo 120} UW5NOH * DOH5S * TREH5S *.",
    "{transpose 5} AA5 {finetune 50} AA5.",
    "{hoarse 50} AA5 {diplo 50} AA5 {f0up 20} AA5 {f0down 20} AA5.",
    "{articeff 50} OH5LAA {articspd 50} SEHNYOH5R.",
    "{volume 50} SUWAA5VEH {volume 150} FUWEH5RTEH.",
    "{f0range 400} OH5LAA {f0range 20} SEHNYOH5R.",
    "{voice munchkin} OH5LAA {voice troll} SEHNYOH5R {voice fastfred} KOH5MOH.",
    "{voice milktoast} UWSTEH5D {voice largemale} SIY5 {voice giantmale} NOH5.",
    "{voice mellowmale} BEH5SOH {voice female} MAA5MAA.",
    "AA5 EH5 IY5 OH5 UW5 AY5 EY5 OY5 AW5 OW5 UH5 AH5 AE5 AO5 AX5 IX5 IH5 ER5.",
    "PAA5 BAA5 TAA5 DAA5 KAA5 GAA5 FAA5 VAA5 SAA5 ZAA5 SHAA5 ZHAA5 THAA5 DHAA5.",
    "CHAA5 HHAA5 MAA5 NAA5 NYAA5 LAA5 RAA5 RRAA5 WAA5 YAA5 AA5NX.",
    "AA1 AA2 AA3 AA4 AA5 AA6 AA7 AA8 AA9.",
    "(AA5) AA5 )AA5 AA5-AA5: AA5? AA5!",
    "KAARREHTEH5RAA {pitch 300} GIYTAA5RRAA {pitch 90} PEH5RROH.",
]

# More phoneme-mode lines for rarer paths: pitch commands in the singing
# (sing = f0style 3) and "random" (f0style 4) modes, notes out of range,
# user syncs, unusual phoneme sequences.
EXTRA = [
    "{f0style random} {pitch 200} LAA5 {c4} LAA5 {transpose 3; f0range 300} LAA5 {pitch 5} LAA5 {pitch 3000} LAA5.",
    "{f0style random} MAA5 {g#8} NOH5 {a0} SOH5L {transpose -40} {c1} LAA5.",
    "{f0style sing; transpose 2; f0range 200} {c4} LAA5 {pitch 3000} LAA5 {pitch 5} LAA5 {pitch 300} LAA5.",
    "{f0style sing; transpose -40} {c0} LAA5 {transpose 30} {g#8} LAA5.",
    "{pitch 3000} OH5LAA {pitch 5} SEHNYOH5R {pitch 0} KOH5MOH.",
    "{usync 7} OH5LAA {usync 200} SEHNYOH5R {usync 3} KOH5MOH.",
    "{mouths on} BEH5SOH {mouths off} MAA5MAA.",
    "{rate 2} OH5LAA {rate 1} SEHNYOH5R.",
    "AA5SHOH AA5SHUW IY5ZHOH PER5S BER5T KER5N SER5K.",
    "CHUW5PAA CHUW5LOH SHUW5MAA AA5JUW.",
]

# (setter, values) sweeps with voice 0 (and voice 10 for a female voice).
SWEEPS = [
    ('gender', [0, 1, 2, 3]),
    ('glot', list(range(9))),
    ('voicing', [0, 1, 2]),
    ('f0style', [0, 1, 2, 3, 4]),
    ('f0range', [0, 50, 250, 500]),
    ('perturb', [0, 250, 500]),
    ('vfactor', [30, 100, 300]),
    ('avbias', [-30, 0, 20]),
    ('ahbias', [-30, 20]),
    ('afbias', [-30, 20]),
    ('speakmode', [1, 2, 4]),
    ('pitch', [10, 40, 75, 400, 1000, 2000]),
    ('rate', [20, 40, 300, 500]),
]


def main():
    out = ['# Generated by tools/mkcorpus_frames_es.py: Spanish frame-generator coverage.',
           '#stages 1', '#lang es', '#mode text']
    n = 0
    # All presets, rotating through the sentences.
    for v in range(20):
        out.append(f'#voice {v}')
        for k in range(8):
            out.append(SENT[(v * 8 + k * 3) % len(SENT)])
    # Words and letters with a few presets.
    for i, wd in enumerate(WORDS):
        if i % 10 == 0:
            out.append(f'#voice {(i // 10) * 5 + 2}')
        out.append(wd)
    # Setter sweeps.
    for base in (0, 10):
        out.append(f'#voice {base}')
        k = 0
        for key, values in SWEEPS:
            for val in values:
                out += ['#reset 1', f'#{key} {val}', SENT[(k * 7 + base) % len(SENT)]]
                k += 1
        out.append('#reset 1')
    # Combinations of setters.
    out.append('#voice 3')
    for g, vo, st in [(1, 1, 3), (2, 2, 4), (3, 1, 2), (0, 2, 1), (2, 0, 3)]:
        out += ['#reset 1', f'#gender {g}', f'#voicing {vo}', f'#f0style {st}', SENT[(g * 11 + vo * 3 + st) % len(SENT)]]
    out.append('#reset 1')
    # Embedded commands in phoneme mode.
    out.append('#mode phon')
    for v in (0, 4, 10, 15):
        out.append(f'#voice {v}')
        out += PHON if v == 0 else PHON[v % 3::3]
    for v in (0, 10):
        out.append(f'#voice {v}')
        out += EXTRA
    out.append('#mode text')
    out.append('#voice 0')
    out += ["La ala, de el, lo otro, a ella, mi hijo.", "Alma, alto, el mar, el niño, olmo.",
            "Robot rojo, mamut rápido, sándwich sabroso.", "Chupa, chulo, chuleta, chubasco.",
            "Esto, este, isla, espera, España, escuela, asco."]
    with open(OUT, 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(out) + '\n')
    n = sum(1 for l in out if l and not l.startswith('#'))
    print(OUT, n, 'cases')


if __name__ == '__main__':
    main()
