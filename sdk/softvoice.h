/*
 * softvoice.h - reconstructed API for the SoftVoice TTS engine shipped with
 *               Microsoft Plus! for Kids "Talk It!" (TIBASE32.DLL 1.0.0.1117,
 *               built 1996-11-18; SVGetVersionInfo reports "August 30, 1996").
 *
 * Reverse engineered from TIBASE32.DLL / TIENG32.DLL / TISPAN32.DLL and from
 * the call sites in TalkIt!.exe.  Not an official header.
 *
 * Full reference for phoneme codes, {commands}, error/sync codes and flags:
 * docs/codes.md.
 *
 * Confidence markers used below:
 *   (verified)  - observed in the code and exercised by svsay.c
 *   (code)      - read directly from the disassembly, not exercised
 *   (guess)     - inferred from names/values; treat with suspicion
 *
 * General notes
 *   - All exports are __stdcall, 32-bit x86 only.  Link against tibase32.lib
 *     built from tibase32.def (see build.cmd).
 *   - TIBASE32 loads the language DLLs (TIENG32 / TISPAN32 / TIGERM32) itself
 *     with LoadLibrary, so they must be on the DLL search path.  TIGERM32 was
 *     not shipped with Talk It!.
 *   - Imports MSVCRT40.DLL (still present in SysWOW64 on current Windows).
 *   - Audio: 11025 Hz, 8-bit, mono PCM through waveOut.
 *   - Playback is asynchronous and driven by window messages (the engine owns
 *     a hidden "NarratorClass" window that receives MM_WOM_DONE), so the
 *     thread that calls SVNarrate/SVTTS must pump messages until it receives
 *     SV_SYNC_DONE.
 *   - Only one utterance may be in flight at a time, process-wide.
 *   - Every function returns 0 on success or an SVERR_* code (7000-7025).
 *     waveOut failures are returned as MMRESULT + 7600 (0x1DB0).
 */
#ifndef SOFTVOICE_H
#define SOFTVOICE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SVAPI __stdcall

typedef struct SVENGINE *HSV;   /* opaque, 0x5A8-byte context allocated by SVOpenSpeech */

/* ------------------------------------------------------------------------ */
/* Error codes (text via SVGetErrorText)                              (code) */
/* ------------------------------------------------------------------------ */
#define SVERR_OK                    0
#define SVERR_PHONEME_CODE          7001  /* "Phoneme code error" */
#define SVERR_NO_MEMORY             7002
#define SVERR_COEF_MEMORY           7003
#define SVERR_WAVE_HEADER_ALLOC     7004
#define SVERR_WAVE_DATA_ALLOC       7005
#define SVERR_LOCK                  7006
#define SVERR_WAVE_PREPARE          7007
#define SVERR_WAVE_WRITE            7008
#define SVERR_INVALID_HANDLE        7009
#define SVERR_PARAM_RANGE           7010
#define SVERR_NO_WAVE_DEVICE        7011
#define SVERR_AUDIO_FORMAT          7012  /* 11025/8/mono rejected by device */
#define SVERR_WAVE_OPEN             7013
#define SVERR_BUSY                  7014  /* already speaking, SV_NARRATE_OVERRIDE not given */
#define SVERR_EMBEDDED_COMMAND      7015  /* bad {...} command, returned by SVNarrate (verified) */
#define SVERR_OVERRIDE_FAILED       7016
#define SVERR_CREATE_WINDOW         7017
#define SVERR_DICT_OPEN             7018
#define SVERR_DICT_EOF              7019
#define SVERR_DICT_FORMAT           7020
#define SVERR_EVAL_EXPIRED          7021  /* demo builds only */
#define SVERR_LANGUAGE              7022  /* language DLL missing / not loaded */
#define SVERR_TIMER                 7023  /* timeBeginPeriod / timeSetEvent failed */
#define SVERR_INVALID_ADDRESS       7024  /* NULL pointer argument */
#define SVERR_ERROR_INDEX           7025
#define SVERR_MMSYSTEM_BASE         7600  /* + MMRESULT from waveOut* */

