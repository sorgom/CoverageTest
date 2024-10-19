@echo off
rem common setup for CTC scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

set _who=ctc

call %~dp0_setup.cmd %*

set buildReport=%buildDir%\ctc_build.log
set ctclaunchParams=-C "NO_EXCLUDE+*\code\*" -C "CONST_INSTR = ON" -i m 
set msbuildParams=-p:TrackFileAccess=false
set monFile=%makeDir%\MON.sym
set datFile=%makeDir%\MON.dat

if exist %monFile% rm -f %monFile%
if exist %datFile% rm -f %datFile%

call %subsDir%\_be_off.cmd off
