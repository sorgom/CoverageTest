"""ms build run all available tests with Bullseye coverage"""
import atexit
from glob import glob
from os import chdir, getcwd, makedirs, environ, system as sysCall, remove
from os.path import dirname, abspath, join
from sys import argv

chdir(dirname(abspath(__file__)))
myDir = getcwd()
chdir('..')
repo = getcwd()
buildDir = join(repo, 'build')
exeDir = join(buildDir, 'windows')
excludeFile = join(myDir, 'BullseyeCoverageExclusions')
reportsDir = join(repo, 'reports_bullseye')
report = join(reportsDir, 'coverage.md')
srcDir = join(repo, 'code')
testsDir = join(repo, 'tests')
vsDir = join(repo, 'vs')
vsSolution = 'Tests.sln'

makedirs(reportsDir, exist_ok=True)

remove(report)

environ['COVCOPT'] = f'--srcdir {srcDir} --macro -q'

def covRestore():
    """restore cov01 setting"""
    sysCall('cov01 -q --pop')

atexit.register(covRestore)

def testList():
    """return list of tests"""
    chdir(vsDir)
    return [c.replace('.vcxproj', '') for c in glob('Test_*.vcxproj')]

def tryCall(call:str):
    res = sysCall(call)
    if res != 0:
        print('call failed:', call)
        exit(1)

def vsBuild(target):
    """build vs solution with target"""
    chdir(vsDir)
    tryCall(f'msbuild -m {vsSolution} -t:{target}')

def buildAndRun(test:str):
    """build and run test"""
    chdir(vsDir)
    environ['COVFILE'] = join(reportsDir, f'{test}.cov')
    vsBuild(test)
    tryCall('covclear -q')
    tryCall(f'covselect -qd --import {excludeFile}')
    with open(report, 'a') as fh:
        fh.write(f'## {test}\n```\n')
    tryCall(join(exeDir, f'{test}.exe X >> {report}'))
    chdir(reportsDir)
    tryCall(f'covsrc -q --by-name >> {report}')
    with open(report, 'a') as fh:
        fh.write(f'```\n\n')

sysCall('cov01 -q --push')
sysCall('cov01 -q --on')

vsBuild('Clean')

for test in argv[1:] or testList():
    buildAndRun(test)
