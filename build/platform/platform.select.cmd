@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

if not "%XYO_PLATFORM%" == "" goto :eof

set MSVC_PLATFORM_MACHINE=win64
if  "%PROCESSOR_ARCHITECTURE%" == "x86" set MSVC_PLATFORM_MACHINE=win32

set MSVC_PLATFORM_VERSION=2022
set MSVC_PLATFORM_PATH=C:\Program Files\Microsoft Visual Studio\%MSVC_PLATFORM_VERSION%\Community\VC\Auxiliary\Build\
if exist "%MSVC_PLATFORM_PATH%\vcvarsall.bat" goto PlatformDetected
set MSVC_PLATFORM_VERSION=2019
set MSVC_PLATFORM_PATH=C:\Program Files (x86)\Microsoft Visual Studio\%MSVC_PLATFORM_VERSION%\Community\VC\Auxiliary\Build\
if exist "%MSVC_PLATFORM_PATH%\vcvarsall.bat" goto PlatformDetected
set MSVC_PLATFORM_VERSION=2017
set MSVC_PLATFORM_PATH=C:\Program Files (x86)\Microsoft Visual Studio\%MSVC_PLATFORM_VERSION%\Community\VC\Auxiliary\Build\
if exist "%MSVC_PLATFORM_PATH%\vcvarsall.bat" goto PlatformDetected
goto :eof

:PlatformDetected

set XYO_PLATFORM=%MSVC_PLATFORM_MACHINE%-msvc-%MSVC_PLATFORM_VERSION%