/* ------------------------------------------------------------------------ */
/* Languages: bit mask for SVOpenSpeech, single value for SVSetLanguage       */
/* ------------------------------------------------------------------------ */
#define SV_LANG_ENGLISH   1   /* TIENG32.DLL  (verified) */
#define SV_LANG_SPANISH   2   /* TISPAN32.DLL (verified) */
#define SV_LANG_GERMAN    4   /* TIGERM32.DLL (not shipped) */
#define SV_LANG_ALL       7

/* ------------------------------------------------------------------------ */
/* Engine lifetime                                                            */
/* ------------------------------------------------------------------------ */

/*
 * Open an engine instance.                                       (verified)
 *   phsv        receives the handle (NULL on failure)
 *   hwndNotify  default window for sync messages (SVNarrate replaces it)
 *   uWaveDevice waveOut device id, WAVE_MAPPER (-1) for the default
 *   dwLanguages SV_LANG_* mask; 0 means English only.  The first available
 *               language in the order English, Spanish, German becomes
 *               current.
 *   dwReserved  0
 * If some but not all requested languages load, the handle is valid and the
 * function still returns SVERR_LANGUAGE.  TalkIt!.exe passes SV_LANG_ALL and
 * treats SVERR_LANGUAGE as success.
 */
DWORD SVAPI SVOpenSpeech(HSV *phsv, HWND hwndNotify, UINT uWaveDevice,
                         DWORD dwLanguages, DWORD dwReserved);

/* Also frees the language DLLs and any user dictionary.            (code) */
DWORD SVAPI SVCloseSpeech(HSV hsv);

/* *pdwLanguages = SV_LANG_* mask of the language DLLs that loaded. (verified) */
DWORD SVAPI SVGetAvailableLanguages(HSV hsv, DWORD *pdwLanguages);

/* lang = exactly one SV_LANG_* value.                              (verified) */
DWORD SVAPI SVSetLanguage(HSV hsv, DWORD lang);

typedef struct SVVERSIONINFO {
    DWORD  dwVersion;      /* 0x00020001 */
    LPCSTR pszCompany;     /* "Microsoft Corporation - TalkIt" ... */
    LPCSTR pszDate;        /* "August 30, 1996" */
    WORD   wVoiceInfoSize; /* sizeof(SVVOICEINFO) = 0x6A */
} SVVERSIONINFO;

/* No handle needed.                                                (verified) */
DWORD SVAPI SVGetVersionInfo(SVVERSIONINFO *pInfo);

/* Copy the message for an SVERR_* code into buf (cch includes NUL). No handle.
 * Returns SVERR_PARAM_RANGE for unknown codes.                     (verified) */
DWORD SVAPI SVGetErrorText(DWORD err, LPSTR buf, WORD cch);

/* ------------------------------------------------------------------------ */
/* Speaking                                                                   */
/* ------------------------------------------------------------------------ */

/* SVTextToPhon flags                                                         */
#define SV_TTP_STRESS_ALL     0x02  /* always assign default stress; IX/AX
                                       become stressable       (verified, port) */
#define SV_TTP_SPELL          0x04  /* spell mode (letter by letter); also keeps
                                       ']'; SVTTS sizes its buffer for 6 instead
                                       of 3 bytes per input char (verified, port) */
#define SV_TTP_KEEP_BRACKET   SV_TTP_SPELL  /* old name */
#define SV_TTP_WORD_MARKERS   0x08  /* insert " @w<offset> " before each word
                                       (offset = char index in the source
                                       text) so that SV_SYNC_WORD fires
                                       during playback          (verified) */
#define SV_TTP_MARK_BRACES    0x10  /* also mark words that start an embedded
                                       '{' command (TalkIt! uses 0x18)  (code) */
#define SV_TTP_NO_QUESTION_FIX 0x40 /* disable the '?' fix-up  (verified, port) */

