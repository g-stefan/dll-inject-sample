@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

set XYO_PATH_REPOSITORY=%HOMEDRIVE%%HOMEPATH%\SDK32
set XYO_PATH_RELEASE=%HOMEDRIVE%%HOMEPATH%\SDK32\release
set XYO_PATH_REPOSITORY_LIBRARY=

if "%XYO_PLATFORM%" == "win32-msvc-2019" goto Build
if "%XYO_PLATFORM%" == "win32-msvc-2017" goto Build
set XYO_PLATFORM=
:Build
cmd.exe /C "build\msvc.cmd win32 %1"
