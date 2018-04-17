@echo off
rem --- <core>

if not "%1" == "clean" goto SelectPlatform
rmdir /Q /S bin
rmdir /Q /S build
rmdir /Q /S lib
echo ^> clean done ^<
goto :eof

:SelectPlatform
set ACTION=%1
if "%XYO_PLATFORM%" == "win64-msvc" goto Build
if "%XYO_PLATFORM%" == "win32-msvc" goto Build
set ACTION=%2
if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\" goto Error_MSVC
if "%1" == "win64" goto Win64
if "%1" == "win32" goto Win32
goto Error_Unknown_Platform

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
if not "%XYO_PATH_REPOSITORY%" == "" goto BuildStep
set XYO_PATH_REPOSITORY=..\.repository\%XYO_PLATFORM%
:BuildStep

rem --- </core>

rem --- <make>

set XYO_CC=%XYO_PATH_REPOSITORY%\bin\xyo-cc.exe

%XYO_CC% --mode=%ACTION% --dll dll-inject-sample --no-def-dynamic-link --no-lib --inc=. --use-project=libxyo-win-inject.static
IF ERRORLEVEL 1 goto Error_Build
if "%ACTION%" == "version" goto :eof
goto :eof

rem --- </make>

:Error_Build
echo Error: build
goto :eof
:Error_MSVC
echo Error: not found - Microsoft Visual Studio 2017 Community
goto :eof
:Error_Unknown_Platform
echo Error: uknown platorm please provide win32 or win64
goto :eof
