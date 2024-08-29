// #pragma once
#ifndef COVERAGEHEAD_H
#define COVERAGEHEAD_H

class CoverageHead
{
public:
    inline CoverageHead(bool b = false):
        mBool(b),
        // ternary constructor
        mInt(b ? 1 : 0)
    {}
    inline CoverageHead(int i):
        // simple boolean constructor
        mBool(i != 0),
        mInt(i)
    {}

    inline CoverageHead(int i, bool b):
        // constructor and
        mBool(b && i != 0),
        mInt(i)
    {}

    //  return and
    inline bool operator==(const CoverageHead& other) const
    {
    	return mBool == other.mBool && mInt == other.mInt;
    }
    //  return or
    inline bool operator!=(const CoverageHead& other) const
    {
	    return mBool != other.mBool || mInt != other.mInt;
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
    inline static bool isTrue(bool b)
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
	    return isTrue(mBool && mInt > 0);
    }

    //  boolean call or
    inline bool noVal() const
    {
	    return isTrue((!mBool) || mInt == 0);
    }

    //  for loop
    int sum(int lim) const
    {
        int sum = 0;
        for (int i = 0;	(i < mInt) && (i < lim); ++i)
        {
            sum += i;
        }
        return sum;
    }

    //  switch case single return
    int switchCaseSingle(const int val) const
    {
        int res = -1;
        switch (val)
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
    int switchCaseMulti(const int val) const
    {
        switch (val)
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

    void assignments(int a, int b) const
    {
        //  const assignment constructors
        //  ternary
        const int c1 = a > b ? a : b;
        //  simple boolean
        const bool c2 = a > 0;
        //  boolean and
        const bool c3 = c2 && b > 0;
        //  boolean or
        const bool c4 = c2 || b > 0;

        //  non const assignment constructors
        //  ternary
        int v1 = a > b ? a : b;
        //  simple boolean
        bool v2 = a > 0;
        //  boolean and
        bool v3 = v2 && b > 0;
        //  boolean or
        bool v4 = v2 || b > 0;

        //  non const assignments
        //  ternary
        v1 = a < b ? a : b;
        //  simple boolean
        v2 = a < 0;
        //  boolean and
        v3 = v2 && b < 0;
        //  boolean or
        v4 = v2 || b < 0;
    }

    int ifelse(int val) const
    {
        int ret = -1;
        // simple bool
        if (val == 0)
        {
            ret = 0;
        }
        // bool and
        else if (mBool && val == 1)
        {
            ret = 1;
        }
        // bool or
        else if ((!mBool) || val < 0)
        {
            ret = 2;
        }
        else
        {
            ret = 3;
        }
        return ret;
    }

private:
    const bool mBool;
    const int mInt;
};


#endif // _H
