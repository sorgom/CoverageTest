#include <CoverageExJustify.h>
#include <CoverageExSkip.h>

#include <use.h>
#include <test.h>

void Test01()
{
    switchCaseSkip(VALUE_A);
    switchCaseSkip(VALUE_B);
    switchCaseSkip(VALUE_C);
    switchCaseSkip(static_cast<SomeEnum>(VALUE_C + 1));

    switchCaseJust(VALUE_A);
    switchCaseJust(VALUE_B);
    switchCaseJust(VALUE_C);
    switchCaseJust(static_cast<SomeEnum>(VALUE_C + 1));
}

int main(const int argc, const char**)
{
    setTest("Exclude Code", argc);
    runTest(Test01);
    return 0;
}