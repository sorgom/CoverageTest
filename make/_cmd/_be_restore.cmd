@echo off
rem restore Bullseye Coverage on / off

if "%_beCovActive%" == "" exit /b 0

SETLOCAL

if %_beCovActive% == 1 (
    set state=on
) else (
    set state=off
)

echo - restore Bullseye Coverage: %state%
call cov01 -q --%state%

set _beCovActive=
