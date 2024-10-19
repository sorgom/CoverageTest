#include <CoverageHead.h>
#include <CoverageOneFunc.h>
#include <CoverageSrc.h>
#include <CoverageTpl.h>

#include <use.h>
#include <test.h>

template <class COVCL>
void TestCov()
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

    int i = 0;
    bool b = false;

    c_1.ifElse(false, 0);
    c_1.ifElse(false, 1);
    c_1.ifElse(true, 0);
    c_1.ifElse(true, 1);

    b = c_1.retBoolSimple(0, 1);
    b = c_1.retBoolSimple(1, 1);

    // f _
    b = c_1.retBoolAnd(0, 1);
    // t f
    b = c_1.retBoolAnd(1, 0);
    // t t
    b = c_1.retBoolAnd(1, 1);

    // f f
    b = c_1.retBoolOr(0, 0);
    // f t
    b = c_1.retBoolOr(0, 1);
    // t _
    b = c_1.retBoolOr(1, 0);

    // f
    i = c_1.retTernary(1, 1);
    // t
    i = c_1.retTernary(0, 1);
    

    c_1.callBoolSimple(0, 1);
    c_1.callBoolSimple(1, 1);

    // f _
    c_1.callBoolAnd(0, 1);
    // t f
    c_1.callBoolAnd(1, 0);
    // t t
    c_1.callBoolAnd(1, 1);

    // f f
    c_1.callBoolOr(0, 0);
    // f t
    c_1.callBoolOr(0, 1);
    // t _
    c_1.callBoolOr(1, 0);

    // f
    c_1.callTernary(1, 1);
    // t
    c_1.callTernary(0, 1);

    c_1.assignments(0, 0);
    c_1.assignments(0, 1);
    c_1.assignments(1, 0);
    c_1.assignments(1, 1);

    c_1.forLoopSimple(2);
    c_1.forLoopAnd(2, 3);
    c_1.forLoopAnd(3, 2);
    c_1.forLoopOr(2, 3);
    c_1.forLoopOr(3, 2);

    c_1.switchCaseSingle(0);
    c_1.switchCaseSingle(1);
    c_1.switchCaseSingle(2);
    c_1.switchCaseSingle(3);

    c_1.switchCaseMulti(0);
    c_1.switchCaseMulti(1);
    c_1.switchCaseMulti(2);
    c_1.switchCaseMulti(3);

    c_1.tryCatch(true);
    c_1.tryCatch(false);

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

int main()
{
    settest("cpp 1998");
    test(TestCov<CoverageHead>);
    test(TestCov<CoverageSrc>);
    test(Test03);
    return 0;
}