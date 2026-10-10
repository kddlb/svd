# SoftVoice (Talk It!) codes reference

Everything the engine accepts or reports as a code: the phoneme strings
spoken by `SVNarrate`, the embedded `{commands}` inside them, the phoneme
codes, and the API's error codes, sync messages and flags.

The facts here come from the reverse-engineered DLLs (TIBASE32 / TIENG32 /
TISPAN32 1.0.0.1117). Most were checked by rendering with the bit-exact
Rust port (`port/target/release/svsay -P -w out.wav "..."`) and comparing
the outputs. Statements marked *(code)* are read from the code and were not
checked by ear or by output comparison.

---

## 1. Phoneme strings

`SVTextToPhon` produces phoneme strings, and `SVNarrate` speaks them. You can
also write them by hand:

```
 @w0  /HEH5LOW, @w7  WER5LD.          <- "Hello, world." (English)
{f0style sing; c4} LAA5 {e4} LAA5.    <- hand-written, with commands
```

- **Words** are separated by spaces. Inside a word the phoneme codes run
  together with no separator (`KUMPYUW4TER`). Each code is read greedily as
  one or two characters, using the spellings in section 3.
- **Stress** is a digit `0`–`9` written right after a vowel. `'` means
  stress 5 and `"` means stress 2. Higher is stronger; the rules use 1–5. A
  stress digit after a non-vowel fails with error 7001.
- **Sentences** end at `.` or `?`. Each sentence is synthesized as a separate
  phrase, and `?` gives question intonation.
- **Pauses** are `,` (comma pause), `-` (dash pause) and `:` (a short pause).
  You can change their lengths with `{comma}`, `{dash}` and `{period}`.
- **Pitch-level marks:** `(` starts a stretch at pitch level +2 from the next
  syllable, and `)` ends it at level −2 on the previous syllable. The English
  rules put `)` before function words, for example `)BAXT` "but". *(code)*
- **Beat marks:** a `*` before a phoneme makes it a beat for `{tempo}`
  (section 2).
- **Word markers:** `@w<n>` produces a word sync event with value *n* (a
  character offset in the source text) when the next word starts.
  `SVTextToPhon` inserts these markers when flag 0x08 is set.
- **English R-merge:** in English a vowel followed by `R` becomes an
  R-coloured vowel: `IYR`→IXR, `EHR`→EXR, `AAR`→AXR, `OWR`→OXR, `UWR`→UXR.
  This is the only way to get those five phonemes.
- **Invalid input:** an unknown character or pair gives error 7001
  "Phoneme code error". Spellings are upper case.
- **Long sentences:** a sentence has room for (number of non-`@w`
  characters × 2 + 10) phonemes.

---

## 2. Embedded commands `{...}`

```
{cmd arg}            {cmd arg pos}            {cmd1 arg; cmd2 arg}{cmd3 arg}
```

### Syntax

- **Grouping:** separate commands with `;`, or put them in further `{...}`
  groups placed directly after one another. Spaces inside braces are
  allowed.
- **Keywords** are matched by prefix and must be lower case. The first
  keyword in the table that the word starts with wins, so `{p150}` means
  `{p 150}` and `{pitchx 9}` means `{pitch 9}`.
- **Numbers** are decimal, with an optional `+` or `-`. A trailing `%` makes
  the value relative (it is stored negated). A number must be followed by
  space, `;` or `}`, otherwise it's an error.
- **Keyword arguments** such as `{voice robotoid}` are also matched by
  prefix, against the lists below.
- **`pos`** is an optional third token: a time in milliseconds into the
  following phoneme. Commands that act per frame (rate, voice, tract,
  voicing, tone, biases, articulation, sync) take effect at that frame. In
  `sing` and held-pitch modes a `{pitch}` with a position starts the change
  there.
- **Errors:** an unknown keyword, a bad number or a keyword argument that
  isn't in its list makes `SVNarrate` fail with **7015** ("Embedded command
  error"). That includes `{voice 3}`, which needs a name.
