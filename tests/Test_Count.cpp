#include <CoverageCount.h>

#include <Test.h>

TEST(Count)
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
