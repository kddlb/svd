/*
 * oracle - run the original SoftVoice DLLs headless and record golden data.
 *
 *   oracle corpus.txt out.svg
 *
 * NO AUDIO: every waveOut* import of TIBASE32.DLL is redirected to stubs
 * before the engine is opened, and a self-check refuses to run if any
 * waveOut import is left unhooked.  Finished buffers are "returned" by
 * posting MM_WOM_DONE ourselves, so synthesis runs as fast as the CPU allows.
 *
 * Corpus format (UTF-8 text, one case per line):
 *   # comment
 *   #lang en|es        language for following cases        (default en)
 *   #voice N           personality preset 0..19            (default 0)
 *   #mode text|phon    lines are text (SVTextToPhon first) or phonemes
 *   #ttp HEX           SVTextToPhon flags                  (default 0x08)
 *   #nflags HEX        SVNarrate flags (0x40 is always added: no sync timer)
 *   #pitch N / #rate N  override after selecting the preset (0 = preset value)
 *   #nospeak 1         only run SVTextToPhon
 *   #ttpbuf N          SVTextToPhon output buffer size (0 = whole 256 KB buffer;
 *                      when set, the CASE chunk also gets ttpbuf=N)
 *   #stages 1          also snapshot after every pipeline stage (large output)
 *   #persist 1         keep one engine open across the following cases (CASE
 *                      gets session=N; a new N whenever an engine is opened)
 *   #gender/#glot/#voicing/#f0style/#f0range/#perturb/#vfactor/#avbias/
 *   #ahbias/#afbias/#speakmode N   setter overrides after the preset ("-" = unset)
 *   #reset 1           clear all overrides (incl. pitch and rate)
 *
 * Output: "SVGOLD1\n" followed by chunks  [char tag[4]][u32 len][len bytes]
 *   CASE  key=value lines (id, lang, voice, mode, ttp, nflags, pitch, rate, text)
 *   MODS  u32 base address of tibase32, tieng32, tispan32 (0 if not loaded)
 *   TTPR  i32 SVTextToPhon return value
 *   PHON  phoneme string passed to SVNarrate (no NUL)
 *   STAG  with "#stages 1": u32 stage index (see g_stageSites) followed by
 *         the same body as SNAP, after each pipeline stage of each phrase
 *   LDAT  with "#stages 1", after stages 9, 10, 12 and 13: u32 stage, then
 *         {u32 addr, u32 len, bytes} for the .data of tibase32, tieng32, tispan32
 *   SNAP  one per phrase, taken after frame post-processing and before the
 *         first sample-generator call:
 *           u32 ctx, then 5 blocks of {u32 addr, u32 len, bytes}:
 *           context (0x5A8), phoneme records, syllable arrays, frames,
 *           embedded-command buffer
 *   PCM_  all 8-bit samples written to waveOut, in order
 *   DONE  u32 SVNarrate result, u32 SV_SYNC_DONE error code, u32 phrases
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../sdk/softvoice.h"

/* ---- output ------------------------------------------------------------ */

static FILE *g_out;

static void Chunk(const char *tag, const void *data, DWORD len)
{
    fwrite(tag, 1, 4, g_out);
    fwrite(&len, 4, 1, g_out);
    if (len) fwrite(data, 1, len, g_out);
}

typedef struct { BYTE *p; DWORD len, cap; } Buf;

static void BufAdd(Buf *b, const void *data, DWORD len)
{
    if (b->len + len > b->cap) {
        b->cap = (b->len + len) * 2 + 4096;
        b->p = (BYTE *)realloc(b->p, b->cap);
    }
    memcpy(b->p + b->len, data, len);
    b->len += len;
}
static void BufU32(Buf *b, DWORD v) { BufAdd(b, &v, 4); }

/* ---- fake waveOut ------------------------------------------------------ */

#define FAKE_HWO ((HWAVEOUT)(DWORD_PTR)0x5EED0001)
#define MAX_PENDING 16

static HWND     g_cbWnd;            /* engine's CALLBACK_WINDOW */
static LPWAVEHDR g_pending[MAX_PENDING];
static int      g_npending;
static Buf      g_pcm;
static int      g_badCall;

