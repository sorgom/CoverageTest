@echo off
rem CTC build, run & report
rem using ctclaunch gnumake
rem make file generated by premake5

SETLOCAL
set _me=%~n0
call %~dp0_cmd\_ctc_setup.cmd %*
if %errorlevel% NEQ 0 exit /b 0

set cleanCmd=gnumake -j clean
set buildCmd=ctclaunch %ctclaunchParams% gnumake -j config=%config%

call %subsDir%\_ctc_report.cmd
