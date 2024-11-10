@echo off

if %_me%=="" exit /b 1

cd %~dp0
set myDir=%cd%
cd ..
set rootDir=%cd%
set testsDir=%cd%\tests
set srcDir=%cd%\code
set buildDir=%cd%\build
set binDir=%cd%\submodules\sombin
set reportsDir=%CD%\reports_%tool%

set tmpCmd=%buildDir%\tmp.cmd
set tmpFile=%buildDir%\tmp.tmp

set solution=%myDir%\Tests.sln

if not exist %solution% (
    echo use premake5 to generate %solution%
    exit /b 1
)

rem required tools
set docopts=%binDir%\somcpp\docopts.exe
set covbr2html=%binDir%\covbr2html\covbr2html.exe
for %%f in (%docopts% %covbr2html%) do (
    if not exist %%f (
        echo %%~nxf not found
        exit /b 1
    )
)

md %buildDir% 2>NUL

set optsTxt=%myDir%\options.txt

%docopts% %optsTxt% %* > %tmpCmd%
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