static UINT     WINAPI F_GetNumDevs(void) { return 1; }
static MMRESULT WINAPI F_Open(LPHWAVEOUT phwo, UINT dev, LPCWAVEFORMATEX fmt,
                              DWORD_PTR cb, DWORD_PTR inst, DWORD flags)
{
    (void)dev; (void)inst;
    if (fmt->nSamplesPerSec != 11025 || fmt->wBitsPerSample != 8 || fmt->nChannels != 1)
        g_badCall = 1;
    if (flags & WAVE_FORMAT_QUERY)
        return MMSYSERR_NOERROR;
    if ((flags & CALLBACK_TYPEMASK) != CALLBACK_WINDOW)
        g_badCall = 1;
    g_cbWnd = (HWND)cb;
    if (phwo) *phwo = FAKE_HWO;
    return MMSYSERR_NOERROR;
}
static MMRESULT WINAPI F_Close(HWAVEOUT h) { (void)h; return MMSYSERR_NOERROR; }
static MMRESULT WINAPI F_Prepare(HWAVEOUT h, LPWAVEHDR hdr, UINT cb)
{
    (void)h; (void)cb;
    hdr->dwFlags |= WHDR_PREPARED;
    return MMSYSERR_NOERROR;
}
static MMRESULT WINAPI F_Unprepare(HWAVEOUT h, LPWAVEHDR hdr, UINT cb)
{
    (void)h; (void)cb;
    hdr->dwFlags &= ~WHDR_PREPARED;
    return MMSYSERR_NOERROR;
}
static MMRESULT WINAPI F_Write(HWAVEOUT h, LPWAVEHDR hdr, UINT cb)
{
    (void)h; (void)cb;
    BufAdd(&g_pcm, hdr->lpData, hdr->dwBufferLength);
    hdr->dwFlags = (hdr->dwFlags & ~WHDR_DONE) | WHDR_INQUEUE;
    if (g_npending < MAX_PENDING)
        g_pending[g_npending++] = hdr;
    else
        g_badCall = 1;
    return MMSYSERR_NOERROR;
}
static MMRESULT WINAPI F_Pause(HWAVEOUT h) { (void)h; return MMSYSERR_NOERROR; }
static MMRESULT WINAPI F_Restart(HWAVEOUT h) { (void)h; return MMSYSERR_NOERROR; }
static MMRESULT WINAPI F_Reset(HWAVEOUT h) { (void)h; return MMSYSERR_NOERROR; }

/* ---- snapshot hook ------------------------------------------------------ */

typedef size_t (__cdecl *PFN_msize)(void *);
typedef HGLOBAL (WINAPI *PFN_GlobalAlloc)(UINT, SIZE_T);
static PFN_msize       g_msize;
static PFN_GlobalAlloc g_realGlobalAlloc;
static HSV             g_hsv;
static int             g_phrases;

static void SnapBlock(Buf *b, const void *addr, DWORD len)
{
    BufU32(b, (DWORD)(DWORD_PTR)addr);
    if (!addr) len = 0;
    BufU32(b, len);
    if (len) BufAdd(b, addr, len);
}

static DWORD CrtSize(void *p) { return p ? (DWORD)g_msize(p) : 0; }

static void TakeSnapshot(const char *tag, int stage)
{
    BYTE *ctx = (BYTE *)g_hsv;
    Buf b = {0};
    void *recs  = *(void **)(ctx + 0x156);
    void *syll  = *(void **)(ctx + 0x1FA);
    void *frms  = *(void **)(ctx + 0x230);
    HLOCAL cmds = *(HLOCAL *)(ctx + 0x16E);

    if (stage >= 0)
        BufU32(&b, (DWORD)stage);
    BufU32(&b, (DWORD)(DWORD_PTR)ctx);
    SnapBlock(&b, ctx, 0x5A8);
    SnapBlock(&b, recs, CrtSize(recs));
    SnapBlock(&b, syll, CrtSize(syll));
    SnapBlock(&b, frms, CrtSize(frms));
    SnapBlock(&b, cmds, cmds ? (DWORD)LocalSize(cmds) : 0);
    Chunk(tag, b.p, b.len);
    free(b.p);
}

/* FUN_1c00f300 allocates the 0x2000-byte wave buffer right after the frames
 * are final and right before the first sample-generator call. */
