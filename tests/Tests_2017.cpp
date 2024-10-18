#include <CoverageMcpp.h>

#include <Use.h>
#include <test.h>

void Test01()
{
}

int main()
{
    settest("cpp 2017");
    test(Test01, 1);
    return 0;
}