@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

if exist .\port\build.msvc.config.cmd call .\port\build.msvc.config.cmd

set ACTION=%1
set MSVC_PLATFORM_MACHINE=win64
if "%1" == "" set ACTION=make
if "%1" == "win64" set ACTION=%2
if "%1" == "win64" set MSVC_PLATFORM_MACHINE=win64
if "%1" == "win32" set ACTION=%2
if "%1" == "win32" set MSVC_PLATFORM_MACHINE=win32
if "%ACTION%" == "" set ACTION=make
if "%XYO_PLATFORM%" == "win64-msvc-2019" goto Build
if "%XYO_PLATFORM%" == "win32-msvc-2019" goto Build
if "%XYO_PLATFORM%" == "win64-msvc-2017" goto Build
if "%XYO_PLATFORM%" == "win32-msvc-2017" goto Build
set MSVC_PLATFORM_VERSION=2019
set MSVC_PLATFORM_PATH=C:\Program Files (x86)\Microsoft Visual Studio\%MSVC_PLATFORM_VERSION%\Community\VC\Auxiliary\Build\
if exist "%MSVC_PLATFORM_PATH%\vcvarsall.bat" goto SelectPlatformMachine
set MSVC_PLATFORM_VERSION=2017
set MSVC_PLATFORM_PATH=C:\Program Files (x86)\Microsoft Visual Studio\%MSVC_PLATFORM_VERSION%\Community\VC\Auxiliary\Build\
if exist "%MSVC_PLATFORM_PATH%\vcvarsall.bat" goto SelectPlatformMachine
echo Error: not found - Microsoft Visual Studio Community
goto :eof

:SelectPlatformMachine
if "%MSVC_PLATFORM_MACHINE%" == "win64" goto Win64
if "%MSVC_PLATFORM_MACHINE%" == "win32" goto Win32
echo Error: uknown platform please provide win32 or win64
goto :eof

:Win64
set XYO_PLATFORM=win64-msvc-%MSVC_PLATFORM_VERSION%
pushd "%MSVC_PLATFORM_PATH%"
call vcvarsall.bat x64
popd
goto Build

:Win32
set XYO_PLATFORM=win32-msvc-%MSVC_PLATFORM_VERSION%
pushd "%MSVC_PLATFORM_PATH%"
call vcvarsall.bat x86
popd
goto Build

:Build
set RESTORE_PATH=%PATH%
if not "%XYO_PATH_REPOSITORY%" == "" goto BuildSetPath
set PATH_REPOSITORY=.\repository
set PATH_RELEASE=.\release
if not exist %PATH_REPOSITORY%\ mkdir %PATH_REPOSITORY%
pushd %PATH_REPOSITORY%
set XYO_PATH_REPOSITORY=%CD%
popd
if not exist %PATH_RELEASE%\ mkdir %PATH_RELEASE%
pushd %PATH_RELEASE%
set XYO_PATH_RELEASE=%CD%
popd
:BuildSetPath
set PATH=%XYO_PATH_REPOSITORY%\bin;%PATH%
if not exist bin\ goto BuildBegin
pushd bin
set PATH=%CD%;%PATH%
popd
:BuildBegin

if not exist port\build.msvc.%ACTION%.cmd goto BuildDoMake
call port\build.msvc.%ACTION%.cmd
if errorlevel 1 goto BuildStepError
goto BuildStepDone

:BuildDoMake
call port\build.msvc.make.cmd %ACTION%
if errorlevel 1 goto BuildStepError
goto BuildStepDone

goto BuildStepDone
:BuildStepError
set PATH=%RESTORE_PATH%
exit 1
:BuildStepDone
set PATH=%RESTORE_PATH%

