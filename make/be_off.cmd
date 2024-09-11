@echo off
rem if cov01 installed: 
rem - make sure Bullseye Coverage is off
rem - save status

if "%tmpFile%" == "" exit /b 1

SETLOCAL

call where cov01 | grep -c cov01.exe > %tmpFile%
set /p _beInstalled=<%tmpFile%

if %_beInstalled% == 0 goto end

set state=%1
if "%state%" == "" set state=off

call cov01 -qs | grep -c "enabled" > %tmpFile%

echo - set Bullseye Coverage %state%
call cov01 -q --%state%

ENDLOCAL
set /p _beCovActive=<%tmpFile%

:end
rm -f %tmpFile%
