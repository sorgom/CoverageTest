@echo off
rem common reporting for CTC scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

call %subsDir%\_run.cmd

if %errorlevel% == 0 (
    echo - html
    call ctcreport.exe %ctcreportParams% -o %htmlFolder% >NUL
    echo - report
    call ctcreport.exe %ctcreportParams% -template %ctcHtmTemplate%  -o %covHtm% >NUL
)
if exist %monFile% rm -f %monFile%
if exist %datFile% rm -f %datFile%
