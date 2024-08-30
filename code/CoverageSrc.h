#pragma once
#ifndef COVERAGESRC_H
#define COVERAGESRC_H

class CoverageSrc
{
public:
    CoverageSrc(bool b = false);
    CoverageSrc(int i);
    CoverageSrc(int i, bool b);

    //  return and
    bool operator==(const CoverageSrc& other) const;
    //  return or
    bool operator!=(const CoverageSrc& other) const;
    //  return simple bool
    bool operator<(const CoverageSrc& other) const;
    //  return ternary
    int realVal() const;
    //  boolean parameter
    static bool isTrue(bool b);

    //  simple boolean call
    bool hasVal1() const;
    //  ternary call
    bool hasVal2() const;
    //  boolean call and
    bool hasVal3() const;

    //  boolean call or
    bool noVal() const;
    //  for loop
    void forLoop(int lim) const;
    //  switch case single return
    int switchCaseSingle(const int val) const;
    //  switch case multiple return (not allowed with SIL4)
    int switchCaseMulti(const int val) const;
    void assignments(int a, int b) const;
    int ifElse(int i, bool b = false) const;
    void tryCatch(int i) const;

    inline bool getBool() const { return mBool; }
    inline int getInt() const { return mInt; }

private:
    const bool mBool;
    const int mInt;
};

#endif // _H
