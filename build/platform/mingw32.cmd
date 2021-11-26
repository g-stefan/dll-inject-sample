@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

set CHERE_INVOKING=enabled_from_arguments
set SHLVL=2
set MSYSTEM=MINGW32
C:\msys64\usr\bin\sh --login -- ./build/platform/mingw32.sh %1
