#include "test.h"
#include <iostream>
using std::cout;
using std::endl;

const char* testname = nullptr;
int nr = 0;

void settest(const char* name)
{
    testname = name;
    nr = 0;
}

void test(testfunc func)
{
    if (testname)
    {
        cout << "  - " << testname << " Test " << ++nr << std::endl;
        func();
    }
}