static HGLOBAL WINAPI H_GlobalAlloc(UINT flags, SIZE_T size)
{
    if (size == 0x2000 && g_hsv) {
        TakeSnapshot("SNAP", -1);
        g_phrases++;
    }
    return g_realGlobalAlloc(flags, size);
}

/* ---- per-stage snapshots ------------------------------------------------ */
/* Each pipeline call in the narrate driver FUN_1c003870 is redirected to a
 * hook that runs the original stage and then snapshots (chunk STAG, prefixed
 * with the stage index).  Enabled with "#stages 1". */

typedef int (__cdecl *PFN_stage)(void *s);
static const struct { DWORD site; const char *name; } g_stageSites[] = {
    { 0x1c0038d7, "sentence c500" },
    { 0x1c003948, "parse 4a10" },        { 0x1c00395d, "voice 3e40" },
    { 0x1c003966, "onsets c550" },       { 0x1c00396f, "allophones 5910" },
    { 0x1c003978, "syllables c6d0" },    { 0x1c003981, "boundaries 3de0" },
    { 0x1c00398a, "syll-alloc cc10" },   { 0x1c0039b4, "stress c8c0" },
    { 0x1c0039bd, "f0 cdc0" },           { 0x1c0039c6, "durations c3e0" },
    { 0x1c0039cf, "tempo f7c0" },        { 0x1c0039d8, "frame-alloc c420" },
    { 0x1c0039ef, "frames 5840" },       { 0x1c0039f8, "f0-fill cd40" },
    { 0x1c003a01, "smooth1 de60" },      { 0x1c003a0a, "smooth2 de60" },
    { 0x1c003a13, "post be40" },
};
#define NSTAGES (sizeof g_stageSites / sizeof g_stageSites[0])
static PFN_stage g_stageOrig[NSTAGES];
static int g_stagesOn;

/* .data of each DLL, for stages whose code keeps state there. */
static void DataSection(HMODULE mod, BYTE **addr, DWORD *len)
{
    BYTE *base = (BYTE *)mod;
    IMAGE_NT_HEADERS *nt;
    IMAGE_SECTION_HEADER *sec;
    WORD i;
    *addr = NULL;
    *len = 0;
    if (!mod) return;
    nt = (IMAGE_NT_HEADERS *)(base + ((IMAGE_DOS_HEADER *)base)->e_lfanew);
    sec = IMAGE_FIRST_SECTION(nt);
    for (i = 0; i < nt->FileHeader.NumberOfSections; i++, sec++)
        if (memcmp(sec->Name, ".data", 6) == 0) {
            *addr = base + sec->VirtualAddress;
            *len = sec->Misc.VirtualSize;
        }
}

static void DllDataSnapshot(int stage)
{
    static const char *names[3] = { "tibase32.dll", "tieng32.dll", "tispan32.dll" };
    Buf b = {0};
    int i;
    BufU32(&b, (DWORD)stage);
    for (i = 0; i < 3; i++) {
        BYTE *addr; DWORD len;
        DataSection(GetModuleHandleA(names[i]), &addr, &len);
        SnapBlock(&b, addr, len);
    }
    Chunk("LDAT", b.p, b.len);
    free(b.p);
}

#define STAGE(n) static int __cdecl Stage##n(void *s) {     int r = g_stageOrig[n](s); if (g_stagesOn && g_hsv) { TakeSnapshot("STAG", n); if (n == 9 || n == 10 || n == 12 || n == 13) DllDataSnapshot(n); } return r; }
STAGE(0) STAGE(1) STAGE(2) STAGE(3) STAGE(4) STAGE(5) STAGE(6) STAGE(7) STAGE(8)
STAGE(9) STAGE(10) STAGE(11) STAGE(12) STAGE(13) STAGE(14) STAGE(15) STAGE(16) STAGE(17)
static const PFN_stage g_stageHooks[NSTAGES] = {
    Stage0, Stage1, Stage2, Stage3, Stage4, Stage5, Stage6, Stage7, Stage8,
    Stage9, Stage10, Stage11, Stage12, Stage13, Stage14, Stage15, Stage16, Stage17,
};

