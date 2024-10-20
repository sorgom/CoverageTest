#pragma once
#ifndef COVERAGENOTINC_H
#define COVERAGENOTINC_H

#include <Use.h>

class CoverageNotInc
{
public:
    inline CoverageNotInc(const bool b = false):
        mBool(b),
        // ternary constructor
        mInt(b ? 1 : 0)
    {}
    inline CoverageNotInc(const int i):
        // simple boolean constructor
        mBool(i != 0),
        mInt(i)
    {}

    inline CoverageNotInc(const int i, const bool b):
        // constructor and
        mBool(b and i != 0),
        mInt(i)
    {}

private:
    const bool mBool;
    const int mInt;
};


#endif // _H
