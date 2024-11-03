@echo off
rem common reporting for Bullseye scripts
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

call %subsDir%\_run.cmd

if %errorlevel% NEQ 0 exit /b %errorlevel%

call covselect -qd
call covselect -q --import %excludeFile%

cd %codeDir%
echo - report: %covReport%
call covsrc -qm --srcdir . | tee %covReport%

call covbr -q -u -c3 --srcdir . | sed "s|^.*/code/||" > %covTodo%

if exist %covbr2html% call %covbr2html% -c %covTodo%