- **Bare numbers:** `{N}` is a duration (see `pause`), and `{c4}`, `{f#3}`
  and similar are musical notes (see `pitch`).

### Where and how long commands apply

A command is attached to the **phoneme that follows it**, so put it right
before the sound it should affect. Its setting then holds **until changed,
for the rest of that `SVNarrate` call**. The next `SVNarrate` starts again
from the engine's voice settings (`SVSet*` / `SVSetPersonality`).

The exceptions are `mod`, `vibrato`, `tremelo` and `tonelo`. Nothing resets
them, so on a long-lived engine they carry over into later utterances.
*(code)*

`SVTextToPhon` passes `{...}` groups through unchanged, but only the English
rules do so. The Spanish rules read the text inside the braces aloud.

### Command table

Code = the internal command code (decimal / hex). "No effect" means the
command parses but changes nothing in the audio of this build. That was
checked by rendering with and without it.

#### Voice and vocal tract

| Command | Code | Argument | Effect |
|---|---|---|---|
| `voice` | 50 / 0x32 | preset name | Switches to a preset mid-utterance: pitch, rate, F0 style, tract, voicing, formant scales and so on. Inline it updates the synthesis parameters, so it is close to but not identical to `SVSetPersonality`. The names are matched in list order and select presets 0–19: `male` `female` **`largemale`** (Fast Female) `child` `giantmale` `mellowfemale` **`mellowmale`** (Choir Girl) **`crispmale`** (Amazon) `thefly` `robotoid` `martian` `colossus` `fastfred` `oldwoman` `munchkin` `troll` `nerd` `milktoast` `tipsy` `choirboy`. The three names in bold don't match the preset they select. |
| `tract` | 200 / 0xc8 | `male` `female` `child` `giant` (0–3) | Vocal-tract size, which scales the formants and the pitch range. |
| `glot` | 210 / 0xd2 | `default` `male` `female` `child` `high` `mellow` `impulse` `odd` `colossus` (0–8) | Glottal source (voicing waveform). |
| `voicing` | 220 / 0xdc | `normal` `breathy` `whispered` (0–2) | Voicing mode. |
| `language` | 65 / 0x41 | `english` `spanish` `german` | Phonemes from here on use that language's tables. German was not shipped, and using it crashes the original. *(code)* |

#### Pitch and intonation

