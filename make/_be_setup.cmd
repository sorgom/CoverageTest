@echo off
rem common setup for Bullseye scripts 
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

call %~dp0_bc_setup.cmd %*

set buildReport=%buildDir%\bullsey_build.log
set htmlFolder=%buildDir%\html_bullseye

set covfile=%buildDir%\%project%.cov
set covcopt=--srcdir %repoDir% --macro
set excludeFile=%myDir%\_be_exclude.txt

if exist %covfile% rm -f %covfile%

call %myDir%\_be_off.cmd on
