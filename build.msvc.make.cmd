@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

rem --- make

echo ^> make dll-inject-sample ^<

goto Make
:ErrorMake
echo Error: make
goto :eof
:Make

xyo-cc --mode=%ACTION% --dll-x-static dll-inject-sample --no-def-dynamic-link --no-lib --dll-no-version --inc=. --use-project=libxyo-win-inject.static
IF ERRORLEVEL 1 goto ErrorMake


