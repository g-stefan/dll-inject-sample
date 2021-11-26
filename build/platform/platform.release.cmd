@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo - %BUILD_PROJECT% ^> platform release

goto cmdXDefined
:cmdX
%*
if errorlevel 1 goto cmdXError
goto :eof
:cmdXError
echo "Error: release"
exit 1
:cmdXDefined

call :cmdX cmd.exe /C "build\platform\win64-msvc-2022.cmd clean"
call :cmdX cmd.exe /C "build\platform\win64-msvc-2022.cmd release"
call :cmdX cmd.exe /C "build\platform\win64-msvc-2022.cmd clean"

call :cmdX cmd.exe /C "build\platform\win32-msvc-2022.cmd clean"
call :cmdX cmd.exe /C "build\platform\win32-msvc-2022.cmd release"
call :cmdX cmd.exe /C "build\platform\win32-msvc-2022.cmd clean"

call :cmdX cmd.exe /C "build\platform\win64-msvc-2019.cmd clean"
call :cmdX cmd.exe /C "build\platform\win64-msvc-2019.cmd release"
call :cmdX cmd.exe /C "build\platform\win64-msvc-2019.cmd clean"

call :cmdX cmd.exe /C "build\platform\win32-msvc-2019.cmd clean"
call :cmdX cmd.exe /C "build\platform\win32-msvc-2019.cmd release"
call :cmdX cmd.exe /C "build\platform\win32-msvc-2019.cmd clean"

call :cmdX cmd.exe /C "build\platform\mingw64.cmd clean"
call :cmdX cmd.exe /C "build\platform\mingw64.cmd release"
call :cmdX cmd.exe /C "build\platform\mingw64.cmd clean"

call :cmdX cmd.exe /C "build\platform\mingw32.cmd clean"
call :cmdX cmd.exe /C "build\platform\mingw32.cmd release"
call :cmdX cmd.exe /C "build\platform\mingw32.cmd clean"

call :cmdX cmd.exe /C "build\platform\wsl-ubuntu-20.04.cmd clean"
call :cmdX cmd.exe /C "build\platform\wsl-ubuntu-20.04.cmd release"
call :cmdX cmd.exe /C "build\platform\wsl-ubuntu-20.04.cmd clean"

call :cmdX cmd.exe /C "build\platform\wsl-ubuntu-18.04.cmd clean"
call :cmdX cmd.exe /C "build\platform\wsl-ubuntu-18.04.cmd release"
call :cmdX cmd.exe /C "build\platform\wsl-ubuntu-18.04.cmd clean"
