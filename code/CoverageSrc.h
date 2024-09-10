#pragma once
#ifndef COVERAGESRC_H
#define COVERAGESRC_H

#include <SomeStruct.h>

class CoverageSrc
{
public:
    CoverageSrc(bool b = false);
    CoverageSrc(int i);
    CoverageSrc(int i, bool b);

    int ifElse(int i, bool b = false) const;

    void assignments(int i1, int i2) const;

    //  return bool simple
    bool operator<(const CoverageSrc& other) const;
    //  return bool and
    bool operator==(const CoverageSrc& other) const;
    //  return bool or
    bool operator!=(const CoverageSrc& other) const;
    //  return ternary
    int realVal() const;

    //  bool parameter
    static void call(bool b);

    //  call bool simple
    void callBoolSimple() const;
    //  call bool and
    void callBoolAnd() const;
    //  call bool or
    void callBoolOr() const;
    //  call ternary
    void callTernary() const;

    //  for loop simple
    void forLoopSimple() const;
    //  for loop and
    void forLoopAnd(int lim) const;
    //  for loop or
    void forLoopOr(int lim) const;

    //  switch case single return
    static int switchCaseSingle(int i);

    //  switch case multiple return (not allowed with SIL4)
    static int switchCaseMulti(int i);

    void tryCatch(int i) const;

    const bool mBool;
    const int mInt;
    const SomeStruct mStruct;
};

#endif // _H