| Command | Code | Argument | Effect |
|---|---|---|---|
| `pitch`, `p` | 180 / 0xb4 | Hz, 10–2000 | Sets the base pitch from that phoneme on. In `sing` and held-pitch modes it sets that note's pitch directly. |
| *note* | 180 / 0xb4 | `{a0}` … `{g#8}`: letter a–g, optional `#`, octave 0–8 | A musical note: semitone index = voice octave × 12 + `{transpose}` + note, folded into the engine's note table (A4 = 440 Hz). Notes only take effect in `f0style sing` or the held-pitch mode; in normal speech they are computed and discarded. Verified: c4/e4/g4/c5 measure 262/334/394/525 Hz. |
| `f0style` | 240 / 0xf0 | `natural` `style2` `monotone` `sing` `random` (0–4) | Intonation mode. `natural`: rule-based intonation. `style2`: a different intonation contour (it changes the output, but the details aren't decoded). `monotone`: flat at the base pitch, which `{pitch}` can set. `sing`: pitch follows the notes and `{pitch}` values. `random` is actually a **held-pitch** mode: pitch stays wherever the last `{pitch}`/note put it, with no intonation. |
| `f0range` | 250 / 0xfa | 0–500 | Size of the intonation movements, as with `SVSetF0Range`. |
| `transpose` | 140 / 0x8c | semitones | Shifts the notes that follow it, so put it before the note: `{transpose 5; c4}`. |
| `perturb` | 260 / 0x104 | 0–500 | Pitch jitter. |

#### Timing

| Command | Code | Argument | Effect |
|---|---|---|---|
| *bare number* `{N}` | 40 / 0x28 | ms, or `N%` | Duration of the next phoneme in ms (several are added up). `{150%}` stretches it to 150% of its rule duration instead. |
| `pause` | 80 / 0x50 | ms, or `N%` | Same as a bare number. |
| `rate` | 190 / 0xbe | words per minute | Speaking rate from that point on. |
| `vfactor` | 310 / 0x136 | percent | Vowel duration factor (100 = normal). |
| `comma` | 90 / 0x5a | ms | Length of `,` pauses (default 200). |
| `dash` | 100 / 0x64 | ms | Length of `-` pauses (default 96). |
| `period` | 110 / 0x6e | ms | Length of `.`/`?` pauses (default 140). |
| `tempo` | 710 / 0x2c6 | beats per minute (≥ 20) | Stretches or squeezes the phonemes between `*` beat marks so that beats fall on this tempo (default 80). It has no effect without `*` marks. |

#### Modulation (vibrato and friends)

These four work together. `vibrato`, `tremelo` and `tonelo` set *how much*
each property is modulated. `mod` sets the overall modulation depth, which
is 0 by default, so **nothing happens until you set `{mod N}`**. The depth
ramps in at the `modramp` speed. All of these settings, and their state,
persist on the engine across utterances. *(code)*

| Command | Code | Argument | Effect |
|---|---|---|---|
| `mod` | 172 / 0xac | percent | Target modulation depth (default 0 = off). |
| `vibrato` | 160 / 0xa0 | amount | Pitch modulation. |
| `tremelo` | 162 / 0xa2 | amount | Loudness modulation (voicing and aspiration). |
| `tonelo` | 164 / 0xa4 | amount | Spectral-tilt (brightness) modulation. |
| `modrate` | 170 / 0xaa | speed | Modulation (LFO) rate (default 65). |
| `modramp` | 174 / 0xae | speed | How fast the depth moves towards `mod` (default 10). |

Example: `{mod 60; vibrato 40} AA5AA5AA5.`

#### Spectrum and amplitude

| Command | Code | Argument | Effect |
|---|---|---|---|
| `f1bias` `f2bias` `f3bias` | 500 / 510 / 520 | percent | Scale F1 / F2 / F3 frequencies (100 = normal). |
| `b1bias` `b2bias` `b3bias` | 550 / 560 / 570 | percent | Scale the B1 / B2 / B3 bandwidths. |
| `avbias` `ahbias` `afbias` | 370 / 380 / 390 | dB | Offset the voicing / aspiration / frication amplitude, like `SVSetAVBias` and friends. |
| `avspeed` `ahspeed` `afspeed` | 340 / 350 / 360 | 0–5 | Smoothing of the voicing / aspiration / frication amplitude tracks. |
| `tone` | 230 / 0xe6 | small integer | Offset added to every frame's spectral-tilt index (0–15). The presets use −4…6 (SVVOICEINFO +0x0e). |
| `articeff` | 320 / 0x140 | integer | Articulation effort. Formant targets are pushed (effort + 10) / 10 times their distance from a neutral vowel, so 0 is normal, negative values slur and positive values exaggerate. *(code; male tract)* |
| `articspd` | 330 / 0x14a | 0–5 | Smoothing of formant transitions. |

#### Sync events (no effect on the audio)

| Command | Code | Argument | Effect |
|---|---|---|---|
| `usync` | 850 / 0x352 | 0–255 | Posts an index sync message (1007) with this value when the phoneme starts. Verified: `/HEH5LOW {usync 7} WER5LD.` gives INDEX 7 at 0.405 s. |
| `wordsync` | 820 / 0x334 | number | Posts a word sync message (1003) with this value. This is what `@w<n>` generates. |

#### Accepted but without effect

These parse without error but change nothing in this build:

- `user` (60)
- `volume` (130)
- `embed` (120)
- `finetune` (150)
- `hoarse` (270)
- `f0up` (280)
- `f0down` (290)
- `diplo` (300)
- `f5bias` (540)
- `b4bias` (580)
- `b5bias` (590)
- `speak` (530; `natural` `word` `spell` `none`)
- the on/off switches `mouths` (800), `sentsync` (810), `syllsync` (830), `phonsync` (840) and `allsyncs` (860). Which sync messages you get depends on the `SVNarrate` flags instead (section 6).

`f4bias` is **unusable**: it shares code 530 with `speak`, so its number is
looked up in `speak`'s word list and always fails with 7015.

---

## 3. Phoneme codes

"Spelling" is what you type. "—" means the phoneme exists internally but
can't be typed: the rules or the allophone stage produce it. Formants (Hz)
and durations (ms, minimum–inherent) are the English male targets from
TIENG32. Spanish has its own values for many vowels and consonants.

### Pauses and marks

| Code | Spelling | Meaning |
|---|---|---|
| 0 | space | word boundary |
| 1 | `.` | sentence end (statement) |
| 2 | `?` | sentence end (question) |
| 3 | `,` | comma pause (default 200 ms) |
| 4 | `-` | dash pause (default 96 ms) |
| 5 / 6 | `(` / `)` | pitch-level marks (section 1) |
| 7 | `:` | short pause (60 ms) |
| 8 | — | INV: invalid (used after an error) |
| 94–103 | `0`–`9` | stress digits |
| 104 / 105 | `'` / `"` | stress 5 / stress 2 |
| 106 | `*` | beat mark (for `{tempo}`) |
| 107 | `@w<n>` | word sync marker |

### Vowels

| Code | Spelling | Example | F1/F2/F3 | Duration |
|---|---|---|---|---|
| 9 | `IY` | b**ee**t | 300/2300/2850 | 60–160 |
| 11 | `IH` | b**i**t | 400/1800/2670 | 60–150 |
| 13 | `EH` | b**e**t | 550/1800/2600 | 90–170 |
| 15 | `AE` | b**a**t | 620/1680/2500 | 80–230 |
| 17 | `AA` | f**a**ther | 700/1120/2600 | 100–240 |
| 18 | `AH` | b**u**t | 610/1300/2520 | 80–160 |
| 19 | `AO` | b**ou**ght | 600/1015/2700 | 100–240 |
| 21 | `UH` | b**oo**k | 450/1100/2350 | 60–160 |
| 23 | `AX` | **a**bout (schwa) | 550/1260/2470 | 50–110 |
| 24 | `IX` | ros**e**s | 420/1680/2520 | 50–100 |
| 25 | `ER` | b**ir**d | 515/1330/1700 | 80–180 |
| 31 | `EY` | b**ai**t | 550/1900/2620 | 100–190 |
| 33 | `AY` | b**i**te | 700/1300/2700 | 150–250 |
| 35 | `OY` | b**oy** | 550/940/2300 | 150–280 |
| 37 | `AW` | b**ou**t | 650/1250/2550 | 100–260 |
| 39 | `OW` | b**oa**t | 600/1100/2300 | 80–220 |
| 41 | `UW` | b**oo**t | 400/1280/2475 | 70–210 |
| 43 | — (`IYR`) | b**eer** | 320/1900/2700 | 100–230 |
| 45 | — (`EHR`) | b**ear** | 460/1770/2450 | 130–270 |
| 47 | — (`AAR`) | b**ar** | 690/1100/2425 | 140–255 |
| 49 | — (`OWR`) | b**oar** | 450/760/2200 | 130–240 |
| 51 | — (`UWR`) | p**oor** | 360/800/2000 | 110–230 |
| 58 | — | YU (c**u**te) | 290/1900/2600 | 150–230 |
| 92 | `OH` | Spanish **o** | Spanish 550/1000/2725 | 75–120 |

The codes not listed between 10 and 52 (IY', IH', EY', … UXR') are the
second targets of diphthongs and long vowels. They're stored in the record
after the vowel, are internal, and can't be typed.

### Syllabic consonants and others

| Code | Spelling | Example | Notes |
|---|---|---|---|
| 86 | `UL` | bott**le** | 450/800/2850, 110–255 |
| 87 | `UM` | rhyth**m** | 200/900/2100, 140–200 |
| 88 | `UN` | butt**on** | 200/1600/2700, 130–200 |
| 89–91 | `IL` `IM` `IN` | — | Empty table entries (no formants or duration). English accepts them; **in Spanish they crash the original** (division by zero), and the port panics the same way. |
| 27 | `QX` | — | silent vowel slot used by the rules |
| 28 | — | AXP | internal |

### Consonants

| Code | Spelling | Example | Kind |
|---|---|---|---|
| 54 | `R` | **r**ed | liquid |
| 55 | `L` | **l**et | liquid |
| 29 | `RX` | ca**r** | post-vocalic r |
| 30 | `LX` | ba**ll** | dark l |
| 56 | `W` | **w**et | glide |
| 53 | `WH` | **wh**ich | glide (voiceless) |
| 57 | `Y` | **y**et | glide |
| 60 | `M` | **m**et | nasal |
| 61 | `N` | **n**et | nasal |
| 62 | `NX` | si**ng** | nasal |
| 77 | `B` | **b**et | voiced stop |
| 78 | `D` | **d**ebt | voiced stop |
| 79 | `G` | **g**et | voiced stop |
| 80 | `GX` | **g**o | voiced stop, back allophone |
| 81 | `P` | **p**et | voiceless stop |
| 82 | `T` | **t**en | voiceless stop |
| 84 | `K` | **k**it | voiceless stop |
| 85 | `KX` | **c**oat | voiceless stop, back allophone |
| 63 | `DX` | bu**tt**er | flap |
| 64 | `Q` | uh**-**oh | glottal stop |
| 83 | — | TQ | glottalized t (allophone rules) |
| 73 | `CH` | **ch**ip | affricate |
| 74 | `J` | **j**ump | affricate |
| 65 | `S` | **s**it | fricative |
| 69 | `Z` | **z**oo | fricative |
| 66 | `SH` | **sh**ip | fricative |
| 70 | `ZH` | mea**s**ure | fricative |
| 67 | `F` | **f**it | fricative |
| 71 | `V` | **v**at | fricative |
| 68 | `TH` | **th**in | fricative |
| 72 | `DH` | **th**en | fricative |
| 75 | `/H` or `HH` | **h**at | aspirate (a lone `H` is an error) |
| 76 | — | HX | voiced h (allophone) |
| 108 | `R~` | Spanish pe**rr**o | trill |
| 93 | `/C` | — | empty entry (German *ch*) |

Spellings `C` and `CX` (codes 114 and 115) are accepted but lie past the end
of the phoneme tables. They're leftovers for the German module, so don't use
them. `IW` `EW` `EO` `OE` (codes 110–113) give error 7001.

---

## 4. Error codes

Every API function returns 0 or one of these codes. waveOut failures come
back as 7600 + the MMRESULT.

| Code | Meaning |
|---|---|
| 7001 | Phoneme code error (bad spelling, or a stress digit after a non-vowel) |
| 7002 | Can't allocate memory |
| 7003–7008 | Internal errors (COEF memory, wave header/data, lock, waveOutPrepareHeader, waveOutWrite) |
| 7009 | Invalid speech engine handle |
| 7010 | Parameter out of range |
| 7011 | No waveOut devices installed |
| 7012 | Audio format not supported (11025 Hz 8-bit mono) |
| 7013 | Can't open waveOut device |
| 7014 | Speech device busy (`SVNarrate` while speaking, without flag 0x20) |
| 7015 | Embedded command error (bad `{...}`) |
| 7016 | Override abort failed |
| 7017 | Internal error: can't create window |
| 7018 / 7019 / 7020 | User dictionary: can't open / premature EOF / format error |
| 7021 | Evaluation period expired (demo builds; never fires here) |
| 7022 | Specified language is not supported (module missing) |
| 7023 | Can't allocate the Windows timer |
| 7024 | Invalid address (NULL pointer) |
| 7025 | Error index out of range (`SVGetErrorText`) |

`SVTextToPhon` also returns **−(n+1)** when its output buffer filled up after
*n* input characters. Note that resuming at *n* skips one word. Input longer
than 514 characters gives an empty string and returns 0.

---

## 5. Sync messages

Register a window message with `RegisterWindowMessage("SVSyncMessages")`.
`wParam` holds the code and `lParam` points to an SVSYNC structure (see
`sdk/softvoice.h`). The Rust `Engine` returns the same codes as events with
sample positions.

| Code | Name | Value (`wValue`) | When |
|---|---|---|---|
| 1000 | START | — | the utterance starts |
| 1001 | DONE | error code (0 = ok) | the utterance ended |
| 1002 | PLAYING | — | each sentence (phrase) starts |
| 1003 | WORD | character offset from `@w<n>` | a word starts |
| 1004 | — | phoneme | stressed vowels (`SVNarrate` flag 0x01) |
| 1005 | — | phoneme | stressed vowels (flag 0x02) |
| 1006 | PHONEME | internal phoneme code | each phoneme (flag 0x04) |
| 1007 | INDEX | `{usync}` value | a phoneme with `{usync N}` starts |
| 1008 | MOUTH | mouth shape 1–9 | the mouth shape changes (flag 0x08) |

---

## 6. Flags

### `SVNarrate` flags

| Bit | Meaning |
|---|---|
| 0x01 | send 1004 events |
| 0x02 | send 1005 events |
| 0x04 | send PHONEME (1006) events |
| 0x08 | send MOUTH (1008) events |
| 0x10 | set by `SVSetSpeakingMode(2)` (spell); no audible effect found |
| 0x20 | override: abort the current utterance instead of returning 7014 |
| 0x40 | no sync timer: only START, PLAYING and DONE are posted |
| 0x20000000…0x80000000 | internal (buffer ownership, first-phrase marker) |

### `SVTextToPhon` flags

These were established by the text-to-phoneme port, which matches the
original exactly on 33,262 cases.

| Bit | Meaning |
|---|---|
| 0x02 | always assign default stress, and let IX/AX take stress |
| 0x04 | **spell mode**: spell the text letter by letter, and keep `]` |
| 0x08 | insert `@w<offset>` word markers (needed for WORD events) |
| 0x10 | also mark words that start with a `{` command |
| 0x40 | turn off the `?` fix-up |

Talk It! itself uses 0x18.

---

## 7. Voice settings (SVVOICEINFO and the setters)

| Setting | Values |
|---|---|
| Gender (`SVSetGender`, `{tract}`) | 0 male, 1 female, 2 child, 3 giant |
| Glottal source (`SVSetGlottalSource`, `{glot}`) | 0 default, 1 male, 2 female, 3 child, 4 high, 5 mellow, 6 impulse, 7 odd, 8 colossus |
| Voicing (`SVSetVoicingMode`, `{voicing}`) | 0 normal, 1 breathy, 2 whispered |
| F0 style (`SVSetF0Style`, `{f0style}`) | 0 natural, 1 style2, 2 monotone, 3 sing, 4 held ("random") |
| Presets (`SVSetPersonality`) | 0 Male, 1 Female, 2 Fast Female, 3 Child, 4 Giant Male, 5 Mellow Female, 6 Choir Girl, 7 Amazon, 8 The Fly, 9 Robotoid, 10 Martian, 11 Colossus, 12 Fast Fred, 13 Old Woman, 14 Munchkin, 15 Troll, 16 Nerd, 17 Milktoast, 18 Tipsy, 19 Choir Boy |

Two SVVOICEINFO fields that `sdk/softvoice.h` lists as unknown are now
identified:
- **+0x0e** is the voice's `{tone}` (tilt offset).
- **+0x48** is its singing octave offset, which is added to `{c4}`-style notes.
