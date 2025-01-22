@echo off
rem ========================================
rem build and run sub
rem ========================================
SETLOCAL
if "%_me%"=="" exit /b 1

set target=%1

echo %target%
echo - build
echo. >> %covReport%
echo === %target% >> %covReport%
set covfile=%reportsDir%\%target%.cov
del /Q %covfile% 2>NUL
msbuild %solution% -t:clean -m >NUL

set buildLog=%buildDir%\be_build_%target%.log
cov01 -q1
msbuild %solution% -t:%target% -m > %buildLog% 2>&1
set elevel=%errorlevel%
cov01 -q0
if %elevel% neq 0 (
    echo - build failed
    echo - see %buildLog%
    exit /b %elevel%
) else (
    del %buildLog%
)
echo - report
set exe=%buildDir%\%target%.exe
cd %srcDir%
rem reset coverage data
covclear -q
covselect -qd --import %myDir%\BullseyeCoverageExclusions
rem call executable without tests
%exe%
rem reports
covbr -qu --srcdir . > %buildDir%\todo_%target%.txt
if %_html% covhtml -q --allNum --srcdir . %reportsDir%\html_%target%
%exe% X >> %covReport%
covdir -q --srcdir . --checkmin 100,100
if %errorlevel% neq 0 (
    covbr -qu --srcdir . > %buildDir%\todo_%target%_cov.txt
    if %_html% covhtml -q --allNum --srcdir . %reportsDir%\html_%target%_cov
)
covsrc -q --srcdir . >> %covReport%
covsrc -q -c --srcdir . | sed "s/,/;/g" > %reportsDir%\csv_%target%_cov.csv
del %exe%
