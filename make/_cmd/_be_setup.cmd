@echo off
rem common setup for Bullseye scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

set _who=bullseye

call %~dp0_setup.cmd %*
if %errorlevel% NEQ 0 exit /b 1

set covfile=%buildDir%\%config%%covArg%.cov
set covcopt=--srcdir %repoDir% --macro
set excludeFile=%subsDir%\_be_exclude.txt

if exist %covfile% rm -f %covfile%

call %subsDir%\_be_off.cmd on
