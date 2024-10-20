#pragma once
#ifndef COVERAGEB_H
#define COVERAGEB_H

#include <SomeStruct.h>
#include <use.h>
#include <coverage.h>

class CoverageB
{
public:
    inline CoverageB(const int i):
        // simple bool constructor
        mBool(B(i != 0)),
        mInt(i)
    {}

    //  return bool simple
    inline static bool retBoolSimple(const int i1, const int i2)
    {
	    return B(i2 > i1);
    }

    //  call bool simple
    inline static void callBoolSimple(const int i1, const int i2)
    {
	    call(B(i2 > i1));
    }
    
    //  full coverage
    //  i1 0 / 1
    //  i2 0 / 1
    static void assignments(const int i1, const int i2)
    {
        //  const assignment constructors
        //  simple bool
        const bool cb1 = B(i1 > 0);

        //  non const assignment constructors
        //  simple bool
        bool vb1 = B(i1 > 0);

        //  non const assignments
        //  simple bool
        vb1 = B(i1 == 0);

        //  const struct assignment constructors
        //  bool simple 
        const SomeStruct cs1 = { B(i2 > i1), B(i2 == i1), i2 };

        //  non const struct assignment constructors
        //  bool simple 
        SomeStruct vs1 = { B(i2 > i1), B(i2 == i1), i2 };

        use(cb1, vb1, cs1, vs1);
    }

    const bool mBool;
    const int mInt;
};

#endif // _H
