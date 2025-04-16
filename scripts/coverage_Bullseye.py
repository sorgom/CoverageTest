"""ms build and run available tests with Bullseye coverage"""
from coverage_common import testList, call, proc, build, checkArgs, myDir, repo, srcDir, vsDir

import atexit
from os import chdir, makedirs, environ
# from os.path import join
from sys import argv

reportsDir  = f'{repo}/reports_Bullseye'
report      = f'{reportsDir}/coverage.md'
excludeFile = f'{myDir}/BullseyeCoverageExclusions'

def covRestore():
    """restore cov01 setting"""
    call('cov01 -q --pop')

def buildAndRun(test:str, fh):
    """build, run and report"""
    environ['COVFILE'] = f'{reportsDir}/{test}.cov'
    build(test)
    call('covclear -q')
    fh.write(f'### {test}\n```\n')
    proc(f'{test} X', fh)
    chdir(reportsDir)
    call(f'covselect -qd --import {excludeFile}')
    proc(f'covsrc -q --by-name', fh)
    fh.write('```\n\n')

def run(tests):
    """run tests"""
    makedirs(reportsDir, exist_ok=True)
    with open(report, 'w') as fh:
        atexit.register(covRestore)
        environ['COVCOPT'] = f'--srcdir {srcDir} --macro -q'
        call('cov01 -q --push')

        call('cov01 -q --off')
        build('testlib')

        call('cov01 -q --on')
        for test in tests:
            buildAndRun(test, fh)

        fh.close()

if __name__ == '__main__':
    checkArgs()
    build('clean')
    run(argv[1:] or testList())
