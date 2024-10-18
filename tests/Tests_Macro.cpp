#include <CoverageMacro.h>

#include <Use.h>
#include <test.h>

void Test01()
{
}

int main()
{
    settest("macros");
    test(Test01, 1);
    return 0;
}