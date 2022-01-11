@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo - %BUILD_PROJECT% ^> install-archived-release

goto cmdXDefined
:cmdX
%*
if errorlevel 1 goto cmdXError
goto :eof
:cmdXError
echo "Error: install-archived-release"
exit 1
:cmdXDefined

call :cmdX  xyo-cc %BUILD_PROJECT% --install-archived-release --version-file=version.ini
