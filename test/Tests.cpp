#include <CoverageHead.h>
#include <CoverageSrc.h>
#include <CoverageTpl.h>

#include <iostream>
using std::cout;
using std::endl;

void Test01()
{
    cout << "- Test01" << endl;
    CoverageHead ch1(true);
    CoverageHead ch2(22);
    CoverageHead ch3(33, true);
}

void Test02()
{
    cout << "- Test02" << endl;
    CoverageSrc cs1(false);
    CoverageSrc cs2(-22);
    CoverageSrc cs3(-33, false);
}

void Test03()
{
    cout << "- Test03" << endl;
    CoverageTpl<22, true> ct1;
    bool b1 = ct1.isNeg();
    int  i1 = ct1.val();
}

int main()
{
    Test01();
    Test02();
    Test03();
    return 0;
}