/*
 * Convert text to a SoftVoice phoneme string using the current language's
 * letter-to-sound rules.                                           (verified)
 *   pszText   input, Latin-1.  Letters are upper-cased; most punctuation that
 *             is not meaningful becomes a space.  Embedded {commands} pass
 *             through.
 *   pszPhon   output buffer, NUL-terminated
 *   cbPhon    size of pszPhon in bytes (TalkIt! uses 0x2800)
 *   dwFlags   SV_TTP_*
 * Returns 0 when everything was converted, an SVERR_* code on error, or a
 * negative value -(n + 1) when pszPhon filled up after n input characters had
 * been consumed (continue from pszText + n with a fresh buffer).
 */
LONG  SVAPI SVTextToPhon(HSV hsv, LPCSTR pszText, LPSTR pszPhon, LONG cbPhon,
                         DWORD dwFlags, DWORD dwReserved);

/* SVNarrate flags.  The low byte selects which optional sync messages are
 * generated; SV_SYNC_START, SV_SYNC_DONE, SV_SYNC_PLAYING, SV_SYNC_WORD and
 * SV_SYNC_INDEX are always sent.                                             */
#define SV_NARRATE_SYNC_1004   0x01  /* enable SV_SYNC_1004          (verified) */
#define SV_NARRATE_SYNC_1005   0x02  /* enable SV_SYNC_1005          (verified) */
#define SV_NARRATE_SYNC_PHON   0x04  /* enable SV_SYNC_PHONEME       (verified) */
#define SV_NARRATE_SYNC_MOUTH  0x08  /* enable SV_SYNC_MOUTH         (verified) */
#define SV_NARRATE_SPELL       0x10  /* same bit SVSetSpeakingMode(2) sets (guess) */
#define SV_NARRATE_OVERRIDE    0x20  /* abort the current utterance instead of
                                        failing with SVERR_BUSY       (code) */
#define SV_NARRATE_NO_SYNC     0x40  /* no sync timer at all: only START,
                                        PLAYING and DONE are posted     (code) */
/* Bits 0x20000000..0x80000000 are internal (buffer ownership, first-buffer
 * flag) and are overwritten by the DLL.                                      */

/*
 * Speak a phoneme string (the output of SVTextToPhon, or hand-written).
 * Asynchronous: returns once the first two 4 KB audio buffers are queued.
 *   pszPhon     phonemes; must stay valid until SV_SYNC_DONE.  Caller keeps
 *               ownership.
 *   hwndNotify  receives the SVSyncMessages registered message (may differ
 *               from the hwnd passed to SVOpenSpeech)
 *   dwFlags     SV_NARRATE_*
 * An empty string just posts START, PLAYING and DONE.             (verified)
 */
DWORD SVAPI SVNarrate(HSV hsv, LPCSTR pszPhon, HWND hwndNotify,
                      DWORD dwFlags, DWORD dwReserved);

/* SVTTS extra flag (in dwTtpFlags) */
#define SV_TTS_RETURN_PHONEMES 0x80  /* hand the phoneme string back       (code) */

/*
 * Text-to-speech in one call: SVTextToPhon (growing the buffer as needed),
 * then SVNarrate.                                                  (verified)
 *   ppszPhon, pcchPhon  only used with SV_TTS_RETURN_PHONEMES: receive the
 *               phoneme string the engine is speaking and its length.  That
 *               buffer is calloc'ed from MSVCRT40.DLL and is NOT freed by the
 *               engine in this mode.  The caller must free it with
 *               MSVCRT40's free(), after SV_SYNC_DONE.  Without the flag the
 *               engine frees its own copy when speech ends.  Pass NULL for
 *               both when the flag is not set.
 *   dwTtpFlags  SV_TTP_* | SV_TTS_RETURN_PHONEMES
 *   dwNarrateFlags SV_NARRATE_*
 */
DWORD SVAPI SVTTS(HSV hsv, LPCSTR pszText, LPSTR *ppszPhon, LONG *pcchPhon,
                  HWND hwndNotify, DWORD dwTtpFlags, DWORD dwNarrateFlags,
                  DWORD dwReserved);

/* Stop speech; pumps messages until the engine is idle.            (code) */
DWORD SVAPI SVAbort(HSV hsv);
/* waveOutPause / waveOutRestart while speaking.                    (code) */
DWORD SVAPI SVPause(HSV hsv);
DWORD SVAPI SVResume(HSV hsv);

