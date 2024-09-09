@echo off
SETLOCAL
set _me=%~n0
call %~dp0ctc_setup.cmd

@REM cd /d %~dp0
@REM set myDir=%cd%
@REM cd ..
@REM set repoDir=%cd%
@REM cd %myDir%
@REM set codeDir=%repoDir%\code
@REM set solution=CoverageTest.sln
@REM set trg=CoverageTest
@REM set msbuildParams=-p:TrackFileAccess=false
@REM set ctclaunchParams=-C "NO_EXCLUDE+*\code\*" -C "CONST_INSTR = ON" -i m 
@REM set executable=exe\CoverageTest.exe
@REM set buildReport=ctc_build.log
@REM set tmpFile=tmp.tmp
@REM set symFile=MON.sym
@REM set covFile=MON.dat
@REM set eCode=0

call be_off.cmd
echo - clean
call msbuild /t:clean %solution% >NUL 2>&1
if exist %symFile% rm -f %symFile%
if exist %covFile% rm -f %covFile%
echo - build
call ctclaunch %ctclaunchParams% msbuild %solution% /t:%trg% %msbuildParams% > %buildReport% 2>&1
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
call ctcreport.exe -nsb -restrict-to-files "*/code/*" -measures f,mcdc -o %myDir%\html_ctc >NUL
:end
call be_restore.cmd
exit /b %eCode%
