@echo off
rem run & report
if "%_me%" == "" exit /b 1

if exist %buildReport% rm -f %buildReport%
if exist %htmlFolder% rm -rf %htmlFolder%

echo - clean
call %cleanCmd% >NUL 2>&1

echo - build
echo %DATE% %TIME% CFG: %config% > %buildReport%
call %buildCmd% >> %buildReport% 2>&1

call %subsDir%\_be_restore.cmd

echo - eval
if not exist %executable% (
    echo - build failed
    cat %buildReport%
    exit /b 1
) else (
    rm -f %buildReport%
)

echo - run
call %executable% %covArg%
