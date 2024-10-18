@echo off
rem common setup for CTC and Bullseye scripts
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

echo - setup

cd /d %~dp0
set subsDir=%cd%
cd ..
set makeDir=%cd%
cd ..
set repoDir=%cd%
cd %makeDir%

set project=CoverageTest
set buildDir=%repoDir%\build
set cmakeDir=%makeDir%\cmakelists
set codeDir=%repoDir%\code
set executable=%project%.exe
set solution=%project%.sln
set tmpFile=tmp.tmp
set trg=%project%

set config=%1
if "%config%" == "" set config=1998
if "%_nocopy%" == "" cp Makefile *.make *.sln *.vcxproj %buildDir%

cd %buildDir%
