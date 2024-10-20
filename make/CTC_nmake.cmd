@echo off
rem CTC build, run & report
rem using nmake
rem make file generated using cmake

SETLOCAL
set _me=%~n0
set _nocopy=1
call %~dp0_cmd\_ctc_setup.cmd %*
if %errorlevel% NEQ 0 exit /b 0

echo - gen
cp -r %cmakeDir%/* ./
cmake -S . -B . -G "NMake Makefiles"
set MAKE=nmake
set cleanCmd=nmake.exe clean
set buildCmd=nmake.exe

call %subsDir%\_ctc_report.cmd
