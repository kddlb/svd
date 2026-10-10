/*
 * svsay - drive the SoftVoice (Talk It!) engine through softvoice.h.
 *
 *   svsay [options] text...
 *     -l en|es     language (default en)
 *     -v N         personality preset 0..19
 *     -r WPM       rate 20..500
 *     -p HZ        pitch 10..2000
 *     -P           text is already a phoneme string (SVNarrate directly)
 *     -t           use SVTTS instead of SVTextToPhon + SVNarrate
 *     -n           convert only: print phonemes, do not speak
 *     -w FILE      also write the audio to FILE (.wav, 11025 Hz 8-bit mono)
 *     -f FLAGS     SV_NARRATE_* flags for SVNarrate/SVTTS (e.g. 0x0f)
 *     -s           print every sync message
 *     --info       print version, languages and the 20 voice presets
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "softvoice.h"

static UINT   g_syncMsg;
static FILE  *g_wav;
static DWORD  g_wavBytes;
static int    g_verbose;
static const char *g_text;      /* source text, for word-sync display */
static DWORD  g_doneErr;

/* ---- WAV capture: hook TIBASE32's import of waveOutWrite ---------------- */

typedef MMRESULT (WINAPI *PFN_waveOutWrite)(HWAVEOUT, LPWAVEHDR, UINT);
static PFN_waveOutWrite g_realWaveOutWrite;

static MMRESULT WINAPI HookWaveOutWrite(HWAVEOUT hwo, LPWAVEHDR hdr, UINT cb)
{
    if (g_wav && hdr && hdr->lpData) {
        fwrite(hdr->lpData, 1, hdr->dwBufferLength, g_wav);
        g_wavBytes += hdr->dwBufferLength;
    }
    return g_realWaveOutWrite(hwo, hdr, cb);
}

static int HookImport(HMODULE mod, const char *dll, const char *fn, void *hook, void **orig)
{
    BYTE *base = (BYTE *)mod;
    IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)(base + ((IMAGE_DOS_HEADER *)base)->e_lfanew);
    IMAGE_DATA_DIRECTORY dir = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    IMAGE_IMPORT_DESCRIPTOR *imp = (IMAGE_IMPORT_DESCRIPTOR *)(base + dir.VirtualAddress);
    for (; imp->Name; imp++) {
        if (_stricmp((char *)(base + imp->Name), dll) != 0)
            continue;
        IMAGE_THUNK_DATA *names = (IMAGE_THUNK_DATA *)(base + imp->OriginalFirstThunk);
        IMAGE_THUNK_DATA *iat = (IMAGE_THUNK_DATA *)(base + imp->FirstThunk);
        for (; names->u1.AddressOfData; names++, iat++) {
            if (IMAGE_SNAP_BY_ORDINAL(names->u1.Ordinal))
                continue;
            IMAGE_IMPORT_BY_NAME *ibn = (IMAGE_IMPORT_BY_NAME *)(base + names->u1.AddressOfData);
            if (strcmp((char *)ibn->Name, fn) == 0) {
                DWORD old;
                VirtualProtect(&iat->u1.Function, sizeof(void *), PAGE_READWRITE, &old);
                *orig = (void *)iat->u1.Function;
                iat->u1.Function = (DWORD)(DWORD_PTR)hook;
                VirtualProtect(&iat->u1.Function, sizeof(void *), old, &old);
                return 1;
            }
        }
    }
    return 0;
}

static void WriteWavHeader(FILE *f, DWORD dataBytes)
{
    struct {
        char riff[4]; DWORD size; char wave[4];
        char fmt[4]; DWORD fmtSize; WORD tag, ch; DWORD rate, bps; WORD align, bits;
        char data[4]; DWORD dataSize;
    } h = { {'R','I','F','F'}, 36 + dataBytes, {'W','A','V','E'},
            {'f','m','t',' '}, 16, 1, 1, 11025, 11025, 1, 8,
            {'d','a','t','a'}, dataBytes };
    fseek(f, 0, SEEK_SET);
    fwrite(&h, sizeof h, 1, f);
}

/* ---- notification window ----------------------------------------------- */

