@echo off
rem Builds svsay.exe (x86) against TIBASE32.DLL. Output goes to sdk\build\.
setlocal
set HERE=%~dp0
set OUT=%HERE%build
if not exist "%OUT%" mkdir "%OUT%"

where cl >nul 2>nul || call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul || exit /b 1

lib /nologo /def:"%HERE%tibase32.def" /machine:x86 /out:"%OUT%\tibase32.lib" || exit /b 1
cl /nologo /W3 /O2 /MT /D_CRT_SECURE_NO_WARNINGS /Fo"%OUT%\\" /Fe"%OUT%\svsay.exe" "%HERE%svsay.c" ^
   "%OUT%\tibase32.lib" user32.lib winmm.lib || exit /b 1

rem The engine loads its language DLLs from the search path; keep them next to the exe.
copy /y "%HERE%..\TalkIt\ti*.dll" "%OUT%\" >nul
echo built %OUT%\svsay.exe