static int PatchStageCalls(HMODULE base)
{
    size_t i;
    DWORD delta = (DWORD)(DWORD_PTR)base - 0x1c000000;   /* in case of relocation */
    for (i = 0; i < NSTAGES; i++) {
        BYTE *site = (BYTE *)(DWORD_PTR)(g_stageSites[i].site + delta);
        DWORD old;
        if (site[0] != 0xE8) {
            fprintf(stderr, "stage site %08lx is not a call\n", (unsigned long)g_stageSites[i].site);
            return 0;
        }
        g_stageOrig[i] = (PFN_stage)(site + 5 + *(LONG *)(site + 1));
        VirtualProtect(site, 5, PAGE_EXECUTE_READWRITE, &old);
        *(LONG *)(site + 1) = (LONG)((BYTE *)g_stageHooks[i] - (site + 5));
        VirtualProtect(site, 5, old, &old);
    }
    FlushInstructionCache(GetCurrentProcess(), NULL, 0);
    return 1;
}

/* ---- IAT patching ------------------------------------------------------- */

typedef struct { const char *name; void *hook; } Hook;

static const Hook g_waveHooks[] = {
    { "waveOutGetNumDevs",     (void *)F_GetNumDevs },
    { "waveOutOpen",           (void *)F_Open },
    { "waveOutClose",          (void *)F_Close },
    { "waveOutPrepareHeader",  (void *)F_Prepare },
    { "waveOutUnprepareHeader",(void *)F_Unprepare },
    { "waveOutWrite",          (void *)F_Write },
    { "waveOutPause",          (void *)F_Pause },
    { "waveOutRestart",        (void *)F_Restart },
    { "waveOutReset",          (void *)F_Reset },
};

/* Calls fn(name, slot) for every by-name import of `dll` in `mod`. */
static void ForEachImport(HMODULE mod, const char *dll,
                          void (*fn)(const char *, void **, void *), void *arg)
{
    BYTE *base = (BYTE *)mod;
    IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)(base + ((IMAGE_DOS_HEADER *)base)->e_lfanew);
    IMAGE_DATA_DIRECTORY dir = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    IMAGE_IMPORT_DESCRIPTOR *imp = (IMAGE_IMPORT_DESCRIPTOR *)(base + dir.VirtualAddress);
    for (; imp->Name; imp++) {
        IMAGE_THUNK_DATA *names, *iat;
        if (_stricmp((char *)(base + imp->Name), dll) != 0)
            continue;
        names = (IMAGE_THUNK_DATA *)(base + imp->OriginalFirstThunk);
        iat = (IMAGE_THUNK_DATA *)(base + imp->FirstThunk);
        for (; names->u1.AddressOfData; names++, iat++) {
            if (IMAGE_SNAP_BY_ORDINAL(names->u1.Ordinal))
                continue;
            fn((char *)((IMAGE_IMPORT_BY_NAME *)(base + names->u1.AddressOfData))->Name,
               (void **)&iat->u1.Function, arg);
        }
    }
}

static void Patch(void **slot, void *value, void **orig)
{
    DWORD old;
    VirtualProtect(slot, sizeof *slot, PAGE_READWRITE, &old);
    if (orig) *orig = *slot;
    *slot = value;
    VirtualProtect(slot, sizeof *slot, old, &old);
}

static void HookWinmm(const char *name, void **slot, void *arg)
{
    size_t i;
    (void)arg;
    for (i = 0; i < sizeof g_waveHooks / sizeof g_waveHooks[0]; i++)
        if (strcmp(name, g_waveHooks[i].name) == 0)
            Patch(slot, g_waveHooks[i].hook, NULL);
}

static void CheckWinmm(const char *name, void **slot, void *arg)
{
    size_t i;
    int *bad = (int *)arg;
    if (strncmp(name, "waveOut", 7) != 0)
        return;
    for (i = 0; i < sizeof g_waveHooks / sizeof g_waveHooks[0]; i++)
        if (*slot == g_waveHooks[i].hook)
            return;
    fprintf(stderr, "SAFETY: %s is not hooked - refusing to run\n", name);
    *bad = 1;
}

static void HookKernel(const char *name, void **slot, void *arg)
{
    (void)arg;
    if (strcmp(name, "GlobalAlloc") == 0)
        Patch(slot, (void *)H_GlobalAlloc, (void **)&g_realGlobalAlloc);
}

/* ---- notification window ----------------------------------------------- */

static UINT  g_syncMsg;
static int   g_done;
static DWORD g_doneErr;

