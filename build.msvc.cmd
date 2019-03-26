@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

rem --- core

if not "%1" == "clean" goto SelectPlatform
call build.msvc.clean.cmd
goto :eof

:SelectPlatform
set ACTION=%1
if "%1" == "win64" set ACTION=%2
if "%1" == "win32" set ACTION=%2
if "%XYO_PLATFORM%" == "win64-msvc" goto Build
if "%XYO_PLATFORM%" == "win32-msvc" goto Build
set ACTION=%2
if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\" goto NoPlatform
if "%1" == "win64" goto Win64
if "%1" == "win32" goto Win32
echo Error: uknown platform please provide win32 or win64
goto :eof
:NoPlatform
echo Error: not found - Microsoft Visual Studio 2017 Community
goto :eof

:Win64
set XYO_PLATFORM=win64-msvc
pushd "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build"
call vcvarsall.bat x64
popd
goto Build

:Win32
set XYO_PLATFORM=win32-msvc
pushd "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build"
call vcvarsall.bat x86
popd
goto Build

:Build
set RESTORE_PATH=%PATH%
set PATH_REPOSITORY=..\repository
set PATH_RELEASE=..\release
if not "%XYO_PATH_REPOSITORY%" == "" goto BuildStep1
if exist ..\..\sdk.build.msvc.cmd goto BuildWithSDK
if exist ..\build.msvc.config.cmd call ..\build.msvc.config.cmd
goto BuildRepositoryPath
:BuildWithSDK
set PATH_REPOSITORY=..\..\repository
set PATH_RELEASE=..\..\release
:BuildRepositoryPath
if not exist %PATH_REPOSITORY%\ mkdir %PATH_REPOSITORY%
pushd %PATH_REPOSITORY%
set XYO_PATH_REPOSITORY=%CD%
popd
if not exist %PATH_RELEASE%\ mkdir %PATH_RELEASE%
pushd %PATH_RELEASE%
set XYO_PATH_RELEASE=%CD%
popd
:BuildStep1
set PATH=%XYO_PATH_REPOSITORY%\bin;%PATH%
if not exist bin\ goto BuildStep2
pushd bin
set PATH=%CD%;%PATH%
popd
:BuildStep2

call build.msvc.make.cmd

set PATH=%RESTORE_PATH%
