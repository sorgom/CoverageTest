@echo off
SETLOCAL

cd /d %~dp0
set myDir=%cd%
cd ..
set repoDir=%cd%
cd %myDir%
set codeDir=%repoDir%\code
set solution=CoverageTest.sln
set trg=CoverageTest
set msbuildParams=-p:TrackFileAccess=false
set ctclaunchParams=-C "NO_EXCLUDE+*\code\*" -i m 
@REM set ctclaunchParams=-i m
set executable=exe\CoverageTest.exe
set buildReport=ctc_build.log
set tmpFile=tmp.tmp
set symFile=MON.sym
set covFile=MON.dat
set eCode=0

cov01 -qs | grep -c "enabled" > %tmpFile%
set /p _covEnabled=<%tmpFile%
rm -f %tmpFile%
call cov01 -q --off
echo - clean
call msbuild /t:clean %solution% >NUL 2>&1
if exist %symFile% rm -f %symFile%
if exist %covFile% rm -f %covFile%
echo - build
call ctclaunch %ctclaunchParams% msbuild %solution% /t:%trg% %msbuildParams% > %buildReport% 2>&1
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
call ctcreport.exe -nsb -restrict-to-files "*/code/*" -measures f,mcdc -o %myDir%\html_ctc >NUL
:end
if %_covEnabled% == 1 call cov01 -q --on

exit /b %eCode%