static LRESULT CALLBACK NotifyProc(HWND h, UINT msg, WPARAM wp, LPARAM lp)
{
    if (msg == g_syncMsg && msg) {
        if (wp == SV_SYNC_DONE) {
            g_done = 1;
            g_doneErr = ((const SVSYNC *)lp)->wValue;
        }
        return 0;
    }
    return DefWindowProcA(h, msg, wp, lp);
}

/* Pump until SV_SYNC_DONE.  Buffers are only handed back when the queue is
 * empty, so each phrase's messages are handled before its buffers are freed. */
static int RunUntilDone(void)
{
    MSG m;
    int idle = 0;
    while (!g_done) {
        if (PeekMessageA(&m, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&m);
            DispatchMessageA(&m);
            idle = 0;
            continue;
        }
        if (g_npending > 0) {
            LPWAVEHDR hdr = g_pending[0];
            memmove(g_pending, g_pending + 1, --g_npending * sizeof g_pending[0]);
            hdr->dwFlags = (hdr->dwFlags & ~WHDR_INQUEUE) | WHDR_DONE;
            PostMessageA(g_cbWnd, MM_WOM_DONE, (WPARAM)FAKE_HWO, (LPARAM)hdr);
            continue;
        }
        if (++idle > 200) {
            fprintf(stderr, "stuck: no messages and no pending buffers\n");
            return 0;
        }
        MsgWaitForMultipleObjects(0, NULL, FALSE, 5, QS_ALLINPUT);
    }
    return 1;
}

/* ---- corpus ------------------------------------------------------------- */

static int ToLatin1(const char *utf8, char *out, int cap)
{
    WCHAR w[8192];
    int n = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, w, 8192), i, j = 0;
    for (i = 0; i < n - 1 && j < cap - 1; i++)
        out[j++] = w[i] < 256 ? (char)w[i] : '?';
    out[j] = 0;
    return j;
}

static void Fail(const char *what, DWORD err)
{
    char buf[128] = "";
    SVGetErrorText(err, buf, sizeof buf);
    fprintf(stderr, "%s: %lu %s\n", what, (unsigned long)err, buf);
}

