#   generate coverage source and header code from header only

import re
from os.path import dirname

hederFile = dirname(__file__) + '/../code/CoverageHead.h'

rxInl = re.compile(r'\binline +')
rxClean = re.compile(r' +$', re.M)
rxParams = re.compile(r'\(.*?\)')
rxBody = re.compile(r'\n {4}\{(?:\}|.*?\n {4}\})', re.S)
rxDef = re.compile(r'^((?:\w+ +)*\w+)(\((.*?)\))', re.M)
rxCon = re.compile(r'\):\n.*?\n {4}\{\}', re.S)

def remConst(mo):
    c = mo.group(0)
    return re.sub(r'const +', '', c)

def remDef(mo):
    return mo.group(1) + re.sub(r' *= *\w+', '', mo.group(2))

with open(hederFile, 'r') as fh:
    cont = fh.read()
    cont = cont.expandtabs(4)
    cont = rxInl.sub('', cont)
    cont = rxClean.sub('', cont)
    cont = cont.replace('CoverageHead', 'CoverageSrc')
    decls = rxCon.sub(');', cont)
    decls = rxBody.sub(';', decls)
    decls = rxParams.sub(remConst, decls)
    decls = decls.replace('CoverageSrc&', 'const CoverageSrc&')
    print('\n##### decls\n')
    print(decls)
    defs = re.sub(r'^ {4}', '', cont, flags=re.M)
    defs = re.sub(r'^static +', '', defs, flags=re.M)
    defs = rxDef.sub(remDef, defs)
    defs = re.sub(r'^((?:\w+ +)*)(\w+)\(', r'\1CoverageSrc::\2(', defs, flags=re.M)
    print('\n##### defs\n')
    print(defs)
