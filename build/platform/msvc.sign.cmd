@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo - %BUILD_PROJECT% ^> sign

if not exist output\bin\ goto BuildStignSkipBin
pushd output\bin
for /r %%i in (*.dll) do call grigore-stefan.sign "%BUILD_PROJECT%" "%%i"
for /r %%i in (*.exe) do call grigore-stefan.sign "%BUILD_PROJECT%" "%%i"
popd

:BuildStignSkipBin
pushd output
for /r %%i in (*.dll) do call grigore-stefan.sign "%BUILD_PROJECT%" "%%i"
for /r %%i in (*.exe) do call grigore-stefan.sign "%BUILD_PROJECT%" "%%i"
popd
