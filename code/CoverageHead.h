#pragma once
#ifndef COVERAGEHEAD_H
#define COVERAGEHEAD_H

#include <SomeStruct.h>
#include <use.h>
#include <coverage.h>

class CoverageHead
{
public:
    //  full coverage
    //  b true / false
    inline CoverageHead(const bool b = false):
        mBool(b),
        // ternary constructor
        mInt(b ? 1 : 0)
    {}

    //  full coverage
    //  i 0 / 1 
    inline CoverageHead(const int i):
        // simple bool constructor
        mBool(i != 0),
        mInt(i)
    {}

    //  full coverage
    //  i 0 / 1
    //  b false / true
    inline CoverageHead(const bool b, const int i):
        // constructor or
        mBool(b or i != 0),
        mInt(i)
    {}

    //  full coverage
    //  b true / false
    //  i 0 / 1 / -1
    void ifElse(const bool b, const int i) const
    {
        // bool var
        if (b)
        {
            pass();
        }
        // bool simple
        if (i > 0)
        {
            pass();
        }
        // bool and
        if (b and i > 0)
        {
            pass();
        }
        // bool or
        if (b or i > 0)
        {
            pass();
        }
    }

    //  return bool simple
    inline bool retBoolSimple(const int i1, const int i2) const
    {
	    return i2 > i1;
    }

    //  return bool and
    inline bool retBoolAnd(const int i1, const int i2) const
    {
    	return (i1 > 0) and (i2 > 0);
    }
    //  return bool or
    inline bool retBoolOr(const int i1, const int i2) const
    {
    	return (i1 > 0) or (i2 > 0);
    }
    //  return ternary
    inline int retTernary(const int i1, const int i2) const
    {
	    return i2 > i1 ? i2 : i1;
    }

    //  call bool simple
    inline void callBoolSimple(const int i1, const int i2) const
    {
	    call(i2 > i1);
    }
    //  call bool and
    inline void callBoolAnd(const int i1, const int i2) const
    {
	    call((i1 > 0) and (i2 > 0));
    }
    //  call bool or
    inline void callBoolOr(const int i1, const int i2) const
    {
	    call((i1 > 0) or (i2 > 0));
    }
    //  call ternary
    inline void callTernary(const int i1, const int i2) const
    {
	    call(i2 > i1 ? i2 : i1);
    }

    //  full coverage
    //  i1 0 / 1
    //  i2 0 / 1
    void assignments(const int i1, const int i2) const
    {
        //  const assignment constructors
        //  simple bool
        const bool cb1 = i1 > 0;
        //  bool and
        const bool cb2 = (i1 > 0) and (i2 > 0);
        //  bool or
        const bool cb3 = (i1 > 0) or (i2 > 0);
        //  ternary
        const int ci1 = (i2 > i1) ? i2 : i1;
        
        use(ci1, cb1, cb2, cb3);

        //  non const assignment constructors
        //  simple bool
        bool vb1 = i1 > 0;
        //  bool and
        bool vb2 = (i1 > 0) and (i2 > 0);
        //  bool or
        bool vb3 = (i1 > 0) or (i2 > 0);
        //  ternary
        int vi1 = (i2 > i1) ? i2 : i1;

        //  non const assignments
        //  simple bool
        vb1 = i1 == 0;
        //  bool and
        vb2 = (i1 == 0) and (i2 == 0);
        //  bool or
        vb3 = (i1 == 0) or (i2 == 0);
        //  ternary
        vi1 = (i2 == 1) ? i2 : i1;


        use(vb1, vb2, vb3, vi1);

        //  const struct assignment constructors
        //  bool simple 
        const SomeStruct cs1 = { i2 > i1, i2 == i1, i2 };
        //  bool and / or
        const SomeStruct cs2 = { vb1 and vb2, vb2 or vb3, i1 };
        //  ternary
        const SomeStruct cs3 = { vb2, vb3, i2 > i1 ? i2 : i1 };

        //  non const struct assignment constructors
        //  bool simple 
        SomeStruct vs1 = { i2 > i1, i2 == i1, i2 };
        //  bool and / or
        SomeStruct vs2 = { vb1 and vb2, vb2 or vb3, i1 };
        //  ternary
        SomeStruct vs3 = { vb2, vb3, i2 > i1 ? i2 : i1 };

        use(cs1, cs2, cs3, vs1, vs2, vs3);
    }

    //  for loop simple
    void forLoopSimple(const int i1) const
    {
        for (int i = 0;	i < i1; ++i)
        {
            use(i);
        }
    }
    //  for loop and
    void forLoopAnd(const int i1, const int i2) const
    {
        for (int i = 0;	(i < i1) and (i < i2); ++i)
        {
            use(i);
        }
    }
    //  for loop or
    void forLoopOr(const int i1, const int i2) const
    {
        for (int i = 0;	(i < i1) or (i < i2); ++i)
        {
            use(i);
        }
    }

    //  switch case single return
    static int switchCaseSingle(const int i)
    {
        int res = -1;
        switch (i)
        {
            case 0:
                res = 0;
                break;
            case 1:
            case 2:
                res = 1;
                break;
            default:
                break;
        }
        return res;
    }

    //  switch case multiple return (not allowed with SIL4)
    static int switchCaseMulti(const int i)
    {
        switch (i)
        {
            case 0:
                return 0;
            case 1:
            case 2:
                return 1;
            default:
                return -1;
        }
        // unreachable
        BULLSEY_PAUSE
        #pragma CTC SKIP
        return 42;
        #pragma CTC ENDSKIP
        BULLSEY_RESUME
    }

    void tryCatch(const bool b) const
    {
        try
        {
            if (not b)
            {
                throw false;
            }
        }
        catch(bool e)
        {
            use(e);
        }
    }

    const bool mBool;
    const int mInt;
};

#endif // _H
