@echo off
SETLOCAL
set _me=%~n0
call %~dp0ctc_setup.cmd

call be_off.cmd
if exist %symFile% rm -f %symFile%
if exist %covFile% rm -f %covFile%

echo - clean
call gnumake -f %makefile% clean >NUL 2>&1
echo - build
call ctclaunch %ctclaunchParams% gnumake -j -f %makefile% > %buildReport% 2>&1

if not exist %executable% (
    echo - build failed
    cat %buildReport%
    set eCode=1
    goto end
) else (
    rm -f %buildReport%
)

echo - run
call %executable%
echo - report
call ctcreport.exe -nsb -t 25 -restrict-to-files "*/code/*" -measures f,mcdc -o html_ctc >NUL
echo - report returned: %errorlevel%

:end
call be_restore.cmd
exit /b %eCode%
