#ifndef COVERAGE_MCPP_H
#define COVERAGE_MCPP_H

#include <SomeStruct.h>
#include <use.h>

class CoverageMcpp
{
public:
    inline CoverageMcpp(const int i = 0):
        // member struct constructor bool simple
        mStruct{i == 0, i > 0, i}
    {}

    inline CoverageMcpp(const bool b, const int i):
        // member struct constructor bool and / or, ternary
        mStruct{b and i > 0, b or i > 0, b ? 1 : 0}
    {}

    //  full coverage
    //  i1 0 / 1
    //  i2 0 / 1
    static void assignments(const int i1, const int i2)
    {
        //  const assignment constructors
        //  simple bool
        const bool cb1 { i1 > 0 };
        //  bool and
        const bool cb2 { (i1 > 0) and (i2 > 0) };
        //  bool or
        const bool cb3 { (i1 > 0) or (i2 > 0) };
        //  ternary
        const int ci1 { (i2 > i1) ? i2 : i1 };

        use(ci1, cb1, cb2, cb3);

        //  non const assignment constructors
        //  simple bool
        bool vb1 { i1 > 0 };
        //  bool and
        bool vb2 { (i1 > 0) and (i2 > 0) };
        //  bool or
        bool vb3 { (i1 > 0) or (i2 > 0) };
        //  ternary
        int vi1 = { (i2 > i1) ? i2 : i1 };

        use(vb1, vb2, vb3, vi1);

        //  const struct assignment constructors
        //  bool simple
        const SomeStruct cs1 { i2 > i1, i2 == i1, i2 };
        //  bool and / or
        const SomeStruct cs2 { vb1 and vb2, vb2 or vb3, i1 };
        //  ternary
        const SomeStruct cs3 { vb2, vb3, i2 > i1 ? i2 : i1 };

        //  non const struct assignment constructors
        //  bool simple
        SomeStruct vs1 { i2 > i1, i2 == i1, i2 };
        //  bool and / or
        SomeStruct vs2 { vb1 and vb2, vb2 or vb3, i1 };
        //  ternary
        SomeStruct vs3 { vb2, vb3, i2 > i1 ? i2 : i1 };

        use(cs1, cs2, cs3, vs1, vs2, vs3);
    }


    const SomeStruct mStruct;
};

template <bool B, int I>
class CoverageInline
{
public:
    CoverageInline() = delete;
    inline static bool isNeg() { return IsNeg or I < 0; }
    inline static int val() { return IsNeg ? Val : -Val; }
    inline static bool func()
    {
        if constexpr (I < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    //  static const bool and
    const static bool IsNeg = B and I < 0;
    //  static const int ternary
    const static int Val = IsNeg ? I : -I;
};

template <bool B, int I>
class CoverageConstExpr
{
public:
    CoverageConstExpr() = delete;
    constexpr static bool isNeg() { return IsNeg or I < 0; }
    constexpr static int val() { return IsNeg ? Val : -Val; }
    constexpr static bool func()
    {
        if constexpr (I < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    //  static const bool and
    constexpr static bool IsNeg = B and I < 0;
    //  static const int ternary
    constexpr static int Val = IsNeg ? I : -I;
};



#endif // _H
