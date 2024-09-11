@echo off
rem CTC build, run & report
rem using ctclaunch msbuild
rem solution generated by premake5

SETLOCAL
set _me=%~n0
call %~dp0ctc__setup.cmd

echo - clean
call msbuild /t:clean %solution% >NUL 2>&1
echo - build
call ctclaunch %ctclaunchParams% msbuild %solution% /t:%trg% %msbuildParams% > %buildReport% 2>&1

call %myDir%\ctc__run.cmd
