@echo off
rem CTC build, run & report
rem using nmake
rem make file generated using cmake

SETLOCAL
set _me=%~n0
call %~dp0ctc_setup.cmd

call be_off.cmd
if exist %buildDir% rm -rf %buildDir%
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
call %reportCall%
echo - report returned: %errorlevel%
:end
call %myDir%\be_restore.cmd
exit /b %eCode%
