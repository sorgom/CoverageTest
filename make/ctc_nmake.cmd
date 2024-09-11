@echo off
rem CTC build, run & report
rem using nmake
rem make file generated using cmake

SETLOCAL
set _me=%~n0
call %~dp0ctc__setup.cmd X

echo - gen
cp -r %cmakeDir%/* ./
cmake -S . -B . -G "NMake Makefiles"
echo - clean
set MAKE=nmake
nmake.exe clean
echo - build
nmake.exe > %buildReport% 2>&1

call %myDir%\ctc__run.cmd