/* ------------------------------------------------------------------------ */
/* Sync messages                                                              */
/* ------------------------------------------------------------------------ */
/* Register with RegisterWindowMessageA(SV_SYNC_MESSAGE_NAME).  wParam is one
 * of SV_SYNC_*, lParam points to an SVSYNC that is reused by the engine, so
 * copy what you need before returning.                                       */
#define SV_SYNC_MESSAGE_NAME "SVSyncMessages"

#define SV_SYNC_START    1000  /* utterance started                   (verified) */
#define SV_SYNC_DONE     1001  /* finished; wValue = error code (0 = ok) (verified) */
#define SV_SYNC_PLAYING  1002  /* a phrase/sentence chunk started      (verified) */
#define SV_SYNC_WORD     1003  /* wValue = char offset of the word in
                                  the text given to SVTextToPhon
                                  (needs SV_TTP_WORD_MARKERS)       (verified) */
#define SV_SYNC_1004     1004  /* flag 0x01; fires at stressed vowels,
                                  same value as SV_SYNC_PHONEME  (verified; meaning guessed:
                                  syllable sync) */
#define SV_SYNC_1005     1005  /* flag 0x02; fired alongside 1004 in tests
                                  (meaning guessed: stress sync)  (verified) */
#define SV_SYNC_PHONEME  1006  /* flag 0x04; wValue = internal phoneme
                                  number                         (verified) */
#define SV_SYNC_INDEX    1007  /* wValue = embedded index marker value (guess) */
#define SV_SYNC_MOUTH    1008  /* flag 0x08; wValue = mouth shape id 1..9,
                                  sent when it changes (lip-sync)  (verified) */

typedef struct SVSYNC {
    HSV    hsv;          /* 0x00 engine that sent it */
    DWORD  dwTime;       /* 0x04 timeGetTime() at which the event is due;
                                 ring events are released by a 10 ms
                                 timer when this time passes   (verified) */
    WORD   wCode;        /* 0x08 same as wParam (ring events only)            */
    WORD   wValue;       /* 0x0A event value / SV_SYNC_DONE error code        */
    DWORD  dwValue;      /* 0x0C wider form of wValue                          */
    LPCSTR pszPhon;      /* 0x10 phoneme string being spoken                   */
    DWORD  dwPosition;   /* 0x14 internal position counter            (guess)  */
    DWORD  dwReserved[2];/* 0x18                                                */
} SVSYNC;                /* 0x20 bytes */

/* ------------------------------------------------------------------------ */
/* Voice                                                                      */
/* ------------------------------------------------------------------------ */
#define SV_GENDER_MALE    0
#define SV_GENDER_FEMALE  1   /* also selects the language's female formant table */
#define SV_GENDER_CHILD   2
#define SV_GENDER_GIANT   3

/* Glottal source 0..8, names from the {glot ...} keyword table      (code) */
#define SV_GLOT_DEFAULT   0
#define SV_GLOT_MALE      1
#define SV_GLOT_FEMALE    2
#define SV_GLOT_CHILD     3
#define SV_GLOT_HIGH      4
#define SV_GLOT_MELLOW    5
#define SV_GLOT_IMPULSE   6
#define SV_GLOT_ODD       7
#define SV_GLOT_COLOSSUS  8

/* Voicing mode 0..2 ({voicing ...})                                 (code) */
#define SV_VOICING_NORMAL     0
#define SV_VOICING_BREATHY    1
#define SV_VOICING_WHISPERED  2

/* F0 (intonation) style 0..4 ({f0style ...})                        (code) */
#define SV_F0_NATURAL   0
#define SV_F0_STYLE2    1
#define SV_F0_MONOTONE  2
#define SV_F0_SING      3
#define SV_F0_RANDOM    4   /* actually "held pitch": no intonation, pitch stays
                               where the last {pitch}/note put it      */

