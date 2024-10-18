#include <CoverageB.h>

#include <Use.h>
#include <test.h>

void Test01()
{
}

int main()
{
    settest("B() macro");
    test(Test01, 1);
    return 0;
}