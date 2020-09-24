@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

set XYO_PATH_REPOSITORY=%HOMEDRIVE%%HOMEPATH%\SDK
set XYO_PATH_RELEASE=%HOMEDRIVE%%HOMEPATH%\SDK\release

if "%XYO_PLATFORM%" == "win64-msvc-2019" goto Build
if "%XYO_PLATFORM%" == "win64-msvc-2017" goto Build
set XYO_PLATFORM=
:Build
cmd.exe /C "port\build.msvc.cmd win64 %1"
