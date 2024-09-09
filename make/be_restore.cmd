@echo off
rem restore Bullseye Coverage on / off

if "%_beEnabled%" == "" exit /b 0
if %_beEnabled% == 1 call cov01 -q --on
