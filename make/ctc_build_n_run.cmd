@echo off
rem ========================================
rem build and run sub CTC
rem ========================================
SETLOCAL
if "%_me%"=="" exit /b 1

set target=%1

echo %target%
echo - build
del /Q %monFile% %datFile% 2>NUL
msbuild %solution% -t:clean >NUL

set buildLog=%buildDir%\ctc_build_%target%.log

cd %myDir%

ctclaunch %ctclaunchParams% msbuild  %solution% -t:%target% %msbuildParams% > %buildLog% 2>&1
if %errorlevel% neq 0 (
    echo - build failed
    echo - see %buildLog%
    exit /b %elevel%
) else (
    del %buildLog%
)
set exe=%buildDir%\%target%.exe

echo - report
rem call executable without tests
%exe%
ctcreport.exe %ctcreportParams% -D ProjectName=%target% -template %myDir%\ctc_report.htm -o %reportsDir%\%target%.html >NUL
rem call executable with tests
%exe% X
ctcreport.exe %ctcreportParams% -D ProjectName=%target%_cov -template %myDir%\ctc_report.htm -o %reportsDir%\%target%_cov.html >NUL
if %_html% (
    ctcreport.exe %ctcreportParams%  -D ProjectName=%target%_cov -o %reportsDir%\html_%target%_cov >NUL
)
del %exe%
echo.
