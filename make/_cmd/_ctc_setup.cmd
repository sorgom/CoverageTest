@echo off
rem common setup for CTC scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

set _who=ctc

call %~dp0_setup.cmd %*
if not %errorlevel% == 0 exit /b 1

set buildReport=%buildDir%\ctc_build.log
set ctclaunchParams=-C "NO_EXCLUDE+*\code\*" -C "CONST_INSTR = ON" -i m
set ctcreportParams=-t 98 -nsb -include-justifications -restrict-to-files "*/code/*" -measures f,mcdc -D ProjectName=%config%%covArg%
set ctcTxtTemplate=%subsDir%\_ctc_report.txt
set ctcHtmTemplate=%subsDir%\_ctc_report_2.htm
set msbuildParams=-p:TrackFileAccess=false
set monFile=%makeDir%\MON.sym
set datFile=%makeDir%\MON.dat

if exist %monFile% rm -f %monFile%
if exist %datFile% rm -f %datFile%

call %subsDir%\_be_off.cmd off
