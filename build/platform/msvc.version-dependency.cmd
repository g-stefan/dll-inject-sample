@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo - %BUILD_PROJECT% ^> version-dependency

rem Do version-install before this to update versions without build.

xyo-cc --bump-version-minor-if-version-dependency %BUILD_PROJECT%
