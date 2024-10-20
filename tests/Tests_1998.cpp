#include <CoverageHead.h>
#include <CoverageOneFunc.h>
#include <CoverageSrc.h>
#include <CoverageTpl.h>

#include <use.h>
#include <test.h>

//  same tests for header and src based classes
template <class COVCL>
void TestCov()
{
    {
        // f, 0
        const COVCL c_f(false);
        // t, 1
        const COVCL c_t(true);
        // f, 0
        const COVCL c_0(0);
        // t, 1
        const COVCL c_1(1);
        // f, 0
        const COVCL c_f_0(false, 0);
        // t, 1
        const COVCL c_f_1(false, 1);
        // t, 0
        const COVCL c_t_0(true, 0);
        // t, 1
        const COVCL c_t_1(true, 1);

        use(c_f, c_t, c_0, c_1, c_f_0, c_f_1, c_t_0, c_t_1);
    }

    int i = 0;
    bool b = false;

    COVCL::ifElse(false, 0);
    COVCL::ifElse(false, 1);
    COVCL::ifElse(true, 0);
    COVCL::ifElse(true, 1);

    b = COVCL::retBoolSimple(0, 1);
    b = COVCL::retBoolSimple(1, 1);

    // f _
    b = COVCL::retBoolAnd(0, 1);
    // t f
    b = COVCL::retBoolAnd(1, 0);
    // t t
    b = COVCL::retBoolAnd(1, 1);

    // f f
    b = COVCL::retBoolOr(0, 0);
    // f t
    b = COVCL::retBoolOr(0, 1);
    // t _
    b = COVCL::retBoolOr(1, 0);

    // f
    i = COVCL::retTernary(1, 1);
    // t
    i = COVCL::retTernary(0, 1);

    COVCL::callBoolSimple(0, 1);
    COVCL::callBoolSimple(1, 1);

    // f _
    COVCL::callBoolAnd(0, 1);
    // t f
    COVCL::callBoolAnd(1, 0);
    // t t
    COVCL::callBoolAnd(1, 1);

    // f f
    COVCL::callBoolOr(0, 0);
    // f t
    COVCL::callBoolOr(0, 1);
    // t _
    COVCL::callBoolOr(1, 0);

    // f
    COVCL::callTernary(1, 1);
    // t
    COVCL::callTernary(0, 1);

    COVCL::assignments(0, 0);
    COVCL::assignments(0, 1);
    COVCL::assignments(1, 0);
    COVCL::assignments(1, 1);

    COVCL::forLoopSimple(2);
    COVCL::forLoopAnd(2, 3);
    COVCL::forLoopAnd(3, 2);
    COVCL::forLoopOr(2, 3);
    COVCL::forLoopOr(3, 2);

    COVCL::switchCaseSingle(0);
    COVCL::switchCaseSingle(1);
    COVCL::switchCaseSingle(2);
    COVCL::switchCaseSingle(3);

    COVCL::switchCaseMulti(0);
    COVCL::switchCaseMulti(1);
    COVCL::switchCaseMulti(2);
    COVCL::switchCaseMulti(3);

    COVCL::tryCatch(true);
    COVCL::tryCatch(false);

    use(b, i);
}

void Test03()
{
    bool b = false;
    int i = 0;
    b = CoverageTpl<false,  0>::isNeg();
    i = CoverageTpl<false,  0>::val();
    b = CoverageTpl<false, -1>::isNeg();
    i = CoverageTpl<false, -1>::val();
    b = CoverageTpl<true,   0>::isNeg();
    i = CoverageTpl<true,   0>::val();
    b = CoverageTpl<true,  -1>::isNeg();
    i = CoverageTpl<true,  -1>::val();

    ByteBuffer<long int, short> bb;
    use(b, i, bb);

    oneFunc();
}

int main(const int argc, const char**)
{
    settest("cpp 1998", argc);
    test(TestCov<CoverageHead>);
    test(TestCov<CoverageSrc>);
    test(Test03);
    return 0;
}