@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo - %BUILD_PROJECT% ^> version-install

set INSTALL_PATH=%XYO_PATH_REPOSITORY%
set INSTALL_PATH_LIB=%XYO_PATH_REPOSITORY%\lib

rem Do this before version-dependency to update version without build

copy /Y /B version.ini %INSTALL_PATH_LIB%\%BUILD_PROJECT%.version.ini
