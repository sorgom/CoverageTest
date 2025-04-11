"""ms build and run available tests with Bullseye coverage"""
from coverage_common import testList, sysCall, proc, vsBuild, checkArgs, myDir, repo, exeDir, srcDir, vsDir

import atexit
from os import chdir, makedirs, environ
from os.path import join
from sys import argv

reportsDir = join(repo, 'reports_Bullseye')
report = join(reportsDir, 'coverage.md')
excludeFile = join(myDir, 'BullseyeCoverageExclusions')

def covRestore():
    """restore cov01 setting"""
    sysCall('cov01 -q --pop')

def buildAndRun(test:str, fh):
    """build, run and report"""
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

def run(tests):
    """run tests"""
    makedirs(reportsDir, exist_ok=True)
    with open(report, 'w') as fh:
        atexit.register(covRestore)
        environ['COVCOPT'] = f'--srcdir {srcDir} --macro -q'
        sysCall('cov01 -q --push')

        sysCall('cov01 -q --off')
        vsBuild('testlib')

        sysCall('cov01 -q --on')
        for test in tests:
            buildAndRun(test, fh)

        fh.close()

if __name__ == '__main__':
    checkArgs()
    vsBuild('clean')
    run(argv[1:] or testList())
