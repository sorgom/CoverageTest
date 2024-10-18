@echo off
rem CTC build, run & report
rem using ctclaunch msbuild
rem solution generated by premake5

SETLOCAL
set _me=%~n0
call %~dp0_ctc_setup.cmd %*

set cleanCmd=msbuild -t:clean -p:configuration=%config% %solution%
set buildCmd=ctclaunch %ctclaunchParams% msbuild -t:%trg% %msbuildParams% -p:configuration=%config% %solution%

call %myDir%\_ctc_report.cmd
