@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo -^> version-install dll-inject-sample

set INSTALL_PATH=%XYO_PATH_REPOSITORY%
set INSTALL_PATH_LIB=%XYO_PATH_REPOSITORY%\lib

rem // ---

copy /Y /B version.ini %INSTALL_PATH_LIB%\dll-inject-sample.version.ini