static const char *SyncName(WPARAM w)
{
    switch (w) {
    case SV_SYNC_START:   return "START";
    case SV_SYNC_DONE:    return "DONE";
    case SV_SYNC_PLAYING: return "PLAYING";
    case SV_SYNC_WORD:    return "WORD";
    case SV_SYNC_1004:    return "1004";
    case SV_SYNC_1005:    return "1005";
    case SV_SYNC_PHONEME: return "PHONEME";
    case SV_SYNC_INDEX:   return "INDEX";
    case SV_SYNC_MOUTH:   return "MOUTH";
    default:              return "?";
    }
}

static LRESULT CALLBACK NotifyProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    if (msg == g_syncMsg && msg != 0) {
        const SVSYNC *s = (const SVSYNC *)lp;
        if (g_verbose) {
            printf("  sync %-7s (%u) time=%lu value=%u", SyncName(wp), (unsigned)wp,
                   (unsigned long)s->dwTime, s->wValue);
            if (wp == SV_SYNC_WORD && g_text) {
                const char *w = g_text + s->wValue;
                int n = 0;
                while (w[n] && w[n] != ' ') n++;
                printf("  \"%.*s\"", n, w);
            }
            printf("\n");
        }
        if (wp == SV_SYNC_DONE) {
            g_doneErr = s->wValue;
            PostQuitMessage(0);
        }
        return 0;
    }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

/* ---- helpers ------------------------------------------------------------ */

static void Check(const char *what, DWORD err)
{
    char buf[128];
    if (err == 0)
        return;
    SVGetErrorText(err, buf, sizeof buf);
    fprintf(stderr, "%s failed: %lu (%s)\n", what, (unsigned long)err, buf);
    exit(1);
}

static void PrintInfo(HSV hsv)
{
    SVVERSIONINFO v;
    DWORD langs = 0;
    int i;

    Check("SVGetVersionInfo", SVGetVersionInfo(&v));
    printf("version %08lx  \"%s\"  \"%s\"  voiceinfo=%u bytes\n",
           (unsigned long)v.dwVersion, v.pszCompany, v.pszDate, v.wVoiceInfoSize);
    Check("SVGetAvailableLanguages", SVGetAvailableLanguages(hsv, &langs));
    printf("languages %lx:%s%s%s\n", (unsigned long)langs,
           langs & SV_LANG_ENGLISH ? " english" : "",
           langs & SV_LANG_SPANISH ? " spanish" : "",
           langs & SV_LANG_GERMAN ? " german" : "");

    printf("\n id name           pitch rate gen glot vmode f0sty f0rng f0prt vfact  av  ah  af  F4   B4   F5   B5\n");
    for (i = 0; i < SV_VOICE_COUNT; i++) {
        SVVOICEINFO vi;
        memset(&vi, 0, sizeof vi);
        Check("SVGetVoiceInfo", SVGetVoiceInfo(hsv, (WORD)i, &vi, sizeof vi));
        printf(" %2d %-14s %5u %4u %3u %4u %5u %5u %5u %5u %5u %3d %3d %3d %4u %4u %4u %4u\n",
               i, vi.szName, vi.wPitch, vi.wRate, vi.wGender, vi.wGlottalSource,
               vi.wVoicingMode, vi.wF0Style, vi.wF0Range, vi.wF0Perturb, vi.wVowelFactor,
               vi.sAVBias, vi.sAHBias, vi.sAFBias, vi.wF4, vi.wB4, vi.wF5, vi.wB5);
    }
}

