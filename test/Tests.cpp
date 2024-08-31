#include <CoverageHead.h>
#include <CoverageOneFunc.h>
// #include <CoverageMacro.h>
#include <CoverageSrc.h>
#include <CoverageTpl.h>

#include <Use.h>

#include <iostream>
using std::cout;
using std::endl;

void Test01()
{
    cout << "- Test01" << endl;
    CoverageHead ch1(true);
    CoverageHead ch2(22);
    CoverageHead ch3(33, true);

    int i = 0;
    bool b = false;

    b = ch1 == ch2;
    b = ch1 != ch3;
    b = ch1 < ch2;

    i = ch1.realVal();
    b = ch2.hasVal1();
    b = ch3.hasVal2();
    b = ch1.hasVal3();
    b = ch2.noVal();

    ch1.forLoop();
    ch1.forLoopAnd(10);
    i = ch3.switchCaseSingle(1);
    i = ch1.switchCaseMulti(1);
    ch2.assignments(1, 2);

    i = ch2.ifElse(0, true);
    ch3.tryCatch(22);
    ch1.tryCatch(ch1.getInt());

    use(b, i);
}

void Test02()
{
    cout << "- Test02" << endl;
    CoverageSrc cs1(false);
    CoverageSrc cs2(-22);
    CoverageSrc cs3(-33, false);

    use(cs1, cs2, cs3);
}

void Test03()
{
    cout << "- Test03" << endl;

    constexpr int i = 22;
    constexpr bool b = true;

    CoverageTpl<b ? -i : i, b and i == 10> ct1;
    bool b1 = ct1.isNeg();
    int  i1 = ct1.val();

    use(b1, i1);
}

void Test04()
{
    // cout << "- Test04" << endl;

    // int i = 0;
    // bool b = false;

    // CoverageMacro cm;

    // b = cm.getBool();
    // i = cm.getInt1();
    // i = cm.getInt2();

    // CoverageMacroMcp cmm;
    // cmm.setInt2(0);

    // use(b, i);
}

int main()
{
    Test01();
    Test02();
    Test03();
    // Test04();
    return 0;
}