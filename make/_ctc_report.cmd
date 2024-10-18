@echo off
rem common reporting for CTC scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

@REM if exist %datFile% rm -f %datFile%

call %myDir%\_bc_run.cmd

if %errorlevel% == 0 (
    echo - report
    call ctcreport.exe -t 98 -nsb -restrict-to-files "*/code/*" -measures f,mcdc -o %htmlFolder%
)
