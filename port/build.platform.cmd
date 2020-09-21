@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

set ACTION=%1
if "%1" == "" set ACTION=make
if not exist port\build.platform.%ACTION%.cmd goto BuildStepError
call port\build.platform.%ACTION%.cmd
if errorlevel 1 goto BuildStepError
goto :eof
:BuildStepError
exit 1
