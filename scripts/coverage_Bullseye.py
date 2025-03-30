"""ms build run all available tests with Bullseye coverage"""
from coverage_common import testList, sysCall, proc, vsBuild, myDir, repo, exeDir, srcDir, vsDir, vsSolution

import atexit
from os import chdir, makedirs, environ
from os.path import join
from sys import argv


reportsDir = join(repo, 'reports_bullseye')
report = join(reportsDir, 'coverage.md')
excludeFile = join(myDir, 'BullseyeCoverageExclusions')

makedirs(reportsDir, exist_ok=True)

fh = open(report, 'w')

environ['COVCOPT'] = f'--srcdir {srcDir} --macro -q'

def covRestore():
    """restore cov01 setting"""
    sysCall('cov01 -q --pop')

atexit.register(covRestore)

def buildAndRun(test:str):
    """build and run test"""
    chdir(vsDir)
    environ['COVFILE'] = join(reportsDir, f'{test}.cov')
    vsBuild(test)
    sysCall('covclear -q')
    fh.write(f'### {test}\n```\n')
    proc(join(exeDir, f'{test}.exe X'), fh)
    chdir(reportsDir)
    sysCall(f'covselect -qd --import {excludeFile}')
    proc(f'covsrc -q --by-name', fh)
    fh.write('```\n\n')

sysCall('cov01 -q --push')
sysCall('cov01 -q --on')

# vsBuild('Clean')

for test in argv[1:] or testList():
    buildAndRun(test)
