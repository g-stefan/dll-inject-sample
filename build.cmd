@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

if "%1" == "" goto SelectDefaultPlatform
if not exist ".\port\build.%1.cmd" goto SelectDefaultPlatform
call ".\port\build.%1.cmd" %2
goto :eof
:SelectDefaultPlatform
set DEFAULT_PLATFORM=
if "%XYO_PLATFORM%" == "win64-msvc-2019" set DEFAULT_PLATFORM=msvc
if "%XYO_PLATFORM%" == "win32-msvc-2019" set DEFAULT_PLATFORM=msvc
if "%XYO_PLATFORM%" == "win64-msvc-2017" set DEFAULT_PLATFORM=msvc
if "%XYO_PLATFORM%" == "win32-msvc-2017" set DEFAULT_PLATFORM=msvc
if "%XYO_PLATFORM%" == "" goto Info
if not exist ".\port\build.%DEFAULT_PLATFORM%.cmd" goto Info
call ".\port\build.%DEFAULT_PLATFORM%.cmd" %1
goto :eof
:Info
echo build [platform] [mode]
