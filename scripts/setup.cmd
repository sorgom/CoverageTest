@echo off

if %_me%=="" exit /b 1

cd %~dp0
set myDir=%cd%
cd ..
set repo=%cd%
set buildDir=%repo%\build
set exeDir=%buildDir%\windows
set pyDir=%repo%\submodules\sompy
set reportsDir=%repo%\reports_%tool%
set srcDir=%repo%\code
set testsDir=%repo%\tests
set vsDir=%repo%\vs

set tmpCmd=%buildDir%\tmp.cmd
set tmpFile=%buildDir%\tmp.tmp

set solution=%vsDir%\Tests.sln

if not exist %solution% (
    echo use premake5 to generate %solution%
    exit /b 1
)

md %buildDir% 2>NUL

set optsTxt=%myDir%\options.txt

%pyDir%\somutil\docopts.py %optsTxt% %* > %tmpCmd%
if %errorlevel% neq 0 exit /b 1
call %tmpCmd%
del %tmpCmd% 2>NUL

rem help
if %_h% (
    echo usage: %_me% [options] [targets]
    type %optsTxt%
    exit /b 1
)

rem list targets
if %_l% (
    echo targets:
    for %%f in (%testsDir%\*.cpp) do echo %%~nf
    exit /b 1
)

rem clean build and reports
if %_c% (
    del /Q /S %buildDir% >NUL 2>&1
    del /Q /S %reportsDir% >NUL 2>&1
)

rem enable HTML (uppercase H option)
set _html=%_Hu%

set start=%time%
md %reportsDir% 2>NUL

exit /b 0
