@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo -^> platform local-release dll-inject-sample

goto cmdXDefined
:cmdX
%*
if errorlevel 1 goto cmdXError
goto :eof
:cmdXError
echo "Error: local-release"
exit 1
:cmdXDefined

call :cmdX cmd.exe /C "port\build.msvc64.cmd clean"
call :cmdX cmd.exe /C "port\build.msvc64.cmd local-release"
call :cmdX cmd.exe /C "port\build.msvc64.cmd clean"

call :cmdX cmd.exe /C "port\build.msvc32.cmd clean"
call :cmdX cmd.exe /C "port\build.msvc32.cmd local-release"
call :cmdX cmd.exe /C "port\build.msvc32.cmd clean"

