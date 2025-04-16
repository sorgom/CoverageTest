from glob import glob
from os import chdir, getcwd, system, name as oname, environ
from os.path import dirname, abspath, isfile
from subprocess import Popen, PIPE
from sys import argv

isWin = oname == 'nt'
osSub = 'windows' if isWin else 'linux'

chdir(dirname(abspath(__file__)))
myDir = getcwd()
chdir('..')
repo = getcwd()
buildDir    = f'{repo}/build'
binDir      = f'{buildDir}/{osSub}'
makeDir     = f'{repo}/make'
vsDir       = f'{repo}/vs'
vsSolution  = f'{vsDir}/Tests.sln'
srcDir      = f'{repo}/code'
testsDir    = f'{repo}/tests'

if isWin and not isfile(vsSolution):
    print('not found:', vsSolution, 'use premake5 to generate', sep='\n')
    exit(1)

environ['PATH'] = f"{binDir}{';' if isWin else ':'}{environ['PATH']}"

def testList():
    """return list of tests"""
    if isWin:
        chdir(vsDir)
        return [c.replace('.vcxproj', '') for c in glob('Test_*.vcxproj')]
    else:
        chdir(makeDir)
        return [c.replace('.make', '') for c in glob('Test_*.make')]

def call(call:str):
    if system(call) != 0:
        print('call failed:', call)
        exit(1)

def proc(call:str, fh):
    """run process to report"""
    try:
        with Popen(call.split(), stdout=PIPE, universal_newlines=True) as proc:
            fh.write(proc.stdout.read())
    except Exception:
        print('call failed:', call)
        exit(1)

def build(target):
    """build target"""
    if isWin:
        chdir(vsDir)
        call(f'msbuild -m {vsSolution} -t:{target}')
    else:
        call(f'make -j -C {makeDir} {target}')

def showTests():
    """show available tests"""
    print('available tests:', *testList(), sep='\n')
    exit(0)

def checkArgs():
    """show available tests with -l option"""
    if '-l' in argv:
        showTests()
