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
set buildReport=%buildDir%\ctc_build.log
set tmpFile=tmp.tmp
set symFile=MON.sym
set covFile=MON.dat
set eCode=0

rem make sure Bullseye Coverage is off
cov01 -qs | grep -c "enabled" > %tmpFile%
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
nmake.exe > %buildReport% 2>&1
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
