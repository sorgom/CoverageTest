#include <CoverageB.h>

#include <use.h>
#include <test.h>

void Test01()
{
    {
        CoverageB c0(0);
        CoverageB c1(1);

        use(c0, c1);
    }

    CoverageB::retBoolSimple(0, 0);
    CoverageB::retBoolSimple(0, 1);

    CoverageB::callBoolSimple(0, 0);
    CoverageB::callBoolSimple(0, 1);

    CoverageB::assignments(0, 0);
    CoverageB::assignments(0, 1);
    CoverageB::assignments(1, 0);
    CoverageB::assignments(1, 1);
}

int main(const int argc, const char**)
{
    setTest("B() macro", argc);
    runTest(Test01);
    return 0;
}