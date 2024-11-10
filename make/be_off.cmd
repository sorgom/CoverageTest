@echo off
rem if cov01 installed:
rem - make sure Bullseye Coverage is off

if "%tmpFile%" == "" exit /b 1

SETLOCAL

call where cov01 | grep -c cov01.exe > %tmpFile%
set /p _beInstalled=<%tmpFile%

if %_beInstalled% NEQ 0 call cov01 -q --off
