@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

rem --- clean

echo -^> clean dll-inject-sample

if exist bin\ rmdir /Q /S bin
if exist build\ rmdir /Q /S build
if exist lib\ rmdir /Q /S lib
if exist .vscode\ipch\ rmdir /Q /S .vscode\ipch

