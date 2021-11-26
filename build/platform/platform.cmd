@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

if exist .\build\msvc.config.cmd call .\build\msvc.config.cmd

set ACTION=%1
if "%1" == "" set ACTION=make
set ACTION_CMD=build\platform.%ACTION%.cmd
if exist build\platform.%ACTION%.cmd goto BuildActionOk
set ACTION_CMD=build\platform\platform.%ACTION%.cmd
if exist build\platform\platform.%ACTION%.cmd goto BuildActionOk
exit 1

:BuildActionOk
call %ACTION_CMD%
if errorlevel 1 goto BuildStepError
goto :eof
:BuildStepError
exit 1
