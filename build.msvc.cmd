@echo off
if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\" goto Error_MSVC
rem ---
if "%1" == "win32" goto Win32
if "%1" == "win64" goto Win64
if "%1" == "clean" goto Clean
goto Error_Unknown_Platform

:Win64
if "%XYO_PLATFORM%" == "win64-msvc" goto Build
set XYO_PLATFORM=win64-msvc
pushd "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build"
call vcvarsall.bat x64
popd
goto Build

:Win32
if "%XYO_PLATFORM%" == "win32-msvc" goto Build
set XYO_PLATFORM=win32-msvc
pushd "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build"
call vcvarsall.bat x86
popd
goto Build

:Clean
rmdir /Q /S bin
rmdir /Q /S build
echo ^> clean done ^<
goto :eof

:Build
if not "%XYO_PATH_REPOSITORY%" == "" goto BuildStep
set XYO_PATH_REPOSITORY=..\.repository\%XYO_PLATFORM%
:BuildStep

set XYO_CC=%XYO_PATH_REPOSITORY%\bin\xyo-cc.exe

%XYO_CC% --mode=%2 --dll dll-inject-sample --no-def-dynamic-link --no-lib --inc=. --use-project=libxyo-win-inject.static
IF ERRORLEVEL 1 goto Error_Build
if "%2" == "version" goto :eof
goto :eof

rem ---

:Error_Build
echo Error: build
goto :eof
:Error_MSVC
echo Error: not found - Microsoft Visual Studio 2017 Community
goto :eof
:Error_Unknown_Platform
echo Error: uknown platorm please provide win32 or win64
goto :eof
