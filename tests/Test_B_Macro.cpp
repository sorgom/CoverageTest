#include <CoverageB.h>

#include <use.h>
#include <Test.h>

TEST(B_Macro)
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
