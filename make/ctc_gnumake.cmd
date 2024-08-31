@echo off
SETLOCAL

cd /d %~dp0
set myDir=%cd%
cd ..
set repoDir=%cd%
cd %myDir%
set cmakeDir=%myDir%\cmakelists
set codeDir=%repoDir%\code
set executable=bin\CoverageTest.exe
set makefile=CoverageTest.make
set buildReport=ctc_build.log
set tmpFile=tmp.tmp
set symFile=MON.sym
set covFile=MON.dat
set eCode=0
set ctclaunchParams=-C "NO_EXCLUDE+*\code\*" -C "CONST_INSTR = ON" -i m 

rem make sure Bullseye Coverage is off
cov01 -qs | grep -c "enabled" > %tmpFile%
set /p _covEnabled=<%tmpFile%
rm -f %tmpFile%
call cov01 -q --off

if exist %symFile% rm -f %symFile%
if exist %covFile% rm -f %covFile%

call gnumake -f %makefile% clean
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
if %_covEnabled% == 1 call cov01 -q --on

exit /b %eCode%
