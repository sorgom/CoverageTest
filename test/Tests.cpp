#include <CoverageHead.h>
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

    use(ch1, ch2, ch3);
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

int main()
{
    Test01();
    Test02();
    Test03();
    return 0;
}