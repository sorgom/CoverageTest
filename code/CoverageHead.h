#pragma once
#ifndef COVERAGEHEAD_H
#define COVERAGEHEAD_H

#include <SomeStruct.h>
#include <Use.h>

class CoverageHead
{
public:
    inline CoverageHead(const bool b = false):
        mBool(b),
        // ternary constructor
        mInt(b ? 1 : 0)
    {}

    inline CoverageHead(const int i):
        // simple bool constructor
        mBool(i != 0),
        mInt(i)
    {}

    inline CoverageHead(const int i, const bool b):
        // constructor and
        mBool(b and i != 0),
        mInt(i)
    {}

    int ifElse(const int i, const bool b = false) const
    {
        int ret = -1;
        // bool var
        if (b)
        {
            ret = 10;
        }
        // simple bool
        else if (i == 0)
        {
            ret = 0;
        }
        // bool and
        else if (mBool and i == 1)
        {
            ret = 1;
        }
        // bool or
        else if ((!mBool) or i < 0)
        {
            ret = 2;
        }
        else
        {
            ret = 3;
        }
        return ret;
    }

    void assignments(const int i1, const int i2) const
    {
        //  const assignment constructors
        //  simple bool
        const bool cb1 = i1 > 0;
        //  bool and
        const bool cb2 = cb1 and i2 > 0;
        //  bool or
        const bool cb3 = cb2 or i2 > 0;
        //  ternary
        const int ci1 = cb1 ? i1 : i2;
        
        use(ci1, cb1, cb2, cb3);

        //  non const assignment constructors
        //  simple bool
        bool vb1 = i1 > 0;
        //  bool and
        bool vb2 = vb1 and i2 > 0;
        //  bool or
        bool vb3 = vb2 or i2 > 0;
        //  ternary
        int vi1 = vb3 ? i1 : i2;

        //  non const assignments
        //  simple bool
        vb1 = i1 < 0;
        //  bool and
        vb2 = vb1 and i2 < 0;
        //  bool or
        vb3 = vb2 or i2 < 0;
        //  ternary
        vi1 = vb3 ? i1 : i2;

        use(vb1, vb2, vb3, vi1);

        //  const struct assignment constructors
        //  bool simple 
        const SomeStruct cs1 = { ci1 < vi1, ci1 > vi1, vi1 };
        //  bool and / or
        const SomeStruct cs2 = { vb2 and ci1 > vi1, vb3 or ci1 < vi1, ci1 };
        //  ternary
        const SomeStruct cs3 = { vb2, vb3, vb1 ? vi1 : ci1 };

        //  non const struct assignment constructors
        //  bool simple 
        SomeStruct vs1 = { ci1 < vi1, ci1 > vi1, vi1 };
        //  bool and / or
        SomeStruct vs2 = { vb2 and ci1 > vi1, vb3 or ci1 < vi1, ci1 };
        //  ternary
        SomeStruct vs3 = { vb2, vb3, vb1 ? vi1 : ci1 };

        use(cs1, cs2, cs3, vs1, vs2, vs3);
    }

    //  return bool simple
    inline bool operator<(const CoverageHead& other) const
    {
	    return mInt < other.mInt;
    }

    //  return bool and
    inline bool operator==(const CoverageHead& other) const
    {
    	return mBool == other.mBool and mInt == other.mInt;
    }
    //  return bool or
    inline bool operator!=(const CoverageHead& other) const
    {
	    return mBool != other.mBool or mInt != other.mInt;
    }
    //  return ternary
    inline int realVal() const
    {
	    return mBool ? mInt + 1 : mInt;
    }

    //  bool parameter
    inline static void call(const bool b)
    {
	    use(b);
    }

    //  call bool simple
    inline void callBoolSimple() const
    {
	    call(mInt > 0);
    }
    //  call bool and
    inline void callBoolAnd() const
    {
	    call(mBool and mInt > 0);
    }
    //  call bool or
    inline void callBoolOr() const
    {
	    call((!mBool) or mInt == 0);
    }
    //  call ternary
    inline void callTernary() const
    {
	    call(mBool ? mInt > 0 : mInt < 0);
    }

    //  for loop simple
    void forLoopSimple() const
    {
        for (int i = 0;	i < mInt; ++i)
        {
            use(i);
        }
    }
    //  for loop and
    void forLoopAnd(const int lim) const
    {
        for (int i = 0;	(i < mInt) and (i < lim); ++i)
        {
            use(i);
        }
    }
    //  for loop or
    void forLoopOr(const int lim) const
    {
        for (int i = 0;	(i < mInt) or (i < lim); ++i)
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
        #pragma BullseyeCoverage off
        #pragma CTC SKIP
        return 42;
        #pragma CTC ENDSKIP
        #pragma BullseyeCoverage on
    }

    void tryCatch(const int i) const
    {
        try
        {
            if (i == mInt)
            {
                throw 0;
            }
        }
        catch(int e)
        {
            use(e);
        }
    }

    const bool mBool;
    const int mInt;
};

#endif // _H
