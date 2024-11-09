@echo off
SETLOCAL

cd %~dp0
set _me=%~n0
set myDir=%cd%
cd ..
set rootDir=%cd%
set testsDir=%cd%\tests
set buildDir=%cd%\build
set binDir=%cd%\submodules\sombin
set tmpCmd=%buildDir%\tmp.cmd

set optsTxt=%myDir%\_cmd\_options.txt

for %%f in (%testsDir%\*.cpp) do (
    echo %%~nf
)

%binDir%\somcpp\docopts.exe %optsTxt% %* > %tmpCmd%
call %tmpCmd%

echo %_c%
