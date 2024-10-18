#include <CoverageB.h>

#include <iostream>
using std::cout;
using std::endl;

void tstOut(const char* nr)
{
    cout << "  - Test B_Macro" << nr << endl;
}

void Test01()
{
    tstOut("01");
}

int main()
{
    Test01();
    return 0;
}