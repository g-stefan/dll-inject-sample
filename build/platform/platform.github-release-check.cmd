@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

SETLOCAL ENABLEDELAYEDEXPANSION

echo - %BUILD_PROJECT% ^> platform github-release-check

if "%GITHUB_PROJECT%" == "" set GITHUB_PROJECT=%BUILD_PROJECT%

set PROJECT=%BUILD_PROJECT%
if not exist version.ini echo Error - no version & exit 1
FOR /F "tokens=* USEBACKQ" %%F IN (`xyo-version --no-bump --get "--version-file=version.ini" %PROJECT%`) DO (
	SET VERSION=%%F
)

github-release info --repo %GITHUB_PROJECT% --tag v%VERSION%
