#include <CoverageCount.h>

#include <test.h>

void Test01()
{
    oneFunc();

    switchCaseSingle(VALUE_A);
    switchCaseSingle(VALUE_B);
    switchCaseSingle(VALUE_C);
    switchCaseSingle(static_cast<SomeEnum>(VALUE_C + 1));

    switchCaseMulti(VALUE_A);
    switchCaseMulti(VALUE_B);
    switchCaseMulti(VALUE_C);
    switchCaseMulti(static_cast<SomeEnum>(VALUE_C + 1));
} 

int main(const int argc, const char**)
{
    setTest("Count", argc);
    runTest(Test01);
    return 0;
}