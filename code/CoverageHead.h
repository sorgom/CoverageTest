#pragma once
#ifndef COVERAGE_HEAD_H
#define COVERAGE_HEAD_H

#include <SomeEnum.h>
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
        mInt(i),
        // bool and ternary in new array
        mData(new int[b and i > 0? 20 : 10])
    {}

    //  destructor with if statement
    ~CoverageHead()
    {
        if (mData != nullptr) delete[] mData;
    }    

    //  full coverage
    //  b true / false
    //  i 0 / 1 / -1
    static void ifElse(const bool b, const int i)
    {
        // bool var
        if (b) { pass(); }
        // bool simple
        if (i > 0) { pass(); }
        // bool and
        if (b and i > 0) { pass(); }
        // bool or
        if (b or i > 0) { pass(); }
        else { pass(); }
    }

    //  return bool simple
    inline static bool retBoolSimple(const int i1, const int i2)
    {
        return i2 > i1;
    }

    //  return bool and
    inline static bool retBoolAnd(const int i1, const int i2)
    {
        return (i1 > 0) and (i2 > 0);
    }
    //  return bool or
    inline static bool retBoolOr(const int i1, const int i2)
    {
        return (i1 > 0) or (i2 > 0);
    }
    //  return ternary
    inline static int retTernary(const int i1, const int i2)
    {
        return i2 > i1 ? i2 : i1;
    }

    //  call bool simple
    inline static void callBoolSimple(const int i1, const int i2)
    {
        call(i2 > i1);
    }
    //  call bool and
    inline static void callBoolAnd(const int i1, const int i2)
    {
        call((i1 > 0) and (i2 > 0));
    }
    //  call bool or
    inline static void callBoolOr(const int i1, const int i2)
    {
        call((i1 > 0) or (i2 > 0));
    }
    //  call ternary
    inline static void callTernary(const int i1, const int i2)
    {
        call(i2 > i1 ? i2 : i1);
    }

    //  full coverage
    //  i1 0 / 1
    //  i2 0 / 1
    static void assignments(const int i1, const int i2)
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

        //  new statements
        //  bool simple
        const bool* nbs = new bool(i1 > 0);
        delete nbs;
        //  bool and
        const bool* nba = new bool((i1 > 0) and (i2 > 0));
        delete nba;
        //  bool or
        const bool* nbo = new bool((i1 > 0) or (i2 > 0));
        delete nbo;
        //  ternary array size
        const int* data = new int[i1 > 0 ? 20 : 10];
        delete [] data;
    }

    //  for loop simple
    static void forLoopSimple(const int i1)
    {
        for (int i = 0; i < i1; ++i)
        {
            use(i);
        }
    }
    //  for loop and
    static void forLoopAnd(const int i1, const int i2)
    {
        for (int i = 0; (i < i1) and (i < i2); ++i)
        {
            use(i);
        }
    }
    //  for loop or
    static void forLoopOr(const int i1, const int i2)
    {
        for (int i = 0; (i < i1) or (i < i2); ++i)
        {
            use(i);
        }
    }

    //  switch case
    static int switchCase(const SomeEnum e)
    {
        int res = -1;
        switch (e)
        {
            case VALUE_A:
                res = 0;
                break;
            case VALUE_B:
            case VALUE_C:
                res = 1;
                break;
            // not reachable with proper enumeration
            // but testable with cast
            default:
                break;
        }
        return res;
    }

    static void tryCatch(const bool b)
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
    const int* mData = nullptr;
};

#endif // _H
