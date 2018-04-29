@echo off

rem --- make

echo ^> make dll-inject-sample ^<

goto Make
:ErrorMake
echo Error: make
goto :eof
:Make

xyo-cc --mode=%ACTION% --dll dll-inject-sample --no-def-dynamic-link --no-lib --inc=. --use-project=libxyo-win-inject.static
IF ERRORLEVEL 1 goto ErrorMake


