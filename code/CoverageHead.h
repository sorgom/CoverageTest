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
        mInt(b ? 1 : 0),
        mStruct{b, b, 0}
    {}
    inline CoverageHead(const int i):
        // simple bool constructor
        mBool(i != 0),
        mInt(i),
        // mod cpp member struct constructor bool simple
        mStruct{i < 0, i > 0, i}
    {}

    inline CoverageHead(const int i, const bool b):
        // constructor and
        mBool(b and i != 0),
        mInt(i),
        // mod cpp member struct constructor bool and / or, ternary
        mStruct{b and i < 0, b or i > 0, b ? 1 : 0}
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

        //  const mod cpp constructors
        //  simple bool
        const bool cb4 { i1 > 0 };
        //  bool and
        const bool cb5 {cb2 and i2 > 0};
        //  bool or
        const bool cb6 {cb2 or i2 > 0};
        //  ternary
        const int ci2 { cb6 ? i1 : i2 };
        
        use(ci2, cb4, cb5, cb6);

        //  non const assignment constructors
        //  simple bool
        bool vb1 = i1 > 0;
        //  bool and
        bool vb2 = vb1 and i2 > 0;
        //  bool or
        bool vb3 = vb2 or i2 > 0;
        //  ternary
        int vi1 = vb3 ? i1 : i2;

        //  mod cpp non const constructors
        //  simple bool
        bool vb4 { i1 > 0 };
        //  bool and
        bool vb5 { vb2 and i2 > 0 };
        //  bool or
        bool vb6 { vb1 or i2 > 0 };
        //  ternary
        int vi2 { vb6 ? i1 : i2 };

        //  non const assignments
        //  simple bool
        vb1 = i1 < 0;
        //  bool and
        vb2 = vb1 and i2 < 0;
        //  bool or
        vb3 = vb2 or i2 < 0;
        //  ternary
        vi1 = vb3 ? i1 : i2;

        use(vb1, vb2, vb3, vb4, vb5, vb6, vi1, vi2);

        //  const struct assignment constructors
        //  bool simple 
        const SomeStruct cs1 = { vi2 < vi1, vi2 > vi1, vi1 };
        //  bool and / or
        const SomeStruct cs2 = { vb2 and vi2 > vi1, vb3 or vi2 < vi1, vi2 };
        //  ternary
        const SomeStruct cs3 = { vb2, vb3, vb1 ? vi1 : vi2 };

        //  non const struct assignment constructors
        //  bool simple 
        SomeStruct vs1 = { vi2 < vi1, vi2 > vi1, vi1 };
        //  bool and / or
        SomeStruct vs2 = { vb2 and vi2 > vi1, vb3 or vi2 < vi1, vi2 };
        //  ternary
        SomeStruct vs3 = { vb2, vb3, vb1 ? vi1 : vi2 };

        use(cs1, cs2, cs3, vs1, vs2, vs3);

        //  mod cpp const struct constructors
        //  bool simple 
        const SomeStruct cs4 { vi2 < vi1, vi2 > vi1, vi1 };
        //  bool and / or
        const SomeStruct cs5 { vb2 and vi2 > vi1, vb3 or vi2 < vi1, vi2 };
        //  ternary
        const SomeStruct cs6 { vb2, vb3, vb1 ? vi1 : vi2 };

        //  mod cpp const struct constructors
        //  bool simple 
        SomeStruct vs4 { vi2 < vi1, vi2 > vi1, vi1 };
        //  bool and / or
        SomeStruct vs5 { vb2 and vi2 > vi1, vb3 or vi2 < vi1, vi2 };
        //  ternary
        SomeStruct vs6 { vb2, vb3, vb1 ? vi1 : vi2 };

        use(cs4, cs5, cs6, vs4, vs5, vs6);
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
    const SomeStruct mStruct;
};

#endif // _H
