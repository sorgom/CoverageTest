#include "test.h"
#include <iostream>
using std::cout;
using std::endl;

const char* testname = nullptr;

void settest(const char* name)
{
    testname = name;
}

void test(testfunc func, int nr)
{
    if (testname)
    {
        cout << "  - " << testname << " Test " << nr << std::endl;
        func();
    }
}