int main(int argc, char **argv)
{
    HMODULE base = GetModuleHandleA("tibase32.dll");
    FILE *in;
    char line[8192], text[8192];
    int bad = 0, id = 0, lang = SV_LANG_ENGLISH, voice = 0, phonMode = 0, nospeak = 0;
    int pitch = 0, rate = 0, failures = 0;
    /* Optional setter overrides, applied after the preset; -32768 = unset. */
    enum { S_GENDER, S_GLOT, S_VOICING, S_F0STYLE, S_F0RANGE, S_PERTURB, S_VFACTOR,
           S_AVBIAS, S_AHBIAS, S_AFBIAS, S_SPEAKMODE, S_COUNT };
    static const char *setterNames[S_COUNT] = { "gender", "glot", "voicing", "f0style",
        "f0range", "perturb", "vfactor", "avbias", "ahbias", "afbias", "speakmode" };
    int setters[S_COUNT];
    int si;
    DWORD ttp = SV_TTP_WORD_MARKERS, nflags = 0;
    LONG ttpbuf = 0;
    int persist = 0, session = 0;
    static char phon[1 << 18];
    WNDCLASSA wc = {0};
    HWND hwnd;

    if (argc < 3) {
        fprintf(stderr, "usage: oracle corpus.txt out.svg\n");
        return 2;
    }

    /* Hook before anything can touch the audio device. */
    ForEachImport(base, "WINMM.dll", HookWinmm, NULL);
    ForEachImport(base, "WINMM.dll", CheckWinmm, &bad);
    ForEachImport(base, "KERNEL32.dll", HookKernel, NULL);
    if (bad || !g_realGlobalAlloc || !PatchStageCalls(base))
        return 3;
    g_msize = (PFN_msize)GetProcAddress(GetModuleHandleA("msvcrt40.dll"), "_msize");
    if (!g_msize) {
        fprintf(stderr, "msvcrt40 _msize not found\n");
        return 3;
    }

    for (si = 0; si < S_COUNT; si++) setters[si] = -32768;
    g_syncMsg = RegisterWindowMessageA(SV_SYNC_MESSAGE_NAME);
    wc.lpfnWndProc = NotifyProc;
    wc.hInstance = GetModuleHandleA(NULL);
    wc.lpszClassName = "oracleNotify";
    RegisterClassA(&wc);
    hwnd = CreateWindowA(wc.lpszClassName, "", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, wc.hInstance, NULL);

    in = fopen(argv[1], "rb");
    g_out = fopen(argv[2], "wb");
    if (!in || !g_out) {
        perror("open");
        return 2;
    }
    fputs("SVGOLD1\n", g_out);

    while (fgets(line, sizeof line, in)) {
        char meta[9000];
        DWORD err, narrateErr = 0;
        LONG r = 0;
        size_t n = strcspn(line, "\r\n");
        line[n] = 0;
        if (!line[0] || (line[0] == '#' && line[1] == ' ') || !strcmp(line, "#"))
            continue;
        if (line[0] == '#') {
            char key[32], val[64];
            if (sscanf(line + 1, "%31s %63s", key, val) != 2) continue;
            if (!strcmp(key, "lang")) lang = !strcmp(val, "es") ? SV_LANG_SPANISH : SV_LANG_ENGLISH;
            else if (!strcmp(key, "voice")) voice = atoi(val);
            else if (!strcmp(key, "mode")) phonMode = !strcmp(val, "phon");
            else if (!strcmp(key, "ttp")) ttp = strtoul(val, NULL, 0);
            else if (!strcmp(key, "nflags")) nflags = strtoul(val, NULL, 0);
            else if (!strcmp(key, "pitch")) pitch = atoi(val);
            else if (!strcmp(key, "rate")) rate = atoi(val);
            else if (!strcmp(key, "nospeak")) nospeak = atoi(val);
            else if (!strcmp(key, "ttpbuf")) { ttpbuf = atol(val); if (ttpbuf < 0 || ttpbuf > (LONG)sizeof phon) ttpbuf = 0; }
            else if (!strcmp(key, "stages")) g_stagesOn = atoi(val);
            else if (!strcmp(key, "persist")) {
                persist = atoi(val);
                if (!persist && g_hsv) { SVCloseSpeech(g_hsv); g_hsv = NULL; }
            }
            else if (!strcmp(key, "reset")) { for (si = 0; si < S_COUNT; si++) setters[si] = -32768; pitch = rate = 0; }
            else {
                for (si = 0; si < S_COUNT; si++)
                    if (!strcmp(key, setterNames[si])) { setters[si] = !strcmp(val, "-") ? -32768 : atoi(val); break; }
                if (si == S_COUNT) fprintf(stderr, "unknown directive %s\n", key);
            }
            continue;
        }

        ToLatin1(line, text, sizeof text);
        id++;
        _snprintf(meta, sizeof meta,
                  "id=%d\nlang=%s\nvoice=%d\nmode=%s\nttp=0x%lx\nnflags=0x%lx\npitch=%d\nrate=%d\n",
                  id, lang == SV_LANG_SPANISH ? "es" : "en", voice, phonMode ? "phon" : "text",
                  (unsigned long)ttp, (unsigned long)(nflags | 0x40), pitch, rate);
        for (si = 0; si < S_COUNT; si++)
            if (setters[si] != -32768)
                _snprintf(meta + strlen(meta), sizeof meta - strlen(meta), "%s=%d\n", setterNames[si], setters[si]);
        if (ttpbuf)
            _snprintf(meta + strlen(meta), sizeof meta - strlen(meta), "ttpbuf=%ld\n", (long)ttpbuf);
        if (!g_hsv) session++;
        _snprintf(meta + strlen(meta), sizeof meta - strlen(meta), "session=%d\n", session);
        _snprintf(meta + strlen(meta), sizeof meta - strlen(meta), "text=%s", line);
        Chunk("CASE", meta, (DWORD)strlen(meta));

        /* Fresh engine per case (reloads the language DLLs, so no state
         * carries over), unless "#persist 1" keeps one engine open across
         * cases like an application would.  "session" in CASE says which. */
        if (!g_hsv) {
            err = SVOpenSpeech(&g_hsv, hwnd, WAVE_MAPPER, SV_LANG_ENGLISH | SV_LANG_SPANISH, 0);
            if (!g_hsv || (err && err != SVERR_LANGUAGE)) {
                Fail("SVOpenSpeech", err);
                return 1;
            }
        }
        {
            DWORD mods[3] = {
                (DWORD)(DWORD_PTR)base,
                (DWORD)(DWORD_PTR)GetModuleHandleA("tieng32.dll"),
                (DWORD)(DWORD_PTR)GetModuleHandleA("tispan32.dll"),
            };
            Chunk("MODS", mods, sizeof mods);
        }
        if ((err = SVSetLanguage(g_hsv, lang)) != 0) Fail("SVSetLanguage", err);
        if ((err = SVSetPersonality(g_hsv, (WORD)voice)) != 0) Fail("SVSetPersonality", err);
        if (pitch && (err = SVSetPitch(g_hsv, (WORD)pitch)) != 0) Fail("SVSetPitch", err);
        if (rate && (err = SVSetRate(g_hsv, (WORD)rate)) != 0) Fail("SVSetRate", err);
        for (si = 0; si < S_COUNT; si++) {
            int v = setters[si];
            if (v == -32768) continue;
            switch (si) {
            case S_GENDER:    err = SVSetGender(g_hsv, (WORD)v); break;
            case S_GLOT:      err = SVSetGlottalSource(g_hsv, (WORD)v); break;
            case S_VOICING:   err = SVSetVoicingMode(g_hsv, (WORD)v); break;
            case S_F0STYLE:   err = SVSetF0Style(g_hsv, (WORD)v); break;
            case S_F0RANGE:   err = SVSetF0Range(g_hsv, (WORD)v); break;
            case S_PERTURB:   err = SVSetF0Perturb(g_hsv, (WORD)v); break;
            case S_VFACTOR:   err = SVSetVowelFactor(g_hsv, (SHORT)v); break;
            case S_AVBIAS:    err = SVSetAVBias(g_hsv, (SHORT)v); break;
            case S_AHBIAS:    err = SVSetAHBias(g_hsv, (SHORT)v); break;
            case S_AFBIAS:    err = SVSetAFBias(g_hsv, (SHORT)v); break;
            case S_SPEAKMODE: err = SVSetSpeakingMode(g_hsv, (WORD)v); break;
            }
            if (err) Fail(setterNames[si], err);
        }

        if (phonMode) {
            strncpy(phon, text, sizeof phon - 1);
            phon[sizeof phon - 1] = 0;
        } else {
            r = SVTextToPhon(g_hsv, text, phon, ttpbuf ? ttpbuf : (LONG)sizeof phon, ttp, 0);
            Chunk("TTPR", &r, 4);
            if (r != 0) {
                fprintf(stderr, "case %d: SVTextToPhon returned %ld\n", id, (long)r);
                failures++;
            }
        }
        Chunk("PHON", phon, (DWORD)strlen(phon));

        g_pcm.len = 0;
        g_npending = 0;
        g_phrases = 0;
        g_done = 0;
        g_doneErr = 0;
        if (!nospeak) {
            narrateErr = SVNarrate(g_hsv, phon, hwnd, nflags | SV_NARRATE_NO_SYNC, 0);
            if (narrateErr == 0) {
                if (!RunUntilDone()) {
                    fprintf(stderr, "case %d did not finish\n", id);
                    return 1;
                }
            } else {
                failures++;
            }
            Chunk("PCM_", g_pcm.p, g_pcm.len);
            {
                DWORD done[3] = { narrateErr, g_doneErr, (DWORD)g_phrases };
                Chunk("DONE", done, sizeof done);
            }
        }
        if (!persist) {
            SVCloseSpeech(g_hsv);
            g_hsv = NULL;
        }
        if (g_badCall) {
            fprintf(stderr, "unexpected waveOut usage in case %d\n", id);
            return 1;
        }
        /* Drain anything the closed engine left behind. */
        {
            MSG m;
            while (PeekMessageA(&m, NULL, 0, 0, PM_REMOVE)) DispatchMessageA(&m);
        }
        if (id % 500 == 0)
            fprintf(stderr, "%d cases\n", id);
    }
    if (g_hsv) {
        SVCloseSpeech(g_hsv);
        g_hsv = NULL;
    }
    fclose(g_out);
    fprintf(stderr, "%d cases, %d with errors\n", id, failures);
    return 0;
}
