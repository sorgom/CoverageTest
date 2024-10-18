#pragma once
#ifndef COVERAGEB_H
#define COVERAGEB_H

#include <SomeStruct.h>
#include <Use.h>

#define B(BOOL_EXPR) (BOOL_EXPR ? true : false)

class CoverageB
{
public:
    inline CoverageB(const int i):
        // simple bool constructor
        mBool(B(i != 0)),
        mInt(i)
    {}


    void assignments(const int i1, const int i2) const
    {
        //  const assignment constructors
        //  simple bool
        const bool cb1 = B(i1 > 0);
        
        //  non const assignment constructors
        //  simple bool
        bool vb1 = B(i1 > 0);

        //  non const assignments
        //  simple bool
        vb1 = (i1 < 0);

        //  const struct assignment constructors
        //  bool simple 
        const SomeStruct cs1 = { B(i1 < i2), B(i1 == i2), i1 };

        //  non const struct assignment constructors
        //  bool simple 
        SomeStruct vs1 = { B(i1 < i2), B(i1 == i2), i1 };

        use(cb1, vb1, cs1, vs1);
    }

    //  return bool simple
    inline bool operator<(const CoverageB& other) const
    {
	    return B(mInt < other.mInt);
    }

    //  bool parameter
    inline static void call(const bool b)
    {
	    use(b);
    }

    //  call bool simple
    inline void callBoolSimple() const
    {
	    call(B(mInt > 0));
    }

    const bool mBool;
    const int mInt;
};

#endif // _H
