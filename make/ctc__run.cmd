@echo off
rem run & report
rem avoid env polution by call of this sctipt
if "%_me%" == "" exit /b 1

if not exist %executable% (
    echo - build failed
    cat %buildReport%
    goto end
) else (
    rm -f %buildReport%
)

echo - run
call %executable%
echo - report
call ctcreport.exe -t 98 -nsb -restrict-to-files "*/code/*" -measures f,mcdc -o %htmlFolder%
:end
call %myDir%\be_restore.cmd
