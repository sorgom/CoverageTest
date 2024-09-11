#include <CoverageHead.h>
// #include <CoverageMacro.h>
#include <CoverageOneFunc.h>
#include <CoverageSrc.h>
#include <CoverageTpl.h>

#include <Use.h>

#include <iostream>
using std::cout;
using std::endl;

void tstOut(const char* nr)
{
    cout << "  - cpp 1998 Test" << nr << endl;
}

void Test01()
{
    tstOut("01");

    CoverageHead ch1(true);
    CoverageHead ch2(22);
    CoverageHead ch3(33, true);

    int i = 0;
    bool b = false;

    b = ch1 == ch2;
    b = ch1 != ch3;
    b = ch1 < ch2;

    i = ch1.realVal();
    ch2.callBoolSimple();
    ch3.callBoolAnd();
    ch1.callBoolOr();
    ch2.callTernary();

    ch1.forLoopSimple();
    ch2.forLoopAnd(10);
    ch3.forLoopOr(10);

    i = ch3.switchCaseSingle(1);
    i = ch1.switchCaseMulti(1);
    
    ch2.assignments(1, 2);

    i = ch2.ifElse(0, true);
    ch3.tryCatch(22);
    ch1.tryCatch(ch1.mInt);

    use(b, i);
}

void Test02()
{
    tstOut("02");
    CoverageSrc cs1(false);
    CoverageSrc cs2(-22);
    CoverageSrc cs3(-33, false);

    use(cs1, cs2, cs3);
}

void Test03()
{
    tstOut("03");

    constexpr int i = 22;
    constexpr bool b = true;

    CoverageTpl<b ? -i : i, b and i == 10> ct1;
    bool b1 = ct1.isNeg();
    int  i1 = ct1.val();

    ByteBuffer<long int, short> bb1;

    use(b1, i1, bb1);
}

int main()
{
    Test01();
    Test02();
    Test03();
    return 0;
}