@echo off
SETLOCAL

cd /d %~dp0
set myDir=%cd%
cd ..
set repoDir=%cd%
cd %myDir%
set codeDir=%repoDir%\code
set solution=CovrageTest.sln
set trg=CoverageTest
set buildParams=-p:TrackFileAccess=false
set executable=exe\CoverageTest.exe
set buildReport=ctc_build.log
set tmpFile=tmp.tmp
set symFile=MON.sym
set covFile=MON.dat

cov01 -qs | grep -c "Coverage build enabled" > %tmpFile%
set /p _covEnabled=<%tmpFile%
rm -f %tmpFile%
call cov01 -q --off
echo - clean
call msbuild /t:clean %solution% >NUL 2>&1
if exist %symFile% rm -f %symFile%
if exist %covFile% rm -f %covFile%
echo - build
call ctclaunch -i m msbuild %solution% /t:%trg% %buildParams% > %buildReport% 2>&1
if not exist %executable% (
    echo - build failed
    exit /b 1
) else (
    rm -f %buildReport%
)
echo - run
call %executable%
echo - report
call ctcreport.exe -nsb -restrict-to-files "*/code/*" -measures f,mcdc -o %myDir%\html_ctc >NUL
if %_covEnabled% == 1 (
    call cov01 -q --on
)
