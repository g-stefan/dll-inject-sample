@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

SETLOCAL ENABLEDELAYEDEXPANSION

echo - %BUILD_PROJECT% ^> platform github-release-keep-last-3

if "%GITHUB_PROJECT%" == "" set GITHUB_PROJECT=%BUILD_PROJECT%

echo -^> github-release-keep-last-3 %GITHUB_PROJECT%

if not exist temp\ mkdir temp
if exist temp\github-release-delete.cmd del /Q temp\github-release-delete.cmd
github-release info --repo %GITHUB_PROJECT% --json > temp\github-release-info.json
quantum-script build\platform\platform.github-release-keep-last-3.js
if exist temp\github-release-delete.cmd call temp\github-release-delete.cmd
