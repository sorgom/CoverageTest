@echo off
rem common setup for CTC scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

echo - setup

cd /d %~dp0
set myDir=%cd%
cd ..
set repoDir=%cd%
cd %myDir%

set project=CoverageTest
set buildDir=%repoDir%\build
set buildReport=%buildDir%\ctc_build.log
set cmakeDir=%myDir%\cmakelists
set codeDir=%repoDir%\code
set ctclaunchParams=-C "NO_EXCLUDE+*\code\*" -C "CONST_INSTR = ON" -i m 
set executable=%project%.exe
set htmlFolder=%buildDir%\html_ctc
set makefile=%project%.make
set msbuildParams=-p:TrackFileAccess=false
set solution=%project%.sln
set tmpFile=tmp.tmp
set trg=%project%

if exist %buildDir% rm -rf %buildDir%
mkdir %buildDir%

call be_off.cmd

if "%1" == "" cp *.make *.sln *.vcxproj %buildDir%

cd %buildDir%
