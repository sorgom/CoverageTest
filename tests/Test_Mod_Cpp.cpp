#include <CoverageMcpp.h>

#include <use.h>
#include <testlib.h>

TEST(Mod_Cpp_1)
{
    {
        CoverageMcpp c0(0);
        CoverageMcpp c1(1);
        CoverageMcpp cf0(false, 0);
        CoverageMcpp cf1(false, 1);
        CoverageMcpp ct0(true, 0);
        CoverageMcpp ct1(true, 1);

        use(c0, c1, cf0, cf1, ct0, ct1);
    }
    CoverageMcpp::assignments(0, 0);
    CoverageMcpp::assignments(0, 1);
    CoverageMcpp::assignments(1, 0);
    CoverageMcpp::assignments(1, 1);
}

TEST(Mod_Cpp_2)
{
    bool b = false;
    int i = 0;
    b = CoverageInline<true,  -1>::isNeg();
    b = CoverageInline<true,   1>::isNeg();
    b = CoverageInline<false, -1>::isNeg();
    b = CoverageInline<false,  1>::isNeg();

    b = CoverageInline<true,  -1>::func();
    b = CoverageInline<true,   1>::func();

    i = CoverageInline<true,  -1>::val();
    i = CoverageInline<false,  1>::val();
    use(b, i);
}

TEST(Mod_Cpp_3)
{
    bool b = false;
    int i = 0;
    b = CoverageConstExpr<true,  -1>::isNeg();
    b = CoverageConstExpr<true,   1>::isNeg();
    b = CoverageConstExpr<false, -1>::isNeg();
    b = CoverageConstExpr<false,  1>::isNeg();

    b = CoverageConstExpr<true,  -1>::func();
    b = CoverageConstExpr<true,   1>::func();

    i = CoverageConstExpr<true, -1>::val();
    i = CoverageConstExpr<false, 1>::val();
    use(b, i);
}
