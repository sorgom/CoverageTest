@echo off
rem common setuo for CTC scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

cd /d %~dp0
set myDir=%cd%
cd ..
set repoDir=%cd%
cd %myDir%

set buildDir=%repoDir%\build
set buildReport=%myDir%\ctc_build.log
set cmakeDir=%myDir%\cmakelists
set codeDir=%repoDir%\code
set covFile=MON.dat
set ctclaunchParams=-C "NO_EXCLUDE+*\code\*" -C "CONST_INSTR = ON" -i m 
set eCode=0
set executable=CoverageTest.exe
set htmlFolder=%myDir%\html_ctc
set makefile=CoverageTest.make
set msbuildParams=-p:TrackFileAccess=false
set solution=CoverageTest.sln
set symFile=MON.sym
set tmpFile=tmp.tmp
set trg=CoverageTest

set reportCall=ctcreport.exe -t 98 -nsb -restrict-to-files "*/code/*" -measures f,mcdc -o %htmlFolder%