@echo off
SETLOCAL

cd /d %~dp0
set myDir=%cd%
cd ..
set repoDir=%cd%
cd %myDir%
set buildDir=%repoDir%\build
set cmakeDir=%myDir%\cmakelists
set codeDir=%repoDir%\code
set executable=CoverageTest.exe
set buildReport=ctc_build.log
set tmpFile=tmp.tmp
set symFile=MON.sym
set covFile=MON.dat

rem make sure Bullseye Coverage is off
cov01 -qs | grep -c "Coverage build enabled" > %tmpFile%
set /p _covEnabled=<%tmpFile%
rm -f %tmpFile%
call cov01 -q --off

if exist %buildDir% rm -f %buildDir%
mkdir %buildDir%
cd %buildDir%
echo - gen
cp -r %cmakeDir%/* ./
cmake -S . -B . -G "NMake Makefiles"
echo - clean
set MAKE=nmake
if exist %symFile% rm -f %symFile%
if exist %covFile% rm -f %covFile%
nmake.exe clean
echo - build
nmake.exe

echo - run
call %executable%
echo - report
call ctcreport.exe -nsb -restrict-to-files "*/code/*" -measures f,mcdc -o html_ctc >NUL
@REM call ctcreport.exe -nsb -measures f,mcdc -o html_ctc >NUL
if %_covEnabled% == 1 (
    echo - restore Bullseye Coverage
    call cov01 -q --on
)
