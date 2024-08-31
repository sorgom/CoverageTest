#pragma once
#ifndef COVERAGEHEAD_H
#define COVERAGEHEAD_H

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
        // simple boolean constructor
        mBool(i != 0),
        mInt(i)
    {}

    inline CoverageHead(const int i, const bool b):
        // constructor and
        mBool(b and i != 0),
        mInt(i)
    {}

    //  return and
    inline bool operator==(const CoverageHead& other) const
    {
    	return mBool == other.mBool and mInt == other.mInt;
    }
    //  return or
    inline bool operator!=(const CoverageHead& other) const
    {
	    return mBool != other.mBool or mInt != other.mInt;
    }
    //  return simple bool
    inline bool operator<(const CoverageHead& other) const
    {
	    return mInt < other.mInt;
    }
    //  return ternary
    inline int realVal() const
    {
	    return mBool ? mInt + 1 : mInt;
    }

    //  boolean parameter
    inline static bool isTrue(const bool b)
    {
	    return b;
    }

    //  simple boolean call
    inline bool hasVal1() const
    {
	    return isTrue(mInt > 0);
    }

    //  ternary call
    inline bool hasVal2() const
    {
	    return isTrue(mBool ? mInt > 0 : mInt < 0);
    }

    //  boolean call and
    inline bool hasVal3() const
    {
	    return isTrue(mBool and mInt > 0);
    }

    //  boolean call or
    inline bool noVal() const
    {
	    return isTrue((!mBool) or mInt == 0);
    }

    //  for loop
    void forLoop() const
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

    //  switch case single return
    int switchCaseSingle(const int i) const
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
    int switchCaseMulti(const int i) const
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

    void assignments(const int a, const int b) const
    {
        //  const assignment constructors
        //  ternary
        const int c1 = a > b ? a : b;
        //  simple boolean
        const bool c2 = a > 0;
        //  boolean and
        const bool c3 = c2 and b > 0;
        //  boolean or
        const bool c4 = c2 or b > 0;
        
        use(c1, c2, c3, c4);

        //  const mcp constructors
        //  ternary
        const int c5 { a > b ? a : b };
        //  simple boolean
        const bool c6 { a > 0 };
        //  boolean and
        const bool c7 {c2 and b > 0};
        //  boolean or
        const bool c8 {c2 or b > 0};
        
        use(c5, c6, c7, c8);

        //  non const assignment constructors
        //  ternary
        int v1 = a > b ? a : b;
        //  simple boolean
        bool v2 = a > 0;
        //  boolean and
        bool v3 = v2 and b > 0;
        //  boolean or
        bool v4 = v2 or b > 0;

        //  non const mcp constructors
        //  ternary
        int v5 { a > b ? a : b };
        //  simple boolean
        bool v6 { a > 0 };
        //  boolean and
        bool v7 { v2 and b > 0 };
        //  boolean or
        bool v8 { v2 or b > 0 };

        use(v5, v6, v7, v8);

        //  non const assignments
        //  ternary
        v1 = a < b ? a : b;
        //  simple boolean
        v2 = a < 0;
        //  boolean and
        v3 = v2 and b < 0;
        //  boolean or
        v4 = v2 or b < 0;

        use(v1, v2, v3, v4);
    }

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

    void tryCatch(const int i) const
    {
        try
        {
            if (i == mInt)
            {
                throw 0;
            }
        }
        catch (int e)
        {
            use(e);
        }
    }

    inline bool getBool() const { return mBool; }
    inline int getInt() const { return mInt; }

private:
    const bool mBool;
    const int mInt;
};


#endif // _H
