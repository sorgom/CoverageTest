from coverage_common import testList, sysCall, myDir, repo, exeDir, vsSolution
from os import chdir, makedirs, remove
from os.path import join, isfile
from sys import argv

reportsDir = join(repo, 'reports_CTC')

ctcLaunchParams = '-C "NO_EXCLUDE+*/code/*" -C "CONST_INSTR = ON" -i m'
ctcReportParams = f'-t 98 -nsb -shorten-path {repo}/ -include-justifications -restrict-to-files "*/code/*" -measures f,mcdc'
msBuildParams = '-p:TrackFileAccess=false -m'
monFile = join(myDir, 'MON.sym')
datFile = join(myDir, 'MON.dat')

makedirs(reportsDir, exist_ok=True)

def reportTemplate(target):
    """build report using template"""
    sysCall(f'ctcreport.exe {ctcReportParams} -D ProjectName={target} -template {join(myDir, 'ctc_report.htm')} -o {join(reportsDir, target)}.html')

def buildAndRun(test:str):
    """build, run and report"""
    chdir(myDir)
    if isfile(monFile): remove(monFile)
    if isfile(datFile): remove(datFile)
    sysCall(f'ctclaunch {ctcLaunchParams} msbuild {vsSolution} -t:{test} {msBuildParams}')

    exe = join(exeDir, f'{test}.exe')
    sysCall(exe)
    reportTemplate(test)
    sysCall(f'{exe} X')
    reportTemplate(f'{test}_cov')
    htmlDir = join(reportsDir, f'html_{test}_cov')
    sysCall(f'ctcreport.exe {ctcReportParams} -D ProjectName={test}_cov -o {htmlDir}')

# vsBuild('Clean')

for test in argv[1:] or testList():
    buildAndRun(test)
