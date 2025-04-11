from glob import glob
from os import chdir, getcwd, system
from os.path import dirname, abspath, join, isfile
from subprocess import Popen, PIPE
from sys import argv

chdir(dirname(abspath(__file__)))
myDir = getcwd()
chdir('..')
repo = getcwd()
buildDir = join(repo, 'build')
exeDir = join(buildDir, 'windows')
srcDir = join(repo, 'code')
testsDir = join(repo, 'tests')
vsDir = join(repo, 'vs')
vsSolution = join(vsDir, 'Tests.sln')

if not isfile(vsSolution):
    print(f'{vsSolution} not found', 'use premake5 to generate', sep='\n')
    exit(1)

def testList():
    """return list of tests"""
    chdir(vsDir)
    return [c.replace('.vcxproj', '') for c in glob('Test_*.vcxproj')]

def sysCall(call:str):
    if system(call) != 0:
        print('call failed:', call)
        exit(1)

def proc(call:str, fh):
    """run process to report"""
    try:
        with Popen(call, stdout=PIPE, universal_newlines=True) as proc:
            fh.write(proc.stdout.read())
    except Exception:
        print('call failed:', call)
        exit(1)

def vsBuild(target):
    """build vs solution with target"""
    sysCall(f'msbuild -m {vsSolution} -t:{target}')

def showTests():
    """show available tests"""
    print('available tests:', *testList(), sep='\n')
    exit(0)

def checkArgs():
    """show available tests with -l option"""
    if '-l' in argv:
        showTests()
