#include <CoverageMcpp.h>

#include <use.h>
#include <test.h>

void Test01()
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

int main(const int argc, const char**)
{
    setTest("cpp 2017", argc);
    runTest(Test01);
    return 0;
}
