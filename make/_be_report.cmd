@echo off
rem common reporting for Bullseye scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

call %myDir%\_bc_run.cmd

if %errorlevel% NEQ 0 exit /b %errorlevel%

call covselect -qd
call covselect -q --import %excludeFile%

cd %codeDir%
echo - html
call covhtml -q --allNum %htmlFolder%
echo - report
call covsrc -qm --srcdir . | tee %buildReport%
