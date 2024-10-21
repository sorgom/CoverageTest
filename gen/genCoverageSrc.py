#   generate coverage source and header code from header only
#   (quick, dirty and uncommented)

import re
from os.path import dirname

codeDir = dirname(__file__) + '/../code/'

headerIn = codeDir + 'CoverageHead.h'
headerOut = codeDir + 'CoverageSrc.h'
sourceOut = codeDir + 'CoverageSrc.cpp'

rxInl = re.compile(r'\binline +')
rxClean = re.compile(r' +$', re.M)
rxParams = re.compile(r'\(.*?\)')
rxBody = re.compile(r'\n {4}\{(?:\}|.*?\n {4}\})', re.S)
rxDef = re.compile(r'^((?:\w+ +)*\w+)(\((.*?)\))', re.M)
rxCon = re.compile(r'\):\n.*?\n {4}\{\}', re.S)

def remConst(mo):
    return re.sub(r'const +', '', mo.group(0))

def remDef(mo):
    return mo.group(1) + re.sub(r' *= *\w+', '', mo.group(2))

with open(headerIn, 'r') as fh:
    cont = fh.read()
    cont = cont.expandtabs(4)
    cont = rxInl.sub('', cont)
    cont = rxClean.sub('', cont)
    cont = cont.replace('CoverageHead', 'CoverageSrc')

    # declarations
    decls = rxCon.sub(');', cont)
    decls = rxBody.sub(';', decls)
    decls = rxParams.sub(remConst, decls)
    decls = decls.replace('CoverageSrc&', 'const CoverageSrc&')
    decls = decls.replace('COVERAGE_HEAD_H', 'COVERAGE_SRC_H')
    print('\n// ##### decls\n')
    print(decls)
    # definitions
    defs = re.sub(r'^ {4}', '', cont, flags=re.M)
    defs = re.sub(r'^static +', '', defs, flags=re.M)
    defs = rxDef.sub(remDef, defs)
    defs = re.sub(r'^(~)?((?:\w+ +)*)(\w+)\(', r'\2CoverageSrc::\1\3(', defs, flags=re.M)
    defs = re.sub(r'^.*\npublic:', '', defs, flags=re.S)
    defs = re.sub(r'\s*\nconst.*$', '', defs, flags=re.S|re.M)
    defs = f'#include <CoverageSrc.h>\n{defs.strip()}\n'
    print('\n// ##### defs\n')
    print(defs)

    with open(headerOut, 'w') as fh:
        fh.write(decls)
        fh.close()

    with open(sourceOut, 'w') as fh:
        fh.write(defs)
        fh.close()