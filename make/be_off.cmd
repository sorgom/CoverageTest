@echo off
rem if cov01 installed: 
rem - make sure Bullseye Coverage is off
rem - save status

if "%tmpFile%" == "" exit /b 1

call where cov01 | grep -c cov01.exe > %tmpFile%
set /p _beEnabled=<%tmpFile%

if %_beEnabled% == 0 goto end

call cov01 -qs | grep -c "enabled" > %tmpFile%
set /p _beEnabled=<%tmpFile%

call cov01 -q --off

rm -f %tmpFile%
