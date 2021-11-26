@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

if "%XYO_PLATFORM%" == "" goto :eof
if "%XYO_PATH_REPOSITORY%" == "" goto :eof
if "%XYO_PATH_RELEASE%" == "" goto :eof

if exist .\build\msvc.config.cmd call .\build\msvc.config.cmd

set ACTION=%1
if "%ACTION%" == "" set ACTION=make
set ACTION_CMD=build\msvc.%ACTION%.cmd
if exist build\msvc.%ACTION%.cmd goto BuildActionOk
set ACTION_CMD=build\platform\msvc.%ACTION%.cmd
if exist build\platform\msvc.%ACTION%.cmd goto BuildActionOk
set ACTION=make
set ACTION_CMD=build\msvc.%ACTION%.cmd
if exist build\msvc.%ACTION%.cmd goto BuildActionOk
set ACTION_CMD=build\platform\msvc.%ACTION%.cmd
:BuildActionOk

set RESTORE_PATH=%PATH%
set RESTORE_INCLUDE=%INCLUDE%
set RESTORE_LIB=%LIB%

set PATH=%XYO_PATH_REPOSITORY%\bin;%PATH%
set INCLUDE=%XYO_PATH_REPOSITORY%\include;%INCLUDE%
set LIB=%XYO_PATH_REPOSITORY%\lib;%LIB%

if not exist output\ goto BuildSetPathOutputSkip
pushd output
set PATH=%CD%;%PATH%
popd
:BuildSetPathOutputSkip

if not exist output\bin\ goto BuildSetPathOutputBinSkip
pushd output\bin
set PATH=%CD%;%PATH%
popd
:BuildSetPathOutputBinSkip

call %ACTION_CMD% %1
if errorlevel 1 goto BuildStepError
goto BuildStepDone

:BuildStepError
set PATH=%RESTORE_PATH%
set INCLUDE=%RESTORE_INCLUDE%
set LIB=%RESTORE_LIB%
exit 1
:BuildStepDone
set PATH=%RESTORE_PATH%
set INCLUDE=%RESTORE_INCLUDE%
set LIB=%RESTORE_LIB%

