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
    static void ifElse(bool b, int i);

    //  return static bool simple
    static bool retBoolSimple(int i1, int i2);

    //  return static bool and
    static bool retBoolAnd(int i1, int i2);
    //  return static bool or
    static bool retBoolOr(int i1, int i2);
    //  return ternary
    static int retTernary(int i1, int i2);

    //  call static bool simple
    static void callBoolSimple(int i1, int i2);
    //  call static bool and
    static void callBoolAnd(int i1, int i2);
    //  call static bool or
    static void callBoolOr(int i1, int i2);
    //  call ternary
    static void callTernary(int i1, int i2);

    //  full coverage
    //  i1 0 / 1
    //  i2 0 / 1
    static void assignments(int i1, int i2);

    //  for loop simple
    static void forLoopSimple(int i1);
    //  for loop and
    static void forLoopAnd(int i1, int i2);
    //  for loop or
    static void forLoopOr(int i1, int i2);

    //  switch case single return
    static int switchCaseSingle(int i);

    //  switch case multiple return (not allowed with SIL4)
    static int switchCaseMulti(int i);

    static void tryCatch(bool b);

    const bool mBool;
    const int mInt;
};

#endif // _H
