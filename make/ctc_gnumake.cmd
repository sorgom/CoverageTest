@echo off
rem CTC build, run & report
rem using ctclaunch gnumake
rem make file generated by premake5

SETLOCAL
set _me=%~n0
call %~dp0ctc__setup.cmd

set config=%1
if "%config%" == "" set config=1998

echo - clean
call gnumake clean >NUL 2>&1
echo - build
call ctclaunch %ctclaunchParams% gnumake -j config=%config% > %buildReport% 2>&1

call %myDir%\ctc__run.cmd
