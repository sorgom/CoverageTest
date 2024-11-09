#include <CoverageExJustify.h>
#include <CoverageExSkip.h>

#include <use.h>
#include <testlib.h>

TEST(Exclude)
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
