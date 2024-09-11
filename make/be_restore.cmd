@echo off
rem restore Bullseye Coverage on / off

if "%_beCovActive%" == "" exit /b 0
if %_beCovActive% == 1 (
    echo - set Bullseye Coverage on
    call cov01 -q --on
)
