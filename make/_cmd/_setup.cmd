@echo off
rem common setup for CTC and Bullseye scripts
rem avoid env polution by call of this sctipt
if "%_who%" == "" exit /b 1

echo - setup

cd /d %~dp0
set subsDir=%cd%
cd ..
set makeDir=%cd%
cd ..
set repoDir=%cd%
cd %makeDir%

set buildReport=%buildDir%\%_who%_build.log
set covReport=%buildDir%\%_who%_coverage.log
set htmlFolder=%buildDir%\html_%_who%

set project=CoverageTest
set buildDir=%repoDir%\build
set cmakeDir=%makeDir%\cmakelists
set codeDir=%repoDir%\code
set executable=%buildDir%\%project%.exe
set solution=%project%.sln
set makeFile=%project%.make
set tmpFile=tmp.tmp
set trg=%project%

set config=%1
if "%config%" == "" set config=1998