int main(int argc, char **argv)
{
    HSV hsv = NULL;
    HWND hwnd;
    WNDCLASSA wc = {0};
    MSG m;
    DWORD err, lang = SV_LANG_ENGLISH;
    DWORD narrateFlags = 0;
    int voice = -1, rate = 0, pitch = 0, phonIn = 0, useTts = 0, convertOnly = 0, info = 0;
    const char *wavPath = NULL;
    static char text[4096], phon[0x2800];
    int i;

    for (i = 1; i < argc; i++) {
        const char *a = argv[i];
        if (!strcmp(a, "-l") && i + 1 < argc) lang = !strcmp(argv[++i], "es") ? SV_LANG_SPANISH : SV_LANG_ENGLISH;
        else if (!strcmp(a, "-v") && i + 1 < argc) voice = atoi(argv[++i]);
        else if (!strcmp(a, "-r") && i + 1 < argc) rate = atoi(argv[++i]);
        else if (!strcmp(a, "-p") && i + 1 < argc) pitch = atoi(argv[++i]);
        else if (!strcmp(a, "-w") && i + 1 < argc) wavPath = argv[++i];
        else if (!strcmp(a, "-f") && i + 1 < argc) narrateFlags = strtoul(argv[++i], NULL, 0);
        else if (!strcmp(a, "-P")) phonIn = 1;
        else if (!strcmp(a, "-t")) useTts = 1;
        else if (!strcmp(a, "-n")) convertOnly = 1;
        else if (!strcmp(a, "-s")) g_verbose = 1;
        else if (!strcmp(a, "--info")) info = 1;
        else {
            if (text[0]) strncat(text, " ", sizeof text - strlen(text) - 1);
            strncat(text, a, sizeof text - strlen(text) - 1);
        }
    }
    if (!text[0] && !info) {
        fprintf(stderr, "usage: svsay [-l en|es] [-v N] [-r WPM] [-p HZ] [-f FLAGS] [-P] [-t] [-n] [-s] [-w out.wav] [--info] text...\n");
        return 2;
    }
    g_text = text;

    g_syncMsg = RegisterWindowMessageA(SV_SYNC_MESSAGE_NAME);
    wc.lpfnWndProc = NotifyProc;
    wc.hInstance = GetModuleHandleA(NULL);
    wc.lpszClassName = "svsayNotify";
    RegisterClassA(&wc);
    hwnd = CreateWindowA(wc.lpszClassName, "", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, wc.hInstance, NULL);

    err = SVOpenSpeech(&hsv, hwnd, WAVE_MAPPER, SV_LANG_ENGLISH | SV_LANG_SPANISH, 0);
    if (err == SVERR_LANGUAGE && hsv)
        err = 0;    /* some language missing: same handling as TalkIt!.exe */
    Check("SVOpenSpeech", err);

    if (info)
        PrintInfo(hsv);
    if (!text[0])
        goto out;

    Check("SVSetLanguage", SVSetLanguage(hsv, lang));
    if (voice >= 0) Check("SVSetPersonality", SVSetPersonality(hsv, (WORD)voice));
    if (rate)       Check("SVSetRate", SVSetRate(hsv, (WORD)rate));
    if (pitch)      Check("SVSetPitch", SVSetPitch(hsv, (WORD)pitch));

    if (wavPath) {
        if (!HookImport(GetModuleHandleA("tibase32.dll"), "WINMM.dll", "waveOutWrite",
                        (void *)HookWaveOutWrite, (void **)&g_realWaveOutWrite)) {
            fprintf(stderr, "could not hook waveOutWrite\n");
            return 1;
        }
        g_wav = fopen(wavPath, "wb");
        if (!g_wav) { perror(wavPath); return 1; }
        WriteWavHeader(g_wav, 0);
    }

    if (useTts) {
        printf("SVTTS: %s\n", text);
        Check("SVTTS", SVTTS(hsv, text, NULL, NULL, hwnd, SV_TTP_WORD_MARKERS, narrateFlags, 0));
    } else {
        if (phonIn) {
            strncpy(phon, text, sizeof phon - 1);
            g_text = NULL;
        } else {
            LONG r = SVTextToPhon(hsv, text, phon, sizeof phon, SV_TTP_WORD_MARKERS, 0);
            if (r < 0)
                fprintf(stderr, "warning: phoneme buffer full after %ld chars\n", -r - 1);
            else
                Check("SVTextToPhon", (DWORD)r);
        }
        printf("phonemes: %s\n", phon);
        if (convertOnly)
            goto out;
        Check("SVNarrate", SVNarrate(hsv, phon, hwnd, narrateFlags, 0));
    }

    while (GetMessageA(&m, NULL, 0, 0) > 0) {
        TranslateMessage(&m);
        DispatchMessageA(&m);
    }
    if (g_doneErr) {
        char buf[128];
        SVGetErrorText(g_doneErr, buf, sizeof buf);
        fprintf(stderr, "speech ended with error %lu (%s)\n", (unsigned long)g_doneErr, buf);
    }

out:
    if (g_wav) {
        WriteWavHeader(g_wav, g_wavBytes);
        fclose(g_wav);
        printf("wrote %s: %lu samples (%.2f s)\n", wavPath, (unsigned long)g_wavBytes, g_wavBytes / 11025.0);
    }
    SVCloseSpeech(hsv);
    return g_doneErr ? 1 : 0;
}
