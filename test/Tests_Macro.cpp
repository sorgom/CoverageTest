#include <CoverageMacro.h>


#include <iostream>
using std::cout;
using std::endl;

void tstOut(const char* nr)
{
    cout << "  - Macro Test" << nr << endl;
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