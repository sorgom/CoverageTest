#include <CoverageFD_SET.h>

#include <use.h>
#include <test.h>

void Test01()
{
    selectSocket1(0);
    selectSocket2(0);
}

int main(const int argc, const char**)
{
    setTest("FD_SET", argc);
    runTest(Test01);
    return 0;
}