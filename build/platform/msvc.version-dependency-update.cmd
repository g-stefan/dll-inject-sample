@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo - %BUILD_PROJECT% ^> version-dependency-update

xyo-cc --update-version-dependency %BUILD_PROJECT%
