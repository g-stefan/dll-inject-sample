@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

set MSVC_PLATFORM_MACHINE=win64
set MSVC_PLATFORM_VERSION=2019
set MSVC_PLATFORM_PATH=C:\Program Files (x86)\Microsoft Visual Studio\%MSVC_PLATFORM_VERSION%\Community\VC\Auxiliary\Build\

if "%MSVC_PLATFORM_ACTIVE%" == "%MSVC_PLATFORM_MACHINE%-%MSVC_PLATFORM_VERSION%" goto PlatformAlreadyActive
pushd "%MSVC_PLATFORM_PATH%"
call vcvarsall.bat x64
popd
set MSVC_PLATFORM_ACTIVE=%MSVC_PLATFORM_MACHINE%-%MSVC_PLATFORM_VERSION%
:PlatformAlreadyActive

set XYO_PLATFORM=%MSVC_PLATFORM_MACHINE%-msvc-%MSVC_PLATFORM_VERSION%
set XYO_PATH_REPOSITORY=%HOMEDRIVE%%HOMEPATH%\SDK\%XYO_PLATFORM%
set XYO_PATH_RELEASE=%HOMEDRIVE%%HOMEPATH%\SDK\%XYO_PLATFORM%\release

cmd.exe /C "build\platform\msvc.cmd %1"
