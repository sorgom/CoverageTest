@echo off
rem common reporting for CTC scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

call %subsDir%\_run.cmd

if %errorlevel% == 0 (
    echo - report
    call ctcreport.exe -t 98 -nsb  -include-justifications -restrict-to-files "*/code/*" -measures f,mcdc -o %htmlFolder%
)
if exist %monFile% rm -f %monFile%
if exist %datFile% rm -f %datFile%
