#pragma once
#ifndef COVERAGESRC_H
#define COVERAGESRC_H

#include <SomeStruct.h>
#include <use.h>
#include <coverage.h>

class CoverageSrc
{
public:
    //  full coverage
    //  b true / false
    CoverageSrc(bool b = false);

    //  full coverage
    //  i 0 / 1
    CoverageSrc(int i);

    //  full coverage
    //  i 0 / 1
    //  b false / true
    CoverageSrc(bool b, int i);

    //  full coverage
    //  b true / false
    //  i 0 / 1 / -1
    void ifElse(bool b, int i) const;

    //  return bool simple
    bool retBoolSimple(int i1, int i2) const;

    //  return bool and
    bool retBoolAnd(int i1, int i2) const;
    //  return bool or
    bool retBoolOr(int i1, int i2) const;
    //  return ternary
    int retTernary(int i1, int i2) const;

    //  call bool simple
    void callBoolSimple(int i1, int i2) const;
    //  call bool and
    void callBoolAnd(int i1, int i2) const;
    //  call bool or
    void callBoolOr(int i1, int i2) const;
    //  call ternary
    void callTernary(int i1, int i2) const;

    //  full coverage
    //  i1 0 / 1
    //  i2 0 / 1
    void assignments(int i1, int i2) const;

    //  for loop simple
    void forLoopSimple(int i1) const;
    //  for loop and
    void forLoopAnd(int i1, int i2) const;
    //  for loop or
    void forLoopOr(int i1, int i2) const;

    //  switch case single return
    static int switchCaseSingle(int i);

    //  switch case multiple return (not allowed with SIL4)
    static int switchCaseMulti(int i);

    void tryCatch(bool b) const;

    const bool mBool;
    const int mInt;
};

#endif // _H
