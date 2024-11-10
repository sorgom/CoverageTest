#pragma once
#ifndef COVERAGE_SRC_H
#define COVERAGE_SRC_H

#include <SomeEnum.h>
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

    //  destructor with if statement
    ~CoverageSrc();

    //  full coverage
    //  b true / false
    //  i 0 / 1 / -1
    static void ifElse(bool b, int i);

    //  return bool simple
    static bool retBoolSimple(int i1, int i2);

    //  return bool and
    static bool retBoolAnd(int i1, int i2);
    //  return bool or
    static bool retBoolOr(int i1, int i2);
    //  return ternary
    static int retTernary(int i1, int i2);

    //  call bool simple
    static void callBoolSimple(int i1, int i2);
    //  call bool and
    static void callBoolAnd(int i1, int i2);
    //  call bool or
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

    //  switch case
    static int switchCase(SomeEnum e);

    static void tryCatch(bool b);

    const bool mBool;
    const int mInt;
    const int* mData = nullptr;
};

#endif // _H
