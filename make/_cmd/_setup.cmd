@echo off
rem common setup for CTC and Bullseye scripts
rem avoid env polution by call of this sctipt
if "%_who%" == "" exit /b 1

cd /d %~dp0
set subsDir=%cd%
cd ..
set makeDir=%cd%
cd ..
set repoDir=%cd%
cd %makeDir%

set covArg=
set config=standard
for %%p in (%*) do (
    if "%%p" == "-h" (
        echo.
        echo Usage: %_me%.cmd [options] [config]
        cat %subsDir%\_options.txt
        exit /b 1
    ) else if "%%p" == "-c" (
        set covArg=_cov
    ) else (
        set config=%%p
    )
)

echo - setup

set project=CoverageTest
set buildDir=%repoDir%\build
set cmakeDir=%makeDir%\cmakelists
set codeDir=%repoDir%\code
set executable=%buildDir%\%project%.exe
set solution=%project%.sln
set makeFile=%project%.make
set tmpFile=tmp.tmp
set trg=%project%

set buildReport=%buildDir%\%_who%_build.log
set covReport=%buildDir%\%_who%_%config%%covArg%.log
set covHtm=%buildDir%\%_who%_%config%%covArg%.html
set htmlFolder=%buildDir%\html_%_who%_%config%%covArg%
