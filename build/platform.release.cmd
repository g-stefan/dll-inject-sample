@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo -^> platform release dll-inject-sample

goto cmdXDefined
:cmdX
%*
if errorlevel 1 goto cmdXError
goto :eof
:cmdXError
echo "Error: release"
exit 1
:cmdXDefined

call :cmdX cmd.exe /C "build\msvc64.cmd clean"
call :cmdX cmd.exe /C "build\msvc64.cmd release"
call :cmdX cmd.exe /C "build\msvc64.cmd clean"

call :cmdX cmd.exe /C "build\msvc32.cmd clean"
call :cmdX cmd.exe /C "build\msvc32.cmd release"
call :cmdX cmd.exe /C "build\msvc32.cmd clean"