/* Built-in personalities for SVSetPersonality / SVGetVoiceInfo  (verified) */
enum {
    SV_VOICE_MALE, SV_VOICE_FEMALE, SV_VOICE_FAST_FEMALE, SV_VOICE_CHILD,
    SV_VOICE_GIANT_MALE, SV_VOICE_MELLOW_FEMALE, SV_VOICE_CHOIR_GIRL,
    SV_VOICE_AMAZON, SV_VOICE_THE_FLY, SV_VOICE_ROBOTOID, SV_VOICE_MARTIAN,
    SV_VOICE_COLOSSUS, SV_VOICE_FAST_FRED, SV_VOICE_OLD_WOMAN,
    SV_VOICE_MUNCHKIN, SV_VOICE_TROLL, SV_VOICE_NERD, SV_VOICE_MILKTOAST,
    SV_VOICE_TIPSY, SV_VOICE_CHOIR_BOY,
    SV_VOICE_COUNT                    /* 20 */
};
#define SV_VOICE_CURRENT 0xFF         /* SVGetVoiceInfo: the live settings */

#pragma pack(push, 2)
typedef struct SVVOICEINFO {
    LPSTR pszName;          /* 0x00 points at szName (or at the engine's copy) */
    WORD  wPitch;           /* 0x04 10..2000, base F0 in Hz (male 100)         */
    WORD  wRate;            /* 0x06 20..500, words/min (default 150)           */
    WORD  wGender;          /* 0x08 SV_GENDER_*                                */
    WORD  wGlottalSource;   /* 0x0A SV_GLOT_*                                  */
    WORD  wVoicingMode;     /* 0x0C SV_VOICING_*                               */
    SHORT sTone;            /* 0x0E spectral-tilt offset ({tone}), -4..6 in
                                    presets                              (code) */
    WORD  wF0Style;         /* 0x10 SV_F0_*                                    */
    WORD  wF0Range;         /* 0x12 0..500, intonation range                   */
    WORD  wF0Perturb;       /* 0x14 0..500, pitch jitter                       */
    WORD  wUnknown16;       /* 0x16 always 0, not used by the synth            */
    WORD  wUnknown18;       /* 0x18 50..125                            (?)     */
    WORD  wUnknown1A;       /* 0x1A always equals wUnknown18           (?)     */
    WORD  wUnknown1C;       /* 0x1C 0                                          */
    WORD  wUnknown1E;       /* 0x1E 25                                         */
    WORD  wUnknown20;       /* 0x20 110                                        */
    WORD  wVowelFactor;     /* 0x22 percent, vowel duration (100 = normal)     */
    WORD  wUnknown24;       /* 0x24 0                                          */
    WORD  wUnknown26;       /* 0x26 0                                          */
    SHORT sAVBias;          /* 0x28 voicing amplitude offset, dB  (SVSetAVBias) */
    SHORT sAHBias;          /* 0x2A aspiration amplitude offset   (SVSetAHBias) */
    SHORT sAFBias;          /* 0x2C frication amplitude offset    (SVSetAFBias) */
    SHORT sAVSpeed;         /* 0x2E 0 in presets                      (guess)  */
    SHORT sAHSpeed;         /* 0x30                                    (guess)  */
    SHORT sAFSpeed;         /* 0x32                                    (guess)  */
    WORD  wFormantScale[6]; /* 0x34 percent, 100 = neutral; probably F1-F3
                                    frequency and bandwidth scaling     (guess) */
    WORD  wF4;              /* 0x40 Hz (male 3600, female 4200)        (guess)  */
    WORD  wB4;              /* 0x42 Hz                                 (guess)  */
    WORD  wF5;              /* 0x44 Hz                                 (guess)  */
    WORD  wB5;              /* 0x46 Hz                                 (guess)  */
    SHORT sOctave;          /* 0x48 singing octave offset added to {c4}-style
                                    notes, -1..2 in presets              (code) */
    CHAR  szName[32];       /* 0x4A                                            */
} SVVOICEINFO;              /* 0x6A bytes */
#pragma pack(pop)

/*
 * Read a preset (0..19) or SV_VOICE_CURRENT.  cbSize must be
 * sizeof(SVVOICEINFO) to get the name; any other value copies only the
 * numeric fields.                                                 (verified)
 */
