@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

rem --- make

echo ^> %ACTION% dll-inject-sample ^<

goto Make
:ErrorMake
echo Error: %ACTION%
goto :eof
:Make

xyo-cc --mode=%ACTION% --dll-x-static dll-inject-sample --source-is-separate --no-def-dynamic-link --no-lib --dll-no-version --inc=. --use-project=libxyo-win-inject.static
IF ERRORLEVEL 1 goto ErrorMake