DWORD SVAPI SVGetVoiceInfo(HSV hsv, WORD wVoice, SVVOICEINFO *pInfo, WORD cbSize);
/* Validate and apply a whole voice.  The name is only copied when cbSize is
 * sizeof(SVVOICEINFO).                                              (code) */
DWORD SVAPI SVSetVoiceInfo(HSV hsv, const SVVOICEINFO *pInfo, WORD cbSize);
/* Load preset 0..19 into the live voice.                          (verified) */
DWORD SVAPI SVSetPersonality(HSV hsv, WORD wVoice);

/* Individual setters.  Range-checked ones return SVERR_PARAM_RANGE.
 * Values take effect at the next SVNarrate/SVTTS.                           */
DWORD SVAPI SVSetPitch(HSV hsv, WORD wHz);            /* 10..2000  (verified) */
DWORD SVAPI SVSetRate(HSV hsv, WORD wWpm);            /* 20..500   (verified) */
DWORD SVAPI SVSetGender(HSV hsv, WORD wGender);       /* 0..3      (code) */
DWORD SVAPI SVSetGlottalSource(HSV hsv, WORD wGlot);  /* 0..8      (code) */
DWORD SVAPI SVSetVoicingMode(HSV hsv, WORD wMode);    /* 0..2      (code) */
DWORD SVAPI SVSetF0Style(HSV hsv, WORD wStyle);       /* 0..4      (code) */
DWORD SVAPI SVSetF0Range(HSV hsv, WORD wRange);       /* 0..500    (code) */
DWORD SVAPI SVSetF0Perturb(HSV hsv, WORD wPerturb);   /* 0..500    (code) */
DWORD SVAPI SVSetVowelFactor(HSV hsv, SHORT s);       /* unchecked (code) */
DWORD SVAPI SVSetAVBias(HSV hsv, SHORT s);            /* unchecked (code) */
DWORD SVAPI SVSetAHBias(HSV hsv, SHORT s);            /* unchecked (code) */
DWORD SVAPI SVSetAFBias(HSV hsv, SHORT s);            /* unchecked (code) */

/* Speaking mode: wMode & 7 must be non-zero.  Bit 2 sets the internal
 * SV_NARRATE_SPELL flag, any other value clears it.  Probably 1 = normal,
 * 2 = spell out letters.                                            (guess) */
DWORD SVAPI SVSetSpeakingMode(HSV hsv, WORD wMode);

/* ------------------------------------------------------------------------ */
/* User dictionary                                                            */
/* ------------------------------------------------------------------------ */
/* Binary file starting with the magic "SVXF", followed by 5 DWORDs
 * (skipped), the entry count, the data size, a 28-DWORD index, then the
 * data.  The authoring format is unknown.                            (code) */
DWORD SVAPI SVLoadUserDictionary(HSV hsv, LPCSTR pszPath);
DWORD SVAPI SVUnloadUserDictionary(HSV hsv, DWORD dwReserved);

/* ------------------------------------------------------------------------ */
/* Phoneme string format (input to SVNarrate)                                 */
/* ------------------------------------------------------------------------ */
/*
 * See docs/codes.md for the complete reference.  In short:
 *   - space-separated words of phoneme codes (IY IH EH AE AA AH AO UH AX IX
 *     ER EY AY OY AW OW UW, R L RX LX W WH Y M N NX, P B T D K G KX GX DX Q,
 *     F V TH DH S Z SH ZH CH J, /H (= HH), UL UM UN; Spanish OH R~), a stress
 *     digit after vowels; English turns vowel + R into IXR/EXR/AXR/OXR/UXR.
 *   - . ? end sentences, , - : pause, ( ) pitch-level marks, * beat,
 *     @w<n> word-sync marker.
 *   - {cmd arg [pos]; ...} embedded commands, e.g. {voice robotoid},
 *     {pitch 150}, {rate 200}, {f0style sing; c4}, {mod 60; vibrato 40},
 *     {200} (duration of the next phoneme in ms), {usync 7}.  Several
 *     keywords parse but have no effect, and {f4bias} can never parse (it
 *     shares its code with {speak}).
 */

#ifdef __cplusplus
}
#endif
#endif /* SOFTVOICE_H */
